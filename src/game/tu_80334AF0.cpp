/*
 * Game code, .text 0x80334AF0-0x80338ECC (debug-menu classes: pitch/catch/camera
 * options; original file and TU boundaries unknown, placeholder). Every data
 * object is extern by its lbl_ name.
 */
#include "game/tu_80331C60.h"
#include "game/chooser.h"

extern "C" {
void fn_8032FB78(void* item, int v);
void fn_80330BC8(Menu* p, int k);
void fn_8032F120(void* item, const char* name, int v);
void fn_803349D0(Menu* p);
void fn_80334A60(Menu* p);
UnkC128* fn_803349B8(Menu* p);
}

struct V2F { float x; float y; };
/* Menu object whose vptr (+0x2DC) is dispatched virtually: slot 6 is the key handler
 * (fn_80330BC8 in the base vtable lbl_80666A18). */
class MenuVT {
public:
    char pad0[0x2DC];
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual void s6(int k);
};
/* Wrapper that embeds a menu at +0x24 and a screen vptr at +0x18. Evidence: fn_80335604
 * (ctor), fn_803356D4 (key handler). */
struct Wrap { char pad0[0x18]; const void* m18; char pad1C[8]; Menu sub; int m304; int m308; };
extern "C" {
void* fn_80328234(void* p, int a, int b);
void fn_80330B48(int a);
void fn_80331234(void* m);
void fn_80331294(void* m);
}
extern MenuVT* lbl_80620410;
struct Unk200 { char pad0[0x200]; int m200; };
extern Unk200* lbl_80620410b;
extern "C" { void fn_802D7ACC(); void fn_802D7ADC(); }
extern int lbl_80620414, lbl_806204E4, lbl_8061B9BC;
extern const char lbl_80665E78[], lbl_80665EC8[];
struct Unk80084910_N;
void fn_800860E0(Unk80084910_N* o, char* buf);
void fn_80086140(Unk80084910_N* o, char* buf);
extern "C" int fn_8033E958(const char* fmt, ...);
extern const char lbl_805EF344[], lbl_805EF348[], lbl_805EF390[], lbl_805EF3A0[], lbl_805EF3B0[], lbl_805EF3C8[], lbl_805EF3E4[], lbl_805EBC74[];
extern const char lbl_805EF400[], lbl_805EF410[], lbl_805EF41C[], lbl_805EF42C[], lbl_805EF438[], lbl_805EF448[];
extern const char lbl_805EF648[], lbl_805EF66C[], lbl_805EF680[], lbl_805EF694[], lbl_805EF6A8[], lbl_805EF6BC[];
struct I3 { int a[3]; };
extern const I3 lbl_805EFA78;
extern "C" {
void fn_802AE408(void* a, void* b);
void fn_802AD538(void* a, int k);
void fn_8037C9F4(Unk8037C7FC* a, int v);
}
struct Unk8061E978 { char pad0[8]; void* m8; };
extern Unk8061E978* lbl_8061E978;
void fn_80299B98(Unk80270BA0_X* x, const Unk80273498_Vec3& pos, float* ang);

/* Enum item: m4C is the chosen index, m60 the value table. */
struct MIE { char pad0[0x4C]; int m4C; char pad50[0x10]; int* m60; };
inline int EnumVal(MIE* i) { return i->m60[i->m4C]; }
inline MIE* EAt(Menu* p, int off) { return (MIE*)((char*)p + off); }

extern const char lbl_80666778[];
extern const char lbl_80666368[], lbl_805EF59C[], lbl_805EF5A4[], lbl_805EF5BC[], lbl_805F3504[];
extern int lbl_8062080C, lbl_80620810;
extern "C" {
void fn_8032E70C(void* item, const char* name, float a, float b, float c, float d);
void fn_8032E894(void* item, const char* name, int* val, float a, float b, float c, float d);
void fn_8032FAB0(void* item, const char* name, int* val, const void* tbl, int n, int cur);
}
extern float lbl_805EEF30, lbl_805EEF40;
extern int lbl_8062076C, lbl_80620784, lbl_80620780, lbl_80620760, lbl_80620764, lbl_80620768;
extern float lbl_80620770, lbl_8062077C;
extern V2F lbl_80620774;
extern "C" void fn_8032E088(void* item, V2F v);
struct Unk480 { char pad0[0x480]; int m480; };
extern "C" {
Unk480* fn_801C1638(UnkMgr8* m, int k);
float fn_8025356C(void* p);
void fn_80252DF4(void* p, float v);
}
extern int lbl_8061D030, lbl_8061D034, lbl_8061D038, lbl_8061D03C;
extern int lbl_8061D3F8, lbl_8061D3FC, lbl_8061D400, lbl_8061D404, lbl_8061D408, lbl_8061D40C;
extern int lbl_8061D410, lbl_8061D414, lbl_8061D418, lbl_8061D41C;
extern int lbl_80620830, lbl_8062083C;
extern int lbl_806E2A50[], lbl_806E3864[];
extern unsigned lbl_80620804;
extern V2F lbl_80691BEC;

extern const char lbl_805EF278[];
extern int lbl_8061CC00;
extern int lbl_80620418;

extern "C" {
int fn_80334AF0(Menu* p)
{
    if (fn_803349B8(p)->m6C == lbl_80620418)
        return 0;
    return 1;
}

int fn_80334B2C(Menu* p)
{
    int i = fn_80334AF0(p);
    UnkC128* o = fn_803349B8(p);
    return o->m14[i];
}

void fn_80334B70(Menu* p, int k)
{
    MIV* it = IAt(p, 0x328);
    int old = it->m4C;
    fn_80330BC8(p, k);
    if (old != it->m4C) {
        fn_80334A60(p);
        fn_803349D0(p);
    }
}

void fn_80334EB0() {}

void fn_8033531C(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
    UnkMgr8* m = lbl_8061B8C0->m8;
    SetV(IAt(p, 0x6D0), m->m700->m3B4->m1C);
    Unk404* c = m->m700->m404;
    SetVF(IAt(p, 0x784), c->m4);
    SetV(IAt(p, 0x7E8), (int)(c->m8 * 100.0f));
}

void fn_80335434(Menu* p)
{
    UnkMgr8* m = lbl_8061B8C0->m8;
    Unk3B4* t = m->m700->m3B4;
    t->m1C = GetV(IAt(p, 0x6D0));
    Unk404* c = m->m700->m404;
    {
        float a = GetVF2(IAt(p, 0x784));
        c->m4 = a;
    }
    {
        float b = (float)GetV2(IAt(p, 0x7E8)) * 0.01f;
        c->m8 = b;
    }
}

Wrap* fn_80335604(Wrap* p, int a, int b)
{
    fn_80328234(p, 12, 0);
    Menu* sub = &p->sub;
    MenuInit(sub, 0);
    p->sub.m2DC = lbl_80665E78;
    p->m18 = lbl_80665EC8;
    p->m308 = b;
    if (lbl_8061B9BC == 0)
        lbl_806204E4 = lbl_8061B9BC;
    p->m304 = a;
    fn_80330B48(a);
    if (p->m308) {
        fn_80331234(sub);
        int m = -1;
        lbl_80620418 = m;
    }
    return p;
}

void fn_803356D4(Wrap* p, int ev)
{
    UnkGm* g = lbl_8061B8C0;
    switch (ev) {
    case 10: {
        Unk200* cur = lbl_80620410b;
        if (cur->m200)
            fn_80330B48(cur->m200);
        break;
    }
    case 11: {
        int z = p->m308;
        if (z == 0) {
            fn_80330B48(p->m304);
            if (lbl_80620414) {
                fn_80331294(&p->sub);
                g->m24 = z;
                fn_802D7ACC();
            } else {
                fn_80331234(&p->sub);
                g->m24 = 1;
                fn_802D7ADC();
            }
        }
        break;
    }
    default:
        if (lbl_80620414)
            lbl_80620410->s6(ev);
        break;
    }
}

void fn_803357B4() {}

void fn_803361B0(Menu* p)
{
    fn_8032FB78((char*)p + 0x2E0, lbl_8062076C);
    fn_8032FB78((char*)p + 0x344, lbl_80620784);
    SetV(IAt(p, 0x3A8), lbl_80620780);
    SetV(IAt(p, 0x444), lbl_80620760);
    SetVF(IAt(p, 0x498), lbl_80620770);
    fn_8032E088((char*)p + 0x4FC, lbl_80620774);
    SetVF(IAt(p, 0x578), lbl_8062077C);
    SetV(IAt(p, 0x690), lbl_80620764);
    SetV(IAt(p, 0x628), lbl_80620768);
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
}

void fn_8033635C() {}

void fn_80336360()
{
    UnkMgr8* m = lbl_8061B8C0->m8;
    UnkObj65C* o = lbl_80620804 > 12 ? 0 : m->m65C[lbl_80620804];
    Unk80273498_Vec3 w;
    Unk80273498_Vec3 v = {0.0f, 0.0f, 0.0f};
    v.x = lbl_80691BEC.x;
    v.y = o->m64;
    v.z = lbl_80691BEC.y;
    w = v;
    fn_80299B98((Unk80270BA0_X*)o, w, 0);
}

void fn_80336418()
{
    UnkMgr8* m = lbl_8061B8C0->m8;
    UnkObj65C* o = lbl_80620804 > 12 ? 0 : m->m65C[lbl_80620804];
    V2F v = {0, 0};
    v.x = o->m60;
    v.y = o->m68;
    lbl_80691BEC = v;
}

Menu* fn_8033648C(Menu* p, int a)
{
    MenuInit(p, a);
    p->m2DC = lbl_80666778;
    fn_8032F120((char*)p + 0x2E0, lbl_805EF278, lbl_8061CC00);
    fn_80330ACC(p, (MItem*)((char*)p + 0x2E0));
    return p;
}

void fn_80336518(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
    SetV(IAt(p, 0x2E0), lbl_8061CC00);
}

void fn_803365B4(Menu* p) { lbl_8061CC00 = GetV(IAt(p, 0x2E0)); }

void fn_803367CC(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
}

void fn_80336844() {}

void fn_80336848()
{
    lbl_8061D3F8 = 0;
    lbl_8061D3FC = 0;
    lbl_8061D400 = 0;
    lbl_8061D404 = 0;
    lbl_8061D408 = 0;
    lbl_8061D40C = 0;
    lbl_8061D410 = 0;
    lbl_8061D414 = 0;
    lbl_8061D418 = 0;
    lbl_8061D41C = 0;
}

void fn_803368B0()
{
    fn_8033E958(lbl_805EF344);
    fn_8033E958(lbl_805EF348);
    fn_8033E958(lbl_805EF390, lbl_8061D404);
    fn_8033E958(lbl_805EF3A0, lbl_8061D408);
    fn_8033E958(lbl_805EF3B0, lbl_8061D400);
    fn_8033E958(lbl_805EF3C8, lbl_8061D3FC);
    fn_8033E958(lbl_805EF3E4, lbl_8061D3F8);
    fn_8033E958(lbl_805EBC74);
    fn_8033E958(lbl_805EF400, lbl_8061D40C);
    fn_8033E958(lbl_805EF410, lbl_8061D410);
    fn_8033E958(lbl_805EF41C, lbl_8061D414);
    fn_8033E958(lbl_805EF42C, lbl_8061D418);
    fn_8033E958(lbl_805EF438, lbl_8061D41C);
    fn_8033E958(lbl_805EBC74);
    fn_8033E958(lbl_805EF448);
}

void fn_80336D88(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
    fn_8032FB78((char*)p + 0x954, lbl_8061B8C0->m8->m6F8->m10->mC);
    SetV(IAt(p, 0x9B8), lbl_8061D030);
    fn_8032FB78((char*)p + 0xA0C, lbl_8061D034);
    SetV(IAt(p, 0xA70), lbl_8061D038);
    fn_8032FB78((char*)p + 0xAC4, lbl_8061D03C);
}

void fn_80336E88(Menu* p)
{
    UnkC128* c = lbl_8061B8C0->m8->m6F8->m10;
    c->mC = EnumVal(EAt(p, 0x954));
    lbl_8061D030 = GetV(IAt(p, 0x9B8));
    lbl_8061D034 = EnumVal(EAt(p, 0xA0C));
    lbl_8061D038 = GetV(IAt(p, 0xA70));
    lbl_8061D03C = EnumVal(EAt(p, 0xAC4));
}

void fn_80336F38(Menu* p, int k) { fn_80330BC8(p, k); }

Menu* fn_80336F58(Menu* p, int a)
{
    MenuInit(p, a);
    p->m2DC = lbl_80666368;
    fn_8032E70C((char*)p + 0x2E0, lbl_805EF59C, 0.0f, 0.1f, 0.0f, 1.0f);
    fn_8032E894((char*)p + 0x344, lbl_805EF5A4, &lbl_8062080C, 1.0f, 0.01f, 0.33f, 1.5f);
    fn_8032FAB0((char*)p + 0x3A8, lbl_805EF5BC, &lbl_80620810, lbl_805F3504, 3, -1);
    fn_80330ACC(p, (MItem*)((char*)p + 0x2E0));
    fn_80330ACC(p, (MItem*)((char*)p + 0x344));
    fn_80330ACC(p, (MItem*)((char*)p + 0x3A8));
    return p;
}

void fn_80337074(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
    Unk480* o = fn_801C1638(lbl_8061B8C0->m8, 0);
    float f = fn_8025356C(&o->m480);
    fn_8032FB78((char*)p + 0x3A8, o->m480);
    SetVF(IAt(p, 0x2E0), f);
}

void fn_80337148(Menu* p)
{
    Unk480* o = fn_801C1638(lbl_8061B8C0->m8, 0);
    fn_80252DF4(&o->m480, GetVF2(IAt(p, 0x2E0)));
    o->m480 = EnumVal(EAt(p, 0x3A8));
}

void fn_803371C4(Menu* p, int k) { fn_80330BC8(p, k); }

void fn_80337488()
{
    lbl_80620830 = 0;
    lbl_8062083C = 0;
}

void fn_803374A0()
{
    UnkMgr8* m = lbl_8061B8C0->m8;
    if (m) {
        UnkB6F8* b6 = m->m6F8;
        if (b6) {
            UnkC128* o = b6->m10;
            if (o) {
                char buf[0x10];
                fn_8033E958(lbl_805EF648);
                Unk80084910_N* a = (Unk80084910_N*)((char*)o + 0x78);
                Unk80084910_N* b = (Unk80084910_N*)((char*)o + 0x80);
                fn_800860E0(a, buf);
                fn_8033E958(lbl_805EF66C, buf);
                fn_80086140(a, buf);
                fn_8033E958(lbl_805EF680, buf);
                fn_800860E0(b, buf);
                fn_8033E958(lbl_805EF694, buf);
                fn_80086140(b, buf);
                fn_8033E958(lbl_805EF6A8, buf);
                fn_8033E958(lbl_805EF6BC);
            }
        }
    }
}

int fn_80337830(int i) { return lbl_806E2A50[i]; }

int fn_80337844(int i) { return lbl_806E3864[i]; }

void fn_80338054(int idx)
{
    if (idx == 0) {
        fn_802AE408(lbl_8061E978, lbl_8061E978->m8);
    } else {
        I3 t = lbl_805EFA78;
        fn_8037C9F4(fn_8037C7FC(), t.a[idx]);
    }
    fn_802AD538(lbl_8061E978, 0);
}

}
