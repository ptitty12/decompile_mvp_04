"""Find already-matched "twins" of an unmatched function and print their C.

    python tools/match/twins.py show fn_8026C65C [more fns] [-n 3] [--lines 80] [--diff]
    python tools/match/twins.py unit game/tu_8026C414        # best twin per unmatched function
    python tools/match/twins.py rank [--area game] [--min 0.8] [--max-size 0x800] > worklist.tsv

A twin is a matched function (objdiff 100%) whose code looks like the target's:
the same opcode sequence (normalised edit distance), the same callees, and the
same field offsets off non-stack registers. Its source is a worked example of
how this compiler produced that shape. Similarity-guided examples were the
biggest long-tail win reported for LLM matching (blog.chrislewis.au, "The Long
Tail of LLM-Assisted Decompilation"); Coddog uses the same opcode distance.

Twins inform; they verify nothing. objdiff and tools/verify/verify.py decide.

Scores (0..1): ops = 1 - levenshtein(opcodes)/max(len); calls/fields/data =
Jaccard of callee names / field-offset accesses / data symbols. Total is a
weighted mean over the features either function has (ops .55, calls .2,
fields .15, data .1). A twin with ops 1.00 and the same length is a clone:
copy its source and adapt names and types.

Twin sources with permuter-style constructs (do {} while (0), (void)0,
if (1)) are flagged and ranked lower: they match, but they don't show how the
original was written.

Reads build/GV4E69/report.json, build/GV4E69/asm/**.s and src/. The parsed
index is cached in build/GV4E69/twins_cache.pkl and rebuilt when either input
is newer. First run takes about a minute.
"""
from __future__ import annotations

import argparse
import difflib
import json
import os
import pickle
import re
import sys
from pathlib import Path

import numpy as np

BUILD = Path("build/GV4E69")
ASM_DIR = BUILD / "asm"
REPORT = BUILD / "report.json"
CACHE = BUILD / "twins_cache.pkl"
CACHE_VERSION = 4

WEIGHTS = {"ops": 0.55, "calls": 0.20, "fields": 0.15, "data": 0.10}
HASH_DIM = 1024
PREFILTER_K = 40

FN_RE = re.compile(r"^\.fn (\S+), \w+$(.*?)^\.endfn \1$", re.S | re.M)
INS_RE = re.compile(r"^/\* [0-9A-F]{8} [0-9A-F]+\s+[0-9A-F ]+ \*/\t(\S+)\s*(.*)$", re.M)
MEM_RE = re.compile(r"(-?0x[0-9A-Fa-f]+|-?\d+)\((r\d+)\)")
SYM_RE = re.compile(r"([A-Za-z_.$][\w.$@]*?)(?:@ha|@l|@h|@sda21)")
GENERATED = ("__static_initialization_and_destruction", "_GLOBAL_.")
PERMUTER_RE = re.compile(
    r"do\s*\{\s*\}\s*while\s*\(\s*0\s*\)|\(void\)\s*0\b|\bif\s*\(\s*1\s*\)|\bwhile\s*\(\s*0\s*\)"
)
BRANCH_PREFIXES = ("b", "bl", "bctr", "bctrl", "blr")


# ---------------------------------------------------------------- index


def newest_mtime(paths) -> float:
    return max((p.stat().st_mtime for p in paths), default=0.0)


class Index:
    """Parsed functions: opcode ids plus feature sets, keyed by (unit, name)."""

    def __init__(self) -> None:
        self.keys: list[tuple[str, str]] = []
        self.size: list[int] = []
        self.pct: list[float] = []
        self.ops: list[np.ndarray] = []
        self.calls: list[frozenset] = []
        self.fields: list[frozenset] = []
        self.data: list[frozenset] = []
        self.opcode_ids: dict[str, int] = {}
        self.by_name: dict[str, list[int]] = {}

    def opcode_id(self, mnem: str) -> int:
        return self.opcode_ids.setdefault(mnem, len(self.opcode_ids))


def parse_function(body: str, idx: Index):
    ops, calls, fields, data = [], set(), set(), set()
    for m in INS_RE.finditer(body):
        mnem, args = m.group(1), m.group(2)
        ops.append(idx.opcode_id(mnem))
        if mnem in ("bl", "b") and args and not args.startswith(".L"):
            calls.add(args.split()[0])
        for off, reg in MEM_RE.findall(args):
            if reg not in ("r1", "r2", "r13"):
                fields.add(f"{mnem}@{int(off, 0):#x}")
        for sym in SYM_RE.findall(args):
            data.add(sym)
    return np.array(ops, dtype=np.uint16), frozenset(calls), frozenset(fields), frozenset(data)


def build_index() -> Index:
    report = json.loads(REPORT.read_text())
    status = {}
    for u in report["units"]:
        for f in u.get("functions", []):
            status[(u["name"], f["name"])] = (int(f.get("size", 0) or 0), float(f.get("fuzzy_match_percent", 0) or 0))
    idx = Index()
    for path in sorted(ASM_DIR.rglob("*.s")):
        unit = "main/" + path.relative_to(ASM_DIR).with_suffix("").as_posix()
        text = path.read_text(encoding="utf-8", errors="replace")
        for m in FN_RE.finditer(text):
            name = m.group(1)
            size, pct = status.get((unit, name), (0, 0.0))
            ops, calls, fields, data = parse_function(m.group(2), idx)
            if len(ops) == 0:
                continue
            i = len(idx.keys)
            idx.keys.append((unit, name))
            idx.size.append(size or 4 * len(ops))
            idx.pct.append(pct)
            idx.ops.append(ops)
            idx.calls.append(calls)
            idx.fields.append(fields)
            idx.data.append(data)
            idx.by_name.setdefault(name, []).append(i)
    return idx


def load_index() -> Index:
    if not REPORT.exists() or not ASM_DIR.exists():
        raise SystemExit("needs build/GV4E69/report.json and build/GV4E69/asm (run configure.py && ninja)")
    stamp = (CACHE_VERSION, REPORT.stat().st_mtime, newest_mtime(ASM_DIR.rglob("*.s")))
    if CACHE.exists():
        try:
            with CACHE.open("rb") as fh:
                saved_stamp, state = pickle.load(fh)
            if saved_stamp == stamp:
                idx = Index()
                idx.__dict__.update(state)  # plain dict: loads whether run as a script or imported
                return idx
        except Exception:
            pass
    print("twins: indexing asm (cached afterwards)...", file=sys.stderr)
    idx = build_index()
    with CACHE.open("wb") as fh:
        pickle.dump((stamp, idx.__dict__), fh, protocol=pickle.HIGHEST_PROTOCOL)
    return idx


# ---------------------------------------------------------------- scoring


def vectors(idx: Index, which: list[int]) -> np.ndarray:
    """Hashed opcode unigram+bigram histograms, L2-normalised (prefilter only)."""
    out = np.zeros((len(which), HASH_DIM), dtype=np.float32)
    for row, i in enumerate(which):
        o = idx.ops[i].astype(np.int64)
        h = np.concatenate([o * 7919 % HASH_DIM, (o[:-1] * 1031 + o[1:] * 7) % HASH_DIM])
        v = np.bincount(h, minlength=HASH_DIM).astype(np.float32)
        out[row] = np.sqrt(v)
    norms = np.linalg.norm(out, axis=1, keepdims=True)
    return out / np.maximum(norms, 1e-9)


def levenshtein(a: np.ndarray, b: np.ndarray) -> int:
    """Row-vectorised edit distance (insert/delete/substitute cost 1)."""
    if len(a) < len(b):
        a, b = b, a
    m = len(b)
    if m == 0:
        return len(a)
    ar = np.arange(m + 1, dtype=np.int32)
    prev = ar.copy()
    for i in range(1, len(a) + 1):
        sub = prev[:-1] + (b != a[i - 1])
        cur = np.empty(m + 1, dtype=np.int32)
        cur[0] = i
        cur[1:] = np.minimum(prev[1:] + 1, sub)
        # insertions within the row: cur[j] = min_k(cur[k] + j - k)
        cur = np.minimum.accumulate(cur - ar) + ar
        prev = cur
    return int(prev[-1])


def jaccard(a: frozenset, b: frozenset):
    if not a and not b:
        return None
    return len(a & b) / len(a | b)


def score(idx: Index, t: int, c: int) -> dict:
    a, b = idx.ops[t], idx.ops[c]
    parts = {"ops": 1.0 - levenshtein(a, b) / max(len(a), len(b))}
    for feat in ("calls", "fields", "data"):
        s = jaccard(getattr(idx, feat)[t], getattr(idx, feat)[c])
        if s is not None:
            parts[feat] = s
    total = sum(WEIGHTS[k] * v for k, v in parts.items()) / sum(WEIGHTS[k] for k in parts)
    parts["total"] = total
    parts["clone"] = parts["ops"] == 1.0
    return parts


def candidates(idx: Index) -> list[int]:
    return [
        i
        for i, (unit, name) in enumerate(idx.keys)
        if idx.pct[i] >= 100.0 and not name.startswith(GENERATED) and "/auto_" not in unit
    ]


def best_twins(idx: Index, targets: list[int], cand: list[int], cand_vec: np.ndarray, n: int, src_cache: dict) -> dict:
    out = {}
    tvec = vectors(idx, targets)
    sims = tvec @ cand_vec.T
    clen = np.array([len(idx.ops[c]) for c in cand])
    for row, t in enumerate(targets):
        tl = len(idx.ops[t])
        lo, hi = (tl / 2.0, tl * 2.0) if tl > 8 else (0, tl + 4)
        s = np.where((clen >= lo) & (clen <= hi), sims[row], -1.0)
        top = np.argpartition(-s, min(PREFILTER_K, len(s) - 1))[:PREFILTER_K]
        scored = []
        for j in top:
            if s[j] < 0:
                continue
            c = cand[j]
            if c == t:
                continue
            p = score(idx, t, c)
            src = twin_source(idx, c, src_cache)
            p["permuter"] = bool(src and PERMUTER_RE.search(src[1]))
            rank = p["total"] - (0.1 if p["permuter"] else 0.0)
            scored.append((rank, c, p))
        scored.sort(key=lambda x: -x[0])
        out[t] = scored[:n]
    return out


# ---------------------------------------------------------------- source lookup

OPS = {
    "as": "operator=", "eq": "operator==", "ne": "operator!=", "lt": "operator<", "gt": "operator>",
    "le": "operator<=", "ge": "operator>=", "pl": "operator+", "mi": "operator-", "ml": "operator*",
    "dv": "operator/", "md": "operator%", "vc": "operator[]", "cl": "operator()", "nw": "operator new",
    "dl": "operator delete", "vn": "operator new[]", "vd": "operator delete[]", "apl": "operator+=",
    "ami": "operator-=", "amu": "operator*=", "adv": "operator/=", "ls": "operator<<", "rs": "operator>>",
    "nt": "operator!", "aa": "operator&&", "oo": "operator||", "rf": "operator->",
}


def parse_class(s: str):
    """Class name at the start of a g++ 2.95 mangled tail: '11Foo...' or 'Q24EAGL11Bar...'."""
    m = re.match(r"Q(\d)(.*)", s)
    if m:
        n, rest, last = int(m.group(1)), m.group(2), None
        for _ in range(n):
            mm = re.match(r"(\d+)(.*)", rest)
            if not mm:
                return None
            k = int(mm.group(1))
            last, rest = mm.group(2)[:k], mm.group(2)[k:]
        return last
    m = re.match(r"(\d+)(.*)", s)
    if m:
        k = int(m.group(1))
        return m.group(2)[:k]
    return None


def search_patterns(name: str) -> list[str]:
    """Regexes (most specific first) that find this symbol's definition in source."""
    if name.startswith("_._"):
        cls = parse_class(name[3:])
        return [rf"\b{re.escape(cls)}::~{re.escape(cls)}\s*\(", rf"~{re.escape(cls)}\s*\("] if cls else []
    if name.startswith("__") and not name.startswith(GENERATED):
        tail = name[2:]
        m = re.match(r"([a-z]{2,3})__(.*)", tail)
        if m and m.group(1) in OPS:
            cls = parse_class(m.group(2))
            op = re.escape(OPS[m.group(1)])
            return ([rf"\b{re.escape(cls)}::{op}\s*\("] if cls else []) + [rf"{op}\s*\("]
        cls = parse_class(tail)
        return [rf"\b{re.escape(cls)}::{re.escape(cls)}\s*\(", rf"\b{re.escape(cls)}\s*\("] if cls else []
    m = re.match(r"(.+?)__(F.*|Q\d.*|\d+[A-Za-z_].*)$", name)
    if m:
        base, tail = m.group(1), m.group(2)
        if tail.startswith("F"):
            return [rf"\b{re.escape(base)}\s*\("]
        cls = parse_class(tail)
        pats = [rf"\b{re.escape(cls)}::{re.escape(base)}\s*\("] if cls else []
        return pats + [rf"\b{re.escape(base)}\s*\("]
    return [rf"\b{re.escape(name)}\s*\("]


def unit_sources(unit: str) -> list[Path]:
    rel = unit[len("main/"):] if unit.startswith("main/") else unit
    return [p for p in (Path("src") / f"{rel}{ext}" for ext in (".cpp", ".c", ".cp")) if p.exists()]


def extract_definition(text: str, pat: str):
    """(line number, source) of the first definition matching pat, or None."""
    for m in re.finditer(pat, text):
        line_prefix = text[text.rfind("\n", 0, m.start()) + 1 : m.start()]
        if "//" in line_prefix or line_prefix.rfind("/*") > line_prefix.rfind("*/"):
            continue  # a mention inside a comment
        # walk to the end of the parameter list
        i, depth = m.end() - 1, 0
        while i < len(text):
            ch = text[i]
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
                if depth == 0:
                    break
            i += 1
        j = i + 1
        while j < len(text) and text[j] not in "{;":
            j += 1
        if j >= len(text) or text[j] != "{":
            continue  # a declaration or a call
        start = text.rfind("\n", 0, m.start()) + 1
        prev_end = start - 1
        prev_start = text.rfind("\n", 0, max(prev_end, 0)) + 1
        prev = text[prev_start:prev_end].strip() if prev_end > 0 else ""
        if prev and not prev.endswith((";", "}", "{", "*/")) and not prev.startswith(("#", "//")):
            start = prev_start  # return type on its own line
        depth, k = 0, j
        while k < len(text):
            if text[k] == "{":
                depth += 1
            elif text[k] == "}":
                depth -= 1
                if depth == 0:
                    break
            k += 1
        line = text.count("\n", 0, start) + 1
        return line, text[start : k + 1]
    return None


def file_text(f: Path, cache: dict) -> str:
    key = ("file", f)
    if key not in cache:
        cache[key] = f.read_text(encoding="utf-8", errors="replace")
    return cache[key]


def twin_source(idx: Index, i: int, cache: dict):
    """(path:line, source text) for function i, or None if not found."""
    if i in cache:
        return cache[i]
    unit, name = idx.keys[i]
    found = None
    files = unit_sources(unit)
    for pat in search_patterns(name):
        for f in files:
            text = file_text(f, cache)
            r = extract_definition(text, pat)
            if r:
                found = (f"{f.as_posix()}:{r[0]}", r[1])
                break
        if found:
            break
    cache[i] = found
    return found


def callers_of(idx: Index, cand: list[int]) -> dict[str, list[int]]:
    """callee name -> matched functions that call it."""
    out: dict[str, list[int]] = {}
    for c in cand:
        for callee in idx.calls[c]:
            out.setdefault(callee, []).append(c)
    return out


def callee_info(idx: Index, callee: str, callers: list[int], cache: dict):
    """(prototype or None, where, example call or None) for a callee, from matched source.

    The prototype is the callee's own definition signature when it is matched
    source, else a column-0 declaration in a matched caller's file."""
    for j in idx.by_name.get(callee, []):
        if idx.pct[j] >= 100.0:
            src = twin_source(idx, j, cache)
            if src:
                sig = src[1].split("{", 1)[0].strip().replace("\n", " ")
                proto, where = re.sub(r"\s+", " ", sig) + ";", src[0]
                break
    else:
        proto, where = None, None
    example = None
    pats = search_patterns(callee)
    for c in callers[:8]:
        for f in unit_sources(idx.keys[c][0]):
            text = file_text(f, cache)
            for pat in pats:
                for m in re.finditer(pat, text):
                    ls = text.rfind("\n", 0, m.start()) + 1
                    le = text.find("\n", m.end())
                    line = text[ls : le if le >= 0 else len(text)]
                    stripped = line.strip()
                    if not stripped.endswith(";"):
                        continue
                    if proto is None and not line[:1].isspace() and "=" not in stripped.split("(")[0]:
                        proto, where = stripped, f"{f.as_posix()}:{text.count(chr(10), 0, ls) + 1}"
                    elif example is None and line[:1].isspace():
                        example = f"{stripped}   ({f.as_posix()}:{text.count(chr(10), 0, ls) + 1})"
                    if proto and example:
                        return proto, where, example
    return proto, where, example


def same_callee_examples(idx: Index, t: int, callers: dict, n: int):
    counts: dict[int, int] = {}
    for callee in idx.calls[t]:
        for c in callers.get(callee, [])[:500]:
            counts[c] = counts.get(c, 0) + 1
    best = sorted(counts.items(), key=lambda kv: (-kv[1], abs(len(idx.ops[kv[0]]) - len(idx.ops[t]))))
    return [(c, k) for c, k in best if k >= 2][:n]


# ---------------------------------------------------------------- commands


def resolve(idx: Index, fn: str, unit: str | None) -> int:
    hits = idx.by_name.get(fn, [])
    if not hits:
        hits = [i for i, (_, n) in enumerate(idx.keys) if n.startswith(fn + "__")]
    if unit:
        u = unit if unit.startswith("main/") else "main/" + unit
        hits = [i for i in hits if idx.keys[i][0] == u]
    if not hits:
        raise SystemExit(f"{fn}: not found in build/GV4E69/asm")
    if len(hits) > 1:
        units = ", ".join(idx.keys[i][0] for i in hits[:6])
        raise SystemExit(f"{fn}: ambiguous ({units}); pass --unit")
    return hits[0]


def fmt_parts(p: dict) -> str:
    keys = [k for k in ("ops", "calls", "fields", "data") if k in p]
    s = " ".join(f"{k} {p[k]:.2f}" for k in keys)
    flags = (" CLONE" if p["clone"] else "") + (" permuter-style-source" if p["permuter"] else "")
    return f"score {p['total']:.2f} ({s}){flags}"


def opcode_diff(idx: Index, t: int, c: int, limit: int = 4) -> list[str]:
    names = {v: k for k, v in idx.opcode_ids.items()}
    a = [names[o] for o in idx.ops[t]]
    b = [names[o] for o in idx.ops[c]]
    out = []
    for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes():
        if tag == "equal":
            continue
        out.append(f"   target[{i1}:{i2}] {' '.join(a[i1:i2]) or '-'}  |  twin[{j1}:{j2}] {' '.join(b[j1:j2]) or '-'}")
        if len(out) >= limit:
            out.append("   ...")
            break
    return out


def cmd_show(args) -> None:
    idx = load_index()
    cand = candidates(idx)
    cvec = vectors(idx, cand)
    cache: dict = {}
    targets = [resolve(idx, fn, args.unit) for fn in args.fns]
    res = best_twins(idx, targets, cand, cvec, args.n, cache)
    for t in targets:
        unit, name = idx.keys[t]
        print(f"== {name}  ({unit}, {idx.size[t]:#x} B, {len(idx.ops[t])} ins, {idx.pct[t]:.1f}% now)")
        if not res[t]:
            print("   no twin within 2x length")
        for rank, (_, c, p) in enumerate(res[t], 1):
            cu, cn = idx.keys[c]
            src = twin_source(idx, c, cache)
            where = src[0] if src else f"(source not found in {unit_sources(cu) or 'src/'})"
            print(f"-- #{rank} {cn}  {fmt_parts(p)}")
            print(f"   {cu}, {idx.size[c]:#x} B, {len(idx.ops[c])} ins, {where}")
            if args.diff:
                print("\n".join(opcode_diff(idx, t, c)))
            if src and args.lines > 0:
                lines = src[1].splitlines()
                body = lines[: args.lines] + ([f"   ... ({len(lines) - args.lines} more lines)"] if len(lines) > args.lines else [])
                print("\n".join("   " + l for l in body))
        if not args.no_callees and idx.calls[t]:
            callers = callers_of(idx, cand) if "callers" not in cache else cache["callers"]
            cache["callers"] = callers
            print(f"-- callees ({len(idx.calls[t])}): prototype from matched source | example call")
            for callee in sorted(idx.calls[t]):
                proto, where, example = callee_info(idx, callee, callers.get(callee, []), cache)
                n_callers = len(callers.get(callee, []))
                if proto is None and example is None:
                    print(f"   {callee}: no matched source calls it yet")
                    continue
                print(f"   {callee}  [{n_callers} matched callers]")
                if proto:
                    print(f"      {proto}   ({where})")
                if example:
                    print(f"      e.g. {example}")
            ex = same_callee_examples(idx, t, callers, 3)
            if ex:
                print("-- matched functions sharing the most callees (read for argument types and call order):")
                for c, k in ex:
                    src = twin_source(idx, c, cache)
                    where = src[0] if src else idx.keys[c][0]
                    print(f"   {idx.keys[c][1]}  shares {k}/{len(idx.calls[t])} callees, {len(idx.ops[c])} ins, {where}")
        print()


def area_of(unit: str) -> str:
    parts = unit.split("/")
    return parts[1] if len(parts) > 2 else parts[-1]


def cmd_rank(args, only_unit: str | None = None) -> None:
    idx = load_index()
    cand = candidates(idx)
    cvec = vectors(idx, cand)
    cache: dict = {}
    max_size = int(args.max_size, 0) if getattr(args, "max_size", None) else None
    targets = []
    for i, (unit, name) in enumerate(idx.keys):
        if idx.pct[i] >= 100.0 or "/auto_" in unit or name.startswith(GENERATED):
            continue
        if only_unit and unit != only_unit:
            continue
        if getattr(args, "area", None) and area_of(unit) != args.area:
            continue
        if max_size and idx.size[i] > max_size:
            continue
        targets.append(i)
    res = {}
    for k in range(0, len(targets), 256):
        res.update(best_twins(idx, targets[k : k + 256], cand, cvec, 1, cache))
        if not only_unit:
            print(f"twins: {min(k + 256, len(targets))}/{len(targets)}", file=sys.stderr)
    rows = []
    for t in targets:
        if not res[t]:
            rows.append((0.0, t, None, None))
            continue
        _, c, p = res[t][0]
        rows.append((p["total"], t, c, p))
    rows.sort(key=lambda r: (-r[0], idx.size[r[1]]))
    callers = callers_of(idx, cand)
    matched_names = {idx.keys[c][1] for c in cand}

    def coverage(t: int) -> str:
        # share of the target's callees that matched code already calls or defines
        calls = idx.calls[t]
        if not calls:
            return "-"
        known = sum(1 for x in calls if x in callers or x in matched_names)
        return f"{known / len(calls):.2f}"

    print("score\tclone\tfunction\tunit\tsize\tnow_pct\ttwin\ttwin_unit\tops\tcalls\tfields\tcallee_cov")
    for s, t, c, p in rows:
        if s < args.min:
            continue
        unit, name = idx.keys[t]
        if c is None:
            print(f"0.00\t-\t{name}\t{unit}\t{idx.size[t]:#x}\t{idx.pct[t]:.1f}\t-\t-\t-\t-\t-\t{coverage(t)}")
            continue
        cu, cn = idx.keys[c]
        print(
            f"{s:.2f}\t{'yes' if p['clone'] else '-'}\t{name}\t{unit}\t{idx.size[t]:#x}\t{idx.pct[t]:.1f}\t{cn}\t{cu}"
            f"\t{p['ops']:.2f}\t{p.get('calls', float('nan')):.2f}\t{p.get('fields', float('nan')):.2f}\t{coverage(t)}"
        )


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("show", help="print the best twins of one or more functions, with their source")
    s.add_argument("fns", nargs="+")
    s.add_argument("--unit", help="disambiguate a name that exists in several units")
    s.add_argument("-n", type=int, default=3)
    s.add_argument("--lines", type=int, default=80, help="max source lines per twin (0 = location only)")
    s.add_argument("--diff", action="store_true", help="show where the opcode sequences differ")
    s.add_argument("--no-callees", action="store_true", help="skip the callee prototype section")
    u = sub.add_parser("unit", help="best twin for every unmatched function in a unit")
    u.add_argument("unit")
    u.add_argument("--min", type=float, default=0.0)
    r = sub.add_parser("rank", help="TSV worklist of all unmatched functions, best twin first")
    r.add_argument("--area", help="game, fe, db, ealib, dolphin, ...")
    r.add_argument("--min", type=float, default=0.0)
    r.add_argument("--max-size", help="skip functions larger than this (e.g. 0x800)")
    args = ap.parse_args()
    if args.cmd == "show":
        cmd_show(args)
    elif args.cmd == "unit":
        unit = args.unit if args.unit.startswith("main/") else "main/" + args.unit
        cmd_rank(args, only_unit=unit.removesuffix(".cpp").removesuffix(".c"))
    else:
        cmd_rank(args)


if __name__ == "__main__":
    main()
