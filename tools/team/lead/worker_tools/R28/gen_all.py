import sys, re, os, glob, collections, subprocess

S = "C:/Users/PATRIC~1/AppData/Local/Temp/claude/C--Users-Patrick-Taylor-decompile-mvp-04/ddf206fc-e9e3-4b5f-93d0-98c4cc873084/scratchpad/R28"
sys.path.insert(0, S)
from shapes import funcs, units

EXT = set("""fn_80356798 fn_803567AC fn_8035682C fn_80356838 fn_8035686C fn_80356CE0 fn_803579D4 fn_80357A5C fn_80358484 fn_80359604 fn_803596DC fn_80359910 fn_80359948 fn_80359A40 fn_80359B78 fn_80359BAC fn_80359C58 fn_80359E94 fn_8035A09C fn_8035A304 fn_8035A324 fn_8035A344 fn_8035A5A4 fn_8035A618 fn_8035A900 fn_8035AB00 fn_8035ABB0 fn_8035B16C fn_8035B1C8 fn_8035B3BC fn_8035B53C""".split())

NL = chr(10)
NOTE = {
    "fn_80357B58": "/* fn_80357B58: not attempted (0x92C bytes, over the size limit); the original code stays linked */",
    "fn_80358898": "/* fn_80358898: not attempted (0x6BC bytes, over the size limit); the original code stays linked */",
    "fn_8035867C": NL.join(["/* fn_8035867C: not matched. UI node builder like fn_80358F84, but fn_8032DC2C takes three by-value 8-byte temporaries",
                            "   (built from lbl_805C5FAC / lbl_805C5FB0 and lbl_8060558C); the original code stays linked */"]),
    "fn_80359E94": NL.join(["/* fn_80359E94: not matched. Lazy singleton of the 0x334-byte thread object (same crclr memset issue as fn_80359C58,",
                            "   plus a dead lis/ori 0x19000); the original code stays linked */"]),
    "fn_80359F30": "/* fn_80359F30: not matched. Factory for the same object (see fn_80359E94); the original code stays linked */",
}
allf = {}
order = []
for u in units:
    for n, ins in funcs(u):
        allf[n] = (u, ins)
        order.append((u, n))


CALLED = set()
for _n, (_u, _ins) in allf.items():
    for _s in _ins:
        _m = re.search(r"(fn_[0-9A-F]{8})", _s)
        if _m:
            CALLED.add(_m.group(1))


def hexint(x):
    return int(x, 16) if x.startswith(("0x", "-0x")) else int(x)


H = {}
for f in glob.glob(S + "/hand/*.txt"):
    H[os.path.basename(f)[:-4]] = open(f).read()
for f in sorted(glob.glob(S + "/hand_*.txt")):
    cur = None
    buf = []
    for line in open(f).read().split(chr(10)):
        if line.startswith("@@ "):
            if cur:
                H[cur] = (H.get(cur, "") if cur == "types" else "") + chr(10).join(buf).strip(chr(10)) + chr(10)
            cur = line[3:].strip()
            buf = []
        elif cur is not None:
            buf.append(line)
    if cur:
        H[cur] = (H.get(cur, "") if cur == "types" else "") + chr(10).join(buf).strip(chr(10)) + chr(10)

try:
    ESIG = {}
    for l in open(S + "/esig.txt"):
        l = l.strip()
        if l and not l.startswith("#"):
            m = re.search(r"\b(fn_[0-9A-F]{8}\w*)\(", l)
            ESIG[m.group(1) if m else l] = l
except OSError:
    ESIG = {}

PRO = ["stwu r1, -0x8(r1)", "mflr r0", "stw r0, 0xc(r1)"]
EPI = ["lwz r0, 0xc(r1)", "mtlr r0", "addi r1, r1, 0x8", "blr"]


def shape(n, I):
    if len(I) == 8 and I[:3] == PRO and I[4:] == EPI and I[3].startswith("bl "):
        return ("fwd", I[3][3:])
    if len(I) == 14 and I[:3] == PRO and I[-4:] == EPI:
        a = re.match(r"lis r9, (lbl_\w+)@ha", I[3])
        if a and I[4] == "andi. r0, r4, 0x1" and I[5] == f"addi r9, r9, {a.group(1)}@l":
            d = re.match(r"stw r9, (\S+)\(r3\)", I[6])
            if d and I[7].startswith("beq") and I[8] == "bl fn_80377408" and I[9] == "LABEL":
                return ("dtordel", a.group(1), hexint(d.group(1)))
    if len(I) == 12 and I[:3] == PRO and I[-4:] == EPI:
        a = re.match(r"lis r9, (lbl_\w+)@ha", I[3])
        if a and I[4] == "mr r11, r3" and I[5] == f"addi r9, r9, {a.group(1)}@l":
            d = re.match(r"stw r9, (\S+)\(r11\)", I[6])
            if d and I[7].startswith("bl "):
                return ("dtorchain", a.group(1), hexint(d.group(1)), I[7][3:])
    if len(I) == 14 and I[:3] == PRO and I[-4:] == EPI:
        a = re.match(r"lis r9, (lbl_\w+)@ha", I[3])
        b = re.match(r"lis r11, (lbl_\w+)@ha", I[4])
        if a and b and I[5] == f"addi r9, r9, {a.group(1)}@l" and I[6] == f"addi r11, r11, {b.group(1)}@l":
            d = re.match(r"stw r9, (\S+)\(r3\)", I[7])
            e = re.match(r"stw r11, (\S+)\(r3\)", I[8])
            if d and e and I[9].startswith("bl "):
                return ("dtor2", a.group(1), hexint(d.group(1)), b.group(1), hexint(e.group(1)), I[9][3:])
    if len(I) == 5:
        a = re.match(r"lis r9, (lbl_\w+)@ha", I[0])
        if a and I[1] == "mr r11, r3" and I[2] == f"addi r9, r9, {a.group(1)}@l" and I[3] == "stw r9, 0x0(r11)" and I[4] == "blr":
            return ("ctor1", a.group(1))
    if len(I) == 15 and I[0] == "stwu r1, -0x10(r1)" and I[1] == "mflr r0" and I[2] == "stmw r30, 0x8(r1)" and I[3] == "stw r0, 0x14(r1)" and I[4] == "mr r30, r3" and I[5].startswith("bl "):
        a = re.match(r"lis r9, (lbl_\w+)@ha", I[6])
        if a and I[7] == "mr r3, r30" and I[8] == f"addi r9, r9, {a.group(1)}@l" and I[9] == "stw r9, 0x0(r30)":
            return ("ctorchain", a.group(1), I[5][3:])
    # getters / setters / small returns
    m = re.match(r"lwz r3, (\S+)\(r3\)$", I[0]) if len(I) == 2 else None
    if m and I[1] == "blr":
        return ("get", hexint(m.group(1)))
    m = re.match(r"stw r4, (\S+)\(r3\)$", I[0]) if len(I) == 2 else None
    if m and I[1] == "blr":
        return ("set", hexint(m.group(1)))
    m = re.match(r"li r3, (\S+)$", I[0]) if len(I) == 2 else None
    if m and I[1] == "blr":
        return ("ret", hexint(m.group(1)))
    m = re.match(r"addi r3, r3, (\S+)$", I[0]) if len(I) == 2 else None
    if m and I[1] == "blr":
        return ("lea", hexint(m.group(1)))
    # string select: lis r3,lbl ; mr r4,r5 ; addi r3,r3,lbl@l ; bl X
    if len(I) == 11 and I[:3] == PRO and I[-4:] == EPI:
        a = re.match(r"lis r3, (lbl_\w+)@ha", I[3])
        if a and I[4] == "mr r4, r5" and I[5] == f"addi r3, r3, {a.group(1)}@l" and I[6].startswith("bl "):
            return ("strsel", a.group(1), I[6][3:])
    # shift-forward: mr r3,r4 ; mr r4,r5 ; bl X
    if len(I) == 10 and I[:3] == PRO and I[-4:] == EPI and I[3] == "mr r3, r4" and I[4] == "mr r4, r5" and I[5].startswith("bl "):
        return ("shift2", I[5][3:])
    # virtual call on the second argument
    if len(I) == 15 and I[:3] == PRO and I[-4:] == EPI and I[3] == "mr r3, r4":
        a = re.match(r"lwz r9, (\S+)\(r3\)$", I[4])
        b = re.match(r"li r4, (\S+)$", I[5])
        c = re.match(r"lha r0, (\S+)\(r9\)$", I[6])
        d = re.match(r"lwz r9, (\S+)\(r9\)$", I[7])
        if a and b and c and d and I[8] == "add r3, r3, r0" and I[9] == "mtlr r9" and I[10] == "blrl":
            return ("vcall", hexint(a.group(1)), hexint(c.group(1)), hexint(b.group(1)))
    if I == ["blr"]:
        return ("void",)
    if I == ["li r3, 0x0", "blr"]:
        return ("ret", 0)
    if I == ["li r3, 0x1", "blr"]:
        return ("ret", 1)
    return None


kind = {}
for u, n in order:
    if n in H:
        kind[n] = ("hand",)
        continue
    s = shape(n, allf[n][1])
    kind[n] = s if s else ("todo",)

CALLEE_ALIAS = {"_._11Unk8037B3E8": "fn_8037B424"}


def cname(c):
    mm = re.match(r"(fn_[0-9A-F]{8})__F", c)
    if mm:
        c = mm.group(1)
    return CALLEE_ALIAS.get(c, c)


def linkage(n):
    return 'extern "C" ' if n in EXT else ""


def emit(n):
    k = kind[n]
    kd = k[0]
    L = linkage(n)
    if kd == "hand":
        if "::" in H[n].split(NL)[0].split("(")[0]:
            return H[n].rstrip(NL)
        return L + H[n].rstrip(NL)
    if kd == "fwd":
        return f"{L}void {n}(void* a, int b) {{ {cname(k[1])}(a, b); }}"
    if kd == "dtordel":
        return f"{L}void {n}(void* self, int c)\n{{\n    PUT({k[2]:#x}, {k[1]});\n    if (c & 1)\n        fn_80377408(self);\n}}"
    if kd == "dtorchain":
        return f"{L}void {n}(void* self, int c)\n{{\n    PUT({k[2]:#x}, {k[1]});\n    {cname(k[3])}(self, c);\n}}"
    if kd == "dtor2":
        return f"{L}void {n}(void* self, int c)" + NL + "{" + NL + f"    PUT({k[2]:#x}, {k[1]});" + NL + f"    PUT({k[4]:#x}, {k[3]});" + NL + f"    {cname(k[5])}(self, c);" + NL + "}"
    if kd == "get":
        return f"{L}int {n}(void* p) {{ return F(int, p, {k[1]:#x}); }}"
    if kd == "set":
        return f"{L}void {n}(void* p, int v) {{ F(int, p, {k[1]:#x}) = v; }}"
    if kd == "lea":
        return f"{L}char* {n}(char* p) {{ return p + {k[1]:#x}; }}"
    if kd == "strsel":
        return f"{L}void {n}(void* a, int b, int c) {{ {cname(k[2])}({k[1]}, c); }}"
    if kd == "shift2":
        return f"{L}void {n}(void* a, void* b, int c) {{ {cname(k[1])}(b, c); }}"
    if kd == "vcall":
        return f"{L}int {n}(void* a, VT{k[1]:X}* s) {{ return s->s{k[2] // 8}({k[3]:#x}); }}"
    if kd == "void":
        return f"{L}void {n}() {{}}"
    if kd == "ret":
        return f"{L}int {n}() {{ return {k[1]}; }}"
    if kd == "ctor1":
        return f"{L}void* {n}(void* self)" + NL + "{" + NL + f"    PUT(0, {k[1]});" + NL + "    return self;" + NL + "}"
    if kd == "ctorchain":
        return f"{L}void* {n}(void* self)" + NL + "{" + NL + f"    {k[2]}(self);" + NL + f"    PUT(0, {k[1]});" + NL + "    return self;" + NL + "}"
    return None


def proto(n):
    k = kind[n]
    kd = k[0]
    L = linkage(n)
    if kd == "hand":
        first = next((l for l in H[n].split(NL) if re.match(r"^[A-Za-z_]", l) and (n + "(") in l and not l.startswith(("struct", "class")) ), H[n].split(NL)[0]).split("{")[0].rstrip()
        if first.startswith("/*") or "(" not in first or "::" in first.split("(")[0]:
            return None
        if n not in CALLED and n not in EXT:
            return None
        return L + first + ";"
    if kd == "fwd" or kd in ("dtordel", "dtorchain", "dtor2"):
        return f"{L}void {n}(void*, int);"
    if kd == "get":
        return f"{L}int {n}(void*);"
    if kd == "set":
        return f"{L}void {n}(void*, int);"
    if kd == "lea":
        return f"{L}char* {n}(char*);"
    if kd == "strsel":
        return f"{L}void {n}(void*, int, int);"
    if kd == "shift2":
        return f"{L}void {n}(void*, void*, int);"
    if kd == "vcall":
        return f"{L}int {n}(void*, VT{k[1]:X}*);"
    if kd == "void":
        return f"{L}void {n}();"
    if kd == "ret":
        return f"{L}int {n}();"
    if kd in ("ctor1", "ctorchain"):
        return f"{L}void* {n}(void*);"
    return None


def class_decls():
    decls = []
    done = set()

    def decl(n):
        if n in done:
            return
        k = kind[n]
        cl = "Unk" + n[3:]
        if k[0] == "ctor1":
            decls.append(f"struct {cl} {{ const void* m0; {cl}(); }};")
        else:
            b = k[2]
            decl(b)
            decls.append(f"struct {cl} : Unk{b[3:]} {{ {cl}(); }};")
        done.add(n)

    for u, n in order:
        if kind[n][0] in ("ctor1", "ctorchain"):
            decl(n)
    return decls


def used_lbls():
    s = set()
    for u, n in order:
        for x in allf[n][1]:
            for m in re.finditer(r"\b(lbl_[0-9A-F]{8})\b", x):
                s.add(m.group(1))
    return sorted(s)


def header():
    out = []
    out.append("""#ifndef GAME_TU_80355A6C_H
#define GAME_TU_80355A6C_H

/*
 * Shared declarations for the game tail 0x80355A6C..0x8035B60C (range 28):
 * UI/menu object boilerplate (ctors that store a vtable, dtors with the
 * in-charge flag, forwarders to the base dtors). Vtables and the other data
 * are retail objects, extern by lbl_ name; classes here never define a virtual.
 */
#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))
#define F(T, p, o) (*(T*)((char*)(p) + (o)))
""")
    try:
        out.append(open(S + "/types.h").read())
    except OSError:
        pass

    skip = set()
    try:
        skip = set(open(S + "/noext.txt").read().split())
    except OSError:
        pass
    out.append("/* retail data objects */")
    for l in used_lbls():
        if l in skip:
            continue
        out.append(f"extern char {l}[];")
    out.append("")
    out.append("")
    out.append("/* callees outside this range */")
    for n, d in sorted(ESIG.items()):
        out.append(d)
    out.append("")
    if "types" in H:
        out.append(H["types"])
    out.append("/* functions of this range */")
    for u, n in order:
        p = proto(n)
        if p:
            out.append(p)
    out.append("\n#endif")
    return "\n".join(out) + "\n"


BANNER = {}
for u in units:
    r = subprocess.run(["git", "show", f"HEAD:src/game/tu_{u}.cpp"], capture_output=True, text=True)
    t = r.stdout
    BANNER[u] = t[: t.index("*/") + 2] + "\n"


def unit_src(u):
    out = [BANNER[u], '#include "game/tu_80355A6C.h"', ""]
    for uu, n in order:
        if uu != u:
            continue
        e = emit(n)
        if e is None:
            out.append(NOTE.get(n, f"/* {n}: not matched, the original code stays linked */"))
        else:
            out.append(e)
        out.append("")
    return "\n".join(out)


if __name__ == "__main__":
    cmd = sys.argv[1] if len(sys.argv) > 1 else "stat"
    if cmd == "stat":
        c = collections.Counter(k[0] for k in kind.values())
        print(c)
        for u, n in order:
            if kind[n][0] == "todo":
                print(n, u, len(allf[n][1]))
    elif cmd == "write":
        open("include/game/tu_80355A6C.h", "w", newline="\n").write(header())
        for u in units:
            open(f"src/game/tu_{u}.cpp", "w", newline="\n").write(unit_src(u))
        al = []
        for f in glob.glob(S + "/alias_*.txt"):
            al.extend(open(f).read().splitlines())
        open(S + "/alias.txt", "w").write(chr(10).join(al) + chr(10))
        print("written")
