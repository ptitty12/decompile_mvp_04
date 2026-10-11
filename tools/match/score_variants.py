#!/usr/bin/env python3
"""Score scratch copies of a unit against one retail function, fast (about 0.15 s per file).

Usage (from the repo root, after `python configure.py && ninja` once):
  python tools/match/score_variants.py <unit> <function> <file.cpp> [<file.cpp> ...]
        [--relax] [--show] [--flags "<cflags>"]

  <unit>      unit path under src/ without extension, e.g. animation/choosers/tu_80271F14
  <function>  symbol in dtk's target object (build/GV4E69/obj/<unit>.o): the exact
              (mangled) name, or a substring that matches exactly one function
  <file>      scratch sources (typically edited copies of src/<unit>.cpp, kept outside
              the repo), each compiled from the repo root with the unit's cflags from
              build.ninja (or --flags), so -Iinclude resolves as in the real build.
              A directory stands for all .c/.cpp files in it (pipe through `sort -n`).

Prints one line per file: the number of instruction slots that differ (0 = MATCH),
the alignment-aware count (instructions outside the longest common subsequence, so one
inserted instruction adds 1 instead of shifting everything after it), and both lengths.
--show (or a single file) lists the differing slots, retail on the left.

Relocated fields (branch targets, @ha/@l, sda21) are masked when both sides have a
relocation, as in cmp_objects.py. --relax also accepts a relocation on one side against
a raw immediate on the other (e.g. `lis r9,GXWGFifo@ha` vs retail `lis r9,0xcc01`).

This is a search aid, not verification: tools/verify/verify.py and objdiff decide.
"""
import argparse
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
VERSION = "GV4E69"
EXE = ".exe" if os.name == "nt" else ""


def ninja_vars(unit):
    """Return the variables (cflags, mw_version, ...) of the build statement for src/<unit>.o."""
    text = (ROOT / "build.ninja").read_text(encoding="utf-8")
    text = re.sub(r"\$\n\s*", "", text)  # ninja line continuations
    want = os.path.normpath(f"build/{VERSION}/src/{unit}.o")
    lines = text.splitlines()
    for i, line in enumerate(lines):
        m = re.match(r"build (.+?): \S+ ", line)
        if not (m and os.path.normpath(m.group(1).replace("$ ", " ")) == want):
            continue
        out = {}
        for var in lines[i + 1:]:
            vm = re.match(r"\s+(\w+) = (.*)$", var)
            if not vm:
                break
            out[vm.group(1)] = vm.group(2).replace("$ ", " ")
        return out
    sys.exit(f"no build statement for {want} in build.ninja (run configure.py?)")


def functions(objdump, obj):
    """{name: [[word, text, reloc_symbol], ...]} for every function in obj."""
    out = subprocess.run([objdump, "-d", "-r", str(obj)], capture_output=True, text=True).stdout
    res, cur = {}, None
    for line in out.splitlines():
        m = re.match(r"^[0-9a-f]+ <(.+)>:$", line)
        if m:
            cur = m.group(1)
            res[cur] = []
            continue
        if cur is None:
            continue
        m = re.match(r"^\s+[0-9a-f]+:\s+((?:[0-9a-f]{2} ){4})\s*(.*)$", line)
        if m:
            res[cur].append([int(m.group(1).replace(" ", ""), 16), m.group(2).strip(), ""])
            continue
        m = re.match(r"^\s+[0-9a-f]+: (R_PPC_\w+)\s+(\S+)", line)
        if m and res[cur]:
            res[cur][-1][2] = m.group(2)
    return res


def mask(word, reloc):
    op = word >> 26
    if op == 16:  # bc: keep BO/BI (the branch sense) and AA/LK; mask the displacement
        return word & 0xFFFF0003
    if op == 18:  # b/bl: keep opcode and AA/LK bits
        return word & 0xFC000003
    if reloc:
        return word & 0xFFE00000 if op in (14, 15) else word & 0xFFFF0000
    return word


def same(t, b, relax):
    if relax and (t[2] or b[2]):
        r = t[2] or b[2]
        return mask(t[0], r) == mask(b[0], r)
    return mask(t[0], t[2]) == mask(b[0], b[2])


def lcs(t, b, relax):
    """Length of the longest common subsequence of two instruction lists."""
    prev = [0] * (len(b) + 1)
    for x in t:
        cur = [0]
        for j, y in enumerate(b):
            cur.append(prev[j] + 1 if same(x, y, relax) else max(prev[j + 1], cur[j]))
        prev = cur
    return prev[-1]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("unit")
    ap.add_argument("function")
    ap.add_argument("files", nargs="+")
    ap.add_argument("--relax", action="store_true", help="a relocation on either side masks both")
    ap.add_argument("--show", action="store_true", help="list differing instructions")
    ap.add_argument("--flags", help="compiler flags (default: the unit's cflags from build.ninja)")
    a = ap.parse_args()

    unit = a.unit.replace("\\", "/").removeprefix("src/").removesuffix(".cpp").removesuffix(".c")
    v = ninja_vars(unit)
    cflags = (a.flags or v["cflags"]).split()
    prodg = ROOT / "build" / "compilers" / v.get("mw_version", r"ProDG\3.9.3")
    objdump = ROOT / "build" / "binutils" / f"powerpc-eabi-objdump{EXE}"
    target_obj = ROOT / "build" / VERSION / "obj" / f"{unit}.o"
    for p in (prodg / f"ngccc{EXE}", objdump, target_obj):
        if not p.exists():
            sys.exit(f"missing {p} (run configure.py and ninja first)")

    tfuncs = functions(objdump, target_obj)
    name = a.function if a.function in tfuncs else None
    if name is None:
        hits = [n for n in tfuncs if a.function in n]
        if len(hits) != 1:
            sys.exit(f"function {a.function!r} matches {len(hits)} target symbols: {hits[:8]}")
        name = hits[0]
    target = tfuncs[name]

    files = []
    for f in a.files:  # a directory stands for every .c/.cpp file in it
        files += sorted(str(p) for p in Path(f).iterdir() if p.suffix in (".c", ".cpp")) if os.path.isdir(f) else [f]
    env = dict(os.environ, SN_NGC_PATH=str(prodg))
    tmp = tempfile.mkdtemp(prefix="score_")
    show = a.show or len(files) == 1
    for i, src in enumerate(files):
        obj = os.path.join(tmp, f"v{i}.o")
        r = subprocess.run([str(prodg / f"ngccc{EXE}"), *cflags, "-c", os.path.abspath(src), "-o", obj],
                           cwd=ROOT, env=env, capture_output=True, text=True)
        if r.returncode:
            print(f"ERROR  {src}\n{(r.stdout + r.stderr).strip()[-1500:]}")
            continue
        base = functions(objdump, obj).get(name)
        if base is None:
            print(f"ERROR  {src}: no function {name}")
            continue
        n = max(len(base), len(target))
        diffs = [k for k in range(n)
                 if k >= len(base) or k >= len(target) or not same(target[k], base[k], a.relax)]
        aligned = len(base) + len(target) - 2 * lcs(target, base, a.relax)
        tag = "MATCH" if not diffs else f"{len(diffs):5}"
        print(f"{tag}  aligned {aligned:4}  len {len(base)}/{len(target)}  {src}", flush=True)
        if show and diffs:
            for k in diffs:
                t = target[k] if k < len(target) else [0, "-", ""]
                b = base[k] if k < len(base) else [0, "-", ""]
                print(f"    {k:4}  {t[1][:34]:34} {t[2][:14]:14} | {b[1][:34]:34} {b[2][:14]}")


if __name__ == "__main__":
    main()
