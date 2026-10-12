/*
 * Database overlay code, .database_codeoverlay 0x80596D88-0x80599594 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"
#include "game/tu_8008CE64.h"

struct U {
    char pad0[0x4000];
};

#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))

extern char lbl_80682D30[];

extern "C" void fn_80377408(void* p);

extern "C" DB_OVERLAY void fn_80597A70(U* self, int chrg)
{
    PUT(0x18, lbl_80682D30);
    if (chrg & 1)
        fn_80377408(self);
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

struct Obj {
    char* m0;
    int m4;
};

struct Unk80071604 {
    char m0[16];
    Obj* m10;
    int m14;
    int m18;
    unsigned m1C;
    void* m20;
    char* m24;
};

extern char lbl_806842A0[];

void fn_80071688(Unk80071604* self, int chrg);

extern "C" DB_OVERLAY void fn_80598A1C(Unk80071604* self, int chrg)
{
    self->m20 = lbl_806842A0;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

extern Unk8008CE64_Pmf lbl_80602274[];

extern "C" DB_OVERLAY float fn_80598DDC(Unk8008CE64_Obj* o, int i, int a)
{
    float r = (o->*lbl_80602274[i])(a);
    return r;
}

struct Unk80084910_VT2 {
    char pad0[0x28];
    short delta;
    short pad2A;
    int (*pfn)(void* self, int k, int a);
};

struct Unk80084910_G {
    char pad0[0x20];
    Unk80084910_VT2* m20;
};

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

extern "C" void fn_80329FA0(void* out, int v, ...);

extern "C" DB_OVERLAY float fn_805993D8(G* self, int a)
{
    unsigned char buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 0, a));
    return (float)buf;
}

struct Db8053CC9C_Buf3 {
    unsigned short a;
    unsigned short b;
};

extern "C" DB_OVERLAY float fn_80599448(G* self, int a)
{
    Db8053CC9C_Buf3 buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 0, a));
    return (float)buf.b;
}

struct Db8053CC9C_Buf2 {
    unsigned char a;
    unsigned char b;
    unsigned short pad;
};

extern "C" DB_OVERLAY float fn_805994C4(G* self, int a)
{
    Db8053CC9C_Buf2 buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 0, a));
    return (float)buf.b;
}
