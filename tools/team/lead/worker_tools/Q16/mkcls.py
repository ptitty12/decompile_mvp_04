#!/usr/bin/env python3
"""mkcls.py Name 'N=decl' ... : print a FeW-family widget view class (Unk800C7B40_Data base, virtual dtor,
slots s2..s127 returning void with no args) with the given slots replaced.
decl is the part after 'virtual ', e.g. '14=int s14()' or '68=void s68(int a)'."""
import sys
name = sys.argv[1]
spec = {}
for a in sys.argv[2:]:
    k, v = a.split('=', 1)
    spec[int(k)] = v
items = []
for n in range(2, 128):
    items.append(spec.get(n, 'void s%d()' % n))
lines = ['struct %s : Unk800C7B40_Data {' % name, '    virtual ~%s();' % name]
cur = '   '
for it in items:
    t = ' virtual %s;' % it
    if len(cur) + len(t) > 110:
        lines.append(cur)
        cur = '   '
    cur += t
lines.append(cur)
lines.append('};')
print('\n'.join(lines))
