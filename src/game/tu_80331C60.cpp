/*
 * Game code, .text 0x80331C60-0x80334AF0 (debug-menu classes and option toggles;
 * original file and TU boundaries unknown, placeholder). Every data object is
 * extern by its lbl_ name.
 */
#include "game/tu_80331C60.h"

/* Menu whose 20 item slots (0x18 bytes each: item pointer plus a name field) sit
 * at +0x2E0 with the count at +0x4C0. Evidence: fn_80332398 / fn_80332584 delete
 * them in a loop, fn_80332520 passes the name field at +4 to fn_8040B6A0. */
struct MenuListEnt { MItem* m0; char m4[0x14]; };
struct MenuL : Menu {
    MenuListEnt e[20];
    int m4C0;
};

struct MenuV : Menu {
    char pad2E0[0x94];
    int m374;
};

inline MIV* ItemAt2(Menu* p, int i)
{
    char* b = (char*)p + 0x388;
    int off = i * 4;
    return *(MIV**)(b + off);
}
inline MIV* ItemAtA(Menu* p, int i)
{
    char* b = (char*)p + 0x334;
    int off = i * 4;
    return *(MIV**)(b + off);
}
inline MIV* ItemAtB(Menu* p, int i)
{
    char* b = (char*)p + 0x370;
    int off = i * 4;
    return *(MIV**)(b + off);
}
inline MIV* ItemAt(Menu* p, int i)
{
    char* b = (char*)p + 0x418;
    int off = i * 4;
    return *(MIV**)(b + off);
}
extern int lbl_8061EDC0, lbl_8061B88C;
extern int lbl_8061EDCC, lbl_8061FE94, lbl_8061F830, lbl_8068B4BC, lbl_8061C900, lbl_8061B894;
extern int lbl_8061CB80, lbl_8061D3AC, lbl_80691CA8;
extern int lbl_8061D3A0, lbl_8068CD0C, lbl_8068B5D0, lbl_80691DE0, lbl_80691DE4;
extern float lbl_806203BC, lbl_806203C0, lbl_806203C4;

extern "C" {
void fn_8032FAB0(void* item, const char* name, int* val, const void* tbl, int n, int cur);
void fn_8032D880(void* item, const char* s);
int fn_80148404(UnkGm* g);
UnkOpt* fn_801A4CE8(UnkMgr8* m, int k);
void fn_80331508();
void fn_80331568();
void fn_80330F98(Menu* p);
void fn_80330BC8(Menu* p, int k);
void fn_802D7ACC();
void fn_802D7ADC();
int fn_802D7CE0(int a, int b);
int fn_80332318(void* self, int a, int b);
void fn_8040B6A0(char* s);
int fn_8023C6C4(char* o, int i);
int fn_8023C1D8(char* o);
void fn_8023C1E0(char* o, int v);
void fn_8032D868(void* item, const char* s);
void fn_801A4674(UnkMgr8* m);
void fn_80333E28(Menu* p);
void fn_80333E98(Menu* p);
void fn_80334504(Menu* p);
int fn_8023C3E0(char* o, int i, int k);
void fn_8023C490(char* o, int i, int k, int v);
void fn_8009DC48(void* o, int v);
extern char lbl_8068CC18[];
int fn_80334AF0(Menu* p);
int fn_80334B2C(Menu* p);
UnkC128* fn_803349B8(Menu* p);
struct MenuV;
void fn_803349D0(MenuV* p);
void fn_80334A60(MenuV* p);
void fn_80334604(Menu* p);
void fn_8023C6F8(char* o, int i, int v);
void fn_8022E92C(void* h, int k);
int fn_804089B4(char* buf, const char* fmt, ...);
}
struct Unk80039B04_Mgr;
struct Unk8005BA1C_Obj;
extern "C" Unk80039B04_Mgr* fn_80038EB4();
void fn_8003A0B0(Unk80039B04_Mgr* m, int a);
void fn_8003A130(Unk80039B04_Mgr* m);
Unk8005BA1C_Obj* fn_8005BA9C();
int fn_8005C410(Unk8005BA1C_Obj* o, int k, float f);
void fn_8017E264(Unk8017DD64_T* t);
extern char lbl_8068CCA8[];
/* one-int struct: keeps the compiler from reordering the store past item-pointer loads (MEM_IN_STRUCT_P) */
struct IntBox { int v; };
extern IntBox lbl_8068CCB0, lbl_8068CC9C;
extern int lbl_8068CCB4;
extern const char* lbl_80620564[];
extern const char lbl_80666EC0[];
extern const char lbl_80666048[];
extern const char lbl_80665FF8[];
extern const char lbl_80666098[];
struct Unk80084910_S;
struct Unk80087A58_O;
void fn_80087A50(Unk80084910_S* s, int v);
void fn_80087A58(Unk80087A58_O* s, int a, char v, int w, int flag);
int fn_80087A88(Unk80087A58_O* s, int a, int w, int flag);
void fn_80087B10();
extern int lbl_806177DC;
extern int lbl_806164F8, lbl_80616EE0, lbl_806177E0, lbl_806177E4, lbl_806177E8;
extern int lbl_806177EC, lbl_8061651C, lbl_80616EE4, lbl_80616EE8, lbl_80620548;
extern IntBox lbl_80687608, lbl_8068760C, lbl_80687610, lbl_80687614, lbl_80687618, lbl_8068761C, lbl_80687620, lbl_80687624;
extern float lbl_80620540, lbl_80620544;
struct MIE2 { char pad0[0x4C]; int m4C; char pad50[0x10]; int* m60; };
inline int EnumVal2(MIE2* i) { return i->m60[i->m4C]; }
inline MIE2* EAt2(Menu* p, int off) { return (MIE2*)((char*)p + off); }
/* Button item (0x4C bytes): +0/+4 floats, vptr at +8, +0xC flag, callback at +0x48. Evidence: the
 * inline base-item ctor in fn_80332978 stores m0, m4, vptr and mC, then fn_8032D868 sets the
 * name and fn_8033FBD8 the callback. */
struct ItemB { float m0; float m4; const void* m8; int mC; char pad10[0x38]; void* m48; };
extern const char lbl_80666E70[], lbl_80666DD0[], lbl_80666E20[], lbl_80666138[];
extern const char lbl_805EDE40[], lbl_805EDE5C[], lbl_805EDE78[], lbl_805EDE94[], lbl_805EDEAC[], lbl_805EDEC4[], lbl_805EDEDC[], lbl_805EDEF0[], lbl_805EDF08[];
extern int lbl_80620530[];
extern "C" {
void fn_8032F120(void* item, const char* name, int v);
void fn_8032F428(void* item, const char* name, const void* tbl, int n, int cur);
void fn_8033FBD8(void* item, void* cb);
void fn_80332930();
void fn_80332954();
void fn_80333848(void* menu, Menu* owner);
}
extern const char lbl_805EDDD4[];
extern int lbl_80691DD8;
extern "C" {
void fn_8032FB78(void* item, int v);
void fn_80086EC0(void* o, int a, int b);
void fn_801A23B8(UnkMgr8* m, int k);
void fn_801A6820(UnkMgr8* m);
}
extern const char lbl_805EDD98[], lbl_805EDDA4[], lbl_805EDDB0[], lbl_805EDDBC[], lbl_805EDDC8[];
extern int lbl_8062050C, lbl_80620520;
extern const char lbl_805F3428[], lbl_805F343C[];
extern const char lbl_80666318[];
extern const char lbl_80666278[];
extern const char lbl_80666228[];

extern "C" {
void fn_80331C60()
{
    lbl_8061EDC0 = 0;
    UnkMgr8* m = lbl_8061B8C0->m8;
    int f = fn_801A4CE8(m, 1)->m10;
    f = (f == 1) ? 0 : 1;
    fn_801A4CE8(m, 1)->mC = 0;
    fn_801A4CE8(m, 1)->m10 = f;
    lbl_8061B88C = f ^ 1;
    fn_80331508();
}

void fn_80331CF0()
{
    UnkMgr8* m = lbl_8061B8C0->m8;
    UnkOpt* o = fn_801A4CE8(m, 1);
    o->mA0 = (fn_801A4CE8(m, 1)->mA0 == 1) ? 0 : 1;
    fn_80331508();
}

void fn_80331D58()
{
    lbl_8061EDC0 = 0;
    UnkMgr8* m = lbl_8061B8C0->m8;
    fn_801A4CE8(m, 1)->m10 = 0;
    fn_801A4CE8(m, 1)->mC = 0;
    fn_80331508();
}

/* near-miss: 9 slots, all the `mr r3,<item ptr>` placement (retail emits it after the other
 * argument moves, which a free-function call does not; probably a ctor/method call whose
 * callee fn_8032FAB0 is in an unmatched unit). */
Menu* fn_80331DB8(Menu* p, int a)
{
    MenuInit(p, a);
    p->m2DC = lbl_80666318;
    fn_8032FAB0((char*)p + 0x2E0, lbl_805EDD98, &lbl_8062050C, lbl_805F3428, 5, -1);
    fn_8032FAB0((char*)p + 0x344, lbl_805EDDA4, &lbl_8062050C, lbl_805F3428, 5, -1);
    fn_8032FAB0((char*)p + 0x3A8, lbl_805EDDB0, &lbl_80620520, lbl_805F343C, 3, -1);
    fn_80330ACC(p, (MItem*)((char*)p + 0x2E0));
    fn_80330ACC(p, (MItem*)((char*)p + 0x344));
    fn_80330ACC(p, (MItem*)((char*)p + 0x3A8));
    if (fn_80148404(lbl_8061B8C0) == 1) {
        fn_8032D880((char*)p + 0x2E0, lbl_805EDD98);
        fn_8032D880((char*)p + 0x344, lbl_805EDDA4);
    } else {
        fn_8032D880((char*)p + 0x2E0, lbl_805EDDBC);
        fn_8032D880((char*)p + 0x344, lbl_805EDDC8);
    }
    return p;
}

void fn_80331F0C(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
    UnkMgr8* m = lbl_8061B8C0->m8;
    if (fn_80148404(lbl_8061B8C0) == 1) {
        UnkC128* o = m->m6F8->m10;
        int a = o->m6C;
        int b = o->m70;
        fn_8032FB78((char*)p + 0x2E0, a);
        fn_8032FB78((char*)p + 0x344, b);
        fn_8032FB78((char*)p + 0x3A8, lbl_80691DD8);
    } else {
        UnkMgr8* m2 = lbl_8061B8C0->mC;
        int a = m->m6F8->m10->m70;
        int b = m2->m6F8->m10->m70;
        fn_8032FB78((char*)p + 0x2E0, a);
        fn_8032FB78((char*)p + 0x344, b);
    }
}

void fn_80332008(Menu* p)
{
    UnkMgr8* m = lbl_8061B8C0->m8;
    if (fn_80148404(lbl_8061B8C0) == 1) {
        int a = EnumVal2(EAt2(p, 0x2E0));
        int b = EnumVal2(EAt2(p, 0x344));
        fn_80086EC0(m->m6F8->m10, 0, a);
        fn_80086EC0(m->m6F8->m10, 1, b);
        lbl_80691DD8 = EnumVal2(EAt2(p, 0x3A8));
    } else {
        UnkMgr8* m2 = lbl_8061B8C0->mC;
        int a = EnumVal2(EAt2(p, 0x2E0));
        int b = EnumVal2(EAt2(p, 0x344));
        fn_80086EC0(m->m6F8->m10, 0, -1);
        fn_80086EC0(m->m6F8->m10, 1, a);
        fn_80086EC0(m2->m6F8->m10, 0, -1);
        fn_80086EC0(m2->m6F8->m10, 1, b);
        fn_801A23B8(m2, 0);
    }
    fn_801A23B8(m, 1);
    fn_801A6820(m);
}

/* near-miss: loop entry. Retail enters the do-while at the call (skipping the r3/r4 moves,
 * p and k are still in r3/r4) and keeps p in r30, k in r27; mine re-does the moves and
 * allocates callee-saved registers differently. Tried do/while/for/goto shapes. */
void fn_80332154(Menu* p, int k)
{
    MIE2* e0 = EAt2(p, 0x2E0);
    MIE2* e1 = EAt2(p, 0x344);
    int v0 = EnumVal2(e0);
    int v1 = EnumVal2(e1);
    int i = 0;
    do {
        fn_80330BC8(p, k);
        if (fn_80332318(p, EnumVal2(e0), EnumVal2(e1)) != 0)
            goto done;
        i++;
    } while (i <= 4);
    fn_8032FB78(e0, v0);
    fn_8032FB78(e1, v1);
done:
    UnkMgr8* m = lbl_8061B8C0->m8;
    if (fn_80148404(lbl_8061B8C0) == 1) {
        int a = EnumVal2(EAt2(p, 0x2E0));
        int b = EnumVal2(EAt2(p, 0x344));
        fn_80086EC0(m->m6F8->m10, 0, a);
        fn_80086EC0(m->m6F8->m10, 1, b);
    } else {
        UnkMgr8* m2 = lbl_8061B8C0->mC;
        int a = EnumVal2(EAt2(p, 0x2E0));
        int b = EnumVal2(EAt2(p, 0x344));
        fn_80086EC0(m->m6F8->m10, 0, -1);
        fn_80086EC0(m->m6F8->m10, 1, a);
        fn_80086EC0(m2->m6F8->m10, 0, -1);
        fn_80086EC0(m2->m6F8->m10, 1, b);
    }
}

void fn_803322F8(Menu* p) { fn_80330F98(p); }

int fn_80332318(void* self, int a, int b)
{
    int ok = 1;
    if (a == b && b != -1) {
        ok = 0;
    } else if ((fn_802D7CE0(a, 1) == 0 && a != -1) || (fn_802D7CE0(b, 1) == 0 && b != -1)) {
        ok = 0;
    }
    return ok;
}

void fn_80332398(MenuL* p)
{
    for (int i = 0; i < p->m4C0; i++) {
        MenuListEnt* b = p->e;
        int off = i * 0x18;
        MItem* it = *(MItem**)((char*)b + off);
        if (it)
            delete it;
        *(MItem**)((char*)b + off) = 0;
    }
    p->m4C0 = 0;
    p->m178 = 0;
}

void fn_80332428(MenuL* p, int c)
{
    p->m2DC = lbl_80666278;
    fn_80332398(p);
    fn_80330870(p, c);
}

void fn_80332470(MenuL* p)
{
    char buf[0x18];
    fn_80332398(p);
    if (p->m4C0 == 0) {
        for (int i = 0; i <= 0x13; i++)
            fn_804089B4(buf, lbl_805EDDD4, i);
    }
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
}

void fn_80332520(MenuL* p, int k)
{
    if (k == 12) {
        int i = p->m174;
        if (i >= 0) {
            if (i <= 0x13)
                fn_8040B6A0(p->e[i].m4);
        }
    }
    fn_80330BC8(p, k);
}

void fn_80332584(MenuL* p)
{
    for (int i = 0; i < p->m4C0; i++) {
        MenuListEnt* b = p->e;
        int off = i * 0x18;
        MItem* it = *(MItem**)((char*)b + off);
        if (it)
            delete it;
        *(MItem**)((char*)b + off) = 0;
    }
    p->m4C0 = 0;
    p->m178 = 0;
}

void fn_80332614(MenuL* p, int c)
{
    p->m2DC = lbl_80666228;
    fn_80332584(p);
    fn_80330870(p, c);
}

void fn_8033265C(MenuL* p)
{
    char buf[0x18];
    fn_80332584(p);
    if (p->m4C0 == 0) {
        for (int i = 0; i <= 0x13; i++)
            fn_804089B4(buf, lbl_805EDDD4, i);
    }
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
}

void fn_8033270C(MenuL* p, int k)
{
    if (k == 12) {
        int i = p->m174;
        if (i >= 0) {
            if (i <= 0x13)
                fn_8040B6A0(p->e[i].m4);
        }
    }
    fn_80330BC8(p, k);
}

void fn_80332770(Menu* p, int k) { fn_80330BC8(p, k); }

void fn_80332790(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
}

void fn_80332808() {}

/* near-miss: 8 slots differ, only the register numbers of the lis'd global addresses
 * (r4..r11 permuted). Searched ~1500 store orders; the float stores must keep source order
 * 45.0, 25.0, 90.0 (pool order). */
void fn_8033280C(int on)
{
    UnkC128* c = lbl_8061B8C0->m8->m6F8->m10;
    lbl_806203BC = 45.0f;
    lbl_806203C0 = 25.0f;
    lbl_806203C4 = 90.0f;
    lbl_8068B4BC = on ^ 1;
    lbl_8061CB80 = on;
    lbl_8061D3AC = on;
    lbl_80691CA8 = on;
    lbl_8061FE94 = on;
    if (on == 1)
        c->m128 = on;
    else
        c->m128 = 0;
}

void fn_80332898()
{
    lbl_8061EDCC = lbl_8061EDCC ^ 1;
    if (lbl_8061EDCC) {
        lbl_8061B8C0->m24 = 0;
        fn_802D7ACC();
    } else {
        lbl_8061B8C0->m24 = 1;
        fn_802D7ADC();
    }
    int on = lbl_8061EDCC;
    int off = on ^ 1;
    lbl_8061F830 = off;
    lbl_8061FE94 = on;
    lbl_8068B4BC = off;
    lbl_8061C900 = off;
    lbl_8061B894 = off;
    fn_80331568();
}

void fn_80332930() { fn_8033280C(1); }

void fn_80332954() { fn_8033280C(0); }

/* near-miss (parked, 150 vs 152 instructions): the three inline button-item ctors are right in
 * shape (vptr EC0, floats m0/m4, vptr E70, mC, name, vptr DD0, callback), but retail keeps one
 * more callee-saved register live (r15..r30: the callback address of the first button is
 * hoisted into r29) and so allocates every item pointer one register lower. */
Menu* fn_80332978(Menu* p, int a)
{
    MenuInit(p, a);
    p->m2DC = lbl_80666138;
    fn_8032F120((char*)p + 0x2E0, lbl_805EDE40, 0);
    ItemB* bA = (ItemB*)((char*)p + 0x334);
    bA->m8 = lbl_80666EC0;
    bA->m0 = 0.0f;
    bA->m4 = 0.0f;
    bA->m8 = lbl_80666E70;
    bA->mC = 0;
    fn_8032D868(bA, lbl_805EDE5C);
    bA->m8 = lbl_80666DD0;
    fn_8033FBD8(bA, (void*)fn_80332930);
    ItemB* bB = (ItemB*)((char*)p + 0x380);
    bB->m8 = lbl_80666EC0;
    bB->m0 = 0.0f;
    bB->m4 = 0.0f;
    bB->m8 = lbl_80666E70;
    bB->mC = 0;
    fn_8032D868(bB, lbl_805EDE78);
    bB->m8 = lbl_80666DD0;
    fn_8033FBD8(bB, (void*)fn_80332954);
    fn_8032F120((char*)p + 0x3CC, lbl_805EDE94, 0);
    fn_8032F428((char*)p + 0x420, lbl_805EDEAC, lbl_80620530, 4, 0);
    fn_8032F120((char*)p + 0x480, lbl_805EDEC4, 0);
    ItemB* bC = (ItemB*)((char*)p + 0x4D4);
    bC->m8 = lbl_80666EC0;
    bC->m0 = 0.0f;
    bC->m4 = 0.0f;
    bC->m8 = lbl_80666E70;
    bC->mC = 0;
    fn_8032D868(bC, lbl_805EDEDC);
    bC->m48 = (char*)p + 0x520;
    bC->m8 = lbl_80666E20;
    fn_80333848((char*)p + 0x520, p);
    fn_8032F120((char*)p + 0x9F4, lbl_805EDEF0, 0);
    fn_8032F120((char*)p + 0xA48, lbl_805EDF08, 0);
    fn_80330ACC(p, (MItem*)((char*)p + 0x2E0));
    fn_80330ACC(p, (MItem*)bA);
    fn_80330ACC(p, (MItem*)bB);
    fn_80330ACC(p, (MItem*)((char*)p + 0x3CC));
    fn_80330ACC(p, (MItem*)((char*)p + 0x420));
    fn_80330ACC(p, (MItem*)((char*)p + 0x480));
    fn_80330ACC(p, (MItem*)bC);
    fn_80330ACC(p, (MItem*)((char*)p + 0x9F4));
    fn_80330ACC(p, (MItem*)((char*)p + 0xA48));
    p->m174 = 0;
    return p;
}

void fn_80332BD8(Menu* p, int k)
{
    fn_80330BC8(p, k);
    lbl_8061D3A0 = GetV(IAt(p, 0x2E0));
    lbl_8068CD0C = IAt(p, 0x420)->m4C;
    lbl_8068B5D0 = GetV(IAt(p, 0x3CC));
    lbl_80691DE0 = GetV(IAt(p, 0x9F4));
    lbl_80691DE4 = GetV(IAt(p, 0xA48));
}

void fn_80332CA0(Menu* p)
{
    SetV(IAt(p, 0x2E0), lbl_8061D3A0);
    SetV(IAt(p, 0x3CC), lbl_8068B5D0);
    fn_8032F574((MItem*)IAt(p, 0x420), lbl_8068CD0C);
    SetV(IAt(p, 0x9F4), lbl_80691DE0);
    SetV(IAt(p, 0xA48), lbl_80691DE4);
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
}

void fn_80332DB8() {}

void fn_80333184(Menu* p, int k)
{
    fn_80330BC8(p, k);
    lbl_806164F8 = GetV(IAt(p, 0X2E0));
    lbl_806177DC = IAt(p, 0x334)->m4C;
    lbl_80616EE0 = GetV(IAt(p, 0X394));
    lbl_80687608.v = GetV(IAt(p, 0X3E8));
    lbl_8068760C.v = GetV(IAt(p, 0X43C));
    lbl_806177E0 = GetV(IAt(p, 0X490));
    lbl_806177E4 = GetV(IAt(p, 0X4E4));
    lbl_806177E8 = GetV(IAt(p, 0X538));
    lbl_80687620.v = GetV(IAt(p, 0X58C));
    lbl_80687610.v = GetV(IAt(p, 0X5E0));
    lbl_80687614.v = GetV(IAt(p, 0X634));
    lbl_80687618.v = GetV(IAt(p, 0X688));
    lbl_806177EC = GetV(IAt(p, 0X6DC));
    lbl_8068761C.v = GetV(IAt(p, 0X730));
    lbl_80687624.v = GetV(IAt(p, 0X784));
    lbl_8061651C = GetV(IAt(p, 0X7D8));
    lbl_80616EE4 = GetV(IAt(p, 0X82C));
    lbl_80616EE8 = GetV(IAt(p, 0X880));
    lbl_80620540 = GetVF2(IAt(p, 0x8D4));
    lbl_80620544 = GetVF2(IAt(p, 0x938));
    lbl_80620548 = GetV2(IAt(p, 0x99C));
}

void fn_8033348C(Menu* p)
{
    SetV(IAt(p, 0X2E0), lbl_806164F8);
    SetV(IAt(p, 0X3E8), lbl_80687608.v);
    SetV(IAt(p, 0X394), lbl_80616EE0);
    SetV(IAt(p, 0X43C), lbl_8068760C.v);
    SetV(IAt(p, 0X490), lbl_806177E0);
    SetV(IAt(p, 0X4E4), lbl_806177E4);
    SetV(IAt(p, 0X538), lbl_806177E8);
    SetV(IAt(p, 0X58C), lbl_80687620.v);
    SetV(IAt(p, 0X5E0), lbl_80687610.v);
    SetV(IAt(p, 0X634), lbl_80687614.v);
    SetV(IAt(p, 0X688), lbl_80687618.v);
    SetV(IAt(p, 0X6DC), lbl_806177EC);
    SetV(IAt(p, 0X730), lbl_8068761C.v);
    SetV(IAt(p, 0X784), lbl_80687624.v);
    SetV(IAt(p, 0X7D8), lbl_8061651C);
    SetV(IAt(p, 0X82C), lbl_80616EE4);
    SetV(IAt(p, 0X880), lbl_80616EE8);
    SetVF(IAt(p, 0x8D4), lbl_80620540);
    SetVF(IAt(p, 0x938), lbl_80620544);
    SetV(IAt(p, 0x99C), lbl_80620548);
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
}

void fn_803337EC()
{
    fn_8003A0B0(fn_80038EB4(), lbl_806177DC);
    fn_8003A130(fn_80038EB4());
    fn_8005C410(fn_8005BA9C(), 0, lbl_80620540);
    fn_8005C410(fn_8005BA9C(), 1, lbl_80620544);
}

void fn_803339D4(Menu* p, int k) { fn_80330BC8(p, k); }

void fn_803339F4(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
}

void fn_80333A6C() {}

void fn_80333BE8(Menu* p, int c)
{
    p->m2DC = lbl_80666048;
    for (int i = 0; i < 15; i++) {
        char* b = (char*)p + 0x418;
        int off = i * 4;
        MItem* it = *(MItem**)(b + off);
        if (it) {
            delete it;
            *(MItem**)(b + off) = 0;
        }
    }
    SetVp(p, 0x3D8, lbl_80666EC0);
    SetVp(p, 0x390, lbl_80666EC0);
    SetVp(p, 0x33C, lbl_80666EC0);
    SetVp(p, 0x2E8, lbl_80666EC0);
    fn_80330870(p, c);
}

void fn_80333C8C(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
    SetV(IAt(p, 0x2E0), lbl_8068CCB0.v);
    int v = fn_8023C1D8(lbl_8068CCA8);
    SetV(IAt(p, 0x334), v);
    fn_8032D868((char*)p + 0x388, lbl_80620564[lbl_8068CCB4]);
    fn_80333E28(p);
}

void fn_80333D78(Menu* p)
{
    lbl_8068CCB0.v = GetV(IAt(p, 0x2E0));
    fn_8023C1E0(lbl_8068CCA8, GetV(IAt(p, 0x334)));
    UnkMgr8* m = lbl_8061B8C0->m8;
    fn_80333E98(p);
    fn_801A4674(m);
}

void fn_80333E08(Menu* p, int k) { fn_80330BC8(p, k); }

void fn_80333E28(Menu* p)
{
    int i = 0;
    do {
        int v = fn_8023C6C4(lbl_8068CCA8, i);
        SetV(ItemAt(p, i), v);
        i++;
    } while (i <= 14);
}

void fn_80333E98(Menu* p)
{
    int i = 0;
    do {
        fn_8023C6F8(lbl_8068CCA8, i, GetV2(ItemAt(p, i)));
        i++;
    } while (i <= 14);
    UnkMgr8* m = lbl_8061B8C0->m8;
    fn_8017E264(m->m700);
    fn_8022E92C(m->m700->m3B0, 0);
    fn_8022E92C(m->m700->m3B0, 1);
}

void fn_80333F3C(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
}

void fn_80333FB4() {}

void fn_80333FB8(Menu* p, int k) { fn_80330BC8(p, k); }

void fn_8033421C(Menu* p, int c)
{
    p->m2DC = lbl_80666098;
    for (int i = 0; i < 15; i++) {
        char* b = (char*)p + 0x334;
        int off = i * 4;
        MItem* it = *(MItem**)(b + off);
        if (it) {
            delete it;
            *(MItem**)(b + off) = 0;
        }
        b = (char*)p + 0x370;
        it = *(MItem**)(b + off);
        if (it) {
            delete it;
            *(MItem**)(b + off) = 0;
        }
    }
    SetVp(p, 0x4AC, lbl_80666EC0);
    SetVp(p, 0x464, lbl_80666EC0);
    SetVp(p, 0x3FC, lbl_80666EC0);
    SetVp(p, 0x3B4, lbl_80666EC0);
    SetVp(p, 0x2E8, lbl_80666EC0);
    fn_80330870(p, c);
}

void fn_803342F8(Menu* p)
{
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
    SetV(IAt(p, 0x2E0), lbl_8068CC9C.v);
    fn_80334504(p);
}

void fn_8033439C(Menu* p)
{
    lbl_8068CC9C.v = GetV(IAt(p, 0x2E0));
    UnkMgr8* m = lbl_8061B8C0->m8;
    fn_80334604(p);
    fn_801A4674(m);
}

void fn_803343FC(Menu* p, int k)
{
    if (GetV2(ItemAtB(p, 0)) > 0) {
        for (int i = 0; i < 15; i++) {
            char* b = (char*)p + 0x370;
            int v = GetV2(ItemAtB(p, 0));
            int off = i * 4;
            SetV(*(MIV**)(b + off), v);
        }
    }
    if (GetV2(ItemAtA(p, 0)) > 0) {
        for (int i = 0; i < 15; i++) {
            char* b = (char*)p + 0x334;
            int v = GetV2(ItemAtA(p, 0));
            int off = i * 4;
            SetV(*(MIV**)(b + off), v);
        }
    }
    fn_80330BC8(p, k);
}

void fn_80334504(Menu* p)
{
    int i = 0;
    do {
        int v = fn_8023C3E0(lbl_8068CC18, i, 0);
        SetV(ItemAtA(p, i), v);
        v = fn_8023C3E0(lbl_8068CC18, i, 1);
        SetV(ItemAtB(p, i), v);
        i++;
    } while (i <= 14);
    UnkMgr8* m = lbl_8061B8C0->m8;
    SetV(IAt(p, 0x3F4), m->m6F8->m14->m114);
    SetV(IAt(p, 0x4A4), m->m6F8->m14->mF78);
}

void fn_80334604(Menu* p)
{
    int i = 0;
    do {
        fn_8023C490(lbl_8068CC18, i, 0, GetV2(ItemAtA(p, i)));
        fn_8023C490(lbl_8068CC18, i, 1, GetV2(ItemAtB(p, i)));
        i++;
    } while (i <= 14);
    UnkMgr8* m = lbl_8061B8C0->m8;
    fn_8009DC48(m->m6F8->m14, GetV2(IAt(p, 0x3F4)));
    fn_8009DC48((char*)m->m6F8->m14 + 0xE64, GetV2(IAt(p, 0x4A4)));
    fn_8017E264(m->m700);
}

void fn_80334848(Menu* p, int c)
{
    p->m2DC = lbl_80665FF8;
    for (int i = 0; i < 0x59; i++) {
        char* b = (char*)p + 0x388;
        int off = i * 4;
        MItem* it = *(MItem**)(b + off);
        if (it)
            delete it;
    }
    SetVp(p, 0x330, lbl_80666EC0);
    SetVp(p, 0x2E8, lbl_80666EC0);
    fn_80330870(p, c);
}

void fn_803348DC(MenuV* p)
{
    int v = fn_80334B2C(p);
    fn_8032F574((MItem*)IAt(p, 0x328), v);
    fn_803349D0(p);
    p->m204 = 0;
    p->m208 = 0;
    p->items[p->m174]->s3();
    p->m174 = 0;
    p->items[p->m174]->s2();
}

void fn_8033496C(MenuV* p)
{
    fn_80334A60(p);
    fn_803349B8(p);
    fn_80087B10();
    fn_8017E264(lbl_8061B8C0->m8->m700);
}

UnkC128* fn_803349B8(Menu* p) { return lbl_8061B8C0->m8->m6F8->m10; }

void fn_803349D0(MenuV* p)
{
    int w = fn_80334AF0(p);
    UnkC128* o = fn_803349B8(p);
    fn_80087A50((Unk80084910_S*)o, p->m374);
    int i = 0;
    do {
        int v = fn_80087A88((Unk80087A58_O*)o, i, w, 1);
        SetV(ItemAt2(p, i), v);
        i++;
    } while (i <= 0x58);
}

/* near-miss: retail passes the value to fn_80087A58 without an extsb, but the repo's
 * definition of the callee (tu_80087A58.cpp) takes `char v`, so the caller narrows it
 * (1 extra instruction). Everything else matches. */
void fn_80334A60(MenuV* p)
{
    int w = fn_80334AF0(p);
    UnkC128* o = fn_803349B8(p);
    fn_80087A50((Unk80084910_S*)o, p->m374);
    int i = 0;
    do {
        fn_80087A58((Unk80087A58_O*)o, i, GetV2(ItemAt2(p, i)), w, 1);
        i++;
    } while (i <= 0x58);
}

}
