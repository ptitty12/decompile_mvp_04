"""Minimal read-only CISO + GameCube GCM reader for Phase 0 recon."""
import struct, sys, os

class CISO:
    def __init__(self, path):
        self.f = open(path, 'rb')
        h = self.f.read(0x8000)
        assert h[:4] == b'CISO', h[:4]
        self.bs = struct.unpack('<I', h[4:8])[0]
        self.map = {}
        n = 0
        for i, b in enumerate(h[8:]):
            if b == 1:
                self.map[i] = 0x8000 + n * self.bs
                n += 1

    def read(self, off, size):
        out = bytearray()
        while size > 0:
            blk, bo = divmod(off, self.bs)
            take = min(size, self.bs - bo)
            if blk in self.map:
                self.f.seek(self.map[blk] + bo)
                out += self.f.read(take)
            else:
                out += b'\0' * take
            off += take; size -= take
        return bytes(out)

class GCM:
    def __init__(self, dev):
        self.d = dev
        self.boot = dev.read(0, 0x440)
        self.bi2 = dev.read(0x440, 0x2000)
        self.dol_off, self.fst_off, self.fst_size = struct.unpack('>III', self.boot[0x420:0x42c])
        fst = dev.read(self.fst_off, self.fst_size)
        n = struct.unpack('>I', fst[8:12])[0]
        strtab = fst[n * 12:]
        self.files = []  # (path, offset, size)
        self.dirs = []
        def name(i):
            o = struct.unpack('>I', fst[i*12:i*12+4])[0] & 0xffffff
            return strtab[o:strtab.index(b'\0', o)].decode('shift_jis', 'replace')
        # walk
        stack = [(n, '')]
        i = 1
        while i < n:
            while stack and i >= stack[-1][0]:
                stack.pop()
            typ = fst[i*12]
            a, b = struct.unpack('>II', fst[i*12+4:i*12+12])
            nm = name(i)
            parent = stack[-1][1] if stack else ''
            p = parent + '/' + nm
            if typ == 1:
                self.dirs.append(p)
                stack.append((b, p))
            else:
                self.files.append((p, a, b))
            i += 1

    def dol_size(self):
        h = self.d.read(self.dol_off, 0x100)
        offs = struct.unpack('>18I', h[0:72])
        sizes = struct.unpack('>18I', h[0x90:0x90+72])
        return max(o + s for o, s in zip(offs, sizes) if s)

if __name__ == '__main__':
    g = GCM(CISO(sys.argv[1]))
    print('dol_off', hex(g.dol_off), 'dol_size', hex(g.dol_size()), 'fst', hex(g.fst_off), hex(g.fst_size))
    print('apploader date', g.d.read(0x2440, 16))
    if len(sys.argv) > 2 and sys.argv[2] == 'list':
        for p, o, s in g.files:
            print(f'{o:08x} {s:10d} {p}')
    if len(sys.argv) > 3 and sys.argv[2] == 'extract':
        outdir = sys.argv[3]
        os.makedirs(outdir, exist_ok=True)
        open(os.path.join(outdir, 'main.dol'), 'wb').write(g.d.read(g.dol_off, g.dol_size()))
        open(os.path.join(outdir, 'boot.bin'), 'wb').write(g.boot)
        open(os.path.join(outdir, 'bi2.bin'), 'wb').write(g.bi2)
        for want in sys.argv[4:]:
            for p, o, s in g.files:
                if p == want:
                    dst = os.path.join(outdir, p.strip('/').replace('/', '__'))
                    open(dst, 'wb').write(g.d.read(o, s))
                    print('extracted', p, s)
