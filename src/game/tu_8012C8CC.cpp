/*
 * Game code, .text 0x8012C8CC-0x80130DFC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8012C8CC.h"

#include "game/tu_8001B190.h"

struct Unk8012CCF4_Obj {
    char pad0[0x14];
    int m14;
};

/* Front-end screen class (ctor fn_8012E7FC, vptr lbl_806554C8, base ctor fn_800EC648). */
struct Unk8012E7FC : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
    int m160;
    int m164;
    int m168;
    int m16C;
    void (*m170)();
    int m174;
    Unk8012CCF4_Obj* m178;
    int m17C;
    int m180;
    int m184;
    int m188;
    int m18C;
    int m190;
    int m194;
    int m198;
    int m19C;
};
typedef Unk8012E7FC Scr;
static inline int IsBusy(Scr* x)
{
    if (x->m188 != 0 || x->m18C != 0) {
        return 1;
    }
    return 0;
}

struct UnkFEState {
    char pad0[0x570];
    int m570;
};
struct Unk8061A32C {
    char padB8[0xB8];
    int mB8;
};
extern Unk8061A32C* lbl_8061A32C;
extern const char lbl_806554C8[];
extern const char lbl_805C0424[];
extern const char lbl_805C0438[];
extern const char lbl_805C0A08[];
extern const char lbl_805C0A14[];
Unk8001BC8C* fn_8001BC4C();

extern "C" {
UnkFEState* fn_800B555C();
Unk8061A32C* fn_800B64BC(void* p);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
Unk800C7B40_Widget* fn_800C8044(Unk800C7B40_Widget* p);
int fn_8012E3F4(Scr* x, int a);
void fn_8012E328(Scr* x, int a);
void fn_8012D180(Scr* x, Unk800C7B40_Widget* w, int v);
void fn_800ECAA4(void* x);
void fn_800ED254(void* x);
void* fn_800C33D0();
void fn_800C3BE0();
int fn_8011AA24(int a);
int fn_801A4A94(int a, int b);
void fn_800C3DCC(void* a, int b, int c);
void fn_800C3ED4(void* a, int b, int c);
}
extern "C" {
void* fn_800B8144();
void fn_800B83F8(void* p, int a, int b);
int fn_80127550(Scr* x, Unk800C7B40_Widget* w);
void fn_800DC0F4(int a, int b, int c);
void fn_800ECE34(void* x);
void fn_8012E9D4(void* x);
void fn_800C3AB4(void* p, int v);
}

extern const char lbl_805C08C0[];
extern const char lbl_805C08EC[];
extern const char lbl_805C08F8[];
extern const char lbl_805C0918[];

struct UnkI184 {
    char pad0[0x184];
    int m184;
};

extern "C" int fn_8012C8CC(Scr* x, int a)
{
    if (!IsBusy(x) && x->m13C != 0 && x->m164 != 0 && x->m168 != 0 && fn_8012E3F4(x, a) != 0) {
        x->fn_vslot84(0, 0);
    }
    return 0;
}

extern "C" int fn_8012C978(Scr* x, int a)
{
    if (!IsBusy(x) && x->m13C != 0 && x->m164 != 0 && x->m168 != 0 && fn_8012E3F4(x, a) != 0) {
        x->fn_vslot84(1, 0);
    }
    return 0;
}

extern "C" int fn_8012CA24(Scr* x, int a)
{
    if (x->m134 != 0 && fn_8012E3F4(x, a) != 0) {
        fn_8001BC4C()->fn_8001BDAC(0xA0);
        x->fn_vslot8(0);
        x->fn_vslot16(0);
        fn_8012E328(x, 0);
        if (x->m170 != 0) {
            x->m170();
        }
        return 1;
    }
    return 0;
}

extern "C" Unk800C7B40_Widget* fn_8012CC20(Scr* x)
{
    Unk800C7B40_Widget* r = 0;
    int k = x->fn_vslot85();
    if (k != 2) {
        if (k == 0) {
            if (x->fn_vslot86() != 0) {
                r = fn_800C8044(x->fn_vslot32(lbl_805C0424, 1));
            }
        } else {
            if (x->fn_vslot87() != 0) {
                r = fn_800C8044(x->fn_vslot32(lbl_805C0438, 1));
            }
        }
    }
    return r;
}

extern "C" void fn_8012CCF4(Scr* x, int which)
{
    int sub = 0;
    int v = 5;
    if (x->m178 != 0) {
        sub = x->m178->m14;
        Unk800C7B40_Widget* w;
        if (which == 0) {
            w = fn_800C8044(x->fn_vslot32(lbl_805C0424, 1));
        } else {
            w = fn_800C8044(x->fn_vslot32(lbl_805C0438, 1));
        }
        v = fn_80127550(x, w);
    }
    fn_800DC0F4(sub, v, which == 0 ? x->m164 : x->m168);
}

extern "C" void fn_8012D0D0(Scr* x)
{
    if (x->m164 != 0) {
        fn_8012D180(x, fn_800C8044(x->fn_vslot32(lbl_805C0424, 1)), x->m164);
    }
    if (x->m168 != 0) {
        fn_8012D180(x, fn_800C8044(x->fn_vslot32(lbl_805C0438, 1)), x->m168);
    }
}

extern "C" int fn_8012DEE4(UnkI184* p) { return p->m184; }

extern "C" int fn_8012DEEC() { return 0; }

extern "C" void fn_8012DEF4(Scr* x, int which, int v)
{
    if (which == 0) {
        x->fn_vslot32(lbl_805C08C0, 1)->fn_vslot8(v);
        int* p = &x->m190;
        *(int*)((char*)p + which) = v;
    } else if (which == 1) {
        x->fn_vslot32(lbl_805C08EC, 1)->fn_vslot8(v);
        x->m194 = v;
    }
}

extern "C" void fn_8012DFC0(Scr* x, int which, int v)
{
    if (which == 0) {
        x->fn_vslot29(lbl_805C08F8)->fn_vslot8(v);
    } else if (which == 1) {
        x->fn_vslot29(lbl_805C0918)->fn_vslot8(v);
    }
}

extern "C" void fn_8012E328(Scr* x, int a)
{
    if (a != 0) {
        fn_800B83F8(fn_800B8144(), 1, 1);
    } else if (x->m140 == 0) {
        if (!x->b0 || (!x->fn_vslot32(lbl_805C0424, 1)->b0 && !x->fn_vslot32(lbl_805C0438, 1)->b0)) {
            fn_800B83F8(fn_800B8144(), 0, 0);
        }
    }
}

extern "C" int fn_8012E3F4(Scr* x, int a)
{
    int t = x->m198;
    if (t == -99) {
        int s = fn_800B555C()->m570;
        return a == s || s == -1;
    }
    return t == -1 || a == t;
}

extern "C" void fn_8012E45C(Scr* x, int v, int which)
{
    if (which == 0) {
        x->m188 = v;
    } else if (which == 1) {
        x->m18C = v;
    }
}

extern "C" void fn_8012E47C(int a, int b)
{
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    }
    if (lbl_8061A32C->mB8 != 0) {
        int c = fn_801A4A94(fn_8011AA24(0), b);
        fn_800C3DCC(fn_800C33D0(), a, c);
    } else {
        fn_800C3ED4(fn_800C33D0(), a, b);
    }
}

extern "C" int fn_8012E7F4() { return 0; }

/* near-miss: 46/46 insns; the constant stores are scheduled in a different order (retail keeps 0x184,0x188,0x190,0x19C,0x198 first, then the zeros in field order; here the -1/5/1 stores migrate up). Source order is retail order. */
extern "C" Scr* fn_8012E7FC(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806554C8);
    self->m184 = 5;
    self->m188 = 2;
    self->m190 = 0;
    self->m19C = -1;
    self->m198 = 1;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = -1;
    self->m154 = -1;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m174 = 0;
    self->m17C = 0;
    self->m180 = 5;
    self->m18C = 0;
    self->m194 = 1;
    return self;
}

extern "C" void fn_8012E8B4(Scr* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" void fn_8012E8DC(Scr* x)
{
    fn_800ECE34(x);
    fn_8012E9D4(x);
    fn_800C3AB4(fn_800C33D0(), 9);
    x->fn_vslot8(1);
    x->fn_vslot16(1);
    x->fn_vslot32(lbl_805C0A08, 1)->fn_vslot8(0);
    x->fn_vslot32(lbl_805C0A14, 1)->fn_vslot8(0);
}

extern "C" void fn_8013011C(Scr* x)
{
    fn_800ECAA4(x);
}

extern "C" int fn_8013080C(Scr* x, Unk800C7B40_Widget* a)
{
    if (a == fn_800C8044(x->fn_vslot32(lbl_805C0A08, 1))) {
        return x->m180;
    }
    return a == fn_800C8044(x->fn_vslot32(lbl_805C0A14, 1)) ? x->m184 : 0;
}
