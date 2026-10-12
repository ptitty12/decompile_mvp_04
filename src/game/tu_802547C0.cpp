/*
 * Game code, .text 0x802547C0-0x80256C80 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_8024EF40.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;

extern "C++" {
/* near-miss: loop in the last block is laid out differently (2 instructions shorter here) */
int fn_80254EA4(A* self, int a);
int fn_8035E318(A* a);
int fn_8014E374(int a);
int fn_8014E310(int a);
int fn_8026D730(P* p, int a);
int fn_801BBEFC(int a);
int fn_801BBF04(int a);
int fn_8017C94C(Unk8024EF40_Ctx* c);
int fn_80257458(void* list, P* p);
void* fn_801A497C(void* q, int a, int b);
void fn_80081C94(void* y, int a, int b, int c, int d);
void fn_8037893C(void* q, int id, void* o, int a, int b);
void fn_8035E214(void* o, int a);
P* fn_80257BD0(void* list, P* p, int a);
P* fn_80257DFC(void* list, P* p, int a);
void fn_80258740(void* list, P* p);
void fn_8017BA50(Unk8024EF40_Ctx* c, P* p, int a, int b);
void fn_802491D8(P* p);
void fn_80255314(A* self, int a, int b);
void fn_802553BC(A* self, int a);
void fn_801BD3BC(int a, int b);
void fn_801BCF88(int a, int b, int c);
void fn_802550A8(A* self, int a, int b);
}

struct Unk8025480C_Msg {
    int m0;
    const void* vptr;
    int m8;
    P* mC;
    void Base(int id)
    {
        vptr = lbl_80649DA0;
        m0 = id;
    }
    void Derived(int a, P* b)
    {
        vptr = lbl_80660EC0;
        m8 = a;
        mC = b;
    }
};

void fn_802547C0(A* self, int a)
{
    self->m2C = fn_80254EA4(&self->m0->m58C, 0);
    self->b2 = a;
}

void fn_8025480C(A* self, int a)
{
    if (a == -1) {
        int t = self->m34;
        if (t >= 0) {
            if (t <= 2) {
                if (!self->b2) {
                    Unk8025480C_Msg m;
                    m.Base(0x63);
                    m.Derived(t, self->m0);
                    fn_8037893C(self->m0->m44C->m704, m.m0, &m, 0, 0);
                    fn_8035E214(&m, 2);
                }
            }
        }
    }
    self->m34 = a;
}

void fn_802548BC(A* self, int a)
{
    if (a != 0)
        fn_8035E318(self);
    else
        fn_8014E374(self->m38);
}

int fn_802548F0(A* self)
{
    int r = 0;
    P* p = self->m0;
    if (p != 0 && p->m458 == 9) {
        A* a = &p->m58C;
        if (a->m38 == 0 && a->m30 == 0 && fn_8026D730(p, 0) != 0)
            r = 1;
    }
    return r;
}

int fn_80254964(A* self)
{
    int r = 0;
    int t = self->m44;
    int lo = 1, hi = 2;
    if (t == lo || t == hi)
        r = 1;
    return r;
}

int fn_80254984(A* self)
{
    if (self->b2 || fn_80254964(self) || self->m0->m264 != 0)
        return 0;
    P* p = self->m0;
    if (p->m458 == 9) {
        int c = p->m44C->m700->m3BC;
        if (fn_801BBEFC(c) == 0 && fn_801BBF04(c) == 0 && fn_8017C94C(self->m0->m44C->m700) == 0)
            return 0;
    }
    return 1;
}

int fn_80254A34(A* self)
{
    int r;
    if (fn_80254984(self)) {
        r = 1;
        if (self->m34 == -1)
            r = fn_802548F0(self) == 0;
    } else {
        r = 0;
    }
    return r;
}

int fn_80254A90(A* self)
{
    if ((fn_80254A34(self) == 1 || fn_80254964(self) != 0) && !self->b2) {
        float t = self->m8;
        if (!(t > 0.0f))
            return 1;
        const float lo = 0.4f;
        float d = Secs(self->m0->m44C) - t;
        if (d < lo)
            return 1;
    }
    return 0;
}

int fn_80254B60(A* self)
{
    if (fn_80254A34(self) != 0 && (self->m8 == 0.0f || self->m30 != self->m3C) && self->m40 == -1)
        return fn_80257458(self->m0->m44C->m700->m3B4, (P*)((char*)self - 0x58C)) == 0;
    return 0;
}

void fn_80254DA4(A* self, int a)
{
    P* p = self->m0;
    if (fn_8014E310(p->m458) >= 0 && a != self->b0) {
        Unk8024EF40_Q* q = self->m0->m44C;
        if (q != 0) {
            int t = self->m0->m708;
            int idx;
            if (t > 2) {
                idx = 3;
                if (t == 3)
                    idx = 4;
            } else {
                idx = t == 0;
            }
            Unk8024EF40_Pos* pos = (Unk8024EF40_Pos*)fn_801A497C(q, idx, 0);
            if (pos != 0) {
                void* y = q->m6F8->m14;
                if (y != 0 && self->m0->m458 == 9) {
                    int f = 1;
                    if (a == 0)
                        f = 0;
                    unsigned char c = pos->m70C;
                    fn_80081C94(y, fn_8014E310(9), self->m0->m70C, c, f);
                }
            }
        }
    }
    self->b0 = a;
}

int fn_80254EA4(A* self, int a)
{
    int r = -1;
    if (!self->b2) {
        P* p = self->m0;
        if (p != 0 && (unsigned)(p->m458 - 9) <= 3) {
            int f = 0;
            if (a != 0 || fn_801BBEFC(p->m44C->m700->m3BC) != 0 || fn_8017C94C(self->m0->m44C->m700) != 0)
                f = 1;
            if (f != 0) {
                unsigned t = self->m34;
                if (t <= 2) {
                    r = t;
                } else {
                    int n = fn_8014E310(self->m0->m458 + 1);
                    if (self->m38 >= n) {
                        r = -1;
                    } else {
                        P* q = self->m0;
                        if (q->m458 != 9) {
                            void* list = q->m44C->m700->m3B4;
                            for (;;) {
                                P* nx = fn_80257BD0(list, q, 1);
                                if (nx == 0 || nx->m58C.b2)
                                    break;
                                if (nx->m458 == 9) {
                                    r = n;
                                    break;
                                }
                                q = nx;
                            }
                        } else {
                            r = n;
                        }
                    }
                }
            }
        }
    }
    return r;
}

void fn_80254FD8(A* self, float f)
{
    self->m48 = Secs(self->m0->m44C) + f;
}

void fn_80255028(A* self)
{
    P* p = self->m0;
    Unk8024EF40_Ctx* c = p->m44C->m700;
    fn_80258740(c->m3B4, p);
}

void fn_80255058()
{
}

void fn_8025505C(A* self, int a, int b)
{
    self->m38 = a;
    fn_80255314(self, a, b);
    P* p = self->m0;
    fn_8017BA50(p->m44C->m700, p, a, 7);
}

/* near-miss: retail has the p = n / q reload at the loop top and the call as loop test; ours rotates the test (34 vs 36 instructions) */
int fn_80255284(A* self, int a)
{
    int r = 0;
    P* p = self->m0;
    P* n;
    while ((n = fn_80257DFC(self->m0->m44C->m700->m3B4, p, 0)) != 0) {
        A* na = &n->m58C;
        if (fn_80254984(na) && na->m3C == a) {
            r = 1;
            break;
        }
        p = n;
    }
    return r;
}

void fn_80255314(A* self, int a, int b)
{
    P* p = self->m0;
    if ((unsigned)(p->m458 - 9) <= 3) {
        if (fn_80255284(self, a) == 0) {
            int old = self->m38;
            self->m3C = a;
            self->m38 = a;
            if (self->m0->m458 == 9 && old == -1 && a == 0)
                fn_802491D8(self->m0);
            if (b != 0 && old != a)
                fn_802550A8(self, a, old);
        }
    } else {
        p->m730 = a;
    }
}

void fn_802554BC(A* self, int a, int b)
{
    if (a != 0) {
        if (self->mC == 0.0f && self->m24 == 0) {
            self->mC = Secs(self->m0->m44C) + self->m50->m4;
            self->m10 = b;
            self->m24 = 1;
        }
    } else {
        self->mC = 0.0f;
        self->m10 = -1;
    }
}

void fn_80255554(A* self)
{
    if (self->mC != 0.0f) {
        if (!(Secs(self->m0->m44C) <= self->mC)) {
            fn_802554BC(self, 0, -1);
            fn_802553BC(self, 1);
        }
    }
}

float fn_802555EC(A* self)
{
    if (self->mC != 0.0f)
        return self->mC - self->m50->m4;
    return -1.0f;
}

void fn_8025561C(A* self, int a)
{
    if (a != 0) {
        if (self->m14 == 0.0f && self->m24 == 0) {
            self->m14 = Secs(self->m0->m44C) + self->m50->m4;
            self->m24 = 1;
        }
    } else {
        self->m14 = 0.0f;
    }
}

/* near-miss: only register choice of the loads from Q (r5/r10/r11) differs */
void fn_802556A8(A* self)
{
    if (self->m14 != 0.0f) {
        Unk8024EF40_Q* q = self->m0->m44C;
        if (!(Secs(q) <= self->m14) && self->m8 == 0.0f) {
            fn_801BD3BC(q->m700->m3BC, q->m6CC->m36C);
            fn_8025561C(self, 0);
        }
    }
}

float fn_80255754(A* self)
{
    if (self->m14 != 0.0f)
        return self->m14 - self->m50->m4;
    return -1.0f;
}

void fn_80255784(A* self, int a, int b, int c)
{
    if (a != 0) {
        if (self->m18 == 0.0f && self->m24 == 0) {
            self->m18 = Secs(self->m0->m44C) + self->m50->m4;
            self->m1C = b;
            self->m20 = c;
            self->m24 = 1;
        }
    } else {
        self->m18 = 0.0f;
        self->m1C = -1;
        self->m20 = 0;
    }
}

void fn_8025582C(A* self)
{
    if (self->m18 != 0.0f) {
        if (!(Secs(self->m0->m44C) <= self->m18)) {
            int x = self->m1C;
            int y = self->m20;
            fn_80255784(self, 0, -1, 0);
            fn_801BCF88(self->m0->m44C->m700->m3BC, x, y);
        }
    }
}

float fn_802558E0(A* self)
{
    if (self->m18 != 0.0f)
        return self->m18 - self->m50->m4;
    return -1.0f;
}

void fn_80255910(A* self)
{
    self->m24 = 0;
    fn_80255784(self, 0, -1, 0);
    fn_802554BC(self, 0, -1);
    fn_8025561C(self, 0);
}

void fn_8025596C(A* self, int a)
{
    self->m28 = a;
}

struct Unk80256978_S84 {
    char pad0[0x84];
    int m84;
};
struct Unk80256980_S8 {
    int m0;
    int m4;
    int m8;
};
struct Unk80256990_S658 {
    char pad0[0x658];
    int m658;
};
struct Unk80256A88_SA08 {
    char pad0[0xA08];
    int mA08;
};
struct Unk80256B2C_S6D4 {
    char pad0[0x6D4];
    float m6D4[4];
};
struct Unk80256BE4_S71C {
    char pad0[0x71C];
    short m71C;
};
struct Unk80256C70_SAB4 {
    char pad0[0xAB4];
    float mAB4;
};

int fn_80256978(Unk80256978_S84* self)
{
    return self->m84;
}

int fn_80256980(Unk80256980_S8* self)
{
    return self->m8;
}

int fn_80256988(Unk80256980_S8* self)
{
    return self->m8;
}

void fn_80256990(Unk80256990_S658* self, int a)
{
    self->m658 = a;
}

void fn_80244858(float a);

void fn_80256998(float a, float b, float c)
{
    fn_80244858(b);
}

void fn_802569C8(float a)
{
    fn_80244858(a);
}

struct Unk802569F0_Ref {
    float m0;
    float m4;
};
void fn_802569F0(int self, Unk802569F0_Ref* p)
{
    fn_80244858(p->m4);
}

struct Unk80256A14_Vec3 {
    float m0;
    float m4;
    float m8;
};
struct Unk80256A14_S618 {
    char pad0[0x618];
    void* m618;
};
extern Unk80256A14_Vec3 lbl_806055AC;
float fn_80382BB8(void* p);

Unk80256A14_Vec3 fn_80256A14(Unk80256A14_S618* self)
{
    Unk80256A14_Vec3 v = lbl_806055AC;
    v.m4 = fn_80382BB8(self->m618);
    return v;
}

int fn_80256A88(Unk80256A88_SA08* self)
{
    return self->mA08;
}

void fn_80256A90(Unk80256A90_V* self)
{
    self->v23();
}

void fn_80256AC4(Unk80256A90_V* self)
{
    self->v4();
}

void fn_80256AF8(Unk80256A90_V* self)
{
    self->v4();
}

float fn_80256B2C(Unk80256B2C_S6D4* self, int i)
{
    return self->m6D4[i];
}

void fn_80256B3C(Unk80256B2C_S6D4* self, float v, int i)
{
    self->m6D4[i] = v;
}

void fn_80256B5C()
{
}

extern char lbl_806EF9C7;
extern char lbl_806EF9C8;
extern char lbl_806EF9C4;
extern char lbl_8061EC9C;
int fn_80256B60()
{
    return lbl_806EF9C7;
}

int fn_80256B70()
{
    return lbl_806EF9C8;
}

int fn_80256B80()
{
    return lbl_806EF9C4;
}

int fn_80256B90(int a, int b)
{
    return b;
}

int fn_80256B98(int a, int b)
{
    return b;
}

int fn_80256BA0()
{
    return lbl_8061EC9C;
}

void fn_80256BB0(Unk80256A90_V* self)
{
    self->v28();
}

int fn_80256BE4(Unk80256BE4_S71C* self)
{
    return self->m71C > 0;
}

void fn_80256BFC(Unk80256A90_V* self)
{
    self->v4();
}

void fn_80256C30(Unk80256A90_V* self)
{
    self->v5(1);
}

int* fn_80256C68(char* self)
{
    return (int*)(self + 0x8C);
}

float fn_80256C70(Unk80256C70_SAB4* self)
{
    return self->mAB4;
}

char* fn_80256C78(char* self)
{
    return self + 0x60;
}
