"""clone2.py [--apply] : clone matched header-2 donor functions into my units with identical masked shape."""
import sys, re, subprocess, os
sys.path.insert(0, '.')
from asmlib import *
from rd import rd
WT = (os.environ.get('WT') or os.getcwd())
DONORS = "80459228 8045B134 8045EDDC 80462504 80464090 804654A0 8046C6F8 8046F770".split() + UNITS

def shape(body):
    out = []
    for a, i in ins(body):
        i = re.sub(r'\.L_[0-9A-F]+', 'L', i)
        i = re.sub(r'\b(fn|lbl|gap)_\w+(@\w+)?', lambda m: 'S' + (m.group(2) or ''), i)
        out.append(i)
    return tuple(out)

def syms(body):
    out = []
    for a, i in ins(body):
        i = re.sub(r'\.L_[0-9A-F]+', 'L', i)
        out.append(re.findall(r'\b(?:fn|lbl|gap)_\w+', i))
    return out

def cstr(a):
    b = rd(a, 200)
    if not b:
        return None
    e = b.find(b'\0')
    if e < 0:
        return None
    t = b[:e]
    if t and all(32 <= c < 127 for c in t):
        return t.decode()
    return None

DEF = re.compile(r'^((?:extern "C" )?FE_OVERLAY [^\n]*?\b(fn_[0-9A-F]{8})\([^\n]*\)\n\{\n.*?^\}\n)', re.S | re.M)
def defined_funcs(path):
    src = open(path).read()
    res = {}
    for m in DEF.finditer(src):
        res[m.group(2)] = m.group(1)
    return src, res

apply = '--apply' in sys.argv
matched_by_unit = {}
for d in DONORS:
    r = subprocess.run(['python', 'tools/match/diff_unit.py', 'fe/tu_' + d], cwd=WT, capture_output=True, text=True)
    matched_by_unit[d] = {l.split()[1] for l in r.stdout.splitlines() if l.startswith('MATCH')}
allf = {}
for u in DONORS:
    for n, b in funcs(u):
        if n in matched_by_unit[u]:
            allf.setdefault(shape(b), []).append((u, n, b))
donor_defs = {}
for u in DONORS:
    s, d = defined_funcs(WT + '/src/fe/tu_' + u + '.cpp')
    donor_defs[u] = d
H1 = open(WT + '/include/game/fe_80459228.h').read() + open(WT + '/include/game/fe_804BE560.h').read()
alltext = H1 + ''.join(open(WT + '/src/fe/tu_' + u + '.cpp').read() for u in DONORS)
HDR = set(re.findall(r'(fn_[0-9A-F]{8})\(', H1))
HDR2 = set(re.findall(r'(lbl_[0-9A-F]{8})', H1))

def decl_of(a):
    pat = r'^(?:extern "C" )?(?:FE_OVERLAY )?([^\n;(]*\b' + a + r'\([^\n;]*\))\s*(;|\n\{)'
    m = re.search(pat, alltext, re.M)
    if m:
        return 'extern "C" ' + m.group(1) + ';'
    return None

new = {}
done = set()
for u in UNITS:
    s, d = defined_funcs(WT + '/src/fe/tu_' + u + '.cpp')
    have = set(d)
    for g, gb in funcs(u):
        if g in have or g in done:
            continue
        sh = shape(gb)
        if sh not in allf:
            continue
        for (du, f, fb) in allf[sh]:
            if f not in donor_defs[du]:
                continue
            fs, gs = syms(fb), syms(gb)
            mp = {}
            ok = True
            for x, y in zip(fs, gs):
                for a, b in zip(x, y):
                    if mp.setdefault(a, b) != b:
                        ok = False
            if not ok:
                continue
            text = donor_defs[du][f]
            if not text.startswith('extern "C"'):
                text = 'extern "C" ' + text
            for a, b in list(mp.items()):
                if a.startswith('lbl_') and a != b:
                    sa = cstr(int(a[4:], 16))
                    sb = cstr(int(b[4:], 16))
                    if sa is not None and sb is not None and sa != sb:
                        text = text.replace('"%s"' % sa, '"%s"' % sb)
            mp[f] = g
            for a in sorted(mp, key=len, reverse=True):
                text = re.sub(r'\b' + a + r'\b', mp[a], text)
            decls = []
            for a, b in mp.items():
                if a == f or b == g:
                    continue
                if a.startswith('fn_'):
                    if b in HDR:
                        continue
                    dd = decl_of(a)
                    if dd:
                        dd = re.sub(r'\b' + a + r'\b', b, dd)
                        if dd not in decls:
                            decls.append(dd)
                    else:
                        print('  NO DECL for', a)
                elif a.startswith('lbl_'):
                    if b in HDR2:
                        continue
                    m = re.search(r'^extern [^\n;]*\b' + a + r'\b[^\n;]*;', alltext, re.M)
                    if m:
                        dd = re.sub(r'\b' + a + r'\b', b, m.group(0))
                    else:
                        dd = 'extern const char %s[];' % b
                    if dd not in decls:
                        decls.append(dd)
            new.setdefault(u, []).append((g, decls, text, f, du, mp))
            done.add(g)
            print('clone', du, f, '->', u, g)
            break
if apply:
    for u, lst in new.items():
        p = WT + '/src/fe/tu_' + u + '.cpp'
        s = open(p).read()
        if 'fe_804BE560.h' not in s:
            s += '\n#include "game/fe_804BE560.h"\n'
        for g, decls, text, f, du, mp in lst:
            keep = [l for l in decls if l not in s]
            s += '\n' + '\n'.join(keep) + ('\n' if keep else '') + text
        open(p, 'w').write(s)
        print('wrote', u, len(lst))
