import sys, re, collections, os
sys.path.insert(0, os.path.dirname(__file__))
from dol import DOL
d = DOL(sys.argv[1])
strs = []
for k, i, a, s, o in d.secs:
    for m in re.finditer(rb'[\x20-\x7e]{5,}', d.raw[o:o + s]):
        strs.append((a + m.start(), m.group().decode('latin1')))
paths = collections.OrderedDict()
BS = chr(92)
for a, s in strs:
    for m in re.finditer(r'[A-Za-z]:[/' + re.escape(BS) + r'][^\s"\']+?\.(?:cpp|c|h|hpp|inl|s)\b', s):
        p = m.group().replace(BS, '/').lower()
        paths.setdefault(p, []).append(a)
print('unique source paths:', len(paths))
srcs = [p for p in paths if p.endswith(('.cpp', '.c', '.s'))]
print('unique .c/.cpp:', len(srcs))
dirs = collections.Counter('/'.join(p.split('/')[:-1]) for p in paths)
for dname, c in sorted(dirs.items()):
    print(f'  {c:3d}  {dname}')
open(sys.argv[2], 'w').write('\n'.join(f'{p}  first@{v[0]:08x} refs={len(v)}' for p, v in paths.items()))
