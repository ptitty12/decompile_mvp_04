"""String cross-references -> first-pass subsystem map."""
import sys, os, re, bisect, collections
sys.path.insert(0, os.path.dirname(__file__))
from dol import DOL, sext

d = DOL(sys.argv[1])
funcs = [int(l.split()[0], 16) for l in open(sys.argv[2])]
R13 = 0x806f69c0

strings = {}
for k, i, a, s, o in d.secs:
    if k == 'D':
        for m in re.finditer(rb'[\x20-\x7e]{4,}\x00', d.raw[o:o + s]):
            strings[a + m.start()] = m.group()[:-1].decode('latin1')

refs = collections.defaultdict(set)  # string addr -> set(func)
for sec in d.text():
    hi = {}
    for a, w in d.words(sec):
        op = w >> 26; rd = (w >> 21) & 31; ra = (w >> 16) & 31
        tgt = None
        if op == 15 and ra == 0:
            hi[rd] = ((w & 0xffff) << 16, a)
            continue
        if op in (14, 24) or 32 <= op <= 55:
            if ra == 13 and op == 14:
                tgt = (R13 + sext(w & 0xffff, 16)) & 0xffffffff
            elif ra in hi and a - hi[ra][1] < 64:
                lo = sext(w & 0xffff, 16) if op != 24 else (w & 0xffff)
                tgt = (hi[ra][0] + lo) & 0xffffffff
        if tgt in strings:
            fi = bisect.bisect_right(funcs, a) - 1
            refs[tgt].add(funcs[fi] if fi >= 0 else a)
        if (w >> 26) == 18 or w == 0x4e800020:
            hi.clear()

print('strings referenced from code:', len(refs))
mode = sys.argv[3]
if mode == 'kw':
    kws = sys.argv[4:]
    for kw in kws:
        fs = collections.Counter()
        ex = []
        for sa, fset in refs.items():
            if re.search(kw, strings[sa], re.I):
                for f in fset:
                    fs[f // 0x10000 * 0x10000] += 1
                if len(ex) < 4:
                    ex.append(strings[sa][:50])
        top = ', '.join(f'{b:08x}x{c}' for b, c in fs.most_common(5))
        print(f'{kw:14} refs={sum(fs.values()):4}  top 64K buckets: {top}\n{"":14} e.g. {ex}')
elif mode == 'buckets':
    by = collections.defaultdict(list)
    for sa, fset in refs.items():
        s = strings[sa]
        if len(s) >= 8 and re.search(r'[a-z]{4}', s, re.I) and not s.startswith('<<'):
            for f in fset:
                by[f // 0x20000 * 0x20000].append(s)
    for b in sorted(by):
        ss = sorted(set(by[b]), key=lambda x: -len(x))
        pick = [x[:42] for x in ss if '/' not in x][:6]
        paths = sorted({x.split('/')[-1] for x in ss if x.lower().startswith('c:/')})[:6]
        print(f'{b:08x}: {pick} {paths if paths else ""}')
