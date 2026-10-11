"""Compile a scratch file of function variants with ProDG and score each against a target function.

Usage: python variants.py <prodg_dir> <objdump> <variants.cpp> <target.o> <target_symbol> [flags...]
Every function in variants.cpp whose (mangled) name contains "__v" followed by digits is scored.
"""
import difflib, os, re, subprocess, sys, tempfile

prodg, objdump, src, tobj, tsym = sys.argv[1:6]
flags = sys.argv[6:] or ["-O2", "-G0", "-fno-rtti", "-fno-exceptions"]


def funcs(obj):
    out = subprocess.run([objdump, "-d", "-r", obj], capture_output=True, text=True).stdout
    res, cur = {}, None
    for line in out.splitlines():
        m = re.match(r"^[0-9a-f]+ <(.+)>:$", line)
        if m:
            cur = m.group(1); res[cur] = []; continue
        m = re.match(r"^\s+[0-9a-f]+:\s+((?:[0-9a-f]{2} ){4})\s*(.*)$", line)
        if m and cur:
            res[cur].append([int(m.group(1).replace(" ", ""), 16), m.group(2).strip(), False]); continue
        m = re.match(r"^\s+[0-9a-f]+: (R_PPC_\w+)", line)
        if m and cur and res[cur]:
            res[cur][-1][2] = True
    return res


def mask(w, rel):
    op = w >> 26
    if op in (16, 18):
        return w & 0xFC000003
    return (w & 0xFFE00000 if op in (14, 15) else w & 0xFFFF0000) if rel else w


target = funcs(tobj)[tsym]
env = dict(os.environ, SN_NGC_PATH=prodg)
obj = os.path.join(tempfile.mkdtemp(), "v.o")
r = subprocess.run([os.path.join(prodg, "ngccc.exe"), *flags, "-c", src, "-o", obj], capture_output=True, text=True, env=env)
if r.returncode:
    sys.exit(r.stdout + r.stderr)
for name, ins in funcs(obj).items():
    if not re.search(r"_v\d+", name):
        continue
    n = max(len(ins), len(target))
    diffs = [i for i in range(n) if i >= len(ins) or i >= len(target) or mask(ins[i][0], ins[i][2]) != mask(target[i][0], target[i][2])]
    # Alignment-aware score: instructions outside the longest common subsequence
    # (one inserted instruction no longer counts as "everything after it differs").
    a = [mask(x[0], x[2]) for x in ins]
    b = [mask(x[0], x[2]) for x in target]
    same = sum(blk.size for blk in difflib.SequenceMatcher(None, a, b, autojunk=False).get_matching_blocks())
    aligned = len(a) + len(b) - 2 * same
    print(f"{'MATCH' if not diffs else f'{len(diffs):3} diffs ({aligned:3} aligned)'}  len {len(ins)}/{len(target)}  {name}")
    if diffs and os.environ.get("SHOW") and os.environ["SHOW"] in name:
        for i in diffs[:20]:
            a = ins[i][1] if i < len(ins) else "-"
            b = target[i][1] if i < len(target) else "-"
            print(f"     [{i}] mine: {a:36} retail: {b}")
