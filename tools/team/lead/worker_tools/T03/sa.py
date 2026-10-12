"""sa.py unit func [--pin-last N] [--iters N] [--seed N] [--start tgt|cur]: simulated annealing over statement order of body (one stmt per line). prints best text."""
import os
import sys, random, math
sys.path.insert(0, (os.environ.get('QDIR') or os.path.dirname(os.path.abspath(__file__))))
from vtlib import *
unit, func = sys.argv[1:3]
def arg(n, d): return int(sys.argv[sys.argv.index(n)+1]) if n in sys.argv else d
pf, pl, iters, seed = arg('--pin-first',0), arg('--pin-last',0), arg('--iters',800), arg('--seed',1)
c = Ctx(unit, func)
lines = c.defn.split('\n')
i0 = lines.index('{') + 1
i1 = len(lines) - 1 - lines[::-1].index('}')
head, body, tail = lines[:i0], lines[i0:i1], lines[i1:]
ff, fl = body[:pf], (body[len(body)-pl:] if pl else [])
mid = body[pf:len(body)-pl if pl else len(body)]
def build(m): return '\n'.join(head + ff + m + fl + tail)
random.seed(seed)
cur = mid[:]; cs = c.score(build(cur)); best, bm = cs, cur[:]
T = 2.0
for it in range(iters):
    m = cur[:]
    r = random.random()
    if r < .5 and len(m) > 1:
        i = random.randrange(len(m)-1); m[i], m[i+1] = m[i+1], m[i]
    else:
        i, j = random.sample(range(len(m)), 2); x = m.pop(i); m.insert(j, x)
    s = c.score(build(m))
    if s >= cs or random.random() < math.exp((s - cs) / T):
        cur, cs = m, s
        if s > best:
            best, bm = s, m[:]; print(it, best, flush=True)
            if best >= len(c.tm): break
    T = max(0.15, T * 0.995)
print('BEST', best, '/', len(c.tm))
print(build(bm))
if '--write' in sys.argv and best >= len(c.tm):
    open(c.src_path, 'w').write(c.src.replace(c.defn, build(bm) + '\n')); print('written')
