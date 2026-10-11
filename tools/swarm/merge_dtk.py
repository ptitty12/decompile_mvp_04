#!/usr/bin/env python3
"""Git merge driver for dtk's config/GV4E69/symbols.txt and splits.txt.

Requested by the swarm/benchmark session: parallel matchers all edit these
two files, git's line merge conflicts constantly, and a union merge of
splits.txt once scrambled two units' blocks. This driver merges by meaning
instead of by line position:

  symbols  one entry per (section, address, n-th symbol at that address),
           3-way merged field by field: the name, and the `// ...` attributes.
           A side that renamed a symbol and a side that only changed its
           size both win. Output is sorted by section, then address.
  splits   the `Sections:` header, then one block per unit name, 3-way
           merged as whole blocks. Output is the header, then the blocks
           sorted by the start address of their first range.

Per field or block: equal on both sides, or changed on one side only, merges
cleanly. Added on one side is kept; deleted on one side and untouched on the
other is dropped. Changed differently on both sides is a real conflict: it is
written with git's <<<<<<< / ======= / >>>>>>> markers around just that entry,
and the driver exits 1 so git reports the conflict.

Wiring (once per clone; worktrees share it):
  .gitattributes:  config/GV4E69/symbols.txt merge=dtk-symbols
                   config/GV4E69/splits.txt  merge=dtk-splits
  git config merge.dtk-symbols.driver 'python "<repo>/tools/swarm/merge_dtk.py" symbols %O %A %B'
  git config merge.dtk-splits.driver  'python "<repo>/tools/swarm/merge_dtk.py" splits %O %A %B'
  (tools/swarm/install_merge_drivers.py does both config lines.)

Usage (as git calls it): merge_dtk.py {symbols|splits} BASE OURS THEIRS
Writes the result to OURS.
"""
import re
import sys
from pathlib import Path
from typing import Dict, List, Optional, Tuple

SYM = re.compile(r"^(\S+) = (\.?[\w.]+):0x([0-9A-Fa-f]{8});(.*)$")
START = re.compile(r"start:0x([0-9A-Fa-f]+)")
Key = Tuple[str, int, int]


def read(path: str) -> List[str]:
    return Path(path).read_text(encoding="utf-8").replace("\r\n", "\n").split("\n")


def merge3(o: Optional[str], a: Optional[str], b: Optional[str]) -> Tuple[Optional[str], bool]:
    """Returns (value, conflict). None means absent."""
    if a == b:
        return a, False
    if a == o:
        return b, False
    if b == o:
        return a, False
    return None, True


def parse_symbols(lines: List[str]) -> Tuple[Dict[Key, Tuple[str, str]], List[str], List[str]]:
    """(entries, section order, other non-blank lines)."""
    entries: Dict[Key, Tuple[str, str]] = {}
    order: List[str] = []
    other: List[str] = []
    count: Dict[Tuple[str, int], int] = {}
    for line in lines:
        m = SYM.match(line)
        if not m:
            if line.strip():
                other.append(line)
            continue
        name, sec, addr, rest = m.group(1), m.group(2), int(m.group(3), 16), m.group(4)
        if sec not in order:
            order.append(sec)
        n = count.get((sec, addr), 0)
        count[(sec, addr)] = n + 1
        entries[(sec, addr, n)] = (name, rest)
    return entries, order, other


def merge_symbols(o_lines: List[str], a_lines: List[str], b_lines: List[str]) -> Tuple[List[str], int]:
    O, o_ord, _ = parse_symbols(o_lines)
    A, a_ord, a_other = parse_symbols(a_lines)
    B, b_ord, _ = parse_symbols(b_lines)
    order = list(a_ord)
    for s in b_ord + o_ord:
        if s not in order:
            order.append(s)
    rank = {s: i for i, s in enumerate(order)}
    out: List[str] = []
    conflicts = 0
    for key in sorted(set(O) | set(A) | set(B), key=lambda k: (rank[k[0]], k[1], k[2])):
        o, a, b = O.get(key), A.get(key), B.get(key)
        sec, addr = key[0], key[1]

        def fmt(e: Tuple[str, str]) -> str:
            return f"{e[0]} = {sec}:0x{addr:08X};{e[1]}"

        if a is None or b is None or o is None:
            # Added or deleted on some side: treat the whole entry as one field.
            whole, bad = merge3(fmt(o) if o else None, fmt(a) if a else None, fmt(b) if b else None)
            if bad:
                conflicts += 1
                out += ["<<<<<<< ours", fmt(a) if a else "", "=======", fmt(b) if b else "", ">>>>>>> theirs"]
            elif whole is not None:
                out.append(whole)
            continue
        name, bad1 = merge3(o[0], a[0], b[0])
        attrs, bad2 = merge3(o[1], a[1], b[1])
        if bad1 or bad2:
            conflicts += 1
            out += ["<<<<<<< ours", fmt(a), "=======", fmt(b), ">>>>>>> theirs"]
        else:
            out.append(fmt((name, attrs)))
    return a_other + out, conflicts


def parse_splits(lines: List[str]) -> Tuple[List[str], Dict[str, List[str]], List[str]]:
    """(header block lines, unit -> block lines, unit order)."""
    blocks: List[List[str]] = []
    cur: List[str] = []
    for line in lines:
        if line.strip():
            cur.append(line)
        elif cur:
            blocks.append(cur)
            cur = []
    if cur:
        blocks.append(cur)
    header: List[str] = []
    units: Dict[str, List[str]] = {}
    order: List[str] = []
    for blk in blocks:
        name = blk[0].rstrip()
        if name == "Sections:":
            header = blk
            continue
        if name in units:
            sys.exit(f"merge_dtk: duplicate unit block {name}")
        units[name] = blk
        order.append(name)
    return header, units, order


def block_start(blk: List[str]) -> int:
    for line in blk[1:]:
        m = START.search(line)
        if m:
            return int(m.group(1), 16)
    return 1 << 32


def merge_splits(o_lines: List[str], a_lines: List[str], b_lines: List[str]) -> Tuple[List[str], int]:
    oh, O, _ = parse_splits(o_lines)
    ah, A, _ = parse_splits(a_lines)
    bh, B, _ = parse_splits(b_lines)
    conflicts = 0
    j = lambda blk: "\n".join(blk) if blk is not None else None
    header, bad = merge3(j(oh), j(ah), j(bh))
    out_blocks: List[Tuple[int, str, List[str]]] = []
    if bad:
        conflicts += 1
        out_blocks.append((-1, "", ["<<<<<<< ours", *ah, "=======", *bh, ">>>>>>> theirs"]))
    elif header:
        out_blocks.append((-1, "", header.split("\n")))
    for name in set(O) | set(A) | set(B):
        merged, bad = merge3(j(O.get(name)), j(A.get(name)), j(B.get(name)))
        if bad:
            conflicts += 1
            blk = ["<<<<<<< ours", *(A.get(name) or []), "=======", *(B.get(name) or []), ">>>>>>> theirs"]
            out_blocks.append((block_start(A.get(name) or B[name]), name, blk))
        elif merged is not None:
            blk = merged.split("\n")
            out_blocks.append((block_start(blk), name, blk))
    out_blocks.sort(key=lambda t: (t[0], t[1]))
    out: List[str] = []
    for _, _, blk in out_blocks:
        out += blk + [""]
    return out[:-1] if out else out, conflicts


def main() -> None:
    if len(sys.argv) != 5 or sys.argv[1] not in ("symbols", "splits"):
        sys.exit(__doc__)
    kind, base, ours, theirs = sys.argv[1:]
    o, a, b = read(base), read(ours), read(theirs)
    out, conflicts = (merge_symbols if kind == "symbols" else merge_splits)(o, a, b)
    Path(ours).write_bytes(("\n".join(out).rstrip("\n") + "\n").encode("utf-8"))
    if conflicts:
        sys.stderr.write(f"merge_dtk: {conflicts} conflicting {kind} entr{'y' if conflicts == 1 else 'ies'}\n")
        sys.exit(1)


if __name__ == "__main__":
    main()
