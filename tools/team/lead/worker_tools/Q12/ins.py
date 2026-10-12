"""ins.py <unit> <fn> <file> [--before FN_ANCHOR] [--types FILE] [--proto LINE] [--auto]
Replace the definition of <fn> in src/<unit>.cpp (unit like game/tu_X or tu_X for game/) with the text in <file>.
If <fn> is not defined: insert before the definition of FN_ANCHOR, or with --auto before the first
defined fn_XXXXXXXX with a higher address (file assumed address-sorted), or append at the end.
--types FILE: text inserted before '// PROTOS-BEGIN' (or first 'extern "C" {' line).
--proto LINE: line added before '// PROTOS-END' (or before the closing '}' of the first extern "C" block).
Preserves CRLF/LF."""
import os
import re, sys
WT = (os.environ.get('WT') or os.getcwd())
args = sys.argv[1:]
def opt(name):
    if name in args:
        i = args.index(name)
        v = args[i + 1]
        del args[i:i + 2]
        return v
    return None
anchor = opt('--before'); types = opt('--types'); proto = opt('--proto')
auto = '--auto' in args
if auto: args.remove('--auto')
unit, fn, f = args[:3]
path = f'{WT}/src/{unit}.cpp' if '/' in unit else f'{WT}/src/game/{unit}.cpp'
raw = open(path, newline='').read()
crlf = '\r\n' in raw
src = raw.replace('\r\n', '\n')
body = open(f, newline='').read().replace('\r\n', '\n').strip('\n') + '\n'
DEF = lambda name: re.compile(r'(?m)^(?![ \t}/#])[^\n;]*\b' + re.escape(name) + r'\([^\n;{]*\)[^\n;{]*(?:\{[^\n]*\n|\n\{\n).*?^\}\n', re.S)
def find_def(name):
    return DEF(name).search(src)
m = find_def(fn)
if m:
    src = src[:m.start()] + body + src[m.end():]
    how = 'replaced'
else:
    how = 'appended'
    pos = None
    if anchor:
        a = find_def(anchor)
        if not a:
            print('anchor not found'); sys.exit(1)
        pos = a.start()
    elif auto:
        want = int(re.search(r'fn_([0-9A-F]{8})', fn).group(1), 16)
        for mm in re.finditer(r'(?m)^(?![ \t}/#])[^\n;]*\bfn_([0-9A-F]{8})\([^\n;{]*\)[^\n;{]*(?:\{[^\n]*\n|\n\{\n)', src):
            if int(mm.group(1), 16) > want:
                pos = mm.start(); break
    if pos is not None:
        pre = src[:pos].rstrip('\n').split('\n')
        s = pos
        while pre and (pre[-1].startswith('/*') or pre[-1].startswith(' *') or pre[-1].startswith('//')):
            s -= len(pre[-1]) + 1
            pre.pop()
        src = src[:s] + body + '\n' + src[s:]
        how = 'inserted'
    else:
        src = src.rstrip('\n') + '\n\n' + body
if types:
    t = open(types, newline='').read().replace('\r\n', '\n').strip('\n') + '\n'
    if '// PROTOS-BEGIN' in src:
        i = src.index('// PROTOS-BEGIN')
        # insert before the 'extern "C" {' line that precedes it
        j = src.rfind('extern "C" {', 0, i)
        i = j
    else:
        i = src.index('\nextern "C" {\n') + 1
    src = src[:i] + t + src[i:]
if proto:
    if '// PROTOS-END' in src:
        i = src.index('// PROTOS-END')
    else:
        i0 = src.index('\nextern "C" {\n')
        i = src.index('\n}\n', i0) + 1
    src = src[:i] + proto.strip('\n') + '\n' + src[i:]
if crlf:
    src = src.replace('\n', '\r\n')
open(path, 'w', newline='').write(src)
print('ok', how)
