#ifndef GAME_TU_8000C2C4_H
#define GAME_TU_8000C2C4_H

/*
 * On-screen debug console ("DBGVIOCtrl (SI)" string at 0x805A3B44) drawn into
 * the external framebuffer with an 8x8 4-bit font (0xC00 bytes at 0x806158B8,
 * 32 bytes per glyph from ' ').
 *
 * Unk80634ADC: render-mode record at 0x80634ADC (same layout as GXRenderModeObj).
 * Evidence: fn_8000C2C4 reads the u16 at +4 and +8 to size the framebuffer as
 * ((m4 + 15) & 0xFFF0) * m8 * 2 bytes; fn_8000C354 passes the u16 at +4 as the
 * line width to the glyph blitter (fn_8000C704).
 */
/*
 * SysV varargs record. gcc 2.95's __builtin_saveregs spills r3..r10/f1..f8 and
 * returns the address of a 12-byte block {gpr, fpr, overflow area, save area};
 * va_start copies that block into the caller's va_list. That copy is the extra
 * 12-byte stack object in fn_8000C674 (0x70), next to the block (0x80). The
 * array typedef makes a va_list parameter a pointer (fn_8000C5D8 tests it).
 */
struct va_list_tag {
    char gpr;
    char fpr;
    char* overflow_arg_area;
    char* reg_save_area;
};
typedef va_list_tag va_list[1];
#define va_start(AP, LASTARG) (__builtin_next_arg(LASTARG), *(AP) = *(va_list_tag*)__builtin_saveregs())

struct Unk80634ADC {
    unsigned int m0;
    unsigned short m4;
    unsigned short m6;
    unsigned short m8;
};

/*
 * Three-word color record: default at 0x80615854 (a 0x48-byte table), copied
 * to Unk8000C2C4::m10 by the constructor and by fn_8000C464. fn_8000C408 packs
 * m0/m4/m8 into the low 24 bits of each framebuffer word (m4 << 16 | m0 << 8 |
 * m8); fn_8000C354 uses the low halves of m0 and m4 as a 16-bit glyph color.
 */
struct Unk80615854 {
    int m0;
    int m4;
    int m8;
};

/*
 * Console object (0x20 bytes), allocated through the function pointer at
 * 0x8062C668 (called with 0x20, 0) in fn_8000C4A8, which stores it in
 * 0x80615850. Offsets: fn_8000C2C4 (ctor), fn_8000C354 (print), fn_8000C408
 * (clear), fn_8000C480 (flip).
 */
struct Unk8000C2C4 {
    Unk8000C2C4(unsigned char* fb, Unk80634ADC* rmode);
    void fn_8000C340(int v);
    void fn_8000C348(short x, short y);
    void fn_8000C354(const char* s);
    void fn_8000C408(const Unk80615854* c);
    void fn_8000C464(const Unk80615854* c);
    void fn_8000C480();

    unsigned char* m0;         /* framebuffer */
    Unk80634ADC* m4;           /* render mode */
    unsigned int m8;           /* framebuffer size in bytes */
    short mC;                  /* cursor x */
    short mE;                  /* cursor y */
    Unk80615854 m10;           /* color */
    int m1C;                   /* also echo to the debug output when non-zero */
};

/*
 * Plain 3-float vector (the static initializer at 0x8000C840 builds thirteen
 * unit vectors in .bss from a table of points in .rodata).
 */
struct Unk8000C840_Vec3 {
    float x;
    float y;
    float z;
};

#endif
