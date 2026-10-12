"""mixsolve2.py <repo> <unit> <fn> <idxreg r3|r4|r5> <maxv> : general constant switch solver.
Cases are a contiguous range [a, b] within 0..maxv; default = value outside the range.
Forms: r (int r = dflt; case: r = v; break;) and ret (case: return v; ... return dflt;),
signed/unsigned index. Prints MATCH lines (name encodes form_sign_a_b)."""
import sys, os, subprocess
here = os.path.dirname(os.path.abspath(__file__))
root, unit, fn, reg, maxv = sys.argv[1:6]
maxv = int(maxv)
env = dict(os.environ, IDX=reg)
out = subprocess.run([sys.executable, os.path.join(here, "treeval.py"), root, unit, fn, "-1", str(maxv + 1)],
                     capture_output=True, text=True, env=env).stdout.split("\n")
vals = {}
for l in out:
    if l.strip():
        k, v = l.split()
        vals[int(k)] = 0 if v == "None" else int(v)
dflt = vals[maxv + 1]
params = {"r3": "int k", "r4": "void* l, int k", "r5": "void* l, void* m, int k"}[reg]
src = ""
for form in ("r", "ret"):
    for sign in ("int", "unsigned"):
        for a in range(0, 6):
            for b in range(a, maxv + 1):
                name = f"S_{form}_{sign[0]}_{a}_{b}"
                s = f'extern "C" int {name}({params})\n{{\n'
                if form == "r":
                    s += f"    int r = {dflt};\n"
                s += f"    switch (({sign})k) {{\n" if sign == "unsigned" else "    switch (k) {\n"
                for c in range(a, b + 1):
                    s += f"    case {c}: " + (f"r = {vals[c]}; break;\n" if form == "r" else f"return {vals[c]};\n")
                s += "    }\n    return " + ("r" if form == "r" else str(dflt)) + ";\n}\n"
                src += s
path = os.path.join(here, f"mix2_{fn}.cpp")
open(path, "w").write(src)
r = subprocess.run([sys.executable, os.path.join(here, "cmp.py"), root, unit, fn, path], capture_output=True, text=True)
hits = [l.strip() for l in r.stdout.splitlines() if "MATCH" in l]
best = sorted((int(l.split()[0]), l.strip()) for l in r.stdout.splitlines() if l.split() and l.split()[0].isdigit())[:2]
print(fn, "dflt", dflt, hits[:4] if hits else ("no match; best " + str(best)))
