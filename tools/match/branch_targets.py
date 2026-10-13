"""Function-relative PPC branch targets from relocatable ELF code sections."""
import struct


def local_branch_destinations(elf, section_index):
    """Map function names to local destinations, one entry per instruction.

    Non-branches and external destinations are None. Resolve RELA branches
    before comparing: a self/section relocation and a resolved instruction
    must describe the same edge, even when their encoded displacements differ.
    """
    section_address = elf.secs[section_index][3]
    code = elf.sec_bytes(section_index)
    relocations = elf.relocs(section_index)
    result = {}
    for name, (address, size) in elf.funcs(section_index).items():
        start = address - section_address
        if start < 0 or size % 4 or start + size > len(code):
            raise ValueError('invalid function code range: ' + name)
        destinations = []
        for offset in range(start, start + size, 4):
            word, = struct.unpack_from('>I', code, offset)
            op = word >> 26
            target = None
            if op in (16, 18):
                relocation = relocations.get(offset)
                if relocation is not None:
                    symbol_index, kind, addend = relocation
                    symbol = elf.syms[symbol_index]
                    if kind in (10, 11, 12, 13) and symbol[4] == section_index:
                        target = symbol[1] - section_address + addend
                else:
                    bits = 16 if op == 16 else 26
                    displacement = word & (0xfffc if op == 16 else 0x03fffffc)
                    if displacement & (1 << (bits - 1)):
                        displacement -= 1 << bits
                    target = (displacement - section_address if word & 2
                              else offset + displacement)
            destinations.append(target - start if target is not None
                                and start <= target < start + size else None)
        result[name] = destinations
    return result
