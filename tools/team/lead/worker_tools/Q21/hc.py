"""hc.py <unit> <fn> <first-line-text> <last-line-text> [rounds]
Hill-climb the order of the lines between (and including) the two marker lines in the function's body.
Each line must be a self-contained statement (one line). Scores with score_variants (smaller is better)."""
import sys, os, re, random, subprocess

W = 'C:/Users/Patrick Taylor/decompile_mvp_04-W2'
SP = os.path.dirname(os.path.abspath(__file__)).replace(chr(92), '/')
unit, fn, first, last = sys.argv[1:5]
rounds = int(sys.argv[5]) if len(sys.argv) > 5 else 10
apply_ = '--apply' in sys.argv

p = f'{W}/src/{unit}.cpp'
src = open(p, newline='').read()
crlf = src.count('\r\n') > src.count('\n') // 2
s = src.replace('\r\n', '\n')
m = re.search(r'^[^\n]*\b%s\([^\n]*\)\n\{\n.*?^\}\n' % re.escape(fn), s, re.S | re.M)
body = m.group(0)
lines = body.split('\n')
a = next(i for i, l in enumerate(lines) if first in l)
b = next(i for i, l in enumerate(lines) if last in l and i >= a)
sel = lines[a:b + 1]


def build(order):
    nl = lines[:a] + [sel[i] for i in order] + lines[b + 1:]
    return s[:m.start()] + '\n'.join(nl) + s[m.end():]


def score(orders):
    files = []
    for k, o in enumerate(orders):
        f = f'{SP}/v/hc_{k}.cpp'
        t = build(o).replace('"../../include/', '"' + W + '/include/')
        open(f, 'w', newline='').write(t)
        files.append(f)
    r = subprocess.run(['python', 'tools/match/score_variants.py', unit, fn] + files, cwd=W, capture_output=True, text=True)
    res = []
    for line in r.stdout.splitlines():
        mm = re.match(r'\s*(MATCH|\d+|ERROR)\s+(?:aligned\s+(\d+))?', line)
        if not mm:
            continue
        if mm.group(1) == 'ERROR':
            res.append((9999, 9999))
        else:
            sc = 0 if mm.group(1) == 'MATCH' else int(mm.group(1))
            res.append((sc, int(mm.group(2) or 0)))
    while len(res) < len(orders):
        res.append((9999, 9999))
    return res


os.makedirs(SP + '/v', exist_ok=True)
cur = list(range(len(sel)))
best = score([cur])[0]
print('start', best)
n = len(cur)
for r in range(rounds):
    cands = []
    for i in range(n - 1):
        c = cur[:]
        c[i], c[i + 1] = c[i + 1], c[i]
        cands.append(c)
    for _ in range(40):
        i, j = random.sample(range(n), 2)
        c = cur[:]
        x = c.pop(i)
        c.insert(j, x)
        cands.append(c)
    res = score(cands)
    k = min(range(len(cands)), key=lambda t: res[t])
    if res[k] < best:
        best = res[k]
        cur = cands[k]
        print('round', r, best)
        if best[0] == 0:
            break
    else:
        print('round', r, 'no improvement', best)
        if r > 2:
            break
if apply_:
    out = build(cur)
    if crlf:
        out = out.replace('\n', '\r\n')
    open(p, 'w', newline='').write(out)
    print('applied')
print(cur)
