"""Shortlist equal-length function near-misses differing only in r1 offsets.

Read-only triage: a reported displacement mapping is an observation, not a
buffer-size inference or source-edit recommendation. Retail literals,
relocations, callee layout and the official verifier remain separate gates.
"""
import argparse
import json
import struct
from collections import defaultdict
from pathlib import Path

from branch_targets import local_branch_destinations
from check_literals import BUILD, Elf
from score_variants import mask


def signed16(word):
    value = word & 0xffff
    return value - 0x10000 if value & 0x8000 else value


def stack_operand(word):
    """Return (kind, displacement) for conservative r1-relative forms."""
    op = word >> 26
    if 32 <= op <= 55:  # D-form integer/FPR loads and stores
        if (word >> 16) & 31 != 1:
            return None
        return ('mem', signed16(word))
    if op == 14:  # addi only; addis is a high-half relocation form
        if (word >> 16) & 31 != 1:
            return None
        return ('addi', signed16(word))
    return None


def stack_differences(target, source, target_relocs=(), source_relocs=(),
                      target_edges=None, source_edges=None):
    """Return changed r1 operand rows; reject any other instruction change."""
    if len(target) != len(source) or not target:
        return None
    if target_edges is not None and source_edges is not None and target_edges != source_edges:
        return None
    changes = []
    for i, (x, y) in enumerate(zip(target, source)):
        off = i * 4
        xr = off in target_relocs or off + 2 in target_relocs
        yr = off in source_relocs or off + 2 in source_relocs
        if x >> 26 in (16, 18):
            # Preserve BO/BI/AA/LK; independently compare resolved local edges.
            if mask(x, xr) != mask(y, yr):
                return None
            continue
        if mask(x, xr) == mask(y, yr):
            continue
        if xr or yr:
            return None
        a, b = stack_operand(x), stack_operand(y)
        if a is None or b is None or a[0] != b[0]:
            return None
        # The instruction/register fields must be identical; only signed d changes.
        if (x & 0xffff0000) != (y & 0xffff0000):
            return None
        changes.append({'instruction_offset': off, 'kind': a[0],
                        'target_displacement': a[1], 'source_displacement': b[1],
                        'target_word': x, 'source_word': y})
    return changes or None


def relocation_signature(elf, relocs, start, size):
    return {pos - start: {'symbol': elf.syms[sym][0], 'type': kind, 'addend': addend}
            for pos, (sym, kind, addend) in relocs.items()
            if start <= pos < start + size}


def relocation_differences(target, source):
    """Describe unmatched bindings without treating them as verified."""
    result = []
    for offset in sorted(set(target) | set(source)):
        a, b = target.get(offset), source.get(offset)
        if a != b:
            result.append({'instruction_offset': offset, 'target': a, 'source': b})
    return result


def bindings_eligible(differences, unverified_bindings=False):
    return not differences or unverified_bindings


def candidates(report, build=BUILD, minimum=90, unverified_bindings=False):
    rows = []
    for unit in report.get('units', []):
        funcs = [f for f in unit.get('functions', [])
                 if minimum <= f.get('fuzzy_match_percent', 0) < 100]
        if not funcs:
            continue
        name = unit['name'].removeprefix('main/')
        paths = [build / kind / (name + '.o') for kind in ('obj', 'src')]
        if not all(p.is_file() for p in paths):
            continue
        target, source = map(Elf, paths)
        for ai, section in enumerate(target.secs):
            if not section[2] & 4 or not section[5]:
                continue
            bi = source.text_index(target.names[ai])
            if bi is None:
                continue
            af, bf = target.funcs(ai), source.funcs(bi)
            at, bt = target.sec_bytes(ai), source.sec_bytes(bi)
            ar, br = target.relocs(ai), source.relocs(bi)
            ae, be = local_branch_destinations(target, ai), local_branch_destinations(source, bi)
            for f in funcs:
                fn = f['name']
                if fn not in af or fn not in bf or af[fn][1] != bf[fn][1]:
                    continue
                ao, size = af[fn]
                bo, _ = bf[fn]
                if not size or size % 4 or ae.get(fn) != be.get(fn):
                    continue
                # Masking relocated fields for opcode comparison is safe only
                # when their resolved symbol/type/addend bindings also agree.
                ta = relocation_signature(target, ar, ao, size)
                sb = relocation_signature(source, br, bo, size)
                binding_diffs = relocation_differences(ta, sb)
                if not bindings_eligible(binding_diffs, unverified_bindings):
                    continue
                aw = struct.unpack('>' + str(size // 4) + 'I', at[ao:ao + size])
                bw = struct.unpack('>' + str(size // 4) + 'I', bt[bo:bo + size])
                changes = stack_differences(
                    aw, bw,
                    {p - ao for p in ar if ao <= p < ao + size},
                    {p - bo for p in br if bo <= p < bo + size},
                    ae[fn], be[fn])
                if not changes:
                    continue
                mapping = defaultdict(set)
                for change in changes:
                    mapping[change['target_displacement']].add(change['source_displacement'])
                rows.append({'unit': name, 'function': fn, 'bytes': size,
                             'percent': f.get('fuzzy_match_percent'),
                             'changes': changes,
                             'bindings_status': ('unverified' if binding_diffs else 'matching'),
                             'unverified_binding_differences': binding_diffs,
                             'offset_mapping': [
                                 {'target': k, 'source_options': sorted(v),
                                  'ambiguous': len(v) > 1}
                                 for k, v in sorted(mapping.items())]})
    return sorted(rows, key=lambda r: (-r['bytes'], r['unit'], r['function']))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', type=Path, default=BUILD,
                        help='build/GV4E69 directory containing obj/, src/ and report.json')
    parser.add_argument('--report', type=Path,
                        help='report JSON (defaults to <build>/report.json)')
    parser.add_argument('--limit', type=int, default=30)
    parser.add_argument('--minimum', type=float, default=90)
    parser.add_argument('--unverified-bindings', action='store_true',
                        help='show opcode/edge candidates despite relocation differences; bindings are explicitly provisional')
    parser.add_argument('--json', action='store_true')
    args = parser.parse_args()
    if args.limit < 1 or not 0 <= args.minimum <= 100:
        parser.error('limit must be positive; minimum must be in [0, 100]')
    report_path = args.report or args.build / 'report.json'
    report = json.loads(report_path.read_text(encoding='utf-8'))
    rows = candidates(report, build=args.build, minimum=args.minimum,
                      unverified_bindings=args.unverified_bindings)
    if args.json:
        print(json.dumps(rows[:args.limit], indent=2))
    else:
        print(f'{len(rows)} equal-length stack-offset candidates; inspect callee layout and full link/verifier evidence.')
        for r in rows[:args.limit]:
            mappings = ', '.join(f"{m['target']}->{m['source_options']}" for m in r['offset_mapping'])
            print(f"{r['bytes']:5} B {r['percent']:8.5f}% {r['unit']} {r['function']} "
                  f"({len(r['changes'])} instructions; bindings {r['bindings_status']}, "
                  f"{len(r['unverified_binding_differences'])} differing bindings; target->source {mappings})")


if __name__ == '__main__':
    main()
