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
     Before that, a function whose masked code equals exactly one target
     function in the unit is pinned to it (catches real C++ ctors/dtors
     that size-order pairing would put at the wrong address).

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
SYM_LINE = re.compile(r"^(\S+) = \.(?:text|feoverlay|dboverlay):0x([0-9A-Fa-f]{8});(.*)$")
ADDR_PREFIX = re.compile(r"^fn_([0-9A-Fa-f]{8})(?![0-9A-Fa-f])")
SIZE_ATTR = re.compile(r"size:0x([0-9A-Fa-f]+)")
# Code sections: .text, and the overlay sections code-only overlay units split.
CODE_SECTIONS = (".text", ".feoverlay", ".dboverlay")


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
            if info & 0xF == 2 and 0 < shndx < len(names) and names[shndx] in CODE_SECTIONS:
                out.append((value, size, cstr(strtab[4] + st_name)))
    # Aliases at one address: keep the first name seen.
    seen, uniq = set(), []
    for v, sz, n in sorted(out):
        if v not in seen:
            seen.add(v)
            uniq.append((v, sz, n))
    return uniq


def masked_bodies(path: Path) -> Dict[int, Tuple[int, ...]]:
    """{offset in its code section: masked instruction words} for FUNC symbols.

    Branch displacements and relocated immediates are masked (as in
    tools/match/cmp_objects.py), so a compiled function and its retail
    original compare equal when only symbol addresses differ."""
    data = path.read_bytes()
    shoff, = struct.unpack_from(">I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from(">HHH", data, 0x2E)
    secs = [struct.unpack_from(">IIIIIIIIII", data, shoff + i * shentsize) for i in range(shnum)]

    def cstr(off: int) -> str:
        return data[off:data.index(b"\0", off)].decode("latin-1")

    names = [cstr(secs[shstrndx][4] + s[0]) for s in secs]
    relocs: Dict[int, set] = {}
    for s in secs:
        if s[1] == 4:  # SHT_RELA
            offs = relocs.setdefault(s[7], set())
            for i in range(s[5] // 12):
                off, = struct.unpack_from(">I", data, s[4] + i * 12)
                offs.add(off & ~3)
    out: Dict[int, Tuple[int, ...]] = {}
    for s in secs:
        if s[1] != 2:
            continue
        for i in range(s[5] // 16):
            _, value, size, info, _, shndx = struct.unpack_from(">IIIBBH", data, s[4] + i * 16)
            if info & 0xF != 2 or not (0 < shndx < len(names)) or names[shndx] not in CODE_SECTIONS:
                continue
            sec, r, words = secs[shndx], relocs.get(shndx, set()), []
            for k in range(0, size - size % 4, 4):
                w, = struct.unpack_from(">I", data, sec[4] + value + k)
                op = w >> 26
                if op == 16:
                    w &= 0xFFFF0003
                elif op == 18:
                    w &= 0xFC000003
                elif value + k in r:
                    w &= 0xFFE00000 if op in (14, 15) else 0xFFFF0000
                words.append(w)
            out.setdefault(value, tuple(words))
    return out


def text_range(splits: Path, unit: str) -> Tuple[int, int]:
    cur = None
    for line in splits.read_text(encoding="utf-8").splitlines():
        if line and not line[0].isspace():
            cur = line.rstrip(":")
        elif cur == unit and line.strip().startswith(CODE_SECTIONS):
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


def pair(src: List[Tuple[int, int, str]], dst: List[Tuple[int, int, str]],
         content: Optional[Dict[int, int]] = None) -> List[Tuple[int, int]]:
    """Index pairs (i in src, j in dst), in order.

    Names that start with fn_<address> pin first, then functions whose masked
    code equals exactly one target function (`content`, src index -> dst
    index), keeping only pins that agree in order; the stretches between pins
    are paired by pair_segment."""
    j_of_addr = {d[0]: j for j, d in enumerate(dst)}
    pins = []
    for i, (_, _, name) in enumerate(src):
        pm = ADDR_PREFIX.match(name)
        if pm and int(pm.group(1), 16) in j_of_addr:
            pins.append((i, j_of_addr[int(pm.group(1), 16)]))
        elif content and i in content:
            pins.append((i, content[i]))
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


PER_TU_LOCAL = re.compile(r"^(__static_initialization_and_destruction_0|__tcf_\d+)$")

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
    # Content pins: a compiled function whose masked code equals exactly one
    # target function in this unit pairs with it, whatever its size order.
    content: Dict[int, int] = {}
    target = ROOT / "build" / "GV4E69" / "obj" / Path(args.unit).with_suffix(".o")
    if target.is_file():
        tb, sb = masked_bodies(target), masked_bodies(obj)
        js_of_body: Dict[Tuple[int, ...], List[int]] = {}
        for j, (addr, _, _) in enumerate(dst):
            body = tb.get(addr - lo)
            if body and len(body) >= 2:
                js_of_body.setdefault(body, []).append(j)
        for i, (off, _, _) in enumerate(src):
            js = js_of_body.get(sb.get(off, ()), [])
            if len(js) == 1:
                content[i] = js[0]
    renames: List[Tuple[str, str]] = []
    paired = pair(src, dst, content)
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
        if new in addr_of_name and addr_of_name[new] != addr and not PER_TU_LOCAL.match(new):
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
        # g++ names these per TU (static init, __tcf_N stubs): several TUs share
        # a name, so they must be local or links resolve to the wrong copy.
        if PER_TU_LOCAL.match(new) and "scope:local" not in lines[k]:
            lines[k] = lines[k].rstrip() + " scope:local"
    args.symbols.write_bytes("\n".join(lines).encode("utf-8"))
    print(f"wrote {len(renames)} rename(s) to {args.symbols}")


if __name__ == "__main__":
    main()
