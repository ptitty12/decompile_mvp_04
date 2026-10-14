#!/usr/bin/env python3
"""EA RefPack (QFS) decompress and compress. Standard library only.

Stream layout (verified on the game's database.big entries and ovlay.big):

    flags   u8   0x10 here; bit 0x80 = 4-byte size fields, bit 0x01 = a
                 "compressed size" field is present (neither is set in the
                 files this project has seen)
    magic   u8   0xFB
    size    24-bit big-endian unpacked size (32-bit when flags & 0x80)
    ...commands...

Commands, by the first byte `a` (b, c, d are the following bytes):

    0x00-0x7F  2 bytes  copy a&3 literals, then reflen=((a>>2)&7)+3 bytes from
                        distance (((a&0x60)<<3)+b+1)
    0x80-0xBF  3 bytes  literals = b>>6, reflen=(a&0x3F)+4,
                        distance=((b&0x3F)<<8)+c+1
    0xC0-0xDF  4 bytes  literals = a&3, reflen=((a&0x0C)<<6)+d+5,
                        distance=((a&0x10)<<12)+(b<<8)+c+1
    0xE0-0xFB  1 byte   literal run of ((a&0x1F)<<2)+4 bytes
    0xFC-0xFF  1 byte   stop; copy a&3 trailing literals

The compressor is a straightforward greedy matcher. Its output decompresses
to the same bytes, but it is not guaranteed to equal EA's compressor output
byte for byte (see docs/ROSTERS.md).
"""
import struct
import sys


class RefPackError(ValueError):
    pass


def parse_header(data, pos=0):
    """Return (unpacked_size, header_length, flags)."""
    if len(data) - pos < 5:
        raise RefPackError("truncated header")
    flags, magic = data[pos], data[pos + 1]
    if magic != 0xFB or (flags & 0x7E) != 0x10:
        raise RefPackError("not a RefPack stream: %02x %02x" % (flags, magic))
    p = pos + 2
    if flags & 0x01:  # compressed size present
        p += 4 if flags & 0x80 else 3
    if flags & 0x80:
        size = struct.unpack(">I", data[p:p + 4])[0]
        p += 4
    else:
        size = (data[p] << 16) | (data[p + 1] << 8) | data[p + 2]
        p += 3
    return size, p - pos, flags


def is_refpack(data, pos=0):
    return (len(data) - pos >= 5 and data[pos + 1] == 0xFB
            and (data[pos] & 0x7E) == 0x10)


def decompress(data, pos=0):
    size, hlen, _flags = parse_header(data, pos)
    p = pos + hlen
    out = bytearray()
    n = len(data)
    while True:
        if p >= n:
            raise RefPackError("stream ended without a stop command")
        a = data[p]
        if a < 0x80:
            b = data[p + 1]
            lit = a & 3
            ref = ((a >> 2) & 7) + 3
            dist = ((a & 0x60) << 3) + b + 1
            p += 2
        elif a < 0xC0:
            b, c = data[p + 1], data[p + 2]
            lit = b >> 6
            ref = (a & 0x3F) + 4
            dist = ((b & 0x3F) << 8) + c + 1
            p += 3
        elif a < 0xE0:
            b, c, d = data[p + 1], data[p + 2], data[p + 3]
            lit = a & 3
            ref = ((a & 0x0C) << 6) + d + 5
            dist = ((a & 0x10) << 12) + (b << 8) + c + 1
            p += 4
        elif a < 0xFC:
            lit = ((a & 0x1F) << 2) + 4
            ref = 0
            dist = 0
            p += 1
        else:
            lit = a & 3
            ref = 0
            dist = 0
            p += 1
            out += data[p:p + lit]
            p += lit
            break
        out += data[p:p + lit]
        p += lit
        if ref:
            if dist > len(out):
                raise RefPackError("back-reference before start of output")
            s = len(out) - dist
            if dist >= ref:
                out += out[s:s + ref]
            else:  # overlapping copy
                for i in range(ref):
                    out.append(out[s + i])
    if len(out) != size:
        raise RefPackError("size mismatch: header %d, got %d" % (size, len(out)))
    return bytes(out)


def _emit_literals(out, lits):
    """Emit literal runs of 4..112 (multiples of 4) via 0xE0 commands.
    Return the 0-3 leftover literals (to ride on the next command)."""
    i = 0
    n = len(lits)
    while n - i >= 4:
        run = min(112, (n - i) & ~3)
        out.append(0xE0 | ((run - 4) >> 2))
        out += lits[i:i + run]
        i += run
    return lits[i:]


def compress(data, max_chain=64):
    """Greedy LZ77 compressor emitting RefPack with 24-bit sizes (or 32-bit
    when the input is >= 16 MiB). Not byte-identical to EA's tool."""
    n = len(data)
    big = n >= (1 << 24)
    out = bytearray()
    if big:
        out += bytes([0x90, 0xFB]) + struct.pack(">I", n)
    else:
        out += bytes([0x10, 0xFB]) + bytes([(n >> 16) & 255, (n >> 8) & 255, n & 255])
    heads = {}      # 3-byte key -> list of positions (most recent last)
    lits = bytearray()
    i = 0

    def insert(pos):
        if pos + 3 <= n:
            heads.setdefault(data[pos:pos + 3], []).append(pos)

    while i < n:
        best_len = 0
        best_dist = 0
        if i + 3 <= n:
            cands = heads.get(data[i:i + 3])
            if cands:
                for q in reversed(cands[-max_chain:]):
                    dist = i - q
                    if dist > 131072:
                        break
                    ln = 3
                    lim = min(1028, n - i)
                    while ln < lim and data[q + ln] == data[i + ln]:
                        ln += 1
                    if ln > best_len:
                        best_len, best_dist = ln, dist
                        if ln == lim:
                            break
        # choose a command form that can carry this match
        form = 0
        if best_len >= 3:
            if best_len <= 10 and best_dist <= 1024:
                form = 2
            elif best_len <= 67 and best_dist <= 16384 and best_len >= 4:
                form = 3
            elif best_len >= 5:
                form = 4
            if form == 0:
                best_len = 0
        if form == 0:
            lits.append(data[i])
            insert(i)
            i += 1
            continue
        # flush literals: leave 0-3 to ride on the match command
        rest = _emit_literals(out, lits)
        nl = len(rest)
        d = best_dist - 1
        ln = best_len
        if form == 2:
            out.append(((d >> 8) << 5) | ((ln - 3) << 2) | nl)
            out.append(d & 255)
        elif form == 3:
            out.append(0x80 | (ln - 4))
            out.append((nl << 6) | (d >> 8))
            out.append(d & 255)
        else:
            out.append(0xC0 | ((d >> 16) << 4) | (((ln - 5) >> 8) << 2) | nl)
            out.append((d >> 8) & 255)
            out.append(d & 255)
            out.append((ln - 5) & 255)
        out += rest
        lits = bytearray()
        for k in range(ln):
            insert(i + k)
        i += ln
    rest = _emit_literals(out, lits)
    out.append(0xFC | len(rest))
    out += rest
    return bytes(out)


def main(argv):
    import argparse
    ap = argparse.ArgumentParser(description="RefPack tool")
    ap.add_argument("mode", choices=["d", "c", "check"])
    ap.add_argument("src")
    ap.add_argument("dst", nargs="?")
    a = ap.parse_args(argv)
    data = open(a.src, "rb").read()
    if a.mode == "d":
        open(a.dst, "wb").write(decompress(data))
    elif a.mode == "c":
        open(a.dst, "wb").write(compress(data))
    else:
        out = decompress(data)
        again = decompress(compress(out))
        print("unpacked", len(out), "roundtrip", "OK" if again == out else "FAIL")
        return 0 if again == out else 1
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
