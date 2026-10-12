"""hill.py unit sym 'header line' stmts_file [restarts] : hill-climb statement order via batch scoring
Lines of stmts_file are statements; lines starting with '@pre ' / '@post ' are fixed prefix/suffix lines.
Moves: all pairwise swaps and all single-element moves."""
import sys, re, os, random, subprocess, itertools
WT='C:/Users/Patrick Taylor/decompile_mvp_04-W6'
HERE=os.path.dirname(os.path.abspath(__file__))
unit,sym,header,stmts_file=sys.argv[1:5]
restarts=int(sys.argv[5]) if len(sys.argv)>5 else 3
allines=[l.rstrip('\n') for l in open(stmts_file) if l.strip()]
PRE=[l[5:] for l in allines if l.startswith('@pre ')]
POST=[l[6:] for l in allines if l.startswith('@post ')]
stmts=[l for l in allines if not l.startswith('@pre ') and not l.startswith('@post ')]
src=open(f'{WT}/src/{unit}.cpp').read()
m=re.search(r'^'+re.escape(header)+r'\n\{\n.*?^\}\n',src,re.S|re.M)
assert m,'header not found'
pre,post=src[:m.start()],src[m.end():]
d=HERE+'/hc'
os.makedirs(d,exist_ok=True)
def score_many(perms):
    for f in os.listdir(d): os.remove(d+'/'+f)
    for i,p in enumerate(perms):
        body='\n'.join(PRE+[stmts[k] for k in p]+POST)
        open(f'{d}/p{i:05d}.cpp','w').write(pre+header+'\n{\n'+body+'\n}\n'+post)
    r=subprocess.run(['python','tools/match/score_variants.py',unit,sym,d],cwd=WT,capture_output=True,text=True)
    res={}
    for l in r.stdout.splitlines():
        t=l.split()
        if 'aligned' not in l: continue
        sc=0 if t[0]=='MATCH' else int(t[0])
        al=int(t[2])
        mm=re.search(r'p(\d{5})\.cpp',l)
        res[int(mm.group(1))]=(sc,al)
    return [res.get(i,(999,999)) for i in range(len(perms))]
def neighbors(p):
    n=len(p);out=set()
    for i in range(n):
        for j in range(i+1,n):
            q=list(p);q[i],q[j]=q[j],q[i];out.add(tuple(q))
    for i in range(n):
        for j in range(n):
            if i!=j:
                q=list(p);x=q.pop(i);q.insert(j,x);out.add(tuple(q))
    out.discard(tuple(p))
    return list(out)
best_all=None
for r in range(restarts):
    p=list(range(len(stmts)))
    if r>0: random.shuffle(p)
    cur=score_many([p])[0]
    print('restart',r,'start',cur,flush=True)
    while True:
        nb=neighbors(p)
        sc=score_many(nb)
        k=min(range(len(nb)),key=lambda i:(sc[i][0],sc[i][1]))
        if (sc[k][0],sc[k][1])<cur:
            cur=sc[k];p=list(nb[k]);print(' ->',cur,flush=True)
            if cur[0]==0: break
        else: break
    if best_all is None or cur<best_all[0]: best_all=(cur,p)
    if cur[0]==0: break
print('BEST',best_all[0])
print('\n'.join(PRE+[stmts[k] for k in best_all[1]]+POST))
if os.environ.get('APPLY') and best_all[0][0]==0:
    body='\n'.join(PRE+[stmts[k] for k in best_all[1]]+POST)
    open(f'{WT}/src/{unit}.cpp','w').write(pre+header+'\n{\n'+body+'\n}\n'+post)
    print('APPLIED')
