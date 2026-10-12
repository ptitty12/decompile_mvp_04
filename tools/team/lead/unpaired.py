"""Find target functions that a compiled unit already reproduces but objdiff
doesn't pair (the compiled symbol has another name, e.g. a mangled ctor that
rename.py skipped because the old fn_ name is still referenced elsewhere).

usage: unpaired.py REPO [unit-substring ...]
Prints: unit  target_name  <-  compiled_name  (n insns)
"""
import json, struct, sys
from pathlib import Path

repo = Path(sys.argv[1])
filters = sys.argv[2:]
CODE = (".text", ".feoverlay", ".dboverlay")


def load(path):
    data = path.read_bytes()
    shoff, = struct.unpack_from(">I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from(">HHH", data, 0x2E)
    secs = [struct.unpack_from(">IIIIIIIIII", data, shoff + i * shentsize) for i in range(shnum)]
    cstr = lambda off: data[off:data.index(b"\0", off)].decode("latin-1")
    names = [cstr(secs[shstrndx][4] + s[0]) for s in secs]
    relocs = {}  # section index -> set of offsets
    for s in secs:
        if s[1] == 4:  # RELA
            tgt = s[7]
            offs = relocs.setdefault(tgt, set())
            for i in range(s[5] // 12):
                off, = struct.unpack_from(">I", data, s[4] + i * 12)
                offs.add(off & ~3)
    funcs = {}
    for s in secs:
        if s[1] != 2:
            continue
        strtab = secs[s[6]]
        for i in range(s[5] // 16):
            st_name, value, size, info, _, shndx = struct.unpack_from(">IIIBBH", data, s[4] + i * 16)
            if info & 0xF != 2 or not (0 < shndx < len(names)) or names[shndx] not in CODE or size == 0:
                continue
            sec = secs[shndx]
            body = data[sec[4] + value: sec[4] + value + size]
            r = relocs.get(shndx, set())
            words = []
            for k in range(0, size - size % 4, 4):
                w, = struct.unpack_from(">I", body, k)
                op = w >> 26
                if op == 16:
                    w &= 0xFFFF0003
                elif op == 18:
                    w &= 0xFC000003
                elif (value + k) in r:
                    w &= 0xFFE00000 if op in (14, 15) else 0xFFFF0000
                words.append(w)
            funcs[cstr(strtab[4] + st_name)] = tuple(words)
    return funcs


rep = json.loads((repo / "build/GV4E69/report.json").read_text())
total = 0
for u in rep["units"]:
    name = u["name"].removeprefix("main/")
    if "auto_" in name or (filters and not any(f in name for f in filters)):
        continue
    bad = [f["name"] for f in u.get("functions", []) if f.get("fuzzy_match_percent", 0) < 100]
    if not bad:
        continue
    base = None
    for ext in (".cpp", ".c", ".cp"):
        p = repo / "build/GV4E69/src" / (name + ".o")
        if p.is_file():
            base = p
            break
    tgt = repo / "build/GV4E69/obj" / (name + ".o")
    if base is None or not tgt.is_file():
        continue
    try:
        b, t = load(base), load(tgt)
    except Exception as e:
        print(f"# {name}: {e}")
        continue
    by_words = {}
    for n, w in b.items():
        by_words.setdefault(w, []).append(n)
    for n in bad:
        w = t.get(n)
        if not w or len(w) < 2:
            continue
        cands = [c for c in by_words.get(w, []) if c != n]
        if cands:
            total += 1
            print(f"{name}\t{n}\t<-\t{','.join(cands)}\t({len(w)} insns)")
print(f"# {total} unpaired target functions already reproduced", file=sys.stderr)
