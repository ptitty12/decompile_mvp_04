#!/usr/bin/env python3
"""vdir.py unit fn variants.txt [top]: like vt.py but passes a directory to score_variants (many variants)."""
import os, re, shutil, subprocess, sys
unit, fn, vf = sys.argv[1:4]
top = int(sys.argv[4]) if len(sys.argv) > 4 else 6
W = (os.environ.get('WT') or os.getcwd())
src = open(f'{W}/src/{unit}.cpp', 'rb').read().decode().replace('\r\n', '\n')
PAT = r'^(?![ \t}/#])(?:[^\n;]*[ *&])?' + re.escape(fn) + r'\([^\n;]*\)[^\n;]*\n\{\n.*?^\}\n'
m = re.search(PAT, src, re.S | re.M)
assert m, 'fn not found'
blocks = re.split(r'^//// *(.*)$', open(vf).read(), flags=re.M)
d = os.path.join(os.path.dirname(os.path.abspath(vf)), 'vd_tmp')
shutil.rmtree(d, ignore_errors=True)
os.makedirs(d)
for i in range(1, len(blocks), 2):
    name = blocks[i].strip() or f'v{i // 2}'
    body = blocks[i + 1].strip('\n') + '\n'
    open(f'{d}/{name}.cpp', 'w').write(src[:m.start()] + body + src[m.end():])
r = subprocess.run(['python', f'{W}/tools/match/score_variants.py', unit, os.environ.get('SYM', fn), d], cwd=W, capture_output=True, text=True)
lines = [l for l in r.stdout.splitlines() if 'len' in l]
def key(l):
    mm = re.match(r'\s*(\d+|MATCH)\s+aligned\s+(\d+)', l)
    return (0 if mm.group(1) == 'MATCH' else int(mm.group(1)), int(mm.group(2))) if mm else (999, 999)
lines.sort(key=key)
out = chr(10).join(l.replace(d, '') for l in lines[:top])
print(out)
print(r.stderr[-500:])
shutil.rmtree(d, ignore_errors=True)
