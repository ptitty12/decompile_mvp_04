#!/usr/bin/env python3
"""EA BIGF archive reader and writer. Standard library only.

Layout (verified on all 190+ .big files of the GV4E69 disc, see docs/ROSTERS.md):

    0x00  "BIGF"
    0x04  u32 LITTLE-endian  total file size
    0x08  u32 big-endian     entry count
    0x0C  u32 big-endian     header size (entry table + trailer, NOT aligned)
    0x10  entries, `count` times:
              u32 big-endian offset of the payload
              u32 big-endian payload size
              NUL-terminated name
    ....  trailer: "L234" + u32 big-endian flag (0 raw, 1 RefPack, 2 anims.big,
          3 fonts.big; meaning inferred from which archives hold which value)
    payloads, each starting at a multiple of 4, zero padded; the last payload
    ends exactly at the end of the file.

A payload that starts with a RefPack header (flags 0x10, magic 0xFB) is
compressed; some archives mix raw and compressed payloads, so check each one.

Source of bytes: a file path, bytes, or a GameCube disc image plus the path of
the .big inside it (the disc reader is tools/recon/gcdisc.py).

CLI (read only unless -o is given):
    big.py list     <archive>           # <archive> is a file or  disc.ciso:/data/x.big
    big.py extract  <archive> <name> [-o out]   # decompresses RefPack
    big.py raw      <archive> <name> [-o out]   # payload as stored
    big.py repack   <archive> -o out            # rebuild from parsed entries
"""
import os
import struct
import sys

try:
    from . import refpack
except ImportError:  # run as a script
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import refpack


class BigError(ValueError):
    pass


class Entry:
    __slots__ = ("name", "offset", "size")

    def __init__(self, name, offset, size):
        self.name, self.offset, self.size = name, offset, size

    def __repr__(self):
        return "Entry(%r, off=%#x, size=%d)" % (self.name, self.offset, self.size)


class BigArchive:
    """A parsed archive. `reader(offset, size)` returns bytes of the file."""

    def __init__(self, reader, total_size=None):
        self._reader = reader
        head = reader(0, 16)
        if len(head) < 16 or head[:4] != b"BIGF":
            raise BigError("not a BIGF archive")
        self.file_size = struct.unpack("<I", head[4:8])[0]
        count, self.header_size = struct.unpack(">II", head[8:16])
        if total_size is not None and total_size != self.file_size:
            raise BigError("size field %d != file size %d" % (self.file_size, total_size))
        hdr = reader(0, self.header_size)
        if len(hdr) != self.header_size:
            raise BigError("truncated header")
        p = 16
        self.entries = []
        for _ in range(count):
            if p + 9 > len(hdr):
                raise BigError("entry table runs past the header")
            off, size = struct.unpack(">II", hdr[p:p + 8])
            p += 8
            end = hdr.index(b"\0", p)
            self.entries.append(Entry(hdr[p:end].decode("latin-1"), off, size))
            p = end + 1
        self.trailer = bytes(hdr[p:])
        if len(self.trailer) != 8 or self.trailer[:4] != b"L234":
            raise BigError("unexpected trailer %r" % self.trailer)
        self.flag = struct.unpack(">I", self.trailer[4:])[0]
        self._index = {}
        for e in self.entries:
            self._index.setdefault(e.name.lower(), e)

    # ---- construction helpers
    @classmethod
    def from_bytes(cls, data):
        data = bytes(data)
        return cls(lambda o, n: data[o:o + n], len(data))

    @classmethod
    def from_file(cls, path):
        size = os.path.getsize(path)
        f = open(path, "rb")

        def rd(o, n):
            f.seek(o)
            return f.read(n)
        a = cls(rd, size)
        a._file = f
        return a

    @classmethod
    def from_disc(cls, image, inner_path):
        """`image` is a CISO/ISO path; `inner_path` like /data/database/database.big"""
        d = _open_disc(image)
        inner = "/" + inner_path.replace("\\", "/").lstrip("/")
        for p, off, size in d.files:
            if p.lower() == inner.lower():
                return cls(lambda o, n, off=off: d.d.read(off + o, n), size)
        raise BigError("%s not found on %s" % (inner_path, image))

    @classmethod
    def open(cls, spec):
        """Open `spec`: a file path, or `image:/path/inside/disc.big`."""
        if not os.path.exists(spec):
            for sep in (":/", ":\\"):
                i = spec.rfind(sep)
                if i > 1 and os.path.exists(spec[:i]):
                    return cls.from_disc(spec[:i], spec[i + 1:])
        return cls.from_file(spec)

    # ---- access
    def names(self):
        return [e.name for e in self.entries]

    def entry(self, name):
        try:
            return self._index[name.lower()]
        except KeyError:
            raise KeyError("no entry %r" % name)

    def raw(self, name):
        e = self.entry(name)
        return self._reader(e.offset, e.size)

    def read(self, name):
        """Payload, RefPack-decompressed when it carries a RefPack header."""
        data = self.raw(name)
        return refpack.decompress(data) if refpack.is_refpack(data) else data

    def is_compressed(self, name):
        return refpack.is_refpack(self._reader(self.entry(name).offset, 5))

    def check_layout(self):
        """Problems with the canonical layout (empty list = canonical)."""
        out = []
        pos = self.header_size
        for e in self.entries:
            want = (pos + 3) & ~3
            if e.offset != want:
                out.append("%s: offset %#x, expected %#x" % (e.name, e.offset, want))
            pos = e.offset + e.size
        if pos != self.file_size:
            out.append("payloads end at %#x, file size %#x" % (pos, self.file_size))
        return out

    def payload_alignment(self):
        """The largest power of two A (4..4096) for which the archive is canonical
        with payloads aligned to A, or None. Most archives use 4; the audio name
        archives use 64 or 128 (docs/ROSTERS.md 2.1)."""
        for a in (4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4):
            pos = self.header_size
            for e in self.entries:
                if e.offset != (pos + a - 1) & ~(a - 1):
                    break
                pos = e.offset + e.size
            else:
                if pos == self.file_size:
                    return a
        return None

    def to_bytes(self, replace=None, align=4):
        """Rebuild the archive. `replace` maps entry name -> new raw payload.
        With no replacements and a canonical source this reproduces the input
        (pass align=payload_alignment() for archives aligned beyond 4)."""
        replace = replace or {}
        payloads = []
        for e in self.entries:
            payloads.append(replace[e.name] if e.name in replace else self.raw(e.name))
        return build(list(zip(self.names(), payloads)), self.flag, align)


def build(items, flag=1, align=4):
    """Build an archive from [(name, raw payload)] with the game's layout; payloads
    start on multiples of `align` (a power of two, 4 for most archives)."""
    table = bytearray()
    for name, _ in items:
        table += b"\0\0\0\0\0\0\0\0" + name.encode("latin-1") + b"\0"
    hs = 16 + len(table) + 8
    pos = hs
    offs = []
    for _, data in items:
        pos = (pos + align - 1) & ~(align - 1)
        offs.append(pos)
        pos += len(data)
    total = pos
    out = bytearray(b"BIGF" + struct.pack("<I", total) + struct.pack(">II", len(items), hs))
    for (name, data), off in zip(items, offs):
        out += struct.pack(">II", off, len(data)) + name.encode("latin-1") + b"\0"
    out += b"L234" + struct.pack(">I", flag)
    for (_, data), off in zip(items, offs):
        out += b"\0" * (off - len(out))
        out += data
    assert len(out) == total
    return bytes(out)


def _open_disc(image):
    here = os.path.dirname(os.path.abspath(__file__))
    recon = os.path.join(os.path.dirname(here), "recon")
    if recon not in sys.path:
        sys.path.insert(0, recon)
    import gcdisc  # tools/recon/gcdisc.py
    with open(image, "rb") as f:
        magic = f.read(4)
    dev = gcdisc.CISO(image) if magic == b"CISO" else _IsoDev(image)
    return gcdisc.GCM(dev)


class _IsoDev:
    def __init__(self, path):
        self.f = open(path, "rb")

    def read(self, off, size):
        self.f.seek(off)
        return self.f.read(size)


def main(argv):
    import argparse
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("cmd", choices=["list", "extract", "raw", "repack"])
    ap.add_argument("archive")
    ap.add_argument("name", nargs="?")
    ap.add_argument("-o", "--out")
    a = ap.parse_args(argv)
    arc = BigArchive.open(a.archive)
    if a.cmd == "list":
        print("%d entries, header %#x, trailer flag %d, file size %d, layout %s"
              % (len(arc.entries), arc.header_size, arc.flag, arc.file_size,
                 "canonical" if not arc.check_layout() else "NON-CANONICAL"))
        for e in arc.entries:
            print("%08x %9d %s %s" % (e.offset, e.size,
                  "RP" if arc.is_compressed(e.name) else "--", e.name))
        return 0
    if a.cmd == "repack":
        if not a.out:
            ap.error("repack needs -o")
        data = arc.to_bytes()
        open(a.out, "wb").write(data)
        print("wrote %d bytes" % len(data))
        return 0
    if not a.name:
        ap.error("name required")
    data = arc.read(a.name) if a.cmd == "extract" else arc.raw(a.name)
    if a.out:
        open(a.out, "wb").write(data)
    else:
        sys.stdout.buffer.write(data)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
