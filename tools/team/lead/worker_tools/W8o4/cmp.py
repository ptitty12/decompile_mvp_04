"""cmp.py <repo> <unit> <fn> <file.cpp> : compile file.cpp, compare every function in it against target fn."""
import re, sys, subprocess, os, difflib
sys.argv, args = sys.argv[:1], sys.argv[1:]
here = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, here)
root, unit, fn, src = args
import importlib.util
spec = importlib.util.spec_from_file_location("sv", os.path.join(here, "solve_lib.py"))
sv = importlib.util.module_from_spec(spec); spec.loader.exec_module(sv)
t = sv.target(root, unit, fn)
subprocess.run(["bash", os.path.join(here, "dump.sh"), src], check=True)
s = open(src[:-4] + ".s").read()
for m in re.finditer(r"^(\w+?)(__\w+)?:\n", s, re.M):
    name = m.group(1)
    if name.startswith(".") or name in ("gcc2_compiled",): continue
    try: o = sv.ours(s, name)
    except Exception: continue
    sm = difflib.SequenceMatcher(None, t, o)
    diff = sum(max(i2-i1, j2-j1) for tag, i1, i2, j1, j2 in sm.get_opcodes() if tag != "equal")
    print(f"{'MATCH' if o == t else diff:>6} {name} ({len(o)} vs {len(t)})")
    if os.environ.get("SHOW") == name:
        for l in difflib.unified_diff(t, o, lineterm="", n=2): print("   ", l)
