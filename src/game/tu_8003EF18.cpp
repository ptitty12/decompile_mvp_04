/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8003EF18-0x800401E4 only: every data object is extern by its lbl_ name.
 * Continues the Unk8003A5DC object of tu_80039B04.cpp (include/game/tu_80039B04.h).
 */
#include "game/tu_80039B04.h"
#include "game/tu_8003C9A0.h"
#include "game/tu_8003DF80.h"
#include "game/tu_8003EF18.h"

int fn_8025416C(void* p, int n);
Unk800475EC_Obj* fn_800475EC();
int fn_8003E844(Unk8003A5DC* self);
void* fn_8004072C();
int fn_800412AC(void* o, int a, int b, int c, int d, int e);
int fn_8003B478(Unk8003A5DC* self, int a);
int fn_8003B4B8(Unk8003A5DC* self, int a);
void fn_8003AEE4(Unk8003A5DC* self);
void fn_8003DCA0(Unk8003A5DC* self);
void fn_8003DCE0(Unk8003A5DC* self);
void* fn_8005BA9C();
int fn_8005C7E8(void* p, int a);
void fn_8005C75C(void* p, int a, int b);
int fn_8040ABA0();
void fn_8001B798(int a, int b);
void fn_8001B7F4(int a);
void fn_8001B848(int a, int b);
int fn_800473D4(int a);
int fn_8009E1D4(void* p, int a, int b);
void fn_8001B010(int a);
void fn_8001B0D0(int a, int b);
void fn_8001AE84();
void fn_8001AFA4(int a, int b, int c, int d);
int fn_8011B630(Unk8003FC18_Entry* e, int* out);
int fn_8011B604(Unk8003FC18_Entry* e, int* out);
int fn_8011B5D8(Unk8003FC18_Entry* e, int* out);
Unk8003DF80_Pl* fn_801A49F0(Unk8003A5DC_Ctx* c, int idx, int out);
int fn_80044820(int a);
int fn_80044828(int a);
void fn_8001B12C(int a, int b, int c);
void fn_8001B190(int a, int b, int c);
void fn_8001B1F4(int a, int b, int c);
void fn_8001B258();
void* fn_800B555C();
int fn_800B57EC(void* p);
void fn_800B5898(void* p);

void fn_8003EF18(Unk8003A5DC* self)
{
}

void fn_8003EF1C(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c && fn_8003E844(self)) {
        int bit = 1 << (fn_8040ABA0() % 10);
        fn_8001B798(bit, 1 << ((bit + fn_8040ABA0() % 9 + 1) % 10));
    }
}

void fn_8003F004(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c && fn_8003E844(self))
        fn_8001B7F4(1 << (fn_8040ABA0() % 10));
}

void fn_8003F094(Unk8003A5DC* self)
{
    if (fn_8003E844(self) != 0)
        fn_8003AEE4(self);
}

void fn_8003F0D0(Unk8003A5DC* self)
{
    if (fn_8003E844(self) != 0 && self->m1E0[6] == 0) {
        fn_8001B848(8, 1 << (fn_8040ABA0() % 10));
        self->m1E0[6] = 1;
    }
}

void fn_8003F14C(Unk8003A5DC* self, int a)
{
    if (fn_8003E844(self) != 0) {
        int bit = 1 << (fn_8040ABA0() % 10);
        fn_8001B848(fn_800473D4(a), bit);
    }
}

void fn_8003F1C0(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1 && fn_8003B4B8(self, 0x14) != 0)
        fn_800412AC(fn_8004072C(), 0x7c, 0, 0, 0, 0);
}

void fn_8003F250(Unk8003A5DC* self, unsigned int a)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if (a > 2 && fn_8003B478(self, 0x18) == 1)
                fn_800412AC(fn_8004072C(), 0x7b, 0, 0, 0, 0);
        } else {
            int done = 0;
            if (a <= 2 && fn_8003B478(self, 0x17) == 1) {
                done = 1;
                fn_800412AC(fn_8004072C(), 0x79, 0, 0, 0, 0);
            }
            if (done == 0 && a > 3 && fn_8003B478(self, 0x19) == 1)
                fn_800412AC(fn_8004072C(), 0x78, 0, 0, 0, 0);
        }
    }
}

void fn_8003F37C(Unk8003A5DC* self, int a)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if (a != 0 && fn_8003B478(self, 0x1b) == 1)
                fn_800412AC(fn_8004072C(), 0x7a, 0, 0, 0, 0);
        } else if ((unsigned int)a <= 1 && fn_8003B478(self, 0x1a) == 1) {
            fn_800412AC(fn_8004072C(), 0x77, 0, 0, 0, 0);
        }
    }
}

void fn_8003F460(Unk8003A5DC* self, unsigned int a)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1 && a > 9 && fn_8003B478(self, 0x29) == 1)
        fn_800412AC(fn_8004072C(), 0x6c, 0, 0, 0, 0);
}

void fn_8003F4FC(Unk8003A5DC* self, int a)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            switch (a) {
            case 28:
                if (fn_8003B478(self, 0x3d) == 1)
                    fn_800412AC(fn_8004072C(), 0x8c, 0, 0, 0, 0);
                break;
            case 29:
                if (fn_8003B478(self, 0x3c) == 1)
                    fn_800412AC(fn_8004072C(), 0x8b, 0, 0, 0, 0);
                break;
            case 30:
                if (fn_8003B478(self, 0x3b) == 1)
                    fn_800412AC(fn_8004072C(), 0x8a, 0, 0, 0, 0);
                break;
            }
        } else {
            switch (a) {
            case 28:
                if (fn_8003B478(self, 0x3a) == 1)
                    fn_800412AC(fn_8004072C(), 0x89, 0, 0, 0, 0);
                break;
            case 29:
                if (fn_8003B478(self, 0x39) == 1)
                    fn_800412AC(fn_8004072C(), 0x88, 0, 0, 0, 0);
                break;
            case 30:
                if (fn_8003B478(self, 0x38) == 1)
                    fn_800412AC(fn_8004072C(), 0x87, 0, 0, 0, 0);
                break;
            }
        }
    }
}

void fn_8003F698(Unk8003A5DC* self)
{
    if (self->m138 == 0)
        fn_8003D944(self, 0x10, 0x1e, 0, self->m130);
}

void fn_8003F6D4(Unk8003A5DC* self)
{
    fn_8003D944(self, 0x18, 0x78, self->m138, self->m130);
}

void fn_8003F704(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if (fn_8003B478(self, 0x42) == 1)
                fn_800412AC(fn_8004072C(), 0x91, 0, 0, 0, 0);
        } else if (fn_8003B478(self, 0x43) == 1) {
            fn_800412AC(fn_8004072C(), 0x92, 0, 0, 0, 0);
        }
    }
}

void fn_8003F7D4(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if (fn_8003B478(self, 0x45) == 1)
                fn_800412AC(fn_8004072C(), 0x94, 0, 0, 0, 0);
        } else if (fn_8003B478(self, 0x44) == 1) {
            fn_800412AC(fn_8004072C(), 0x93, 0, 0, 0, 0);
        }
    }
}

void fn_8003F8A4(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if (fn_8003B478(self, 0x46) == 1)
                fn_800412AC(fn_8004072C(), 0x95, 0, 0, 0, 0);
        } else if (fn_8003B478(self, 0x47) == 1) {
            fn_800412AC(fn_8004072C(), 0x96, 0, 0, 0, 0);
        }
    }
}

void fn_8003F974(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if (fn_8003B478(self, 0x48) == 1)
                fn_800412AC(fn_8004072C(), 0x97, 0, 0, 0, 0);
        } else if (fn_8003B478(self, 0x49) == 1) {
            fn_800412AC(fn_8004072C(), 0x98, 0, 0, 0, 0);
        }
    }
}

void fn_8003FA44(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if (fn_8003B478(self, 0x32) == 1)
                fn_800412AC(fn_8004072C(), 0x81, 0, 0, 0, 0);
        } else if (fn_8003B478(self, 0x33) == 1) {
            fn_800412AC(fn_8004072C(), 0x82, 0, 0, 0, 0);
        }
    }
}

void fn_8003FB14(Unk8003A5DC* self)
{
    if (self->m138 == 1 && fn_8003B478(self, 0) == 1)
        fn_800412AC(fn_8004072C(), 0x7e, 0, 0, 0, 0);
}

void fn_8003FB68(Unk8003A5DC* self)
{
    fn_8001B010(fn_8009E1D4((char*)self->m10C->m6F8->m14 + 0x8c, 2, 0));
}

void fn_8003FBA4(Unk8003A5DC* self)
{
    fn_8003D944(self, 5, 0x3c, self->m138, self->m130);
}

void fn_8003FBD4(Unk8003A5DC* self)
{
    if (fn_8005C7E8(fn_8005BA9C(), 1) == 1)
        fn_8005C75C(fn_8005BA9C(), 1, 0x4b0);
    fn_8001AE84();
}

/* near-miss (fn_8003FC18, FD7C, FEA0, FFC4): this inline reproduces retail's
 * bdnz byte-sum loops (unsigned counter, index cast to unsigned char); the
 * rest differs only in scheduling (retail loads m10C into r8 first, here r5)
 * and register numbers. Tried: Sum(ctx, idx), no local ctx, pointer local,
 * unsigned char counter (compiled to an andi. 128 test), != 0x80. */
inline unsigned int Unk8003FC18_Sum(Unk8003FC18_Entry* e)
{
    unsigned int acc = 0;
    unsigned int i;
    for (i = 0; i < 0x80; i++)
        acc += e->m1B4[(unsigned char)i];
    return acc;
}

void fn_8003FC18(Unk8003A5DC* self)
{
    Unk8003A5DC_Ctx* c = self->m10C;
    unsigned int s0 = Unk8003FC18_Sum((Unk8003FC18_Entry*)c->m6F8->m14);
    unsigned int s1 = Unk8003FC18_Sum((Unk8003FC18_Entry*)c->m6F8->m14 + 1);
    int a = s1 >= s0;
    int b = s1 < s0;
    Unk8003B2DC_Sub6F8* p = c->m6F8;
    int h1 = fn_8009E1D4(((Unk8003FC18_Entry*)p->m14 + a)->m8C, 2, 0);
    int h2 = fn_8009E1D4(((Unk8003FC18_Entry*)p->m14 + b)->m8C, 2, 0);
    unsigned int sa = Unk8003FC18_Sum((Unk8003FC18_Entry*)self->m10C->m6F8->m14 + a);
    unsigned int sb = Unk8003FC18_Sum((Unk8003FC18_Entry*)self->m10C->m6F8->m14 + b);
    fn_8001AFA4(h1, h2, sa, sb);
}

void fn_8003FD7C(Unk8003A5DC* self)
{
    Unk8003A5DC_Ctx* c = self->m10C;
    unsigned int s0 = Unk8003FC18_Sum((Unk8003FC18_Entry*)c->m6F8->m14);
    unsigned int s1 = Unk8003FC18_Sum((Unk8003FC18_Entry*)c->m6F8->m14 + 1);
    int idx = s1 < s0;
    int out = 0;
    if (fn_8011B630((Unk8003FC18_Entry*)c->m6F8->m14 + idx, &out) != 0) {
        Unk8003DF80_Pl* pl = fn_801A49F0(self->m10C, idx, out);
        if (pl != 0) {
            int v = fn_8025416C((char*)pl + 0x588, 0);
            int flag = v > 0x4e1f;
            if (flag)
                v -= 0x4e20;
            fn_8001B12C(v, fn_80044820(pl->m708), fn_80044828(flag));
        }
    }
}

void fn_8003FEA0(Unk8003A5DC* self)
{
    Unk8003A5DC_Ctx* c = self->m10C;
    unsigned int s0 = Unk8003FC18_Sum((Unk8003FC18_Entry*)c->m6F8->m14);
    unsigned int s1 = Unk8003FC18_Sum((Unk8003FC18_Entry*)c->m6F8->m14 + 1);
    int idx = s1 >= s0;
    int out = 0;
    if (fn_8011B604((Unk8003FC18_Entry*)c->m6F8->m14 + idx, &out) != 0) {
        Unk8003DF80_Pl* pl = fn_801A49F0(self->m10C, idx, out);
        if (pl != 0) {
            int v = fn_8025416C((char*)pl + 0x588, 0);
            int flag = v > 0x4e1f;
            if (flag)
                v -= 0x4e20;
            fn_8001B190(v, fn_80044820(pl->m708), fn_80044828(flag));
        }
    }
}

void fn_8003FFC4(Unk8003A5DC* self)
{
    Unk8003A5DC_Ctx* c = self->m10C;
    unsigned int s0 = Unk8003FC18_Sum((Unk8003FC18_Entry*)c->m6F8->m14);
    unsigned int s1 = Unk8003FC18_Sum((Unk8003FC18_Entry*)c->m6F8->m14 + 1);
    int idx = s1 >= s0;
    int out = 0;
    if (fn_8011B5D8((Unk8003FC18_Entry*)c->m6F8->m14 + idx, &out) != 0) {
        Unk8003DF80_Pl* pl = fn_801A49F0(self->m10C, idx, out);
        if (pl != 0) {
            int v = fn_8025416C((char*)pl + 0x588, 0);
            int flag = v > 0x4e1f;
            if (flag)
                v -= 0x4e20;
            fn_8001B1F4(v, fn_80044820(pl->m708), fn_80044828(flag));
        }
    }
}

void fn_800400E8(Unk8003A5DC* self)
{
    fn_8001B258();
}

void fn_80040108(Unk8003A5DC* self)
{
    Unk8003B2DC_Sub6F8* p = self->m10C->m6F8;
    int r = fn_8009E1D4((char*)p->m14 + 0x8c, 2, 0);
    int n = p->m14->m1D50;
    if (n > 0)
        fn_8001B0D0(r, n);
}

void fn_8004015C(Unk8003A5DC* self)
{
    self->fn_vslot12();
    fn_8003DCA0(self);
    fn_8003DCE0(self);
}

int fn_800401AC(Unk8003A5DC* self)
{
    if (fn_800B57EC(fn_800B555C()) != 1)
        fn_800B5898(fn_800B555C());
    return 0;
}
