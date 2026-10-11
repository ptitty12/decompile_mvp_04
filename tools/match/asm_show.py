"""Find/print functions in dtk asm output.

Usage: python asmfind.py <asm_dir> list <min_ins> <max_ins> <must_contain,...> [limit]
       python asmfind.py <asm_dir> show <fn_name> [<fn_name> ...]
"""
import glob, os, re, sys

asm_dir, mode = sys.argv[1], sys.argv[2]
FN = re.compile(r"^\.fn (\S+), \w+$(.*?)^\.endfn \1$", re.S | re.M)


def iter_funcs():
    for f in sorted(glob.glob(os.path.join(asm_dir, "**", "*.s"), recursive=True)):
        txt = open(f, encoding="utf-8").read()
        for m in FN.finditer(txt):
            yield os.path.basename(f), m.group(1), m.group(2)


def compact(body):
    out = []
    for l in body.splitlines():
        m = re.match(r"^/\* ([0-9A-F]{8}) [0-9A-F]+\s+([0-9A-F ]+) \*/\t(.*)$", l)
        if m:
            out.append(f"{m.group(1)} {m.group(2).replace(' ', '')}  {m.group(3)}")
        elif l.strip() and not l.startswith("#"):
            out.append("         " + l.strip())
    return out


if mode == "list":
    lo, hi = int(sys.argv[3]), int(sys.argv[4])
    musts = [s for s in sys.argv[5].split(",") if s]
    limit = int(sys.argv[6]) if len(sys.argv) > 6 else 20
    n = 0
    for f, name, body in iter_funcs():
        ins = [l for l in body.splitlines() if l.startswith("/*")]
        if lo <= len(ins) <= hi and all(s in body for s in musts) and name.startswith("fn_8") and name < "fn_80360000":
            print(f"{name} ({len(ins)} ins) in {f}")
            n += 1
            if n >= limit:
                break
else:
    want = set(sys.argv[3:])
    for f, name, body in iter_funcs():
        if name in want:
            print(f"===== {name} ({f})")
            print("\n".join(compact(body)))
