#!/usr/bin/env python3
"""Check that splits.txt allows one link order, before dtk finds out the hard way.

dtk links every unit in a single order, and within each section each unit's
range has to follow that order. If unit X comes before Y in .text but after Y
in .sbss, no order works and dtk reports a cyclic link order. The swarm hit this
combining SDK and EA-library branches. This prints the units involved and the
section ranges that force each edge, so the cycle can be fixed before merging.
It also reports ranges that overlap within a section.

Ranges marked `common` (docs/dtk/common_bss.md) are ordered on their own: the
linker allocates common symbols after all regular data of the section. A
cycle closed only by a late .bss/.sbss range is the usual sign of common data
that isn't marked yet.

Usage: python tools/swarm/check_order.py [config/GV4E69/splits.txt]
Exit status: 0 = consistent, 1 = cycle or overlap found.
"""
import re
import sys
from collections import defaultdict
from pathlib import Path
from typing import Dict, List, Set, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
from merge_dtk import parse_splits, read  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
RANGE = re.compile(r"^\s*(\.?[\w.]+)\s+start:0x([0-9A-Fa-f]+) end:0x([0-9A-Fa-f]+)(.*)$")


def main() -> None:
    path = sys.argv[1] if len(sys.argv) > 1 else str(ROOT / "config" / "GV4E69" / "splits.txt")
    _, blocks, _ = parse_splits(read(path))
    units = {name.rstrip(":"): blk for name, blk in blocks.items()}
    by_sec: Dict[str, List[Tuple[int, int, str]]] = defaultdict(list)
    for name, blk in units.items():
        for line in blk[1:]:
            m = RANGE.match(line)
            if m:
                # Common ranges are allocated after every regular range of the section,
                # in link order among themselves: order them as a section of their own.
                sec = m.group(1) + (" common" if "common" in m.group(4).split() else "")
                by_sec[sec].append((int(m.group(2), 16), int(m.group(3), 16), name))

    problems = 0
    edges: Dict[str, Set[str]] = defaultdict(set)
    why: Dict[Tuple[str, str], str] = {}
    for sec, rs in by_sec.items():
        rs.sort()
        for (s1, e1, u1), (s2, e2, u2) in zip(rs, rs[1:]):
            if s2 < e1:
                problems += 1
                print(f"OVERLAP {sec}: {u1} {s1:08X}..{e1:08X} and {u2} {s2:08X}..{e2:08X}")
            if u1 != u2:
                edges[u1].add(u2)
                why.setdefault((u1, u2), f"{sec} {u1} {s1:08X} < {u2} {s2:08X}")

    # Tarjan's strongly connected components; any component of 2+ units is a cycle.
    index: Dict[str, int] = {}
    low: Dict[str, int] = {}
    stack: List[str] = []
    on: Set[str] = set()
    comps: List[List[str]] = []
    counter = [0]

    def visit(v: str) -> None:
        work = [(v, iter(sorted(edges[v])))]
        index[v] = low[v] = counter[0]
        counter[0] += 1
        stack.append(v)
        on.add(v)
        while work:
            node, it = work[-1]
            nxt = next(it, None)
            if nxt is not None:
                if nxt not in index:
                    index[nxt] = low[nxt] = counter[0]
                    counter[0] += 1
                    stack.append(nxt)
                    on.add(nxt)
                    work.append((nxt, iter(sorted(edges[nxt]))))
                elif nxt in on:
                    low[node] = min(low[node], index[nxt])
                continue
            work.pop()
            if work:
                low[work[-1][0]] = min(low[work[-1][0]], low[node])
            if low[node] == index[node]:
                comp = []
                while True:
                    w = stack.pop()
                    on.discard(w)
                    comp.append(w)
                    if w == node:
                        break
                if len(comp) > 1:
                    comps.append(comp)

    for u in sorted(units):
        if u not in index:
            visit(u)

    for comp in comps:
        problems += 1
        members = set(comp)
        print(f"CYCLE among {len(comp)} units: {', '.join(sorted(comp))}")
        for (u1, u2), reason in sorted(why.items()):
            if u1 in members and u2 in members:
                print(f"  {reason}")
    if problems:
        sys.exit(1)
    print(f"link order OK: {len(units)} units, {sum(len(v) for v in by_sec.values())} ranges")


if __name__ == "__main__":
    main()
