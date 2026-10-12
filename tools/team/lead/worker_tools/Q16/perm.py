"""usage: perm.py <unit> <fn> <srcfile> <startmarker-substring> <count> [<more blocks as marker count>...]
Permutes COUNT consecutive lines after the first line containing the marker (inside <fn>)."""
import sys, itertools, subprocess, os, re, shutil
unit, fn, src = sys.argv[1], sys.argv[2], sys.argv[3]
blocks = []
a = sys.argv[4:]
while a:
    blocks.append((a[0], int(a[1]))); a = a[2:]
W = (os.environ.get('WT') or os.getcwd())
R = os.path.dirname(os.path.abspath(__file__))
lines = open(src, encoding='utf-8').read().split('\n')
# find function start
fi = next(i for i, l in enumerate(lines) if re.search(r'\b' + fn + r'\(', l) and 'FE_OVERLAY' in l)
pos = []
for mk, n in blocks:
    i = next(j for j in range(fi, len(lines)) if mk in lines[j])
    pos.append((i + 1, n))
vd = os.path.join(R, 'vp'); shutil.rmtree(vd, ignore_errors=True); os.makedirs(vd)
perms = [list(itertools.permutations(range(n))) for _, n in pos]
cnt = 0
for combo in itertools.product(*perms):
    new = list(lines)
    for (s, n), p in zip(pos, combo):
        blk = lines[s:s + n]
        new[s:s + n] = [blk[k] for k in p]
    name = 'v' + '_'.join(''.join(map(str, p)) for p in combo) + '.cpp'
    open(os.path.join(vd, name), 'w', encoding='utf-8').write('\n'.join(new))
    cnt += 1
print(cnt, 'variants')
env = dict(os.environ)
env['PATH'] = "/c/Users/Patrick Taylor/AppData/Local/Microsoft/WinGet/Links:" + env['PATH']
r = subprocess.run([sys.executable, 'tools/match/score_variants.py', unit, fn, vd], cwd=W, capture_output=True, text=True, env=env)
out = [l for l in r.stdout.split('\n') if 'len' in l]
def key(l):
    m = re.match(r'\s*(\d+)\s+aligned\s+(\d+)', l); return (int(m.group(1)), int(m.group(2))) if m else (999, 999)
out.sort(key=key)
print('\n'.join(out[:5]))
if r.stderr: print(r.stderr[-500:])
