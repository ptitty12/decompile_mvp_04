"""Tiny ELF32 inspector (either endianness) + ar archive lister."""
import struct, sys

def elf(data, verbose=True):
    assert data[:4] == b'\x7fELF'
    e = '>' if data[5] == 2 else '<'
    (etype, mach, ver, entry, phoff, shoff, flags, ehsize, phentsize, phnum,
     shentsize, shnum, shstrndx) = struct.unpack(e + 'HHIIIIIHHHHHH', data[16:52])
    print(f'endian={e} type={etype} machine={mach} entry={entry:#x} flags={flags:#x} phnum={phnum} shnum={shnum}')
    secs = []
    for i in range(shnum):
        o = shoff + i * shentsize
        secs.append(struct.unpack(e + 'IIIIIIIIII', data[o:o + 40]))
    shstr = secs[shstrndx] if shnum else None
    def nm(off, tab):
        s = tab[4]
        return data[s + off:data.index(b'\0', s + off)].decode('latin1')
    out = []
    for i, s in enumerate(secs):
        name = nm(s[0], shstr) if shstr else '?'
        out.append((name, s))
        if verbose:
            print(f'  [{i:2}] {name:24} type={s[1]:#x} flags={s[2]:#x} addr={s[3]:#010x} off={s[4]:#x} size={s[5]:#x} link={s[6]} info={s[7]} align={s[8]}')
    for i in range(phnum):
        o = phoff + i * phentsize
        p = struct.unpack(e + 'IIIIIIII', data[o:o + 32])
        if verbose:
            print(f'  PH type={p[0]} off={p[1]:#x} vaddr={p[2]:#x} filesz={p[4]:#x} memsz={p[5]:#x} flags={p[6]}')
    return e, out

def symbols(data, e, secs):
    for name, s in secs:
        if s[1] == 2:  # SYMTAB
            strtab = secs[s[6]][1]
            res = []
            for o in range(s[4], s[4] + s[5], 16):
                st_name, val, size, info, other, shndx = struct.unpack(e + 'IIIBBH', data[o:o + 16])
                n = data[strtab[4] + st_name:data.index(b'\0', strtab[4] + st_name)].decode('latin1')
                res.append((n, val, size, info, shndx))
            return res
    return []

def ar(data):
    assert data[:8] == b'!<arch>\n'
    o = 8
    members = []
    longnames = b''
    while o < len(data):
        hdr = data[o:o + 60]
        name = hdr[:16].decode('latin1').strip()
        size = int(hdr[48:58].decode().strip())
        body = data[o + 60:o + 60 + size]
        if name == '//':
            longnames = body
        elif name.startswith('/') and name[1:].strip().isdigit():
            i = int(name[1:])
            name = longnames[i:longnames.index(b'\n', i)].decode('latin1')
        members.append((name, size, body))
        o += 60 + size + (size & 1)
    return members

if __name__ == '__main__':
    d = open(sys.argv[1], 'rb').read()
    if d[:8] == b'!<arch>\n':
        ms = ar(d)
        print(len(ms), 'members')
        for n, s, b in ms[:int(sys.argv[2]) if len(sys.argv) > 2 else 40]:
            print(f'  {s:9d} {n!r} magic={b[:8]!r}')
    else:
        e, secs = elf(d)
        syms = symbols(d, e, secs)
        print('symbols:', len(syms))
        for x in syms[:int(sys.argv[2]) if len(sys.argv) > 2 else 30]:
            print('  ', x)
