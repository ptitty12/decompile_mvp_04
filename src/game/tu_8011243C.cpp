/*
 * Game code, .text 0x8011243C-0x801164AC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk8010E0F4_Scr UnkScrA;
typedef Unk80114A20_Scr Scr;

extern const char lbl_805BE138[];
extern const char lbl_805BA6D8[];
extern const char lbl_805BADC8[];

// PROTOS-BEGIN
extern "C" {
void fn_801142C4();
void fn_80114318(UnkScrA* self, int a);
void fn_80114528(UnkScrA* self);
void fn_8011452C(UnkScrA* self);
void fn_801145C0(UnkScrA* self);
void fn_80114664(UnkScrA* self, int b);
void fn_801147E4(int a, UnkScrA* b);
void fn_80114840(int a, UnkScrA* b);
void fn_80114A00(UnkScrA* self);
int fn_80114D14(Scr* self, int a);
void fn_80114E7C(int a, Scr* b);
void fn_80114F2C(Scr* self);
void fn_8011566C(Scr* self);
int fn_801156A0(Scr* self, int a);
int fn_801156FC(Scr* self, int a);
int fn_80115758(Scr* self, int a);
int fn_801157B4(Scr* self, int a);
int fn_80115810(Scr* self, int a);
int fn_8011586C(Scr* self, int a);
int fn_801158C8(Scr* self, int a);
int fn_80115924(Scr* self, int a);
}
// PROTOS-END
extern "C" {
void fn_800ED310(UnkScrA* self);
void fn_800ECAA4(UnkScrA* self);
void fn_800ED254(Scr* self);
void fn_8011489C(UnkScrA* self);
void fn_8011496C(UnkScrA* self);
void fn_80110F7C(UnkScrA* self);
void fn_801114CC(UnkScrA* self);
void fn_80111E50(UnkScrA* self);
void fn_801120EC(UnkScrA* self);
void fn_80117764(Scr* self);
void fn_80117634(Scr* self);
void fn_80131F34(Unk800C7B40_Widget* w, void* self, void (*cb)(int, void*), int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
}

extern "C" {

void fn_801142C4()
{
    int v = fn_8011AA24(0)->m6F8->m10->m124;
    fn_802D61AC(fn_801A4CE8(fn_8011AA24(0), 1), v, 0);
}

void fn_80114318(UnkScrA* self, int a)
{
    fn_800ED310(self);
    self->m150->fn_vslot14(a);
}

void fn_80114528(UnkScrA* self)
{
}

void fn_8011452C(UnkScrA* self)
{
    switch (self->m134) {
    case 0:
        fn_80110F7C(self);
        fn_80114528(self);
        break;
    case 1:
        fn_801114CC(self);
        fn_80114528(self);
        break;
    case 2:
        fn_80111E50(self);
        break;
    case 3:
        fn_801120EC(self);
        fn_80114528(self);
        break;
    }
}

void fn_801145C0(UnkScrA* self)
{
    Unk800C7B40_Widget* w = (Unk800C7B40_Widget*)self->m16C[0];
    w->fn_vslot16(0);
    w = (Unk800C7B40_Widget*)self->m16C[0];
    w->fn_vslot8(0);
    self->fn_vslot16(1);
    self->m154->fn_vslot16(1);
}

void fn_80114664(UnkScrA* self, int b)
{
    if (self->m16C[0] == 0 || (fn_801145C0(self), self->m16C[0] == 0)) {
        if (lbl_8061A32C == 0)
            lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
        Unk800C7B40_Widget* w = fn_800B7AB8(lbl_8061A32C, lbl_805BA6D8);
        self->m16C[0] = (int)w;
        *(int*)((char*)w + 0x2F0) = -0x63;
    }
    self->fn_vslot16(0);
    self->m154->fn_vslot16(0);
    if (b != 0)
        fn_80131F34((Unk800C7B40_Widget*)self->m16C[0], self, fn_801147E4, 0, 0x5CDB, 2, -1, 1, 0x26DF, 0x26DE, 0, 0, 0, 0);
    else
        fn_80131F34((Unk800C7B40_Widget*)self->m16C[0], self, fn_80114840, 0, 0x5CDB, 2, -1, 1, 0x26DF, 0x26DE, b, b, b, b);
    ((Unk800C7B40_Widget*)self->m16C[0])->fn_vslot86();
}

void fn_801147E4(int a, UnkScrA* b)
{
    if (a) {
        if (a == 1) {
            lbl_806192E0->m4->mC->m600 = a;
            fn_8011489C(b);
        }
    }
    fn_801145C0(b);
}

void fn_80114840(int a, UnkScrA* b)
{
    if (a) {
        if (a == 1) {
            lbl_806192E0->m4->mC->m600 = a;
            fn_8011496C(b);
        }
    }
    fn_801145C0(b);
}

void fn_80114A00(UnkScrA* self)
{
    fn_800ECAA4(self);
}

/* near-miss: clone of fn_8010FE70, same argument-order difference. */
int fn_80114D14(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        int v = self->m1B8;
        if (v == 0) {
            char name[16];
            char* np = name;
            fn_8035682C(np);
            fn_8040B830(np, lbl_805BE138, 0xF);
            np[15] = v;
            self->fn_vslot80(0);
            if (lbl_8061A32C == 0)
                lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
            fn_800B7B4C(lbl_8061A32C, np, self);
        } else {
            if (lbl_8061A32C == 0)
                lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
            Unk800C7B40_Widget* w = fn_800B7AB8(lbl_8061A32C, lbl_805BA6D8);
            *(int*)((char*)w + 0x2F0) = -0x63;
            fn_80131F34(w, self, fn_80114E7C, 0, 0x3364, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
            w->fn_vslot86();
        }
    }
    return 1;
}

/* near-miss: clone of fn_8010FFD8, same argument-order difference. */
void fn_80114E7C(int a, Scr* b)
{
    if (a == 1) {
        fn_80114F2C(b);
        char name[16];
        char* np = name;
        fn_8035682C(np);
        fn_8040B830(np, lbl_805BE138, 0xF);
        np[15] = 0;
        b->fn_vslot80(1);
        if (lbl_8061A32C == 0)
            lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
        fn_800B7B4C(lbl_8061A32C, np, b);
    }
}

void fn_80114F2C(Scr* self)
{
    fn_80117764(self);
    if (self->m184 == 3)
        fn_80117634(self);
}

void fn_8011566C(Scr* self)
{
    fn_800ED254(self);
    fn_80117764(self);
}

int fn_801156A0(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot50();
    return 1;
}

int fn_801156FC(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot51();
    return 1;
}

int fn_80115758(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot52();
    return 1;
}

int fn_801157B4(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot53();
    return 1;
}

int fn_80115810(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot54();
    return 1;
}

int fn_8011586C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot55();
    return 1;
}

int fn_801158C8(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot56();
    return 1;
}

int fn_80115924(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m198->fn_vslot57();
    return 1;
}

}
