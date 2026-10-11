"""Check the data that matched functions load from their own literal pools.

    python tools/match/check_literals.py [unit-substring ...]

objdiff's default report ignores relocation target values, so a function that
loads 211.3f where the original loads 211.2f still scores 100%. This walks the
.text relocations of every function the report scores at 100% and, where our
object resolves the relocation into its own data (literal pools, strings,
local tables), compares those bytes with the bytes the original relocation
points at in build/GV4E69/main.elf.

Compared length: 4 bytes for lfs/lwz/stw, 8 for lfd, 2 for lhz/lha, 1 for
lbz, and for an address (addi) the C string at the target, or 4 bytes if it
is not a string.

Relocations to symbols outside the object (calls, globals) are compared by
address through symbols.txt: a call to the wrong function or a load of the
wrong global also scores 100% in the default report. Targets whose name is
not in symbols.txt are counted as unresolved (they would fail to link) and
listed with -v. Prints one line per mismatch and exits 1 if there are any.
This is a lead-side extra check; it does not replace tools/verify.
"""
import json
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
BUILD = ROOT / "build" / "GV4E69"
# Overlay units' code is split into .feoverlay/.dboverlay (FE_OVERLAY/DB_OVERLAY).
CODE_SECTIONS = (".text", ".feoverlay", ".dboverlay")


class Elf:
    def __init__(self, path):
        d = self.data = path.read_bytes()
        shoff, = struct.unpack_from(">I", d, 0x20)
        shentsize, shnum, shstrndx = struct.unpack_from(">HHH", d, 0x2E)
        self.secs = [struct.unpack_from(">IIIIIIIIII", d, shoff + i * shentsize) for i in range(shnum)]
        names = self.secs[shstrndx]
        self.names = [self.cstr(names[4] + s[0]) for s in self.secs]
        self.syms = []
        for s in self.secs:
            if s[1] == 2:  # SHT_SYMTAB
                strtab = self.secs[s[6]]
                for i in range(s[5] // 16):
                    st_name, value, size, info, _, shndx = struct.unpack_from(">IIIBBH", d, s[4] + i * 16)
                    self.syms.append((self.cstr(strtab[4] + st_name), value, size, info, shndx))

    def cstr(self, off):
        return self.data[off:self.data.index(b"\0", off)].decode("latin-1")

    def sec_bytes(self, idx):
        s = self.secs[idx]
        return self.data[s[4]:s[4] + s[5]] if s[1] != 8 else bytes(s[5])  # SHT_NOBITS

    def text_index(self, name=None):
        """Index of the code section: `name` if given, else .text or an overlay section."""
        for n in ([name] if name else CODE_SECTIONS):
            if n in self.names:
                return self.names.index(n)
        return None

    def relocs(self, target_idx):
        """{offset: (sym_index, type, addend)} for the RELA section applying to target_idx."""
        out = {}
        for s in self.secs:
            if s[1] == 4 and s[7] == target_idx:  # SHT_RELA, sh_info
                for i in range(s[5] // 12):
                    off, info, add = struct.unpack_from(">IIi", self.data, s[4] + i * 12)
                    out[off] = (info >> 8, info & 0xFF, add)
        return out

    def funcs(self, idx):
        return {n: (v, sz) for n, v, sz, info, sh in self.syms if info & 0xF == 2 and sh == idx}

    def read_addr(self, addr, n):
        for s in self.secs:
            if s[3] and s[3] <= addr < s[3] + s[5] and s[1] != 8:
                o = s[4] + addr - s[3]
                return self.data[o:o + n]
        return None


def load_size(word):
    op = word >> 26
    return {48: 4, 49: 4, 52: 4, 53: 4, 32: 4, 33: 4, 36: 4, 50: 8, 51: 8, 54: 8,
            40: 2, 42: 2, 44: 2, 34: 1, 38: 1}.get(op)


def main():
    verbose = "-v" in sys.argv[1:]
    filt = [a for a in sys.argv[1:] if a != "-v"]
    report = json.loads((BUILD / "report.json").read_text())
    dol = Elf(BUILD / "main.elf")
    addr_of = {}
    for line in (ROOT / "config" / "GV4E69" / "symbols.txt").read_text().splitlines():
        m = re.match(r"^(\S+) = [.\w]+:0x([0-9A-Fa-f]+);", line)
        if m:
            addr_of[m.group(1)] = int(m.group(2), 16)
    bad = checked = unresolved = 0
    for u in report["units"]:
        name = u["name"].split("/", 1)[1]
        if filt and not any(f in name for f in filt):
            continue
        full = [f["name"] for f in u.get("functions", []) if f.get("fuzzy_match_percent") == 100.0]
        ours_p, orig_p = BUILD / "src" / (name + ".o"), BUILD / "obj" / (name + ".o")
        if not full or not ours_p.exists() or not orig_p.exists():
            continue
        ours, orig = Elf(ours_p), Elf(orig_p)
        gt = orig.text_index()
        ot = ours.text_index(orig.names[gt]) if gt is not None else None
        if ot is None or gt is None:
            continue
        otext, orel, grel = ours.sec_bytes(ot), ours.relocs(ot), orig.relocs(gt)
        of, gf = ours.funcs(ot), orig.funcs(gt)
        for fn in full:
            if fn not in of or fn not in gf:
                continue
            ov, sz = of[fn]
            gv = gf[fn][0]
            for off in range(ov, ov + sz):
                r = orel.get(off)
                if not r:
                    continue
                sym = ours.syms[r[0]]
                g = grel.get(gv + off - ov)
                if not g:
                    continue
                gname = orig.syms[g[0]][0]
                if gname not in addr_of:
                    continue
                if sym[4] == 0:  # undefined in our object: compare addresses
                    checked += 1
                    if sym[0] not in addr_of:
                        unresolved += 1
                        if verbose:
                            print(f"unresolved {name} {fn} +0x{off - ov:X}: {sym[0]} (original {gname})")
                    elif addr_of[sym[0]] + r[2] != addr_of[gname] + g[2]:
                        bad += 1
                        print(f"{name} {fn} +0x{off - ov:X}: target {sym[0]}+{r[2]} vs {gname}+{g[2]}")
                    continue
                if r[1] not in (4, 1) or not (0 < sym[4] < len(ours.secs)) or sym[4] == ot:
                    continue
                data = ours.sec_bytes(sym[4])
                start = sym[1] + r[2]
                word, = struct.unpack_from(">I", otext, off & ~3)
                n = load_size(word)
                if n is None:  # address: a string, or a word
                    end = data.find(b"\0", start)
                    s = data[start:end] if end >= 0 else b""
                    n = len(s) + 1 if s and all(32 <= c < 127 or c in (9, 10, 13) for c in s) else 4
                mine = data[start:start + n]
                theirs = dol.read_addr(addr_of[gname] + g[2], n)
                dr = ours.relocs(sym[4]).get(start) if n == 4 else None
                if dr and dr[1] == 1 and theirs is not None:
                    # The word is a pointer filled in by a relocation (e.g. const char* p = "x"):
                    # its bytes in the .o are not the value. Compare what the two pointers
                    # point to instead (the C string, or 4 bytes).
                    tsym = ours.syms[dr[0]]
                    tdata = ours.sec_bytes(tsym[4]) if 0 < tsym[4] < len(ours.secs) else None
                    if tdata is not None:
                        tstart = tsym[1] + dr[2]
                        end = tdata.find(b"\0", tstart)
                        s = tdata[tstart:end] if end >= 0 else b""
                        m = len(s) + 1 if s and all(32 <= c < 127 or c in (9, 10, 13) for c in s) else 4
                        mine = tdata[tstart:tstart + m]
                        theirs = dol.read_addr(struct.unpack(">I", theirs)[0], m)
                checked += 1
                if theirs is not None and mine != theirs:
                    bad += 1
                    print(f"{name} {fn} +0x{off - ov:X}: ours {mine[:16].hex()} vs {gname}+{g[2]} {theirs[:16].hex()}")
    print(f"checked {checked} references, {bad} mismatch(es), {unresolved} unresolved name(s)")
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
