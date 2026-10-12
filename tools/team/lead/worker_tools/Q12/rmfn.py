"""rmfn.py unit fn : remove the definition of fn (CRLF-preserving), saving it to Q12/parked_<fn>.txt"""
import re, sys
unit, fn = sys.argv[1:3]
Q = 'C:/Users/PATRIC~1/AppData/Local/Temp/claude/C--Users-Patrick-Taylor-decompile-mvp-04/ddf206fc-e9e3-4b5f-93d0-98c4cc873084/scratchpad/Q12'
p = f'C:/Users/Patrick Taylor/decompile_mvp_04-W12/src/{unit}.cpp'
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
