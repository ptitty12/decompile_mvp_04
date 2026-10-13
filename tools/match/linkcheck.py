"""Find references in compiled source that will not link: callee names that
differ from the symbol the target defines at that address.

    python tools/match/linkcheck.py                 # summary + the 30 most-referenced mismatches
    python tools/match/linkcheck.py --unit game/tu_8026C414   # one unit's mismatches, with fixes
    python tools/match/linkcheck.py --top 100 --json > linkcheck.json

objdiff masks relocation names, so a call to `fn_80328234__FPvi` scores 100%
even when the symbol at 0x80328234 is the plain `fn_80328234` (an `extern "C"`
definition), and vice versa. Such a unit links only once every name agrees.
For each undefined symbol of every compiled object under build/GV4E69/src it
checks: is the name defined by symbols.txt or by another compiled object? If
not, it takes the address from the name (fn_/lbl_XXXXXXXX), lists what
symbols.txt calls that address, and, when that function is already written
in src/, prints its definition signature: the prototype to declare.

Mismatch kinds:
  c++->C    the caller uses a mangled name; the target symbol is plain: declare it extern "C"
  C->c++    the caller uses a plain name; the target symbol is mangled: declare it with C++ linkage and those parameters
  params    both mangled, different parameter lists: the declaration's parameter types are wrong
  renamed   symbols.txt now has a real name there (e.g. strncpy for fn_8040B830): call it by that name
  missing   no symbol at that address in symbols.txt (wrong address, or a symbol not split yet)

A return-type mismatch can't be seen here (g++ 2.95 does not mangle return
types); tools/match/protolint.py covers return types. Read-only; it verifies
nothing. objdiff and tools/verify/verify.py decide.
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools" / "match"))
from check_literals import BUILD, CODE_SECTIONS, Elf  # noqa: E402

SYMBOLS = ROOT / "config" / "GV4E69" / "symbols.txt"
ADDR_RE = re.compile(r"(?:fn|lbl)_([0-9A-Fa-f]{8})")
SYM_RE = re.compile(r"^(\S+) = ([.\w]+):0x([0-9A-Fa-f]+);")


def load_symbols():
    by_name, by_addr = {}, defaultdict(list)
    for line in SYMBOLS.read_text(encoding="utf-8").splitlines():
        m = SYM_RE.match(line)
        if m:
            addr = int(m.group(3), 16)
            by_name[m.group(1)] = (m.group(2), addr)
            by_addr[addr].append(m.group(1))
    return by_name, by_addr


def unit_of(obj: Path) -> str:
    return obj.relative_to(BUILD / "src").with_suffix("").as_posix()


def scan_objects():
    """defined: names defined by compiled objects; refs: name -> {unit: reference count}."""
    defined, refs = set(), defaultdict(lambda: defaultdict(int))
    for obj in sorted((BUILD / "src").rglob("*.o")):
        try:
            elf = Elf(obj)
        except Exception:
            continue
        unit = unit_of(obj)
        undef = {}
        for i, (name, value, size, info, shndx) in enumerate(elf.syms):
            if not name or info & 0xF == 4:  # unnamed / STT_FILE
                continue
            if shndx == 0:
                undef[i] = name
            elif info >> 4 in (1, 2):  # global / weak
                defined.add(name)
        if not undef:
            continue
        counted = set()
        for idx, secname in enumerate(elf.names):
            for _, (sym, _type, _add) in elf.relocs(idx).items():
                if sym in undef:
                    refs[undef[sym]][unit] += 1
                    counted.add(sym)
        for i, name in undef.items():
            if i not in counted:
                refs[name][unit] += 0  # declared and emitted but never relocated
    return defined, refs


def mangled(name: str) -> bool:
    return "__" in name.lstrip("_")


def params_of(name: str) -> str:
    m = re.search(r"__F(.*)$", name)
    return m.group(1) if m else ""


def base_name(name: str) -> str:
    m = re.match(r"(fn_[0-9A-Fa-f]{8}|lbl_[0-9A-Fa-f]{8})", name)
    if m:
        return m.group(1)
    return name.split("__", 1)[0] if mangled(name) else name


def classify(ref: str, canon: list[str]) -> str:
    if not canon:
        return "missing"
    if all(base_name(c) != base_name(ref) for c in canon):
        return "renamed"
    if mangled(ref) and not any(mangled(c) for c in canon):
        return "c++->C"
    if not mangled(ref) and all(mangled(c) for c in canon):
        return "C->c++"
    return "params"


def definition_of(name: str, report_units: dict, cache: dict):
    """(path:line, signature) of `name`'s definition in src/, if that function is written."""
    try:
        import twins  # same directory; reuses its g++ 2.95 name search
    except Exception:
        return None
    unit = report_units.get(name)
    if not unit:
        return None
    for pat in twins.search_patterns(name):
        for f in twins.unit_sources(unit):
            text = twins.file_text(f, cache)
            r = twins.extract_definition(text, pat)
            if r:
                sig = re.sub(r"\s+", " ", r[1].split("{", 1)[0].strip())
                return f"{f.as_posix()}:{r[0]}", sig
    return None


def report_unit_map():
    path = BUILD / "report.json"
    if not path.exists():
        return {}
    out = {}
    for u in json.loads(path.read_text()).get("units", []):
        for f in u.get("functions", []):
            out.setdefault(f["name"], u["name"])
    return out


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--unit", help="only references made by this unit (e.g. game/tu_8026C414)")
    ap.add_argument("--top", type=int, default=30, help="how many callees to list (default 30)")
    ap.add_argument("--json", action="store_true")
    args = ap.parse_args()

    by_name, by_addr = load_symbols()
    defined, refs = scan_objects()
    report_units = report_unit_map()
    unit_filter = args.unit.removeprefix("main/").removesuffix(".cpp").removesuffix(".c") if args.unit else None

    rows = []
    for ref, units in refs.items():
        if ref in by_name or ref in defined:
            continue
        if unit_filter:
            units = {u: n for u, n in units.items() if u == unit_filter}
            if not units:
                continue
        m = ADDR_RE.search(ref)
        if not m:
            continue  # runtime/library names (memcpy, __ptmf_*): not address-named
        addr = int(m.group(1), 16)
        canon = by_addr.get(addr, [])
        rows.append({
            "ref": ref,
            "addr": f"{addr:#010x}",
            "kind": classify(ref, canon),
            "symbols_txt": canon,
            "units": dict(sorted(units.items())),
            "sites": sum(units.values()),
        })
    rows.sort(key=lambda r: (-len(r["units"]), -r["sites"], r["ref"]))

    cache: dict = {}
    for r in rows[: args.top] if not unit_filter else rows:
        for c in r["symbols_txt"][:1]:
            d = definition_of(c, report_units, cache)
            if d:
                r["definition"] = {"where": d[0], "signature": d[1]}

    if args.json:
        json.dump(rows, sys.stdout, indent=1)
        return

    kinds = defaultdict(lambda: [0, 0, set()])
    for r in rows:
        k = kinds[r["kind"]]
        k[0] += 1
        k[1] += r["sites"]
        k[2].update(r["units"])
    scope = f"unit {unit_filter}" if unit_filter else "all compiled units"
    print(f"linkcheck ({scope}): {len(rows)} referenced names have no matching symbol")
    for kind, (n, sites, units) in sorted(kinds.items(), key=lambda kv: -kv[1][1]):
        print(f"  {kind:8} {n:5} names  {sites:6} relocations  in {len(units)} units")
    print()
    shown = rows if unit_filter else rows[: args.top]
    for r in shown:
        target = ", ".join(r["symbols_txt"]) or "(nothing at that address)"
        print(f"{r['kind']:8} {r['ref']}  ->  symbols.txt: {target}")
        print(f"         {r['sites']} relocations in {len(r['units'])} units: " + ", ".join(list(r["units"])[:6])
              + (" ..." if len(r["units"]) > 6 else ""))
        if "definition" in r:
            print(f"         defined as: {r['definition']['signature']}   ({r['definition']['where']})")
        elif r["kind"] == "c++->C":
            print('         fix: declare it extern "C" (keep the parameters the original passes)')
    if not unit_filter and len(rows) > args.top:
        print(f"... {len(rows) - args.top} more; use --unit or --top")


if __name__ == "__main__":
    main()
