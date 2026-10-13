#!/usr/bin/env python3
"""Run decomp-permuter on one near-miss function of a C unit, unattended.

Usage (from a worktree root, after `python configure.py && ninja` once):
  python tools/match/permute.py <unit> <function> [--minutes 20] [-j 4]
        [--source FILE.c] [--dir DIR] [--setup-only] [--show-errors]

  <unit>      unit path under src/ without extension, e.g. dolphin/os/tu_804321CC
  <function>  the function's name in that unit (as in dtk's split asm)
  --source    a C file to start from instead of src/<unit>.c. decomp-permuter parses
              C only, so a C++ unit needs a C extraction of the function and what it uses.

What it sets up in DIR (default build/permute/<function>, gitignored):
  target.o     the retail function alone: its `.fn` block from dtk's split asm
               (build/GV4E69/asm/<unit>.s), assembled with build/binutils/powerpc-eabi-as.
  base.c       the unit (or --source) preprocessed by the unit's own compiler and cflags
               from build.ninja (MWCC for the Dolphin SDK, ProDG ngccc otherwise), cut down
               the way the permuter will cut it: the target and `inline` functions keep
               their bodies, the rest become prototypes. Helpers the compiler inlined on
               its own (found from full.c's code: called in the source, no `bl`) are
               marked `inline` so they survive, and setup warns if base.c then compiles the
               function differently from the full unit (full.c). Compiler extensions
               pycparser can't read (__declspec, __attribute__, asm functions) are removed
               from the other declarations.
  compile.sh   compiles a candidate the same way.
  settings.toml  names the function and an objdump that disassembles only that
               function (--disassemble=<function>), so the rest of base.c is not scored.
Then it runs the permuter for --minutes, stops it, and lists the best candidates
(DIR/output-<score>-<n>/source.c; lower is better, 0 is a match).

A candidate is only a lead: port the change into the real source and confirm it with
score_variants.py, the build and tools/verify/verify.py as usual.

The permuter itself is not vendored. It lives in its own clone and venv:
  PERMUTER_DIR  default C:\\Users\\Patrick Taylor\\tools-ext\\permuter
                (github.com/simonlindholm/decomp-permuter)
  PERMUTER_PY   default C:\\Users\\Patrick Taylor\\tools-ext\\permuter-venv\\Scripts\\python.exe
                (pip install toml Levenshtein)
Its `cpp` step uses ProDG's CPP.exe; it needs Git for Windows' bash on PATH.
"""
import argparse
import os
import re
import shlex
import shutil
import signal
import subprocess
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from score_variants import EXE, ROOT, VERSION, ninja_vars  # noqa: E402

PERMUTER_DIR = Path(os.environ.get("PERMUTER_DIR", r"C:\Users\Patrick Taylor\tools-ext\permuter"))
PERMUTER_PY = Path(os.environ.get("PERMUTER_PY", r"C:\Users\Patrick Taylor\tools-ext\permuter-venv\Scripts\python.exe"))
PRODG = ROOT / "build" / "compilers" / "ProDG" / "3.9.3"  # its CPP.exe serves the permuter's `cpp`
BINUTILS = ROOT / "build" / "binutils"
SECTION = re.compile(r"^\s*\.(text|data|rodata|bss|sdata2?|sbss2?|section\s+\S+.*)\s*$")


def compiler(v):
    """(argv prefix, env) that compile like the unit's ninja rule."""
    tool = ROOT / "build" / "compilers" / v["mw_version"]
    if (tool / f"ngccc{EXE}").exists():
        return [str(tool / f"ngccc{EXE}")], dict(os.environ, SN_NGC_PATH=str(tool))
    if (tool / f"mwcceppc{EXE}").exists():
        return [str(tool / f"mwcceppc{EXE}")], dict(os.environ)
    sys.exit(f"no ngccc or mwcceppc in {tool} (run configure.py and ninja first)")


def target_asm(unit, fn):
    """The function's `.fn` block from dtk's split asm, with the include and its section."""
    path = ROOT / "build" / VERSION / "asm" / f"{unit}.s"
    if not path.exists():
        sys.exit(f"missing {path} (run ninja first)")
    lines = path.read_text(encoding="utf-8").splitlines()
    section = ".text"
    for i, line in enumerate(lines):
        if SECTION.match(line):
            section = line.strip()
        if re.match(rf"\.fn {re.escape(fn)}\b", line.strip()):
            end = next((j for j in range(i, len(lines)) if re.match(rf"\.endfn {re.escape(fn)}\b", lines[j].strip())), None)
            if end is None:
                sys.exit(f"no .endfn {fn} in {path}")
            return "\n".join(['.include "macros.inc"', section, ".balign 4", *lines[i:end + 1], ""])
    sys.exit(f"no `.fn {fn}` in {path}")


def balanced(text, start):
    """Index just past the bracket group that opens at text[start] ('(' or '{')."""
    pairs = {"(": ")", "{": "}"}
    open_, close, depth = text[start], pairs[text[start]], 0
    for i in range(start, len(text)):
        depth += (text[i] == open_) - (text[i] == close)
        if depth == 0:
            return i + 1
    return len(text)


def drop_calls(text, word):
    """Remove every `word(...)` (balanced parens), e.g. __declspec(weak) or __attribute__((x))."""
    out, pos = [], 0
    for m in re.finditer(rf"\b{word}\s*\(", text):
        if m.start() < pos:
            continue
        out.append(text[pos:m.start()])
        pos = balanced(text, m.end() - 1)
    return "".join(out) + text[pos:]


def for_pycparser(text, fn):
    """Make compiler-extension syntax parseable by the permuter's pycparser.

    Only declarations and other functions change: linkage/section attributes go, and
    asm functions become prototypes. The target function must be plain C."""
    for word in ("__declspec", "__attribute__", "__attribute"):
        text = drop_calls(text, word)
    text = re.sub(r"\b__inline(__)?\b", "inline", text)
    text = re.sub(r"\b__restrict(__)?\b", "", text)
    text = re.sub(r"\b__const\b", "const", text)
    out, pos = [], 0
    for m in re.finditer(r"^[ \t]*(?:static\s+)?asm\b([^;{}]*?\))\s*\{", text, re.M):
        if m.start() < pos:
            continue
        if re.search(rf"\b{re.escape(fn)}\s*\(", m.group(1)):
            sys.exit(f"{fn} is an asm function; the permuter cannot work on it")
        out.append(text[pos:m.start()] + re.sub(r"\basm\b", "", m.group(0)[:m.group(0).rindex("{")]).rstrip() + ";")
        pos = balanced(text, m.end() - 1)
    text = "".join(out) + text[pos:]
    # pycparser reads `sizeof(T) + x` as `sizeof((T)(+x))`; parenthesized, it reads it right.
    out, pos = [], 0
    for m in re.finditer(r"\bsizeof\s*\(", text):
        if m.start() < pos:
            continue
        end = balanced(text, m.end() - 1)
        out.append(text[pos:m.start()] + "(" + text[m.start():end] + ")")
        pos = end
    text = "".join(out) + text[pos:]
    if "__builtin_va_list" in text and not re.search(r"typedef[^;]*\b__builtin_va_list\b", text):
        text = "typedef char *__builtin_va_list;\n" + text
    return text


def decl_start(header):
    """Offset of a declaration's first token, past blank, `#` and comment-only lines."""
    pos = 0
    for line in header.splitlines(keepends=True):
        s = line.strip()
        if s and not s.startswith("#") and not (s.startswith("/*") and s.endswith("*/")):
            return pos + len(line) - len(line.lstrip())
        pos += len(line)
    return len(header)


def definitions(text):
    """{name: (header_start, body_start, body_end)} for each top-level function definition."""
    defs, depth, last_end, i = {}, 0, 0, 0
    while i < len(text):
        c = text[i]
        if c in ";}" and depth == 0:
            last_end = i + 1
        elif c == "{":
            if depth == 0 and text[last_end:i].rstrip().endswith(")"):
                end = balanced(text, i)
                start = last_end + decl_start(text[last_end:i])
                m = re.search(r"(\w+)\s*\(", text[start:i])
                if m:
                    defs[m.group(1)] = (start, i, end)
                i = last_end = end
                continue
            depth += 1
        elif c == "}":
            depth -= 1
        i += 1
    return defs


def called(text):
    return set(re.findall(r"\b([A-Za-z_]\w*)\s*\(", text))


def compile_fn(cc, cflags, env, src, obj, fn):
    """Compile src and return (disassembly rows of fn without addresses, its bl targets)."""
    r = subprocess.run([*cc, *cflags, "-c", str(src), "-o", str(obj)], cwd=ROOT, env=env, capture_output=True,
                       text=True, encoding="utf-8", errors="replace")
    if r.returncode:
        sys.exit(f"compiling {src} failed:\n{(r.stdout + r.stderr)[-2000:]}")
    out = subprocess.run([str(BINUTILS / f"powerpc-eabi-objdump{EXE}"), "-dr", f"--disassemble={fn}", str(obj)],
                         capture_output=True, text=True).stdout
    rows, calls = [], set()
    for line in out.splitlines():
        m = re.match(r"^\s+[0-9a-f]+:\s+((?:[0-9a-f]{2} ){4})\s*(\S+)", line)
        if m:
            rows.append((m.group(1), m.group(2)))
        m = re.match(r"^\s+[0-9a-f]+: R_PPC_REL24\s+(\S+)", line)
        if m:
            calls.add(m.group(1))
    return rows, calls


def prune(text, fn, keep_inline):
    """What the permuter compiles: fn and inline functions keep bodies, others become prototypes."""
    defs = definitions(text)
    out, pos = [], 0
    for name, (h, b, e) in sorted(defs.items(), key=lambda x: x[1][0]):
        header = text[h:b]
        if name == fn or name in keep_inline or re.search(r"\binline\b", header):
            if name in keep_inline and not re.search(r"\binline\b", header):
                header = "inline " + header  # h is the declaration's first token
            out.append(text[pos:h] + header + text[b:e])
        else:
            out.append(text[pos:h] + header.rstrip() + ";")
        pos = e
    return "".join(out) + text[pos:]


def setup(a):
    unit = a.unit.replace("\\", "/").removeprefix("src/").removesuffix(".cpp").removesuffix(".c")
    src = Path(a.source).resolve() if a.source else ROOT / "src" / f"{unit}.c"
    if not src.exists():
        cpp = ROOT / "src" / f"{unit}.cpp"
        sys.exit(f"{src} does not exist" + (f"; {cpp.name} is C++, which the permuter cannot parse: "
                                             "pass --source with a C extraction" if cpp.exists() else ""))
    for p in (PERMUTER_DIR / "permuter.py", PERMUTER_PY, PRODG / f"CPP{EXE}", BINUTILS / f"powerpc-eabi-as{EXE}"):
        if not p.exists():
            sys.exit(f"missing {p}" + (" (run `ninja build/binutils`)" if "binutils" in str(p) else ""))
    if not shutil.which("bash"):
        sys.exit("bash is not on PATH (Git for Windows provides it)")

    v = ninja_vars(unit)
    cc, env = compiler(v)
    cflags = shlex.split(v["cflags"])
    d = Path(a.dir).resolve() if a.dir else ROOT / "build" / "permute" / a.function
    if d.exists():
        shutil.rmtree(d)
    d.mkdir(parents=True)

    (d / "target.s").write_text(target_asm(unit, a.function), encoding="utf-8")
    r = subprocess.run([str(BINUTILS / f"powerpc-eabi-as{EXE}"), "-mgekko", "-I", str(ROOT / "build" / VERSION / "include"),
                        "-o", str(d / "target.o"), str(d / "target.s")], capture_output=True, text=True)
    if r.returncode:
        sys.exit(f"assembling the target failed:\n{r.stdout}{r.stderr}")

    r = subprocess.run([*cc, *cflags, "-E", str(src)], cwd=ROOT, env=env, capture_output=True, text=True,
                       encoding="utf-8", errors="replace")
    if r.returncode or not r.stdout.strip():
        sys.exit(f"preprocessing {src} failed:\n{r.stderr[-2000:]}")
    base = re.sub(r"^\s*#\s*(line\s+)?\d+.*$", "", r.stdout, flags=re.M)  # line markers
    full = for_pycparser(base, a.function)
    defs = definitions(full)
    if a.function not in defs:
        sys.exit(f"{a.function} has no body in {src}")
    # The permuter keeps only the target's body and `inline` ones. Helpers the compiler
    # inlined on its own (MWCC -inline auto, static functions) must stay inline, or the
    # target compiles to calls: find them from the full unit's code (called in the source,
    # but no `bl` to them), mark them inline, and check the result compiles the same.
    (d / "full.c").write_text(full, encoding="utf-8")
    want, calls = compile_fn(cc, cflags, env, d / "full.c", d / "full.o", a.function)
    inline, todo = set(), [a.function]
    while todo:
        h, b, e = defs[todo.pop()]
        for name in called(full[b:e]) & defs.keys() - calls - inline - {a.function}:
            inline.add(name)
            todo.append(name)
    base = prune(full, a.function, inline)
    (d / "base.c").write_text(base, encoding="utf-8")
    got, _ = compile_fn(cc, cflags, env, d / "base.c", d / "base.o", a.function)
    diff = sum(x != y for x, y in zip(want, got)) + abs(len(want) - len(got))
    print(f"inlined helpers kept: {', '.join(sorted(inline)) or 'none'}")
    if diff:
        print(f"WARNING: pruned base.c compiles {a.function} differently from the full unit "
              f"({diff} instruction slots); scores are offset from the real build")

    # compile.sh runs under Git Bash: $1 = candidate .c, $3 = output .o.
    sn = f"export SN_NGC_PATH={shlex.quote(env['SN_NGC_PATH'])}\n" if "SN_NGC_PATH" in env else ""
    (d / "compile.sh").write_text(
        "#!/bin/bash\n"
        "# Written by tools/match/permute.py: the unit's compiler and cflags from build.ninja.\n"
        "export MSYS_NO_PATHCONV=1\n" + sn +
        f"cd {shlex.quote(ROOT.as_posix())}\n"
        f"exec {shlex.quote(Path(cc[0]).as_posix())} {v['cflags']} -c \"$1\" -o \"$3\"\n",
        encoding="utf-8", newline="\n")
    kind = "gcc" if "SN_NGC_PATH" in env else "mwcc"
    objdump = (BINUTILS / f"powerpc-eabi-objdump{EXE}").as_posix()
    (d / "settings.toml").write_text(
        f'func_name = "{a.function}"\ncompiler_type = "{kind}"\n'
        f"objdump_command = '\"{objdump}\" -dr --disassemble={a.function} -EB -mpowerpc -M broadway'\n",
        encoding="utf-8")
    return d


def run(d, a):
    env = dict(os.environ)
    env["PATH"] = os.pathsep.join([str(PRODG), str(BINUTILS), env.get("PATH", "")])  # cpp, powerpc-eabi-objdump
    log = d / "permuter.log"
    cmd = [str(PERMUTER_PY), str(PERMUTER_DIR / "permuter.py"), str(d), "-j", str(a.jobs), "--stop-on-zero"]
    if a.show_errors:
        cmd.append("--show-errors")
    print(f"permuting {a.function} for {a.minutes} min with {a.jobs} jobs; log {log}", flush=True)
    with open(log, "w", encoding="utf-8", errors="replace") as f:
        p = subprocess.Popen(cmd, cwd=d, env=env, stdout=f, stderr=subprocess.STDOUT,
                             creationflags=getattr(subprocess, "CREATE_NEW_PROCESS_GROUP", 0))
        try:
            p.wait(timeout=a.minutes * 60)
        except subprocess.TimeoutExpired:
            if os.name == "nt":
                subprocess.run(["taskkill", "/T", "/F", "/PID", str(p.pid)], capture_output=True)
            else:
                p.send_signal(signal.SIGINT)
            p.wait()
    text = log.read_text(encoding="utf-8", errors="replace")
    base = re.search(r"base score = (\d+)", text)
    outs = sorted(((int(m.group(1)), o) for o in d.glob("output-*") if (m := re.match(r"output-(\d+)-", o.name))),
                  key=lambda x: x[0])
    print(f"base score {base.group(1) if base else '?'}; {len(outs)} candidates saved, best first (0 = match)")
    for score, o in outs[:5]:
        print(f"  {score:6}  {o / 'source.c'}")
    if not base:
        print("the permuter did not start; last lines of its log:\n" + "\n".join(text.splitlines()[-15:]))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("unit")
    ap.add_argument("function")
    ap.add_argument("--minutes", type=float, default=20)
    ap.add_argument("-j", "--jobs", type=int, default=4)
    ap.add_argument("--source", help="C file to start from instead of src/<unit>.c")
    ap.add_argument("--dir", help="scratch directory (default build/permute/<function>)")
    ap.add_argument("--setup-only", action="store_true", help="write the directory, don't run")
    ap.add_argument("--show-errors", action="store_true", help="pass --show-errors to the permuter")
    a = ap.parse_args()
    t = time.time()
    d = setup(a)
    print(f"set up {d} in {time.time() - t:.1f}s")
    if not a.setup_only:
        run(d, a)


if __name__ == "__main__":
    main()
