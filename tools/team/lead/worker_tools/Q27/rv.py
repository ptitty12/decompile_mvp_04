"""rv.py <unit> <sym> <startpat> <variants.txt> [--show N] [--apply N]
Segment = the definition whose first line contains <startpat> (col 0) up to the next line == '}'.
variants.txt: full replacement definitions separated by lines '//---'.
Scores each against retail function <sym> (substring ok) with score_variants.py (from the repo root)."""
import sys, os, subprocess, shutil
unit, sym, pat, vf = sys.argv[1:5]
show = int(sys.argv[sys.argv.index('--show') + 1]) if '--show' in sys.argv else None
apply = int(sys.argv[sys.argv.index('--apply') + 1]) if '--apply' in sys.argv else None
ROOT = os.getcwd()
srcp = f'{ROOT}/src/{unit}.cpp'
raw = open(srcp, newline='').read()
crlf = '\r\n' in raw
src = raw.replace('\r\n', '\n')
lines = src.split('\n')
start = None
for i, l in enumerate(lines):
    if l and not l[0].isspace() and pat in l and l[0] not in '/}' and not l.rstrip().endswith(';'):
        start = i
        break
assert start is not None, 'pattern not found'
end = start
while lines[end] != '}':
    end += 1
# include preceding marker/comment lines? keep them outside.
old = '\n'.join(lines[start:end + 1])
vs = [v.strip('\n') for v in open(vf).read().split('//---\n') if v.strip()]
# Per-worker scratch under $QDIR (workers share this script's folder, so never write next to it).
import tempfile
D = (os.environ.get('QDIR') or tempfile.mkdtemp(prefix='rv_')) + '/rvtmp'
shutil.rmtree(D, ignore_errors=True)
os.makedirs(D)
for i, v in enumerate(vs):
    open(f'{D}/v{i:03d}.cpp', 'w').write('\n'.join(lines[:start]) + '\n' + v + '\n' + '\n'.join(lines[end + 1:]))
if apply is not None:
    txt = open(f'{D}/v{apply:03d}.cpp').read()
    open(srcp, 'w', newline='').write(txt.replace('\n', '\r\n') if crlf else txt)
    print('applied', apply)
    sys.exit(0)
args = ['python', 'tools/match/score_variants.py', unit, sym] + [f'{D}/v{i:03d}.cpp' for i in range(len(vs))] + ['--relax']
if show is not None:
    args = ['python', 'tools/match/score_variants.py', unit, sym, f'{D}/v{show:03d}.cpp', '--relax', '--show']
r = subprocess.run(args, capture_output=True, text=True)
out = r.stdout + r.stderr
import re
out = out.replace(D + '/', '').replace(D.replace('/', '\\') + '\\', '')
print(out[-30000:])
