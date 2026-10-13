"""Read-only literal-reference leads from same-offset relocations in matched code.

Names/addresses/bytes are evidence to review, not ownership or ABI proof. A
fallback 4-byte prefix is never described as a complete object. Final data
placement, literal checking, retail hash and the unmodified verifier remain
required.
"""
import argparse
import json
import re
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve()
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / 'tools' / 'match'))
from check_literals import BUILD, Elf, load_size


def matched_function_pairs(source, retail, matched):
    """Return same-name/same-size functions from every code section paired by name."""
    pairs, skipped, unpaired_sections = [], [], []
    source_exec = {source.names[i]: i for i, sec in enumerate(source.secs) if sec[2] & 4 and sec[5]}
    retail_exec = {retail.names[i]: i for i, sec in enumerate(retail.secs) if sec[2] & 4 and sec[5]}
    for secname in sorted(set(source_exec) | set(retail_exec)):
        si, ri = source_exec.get(secname), retail_exec.get(secname)
        if si is None or ri is None:
            unpaired_sections.append(secname)
            continue
        sf, rf = source.funcs(si), retail.funcs(ri)
        for fn in sorted(matched):
            if fn not in sf:
                continue
            so, ssize = sf[fn]
            if fn not in rf:
                skipped.append({'section': secname, 'function': fn, 'reason': 'no retail function'})
                continue
            ro, rsize = rf[fn]
            if ssize != rsize:
                skipped.append({'section': secname, 'function': fn,
                                'reason': f'unequal function sizes {ssize} vs {rsize}'})
                continue
            pairs.append((secname, si, ri, fn, so, ro, ssize))
    return pairs, skipped, unpaired_sections


def paired_data_relocations(source, retail, si, ri, fn, so, ro, size):
    """Pair source non-code data relocs to same-kind retail relocs at same function offset."""
    sr, rr = source.relocs(si), retail.relocs(ri)
    result, skipped = [], []
    for off in range(so, so + size):
        q = sr.get(off)
        if not q or q[1] not in (1, 4):
            continue
        sym = source.syms[q[0]]
        if sym[4] <= 0 or sym[4] >= len(source.secs):
            continue
        if source.secs[sym[4]][2] & 4:
            continue
        rel = rr.get(ro + off - so)
        if not rel or rel[1] not in (1, 4):
            skipped.append({'section': source.names[si], 'function': fn,
                            'code_offset': f'0x{off-so:X}', 'reason': 'unpaired data relocation'})
            continue
        if rel[1] != q[1]:
            skipped.append({'section': source.names[si], 'function': fn,
                            'code_offset': f'0x{off-so:X}', 'reason': 'mismatched relocation kinds',
                            'source_kind': q[1], 'retail_kind': rel[1]})
            continue
        result.append((off - so, q, rel))
    return result, skipped


def checked_range(data, start, size):
    """Return a complete section slice, or None when the requested extent is invalid."""
    if not isinstance(start, int) or not isinstance(size, int) or start < 0 or size < 0:
        return None
    if start > len(data) or start + size > len(data):
        return None
    return data[start:start + size]


def byte_comparison(mine, theirs, address, names, size, size_basis, extent_complete):
    """Mark exact only when both buffers contain the whole requested extent."""
    complete = len(mine) == size and theirs is not None and len(theirs) == size
    unique_names = sorted({n.get('name') for n in names if n.get('name')})
    return {'retail_address': f'0x{address:08X}' if address is not None else None,
            'candidate_names': names, 'ambiguous_target_names': len(unique_names) > 1,
            'target_hex': theirs.hex() if theirs is not None else None,
            'bytes_equal': bool(complete and theirs == mine), 'size': size,
            'size_basis': size_basis, 'extent_complete': bool(complete and extent_complete),
            'source_bytes_available': len(mine),
            'target_bytes_available': len(theirs) if theirs is not None else None,
            'bounds_ok': complete, 'unresolved_bounds': not complete}


def address_map(main):
    result = {}
    for name, value, _, _, shndx in main.syms:
        if shndx:
            result.setdefault(name, value)
    symbols = ROOT / 'config' / 'GV4E69' / 'symbols.txt'
    if symbols.is_file():
        for line in symbols.read_text(encoding='utf-8').splitlines():
            m = re.match(r'^(\S+) = [.\w]+:0x([0-9A-Fa-f]+);', line)
            if m:
                result.setdefault(m.group(1), int(m.group(2), 16))
    return result


def names_by_address(main, symbols):
    result = {}
    for name, value, size, info, shndx in main.syms:
        if shndx and info >> 4 == 1:
            result.setdefault(value, []).append({'name': name, 'size': size or None})
    if symbols.is_file():
        for line in symbols.read_text(encoding='utf-8').splitlines():
            m = re.match(r'^(\S+) = [.]\w+:0x([0-9A-Fa-f]+);', line)
            if m:
                addr, item = int(m.group(2), 16), {'name': m.group(1), 'size': None}
                if item not in result.setdefault(addr, []):
                    result[addr].append(item)
    aliases = ROOT / 'tools' / 'match' / 'symbol_aliases.tsv'
    if aliases.is_file():
        for line in aliases.read_text(encoding='utf-8').splitlines():
            fields = line.split('\t')
            if len(fields) >= 2 and not line.startswith('#'):
                target = next((addr for addr, items in result.items()
                               if any(item['name'] == fields[1] for item in items)), None)
                if target is not None:
                    alias = {'name': fields[0], 'size': None}
                    if alias not in result[target]:
                        result[target].append(alias)
    return result


def code_bases(retail, addr_of):
    out = {}
    for i, sec in enumerate(retail.secs):
        if not (sec[2] & 4 and sec[5]):
            continue
        bases = {addr_of[n] - v for n, (v, _) in retail.funcs(i).items() if n in addr_of}
        if len(bases) == 1:
            out[i] = next(iter(bases))
    return out


def target_address(retail, rel, code_idx, bases, addr_of):
    symidx, _, addend = rel
    name, value, _, _, shndx = retail.syms[symidx]
    if name in addr_of:
        return addr_of[name] + addend
    if shndx in bases:
        return bases[shndx] + value + addend
    if shndx == 0xFFF1:
        return value + addend
    if shndx and shndx < len(retail.secs):
        secaddr = retail.secs[shndx][3]
        return secaddr + value + addend if secaddr else None
    m = re.match(r'^lbl_([0-9A-Fa-f]{8})', name)
    return int(m.group(1), 16) + addend if m else None


def run(unit):
    name = unit.removeprefix('src/').removesuffix('.cpp').removesuffix('.c')
    source = Elf(BUILD / 'src' / (name + '.o'))
    retail = Elf(BUILD / 'obj' / (name + '.o'))
    main = Elf(BUILD / 'main.elf')
    report = json.loads((BUILD / 'report.json').read_text(encoding='utf-8'))
    row = next((u for u in report['units'] if u['name'].removeprefix('main/') == name), None)
    matched = {f['name'] for f in (row or {}).get('functions', [])
               if f.get('fuzzy_match_percent') == 100.0}
    pairs, skipped, unpaired_sections = matched_function_pairs(source, retail, matched)
    addr_of = address_map(main)
    exports = names_by_address(main, ROOT / 'config' / 'GV4E69' / 'symbols.txt')
    bases = code_bases(retail, addr_of)
    rows = []
    for secname, si, ri, fn, so, ro, fnsize in pairs:
        sites, unpaired = paired_data_relocations(source, retail, si, ri, fn, so, ro, fnsize)
        skipped.extend(unpaired)
        code = source.sec_bytes(si)
        for rel_off, srel, rrel in sites:
            ss = source.syms[srel[0]]
            sh = ss[4]
            start = ss[1] + srel[2]
            data = source.sec_bytes(sh)
            addr = target_address(retail, rrel, ri, bases, addr_of)
            names = exports.get(addr, []) if addr is not None else []
            word = struct.unpack_from('>I', code, (so + rel_off) & ~3)[0]
            width = load_size(word)
            if width is not None:
                size, basis, complete_extent = width, 'instruction_load_width', True
            else:
                # String extent is known only when a printable NUL terminator is present.
                end = data.find(b'\0', start)
                text = data[start:end] if end >= 0 else b''
                if text and all(32 <= c < 127 or c in (9, 10, 13) for c in text):
                    size, basis, complete_extent = len(text) + 1, 'validated_nul_terminated_string', True
                elif len({x['size'] for x in names if x.get('size')}) == 1:
                    size = next(x['size'] for x in names if x.get('size'))
                    basis, complete_extent = 'retail_symbol_size', True
                else:
                    size, basis, complete_extent = 4, 'fallback_prefix_4', False
            mine = checked_range(data, start, size)
            if mine is None:
                skipped.append({'section': secname, 'function': fn,
                                'code_offset': f'0x{rel_off:X}', 'source_section': source.names[sh],
                                'source_offset': start, 'requested_size': size,
                                'bounds_ok': False, 'reason': 'source byte range out of bounds'})
                continue
            theirs = main.read_addr(addr, size) if addr is not None else None
            result = byte_comparison(mine, theirs, addr, names, size, basis, complete_extent)
            rows.append({'section': secname, 'function': fn, 'code_offset': f'0x{rel_off:X}',
                         'source_section': source.names[sh], 'source_offset': f'0x{start:X}',
                         'source_hex': mine.hex(), 'retail_symbol': retail.syms[rrel[0]][0], **result})
    return {'unit': name,
            'warning': 'Relocation pairing and byte checks are leads, not ownership/signature proof.',
            'paired_candidates': rows, 'skipped': skipped,
            'unpaired_code_sections': unpaired_sections}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('units', nargs='+')
    ap.add_argument('--json', action='store_true')
    ap.add_argument('--limit', type=int)
    args = ap.parse_args()
    if args.limit is not None and args.limit < 1:
        ap.error('--limit must be positive')
    units = args.units[:args.limit] if args.limit else args.units
    try:
        rows = [run(unit) for unit in units]
    except OSError as exc:
        ap.error(f'missing build input: {exc}')
    if args.json:
        print(json.dumps(rows, indent=2))
    else:
        for row in rows:
            candidates = row.get('paired_candidates', [])
            exact = sum(x['bytes_equal'] for x in candidates)
            print(f"{row['unit']}: {len(candidates)} paired refs, {exact} exact byte comparisons")
            if row.get('unpaired_code_sections'):
                print('  unmatched code sections: ' + ', '.join(row['unpaired_code_sections']))


if __name__ == '__main__':
    main()
