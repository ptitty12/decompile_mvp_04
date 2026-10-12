#!/usr/bin/env python3
import os
r"""put.py <unit> <deffile> : insert/replace function definitions in src/<unit>.cpp (CRLF preserved).
deffile (LF text): optional `//DECL` ... `//ENDDECL` section (top-level declaration chunks inserted after the last
#include unless the exact chunk is already in the file; chunks inside `extern "C" {` stay C-linkage) followed by
function definitions (top-level blocks ending at a '}' in col 0)."""
import re, sys, subprocess
ROOT = (os.environ.get('WT') or os.getcwd())
unit, df = sys.argv[1], sys.argv[2]
p = ROOT + "/src/" + unit + ".cpp"
src = open(p, 'rb').read().decode()
crlf = '\r\n' in src
src = src.replace('\r\n', '\n')
new = open(df, 'rb').read().decode().replace('\r\n', '\n')
decl = ''
m = re.search(r'//DECL\n(.*?)//ENDDECL\n', new, re.S)
if m:
    decl = m.group(1)
    new = new[:m.start()] + new[m.end():]
if decl.strip():
    ents = []  # (isC, chunk text)
    inC = False
    cur = []
    depth = 0
    for l in decl.split('\n'):
        t = l.strip()
        if not t and not cur:
            continue
        if depth == 0 and not cur and t == 'extern "C" {':
            inC = True
            continue
        if depth == 0 and not cur and t == '}' and inC:
            inC = False
            continue
        cur.append(l)
        depth += l.count('{') - l.count('}')
        if depth == 0 and (t.endswith(';') or t.endswith('}') or t.endswith('};')):
            ents.append((inC, '\n'.join(cur)))
            cur = []
    if cur:
        ents.append((inC, '\n'.join(cur)))
    ents = [e for e in ents if e[1] not in src]
    ents.sort(key=lambda e: 1 if e[1].lstrip().startswith(('static inline', 'inline')) else 0)
    out = []
    i = 0
    while i < len(ents):
        j = i
        while j < len(ents) and ents[j][0] == ents[i][0]:
            j += 1
        grp = [e[1] for e in ents[i:j]]
        if ents[i][0]:
            out += ['extern "C" {'] + grp + ['}']
        else:
            out += grp
        i = j
    if out:
        incs = [mm.end() for mm in re.finditer(r'(?m)^#include[^\n]*\n', src)]
        pos = incs[-1]
        src = src[:pos] + '\n'.join(out) + '\n' + src[pos:]


def fix_wrapper(path):
    """sort_functions can leave the extern "C" { wrapper behind a lower-addressed function: move it back."""
    raw = open(path, 'rb').read().decode()
    cr = '\r\n' in raw
    lines = raw.replace('\r\n', '\n').split('\n')
    last = max(i for i, l in enumerate(lines) if l == '}')
    depth = 0
    wrap = None
    for i in range(last, -1, -1):
        depth += lines[i].count('}') - lines[i].count('{')
        if depth == 0:
            wrap = i
            break
    if wrap is None or lines[wrap] != 'extern "C" {':
        return
    first = next(i for i, l in enumerate(lines) if l.startswith('FE_OVERLAY'))
    if first > wrap:
        return
    del lines[wrap]
    first = next(i for i, l in enumerate(lines) if l.startswith('FE_OVERLAY'))
    while first > 0 and (lines[first - 1].startswith('/*') or lines[first - 1].startswith(' *') or lines[first - 1].startswith('//')):
        first -= 1
    lines.insert(first, 'extern "C" {')
    out = '\n'.join(lines)
    if cr:
        out = out.replace('\n', '\r\n')
    open(path, 'wb').write(out.encode())


blocks = []
cur = []
for ln in new.split('\n'):
    cur.append(ln)
    if ln == '}':
        blocks.append('\n'.join(cur).strip('\n'))
        cur = []
rest = '\n'.join(cur).strip()
if rest:
    blocks.append(rest)
NAME = re.compile(r"\bfn_([0-9A-Fa-f]{8})\w*\s*\(")
for b in blocks:
    head = b.split('{')[0]
    ms = list(NAME.finditer(head))
    nm = ms[0].group(0)[:-1].strip() if ms else None
    replaced = False
    if nm:
        pat = re.compile(r"(?m)^[^\n]*\b" + re.escape(nm) + r"\s*\([^\n;]*\)\s*\n\{\n.*?\n\}\n", re.S)
        m = pat.search(src)
        if m:
            src = src[:m.start()] + b + '\n' + src[m.end():]
            replaced = True
    if not replaced:
        t = src.rstrip('\n')
        if t.endswith('\n}') and re.search(r'(?m)^extern "C" \{\n', src) and t.rsplit('\n', 2)[-2] == '':
            # wrapped file: closing brace of the extern "C" block is the last line
            t = t[:-2].rstrip('\n')
            src = t + '\n\n' + b + '\n\n}\n'
        else:
            src = t + '\n\n' + b + '\n'
if crlf:
    src = src.replace('\n', '\r\n')
open(p, 'wb').write(src.encode())
subprocess.run([sys.executable, 'tools/match/sort_functions.py', ROOT + "/src/" + unit + ".cpp"], cwd=ROOT)
fix_wrapper(ROOT + "/src/" + unit + ".cpp")
