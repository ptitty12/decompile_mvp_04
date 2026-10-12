import re,sys,collections
units="80355A6C 803560F8 8035688C 8035726C 80357A70 803597C4 8035A2D0 8035AB44".split()
def funcs(u):
    txt=open(f"build/GV4E69/asm/game/tu_{u}.s").read()
    parts=re.split(r"(?m)^\.fn (\w+), \w+\n",txt)
    out=[]
    for i in range(1,len(parts),2):
        name=parts[i]; body=parts[i+1].split(".endfn")[0]
        mm=re.match(r"(fn_[0-9A-F]{8})__F",name)
        if mm: name=mm.group(1)
        ins=[]
        first_set=False
        for l in body.split("\n"):
            m=re.match(r"/\* ([0-9A-F]{8}) [0-9A-F]{8}  (?:[0-9A-F]{2} ){4}\*/\t(.*)",l)
            if m:
                if not ins and not first_set:
                    name = "fn_" + m.group(1)
                    first_set = True
                ins.append(re.sub(r"\b__\d+Unk([0-9A-F]{8})\b", r"fn_\1", m.group(2)))
            elif l.startswith(".L_"): ins.append("LABEL")
        out.append((name,ins))
    return out
def norm(ins):
    r=[]
    for s in ins:
        s=re.sub(r"\.L_[0-9A-F]+","L",s)
        s=re.sub(r"(lbl_|fn_|__)\w+(@\w+)?","SYM",s)
        r.append(s)
    return r
if __name__=="__main__":
    cl=collections.OrderedDict()
    for u in units:
        for n,ins in funcs(u):
            k=tuple(norm(ins))
            cl.setdefault(k,[]).append((u,n))
    print(len(cl),"clusters")
    for k,v in sorted(cl.items(),key=lambda kv:-len(kv[1])):
        print(len(v),len(k),[n for u,n in v][:6])
