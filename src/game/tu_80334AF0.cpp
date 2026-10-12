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
struct P3 { const char* a[3]; };
extern const P3 lbl_805EED20;
extern const char lbl_805EED2C[];
void* fn_802BB19C();
int fn_802BB4C0(char* o, int i);
int fn_802BB4D0(char* o, int i);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void fn_8032D880(void* cmd, char* text);
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

extern int lbl_8061D3A4, lbl_8061D3A8, lbl_8061D3AC, lbl_8061D3B0, lbl_8061D3B4, lbl_8061D3B8, lbl_8061D3BC, lbl_8061D3C0, lbl_8061D3C4;
extern const char lbl_805EF288[], lbl_805EF298[], lbl_805EF2AC[], lbl_805EF2C4[], lbl_805EF2D4[], lbl_805EF2E4[], lbl_805EF2F8[], lbl_805EF310[], lbl_805EF328[];
extern const char lbl_80666728[];
extern "C" void fn_8032F19C(void* item, const char* name, int* val, int init);
extern const char lbl_805EF48C[], lbl_805EED98[], lbl_805EF4A4[], lbl_805EF4B4[], lbl_805EF4D0[], lbl_805EF4E8[], lbl_805EF500[], lbl_805EF514[], lbl_805EF524[], lbl_805EF53C[], lbl_805EF550[], lbl_805EF564[];
extern const char lbl_805F34B4[], lbl_805F34C4[], lbl_805F34D4[], lbl_806666D8[], lbl_80666E20[], lbl_80666DD0[];
extern int lbl_8061CB80, lbl_806207B4, lbl_806207C4, lbl_806207D4, lbl_8061C68C, lbl_8061D034, lbl_8061D03C;
extern "C" {
void fn_8032FAB0(void* item, const char* name, int* val, const void* tbl, int n, int cur);
void fn_8033FBD8(void* item, void* cb);
Menu* fn_8032BAF4(Menu* p, int a);
void fn_803368B0();
void fn_80336848();
}
extern const char lbl_80666778[];
extern const char lbl_80665FA8[], lbl_80666E70[], lbl_805EBBF8[], lbl_80666EC0[];
extern "C" void fn_8032D868(void* item, const char* name);
/* inline base-item ctor + name, as emitted in the menu ctors */
inline void LabelInit(ItemB* it, const char* name)
{
    it->m8 = lbl_80666EC0;
    it->m0 = 0.0f;
    it->m4 = 0.0f;
    it->m8 = lbl_80666E70;
    it->mC = 0;
    fn_8032D868(it, name);
}
extern const char lbl_80666368[], lbl_805EF59C[], lbl_805EF5A4[], lbl_805EF5BC[], lbl_805F3504[];
extern int lbl_8062080C, lbl_80620810;
extern "C" {
void fn_8032E70C(void* item, const char* name, float a, float b, float c, float d);
void fn_8032E894(void* item, const char* name, int* val, float a, float b, float c, float d);
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

Menu* fn_80334BC0(Menu* p, int a)
{
    MenuInit(p, a);
    p->m2DC = lbl_80665FA8;
    ItemB* i0 = (ItemB*)((char*)p + 0x2E0);
    ItemB* i1 = (ItemB*)((char*)p + 0x328);
    ItemB* i2 = (ItemB*)((char*)p + 0x370);
    LabelInit(i0, lbl_805EBBF8);
    LabelInit(i1, lbl_805EBBF8);
    LabelInit(i2, lbl_805EBBF8);
    fn_80330ACC(p, (MItem*)i0);
    fn_80330ACC(p, (MItem*)i1);
    fn_80330ACC(p, (MItem*)i2);
    return p;
}

/* near-miss: 2 slots. Retail loads items[0] with `lwzx r11,r31,r30` (r30 = the shared zero register, no constant fold) before
   the m174 store; here the index folds to `lwz r11,0(r31)` after it. Same unfolded-zero-index shape as fn_80327214. */
extern "C" void fn_80334CDC(Menu* self) {
    char* h = (char*)fn_802BB19C();
    P3 nm = lbl_805EED20;
    float a, b, c;
    char buf[0x68];
    void* items[2];
    items[0] = (char*)self + 0x2E0;
    items[1] = (char*)self + 0x328;
    int i = 0;
    do {
        a = (float)fn_802BB4C0(h, i) * 0.001f;
        b = (float)fn_802BB4D0(h, i) * 0.001f;
        c = (1.0f - b / a) * 100.0f;
        sprintf(buf, lbl_805EED2C, nm.a[i], (int)a, (int)b, (int)c);
        fn_8032D880(items[i], buf);
        i++;
    } while (i <= 1);
    self->m204 = 0;
    self->m208 = 0;
    self->items[self->m174]->s3();
    MItem* it0 = self->items[0];
    self->m174 = 0;
    it0->s2();
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

/* Reorders the menu's items to follow a delimited name list: each token is looked up by
 * the item's s6() name and the matching item is moved to the next free front slot. */
extern const char lbl_805EEF58[];
extern "C" {
int fn_8040B574(const char* a, const char* b);
char* fn_8040B9B0(char* s, const char* delim);
}

extern "C" void fn_803354FC(Menu* p)
{
    char buf[0x400] = "";
    buf[0] = 0;
    int k = 0;
    char* tok = fn_8040B9B0(buf, lbl_805EEF58);
    while (tok) {
        int i = 0;
        MItem** pp = p->items;
        while (i < p->m178) {
            if (fn_8040B574(tok, (*pp)->s6()) == 0)
                break;
            pp++;
            i++;
        }
        MItem* it = p->items[i];
        if (i > k) {
            do {
                p->items[i] = p->items[i - 1];
                i--;
            } while (i > k);
        }
        p->items[i] = it;
        k++;
        tok = fn_8040B9B0(0, lbl_805EEF58);
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

Menu* fn_803365DC(Menu* p, int a)
{
    MenuInit(p, a);
    p->m2DC = lbl_80666728;
    fn_8032F19C((char*)p + 0X2E0, lbl_805EF288, &lbl_8061D3A4, lbl_8061D3A4);
    fn_8032F19C((char*)p + 0X334, lbl_805EF298, &lbl_8061D3A8, lbl_8061D3A8);
    fn_8032F19C((char*)p + 0X388, lbl_805EF2AC, &lbl_8061D3AC, lbl_8061D3AC);
    fn_8032F19C((char*)p + 0X3DC, lbl_805EF2C4, &lbl_8061D3B0, lbl_8061D3B0);
    fn_8032F19C((char*)p + 0X430, lbl_805EF2D4, &lbl_8061D3B4, lbl_8061D3B4);
    fn_8032F19C((char*)p + 0X484, lbl_805EF2E4, &lbl_8061D3B8, lbl_8061D3B8);
    fn_8032F19C((char*)p + 0X4D8, lbl_805EF2F8, &lbl_8061D3BC, lbl_8061D3BC);
    fn_8032F19C((char*)p + 0X52C, lbl_805EF310, &lbl_8061D3C0, lbl_8061D3C0);
    fn_8032F19C((char*)p + 0X580, lbl_805EF328, &lbl_8061D3C4, lbl_8061D3C4);
    fn_80330ACC(p, (MItem*)((char*)p + 0X2E0));
    fn_80330ACC(p, (MItem*)((char*)p + 0X334));
    fn_80330ACC(p, (MItem*)((char*)p + 0X388));
    fn_80330ACC(p, (MItem*)((char*)p + 0X3DC));
    fn_80330ACC(p, (MItem*)((char*)p + 0X430));
    fn_80330ACC(p, (MItem*)((char*)p + 0X484));
    fn_80330ACC(p, (MItem*)((char*)p + 0X4D8));
    fn_80330ACC(p, (MItem*)((char*)p + 0X52C));
    fn_80330ACC(p, (MItem*)((char*)p + 0X580));
    return p;
}

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

/* near-miss (parked): 219 vs 222 instructions. Shape and calls are right; retail spills the
 * 0x900 and 0xAC4 item pointers to the stack and keeps the others in r14..r31 in a different
 * order than mine. Declaration order of the 15 pointer locals not searched. */
Menu* fn_80336A10(Menu* p, int a)
{
    ItemB* i0 = (ItemB*)((char*)p + 0x2E0);
    Menu* s0 = (Menu*)((char*)p + 0x32C);
    void* i1 = (char*)p + 0x900;
    void* i2 = (char*)p + 0x954;
    void* i3 = (char*)p + 0x9B8;
    void* i4 = (char*)p + 0xA0C;
    void* i5 = (char*)p + 0xA70;
    void* i6 = (char*)p + 0xAC4;
    ItemB* i7 = (ItemB*)((char*)p + 0xB28);
    Menu* s7 = (Menu*)((char*)p + 0xB74);
    ItemB* i8 = (ItemB*)((char*)p + 0xEA8);
    Menu* s8 = (Menu*)((char*)p + 0xEF4);
    void* i9 = (char*)p + 0x1568;
    ItemB* i10 = (ItemB*)((char*)p + 0x15BC);
    ItemB* i11 = (ItemB*)((char*)p + 0x1608);
    MenuInit(p, a);
    p->m2DC = lbl_806666D8;
    LabelInit(i0, lbl_805EF48C);
    i0->m48 = s0;
    i0->m8 = lbl_80666E20;
    fn_803365DC(s0, (int)p);
    fn_8032F19C(i1, lbl_805EED98, &lbl_8061CB80, 0);
    fn_8032FAB0(i2, lbl_805EF4A4, &lbl_806207B4, lbl_805F34B4, 4, 1);
    fn_8032F19C(i3, lbl_805EF4B4, &lbl_8061D030, 0);
    fn_8032FAB0(i4, lbl_805EF4D0, &lbl_806207C4, lbl_805F34C4, 4, lbl_8061D034);
    fn_8032F19C(i5, lbl_805EF4E8, &lbl_8061D038, 0);
    fn_8032FAB0(i6, lbl_805EF500, &lbl_806207D4, lbl_805F34D4, 12, lbl_8061D03C);
    LabelInit(i7, lbl_805EF514);
    i7->m48 = s7;
    i7->m8 = lbl_80666E20;
    fn_8033648C(s7, (int)p);
    LabelInit(i8, lbl_805EF524);
    i8->m48 = s8;
    i8->m8 = lbl_80666E20;
    fn_8032BAF4(s8, (int)p);
    fn_8032F19C(i9, lbl_805EF53C, &lbl_8061C68C, lbl_8061C68C);
    LabelInit(i10, lbl_805EF550);
    i10->m8 = lbl_80666DD0;
    fn_8033FBD8(i10, (void*)fn_803368B0);
    LabelInit(i11, lbl_805EF564);
    i11->m8 = lbl_80666DD0;
    fn_8033FBD8(i11, (void*)fn_80336848);
    fn_80330ACC(p, (MItem*)i0);
    fn_80330ACC(p, (MItem*)i1);
    fn_80330ACC(p, (MItem*)i2);
    fn_80330ACC(p, (MItem*)i3);
    fn_80330ACC(p, (MItem*)i4);
    fn_80330ACC(p, (MItem*)i5);
    fn_80330ACC(p, (MItem*)i6);
    fn_80330ACC(p, (MItem*)i7);
    fn_80330ACC(p, (MItem*)i8);
    fn_80330ACC(p, (MItem*)i9);
    fn_80330ACC(p, (MItem*)i10);
    fn_80330ACC(p, (MItem*)i11);
    return p;
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
