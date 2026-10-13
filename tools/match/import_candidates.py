"""Find likely retail providers for imports via paired REL24 call sites.

Address/name candidates from matched relocations are leads, not ABI proof.
"""
import argparse, json, re, sys
from collections import defaultdict
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools" / "match"))
from check_literals import BUILD, CODE_SECTIONS, Elf
from link_candidates import candidates as link_candidates


def address_map(main, symbols_file, aliases_file=None):
    result = {}
    for name, value, _, info, shndx in main.syms:
        if shndx and info >> 4 and info & 15 == 2:
            result.setdefault(name, value)
    for line in symbols_file.read_text(encoding="utf-8").splitlines():
        m = re.match(r"^(\S+) = [.\w]+:0x([0-9A-Fa-f]+);", line)
        if m: result[m.group(1)] = int(m.group(2), 16)
    if aliases_file and aliases_file.is_file():
        for line in aliases_file.read_text(encoding="utf-8").splitlines():
            p = line.split("\t")
            if len(p) >= 2 and not line.startswith("#") and p[1] in result:
                result.setdefault(p[0], result[p[1]])
    return result


def exported_functions_by_address(main):
    out = defaultdict(set)
    for n, v, _, info, shndx in main.syms:
        if shndx and info >> 4 and info & 15 == 2: out[v].add(n)
    return {a: sorted(ns) for a, ns in out.items()}


def _sections(source, retail, funcs):
    pairs = {}
    for name in funcs:
        for secname in CODE_SECTIONS:
            if secname not in source.names or secname not in retail.names: continue
            si, ri = source.names.index(secname), retail.names.index(secname)
            if name in source.funcs(si) and name in retail.funcs(ri):
                pairs[name] = (si, ri)
                break
    return pairs


def _code_base(retail, ri, addr_of):
    bases = {addr_of[n] - v for n, (v, _) in retail.funcs(ri).items() if n in addr_of}
    return next(iter(bases)) if len(bases) == 1 else None


def _destination(retail, rel, ri, base, addr_of):
    symidx, kind, addend = rel
    if kind != 10: return None, None
    name, value, _, _, shndx = retail.syms[symidx]
    if shndx == 0:
        addr = addr_of.get(name)
        return (addr + addend, name) if addr is not None else (None, name)
    if shndx == ri:
        return (base + value + addend, name) if base is not None else (None, name)
    if shndx == 0xFFF1: return value + addend, name
    secaddr = retail.secs[shndx][3] if shndx < len(retail.secs) else 0
    return (secaddr + value + addend, name) if secaddr else (None, name)


def paired_imports(source, retail, main, missing_imports, matched_functions, addr_of=None):
    """Map missing source import -> paired retail REL24 destination(s)."""
    addr_of = addr_of or {}
    exports = exported_functions_by_address(main)
    pairs = _sections(source, retail, matched_functions)
    groups = defaultdict(lambda: defaultdict(lambda: {
        "address": None, "names": set(), "retail_symbols": set(), "call_sites": []}))
    for fn in matched_functions:
        if fn not in pairs: continue
        si, ri = pairs[fn]
        sf, rf = source.funcs(si), retail.funcs(ri)
        sv, ssize = sf[fn]; rv, rsize = rf[fn]
        if ssize != rsize:
            continue
        base = _code_base(retail, ri, addr_of)
        sr, rr = source.relocs(si), retail.relocs(ri)
        for off in range(sv, sv + ssize):
            srel = sr.get(off)
            if not srel or srel[1] != 10: continue
            ssym = source.syms[srel[0]]
            if ssym[4] != 0 or ssym[0] not in missing_imports: continue
            relative = off - sv
            if relative >= rsize: continue
            rrel = rr.get(rv + relative)
            if not rrel or rrel[1] != 10: continue
            addr, rname = _destination(retail, rrel, ri, base, addr_of)
            key = addr if addr is not None else "unresolved:" + str(rname)
            item = groups[ssym[0]][key]
            item["address"] = addr; item["retail_symbols"].add(rname)
            if addr is not None: item["names"].update(exports.get(addr, ()))
            item["call_sites"].append({"function": fn, "offset": relative})
    result = {}
    for old, targets in sorted(groups.items()):
        rows = []
        for _, item in sorted(targets.items(), key=lambda x: str(x[0])):
            rows.append({"address": f"0x{item['address']:08X}" if item["address"] is not None else None,
                         "names": sorted(item["names"]),
                         "retail_symbols": sorted(item["retail_symbols"]),
                         "call_sites": sorted(item["call_sites"], key=lambda x: (x["function"], x["offset"]))})
        result[old] = {"ambiguous": len(rows) > 1, "retail_targets": rows}
    return result


def _full_functions(unit):
    return [f["name"] for f in unit.get("functions", []) if f.get("fuzzy_match_percent") == 100.0]


def run_unit(name, report, main, addr_of):
    unit = next((u for u in report["units"] if u["name"].removeprefix("main/") == name), None)
    if unit is None: return None
    srcp, retp = BUILD / "src" / (name + ".o"), BUILD / "obj" / (name + ".o")
    if not srcp.is_file() or not retp.is_file(): return None
    rows = link_candidates({"units": [unit]}, main)
    missing = rows[0]["missing"] if rows else []
    candidates = paired_imports(Elf(srcp), Elf(retp), main, set(missing), _full_functions(unit), addr_of)
    unpaired = sorted(set(missing) - set(candidates))
    return {"unit": name, "missing_imports": missing, "candidates": candidates,
            "unpaired_imports": unpaired}


def main_cli():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("units", nargs="*", help="units; default: fully matched candidates with missing imports")
    ap.add_argument("--json", action="store_true"); ap.add_argument("--limit", type=int, default=30)
    args = ap.parse_args()
    if args.limit < 1: ap.error("--limit must be positive")
    try:
        report = json.loads((BUILD / "report.json").read_text(encoding="utf-8"))
        main = Elf(BUILD / "main.elf")
        addr = address_map(main, ROOT / "config" / "GV4E69" / "symbols.txt",
                           ROOT / "tools" / "match" / "symbol_aliases.tsv")
        rows = link_candidates(report, main)
    except OSError as e: ap.error(f"missing build input: {e}; run configure.py and ninja first")
    names = args.units or [r["unit"] for r in rows if r["same_layout"] and r["missing"]]
    names = names[:args.limit]
    output = [r for n in names if (r := run_unit(n, report, main, addr)) is not None]
    if args.json:
        print(json.dumps({"warning": "Call-site address/name candidates do not prove ABI or matching; verify retail hash, literals, and the unmodified verifier.",
                          "units": output}, indent=2)); return
    for row in output:
        print(f"{row['unit']}: {len(row['missing_imports'])} missing import(s), "
              f"{len(row['unpaired_imports'])} unpaired")
        for old, info in row["candidates"].items():
            for target in info["retail_targets"]:
                names = ", ".join(target["names"]) or "<no global function name>"
                tag = " [AMBIGUOUS]" if info["ambiguous"] or len(target["names"]) > 1 else ""
                print(f"  {old} -> {target['address'] or 'unresolved'} {names}{tag} ({len(target['call_sites'])} call site(s))")
        if row["unpaired_imports"]:
            print("  no paired call site: " + ", ".join(row["unpaired_imports"]))


if __name__ == "__main__": main_cli()

