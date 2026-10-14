"""EA's own names for our functions, from related EA GameCube builds that ship
symbols or a linker map (config/GV4E69/refnames/, see its README).

    python tools/match/refnames.py fn_803E628C fn_80415B20     # reference names for functions
    python tools/match/refnames.py 0x803E628C                   # or addresses
    python tools/match/refnames.py --unit ealib/tu_803E3C08     # every function in a unit
    python tools/match/refnames.py --stats                      # coverage of unmatched code

A reference name means the reference build's function has the same code as
ours, addresses masked (unique fingerprint, at least 12 instructions). Names
from linker maps (fifa05, uefa, sims2) come demangled with full parameter
types and the object file, the best hint there is for a prototype. Hits in
the EA library, sound and SDK blocks are reliable. Hits in MVP's own game code
are often look-alikes from other games and are flagged.

Names are hints and evidence, not renames. Renaming a symbol is a
symbols.txt change (lead) and needs the evidence line in the commit.
"""
from __future__ import annotations

import argparse
import csv
import json
import re
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
REF_DIR = ROOT / "config" / "GV4E69" / "refnames"
SYMBOLS = ROOT / "config" / "GV4E69" / "symbols.txt"
REPORT = ROOT / "build" / "GV4E69" / "report.json"
GAME_AREAS = ("game", "fe", "db", "animation", "gamelib")

_refs = None
_addrs = None


def refs() -> dict[int, list[tuple[str, str, str]]]:
    """address -> [(name, build, object path)]"""
    global _refs
    if _refs is None:
        _refs = defaultdict(list)
        for p in sorted(REF_DIR.glob("*.tsv")):
            for row in csv.reader(p.open(encoding="utf-8"), delimiter="\t"):
                if len(row) >= 3 and row[0].startswith("0x"):
                    _refs[int(row[0], 16)].append((row[2], p.stem, row[3] if len(row) > 3 else ""))
    return _refs


def symbol_addrs() -> dict[str, int]:
    global _addrs
    if _addrs is None:
        _addrs = {}
        for line in SYMBOLS.open(encoding="utf-8"):
            m = re.match(r"^(\S+) = [.\w]+:0x([0-9A-Fa-f]+);", line)
            if m:
                _addrs.setdefault(m.group(1), int(m.group(2), 16))
    return _addrs


def address_of(name_or_addr: str) -> int | None:
    if re.fullmatch(r"(0x)?[0-9A-Fa-f]{8}", name_or_addr):
        return int(name_or_addr, 16)
    a = symbol_addrs().get(name_or_addr)
    if a is None:
        m = re.match(r"(?:fn|lbl)_([0-9A-Fa-f]{8})", name_or_addr)
        a = int(m.group(1), 16) if m else None
    return a


def best(addr: int | None, unit: str | None = None) -> str | None:
    """One line for tools: the most informative reference name, its builds, and a confidence note."""
    if addr is None or addr not in refs():
        return None
    entries = refs()[addr]
    # Prefer demangled map names (they carry parameter types), then the most common name.
    by_name = defaultdict(list)
    for name, build, obj in entries:
        by_name[name].append(build)
    name = max(by_name, key=lambda n: ("(" in n, len(by_name[n])))
    builds = sorted({b for _, b, _ in entries})
    obj = next((o for n, _, o in entries if n == name and o), "")
    objname = re.split(r"[\\/]", obj)[-1] if obj else ""
    area = unit.split("/")[1] if unit and unit.count("/") >= 2 else ""
    note = "  (game code: often a look-alike, check)" if area in GAME_AREAS else ""
    others = [n for n in by_name if n != name]
    alt = f"; also {', '.join(others[:2])}" if others else ""
    return f"{name}  [{', '.join(builds)}{', ' + objname if objname else ''}]{alt}{note}"


def unit_functions(unit: str):
    rep = json.loads(REPORT.read_text())
    u = unit if unit.startswith("main/") else "main/" + unit
    for x in rep["units"]:
        if x["name"] == u.removesuffix(".cpp").removesuffix(".c"):
            for f in x.get("functions", []):
                yield f["name"], f.get("size"), f.get("fuzzy_match_percent", 0) or 0


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("names", nargs="*", help="function names or addresses")
    ap.add_argument("--unit", help="list every function of a unit with its reference name")
    ap.add_argument("--stats", action="store_true", help="how much unmatched code has a reference name")
    args = ap.parse_args()
    if args.stats:
        rep = json.loads(REPORT.read_text())
        tot, named = defaultdict(lambda: [0, 0]), defaultdict(lambda: [0, 0])
        for u in rep["units"]:
            area = u["name"].split("/")[1] if u["name"].count("/") >= 2 else u["name"]
            for f in u.get("functions", []):
                if (f.get("fuzzy_match_percent", 0) or 0) >= 100:
                    continue
                sz = int(f.get("size", 0) or 0)
                tot[area][0] += 1
                tot[area][1] += sz
                if address_of(f["name"]) in refs():
                    named[area][0] += 1
                    named[area][1] += sz
        print("area: unmatched functions (bytes) | with a reference name (bytes)")
        for a in sorted(tot, key=lambda k: -tot[k][1]):
            print(f"  {a:10} {tot[a][0]:5} ({tot[a][1]:>9,}) | {named[a][0]:4} ({named[a][1]:>8,})")
        return
    if args.unit:
        for name, size, pct in unit_functions(args.unit):
            b = best(address_of(name), "main/" + args.unit)
            print(f"{name:40} {int(size or 0):#7x} {pct:6.1f}%  {b or '-'}")
        return
    for n in args.names:
        a = address_of(n)
        entries = refs().get(a, []) if a is not None else []
        print(f"== {n} ({a:#010x})" if a is not None else f"== {n}: unknown")
        if not entries:
            print("   no reference name")
        for name, build, obj in entries:
            print(f"   {build:7} {name}" + (f"   ({obj})" if obj else ""))


if __name__ == "__main__":
    main()
