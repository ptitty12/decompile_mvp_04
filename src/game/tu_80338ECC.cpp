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
struct V3x { float x; float y; float z; };
extern V3x lbl_805F2D64, lbl_805F2D70;
extern float lbl_805F2D7C;
extern int lbl_80620DF0, lbl_80691DEC;
struct Unk738Mgr { char pad0[0x738]; void* m738; };
extern "C" {
Rec24 fn_80326F44(int a, int b, float f, int k);
void fn_8030D1E4(void* o, int k, V3x* a, V3x* b, int z, float f);
}
struct KnotV { char pad0[4]; float m4; float m8; float mC; };
extern "C" void fn_80378D70(const char* src, unsigned int len, char* dst, int cap, int delim, unsigned int* outn);
extern "C" double fn_80409D88(const char* s);
struct Unk308 { char pad0[0x300]; int m300; char pad304[4]; int m308; int m30C; int m310; int m314; int m318; char pad31C[8]; int m324; char pad328[0xC0]; int m3E8; int m3EC; int m3F0; int m3F4; };
extern Unk308* lbl_8061EA68;
extern int lbl_80621574, lbl_80621578;
extern int lbl_80621510, lbl_80621514, lbl_8062087C, lbl_805C94A0[], lbl_805C9758[], lbl_8062150C, lbl_80621520, lbl_80621524, lbl_80621528, lbl_8062152C;
struct MIE3 { char pad0[0x4C]; int m4C; char pad50[0x10]; int* m60; };
extern "C" void fn_8032FB78(void* item, int v);
struct Unk3D40 { char pad0[0x3D40]; int m3D40; };
extern UnkGm* lbl_8068B618;
extern int lbl_80620860, lbl_80620864, lbl_80620868;
struct Unk588 { char pad0[0x588]; int m588; };
extern "C" {
Unk588* fn_801A4910(UnkMgr8* m, int a, int b);
void fn_802542E8(void* p, int k, void* buf);
}
extern "C" {
void fn_801A0790(UnkMgr8* m, float f);
Unk3D40* fn_801A6D84(UnkMgr8* m, int i);
void fn_80086EC0(void* o, int a, int b);
void fn_801A23B8(UnkMgr8* m, int k);
}
extern char* lbl_8061E978;
extern const char lbl_805F2FB0[];
extern "C" {
int fn_8040B574(const char* a, const char* b);
void fn_802B1E38(Unk308* o, char* name, int v);
void fn_802B5234(void* p);
}
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

extern "C" void fn_8033982C()
{
    UnkMgr8* m = lbl_8068B618->m8;
    fn_80331294(lbl_8061B998 + 0x24);
    if (m) {
        int v = lbl_80620868;
        if (v > 0)
            *(int*)((char*)m->m6F8->m10 + 0x1C) = v;
        fn_801A0790(m, (float)m->m4C * 0.016666668f + 4500.0f);
        int i = 0;
        do {
            Unk3D40* o = fn_801A6D84(m, i);
            if (o)
                o->m3D40 = 1;
            i++;
        } while (i <= 5);
        fn_80086EC0(m->m6F8->m10, 0, -1);
        fn_80086EC0(m->m6F8->m10, 1, -1);
        fn_801A23B8(m, 1);
    }
    lbl_80620860 = 1;
    if (lbl_80620864 <= 0)
        lbl_80620864 = 255;
    lbl_8061B8C0->m24 = 0;
    fn_802D7ACC();
}

extern "C" void fn_80339968()
{
    UnkMgr8* m = lbl_8068B618->m8;
    lbl_80620860 = 0;
    fn_801A0790(m, (float)m->m4C * 0.016666668f);
    int i = 0;
    do {
        Unk3D40* o = fn_801A6D84(m, i);
        i++;
        if (o)
            o->m3D40 = 0;
    } while (i <= 5);
}

extern "C" void fn_80339A08()
{
    char buf[0x80];
    int a = 0;
    UnkMgr8* m = lbl_8061B8C0->m8;
    do {
        int b = 0;
        do {
            Unk588* o = fn_801A4910(m, a, b);
            b++;
            if (o)
                fn_802542E8(&o->m588, 1, buf);
        } while (b <= 0x18);
        a++;
    } while (a <= 1);
}

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

extern "C" void fn_8033B220()
{
    int a = lbl_80620DF0;
    float f = fn_8033ACE8()->m4;
    Rec24* dst = fn_8033ACE8();
    *dst = fn_80326F44(lbl_80691DEC, a, f, 1);
}

extern "C" void fn_8033B2B0()
{
    UnkOpt2* o = fn_801A04A8(lbl_8061B8C0->m8, 1);
    float v = fn_8033ACE8()->m4;
    o->m4C = v;
}

extern "C" void fn_8033B300() { *fn_8033ACE8() = lbl_805EBA10; }

/* near-miss: 140 vs 143 instructions; the value/pointer registers of the first two GetV reads
 * and the item-pointer reuse around the clamp differ (3 attempts). */
extern "C" int fn_8033B8D8(Menu* p, int k)
{
    fn_80330BC8(p, k);
    lbl_80621510 = GetV(IAt(p, 0x460));
    lbl_80621514 = GetV(IAt(p, 0x4B4));
    MIE3* e = (MIE3*)((char*)p + 0x32C);
    int v = e->m60[e->m4C];
    lbl_8062087C = v;
    SetV(IAt(p, 0x390), lbl_805C94A0[v]);
    int lim = lbl_805C9758[v];
    if (GetV2(IAt(p, 0x3F8)) > lim)
        SetV(IAt(p, 0x3F8), lim);
    lbl_8062150C = GetV2(IAt(p, 0x3F8));
    *(int*)((char*)p + 0x454) = lim;
    fn_8032FB78((char*)p + 0x60C, fn_8033ACE8()->m8);
    fn_8032FB78((char*)p + 0x670, fn_8033ACE8()->mC);
    SetVF(IAt(p, 0x6D4), fn_8033ACE8()->m4);
    lbl_80621520 = GetV(IAt(p, 0x880));
    lbl_80621524 = GetV2(IAt(p, 0x8D4));
    lbl_80621528 = GetV(IAt(p, 0x93C));
    lbl_8062152C = GetV2(IAt(p, 0x990));
    return GetV(IAt(p, 0x9F8));
}

extern "C" void fn_8033BB14(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
    SetV(IAt(p, 0x9F8), lbl_8062151C);
}

/* near-miss: 13 slots (schedule of the two 12-byte copies against the lis/addi of the globals;
 * 24 statement orders tried). */
extern "C" void fn_8033BBB0()
{
    int z = 0;
    UnkMgr8* m = lbl_8061B8C0->m8;
    V3x a = lbl_805F2D64;
    V3x b = lbl_805F2D70;
    fn_8030D1E4(m->m738, 11, &a, &b, 0, lbl_805F2D7C);
    fn_80331294(lbl_8061B998 + 0x24);
    lbl_8061B8C0->m24 = z;
    fn_802D7ACC();
}

extern "C" void fn_8033BC68()
{
    if (lbl_8061FE10)
        lbl_8062157C = (int)fn_8030EBC8(lbl_8061FE10, (void*)lbl_8062157C, 1);
}

extern "C" void fn_8033C75C(Menu* p)
{
    Unk308* o = lbl_8061EA68;
    SetV(IAt(p, 0x11C0), o->m310);
    SetV(IAt(p, 0x1228), o->m314);
    SetV(IAt(p, 0x1088), o->m308);
    SetV(IAt(p, 0x1158), o->m3F4);
    SetV(IAt(p, 0x10F0), o->m30C);
    SetV(IAt(p, 0x1290), o->m318);
    SetV(IAt(p, 0x12F8), o->m324);
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
}

extern "C" void fn_8033C8BC(Menu* p, int k)
{
    int i = 0;
    fn_80330BC8(p, k);
    Unk308* o = lbl_8061EA68;
    if (i < o->m300) {
        MIV* it = IAt(p, 0x2E0);
        char* name = (char*)o;
        do {
            int v = GetV2(it);
            int c = v;
            if (c > 5)
                c = 5;
            if (fn_8040B574(name, lbl_805F2FB0) != 0)
                fn_802B1E38(o, name, c);
            i++;
            it = (MIV*)((char*)it + 0x68);
            name += 0x18;
        } while (i < o->m300);
    }
    int a = GetV2(IAt(p, 0x1228));
    int b = GetV2(IAt(p, 0x11C0));
    int c = GetV2(IAt(p, 0x1088));
    int d = GetV2(IAt(p, 0x1158));
    int e = GetV2(IAt(p, 0x10F0));
    int f = GetV2(IAt(p, 0x1290));
    int g = GetV2(IAt(p, 0x12F8)) - 1;
    lbl_80621574 = GetV(IAt(p, 0xFE0));
    lbl_80621578 = GetV(IAt(p, 0x1034));
    o->m314 = a;
    o->m310 = b;
    o->m308 = c;
    o->m30C = e;
    o->m3F4 = d;
    o->m318 = f;
    o->m324 = g;
    fn_802B5234(lbl_8061E978 + 8);
    o->m3E8 = 1;
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

extern "C" void fn_8033CC0C(KnotV* o, const char* s, unsigned int len)
{
    const char* cur = s;
    unsigned int n = 0;
    char buf[0x20];
    fn_80378D70(cur, len, buf, 0x19, 0x2C, &n);
    o->mC = (float)fn_80409D88(buf);
    cur += n + 1;
    fn_80378D70(cur, len, buf, 0x19, 0x2C, &n);
    o->m4 = (float)fn_80409D88(buf);
    cur += n + 1;
    fn_80378D70(cur, len, buf, 0x19, 0x23, &n);
    o->m8 = (float)fn_80409D88(buf);
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
