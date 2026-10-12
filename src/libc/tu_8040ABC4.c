/*
 * SN ProDG libc, newlib 1.8.2 (cflags_libc: -O2 -fno-common, default -G8),
 * .text 0x8040ABC4-0x8040AC00 (code-only unit, 1 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

extern char lbl_8060EC0C[];
extern void fn_80433CE8(int a, int b, const char *fmt, ...);

/* near-miss (11/15 slots): the original reads the link register directly (`mflr r6; addi r6,r6,-4`);
 * __builtin_return_address(0) walks the frame (`lwz r9,0(r1); lwz r6,4(r9)`) with every flag tried
 * (-fomit-frame-pointer, -G0). ProDG library stub: reports the external call to 'free' (lbl_8060EC0C is
 * the message pool: 'free', 'realloc', 'calloc'). */
void fn_8040ABC4(void)
{
    fn_80433CE8(0, 0, lbl_8060EC0C, (char *)__builtin_return_address(0) - 4);
}
