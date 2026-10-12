"""rmfn.py unit fn : remove the definition of fn (CRLF-preserving), saving it to Q12/parked_<fn>.txt"""
import os
import re, sys
unit, fn = sys.argv[1:3]
Q = (os.environ.get('QDIR') or os.path.dirname(os.path.abspath(__file__)))
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
print('removed')
