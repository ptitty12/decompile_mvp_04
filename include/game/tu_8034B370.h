#ifndef GAME_TU_8034B370_H
#define GAME_TU_8034B370_H

#include "game/tu_803401A8.h"
#include "game/tu_8007FF8C.h"
#include "game/clampiter.h"

/*
 * Shared types for the game tail 0x8034B370..0x80355A6C (range 27).
 */

/* Release family (fn_8034BBD0 and 151 clones): *pp points to an object whose
 * first word is an observer list (fn_803BA44C counts it, fn_803BA378 drops it);
 * the object is freed through virtual 2 of the allocator (vtable entry 2:
 * lha delta at +0x10, lwz pfn at +0x14) and *pp is cleared.  The release only
 * happens when the count is <= 1 or flag == 1. */
struct Unk803BA44C_Obj {
    void* m0;
};
extern "C" int fn_803BA44C(void* list, int* count);
extern "C" int fn_803BA378(void* list);

extern "C" void fn_8040074C(void* p, unsigned n); /* bzero */

/* Ring / array containers (fn_80353244 .. fn_80353F58 and the clones at
 * 0x80354xxx, 0x80355xxx, five instantiations of the same template): m0 is the
 * element buffer, m4 the element count, mC the cursor; a polymorphic variant
 * has its vptr at +0x10 (Unk80353ECC). Evidence: the getter/setter pair
 * fn_80353244 / fn_80353DA4, the wrap-around steps fn_80353880 / fn_80353F00
 * (unsigned modulo of mC by m4) and the virtual wrappers fn_80353ECC / F24. */
struct Unk80353E68 {
    int* m0;
    unsigned m4;
    int m8;
    unsigned mC;
    inline void Clear()
    {
        fn_8040074C(m0, m8 << 2);
        m4 = 0;
        mC = 0;
    }
    inline int Find(int v)
    {
        unsigned i;
        for (i = 0; i < m4; i++) {
            if (m0[i] == v)
                return i;
        }
        return -1;
    }
    inline void Add(int v)
    {
        if (m4 < m8) {
            m0[m4] = v;
            m4++;
        }
    }
};
struct Unk80353ECC : Unk80353E68 {
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

/* Byte-element variant of the ring (fn_80353234, fn_80353DAC, fn_80354FD4). */
struct Unk80353234 {
    unsigned char* m0;
    unsigned m4;
    int m8;
    unsigned mC;
    inline void Clear()
    {
        fn_8040074C(m0, m8);
        m4 = 0;
        mC = 0;
    }
};
void fn_80341598(Unk8034151C* t, int v);
void fn_8034166C(Unk803415F0* t, int v);
extern "C" void* fn_8040B190(void* dst, const void* src, int n); /* memcpy */

/* Ring of 0x24-byte elements (fn_803541D4, fn_80354244, fn_803542CC return
 * the element by value through the hidden pointer in r3). */
struct Unk803541D4_E {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    inline int EqLo(const Unk803541D4_E& o) const
    {
        int r = 0;
        if (m8 == o.m8)
            r = mC == o.mC;
        return r;
    }
    inline int Eq(const Unk803541D4_E& o) const
    {
        int lo = EqLo(o);
        int r = 0;
        if (o.m0 == m0 && lo)
            r = 1;
        return r;
    }
    inline int EqAll(const Unk803541D4_E& o) const
    {
        int r = 0;
        if (o.m1C == m1C && m20 == o.m20) {
            if (Eq(o))
                r = 1;
        }
        return r;
    }
};
struct Unk803541D4 {
    Unk803541D4_E* m0;
    unsigned m4;
    int m8;
    unsigned mC;
};

/* Pool of Unk803541D4_E elements (ring at +0), vptr at +0x10 (virtual 19
 * answers whether element i is live) and an index ring at +0x14. */
struct Unk80354940_V : Unk803541D4 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual int v19(int i);
};
struct Unk80354940 : Unk80354940_V {
    Unk80353E68 m14;
};
/* Ring of 0x1C-byte elements (fn_80355414, fn_80355460, fn_803554C8). */
struct Unk80355414_E {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    inline int EqLo(const Unk80355414_E& o) const
    {
        int r = 0;
        if (m8 == o.m8)
            r = mC == o.mC;
        return r;
    }
    inline int Eq(const Unk80355414_E& o) const
    {
        int lo = EqLo(o);
        int r = 0;
        if (o.m0 == m0 && lo)
            r = 1;
        return r;
    }
};
struct Unk80355414 {
    Unk80355414_E* m0;
    unsigned m4;
    int m8;
    unsigned mC;
};

/* Block of 0x3C bytes whose four 12-byte records are cleared by fn_80080B98
 * (the Unk8007FF8C_Z of tu_8007FF8C.h): the member array constructs each
 * record (fn_80353930 loops with a post-decrement counter), fn_80355354 sets
 * the header bytes and walks the records again. */
void fn_80080B98(Unk8007FF8C_Q* q);
struct Unk80353930_Q {
    unsigned char m0;
    unsigned char m1;
    int m4;
    int m8;
    Unk80353930_Q() { fn_80080B98((Unk8007FF8C_Q*)this); }
};
struct Unk80353930 {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    short pad6;
    int m8;
    Unk80353930_Q q[4];
    Unk80353930();
};
void fn_80355354(Unk80353930* z);

/* Rings with a vptr at +0x10 whose virtual 3 returns the current element by
 * value (fn_80354430, fn_80355608). */
struct Unk80355608 : Unk80355414 {
    virtual void v1();
    virtual void v2();
    virtual Unk80355414_E v3();
};
struct Unk80354430 : Unk803541D4 {
    virtual void v1();
    virtual void v2();
    virtual Unk803541D4_E v3();
};
/* Rings that carry a vptr slot at +0x10 and are initialised over inline
 * storage (fn_803537FC byte ring, fn_80353A9C / fn_80353B3C int rings). The
 * Init() inline gives the sub-object pointer plus the offset-0 fold. */
struct Unk803537FC_R {
    unsigned char* m0;
    unsigned m4;
    int m8;
    unsigned mC;
    const void* m10;
    inline void Init(unsigned char* buf, int n, const void* vt)
    {
        m10 = vt;
        m0 = buf;
        m8 = n;
        fn_8040074C(m0, n);
        m4 = 0;
        mC = 0;
    }
    inline void Clear()
    {
        fn_8040074C(m0, m8);
        m4 = 0;
        mC = 0;
    }
};
struct Unk803536B0 {
    int m0;
    Unk803537FC_R m4;
    unsigned char m18[10];
    int m24;
    unsigned char m28[0xC];
    char m34[1];
};
struct Unk80353A9C_R {
    int* m0;
    unsigned m4;
    int m8;
    unsigned mC;
    const void* m10;
    inline void Init(void* buf, int n, int bytes, const void* vt)
    {
        m10 = vt;
        m0 = (int*)buf;
        m8 = n;
        fn_8040074C(m0, bytes);
        m4 = 0;
        mC = 0;
    }
};

/* Three-int accumulator (fn_8035300C / fn_80353110: clear the output, ask
 * fn_800838E0 for a list of up to 128 ids, and for each live id add the
 * triple that fn_80083838 / fn_8008388C fills in). */
struct Unk8035300C_V3 {
    int x;
    int y;
    int z;
    inline void Add(const Unk8035300C_V3& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
    }
};
extern "C" void* fn_8040B320(void* dst, int c, unsigned n); /* memset */
extern "C" int fn_800838E0(int a, int b, int c, int d, int* list);
extern "C" void fn_80083838(int a, int b, int c, int d, Unk8035300C_V3* out);
extern "C" void fn_8008388C(int a, int b, int c, int d, Unk8035300C_V3* out);

extern "C" void fn_8009619C(void* p);
extern "C" void fn_80377408(void* p);
extern "C" void fn_80377488(void* p);

#endif
