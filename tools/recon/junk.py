"""GameCube disc junk (lagged Fibonacci) regenerator, validated against present data.

Usage: python junk.py <disc.ciso> validate
       python junk.py <disc.ciso> sha1
"""
import sys, os, struct, hashlib
sys.path.insert(0, os.path.dirname(__file__))
from gcdisc import CISO, GCM

K, J, SEED = 521, 32, 17
BLOCK = 0x8000  # reseeded every 0x8000-byte sector (validated)
M = 0xffffffff
DISC_SIZE = 0x57058000

def junk_block(game_id4, disc_num, block_offset):
    """Return BLOCK bytes of junk for the 0x8000-aligned sector at block_offset."""
    i0, i1, i2, i3 = game_id4
    seed = ((i2 << 24) | (i1 << 16) | (((i3 + i2) & 0xff) << 8) | ((i0 + i1) & 0xff)) ^ disc_num
    sector = block_offset // 0x8000
    n = ((seed * 0x260BCD5) ^ (sector * 0x1EF29123)) & M
    buf = [0] * K
    for i in range(SEED):
        v = 0
        for _ in range(J):
            n = (n * 0x5D588B65 + 1) & M
            v = (v >> 1) | (n & 0x80000000)
        buf[i] = v
    buf[16] ^= (buf[0] >> 9) ^ ((buf[16] << 23) & M)
    for i in range(SEED, K):
        buf[i] = (((buf[i - 17] << 23) & M) ^ (buf[i - 16] >> 9) ^ buf[i - 1])
    buf = [(x & 0xFF00FFFF) | ((x >> 2) & 0x00FF0000) for x in buf]

    def forward():
        for i in range(J):
            buf[i] ^= buf[i + K - J]
        for i in range(J, K):
            buf[i] ^= buf[i - J]
    for _ in range(4):
        forward()
    out = bytearray()
    while len(out) < BLOCK:
        out += struct.pack('>521I', *buf)
        forward()
    return bytes(out[:BLOCK])

def main():
    dev = CISO(sys.argv[1])
    g = GCM(dev)
    gid = g.boot[:4]
    disc = g.boot[6]
    last = max(o + s for p, o, s in g.files)
    present_end = (max(dev.map) + 1) * dev.bs
    if sys.argv[2] == 'validate':
        # find the first non-zero byte after the last file, compare from there to the end of present data
        start = last
        probe = dev.read(last, 0x100)
        start = last + next(i for i, b in enumerate(probe) if b)
        blk = start // BLOCK * BLOCK
        total = mism = 0
        while blk < present_end:
            j = junk_block(gid, disc, blk)
            lo = max(start, blk)
            real = dev.read(lo, blk + BLOCK - lo)
            gen = j[lo - blk:]
            total += len(real)
            mism += sum(1 for a, b in zip(real, gen) if a != b)
            print(f'block {blk:#x}: compared {len(real):#x} bytes, mismatches so far {mism}')
            blk += BLOCK
        print(f'junk starts at {start:#x}; compared {total} bytes; mismatched {mism}')
        print('VALID' if total and mism == 0 else 'INVALID')
    elif sys.argv[2] == 'sha1':
        h = hashlib.sha1()
        off = 0
        CH = 0x200000
        while off < present_end:
            h.update(dev.read(off, CH)); off += CH
        blk = present_end
        while blk < DISC_SIZE:
            h.update(junk_block(gid, disc, blk)[:min(BLOCK, DISC_SIZE - blk)])
            blk += BLOCK
        print('reconstructed size', hex(DISC_SIZE), 'sha1', h.hexdigest())

main()
