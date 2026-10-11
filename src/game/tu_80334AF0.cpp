/*
 * Game code, .text 0x80334AF0-0x80338ECC (debug-menu classes: pitch/catch/camera
 * options; original file and TU boundaries unknown, placeholder). Every data
 * object is extern by its lbl_ name.
 */
#include "game/tu_80331C60.h"

extern "C" {
void fn_8032FB78(void* item, int v);
void fn_80330BC8(Menu* p, int k);
void fn_8032F120(void* item, const char* name, int v);
void fn_803349D0(Menu* p);
void fn_80334A60(Menu* p);
UnkC128* fn_803349B8(Menu* p);
}

/* Enum item: m4C is the chosen index, m60 the value table. */
struct MIE { char pad0[0x4C]; int m4C; char pad50[0x10]; int* m60; };
inline int EnumVal(MIE* i) { return i->m60[i->m4C]; }
inline MIE* EAt(Menu* p, int off) { return (MIE*)((char*)p + off); }

extern const char lbl_80666778[];
extern int lbl_8061D030, lbl_8061D034, lbl_8061D038, lbl_8061D03C;
extern int lbl_8061D3F8, lbl_8061D3FC, lbl_8061D400, lbl_8061D404, lbl_8061D408, lbl_8061D40C;
extern int lbl_8061D410, lbl_8061D414, lbl_8061D418, lbl_8061D41C;
extern int lbl_80620830, lbl_8062083C;
extern int lbl_806E2A50[], lbl_806E3864[];
extern unsigned lbl_80620804;
struct V2F { float x; float y; };
extern V2F lbl_80691BEC;
struct UnkObj65C { char pad0[0x60]; float m60; char pad64[4]; float m68; };
struct UnkMgr65C { char pad0[0x65C]; UnkObj65C* m65C[13]; };
struct UnkGm2 { char pad0[8]; UnkMgr65C* m8; };

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

void fn_803357B4() {}

void fn_8033635C() {}

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

void fn_80337488()
{
    lbl_80620830 = 0;
    lbl_8062083C = 0;
}

int fn_80337830(int i) { return lbl_806E2A50[i]; }

int fn_80337844(int i) { return lbl_806E3864[i]; }

}
