/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8003DF80-0x8003EF18 only: every data object is extern by its lbl_ name.
 * Continues the Unk8003A5DC object of tu_80039B04.cpp (include/game/tu_80039B04.h).
 */
#include "game/tu_80039B04.h"
#include "game/tu_8003DF80.h"
#include "game/tu_8003C9A0.h"

extern float lbl_805A7634;

int fn_8025416C(void* p, int n);
Unk800475EC_Obj* fn_800475EC();
int fn_8003E844(Unk8003A5DC* self);
void* fn_8004072C();
int fn_800412AC(void* o, int a, int b, int c, int d, int e);
int fn_8003B478(Unk8003A5DC* self, int a);
int fn_8003B52C(Unk8003A5DC* self, int a);
void fn_8003B618(Unk8003A5DC* self);
void fn_8003B3F4(Unk8003A5DC* self);
void fn_8003DCA0(Unk8003A5DC* self);
void fn_8003DCE0(Unk8003A5DC* self);
void fn_8003DC00(Unk8003A5DC* self);
void fn_8003DE44(Unk8003A5DC* self, int a);
void fn_8003E180(Unk8003A5DC* self, int p);
void fn_8003E494(Unk8003A5DC* self, int p);
/* near-miss: 117/147 slots. Retail keeps a dead compare chain
 * (m184 != 0, 2, 4, 9, 0xB, 0xE, 0x10, 0x12, 6, all branching to the same
 * point) before the switch, which compiles away here in every form tried
 * (empty body, dead store, local copy), and its switch tree has an extra
 * case 7 that falls to the default. */
void fn_8003E53C(Unk8003A5DC* self, int a);
void fn_800401AC(Unk8003A5DC* self);
void fn_8003FBA4(Unk8003A5DC* self);
void* fn_8005BA9C();
int fn_8005C7E8(void* p, int a);
void fn_8005C75C(void* p, int a, int b);
void fn_8001AA84(int a, int b);
void fn_8001AAE0(int a, int b, int c);
void fn_8001AB44(int a, int b, int c);
void fn_8001ABA8(int a);
void fn_8001ABFC(int a);
void fn_8001ADA0(int a);
void fn_8001AC50(int a);
void fn_8001ACA4(int a);
void fn_8001ACF8(int a);
void fn_8001AD4C(int a);
void fn_8001AA24(int a, int b);
void fn_8001B62C();
void fn_8001B5E4();
void fn_8001B59C();
void fn_8001B420();
void fn_8001B2F0();
void fn_8001B4B8();
void fn_8001B3D4();
void fn_8001B550();
void fn_8001B33C();
void fn_8001B46C();
void fn_8001B504();
void fn_8001B388();
int fn_8040ABA0();

void fn_8003DF80(Unk8003A5DC* self, Unk8003DF80_Pl* p)
{
    if (self->m184 == -1 && self->m194 == 1 && p != 0) {
        int v = p->m704;
        int i;
        for (i = 0; i < 5; i++) {
            if (v == self->m1B8[i] || v == self->m1CC[i]) {
                self->m184 = 6;
                self->m190 = fn_8025416C((char*)p + 0x588, 0);
            }
        }
    }
}

void fn_8003E01C(Unk8003A5DC* self)
{
    if (self->m184 == -1 && self->m138 == 0) {
        fn_8003DF80(self, (Unk8003DF80_Pl*)self->m130);
        fn_8003DE44(self, 0);
    }
}

void fn_8003E070(Unk8003A5DC* self, int a)
{
    if (self->m184 == -1 && self->m138 == 1 && a != 0) {
        fn_8003DF80(self, (Unk8003DF80_Pl*)a);
        fn_8003DE44(self, 0);
    }
}

void fn_8003E0C8(Unk8003A5DC* self)
{
    if (self->m184 == -1 && (self->m160 == 1 || self->m140 == 1 || self->m144 == 1)) {
        fn_8003DF80(self, (Unk8003DF80_Pl*)self->m130);
        fn_8003DE44(self, 1);
    }
}

void fn_8003E138(Unk8003A5DC* self)
{
    if (self->m184 == -1) {
        fn_8003E180(self, self->m130);
        fn_8003E494(self, self->m130);
    }
}

void fn_8003E180(Unk8003A5DC* self, int p)
{
    if (self->m184 == -1 && p != 0 && fn_8025416C((void*)(p + 0x588), 0x16) == 4 && fn_8003B52C(self, 8) == 1)
        self->m184 = 8;
}

void fn_8003E1EC(Unk8003A5DC* self)
{
    if (self->m184 == -1 && (self->m160 == 1 || self->m140 == 1 || self->m144 == 1)) {
        if (self->m11C == 1) {
            int x;
            if (fn_8003B52C(self, 9) == 1) {
                x = 9;
                goto set;
            }
            if (fn_8003B52C(self, 10) == 1) {
                x = 10;
                goto set;
            }
            if (fn_8003B52C(self, 11) == 1) {
                x = 11;
                goto set;
            }
            if (fn_8003B52C(self, 12) == 1) {
                x = 12;
            set:
                self->m184 = x;
            }
        }
        if (self->m184 == -1) {
            if (self->m11C == 0x1a && fn_8003B52C(self, 0xd) == 1)
                self->m184 = 0xd;
            if (self->m184 == -1 && self->m11C != 0x1a && self->m11C != 0xd) {
                int r;
                if (fn_8003B52C(self, 0) == 1) {
                    self->m184 = 0;
                    return;
                }
                r = fn_8003B52C(self, 1);
                if (r == 1)
                    self->m184 = r;
            }
        }
    }
}

void fn_8003E34C(Unk8003A5DC* self, int a, int b)
{
    int t = self->m184;
    if (t == -1 && ((b == 1 && self->m13C == 0 && self->m140 == 0 && self->m144 == 0) || (a == 3 && self->m160 == 0)) && self->m184 == -1) {
        if (self->m120 == 0x11 && (self->m11C == 1 || self->m11C == 0xf || self->m11C == 0x10 || self->m11C == 0x12 || self->m11C == 0x13)) {
            int x;
            if (fn_8003B52C(self, 0x10) == 1) {
                x = 0x10;
                goto set;
            }
            if (fn_8003B52C(self, 0x11) == 1) {
                x = 0x11;
            set:
                self->m184 = x;
            }
        }
        if (self->m184 == -1 && self->m120 == 0xf) {
            int u = self->m11C;
            if (u == 0x13) {
                if (fn_8003B52C(self, 0x12) == 1) {
                    self->m184 = 0x12;
                    return;
                }
                if (fn_8003B52C(self, 0x13) == 1)
                    self->m184 = u;
            }
        }
    }
}

void fn_8003E494(Unk8003A5DC* self, int p)
{
    if (self->m184 == -1 && self->m120 == 0x1a && self->m11C == 0x1d && p != 0) {
        int v = fn_8025416C((void*)(p + 0x588), 0);
        if (v == 0x1b6) {
            int x;
            if (fn_8003B52C(self, 0xe) == 1) {
                x = 0xe;
                goto set;
            }
            if (fn_8003B52C(self, 0xf) == 1) {
                x = 0xf;
            set:
                self->m184 = x;
                self->m190 = v;
            }
        }
    }
}

void fn_8003E53C(Unk8003A5DC* self, int a)
{
    int ok = 0;
    if (self->m184 != -1) {
        Unk800475EC_Obj* o = fn_800475EC();
        int c = 0;
        if (o->mF4 == 1)
            c = o->mC00 >= 0;
        if (c == 1 && ((unsigned int)self->m18C <= 1 || self->m184 == 0xd || a == 1)) {
            ok = 1;
            if (self->m184 != 0 && self->m184 != 2 && self->m184 != 4 && self->m184 != 9 && self->m184 != 0xb && self->m184 != 0xe && self->m184 != 0x10 && self->m184 != 0x12 && self->m184 != 6) {
            }
            fn_800401AC(self);
            fn_8004072C();
            switch (self->m184) {
            case 0:
            case 1:
                fn_8001AA84(self->m11C, 2);
                break;
            case 2:
            case 3:
                fn_8001AAE0(self->m190, 1, 2);
                break;
            case 4:
            case 5:
                fn_8001AB44(self->m190, 1, 2);
                break;
            case 6:
                fn_8001ABA8(2);
                break;
            case 8:
                fn_8001ABFC(2);
                break;
            case 9:
            case 10:
            case 11:
            case 12:
                fn_8001ADA0(2);
                break;
            case 13:
                fn_8001AC50(2);
                break;
            case 14:
            case 15:
                fn_8001ACA4(2);
                break;
            case 16:
            case 17:
                fn_8001ACF8(2);
                break;
            case 18:
            case 19:
                fn_8001AD4C(2);
                break;
            default:
                ok = 0;
                break;
            }
        }
    }
    self->m190 = -1;
    if (ok == 1)
        fn_8003DC00(self);
}

void fn_8003E788(Unk8003A5DC* self)
{
    self->m194 = 0;
}

void fn_8003E794(Unk8003A5DC* self)
{
    fn_8003E53C(self, 0);
}

void fn_8003E7B8(Unk8003A5DC* self)
{
    fn_8003DCA0(self);
    fn_8003DCE0(self);
    fn_8003B618(self);
}

void fn_8003E7F4(Unk8003A5DC* self)
{
    int v = self->m11C;
    if (v != 0x1a) {
        if (v != 0xd) {
            if (!(self->m118 >= lbl_805A7634)) {
                self->m184 = 0;
                return;
            }
            self->m184 = 1;
            return;
        }
        return;
    }
    self->m184 = 0xd;
}

int fn_8003E844(Unk8003A5DC* self)
{
    int r = 0;
    if (self->m19C == 1 && self->m130 != 0 && self->m134 != 0)
        r = 1;
    return r;
}

void fn_8003E878(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1)
        fn_8001AA24(self->m11C, 1);
}

void fn_8003E8E4(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1)
        fn_800412AC(fn_8004072C(), 0x48, 7, 0, 0, 0);
}

void fn_8003E960(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if (fn_8003B478(self, 0xa) == 1)
                fn_800412AC(fn_8004072C(), 0x5f, 0, 0, 0, 0);
        } else if (fn_8003B478(self, 0x35) == 1) {
            fn_800412AC(fn_8004072C(), 0x84, 0, 0, 0, 0);
        }
    }
}

void fn_8003EA30(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c && fn_8003E844(self))
        fn_8003D944(self, 0x16, 5, self->m138, self->m130);
    fn_8003B3F4(self);
}

void fn_8003EAB0(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c && fn_8003E844(self)) {
        Unk8003B2DC_Sub6F8* p = self->m10C->m6F8;
        Unk8003B3F4_Sub14* q = p->m14;
        Unk8003EAB0_Sub10* r = p->m10;
        int b = r->m1C;
        unsigned char n = q->m1CC8;
        int n1 = n + 1;
        int a = q->m1CD0;
        if (n == 6 && a == 1 && b == 9) {
            fn_8003FBA4(self);
        } else {
            if (fn_8005C7E8(fn_8005BA9C(), 1) == 1)
                fn_8005C75C(fn_8005BA9C(), 1, 0x4b0);
            if (n1 == 1)
                fn_8001B62C();
            else
                fn_8001B5E4();
        }
    }
    fn_8003B3F4(self);
}

void fn_8003EB94(Unk8003A5DC* self)
{
    fn_8001B59C();
}

void fn_8003EBB4(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c && fn_8003E844(self))
        fn_8001B420();
}

void fn_8003EC18(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c && fn_8003E844(self))
        fn_8001B2F0();
}

void fn_8003EC7C(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c && fn_8003E844(self))
        fn_8001B4B8();
}

void fn_8003ECE0(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c && fn_8003E844(self))
        fn_8001B3D4();
}

void fn_8003ED44(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c && fn_8003E844(self)) {
        if (fn_8040ABA0() % 100 <= 0x31) {
            fn_8001B550();
            return;
        }
        fn_8001B33C();
    }
}

void fn_8003EDDC(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c && fn_8003E844(self))
        fn_8001B46C();
}

void fn_8003EE40(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c && fn_8003E844(self)) {
        fn_8001B504();
        self->m1B0 = self->m1B0 + 1;
    }
}

void fn_8003EEB0(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c && fn_8003E844(self))
        fn_8001B388();
}

void fn_8003EF14(Unk8003A5DC* self)
{
}
