#!/usr/bin/env python3
"""protolint: find fn_<addr> prototypes whose declared RETURN TYPE disagrees with the
original code.

A callee declared `void` that really returns a value (or the reverse) changes the
caller's argument setup order (sched2 sees a call_value vs a plain call), which is a
common cause of near-misses.  This tool classifies every function in the original code
(build/GV4E69/asm) by what it does with r3, then scans every declaration and definition
of an `fn_<addr>` name in src/ and include/ and lists the ones that disagree.

    python tools/match/protolint.py                    # report
    python tools/match/protolint.py --classes          # also dump the class of every function
    python tools/match/protolint.py --why fn_803FED48   # evidence for one function
    python tools/match/protolint.py --json out.json    # machine-readable findings
    python tools/match/protolint.py --apply [--tier T] [--path PREFIX] [--names a,b]
                                                       # rewrite the return types (see below)

Classification of a callee (r3 dataflow over the CFG of the original function):

  value   certain.  One of
            V1  some `blr` is reached by a definition of r3 that nothing reads (a dead
                store can only be the return value: `mr r3,rN; blr`, `li r3,K; blr`);
            V2  it ends in a tail call (`b fn`) to a function that returns a value;
            V3  some caller reads r3 right after `bl fn` (the result is consumed);
            V4  it is tail-called / returned through by a value function (reverse of V2).
  void    certain ("void").  Every exit leaves r3 untouched (or only a void callee's
          r3), r3 is not an incoming argument that could be handed back, and no caller
          reads the result.
  void?   weak ("void-weak").  Same, but r3 is read at entry, so the function might be
          `T* f(T* p) { ...; return p; }`.  Only flagged when no caller ever consumes
          the result.
  unknown everything else, including `return g();` through a normal call (identical
          code to `(void)g();`), indirect tail calls and switch tables.

The same dataflow runs on f1: a dead f1 definition at blr, a caller reading f1 after the
call, or a tail call to a float function marks a float result.  A void/int/pointer
declaration of such a function is flagged -> float; a float declaration of a function that
returns in r3 is flagged -> int.  Struct-by-value results (hidden pointer) are never judged.

`--apply` rewrites the type tokens in place (void -> int, value -> void, -> float).
Decisions are made on the original code only.  A wrapper's own definition and all headers
and externs that declare the name must change together (the tool edits every declaration
of a selected name; definitions of matched functions only with --defs).  Always follow with
`python tools/verify/verify.py --baseline-ref ...` and keep only batches that do not
regress, because some declarations are right for the callers even though the callee's code
says otherwise (struct returns through an out pointer, callbacks, pass-through of the first
argument).  Those are recorded in tools/match/protolint_skip.txt, which the tool honours.

Ambiguous callees (class unknown: `bl g; blr` is the same code for `return g();` and
`g();`) cannot be judged from the original code.  Toggling their declared type and
diffing the callers is the only test; run that as a separate experiment.
"""
import argparse
import collections
import glob
import json
import os
import re
import sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
ASM_DIR = os.path.join(ROOT, "build", "GV4E69", "asm")
REPORT = os.path.join(ROOT, "build", "GV4E69", "report.json")
SKIP_FILE = os.path.join(ROOT, "tools", "match", "protolint_skip.txt")

# --------------------------------------------------------------------------------------
# 1. original code: functions and instructions
# --------------------------------------------------------------------------------------
HDR = re.compile(r"^# \.[\w.]+:0x[0-9A-Fa-f]+ \| 0x([0-9A-Fa-f]{8}) \| size: 0x([0-9A-Fa-f]+)")
FNL = re.compile(r"^\.fn (\S+), \w+")
INS = re.compile(r"^/\* ([0-9A-F]{8}) [0-9A-F]{8}\s+(?:[0-9A-F]{2} ?)+\*/\t(\S+)(?:[ \t]+(.*?))?\s*$")
REG = re.compile(r"\br(\d+)\b")


class Fn:
    __slots__ = ("name", "addr", "ins", "labels", "info", "finfo")

    def __init__(self, name, addr):
        self.name = name
        self.addr = addr
        self.ins = []      # (mnemonic, operands)
        self.labels = {}   # label -> instruction index
        self.info = None
        self.finfo = None


def load_asm():
    """Return (funcs by address, name -> address)."""
    funcs = {}
    names = {}
    files = glob.glob(os.path.join(ASM_DIR, "**", "*.s"), recursive=True)
    for path in sorted(files, key=lambda p: (os.path.basename(p).startswith("auto_"), p)):
        cur = None
        addr = None
        pending = []
        with open(path, encoding="utf-8", errors="replace") as fh:
            for line in fh:
                if cur is None:
                    m = HDR.match(line)
                    if m:
                        addr = int(m.group(1), 16)
                        continue
                    m = FNL.match(line)
                    if m:
                        nm = m.group(1)
                        a = addr
                        cur = Fn(nm, a)
                        pending = []
                        names[nm] = a
                    continue
                if line.startswith(".endfn"):
                    if cur.addr is not None and cur.addr not in funcs:
                        for lab in pending:
                            cur.labels[lab] = len(cur.ins)
                        funcs[cur.addr] = cur
                    cur = None
                    addr = None
                    continue
                if line.startswith("/*"):
                    m = INS.match(line.rstrip("\n"))
                    if m:
                        for lab in pending:
                            cur.labels[lab] = len(cur.ins)
                        pending = []
                        ops = m.group(3) or ""
                        ops = ops.split("#")[0].strip()
                        cur.ins.append((m.group(2), ops))
                    continue
                s = line.strip()
                if s.endswith(":") and not s.startswith("#"):
                    pending.append(s[:-1])
    return funcs, names


# mnemonics that never write a GPR in their first operand
NODEST_PREFIX = ("st", "psq_st", "cmp", "mt", "tw", "dcb", "icb", "sync", "isync", "eieio", "cr",
                 "mcr", "lwsync", "fcmp", "ps_cmp")
NODEST_EXACT = {"sc", "rfi", "nop", "mttbl", "mttbu"}
UPDATE = {"lbzu", "lbzux", "lhzu", "lhzux", "lhau", "lhaux", "lwzu", "lwzux", "lfsu", "lfsux",
          "lfdu", "lfdux", "stbu", "stbux", "sthu", "sthux", "stwu", "stwux", "stfsu", "stfsux",
          "stfdu", "stfdux", "psq_lu", "psq_stu"}
RESERVED_ABI = ("_savegpr", "_restgpr", "_savefpr", "_restfpr")
COND = re.compile(r"^b(?:eq|ne|lt|gt|le|ge|ns|so|nl|ng|dnz|dz|dnzt|dnzf|dzt|dzf|c)(lr|ctr)?(l)?$")


def reg_effect(mn, ops):
    """(reads r3, writes r3) for a non-branch instruction."""
    base = mn.rstrip(".")
    regs = [int(x) for x in REG.findall(ops)]
    if not regs:
        return False, False
    if base in NODEST_EXACT or base.startswith(NODEST_PREFIX):
        w = False
        if base in UPDATE:
            m = re.search(r"\(r(\d+)\)", ops)
            b = int(m.group(1)) if m else (regs[1] if len(regs) > 1 else -1)
            w = b == 3
        return 3 in regs, w
    first = re.match(r"\s*r(\d+)\b", ops)
    if not first:
        # float load/store or condition-register op: GPRs are only read; update forms write base
        w = False
        if base in UPDATE:
            m = re.search(r"\(r(\d+)\)", ops)
            w = bool(m) and int(m.group(1)) == 3
        return 3 in regs, w
    d = int(first.group(1))
    if base == "lmw":
        return 3 in regs[1:], d <= 3
    reads = set(regs[1:])
    if base in ("rlwimi", "insrwi", "inslwi"):
        reads.add(d)
    w = d == 3
    if base in UPDATE:
        m = re.search(r"\(r(\d+)\)", ops)
        b = int(m.group(1)) if m else (regs[1] if len(regs) > 1 else -1)
        if b == 3:
            w = True
    return 3 in reads, w


FREG = re.compile(r"\bf(\d+)\b")
NODEST_F = ("stf", "psq_st", "fcmp", "mtfs", "ps_cmp")


def reg_effect_f1(mn, ops):
    """(reads f1, writes f1) for a non-branch instruction."""
    regs = [int(x) for x in FREG.findall(ops)]
    if 1 not in regs:
        return False, False
    base = mn.rstrip(".")
    if base.startswith(NODEST_F):
        return True, False
    first = re.match(r"\s*f(\d+)\b", ops)
    if not first:
        return True, False
    d = int(first.group(1))
    reads = set(regs[1:])
    return 1 in reads, d == 1


def callee_name(ops):
    t = ops.split(",")[-1].strip()
    t = re.split(r"[+\- ]", t, 1)[0]
    return t


def analyze(fn, effect=None, attr="info"):
    """Reaching definitions of r3 (or f1, with effect=reg_effect_f1, attr="finfo") over the CFG."""
    effect = effect or reg_effect
    ins = fn.ins
    n = len(ins)
    kind = [None] * n      # plain / b / cond / call / ret / condret / ind / indcall / tail
    tgt = [None] * n       # local target index
    ext = [None] * n       # external callee name
    rd = [False] * n
    wr = [False] * n
    switch = False
    for i, (mn, ops) in enumerate(ins):
        base = mn.rstrip("+-")
        if base == "blr":
            kind[i] = "ret"
        elif base == "blrl" or base == "bctrl":
            kind[i] = "indcall"
        elif base == "bctr":
            kind[i] = "ind"
            for j in range(max(0, i - 4), i):
                if ins[j][0] == "lwzx":
                    switch = True
        elif base in ("b", "ba"):
            name = callee_name(ops)
            if name in fn.labels:
                kind[i], tgt[i] = "b", fn.labels[name]
            elif name.startswith(RESERVED_ABI):
                kind[i] = "ret"
            else:
                kind[i], ext[i] = "tail", name
        elif base in ("bl", "bla"):
            name = callee_name(ops)
            if name in fn.labels:
                kind[i], tgt[i] = "call", None
                ext[i] = name
            elif name.startswith(RESERVED_ABI):
                kind[i] = "plain"
            else:
                kind[i], ext[i] = "call", name
        else:
            m = COND.match(base)
            if m:
                lr, ctr, link = m.group(1), None, m.group(2)
                if lr == "lr":
                    kind[i] = "condret" if not link else "plain"
                elif lr == "ctr":
                    kind[i] = "plain"
                    switch = True
                else:
                    name = callee_name(ops)
                    if link:
                        kind[i] = "plain"
                        switch = True
                    elif name in fn.labels:
                        kind[i], tgt[i] = "cond", fn.labels[name]
                    else:
                        # conditional tail call: treat as unanalysable
                        kind[i] = "plain"
                        switch = True
            else:
                kind[i] = "plain"
                rd[i], wr[i] = effect(mn, ops)
    info = {"switch": switch, "exits": [], "calls": [], "entry_exp": 0, "entry_imp": 0,
            "ndef": 0, "uses": {}}
    setattr(fn, attr, info)
    if switch or n == 0:
        return
    # basic blocks
    leader = {0}
    for i in range(n):
        k = kind[i]
        if k in ("b", "cond") and tgt[i] is not None and tgt[i] < n:
            leader.add(tgt[i])
        if k in ("b", "cond", "ret", "condret", "tail", "ind") and i + 1 < n:
            leader.add(i + 1)
    starts = sorted(leader)
    bidx = {s: b for b, s in enumerate(starts)}
    nb = len(starts)
    ends = [starts[b + 1] if b + 1 < nb else n for b in range(nb)]
    succ = [[] for _ in range(nb)]
    for b in range(nb):
        last = ends[b] - 1
        k = kind[last]
        if k in ("ret", "tail", "ind"):
            continue
        if k == "b":
            if tgt[last] is not None and tgt[last] < n:
                succ[b].append(bidx[tgt[last]])
            continue
        if k == "cond" and tgt[last] is not None and tgt[last] < n:
            succ[b].append(bidx[tgt[last]])
        if ends[b] < n:
            succ[b].append(bidx[ends[b]])
    # transfer: does the block define r3, and what is the last definition
    lastdef = [None] * nb
    for b in range(nb):
        for i in range(starts[b], ends[b]):
            if kind[i] in ("call", "indcall") or wr[i]:
                lastdef[b] = i + 1
    IN = [0] * nb
    OUT = [None] * nb
    IN[0] = 1  # bit 0 = ENTRY
    work = collections.deque(range(nb))
    inq = [True] * nb
    while work:
        b = work.popleft()
        inq[b] = False
        out = IN[b] if lastdef[b] is None else (1 << lastdef[b])
        if out == OUT[b]:
            continue
        OUT[b] = out
        for s in succ[b]:
            nin = IN[s] | out
            if nin != IN[s]:
                IN[s] = nin
                if not inq[s]:
                    inq[s] = True
                    work.append(s)
    # walk blocks, collecting uses and exits
    exp = collections.Counter()
    imp = collections.Counter()

    def bits(x):
        while x:
            low = x & -x
            yield low.bit_length() - 1
            x ^= low

    exits = []
    calls = []
    for b in range(nb):
        state = IN[b]
        if state == 0:
            continue  # unreachable
        for i in range(starts[b], ends[b]):
            k = kind[i]
            if k == "plain":
                if rd[i]:
                    for d in bits(state):
                        exp[d] += 1
                if wr[i]:
                    state = 1 << (i + 1)
            elif k in ("call", "indcall"):
                for d in bits(state):
                    imp[d] += 1
                state = 1 << (i + 1)
                calls.append((i + 1, ext[i] if k == "call" else None))
            elif k in ("ret", "condret"):
                exits.append(("ret", state))
            elif k in ("tail", "ind"):
                for d in bits(state):
                    imp[d] += 1
                exits.append(("tail", ext[i] if k == "tail" else None))
    info["exits"] = [(t, v) for t, v in exits]
    info["calls"] = calls
    info["exp"] = exp
    info["imp"] = imp
    info["entry_exp"] = exp.get(0, 0)
    info["entry_imp"] = imp.get(0, 0)
    info["callmap"] = dict(calls)


# --------------------------------------------------------------------------------------
# 2. classification
# --------------------------------------------------------------------------------------
class Classifier:
    def __init__(self, funcs, names, effect=None, attr="info", reg="r3"):
        self.reg = reg
        self.effect = effect
        self.attr = attr
        self.funcs = funcs
        self.names = names
        self.value = {}    # addr -> reason
        self.void = {}     # addr -> "strong" / "weak"
        self.result_used = collections.Counter()
        self.result_ignored = collections.Counter()
        self.callers = collections.defaultdict(set)   # callee addr -> caller addrs
        self.ret_through = collections.defaultdict(set)
        self.why = collections.defaultdict(list)

    def addr_of(self, name):
        if name is None:
            return None
        return self.names.get(name)

    def run(self):
        funcs = self.funcs
        for a, fn in funcs.items():
            analyze(fn, self.effect, self.attr)
        # per-call result usage, callers
        for a, fn in funcs.items():
            info = getattr(fn, self.attr)
            if info["switch"]:
                continue
            for d, nm in info["calls"]:
                t = self.addr_of(nm)
                if t is None:
                    continue
                self.callers[t].add(a)
                if info["exp"].get(d, 0) > 0:
                    self.result_used[t] += 1
                    self.why[t].append("V3 caller %s reads %s after the call" % (fn.name, self.reg))
                else:
                    self.result_ignored[t] += 1
            for nm in [e[1] for e in info["exits"] if e[0] == "tail"]:
                t = self.addr_of(nm)
                if t is not None:
                    self.callers[t].add(a)
        # V1 / V3 seeds
        for a, fn in funcs.items():
            info = getattr(fn, self.attr)
            if info["switch"]:
                continue
            for t, st in info["exits"]:
                if t != "ret":
                    continue
                for d in self._bits(st):
                    if d == 0:
                        continue
                    kindcall = d in info["callmap"]
                    if not kindcall and info["exp"].get(d, 0) == 0 and info["imp"].get(d, 0) == 0:
                        self.value.setdefault(a, "V1 dead %s definition reaches blr" % self.reg)
        for t, c in self.result_used.items():
            self.value.setdefault(t, "V3 result consumed by %d caller(s)" % c)
        # propagate V2 / V4 / V5 to a fixed point
        changed = True
        while changed:
            changed = False
            for a, fn in funcs.items():
                info = getattr(fn, self.attr)
                if info["switch"]:
                    continue
                isval = a in self.value
                for t, st in info["exits"]:
                    if t == "tail":
                        tt = self.addr_of(st)
                        if tt is None:
                            continue
                        if tt in self.value and a not in self.value:
                            self.value[a] = "V2 tail call to value function %s" % funcs[tt].name if tt in funcs else "V2 tail call"
                            changed = True
                        elif isval and tt not in self.value and tt in funcs:
                            self.value[tt] = "V4 tail-called by value function %s" % fn.name
                            changed = True
                    else:
                        ds = list(self._bits(st))
                        if len(ds) == 1 and ds[0] in info["callmap"] and a in self.value:
                            tt = self.addr_of(info["callmap"][ds[0]])
                            if tt is not None and tt not in self.value and tt in funcs:
                                self.value[tt] = "V5 result returned by value function %s" % fn.name
                                changed = True
        # void classification (strong / weak), memoised DFS over tail calls
        self._void_state = {}
        for a in funcs:
            self.void_of(a)

    @staticmethod
    def _bits(x):
        while x:
            low = x & -x
            yield low.bit_length() - 1
            x ^= low

    def void_of(self, a, stack=()):
        if a in self._void_state:
            return self._void_state[a]
        fn = self.funcs.get(a)
        if fn is None or a in stack:
            return None
        info = getattr(fn, self.attr)
        res = None
        if (not info["switch"] and a not in self.value and info["exits"]
                and self.result_used.get(a, 0) == 0):
            ok = True
            for t, st in info["exits"]:
                if t == "tail":
                    tt = self.addr_of(st)
                    r = self.void_of(tt, stack + (a,)) if tt is not None else None
                    if r is None:
                        ok = False
                        break
                    continue
                for d in self._bits(st):
                    if d == 0:
                        continue
                    if d in info["callmap"]:
                        tt = self.addr_of(info["callmap"][d])
                        r = self.void_of(tt, stack + (a,)) if tt is not None else None
                        if r != "strong":
                            ok = False
                            break
                    else:
                        ok = False  # an r3 write that is read again (scratch or value)
                        break
                if not ok:
                    break
            if ok:
                entry_live = (info["entry_exp"] + info["entry_imp"]) > 0
                res = "weak" if entry_live else "strong"
        self._void_state[a] = res
        if res:
            self.void[a] = res
        return res

    def cls(self, a):
        if a in self.value:
            return "value"
        r = self.void.get(a)
        if r == "strong":
            return "void"
        if r == "weak":
            return "void-weak"
        return "unknown"


# --------------------------------------------------------------------------------------
# 3. source scan
# --------------------------------------------------------------------------------------
NAME = re.compile(r"\bfn_(8[0-9A-Fa-f]{7})\b")
QUALS = {"extern", "static", "inline", "virtual", "FE_OVERLAY", "DB_OVERLAY", "explicit", "friend",
         '"C"', "__inline__", "__inline"}
INT_WORDS = {"int", "unsigned", "signed", "short", "char", "long", "bool", "BOOL", "s8", "s16", "s32",
             "u8", "u16", "u32", "s64", "u64", "size_t", "ptrdiff_t", "wchar_t", "const", "volatile",
             "uint", "uchar", "ushort", "ulong", "u_int", "u_char", "u_short", "u_long", "__int64"}
FLOAT_WORDS = {"float", "double", "f32", "f64"}
BAD_HEAD = {"return", "else", "new", "delete", "throw", "sizeof", "goto", "case", "typedef", "if", "while",
            "for", "switch", "do", "using", "operator", "namespace"}
TOK = re.compile(r'"[^"]*"|::|\.\.\.|->|[A-Za-z_]\w*|\d+|\S')


def strip_comments(text):
    out = []
    i = 0
    n = len(text)
    while i < n:
        c = text[i]
        if c == "/" and i + 1 < n and text[i + 1] == "/":
            j = text.find("\n", i)
            if j < 0:
                j = n
            out.append(" " * (j - i))
            i = j
        elif c == "/" and i + 1 < n and text[i + 1] == "*":
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append("".join("\n" if ch == "\n" else " " for ch in text[i:j]))
            i = j
        elif c == '"' or c == "'":
            j = i + 1
            while j < n and text[j] != c:
                if text[j] == "\\":
                    j += 1
                j += 1
            out.append(text[i:j + 1])
            i = j + 1
        else:
            out.append(c)
            i += 1
    return "".join(out)


def blank_preproc(text):
    lines = text.split("\n")
    cont = False
    for k, ln in enumerate(lines):
        if cont or ln.lstrip().startswith("#"):
            cont = ln.rstrip().endswith("\\")
            lines[k] = " " * len(ln)
    return "\n".join(lines)


def type_names(files):
    structs, scalars = set(), set()
    for p in files:
        t = blank_preproc(strip_comments(open(p, encoding="utf-8", errors="replace").read()))
        for m in re.finditer(r"\b(?:struct|class|union)\s+(\w+)\s*(?:[:{;]|$)", t):
            structs.add(m.group(1))
        for m in re.finditer(r"\benum\s+(\w+)", t):
            scalars.add(m.group(1))
        for m in re.finditer(r"\btypedef\s+([^;{}]*?)\s*\b(\w+)\s*;", t):
            body, nm = m.group(1), m.group(2)
            toks = TOK.findall(body)
            if any(x in INT_WORDS or x in scalars for x in toks) or "*" in toks:
                scalars.add(nm)
            elif any(x in FLOAT_WORDS for x in toks):
                scalars.add(nm)
                FLOAT_WORDS.add(nm)
    return structs, scalars


def classify_type(toks, structs, scalars):
    """-> 'void' | 'int' | 'ptr' | 'float' | 'struct' | 'other'"""
    if toks == ["void"]:
        return "void"
    if toks and toks[-1] in ("*", "&"):
        return "ptr"
    words = [t for t in toks if t not in ("const", "volatile", "struct", "class", "union", "enum", "::", "<", ">", ",")]
    if not words:
        return "other"
    if any(w in FLOAT_WORDS for w in words):
        return "float"
    if all(w in INT_WORDS or w in scalars for w in words):
        return "int"
    if any(w in structs for w in words):
        return "struct"
    return "other"


PARAM_OK = re.compile(r"^[\w\s*&,<>:\[\]().=+\-\"']*$")


def scan_file(path, rel, structs, scalars):
    raw = open(path, encoding="utf-8", errors="replace").read()
    text = blank_preproc(strip_comments(raw))
    line_starts = [0]
    for m in re.finditer("\n", text):
        line_starts.append(m.end())

    def lineno(pos):
        lo, hi = 0, len(line_starts) - 1
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if line_starts[mid] <= pos:
                lo = mid
            else:
                hi = mid - 1
        return lo + 1

    res = []
    for m in NAME.finditer(text):
        j = m.end()
        while j < len(text) and text[j] in " \t\r\n":
            j += 1
        if j >= len(text) or text[j] != "(":
            continue
        # head: back to previous ; { } or a single ':'
        k = m.start() - 1
        while k >= 0:
            c = text[k]
            if c in ";{}":
                break
            if c == ":" and not (k > 0 and text[k - 1] == ":") and not (k + 1 < len(text) and text[k + 1] == ":"):
                break
            k -= 1
        head_start = k + 1
        head = text[head_start:m.start()]
        if len(head) > 300:
            continue
        toks = TOK.findall(head)
        if not toks:
            continue
        if any(t in BAD_HEAD for t in toks):
            continue
        if any(not (re.match(r"[A-Za-z_]\w*$", t) or t in ("::", "*", "&", "<", ">", ",") or t.startswith('"')) for t in toks):
            continue
        # strip trailing  Class::  qualifiers
        e = len(toks)
        qual_member = False
        while e >= 2 and toks[e - 1] == "::" and re.match(r"[A-Za-z_]\w*$", toks[e - 2]):
            e -= 2
            qual_member = True
            if e >= 1 and toks[e - 1] == "::":
                e -= 1
        # nested  A<T>::  not handled -> head would hold < >, fine for ptr types
        toks = toks[:e]
        # drop leading qualifiers
        t2 = [t for t in toks if t not in QUALS]
        if not t2:
            continue
        # closing paren
        depth = 0
        p = j
        while p < len(text):
            if text[p] == "(":
                depth += 1
            elif text[p] == ")":
                depth -= 1
                if depth == 0:
                    break
            p += 1
        if p >= len(text):
            continue
        params = text[j + 1:p]
        if not PARAM_OK.match(params):
            continue
        q = p + 1
        while q < len(text) and text[q] in " \t\r\n":
            q += 1
        follow = text[q:q + 8]
        if follow.startswith(";"):
            what = "decl"
        elif follow.startswith("{") or follow.startswith("const") or follow.startswith(":") and not follow.startswith("::"):
            what = "def"
        else:
            continue
        # locate the type tokens in the original text for rewriting: first type token .. last
        res.append({
            "name": "fn_" + m.group(1).upper(),
            "addr": int(m.group(1), 16),
            "file": rel,
            "line": lineno(m.start()),
            "what": what,
            "member": qual_member,
            "type": " ".join(t2),
            "tk": classify_type(t2, structs, scalars),
            "head_start": head_start,
            "name_pos": m.start(),
        })
    return res


# --------------------------------------------------------------------------------------
# 4. matched status from report.json
# --------------------------------------------------------------------------------------
def load_matched(names):
    """addr -> True if the function is at 100% in the current build, plus unit/source."""
    status = {}
    srcof = {}
    if not os.path.exists(REPORT):
        return status, srcof
    rep = json.load(open(REPORT))
    for u in rep["units"]:
        sp = (u.get("metadata") or {}).get("source_path") or u["name"]
        for f in u.get("functions", []):
            a = names.get(f["name"])
            if a is None:
                m = re.match(r"fn_(8[0-9A-Fa-f]{7})", f["name"])
                if m:
                    a = int(m.group(1), 16)
            if a is not None:
                status[a] = f.get("fuzzy_match_percent", 0.0) >= 100.0
                srcof[a] = sp
    return status, srcof


# --------------------------------------------------------------------------------------
# main
# --------------------------------------------------------------------------------------
def source_files():
    out = []
    for d in ("src", "include"):
        for p in glob.glob(os.path.join(ROOT, d, "**", "*"), recursive=True):
            if os.path.isfile(p) and p.endswith((".cpp", ".h", ".hpp", ".c", ".inc", ".inl")):
                out.append(p)
    return sorted(out)


def verdict(decl_tk, cls, fcls="unknown"):
    """Return (wanted, tier) or None when the declaration agrees / cannot be judged.
    cls is the r3 class, fcls the f1 (float result) class."""
    if decl_tk in ("void", "int", "ptr") and fcls == "value" and cls != "value":
        return "float", "certain"
    if decl_tk == "float" and cls == "value" and fcls != "value":
        return "int", "certain"
    if fcls == "value":
        return None
    if decl_tk == "void":
        if cls == "value":
            return "value", "certain"
        return None
    if decl_tk in ("int", "ptr"):
        if cls == "void":
            return "void", "certain"
        # A pointer result may be the incoming `this` handed back untouched (matched
        # definitions confirm: 71 of them), so only plain integers get the weak tier.
        if cls == "void-weak" and decl_tk == "int":
            return "void", "weak"
    return None


def apply_edits(sel):
    """Rewrite the return-type tokens of the given findings in place.  Returns (edits, files)."""
    edits = collections.defaultdict(list)
    for f in sel:
        edits[f["file"]].append(f)
    changed = 0
    for rel, fl in edits.items():
        p = os.path.join(ROOT, rel)
        raw = open(p, encoding="utf-8", errors="replace", newline="").read()
        crlf = "\r\n" in raw
        body = raw.replace("\r\n", "\n")
        # offsets refer to the comment-stripped text, which keeps every offset identical
        text = blank_preproc(strip_comments(body))
        for f in sorted(fl, key=lambda x: -x["head_start"]):
            head = text[f["head_start"]:f["name_pos"]]
            new = {"void": "void", "value": "int", "int": "int", "float": "float"}[f["wanted"]]
            if f["tk"] == "void":
                mm = re.search(r"\bvoid\b", head)
                if not mm:
                    continue
                s, e = mm.span()
            else:
                toks = list(re.finditer(r'"[^"]*"|::|[A-Za-z_]\w*|\S', head))
                idx = [t for t in toks if t.group(0) not in QUALS]
                if f["member"]:
                    while len(idx) >= 2 and idx[-1].group(0) == "::":
                        idx = idx[:-2]
                if not idx:
                    continue
                s, e = idx[0].start(), idx[-1].end()
            a0 = f["head_start"] + s
            a1 = f["head_start"] + e
            body = body[:a0] + new + body[a1:]
            changed += 1
        if crlf:
            body = body.replace("\n", "\r\n")
        with open(p, "w", encoding="utf-8", newline="") as fh:
            fh.write(body)
    return changed, len(edits)


def analyze_asm():
    funcs, names = load_asm()
    cl = Classifier(funcs, names)
    cl.run()
    clf = Classifier(funcs, names, reg_effect_f1, "finfo", "f1")
    clf.run()
    status, srcof = load_matched(names)
    return {"funcs": funcs, "names": names, "cl": cl, "clf": clf, "status": status}


def load_skip():
    """fn_<addr> names that are known to be unchangeable (tools/match/protolint_skip.txt)."""
    out = {}
    if os.path.exists(SKIP_FILE):
        for ln in open(SKIP_FILE, encoding="utf-8"):
            ln = ln.strip()
            if ln and not ln.startswith("#"):
                parts = ln.split(None, 1)
                out[parts[0]] = parts[1] if len(parts) > 1 else ""
    return out


def scan_source(asm, use_skip=True):
    """Scan src/ and include/ against an analyze_asm() result.  Returns (found, findings)."""
    funcs, cl, clf, status = asm["funcs"], asm["cl"], asm["clf"], asm["status"]
    files = source_files()
    structs, scalars = type_names(files)
    found = []
    for p in files:
        rel = os.path.relpath(p, ROOT).replace(os.sep, "/")
        found.extend(scan_file(p, rel, structs, scalars))
    counts = collections.Counter(f["name"] for f in found)
    skip = load_skip() if use_skip else {}
    findings = []
    for f in found:
        a = f["addr"]
        if a not in funcs or f["name"] in skip:
            continue
        c = cl.cls(a)
        v = verdict(f["tk"], c, clf.cls(a))
        if v is None:
            continue
        callers = cl.callers.get(a, set())
        m_ok = sum(1 for x in callers if status.get(x))
        f = dict(f)
        f.update({"class": c, "wanted": v[0], "tier": v[1], "callers": len(callers),
                  "callers_matched": m_ok, "callers_unmatched": len(callers) - m_ok,
                  "consumed": cl.result_used.get(a, 0), "ignored": cl.result_ignored.get(a, 0),
                  "is_matched": bool(status.get(a)), "ndecl": counts[f["name"]],
                  "reason": (clf.value.get(a) or "") if v[0] == "float" else
                  (cl.value.get(a) or ("void-" + str(cl.void.get(a))))})
        findings.append(f)
    return found, findings


def collect():
    """Run the whole analysis.  Returns a dict with funcs, names, cl, status, found, findings."""
    asm = analyze_asm()
    found, findings = scan_source(asm)
    asm.update({"found": found, "findings": findings})
    return asm


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--json", help="write findings to this file")
    ap.add_argument("--classes", action="store_true", help="dump class of every function")
    ap.add_argument("--why", nargs="*", help="show evidence for these functions")
    ap.add_argument("--apply", action="store_true", help="rewrite flagged return types in place")
    ap.add_argument("--tier", default="certain", choices=["certain", "weak", "all"])
    ap.add_argument("--path", default="", help="only touch files with this relative path prefix")
    ap.add_argument("--names", default="", help="comma separated fn_ names to restrict to")
    ap.add_argument("--defs", action="store_true", help="also rewrite definitions of unmatched functions")
    ap.add_argument("--quiet", action="store_true")
    ap.add_argument("--no-skip", action="store_true", help="also list names in protolint_skip.txt")
    args = ap.parse_args()

    asm = analyze_asm()
    funcs, names, cl, clf = asm["funcs"], asm["names"], asm["cl"], asm["clf"]

    if args.why:
        for w in args.why:
            a = names.get(w) or int(w.replace("fn_", ""), 16)
            f = funcs.get(a)
            print("%s @%08X r3 class=%s  f1 class=%s" % (w, a, cl.cls(a), clf.cls(a)))
            if f:
                print("  exits:", [(t, ("%x" % s if t == "ret" else s)) for t, s in f.info["exits"]])
                print("  callers: %d  result consumed: %d  ignored: %d  (f1 consumed: %d)" % (
                    len(cl.callers.get(a, ())), cl.result_used.get(a, 0), cl.result_ignored.get(a, 0),
                    clf.result_used.get(a, 0)))
            print("  r3 value reason:", cl.value.get(a), " void:", cl.void.get(a), " f1 value:", clf.value.get(a))
            for x in cl.why.get(a, [])[:5]:
                print("   ", x)
        return 0

    if args.classes:
        for a in sorted(funcs):
            print("%08X %-10s %-6s %s" % (a, cl.cls(a), "float" if clf.cls(a) == "value" else "", funcs[a].name))
        return 0

    found, findings = scan_source(asm, not args.no_skip)
    stats = collections.Counter()
    for f in found:
        a = f["addr"]
        if a in funcs:
            c = cl.cls(a)
            stats["%s/%s%s" % (f["tk"], c, "+f1" if clf.cls(a) == "value" else "")] += 1
        else:
            stats["no-such-function"] += 1

    if not args.apply:
        hdr = sorted(findings, key=lambda f: (f["tier"], f["wanted"], f["file"], f["line"]))
        if not args.quiet:
            for f in hdr:
                print("%s:%d  %s %s %s -> %s  [%s, %s]  callers %d (matched %d / unmatched %d), consumed %d%s" % (
                    f["file"], f["line"], f["what"], f["type"], f["name"], f["wanted"], f["tier"], f["reason"],
                    f["callers"], f["callers_matched"], f["callers_unmatched"], f["consumed"],
                    "  [fn matched]" if f["is_matched"] and f["what"] == "def" else ""))
        print("\nfunctions classified: %d  value %d  void %d  void-weak %d  unknown %d  (float result %d)" % (
            len(funcs), sum(1 for a in funcs if cl.cls(a) == "value"),
            sum(1 for a in funcs if cl.cls(a) == "void"),
            sum(1 for a in funcs if cl.cls(a) == "void-weak"),
            sum(1 for a in funcs if cl.cls(a) == "unknown"),
            sum(1 for a in funcs if clf.cls(a) == "value")))
        print("declarations/definitions scanned: %d" % len(found))
        print("findings: %d (%d distinct functions)  certain %d  weak %d" % (
            len(findings), len({f["name"] for f in findings}),
            sum(1 for f in findings if f["tier"] == "certain"), sum(1 for f in findings if f["tier"] == "weak")))
        for k in sorted(stats):
            print("  %-22s %d" % (k, stats[k]))
        if args.json:
            with open(args.json, "w") as fh:
                json.dump(findings, fh, indent=1)
        return 0

    # ---- apply ----
    want_names = {x.strip() for x in args.names.split(",") if x.strip()}
    sel = []
    for f in findings:
        if args.tier != "all" and f["tier"] != args.tier:
            continue
        if args.path and not f["file"].startswith(args.path):
            continue
        if want_names and f["name"] not in want_names:
            continue
        if f["what"] == "def" and (f["is_matched"] or not args.defs):
            continue
        sel.append(f)
    changed, nfiles = apply_edits(sel)
    print("rewrote %d declarations in %d files" % (changed, nfiles))
    return 0


if __name__ == "__main__":
    sys.exit(main())
