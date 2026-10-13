"""Shortlist near misses whose instruction differences are stack offsets only.

Run after configure.py and ninja. Equal instruction counts and internal branch
paths are required. This is a read-only search aid, not proof of a buffer size:
inspect the actual callee's accesses and return layout before editing source.
Every accepted change still requires the retail hash, literal checks and the
unmodified verifier. External call/data relocations are not proved here.
"""
import argparse
import json
import struct

from branch_targets import local_branch_destinations
from check_literals import BUILD, Elf
from score_variants import mask


def frame_size(words):
    for word in words[:4]:
        if word >> 16 == 0x9421 and word & 0x8000:
            return 0x10000 - (word & 0xFFFF)
    return None


def frame_differences(target, source, target_relocs=(), source_relocs=()):
    """Return (byte offset, target word, source word), or None if not eligible.

    Branch displacements and external relocated fields use the normal scorer
    mask. The caller must separately compare resolved internal branch paths.
    """
    if len(target) != len(source):
        return None
    a, b = frame_size(target), frame_size(source)
    if a is None or b is None or a == b:
        return None
    changes = []
    for index, (x, y) in enumerate(zip(target, source)):
        offset = index * 4
        xr = offset in target_relocs or offset + 2 in target_relocs
        yr = offset in source_relocs or offset + 2 in source_relocs
        if mask(x, xr) == mask(y, yr):
            continue
        # Opcodes 32..55 are the integer/FPR D-form loads and stores,
        # including byte/halfword accesses and their update forms.
        if (x >> 16 != y >> 16 or (x >> 16) & 31 != 1
                or not (x >> 26 == 14 or 32 <= x >> 26 <= 55)):
            return None
        changes.append((offset, x, y))
    return changes or None


def candidates(report, build=BUILD, minimum=90):
    rows = []
    for unit in report['units']:
        functions = [f for f in unit.get('functions', [])
                     if minimum <= f.get('fuzzy_match_percent', 0) < 100]
        if not functions:
            continue
        name = unit['name'].removeprefix('main/')
        paths = [build / kind / (name + '.o') for kind in ('obj', 'src')]
        if not all(p.is_file() for p in paths):
            continue
        a, b = [Elf(p) for p in paths]
        for ai, section in enumerate(a.secs):
            if not section[2] & 4 or not section[5]:
                continue
            bi = b.text_index(a.names[ai])
            if ai is None or bi is None:
                continue
            af, bf = a.funcs(ai), b.funcs(bi)
            at, bt = a.sec_bytes(ai), b.sec_bytes(bi)
            ar, br = a.relocs(ai), b.relocs(bi)
            ad, bd = local_branch_destinations(a, ai), local_branch_destinations(b, bi)
            for function in functions:
                fn = function['name']
                if fn not in af or fn not in bf or af[fn][1] != bf[fn][1]:
                    continue
                ao, size = af[fn]
                bo, _ = bf[fn]
                if not size or size % 4 or ad[fn] != bd[fn]:
                    continue
                aw = struct.unpack('>' + str(size // 4) + 'I', at[ao:ao + size])
                bw = struct.unpack('>' + str(size // 4) + 'I', bt[bo:bo + size])
                changes = frame_differences(aw, bw,
                                            {p - ao for p in ar if ao <= p < ao + size},
                                            {p - bo for p in br if bo <= p < bo + size})
                if changes:
                    rows.append({'unit': name, 'function': fn, 'bytes': size,
                                 'percent': function['fuzzy_match_percent'],
                                 'target_frame': frame_size(aw), 'source_frame': frame_size(bw),
                                 'changes': [{'offset': hex(o), 'target': hex(x), 'source': hex(y)}
                                             for o, x, y in changes]})
    return sorted(rows, key=lambda r: (-r['bytes'], r['unit'], r['function']))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--limit', type=int, default=20)
    parser.add_argument('--minimum', type=float, default=90)
    parser.add_argument('--json', action='store_true')
    args = parser.parse_args()
    if args.limit < 1 or not 0 <= args.minimum < 100:
        parser.error('limit must be positive; minimum must be in [0, 100)')
    try:
        report = json.loads((BUILD / 'report.json').read_text(encoding='utf-8'))
        rows = candidates(report, minimum=args.minimum)
    except (OSError, ValueError) as error:
        parser.error(str(error))
    if args.json:
        print(json.dumps(rows[:args.limit], indent=2))
        return
    print(f'{len(rows)} stack-frame candidates; callee-layout evidence and full acceptance checks still required.')
    for row in rows[:args.limit]:
        print(f"{row['bytes']:5} B  frame {row['source_frame']} -> {row['target_frame']}  "
              f"{len(row['changes'])} changed offsets  {row['unit']} {row['function']}")


if __name__ == '__main__':
    main()
