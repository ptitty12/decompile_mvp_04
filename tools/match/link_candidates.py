"""Rank fully matched source objects for source-link trials (read-only).

    python tools/match/link_candidates.py [--limit 30] [--json] [--all]

Requires a successful current build. Candidates have 100% matched code/data,
the same allocated section layout as their retail split object, and preferably
no undefined references missing from main.elf. Layout/import checks are a
shortlist, not proof: object ordering, relocations and alignment can still fail.
Switch ONE unit's Object flag to Matching, rebuild, and keep it only when the
retail DOL hash, check_literals and unmodified verifier all pass. Never alter
the linker script or add address aliases to make a candidate pass.
"""
import argparse
import json
from check_literals import Elf, BUILD


def allocated_layout(obj):
    return [(name, sec[1], sec[2], sec[5], sec[8])
            for name, sec in zip(obj.names, obj.secs) if sec[2] & 2 and sec[5]]


def candidates(report, linked):
    exports = {s[0] for s in linked.syms if s[4] != 0 and s[3] >> 4 != 0}
    rows = []
    for unit in report["units"]:
        m, meta = unit["measures"], unit.get("metadata", {})
        name = unit["name"].removeprefix("main/")
        if (not int(m.get("total_code", 0)) or m.get("matched_code_percent", 0) != 100
                or meta.get("complete") or not meta.get("source_path")):
            continue
        if int(m.get("total_data", 0)) and m.get("matched_data_percent", 0) != 100:
            continue
        target, source = BUILD / "obj" / f"{name}.o", BUILD / "src" / f"{name}.o"
        if not target.is_file() or not source.is_file():
            continue
        retail, built = Elf(target), Elf(source)
        local = {s[0] for s in built.syms if s[4] != 0}
        missing = sorted({s[0] for s in built.syms
                          if s[4] == 0 and s[3] >> 4 != 0 and s[0] not in exports | local})
        rows.append({"unit": name, "source": meta["source_path"],
                     "bytes": int(m["total_code"]), "missing": missing,
                     "same_layout": allocated_layout(retail) == allocated_layout(built)})
    return sorted(rows, key=lambda r: (not r["same_layout"], len(r["missing"]), -r["bytes"], r["unit"]))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--limit", type=int, default=30)
    ap.add_argument("--json", action="store_true", help="print structured shortlist")
    ap.add_argument("--all", action="store_true", help="also list mismatched section layouts")
    a = ap.parse_args()
    if a.limit < 1:
        ap.error("--limit must be positive")
    try:
        report = json.loads((BUILD / "report.json").read_text(encoding="utf-8"))
        rows = candidates(report, Elf(BUILD / "main.elf"))
    except OSError as e:
        ap.error(f"missing build input: {e}; run configure.py and ninja first")
    rows = [r for r in rows if a.all or r["same_layout"]]
    if a.json:
        print(json.dumps(rows[:a.limit], indent=2))
        return
    ready = [r for r in rows if r["same_layout"] and not r["missing"]]
    print(f"{len(rows)} candidates; {len(ready)} with matching layouts and resolved imports "
          f"({sum(r['bytes'] for r in ready)} code bytes). Still require a retail-hash trial.")
    for r in rows[:a.limit]:
        print(f"{r['bytes']:6} B  {len(r['missing']):3} missing  "
              f"{'layout OK' if r['same_layout'] else 'layout differs':14}  {r['unit']}")
        if r["missing"]:
            print("    " + ", ".join(r["missing"]))


if __name__ == "__main__":
    main()
