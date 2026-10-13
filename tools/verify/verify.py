#!/usr/bin/env python3
"""GV4E69 project verifier. Owner-controlled: see CLAUDE.md and docs/DECISIONS.md.

Agents must not modify anything under tools/verify/ (enforced by
.claude/settings.json and checked by CI via protected.sha256).

Checks (any failure exits non-zero):
  1. integrity   SHA-256 of every protected file == tools/verify/protected.sha256
  2. build       `python configure.py && ninja` succeeds; build/GV4E69/main.dol has
                 the retail SHA-1 pinned in this file AND listed in build.sha1
  3. hard rules  no inline asm / naked functions / .incbin in src/ or include/;
                 every `#pragma` line must appear in tools/verify/pragma_allowlist.txt
  4. regressions objdiff report vs a baseline report: no unit or function match
                 percentage may decrease (only with --baseline or --baseline-ref)

Usage:
  python tools/verify/verify.py                       # 1-3
  python tools/verify/verify.py --baseline-ref main   # 1-4, baseline built from a git ref
  python tools/verify/verify.py --baseline FILE.json  # 1-4, baseline report given
  python tools/verify/verify.py --integrity-only      # 1 (no game data needed; for CI)
  python tools/verify/verify.py --print-protected     # print current hashes (OWNER use)
"""
import argparse
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
from collections import defaultdict, namedtuple
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
VERSION = "GV4E69"
# Retail main.dol, MVP Baseball 2005 (USA, rev 0). Pinned here on purpose:
# editing config/GV4E69/build.sha1 alone cannot make a wrong build pass.
RETAIL_SHA1 = "da6becdbea614d03c4b5eae9f8a0fb08e0a184dd"
VERIFY_DIR = ROOT / "tools" / "verify"
PROTECTED_LIST = VERIFY_DIR / "protected.sha256"
PRAGMA_ALLOWLIST = VERIFY_DIR / "pragma_allowlist.txt"
SOURCE_DIRS = [ROOT / "src", ROOT / "include"]
SOURCE_EXTS = {".c", ".cpp", ".cc", ".cp", ".h", ".hpp", ".inc", ".inl", ".s"}
BANNED = [
    (re.compile(r"\b__asm__\b|\b__asm\b|\basm\s*[({]|\basm\s+(volatile\s+)?\w"), "inline assembly"),
    (re.compile(r"\bnaked\b"), "naked function"),
    (re.compile(r"\.incbin\b|\bINCBIN\b"), "binary inclusion"),
]


def fail(msg: str) -> None:
    print(f"VERIFY FAIL: {msg}")
    sys.exit(1)


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk.replace(b"\r\n", b"\n"))  # line-ending neutral
    return h.hexdigest()


def read_protected():
    entries = []
    for line in PROTECTED_LIST.read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if line and not line.startswith("#"):
            digest, rel = line.split(None, 1)
            entries.append((digest, rel.strip()))
    return entries


def check_integrity() -> None:
    if not PROTECTED_LIST.is_file():
        fail(f"missing {PROTECTED_LIST.relative_to(ROOT)}")
    bad = []
    for digest, rel in read_protected():
        p = ROOT / rel
        if not p.is_file():
            bad.append(f"{rel}: missing")
        elif sha256(p) != digest:
            bad.append(f"{rel}: hash changed")
    if bad:
        fail("protected files changed without owner approval:\n  " + "\n  ".join(bad))
    print(f"integrity: {len(read_protected())} protected files OK")


def check_hard_rules() -> None:
    allowed = set()
    if PRAGMA_ALLOWLIST.is_file():
        allowed = {
            l.strip()
            for l in PRAGMA_ALLOWLIST.read_text(encoding="utf-8").splitlines()
            if l.strip() and (not l.strip().startswith("#") or re.match(r"#pragma\b", l.strip()))
        }
    problems = []
    n_files = 0
    for d in SOURCE_DIRS:
        if not d.is_dir():
            continue
        for p in sorted(d.rglob("*")):
            if p.suffix.lower() not in SOURCE_EXTS or not p.is_file():
                continue
            n_files += 1
            rel = p.relative_to(ROOT).as_posix()
            if p.suffix.lower() == ".s":
                problems.append(f"{rel}: assembly source file")
                continue
            text = p.read_text(encoding="utf-8", errors="replace")
            for i, line in enumerate(text.splitlines(), 1):
                code = line.split("//", 1)[0]
                for rx, what in BANNED:
                    if rx.search(code):
                        problems.append(f"{rel}:{i}: {what}: {line.strip()[:80]}")
                if code.lstrip().startswith("#pragma") and code.strip() not in allowed:
                    problems.append(f"{rel}:{i}: #pragma not in allowlist: {line.strip()[:80]}")
    if problems:
        fail("hard-rule violations:\n  " + "\n  ".join(problems))
    print(f"hard rules: {n_files} source files OK")


def run(cmd, cwd: Path) -> None:
    print("+", " ".join(str(c) for c in cmd), flush=True)
    r = subprocess.run(cmd, cwd=cwd)
    if r.returncode:
        fail(f"command failed ({r.returncode}): {' '.join(str(c) for c in cmd)}")


def build(root: Path, extra_args=()) -> Path:
    run([sys.executable, "configure.py", *extra_args], root)
    run(["ninja"], root)
    return root / "build" / VERSION


def check_build() -> Path:
    out = build(ROOT)
    dol = out / "main.dol"
    if not (out / "ok").is_file():
        fail("dtk hash check did not pass (build/GV4E69/ok missing)")
    digest = hashlib.sha1(dol.read_bytes()).hexdigest()
    if digest != RETAIL_SHA1:
        fail(f"main.dol SHA-1 {digest} != retail {RETAIL_SHA1}")
    listed = (ROOT / "config" / VERSION / "build.sha1").read_text().split()[0].lower()
    if listed != RETAIL_SHA1:
        fail(f"config/{VERSION}/build.sha1 lists {listed}, expected retail {RETAIL_SHA1}")
    print(f"build: main.dol == retail ({RETAIL_SHA1})")
    return out / "report.json"


def remove_worktree(wt: Path) -> None:
    subprocess.run(["git", "worktree", "remove", "--force", str(wt)], cwd=ROOT,
                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    shutil.rmtree(wt, ignore_errors=True)
    subprocess.run(["git", "worktree", "prune"], cwd=ROOT)


def baseline_from_ref(ref: str) -> Path:
    """Build `ref` in a git worktree under build/ (reusing this checkout's tools) and return its report.

    The worktree lives in build/_baseline/wt so tool paths can be passed as short
    relative paths (the template's ninja rules do not quote paths with spaces)."""
    wt = ROOT / "build" / "_baseline" / "wt"
    remove_worktree(wt)
    wt.parent.mkdir(parents=True, exist_ok=True)
    run(["git", "worktree", "add", "--detach", str(wt), ref], ROOT)
    try:
        orig_src = ROOT / "orig" / VERSION
        (wt / "orig").mkdir(exist_ok=True)
        shutil.copytree(orig_src, wt / "orig" / VERSION, dirs_exist_ok=True,
                        ignore=shutil.ignore_patterns("*.iso", "*.ciso", "*.rvz", "*.gcm", "*.wbfs", "*.wia", "*.gcz", "*.nfs", "*.tgc"))
        elf = ROOT / "build" / VERSION / "orig" / "mvp.elf"
        if elf.is_file() and not (wt / "orig" / VERSION / "mvp.elf").is_file():
            shutil.copyfile(elf, wt / "orig" / VERSION / "mvp.elf")
        tools = ROOT / "build"
        exe = ".exe" if os.name == "nt" else ""
        rel = lambda p: os.path.relpath(p, wt)
        args = ["--compilers", rel(tools / "compilers"), "--dtk", rel(tools / "tools" / f"dtk{exe}"),
                "--objdiff", rel(tools / "tools" / f"objdiff-cli{exe}")]
        if (tools / "binutils").is_dir():
            args += ["--binutils", rel(tools / "binutils")]
        out = build(wt, args)
        dest = ROOT / "build" / VERSION / "baseline_ref.json"
        shutil.copyfile(out / "report.json", dest)
        return dest
    finally:
        remove_worktree(wt)


ReportUnit = namedtuple("ReportUnit", "fuzzy matched total_code matched_code")
ReportFunction = namedtuple("ReportFunction", "percent address size virtual_address")


def load_report(path: Path):
    r = json.loads(path.read_text(encoding="utf-8"))
    units, funcs = {}, {}
    for u in r.get("units", []):
        m = u.get("measures", {})
        # Units without code (dtk's data-only auto splits) are skipped: their
        # matched_code is trivially 100% and they vanish when a unit claims them.
        if int(m.get("total_code") or 0) == 0:
            continue
        if u["name"] in units:
            fail(f"duplicate unit in {path}: {u['name']}")
        units[u["name"]] = ReportUnit(
            float(m.get("fuzzy_match_percent") or 0),
            float(m.get("matched_code_percent") or 0),
            int(m.get("total_code") or 0), int(m.get("matched_code") or 0))
        for f in u.get("functions", []):
            k = (u["name"], f["name"])
            if k in funcs:
                fail(f"duplicate function in {path}: {k}")
            # Objdiff address is section-relative, so it cannot identify a
            # cross-unit move. Size is the target symbol size, not source size.
            address = f.get("address")
            size = f.get("size")
            virtual = (f.get("metadata") or {}).get("virtual_address")
            funcs[k] = ReportFunction(
                float(f.get("fuzzy_match_percent") or 0),
                int(address) if address is not None else None,
                int(size) if size is not None else None,
                int(virtual) if virtual is not None else None)
    return units, funcs


def pair_functions(bf, cf):
    """Pair identities one-to-one; never choose an ambiguous or better score."""
    bn, cn, ba, ca = (defaultdict(list) for _ in range(4))
    for funcs, names, addresses in ((bf, bn, ba), (cf, cn, ca)):
        for k, f in funcs.items():
            names[k[1]].append(k)
            if f.address is not None and f.size is not None and f.size > 0:
                addresses[(k[0], f.address, f.size)].append(k)

    pairs = {k: k for k in bf if k in cf}
    used = set(pairs.values())

    def compatible(old, new):
        return (old.size is not None and old.size > 0 and old.size == new.size
                and (old.virtual_address is None or new.virtual_address is None
                     or old.virtual_address == new.virtual_address))

    # Resolve unique names before relative-offset renames: splitting an object
    # can put a different function at a moved function's old offset.
    for k, f in bf.items():
        candidates = cn[k[1]]
        if k not in pairs and len(bn[k[1]]) == 1 and len(candidates) == 1:
            nk = candidates[0]
            old_module = k[0].split("/", 1)[0]
            new_module = nk[0].split("/", 1)[0]
            if nk not in used and old_module == new_module and compatible(f, cf[nk]):
                pairs[k] = nk
                used.add(nk)

    for k, f in bf.items():
        slot = (k[0], f.address, f.size)
        candidates = ca[slot]
        if (k not in pairs and not cn[k[1]] and len(ba[slot]) == 1
                and len(candidates) == 1):
            nk = candidates[0]
            if nk not in used and not bn[nk[1]] and compatible(f, cf[nk]):
                pairs[k] = nk
                used.add(nk)
    return pairs


def cohort_measures(keys, funcs, weights):
    total = sum(weights)
    fuzzy = sum(funcs[k].percent * size for k, size in zip(keys, weights)) / total
    matched = 100.0 * sum(size for k, size in zip(keys, weights)
                          if funcs[k].percent == 100.0) / total
    return fuzzy, matched


def check_regressions(current: Path, baseline: Path) -> None:
    bu, bf = load_report(baseline)
    cu, cf = load_report(current)
    pairs = pair_functions(bf, cf)
    moved = [(k, nk) for k, nk in pairs.items() if k[0] != nk[0]]
    affected = {unit for k, nk in moved for unit in (k[0], nk[0])}
    bkeys, ckeys = defaultdict(list), defaultdict(list)
    for k in bf:
        bkeys[k[0]].append(k)
    for k in cf:
        ckeys[k[0]].append(k)
    reverse = {nk: k for k, nk in pairs.items()}

    def covered(unit, units, funcs, keys):
        entries = [funcs[k] for k in keys[unit]]
        return (bool(entries) and all(f.size is not None and f.size > 0 for f in entries)
                and sum(f.size for f in entries) == units[unit].total_code
                and sum(f.size for f in entries if f.percent == 100.0)
                == units[unit].matched_code)

    regs = []
    for k, unit in bu.items():
        fz, mc = unit.fuzzy, unit.matched
        nfz, nmc = cu[k][:2] if k in cu else (0.0, 0.0)
        if k in affected:
            keys = bkeys[k]
            destinations = {pairs[fk][0] for fk in keys if fk in pairs}
            if k in cu:
                destinations.add(k)
            # Reweight only a fully accounted-for redistribution of report
            # functions. Incomplete/ambiguous identities or changed target sizes
            # must not turn a unit-level regression into a pass.
            safe = (covered(k, bu, bf, bkeys)
                    and all(fk in pairs and bf[fk].size == cf[pairs[fk]].size
                            for fk in keys)
                    and all(covered(dest, cu, cf, ckeys)
                            and all(nk in reverse for nk in ckeys[dest])
                            for dest in destinations))
            if not safe:
                regs.append(f"unit {k}: cannot safely compare redistributed functions")
            else:
                weights = [bf[fk].size for fk in keys]
                # Compare the SAME baseline cohort with the SAME target sizes.
                # Recompute both sides to avoid objdiff float32 rounding noise.
                fz, mc = cohort_measures(keys, bf, weights)
                nfz, nmc = cohort_measures([pairs[fk] for fk in keys], cf, weights)
        if nmc + 1e-9 < mc:
            regs.append(f"unit {k}: matched code {mc:.2f}% -> {nmc:.2f}%")
        elif nfz + 1e-9 < fz:
            regs.append(f"unit {k}: fuzzy {fz:.2f}% -> {nfz:.2f}%")
    renamed = []
    for k, f in bf.items():
        nk = pairs.get(k)
        nv = cf[nk].percent if nk is not None else 0.0
        if nk is not None and k[1] != nk[1]:
            renamed.append(f"{k[1]} -> {nk[1]}")
        if nv + 1e-9 < f.percent:
            regs.append(f"function {k[1]} ({k[0]}): {f.percent:.2f}% -> {nv:.2f}%")
    for line in renamed[:50]:
        print(f"renamed (same unit, address and size): {line}")
    for k, nk in moved[:50]:
        print(f"moved (unique name and same size): {k[1]} ({k[0]} -> {nk[0]})")
    if regs:
        fail(f"{len(regs)} match regression(s) vs baseline:\n  " + "\n  ".join(regs[:200]))
    matched = sum(1 for v in cf.values() if v[0] >= 100.0)
    print(f"regressions: none ({matched} functions at 100%, baseline had {sum(1 for v in bf.values() if v[0] >= 100.0)})")


def main() -> None:
    ap = argparse.ArgumentParser()
    g = ap.add_mutually_exclusive_group()
    g.add_argument("--baseline", type=Path)
    g.add_argument("--baseline-ref")
    ap.add_argument("--integrity-only", action="store_true")
    ap.add_argument("--print-protected", action="store_true")
    args = ap.parse_args()

    if args.print_protected:
        for _, rel in read_protected():
            p = ROOT / rel
            print(f"{sha256(p) if p.is_file() else 'MISSING':64}  {rel}")
        return
    check_integrity()
    if args.integrity_only:
        print("VERIFY PASS (integrity only)")
        return
    check_hard_rules()
    # Build the current tree first: it downloads the tools the baseline build reuses.
    report = check_build()
    baseline = args.baseline
    if args.baseline_ref:
        baseline = baseline_from_ref(args.baseline_ref)
    if baseline is not None:
        check_regressions(report, baseline)
    print("VERIFY PASS")


if __name__ == "__main__":
    main()
