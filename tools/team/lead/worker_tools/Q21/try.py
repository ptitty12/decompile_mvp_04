"""try.py <unit> <fn> <newcode.cpp> [--pre file] [--show N] [--flags F]: scratch = unit source + prelude + each '//////' variant; score fn."""
import sys,os,subprocess,re
sys.path.insert(0,os.path.dirname(os.path.abspath(__file__)))
from ins import insert
W='C:/Users/Patrick Taylor/decompile_mvp_04-W2'
SP=os.path.dirname(os.path.abspath(__file__)).replace(chr(92),'/')
unit,fn,nf=sys.argv[1:4]
show=None; pre=''; extra=[]
a=sys.argv[4:]
i=0
while i<len(a):
    if a[i]=='--show': show=int(a[i+1]); i+=2
    elif a[i]=='--pre': pre=open(a[i+1],newline='').read(); i+=2
    elif a[i]=='--flags': extra+=['--flags',a[i+1]]; i+=2
    else: i+=1
src=open(f'{W}/src/{unit}.cpp',newline='').read()
vs=open(nf,newline='').read().split('//////')
os.makedirs(SP+'/v',exist_ok=True)
files=[]
for k,v in enumerate(vs):
    txt=insert(src,pre+'\n'+v).replace('"../../include/','"'+W+'/include/')
    p=f'{SP}/v/try_{fn}_{k}.cpp'
    open(p,'w',newline='').write(txt)
    files.append(p)
cmd=['python','tools/match/score_variants.py',unit,fn]
if show is not None: cmd+= [files[show],'--show']+extra
else: cmd+= files+extra
r=subprocess.run(cmd,cwd=W,capture_output=True,text=True)
out=r.stdout.replace(SP+'/v/','')
err='\n'.join(l.replace(SP+'/v/','')[:200] for l in r.stderr.splitlines()[:6])
print(out[:7000]); print(err)
