#!/usr/bin/env python3
"""Rebuild one unit's object with ninja and diff it function-by-function against
dtk's target object.

Usage (from the repo root):
  python tools/match/diff_unit.py animation/choosers/playeridchooser            # summary
  python tools/match/diff_unit.py animation/choosers/playeridchooser fn_8027    # side-by-side for matching names

Needs `ninja` on PATH and binutils (`ninja tools` downloads them to build/binutils).
Relocated immediates and branch targets are masked, so a MATCH here means the
instructions match; the verifier/objdiff remain the source of truth.
"""
import os
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
VERSION = "GV4E69"


def main() -> None:
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    unit = sys.argv[1].replace("\\", "/").removesuffix(".cpp").removesuffix(".c")
    exe = ".exe" if os.name == "nt" else ""
    objdump = ROOT / "build" / "binutils" / f"powerpc-eabi-objdump{exe}"
    if not objdump.is_file():
        subprocess.run(["ninja", "tools"], cwd=ROOT)
    base = Path("build") / VERSION / "src" / f"{unit}.o"
    target = Path("build") / VERSION / "obj" / f"{unit}.o"
    r = subprocess.run(["ninja", str(base)], cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        print(r.stdout[-3000:])
        sys.exit("compile failed")
    subprocess.run([sys.executable, str(Path(__file__).with_name("cmp_objects.py")), str(objdump),
                    str(ROOT / base), str(ROOT / target), *sys.argv[2:]])


if __name__ == "__main__":
    main()
