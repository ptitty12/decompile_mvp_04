#!/usr/bin/env python3
"""Rename symbols across the knowledge track, and adopt the names dtk gives.

A name commit (CLAUDE.md) renames a symbol everywhere it is spelled:
- config/GV4E69/symbols.txt (the definition line), and config.yml's
  add_relocations targets;
- every reference in src/ and include/ (code and comments, never string or
  character literals);
- tools/match/symbol_aliases.tsv: one `old<TAB>new` line per rename, and older
  aliases that pointed at a renamed name are re-pointed, so sources written
  before the rename still resolve.

Each file keeps its bytes apart from the renamed tokens: line endings,
encoding and every other character stay as they were. Running the same
renames twice changes nothing.

Tidying that only touches lines a rename changed:
- `#define NEW NEW` (an alias macro that now names itself) is removed;
- a trailing comment that only repeats the new name of a declaration on the
  same line (`void OSGetTime(void); /* OSGetTime */`) is removed;
- in comments, a placeholder glossed with its own new name collapses to the
  name (`fn_80438628 (OSGetTime)` -> `OSGetTime`).

dtk (decomp-toolkit) has built-in signatures for many SDK functions. When
symbols.txt names one of them, `dtk dol split` matches the signature and
rewrites symbols.txt itself: it renames callees and data the signature knows,
changes sizes and scopes, and can add labels. --from-dtk runs that split
until symbols.txt stops changing, compares the result with the starting
symbols.txt by address, and propagates every rename (yours and dtk's) into
the sources and the alias table. If the split fails, symbols.txt is restored
and nothing else is touched.

Names that are not C identifiers (dtk's compiler-local `@69` string labels)
stay in symbols.txt and the alias table only. If a source still references
the old name of one, the run reports it and exits 1: that source needs a
decision (see docs/DECISIONS.md), not a blind substitution.

Usage (from anywhere; paths are relative to the repo root):
  python tools/goals/rename_symbols.py RENAMES.tsv             # old<TAB>new per line
  python tools/goals/rename_symbols.py --pair fn_80438628=OSGetTime
  python tools/goals/rename_symbols.py --from-dtk [RENAMES.tsv ...]
  python tools/goals/rename_symbols.py --from-dtk --dry-run    # report only, restore everything
Options: --report FILE writes every applied rename as old<TAB>new<TAB>origin;
--repo DIR works on another checkout. --from-dtk needs one finished `ninja`
(it reads build/GV4E69/orig/main_sections.dol and runs build/tools/dtk).
"""
import argparse
import os
import re
import subprocess
import sys

SYMBOLS = os.path.join("config", "GV4E69", "symbols.txt")
CONFIG = os.path.join("config", "GV4E69", "config.yml")
ALIASES = os.path.join("tools", "match", "symbol_aliases.tsv")
SOURCE_DIRS = ("src", "include")
SOURCE_EXTS = (".c", ".cpp", ".cc", ".cp", ".cxx", ".h", ".hpp", ".hh", ".inc", ".inl", "")

IDENT = re.compile(rb"^[A-Za-z_][A-Za-z0-9_]*$")
SYMLINE = re.compile(rb"^(\S+) = ([^:\s]+):0x([0-9A-Fa-f]+);([^\r\n]*)")
# A gcc 2.95 / SN mangled placeholder: fn_80004830__11Unk8060F6F8 -> base + suffix
MANGLED = re.compile(r"^((?:fn|lbl)_[0-9A-F]{8})(__\w+)$")


# ----------------------------------------------------------------------------
# pairs


def read_pairs(path):
    pairs = []
    with open(path, "rb") as f:
        for raw in f.read().decode("utf-8").splitlines():
            line = raw.strip()
            if not line or line.startswith("#"):
                continue
            parts = line.split("\t")
            if len(parts) < 2:
                parts = line.split()
            pairs.append((parts[0].strip(), parts[1].strip()))
    return pairs


def check_pairs(pairs):
    """Drop no-ops, refuse contradictions. Returns an ordered {old: new}."""
    ren = {}
    for old, new in pairs:
        if old == new:
            continue
        if old in ren and ren[old] != new:
            raise SystemExit(f"rename_symbols: {old} renamed twice ({ren[old]}, {new})")
        ren[old] = new
    news = {}
    for old, new in ren.items():
        if new in news:
            raise SystemExit(f"rename_symbols: {news[new]} and {old} both renamed to {new}")
        news[new] = old
    return ren


def source_renames(ren):
    """The renames as sources spell them: C identifiers only, mangled names by base."""
    out, skipped = {}, {}
    for old, new in ren.items():
        o, n = old, new
        m = MANGLED.match(old)
        if m:
            if not new.endswith(m.group(2)):
                skipped[old] = new
                continue
            o, n = m.group(1), new[: -len(m.group(2))]
        if IDENT.match(o.encode()) and IDENT.match(n.encode()):
            out[o] = n
        else:
            skipped[old] = new
    return out, skipped


# ----------------------------------------------------------------------------
# files


def read(path):
    with open(path, "rb") as f:
        return f.read()


def write(path, data):
    with open(path, "wb") as f:
        f.write(data)


def token_re(names):
    alt = b"|".join(re.escape(n.encode()) for n in sorted(names, key=len, reverse=True))
    return re.compile(rb"(?<![A-Za-z0-9_$])(?:" + alt + rb")(?![A-Za-z0-9_$])")


# ----------------------------------------------------------------------------
# symbols.txt


def parse_symbols(data):
    """[(name, section, addr, attrs)] for each definition line."""
    out = []
    for line in data.splitlines():
        m = SYMLINE.match(line)
        if m:
            out.append((m.group(1).decode("latin-1"), m.group(2).decode("latin-1"),
                        int(m.group(3), 16), m.group(4).decode("latin-1").strip()))
    return out


def rename_symbols_txt(path, ren):
    """Rename definition lines. Returns (renamed olds, olds not found)."""
    data = read(path)
    lines = data.splitlines(keepends=True)
    defined = {}
    for i, line in enumerate(lines):
        m = SYMLINE.match(line)
        if m:
            defined.setdefault(m.group(1).decode("latin-1"), []).append(i)
    done = []
    for old, new in ren.items():
        if old not in defined:
            continue
        if new in defined:
            attrs = [parse_symbols(lines[i])[0] for i in defined[new]]
            if not all("scope:local" in a[3] for a in attrs):
                raise SystemExit(f"rename_symbols: {new} is already defined in symbols.txt ({old} -> {new})")
        for i in defined[old]:
            lines[i] = new.encode("latin-1") + lines[i][len(old.encode("latin-1")):]
        done.append(old)
    if done:
        write(path, b"".join(lines))
    return done, [o for o in ren if o not in defined]


def config_renames(path, ren, dry_run=False):
    """Rename `target:` names in config.yml's add_relocations.

    Returns (count renamed, [olds kept because the new name is not an identifier]).
    """
    if not os.path.isfile(path):
        return 0, []
    data = read(path)
    pat = re.compile(rb"(^[ \t-]*target:[ \t]*)(\S+)", re.M)
    count, kept = 0, []

    def sub(m):
        nonlocal count
        name = m.group(2).decode("latin-1")
        if name not in ren:
            return m.group(0)
        if not IDENT.match(ren[name].encode()):
            kept.append(name)
            return m.group(0)
        count += 1
        return m.group(1) + ren[name].encode("latin-1")
    new = pat.sub(sub, data)
    if new != data and not dry_run:
        write(path, new)
    return count, kept


# ----------------------------------------------------------------------------
# C/C++ sources


def segments(data):
    """Split C/C++ source bytes into [(kind, start, end)], kind in code/comment/string."""
    out = []
    i, n, start = 0, len(data), 0

    def flush(end, k):
        if end > start:
            out.append((k, start, end))
    while i < n:
        c = data[i:i + 1]
        if c == b"/" and data[i + 1:i + 2] == b"/":
            flush(i, "code")
            j = i
            while j < n and data[j:j + 1] not in (b"\n", b"\r"):
                j += 1
            out.append(("comment", i, j))
            i = start = j
        elif c == b"/" and data[i + 1:i + 2] == b"*":
            flush(i, "code")
            j = data.find(b"*/", i + 2)
            j = n if j < 0 else j + 2
            out.append(("comment", i, j))
            i = start = j
        elif c in (b'"', b"'"):
            flush(i, "code")
            j = i + 1
            while j < n and data[j:j + 1] != c and data[j:j + 1] != b"\n":
                j += 2 if data[j:j + 1] == b"\\" else 1
            j = min(j + 1, n)
            out.append(("string", i, j))
            i = start = j
        else:
            i += 1
    flush(n, "code")
    return out


def gloss_re(old, new):
    """`old (new)`, `old new`, `old = new`, `new (old)`, ... inside a comment."""
    o, w = re.escape(old.encode()), re.escape(new.encode())
    b, e = rb"(?<![A-Za-z0-9_$])", rb"(?![A-Za-z0-9_$])"
    sep = rb"(?:[ \t]*(?:=|:|->|=>|/|,)[ \t]*|[ \t]+)"
    return re.compile(
        b + o + rb"[ \t]*\([ \t]*" + w + rb"[ \t]*\)" + e + b"|" +
        b + w + rb"[ \t]*\([ \t]*" + o + rb"[ \t]*\)" + e + b"|" +
        b + o + sep + w + e + b"|" +
        b + w + sep + o + e)


class SourceRenamer:
    def __init__(self, ren):
        self.ren = {o.encode(): n.encode() for o, n in ren.items()}
        self.tok = token_re(ren) if ren else None
        self.gloss = [(gloss_re(o, n), n.encode()) for o, n in ren.items()]
        self.newnames = set(self.ren.values())

    def rename(self, data):
        """Returns (new bytes, set of old names seen in code)."""
        if not self.tok or not self.tok.search(data):
            return data, set()
        seen = set()
        parts = []
        for kind, s, e in segments(data):
            seg = data[s:e]
            if kind == "string" or not self.tok.search(seg):
                parts.append(seg)
                continue
            if kind == "comment":
                for pat, new in self.gloss:
                    if pat.search(seg):
                        seg = pat.sub(new, seg)
            else:
                seen.update(m.group(0) for m in self.tok.finditer(seg))
            seg = self.tok.sub(lambda m: self.ren[m.group(0)], seg)
            parts.append(seg)
        out = b"".join(parts)
        return self.tidy(data, out), seen

    def tidy(self, before, after):
        """Clean up lines the rename changed: self-defines and echo comments."""
        old_lines = set(before.splitlines())
        lines = after.splitlines(keepends=True)
        out = []
        for line in lines:
            body = line.rstrip(b"\r\n")
            eol = line[len(body):]
            if body in old_lines:
                out.append(line)
                continue
            m = re.match(rb"^[ \t]*#[ \t]*define[ \t]+([A-Za-z_]\w*)[ \t]+\1[ \t]*(?:/\*.*?\*/[ \t]*|//.*)?$", body)
            if m and m.group(1) in self.newnames:
                continue
            m = re.match(rb"^(.*?\S)[ \t]*(?:/\*[ \t]*([A-Za-z_]\w*)[ \t]*\*/|//[ \t]*([A-Za-z_]\w*))[ \t]*$", body)
            if m:
                name = m.group(2) or m.group(3)
                code = m.group(1)
                if name in self.newnames and "/*" not in code.decode("latin-1") and "//" not in code.decode("latin-1") \
                        and re.search(rb"(?<![A-Za-z0-9_$])" + re.escape(name) + rb"(?![A-Za-z0-9_$])", code):
                    body = code
            out.append(body + eol)
        return b"".join(out)


def source_files(repo):
    for d in SOURCE_DIRS:
        for root, dirs, files in os.walk(os.path.join(repo, d)):
            dirs.sort()
            for f in sorted(files):
                if os.path.splitext(f)[1] in SOURCE_EXTS:
                    yield os.path.join(root, f)


def rename_sources(repo, ren, dry_run=False):
    """Returns ({path: [old names seen in code]}, changed paths)."""
    r = SourceRenamer(ren)
    seen_by_file, changed = {}, []
    for path in source_files(repo):
        data = read(path)
        new, seen = r.rename(data)
        if seen:
            seen_by_file[os.path.relpath(path, repo)] = sorted(s.decode() for s in seen)
        if new != data:
            changed.append(os.path.relpath(path, repo))
            if not dry_run:
                write(path, new)
    return seen_by_file, changed


def references(repo, names):
    """{path: sorted names} for code (not comment/string) references to `names`."""
    names = [n for n in names if IDENT.match(n.encode())]
    if not names:
        return {}
    tok = token_re(names)
    out = {}
    for path in source_files(repo):
        data = read(path)
        if not tok.search(data):
            continue
        hits = set()
        for kind, s, e in segments(data):
            if kind == "code":
                hits.update(m.group(0).decode() for m in tok.finditer(data, s, e))
        if hits:
            out[os.path.relpath(path, repo)] = sorted(hits)
    return out


# ----------------------------------------------------------------------------
# alias table


def update_aliases(path, ren):
    """Add old<TAB>new lines and re-point aliases at renamed names. Returns (added, repointed)."""
    data = read(path) if os.path.isfile(path) else b"# old placeholder name<TAB>current symbols.txt name\n"
    eol = b"\r\n" if b"\r\n" in data else b"\n"
    lines = data.splitlines(keepends=True)
    keys = set()
    repointed = 0
    for i, line in enumerate(lines):
        body = line.rstrip(b"\r\n")
        if body.startswith(b"#") or b"\t" not in body:
            continue
        parts = body.split(b"\t")
        keys.add(parts[0].decode("latin-1"))
        target = parts[1].decode("latin-1")
        if target in ren and ren[target] != parts[0].decode("latin-1"):
            parts[1] = ren[target].encode("latin-1")
            lines[i] = b"\t".join(parts) + line[len(body):]
            repointed += 1
    added = []
    for old, new in ren.items():
        if old not in keys:
            added.append(old.encode("latin-1") + b"\t" + new.encode("latin-1") + eol)
    if lines and not lines[-1].endswith((b"\n", b"\r")):
        lines[-1] += eol
    out = b"".join(lines + added)
    if out != data:
        write(path, out)
    return len(added), repointed


# ----------------------------------------------------------------------------
# dtk


def dtk_command(repo, dtk=None):
    """The dtk command line prefix. A .py `dtk` runs under this Python (tests use a fake)."""
    if dtk:
        return [sys.executable, os.path.abspath(dtk)] if dtk.endswith(".py") else [os.path.abspath(dtk)]
    for name in ("dtk.exe", "dtk"):
        p = os.path.join("build", "tools", name)
        if os.path.isfile(os.path.join(repo, p)):
            return [p]
    raise SystemExit("rename_symbols: build/tools/dtk not found; run configure.py and ninja once first")


def run_split(repo, max_passes=6, dtk=None):
    """Run `dtk dol split` until symbols.txt stops changing. Returns (ok, passes, log)."""
    if not os.path.isfile(os.path.join(repo, "build", "GV4E69", "orig", "main_sections.dol")):
        raise SystemExit("rename_symbols: build/GV4E69/orig/main_sections.dol missing; run ninja once first")
    cmd = dtk_command(repo, dtk)
    sym = os.path.join(repo, SYMBOLS)
    log = ""
    for n in range(1, max_passes + 1):
        before = read(sym)
        p = subprocess.run(cmd + ["dol", "split", CONFIG, os.path.join("build", "GV4E69")],
                           cwd=repo, capture_output=True, text=True, encoding="utf-8", errors="replace")
        log = p.stdout + p.stderr
        if p.returncode != 0:
            return False, n, log
        if read(sym) == before:
            return True, n, log
    return False, max_passes, log + f"\nsymbols.txt still changing after {max_passes} passes"


def diff_symbols(before, after):
    """Compare two symbols.txt by (section, address).

    Returns (renames {old: new}, added [(name, sec, addr, attrs)], removed [...],
    changed [(name, old attrs, new attrs)], ambiguous [(sec, addr, olds, news)]).
    """
    def by_addr(data):
        d = {}
        for name, sec, addr, attrs in parse_symbols(data):
            d.setdefault((sec, addr), []).append((name, attrs))
        return d
    a, b = by_addr(before), by_addr(after)
    renames, added, removed, changed, ambiguous = {}, [], [], [], []
    for key in sorted(set(a) | set(b), key=lambda k: (k[1], k[0])):
        pa, pb = dict(a.get(key, [])), dict(b.get(key, []))
        gone = [n for n in pa if n not in pb]
        new = [n for n in pb if n not in pa]
        for n in pa:
            if n in pb and pa[n] != pb[n]:
                changed.append((n, pa[n], pb[n]))
        if len(gone) == 1 and len(new) == 1:
            pairs = [(gone[0], new[0])]
        else:
            # Several names at one address (a function and a label dtk adds at its
            # start): pair each vanished name with the one new name of its type.
            pairs = []
            for g in gone:
                same = [n for n in new if sym_type(pb[n]) == sym_type(pa[g])]
                if len(same) == 1 and same[0] not in [p[1] for p in pairs]:
                    pairs.append((g, same[0]))
        for g, n in pairs:
            renames[g] = n
            if pa[g] != pb[n]:
                changed.append((n, pa[g], pb[n]))
        gone = [g for g in gone if g not in renames]
        new = [n for n in new if n not in [p[1] for p in pairs]]
        if gone and new:
            ambiguous.append((key[0], key[1], gone, new))
        else:
            removed += [(n, key[0], key[1], pa[n]) for n in gone]
            added += [(n, key[0], key[1], pb[n]) for n in new]
    return renames, added, removed, changed, ambiguous


def sym_type(attrs):
    m = re.search(r"type:(\w+)", attrs)
    return m.group(1) if m else ""


# ----------------------------------------------------------------------------
# driver


def propagate(repo, ren, dry_run, log):
    """Sources, config.yml and aliases for an already-renamed symbols.txt."""
    src_ren, skipped = source_renames(ren)
    seen, changed = rename_sources(repo, src_ren, dry_run)
    log(f"sources: {len(changed)} files changed")
    blocked = references(repo, [o for o in skipped])
    for old, new in skipped.items():
        log(f"not a C identifier, kept out of the sources: {old} -> {new}")
    n, kept = config_renames(os.path.join(repo, CONFIG), ren, dry_run)
    if n:
        log(f"config.yml: {n} relocation targets renamed")
    if kept:
        blocked[CONFIG.replace(os.sep, "/")] = kept
    if not dry_run:
        added, repointed = update_aliases(os.path.join(repo, ALIASES), ren)
        log(f"aliases: {added} added, {repointed} re-pointed")
    return blocked, changed


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("tsv", nargs="*", help="old<TAB>new rename files")
    ap.add_argument("--pair", action="append", default=[], metavar="OLD=NEW")
    ap.add_argument("--from-dtk", action="store_true",
                    help="run dtk dol split to a fixpoint and propagate every rename it makes")
    ap.add_argument("--dry-run", action="store_true", help="report only; leave every file as it was")
    ap.add_argument("--report", help="write applied renames as old<TAB>new<TAB>origin")
    ap.add_argument("--repo", default=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
    ap.add_argument("--max-passes", type=int, default=6)
    ap.add_argument("--dtk", help="dtk executable (default build/tools/dtk[.exe])")
    ap.add_argument("-q", "--quiet", action="store_true")
    args = ap.parse_args(argv)
    repo = args.repo
    log = (lambda *a: None) if args.quiet else print

    pairs = []
    for t in args.tsv:
        pairs += read_pairs(t)
    for p in args.pair:
        if "=" not in p:
            ap.error(f"--pair wants OLD=NEW, got {p}")
        pairs.append(tuple(p.split("=", 1)))
    explicit = check_pairs(pairs)
    if not explicit and not args.from_dtk:
        ap.error("nothing to rename: give a TSV, --pair or --from-dtk")

    sym = os.path.join(repo, SYMBOLS)
    start = read(sym)
    origin = {}
    if args.from_dtk:
        done, missing = rename_symbols_txt(sym, explicit)
        ok, passes, dlog = run_split(repo, args.max_passes, args.dtk)
        after = read(sym)
        if not ok:
            write(sym, start)
            tail = [line for line in dlog.splitlines() if line.strip()][-6:]
            print("rename_symbols: dtk split failed; symbols.txt restored, nothing else touched", file=sys.stderr)
            print("\n".join(tail), file=sys.stderr)
            return 2
        ren, added, removed, changed, ambiguous = diff_symbols(start, after)
        for old in ren:
            origin[old] = "explicit" if explicit.get(old) == ren[old] else "dtk"
        for old, new in explicit.items():
            if old in missing and new not in [n for n, *_ in parse_symbols(after)]:
                log(f"not in symbols.txt: {old}")
        log(f"dtk split: fixpoint after {passes} pass(es); {len(ren)} renames "
            f"({sum(1 for v in origin.values() if v == 'dtk')} by dtk), "
            f"{len(added)} added, {len(removed)} removed, {len(changed)} attribute changes")
        for name, sec, addr, attrs in added:
            log(f"  added   {name} {sec}:0x{addr:08X} {attrs}")
        for name, sec, addr, attrs in removed:
            log(f"  removed {name} {sec}:0x{addr:08X} {attrs}")
        for sec, addr, olds, news in ambiguous:
            log(f"  AMBIGUOUS {sec}:0x{addr:08X} {olds} -> {news} (not propagated)")
        for name, a, b in changed:
            log(f"  attrs   {name}: {a} -> {b}")
        if args.dry_run:
            write(sym, start)
    else:
        ren = explicit
        if not args.dry_run:
            done, missing = rename_symbols_txt(sym, ren)
        else:
            names = {n for n, *_ in parse_symbols(start)}
            done, missing = [o for o in ren if o in names], [o for o in ren if o not in names]
        for o in ren:
            origin[o] = "explicit"
        log(f"symbols.txt: {len(done)} renamed")
        for o in missing:
            log(f"not in symbols.txt: {o}")

    for old, new in ren.items():
        log(f"  {origin.get(old, 'explicit'):8s} {old} -> {new}")
    blocked, _ = propagate(repo, ren, args.dry_run, log)
    if args.report:
        with open(args.report, "w", encoding="utf-8", newline="\n") as f:
            for old, new in ren.items():
                f.write(f"{old}\t{new}\t{origin.get(old, 'explicit')}\n")
    if blocked:
        for path, names in blocked.items():
            print(f"rename_symbols: {path} still references {', '.join(names)}, whose new name is not a C identifier",
                  file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
