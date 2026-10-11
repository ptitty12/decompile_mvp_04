"""List unmatched functions whose first call reads an argument register they never set.

    python tools/match/passthru.py .        (needs build/GV4E69/asm and report.json)

Such a caller passes its own incoming parameter through, so the callee takes
more arguments than the source declares. Passing them changes the reference
counts, and local-alloc's callee-saved register choice with them. That fixed
the vcall family (fn_80071E2C(self, a, obj)), fn_80080374, fn_800393B0 and
fn_80081BA8. Not every hit is a fix. Output: name, fuzzy %, unit, callee and
the registers passed through.
"""
import re, glob, json, os, sys, collections
root = sys.argv[1]
asmdir = os.path.join(root, "build/GV4E69/asm")
funcs = {}
files = sorted(glob.glob(asmdir + "/**/*.s", recursive=True), key=lambda f: os.path.basename(f).startswith("auto_"))
for f in files:
    cur = None
    for line in open(f, errors="replace"):
        if line.startswith(".fn "):
            cur = line.split()[1].rstrip(",")
            body = []
        elif line.startswith(".endfn"):
            if cur and cur not in funcs:
                funcs[cur] = body
            cur = None
        elif cur is not None:
            m = re.match(r"/\*.*?\*/\s*(\S+)\s*(.*)$", line.strip())
            if m:
                body.append((m.group(1), m.group(2)))
            elif line.strip().endswith(":"):
                body.append((":", line.strip()))
ARGS = ["r%d" % i for i in range(3, 11)]
def regs(s):
    return re.findall(r"\br(\d+)\b", s)
def rw(op, ops):
    """return (reads, writes) lists of GPR names (approx)."""
    parts = [p.strip() for p in ops.split(",")] if ops else []
    rs = ["r" + x for x in regs(ops)]
    if op.startswith("st") and op not in ("stwu", "stwux"):
        return rs, []
    if op in ("stwu", "stwux"):
        return rs, rs[1:2]
    if op.startswith(("cmp", "mt", "tw")) or op in ("b", "blr", "bctr", "bctrl", "blrl") or op.startswith("b"):
        return rs, []
    if op in ("li", "lis", "mflr", "mfcr", "mfctr", "mfspr", "crclr", "crset", "creqv", "crxor"):
        return [], rs[:1]
    if op == "lmw":
        return rs[1:], ["r%d" % i for i in range(int(rs[0][1:]), 32)]
    if op.startswith("l") and "(" in ops:
        return rs[1:], rs[:1]
    if not rs:
        return [], []
    return rs[1:], rs[:1]
def entry_reads(name):
    body = funcs.get(name)
    if body is None: return None
    written = set(); reads = set()
    for op, ops in body:
        if op == ":": continue
        if op == "bl":
            break
        r, w = rw(op, ops)
        for x in r:
            if x in ARGS and x not in written: reads.add(x)
        written |= set(w)
        if op in ("blr", "bctr"): break
    return reads
cache = {}
fuzzy = {}
rep = json.load(open(os.path.join(root, "build/GV4E69/report.json")))
for u in rep["units"]:
    for fn in u.get("functions", []):
        n = fn["name"].split("__")[0]
        fuzzy[n] = (fn.get("fuzzy_match_percent", 0.0), u["name"])
out = []
for name, body in funcs.items():
    written = set()
    for op, ops in body:
        if op == ":": continue
        if op == "bl":
            tgt = ops.split()[0]
            if tgt not in cache: cache[tgt] = entry_reads(tgt)
            er = cache[tgt]
            if er:
                miss = sorted((er - written) - {"r3"}, key=lambda r: int(r[1:]))
                if miss:
                    out.append((name, tgt, miss))
            break
        r, w = rw(op, ops)
        written |= set(w)
for name, tgt, miss in sorted(out):
    fz = fuzzy.get(name)
    if fz and fz[0] < 100.0:
        print("%-14s %5.1f%%  %-40s calls %-14s passthru %s" % (name, fz[0], fz[1], tgt, ",".join(miss)))
