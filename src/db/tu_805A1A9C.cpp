/*
 * Database overlay code, .database_codeoverlay 0x805A1A9C-0x805A2604 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

extern "C" void fn_80400560(void* p, int n);

extern "C" DB_OVERLAY void fn_805A1A9C(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A1AC0(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A1AE4(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A1B08(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A1B2C(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A1B50(void* p)
{
    fn_80400560(p, 0x28);
}

extern "C" DB_OVERLAY void fn_805A1B74(void* p)
{
    fn_80400560(p, 0x28);
}

struct U {
    char pad0[0x4000];
};

#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))

extern char lbl_806841F8[];

extern "C" void fn_80377408(void* p);

extern "C" DB_OVERLAY void fn_805A1B98(U* self, int chrg)
{
    PUT(0x14, lbl_806841F8);
    if (chrg & 1)
        fn_80377408(self);
}

extern char lbl_80683EF8[];

extern "C" DB_OVERLAY void fn_805A1BCC(U* self, int chrg)
{
    PUT(0x4, lbl_80683EF8);
    if (chrg & 1)
        fn_80377408(self);
}

//@805A1C00
struct Vc4_2_D { char pad[0x4]; };
//@805A1C00
struct Vc4_2 : Vc4_2_D { virtual void v1(); virtual void v2(); };

extern "C" DB_OVERLAY void fn_805A1C00(Vc4_2* p)
{
    p->v2();
}

/*
 * Retail destroys these through member arrays whose element destructors are
 * fn_803628C8 (0x150-byte elements) and fn_803628FC (0xA0-byte elements); the
 * element classes here only declare their destructors. The vptr is a plain field.
 */
extern char lbl_80683E88[];
extern char lbl_80683E00[];

struct DbE150 {
    char pad[0x150];
    ~DbE150();
};
struct DbEA0 {
    char pad[0xA0];
    ~DbEA0();
};

struct DbArrB {
    char pad0[0xC];
    DbE150 mC[9];
    DbEA0 mBDC[3];
    const void* mDBC;
    ~DbArrB() { mDBC = lbl_80683E88; }
};

struct DbArrD : DbArrB {
    DbE150 mDC0[9];
    DbE150 m1990[9];
    ~DbArrD() { mDBC = lbl_80683E00; }
};

//@805A1C34
extern "C" DB_OVERLAY void fn_805A1C34(DbArrB* self, int chrg)
{
    self->~DbArrB();
    if (chrg & 1)
        fn_80377408(self);
}

//@805A1CD4
extern "C" DB_OVERLAY void fn_805A1CD4(DbArrD* self, int chrg)
{
    self->~DbArrD();
    if (chrg & 1)
        fn_80377408(self);
}

//@805A1DD8
struct VcDBC_8_D { char pad[0xDBC]; };
//@805A1DD8
struct VcDBC_8 : VcDBC_8_D { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); };

extern "C" DB_OVERLAY void fn_805A1DD8(VcDBC_8* p)
{
    p->v8();
}

//@805A1E0C
extern "C" DB_OVERLAY void fn_805A1E0C(DbArrB* self, int chrg)
{
    self->~DbArrB();
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY char* fn_805A1EAC(char* p, int i)
{
    return p + (i * 336 + 12);
}

extern "C" DB_OVERLAY char* fn_805A1EBC(char* p, int i)
{
    return p + (i * 160 + 3036);
}

//@805A1ECC
extern "C" DB_OVERLAY void fn_805A1ECC(DbArrB* self, int chrg)
{
    self->~DbArrB();
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY char* fn_805A1F6C(char* p, int i)
{
    return p + ((i - 6) * 336 + 12);
}

extern "C" DB_OVERLAY char* fn_805A1F80(char* p, int i)
{
    return p + (i * 160 + 2716);
}

//@805A1F90
extern "C" DB_OVERLAY void fn_805A1F90(DbArrD* self, int chrg)
{
    self->~DbArrD();
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A2094()
{
    return 0;
}

extern "C" DB_OVERLAY char* fn_805A209C(char* p, int i)
{
    return p + ((i - 13) * 336 + 12);
}

extern "C" DB_OVERLAY char* fn_805A20B0(char* p, int i)
{
    return p + (i * 336 - 0x350);
}

extern "C" DB_OVERLAY int fn_805A20C0()
{
    return 0;
}

//@805A20C8
extern "C" DB_OVERLAY void fn_805A20C8(DbArrD* self, int chrg)
{
    self->~DbArrD();
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A21CC()
{
    return 0;
}

extern "C" DB_OVERLAY char* fn_805A21D4(char* p, int i)
{
    return p + ((i - 19) * 336 + 12);
}

extern "C" DB_OVERLAY char* fn_805A21E8(char* p, int i)
{
    return p + (i * 336 - 0xB30);
}

extern "C" DB_OVERLAY char* fn_805A21F8(char* p, int i)
{
    return p + (i * 336 + 160);
}

extern char lbl_80683B78[];

extern "C" DB_OVERLAY void fn_805A2208(U* self, int chrg)
{
    PUT(0xc, lbl_80683B78);
    if (chrg & 1)
        fn_80377408(self);
}

struct G4 { char pad[0x4]; int m; };

extern "C" DB_OVERLAY int fn_805A223C(G4* p)
{
    return p->m;
}

struct G8 { char pad[0x8]; int m; };

extern "C" DB_OVERLAY int fn_805A2244(G8* p)
{
    return p->m;
}

//@805A224C
struct VcC_2_D { char pad[0xC]; };
//@805A224C
struct VcC_2 : VcC_2_D {
    virtual void v1();
    virtual int v2();
};

struct Cnt8 : VcC_2 {
    int m10;
};

//@805A224C
extern "C" DB_OVERLAY void fn_805A224C(Cnt8* self, int a)
{
    if (a >= 0) {
        if (a < self->v2())
            *(int*)((char*)self + 8) = a;
    }
}

extern "C" DB_OVERLAY void fn_805A22A0(U* self, int chrg)
{
    PUT(0xc, lbl_80683B78);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_805A22D4(U* self, int chrg)
{
    PUT(0xc, lbl_80683B78);
    if (chrg & 1)
        fn_80377408(self);
}

struct GC { char pad[0xC]; int m; };

extern "C" DB_OVERLAY int fn_805A2308(GC* p)
{
    return p->m;
}

struct DtorAt1C { char pad[0x1c]; const void* m; };

extern char lbl_806839F0[];

extern "C" void fn_80593DD8(void* self, int a);

extern "C" DB_OVERLAY void fn_805A2310(DtorAt1C* self, int a)
{
    self->m = lbl_806839F0;
    fn_80593DD8(self, a);
}

extern "C" DB_OVERLAY int fn_805A2340()
{
    return 1;
}

extern "C" DB_OVERLAY void fn_805A2348()
{
}

extern char lbl_80683908[];

extern "C" DB_OVERLAY void fn_805A234C(DtorAt1C* self, int a)
{
    self->m = lbl_80683908;
    fn_80593DD8(self, a);
}

void fn_8058FFE4(char* p, int chrg);
extern char lbl_80683850[];

//@805A237C
inline void DbElemDtor(char* p)
{
    DtorAt1C* q = (DtorAt1C*)p;
    q->m = lbl_806839F0;
    fn_80593DD8(q, 2);
}

//@805A237C
extern "C" DB_OVERLAY void fn_805A237C(U* self, int chrg)
{
    char* t = (char*)self;
    PUT(0x438, lbl_80683850);
    fn_8058FFE4(t + 0x370, 2);
    DbElemDtor(t + 0x330);
    DbElemDtor(t + 0x2F0);
    DbElemDtor(t + 0x2B0);
    DbElemDtor(t + 0x270);
    DbElemDtor(t + 0x230);
    PUT(0x218, lbl_80683B78);
    PUT(0x1F4, lbl_80683B78);
    PUT(0x1D0, lbl_80683B78);
    PUT(0x1AC, lbl_80683B78);
    PUT(0x188, lbl_80683B78);
    PUT(0x164, lbl_80683B78);
    PUT(0x140, lbl_80683B78);
    PUT(0x11C, lbl_80683B78);
    PUT(0xF8, lbl_80683B78);
    PUT(0xD4, lbl_80683B78);
    PUT(0xB0, lbl_80683B78);
    PUT(0x8C, lbl_80683B78);
    PUT(0xC, lbl_80683B78);
    if (chrg & 1)
        fn_80377408(self);
}

extern char lbl_806837B8[];

extern "C" DB_OVERLAY void fn_805A2474(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A24A8()
{
    return -1;
}

extern "C" DB_OVERLAY int fn_805A24B0()
{
    return 0;
}

extern "C" DB_OVERLAY int fn_805A24B8()
{
    return 0;
}

extern "C" DB_OVERLAY int fn_805A24C0()
{
    return 0;
}

extern "C" DB_OVERLAY int fn_805A24C8()
{
    return 0;
}

extern "C" DB_OVERLAY void fn_805A24D0()
{
}

extern "C" DB_OVERLAY int fn_805A24D4()
{
    return -1;
}

struct Db8059FE24_Mem {
    char pad[0x20];
    int m20;
};

void fn_80361720(char* p, int chrg);
extern char lbl_80683720[];
extern char lbl_80683688[];
extern char lbl_806837B8[];

//@805A24DC
extern "C" DB_OVERLAY void fn_805A24DC(Db8059FE24_Mem* self, int chrg)
{
    PUT(0x4, lbl_80683720);
    fn_80361720((char*)self + 0x8C, 2);
    fn_80361720((char*)self + 0x60, 2);
    fn_80361720((char*)self + 0x34, 2);
    fn_80361720((char*)self + 0x8, 2);
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A2560()
{
    return 11;
}

extern "C" DB_OVERLAY int fn_805A2568()
{
    return 6;
}

extern "C" DB_OVERLAY int fn_805A2570()
{
    return 2;
}

extern "C" DB_OVERLAY int fn_805A2578()
{
    return 4;
}

//@805A2580
extern "C" DB_OVERLAY void fn_805A2580(Db8059FE24_Mem* self, int chrg)
{
    PUT(0x4, lbl_80683688);
    fn_80361720((char*)self + 0x8C, 2);
    fn_80361720((char*)self + 0x60, 2);
    fn_80361720((char*)self + 0x34, 2);
    fn_80361720((char*)self + 0x8, 2);
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}
