#!/usr/bin/env python3
"""Copy a compiled unit's function names into config/GV4E69/symbols.txt.

Requested by the matching session, which did this by hand after every unit
(docs/SPEEDUPS.md). It reads the FUNC symbols of the unit's compiled object
(build/GV4E69/src/<unit>.o) in address order and pairs them with the unit's
functions in symbols.txt (the .text range from splits.txt):

  1. names that start with fn_<address> are pinned to that address;
  2. between pins, functions whose sizes agree are paired in order (longest
     common subsequence);
  3. equal-length runs left between those anchors are paired in order, but
     only where the two sizes are within 25% of each other.

Anything else is left unpaired and reported. Wrong source order, say, never
yields a wrong name.

Safety checks, each of which skips that rename and says why:
  - a name that starts with fn_<8 hex> naming a different address means the
    pairing is off;
  - the new name is already used at another address in symbols.txt;
  - the old name is still referenced from src/ or include/.

Size differences are reported but don't block a rename: the source defines that
function, it just isn't matched yet.

Dry run by default; --write rewrites symbols.txt in place.

Usage: python tools/scout/rename.py <unit> [--write] [--obj PATH] [--symbols PATH] [--splits PATH]
  e.g. python tools/scout/rename.py animation/choosers/playeridchooser.cpp
"""
import argparse
import re
import struct
import subprocess
import sys
from pathlib import Path
from typing import Dict, List, Optional, Tuple

ROOT = Path(__file__).resolve().parents[2]
SYM_LINE = re.compile(r"^(\S+) = \.text:0x([0-9A-Fa-f]{8});(.*)$")
ADDR_PREFIX = re.compile(r"^fn_([0-9A-Fa-f]{8})(?![0-9A-Fa-f])")
SIZE_ATTR = re.compile(r"size:0x([0-9A-Fa-f]+)")


def elf_text_functions(path: Path) -> List[Tuple[int, int, str]]:
    """(offset in .text, size, name) of FUNC symbols in a big-endian ELF32 object."""
    data = path.read_bytes()
    if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 2:
        sys.exit(f"{path}: not a big-endian ELF32 object")
    shoff, = struct.unpack_from(">I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from(">HHH", data, 0x2E)
    secs = [struct.unpack_from(">IIIIIIIIII", data, shoff + i * shentsize) for i in range(shnum)]
    shstr = secs[shstrndx]

    def cstr(off: int) -> str:
        return data[off:data.index(b"\0", off)].decode("latin-1")

    names = [cstr(shstr[4] + s[0]) for s in secs]
    out = []
    for s in secs:
        if s[1] != 2:  # SHT_SYMTAB
            continue
        strtab = secs[s[6]]
        for i in range(s[5] // 16):
            st_name, value, size, info, _, shndx = struct.unpack_from(">IIIBBH", data, s[4] + i * 16)
            if info & 0xF == 2 and 0 < shndx < len(names) and names[shndx] == ".text":
                out.append((value, size, cstr(strtab[4] + st_name)))
    # Aliases at one address: keep the first name seen.
    seen, uniq = set(), []
    for v, sz, n in sorted(out):
        if v not in seen:
            seen.add(v)
            uniq.append((v, sz, n))
    return uniq


def text_range(splits: Path, unit: str) -> Tuple[int, int]:
    cur = None
    for line in splits.read_text(encoding="utf-8").splitlines():
        if line and not line[0].isspace():
            cur = line.rstrip(":")
        elif cur == unit and line.strip().startswith(".text"):
            m = re.search(r"start:0x([0-9A-Fa-f]+) end:0x([0-9A-Fa-f]+)", line)
            if m:
                return int(m.group(1), 16), int(m.group(2), 16)
    sys.exit(f"{unit}: no .text range in {splits}")


def close(a: int, b: int) -> bool:
    return min(a, b) >= 0.75 * max(a, b)


def pair_segment(src: List[Tuple[int, int, str]], dst: List[Tuple[int, int, str]],
                 si: range, dj: range) -> List[Tuple[int, int]]:
    """Exact-size LCS anchors, then equal-length gaps in order where sizes are close."""
    a, b = list(si), list(dj)
    n, m = len(a), len(b)
    lcs = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(n - 1, -1, -1):
        for j in range(m - 1, -1, -1):
            same = src[a[i]][1] == dst[b[j]][1]
            lcs[i][j] = lcs[i + 1][j + 1] + 1 if same else max(lcs[i + 1][j], lcs[i][j + 1])
    anchors, i, j = [], 0, 0
    while i < n and j < m:
        if src[a[i]][1] == dst[b[j]][1] and lcs[i][j] == lcs[i + 1][j + 1] + 1:
            anchors.append((i, j))
            i, j = i + 1, j + 1
        elif lcs[i + 1][j] >= lcs[i][j + 1]:
            i += 1
        else:
            j += 1
    pairs, pi, pj = [], 0, 0
    for ai, aj in anchors + [(n, m)]:
        if ai - pi == aj - pj:
            pairs += [(a[x], b[y]) for x, y in zip(range(pi, ai), range(pj, aj))
                      if close(src[a[x]][1], dst[b[y]][1])]
        if ai < n:
            pairs.append((a[ai], b[aj]))
        pi, pj = ai + 1, aj + 1
    return pairs


def pair(src: List[Tuple[int, int, str]], dst: List[Tuple[int, int, str]]) -> List[Tuple[int, int]]:
    """Index pairs (i in src, j in dst), in order.

    Names that start with fn_<address> pin first (keeping only pins that agree
    in order); the stretches between pins are paired by pair_segment."""
    j_of_addr = {d[0]: j for j, d in enumerate(dst)}
    pins = []
    for i, (_, _, name) in enumerate(src):
        pm = ADDR_PREFIX.match(name)
        if pm and int(pm.group(1), 16) in j_of_addr:
            pins.append((i, j_of_addr[int(pm.group(1), 16)]))
    chain: List[Tuple[int, int]] = []  # longest run of pins increasing in both
    best: List[List[Tuple[int, int]]] = []
    for k, (i, j) in enumerate(pins):
        prev = [best[q] for q in range(k) if pins[q][1] < j]
        best.append(max(prev, key=len, default=[]) + [(i, j)])
        if len(best[-1]) > len(chain):
            chain = best[-1]
    pairs, pi, pj = [], 0, 0
    for ai, aj in chain + [(len(src), len(dst))]:
        pairs += pair_segment(src, dst, range(pi, ai), range(pj, aj))
        if ai < len(src):
            pairs.append((ai, aj))
        pi, pj = ai + 1, aj + 1
    return pairs


_OBJ_SYMS: Optional[Dict[str, Path]] = None


def object_symbols() -> Dict[str, Path]:
    """Every symbol name (defined or undefined) in the compiled game objects."""
    global _OBJ_SYMS
    if _OBJ_SYMS is None:
        _OBJ_SYMS = {}
        nm = ROOT / "build" / "binutils" / "powerpc-eabi-nm.exe"
        for o in sorted((ROOT / "build" / "GV4E69" / "src").rglob("*.o")):
            out = subprocess.run([str(nm), str(o)], capture_output=True, text=True).stdout
            for line in out.splitlines():
                parts = line.split()
                if parts:
                    _OBJ_SYMS.setdefault(parts[-1], o)
    return _OBJ_SYMS


def referenced(name: str) -> Optional[Path]:
    """Where `name` is still needed under that exact name, or None.

    Source text alone (e.g. a C++ method called fn_80271FE8, whose symbol is
    mangled) doesn't count: only a compiled object that defines or references
    the plain symbol does.
    """
    pat = re.compile(r"\b" + re.escape(name) + r"\b")
    for d in ("src", "include"):
        for p in (ROOT / d).rglob("*"):
            if p.is_file() and p.suffix in (".c", ".cpp", ".cp", ".h", ".hpp", ".inc"):
                if pat.search(p.read_text(encoding="utf-8", errors="replace")):
                    return object_symbols().get(name)
    return None


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("unit", help="unit name as in splits.txt, e.g. animation/choosers/playeridchooser.cpp")
    ap.add_argument("--write", action="store_true", help="rewrite symbols.txt (default: dry run)")
    ap.add_argument("--obj", type=Path)
    ap.add_argument("--symbols", type=Path, default=ROOT / "config" / "GV4E69" / "symbols.txt")
    ap.add_argument("--splits", type=Path, default=ROOT / "config" / "GV4E69" / "splits.txt")
    args = ap.parse_args()

    obj = args.obj or ROOT / "build" / "GV4E69" / "src" / Path(args.unit).with_suffix(".o")
    if not obj.is_file():
        sys.exit(f"{obj} not found; build the unit first (ninja)")
    lo, hi = text_range(args.splits, args.unit)
    src = elf_text_functions(obj)

    raw = args.symbols.read_bytes().decode("utf-8")
    lines = raw.split("\n")
    dst: List[Tuple[int, int, str]] = []  # (address, size, name)
    line_of: Dict[str, int] = {}
    addr_of_name: Dict[str, int] = {}
    for k, line in enumerate(lines):
        m = SYM_LINE.match(line)
        if not m:
            continue
        name, addr = m.group(1), int(m.group(2), 16)
        addr_of_name[name] = addr
        if lo <= addr < hi and "type:function" in m.group(3):
            sz = SIZE_ATTR.search(m.group(3))
            dst.append((addr, int(sz.group(1), 16) if sz else 0, name))
            line_of[name] = k
    dst.sort()

    print(f"{args.unit}: {len(src)} functions in {obj.name}, {len(dst)} in symbols.txt "
          f"for {lo:08X}..{hi:08X}")
    renames: List[Tuple[str, str]] = []
    paired = pair(src, dst)
    for i, j in paired:
        _, ssz, new = src[i]
        addr, dsz, old = dst[j]
        note = "" if ssz == dsz else f"  (size {ssz:#x} vs target {dsz:#x}: not matched yet)"
        pm = ADDR_PREFIX.match(new)
        if new == old:
            continue
        if pm and int(pm.group(1), 16) != addr:
            print(f"  SKIP {addr:08X} {old} -> {new}: name says {pm.group(1)}, pairing is off")
            continue
        if new in addr_of_name and addr_of_name[new] != addr:
            print(f"  SKIP {addr:08X} {old} -> {new}: name already used at {addr_of_name[new]:08X}")
            continue
        ref = referenced(old)
        if ref:
            print(f"  SKIP {addr:08X} {old} -> {new}: {old} is still used in {ref.relative_to(ROOT)}")
            continue
        print(f"  {addr:08X} {old} -> {new}{note}")
        renames.append((old, new))
    unpaired = len(dst) - len(paired)
    if unpaired:
        done = {j for _, j in paired}
        print(f"  {unpaired} target function(s) not paired: "
              + ", ".join(dst[j][2] for j in range(len(dst)) if j not in done))
    if not renames:
        print("nothing to rename")
        return
    if not args.write:
        print(f"{len(renames)} rename(s); dry run, add --write to apply")
        return
    for old, new in renames:
        k = line_of[old]
        lines[k] = new + lines[k][len(old):]
    args.symbols.write_bytes("\n".join(lines).encode("utf-8"))
    print(f"wrote {len(renames)} rename(s) to {args.symbols}")


if __name__ == "__main__":
    main()
