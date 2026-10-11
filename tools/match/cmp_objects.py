"""Per-function compare of a compiled unit object vs dtk's target object.

Usage: python cmpunit.py <objdump> <compiled.o> <target.o> [symbol-substring ...]
Relocated immediates/branch targets are masked; relocation symbol names shown.
"""
import re, subprocess, sys

objdump, base, target = sys.argv[1:4]
filters = sys.argv[4:]


def funcs(obj):
    out = subprocess.run([objdump, "-d", "-r", obj], capture_output=True, text=True).stdout
    res, cur, last = {}, None, None
    for line in out.splitlines():
        m = re.match(r"^[0-9a-f]+ <(.+)>:$", line)
        if m:
            cur = m.group(1); res[cur] = []; continue
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


def mask(w, reloc):
    op = w >> 26
    if op == 16:
        # bc: keep BO/BI (the branch sense); mask only the displacement.
        return w & 0xFFFF0003
    if op == 18:
        return w & 0xFC000003
    if reloc:
        return w & 0xFFE00000 if op in (14, 15) else w & 0xFFFF0000
    return w


b, t = funcs(base), funcs(target)
total = ok = 0
for name in t:
    if filters and not any(f in name for f in filters):
        continue
    if name not in b:
        print(f"MISSING  {name}  ({len(t[name])} ins)")
        total += 1
        continue
    tb, bb = t[name], b[name]
    same = len(tb) == len(bb) and all(mask(x[0], x[2]) == mask(y[0], y[2]) for x, y in zip(tb, bb))
    total += 1; ok += same
    print(f"{'MATCH   ' if same else 'DIFF    '} {name}  target {len(tb)} / base {len(bb)} ins")
    if not same and filters:
        for i in range(max(len(tb), len(bb))):
            x = tb[i] if i < len(tb) else [0, "", ""]
            y = bb[i] if i < len(bb) else [0, "", ""]
            flag = "  " if (i < len(tb) and i < len(bb) and mask(x[0], x[2]) == mask(y[0], y[2])) else "<>"
            print(f"  {flag} {x[1][:34]:34} {x[2][:14]:14} | {y[1][:34]:34} {y[2][:14]}")
print(f"{ok}/{total} functions match")
