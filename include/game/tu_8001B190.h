/*
 * Types for game/tu_8001B190.cpp and game/tu_8001BA78.cpp (reconstructed,
 * placeholder names; nothing here comes from original headers).
 *
 * Unk803445A8: abstract base of a small allocator interface. Evidence: the
 * vtable at 0x80649C48 (data dump) has fn_804144B8 in slots 1-4 (a
 * pure-virtual stub, so four pure virtuals) and fn_803445BC in slot 5 (the
 * dtor); its ctor is fn_803445A8 (out of line, one vptr store); the derived
 * dtor fn_8001BB04 stores 0x80649C48 into the vptr itself, so the base dtor is
 * an inline one. Size 4 (vptr only).
 *
 * Unk8001BA78: the singleton at lbl_806164E8 (0xC bytes: vptr, +4 heap handle
 * from fn_803ED9D4, +8 a 0x6400-byte buffer). Vtable at 0x80649C10 (data
 * dump): slot 1 fn_8001BA14, 2 fn_8001BA40, 3 fn_8001BA68, 4 fn_8001BA70,
 * 5 fn_8001BB04 (dtor). Slot 1 and 2 are called with a third/second argument
 * the overrides ignore (fn_8001B950, fn_8001B9C0): a 12-byte struct of zeros
 * (passed by invisible reference) and a 0.
 */
#ifndef GAME_TU_8001B190_H
#define GAME_TU_8001B190_H

void* operator new(unsigned int size, int heap);      /* 0x80377428 */
void* operator new[](unsigned int size, int heap);    /* 0x803774A8 */

struct Unk8001B950_Zero3 {
    Unk8001B950_Zero3() : m0(0), m4(0), m8(0) {}
    int m0;
    int m4;
    int m8;
};

class Unk803445A8 {
public:
    Unk803445A8();
    virtual void* fn_vslot1(unsigned n, const Unk8001B950_Zero3& z) = 0;
    virtual void fn_vslot2(void* p, int x) = 0;
    virtual int fn_vslot3() = 0;
    virtual int fn_vslot4() = 0;
    virtual ~Unk803445A8() {}
};

class Unk8001BA78 : public Unk803445A8 {
public:
    Unk8001BA78();
    virtual void* fn_vslot1(unsigned n, const Unk8001B950_Zero3& z);   /* 0x8001BA14 */
    virtual void fn_vslot2(void* p, int x);                     /* 0x8001BA40 */
    virtual int fn_vslot3();                                    /* 0x8001BA68 */
    virtual int fn_vslot4();                                    /* 0x8001BA70 */
    virtual ~Unk8001BA78();                                     /* 0x8001BB04 */
    int m4;
    char* m8;
};

Unk8001BA78* fn_8001BB7C();

/*
 * Unk8001BC8C: the 0x14-byte singleton at lbl_806164F0. Evidence: ctor
 * fn_8001BC8C (+0xC = -1, +4/+8/+0x10 = 0, +0 = fn_80020BCC(lbl_80686D90),
 * registers itself in lbl_806164F0), dtor fn_8001BD58 (clears the global,
 * calls fn_8001C89C on the Unk8001C314 singleton), fn_8001BD40 decrements +0xC
 * while it is not negative. No vptr.
 */
class Unk8001BC8C {
public:
    Unk8001BC8C();
    ~Unk8001BC8C();
    void fn_8001BD40();
    void fn_8001BDAC(int cmd);
    float fn_8001C048(int idx);
    void fn_8001C05C(int idx, float value, int flag);
    void fn_8001C190(int idx, int val, int flag);
    void fn_8001C28C(int bits);
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

/*
 * Unk80328234: base of Unk8001C314 (0x18 bytes of data, then the vptr at
 * +0x18, so it introduces the virtuals). Evidence: Unk8001C314's ctor calls
 * fn_80328234(this, 0x12, 0) and then overwrites the vptr at +0x18 with
 * lbl_80649B28 (vtable at 0x80649B28 in the data dump: slot 1 fn_8001C3E0 =
 * the Unk8001C314 dtor, 2..4 fn_80344404 / fn_80344408 / fn_8034446C, 5
 * fn_8001C9B8). Its dtor fn_80328374 is called by fn_8001C3E0 with r4
 * (in-charge) untouched, as docs/PATTERNS.md describes.
 */
class Unk80328234 {
public:
    Unk80328234(int a, int b);
    virtual ~Unk80328234();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    char pad0[0x18];
};

struct Unk8001C314_Slot {
    int m0;
    int m4;
};

/*
 * Unk8001C314: the 0x70-byte singleton at lbl_806164F4. Evidence: ctor
 * fn_8001C314 (vptr at +0x18, eight {-1, 0} pairs at +0x24, zeros at
 * +0x64/+0x68/+0x6C), getter fn_8001C394, fn_8001C410 reads +0x68/+0x64/+0x28.
 */
class Unk8001C314 : public Unk80328234 {
public:
    Unk8001C314();
    virtual ~Unk8001C314();                 /* slot 1: 0x8001C3E0 */
    virtual void fn_vslot5();               /* slot 5: 0x8001C9B8 */
    int fn_8001C620(int idx);
    void fn_8001C89C(int idx);
    void fn_8001C410();
    void fn_8001C50C();
    void fn_8001C568();
    void fn_8001CACC();
    void fn_8001CC04(int* result, int v);
    int fn_8001CC40(int idx);
    char pad1C[8];
    Unk8001C314_Slot m24[8];
    char* m64;
    int m68;
    int m6C;
};

Unk8001C314* fn_8001C394();

#endif
