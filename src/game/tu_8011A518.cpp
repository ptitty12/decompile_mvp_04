/*
 * Game code, .text 0x8011A518-0x8011C5E8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk800C7B40_Widget Wid;


// PROTOS-BEGIN
extern "C" {
void fn_8011A518(UnkGame* g, Wid* w, const char* name);
void fn_8011A5A0(int a, Wid* w, const char* name);
void fn_8011A6D8(int a, Wid* w, const char* name);
void fn_8011A728(int a, Wid* w, const char* name);
void fn_8011A7F4(int a, int unused, Wid* w, const char* name);
void fn_8011A838(int a, int unused, Wid* w, const char* name);
void fn_8011A87C(int a, int unused, Wid* w, const char* name);
void fn_8011A974(int a, Wid* w, const char* name);
void fn_8011A9B8(const char* s, Wid* w, const char* name);
UnkGame* fn_8011AA24(int i);
int fn_8011AA4C();
void fn_8011B5A4();
int fn_8011B5D8(void* a, int* b);
int fn_8011B604(void* a, int* b);
int fn_8011B630(void* a, int* b);
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
int fn_8011B8C8(int a, int b);
int fn_8011B9F4(int a, int b);
float fn_8011BA88(int a, int b);
void fn_801B5AD0(int a, int b);
int fn_8011B65C(int a, void* b, int* c);
int fn_8011BB78(void* a, int b, int c);
int fn_8011BB54(void* a, int b);
int fn_8006BC74(void* a, int b);
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

void fn_8011A5A0(int a, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B8C8(0, a), w, name);
}

void fn_8011A6D8(int a, Wid* w, const char* name)
{
    fn_8011A0A4((int)fn_8011BA88(0, a), w, name);
}

void fn_8011A728(int a, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B9F4(2, a), w, name);
}

void fn_8011A7F4(int a, int unused, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B8C8(3, a), w, name);
}

void fn_8011A838(int a, int unused, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B8C8(4, a), w, name);
}

void fn_8011A87C(int a, int unused, Wid* w, const char* name)
{
    fn_8011A0A4(fn_8011B8C8(7, a), w, name);
}

void fn_8011A974(int a, Wid* w, const char* name)
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
