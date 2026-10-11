"""Summarize functions in an address range from dtk asm: size, calls, data refs, notable ops.

Usage: python fnsum.py <asm_dir> <lo_hex> <hi_hex>
"""
import glob, os, re, sys

asm_dir, lo, hi = sys.argv[1], int(sys.argv[2], 16), int(sys.argv[3], 16)
FN = re.compile(r"^\.fn (\S+), (\w+)$(.*?)^\.endfn \1$", re.S | re.M)
for f in sorted(glob.glob(os.path.join(asm_dir, "**", "*.s"), recursive=True)):
    txt = open(f, encoding="utf-8").read()
    for m in FN.finditer(txt):
        name, scope, body = m.groups()
        am = re.search(r"/\* ([0-9A-F]{8}) ", body)
        if not am:
            continue
        addr = int(am.group(1), 16)
        if not (lo <= addr < hi):
            continue
        ins = [l for l in body.splitlines() if l.startswith("/*")]
        calls = re.findall(r"\tbl (\S+)", body)
        refs = sorted(set(re.findall(r"(lbl_[0-9A-F]+)@(?:ha|h|sda21)", body)))
        notes = []
        if "blrl" in body or "bctrl" in body: notes.append("indirect-call")
        if re.search(r"\tlfs|\tlfd|\tfmul|\tfadd", body): notes.append("float")
        if "andi. r0, r30, 0x1" in body or "andi. r0, r4, 0x1" in body: notes.append("deleting-dtor?")
        print(f"{addr:08X} {name:14} {len(ins)*4:#6x} {scope:6} calls={calls[:6]}{'...' if len(calls) > 6 else ''} refs={refs[:4]} {' '.join(notes)}")
