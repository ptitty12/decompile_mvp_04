#!/usr/bin/env python3
"""setdecl.py <unit> <declfile>: replace (or insert) the Q16 declaration block in src/<unit>.cpp (CRLF preserved).
The block sits right after the last leading #include and is delimited by marker comments.
If pre_<U>.txt exists next to the decl file, its text is inserted before the first #include."""
import os, re, sys
ROOT = (os.environ.get('WT') or os.getcwd())
unit, df = sys.argv[1], sys.argv[2]
p = ROOT + "/src/" + unit + ".cpp"
src = open(p, 'rb').read().decode()
crlf = '\r\n' in src
src = src.replace('\r\n', '\n')
decl = open(df, 'rb').read().decode().replace('\r\n', '\n').strip('\n')
B, E = '/* Q16-DECL-BEGIN */', '/* Q16-DECL-END */'
block = B + '\n' + decl + '\n' + E + '\n'
m = re.search(re.escape(B) + r'.*?' + re.escape(E) + r'\n', src, re.S)
if m:
    src = src[:m.start()] + block + src[m.end():]
else:
    incs = [mm.end() for mm in re.finditer(r'(?m)^#include[^\n]*\n', src)]
    pos = incs[-1]
    src = src[:pos] + '\n' + block + src[pos:]
pre = os.path.join(os.path.dirname(df), 'pre_' + os.path.basename(df)[5:])
if os.path.exists(pre):
    pt = open(pre, 'rb').read().decode().replace('\r\n', '\n').strip('\n') + '\n\n'
    if pt not in src:
        k = src.index('#include')
        src = src[:k] + pt + src[k:]
if crlf:
    src = src.replace('\n', '\r\n')
open(p, 'wb').write(src.encode())
