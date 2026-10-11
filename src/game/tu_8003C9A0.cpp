/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8003C9A0-0x8003DF80 only: every data object is extern by its lbl_ name.
 * Continues the Unk8003A5DC object of tu_80039B04.cpp (include/game/tu_80039B04.h).
 */
#include "game/tu_80039B04.h"
#include "game/tu_8003C9A0.h"

extern int lbl_805B1A3C[];
int fn_80076644(int a, int b, int c);
int fn_8004475C(int a);
int fn_80044820(int a);
int fn_80044828(int a);
void fn_8001AECC(int a, int b, int c, int d);
extern Unk805B1A8C_Ent lbl_805B1A8C[];
extern int lbl_805B0E28;
extern float lbl_805A7630;
int fn_8003B52C(Unk8003A5DC* self, int a);
int fn_8005C498(void* p, int a);
void fn_8005C75C(void* p, int a, int b);
extern float lbl_805A7618;
int fn_8025416C(void* p, int n);

int fn_8040ABA0();
Unk800475EC_Obj* fn_800475EC();
int fn_8003E844(Unk8003A5DC* self);
void* fn_8004072C();
int fn_800412AC(void* o, int a, int b, int c, int d, int e);
int fn_8003B478(Unk8003A5DC* self, int a);
int fn_8003B4B8(Unk8003A5DC* self, int a);
int fn_8003B4EC(Unk8003A5DC* self, int a);
void fn_8003B618(Unk8003A5DC* self);
void fn_8003B394(Unk8003A5DC* self, int a);
void fn_8003DCA0(Unk8003A5DC* self);
void fn_8003DCE0(Unk8003A5DC* self);
void fn_8003DD7C(Unk8003A5DC* self);
void fn_8003E788();
void fn_8003E0C8(Unk8003A5DC* self);
void fn_8003E1EC(Unk8003A5DC* self);
void fn_8003E138(Unk8003A5DC* self);
void fn_8003E34C(Unk8003A5DC* self, int a, int b, int c);
void fn_8003E180(Unk8003A5DC* self, int a);
void fn_8003E494(Unk8003A5DC* self, int a);
void fn_8003E53C(Unk8003A5DC* self, int a);
void fn_8001B8A4(int a);
void fn_8001AE3C();
void fn_8001ADF4();
void* fn_8005BA9C();
int fn_8005C7E8(void* p, int a);
int fn_80235C68(int a);
int fn_80075E7C(int a);
int* fn_8006F9EC(Unk8003B2DC_Sub0C* p, int* count);

void fn_8003C9A0(Unk8003A5DC* self)
{
    if (self->m138 == 0 && self->m1B4 != 0) {
        if ((((Unk8003C9A0_Pl*)self->m130)->m590 & 0x20000000) == 0)
            fn_8003D944(self, 0x15, 0x3c, 0, self->m130);
    }
}

void fn_8003C9F4(Unk8003A5DC* self)
{
    fn_8003D944(self, 0x11, 0x32, self->m138, self->m130);
}

void fn_8003CA24(Unk8003A5DC* self, int a)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        int done = 0;
        if (a > 1 && fn_8003B478(self, 0x27) != 0) {
            done = 1;
            fn_800412AC(fn_8004072C(), 0x6b, 0, 0, 0, 0);
        }
        if (done == 0 && fn_8003B478(self, 0x2d) != 0)
            fn_800412AC(fn_8004072C(), 0x57, 0, 0, 0, 0);
    }
}

void fn_8003CB00(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o;
    int c;
    if (self->m138 == 0 && self->m160 == 0)
        fn_8003D944(self, 0x12, 0x3c, 0, self->m130);
    o = fn_800475EC();
    c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if (fn_8003B478(self, 0x1e) == 1)
                fn_800412AC(fn_8004072C(), 0x70, 0, 0, 0, 0);
        } else if (fn_8003B478(self, 0x1f) == 1) {
            fn_800412AC(fn_8004072C(), 0x71, 0, 0, 0, 0);
        }
    }
    self->m160 = 1;
    fn_8003B618(self);
}

void fn_8003CC0C(Unk8003A5DC* self, int a)
{
    if (!(a & 3) && (a >> 2) > self->m1B0)
        fn_8003D944(self, 0x13, 0x1e, self->m138, self->m130);
}

void fn_8003CC54(Unk8003A5DC* self, int a)
{
    if (self->m138 == 0 && a != 1)
        fn_8003D944(self, 0x14, 0x78, 0, self->m130);
}

void fn_8003CC98(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o;
    int c;
    self->m1A4 = 1;
    o = fn_800475EC();
    c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        int done = 0;
        if (self->m138 == 0) {
            if (fn_8003B478(self, 0x1c) == 1) {
                done = 1;
                fn_800412AC(fn_8004072C(), 0x74, 0, 0, 0, 0);
            }
        } else if (fn_8003B478(self, 0x1d) == 1) {
            done = 1;
            fn_800412AC(fn_8004072C(), 0x75, 0, 0, 0, 0);
        }
        if (done == 0)
            fn_8001B8A4(1 << (fn_8040ABA0() % 10));
    }
}

void fn_8003CDB4(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1 && self->m138 != 0 && fn_8003B478(self, 0x20) == 1)
        fn_800412AC(fn_8004072C(), 0x58, 0, 0, 0, 0);
}

void fn_8003CE50(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1 && self->m138 != 0) {
        if (fn_8003B478(self, 0x21) == 1)
            fn_800412AC(fn_8004072C(), 0x59, 0, 0, 0, 0);
        fn_8003D944(self, 0x17, 0x28, self->m138, self->m130);
    }
}

void fn_8003CF04(Unk8003A5DC* self, int a)
{
    if (self->m198 == 0) {
        fn_8003E788();
        self->m198 = 1;
    }
    if (self->m184 != -1 && lbl_805B1A3C[self->m184] != 1 && self->m184 != 0xe && self->m184 != 0xf)
        self->m184 = -1;
    self->m164 = 0;
    self->m1B0 = 0;
    self->m16C = self->m16C + 1;
    fn_8003B394(self, a);
    if (self->m138 == 0) {
        fn_8003DD7C(self);
        fn_8003D944(self, 0x19, 0x3c, self->m138, self->m130);
    } else {
        fn_8003D944(self, 0x19, 1, self->m138, self->m130);
    }
    if (self->m184 == -1) {
        Unk800475EC_Obj* o = fn_800475EC();
        int c = 0;
        if (o->mF4 == 1)
            c = o->mC00 >= 0;
        if (c == 1 && fn_8003E844(self) == 1) {
            if (self->m138 == 0) {
                fn_8003E0C8(self);
                fn_8003E1EC(self);
            } else {
                fn_8003E138(self);
            }
            fn_8003D944(self, 1, 0x64, self->m138, self->m130);
        }
    }
    fn_8003B618(self);
}

void fn_8003D078(Unk8003A5DC* self, int a)
{
    if (self->m138 == 1) {
        if (!((float)fn_8025416C((void*)(a + 0x588), 0xd) >= lbl_805A7618) && fn_8003B478(self, 0x2a) != 0)
            fn_800412AC(fn_8004072C(), 0x69, 0, 0, 0, 0);
    }
}

/* near-miss: 135/135 slots, 6 differ: retail keeps a2 in r27 and the "done"
 * flag in r28, here they are swapped. Tried: flag declared at function scope,
 * "!done", split/merged declarations, switch and if-chain forms of the
 * m184 reset (the nested-if form here is the closest). */
void fn_8003D120(Unk8003A5DC* self, int a1, int a2, int a3, int a4, int a5, unsigned int a6, int a7)
{
    Unk800475EC_Obj* o;
    int c;
    int t = self->m184;
    self->m1AC = self->m1AC + 1;
    self->m170 = a1;
    if (t != -1 && a3 != 0) {
        if (a1 != 3) {
            int w = lbl_805B1A3C[t];
            if (w == 0) {
                if (a3 == self->m130)
                    self->m184 = -1;
            } else if (w == 1) {
                if (t == 0xd)
                    self->m184 = -1;
            }
        } else {
            self->m184 = -1;
        }
    }
    o = fn_800475EC();
    c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        int done = 0;
        if (self->m138 == 0) {
            if (a4 == 1 && fn_8003B478(self, 0) == 1)
                fn_800412AC(fn_8004072C(), 0x7e, 0, 0, 0, 0);
        } else {
            fn_8003E34C(self, a1, a2, a3);
            fn_8003E180(self, a3);
            if (a2 == 1)
                fn_8003E494(self, a3);
            if (fn_8003B478(self, 0x25) == 1) {
                done = 1;
                fn_800412AC(fn_8004072C(), 0x73, 0, 0, 0, 0);
            }
            if (done == 0 && fn_8003B478(self, 0x26) != 0)
                fn_800412AC(fn_8004072C(), 0x72, 0, 0, 0, 0);
        }
    }
    if (a5 != 0 && self->m138 == 1 && a7 == 1 && a6 <= 2)
        fn_8003D944(self, 0x17, 0x28, 1, self->m130);
    fn_8003DCA0(self);
    fn_8003B618(self);
}

void fn_8003D33C(Unk8003A5DC* self, int a, int b)
{
    self->m114 = a - b;
}

void fn_8003D348(Unk8003A5DC* self, unsigned int a, unsigned int b)
{
    self->m118 = (float)a / (float)b;
}

void fn_8003D394(Unk8003A5DC* self)
{
    int done = 0;
    int ok = 1;
    int v = fn_8025416C((void*)(self->m130 + 0x588), 0);
    if (v == 0xfa || v == 0x395)
        ok = 0;
    if ((unsigned int)(fn_80235C68(self->m10C->m700->m3B0) - 1) <= 1) {
        Unk800475EC_Obj* o = fn_800475EC();
        int c = 0;
        if (o->mF4 == 1)
            c = o->mC00 >= 0;
        if (c == 1 && fn_8003E844(self) == 1) {
            if (self->m138 == 0) {
                if (fn_8003B4EC(self, 0) == 1) {
                    done = 1;
                    fn_800412AC(fn_8004072C(), 0x5c, 0, 0, 0, 0);
                }
                if (ok == 1 && done == 0 && fn_8003B4EC(self, 1) == 1) {
                    void* t = fn_8004072C();
                    fn_800412AC(t, 0x5e, fn_8025416C((void*)(self->m130 + 0x588), 0), 0, 0, 0);
                }
            } else if (ok == 1 && done == 0 && fn_8003B4EC(self, 4) == 1 && (unsigned int)self->m164 <= 1 && (unsigned int)self->m16C > 1) {
                void* t = fn_8004072C();
                fn_800412AC(t, 0x66, fn_8025416C((void*)(self->m130 + 0x588), 0), 0, 0, 0);
                self->m164 = self->m164 + 1;
            }
        }
    }
}

void fn_8003D554(Unk8003A5DC* self)
{
    int done = 0;
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1 && self->m138 == 0) {
        if (fn_8003B4EC(self, 2) == 1) {
            done = 1;
            fn_800412AC(fn_8004072C(), 0x5d, 0, 0, 0, 0);
        }
        if (done == 0 && fn_8003B4EC(self, 3) == 1) {
            void* t = fn_8004072C();
            fn_800412AC(t, 0x6d, fn_8025416C((void*)(self->m134 + 0x588), 0), 0, 0, 0);
        }
    }
}

/* near-miss: 110/111 slots. Retail merges the fn_800412AC tails of the
 * 0x4C/0x4B/0x4A paths (cross-jump) and keeps r in r30 alone; a variant with
 * one shared call site (locals for id/value) was worse. */
void fn_8003D648(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        int r = fn_8040ABA0() % 100;
        if (fn_80075E7C(self->m10C->m6F8->mC->m24) == 0x37) {
            int cnt;
            int* p = fn_8006F9EC(self->m10C->m6F8->mC, &cnt);
            if (cnt > 0) {
                void* t = fn_8004072C();
                if (cnt > 0)
                    p = &p[fn_8040ABA0() % cnt];
                fn_800412AC(t, 0x4c, *p + 0x65, 0, 0, 0);
                return;
            }
        } else {
            int v = self->m1A0;
            if (v == 0) {
                int s = self->m18 + self->m1C;
                if (r <= s + self->m24) {
                    if (r > s)
                        fn_800412AC(fn_8004072C(), 0x4b, self->m124, 0, 0, 0);
                    else
                        fn_800412AC(fn_8004072C(), 0x4a, 0, 0, 0, 0);
                    return;
                }
            } else if (v >= 0 && v <= 2) {
                int s = self->m18 + self->m20;
                if (!(r > s + self->m24)) {
                    if (r <= s) {
                        fn_800412AC(fn_8004072C(), 0x4a, 0, 0, 0, 0);
                        return;
                    }
                    fn_800412AC(fn_8004072C(), 0x4b, self->m124, 0, 0, 0);
                }
            }
        }
    }
}

void fn_8003D804(Unk8003A5DC* self)
{
    self->m168 = 1;
    fn_8003B618(self);
    fn_8003DCE0(self);
}

void fn_8003D840(Unk8003A5DC* self)
{
    int t;
    Unk800475EC_Obj* o;
    int c;
    t = fn_8005C7E8(fn_8005BA9C(), 1);
    o = fn_800475EC();
    c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && t == 0 && fn_8040ABA0() % 100 <= self->m28)
        fn_8001AE3C();
}

void fn_8003D8DC(Unk8003A5DC* self)
{
    int t;
    Unk800475EC_Obj* o;
    int c;
    t = fn_8005C7E8(fn_8005BA9C(), 1);
    o = fn_800475EC();
    c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && t == 0)
        fn_8001ADF4();
}

int fn_8003D944(Unk8003A5DC* self, int id, int time, int a3, int a4)
{
    int ok = 0;
    int i;
    for (i = 0; i < 10; i++) {
        if (self->m30[i].mC == 0) {
            self->m30[i].mC = time;
            self->m30[i].m0 = id;
            self->m30[i].m8 = a4;
            self->m30[i].m4 = a3;
            ok = 1;
            self->mD0 = self->mD0 + 1;
            break;
        }
    }
    return ok;
}

void fn_8003D9D8(Unk8003A5DC* self)
{
    fn_8003E53C(self, 0);
}

void fn_8003D9FC(Unk8003A5DC* self)
{
    int v = fn_8025416C((void*)(self->m130 + 0x588), 0);
    int flag = v > 0x4e1f;
    int w;
    if (flag)
        v -= 0x4e20;
    w = ((Unk8003C9A0_Pl*)self->m130)->m460;
    if (w == 0) {
        int a = fn_8025416C((void*)(self->m130 + 0x588), 5);
        int b = fn_8025416C((void*)(self->m130 + 0x588), 6);
        if (fn_80076644(0, a, b) == 0)
            w = -1;
    }
    fn_8001AECC(fn_8004475C(w), v, fn_80044820(self->m138), fn_80044828(flag));
}

void fn_8003DACC(Unk8003A5DC* self, int i)
{
    if (fn_8003E844(self) != 0 && self->m30[i].m8 == self->m130 && self->m30[i].m4 == self->m138) {
        if (fn_8005C7E8(fn_8005BA9C(), lbl_805B0E28) == 0) {
            if (fn_8003B52C(self, 2) == 1) {
                self->m184 = 2;
                self->m190 = fn_8025416C((void*)(self->m130 + 0x588), 0);
                fn_8003E53C(self, 1);
            } else if (fn_8003B52C(self, 3) == 1) {
                self->m184 = 3;
                self->m190 = fn_8025416C((void*)(self->m130 + 0x588), 0);
                fn_8003E53C(self, 1);
            } else if (fn_8003B52C(self, 4) == 1) {
                self->m184 = 4;
                self->m190 = fn_8025416C((void*)(self->m130 + 0x588), 0);
                fn_8003E53C(self, 1);
            } else if (fn_8003B52C(self, 5) == 1) {
                self->m184 = 5;
                self->m190 = fn_8025416C((void*)(self->m130 + 0x588), 0);
                fn_8003E53C(self, 1);
            }
        } else {
            fn_8003D944(self, 0, 0x1e, self->m138, self->m130);
        }
    }
}

/* near-miss: 40/40 slots, register allocation differs (retail r10/r29/r30/r5,
 * here r7/r29/r30/r8). All 2,520 orders of the seven stores were tried. */
void fn_8003DC00(Unk8003A5DC* self)
{
    Unk8003A5DC_Ctx* p = self->m10C;
    self->m174 = p->m6F8->m14->m1CC8 + 1;
    self->m178 = p->m6F8->m14->m1CD0 == 0;
    self->m18C = self->m18C + 1;
    self->m180 = self->m184;
    self->m184 = -1;
    self->m188 = self->m188 + 1;
    self->m17C = (float)p->m48 * lbl_805A7630;
}

void fn_8003DCA0(Unk8003A5DC* self)
{
    if (fn_8005C7E8(fn_8005BA9C(), 1) == 1)
        fn_8005C75C(fn_8005BA9C(), 1, 0x9c4);
}

void fn_8003DCE0(Unk8003A5DC* self)
{
    int a = fn_8005C7E8(fn_8005BA9C(), 1);
    int b = fn_8005C498(fn_8005BA9C(), 1);
    if (a != 0 && b == 4)
        fn_8005C75C(fn_8005BA9C(), 1, 0x4b0);
    fn_800412AC(fn_8004072C(), 0x49, 0, 0, 0, 0);
}

void fn_8003DD5C(Unk8003A5DC* self)
{
    fn_8003DCE0(self);
}

void fn_8003DD7C(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        int v;
        if (fn_8005C7E8(fn_8005BA9C(), 1) != 0) {
            if (fn_8005C498(fn_8005BA9C(), 1) == 4)
                fn_8005C75C(fn_8005BA9C(), 1, 0x3e8);
        }
        v = fn_8025416C((void*)(self->m130 + 0x588), 10);
        fn_800412AC(fn_8004072C(), 0x48, v, 0, 0, 0);
    }
}

/* near-miss: 79/79 slots; self is r31 and the index r30 in retail, swapped
 * here. found/v/i declaration order and i<0x44 vs i<=0x43 did not change it. */
void fn_8003DE44(Unk8003A5DC* self, int a)
{
    if (self->m184 == -1 && fn_8003E844(self) == 1) {
        int i = 0;
        int v = fn_8025416C((void*)(self->m130 + 0x588), 0);
        int found = 0;
        int x;
        for (i = 0; i <= 0x43; i++) {
            if (v == lbl_805B1A8C[i].m0) {
                found = 1;
                break;
            }
        }
        if (found == 1) {
            int k = lbl_805B1A8C[i].m4;
            if (k == 0) {
                if (fn_8003B52C(self, 2) == 1) {
                    x = 2;
                    goto set;
                }
                if (fn_8003B52C(self, 3) == 1) {
                    x = 3;
                    goto set;
                }
            } else if (a == 1 && k == 1) {
                if (fn_8003B52C(self, 4) == 1) {
                    x = 4;
                    goto set;
                }
                if (fn_8003B52C(self, 5) == 1) {
                    x = 5;
                set:
                    self->m184 = x;
                    self->m190 = v;
                }
            }
        }
    }
}
