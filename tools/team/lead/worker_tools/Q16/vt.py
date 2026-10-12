"""vt.py unit(fe/tu_X) fn variants.txt [--show]   (env SYM = symbol substring to score)
variants.txt: blocks separated by lines '//// name'. Each block replaces the definition of fn in the unit."""
import sys, re, os, subprocess, tempfile, shutil
unit, fn, vf = sys.argv[1:4]
show = '--show' in sys.argv
W = 'C:/Users/Patrick Taylor/decompile_mvp_04-W5'
src = open(f'{W}/src/{unit}.cpp', 'rb').read().decode().replace('\r\n', '\n')
PAT = r'^(?![ \t}/#])(?:[^\n;]*[ *&])?' + re.escape(fn) + r'\([^\n;]*\)[^\n;]*\n\{\n.*?^\}\n'
m = re.search(PAT, src, re.S | re.M)
assert m, 'fn not found'
blocks = re.split(r'^//// *(.*)$', open(vf).read(), flags=re.M)
d = tempfile.mkdtemp(prefix='vt_', dir=os.path.dirname(os.path.abspath(vf)))
files = []
for i in range(1, len(blocks), 2):
    name = blocks[i].strip() or f'v{i // 2}'
    body = blocks[i + 1].strip('\n') + '\n'
    t = src[:m.start()] + body + src[m.end():]
    f = f'{d}/{name}.cpp'
    open(f, 'w').write(t)
    files.append(f)
args = ['python', f'{W}/tools/match/score_variants.py', unit, os.environ.get('SYM', fn)] + files + (['--show'] if show else [])
r = subprocess.run(args, cwd=W, capture_output=True, text=True)
out = r.stdout
base = os.path.basename(d)
out = re.sub(r'\S*' + re.escape(base) + '[/' + chr(92) + chr(92) + ']', '', out)
print(out[-30000:], r.stderr[-1500:])
shutil.rmtree(d, ignore_errors=True)
