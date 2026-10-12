"""rettoggle.py <repo> <unit> <fn> : for each callee of fn (from the target asm), toggle its
declared return type (void <-> int) in the preprocessed unit and report the score of fn.
Works on a copy in scratch: <scratch>/rt/<fnbase>.i"""
import os, re, sys, subprocess, difflib, importlib.util, shutil
here = os.path.dirname(os.path.abspath(__file__))
spec = importlib.util.spec_from_file_location("sv", os.path.join(here, "solve_lib.py"))
sv = importlib.util.module_from_spec(spec); spec.loader.exec_module(sv)
root, unit, fn = sys.argv[1:4]
W = root
CC = os.path.join(W, "build/compilers/ProDG/3.9.3")
env = dict(os.environ, SN_NGC_PATH=CC.replace('/', chr(92)))
FLAGS = os.environ.get("CFLAGS_OVR", "-Os -G0 -ffloat-store -fno-rtti -fno-exceptions").split()
d = os.path.join(here, "rt"); os.makedirs(d, exist_ok=True)
base = fn.split("__")[0] if fn.startswith("fn_") else fn
src = os.path.join(root, "src", unit + ".cpp")
cpp = os.path.join(d, base + ".cpp"); shutil.copy(src, cpp)
ii = os.path.join(d, base + ".i")
subprocess.run([os.path.join(CC, "ngccc.exe"), "-E", "-I" + os.path.join(W, "include"), cpp, "-o", ii], check=True, env=env)
text = open(ii).read()
t = sv.target(root, unit, fn)
# callees from the target asm
callees = []
cur = False
for line in open(os.path.join(root, "build/GV4E69/asm", unit + ".s"), errors="replace"):
    if line.startswith(".fn " + fn): cur = True; continue
    if cur and line.startswith(".endfn"): break
    if cur:
        m = re.search(r"\bbl (\w+)", line)
        if m and m.group(1) not in callees: callees.append(m.group(1))
def score(txt):
    open(ii + ".t.i", "w").write(txt)
    s_out = ii + ".t.s"
    r = subprocess.run([os.path.join(CC, "cc1plus.exe")] + FLAGS + ["-quiet", ii + ".t.i", "-o", s_out], env=env, capture_output=True, text=True)
    if r.returncode: return None
    s = open(s_out).read()
    try: o = sv.ours(s, fn)
    except Exception: return None
    sm = difflib.SequenceMatcher(None, t, o)
    return sum(max(i2-i1, j2-j1) for tag, i1, i2, j1, j2 in sm.get_opcodes() if tag != "equal")
b0 = score(text)
print(f"{unit} {fn}: base {b0}")
TYPES = r"(?:void|int|unsigned int|unsigned|char\s*\*|const char\s*\*|[A-Za-z_]\w*\s*\*)"
for c in callees:
    name = c.split("__")[0] if c.startswith("fn_") else c
    pat = re.compile(r"(\b(?:extern\s+\"C\"\s+)?)(" + TYPES + r")(\s+)(" + re.escape(name) + r")(\s*\()")
    ms = list(pat.finditer(text))
    if not ms: print(f"   {c}: no decl"); continue
    # toggle all declarations of this name
    def rep(m):
        ty = m.group(2)
        nt = "int" if ty.strip() == "void" else "void"
        return m.group(1) + nt + m.group(3) + m.group(4) + m.group(5)
    newt = pat.sub(rep, text)
    sc = score(newt)
    kinds = sorted(set(m.group(2).strip() for m in ms))
    flag = "  <== MATCH" if sc == 0 else ("  <== better" if sc is not None and b0 is not None and sc < b0 else "")
    print(f"   {c} [{'/'.join(kinds)} -> toggled]: {sc}{flag}")
if os.environ.get("PAIRS"):
    import itertools
    pats = {}
    for c in callees:
        name = c.split("__")[0] if c.startswith("fn_") else c
        pat = re.compile(r"(\b(?:extern\s+\"C\"\s+)?)(" + TYPES + r")(\s+)(" + re.escape(name) + r")(\s*\()")
        if pat.search(text): pats[c] = pat
    def rep(m):
        nt = "int" if m.group(2).strip() == "void" else "void"
        return m.group(1) + nt + m.group(3) + m.group(4) + m.group(5)
    for a, b in itertools.combinations(list(pats), 2):
        t2 = pats[b].sub(rep, pats[a].sub(rep, text))
        sc = score(t2)
        if sc is not None and b0 is not None and sc < b0:
            print(f"   PAIR {a} + {b}: {sc}{'  <== MATCH' if sc == 0 else ''}")
