/*
 * Database overlay code, .database_codeoverlay 0x80596D88-0x80599594 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"
#include "game/tu_8008CE64.h"
#include "game/db_80596D88.h"

struct U {
    char pad0[0x4000];
};

#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))

extern char lbl_80682D30[];
extern "C" void fn_8040074C(void* p, unsigned n);

extern "C" void fn_80377408(void* p);

extern char lbl_80682EB0[];

struct Db80596D88_Obj {
    int m0;
    short m4;
    char pad6[2];
    int m8;
    short mC;
    char padE[2];
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    const void* m34;
};

/* near-miss: retail gives the halfword at +4 its own zero register (li r10/r9) and keeps the vptr store first */
//@80596D88
extern "C" DB_OVERLAY void fn_80596D88(Db80596D88_Obj* self)
{
    self->m34 = lbl_80682EB0;
    self->m4 = 0;
    self->m30 = 0;
    self->m8 = 0;
    self->mC = 0;
    self->m10 = 0;
    self->m1C = 0;
    self->m20 = 0;
    self->m24 = 0;
    self->m28 = 0;
    self->m2C = 0;
}

extern "C" DB_OVERLAY void fn_80596DCC(void* self, int c)
{
    PUT(0x34, lbl_80682EB0);
    if (c & 1)
        fn_80377408(self);
}

/* near-miss: same own-zero-register halfword at +4 as fn_80596D88 */
//@80596E00
extern "C" DB_OVERLAY void fn_80596E00(Db80596D88_Obj* self)
{
    self->m30 = 0;
    self->m4 = 0;
    self->m8 = 0;
    self->mC = 0;
    self->m10 = 0;
    self->m14 = 0;
    self->m18 = 0;
    self->m1C = 0;
    self->m20 = 0;
    self->m24 = 0;
    self->m28 = 0;
    self->m2C = 0;
}

//@80596FCC
extern "C" DB_OVERLAY int fn_80596FCC(Db80596D88_Obj* self, int k)
{
    switch (*(int*)self) {
    case 1:
        self->m0 = 0;
        if (k)
            return 0x594B;
        return 0x594C;
    case 2:
        self->m0 = 0;
        if (k)
            return 0x594D;
        return 0x594E;
    case 3:
        self->m0 = 0;
        return 0x59FA;
    case 0:
        return 0;
    default:
        return 0;
    }
}

inline void* operator new(unsigned, void* p)
{
    return p;
}

struct Db80597A5C_X {
    char pad[0x18];
    const void* m18;
    Db80597A5C_X() { m18 = lbl_80682D30; }
    void Init() { m18 = lbl_80682D30; }
};

/* near-miss: retail copies r3 (mr r11,r3) before the vptr store */
//@80597A5C
extern "C" DB_OVERLAY void fn_80597A5C(U* self)
{
    PUT(0x18, lbl_80682D30);
}

extern "C" DB_OVERLAY void fn_80597A70(U* self, int chrg)
{
    PUT(0x18, lbl_80682D30);
    if (chrg & 1)
        fn_80377408(self);
}

extern const float lbl_806E02FC;
extern const float lbl_806E0300;
extern const float lbl_806E0304;
extern const float lbl_806E0308;
extern const float lbl_806E030C;
extern const float lbl_806E0310;

//@80597FE4
extern "C" DB_OVERLAY float fn_80597FE4(void* self, int k)
{
    if (k <= 2)
        return lbl_806E02FC;
    if (k <= 4)
        return lbl_806E0300;
    if (k == 5)
        return lbl_806E0304;
    if (k <= 8)
        return lbl_806E0308;
    if (k <= 10)
        return lbl_806E030C;
    return lbl_806E0310;
}

extern const float lbl_806010C4;
extern const float lbl_806010C8;
extern const float lbl_806010CC;
extern const float lbl_806010D0;
extern const float lbl_806E0314;
extern const float lbl_806E0318;
extern const float lbl_806E031C;
extern const float lbl_806E0320;
extern const float lbl_806E0324;

//@80598054
extern "C" DB_OVERLAY float fn_80598054(float x)
{
    if (!(x > lbl_806010C4))
        return lbl_806E0314;
    if (!(x > lbl_806010C8))
        return lbl_806E0318;
    if (!(x > lbl_806010CC))
        return lbl_806E031C;
    if (x <= lbl_806010D0)
        return lbl_806E0320;
    return lbl_806E0324;
}

extern char lbl_806842A0[];
extern const char lbl_805FE19C[];

//@805980E4
extern "C" DB_OVERLAY void fn_805980E4(void* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 4);
    io->v08(a, (char*)self + 4, 0x14);
}

extern const float lbl_806010D4;
extern const float lbl_806010D8;
extern const float lbl_806010DC;
extern const float lbl_806010E0;
extern void* lbl_80619948;
extern "C" int fn_800A2EB4(void* p);
extern "C" int fn_8057CE00(int a);

//@80598158
extern "C" DB_OVERLAY float fn_80598158()
{
    float r = lbl_806010D4;
    if (fn_800A2EB4(lbl_80619948)) {
        int m = fn_8057CE00(0);
        if (m == 0)
            r += lbl_806010D8;
        else if (m == 1)
            r += lbl_806010DC;
        else if (m == 2)
            r += lbl_806010E0;
    }
    return r;
}

extern "C" int fn_8059841C(void* self);

//@805986F8
extern "C" DB_OVERLAY int fn_805986F8(void* self)
{
    int base = fn_8059841C(self);
    Unk8007B2B0_Screen* sc = (Unk8007B2B0_Screen*)lbl_8061930C;
    int d = sc->fn_8007B8C4(0x36, (int)self) - base;
    if (d == 0)
        return 4;
    int r = d + 4;
    if (r < 0)
        r = 0;
    if (r > 10)
        r = 10;
    return r;
}

extern const float lbl_80601164;
extern const float lbl_80601168;
extern const float lbl_8060116C;
extern const float lbl_80601170;
extern const float lbl_80601174;

//@80598924
extern "C" DB_OVERLAY float fn_80598924(float x)
{
    if (!(x > lbl_80601164))
        return lbl_80601168;
    if (x < lbl_8060116C)
        return x * lbl_80601170;
    return lbl_80601174;
}

struct Unk800C7B40_Data {
    int m0;
    int m4;
    int m8;
    char mC[16];
    int m1C;
    int m20;
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned b2 : 1;
    unsigned b3 : 1;
    unsigned b4 : 1;
    unsigned b5 : 1;
    unsigned b6 : 1;
    unsigned b7 : 1;
    unsigned b8 : 1;
    unsigned b9 : 1;
    unsigned b10 : 1;
    unsigned b11 : 1;
    unsigned b12 : 1;
    unsigned b13 : 1;
    unsigned b14 : 1;
    unsigned b15 : 1;
    short m26;
    short m28;
    short m2A;
    short m2C;
    short m2E;
    short m30;
    short m32;
    short m34;
    short m36;
    float m38;
};

struct Unk800C7B40_Widget : Unk800C7B40_Data {
    virtual ~Unk800C7B40_Widget();
    // BEGIN-SLOTS
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
    virtual void fn_vslot9(int a);
    virtual void fn_vslot10(int a);
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14(int a);
    virtual void fn_vslot15();
    virtual void fn_vslot16(int a);
    virtual void fn_vslot17();
    virtual void fn_vslot18(int a);
    virtual float fn_vslot19();
    virtual void fn_vslot20(float a);
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual Unk800C7B40_Widget* fn_vslot28(const char* name);
    virtual Unk800C7B40_Widget* fn_vslot29(const char* name);
    virtual Unk800C7B40_Widget* fn_vslot30(const char* name, int a);
    virtual int fn_vslot31();
    virtual Unk800C7B40_Widget* fn_vslot32(const char* name, int a);
    virtual Unk800C7B40_Widget* fn_vslot33(int a, int b);
    virtual const char* fn_vslot34();
    virtual void fn_vslot35();
    virtual void fn_vslot36();
    virtual void fn_vslot37(int a);
    virtual void fn_vslot38(int a);
    virtual void fn_vslot39();
    virtual void fn_vslot40(int a);
    virtual void fn_vslot41(int a);
    virtual void fn_vslot42();
    virtual void fn_vslot43(int a, int b, char* c, int d);
    virtual void fn_vslot44(int a, int b, char* c, int d);
    virtual void fn_vslot45();
    virtual void fn_vslot46();
    virtual void fn_vslot47(int a);
    virtual void fn_vslot48();
    virtual void fn_vslot49(int a);
    virtual void fn_vslot50();
    virtual void fn_vslot51();
    virtual void fn_vslot52();
    virtual void fn_vslot53();
    virtual void fn_vslot54();
    virtual void fn_vslot55();
    virtual void fn_vslot56();
    virtual void fn_vslot57();
    virtual int fn_vslot58();
    virtual int fn_vslot59();
    virtual int fn_vslot60();
    virtual int fn_vslot61();
    virtual void fn_vslot62();
    virtual void fn_vslot63();
    virtual void fn_vslot64();
    virtual void fn_vslot65();
    virtual void fn_vslot66();
    virtual void fn_vslot67(int a, int b);
    virtual void fn_vslot68(int a);
    virtual void fn_vslot69();
    virtual Unk800C7B40_Widget* fn_vslot70();
    virtual void fn_vslot71();
    virtual void fn_vslot72();
    virtual Unk800C7B40_Widget* fn_vslot73(int idx, int a);
    virtual void fn_vslot74();
    virtual void fn_vslot75();
    virtual void fn_vslot76();
    virtual void fn_vslot77();
    virtual void fn_vslot78();
    virtual void fn_vslot79(int a, int b);
    virtual void fn_vslot80(int a);
    virtual void fn_vslot81();
    virtual void fn_vslot82();
    virtual int fn_vslot83();
    virtual void fn_vslot84(int a, int b);
    virtual int fn_vslot85();
    virtual int fn_vslot86();
    virtual int fn_vslot87();
    virtual void fn_vslot88(int a);
    virtual void fn_vslot89(int a);
    virtual int fn_vslot90();
    virtual int fn_vslot91();
    virtual void fn_vslot92();
    virtual void fn_vslot93();
    virtual void fn_vslot94();
    virtual void fn_vslot95();
    virtual void fn_vslot96();
    virtual void fn_vslot97();
    virtual void fn_vslot98();
    virtual void fn_vslot99();
    virtual void fn_vslot100();
    virtual void fn_vslot101();
    virtual void fn_vslot102();
    virtual void fn_vslot103();
    virtual void fn_vslot104();
    virtual void fn_vslot105(int a);
    virtual void fn_vslot106();
    virtual void fn_vslot107();
    virtual void fn_vslot108();
    virtual void fn_vslot109();
    virtual void fn_vslot110();
    virtual void fn_vslot111();
    virtual void fn_vslot112();
    virtual void fn_vslot113();
    virtual void fn_vslot114();
    virtual void fn_vslot115();
    virtual void fn_vslot116();
    virtual void fn_vslot117();
    virtual void fn_vslot118();
    virtual void fn_vslot119();
    virtual void fn_vslot120();
    virtual void fn_vslot121();
    virtual void fn_vslot122();
    virtual void fn_vslot123();
    virtual void fn_vslot124();
    virtual void fn_vslot125();
    virtual void fn_vslot126();
    virtual void fn_vslot127();
    // END-SLOTS
    void SetVptr(const void* v) { *(const void**)((char*)this + 0x3C) = v; }
};

typedef Unk800C7B40_Widget FeW;

struct FeSlot44 {
    char pad0[0x38];
    int m38;
    char pad3C[8];
};

struct FeScrM : FeW {
    char pad40[0xF0];
    int m130;
    int m134;
    FeW* m138;
    char pad13C[0x144 - 0x13C];
    FeSlot44 m144;
    FeSlot44 m188;
    FeW* m1CC;
    FeW* m1D0;
    int m1D4;
    char pad1D8[0x998 - 0x1D8];
    void* m998;
    int m99C;
};

extern "C" FeW* fn_80553248(FeSlot44* p);

extern "C" FeSlot44* fn_805981EC(FeScrM* x, int a);

extern "C" DB_OVERLAY void fn_8059897C(FeScrM* x, int a)
{
    fn_80553248(fn_805981EC(x, a));
}

//@805989A0
extern "C" DB_OVERLAY Unk80071604* fn_805989A0(Unk80071604* self, const char* name, Obj* type, unsigned count)
{
    fn_80071604(self, name, type, count);
    self->m20 = lbl_806842A0;
    self->m24 = 0;
    self->m24 = (char*)operator new[](self->m1C * 0x28, 0);
    fn_8040074C(self->m24, self->m1C * 0x28);
    self->m14 = fn_8007366C(lbl_805FE19C, lbl_805FE19C);
    return self;
}

extern char lbl_806842A0[];


extern "C" DB_OVERLAY void fn_80598A1C(Unk80071604* self, int chrg)
{
    self->m20 = lbl_806842A0;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

//@80598A78
extern "C" DB_OVERLAY void fn_80598A78(Unk80071604* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(self->m24 + i * 0x28, 0x28);
}

//@80598D5C
extern "C" DB_OVERLAY char* fn_80598D5C(Unk80071604* self, int which, unsigned idx, char* out)
{
    if (idx < self->m1C) {
        switch (which) {
        case 0:
            fn_8040B61C(out, self->m24 + idx * 0x28 + 0xC);
            break;
        case 1:
            fn_8040B61C(out, self->m24 + idx * 0x28 + 0x18);
            break;
        }
    }
    return out;
}

extern Unk8008CE64_Pmf lbl_80602274[];

extern "C" DB_OVERLAY float fn_80598DDC(Unk8008CE64_Obj* o, int i, int a)
{
    float r = (o->*lbl_80602274[i])(a);
    return r;
}

typedef Unk80084910_G G;

extern "C" DB_OVERLAY float fn_80599300(G* self, int a)
{
    float r = (float)(self->m20->pfn((char*)self + self->m20->delta, 1, a) + 0x30);
    return r;
}

extern "C" DB_OVERLAY float fn_8059936C(G* self, int a)
{
    float r = (float)(self->m20->pfn((char*)self + self->m20->delta, 2, a) + 0x64);
    return r;
}

extern "C" DB_OVERLAY float fn_805993D8(G* self, int a)
{
    unsigned char buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 0, a));
    return (float)buf;
}

extern "C" DB_OVERLAY float fn_80599448(G* self, int a)
{
    Db8053CC9C_Buf3 buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 0, a));
    return (float)buf.b;
}

extern "C" DB_OVERLAY float fn_805994C4(G* self, int a)
{
    Db8053CC9C_Buf2 buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 0, a));
    return (float)buf.b;
}

//@80599540
struct Db80599540_D {
    char pad[0x20];
};
struct Db80599540_Obj : Db80599540_D {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(int a, int b);
};

//@80599540
extern "C" DB_OVERLAY float fn_80599540(Db80599540_Obj* self, int a)
{
    int v = self->v5(8, a);
    float r = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80079A90(v);
    return r;
}
