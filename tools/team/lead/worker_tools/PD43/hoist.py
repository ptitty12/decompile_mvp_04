"""hoist.py file.cpp : move every non-function top-level chunk above all DB_OVERLAY definitions,
sort the definitions by address and emit one block of forward declarations (idempotent)."""
import sys, re
p = sys.argv[1]
lines = open(p).read().split('\n')
n = len(lines)
MARK = '/* forward declarations (definitions are in address order) */'
chunks = []
cur = []
def flush():
    global cur
    if cur:
        chunks.append(('decl', '\n'.join(cur)))
        cur = []
i = 0
while i < n:
    l = lines[i]
    if (l.startswith('extern "C" DB_OVERLAY') or l.startswith('DB_OVERLAY')) and not l.rstrip().endswith(';'):
        com = []
        while cur and (cur[-1].startswith('/*') or cur[-1].startswith('//') or cur[-1].startswith(' *') or cur[-1].strip().endswith('*/')):
            if cur[-1].strip() == MARK:
                break
            com.insert(0, cur.pop())
        while cur and cur[-1].strip() == '':
            cur.pop()
        flush()
        body = com + [l]
        i += 1
        while i < n:
            body.append(lines[i])
            if lines[i] == '}':
                i += 1
                break
            i += 1
        chunks.append(('fn', '\n'.join(body)))
        continue
    cur.append(l)
    i += 1
flush()
decls = [c[1] for c in chunks if c[0] == 'decl']
fns = [c[1] for c in chunks if c[0] == 'fn']
def addr(f):
    m = re.search(r'fn_([0-9A-F]{8})\(', f)
    return int(m.group(1), 16) if m else 0
fns.sort(key=addr)
protos = []
for f in fns:
    for ln in f.split('\n'):
        if ln.startswith('extern "C" DB_OVERLAY'):
            protos.append(ln.replace(' DB_OVERLAY', '', 1) + ';')
            break
pset = set(protos)
clean = []
for d in decls:
    ls = [l for l in d.split('\n') if l not in pset and l.strip() != MARK]
    clean.append('\n'.join(ls))
decls = [d for d in clean if d.strip()]
decls.append(MARK + '\n' + '\n'.join(protos))
out = '\n'.join(d.rstrip('\n') for d in decls) + '\n\n' + '\n\n'.join(fns) + '\n'
out = re.sub(r'\n{3,}', '\n\n', out)
open(p, 'w').write(out)
print(len(decls), 'decl chunks,', len(fns), 'functions')
