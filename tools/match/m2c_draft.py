"""First-draft C for one function, from dtk's split asm, using m2c (external).

    python tools/match/m2c_draft.py <unit-without-ext> <function> [extra m2c args]
    python tools/match/m2c_draft.py animation/choosers/tu_80271F14 fn_80272164

The draft is a starting point, not a match: m2c guesses types and invents
temporaries. Field names come out as unk<offset>, which map to our m<offset>.

m2c (github.com/matt-kempster/m2c) is not vendored. It lives in its own venv;
point M2C_PY at that venv's python (default below). Target ppc-gcc-c++ fits
ProDG's g++ 2.95 output best.
"""
import os
import subprocess
import sys
from pathlib import Path

DEFAULT_M2C_PY = r"C:\Users\Patrick Taylor\tools-ext\m2c-venv\Scripts\python.exe"


def find_asm(unit: str, fn: str) -> Path:
    asm_dir = Path("build/GV4E69/asm")
    p = asm_dir / f"{unit}.s"
    if p.exists():
        return p
    marker = f".fn {fn},"
    hits = [f for f in asm_dir.rglob("*.s") if marker in f.read_text(errors="replace")]
    if not hits:
        raise SystemExit(f"{fn} not found under {asm_dir}")
    return max(hits, key=lambda f: f.stat().st_mtime)


def main() -> None:
    if len(sys.argv) < 3:
        raise SystemExit(__doc__)
    unit, fn, extra = sys.argv[1], sys.argv[2], sys.argv[3:]
    m2c_py = os.environ.get("M2C_PY", DEFAULT_M2C_PY)
    asm = find_asm(unit, fn)
    text = asm.read_text(errors="replace")
    if ".feoverlay" in text or ".dboverlay" in text:
        # m2c only reads code from .text: present the overlay section as .text.
        import tempfile
        tmp = Path(tempfile.gettempdir()) / f"m2c_{asm.stem}.s"
        tmp.write_text(text.replace(".feoverlay", ".text").replace(".dboverlay", ".text"))
        asm = tmp
    cmd = [m2c_py, "-I", "-m", "m2c.main", "--target", "ppc-gcc-c++", str(asm), "--function", fn, *extra]
    sys.exit(subprocess.call(cmd))


if __name__ == "__main__":
    main()
