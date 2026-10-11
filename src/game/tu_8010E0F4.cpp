/*
 * Game code, .text 0x8010E0F4-0x8011243C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk8010E0F4_Scr Scr;
inline void Init(char* n, const char* s)
{
    fn_8035682C(n);
    fn_8040B830(n, s, 0xF);
    n[15] = 0;
}
struct UnkName {
    char s[16];
    UnkName(const char* x)
    {
        fn_8035682C(this);
        fn_8040B830(this, x, 0xF);
        s[15] = 0;
    }
};

struct Unk80687CB8 {
    Unk800C7B40_Widget* m0;
    int m4;
    Unk800C7B40_Widget* m8;
    int mC;
};
extern Unk80687CB8 lbl_80687CB8;
extern const char* lbl_8061B3E0[];
extern const char lbl_805BFA5C[];
extern const char lbl_805BFA70[];
extern const char lbl_806508D0[];
extern const char lbl_805BA760[];
extern const char lbl_805BC19C[];
extern const char lbl_805BAF40[];
extern const char lbl_805BE138[];
extern const char lbl_805BA6D8[];

Unk8001BC8C* fn_8001BC4C();

extern "C" {
void fn_8010F1E4(Scr* self);
void fn_8010D33C(Scr* self, int a);
void fn_8010EFD0(Scr* self, Unk800C7B40_Widget* w, int i);
void fn_8010A808(Scr* self);
void fn_8010B6B8(Scr* self);
void fn_8010BF88(Scr* self);
void fn_800EC648(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_801142C4(Scr* self);
void fn_8011415C(Scr* self);
void fn_800ED254(Scr* self);
void fn_8010F9CC(Scr* self, int a);
void fn_8012E1C4(Unk800C7B40_Widget* w, int a, int b);
void fn_8010FFD8(int a, Scr* b);
void fn_80131F34(Unk800C7B40_Widget* w, Scr* self, void (*cb)(int, Scr*), int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
}

// PROTOS-BEGIN
extern "C" {
int fn_8010E0F4(Scr* self, Unk800C7B40_Widget* a);
int fn_8010E40C(Scr* self, Scr* a, int b, int c);
void fn_8010E4BC(Scr* self);
int fn_8010E4FC(Scr* self, int a);
int fn_8010E5FC(Scr* self, int a);
int fn_8010E69C(Scr* self, int a);
int fn_8010E79C(Scr* self, int a);
int fn_8010E83C(Scr* self, int a);
int fn_8010E8F0(Scr* self, int a);
int fn_8010E998(Scr* self, int a);
int fn_8010EA4C(Scr* self, int a);
void fn_8010EF84(Scr* self);
void fn_8010F290(Scr* self);
void fn_8010F494(Scr* self, int a);
int fn_8010F4D4(int a, int b);
void fn_8010F550(Scr* self);
void* fn_8010FBB0(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
int fn_8010FE70(Scr* self, int a);
void fn_8010FFD8(int a, Scr* b);
void fn_80110088(Scr* self);
void fn_80110A7C(Scr* self);
int fn_80110AB0(Scr* self, int a);
int fn_80110B0C(Scr* self, int a);
int fn_80110B68(Scr* self, int a);
int fn_80110BC4(Scr* self, int a);
int fn_80110C20(Scr* self, int a);
int fn_80110C7C(Scr* self, int a);
int fn_80110CD8(Scr* self, int a);
int fn_80110D34(Scr* self, int a);
Unk800C7B40_Widget* fn_80110D90(Scr* self, int a);
}
// PROTOS-END

extern "C" {

int fn_8010E0F4(Scr* self, Unk800C7B40_Widget* a)
{
    if (a == self->fn_vslot29(lbl_805BFA5C) || a == self->fn_vslot29(lbl_805BFA70)) {
        fn_8010F1E4(self);
        fn_8010D33C(self, 0);
        return 1;
    }
    return 0;
}

int fn_8010E40C(Scr* self, Scr* a, int b, int c)
{
    int r = 0;
    if ((a == (Scr*)self->m148 && (self->m140 == 0 || self->m140 == 2)) || (a == (Scr*)self->m14C && self->m140 == 1)) {
        a->fn_vslot68(c);
        self->fn_vslot44(fn_800B555C()->m570);
        r = 1;
    }
    return r;
}

void fn_8010E4BC(Scr* self)
{
    int f = 0;
    if (self->m13C != 0 && self->m13C->b0)
        f = 1;
    fn_8010D33C(self, f);
}

int fn_8010E4FC(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        switch (self->m140) {
        case 0:
        case 2:
            self->m148->fn_vslot50();
            fn_8010F9CC(self, self->m16C[self->m148->fn_vslot60()]);
            break;
        case 1:
            self->m14C->fn_vslot50();
            fn_8010F9CC(self, self->m1D0[self->m14C->fn_vslot60()]);
            break;
        }
    }
    return 1;
}

int fn_8010E5FC(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        switch (self->m140) {
        case 0:
        case 2:
            self->m148->fn_vslot51();
            break;
        case 1:
            self->m14C->fn_vslot51();
            break;
        }
    }
    return 1;
}

int fn_8010E69C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        switch (self->m140) {
        case 0:
        case 2:
            self->m148->fn_vslot52();
            fn_8010F9CC(self, self->m16C[self->m148->fn_vslot60()]);
            break;
        case 1:
            self->m14C->fn_vslot52();
            fn_8010F9CC(self, self->m1D0[self->m14C->fn_vslot60()]);
            break;
        }
    }
    return 1;
}

int fn_8010E79C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        switch (self->m140) {
        case 0:
        case 2:
            self->m148->fn_vslot53();
            break;
        case 1:
            self->m14C->fn_vslot53();
            break;
        }
    }
    return 1;
}

int fn_8010E83C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        fn_800C805C(fn_800C8044(self->fn_vslot32(lbl_805BA760, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot38(1);
        fn_8010F1E4(self);
    }
    return 1;
}

int fn_8010E8F0(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        fn_800C805C(fn_800C8044(self->fn_vslot32(lbl_805BA760, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot39();
    return 1;
}

int fn_8010E998(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        fn_800C805C(fn_800C8044(self->fn_vslot32(lbl_805BA760, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot40(1);
        fn_8010F1E4(self);
    }
    return 1;
}

int fn_8010EA4C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        fn_800C805C(fn_800C8044(self->fn_vslot32(lbl_805BA760, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot41();
    return 1;
}

void fn_8010EF84(Scr* self)
{
    fn_8010EFD0(self, lbl_80687CB8.m0, 0);
    fn_8010EFD0(self, lbl_80687CB8.m8, 1);
}

void fn_8010F290(Scr* self)
{
    fn_8010A808(self);
    fn_8010B6B8(self);
    fn_8010BF88(self);
}

void fn_8010F494(Scr* self, int a)
{
    if (self->m234 != 0)
        fn_8001BC4C()->fn_8001BDAC(a);
}

/* near-miss: the case 6/7 tails and the compare chain order differ from retail (switch layout). */
int fn_8010F4D4(int a, int b)
{
    switch (b) {
    case 0:
        return 0x2441;
    case 1:
    case 4:
    case 5:
        return 0x3A65;
    case 2:
    case 3:
        return 0xC82;
    case 6:
        return a == 1 ? 0x3A65 : 0xC82;
    case 7:
        return a == 1 ? 0xC82 : 0x3A65;
    }
    return 0x3A65;
}

void fn_8010F550(Scr* self)
{
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    Unk800C7B40_Widget* w = fn_800B7AB8(lbl_8061A32C, lbl_805BAF40);
    fn_8012E1C4(w, 0, fn_8010F4D4(0, self->m144));
    fn_8012E1C4(w, 1, fn_8010F4D4(1, self->m144));
}

/* near-miss: retail stores m158 first and m168 last; the scheduler hoists m168 here (tried all positions of those two). */
void* fn_8010FBB0(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806508D0);
    self->m16C[0] = 0;
    self->m130 = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m158 = 1;
    return self;
}

/* near-miss: 2 slots; retail loads the fn_8040B830 arguments as lis r4, li r5, addi r4, mr r3 (name pointer last). */
int fn_8010FE70(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        int v = self->m168;
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
            fn_80131F34(w, self, fn_8010FFD8, 0, 0x3364, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
            w->fn_vslot86();
        }
    }
    return 1;
}

/* near-miss: same argument-order difference as fn_8010FE70 (name pointer copied last in retail). */
void fn_8010FFD8(int a, Scr* b)
{
    if (a == 1) {
        fn_80110088(b);
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

void fn_80110088(Scr* self)
{
    fn_801142C4(self);
    if (self->m134 == 3)
        fn_8011415C(self);
}

void fn_80110A7C(Scr* self)
{
    fn_800ED254(self);
    fn_801142C4(self);
}

int fn_80110AB0(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot50();
    return 1;
}

int fn_80110B0C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot51();
    return 1;
}

int fn_80110B68(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot52();
    return 1;
}

int fn_80110BC4(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot53();
    return 1;
}

int fn_80110C20(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot54();
    return 1;
}

int fn_80110C7C(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot55();
    return 1;
}

int fn_80110CD8(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot56();
    return 1;
}

int fn_80110D34(Scr* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m150->fn_vslot57();
    return 1;
}

Unk800C7B40_Widget* fn_80110D90(Scr* self, int a)
{
    return fn_800C8060(self->fn_vslot32(lbl_8061B3E0[a], 1));
}

}
