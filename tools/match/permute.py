#!/usr/bin/env python3
"""Run decomp-permuter on one near-miss function, unattended (C and C++ units).

Usage (from a worktree root, after `python configure.py && ninja` and `ninja build/binutils`):
  python tools/match/permute.py <unit> <function> [--minutes 20] [-j 4]
        [--source FILE] [--dir DIR] [--setup-only] [--show-errors] [--force]

  <unit>      unit path under src/ without extension, e.g. dolphin/os/tu_804321CC
  <function>  the function's name in dtk's split asm (mangled if the symbol is)
  --source    start from this file instead of src/<unit>.c / .cpp

What it sets up in DIR (default build/permute/<function>, gitignored):
  target.o     the retail function alone: its `.fn` block from dtk's split asm
               (build/GV4E69/asm/<unit>.s), assembled with build/binutils/powerpc-eabi-as.
  base.c       C for the permuter to parse and mutate.
               C unit: the unit preprocessed by its own compiler and cflags (MWCC for
               the Dolphin SDK, ProDG ngccc otherwise), cut down the way the permuter cuts
               it: the target and `inline` functions keep their bodies, the rest become
               prototypes. Helpers the compiler inlined on its own (found from full.c's
               code: called in the source, no `bl`) are marked `inline` so they survive.
               C++ unit: the function plus only the declarations it uses, flattened to C
               by cxx2c.py (records keep their data members, references become pointers,
               ...); declarations pycparser still rejects are dropped one by one.
               Either way, compiler extensions pycparser can't read (__declspec,
               __attribute__, asm functions) are removed from the other declarations.
  compile.sh   C unit: the unit's compiler and cflags on the candidate.
               C++ unit: `permute.py --splice` puts the candidate's function body back
               into the original preprocessed unit (orig.cpp) and compiles that with g++,
               so codegen and (mangled) symbol names are exactly the real build's.
  settings.toml  names the function and an objdump that disassembles only that
               function (--disassemble=<function>), so the rest of the object is not scored.
Setup compiles base.c through compile.sh and compares the function with the real unit's
code. A C++ unit is refused when they differ (--force overrides); a C unit gets a warning.
Refusals name the reason: methods and g++ named return values (`) return r`) have no
plain definition to splice, and some bodies use C++ the C parser cannot read.
Then it runs the permuter for --minutes, stops it, and lists the best candidates
(DIR/output-<score>-<n>/source.c; lower is better, 0 is a match).

A candidate is only a lead: port the change into the real source and confirm it with
score_variants.py, the build and tools/verify/verify.py as usual.

The permuter itself is not vendored. It lives in its own clone and venv:
  PERMUTER_DIR  default C:\\Users\\Patrick Taylor\\tools-ext\\permuter
                (github.com/simonlindholm/decomp-permuter)
  PERMUTER_PY   default C:\\Users\\Patrick Taylor\\tools-ext\\permuter-venv\\Scripts\\python.exe
                (pip install toml Levenshtein)
Its `cpp` step uses ProDG's CPP.exe; it needs Git for Windows' bash on PATH. About 5% of
its mutations fail on C99 `for (int i ...)` declarations (a permuter limitation); it skips
those and goes on.
"""
import argparse
import json
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
from cxx2c import base_name, cxx_to_c, definition_body, is_definition_of, needed_only, segments  # noqa: E402

PERMUTER_DIR = Path(os.environ.get("PERMUTER_DIR", r"C:\Users\Patrick Taylor\tools-ext\permuter"))
PERMUTER_PY = Path(os.environ.get("PERMUTER_PY", r"C:\Users\Patrick Taylor\tools-ext\permuter-venv\Scripts\python.exe"))
PRODG = ROOT / "build" / "compilers" / "ProDG" / "3.9.3"  # its CPP.exe serves the permuter's `cpp`
BINUTILS = ROOT / "build" / "binutils"
SECTION = re.compile(r"^\s*\.(text|data|rodata|bss|sdata2?|sbss2?|section\s+\S+.*)\s*$")


def git_bash_dir():
    """Git for Windows' bash directory (not WSL's System32\\bash.exe, which may come first on PATH)."""
    for d in (os.environ.get("GIT_BASH_DIR"), r"C:\Program Files\Git\usr\bin", r"C:\Program Files\Git\bin"):
        if d and Path(d, "bash.exe").exists():
            return d
    git = shutil.which("git")
    if git:
        for d in (Path(git).parents[1] / "usr" / "bin", Path(git).parents[1] / "bin"):
            if (d / "bash.exe").exists():
                return str(d)
    return None if os.name == "nt" else str(Path(shutil.which("bash") or "/bin/bash").parent)


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
            # The full split file declares these flags before switching back with
            # a bare .section. A standalone function must carry that declaration
            # too, or objdump -d sees an empty target and scores every instruction
            # as an insertion. This changes only the scratch object's metadata.
            if section in (".section .feoverlay", ".section .dboverlay"):
                section += ', "ax"'
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
    return disasm(obj, fn)


def disasm(obj, fn):
    """(rows of fn as (bytes, mnemonic), names it calls with bl) from an object."""
    result = subprocess.run([str(BINUTILS / f"powerpc-eabi-objdump{EXE}"), "-dr", f"--disassemble={fn}", str(obj)],
                            capture_output=True, text=True)
    if result.returncode:
        raise RuntimeError(f"objdump failed for {obj}: {result.stderr.strip()}")
    out = result.stdout
    rows, calls = [], set()
    for line in out.splitlines():
        m = re.match(r"^\s+[0-9a-f]+:\s+((?:[0-9a-f]{2} ){4})\s*(\S+)", line)
        if m:
            rows.append((m.group(1), m.group(2)))
        m = re.match(r"^\s+[0-9a-f]+: R_PPC_REL24\s+(\S+)", line)
        if m:
            calls.add(m.group(1))
    return rows, calls


def require_target(obj, fn):
    """Reject missing/non-executable targets before spending time on mutations."""
    rows, _ = disasm(obj, fn)
    if not rows:
        sys.exit(f"REFUSED: {fn} has no disassembled target instructions in {obj}; "
                 "check its symbol and executable section flags")
    return rows


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
    if not a.source and not src.exists() and (ROOT / "src" / f"{unit}.cpp").exists():
        src = ROOT / "src" / f"{unit}.cpp"
    if not src.exists():
        sys.exit(f"{src} does not exist")
    cxx = src.suffix == ".cpp"
    cname = base_name(a.function) if cxx else a.function  # the function's name in the C
    for p in (PERMUTER_DIR / "permuter.py", PERMUTER_PY, PRODG / f"CPP{EXE}", BINUTILS / f"powerpc-eabi-as{EXE}"):
        if not p.exists():
            sys.exit(f"missing {p}" + (" (run `ninja build/binutils`)" if "binutils" in str(p) else ""))
    if not git_bash_dir():
        sys.exit("Git for Windows' bash not found (set GIT_BASH_DIR)")

    v = ninja_vars(unit)
    cc, env = compiler(v)
    cflags = shlex.split(v["cflags"])
    d = Path(a.dir).resolve() if a.dir else ROOT / "build" / "permute" / cname
    if d.exists():
        shutil.rmtree(d)
    d.mkdir(parents=True)

    (d / "target.s").write_text(target_asm(unit, a.function), encoding="utf-8")
    r = subprocess.run([str(BINUTILS / f"powerpc-eabi-as{EXE}"), "-mgekko", "-I", str(ROOT / "build" / VERSION / "include"),
                        "-o", str(d / "target.o"), str(d / "target.s")], capture_output=True, text=True)
    if r.returncode:
        sys.exit(f"assembling the target failed:\n{r.stdout}{r.stderr}")
    require_target(d / "target.o", a.function)

    r = subprocess.run([*cc, *cflags, "-E", str(src)], cwd=ROOT, env=env, capture_output=True, text=True,
                       encoding="utf-8", errors="replace")
    if r.returncode or not r.stdout.strip():
        sys.exit(f"preprocessing {src} failed:\n{r.stderr[-2000:]}")
    pre = re.sub(r"^\s*#\s*(line\s+)?\d+.*$", "", r.stdout, flags=re.M)  # line markers
    if cxx and definition_body(pre, a.function):
        cname = a.function  # the source spells the (mangled) name out itself
    if cxx:
        want = setup_cxx(a, d, cc, cflags, env, pre, cname)
    else:
        want = setup_c(a, d, cc, cflags, env, v, pre)
    got, _ = disasm(d / "base.o", a.function)
    diff = sum(x != y for x, y in zip(want, got)) + abs(len(want) - len(got))
    if diff and cxx and not a.force:
        sys.exit(f"REFUSED: base.c compiles {a.function} differently from the C++ unit ({diff} instruction "
                 f"slots), so the permuter would chase the wrong code. Compare {d / 'base.c'} with the "
                 "source, or pass --force to run anyway.")
    if diff:
        print(f"WARNING: base.c compiles {a.function} differently from the real unit "
              f"({diff} instruction slots); scores are offset from the real build")
    kind = "gcc" if "SN_NGC_PATH" in env else "mwcc"
    objdump = (BINUTILS / f"powerpc-eabi-objdump{EXE}").as_posix()
    (d / "settings.toml").write_text(
        f'func_name = "{cname}"\ncompiler_type = "{kind}"\n'
        f"objdump_command = '\"{objdump}\" -dr --disassemble={a.function} -EB -mpowerpc -M broadway'\n",
        encoding="utf-8")
    return d


def setup_c(a, d, cc, cflags, env, v, pre):
    """C unit: base.c is the unit itself, trimmed; compile.sh runs the unit's compiler on it."""
    full = for_pycparser(pre, a.function)
    defs = definitions(full)
    if a.function not in defs:
        sys.exit(f"{a.function} has no body in the unit")
    # The permuter keeps only the target's body and `inline` ones. Helpers the compiler
    # inlined on its own (MWCC -inline auto, static functions) must stay inline, or the
    # target compiles to calls: find them from the full unit's code (called in the source,
    # but no `bl` to them), mark them inline; setup() then checks base.c compiles the same.
    (d / "full.c").write_text(full, encoding="utf-8")
    want, calls = compile_fn(cc, cflags, env, d / "full.c", d / "full.o", a.function)
    inline, todo = set(), [a.function]
    while todo:
        h, b, e = defs[todo.pop()]
        for name in called(full[b:e]) & defs.keys() - calls - inline - {a.function}:
            inline.add(name)
            todo.append(name)
    print(f"inlined helpers kept: {', '.join(sorted(inline)) or 'none'}")
    (d / "base.c").write_text(prune(full, a.function, inline), encoding="utf-8")
    # compile.sh runs under Git Bash: $1 = candidate .c, $3 = output .o.
    sn = f"export SN_NGC_PATH={shlex.quote(env['SN_NGC_PATH'])}\n" if "SN_NGC_PATH" in env else ""
    (d / "compile.sh").write_text(
        "#!/bin/bash\n"
        "# Written by tools/match/permute.py: the unit's compiler and cflags from build.ninja.\n"
        "export MSYS_NO_PATHCONV=1\n" + sn +
        f"cd {shlex.quote(ROOT.as_posix())}\n"
        f"exec {shlex.quote(Path(cc[0]).as_posix())} {v['cflags']} -c \"$1\" -o \"$3\"\n",
        encoding="utf-8", newline="\n")
    compile_fn(cc, cflags, env, d / "base.c", d / "base.o", a.function)
    return want


def setup_cxx(a, d, cc, cflags, env, pre, cname):
    """C++ unit: base.c is a C rendering of the function and what it uses, for the permuter
    to parse and mutate. compile.sh splices the candidate's body back into the original
    preprocessed unit (orig.cpp) and compiles that with g++, so codegen and symbol names
    are exactly the real build's."""
    if definition_body(pre, cname) is None:
        sys.exit(f"REFUSED: no plain `{cname}(...) {{` definition in the unit "
                 "(a method, or a g++ named return value `) return r`?)")
    (d / "orig.cpp").write_text(pre, encoding="utf-8")
    want, _ = compile_fn(cc, cflags, env, d / "orig.cpp", d / "orig.o", a.function)
    if not want:
        sys.exit(f"{a.function} is not in the unit's object")
    base = needed_only(for_pycparser(cxx_to_c(pre), cname), cname)
    if base is None:
        sys.exit(f"REFUSED: {cname}'s definition did not survive the C rewrite")
    base = parse_clean(base, cname, d)
    (d / "base.c").write_text(base, encoding="utf-8")
    (d / "splice.json").write_text(json.dumps({"cc": cc, "cflags": cflags, "env": {
        k: env[k] for k in ("SN_NGC_PATH",) if k in env}, "fn": cname}), encoding="utf-8")
    (d / "compile.sh").write_text(
        "#!/bin/bash\n"
        "# Written by tools/match/permute.py: splice the candidate's body into orig.cpp, compile with g++.\n"
        f"exec {shlex.quote(Path(sys.executable).as_posix())} {shlex.quote(Path(__file__).resolve().as_posix())} "
        f"--splice {shlex.quote(d.as_posix())} \"$1\" \"$3\"\n",
        encoding="utf-8", newline="\n")
    r = subprocess.run([str(Path(git_bash_dir(), "bash.exe")) if os.name == "nt" else "bash", str(d / "compile.sh"),
                        str(d / "base.c"), "-o", str(d / "base.o")], capture_output=True, text=True)
    if r.returncode:
        sys.exit(f"REFUSED: base.c's body does not compile inside the unit:\n{(r.stdout + r.stderr)[-1500:]}")
    print(f"base.c: {base.count(chr(10))} lines of C (the function and what it uses)")
    return want


def parse_clean(base, fn, d, tries=200):
    """Drop declarations the permuter's pycparser rejects, until base.c parses; never fn."""
    check = d / "parse_check.py"
    check.write_text(
        "import re, sys\n"
        f"sys.path.insert(0, {str(PERMUTER_DIR)!r})\n"
        "from src.ast_util import parse_c\n"
        "try:\n"
        "    parse_c(open(sys.argv[1], encoding='utf-8').read())\n"
        "    print('OK')\n"
        "except Exception as e:\n"
        "    m = re.search(r'line (\\d+)', str(e))\n"
        "    print('ERR', m.group(1) if m else 0, ' '.join(str(e).split())[:300])\n", encoding="utf-8")
    tmp = d / "parse_tmp.c"
    for _ in range(tries):
        tmp.write_text(base, encoding="utf-8")
        out = subprocess.run([str(PERMUTER_PY), str(check), str(tmp)], capture_output=True, text=True).stdout.strip()
        if out == "OK":
            return base
        _, line, msg = (out.split(" ", 2) + ["", ""])[:3]
        off = sum(len(x) + 1 for x in base.split("\n")[:max(0, int(line) - 1)])
        seg = next(((s, e) for s, e in segments(base) if s <= off < e), None)
        if seg is None or is_definition_of(base[seg[0]:seg[1]], fn):
            sys.exit(f"REFUSED: the permuter's C parser rejects {fn} itself: {msg}")
        base = base[:seg[0]] + base[seg[1]:]
    sys.exit("REFUSED: base.c still does not parse after dropping declarations")


def splice_compile(d, cand, out):
    """compile.sh for C++ units: candidate body -> orig.cpp -> g++ -> out."""
    d = Path(d)
    cfg = json.loads((d / "splice.json").read_text(encoding="utf-8"))
    orig = (d / "orig.cpp").read_text(encoding="utf-8")
    c = Path(cand).read_text(encoding="utf-8")
    ob, cb = definition_body(orig, cfg["fn"]), definition_body(c, cfg["fn"])
    if not ob or not cb:
        return 1
    cpp = Path(out + ".cpp")
    cpp.write_text(orig[:ob[0]] + c[cb[0]:cb[1]] + orig[ob[1]:], encoding="utf-8")
    try:
        r = subprocess.run([*cfg["cc"], *cfg["cflags"], "-c", str(cpp), "-o", out], cwd=ROOT,
                           env=dict(os.environ, **cfg["env"]))
    finally:
        cpp.unlink(missing_ok=True)
    return r.returncode


def run(d, a):
    env = dict(os.environ)
    # cpp (ProDG's CPP.exe), powerpc-eabi-objdump, and Git's bash ahead of WSL's
    env["PATH"] = os.pathsep.join([str(PRODG), str(BINUTILS), git_bash_dir() or "", env.get("PATH", "")])
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
    return (int(base.group(1)) if base else None), (outs[0] if outs else None)


def main():
    if sys.argv[1:2] == ["--splice"]:  # called by a C++ unit's compile.sh: DIR CAND.c -o OUT.o
        sys.exit(splice_compile(sys.argv[2], sys.argv[3], sys.argv[4]))
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("unit")
    ap.add_argument("function")
    ap.add_argument("--minutes", type=float, default=20)
    ap.add_argument("-j", "--jobs", type=int, default=4)
    ap.add_argument("--source", help="C file to start from instead of src/<unit>.c")
    ap.add_argument("--dir", help="scratch directory (default build/permute/<function>)")
    ap.add_argument("--setup-only", action="store_true", help="write the directory, don't run")
    ap.add_argument("--show-errors", action="store_true", help="pass --show-errors to the permuter")
    ap.add_argument("--force", action="store_true", help="run even if a C++ unit's C rewrite compiles differently")
    a = ap.parse_args()
    t = time.time()
    d = setup(a)
    print(f"set up {d} in {time.time() - t:.1f}s")
    if not a.setup_only:
        run(d, a)


if __name__ == "__main__":
    main()
