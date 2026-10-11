/*
 * Game code, .text 0x801164AC-0x8011A518 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk80114A20_Scr Scr;
typedef Unk800C7B40_Widget Wid;


extern const char lbl_805BA6D8[];
extern const char lbl_805BFB3C[];
extern const char lbl_805BFB4C[];
extern const char lbl_805BE1B0[];
int fn_801A71D0();
int* fn_800ED2B0(void* container, const char* name);
extern const float lbl_805BFB38;
Unk8001BC8C* fn_8001BC4C();
extern const char lbl_805BC1A8[];
extern const char lbl_805BFCC4[];
extern const char lbl_805BFCCC[];
extern const float lbl_805BFCD4;
extern const float lbl_805BFCD8;
extern char lbl_805B9A30;
extern const char lbl_805BADC8[];
extern const char lbl_8064E8D8[];
extern const char lbl_8064E630[];

// PROTOS-BEGIN
extern "C" {
int fn_80116A64(Scr* self, int b);
void fn_80117634(Scr* self);
void fn_80117764(Scr* self);
void fn_801177E8(Scr* self, int a);
int fn_80117838();
void fn_80117840(Scr* self);
void fn_80117844(Scr* self);
void fn_801178D8(Scr* self);
void fn_80117984(Scr* self, int b);
void fn_80117B04(int a, Scr* b);
void fn_80117B60(int a, Scr* b);
void* fn_80117D20(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80117D70(Unk80117D20_Scr* self);
void fn_80117EA0(Unk80117D20_Scr* self, Wid* w, int v);
void* fn_80117FDC(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_801181EC(Scr* self);
void fn_80119F48(char* buf, float v);
void fn_8011A0A4(int v, Unk800C7B40_Widget* w, const char* name);
void fn_8011A14C(int a, Unk800C7B40_Widget* w, const char* name, int flag);
void fn_8011A1D4(UnkGame* g, int a, Unk800C7B40_Widget* w, const char* name);
void fn_8011A268(char* base, Unk800C7B40_Widget* w, const char* name);
void fn_8011A2AC(int a, Unk800C7B40_Widget* w, const char* name);
void fn_8011A3CC(int a, Unk800C7B40_Widget* w, const char* name);
void fn_8011A414(int a, Unk800C7B40_Widget* w, const char* name);
void fn_8011A468(int a, Unk800C7B40_Widget* w, const char* name);
}
// PROTOS-END
extern "C" {
void fn_800ED310(Scr* self);
void fn_800ECAA4(Scr* self);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
int fn_8011AD00(int a);
void fn_800ECF18(void* self);
void fn_80116100(Scr* self);
void fn_80116268(Scr* self);
void fn_801164AC(Scr* self);
void fn_801167AC(Scr* self);
void fn_80117BBC(Scr* self);
void fn_80117C8C(Scr* self);
void fn_80117634(Scr* self);
int fn_804089B4(char* buf, const char* fmt, ...);
int fn_8040B320(void* p, int c, int n, ...);
int fn_8011B784(int a, int b, int c);
float fn_8011B81C(int a, int b, int c);
void fn_8011A0A4(int v, Unk800C7B40_Widget* w, const char* name);
void fn_80119F48(char* buf, float v);
int fn_8025416C(char* p, int a);
int fn_80097288(int a, int b);
const char* fn_800E5E4C(int a);
void fn_800DE274(UnkTextArg* p, int a, int b);
void fn_80131F34(Unk800C7B40_Widget* w, void* self, void (*cb)(int, void*), int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
}

extern "C" {

int fn_80116A64(Scr* self, int b)
{
    if (b <= 1) {
        if (b >= 0) {
            if (fn_8011AD00(self->m180) != -1)
                return 1;
        }
    }
    return 0;
}

void fn_80117634(Scr* self)
{
    Unk8001BC8C* g = fn_8001BC4C();
    float t0 = (float)self->m188;
    g->fn_8001C05C(3, t0 * lbl_805BFB38, 1);
    float t1 = (float)self->m18C;
    g->fn_8001C05C(1, t1 * lbl_805BFB38, 1);
    float t2 = (float)self->m190;
    g->fn_8001C05C(4, t2 * lbl_805BFB38, 1);
    float t3 = (float)self->m194;
    g->fn_8001C05C(2, t3 * lbl_805BFB38, 1);
}

void fn_80117764(Scr* self)
{
    UnkGame* g = fn_8011AA24(0);
    int v = g->m6F8->m10->m124;
    fn_802D61AC(fn_801A4CE8(g, 1), v, 0);
    if (self->m1A4 != 0) {
        g = fn_8011AA24(1);
        v = g->m6F8->m10->m124;
        fn_802D61AC(fn_801A4CE8(g, 1), v, 0);
    }
}

void fn_801177E8(Scr* self, int a)
{
    fn_800ED310(self);
    self->m198->fn_vslot14(a);
}

int fn_80117838()
{
    return 0;
}

void fn_80117840(Scr* self)
{
}

void fn_80117844(Scr* self)
{
    switch (self->m184) {
    case 0:
        fn_80116100(self);
        fn_80117840(self);
        break;
    case 1:
        fn_80116268(self);
        fn_80117840(self);
        break;
    case 2:
        fn_801164AC(self);
        break;
    case 3:
        fn_801167AC(self);
        fn_80117840(self);
        break;
    }
}

void fn_801178D8(Scr* self)
{
    Unk800C7B40_Widget* w = (Unk800C7B40_Widget*)self->m1BC[0];
    w->fn_vslot16(0);
    w = (Unk800C7B40_Widget*)self->m1BC[0];
    w->fn_vslot8(0);
    self->m1BC[0] = 0;
    self->fn_vslot16(1);
    self->m19C->fn_vslot16(1);
}

void fn_80117984(Scr* self, int b)
{
    if (self->m1BC[0] == 0 || (fn_801178D8(self), self->m1BC[0] == 0)) {
        if (lbl_8061A32C == 0)
            lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
        Unk800C7B40_Widget* w = fn_800B7AB8(lbl_8061A32C, lbl_805BA6D8);
        self->m1BC[0] = (int)w;
        *(int*)((char*)w + 0x2F0) = -0x63;
    }
    self->fn_vslot16(0);
    self->m19C->fn_vslot16(0);
    if (b != 0)
        fn_80131F34((Unk800C7B40_Widget*)self->m1BC[0], self, fn_80117B04, 0, 0x5CDB, 2, -1, 1, 0x26DF, 0x26DE, 0, 0, 0, 0);
    else
        fn_80131F34((Unk800C7B40_Widget*)self->m1BC[0], self, fn_80117B60, 0, 0x5CDB, 2, -1, 1, 0x26DF, 0x26DE, b, b, b, b);
    ((Unk800C7B40_Widget*)self->m1BC[0])->fn_vslot86();
}

void fn_80117B04(int a, Scr* b)
{
    if (a) {
        if (a == 1) {
            lbl_806192E0->m4->mC->m600 = a;
            fn_80117BBC(b);
        }
    }
    fn_801178D8(b);
}

void fn_80117B60(int a, Scr* b)
{
    if (a) {
        if (a == 1) {
            lbl_806192E0->m4->mC->m600 = a;
            fn_80117C8C(b);
        }
    }
    fn_801178D8(b);
}

void* fn_80117D20(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8064E8D8);
    self->m134 = 0;
    return self;
}

void fn_80117D70(Unk80117D20_Scr* self)
{
    fn_800ECF18(self);
    UnkGame* g = fn_8011AA24(0);
    UnkGameP6F8* p = g->m6F8;
    int n = fn_801A71D0() != 0 ? 3 : 4;
    int idx = n;
    if (n > 2) {
        int t = 0;
        if (g->m6F8->m14->m1CD0 != 0)
            t = 1;
        idx = t;
        if (n != 3)
            idx ^= 1;
    }
    UnkPlayerRec* rec = &p->m14->rec[idx];
    const char* name;
    if (idx == 0)
        name = lbl_805BFB3C;
    else
        name = lbl_805BFB4C;
    UnkSub* s = (UnkSub*)((char*)fn_800C8054(self->fn_vslot29(name)) + 0x98);
    s->fn_vslot20(rec->m198, 0);
    for (Wid* c = ((UnkGroupW*)self)->m40; c != 0; c = (Wid*)c->m8)
        fn_80117EA0(self, c, rec->m198);
    self->m134 = (int)fn_800ED2B0(self, lbl_805BE1B0);
}

void fn_80117EA0(Unk80117D20_Scr* self, Wid* w, int v)
{
    int t = w->m1C;
    if (t == 9) {
        if (v != 0) {
            UnkSub* s = (UnkSub*)((char*)fn_800C8054(w) + 0x98);
            s->fn_vslot20(v, 0);
        }
    } else if (t == 3 || t == 8) {
        for (Wid* c = ((UnkGroupW*)w)->m40; c != 0; c = (Wid*)c->m8)
            fn_80117EA0(self, c, v);
    }
}

void* fn_80117FDC(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8064E630);
    return self;
}

void fn_801181EC(Scr* self)
{
    fn_800ECAA4(self);
}

void fn_80119F48(char* buf, float v)
{
    int m = (int)((v + lbl_805BFCD4) * lbl_805BFCD8);
    m = m % 1000;
    if ((int)v > 0)
        fn_804089B4(buf, lbl_805BFCC4);
    else
        fn_804089B4(buf, lbl_805BFCCC, m);
}

void fn_8011A0A4(int v, Unk800C7B40_Widget* w, const char* name)
{
    char buf[40];
    buf[0] = lbl_805B9A30;
    fn_8040B320(buf + 1, 0, 0x27);
    fn_804089B4(buf, lbl_805BC1A8, v);
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot30(buf);
}

void fn_8011A14C(int a, Unk800C7B40_Widget* w, const char* name, int flag)
{
    UnkTextArg arg;
    int c = 0;
    if (flag != 0)
        c = 1;
    fn_800DE274(&arg, a, c);
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot28(&arg);
}

void fn_8011A1D4(UnkGame* g, int a, Unk800C7B40_Widget* w, const char* name)
{
    int t = fn_80097288(a, g->m704);
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot30(fn_800E5E4C(t));
}

void fn_8011A268(char* base, Unk800C7B40_Widget* w, const char* name)
{
    fn_8011A0A4(fn_8025416C(base + 0x588, 4), w, name);
}

void fn_8011A2AC(int a, Unk800C7B40_Widget* w, const char* name)
{
    fn_8011A0A4(fn_8011B784(0, a, 2), w, name);
}

void fn_8011A3CC(int a, Unk800C7B40_Widget* w, const char* name)
{
    fn_8011A0A4(fn_8011B784(1, a, 2), w, name);
}

void fn_8011A414(int a, Unk800C7B40_Widget* w, const char* name)
{
    fn_8011A0A4((int)fn_8011B81C(0, a, 2), w, name);
}

void fn_8011A468(int a, Unk800C7B40_Widget* w, const char* name)
{
    char buf[40];
    buf[0] = lbl_805B9A30;
    fn_8040B320(buf + 1, 0, 0x27);
    float f = fn_8011B81C(3, a, 2);
    fn_80119F48(buf, f);
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot30(buf);
}

}
