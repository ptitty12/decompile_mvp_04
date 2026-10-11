/*
 * Game code, .text 0x80338ECC-0x8033CED8 (debug-menu classes: draw/replay/weather
 * options, spline knot sets; original file and TU boundaries unknown,
 * placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80331C60.h"

/* 24-byte record array at lbl_80691BF4 (selected by lbl_80691DF4). Evidence:
 * fn_8033ACE8 (&arr[idx], stride 0x18), fn_8033B300 (copies a 24-byte default). */
struct Rec24 { float m0; float m4; int m8; int mC; int m10; int m14; };
struct UnkOpt2 { char pad0[0x4C]; float m4C; };

/* Knot record: 0x10 bytes with a virtual destructor (vptr at +0xC); six of them make
 * a knot set whose vptr sits at +0x64. Evidence: fn_8033CB30 (ctor loop), fn_8033CB88
 * (array destruction through the virtual dtor, slot 1). */
class KnotAB {
public:
    char pad0[0xC];
    virtual void s1(int c);
};
struct KnotA { int m0; int m4; int m8; const void* mC; KnotA(); };
struct KnotSet { KnotA k[6]; char pad60[4]; const void* m64; };
struct KnotBuf { const void* m0; void* m4; int m8; };

extern Rec24 lbl_80691BF4[];
extern int lbl_80691DF4;
extern Rec24 lbl_805EBA10;
struct Unk54 { char pad0[0x54]; int m54; };
extern Unk54* lbl_8061FEDC;
extern int lbl_8061BE30, lbl_8061F958, lbl_8061F968, lbl_8061FF70, lbl_8061D2B8;
extern int lbl_8062151C, lbl_80621518, lbl_8062157C;
extern void* lbl_8061FE10;
extern char* lbl_8061B998;
extern const char lbl_80666820[];
extern const char lbl_80666808[];
extern const char lbl_806667C8[];

extern "C" {
void fn_80330BC8(Menu* p, int k);
void fn_8015F918(void* p, int k);
void fn_80331294(void* p);
void fn_802D7ACC();
UnkOpt2* fn_801A04A8(UnkMgr8* m, int k);
void* fn_8030EBC8(void* a, void* b, int k);
Rec24* fn_8033ACE8();
void fn_8033CB2C(KnotA* p);
void fn_8033CD74(KnotBuf* p);
void fn_80356798(void* p);
void fn_80377488(void* p);
}

inline void* operator new(unsigned int, void* p) { return p; }

/* definitions */
extern "C" void fn_80339530(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
    SetV(IAt(p, 0xF90), lbl_8061FEDC->m54);
    SetV(IAt(p, 0xE94), lbl_8061BE30);
    SetV(IAt(p, 0x1190), lbl_8061F958);
    SetV(IAt(p, 0x11E4), lbl_8061F968);
    SetV(IAt(p, 0x1238), lbl_8061FF70);
    SetV(IAt(p, 0x128C), lbl_8061D2B8);
    SetV(IAt(p, 0x1430), 0);
}

extern "C" void fn_80339790(Menu* p, int k) { fn_80330BC8(p, k); }

extern "C" void fn_803397B0(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
}

extern "C" void fn_80339828() {}

Rec24* fn_8033ACE8() { return &lbl_80691BF4[lbl_80691DF4]; }

extern "C" void fn_8033AE60()
{
    int z = 0;
    fn_8015F918(lbl_8061B8C0->m8->m710, 4);
    lbl_80621518 = 1;
    UnkGm* g = lbl_8061B8C0;
    fn_80331294(lbl_8061B998 + 0x24);
    g->m24 = z;
    fn_802D7ACC();
}

extern "C" void fn_8033B2B0()
{
    UnkOpt2* o = fn_801A04A8(lbl_8061B8C0->m8, 1);
    float v = fn_8033ACE8()->m4;
    o->m4C = v;
}

extern "C" void fn_8033B300() { *fn_8033ACE8() = lbl_805EBA10; }

extern "C" void fn_8033BB14(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
    SetV(IAt(p, 0x9F8), lbl_8062151C);
}

extern "C" void fn_8033BC68()
{
    if (lbl_8061FE10)
        lbl_8062157C = (int)fn_8030EBC8(lbl_8061FE10, (void*)lbl_8062157C, 1);
}

/* fn_8033CAB4 */
KnotA::KnotA()
{
    mC = lbl_80666820;
    m0 = 0;
    m4 = 0;
    m8 = 0;
}

extern "C" void fn_8033CAD8(KnotA* p, int c)
{
    p->mC = lbl_80666820;
    fn_8033CB2C(p);
    p->m8 = 0;
    if (c & 1)
        fn_80377408(p);
}

extern "C" void fn_8033CB2C(KnotA* p) {}

extern "C" KnotSet* fn_8033CB30(KnotSet* p)
{
    p->m64 = lbl_80666808;
    KnotA* e = p->k;
    int n = 5;
    do {
        new (e) KnotA;
        e++;
    } while (n-- != 0);
    return p;
}

extern "C" void fn_8033CB88(KnotSet* p, int c)
{
    p->m64 = lbl_80666808;
    if (p) {
        KnotA* e = p->k + 6;
        if ((KnotA*)p != e) {
            do {
                e--;
                ((KnotAB*)e)->s1(0);
            } while ((KnotA*)p != e);
        }
    }
    if (c & 1)
        fn_80377408(p);
}

extern "C" KnotBuf* fn_8033CCE0(KnotBuf* p)
{
    fn_80356798(p);
    p->m4 = 0;
    p->m0 = lbl_806667C8;
    p->m8 = 0;
    return p;
}

extern "C" void fn_8033CD28(KnotBuf* p, int c)
{
    p->m0 = lbl_806667C8;
    fn_8033CD74(p);
    if (c & 1)
        fn_80377408(p);
}

extern "C" void fn_8033CD74(KnotBuf* p)
{
    if (p->m8 && p->m4) {
        fn_80377488(p->m4);
        p->m8 = 0;
        p->m4 = 0;
    }
}
