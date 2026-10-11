#!/usr/bin/env python3
"""Create a ready-to-build worktree for one more matching agent.

Copies what a fresh worktree lacks, all gitignored and never committed, the way
tools/verify/verify.py prepares its baseline builds:
  - orig/GV4E69/: the disc's extracted files except disc images, and the
    extracted mvp.elf from this checkout's build/GV4E69/orig/;
  - build/compilers, build/tools, build/binutils: the toolchain, so configure.py
    doesn't download it again.

Usage: python tools/swarm/provision.py NAME BRANCH [--from REF] [--dry-run]
  e.g. python tools/swarm/provision.py W6 match/W6-unit90
  creates ../decompile_mvp_04-W6 on a new branch from origin/main (default).
"""
import argparse
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
VERSION = "GV4E69"
DISC_IMAGES = {".iso", ".ciso", ".rvz", ".gcm", ".wbfs", ".wia", ".gcz", ".nfs", ".tgc"}
TOOLCHAIN = ("compilers", "tools", "binutils")


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("name")
    ap.add_argument("branch")
    ap.add_argument("--from", dest="ref", default="origin/main")
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()

    wt = ROOT.parent / f"{ROOT.name}-{args.name}"
    if wt.exists():
        sys.exit(f"{wt} already exists")
    elf = ROOT / "build" / VERSION / "orig" / "mvp.elf"
    if not elf.is_file():
        sys.exit(f"{elf} missing: build this checkout once (ninja) first")
    plan = [("worktree", f"git worktree add -b {args.branch} {wt} {args.ref}")]
    for p in sorted((ROOT / "orig" / VERSION).iterdir()):
        if p.is_file() and p.suffix.lower() not in DISC_IMAGES:
            plan.append(("copy", f"{p} -> {wt / 'orig' / VERSION / p.name}"))
    plan.append(("copy", f"{elf} -> {wt / 'orig' / VERSION / 'mvp.elf'}"))
    for d in TOOLCHAIN:
        if (ROOT / "build" / d).is_dir():
            plan.append(("copytree", f"{ROOT / 'build' / d} -> {wt / 'build' / d}"))
    for kind, what in plan:
        print(f"{kind:9} {what}")
    if args.dry_run:
        return

    subprocess.run(["git", "-C", str(ROOT), "fetch", "-q", "origin"], check=True)
    subprocess.run(["git", "-C", str(ROOT), "worktree", "add", "-q", "-b", args.branch, str(wt), args.ref], check=True)
    dst = wt / "orig" / VERSION
    dst.mkdir(parents=True, exist_ok=True)
    for p in (ROOT / "orig" / VERSION).iterdir():
        if p.is_file() and p.suffix.lower() not in DISC_IMAGES:
            shutil.copy2(p, dst / p.name)
    shutil.copy2(elf, dst / "mvp.elf")
    for d in TOOLCHAIN:
        if (ROOT / "build" / d).is_dir():
            shutil.copytree(ROOT / "build" / d, wt / "build" / d)
    print(f"ready: {wt} (branch {args.branch}). Next: python configure.py && ninja")


if __name__ == "__main__":
    main()
