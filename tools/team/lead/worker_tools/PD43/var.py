"""var.py db/tu_X fn variants.txt [--show]
blocks separated by '//// name'; each block replaces the definition of fn (may include helpers before it)."""
import sys, re, os, subprocess, tempfile, shutil
WT = (os.environ.get('WT') or os.getcwd())
os.chdir(WT)
unit, fn, vf = sys.argv[1:4]
show = '--show' in sys.argv
srcp = f'src/{unit}.cpp'
src = open(srcp).read()
m = re.search(r'^(?:extern "C" )?(?![ \t}/#])[^\n;]*?\b' + re.escape(fn) + r'\([^\n;]*\)(?: \{\n|\n\{\n).*?^\}\n', src, re.S | re.M)
assert m, 'fn not found'
blocks = re.split(r'^//// *(.*)$', open(vf).read(), flags=re.M)
d = tempfile.mkdtemp(prefix='var_', dir=os.path.dirname(os.path.abspath(vf)))
files = []
for i in range(1, len(blocks), 2):
    name = blocks[i].strip() or f'v{i // 2}'
    body = blocks[i + 1].strip('\n') + '\n'
    t = src[:m.start()] + body + src[m.end():]
    f = f'{d}/{name}.cpp'
    open(f, 'w').write(t)
    files.append(f)
r = subprocess.run(['python', 'tools/match/score_variants.py', unit, fn, *files] + (['--show'] if show else []), capture_output=True, text=True)
print(r.stdout + r.stderr)
shutil.rmtree(d, ignore_errors=True)
