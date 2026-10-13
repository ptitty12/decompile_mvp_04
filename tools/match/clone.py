#!/usr/bin/env python3
"""Clone already-matched functions onto unmatched functions with an identical instruction shape.

    python tools/match/clone.py <unit> [--apply | --write] [--skip fn_X,fn_Y] [--busy FILE ...] [--free FILE ...]
    python tools/match/clone.py --scan [--busy FILE ...]      # candidate counts per unit
      <unit>   e.g. game/tu_80360168, fe/tu_804B7C98 (.cpp optional)
      --apply  insert, build, diff_unit + check_literals, drop clones that fail (about 1.5 min/unit)
      --write  insert the pre-checked clones only (batch use; verify afterwards yourself)
      --busy   files listing units owned by other workers (re-read every run; refused if the unit is in them)
      --free   files whose units are allowed even if --busy lists them
      CLONE_DEBUG=<ADDR> prints the scratch source and compiler errors for that target function.

About 1,100 unmatched functions have an "exact masked-asm twin" that is already matched:
the same instructions once labels are normalised and every fn_/lbl_/gap_ symbol is
replaced by a placeholder. Their C++ is the twin's C++ with the symbols swapped.

What it does, per unmatched function of the unit (no definition in the .cpp yet):
  1. Finds matched twins anywhere (game, animation, fe, db, ealib units): shapes come from
     build/GV4E69/asm, matched/unmatched from build/GV4E69/report.json (fuzzy == 100).
  2. Takes the twin's definition text from its .cpp (free functions named fn_<ADDR>).
  3. Maps symbols position by position (twin's symbol at instruction i -> target's) and
     rewrites every fn_/lbl_/gap_ name in the text simultaneously (the function's own name too).
     Float and string literals the twin writes inline are replaced by the values the target
     reads from its own pool (read from build/GV4E69/main.dol).
  4. Finds the declarations the clone needs: identifiers (types, inline helpers, prototypes,
     extern data) that the target unit cannot see but the twin's unit can. Types and inlines
     come from the twin's header (#include is added) or are copied from its .cpp; prototypes and
     externs are copied with the renamed symbol, extern "C" when the target's asm symbol is not mangled.
  5. Compiles the unit text up to the new function with the unit's own cflags and compares the
     new function against dtk's target object (relocation names included, via symbols.txt names).
     Candidate twins are tried in order (same unit, same directory, nearest address), at most --tries.
  Without --apply that is all: it prints each candidate and its verdict.
  With --apply the accepted clones are inserted in .text address order, then
     ninja <unit>.o ; rename.py <unit> --write ; ninja ; diff_unit ; check_literals
  and any clone that is not MATCH with 0 literal mismatches is removed again (the unit is
  restored from git and the run repeated without it).  Nothing is committed or pushed.

Limits (skipped, reported as "skip:<reason>"):
  - target or twin that is a method / ctor / dtor / virtual slot / static / inline / template;
  - twins whose source depends on macros, or on a local static table;
  - a literal the twin builds by an expression (not a plain float or string literal);
  - symbol maps that are inconsistent or non-injective in a way the compile cannot resolve;
  - anything that does not compile: the unit's own types are never altered.
C++ clones use extern "C"; explicitly C units use plain C declarations (the name stays
fn_<ADDR>, so rename.py has nothing to
mangle and callers in other units keep linking).  Everything it adds is plain C++ the repo's
rules allow; the verifier and check_literals decide, not this tool.
"""
import argparse
import json
import os
import re
import shlex
import struct
import subprocess
import sys
import tempfile
from collections import defaultdict
from pathlib import Path

from score_variants import compiler_command, c_source_text, ninja_vars

ROOT = Path(__file__).resolve().parents[2]
VER = "GV4E69"
BUILD = ROOT / "build" / VER
EXE = ".exe" if os.name == "nt" else ""
OVERLAY = {"fe": "FE_OVERLAY", "db": "DB_OVERLAY"}

SYM_RE = re.compile(r"\b(?:fn|lbl)_[0-9A-F]{8}\w*|\bgap_\d+_[0-9A-F]{8}_\w+")
BASE_RE = re.compile(r"(fn_[0-9A-F]{8}|lbl_[0-9A-F]{8}|gap_\d+_[0-9A-F]{8}_[a-z0-9]+)")
HDR_RE = re.compile(r"^# \.\w+:0x[0-9A-F]+ \| 0x([0-9A-F]{8}) \| size: 0x([0-9A-F]+)")
NAME_ADDR = re.compile(r"\bfn_([0-9A-F]{8})\w*\s*\(")


def base(sym):
    m = BASE_RE.match(sym)
    return m.group(1) if m else sym


# ---------------------------------------------------------------- inventory

class Fn:
    __slots__ = ("unit", "addr", "name", "raw", "ops", "syms", "matched")

    def __init__(self, unit, addr, name, raw):
        self.unit, self.addr, self.name, self.raw = unit, addr, name, raw
        self.ops, self.syms = [], []
        for i in raw:
            i = re.sub(r"\.L_[0-9A-F]+", "L", i)
            self.syms.append(SYM_RE.findall(i))
            self.ops.append(SYM_RE.sub("S", i))
        self.matched = False

    @property
    def shape(self):
        return tuple(self.ops)


class Inventory:
    def __init__(self):
        rep = json.loads((BUILD / "report.json").read_text())
        self.src_path = {}
        status = {}
        for u in rep["units"]:
            self.src_path[u["name"]] = u.get("metadata", {}).get("source_path")
            for f in u.get("functions", []):
                status[(u["name"], f["name"])] = f.get("fuzzy_match_percent", 0) == 100.0
        self.units = {}
        for path in (BUILD / "asm").rglob("*.s"):
            if path.name.startswith("auto_"):
                continue
            rel = path.relative_to(BUILD / "asm").as_posix()[:-2]
            unit = "main/" + rel
            fs, cur, addr = [], None, None
            for line in path.read_text(errors="replace").splitlines():
                m = HDR_RE.match(line)
                if m:
                    addr = int(m.group(1), 16)
                elif line.startswith(".fn "):
                    cur, body, cura = line.split()[1].rstrip(","), [], addr
                elif line.startswith(".endfn"):
                    if cur:
                        f = Fn(unit, cura, cur, body)
                        f.matched = status.get((unit, cur), False)
                        fs.append(f)
                    cur = None
                elif cur is not None:
                    m = re.match(r"/\*.*?\*/\s*(.*)$", line.strip())
                    if m:
                        body.append(m.group(1))
            self.units[unit] = fs
        self.by_shape = defaultdict(list)
        for fs in self.units.values():
            for f in fs:
                if len(f.ops) >= 4:
                    self.by_shape[f.shape].append(f)


# ---------------------------------------------------------------- DOL data

class Dol:
    def __init__(self):
        d = self.d = (BUILD / "main.dol").read_bytes()
        self.off = struct.unpack_from(">18I", d, 0)
        self.addr = struct.unpack_from(">18I", d, 0x48)
        self.size = struct.unpack_from(">18I", d, 0x90)

    def read(self, a, n):
        for o, ad, sz in zip(self.off, self.addr, self.size):
            if sz and ad <= a < ad + sz and o:
                return self.d[o + a - ad:o + a - ad + n]
        return None

    def cstr(self, a):
        b = self.read(a, 256)
        if not b:
            return None
        e = b.find(b"\0")
        if e <= 0:
            return None
        t = b[:e]
        return t if all(32 <= c < 127 or c in (9, 10, 13) for c in t) else None

    def is_pool(self, a):
        """Read-only literal pools: .rodata and .sdata2."""
        return any(lo <= a < hi for lo, hi in POOLS)


POOLS = []


def init_pools():
    dol = Dol()
    for p in (BUILD / "asm").glob("auto_*_*.s"):
        m = re.match(r"auto_\d+_([0-9A-F]{8})_(rodata|sdata2)\.s$", p.name)
        if m:
            lo = int(m.group(1), 16)
            for ad, sz in zip(dol.addr, dol.size):
                if ad == lo:
                    POOLS.append((lo, lo + sz))
    return dol


# ---------------------------------------------------------------- C++ text scanning

def blank(src):
    """src with comments and string/char contents replaced by spaces (same offsets)."""
    out = list(src)
    i, n = 0, len(src)
    while i < n:
        c = src[i]
        if c == "/" and src.startswith("//", i):
            j = src.find("\n", i)
            j = n if j < 0 else j
            for k in range(i, j):
                out[k] = " "
            i = j
        elif c == "/" and src.startswith("/*", i):
            j = src.find("*/", i + 2)
            j = n if j < 0 else j + 2
            for k in range(i, j):
                if out[k] != "\n":
                    out[k] = " "
            i = j
        elif c in "\"'":
            j = i + 1
            while j < n and src[j] != c and src[j] != "\n":
                j += 2 if src[j] == "\\" else 1
            for k in range(i + 1, min(j, n)):
                if out[k] != "\n":
                    out[k] = " "
            i = j + 1
        else:
            i += 1
    return "".join(out)


class Chunk:
    __slots__ = ("path", "s", "e", "kind", "names", "text", "inline", "static", "head", "tmpl", "extc")

    def __repr__(self):
        return f"<{self.kind} {sorted(self.names)} {Path(self.path).name}:{self.s}>"


AGG_START = re.compile(r"(typedef|struct|class|union|enum|namespace)\b")
QUAL = re.compile(r"^(?:(?:extern(?:\s*\"\s*\w*\s*\")?|static|inline|FE_OVERLAY|DB_OVERLAY|const|volatile)\s+)*")
IDENT = re.compile(r"[A-Za-z_]\w*")
EXTC = re.compile(r'extern\s*"[^"]*"\s*\{')
KEYWORDS = set("""auto break case char class const continue default do double else enum extern float for goto if inline int
long register return short signed sizeof static struct switch typedef union unsigned void volatile while
bool true false new delete this operator public private protected virtual template typename namespace using
asm friend explicit catch throw try mutable""".split())


def split_text(path, src):
    """Top-level chunks of C++ text: function defs/protos, types, data, preprocessor lines."""
    bl = blank(src)
    n = len(src)
    res = []
    i = 0
    ext_c = 0
    while i < n:
        while i < n and bl[i].isspace():
            i += 1
        if i >= n:
            break
        if bl[i] == "#" and (bl[:i].rstrip(" \t").endswith("\n") or bl[:i].strip() == ""):
            j = i
            while True:
                k = src.find("\n", j)
                k = n if k < 0 else k
                if k > 0 and src[k - 1] == "\\" and k < n:
                    j = k + 1
                    continue
                break
            c = Chunk()
            c.path, c.s, c.e, c.kind, c.text = path, i, k, "pp", src[i:k]
            c.names, c.inline, c.static, c.head, c.tmpl, c.extc = set(), False, False, "", False, False
            m = re.match(r"#\s*define\s+(\w+)", c.text)
            if m:
                c.kind = "macro"
                c.names = {m.group(1)}
            res.append(c)
            i = k
            continue
        m = EXTC.match(bl, i)
        if m:
            ext_c += 1
            i = m.end()
            continue
        if bl[i] == "}" and ext_c:
            ext_c -= 1
            i += 1
            if i < n and bl[i] == ";":
                i += 1
            continue
        s = i
        depth = pd = 0
        first_brace = None
        end = None
        while i < n:
            ch = bl[i]
            if ch == "(":
                pd += 1
            elif ch == ")":
                pd -= 1
            elif ch == "{":
                if depth == 0:
                    first_brace = i
                depth += 1
            elif ch == "}":
                depth -= 1
                if depth == 0:
                    h = re.sub(r"^\s*template\s*<[^>]*>\s*", "", bl[s:first_brace])
                    hq = QUAL.sub("", h.strip())
                    if "(" in h and not AGG_START.match(hq) and "=" not in h.split("(")[0]:
                        end = i + 1
                        i += 1
                        break
            elif ch == ";" and depth == 0 and pd <= 0:
                end = i + 1
                i += 1
                break
            i += 1
        if end is None:
            break
        c = Chunk()
        c.path, c.s, c.e, c.text, c.extc = path, s, end, src[s:end], ext_c > 0
        analyze(c, bl[s:end], (first_brace - s) if first_brace is not None and first_brace < end else None)
        res.append(c)
    return res


_CHUNKS = {}


def split_chunks(path):
    key = str(path)
    if key not in _CHUNKS:
        _CHUNKS[key] = split_text(path, Path(path).read_text(encoding="utf-8", errors="replace"))
    return _CHUNKS[key]


def analyze(c, b, fb):
    """Fill kind/names/head for one chunk from its blanked text (fb: offset of the first '{')."""
    c.names, c.head = set(), b
    pre = b[:fb] if fb is not None else b
    pre0 = pre.split("(")[0]
    c.inline = bool(re.search(r"\binline\b", pre0))
    c.static = bool(re.search(r"\bstatic\b", pre0))
    c.tmpl = bool(re.match(r"\s*template\b", b))
    hd = re.sub(r"^\s*template\s*<[^>]*>\s*", "", pre)
    hs = QUAL.sub("", hd.strip())
    if hs.startswith("typedef"):
        c.kind = "type"
        stripped = b
        while True:
            t2 = re.sub(r"\{[^{}]*\}", " ", stripped)
            if t2 == stripped:
                break
            stripped = t2
        mm = re.search(r"\(\s*\*\s*(\w+)\s*\)", stripped)
        if mm:
            c.names.add(mm.group(1))
        else:
            ids = IDENT.findall(re.sub(r"\[[^\]]*\]", " ", stripped.rstrip().rstrip(";")))
            if ids:
                c.names.add(ids[-1])
        sm = re.match(r"typedef\s+(?:struct|class|union|enum)\s+(\w+)", hs)
        if sm:
            c.names.add(sm.group(1))
        return
    am = AGG_START.match(hs)
    if am and "(" not in hd:
        c.kind = "type"
        nm = re.match(r"(?:struct|class|union|enum|namespace)\s+(\w+)", hs)
        if nm:
            c.names.add(nm.group(1))
        if am.group(1) == "enum" and "{" in b:
            inner = b[b.index("{") + 1:b.rindex("}")]
            for part in inner.split(","):
                mm = IDENT.match(part.strip())
                if mm:
                    c.names.add(mm.group(0))
        return
    if "(" in hd.split("=")[0]:
        c.kind = "fdef" if fb is not None else "func"
        m = re.search(r"((?:[\w~]+::)*(?:operator\s*[^\s(]+|~?\w+))\s*\(", hs)
        if m:
            c.names.add(m.group(1))
        return
    c.kind = "var"
    d = re.sub(r"=.*", "", hs, flags=re.S)
    d = re.sub(r"\[[^\]]*\]", " ", d).rstrip().rstrip(";")
    for part in d.split(","):
        ids = IDENT.findall(part)
        if ids:
            c.names.add(ids[-1])


class Ctx:
    """Everything visible in one translation unit: its own chunks and those of its includes."""

    def __init__(self, path, src=None):
        self.files = []
        self.chunks = []
        self.defs = {}   # name -> chunk
        self.root = path
        self._walk(path, set(), src)

    @staticmethod
    def _resolve(cur, inc):
        for d in (ROOT / "include", Path(cur).parent, ROOT / "src"):
            p = d / inc
            if p.is_file():
                return p
        return None

    def _walk(self, path, seen, src=None):
        if str(path) in seen:
            return
        seen.add(str(path))
        self.files.append(path)
        chunks = split_text(path, src) if src is not None else split_chunks(path)
        for c in chunks:
            if c.kind == "pp":
                m = re.match(r'#\s*include\s+"([^"]+)"', c.text)
                if m:
                    p = self._resolve(path, m.group(1))
                    if p:
                        self._walk(p, seen)
                continue
            self.chunks.append(c)
            for nm in c.names:
                prev = self.defs.get(nm)
                if prev is None or (prev.kind in ("func", "var") and c.kind in ("fdef", "type")):
                    self.defs[nm] = c

    def has(self, name):
        return name in self.defs


# ---------------------------------------------------------------- literal helpers

def f32_text(v):
    if v != v or v in (float("inf"), float("-inf")):
        return None
    for p in range(1, 10):
        s = "%.*g" % (p, v)
        if struct.unpack(">f", struct.pack(">f", float(s)))[0] == v:
            break
    if "e" not in s and "." not in s and "n" not in s:
        s += ".0"
    return s + "f"


def f64_text(v):
    if v != v or v in (float("inf"), float("-inf")):
        return None
    for p in range(1, 18):
        s = "%.*g" % (p, v)
        if float(s) == v:
            break
    if "e" not in s and "." not in s:
        s += ".0"
    return s


def c_escape(b):
    out = []
    for c in b:
        if c == 0x5C:
            out.append("\\\\")
        elif c == 0x22:
            out.append('\\"')
        elif c == 10:
            out.append("\\n")
        elif c == 9:
            out.append("\\t")
        elif c == 13:
            out.append("\\r")
        elif 32 <= c < 127:
            out.append(chr(c))
        else:
            out.append("\\%03o" % c)
    return "".join(out)


def c_unescape(s):
    out = bytearray()
    i = 0
    while i < len(s):
        ch = s[i]
        if ch != "\\":
            out.append(ord(ch))
            i += 1
            continue
        i += 1
        e = s[i]
        if e in "ntr\\\"'":
            out.append({"n": 10, "t": 9, "r": 13, "\\": 92, '"': 34, "'": 39}[e])
            i += 1
        elif e in "01234567":
            j = i
            while j < len(s) and j < i + 3 and s[j] in "01234567":
                j += 1
            out.append(int(s[i:j], 8) & 255)
            i = j
        elif e == "x":
            j = i + 1
            while j < len(s) and s[j] in "0123456789abcdefABCDEF":
                j += 1
            out.append(int(s[i + 1:j], 16) & 255)
            i = j
        else:
            return None
    return bytes(out)


TOK = re.compile(r"""//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|'(?:\\.|[^'\\\n])*'|0[xX][0-9A-Fa-f]+[uUlL]*|"""
                 r"""(?:\d+\.\d*|\.\d+)(?:[eE][+-]?\d+)?[fFlL]?|\d+[eE][+-]?\d+[fFlL]?|\d+[fF]\b|[A-Za-z_]\w*|\d+[uUlL]*""", re.S)


def tokens(text):
    for m in TOK.finditer(text):
        yield m


# ---------------------------------------------------------------- the cloner

def unit_key(arg):
    a = arg.replace("\\", "/")
    a = re.sub(r"^(src/|main/)", "", a)
    return re.sub(r"\.(cpp|c)$", "", a)


def tu_name(u):
    m = re.search(r"tu_[0-9A-Fa-f]{8}", u)
    return m.group(0) if m else u


def busy_set(files):
    out = set()
    for f in files:
        try:
            for line in Path(f).read_text().split():
                out.add(tu_name(line.split(":")[0]))
        except OSError:
            pass
    return out


HEAD_FREE = re.compile(r'^(?P<pre>(?:(?:extern\s*"[^"]*"|FE_OVERLAY|DB_OVERLAY)\s+)*)(?P<ret>[^()]*?)\b(?P<name>fn_[0-9A-F]{8})\s*\(')


def def_chunk(path, addr_hex, text=None):
    """The fdef chunk for fn_<addr_hex> in path (text overrides the file), or None."""
    chunks = split_text(path, text) if text is not None else split_chunks(path)
    for c in chunks:
        if c.kind == "fdef":
            m = NAME_ADDR.search(c.head.split("{")[0])
            if m and m.group(1) == addr_hex:
                return c
    return None


def free_def_ok(c):
    """A plain free function definition (not a method/inline/static/template)."""
    if c.inline or c.static or c.tmpl:
        return False
    head = c.head.split("{")[0].strip()
    m = HEAD_FREE.match(head)
    return bool(m) and "::" not in m.group("ret") and "operator" not in head


class Fail(Exception):
    pass


class Cloner:
    def __init__(self, inv, dol, tries=3, verbose=False):
        self.inv, self.dol, self.tries, self.v = inv, dol, tries, verbose
        self.objdump = ROOT / "build" / "binutils" / f"powerpc-eabi-objdump{EXE}"
        self._tcache = {}
        self._vars = {}

    # ---- compiling
    def cflags(self, rel):
        if rel not in self._vars:
            self._vars[rel] = ninja_vars(rel, root=ROOT)
        return self._vars[rel]

    def compile(self, rel, text):
        variables = self.cflags(rel)
        try:
            prefix, env = compiler_command(variables, root=ROOT)
        except FileNotFoundError as exc:
            return None, str(exc)
        directory = tempfile.mkdtemp(prefix="clone_")
        src, obj = os.path.join(directory, "u.cpp"), os.path.join(directory, "u.o")
        Path(src).write_text(text, encoding="utf-8")
        result = subprocess.run([*prefix, *shlex.split(variables["cflags"]), "-c", src, "-o", obj],
                                cwd=ROOT, env=env, capture_output=True, text=True)
        if result.returncode:
            return None, (result.stdout + result.stderr).strip()
        return obj, ""

    def objfuncs(self, obj):
        out = subprocess.run([str(self.objdump), "-d", "-r", str(obj)], capture_output=True, text=True).stdout
        res, cur = {}, None
        for line in out.splitlines():
            m = re.match(r"^[0-9a-f]+ <(.+)>:$", line)
            if m:
                cur = m.group(1)
                res[cur] = []
                continue
            if cur is None:
                continue
            m = re.match(r"^\s+[0-9a-f]+:\s+((?:[0-9a-f]{2} ){4})\s*(.*)$", line)
            if m:
                res[cur].append([int(m.group(1).replace(" ", ""), 16), m.group(2).strip(), ""])
                continue
            m = re.match(r"^\s+[0-9a-f]+: (R_PPC_\w+)\s+(\S+)", line)
            if m and res[cur]:
                res[cur][-1][2] = m.group(2)
        return res

    def target_func(self, rel, addr_hex):
        if rel not in self._tcache:
            self._tcache[rel] = self.objfuncs(BUILD / "obj" / f"{rel}.o")
        for n, ins in self._tcache[rel].items():
            if re.match(rf"fn_{addr_hex}(__|$)", n):
                return ins
        return None

    @staticmethod
    def mask(w, reloc):
        op = w >> 26
        if op == 16:
            return w & 0xFFFF0003
        if op == 18:
            return w & 0xFC000003
        if reloc:
            return w & 0xFFE00000 if op in (14, 15) else w & 0xFFFF0000
        return w

    def compare(self, ours, theirs, self_base):
        """None if equal; else a short reason."""
        if len(ours) != len(theirs):
            return f"length {len(ours)} vs {len(theirs)}"
        for k, (a, b) in enumerate(zip(ours, theirs)):
            if self.mask(a[0], a[2]) != self.mask(b[0], b[2]):
                return f"insn {k}: {a[1]} | {b[1]}"
            if a[2] and b[2]:
                sa, sb = re.sub(r"\+0x[0-9a-f]+$", "", a[2]), re.sub(r"\+0x[0-9a-f]+$", "", b[2])
                if sa.startswith(("fn_", "lbl_", "gap_")) and sb.startswith(("fn_", "lbl_", "gap_")):
                    if sa != sb and not (base(sa) == base(sb) == self_base):
                        return f"reloc {k}: {sa} vs {sb}"
        return None

    # ---- twins and maps
    def twins(self, tg):
        cands = [f for f in self.inv.by_shape[tg.shape] if f.matched and f is not tg]

        def key(f):
            return (f.unit != tg.unit, f.unit.split("/")[1] != tg.unit.split("/")[1], abs(f.addr - tg.addr))
        return sorted(cands, key=key)

    @staticmethod
    def symmap(tw, tg):
        mp = {}
        for a, b in zip(tw.syms, tg.syms):
            if len(a) != len(b):
                return None
            for x, y in zip(a, b):
                bx, by = base(x), base(y)
                if mp.setdefault(bx, by) != by:
                    return None
        return mp

    @staticmethod
    def asm_symbol(tg, b):
        for lst in tg.syms:
            for s in lst:
                if base(s) == b:
                    return s
        return b

    def literal_edits(self, tw, mp, text):
        """{old token -> new token} for float/string literals the twin writes inline."""
        kinds = defaultdict(set)
        for raw, syms in zip(tw.raw, tw.syms):
            mn = raw.split()[0] if raw.split() else ""
            for s in syms:
                if mn in ("lfs", "lfsx"):
                    kinds[base(s)].add("f32")
                elif mn in ("lfd", "lfdx"):
                    kinds[base(s)].add("f64")
                elif mn in ("addi", "la"):
                    kinds[base(s)].add("str")
        toks = list(tokens(text))
        edits = {}
        for a, ks in kinds.items():
            b = mp.get(a)
            if b is None or a == b or not (a.startswith("lbl_") and b.startswith("lbl_")):
                continue
            aa, ba = int(a[4:], 16), int(b[4:], 16)
            if not (self.dol.is_pool(aa) and self.dol.is_pool(ba)):
                continue
            if re.search(r"\b" + a + r"\b", text):
                continue   # used by name: the symbol rename covers it
            for k in ks:
                if k in ("f32", "f64"):
                    n, fmt = (4, ">f") if k == "f32" else (8, ">d")
                    ab, bb = self.dol.read(aa, n), self.dol.read(ba, n)
                    if ab is None or bb is None:
                        raise Fail("literal pool unreadable")
                    if ab == bb:
                        continue
                    av, bv = struct.unpack(fmt, ab)[0], struct.unpack(fmt, bb)[0]
                    found = {}
                    for m in toks:
                        t = m.group(0)
                        if not (t[0].isdigit() or t[0] == "."):
                            continue
                        if t[:2].lower() == "0x" or not ("." in t or "e" in t.lower() or t[-1] in "fF"):
                            continue
                        if k == "f32" and t[-1] in "lL":
                            continue
                        try:
                            tv = float(t.rstrip("fFlL"))
                        except ValueError:
                            continue
                        if k == "f32":
                            tv = struct.unpack(">f", struct.pack(">f", tv))[0]
                        if tv == av:
                            found[t] = 1
                        elif av != 0 and tv == -av:
                            found[t] = -1
                    if len(found) != 1:
                        raise Fail(f"float {av} of {a} not found as one literal")
                    t, sgn = next(iter(found.items()))
                    s = (f32_text if k == "f32" else f64_text)(bv * sgn)
                    if s is None:
                        raise Fail("float not representable")
                    if k == "f32" and t[-1] not in "fF":
                        s = s[:-1]
                    if k == "f64" and t[-1] in "fF":
                        raise Fail("float literal type")
                    if s.startswith("-"):
                        s = "(" + s + ")"
                    if edits.get(t, s) != s:
                        raise Fail("conflicting literal edits")
                    edits[t] = s
                else:
                    sa, sb = self.dol.cstr(aa), self.dol.cstr(ba)
                    if sa is None:
                        continue   # not a string: a table (left to the compile + literal checks)
                    if sb is None:
                        raise Fail("target pool entry is not a string")
                    if sa == sb:
                        continue
                    hit = None
                    for m in toks:
                        t = m.group(0)
                        if t[0] == '"' and c_unescape(t[1:-1]) == sa:
                            hit = t
                            break
                    if hit is None:
                        raise Fail(f"string {sa!r} of {a} not found as a literal")
                    edits[hit] = '"' + c_escape(sb) + '"'
        return edits

    def clone_text(self, tw, tg, mp, chunk, overlay):
        text = re.sub(r"\b(?:FE_OVERLAY|DB_OVERLAY)\b[ \t]*", "", chunk.text)
        if re.search(r"\bstatic\b", blank(text)):
            raise Fail("twin has a function-local static")
        ed = self.literal_edits(tw, mp, text)
        names = {k: v for k, v in mp.items() if k != v}
        names[f"fn_{tw.addr:08X}"] = f"fn_{tg.addr:08X}"
        text = replace_tokens(text, names, ed)
        head, sep, rest = text.partition("{")
        head = re.sub(r'^\s*extern\s*"[^"]*"\s*', "", head)
        return 'extern "C" ' + (overlay + " " if overlay else "") + head.lstrip() + sep + rest, names

    # ---- declarations the clone needs
    def collect_decls(self, clone, own, names, tg, tw_ctx, tgt_ctx, use_includes, prefer_global=False):
        inv = {}
        for k, v in names.items():
            inv.setdefault(v, k)
        out, includes, seen = [], [], set()
        hdr_cache = {}

        def visible_names_of_header(p):
            if str(p) not in hdr_cache:
                hdr_cache[str(p)] = set(Ctx(p).defs)
            return hdr_cache[str(p)]

        def visit(text):
            bl = blank(text)
            for m in IDENT.finditer(bl):
                name, s = m.group(0), m.start()
                if name in KEYWORDS or name in seen or name == own or name in OVERLAY.values():
                    continue
                if bl[max(0, s - 2):s] == "->" or bl[s - 1:s] == ".":
                    continue
                seen.add(name)
                if tgt_ctx.has(name):
                    continue
                tn = inv.get(name, name)
                c = tw_ctx.defs.get(tn)
                if c is None:
                    continue
                resolve(name, tn, c)

        def resolve(name, tn, c):
            if c.kind == "macro":
                text = replace_tokens(c.text, names, {})
                visit(text)
                out.append(text)
                return
            if c.kind in ("fdef", "func") and not c.inline:
                src_c, src_name, from_global = c, tn, False
                if prefer_global and name.startswith("fn_"):
                    g = global_funcs().get(name)
                    if g:
                        src_c, src_name, from_global = g[0], name, True
                if src_c.tmpl or "::" in "".join(src_c.names):
                    raise Fail(f"{tn} is not a plain function")
                if src_c.kind == "fdef":
                    proto = src_c.text[:src_c.head.index("{")].rstrip() + ";"
                else:
                    proto = src_c.text
                proto = re.sub(r'\bextern\s*"[^"]*"\s*', "", proto)
                proto = re.sub(r"\b(?:FE_OVERLAY|DB_OVERLAY)\b\s*", "", proto).strip()
                if not from_global:
                    proto = replace_tokens(proto, names, {})
                    if src_name != name:
                        proto = replace_tokens(proto, {src_name: name}, {})
                mangled = "__" in self.asm_symbol(tg, name)[11:] if name.startswith("fn_") else False
                visit(proto)
                out.append(("" if mangled else 'extern "C" ') + proto)
                return
            hdr = str(c.path).replace("\\", "/")
            if use_includes and hdr.endswith(".h") and hdr.startswith(str(ROOT / "include").replace("\\", "/")) and tn == name \
                    and not re.search(r"\blbl_|\bfn_", c.text):
                inc = Path(c.path).relative_to(ROOT / "include").as_posix()
                if inc not in includes:
                    includes.append(inc)
                seen.update(visible_names_of_header(c.path))
                return
            text = replace_tokens(c.text, names, {})
            if tn != name:
                text = replace_tokens(text, {tn: name}, {})
            if len(out) > 60:
                raise Fail("too many declarations to copy")
            visit(text)
            out.append(text)
            if c.kind == "type":
                # A class declaration can name inline methods whose bodies are
                # separate chunks in the donor .cpp. Without those bodies the
                # scratch clone compiles out-of-line calls instead of inlining.
                for member in tw_ctx.chunks:
                    if member.kind != "fdef" or not member.inline or member.tmpl:
                        continue
                    qualified = [n for n in member.names if n.startswith(tn + "::")]
                    if not qualified or any(n in seen or tgt_ctx.has(n) for n in qualified):
                        continue
                    seen.update(qualified)
                    body = replace_tokens(member.text, names, {})
                    if tn != name:
                        body = replace_tokens(body, {tn: name}, {})
                    visit(body)
                    out.append(body)

        visit(clone)
        return out, includes

    # ---- composing and trying
    @staticmethod
    def positions(text, tg_addr, path):
        """(include_pos, insert_pos) in text for a function at tg_addr."""
        chunks = split_text(path, text)
        inc_pos = None
        for c in chunks:
            if c.kind == "pp" and re.match(r"#\s*include\b", c.text):
                inc_pos = c.e
        defs = []
        for c in chunks:
            if c.kind == "fdef":
                m = NAME_ADDR.search(c.head.split("{")[0])
                if m:
                    defs.append((int(m.group(1), 16), c))
        before = [c for a, c in defs if a < tg_addr]
        after = [c for a, c in defs if a > tg_addr]
        if before:
            ins = before[-1].e
        elif after:
            ins = after[0].s
        else:
            ins = len(text)
        if inc_pos is None:
            inc_pos = -1   # no #include yet: put them in front of the first chunk
        return inc_pos, ins

    @staticmethod
    def compose(text, inc_pos, ins_pos, includes, decls, clone):
        """New text with includes, declarations and clone added; also where the clone ends."""
        block = "\n\n".join(decls + [clone])
        inc = "\n".join(f'#include "{i}"' for i in includes)
        if inc_pos == -1:
            chunks = split_text(Path("x"), text)
            first = chunks[0].s if chunks else len(text)
            inc_pos = min(first, ins_pos)
            head_part = text[:inc_pos] + (inc + "\n\n" if inc else "")
        else:
            head_part = text[:inc_pos] + ("\n" + inc if inc else "")
        if inc_pos > ins_pos:
            ins_pos = inc_pos
        mid = text[inc_pos:ins_pos]
        post = text[ins_pos:]
        pre = head_part + mid
        if not post.strip():
            new_pre = pre.rstrip("\n") + "\n\n" + block + "\n"
            return new_pre + post.lstrip("\n"), len(new_pre)
        if pre.rstrip().endswith("}") or not pre.strip():
            new_pre = pre.rstrip("\n") + ("\n\n" if pre.strip() else "") + block + "\n"
            return new_pre + post, len(new_pre)
        new_pre = pre.rstrip("\n") + "\n\n" + block + "\n\n"
        return new_pre + post, len(new_pre)

    def attempt(self, tgt, text, tg, tw):
        """(new_text, None) on success, (None, reason) otherwise."""
        mp = self.symmap(tw, tg)
        if mp is None:
            return None, "inconsistent symbol map"
        tpath = self.inv.src_path.get(tw.unit)
        if not tpath:
            return None, "twin has no source"
        tp = ROOT / tpath
        chunk = def_chunk(tp, f"{tw.addr:08X}")
        if chunk is None:
            return None, "twin definition not found"
        if not free_def_ok(chunk):
            return None, "twin is not a plain free function"
        try:
            clone, names = self.clone_text(tw, tg, mp, chunk, tgt.overlay)
            tw_ctx = Ctx(tp)
            tgt_ctx = Ctx(tgt.path, text)
        except Fail as e:
            return None, f"skip: {e}"
        own = f"fn_{tg.addr:08X}"
        first_err = None
        tried_sigs = set()
        theirs = self.target_func(tgt.rel, f"{tg.addr:08X}")
        for use_includes, prefer_global in [(False, False), (False, True), (True, False), (True, True)]:
            try:
                decls, includes = self.collect_decls(clone, own, names, tg, tw_ctx, tgt_ctx, use_includes, prefer_global)
            except Fail as e:
                first_err = first_err or f"skip: {e}"
                continue
            if tgt.overlay and not tgt_ctx.has(tgt.overlay) and "game/overlay.h" not in includes:
                includes.append("game/overlay.h")
            sig = (tuple(decls), tuple(includes))
            if sig in tried_sigs:
                continue
            tried_sigs.add(sig)
            inc_pos, ins_pos = self.positions(text, tg.addr, tgt.path)
            new_text, upto = self.compose(text, inc_pos, ins_pos, includes, decls, clone)
            new_text = c_source_text(new_text, self.cflags(tgt.rel)["cflags"])
            obj, err = self.compile(tgt.rel, new_text)
            if obj is None and os.environ.get("CLONE_DEBUG") == f"{tg.addr:08X}":
                print("----- scratch tail -----\n" + new_text[:upto][-2500:] + "\n----- error -----\n" + err[:1500])
            if obj is None:
                lines = [l for l in err.splitlines() if "error" in l.lower() or "parse" in l.lower()]
                msg = (lines[0] if lines else err[:200]).strip()
                first_err = first_err or "compile: " + re.sub(r"^.*?u\.cpp:", "L", msg)[:160]
                continue
            ours = None
            for n, ins in self.objfuncs(obj).items():
                if re.match(rf"fn_{tg.addr:08X}(__|$)", n):
                    ours = ins
            if ours is None or theirs is None:
                first_err = first_err or "function missing after compile"
                continue
            why = self.compare(ours, theirs, f"fn_{tg.addr:08X}")
            if why is None:
                return new_text, None
            first_err = first_err or "differs: " + why
        return None, first_err

    def run_unit(self, tgt, skip=()):
        """Clone as many functions of the unit as possible. Returns (text, accepted, notes)."""
        text = tgt.text()
        accepted, notes = [], []
        unit_fns = self.inv.units.get(tgt.unit, [])
        for tg in sorted(unit_fns, key=lambda f: f.addr):
            if tg.matched or len(tg.ops) < 4 or tg.addr in skip:
                continue
            tw_list = self.twins(tg)
            if not tw_list:
                continue
            if def_chunk(tgt.path, f"{tg.addr:08X}", text) is not None:
                notes.append((tg, "already has a definition"))
                continue
            tried, seen_text, ok = 0, set(), False
            reasons = []
            for tw in tw_list:
                if tried >= self.tries:
                    break
                tpath = self.inv.src_path.get(tw.unit)
                ch = def_chunk(ROOT / tpath, f"{tw.addr:08X}") if tpath else None
                key = ch.text if ch else None
                if key in seen_text:
                    continue
                seen_text.add(key)
                tried += 1
                new_text, why = self.attempt(tgt, text, tg, tw)
                if new_text:
                    text = new_text
                    accepted.append((tg, tw))
                    ok = True
                    break
                reasons.append(f"{tu_name(tw.unit)}:{tw.name[:11]} {why}")
            if not ok:
                notes.append((tg, " | ".join(reasons) or "no usable twin source"))
        return text, accepted, notes


_GLOBAL = None


def global_funcs():
    """{fn_<ADDR>: [func/fdef chunks]} over every header and source in the repo."""
    global _GLOBAL
    if _GLOBAL is None:
        _GLOBAL = defaultdict(list)
        for d in ("include", "src"):
            for p in sorted((ROOT / d).rglob("*")):
                if p.suffix in (".h", ".hpp", ".cpp"):
                    for c in split_chunks(p):
                        if c.kind in ("func", "fdef") and not c.inline and not c.tmpl:
                            for nm in c.names:
                                if nm.startswith("fn_"):
                                    _GLOBAL[nm].append(c)
    return _GLOBAL


def replace_tokens(text, names, edits):
    """Simultaneous whole-token replacement of identifiers (names) and literal tokens (edits)."""
    pieces, last = [], 0
    for m in tokens(text):
        t = m.group(0)
        new = names.get(t)
        if new is None:
            new = edits.get(t)
        if new is not None:
            pieces.append(text[last:m.start()])
            pieces.append(new)
            last = m.end()
    pieces.append(text[last:])
    return "".join(pieces)


# ---------------------------------------------------------------- build / verify steps

def sh(cmd, check=False):
    r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    if check and r.returncode:
        raise SystemExit(f"command failed: {' '.join(map(str, cmd))}\n{(r.stdout + r.stderr)[-2000:]}")
    return r


def apply_unit(cl, tgt, skip=()):
    """Write the clones, build, diff and literal-check; drop clones that do not hold up.

    Returns the list of (target Fn, twin Fn) that are kept (file left written)."""
    rel = tgt.rel
    sym_path = ROOT / "config" / VER / "symbols.txt"
    orig_text, orig_sym = tgt.path.read_bytes(), sym_path.read_bytes()
    skip = set(skip)
    for _round in range(4):
        text, accepted, _notes = cl.run_unit(tgt, skip)
        if not accepted:
            tgt.path.write_bytes(orig_text)
            return []
        tgt.write(text)
        r = sh(["ninja", f"build/{VER}/src/{rel}.o"])
        if r.returncode:
            print("  whole-unit compile failed; dropping the last clone and retrying")
            skip.add(accepted[-1][0].addr)
            tgt.path.write_bytes(orig_text)
            sym_path.write_bytes(orig_sym)
            continue
        r = sh([sys.executable, "tools/scout/rename.py", rel + ".cpp", "--write"])
        sh(["ninja"])
        d = sh([sys.executable, "tools/match/diff_unit.py", rel])
        status = {}
        for line in d.stdout.splitlines():
            m = re.match(r"(MATCH|DIFF|MISSING)\s+(\S+)", line)
            if m:
                status[m.group(2)] = m.group(1)
        lit = sh([sys.executable, "tools/match/check_literals.py", rel])
        bad = {}
        for line in lit.stdout.splitlines():
            m = re.match(rf"{re.escape(rel)} (\S+) \+0x", line)
            if m:
                bad[m.group(1)] = line
        failed = [tg for tg, _ in accepted
                  if status.get(f"fn_{tg.addr:08X}") != "MATCH" or f"fn_{tg.addr:08X}" in bad]
        for tg in failed:
            n = f"fn_{tg.addr:08X}"
            print(f"  DROP {n}: {status.get(n)} {bad.get(n, '')}")
        if not failed:
            return accepted
        skip.update(tg.addr for tg in failed)
        tgt.path.write_bytes(orig_text)
        sym_path.write_bytes(orig_sym)
        sh(["ninja"])
    tgt.path.write_bytes(orig_text)
    sym_path.write_bytes(orig_sym)
    return []


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0],
                                 formatter_class=argparse.RawDescriptionHelpFormatter, epilog=__doc__)
    ap.add_argument("unit", nargs="?", help="e.g. game/tu_80360168")
    ap.add_argument("--apply", action="store_true", help="write the accepted clones and verify them")
    ap.add_argument("--busy", action="append", default=[], help="file listing units to refuse (re-read each run)")
    ap.add_argument("--free", action="append", default=[], help="file listing units that are allowed despite --busy")
    ap.add_argument("--tries", type=int, default=3, help="twins to try per function")
    ap.add_argument("--write", action="store_true",
                    help="write the pre-checked clones into the .cpp without building (batch use: run "
                         "ninja, diff_unit, check_literals and verify yourself afterwards)")
    ap.add_argument("--skip", default="", help="comma-separated fn_<ADDR> to leave alone (e.g. ones that failed a later check)")
    ap.add_argument("--scan", action="store_true", help="count clone candidates per unit and exit")
    ap.add_argument("-v", "--verbose", action="store_true")
    a = ap.parse_args()

    inv = Inventory()
    dol = init_pools()
    busy = busy_set(a.busy) - busy_set(a.free)
    if a.scan:
        rows = []
        for u, fs in inv.units.items():
            n = sum(1 for f in fs if not f.matched and len(f.ops) >= 4 and any(g.matched for g in inv.by_shape[f.shape]))
            if n and inv.src_path.get(u):
                rows.append((n, u[5:], tu_name(u) in busy))
        for n, u, b in sorted(rows, reverse=True):
            print(f"{n:4} {u}{'  (busy)' if b else ''}")
        return
    if not a.unit:
        ap.error("unit required")
    rel = unit_key(a.unit)
    if tu_name(rel) in busy:
        sys.exit(f"{rel} is listed as busy; not touching it")
    tgt = Target(inv, rel)
    if not tgt.path or not tgt.path.is_file():
        sys.exit(f"no source for {rel}")
    cl = Cloner(inv, dol, a.tries, a.verbose)
    skip = {int(x.replace("fn_", ""), 16) for x in a.skip.split(",") if x}
    if a.apply:
        kept = apply_unit(cl, tgt, skip)
        for tg, tw in kept:
            print(f"KEPT  fn_{tg.addr:08X} <- {tw.unit[5:]} fn_{tw.addr:08X}")
        print(f"{rel}: {len(kept)} clone(s) kept")
        return
    text, accepted, notes = cl.run_unit(tgt, skip)
    for tg, tw in accepted:
        print(f"OK    fn_{tg.addr:08X} <- {tw.unit[5:]} fn_{tw.addr:08X}")
    for tg, why in notes:
        print(f"skip  fn_{tg.addr:08X}: {why[:240]}")
    if a.write and accepted:
        tgt.text()   # detects CRLF
        tgt.write(text)
        print(f"wrote {tgt.path.relative_to(ROOT)} (not built or verified)")
    print(f"{rel}: {len(accepted)} clone(s) pass the pre-check, {len(notes)} skipped")


class Target:
    """One unit being worked on."""

    def __init__(self, inv, rel):
        self.rel = rel
        self.unit = "main/" + rel
        sp = inv.src_path.get(self.unit)
        self.path = ROOT / sp if sp else None
        self.overlay = OVERLAY.get(rel.split("/")[0])

    def text(self):
        raw = self.path.read_bytes()
        self.crlf = b"\r\n" in raw
        return raw.decode("utf-8").replace("\r\n", "\n")

    def write(self, text):
        if getattr(self, "crlf", False):
            text = text.replace("\n", "\r\n")
        self.path.write_bytes(text.encode("utf-8"))


if __name__ == "__main__":
    main()
