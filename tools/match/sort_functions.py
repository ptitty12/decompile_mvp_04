"""Reorder a unit's function definitions into .text address order.

    python tools/match/sort_functions.py src/game/tu_80044C10.cpp [--check]

tools/scout/rename.py pairs compiled functions with symbols.txt by object
order, so the source must define functions in address order. This moves each
top-level function definition whose name contains fn_<ADDR> (free function or
method, e.g. `int Unk::fn_8001B190(...)`) to its address position.

A top-level block ends at a line that is exactly `}` (function bodies);
`};` (class/struct definitions) does not end a function block. Non-function
blocks before the first function stay in front; non-function blocks between
functions travel with the function after them. Functions without an address
in their name keep their relative order after the addressed ones that precede
them. --check only reports whether the file is already sorted.
"""
import re
import sys
from pathlib import Path

DEF = re.compile(r"^[A-Za-z_][^\n=;{}]*\bfn_([0-9A-F]{8})\w*\s*\([^;{]*\)\s*(const\s*)?\{", re.M)


def split_blocks(text):
    blocks, cur = [], []
    for line in text.split("\n"):
        cur.append(line)
        if line == "}":
            blocks.append("\n".join(cur).strip("\n"))
            cur = []
    tail = "\n".join(cur).strip("\n")
    return blocks, tail


def main():
    path = Path(sys.argv[1])
    check = "--check" in sys.argv[2:]
    text = path.read_text()
    blocks, tail = split_blocks(text)
    prefix, items, pending, seen = [], [], [], False
    last_addr = 0
    for b in blocks:
        m = DEF.search(b)
        if m:
            seen = True
            addr = int(m.group(1), 16)
            last_addr = addr
            items.append((addr, len(items), "\n\n".join(pending + [b])))
            pending = []
        elif seen and re.search(r"\)\s*(const\s*)?\{", b):
            # a function without an address keeps its place after the last addressed one
            items.append((last_addr, len(items), "\n\n".join(pending + [b])))
            pending = []
        else:
            (pending if seen else prefix).append(b)
    order = sorted(items, key=lambda t: (t[0], t[1]))
    if check:
        ok = [i[1] for i in order] == list(range(len(items)))
        print(f"{path}: {'sorted' if ok else 'NOT sorted'} ({len(items)} functions)")
        sys.exit(0 if ok else 1)
    out = "\n\n".join(prefix + [t[2] for t in order] + pending)
    if tail:
        out += "\n\n" + tail
    path.write_text(out.strip("\n") + "\n")
    print(f"{path}: {len(items)} functions in address order")


if __name__ == "__main__":
    main()
