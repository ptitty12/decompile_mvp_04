#!/usr/bin/env python3
"""Build a GameCube DOL from a linked ELF.

Why not `dtk elf2dol`: it emits one DOL section per ELF section and pads each
to 32 bytes, so its header differs from the retail GV4E69 main.dol, which has
one DOL section per program segment (`.text` + both `*_codeoverlay` sections
share one DOL text section, `.ctors` + `.dtors` share one data section).
SN's ngcld cannot reproduce those segments (its PHDRS support crashes), so the
build groups sections explicitly with a layout file instead.

Modes:
  --segments            one DOL section per PT_LOAD segment. Converting the
                        disc's retail /mvp.elf this way reproduces the retail
                        main.dol byte-for-byte (SHA-1 da6becdb...84dd).
  --layout FILE         group ELF sections into DOL sections as listed in FILE
                        (config/GV4E69/dol_layout.txt). Used by the build. Fails
                        if any allocated, non-empty section is not listed.
  --per-section         analysis only: one DOL section per allocated ELF
                        section with exact, unpadded sizes, so `dtk dol split`
                        sees the real section boundaries. Not a retail-format DOL.

Common rules: DOL section sizes are padded to 32 bytes with zeros (except
--per-section); section data is laid out from file offset 0x100 in slot order
(text slots, then data slots); bss = [lowest start, highest end) of the bss
ranges.

Usage: python tools/mkdol.py (--segments | --layout FILE | --per-section) <in.elf> <out.dol>
"""
import struct
import sys
from typing import Dict, List, Tuple


def align(v: int, a: int) -> int:
    return (v + a - 1) & ~(a - 1)


class Elf:
    def __init__(self, data: bytes) -> None:
        if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 2:
            sys.exit("expected a 32-bit big-endian ELF")
        self.data = data
        self.entry, self.phoff, self.shoff = struct.unpack(">III", data[24:36])
        self.phentsize, self.phnum, self.shentsize, self.shnum, shstrndx = (
            struct.unpack(">HHHHH", data[42:52])
        )
        raw = [
            struct.unpack(">10I", data[self.shoff + i * self.shentsize :][:40])
            for i in range(self.shnum)
        ]
        strtab_off = raw[shstrndx][4] if self.shnum else 0
        # (name, type, flags, addr, offset, size)
        self.sections: List[Tuple[str, int, int, int, int, int]] = []
        for sh in raw:
            end = data.index(b"\0", strtab_off + sh[0])
            name = data[strtab_off + sh[0] : end].decode("latin1")
            self.sections.append((name, sh[1], sh[2], sh[3], sh[4], sh[5]))

    def segments(self):
        for i in range(self.phnum):
            p = struct.unpack(">8I", self.data[self.phoff + i * self.phentsize :][:32])
            p_type, p_off, p_vaddr, _, p_filesz, p_memsz, p_flags, _ = p
            if p_type == 1:  # PT_LOAD
                yield p_vaddr, self.data[p_off : p_off + p_filesz], p_memsz, bool(p_flags & 1)

    def alloc_sections(self):
        for name, sh_type, flags, addr, off, size in self.sections:
            if flags & 2 and size:  # SHF_ALLOC, non-empty
                nobits = sh_type == 8
                blob = b"" if nobits else self.data[off : off + size]
                yield name, addr, blob, size, bool(flags & 4)


def write_dol(text, data, bss, entry: int, pad: bool) -> bytes:
    if len(text) > 7 or len(data) > 11:
        sys.exit(f"too many DOL sections: {len(text)} text, {len(data)} data")
    offs, addrs, sizes = [0] * 18, [0] * 18, [0] * 18
    body = bytearray()
    pos = 0x100
    slots = [(i, s) for i, s in enumerate(text)] + [(7 + i, s) for i, s in enumerate(data)]
    for slot, (addr, blob) in slots:
        size = align(len(blob), 32) if pad else len(blob)
        offs[slot], addrs[slot], sizes[slot] = pos, addr, size
        body += blob + b"\0" * (size - len(blob))
        pos += size
    bss_addr = min(b[0] for b in bss) if bss else 0
    bss_size = (max(b[1] for b in bss) - bss_addr) if bss else 0
    header = struct.pack(">18I18I18I3I", *offs, *addrs, *sizes, bss_addr, bss_size, entry)
    return header + b"\0" * (0x100 - len(header)) + bytes(body)


def from_segments(elf: Elf) -> bytes:
    text, data, bss = [], [], []
    for vaddr, blob, memsz, is_exec in elf.segments():
        if blob:
            (text if is_exec else data).append((vaddr, blob))
        elif memsz:
            bss.append((vaddr, vaddr + memsz))
    return write_dol(text, data, bss, elf.entry, pad=True)


def from_sections(elf: Elf) -> bytes:
    text, data, bss = [], [], []
    for name, addr, blob, size, is_exec in elf.alloc_sections():
        if blob:
            (text if is_exec else data).append((addr, blob))
        else:
            bss.append((addr, addr + size))
    return write_dol(text, data, bss, elf.entry, pad=False)


def from_layout(elf: Elf, layout_path: str) -> bytes:
    secs: Dict[str, Tuple[int, bytes, int]] = {}
    for name, addr, blob, size, _ in elf.alloc_sections():
        secs[name] = (addr, blob, size)
    text, data, bss = [], [], []
    used = set()
    with open(layout_path, encoding="utf-8") as f:
        for lineno, line in enumerate(f, 1):
            line = line.split("#", 1)[0].split()
            if not line:
                continue
            kind, names = line[0], line[1:]
            if kind not in ("text", "data", "bss") or not names:
                sys.exit(f"{layout_path}:{lineno}: bad line")
            present = [n for n in names if n in secs]
            used.update(present)
            if not present:
                continue
            start = min(secs[n][0] for n in present)
            end = max(secs[n][0] + secs[n][2] for n in present)
            if kind == "bss":
                bss.append((start, end))
                continue
            blob = bytearray(end - start)
            for n in present:
                addr, sblob, size = secs[n]
                if len(sblob) != size:
                    sys.exit(f"{layout_path}:{lineno}: {n} has no file data")
                blob[addr - start : addr - start + size] = sblob
            (text if kind == "text" else data).append((start, bytes(blob)))
    missing = sorted(set(secs) - used)
    if missing:
        sys.exit(f"sections not covered by {layout_path}: {missing}")
    return write_dol(text, data, bss, elf.entry, pad=True)


def main() -> None:
    args = sys.argv[1:]
    try:
        if args[0] == "--segments" and len(args) == 3:
            make = lambda e: from_segments(e)
        elif args[0] == "--per-section" and len(args) == 3:
            make = lambda e: from_sections(e)
        elif args[0] == "--layout" and len(args) == 4:
            layout = args[1]
            args = args[1:]
            make = lambda e: from_layout(e, layout)
        else:
            raise IndexError
    except IndexError:
        sys.exit(__doc__)
    with open(args[1], "rb") as f:
        elf = Elf(f.read())
    with open(args[2], "wb") as f:
        f.write(make(elf))


if __name__ == "__main__":
    main()
