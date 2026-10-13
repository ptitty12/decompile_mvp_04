"""Rank fully matched source objects for source-link trials (read-only).

    python tools/match/link_candidates.py [--limit 30] [--json] [--all | --footprint]

Requires a successful current build. Candidates have 100% matched code/data,
the same allocated section layout as their retail split object, and preferably
no undefined references missing from main.elf. Layout/import checks are a
shortlist, not proof: per-function section-relative placement, relocations and
alignment can still differ despite equal section sizes. JSON includes target
and source function offsets/sizes plus missing, extra, moved, and ambiguous names.
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


def allocated_footprint(obj):
    """Section names/types/sizes, ignoring object order, flags and alignment."""
    return sorted((name, sec[1], sec[5])
                  for name, sec in zip(obj.names, obj.secs) if sec[2] & 2 and sec[5])


def executable_function_layout(obj):
    """Return STT_FUNC locations in allocated executable sections.

    Offsets are section-relative. Undefined, absolute, data, debug, and other
    non-executable symbols are ignored. Keep duplicate symbols: identical
    entries can be aliases, while conflicting same-name entries are ambiguous.
    """
    functions = {}
    for name, value, size, info, shndx in obj.syms:
        if info & 0xF != 2 or shndx == 0 or shndx >= len(obj.secs):
            continue
        section = obj.secs[shndx]
        if section[2] & 6 != 6:  # SHF_ALLOC | SHF_EXECINSTR
            continue
        section_name = obj.names[shndx]
        location = (section_name, value - section[3], size)
        functions.setdefault(name, []).append(location)
    return {name: sorted(locations) for name, locations in functions.items()}


def compare_function_layout(target, source):
    """Compare function names and placements without relying on ELF order."""
    target_funcs = executable_function_layout(target)
    source_funcs = executable_function_layout(source)
    details = []
    missing, extra, moved, ambiguous = [], [], [], []

    def render(locations):
        return [{"section": section, "offset": offset, "size": size}
                for section, offset, size in locations]

    for name in sorted(set(target_funcs) | set(source_funcs)):
        target_locations = target_funcs.get(name, [])
        source_locations = source_funcs.get(name, [])
        if not source_locations:
            status = "missing"
            missing.append(name)
        elif not target_locations:
            status = "extra"
            extra.append(name)
        elif any(location[2] == 0 for location in target_locations + source_locations):
            # A zero-sized symbol has no verified function extent. Keep it
            # visible but don't let it establish a ready source-link candidate.
            status = "ambiguous"
            ambiguous.append(name)
        elif len(set(target_locations)) > 1 or len(set(source_locations)) > 1:
            # Same-name symbols at distinct locations cannot be paired safely,
            # even if both objects happen to contain the same ambiguous set.
            status = "ambiguous"
            ambiguous.append(name)
        elif target_locations == source_locations:
            status = "same"
        elif len(target_locations) == len(source_locations) == 1:
            status = "moved"
            moved.append(name)
        else:
            # Duplicate names at distinct locations cannot be paired safely.
            status = "ambiguous"
            ambiguous.append(name)
        details.append({"name": name, "status": status,
                        "target": render(target_locations),
                        "source": render(source_locations)})

    return {
        "same": bool(details) and not (missing or extra or moved or ambiguous),
        "target": [{"name": name, "section": sec, "offset": off, "size": size}
                   for name, locations in sorted(target_funcs.items())
                   for sec, off, size in locations],
        "source": [{"name": name, "section": sec, "offset": off, "size": size}
                   for name, locations in sorted(source_funcs.items())
                   for sec, off, size in locations],
        "missing": missing,
        "extra": extra,
        "moved": moved,
        "ambiguous": ambiguous,
        "details": details,
    }


def candidate_ready(row, allow_footprint=False):
    return (row["same_function_layout"]
            and (row["same_layout"] or allow_footprint and row["same_footprint"])
            and not row["missing"])


def format_function_locations(locations):
    return ", ".join(f"{loc['section']}+0x{loc['offset']:X}/0x{loc['size']:X}"
                      for loc in locations) or "—"


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
        function_layout = compare_function_layout(retail, built)
        local = {s[0] for s in built.syms if s[4] != 0}
        missing = sorted({s[0] for s in built.syms
                          if s[4] == 0 and s[3] >> 4 != 0 and s[0] not in exports | local})
        rows.append({"unit": name, "source": meta["source_path"],
                     "bytes": int(m["total_code"]), "missing": missing,
                     "same_layout": allocated_layout(retail) == allocated_layout(built),
                     "same_footprint": allocated_footprint(retail) == allocated_footprint(built),
                     "same_function_layout": function_layout["same"],
                     "function_layout": function_layout})
    return sorted(rows, key=lambda r: (not r["same_layout"],
                                       not r["same_function_layout"],
                                       len(r["missing"]), -r["bytes"], r["unit"]))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--limit", type=int, default=30)
    ap.add_argument("--json", action="store_true", help="print structured shortlist")
    ap.add_argument("--all", action="store_true", help="also list mismatched section layouts")
    ap.add_argument("--footprint", action="store_true", help="also shortlist equal section sizes/types despite order, flags or alignment differences")
    a = ap.parse_args()
    if a.limit < 1:
        ap.error("--limit must be positive")
    try:
        report = json.loads((BUILD / "report.json").read_text(encoding="utf-8"))
        rows = candidates(report, Elf(BUILD / "main.elf"))
    except OSError as e:
        ap.error(f"missing build input: {e}; run configure.py and ninja first")
    rows = [r for r in rows if a.all or r["same_layout"] or a.footprint and r["same_footprint"]]
    if a.json:
        print(json.dumps(rows[:a.limit], indent=2))
        return
    ready = [r for r in rows if candidate_ready(r, allow_footprint=a.footprint)]
    print(f"{len(rows)} candidates; {len(ready)} with shortlisted layouts/footprints and resolved imports "
          f"({sum(r['bytes'] for r in ready)} code bytes). Still require a retail-hash trial.")
    print("Ready also requires identical per-function section-relative placement, not just equal section sizes.")
    if a.footprint:
        print("Equal footprints do not prove placement: final retail hash, literal checks and verifier remain required.")
    for r in rows[:a.limit]:
        layout = 'layout OK' if r['same_layout'] else 'footprint only' if r['same_footprint'] else 'layout differs'
        function_layout = 'functions OK' if r['same_function_layout'] else 'function placement differs'
        print(f"{r['bytes']:6} B  {len(r['missing']):3} missing  {layout:14}  "
              f"{function_layout:28}  {r['unit']}")
        if r["missing"]:
            print("    " + ", ".join(r["missing"]))
        details = r["function_layout"]
        if details["moved"] or details["missing"] or details["extra"] or details["ambiguous"]:
            print("    function placement: "
                  f"{len(details['moved'])} moved, {len(details['missing'])} missing, "
                  f"{len(details['extra'])} extra, {len(details['ambiguous'])} ambiguous")
            if a.all:
                for function in details["details"]:
                    if function["status"] == "same":
                        continue
                    print(f"      {function['status']:9} {function['name']}: "
                          f"target {format_function_locations(function['target'])}; "
                          f"source {format_function_locations(function['source'])}")


if __name__ == "__main__":
    main()
