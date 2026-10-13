/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8003AEE4-0x8003C9A0 only: every data object is extern by its lbl_ name.
 * Continues the Unk8003A5DC object of tu_80039B04.cpp (include/game/tu_80039B04.h).
 */
#include "game/tu_80039B04.h"
#include "game/tu_8003AEE4.h"

extern float lbl_805A75BC;
extern double lbl_805A75C0;
extern float lbl_805A75C8;
extern double lbl_805A75D0;
extern float lbl_805A75D8;
extern double lbl_805A75E0;
extern int lbl_805B1634[];

int fn_80235C68(int a);
int fn_8040ABA0();
int fn_80047218(int a);
void fn_8001B674(int a, int b);
int fn_8003D944(Unk8003A5DC* self, int a, int b, int c, int d);
void fn_8003E7F4();
int fn_8009E1D4(void* p, int a, int b);
int fn_800471DC(int a, int b, int c);
int fn_80047250(Unk8003A5DC_Ctx* ctx);
int fn_8003B478(Unk8003A5DC* self, int a);
int fn_8003B4B8(Unk8003A5DC* self, int a);
void fn_8001B6D0(int a, int b, int c, int d);
void fn_8001B73C(int a, int b);
Unk800475EC_Obj* fn_800475EC();
int fn_8003E844(Unk8003A5DC* self);
void* fn_8004072C();
int fn_800412AC(void* o, int a, int b, int c, int d, int e);
void fn_8003DCA0(Unk8003A5DC* self);
void fn_8003D840(Unk8003A5DC* self);
extern int* lbl_8061B9C4;
void fn_8003DCE0(Unk8003A5DC* self);
int fn_80075E7C(int a);
Unk80039B04_Mgr* fn_80038EB4();
int fn_8003A194(Unk80039B04_Mgr* self, int a, int b, float f);
int fn_8003A2D8(Unk80039B04_Mgr* self, int a);
int fn_8003A354(Unk80039B04_Mgr* self, int a, int b, float f);
int fn_8003A498(Unk80039B04_Mgr* self, int a, int b, float f);
void fn_8003B56C(Unk8003A5DC* self);
void fn_8003B618(Unk8003A5DC* self);
void fn_8003B674(Unk8003A5DC* self);

void fn_8003AEE4(Unk8003A5DC* self)
{
    Unk8027107C_Outer* o = self->m10C->m700;
    if (fn_80235C68(o->m3B0) <= 1) {
        if (self->m1E0[0] == 0) {
            fn_8003AF68(self);
            fn_8003D944(self, 3, 0x78, self->m138, self->m130);
            return;
        }
        if (self->m1E0[1] == 0)
            fn_8003B008(self);
    }
}

void fn_8003AF68(Unk8003A5DC* self)
{
    Unk8027107C_Outer* o = self->m10C->m700;
    if (fn_80235C68(o->m3B0) <= 1 && self->m1E0[0] == 0) {
        if (self->m1A8 > 0) {
            int bit = 1 << (fn_8040ABA0() % 10);
            fn_8001B674(fn_80047218(self->m170), bit);
        }
        self->m1E0[0] = 1;
    }
}

void fn_8003B008(Unk8003A5DC* self)
{
    Unk8027107C_Outer* o = self->m10C->m700;
    if (fn_80235C68(o->m3B0) <= 1 && self->m1E0[1] == 0) {
        int bit = 1 << (fn_8040ABA0() % 10);
        if (self->m154 != self->m148 || self->m158 != self->m14C || self->m15C != self->m150) {
            int a = fn_800471DC(self->m13C, self->m140, self->m144);
            int b = fn_80047218(self->m170);
            fn_8001B6D0(a, b, fn_80047250(self->m10C), bit);
        }
        self->m1E0[1] = 1;
    }
}

void fn_8003B0F4(Unk8003A5DC* self, Unk8003B0F4_Arg* s)
{
    int a = s->m10;
    int b = s->mC;
    int d = s->m1C;
    int e = s->m20;
    int f = s->m14;
    int g = s->m18;
    int h = s->m24;
    int c = s->m28;
    int bit = 1 << (fn_8040ABA0() % 10);
    if (b != a) {
        switch (a) {
        case 9:
            fn_8001B73C(8, bit);
            break;
        case 10:
        case 11:
            fn_8001B73C(0x10, bit);
            break;
        case 12:
        case 13:
        case 14:
            fn_8001B73C(0x20, bit);
            break;
        case 15:
        case 16:
            fn_8001B73C(0x40, bit);
            break;
        }
    } else if (d != e) {
        switch (e) {
        case 11:
            fn_8001B73C(1, bit);
            break;
        case 12:
        case 13:
            fn_8001B73C(4, bit);
            break;
        }
    } else if (f != g) {
        switch (g) {
        case 3:
            fn_8001B73C(0x20, bit);
            break;
        case 4:
        case 5:
            fn_8001B73C(0x80, bit);
            break;
        }
    } else if (h != c && c == 3) {
        fn_8001B73C(2, bit);
    }
}

void fn_8003B23C(Unk8003A5DC* self, int i)
{
    char* p = (char*)self->m10C->m6F8->m14 + i * 0xE64;
    if (i == 0) {
        char* q = p + 0x8C;
        self->m11C = fn_8009E1D4(q, 2, 0);
        self->m128 = fn_8009E1D4(q, 0, 0);
    } else {
        char* q = p + 0x8C;
        self->m120 = fn_8009E1D4(q, 2, 0);
        self->m12C = fn_8009E1D4(q, 0, 0);
    }
}

void fn_8003B2DC(Unk8003A5DC* self, Unk8003A5DC_Ctx* ctx)
{
    if (self->m110 == 0 && ctx != 0) {
        self->m10C = ctx;
        self->m1A0 = ctx->m6F8->mC->m80;
        self->m124 = lbl_805B1634[fn_80075E7C(ctx->m6F8->mC->m24)];
        self->m110 = 1;
        fn_8003B56C(self);
        fn_8003B674(self);
        fn_8003B618(self);
        self->fn_8003AEC0();
    }
}

void fn_8003B378(Unk8003A5DC* self)
{
    if (self->m110 == 1) {
        self->m10C = 0;
        self->m110 = 0;
    }
}

void fn_8003B394(Unk8003A5DC* self, int a)
{
    self->m130 = a;
    if (self->m134 != 0 && a != 0)
        self->m19C = 1;
}

void fn_8003B3B8(Unk8003A5DC* self, int a)
{
    self->m134 = a;
    if (a != 0 && self->m130 != 0)
        self->m19C = 1;
}

void fn_8003B3DC(Unk8003A5DC* self, int a)
{
    self->m138 = a;
}

void fn_8003B3E4(Unk8003A5DC* self, int a, int b, int c)
{
    self->m13C = a;
    self->m140 = b;
    self->m144 = c;
}

void fn_8003B3F4(Unk8003A5DC* self)
{
    Unk8003B3F4_Sub14* p;
    unsigned char n;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m16C = 0;
    self->m18C = 0;
    self->m170 = 0;
    p = self->m10C->m6F8->m14;
    n = p->m1CC8;
    if (p->m1CD0 == 1 && self->m174 <= n - 1)
        fn_8003E7F4();
}

int fn_8003B478(Unk8003A5DC* self, int a)
{
    return fn_8003A194(fn_80038EB4(), a, self->m114, self->m118);
}

int fn_8003B4B8(Unk8003A5DC* self, int a)
{
    return fn_8003A2D8(fn_80038EB4(), a);
}

int fn_8003B4EC(Unk8003A5DC* self, int a)
{
    return fn_8003A354(fn_80038EB4(), a, self->m114, self->m118);
}

int fn_8003B52C(Unk8003A5DC* self, int a)
{
    return fn_8003A498(fn_80038EB4(), a, self->m114, self->m118);
}

void fn_8003B56C(Unk8003A5DC* self)
{
    self->mFC = (unsigned int)(self->m4 * lbl_805A75BC);
    self->m100 = (unsigned int)(self->m8 * lbl_805A75BC);
}

void fn_8003B618(Unk8003A5DC* self)
{
    self->m108 = (unsigned int)(self->m2C * lbl_805A75C8);
}

void fn_8003B674(Unk8003A5DC* self)
{
    self->m104 = (unsigned int)(self->m14 * lbl_805A75D8);
}

void fn_8003B6D0(Unk8003A5DC* self, unsigned int a1, unsigned int a2, int a3, int a4)
{
    int done = 0;
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if (a2 <= 3 && self->m1A4 == 0)
                fn_8003D840(self);
            if (fn_8003B478(self, 3) == 1) {
                done = 1;
                fn_800412AC(fn_8004072C(), 0x4d, 0, 0, 0, 0);
            }
            if (done == 0 && a3 == 1 && fn_8003B478(self, 0x3e) == 1) {
                done = 1;
                fn_800412AC(fn_8004072C(), 0x8d, 0, 0, 0, 0);
            }
        } else {
            if (a1 > 2 && fn_8003B478(self, 2) == 1) {
                done = 1;
                fn_800412AC(fn_8004072C(), 0x4e, 0, 0, 0, 0);
            }
            if (done == 0) {
                if (a4 == 1 && fn_8003B478(self, 1) == 1) {
                    done = 1;
                    fn_800412AC(fn_8004072C(), 0x7f, 0, 0, 0, 0);
                }
                if (done == 0 && a4 == 1 && fn_8003B478(self, 0) == 1) {
                    done = 1;
                    fn_800412AC(fn_8004072C(), 0x7e, 0, 0, 0, 0);
                }
                if (done == 0 && a3 == 1 && fn_8003B478(self, 0x41) == 1) {
                    done = 1;
                    fn_800412AC(fn_8004072C(), 0x90, 0, 0, 0, 0);
                }
            }
        }
        if (done == 1)
            fn_8003B56C(self);
    }
    fn_8003B618(self);
}

void fn_8003B914(Unk8003A5DC* self, int a1, int a2, int a3, int a4)
{
    int done = 0;
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if (a1 < *lbl_8061B9C4 && self->m1A4 == 0)
                fn_8003D840(self);
            if (a1 > 1 && a2 == 0 && fn_8003B478(self, 0x10) == 1) {
                done = 1;
                fn_800412AC(fn_8004072C(), 0x54, 0, 0, 0, 0);
            }
            if (a2 == 1) {
                if (done == 0 && a3 == 1 && fn_8003B478(self, 0x3f) == 1) {
                    done = 1;
                    fn_800412AC(fn_8004072C(), 0x8e, 0, 0, 0, 0);
                } else if (fn_8003B478(self, 0x11) == 1) {
                    done = 1;
                    fn_800412AC(fn_8004072C(), 0x76, 0, 0, 0, 0);
                }
            } else if (done == 0) {
                if (a4 == 1 && fn_8003B478(self, 1) == 1) {
                    done = 1;
                    fn_800412AC(fn_8004072C(), 0x7f, 0, 0, 0, 0);
                }
                if (done == 0 && a4 == 1 && fn_8003B478(self, 0) == 1) {
                    done = 1;
                    fn_800412AC(fn_8004072C(), 0x7e, 0, 0, 0, 0);
                }
            }
        } else if (a2 == 0) {
            if (fn_8003B478(self, 0x34) == 1) {
                done = 1;
                fn_800412AC(fn_8004072C(), 0x83, 0, 0, 0, 0);
            }
        } else if (a3 == 1 && fn_8003B478(self, 0x40) == 1) {
            done = 1;
            fn_800412AC(fn_8004072C(), 0x8f, 0, 0, 0, 0);
        }
        if (done == 1)
            fn_8003B56C(self);
    }
    fn_8003B618(self);
}

void fn_8003BB78(Unk8003A5DC* self, int a1, unsigned int a2, int a3, int a4)
{
    int done = 0;
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (a2 > 2 && fn_8003B478(self, 0x28) == 1) {
            done = 1;
            fn_800412AC(fn_8004072C(), 0x6a, 0, 0, 0, 0);
        }
        if (self->m138 == 0) {
            if (done == 0) {
                if (a1 == 0 && fn_8003B478(self, 0x13) == 1) {
                    done = 1;
                    fn_800412AC(fn_8004072C(), 0x51, 0, 0, 0, 0);
                }
                if (done == 0 && fn_8003B478(self, 0x22) == 1) {
                    done = 1;
                    fn_800412AC(fn_8004072C(), 0x60, 0, 0, 0, 0);
                }
            }
        } else {
            if (a1 == 0 && done == 0 && fn_8003B478(self, 0x14) == 1) {
                void* t;
                done = 1;
                t = fn_8004072C();
                fn_800412AC(t, 0x52, fn_8025416C((void*)(self->m130 + 0x588), 0), 0, 0, 0);
            }
            if (done == 0 && fn_8003B478(self, 0x16) == 1) {
                done = 1;
                fn_800412AC(fn_8004072C(), 0x65, 0, 0, 0, 0);
            }
        }
        if (done == 1)
            fn_8003B56C(self);
        else
            fn_8003B914(self, 3, a1, a3, a4);
        if (self->m138 == 1 && a1 == 1 && ((unsigned int)self->m170 > 2 || fn_8040ABA0() % 100 <= 0x31))
            fn_8003D944(self, 0xf, 0x1e, self->m138, self->m130);
    }
    fn_8003B618(self);
}

void fn_8003BDE8(Unk8003A5DC* self, int a1, int a2)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        int done = 0;
        if (self->m138 == 0) {
            if (fn_8003B478(self, 0xd) == 1) {
                done = 1;
                fn_800412AC(fn_8004072C(), 0x6e, 0, 0, 0, 0);
            }
            if (done == 0 && a1 == 1 && fn_8003B478(self, 0x3e) == 1)
                fn_800412AC(fn_8004072C(), 0x8d, 0, 0, 0, 0);
            return;
        }
        if (fn_8003B478(self, 0x37) == 1) {
            done = 1;
            fn_800412AC(fn_8004072C(), 0x86, 0, 0, 0, 0);
        }
        if (done == 0) {
            if (a1 == 1 && fn_8003B478(self, 0x41) == 1) {
                done = 1;
                fn_800412AC(fn_8004072C(), 0x90, 0, 0, 0, 0);
            }
            if (done == 0) {
                if (a2 == 1 && fn_8003B478(self, 1) == 1) {
                    done = 1;
                    fn_800412AC(fn_8004072C(), 0x7f, 0, 0, 0, 0);
                }
                if (done == 0 && a2 == 1 && fn_8003B478(self, 0) == 1)
                    fn_800412AC(fn_8004072C(), 0x7e, 0, 0, 0, 0);
            }
        }
    }
}

void fn_8003BFE0(Unk8003A5DC* self, unsigned int a1, int a2, int a3)
{
    int done = 0;
    Unk800475EC_Obj* o;
    int c;
    fn_8003DCA0(self);
    fn_8003DCE0(self);
    o = fn_800475EC();
    c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if (fn_8003B478(self, 4) == 1) {
                done = 1;
                fn_800412AC(fn_8004072C(), 0x4f, 0, 0, 0, 0);
            }
            if (done == 0) {
                if (fn_8003B478(self, 0x23) != 0) {
                    done = 1;
                    fn_800412AC(fn_8004072C(), 0x61, 0, 0, 0, 0);
                }
                if (done == 0 && fn_8003B478(self, 0x24) != 0) {
                    done = 1;
                    fn_800412AC(fn_8004072C(), 0x53, self->m11C, 0, 0, 0);
                }
            }
        } else if (a1 > 2 && fn_8003B478(self, 5) == 1) {
            done = 1;
            fn_800412AC(fn_8004072C(), 0x50, 0, 0, 0, 0);
        }
        if (done == 1)
            fn_8003B56C(self);
        else
            fn_8003B6D0(self, a1, 3, a2, a3);
    }
    fn_8003B618(self);
}

void fn_8003C188(Unk8003A5DC* self)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if (fn_8003B478(self, 0xe) == 1) {
                fn_800412AC(fn_8004072C(), 0x62, 0, 0, 0, 0);
            }
        } else if (fn_8003B478(self, 0xf) == 1) {
            fn_800412AC(fn_8004072C(), 0x63, 0, 0, 0, 0);
        }
    }
    fn_8003DCA0(self);
    fn_8003DCE0(self);
    fn_8003B618(self);
}

void fn_8003C270(Unk8003A5DC* self, int a)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if ((a == 1 && fn_8003B4B8(self, 0x14) != 0) || ((unsigned int)a > 1 && fn_8003B4B8(self, 0x32) != 0)) {
                fn_800412AC(fn_8004072C(), 0x5a, 0, 0, 0, 0);
            }
        } else if ((unsigned int)a > 1 && fn_8003B478(self, 7) == 1) {
            fn_800412AC(fn_8004072C(), 0x5b, 0, 0, 0, 0);
        }
    }
    fn_8003DCA0(self);
    fn_8003DCE0(self);
    fn_8003B618(self);
}

struct Unk8003C388_Vec3 {
    float x;
    float y;
    float z;
};
struct Unk8003C388_Pos {
    char pad0[0x3F4];
    float m3F4;
};
struct Unk8005BA1C_Obj;
Unk8005BA1C_Obj* fn_8005BA9C();
int fn_8005C7E8(Unk8005BA1C_Obj* o, int a);
void fn_8003E53C(Unk8003A5DC* self, int a);
extern "C" float fn_8018CDB8(Unk8003C388_Pos* p, int a, float f);
extern "C" void fn_8018959C(Unk8003C388_Vec3* out, Unk8003C388_Pos* p, float t);
extern "C" float fn_804028E4(float x);
extern "C" int rand();
extern int lbl_805B0C78;
extern const float lbl_805A75EC;
extern const float lbl_805A75F0;
extern const float lbl_805A75F4;
extern const float lbl_805A7600;

inline float Unk8003C388_M3F4(const Unk8003C388_Pos* p) { return p->m3F4; }

inline float Unk8003C388_Len(const Unk8003C388_Vec3& v)
{
    return fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
}

/* near-miss (99.29%, 227 vs 226 insns): the float->unsigned conversion of the first call (e * lbl_805A75F4)
 * comes out as `cror; bns; b`, retail has `blt; b` (plain LT) there; the second call's conversion matches.
 * Tried: unsigned locals, one shared call through a goto, the reversed (l1 - l0) test. Every 0.0f is a
 * literal (retail's lbl_805A75E8 pool entry); the m3F4 read of the first subtraction goes through an inline
 * accessor so it loads before e. */
extern "C" void fn_8003C388(Unk8003A5DC* self, int a, int b, unsigned c, int d)
{
    if (fn_8003E844(self) == 1) {
        int t = fn_8005C7E8(fn_8005BA9C(), lbl_805B0C78);
        if (a != 0) {
            Unk8003C388_Pos* pos = *(Unk8003C388_Pos**)((char*)self->m10C + 0x6CC);
            float e = fn_8018CDB8(pos, 0xB, 0.0f);
            if (!(e <= 0.0f)) {
                float f10 = fn_8018CDB8(pos, 0xA, 0.0f);
                float f3 = fn_8018CDB8(pos, 3, 0.0f);
                Unk8003C388_Vec3 v0;
                fn_8018959C(&v0, pos, e - Unk8003C388_M3F4(pos));
                float l0 = Unk8003C388_Len(v0) * lbl_805A75EC;
                if (!(f3 <= 0.0f) && !(f3 <= e)) {
                    Unk8003C388_Vec3 v1;
                    fn_8018959C(&v1, pos, f3 - pos->m3F4);
                    float l1 = Unk8003C388_Len(v1) * lbl_805A75EC;
                    if (!((l1 - l0) >= lbl_805A75F0))
                        fn_8003D944(self, 2, (unsigned)(e * lbl_805A75F4), self->m138, self->m130);
                } else if (!(f10 <= 0.0f) && !(f10 <= e)) {
                    Unk8003C388_Vec3 v1;
                    fn_8018959C(&v1, pos, f10 - pos->m3F4);
                    float l1 = Unk8003C388_Len(v1) * lbl_805A75EC;
                    if (!((l1 - l0) >= lbl_805A75F0))
                        fn_8003D944(self, 2, (unsigned)(e * lbl_805A7600), self->m138, self->m130);
                }
            }
        } else if (b != 0) {
            if (self->m138 == 1 && rand() % 100 <= 0x1D)
                fn_8003D944(self, 0xD, c >> 1, self->m138, self->m130);
        } else if (d != 0 && self->m138 == 1 && rand() % 100 <= 0x1D) {
            fn_8003D944(self, 0xE, c >> 1, self->m138, self->m130);
        }
        if (t == 0 && self->m184 != -1)
            fn_8003E53C(self, 0);
        else if (self->m138 == 0)
            fn_8003D840(self);
    }
}

void fn_8003C710(Unk8003A5DC* self, int a)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (self->m138 == 0) {
            if ((a == 0 && fn_8003B4B8(self, 0x14) != 0) || (a != 0 && fn_8003B4B8(self, 0x32) != 0)) {
                fn_800412AC(fn_8004072C(), 0x67, 0, 0, 0, 0);
            }
        } else if (fn_8003B478(self, 9) == 1) {
            fn_800412AC(fn_8004072C(), 0x68, 0, 0, 0, 0);
        }
    }
}

/* fn_8003D944 returns int (ends mr r3,r10); that decides where each "mr r3,r31" lands. */
void fn_8003C804(Unk8003A5DC* self, int a)
{
    Unk800475EC_Obj* o = fn_800475EC();
    int done = 0;
    int c = 0;
    if (o->mF4 == 1)
        c = o->mC00 >= 0;
    if (c == 1 && fn_8003E844(self) == 1) {
        if (fn_8003B478(self, 0x2e) == 1) {
            done = 1;
            fn_800412AC(fn_8004072C(), 0x55, 0, 0, 0, 0);
        }
        if (done == 0 && fn_8003B478(self, 0x2f) != 0) {
            fn_800412AC(fn_8004072C(), 0x56, 0, 0, 0, 0);
        }
    }
    fn_8003D944(self, 6, 0x78, self->m138, self->m130);
    fn_8003D944(self, 7, 0x12c, self->m138, self->m130);
    fn_8003D944(self, 8, 0x1e0, self->m138, self->m130);
    fn_8003D944(self, 9, 0x294, self->m138, self->m130);
    if (a != 0)
        fn_8003D944(self, 10, 0x348, self->m138, self->m130);
    fn_8003D944(self, 12, 0x3fc, self->m138, self->m130);
    fn_8003D944(self, 11, 0x4b0, self->m138, self->m130);
}

void fn_8003C988(Unk8003A5DC* self)
{
    if (self->m138 == 0)
        self->m1B4 = 1;
}
