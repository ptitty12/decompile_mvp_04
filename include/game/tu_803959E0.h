/*
 * Shared types of the VP6 video codec units (ealib/tu_803959E0..tu_803A0310).
 * Offsets were read from the original code: the decoder context allocated by
 * fn_80395C68 (0x4954 bytes) and the buffer pointers freed by fn_80395A94.
 */
#ifndef TU_803959E0_H
#define TU_803959E0_H

struct Vp6AllocArgs {
    int m0, m4, m8;
    Vp6AllocArgs() : m0(0), m4(0), m8(0) {}
};

/* Allocator object at lbl_806EE9C0; slot 1 allocates, slot 2 frees. */
struct Vp6Allocator {
    virtual void* Alloc(int size, const Vp6AllocArgs& args);
    virtual void Free(void* p, int flags);
};

/* Probability pair table: two 10-entry rows per entry (fn_8039CD38). */
struct Vp6Tab {
    unsigned char a[10];
    unsigned char b[10];
};

/* Range (bool) decoder state: range, value, bit counter, byte position and buffer. */
struct Vp6Rc {
    int m0, m4, m8, mC, m10;
    const unsigned char* m14;
};

struct Vp6Ctx;
struct Vp6SubB;
struct Vp6Tbl;
struct Vp6TblHolder;

struct Vp6Q {
    unsigned short a, b;
};



struct Vp6Params {
    unsigned m0, m4, m8, mC, m10, m14;
    int m18[8];
};

/* Frame buffer set (0xC8 bytes) built by fn_8039620C / fn_80396114. */
struct Vp6Buf {
    char pad0[0x24];
    void* m24;
    void* m28;
    void* m2C;
    char pad30[4];
    void* m34;
    char pad38[4];
    void* m3C;
    Vp6Params m40;
    int m78;
    int m7C;
    int m80;
    int m84;
    int m88;
    int m8C;
    int m90;
    int m94;
    int m98;
    int m9C;
    void* mA0;
    void* mA4;
    void* mA8;
    void* mAC;
    void* mB0;
    int mB4;
    void* mB8;
    void* mBC;
    int mC0;
    int mC4;
};

/* Decoder sub-object used by fn_80398B40 / fn_80398BEC. */
struct Vp6Dq {
    int m0;
    char pad4[8];
    int mC;
    char pad10[0x38 - 0x10];
    int* m38;
    int* m3C;
};

struct Vp6SubB {
    Vp6Buf* m0;
};

/* Per-macroblock flags: m18 data, m1C stride, m20 mask, m24 output (fn_803962D4). */
struct Vp6Mb {
    char pad0[0xC];
    int mC;
    char pad10[8];
    unsigned char* m18;
    unsigned m1C;
    unsigned m20;
    int* m24;
    char pad28[0x8C - 0x28];
    unsigned m8C;
};

/* Dequant table object (0x990 bytes) built by fn_80396DF0. */
struct Vp6Blk100 {
    int w[64];
};

struct Vp6Tbl {
    int m0;
    int m4;
    char pad8[0x38 - 8];
    int m38;
    int m3C[64];
    const int* m13C;
    unsigned char m140[0x40];
    unsigned short* m180;
    unsigned short* m184;
    void* m188;
    void* m18C;
};

struct Vp6TblHolder {
    Vp6Tbl* m0;
};

struct Vp6Ctx {
    void* m0;
    int m4;
    char pad8[0x104];
    int m10C;
    int m110;
    int m114;
    void* m118;
    void* m11C;
    void* m120;
    char pad124[0x18];
    Vp6Tbl* m13C;
    char pad140[0x8];
    int m148;
    void* m14C;
    Vp6Rc m150;
    char pad168[0x38];
    int m1A0;
    int m1A4;
    int m1A8;
    char pad1AC[0x4];
    Vp6Params m1B0;
    char pad1E8[0x4];
    int m1EC;
    int m1F0;
    int m1F4;
    int m1F8;
    int m1FC;
    int m200;
    int m204;
    int m208;
    int m20C;
    int m210;
    int m214;
    int m218;
    int m21C;
    int m220;
    int m224;
    int m228;
    int m22C;
    int m230;
    int m234;
    int m238;
    int m23C;
    int m240;
    int m244;
    void* m248;
    int m24C;
    void* m250;
    int m254;
    void* m258;
    char pad25C[0x4];
    void* m260;
    int m264;
    void* m268;
    int m26C;
    int m270;
    void* m274;
    int m278;
    int m27C;
    void* m280;
    int m284;
    void* m288;
    void* m28C;
    int m290;
    void* m294;
    Vp6Buf* m298;
    char pad29C[0x40C];
    int m6A8[12];
    char pad6D8[0x14];
    int m6EC;
    int m6F0;
    int m6F4;
    void* m6F8;
    void* m6FC;
    void* m700;
    char pad704[0x28];
    Vp6Tab m72C[3];
    char pad768[0x41D4];
    int m493C;
    int m4940;
    int m4944;
    int m4948;
    char pad494C[0x8];
};
void* fn_8000E5BC(int size);
extern "C" {
void* fn_803959E0(int size);
void fn_80395A44(void* p);
}
 /* C++ symbol fn_8000E5BC__Fi */
extern "C" {
void fn_8040ABC4(void* p);
void* memset(void* p, int c, unsigned n);
void* memcpy(void* d, const void* s, unsigned n);
int rand(void);
}
/* Some callers in this library pass memset/memcpy like an unprototyped function (crclr before the call). */
typedef void* (*Vp6MemsetV)(void*, int, ...);
typedef void* (*Vp6MemcpyV)(void*, const void*, ...);
#define MEMSET_V ((Vp6MemsetV)memset)
#define MEMCPY_V ((Vp6MemcpyV)memcpy)

#endif
