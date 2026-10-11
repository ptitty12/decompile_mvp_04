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
            if l.strip() and not l.strip().startswith("#")
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


def load_report(path: Path):
    r = json.loads(path.read_text(encoding="utf-8"))
    units, funcs = {}, {}
    for u in r.get("units", []):
        m = u.get("measures", {})
        # Units without code (dtk's data-only auto splits) are skipped: their
        # matched_code is trivially 100% and they vanish when a unit claims them.
        if int(m.get("total_code") or 0) == 0:
            continue
        units[u["name"]] = (float(m.get("fuzzy_match_percent") or 0), float(m.get("matched_code_percent") or 0))
        for f in u.get("functions", []):
            # (percent, address within the unit, size): address+size identify a
            # function across renames (e.g. a mangled name changing when a
            # parameter type is corrected).
            funcs[(u["name"], f["name"])] = (float(f.get("fuzzy_match_percent") or 0),
                                             f.get("address"), f.get("size"))
    return units, funcs


def check_regressions(current: Path, baseline: Path) -> None:
    bu, bf = load_report(baseline)
    cu, cf = load_report(current)
    regs = []
    for k, (fz, mc) in bu.items():
        nfz, nmc = cu.get(k, (0.0, 0.0))
        if nmc + 1e-9 < mc:
            regs.append(f"unit {k}: matched code {mc:.2f}% -> {nmc:.2f}%")
        elif nfz + 1e-9 < fz:
            regs.append(f"unit {k}: fuzzy {fz:.2f}% -> {nfz:.2f}%")
    by_addr = {(unit, a, s): (name, p) for (unit, name), (p, a, s) in cf.items() if a is not None}
    renamed = []
    for k, (v, addr, size) in bf.items():
        if k in cf:
            nv = cf[k][0]
        elif addr is not None and (k[0], addr, size) in by_addr:
            new_name, nv = by_addr[(k[0], addr, size)]
            renamed.append(f"{k[1]} -> {new_name}")
        else:
            nv = 0.0
        if nv + 1e-9 < v:
            regs.append(f"function {k[1]} ({k[0]}): {v:.2f}% -> {nv:.2f}%")
    for line in renamed[:50]:
        print(f"renamed (same unit, address and size): {line}")
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
