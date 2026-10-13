"""Try bounded store-order variants without editing the real source.

Example: python tools/match/store_orders.py fe/tu_80488CDC fn_8048A2AC --line 320 --count 4

Select 2-6 adjacent, single-line assignments to distinct fields of one pointer.
Only constants and bare symbol RHS values are accepted. Source/header semantics
still need review (e.g. volatile fields, macros, unions); a compiler score is a
search lead, not verification. Scratch sources stay under build/store_orders.
Apply a candidate manually, then rebuild, check_literals and run the verifier.
"""
import argparse
import itertools
import math
import re
import subprocess
import sys
import tempfile
from pathlib import Path

from cxx2c import base_name, definition_body
from score_variants import ROOT

NUMBER = r"-?(?:0[xX][\da-fA-F]+[uUlL]*|\d+[uUlL]*|(?:\d+\.\d*|\.\d+|\d+)(?:[eE][+-]?\d+)?[fFlL]?)"
STORE = re.compile(r"\s*(\w+)->(\w+)\s*=\s*(?:[A-Za-z_]\w*|" + NUMBER + r")\s*;\s*")


def store_span(text, function, line, count):
    if not 2 <= count <= 6:
        raise ValueError("--count must be between 2 and 6")
    lines = text.splitlines(keepends=True)
    if line < 1 or line + count - 1 > len(lines):
        raise ValueError("selected lines are outside the source")
    rows = lines[line - 1:line - 1 + count]
    stores = [STORE.fullmatch(row) for row in rows]
    if not all(stores):
        raise ValueError("select only single-line pointer-field stores of constants or bare symbols")
    if len({m[1] for m in stores}) != 1 or len({m[2] for m in stores}) != count:
        raise ValueError("stores must use one pointer and distinct fields")
    start = sum(map(len, lines[:line - 1]))
    end = start + sum(map(len, rows))
    body = definition_body(text, function) or definition_body(text, base_name(function))
    if body is None or not (body[0] < start < end <= body[1]):
        raise ValueError("selected stores are not inside the requested function")
    return start, end, rows


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("unit")
    ap.add_argument("function")
    ap.add_argument("--line", type=int, required=True, help="first selected source line (1-based)")
    ap.add_argument("--count", type=int, required=True)
    ap.add_argument("--source", type=Path, help="use a scratch source instead of src/<unit>")
    ap.add_argument("--limit", type=int, default=120, help="maximum variants (default 120, maximum 720)")
    a = ap.parse_args()
    if not 1 <= a.limit <= 720:
        ap.error("--limit must be between 1 and 720")
    unit = a.unit.replace("\\", "/").removeprefix("src/").removesuffix(".cpp").removesuffix(".c")
    src = a.source or next((ROOT / "src" / f"{unit}{ext}" for ext in (".cpp", ".c")
                            if (ROOT / "src" / f"{unit}{ext}").is_file()), None)
    if src is None or not src.is_file():
        ap.error("source file not found")
    with src.open(encoding="utf-8", newline="") as f:
        text = f.read()
    try:
        start, end, rows = store_span(text, a.function, a.line, a.count)
    except ValueError as e:
        ap.error(str(e))
    parent = ROOT / "build" / "store_orders"
    parent.mkdir(parents=True, exist_ok=True)
    out = Path(tempfile.mkdtemp(prefix="orders_", dir=parent))
    for i, order in enumerate(itertools.islice(itertools.permutations(rows), a.limit)):
        (out / f"order_{i:03d}{src.suffix}").write_bytes(
            (text[:start] + "".join(order) + text[end:]).encode("utf-8"))
    print(f"Scoring {min(math.factorial(a.count), a.limit)}/{math.factorial(a.count)} orders in {out}", flush=True)
    result = subprocess.run([sys.executable, str(ROOT / "tools/match/score_variants.py"),
                             unit, a.function, str(out)], cwd=ROOT)
    return result.returncode


if __name__ == "__main__":
    sys.exit(main())
