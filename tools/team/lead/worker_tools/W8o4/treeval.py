"""treeval.py <repo> <unit> <fn> <lo> <hi> : run a switch compare tree (index in r4, signed or
unsigned compares) for k in [lo, hi] and print the value returned (li r3 before blr, or the r3
value set before the tree)."""
import re, sys, os
root, unit, fn, lo, hi = sys.argv[1], sys.argv[2], sys.argv[3], int(sys.argv[4], 0), int(sys.argv[5], 0)
ins, lab = [], {}
cur = False
for line in open(os.path.join(root, "build/GV4E69/asm", unit + ".s"), errors="replace"):
    if line.startswith(".fn " + fn):
        cur = True
        continue
    if cur and line.startswith(".endfn"):
        break
    if not cur:
        continue
    s = line.strip()
    m = re.match(r"\.L_(\w+):", s)
    if m:
        lab[m.group(1)] = len(ins)
        continue
    m = re.match(r"/\*.*?\*/\s*(\S+)\s*(.*)$", s)
    if m:
        ins.append((m.group(1), m.group(2)))
COND = {"beq": lambda c: c[0] == 0, "bne": lambda c: c[0] != 0, "bgt": lambda c: c[0] > 0,
        "blt": lambda c: c[0] < 0, "ble": lambda c: c[0] <= 0, "bge": lambda c: c[0] >= 0}
for k in range(lo, hi + 1):
    pc, cr, r3, steps = 0, (0,), None, 0
    while steps < 1000:
        steps += 1
        op, ops = ins[pc]
        if op in ("cmpwi", "cmplwi") and ops.startswith(os.environ.get("IDX", "r4") + ","):
            v = int(ops.split(",")[1], 0)
            a, b = (k & 0xFFFFFFFF, v & 0xFFFFFFFF) if op == "cmplwi" else (k, v)
            cr = ((a > b) - (a < b),)
            pc += 1
            continue
        if op == "li" and ops.startswith("r3,"):
            r3 = int(ops.split(",")[1], 0)
            pc += 1
            continue
        if op == "ori" and ops.startswith("r3, r3,"):
            r3 |= int(ops.split(",")[2], 0)
            pc += 1
            continue
        if op == "blr":
            break
        if op.endswith("lr") and op[:-2] in COND:
            if COND[op[:-2]](cr):
                break
            pc += 1
            continue
        if op in COND:
            pc = lab[ops.strip()[3:]] if COND[op](cr) else pc + 1
            continue
        if op == "b":
            pc = lab[ops.strip()[3:]]
            continue
        pc += 1
    print(k, r3)
