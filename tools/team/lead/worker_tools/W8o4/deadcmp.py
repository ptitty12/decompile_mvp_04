"""List functions (in tu_* unit asm) with a compare whose CR result is never read.
usage: python deadcmp.py <repo> [busy_units.txt]"""
import re, glob, json, os, sys
root = sys.argv[1]
busy = set()
if len(sys.argv) > 2:
    busy = set(l.strip() for l in open(sys.argv[2]) if l.strip())
asmdir = os.path.join(root, "build/GV4E69/asm")
rep = json.load(open(os.path.join(root, "build/GV4E69/report.json")))
status = {}
for u in rep["units"]:
    for f in u.get("functions", []):
        status[(u["name"].replace("main/", ""), f["name"])] = f.get("fuzzy_match_percent")
def parse(path):
    funcs = {}
    cur = None
    for line in open(path, errors="replace"):
        if line.startswith(".fn "):
            cur = line.split()[1].rstrip(","); body = []; funcs[cur] = body
        elif line.startswith(".endfn"):
            cur = None
        elif cur is not None:
            m = re.match(r"/\*\s*([0-9A-F]{8}).*?\*/\s*(\S+)\s*(.*)$", line.strip())
            if m: body.append((m.group(1), m.group(2), m.group(3)))
            elif line.strip().endswith(":"): body.append((None, ":", line.strip()[:-1]))
    return funcs
def crfield(op, ops):
    if op.startswith("cmp"):
        p = ops.split(",")[0].strip()
        return p if p.startswith("cr") else "cr0"
    return None
def dead_cmps(body):
    labels = {b[2]: i for i, b in enumerate(body) if b[1] == ":"}
    out = []
    for i, (a, op, ops) in enumerate(body):
        if not op.startswith("cmp"): continue
        cr = crfield(op, ops)
        j = i + 1; hops = 0; used = False
        while j < len(body):
            a2, op2, ops2 = body[j]
            if op2 == ":": j += 1; continue
            if op2.startswith("b") and op2 not in ("b", "bl", "blr", "bctr", "bctrl"):
                # conditional branch: reads cr (default cr0)
                if (cr == "cr0" and not ops2.startswith("cr")) or ops2.startswith(cr):
                    used = True; break
                j += 1; continue
            if op2 in ("mfcr", "cror", "crand", "crnor", "crxor", "creqv", "crorc", "crandc", "crnand", "isel") or op2.startswith("cr"):
                used = True; break
            if op2.startswith("cmp") and crfield(op2, ops2) == cr: break
            if op2.endswith(".") and cr == "cr0": break
            if op2 == "b":
                t = ops2.strip()
                if t in labels and hops < 3: j = labels[t]; hops += 1; continue
                break
            if op2 in ("blr", "bctr"): break
            if op2 in ("bl", "bctrl"): break
            j += 1
        if not used: out.append(a)
    return out
res = []
for path in sorted(glob.glob(asmdir + "/*/tu_*.s")):
    unit = os.path.relpath(path, asmdir).replace("\\", "/")[:-2]
    for fn, body in parse(path).items():
        d = dead_cmps(body)
        if not d: continue
        st = status.get((unit, fn))
        if st is None:
            # renamed: find by address prefix
            st = next((v for (u, n), v in status.items() if u == unit and n.startswith(fn)), None)
        res.append((unit, fn, len([b for b in body if b[1] != ':']), len(d), st))
for unit, fn, n, d, st in res:
    if st == 100.0: continue
    print(f"{'BUSY' if unit in busy else 'free'} {unit:28s} {fn:14s} ins={n:4d} dead={d} match={st}")
