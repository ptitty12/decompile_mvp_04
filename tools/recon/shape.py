"""Function discovery + prologue-style classification by address region.

Usage: python shape.py <main.dol> [bucket_hex] [funcs_out.txt]
"""
import sys, os, struct, collections
sys.path.insert(0, os.path.dirname(__file__))
from dol import DOL, sext

d = DOL(sys.argv[1])
BUCKET = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x20000

text_secs = d.text()
words = {}
for sec in text_secs:
    for a, w in d.words(sec):
        words[a] = w

# 1) call targets
targets = collections.Counter()
for a, w in words.items():
    if (w >> 26) == 18 and (w & 1):
        t = (sext(w & 0x3fffffc, 26) + (0 if w & 2 else a)) & 0xffffffff
        if t in words:
            targets[t] += 1
# 2) function pointers in data (vtables / callbacks)
ptrs = set()
for k, i, a, s, o in d.secs:
    if k == 'D':
        for j in range(0, s - 3, 4):
            v = struct.unpack('>I', d.raw[o + j:o + j + 4])[0]
            if v in words and v % 4 == 0:
                ptrs.add(v)
starts = set(targets) | ptrs
# 3) function after a blr/b that begins with a prologue
for a, w in words.items():
    if w == 0x4e800020 or (w >> 26) == 18 and not (w & 1):
        n = a + 4
        nw = words.get(n)
        if nw is not None and ((nw >> 16) == 0x9421 or nw == 0x7c0802a6):
            starts.add(n)
starts = sorted(starts)
print('call targets:', len(targets), ' data->text ptrs:', len(ptrs), ' estimated functions:', len(starts))

def style(a):
    w0 = words.get(a); w1 = words.get(a + 4); w2 = words.get(a + 8)
    if w0 is None: return 'other'
    if (w0 >> 16) == 0x9421 and 0x7c0802a6 in (w1, w2):
        return 'gcc'   # stwu r1 first, then mflr r0
    if w0 == 0x7c0802a6 and w1 is not None and (w1 >> 16) == 0x9001:
        return 'cw'    # mflr r0; stw r0,4(r1); stwu
    if w0 == 0x7c0802a6:
        return 'mflr-first'
    if (w0 >> 16) == 0x9421:
        return 'stwu-leaf'
    return 'leaf/other'

buckets = collections.defaultdict(collections.Counter)
for a in starts:
    buckets[a // BUCKET * BUCKET][style(a)] += 1
tot = collections.Counter()
for b in sorted(buckets):
    c = buckets[b]; tot.update(c)
    print(f'{b:08x}  n={sum(c.values()):5d}  ' + '  '.join(f'{k}={v}' for k, v in sorted(c.items())))
print('TOTAL', dict(tot))

# register-save idioms
stmw = sum(1 for w in words.values() if (w >> 26) == 47)
lmw = sum(1 for w in words.values() if (w >> 26) == 46)
print('stmw', stmw, 'lmw', lmw)
# small-data base usage: D-form with rA=2 / rA=13
dform = set(range(32, 56)) | {14}
r2 = sum(1 for w in words.values() if (w >> 26) in dform and ((w >> 16) & 31) == 2)
r13 = sum(1 for w in words.values() if (w >> 26) in dform and ((w >> 16) & 31) == 13)
print('D-form uses of r2:', r2, ' r13:', r13)
if len(sys.argv) > 3:  # optional function list; write it OUTSIDE the repo or under build/
    open(sys.argv[3], 'w').write(
        '\n'.join(f'{a:08x} {style(a)} calls={targets.get(a, 0)}' for a in starts))
