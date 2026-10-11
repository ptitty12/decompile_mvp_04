/*
 * Linker script for GV4E69 (MVP Baseball 2005), SN ProDG ngcld.
 *
 * Output section names, order and addresses mirror the retail /mvp.elf
 * section table (docs/RECON_REPORT.md section 1). Every gap between output
 * sections in the retail layout is exactly an ALIGN(32) step, so only .init's
 * address is fixed here.
 *
 * ngcld picks its own program headers (its PHDRS support crashes), so the
 * retail DOL grouping is applied by tools/mkdol.py --layout dol_layout.txt.
 *
 * Input section names: dtk's symbols.txt grammar only allows [A-Za-z0-9.] in
 * section names, so the two code overlays are split as `.feoverlay` and
 * `.dboverlay` and renamed back to their retail output names below.
 * (`.batter_codeoverlay` is empty in retail and is not emitted.)
 */
ENTRY(fn_80003100)

SECTIONS
{
    .init 0x80003100 : { *(.init) } =0

    . = ALIGN(32);
    .text : { *(.text) } =0

    . = ALIGN(32);
    .frontend_codeoverlay : { *(.feoverlay) } =0

    . = ALIGN(32);
    .database_codeoverlay : { *(.dboverlay) } =0

    /* GCC-style lists: 0xFFFFFFFF, entries..., 0. The 0xFFFFFFFF head comes
     * from the split objects; dtk omits the 0 terminator (CodeWarrior's
     * linker appends it implicitly, ngcld does not), so it is added here.
     * `_ctors` is referenced by the global-ctor runner @ 0x80413888. */
    . = ALIGN(32);
    .ctors : { _ctors = .; *(.ctors) LONG(0) }

    . = ALIGN(32);
    .dtors : { _dtors = .; *(.dtors) LONG(0) }

    . = ALIGN(32);
    .rodata : { *(.rodata) }

    . = ALIGN(32);
    .data : { *(.data) }

    . = ALIGN(32);
    .bss : { *(.bss) *(COMMON) }

    . = ALIGN(32);
    .sdata :
    {
        /* SN convention, confirmed by retail crt0 @ 0x80003108..0x80003114:
         * r13 = .sdata + 0x8000 = 0x806F69C0, r2 = .sdata + 0x18000 = 0x807069C0 */
        _SDA_BASE_ = . + 0x8000;
        _SDA2_BASE_ = . + 0x18000;
        *(.sdata)
    }

    . = ALIGN(32);
    .sbss : { *(.sbss) *(.scommon) }

    . = ALIGN(32);
    .sdata2 : { *(.sdata2) }
    .sbss2 : { *(.sbss2) }
}
