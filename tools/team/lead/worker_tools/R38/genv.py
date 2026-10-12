"""genv.py [--apply]: generate vcall-wrapper family functions in MINE units."""
import sys,re
sys.path.insert(0,'.')
from asmlib import *
WT='C:/Users/Patrick Taylor/decompile_mvp_04-W4'
apply='--apply' in sys.argv
written=set()
for u in MINE:
    written|=set(re.findall(r'\b(fn_[0-9A-F]{8})\(',open(WT+'/src/fe/tu_'+u+'.cpp').read()))
def hx(s): return int(s,16) if s.startswith('0x') else int(s)
out={}
need=set()
for u in MINE:
    for n,b in funcs(u):
        if n in written: continue
        I=[i for a,i in ins(b)]
        I=[i for k,i in enumerate(I) if not (k<4 and re.match(r'(stwu r1|mflr r0|stw r0, 0x[0-9a-f]+\(r1\))',i)) and not (k>len(I)-6 and re.match(r'(lwz r0, 0x[0-9a-f]+\(r1\)|mtlr r0|addi r1, r1)',i) and i!='mtlr r9')]
        # shape: lwz r3,OFF(r3); [li r4,A]; lwz r9,0x3c(r3); lha r0,D(r9); lwz r9,P(r9); add r3,r3,r0; mtlr r9; blrl; li r3,R; blr
        t=list(I)
        m2=re.match(r'lwz r11, (0x[0-9a-f]+)\(r3\)$',t[0]) if t else None
        if m2:
            pat2=[r'cmpwi r11, 0x0$',r'beq (\S+)$',r'lwz r9, 0x3c\(r11\)$',r'lha r3, (0x[0-9a-f]+)\(r9\)$',r'lwz r0, (0x[0-9a-f]+)\(r9\)$',r'add r3, r11, r3$',r'mtlr r0$',r'blrl$',r'li r3, (-?0x[0-9a-f]+|\d+)$',r'blr$']
            r2=t[1:]
            if len(r2)==len(pat2):
                ms2=[re.match(p,x) for p,x in zip(pat2,r2)]
                if all(ms2):
                    off=hx(m2.group(1)); d=hx(ms2[3].group(1)); p=hx(ms2[4].group(1)); r=hx(ms2[8].group(1))
                    if p==d+4 and d%8==0:
                        need.add((off,'FeObj'))
                        out.setdefault(u,[]).append((n,'extern "C" FE_OVERLAY int %s(FeWf%X* self)\n{\n    if (self->m%X != 0)\n        self->m%X->v%d();\n    return %d;\n}\n'%(n,off,off,off,d//8,r)))
            continue
        m=re.match(r'lwz r3, (0x[0-9a-f]+)\(r3\)$',t[0]) if t else None
        if not m: continue
        off=hx(m.group(1)); rest=t[1:]
        a=None
        if rest and re.match(r'li r4, (-?0x[0-9a-f]+|-?\d+)$',rest[0]):
            a=rest[0].split()[-1]; rest=rest[1:]
        pat=[r'lwz r9, 0x3c\(r3\)$',r'lha r0, (0x[0-9a-f]+)\(r9\)$',r'lwz r9, (0x[0-9a-f]+)\(r9\)$',r'add r3, r3, r0$',r'mtlr r9$',r'blrl$',r'li r3, (-?0x[0-9a-f]+|\d+)$',r'blr$']
        if len(rest)!=len(pat): continue
        ms=[re.match(p,x) for p,x in zip(pat,rest)]
        if not all(ms): continue
        d=hx(ms[1].group(1)); p=hx(ms[2].group(1)); r=hx(ms[6].group(1))
        if p!=d+4 or d%8: continue
        slot=d//8
        cls='FeObj' if a is None else 'FeObj1'
        arg='' if a is None else ('%d'%hx(a))
        body='    self->m%X->v%d(%s);\n    return %d;\n'%(off,slot,arg,r)
        # use FeObj or FeObj1 for field type
        fld='FeObj' if a is None else 'FeObj1'
        need.add((off,fld))
        out.setdefault(u,[]).append((n,'extern "C" FE_OVERLAY int %s(FeWf%X%s* self)\n{\n%s}\n'%(n,off,'' if a is None else 'b',body)))
        if a is not None: need.add((off,'FeObj1'))
print({u:len(v) for u,v in out.items()}, sorted((hex(o),f) for o,f in need))
if apply:
    for u,lst in out.items():
        p=WT+'/src/fe/tu_'+u+'.cpp'
        s=open(p).read()
        for n,t in lst: s+='\n'+t
        open(p,'w').write(s)
    # header decls
    h=WT+'/include/game/fe_804E02E0.h'
    hs=open(h).read()
    mk='/* BEGIN-VWRAP */'
    lines=[]
    for off,fld in sorted(need):
        sfx='' if fld=='FeObj' else 'b'
        lines.append('struct FeWf%X%s : FeObj { char pad40[0x%X - 0x40]; %s* m%X; };'%(off,sfx,off,fld,off))
    if mk in hs:
        ex=re.search(r'/\* BEGIN-VWRAP \*/(.*?)/\* END-VWRAP \*/',hs,re.S).group(1)
        for l in ex.splitlines():
            if l.startswith('struct '):
                if l not in lines: lines.append(l)
    lines.sort()
    block='/* BEGIN-VWRAP */\n/* Screens whose only data is one widget pointer at the given offset (one-call button handlers). */\n'+'\n'.join(lines)+'\n/* END-VWRAP */\n'
    if mk in hs: hs=re.sub(r'/\* BEGIN-VWRAP \*/.*?/\* END-VWRAP \*/\n',block,hs,flags=re.S)
    else: hs=hs.replace('#endif',block+'\n#endif')
    open(h,'w').write(hs)
