"""Which EA datafile classes a function reads, with their field names.

    python tools/match/datafile.py fn_802FA22C fn_80276808    # classes a function builds the hash of
    python tools/match/datafile.py --schema 0x6D896082          # one class: fields and the functions using it
    python tools/match/datafile.py --stats                      # coverage, matched vs unmatched

The game's tuning data lives in EA "datafile" records looked up by a 32-bit
hash of the class (docs/GAME_DATA.md). Code builds those hashes with
`lis rX,hi` + `ori/addi rX,rX,lo`. config/GV4E69/datafile_schemas.tsv holds the
class schemas (field index -> field name, names only) from MVP Baseball 2004's
GameCube data files. 110 of its 131 classes appear in MVP 2005's code, in about
260 functions, so a field index loaded next to the hash usually names the
struct field or tuning value the function reads.

Reads orig/GV4E69/mvp.elf (the disc's stripped ELF, present in every
provisioned worktree) and config/GV4E69/symbols.txt. It decides nothing about
matching.
"""
from __future__ import annotations

import argparse
import bisect
import json
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SCHEMAS = ROOT / "config" / "GV4E69" / "datafile_schemas.tsv"
ELF = ROOT / "orig" / "GV4E69" / "mvp.elf"
SYMBOLS = ROOT / "config" / "GV4E69" / "symbols.txt"
REPORT = ROOT / "build" / "GV4E69" / "report.json"

_cache: dict = {}


def schemas() -> dict[int, dict]:
    if "schemas" not in _cache:
        out = {}
        for line in SCHEMAS.read_text(encoding="utf-8").splitlines():
            if line.startswith("#") or not line.strip():
                continue
            h, n, src, fields = (line.split("\t") + ["", "", "", ""])[:4]
            fmap = {}
            for part in fields.split("|") if fields else []:
                i, _, name = part.partition(":")
                if i.isdigit():
                    fmap[int(i)] = name
            out[int(h, 16)] = {"count": int(n or 0), "source": src, "fields": fmap}
        _cache["schemas"] = out
    return _cache["schemas"]


def functions():
    if "funcs" not in _cache:
        funcs = []
        for line in SYMBOLS.read_text(encoding="utf-8").splitlines():
            m = re.match(r"^(\S+) = [.\w]+:0x([0-9A-Fa-f]+); // type:function size:0x([0-9A-Fa-f]+)", line)
            if m:
                funcs.append((int(m.group(2), 16), int(m.group(3), 16), m.group(1)))
        funcs.sort()
        _cache["funcs"] = funcs
        _cache["starts"] = [f[0] for f in funcs]
    return _cache["funcs"], _cache["starts"]


def fn_at(addr: int):
    funcs, starts = functions()
    i = bisect.bisect_right(starts, addr) - 1
    if i >= 0 and funcs[i][0] <= addr < funcs[i][0] + funcs[i][1]:
        return funcs[i]
    return None


def sites() -> dict[str, dict[int, list[int]]]:
    """function name -> {schema hash: [addresses where the hash is built]}"""
    if "sites" in _cache:
        return _cache["sites"]
    known = schemas()
    d = ELF.read_bytes()
    shoff, = struct.unpack_from(">I", d, 0x20)
    shentsize, shnum, _ = struct.unpack_from(">HHH", d, 0x2E)
    out: dict[str, dict[int, list[int]]] = defaultdict(lambda: defaultdict(list))
    for k in range(shnum):
        s = struct.unpack_from(">IIIIIIIIII", d, shoff + k * shentsize)
        if s[1] == 8 or s[5] == 0 or not (s[2] & 4):  # NOBITS, empty, or not executable
            continue
        b = d[s[4]:s[4] + s[5]]
        words = struct.unpack(f">{len(b) // 4}I", b[: len(b) // 4 * 4])
        for i, w in enumerate(words):
            if w >> 26 != 15 or (w >> 16) & 31:  # lis rD,hi only
                continue
            rd, hi = (w >> 21) & 31, w & 0xFFFF
            for j in range(i + 1, min(i + 10, len(words))):
                x, op = words[j], words[j] >> 26
                v = None
                if op == 24 and (x >> 21) & 31 == rd:  # ori rD,rD,lo
                    v = (hi << 16) | (x & 0xFFFF)
                elif op == 14 and (x >> 16) & 31 == rd:  # addi rX,rD,lo
                    lo = x & 0xFFFF
                    v = ((hi << 16) + (lo - 0x10000 if lo & 0x8000 else lo)) & 0xFFFFFFFF
                if v is not None:
                    if v in known:
                        a = s[3] + 4 * i
                        f = fn_at(a)
                        out[f[2] if f else f"?{a:#x}"][v].append(a)
                    break
    _cache["sites"] = out
    return out


def describe(h: int, limit: int = 12) -> str:
    sc = schemas().get(h)
    if not sc:
        return f"{h:#010x}: unknown"
    names = [sc["fields"][k] for k in sorted(sc["fields"])]
    more = f", ... {len(names) - limit} more" if len(names) > limit else ""
    return f"0x{h:08X} ({sc['count']} fields, {sc['source']}): {', '.join(names[:limit])}{more}"


def summary_for(fn: str) -> list[str]:
    """Lines for twins.py: the datafile classes this function builds hashes for."""
    s = sites()
    hs = s.get(fn)
    if hs is None:
        hs = next((v for k, v in s.items() if k.startswith(fn + "__")), None)
    return [describe(h, 10) for h in sorted(hs)] if hs else []


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("fns", nargs="*")
    ap.add_argument("--schema", help="one class by hash")
    ap.add_argument("--stats", action="store_true")
    args = ap.parse_args()
    s = sites()
    if args.schema:
        h = int(args.schema, 16)
        print(describe(h, 1000))
        users = sorted(fn for fn, hs in s.items() if h in hs)
        print(f"used by {len(users)} functions: {', '.join(users) or '-'}")
        return
    if args.stats:
        status = {}
        if REPORT.exists():
            for u in json.loads(REPORT.read_text())["units"]:
                for f in u.get("functions", []):
                    status[f["name"]] = (f.get("fuzzy_match_percent", 0) or 0, int(f.get("size", 0) or 0))
        used = {h for hs in s.values() for h in hs}
        unmatched = [(fn, status.get(fn, (0, 0))[1]) for fn in s if status.get(fn, (0, 0))[0] < 100]
        print(f"classes in table: {len(schemas())}, used by code: {len(used)}")
        print(f"functions building class hashes: {len(s)}, unmatched: {len(unmatched)} ({sum(b for _, b in unmatched):,} B)")
        for fn, b in sorted(unmatched, key=lambda x: -x[1]):
            print(f"  {fn}  {b:#x} B")
        return
    for fn in args.fns:
        lines = summary_for(fn)
        print(f"== {fn}")
        print("\n".join("   " + l for l in lines) if lines else "   no datafile class hashes")


if __name__ == "__main__":
    main()
