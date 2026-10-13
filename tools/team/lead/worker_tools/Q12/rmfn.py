"""rmfn.py unit fn : remove the definition of fn (CRLF-preserving), saving it to $QDIR/parked_<fn>.txt
(a fresh temp dir when QDIR is unset; never the shared tools folder or the worktree)."""
import os, tempfile
import re, sys
unit, fn = sys.argv[1:3]
Q = os.environ.get('QDIR') or tempfile.mkdtemp(prefix='rmfn_')
p = (os.environ.get('WT') or os.getcwd()) + f'/src/{unit}.cpp'
raw = open(p, newline='').read()
crlf = '\r\n' in raw
s = raw.replace('\r\n', '\n')
m = re.search(r'(?m)^(?![ \t}/#])[^\n;]*\b' + re.escape(fn) + r'\([^\n;{]*\)[^\n;{]*(?:\{[^\n]*\n|\n\{\n).*?^\}\n\n?', s, re.S)
assert m, 'not found'
open(f'{Q}/parked_{fn}.txt', 'w').write(m.group(0))
s = s[:m.start()] + s[m.end():]
if crlf: s = s.replace('\n', '\r\n')
open(p, 'w', newline='').write(s)
print('removed; parked copy in', f'{Q}/parked_{fn}.txt')
