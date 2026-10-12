"""Compile one source with ProDG or MWCC under several flag sets; compare every function to
the retail bytes (read from build/GV4E69/orig/mvp.elf by address).

usage: probe.py REPO SRC CC FLAGSET [FLAGSET ...] [--names FILE] [--show NAME]
  CC       prodg | GC/1.2.5n | GC/2.0 ...
  FLAGSET  one quoted string of flags per variant
  --names  extra symbols file (dtk symbols.txt format) mapping real names to addresses
           (default: the repo's config/GV4E69/symbols.txt; fn_XXXXXXXX names map themselves)
Relocated fields (from the compiled object's relocations) are masked on both sides; for
sda21 relocations the base-register field is masked too (the linker picks r13/r2).
Prints per variant: matched/total functions and the diff count of each function.
"""
import os
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

args = sys.argv[1:]
names_files, show = [], None
while "--names" in args:
    i = args.index("--names"); names_files.append(args[i + 1]); del args[i:i + 2]
if "--show" in args:
    i = args.index("--show"); show = args[i + 1]; del args[i:i + 2]
repo, src, cc, *flagsets = args
repo = Path(repo)
exe = ".exe"
objdump = repo / "build/binutils/powerpc-eabi-objdump.exe"
elf = (repo / "build/GV4E69/orig/mvp.elf").read_bytes()
shoff, = struct.unpack_from(">I", elf, 0x20)
shentsize, shnum, _ = struct.unpack_from(">HHH", elf, 0x2E)
secs = [struct.unpack_from(">IIIIIIIIII", elf, shoff + i * shentsize) for i in range(shnum)]


def word(a):
    for s in secs:
        if s[1] == 1 and s[3] <= a < s[3] + s[5] and (s[8] & 4 or s[2] & 4):
            return struct.unpack_from(">I", elf, s[4] + a - s[3])[0]
    raise KeyError(hex(a))


addr_of, size_at = {}, {}
for f in [str(repo / "config/GV4E69/symbols.txt")] + names_files:
    for m in re.finditer(r"^(\S+) = \.\w+:0x([0-9A-F]{8}); // type:function size:0x([0-9A-F]+)", open(f).read(), re.M):
        a = int(m.group(2), 16)
        addr_of.setdefault(m.group(1), a)
        size_at.setdefault(a, int(m.group(3), 16))


def compiled(obj):
    out = subprocess.run([str(objdump), "-d", "-r", obj], capture_output=True, text=True).stdout
    res, cur = {}, None
    for line in out.splitlines():
        m = re.match(r"^[0-9a-f]+ <(.+)>:$", line)
        if m:
            cur = m.group(1); res[cur] = []; continue
        if cur is None:
            continue
        m = re.match(r"^\s+[0-9a-f]+:\s+((?:[0-9a-f]{2} ){4})\s*(.*)$", line)
        if m:
            res[cur].append([int(m.group(1).replace(" ", ""), 16), m.group(2).strip(), ""]); continue
        m = re.match(r"^\s+[0-9a-f]+: (R_PPC_\w+)\s+(\S+)", line)
        if m and res[cur]:
            res[cur][-1][2] = m.group(1)
    return res


def mask(w, rel):
    op = w >> 26
    if rel in ("R_PPC_REL24",) or op == 18:
        return w & 0xFC000003
    if rel == "R_PPC_EMB_SDA21":
        return w & 0xFFE00000
    if rel:
        return w & 0xFFFF0000
    if op == 16:
        return w & 0xFFFF0003
    return w


def target_addr(name):
    m = re.match(r"fn_([0-9A-F]{8})", name)
    if m:
        return int(m.group(1), 16)
    return addr_of.get(name)


tmp = tempfile.mkdtemp(prefix="probe_")
for vi, fs in enumerate(flagsets):
    tag = " ".join(x for x in fs.split() if not x.startswith(("-I", "-i", "C:")) and x not in ("-isystem",))
    obj = os.path.join(tmp, "o.o")
    if os.path.exists(obj):
        os.remove(obj)
    if cc == "prodg":
        comp = repo / "build/compilers/ProDG/3.9.3"
        cmd = [str(comp / "ngccc.exe"), *fs.split(), "-c", os.path.abspath(src), "-o", obj]
        env = dict(os.environ, SN_NGC_PATH=str(comp))
    else:
        comp = repo / "build/compilers" / cc
        cmd = [str(comp / "mwcceppc.exe"), *fs.split(), "-c", os.path.abspath(src), "-o", obj]
        env = dict(os.environ)
    r = subprocess.run(cmd, cwd=repo, env=env, capture_output=True, text=True)
    if r.returncode or not os.path.exists(obj):
        print(f"[{tag}] COMPILE FAILED: {(r.stdout + r.stderr).strip()[-300:]}")
        continue
    funcs = compiled(obj)
    ok, tot, detail = 0, 0, []
    for name, ins in funcs.items():
        a = target_addr(name)
        if a is None:
            detail.append(f"{name}:?")
            continue
        tsize = size_at.get(a, len(ins) * 4)
        tw = [word(a + 4 * k) for k in range(tsize // 4)]
        n = max(len(tw), len(ins))
        diffs = [k for k in range(n) if k >= len(tw) or k >= len(ins) or mask(tw[k], ins[k][2]) != mask(ins[k][0], ins[k][2])]
        tot += 1
        if not diffs:
            ok += 1
        else:
            detail.append(f"{name}:{len(diffs)}/{len(tw)}")
        if show and show in name:
            for k in diffs[:40]:
                t = f"{tw[k]:08X}" if k < len(tw) else "-"
                b = ins[k][1] if k < len(ins) else "-"
                print(f"    {k:4} {t} | {b} {ins[k][2] if k < len(ins) else ''}")
    print(f"[{tag}] {ok}/{tot} match  " + " ".join(detail[:12]))
