/*
 * Game code, .text 0x8011A518-0x8011C5E8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk800C7B40_Widget Wid;

/* Per-player stats holder: +0x44C the game object, +0x588 an embedded stat table. */
struct UnkPlr {
    char pad0[0x44C];
    UnkGame* m44C;
    char pad450[0x138];
    char m588[1];
};
extern const float lbl_805BFD30;
extern const float lbl_805BFD34;
extern const float lbl_805BFD38;


// PROTOS-BEGIN
extern "C" {
void fn_8011A518(UnkGame* g, Wid* w, const char* name);
void fn_8011A5A0(UnkPlr* a, Wid* w, const char* name);
void fn_8011A6D8(UnkPlr* a, Wid* w, const char* name);
void fn_8011A728(UnkPlr* a, Wid* w, const char* name);
void fn_8011A7F4(UnkPlr* a, int unused, Wid* w, const char* name);
void fn_8011A838(UnkPlr* a, int unused, Wid* w, const char* name);
void fn_8011A87C(UnkPlr* a, int unused, Wid* w, const char* name);
void fn_8011A974(UnkPlr* a, Wid* w, const char* name);
void fn_8011A9B8(const char* s, Wid* w, const char* name);
UnkGame* fn_8011AA24(int i);
int fn_8011AA4C();
UnkGameP10* fn_8011AC90(int idx);
int fn_8011AD00(int mode, int idx);
void fn_8011AD88(int mode, int idx, int c);
int fn_8011AE28(int mode, int idx);
void fn_8011AEB0(int mode, int idx, int c);
void fn_8011B5A4();
int fn_8011B5D8(void* a, int* b);
int fn_8011B604(void* a, int* b);
int fn_8011B630(void* a, int* b);
int fn_8011B6F8(int a, UnkPlr* p);
int fn_8011B784(int a, UnkPlr* p, int c);
float fn_8011B81C(int a, UnkPlr* p, int c);
int fn_8011B8C8(int a, UnkPlr* p);
float fn_8011B954(int a, UnkPlr* p);
int fn_8011B9F4(int a, UnkPlr* p);
float fn_8011BA88(int a, UnkPlr* p);
int fn_8011BB30(void* a, int b);
int fn_8011BB54(void* a, int b);
int fn_8011BD0C(void* a, int b);
int fn_8011BD3C(UnkGame* g, int b);
void* fn_8011BFAC(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
}
// PROTOS-END
extern "C" {
void* fn_800DBAE0(void* p, int a, int b, int c);
void fn_8011A0A4(int v, Wid* w, const char* name);
int fn_8011B8C8(int a, UnkPlr* p);
int fn_8011B9F4(int a, UnkPlr* p);
float fn_8011BA88(int a, UnkPlr* p);
void fn_801B5AD0(int a, int b);
int fn_8011B65C(int a, void* b, int* c);
int fn_8011BB78(void* a, int b, int c);
int fn_8011BB54(void* a, int b);
int fn_8006BC74(void* a, int b);
int fn_8006A1B4(void* p);
void fn_80086EC0(int a, int b);
int fn_8011AA4C();
int fn_800B55A8(UnkFEState* s);
int fn_800B59DC(UnkFEState* s);
int fn_80253DB0(void* t, int a, int b);
int fn_80253F9C(void* t, int a);
int fn_80253F0C(void* t, int a, int b, int c);
int fn_802540E4(void* t, int a, int b);
float fn_80253F54(void* t, int a, int b, int c);
float fn_80254128(void* t, int a, int b);
int fn_80253DF4(void* t, int a, int b);
int fn_80253FDC(void* t, int a);
float fn_80253E38(void* t, int a, int b);
float fn_8025401C(void* t, int a);
int fn_80253E7C(void* t, int a, int b, int c);
int fn_8025405C(void* t, int a, int b);
float fn_80253EC4(void* t, int a, int b, int c);
float fn_802540A0(void* t, int a, int b);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
}

extern const char lbl_8065A918[];
extern "C" {

void fn_8011A518(UnkGame* g, Wid* w, const char* name)
{
    void* r = 0;
    if (fn_8011AA24(0) != 0 && fn_8011AA24(0)->m6F8 != 0)
        r = fn_8011AA24(0)->m6F8->m14;
    fn_8011A0A4((int)fn_800DBAE0(r, 0xD, g->m708, g->m704), w, name);
}

void fn_8011A5A0(UnkPlr* a, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B8C8(0, a), w, name);
}

void fn_8011A6D8(UnkPlr* a, Wid* w, const char* name)
{
    fn_8011A0A4((int)fn_8011BA88(0, a), w, name);
}

void fn_8011A728(UnkPlr* a, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B9F4(2, a), w, name);
}

void fn_8011A7F4(UnkPlr* a, int unused, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B8C8(3, a), w, name);
}

void fn_8011A838(UnkPlr* a, int unused, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B8C8(4, a), w, name);
}

void fn_8011A87C(UnkPlr* a, int unused, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B8C8(7, a), w, name);
}

void fn_8011A974(UnkPlr* a, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B9F4(0, a), w, name);
}

void fn_8011A9B8(const char* s, Wid* w, const char* name)
{
    fn_800C8040(w->fn_vslot32(name, 1))->fn_vslot30(s);
}

/* near-miss: the index register of the lwzx is r0 here, r11 in retail. */

UnkGame* fn_8011AA24(int i)
{
    UnkGameTbl* t = lbl_8061B8C0;
    UnkGame* r;
    if ((unsigned)i <= 2)
        r = t->m8[i];
    else
        r = 0;
    return r;
}

int fn_8011AA4C()
{
    return lbl_806192E0->m4->m10->m74;
}

UnkGameP10* fn_8011AC90(int idx)
{
    UnkGame* g = 0;
    switch (fn_8011AA4C()) {
    case 1:
    case 2:
        g = fn_8011AA24(idx);
        break;
    case 3:
    case 5:
    case 6:
        g = fn_8011AA24(0);
        break;
    }
    return g->m6F8->m10;
}

int fn_8011AD00(int mode, int idx)
{
    UnkGameP10* o = fn_8011AC90(idx);
    switch (mode) {
    case 1:
        return o->m70;
    case 2:
        return o->m6C;
    case 3:
    case 5:
    case 6:
        switch (idx) {
        case 0:
            return o->m6C;
        case 1:
            return o->m70;
        }
        break;
    }
    return -1;
}

void fn_8011AD88(int mode, int idx, int c)
{
    fn_8011AC90(idx);
    switch (mode) {
    case 1:
        fn_80086EC0(1, c);
        break;
    case 2:
        break;
    case 3:
    case 5:
    case 6:
        switch (idx) {
        case 0:
            fn_80086EC0(0, c);
            break;
        case 1:
            fn_80086EC0(1, c);
            break;
        }
        break;
    }
}

int fn_8011AE28(int mode, int idx)
{
    UnkGameP10* o = fn_8011AC90(idx);
    switch (mode) {
    case 1:
        return o->m18;
    case 2:
        return o->m14;
    case 3:
    case 5:
    case 6:
        switch (idx) {
        case 0:
            return o->m14;
        case 1:
            return o->m18;
        }
        break;
    }
    return 1;
}

void fn_8011AEB0(int mode, int idx, int c)
{
    UnkGameP10* o = fn_8011AC90(idx);
    switch (mode) {
    case 2:
        o->m14 = c;
        break;
    case 1:
        o->m18 = c;
        break;
    case 3:
    case 5:
    case 6:
        switch (idx) {
        case 0:
            o->m14 = c;
            break;
        case 1:
            o->m18 = c;
            break;
        }
        break;
    }
}

void fn_8011B5A4()
{
    fn_801B5AD0(fn_8011AA24(0)->m700->m3C4, 2);
}

int fn_8011B5D8(void* a, int* b)
{
    return fn_8011B65C(7, a, b);
}

int fn_8011B604(void* a, int* b)
{
    return fn_8011B65C(3, a, b);
}

int fn_8011B630(void* a, int* b)
{
    return fn_8011B65C(4, a, b);
}

int fn_8011B6F8(int a, UnkPlr* p)
{
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        return fn_80253DB0(&p->m588, a, 1);
    return fn_80253F9C(&p->m588, a);
}

int fn_8011B784(int a, UnkPlr* p, int c)
{
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        return fn_80253F0C(&p->m588, a, c, 1);
    return fn_802540E4(&p->m588, a, c);
}

float fn_8011B81C(int a, UnkPlr* p, int c)
{
    float r = lbl_805BFD30;
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        r = fn_80253F54(&p->m588, a, c, 1);
    else
        r = fn_80254128(&p->m588, a, c);
    return r;
}

int fn_8011B8C8(int a, UnkPlr* p)
{
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        return fn_80253DF4(&p->m588, a, 1);
    return fn_80253FDC(&p->m588, a);
}

float fn_8011B954(int a, UnkPlr* p)
{
    float r = lbl_805BFD34;
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        r = fn_80253E38(&p->m588, a, 1);
    else
        r = fn_8025401C(&p->m588, a);
    return r;
}

int fn_8011B9F4(int a, UnkPlr* p)
{
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        return fn_80253E7C(&p->m588, a, 2, 1);
    return fn_8025405C(&p->m588, a, 2);
}

float fn_8011BA88(int a, UnkPlr* p)
{
    float r = lbl_805BFD38;
    void* x = p->m44C->m6F8;
    int y = fn_800B55A8(fn_800B555C());
    int z = fn_8006A1B4(x);
    int w = fn_800B59DC(fn_800B555C());
    if (z != 0 || y != 0 || w != 0)
        r = fn_80253EC4(&p->m588, a, 2, 1);
    else
        r = fn_802540A0(&p->m588, a, 2);
    return r;
}

int fn_8011BB30(void* a, int b)
{
    return fn_8011BB78(a, b, 1);
}

int fn_8011BB54(void* a, int b)
{
    return fn_8011BB78(a, b, 0);
}

int fn_8011BD0C(void* a, int b)
{
    if (fn_8011BB54(a, b) <= 0)
        return 0;
    return 1;
}

int fn_8011BD3C(UnkGame* g, int b)
{
    int r = 0;
    if (fn_8011BB30(g, b) > 0) {
        if (fn_8006BC74(g->m6F8, b) != 0)
            r = 1;
    }
    return r;
}

void* fn_8011BFAC(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8065A918);
    self->m134 = 0;
    return self;
}

}
