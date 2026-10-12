"""hc.py unit fn "line1|line2|..." [--apply] [--start perm,comma,list]
Hill-climb the order of consecutive statement lines (given in current order) inside src/game/<unit>.cpp.
Moves: take one line and insert it elsewhere. Scores by score_variants (differing slots, then aligned)."""
import sys, os, re, subprocess, shutil, random, tempfile
unit, fn, spec = sys.argv[1:4]
apply = '--apply' in sys.argv
KICKS = 12
random.seed(1)
W = 'C:/Users/Patrick Taylor/decompile_mvp_04-W12'
path = f'{W}/src/fe/{unit}.cpp'
text = open(path).read()
if spec.startswith('@'):
    a_, b_ = spec[1:].split('@@')
    fl = text.split(chr(10))
    ia = next(i for i, l in enumerate(fl) if a_ in l)
    ib = next(i for i in range(ia, len(fl)) if b_ in fl[i])
    lines = fl[ia:ib + 1]
else:
    lines = spec.split('|')
block = '\n'.join(lines)
assert block in text, 'block not found'
n = len(lines)
D = tempfile.mkdtemp(prefix='hc_', dir="C:/Users/PATRIC~1/AppData/Local/Temp/claude/C--Users-Patrick-Taylor-decompile-mvp-04/ddf206fc-e9e3-4b5f-93d0-98c4cc873084/scratchpad/Q12")
def score_many(perms):
    for f in os.listdir(D):
        os.remove(f'{D}/{f}')
    for k, p in enumerate(perms):
        open(f'{D}/p{k:05d}.cpp', 'w').write(text.replace(block, '\n'.join(lines[i] for i in p), 1))
    r = subprocess.run(['python', f'{W}/tools/match/score_variants.py', f'fe/{unit}', fn, D + '/'], capture_output=True, text=True, cwd=W)
    res = {}
    for l in r.stdout.splitlines():
        m = re.match(r'\s*(MATCH|\d+)\s+aligned\s+(\d+).*?p(\d{5})\.cpp', l)
        if m:
            d = 0 if m.group(1) == 'MATCH' else int(m.group(1))
            res[int(m.group(3))] = (d, int(m.group(2)))
    return [res.get(k, (999, 999)) for k in range(len(perms))]
cur = list(range(n))
if '--start' in sys.argv:
    cur = [int(x) for x in sys.argv[sys.argv.index('--start') + 1].split(',')]
best = score_many([cur])[0]
print('start', cur, best, flush=True)
seen = {tuple(cur)}
while best[0] > 0:
    cands = []
    for i in range(n):
        for j in range(n):
            if i != j:
                c = list(cur); x = c.pop(i); c.insert(j, x)
                if tuple(c) not in seen:
                    cands.append(c)
    if not cands:
        break
    sc = score_many(cands)
    k = min(range(len(cands)), key=lambda q: sc[q])
    for c in cands:
        seen.add(tuple(c))
    if sc[k] < best:
        best = sc[k]; cur = cands[k]
        print('improved', cur, best, flush=True)
    else:
        print('stuck', best, cur, flush=True)
        # kick: random double moves, accept <= best
        ok = False
        for rnd in range(KICKS):
            cs = []
            for _ in range(150):
                c = list(cur)
                for _ in range(2):
                    i = random.randrange(n); j = random.randrange(n)
                    x = c.pop(i); c.insert(j, x)
                if tuple(c) not in seen:
                    cs.append(c)
            if not cs:
                continue
            sc2 = score_many(cs)
            for c in cs:
                seen.add(tuple(c))
            k2 = min(range(len(cs)), key=lambda q: sc2[q])
            if sc2[k2] < best or (sc2[k2][0] < best[0] + 3 and rnd % 2 == 0 and sc2[k2] != best):
                cur = cs[k2]; ok = True
                if sc2[k2] < best:
                    best = sc2[k2]
                print('kick', cur, sc2[k2], flush=True)
                break
        if not ok:
            break
NL = chr(10)
if best[0] == 0 and apply:
    t2 = open(path).read()
    if block in t2:
        open(path, 'w').write(t2.replace(block, NL.join(lines[i] for i in cur), 1))
        print('applied')
    else:
        print('block changed meanwhile; NOT applied')
shutil.rmtree(D, ignore_errors=True)
print('final', cur, best)
print('lines:'); print(NL.join(lines[i] for i in cur))
