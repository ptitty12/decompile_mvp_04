#!/usr/bin/env python3
"""Reader/writer for the game's text files FEENG.LOC, IGENG.LOC and MC_ENG.loc.

Layout (little-endian; verified byte for byte on the three English files of
GV4E69 rev 0 by re-serializing them):

    "LOCH"  u32 header size (0x14)  u32 1  u32 1  u32 offset of the "LOCL" block
    "LOCI"  u32 block size (16 + 4*count)  u32 count  u32 0
            count x { u16 string id, u16 string index }       index = 0..count-1 in order
    "LOCL"  u32 block size  u32 0  u32 count
            count x u32 offset of string i, from the start of the LOCL block
            strings, UTF-16LE, each followed by four zero bytes (terminator plus padding);
            the block is zero padded to a multiple of 4 bytes

The ids are what the game code asks for; they are not sorted. Team names, for
example, sit at id 2000+n (nicknames) and 2040+n (full names) for the 30 teams
and the two All-Star sides (docs/ROSTERS.md section 7).

    loc.py dump  <file.LOC> [--grep text]
    loc.py check <file.LOC>             # parse + serialize must reproduce the file
"""
import struct
import sys


class LocError(ValueError):
    pass


class Loc:
    def __init__(self, entries, header_tail=None):
        self.entries = list(entries)       # [(id, text)] in file order
        self.header_tail = header_tail

    @classmethod
    def parse(cls, data):
        data = bytes(data)
        if data[:4] != b"LOCH" or struct.unpack("<I", data[4:8])[0] != 0x14:
            raise LocError("not a LOC file")
        if struct.unpack("<II", data[8:16]) != (1, 1):
            raise LocError("unexpected LOCH version fields")
        p = 0x14
        if data[p:p + 4] != b"LOCI":
            raise LocError("missing LOCI block")
        isize, count, z = struct.unpack("<III", data[p + 4:p + 16])
        if isize != 16 + 4 * count or z != 0:
            raise LocError("odd LOCI header")
        pairs = struct.unpack("<%dH" % (2 * count), data[p + 16:p + 16 + 4 * count])
        q = p + isize
        if data[q:q + 4] != b"LOCL":
            raise LocError("missing LOCL block")
        lsize, z2, lcount = struct.unpack("<III", data[q + 4:q + 16])
        if lcount != count or z2 != 0 or q + lsize != len(data):
            raise LocError("odd LOCL header")
        offs = struct.unpack("<%dI" % count, data[q + 16:q + 16 + 4 * count])
        entries = []
        for n in range(count):
            if pairs[2 * n + 1] != n:
                raise LocError("string index out of order at %d" % n)
            s = q + offs[n]
            e = s
            while data[e:e + 2] != b"\0\0":
                e += 2
            entries.append((pairs[2 * n], data[s:e].decode("utf-16-le")))
        loc = cls(entries, struct.unpack("<I", data[0x10:0x14])[0])
        return loc

    def serialize(self):
        n = len(self.entries)
        loci_size = 16 + 4 * n
        blobs = [t.encode("utf-16-le") + b"\0\0\0\0" for _, t in self.entries]
        offs = []
        pos = 16 + 4 * n
        for b in blobs:
            offs.append(pos)
            pos += len(b)
        pad = (-pos) % 4                    # the block ends on a 4-byte boundary
        pos += pad
        out = bytearray(b"LOCH" + struct.pack("<IIII", 0x14, 1, 1, 0x14 + loci_size))
        out += b"LOCI" + struct.pack("<III", loci_size, n, 0)
        for i, (sid, _) in enumerate(self.entries):
            out += struct.pack("<HH", sid, i)
        out += b"LOCL" + struct.pack("<III", pos, 0, n)
        out += struct.pack("<%dI" % n, *offs)
        for b in blobs:
            out += b
        out += bytes(pad)
        return bytes(out)

    def by_id(self):
        return dict(self.entries)

    def set(self, sid, text):
        for i, (k, _) in enumerate(self.entries):
            if k == sid:
                self.entries[i] = (k, text)
                return
        raise KeyError(sid)


def main(argv):
    import argparse
    ap = argparse.ArgumentParser(description="LOC text file tool")
    ap.add_argument("cmd", choices=["dump", "check"])
    ap.add_argument("file")
    ap.add_argument("--grep")
    a = ap.parse_args(argv)
    data = open(a.file, "rb").read()
    loc = Loc.parse(data)
    if a.cmd == "check":
        same = loc.serialize() == data
        print("%d strings; re-serialized %s" % (len(loc.entries), "IDENTICAL" if same else "DIFFERENT"))
        return 0 if same else 1
    for sid, text in loc.entries:
        if a.grep and a.grep.lower() not in text.lower():
            continue
        print("%d\t%s" % (sid, text.replace("\n", "\\n")))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
