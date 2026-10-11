#!/usr/bin/env python3
"""Print a "unit packet": the setup facts a matcher needs before writing a unit.

Requested by the matching session, which spent about 35 of 80 minutes on its
first game unit working these out by hand (docs/SPEEDUPS.md, item 2). It
complements tools/match/asm_summary.py (one line per function) and adds:

  1. Roles. Each function is tagged by pattern:
       ctor     stores a vtable address into the object
       dtor     stores a vtable and calls the base dtor (BASE_DTOR)
       attr     calls an attribute-registration function (ATTR_FNS),
                listing the string arguments it passes
       factory  calls operator new (NEW), then a ctor; the object size
                comes from the `li r3, <size>` before the call
  2. Classes. For each vtable a ctor/dtor stores: the vtable's function slots,
     and the class name proven through slot 3 (+0x1C). That function loads a
     data pointer to the name string, which is how ICommonPlayerID was proven.
  3. Data. Every data object the unit's functions reference, grouped by
     section, with the functions outside the range that share it. Also the
     neighbouring objects just past each end and who uses them; the unit
     boundary is usually where those owners change.
  4. Neighbours. The functions just before and after the range, and whether
     they touch this unit's data (if they do, the range is probably wrong).

Input is dtk's split asm (build/GV4E69/asm). Run it before splitting the unit
(on auto_* asm) or after; names follow whatever symbols.txt says now.

Usage:
  python tools/scout/packet.py START END          # hex addresses or function names; END exclusive
  python tools/scout/packet.py --unit animation/choosers/playeridchooser.cpp
  options: --asm-dir DIR (default build/GV4E69/asm), --splits FILE
"""
import argparse
import glob
import os
import re
import sys
from collections import defaultdict
from pathlib import Path
from typing import Dict, List, Optional, Set, Tuple

ROOT = Path(__file__).resolve().parents[2]

# Game-specific call targets, found by the matching session on playeridchooser.cpp
# (2026-10-10). Add more as other units show other bases.
NEW = 0x80377428  # operator new
BASE_DTOR = 0x80362C2C  # common base-class dtor; the in-charge flag is passed through
ATTR_FNS = {0x8037B728, 0x8037B6B0}  # attribute registration, takes string arguments
NAME_SLOT = 0x1C  # vtable byte offset of the slot whose function returns the class name
CLUSTER_GAP = 0x100  # bytes between referenced data objects that start a new cluster

FN_HEAD = re.compile(r"^# \.(\w+):0x[0-9A-Fa-f]+ \| 0x([0-9A-Fa-f]{8}) \| size: 0x([0-9A-Fa-f]+)")
INS = re.compile(r"^/\* ([0-9A-F]{8}) [0-9A-F]+ (?: [0-9A-F]{2}){4} \*/\t(\S+)\s*(.*)$")
SYMREF = re.compile(r"\(?([A-Za-z_.$][\w.$]*)(?:[+-]0x[0-9A-Fa-f]+)?\)?@(ha|h|l|sda21)")
REG = re.compile(r"^r(\d+)$")
NO_DEST = ("st", "cmp", "b", "mt", "dcb", "icb", "sync", "isync", "tw")


class Fn:
    def __init__(self, name: str, addr: int, size: int, section: str) -> None:
        self.name, self.addr, self.size, self.section = name, addr, size, section
        self.ins: List[Tuple[int, str, str]] = []


class Obj:
    def __init__(self, name: str, addr: int, size: int, section: str) -> None:
        self.name, self.addr, self.size, self.section = name, addr, size, section
        self.words: Dict[int, str] = {}  # byte offset -> value of a .4byte (symbol name or hex)
        self.string: Optional[str] = None
        self.floats: List[str] = []


def load(asm_dir: Path) -> Tuple[Dict[str, Fn], Dict[str, Obj]]:
    fns: Dict[str, Fn] = {}
    objs: Dict[str, Obj] = {}
    for path in sorted(glob.glob(str(asm_dir / "**" / "*.s"), recursive=True)):
        head: Optional[Tuple[str, int, int]] = None
        cur_fn: Optional[Fn] = None
        cur_obj: Optional[Obj] = None
        off = 0
        with open(path, encoding="utf-8", errors="replace") as f:
            for line in f:
                line = line.rstrip("\n")
                if line.startswith("# ."):
                    m = FN_HEAD.match(line)
                    if m:
                        head = (m.group(1), int(m.group(2), 16), int(m.group(3), 16))
                elif line.startswith(".fn ") and head:
                    name = line[4:].split(",")[0].strip()
                    cur_fn = fns[name] = Fn(name, head[1], head[2], head[0])
                elif line.startswith(".endfn"):
                    cur_fn = None
                elif line.startswith(".obj ") and head:
                    name = line[5:].split(",")[0].strip()
                    cur_obj = objs[name] = Obj(name, head[1], head[2], head[0])
                    off = 0
                elif line.startswith(".endobj"):
                    cur_obj = None
                elif cur_fn is not None and line.startswith("/*"):
                    m = INS.match(line)
                    if m:
                        cur_fn.ins.append((int(m.group(1), 16), m.group(2), m.group(3)))
                elif cur_obj is not None and line.startswith("\t."):
                    d, _, rest = line[1:].partition(" ")
                    vals = [v.strip() for v in rest.split(",")] if rest else []
                    if d == ".4byte":
                        for v in vals:
                            cur_obj.words[off] = v
                            off += 4
                    elif d == ".2byte":
                        off += 2 * len(vals)
                    elif d == ".byte":
                        off += len(vals)
                    elif d in (".string", ".asciz"):
                        s = rest.strip()[1:-1]
                        cur_obj.string = s if cur_obj.string is None else cur_obj.string
                        off += len(s) + 1
                    elif d in (".float", ".double"):
                        cur_obj.floats.append(rest.strip())
                        off += 4 if d == ".float" else 8
                    elif d == ".skip":
                        off += int(rest.strip(), 0)
    return fns, objs


def sym_base(v: str) -> str:
    return re.split(r"[+-]0x", v.strip("()"))[0]


class Analysis:
    """Per-function facts from one linear pass over the instructions."""

    def __init__(self, fn: Fn, fns: Dict[str, Fn], objs: Dict[str, Obj]) -> None:
        self.calls: List[Tuple[str, Optional[int], List[str]]] = []  # target, imm r3, string args
        self.refs: Set[str] = set()
        self.vstores: List[str] = []
        self.float = False
        self.indirect = False
        addr_of: Dict[int, str] = {}
        imm: Dict[int, int] = {}
        for _, mn, ops in fn.ins:
            parts = [p.strip() for p in ops.split(",")]
            for m in SYMREF.finditer(ops):
                if m.group(1) in objs:
                    self.refs.add(m.group(1))
            if mn in ("bctrl", "blrl"):
                self.indirect = True
            if mn.startswith(("lf", "stf", "fm", "fa", "fs", "fd", "fc", "frs", "fn")):
                self.float = True
            if mn in ("bl", "b") and parts and not parts[0].startswith(".L"):
                if mn == "bl" or parts[0] in fns:
                    strs = [addr_of[r] for r in (3, 4, 5, 6) if r in addr_of and objs.get(addr_of[r]) and objs[addr_of[r]].string is not None]
                    self.calls.append((parts[0], imm.get(3), strs))
                for r in [0] + list(range(3, 13)):
                    addr_of.pop(r, None)
                    imm.pop(r, None)
                continue
            if mn == "addi" and len(parts) == 3 and parts[2].endswith("@l"):
                d = REG.match(parts[0])
                if d:
                    addr_of[int(d.group(1))] = sym_base(parts[2][:-2])
                    continue
            if mn == "li" and len(parts) == 2:
                d = REG.match(parts[0])
                if d:
                    try:
                        imm[int(d.group(1))] = int(parts[1], 0)
                    except ValueError:
                        pass
                    continue
            if mn == "stw" and len(parts) == 2:
                s = REG.match(parts[0])
                if s and int(s.group(1)) in addr_of:
                    v = addr_of[int(s.group(1))]
                    o = objs.get(v)
                    if o and any(w in fns for w in o.words.values()):
                        self.vstores.append(v)
                continue
            if not mn.startswith(NO_DEST) and parts:
                d = REG.match(parts[0])
                if d:
                    addr_of.pop(int(d.group(1)), None)
                    imm.pop(int(d.group(1)), None)


def class_name(vt: str, fns: Dict[str, Fn], objs: Dict[str, Obj]) -> Tuple[Optional[str], List[str]]:
    """Slot 3 function -> the data pointer it loads -> the name string.

    Returns the name and the data objects on that chain (pointer, string): they
    belong to the unit even though none of its own functions reference them."""
    o = objs.get(vt)
    slot = o.words.get(NAME_SLOT) if o else None
    if not slot or slot not in fns:
        return None, []
    for _, _, ops in fns[slot].ins:
        for m in SYMREF.finditer(ops):
            p = objs.get(m.group(1))
            if not p:
                continue
            if p.string is not None:
                return p.string, [p.name]
            target = objs.get(sym_base(p.words.get(0, "")))
            if target and target.string is not None:
                return target.string, [p.name, target.name]
    return None, []


def resolve(spec: str, fns: Dict[str, Fn]) -> int:
    return fns[spec].addr if spec in fns else int(spec, 16)


def unit_range(splits: Path, unit: str) -> Tuple[int, int]:
    cur = None
    for line in splits.read_text(encoding="utf-8").splitlines():
        if line and not line[0].isspace():
            cur = line.rstrip(":")
        elif cur == unit and line.strip().startswith(".text"):
            m = re.search(r"start:0x([0-9A-Fa-f]+) end:0x([0-9A-Fa-f]+)", line)
            if m:
                return int(m.group(1), 16), int(m.group(2), 16)
    sys.exit(f"{unit}: no .text range in {splits}")


def preview(o: Obj) -> str:
    if o.string is not None:
        s = o.string if len(o.string) <= 48 else o.string[:45] + "..."
        return f'"{s}"'
    if o.floats:
        return "float " + ", ".join(o.floats[:3])
    syms = [w for w in o.words.values() if not w.startswith("0x")]
    if syms:
        return "ptrs " + ", ".join(syms[:3]) + (" ..." if len(syms) > 3 else "")
    return f"{o.size:#x} bytes"


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("start", nargs="?")
    ap.add_argument("end", nargs="?")
    ap.add_argument("--unit")
    ap.add_argument("--asm-dir", type=Path, default=ROOT / "build" / "GV4E69" / "asm")
    ap.add_argument("--splits", type=Path, default=ROOT / "config" / "GV4E69" / "splits.txt")
    args = ap.parse_args()

    fns, objs = load(args.asm_dir)
    if not fns:
        sys.exit(f"no functions found under {args.asm_dir}; build first (ninja)")
    if args.unit:
        lo, hi = unit_range(args.splits, args.unit)
    elif args.start and args.end:
        lo, hi = resolve(args.start, fns), resolve(args.end, fns)
    else:
        ap.error("give START END or --unit")

    by_addr = sorted(fns.values(), key=lambda f: f.addr)
    addr_to_fn = {f.addr: f for f in by_addr}
    inside = [f for f in by_addr if lo <= f.addr < hi]
    an = {f.name: Analysis(f, fns, objs) for f in by_addr}
    users: Dict[str, Set[str]] = defaultdict(set)
    for name, a in an.items():
        for r in a.refs:
            users[r].add(name)

    def target_addr(t: str) -> Optional[int]:
        return fns[t].addr if t in fns else None

    roles: Dict[str, str] = {}
    sizes: Dict[str, int] = {}
    vt_of: Dict[str, List[str]] = defaultdict(list)  # vtable -> functions storing it
    for f in inside:
        a = an[f.name]
        call_addrs = [target_addr(t) for t, _, _ in a.calls]
        tags = []
        if a.vstores:
            tags.append("dtor" if BASE_DTOR in call_addrs else "ctor")
            for v in a.vstores:
                vt_of[v].append(f.name)
        if any(c in ATTR_FNS for c in call_addrs):
            tags.append("attr")
        for i, (t, size, _) in enumerate(a.calls):
            if target_addr(t) == NEW:
                nxt = a.calls[i + 1][0] if i + 1 < len(a.calls) else None
                tags.append(f"factory(new {size:#x}" + (f" -> {nxt})" if nxt else ")") if size is not None else "factory")
                if size is not None:
                    sizes[f.name] = size
        roles[f.name] = " ".join(tags)

    total = sum(f.size for f in inside)
    print(f"# Unit packet {lo:08X}..{hi:08X}: {len(inside)} functions, {total:#x} bytes\n")

    print("## Functions\n")
    for f in inside:
        a = an[f.name]
        notes = [n for n, on in (("float", a.float), ("indirect-call", a.indirect)) if on]
        calls = []
        for t, _, strs in a.calls:
            calls.append(t + (f"({', '.join(chr(34) + objs[s].string + chr(34) for s in strs)})" if strs else ""))
        line = f"- {f.addr:08X} {f.name} {f.size:#x}"
        if roles[f.name]:
            line += f"  **{roles[f.name]}**"
        if notes:
            line += f"  [{', '.join(notes)}]"
        if calls:
            line += "  calls: " + "; ".join(calls[:8]) + (" ..." if len(calls) > 8 else "")
        print(line)

    print("\n## Classes (from vtables stored by ctors/dtors)\n")
    if not vt_of:
        print("(no vtable stores found)")
    name_chain: Set[str] = set()
    for vt, who in sorted(vt_of.items(), key=lambda kv: objs[kv[0]].addr):
        o = objs[vt]
        name, chain = class_name(vt, fns, objs)
        name_chain.update(chain)
        print(f"- vtable {vt} @ {o.addr:08X} ({o.section}, {o.size:#x} bytes): class "
              + (f"**{name}**" if name else "? (slot +0x1C has no name pointer)"))
        if chain:
            print(f"  - name via: {' -> '.join(f'{c} @ {objs[c].addr:08X} (.{objs[c].section})' for c in chain)}")
        print(f"  - stored by: {', '.join(f'{w} ({roles[w]})' for w in who)}")
        slots = [f"+{off:#x} {w}" for off, w in sorted(o.words.items()) if w in fns]
        print(f"  - slots: {', '.join(slots)}")
    for f, size in sizes.items():
        print(f"- object size {size:#x} (from {f})")

    print("\n## Data referenced\n")
    data: Dict[str, List[Obj]] = defaultdict(list)
    seen: Set[str] = set()
    for c in sorted(name_chain):
        seen.add(c)
        data[objs[c].section].append(objs[c])
    for f in inside:
        for r in an[f.name].refs | set(an[f.name].vstores):
            if r not in seen:
                seen.add(r)
                data[objs[r].section].append(objs[r])
                # One level of pointers, e.g. a name pointer to its string.
                for w in objs[r].words.values():
                    b = sym_base(w)
                    if b in objs and b not in seen and b not in fns:
                        seen.add(b)
                        data[objs[b].section].append(objs[b])
    inside_names = {f.name for f in inside}
    sec_objs: Dict[str, List[Obj]] = defaultdict(list)
    for o in objs.values():
        sec_objs[o.section].append(o)
    for sec in sec_objs:
        sec_objs[sec].sort(key=lambda o: o.addr)
    # Clusters: runs of referenced objects with no big gap. Vtables, for one, can sit
    # far from the rest of a unit's data (seen in reverse unit order).
    suggest: List[Tuple[str, int, int]] = []
    vtables = set(vt_of)
    for sec, lst in sorted(data.items(), key=lambda kv: min(o.addr for o in kv[1])):
        lst.sort(key=lambda o: o.addr)
        clusters: List[List[Obj]] = [[lst[0]]]
        for o in lst[1:]:
            prev = clusters[-1][-1]
            if o.addr - (prev.addr + prev.size) > CLUSTER_GAP:
                clusters.append([o])
            else:
                clusters[-1].append(o)
        idx = {o.name: i for i, o in enumerate(sec_objs[sec])}
        for cl in clusters:
            first, last = cl[0], cl[-1]
            only_vt = all(o.name in vtables for o in cl)
            print(f"### .{sec}: {first.addr:08X}..{last.addr + last.size:08X} ({len(cl)} objects"
                  + (", vtables only" if only_vt else "") + ")\n")
            owned = False
            for o in cl:
                others = sorted(users.get(o.name, set()) - inside_names)
                share = f"  shared with {', '.join(others[:3])}{' ...' if len(others) > 3 else ''}" if others else ""
                tag = "  (class name chain)" if o.name in name_chain else ""
                owned |= not others or o.name in name_chain
                print(f"- {o.addr:08X} {o.name} {preview(o)}{tag}{share}")
            for label, i in (("before", idx[first.name] - 1), ("after", idx[last.name] + 1)):
                if 0 <= i < len(sec_objs[sec]):
                    n = sec_objs[sec][i]
                    who = sorted(users.get(n.name, set()))
                    print(f"- {label}: {n.addr:08X} {n.name} {preview(n)}; used by "
                          + (", ".join(f"{w} ({fns[w].addr:08X})" for w in who[:3]) if who else "nobody directly"))
            print()
            if owned and not only_vt:
                suggest.append((sec, first.addr, last.addr + last.size))

    print("## Suggested splits.txt block (check before use)\n")
    print("Data clusters owned by this unit: not vtable-only, and some object is used only")
    print("here or is a class-name string. Ends are the last object's end.\n")
    print("```")
    print(f"\t.text       start:0x{lo:08X} end:0x{hi:08X}")
    for sec, s, e in suggest:
        print(f"\t.{sec:<10} start:0x{s:08X} end:0x{e:08X}")
    print("```\n")

    print("## Neighbours\n")
    unit_data = seen
    for label, f in (("before", max((g for g in by_addr if g.addr < lo), key=lambda g: g.addr, default=None)),
                     ("after", addr_to_fn.get(hi) or min((g for g in by_addr if g.addr >= hi), key=lambda g: g.addr, default=None))):
        if f is None:
            continue
        shared = sorted(an[f.name].refs & unit_data)
        print(f"- {label}: {f.addr:08X} {f.name} {f.size:#x}"
              + (f"; ALSO uses this unit's data: {', '.join(shared[:4])} (range may be wrong)" if shared else "; uses none of this unit's data"))


if __name__ == "__main__":
    main()
