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

inline void* operator new(unsigned, void* p)
{
    return p;
}

/* Screen manager (lbl_8061930C) as these functions read it: +0x2C a handle, +0x30 the gameplay record
 * (fn_805974B8 / fn_80597330 / fn_8059889C). Game object (lbl_80619948): +0x28 and +0x84 (a month/date key). */
struct Db80596D88_Rec30 {
    void* m0;
    void* m4;
    void* m8;
    void* mC;
    void* m10;
    char pad14[0xA4];
    float mB8;
};
struct Db80596D88_Scr {
    char pad0[0x2C];
    void* m2C;
    Db80596D88_Rec30* m30;
    void* m34;
};
struct Db80596D88_Game {
    char pad0[0x28];
    int m28;
    char pad2C[0x58];
    int m84;
};
#define DB96D88_SCR ((Db80596D88_Scr*)lbl_8061930C)
#define DB96D88_GAME ((Db80596D88_Game*)lbl_80619948)

extern const float lbl_80601160;
extern const float lbl_80601140;
extern const float lbl_80601144;
extern const float lbl_80601148;
extern const float lbl_80601158;
extern const float lbl_8060115C;
extern const float lbl_80601078;
extern const float lbl_8060107C;
extern signed char lbl_806025C4[];
extern "C" float fn_80591270(void* p);
extern "C" int fn_80591A50(void* p);
extern "C" float fn_80593370(void* p, int i);
extern "C" int fn_8056AAE4(int a, int b, int c);
extern "C" int fn_8056B87C(int a);
extern "C" int fn_80593E7C(void* p, int i);
extern "C" void fn_805819EC(void* p, int k);

struct Db80597A5C_X {
    char pad[0x18];
    const void* m18;
    Db80597A5C_X() { m18 = lbl_80682D30; }
    void Init() { m18 = lbl_80682D30; }
};

extern const float lbl_806E02FC;
extern const float lbl_806E0300;
extern const float lbl_806E0304;
extern const float lbl_806E0308;
extern const float lbl_806E030C;
extern const float lbl_806E0310;

extern const float lbl_806010C4;
extern const float lbl_806010C8;
extern const float lbl_806010CC;
extern const float lbl_806010D0;
extern const float lbl_806E0314;
extern const float lbl_806E0318;
extern const float lbl_806E031C;
extern const float lbl_806E0320;
extern const float lbl_806E0324;

extern char lbl_806842A0[];
extern const char lbl_805FE19C[];

extern const float lbl_806010D4;
extern const float lbl_806010D8;
extern const float lbl_806010DC;
extern const float lbl_806010E0;
extern "C" int fn_800A2EB4(void* p);
extern "C" int fn_8057CE00(int a);

extern const float lbl_80601164;
extern const float lbl_80601168;
extern const float lbl_8060116C;
extern const float lbl_80601170;
extern const float lbl_80601174;

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

extern "C" int fn_805981EC(void* x, int a);

extern char lbl_806842A0[];

extern Unk8008CE64_Pmf lbl_80602274[];

extern int lbl_806022A4[];
struct Db80596D88_Rec {
    char pad0[0xC];
    char m0C[0xC];
    char m18[0xC];
    char pad24[4];
};

typedef Unk80084910_G G;

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

inline void Db8059889C_SetB8(Db80596D88_Rec30* s, float v)
{
    s->mB8 = v;
}

extern const float lbl_80601108;
extern "C" int fn_8007F198__FP13Unk8007F198_A(void* a, int b);
extern "C" int fn_8007F24C__FP13Unk8007F198_Aii(void* a, int b, unsigned char c);
extern "C" int fn_8007A6A0__18Unk8007A4DC_Screenii(void* a, int b, int c);

extern const float lbl_80601108;
extern "C" int fn_8007F198__FP13Unk8007F198_A(void* a, int b);
extern "C" int fn_8007F24C__FP13Unk8007F198_Aii(void* a, int b, unsigned char c);
extern "C" int fn_8007A6A0__18Unk8007A4DC_Screenii(void* a, int b, int c);

struct Db80597268_Data {
    char pad0[0x1C];
};
struct Db80597268_Obj : Db80597268_Data {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
};
extern "C" Db80597268_Obj* fn_8058F1F0(void* p, int k);

extern const double lbl_806010A0;
extern const float lbl_806010A8;
extern const float lbl_806010AC;
extern const float lbl_806010B0;
extern const float lbl_806010B4;
extern const float lbl_806010B8;
extern const float lbl_806010BC;
extern const float lbl_806010C0;
extern const float lbl_806E02D8;
extern const float lbl_806E02DC;
extern const float lbl_806E02E0;
extern const float lbl_806E02E4;
extern const float lbl_806E02E8;
extern const float lbl_806E02EC;
extern const float lbl_806E02F0;
extern const float lbl_806E02F4;
extern const float lbl_806E02F8;

struct Db80597058_Big {
    char pad0[0x12B78];
    float m12B78;
};
extern const float lbl_80601070;
extern const float lbl_80601074;

struct Db80596E3C_Rec1E8 {
    char pad0[0x1E8];
    int m1E8;
};
extern "C" int fn_800A2E90(void* p);
extern "C" int fn_800A2E6C(void* p);
extern "C" void fn_800B555C();
extern "C" int fn_800B5758();
extern "C" Db80596E3C_Rec1E8* fn_8007FE04__FP13Unk8007F198_D(void* p);

extern int lbl_80622DEC;
extern int lbl_80622DF0;
extern const float lbl_806010E4;
extern const float lbl_806010E8;
extern const float lbl_806010F8;

/* 0x28-byte record of the table at m24 (fn_805989A0 builds it, fn_80598B80 reads it; bit layout from the
 * getter's extrwi/srwi operands). */
struct Db80598B80_Rec {
    unsigned a0 : 8;
    unsigned f0 : 16;
    unsigned f1 : 6;
    unsigned p0 : 2;
    unsigned f2 : 8;
    unsigned f3 : 7;
    unsigned f4 : 6;
    unsigned f5 : 1;
    unsigned f6 : 1;
    unsigned f7 : 1;
    unsigned f8 : 8;
    unsigned f9 : 3;
    unsigned f10 : 7;
    unsigned f11 : 7;
    unsigned f12 : 7;
    unsigned f13 : 7;
    unsigned p1 : 1;
    char pad0C[0x1C];
};

extern const float lbl_80601080;
extern "C" int fn_8007F7D0__FP13Unk8007F198_BUi(void* p, unsigned i);
extern "C" int fn_8007B320__18Unk8007B2B0_Screenii(void* p, int a, int b);
extern "C" int fn_8056B658(int a, int b, int c);
extern "C" int fn_80596538(void* a, int b);
extern "C" float fn_8059139C(Db80596D88_Rec30* p, int i);

extern const float lbl_80601118;
extern const float lbl_8060111C;
extern const float lbl_80601120;
extern const float lbl_80601124;
extern const float lbl_80601128;
extern const float lbl_8060112C;
extern const float lbl_80601130;
extern const float lbl_80601134;
extern float lbl_806025D4[];
extern "C" int fn_800A2AE8(void* p);
extern "C" int fn_8056B7D0(int a);
extern "C" int fn_8007B3E0__18Unk8007B2B0_Screenii(void* p, int a, int b);
extern "C" int fn_8007B8C4__18Unk8007B2B0_Screenii(void* p, int a, int b);
extern "C" float fn_8007BB28__18Unk8007B2B0_Screeniii(void* p, int a, int b, int c);

inline float Db8059841C_Min(float a, float b)
{
    return a <? b;
}
inline float Db8059841C_Ratio(Db80596D88_Game* g, int m28)
{
    int cur = fn_800A2AE8(g);
    int base = fn_8056B87C(m28);
    int hi = fn_8056B7D0(m28);
    return (float)(cur - base) / (float)(hi - fn_8056B87C(m28));
}
/* forward declarations (definitions are in address order) */
extern "C" void fn_80596D88(Db80596D88_Obj* self);
extern "C" void fn_80596DCC(void* self, int c);
extern "C" void fn_80596E00(Db80596D88_Obj* self);
extern "C" int fn_80596E3C(Db80596D88_Obj* self);
extern "C" int fn_80596FCC(Db80596D88_Obj* self, int k);
extern "C" int fn_80597058(Db80596D88_Obj* self);
extern "C" int fn_805971AC(Db80596D88_Obj* self);
extern "C" void fn_80597268(Db80596D88_Obj* self);
extern "C" void fn_80597330(Db80596D88_Obj* self);
extern "C" void fn_805973D4(Db80596D88_Obj* self);
extern "C" void fn_805974B8(Db80596D88_Obj* self);
extern "C" void fn_8059754C(Db80596D88_Obj* self);
extern "C" void fn_80597618(void* self, int a, Unk80070DDC_Stream* io);
extern "C" void fn_80597818(Db80596D88_Obj* self);
extern "C" void fn_80597A5C(U* self);
extern "C" void fn_80597A70(U* self, int chrg);
extern "C" float fn_80597EE0(float x);
extern "C" float fn_80597FE4(void* self, int k);
extern "C" float fn_80598054(float x);
extern "C" void fn_805980E4(void* self, int a, Unk80070DDC_Stream* io);
extern "C" float fn_80598158();
extern "C" int fn_805981EC(void* self, int a);
extern "C" float fn_80598348(void* self);
extern "C" int fn_8059841C(void* self);
extern "C" int fn_805986F8(void* self);
extern "C" float fn_80598764();
extern "C" float fn_805987F8();
extern "C" float fn_8059889C(void* self);
extern "C" float fn_80598924(float x);
extern "C" void fn_8059897C(FeScrM* x, int a);
extern "C" Unk80071604* fn_805989A0(Unk80071604* self, const char* name, Obj* type, unsigned count);
extern "C" void fn_80598A1C(Unk80071604* self, int chrg);
extern "C" void fn_80598A78(Unk80071604* self, unsigned i);
extern "C" int fn_80598AB4(void* l, int k);
extern "C" int fn_80598B3C(void* l, int k);
extern "C" unsigned fn_80598B80(Unk80071604* a, int k, unsigned c);
extern "C" char* fn_80598D5C(Unk80071604* self, int which, unsigned idx, char* out);
extern "C" float fn_80598DDC(Unk8008CE64_Obj* o, int i, int a);
extern "C" void fn_80598E74(Unk80071604* a, int k, unsigned c, int v);
extern "C" void fn_80599214(Unk80071604* self, int kind, unsigned i, const char* src, int n);
extern "C" float fn_80599300(G* self, int a);
extern "C" float fn_8059936C(G* self, int a);
extern "C" float fn_805993D8(G* self, int a);
extern "C" float fn_80599448(G* self, int a);
extern "C" float fn_805994C4(G* self, int a);
extern "C" float fn_80599540(Db80599540_Obj* self, int a);

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

extern "C" DB_OVERLAY int fn_80596E3C(Db80596D88_Obj* self)
{
    if (fn_800A2E90(lbl_80619948) != 0) {
        fn_800B555C();
        if (fn_800B5758() != 0) {
            int e = fn_8007FE04__FP13Unk8007F198_D(lbl_8061930C)->m1E8;
            unsigned cur = DB96D88_GAME->m84;
            if (e == 1 && (unsigned)self->m30 < cur) {
                self->m30 = cur;
                if (self->m1C == 0)
                    fn_80597268(self);
                if (self->m20 == 0)
                    fn_80597330(self);
                if (self->m24 == 0)
                    fn_805973D4(self);
                fn_805974B8(self);
                if (self->m28 == 0)
                    fn_8059754C(self);
                int r = fn_80597058(self);
                if (r != 0 || (r = fn_805971AC(self)) != 0) {
                    self->m0 = r;
                    return r;
                }
                fn_80597818(self);
            }
            return 0;
        }
    }
    if (fn_800A2E6C(lbl_80619948) != 0) {
        fn_800B555C();
        if (fn_800B5758() != 0) {
            unsigned cur = DB96D88_GAME->m84;
            if ((unsigned)self->m30 < cur) {
                self->m30 = cur;
                volatile Db8053CC9C_Buf3 buf;
                fn_80329FA0((void*)&buf, DB96D88_GAME->m84);
                if (buf.b == 0x7D6 && (int)(cur - fn_8056B87C(DB96D88_GAME->m28)) == 1)
                    fn_805819EC(DB96D88_SCR->m2C, 0x12);
            }
        }
    }
    return 0;
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

extern "C" DB_OVERLAY int fn_80597058(Db80596D88_Obj* self)
{
    Db80596D88_Game* g = DB96D88_GAME;
    void* a = DB96D88_SCR->m2C;
    Db80597058_Big* big = (Db80597058_Big*)DB96D88_SCR->m30->m0;
    float f;
    volatile Db8053CC9C_Buf3 buf;
    fn_80329FA0((void*)&buf, g->m84);
    short t = buf.b - 0x7D5;
    f = big->m12B78;
    if (!(f >= lbl_80601070)) {
        if (t == self->mC) {
            fn_805819EC(a, 4);
            if (self->mC != 0)
                self->mC++;
        }
        if (self->mC == 0) {
            self->mC++;
            self->m10 = g->m84;
            self->m0 = 2;
            return 2;
        }
    } else if (!(f >= lbl_80601074)) {
        if (t == self->m4) {
            fn_805819EC(a, 3);
            if (self->m4 != 0)
                self->m4++;
        }
        if (self->m4 == 0) {
            self->m4++;
            self->m8 = g->m84;
            self->m0 = 1;
            return 1;
        }
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_805971AC(Db80596D88_Obj* self)
{
    void* h = DB96D88_SCR->m30->m0;
    float sp8 = lbl_80601078;
    if (fn_80591A50(h) >= 0)
        sp8 = fn_80593370(h, fn_80591A50(h));
    if (!(sp8 <= lbl_8060107C) && self->m14 == 0) {
        self->m14 = 1;
        self->m18 = DB96D88_GAME->m84;
        self->m0 = 3;
        return 3;
    }
    return 0;
}

extern "C" DB_OVERLAY void fn_80597268(Db80596D88_Obj* self)
{
    Db80596D88_Game* g = DB96D88_GAME;
    Db80596D88_Scr* sc = DB96D88_SCR;
    void* a = sc->m2C;
    volatile Db8053CC9C_Buf3 buf;
    fn_80329FA0((void*)&buf, g->m84);
    if (buf.b - 0x7D5 > 0) {
        int cur = g->m84;
        if (cur == fn_8056B87C(g->m28)) {
            for (int i = 0; i <= 5; i++) {
                if (fn_8058F1F0(sc->m34, i)->v9() > 0)
                    self->m1C = 1;
            }
            if (self->m1C == 0)
                fn_805819EC(a, 5);
        }
    }
}

extern "C" DB_OVERLAY void fn_80597330(Db80596D88_Obj* self)
{
    int cur = DB96D88_GAME->m84;
    Db80596D88_Rec30* b = DB96D88_SCR->m30;
    void* a = DB96D88_SCR->m2C;
    int d = cur - fn_8056B87C(DB96D88_GAME->m28);
    if (d == 30 || d == 120) {
        for (int i = 0; i <= 8; i++) {
            if (fn_80593E7C(b->m4, i) > 0)
                self->m20 = 1;
        }
        if (self->m20 == 0)
            fn_805819EC(a, 6);
    }
}

extern "C" DB_OVERLAY void fn_805973D4(Db80596D88_Obj* self)
{
    Db80596D88_Game* g = DB96D88_GAME;
    Db80596D88_Scr* sc = DB96D88_SCR;
    Db80596D88_Rec30* b = sc->m30;
    void* a = sc->m2C;
    int cur = g->m84;
    int d = cur - fn_8056B87C(g->m28);
    volatile Db8053CC9C_Buf3 buf;
    fn_80329FA0((void*)&buf, g->m84);
    int t = buf.b - 0x7D5;
    if ((t == 0 && d == 0x4B) || (t > 0 && (fn_8056AAE4(g->m28, DB96D88_GAME->m84, 0) != 0 || d == 3))) {
        for (int i = 0; i <= 5; i++) {
            if (fn_80593E7C(b->mC, i) > 0)
                self->m24 = 1;
        }
        if (self->m24 == 0)
            fn_805819EC(a, 7);
    }
}

extern "C" DB_OVERLAY void fn_805974B8(Db80596D88_Obj* self)
{
    int found = 0;
    Db80596D88_Rec30* b = DB96D88_SCR->m30;
    void* a = DB96D88_SCR->m2C;
    if (fn_8056AAE4(DB96D88_GAME->m28, DB96D88_GAME->m84, 0)) {
        for (int i = 0; i <= 15; i++) {
            if (fn_80593E7C(b->m10, i) > 0)
                found = 1;
        }
        if (found == 0)
            fn_805819EC(a, 8);
    }
}

extern "C" DB_OVERLAY void fn_8059754C(Db80596D88_Obj* self)
{
    Db80596D88_Game* g = DB96D88_GAME;
    Db80596D88_Scr* sc = DB96D88_SCR;
    void* a = sc->m2C;
    Db80596D88_Rec30* b = sc->m30;
    volatile Db8053CC9C_Buf3 buf;
    fn_80329FA0((void*)&buf, g->m84);
    if (buf.b - 0x7D5 > 0) {
        int cur = g->m84;
        if (cur == fn_8056B87C(g->m28) || fn_8056AAE4(g->m28, g->m84, 0)) {
            for (int i = 0; i <= 5; i++) {
                if (fn_80593E7C(b->m8, i) > 0)
                    self->m28 = 1;
            }
            if (self->m28 == 0)
                fn_805819EC(a, 9);
        }
    }
}

extern "C" DB_OVERLAY void fn_80597618(void* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 4);
    io->v08(a, (char*)self + 0x4, 2);
    io->v08(a, (char*)self + 0x8, 4);
    io->v08(a, (char*)self + 0xC, 2);
    io->v08(a, (char*)self + 0x10, 4);
    io->v08(a, (char*)self + 0x14, 2);
    io->v08(a, (char*)self + 0x18, 4);
    io->v08(a, (char*)self + 0x28, 4);
    io->v08(a, (char*)self + 0x1C, 4);
    io->v08(a, (char*)self + 0x20, 4);
    io->v08(a, (char*)self + 0x24, 4);
    io->v08(a, (char*)self + 0x2C, 4);
    io->v08(a, (char*)self + 0x30, 4);
}

/* near-miss (97.5%): retail keeps the field (f31) and the 0.0f limit (f30) in callee-saved float registers across the
   fn_8059139C call with no float-store spill; every spelling tried (const/register locals, const pointers) reloads the field. */
extern "C" DB_OVERLAY void fn_80597818(Db80596D88_Obj* self)
{
    Db80596D88_Game* g = DB96D88_GAME;
    int m28 = g->m28;
    void* a = DB96D88_SCR->m2C;
    unsigned base = fn_8056B87C(m28);
    unsigned cur = g->m84;
    int d = cur - base;
    volatile Db8053CC9C_Buf3 buf;
    fn_80329FA0((void*)&buf, cur);
    int t = buf.b - 0x7D5;
    if (cur > base && self->m2C == 0) {
        void* scr = lbl_8061930C;
        int idx = fn_8056B658(m28, cur - 1, fn_8007B320__18Unk8007B2B0_Screenii(scr, 0, fn_8007F7D0__FP13Unk8007F198_BUi(scr, 0)));
        if (idx != -1) {
            int q = fn_80596538(DB96D88_SCR->m30->m10, idx);
            if (q == 1) {
                fn_805819EC(a, 0x11);
                self->m2C = q;
            }
        }
    }
    if (t == 0) {
        if (d == 0) {
            fn_805819EC(a, 1);
            fn_805819EC(a, 2);
            fn_805819EC(a, 0xF);
        } else if (d == 1) {
            fn_805819EC(a, 0x10);
        } else if (d == 2) {
            fn_805819EC(a, 0xC);
        } else if (d == 4) {
            fn_805819EC(a, 0xB);
        }
    } else if (t == 1 && d == 0 && fn_800A2E90(g) == 1) {
        Db80597058_Big* big = (Db80597058_Big*)DB96D88_SCR->m30->m0;
        if (!(big->m12B78 >= lbl_80601080) && !(big->m12B78 - fn_8059139C(DB96D88_SCR->m30, 0) >= lbl_80601080))
            fn_805819EC(a, 0xD);
    }
    if (fn_8056AAE4(m28, cur - 1, 0) != 0 && (unsigned)t <= 2) {
        if (!(((Db80597058_Big*)DB96D88_SCR->m30->m0)->m12B78 >= lbl_80601080))
            fn_805819EC(a, 0xE);
    }
}

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

extern "C" DB_OVERLAY float fn_80597EE0(float x)
{
    if (!(x > lbl_806010A0))
        return lbl_806E02D8;
    if (!(x > lbl_806010A8))
        return lbl_806E02DC;
    if (!(x > lbl_806010AC))
        return lbl_806E02E0;
    if (!(x > lbl_806010B0))
        return lbl_806E02E4;
    if (!(x > lbl_806010B4))
        return lbl_806E02E8;
    if (!(x > lbl_806010B8))
        return lbl_806E02EC;
    if (!(x > lbl_806010BC))
        return lbl_806E02F0;
    if (x <= lbl_806010C0)
        return lbl_806E02F4;
    return lbl_806E02F8;
}

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

//@805980E4
extern "C" DB_OVERLAY void fn_805980E4(void* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, self, 4);
    io->v08(a, (char*)self + 4, 0x14);
}

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

extern "C" DB_OVERLAY int fn_805981EC(void* self, int a)
{
    int r;
    if (lbl_80622DEC == 0) {
        r = fn_805986F8(self);
        float f = fn_80598764() + fn_8059889C(self);
        f = (float)(int)(!(f <= lbl_806010E4) ? f + lbl_806010E8 : f - lbl_806010E8);
        r += (int)f;
    } else {
        r = lbl_80622DF0;
    }
    if (r > 10)
        r = 10;
    else if (r < 0)
        r = 0;
    if (r > 4 && lbl_80622DEC == 0) {
        if (!(((Db80597058_Big*)DB96D88_SCR->m30->m0)->m12B78 >= lbl_806010F8))
            r = 4;
    }
    return r;
}

extern "C" DB_OVERLAY float fn_80598348(void* self)
{
    void* scr = lbl_8061930C;
    int sum = 0;
    int i = 0;
    int n = fn_8007F198__FP13Unk8007F198_A(scr, (int)self);
    while (i < n) {
        int k = fn_8007F24C__FP13Unk8007F198_Aii(scr, (int)self, i);
        i++;
        sum = sum + fn_8007A6A0__18Unk8007A4DC_Screenii(scr, 0x16, k) + 1;
    }
    return (float)sum / ((float)n * lbl_80601108);
}

extern "C" DB_OVERLAY int fn_8059841C(void* self)
{
    void* scr = lbl_8061930C;
    Db80596D88_Game* g = DB96D88_GAME;
    int a = fn_8007F7D0__FP13Unk8007F198_BUi(scr, 0);
    int m28 = g->m28;
    int has = fn_800A2E90(g);
    float t = fn_800A2E90(g) != 0 ? Db8059841C_Ratio(g, m28) : lbl_80601118;
    int b = fn_8007B3E0__18Unk8007B2B0_Screenii(scr, 0xF, a);
    int c = fn_8007B8C4__18Unk8007B2B0_Screenii(scr, 0x36, (int)self);
    float m = Db8059841C_Min(t * lbl_8060111C, lbl_80601118);
    int flag = 0;
    if (has != 0)
        flag = 1;
    float v18 = fn_8007BB28__18Unk8007B2B0_Screeniii(scr, 5, (int)self, flag);
    float v1C;
    if (b == 0) {
        if (c != 0) {
            v1C = (lbl_806025D4[c] + lbl_806025D4[c - 1]) * lbl_80601120;
        } else {
            v1C = (lbl_806025D4[c] - lbl_806025D4[1]) * lbl_80601120 + lbl_806025D4[c];
        }
    } else {
        v1C = fn_8007BB28__18Unk8007B2B0_Screeniii(scr, 5, (int)self, 0);
    }
    float w = Db8059841C_Min(v1C * (lbl_80601118 - m) + v18 * m, lbl_80601118);
    if (!(w < lbl_80601124))
        return 0;
    if (!(w < lbl_80601128))
        return 1;
    if (!(w < lbl_80601120))
        return 2;
    if (!(w < lbl_8060112C))
        return 3;
    if (w >= lbl_80601130)
        return 4;
    if (w >= lbl_80601134)
        return 5;
    return 6;
}

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

extern "C" DB_OVERLAY float fn_80598764()
{
    float f;
    volatile Db8053CC9C_Buf3 buf;
    fn_80329FA0((void*)&buf, DB96D88_GAME->m84);
    unsigned k = buf.b - 0x7D5;
    if (k > 14)
        k = 14;
    signed char c = lbl_806025C4[k];
    f = fn_805987F8() - (float)c;
    return f;
}

extern "C" DB_OVERLAY float fn_805987F8()
{
    int v = (int)(fn_80591270(DB96D88_SCR->m30) * lbl_80601140 + lbl_80601144);
    if (v > 0x5A)
        return lbl_80601148;
    if (v > 0)
        return (float)v * lbl_80601158;
    return lbl_8060115C;
}

extern "C" DB_OVERLAY float fn_8059889C(void* self)
{
    Db80596D88_Rec30* s = DB96D88_SCR->m30;
    if (s->mB8 == lbl_80601160)
        Db8059889C_SetB8(s, fn_80598348(self));
    float d = fn_80598348(self) - DB96D88_SCR->m30->mB8;
    d = d / DB96D88_SCR->m30->mB8;
    return fn_80598924(d);
}

//@80598924
extern "C" DB_OVERLAY float fn_80598924(float x)
{
    if (!(x > lbl_80601164))
        return lbl_80601168;
    if (x < lbl_8060116C)
        return x * lbl_80601170;
    return lbl_80601174;
}

extern "C" DB_OVERLAY void fn_8059897C(FeScrM* x, int a)
{
    fn_80553248((FeSlot44*)fn_805981EC(x, a));
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

/* One assignment per column (14 columns) and no default: the zero arms that CSE
   proves redundant leave dead compares behind (PATTERNS, "Hard-case families 4"). */
//@80598AB4
extern "C" DB_OVERLAY int fn_80598AB4(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 0;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    case 4:
        r = 0;
        break;
    case 5:
        r = 0;
        break;
    case 6:
        r = 0;
        break;
    case 7:
        r = 0;
        break;
    case 8:
        r = 0;
        break;
    case 9:
        r = 0;
        break;
    case 10:
        r = 100;
        break;
    case 11:
        r = 100;
        break;
    case 12:
        r = 100;
        break;
    case 13:
        r = 100;
        break;
    }
    return r;
}

//@80598B3C
extern "C" DB_OVERLAY int fn_80598B3C(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 0;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    case 4:
        r = 0;
        break;
    case 5:
        r = 0;
        break;
    case 6:
        r = 0;
        break;
    case 7:
        r = 0;
        break;
    case 8:
        r = 0;
        break;
    case 9:
        r = 0;
        break;
    case 10:
        r = 0;
        break;
    case 11:
        r = 0;
        break;
    case 12:
        r = 0;
        break;
    case 13:
        r = 0;
        break;
    }
    return r;
}

extern "C" DB_OVERLAY unsigned fn_80598B80(Unk80071604* a, int k, unsigned c)
{
    unsigned r = 0;
    if (c < a->m1C) {
        switch ((unsigned)k) {
        case 0:
            r = ((Db80598B80_Rec*)a->m24)[c].f0;
            break;
        case 1:
            r = ((Db80598B80_Rec*)a->m24)[c].f1;
            break;
        case 2:
            r = ((Db80598B80_Rec*)a->m24)[c].f2;
            break;
        case 3:
            r = ((Db80598B80_Rec*)a->m24)[c].f3;
            break;
        case 4:
            r = ((Db80598B80_Rec*)a->m24)[c].f4;
            break;
        case 5:
            r = ((Db80598B80_Rec*)a->m24)[c].f5;
            break;
        case 6:
            r = ((Db80598B80_Rec*)a->m24)[c].f6;
            break;
        case 7:
            r = ((Db80598B80_Rec*)a->m24)[c].f7;
            break;
        case 8:
            r = ((Db80598B80_Rec*)a->m24)[c].f8;
            break;
        case 9:
            r = ((Db80598B80_Rec*)a->m24)[c].f9;
            break;
        case 10:
            r = ((Db80598B80_Rec*)a->m24)[c].f10;
            break;
        case 11:
            r = ((Db80598B80_Rec*)a->m24)[c].f11;
            break;
        case 12:
            r = ((Db80598B80_Rec*)a->m24)[c].f12;
            break;
        case 13:
            r = ((Db80598B80_Rec*)a->m24)[c].f13;
            break;
        }
    }
    return r;
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

extern "C" DB_OVERLAY float fn_80598DDC(Unk8008CE64_Obj* o, int i, int a)
{
    float r = (o->*lbl_80602274[i])(a);
    return r;
}

extern "C" DB_OVERLAY void fn_80598E74(Unk80071604* a, int k, unsigned c, int v)
{
    if (c < a->m1C) {
        switch ((unsigned)k) {
        case 0: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            if (v <= 0xffff) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0xffff;
            }
            r->f0 = v;
            return;
        }
        case 1: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            if (v <= 0x3f) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x3f;
            }
            r->f1 = v;
            return;
        }
        case 2: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            int t;
            if (v <= 0xff) {
                t = v;
                if (t < 0)
                    t = 0;
            } else {
                t = 0xff;
            }
            r->f2 = t;
            return;
        }
        case 3: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            if (v <= 0x7f) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x7f;
            }
            r->f3 = v;
            return;
        }
        case 4: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            if (v <= 0x3f) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x3f;
            }
            r->f4 = v;
            return;
        }
        case 5: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            if (v <= 1) {
                if (v < 0)
                    v = 0;
            } else {
                v = 1;
            }
            r->f5 = v;
            return;
        }
        case 6: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            if (v <= 1) {
                if (v < 0)
                    v = 0;
            } else {
                v = 1;
            }
            r->f6 = v;
            return;
        }
        case 7: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            if (v <= 1) {
                if (v < 0)
                    v = 0;
            } else {
                v = 1;
            }
            r->f7 = v;
            return;
        }
        case 8: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            int t;
            if (v <= 0xff) {
                t = v;
                if (t < 0)
                    t = 0;
            } else {
                t = 0xff;
            }
            r->f8 = t;
            return;
        }
        case 9: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            if (v <= 7) {
                if (v < 0)
                    v = 0;
            } else {
                v = 7;
            }
            r->f9 = v;
            return;
        }
        case 10: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            if (v <= 100) {
                if (v < 0)
                    v = 0;
            } else {
                v = 100;
            }
            r->f10 = v;
            return;
        }
        case 11: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            if (v <= 100) {
                if (v < 0)
                    v = 0;
            } else {
                v = 100;
            }
            r->f11 = v;
            return;
        }
        case 12: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            if (v <= 100) {
                if (v < 0)
                    v = 0;
            } else {
                v = 100;
            }
            r->f12 = v;
            return;
        }
        case 13: {
            Db80598B80_Rec* r = (Db80598B80_Rec*)(c * 0x28 + (int)a->m24);
            int t;
            if (v <= 100) {
                t = v;
                if (t < 0)
                    t = 0;
            } else {
                t = 100;
            }
            r->f13 = t;
            return;
        }
        }
    }
}

extern "C" DB_OVERLAY void fn_80599214(Unk80071604* self, int kind, unsigned i, const char* src, int n)
{
    if (i < self->m1C) {
        if (n <= 0)
            n = fn_8040B6A0(src);
        int lim = lbl_806022A4[kind] - 1;
        if (n > lim)
            n = lim;
        switch (kind) {
        case 0:
            fn_8040B830(((Db80596D88_Rec*)self->m24)[i].m0C, src, n);
            ((Db80596D88_Rec*)self->m24)[i].m0C[n] = 0;
            break;
        case 1:
            fn_8040B830(((Db80596D88_Rec*)self->m24)[i].m18, src, n);
            ((Db80596D88_Rec*)self->m24)[i].m18[n] = 0;
            break;
        }
    }
}

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
extern "C" DB_OVERLAY float fn_80599540(Db80599540_Obj* self, int a)
{
    int v = self->v5(8, a);
    float r = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80079A90(v);
    return r;
}
