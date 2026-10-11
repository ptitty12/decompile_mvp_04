"""DOL loader + minimal PPC decoder for recon (no external deps)."""
import struct

class DOL:
    def __init__(self, path):
        self.raw = open(path, 'rb').read()
        h = self.raw[:0x100]
        offs = struct.unpack('>18I', h[0:72])
        addrs = struct.unpack('>18I', h[72:144])
        sizes = struct.unpack('>18I', h[144:216])
        self.bss_addr, self.bss_size, self.entry = struct.unpack('>III', h[216:228])
        self.secs = []  # (kind, idx, addr, size, fileoff)
        for i in range(18):
            if sizes[i]:
                self.secs.append(('T' if i < 7 else 'D', i if i < 7 else i - 7, addrs[i], sizes[i], offs[i]))

    def text(self):
        return [s for s in self.secs if s[0] == 'T']

    def read(self, addr, n):
        for k, i, a, s, o in self.secs:
            if a <= addr < a + s:
                return self.raw[o + addr - a:o + addr - a + n]
        return None

    def u32(self, addr):
        b = self.read(addr, 4)
        return struct.unpack('>I', b)[0] if b and len(b) == 4 else None

    def in_text(self, addr):
        return any(a <= addr < a + s for k, i, a, s, o in self.text())

    def words(self, sec):
        k, i, a, s, o = sec
        for j in range(0, s, 4):
            yield a + j, struct.unpack('>I', self.raw[o + j:o + j + 4])[0]

def sext(v, bits):
    return v - (1 << bits) if v & (1 << (bits - 1)) else v

SPR = {8: 'lr', 9: 'ctr', 1: 'xer', 912: 'gqr0', 913: 'gqr1', 914: 'gqr2', 915: 'gqr3', 916: 'gqr4',
       917: 'gqr5', 918: 'gqr6', 919: 'gqr7', 920: 'hid2', 1008: 'hid0', 1009: 'hid1', 1017: 'l2cr', 26: 'srr0', 27: 'srr1'}

def dis(addr, w):
    op = w >> 26
    rd = (w >> 21) & 31; ra = (w >> 16) & 31; rb = (w >> 11) & 31
    simm = sext(w & 0xffff, 16); uimm = w & 0xffff
    if op == 18:
        tgt = sext(w & 0x3fffffc, 26) + (0 if w & 2 else addr)
        return ('bl' if w & 1 else 'b') + (' ' if True else '') + f'{tgt & 0xffffffff:#x}'
    if op == 16:
        tgt = sext(w & 0xfffc, 16) + (0 if w & 2 else addr)
        return f'bc{"l" if w & 1 else ""} {rd},{ra},{tgt & 0xffffffff:#x}'
    if op == 19:
        xo = (w >> 1) & 1023
        if w == 0x4e800020: return 'blr'
        if w == 0x4e800021: return 'blrl'
        if w == 0x4e800420: return 'bctr'
        if w == 0x4e800421: return 'bctrl'
        if w == 0x4c00012c: return 'isync'
        if w == 0x4c000064: return 'rfi'
        return f'op19.{xo} {w:#010x}'
    if op == 15: return f'lis r{rd},{uimm:#x}' if ra == 0 else f'addis r{rd},r{ra},{simm:#x}'
    if op == 14: return f'li r{rd},{simm}' if ra == 0 else f'addi r{rd},r{ra},{simm}'
    if op == 24: return f'ori r{ra},r{rd},{uimm:#x}' if w else 'nop'
    if op == 25: return f'oris r{ra},r{rd},{uimm:#x}'
    if op == 28: return f'andi. r{ra},r{rd},{uimm:#x}'
    if op == 11: return f'cmpwi cr{rd >> 2},r{ra},{simm}'
    if op == 10: return f'cmplwi cr{rd >> 2},r{ra},{uimm}'
    if op == 21:
        sh = rb; mb = (w >> 6) & 31; me = (w >> 1) & 31
        return f'rlwinm r{ra},r{rd},{sh},{mb},{me}'
    names = {32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu',
             40: 'lhz', 42: 'lha', 44: 'sth', 46: 'lmw', 47: 'stmw', 48: 'lfs', 50: 'lfd', 52: 'stfs',
             54: 'stfd', 55: 'stfdu', 56: 'psq_l', 60: 'psq_st'}
    if op in names:
        if op in (56, 60):
            return f'{names[op]} f{rd},{sext(w & 0xfff, 12)}(r{ra}),{(w >> 15) & 1},qr{(w >> 12) & 7}'
        reg = 'f' if op >= 48 else 'r'
        return f'{names[op]} {reg}{rd},{simm}(r{ra})'
    if op == 31:
        xo = (w >> 1) & 1023
        if xo == 339:
            spr = ((w >> 16) & 31) | (((w >> 11) & 31) << 5)
            return f'mfspr r{rd},{SPR.get(spr, spr)}'
        if xo == 467:
            spr = ((w >> 16) & 31) | (((w >> 11) & 31) << 5)
            return f'mtspr {SPR.get(spr, spr)},r{rd}'
        if xo == 444:
            return f'mr r{ra},r{rd}' if rd == rb else f'or r{ra},r{rd},r{rb}'
        if xo == 83: return f'mfmsr r{rd}'
        if xo == 146: return f'mtmsr r{rd}'
        if xo == 598: return 'sync'
        if xo == 266: return f'add r{rd},r{ra},r{rb}'
        if xo == 40: return f'subf r{rd},r{ra},r{rb}'
        if xo == 0: return f'cmpw cr{rd >> 2},r{ra},r{rb}'
        if xo == 32: return f'cmplw cr{rd >> 2},r{ra},r{rb}'
        if xo == 86: return f'dcbf r{ra},r{rb}'
        if xo == 982: return f'icbi r{ra},r{rb}'
        if xo == 54: return f'dcbst r{ra},r{rb}'
        if xo == 1014: return f'dcbz r{ra},r{rb}'
        return f'op31.{xo} {w:#010x}'
    return f'.word {w:#010x}'
