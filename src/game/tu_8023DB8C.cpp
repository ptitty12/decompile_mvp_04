/*
 * Game code, .text 0x8023DB8C-0x80241C24 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8023DB8C.h"

extern int lbl_8061D420[];
extern int lbl_8061E9F4;
void fn_802546E4(void* p);
int fn_80319330(void* p, int id);
void fn_8023EC24(Unk8023DB8C_P* p);
int fn_8023DDD0(Unk8023DB8C_P* p);
void fn_8023E448(Unk8023DB8C_P* p);
extern int lbl_8061B9C8;
int fn_8023EB94(Unk8023DB8C_P* p, int a, int b);
void fn_8024CA08(Unk8023DB8C_P* p);
struct Unk8023E348_V {
    float m0;
    float m4;
    float m8;
};
extern char lbl_806EF9C6;
void fn_80245828(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);

struct Unk8023E348_Sub {
    virtual void v1();
    virtual void v2(char c, Unk8023E348_V* out, int a, int b);
};
struct Unk8023E348_E {
    char pad0[0x36C];
    int m36C;
};
struct Unk8023E348_B {
    char pad0[0x450];
    Unk8023E348_E* m450;
    char pad454[0x5F4 - 0x454];
    float m5F4;
    int m5F8;
    int m5FC;
    int m600;
    int m604;
    int m608;
    int m60C;
    int m610;
    char pad614[0xAB8 - 0x614];
    char* mAB8;
};
struct Unk8023E348_A {
    char pad0[0x938];
    int m938;
};

struct Unk80240D7C_V {
    float m0;
    float m4;
};
struct Unk8024EF40_W;
int fn_8025416C(Unk8024EF40_W* self, int a);
float fn_80253F54(Unk8024EF40_W* self, int a, int b, int c);
int fn_80253F0C(Unk8024EF40_W* self, int a, int b, int c);

void fn_802C959C(void* p, int a);
void* fn_80179058(int a);

void fn_8023DB8C(Unk8023DB8C_P* p)
{
    fn_802546E4(p->m58C);
}

/* near-miss: 19 slots; retail derives the zero test from the first cmpwi via mfcr (rlwinm r11,r11,3,31,31),
 * ours recompares into cr7 (31 vs 30 insns in the first form, 30 vs 30 here) */
int fn_8023DDD0(Unk8023DB8C_P* p)
{
    int v = p->m44C->m6F8->m14->m1CD0;
    int f = 0;
    if (v != 0)
        f = 1;
    int z = f ^ 1;
    if (p->m264 != 0)
        return p->m708 == z;
    if (p->m708 == f || p->m458 == 14)
        return 0;
    return p->m458 != 1;
}

void fn_8023DE48(Unk8023DB8C_P* p)
{
    if (p->m458 == 9) {
        lbl_8061B9C8 = 1;
        ((Unk8023DE48_Q*)((char*)p + 0xA0))->v5();
    } else if (p->mB54 != 0) {
        lbl_8061B9C8 = 2;
        ((Unk8023DE48_Q*)((char*)p + 0xA0))->v5();
    }
}

void fn_8023DED0(Unk8023DB8C_P* p)
{
    if (p->m458 == 9) {
        lbl_8061B9C8 = 1;
        ((Unk8023DE48_Q*)((char*)p + 0xA0))->v5();
    } else if (p->mB54 == 0) {
        lbl_8061B9C8 = 2;
        ((Unk8023DE48_Q*)((char*)p + 0xA0))->v5();
    }
}

void fn_8023E348(Unk8023E348_A* a, Unk8023E348_B* b)
{
    if (!(b->m5F4 <= 0.0f)) {
        Unk8023E348_E* e = b->m450;
        if (e && e->m36C) {
            b->m5F4 = 0.0f;
            return;
        }
        b->m5F4 = b->m5F4 - 1.0f;
        a->m938 = 1;
        Unk8023E348_V v;
        ((Unk8023E348_Sub*)(b->mAB8 + 0xC))->v2(lbl_806EF9C6, &v, 0, 0);
        if (!(v.m4 >= 0.0f))
            v.m4 = 0.0f;
        fn_80245828((int)a, (int)&v, b->m5F8, b->m5FC, b->m600, b->m604, b->m608, b->m60C, b->m610, 1);
    }
}

struct Unk8023E448_V {
    float x;
    float y;
    float z;
};
struct Unk8023E448_N {
    Unk8023E448_N* m0;
    char pad4[0xC];
    int m10;
};
struct Unk8023E448_C {
    char pad0[0x6B8];
    int m6B8;
    char pad6BC[0x6F4 - 0x6BC];
    int m6F4;
};
struct Unk8023E448_P {
    char pad0[0x60];
    Unk8023E448_V m60;
    char pad6C[0x320 - 0x6C];
    Unk8023E448_V m320;
    char pad32C[0x44C - 0x32C];
    Unk8023E448_C* m44C;
    char pad450[8];
    int m458;
    char pad45C[0x624 - 0x45C];
    float m624;
    char pad628[0x708 - 0x628];
    unsigned m708;
    char pad70C[0x934 - 0x70C];
    Unk8023E448_N* m934;
};
inline Unk8023E448_V Pos8023E448(Unk8023E448_P* p)
{
    return p->m320;
}
void fn_80183A44(Unk8023E448_V* out, int a, unsigned b, int c);
int fn_801850B4(int a, Unk8023E448_V* out, unsigned b, float* z);

void fn_8023E448(Unk8023DB8C_P* pp)
{
    Unk8023E448_P* p = (Unk8023E448_P*)pp;
    Unk8023E448_V pos = p->m60;
    Unk8023E448_C* c = p->m44C;
    pos.y = 0.0f;
    float r = 0.0f;
    if (c->m6F4 != 1) {
        int s = p->m458;
        if (s == 15) {
            Unk8023E448_V out;
            fn_80183A44(&out, c->m6B8, p->m708, 0);
            r = out.y;
        } else if (s == 16) {
            if (pos.x > 0.0f || !(pos.z <= 0.0f)) {
                Unk8023E448_V out;
                fn_80183A44(&out, c->m6B8, p->m708, 2);
                r = out.y;
            }
        } else if (s == 13 || s == 17) {
            Unk8023E448_N* n = p->m934;
            int ok = 1;
            while (n) {
                if (n->m10 == 4) {
                    ok = 0;
                    break;
                }
                n = n->m0;
            }
            if (ok) {
                int res = 0;
                Unk8023E448_V out = Pos8023E448(p);
                pos = out;
                float z = 0.0f;
                Unk8023E448_C* cc = p->m44C;
                unsigned t = p->m708;
                int k = cc->m6B8;
                if (t <= 1 && k != 0) {
                    out = pos;
                    res = fn_801850B4(k, &out, t, &z);
                }
                if (res)
                    r = z;
            }
        } else if (s == 9) {
            r = -0.5f;
        }
        p->m624 = r;
    }
}

int fn_8023E604(Unk8023DB8C_P* p, int k)
{
    if (k == 9)
        return 1;
    Unk8023DB8C_Ctx* c = p->m44C;
    if (c) {
        Unk8023DB8C_Outer* o = c->m700;
        if (o) {
            int t = o->m3AC;
            if (t) {
                if (fn_80179058(t) == p)
                    return 1;
            }
        }
    }
    return 0;
}

int fn_8023EB80(void* p, int i)
{
    return lbl_8061D420[i];
}

int fn_8023EB94(Unk8023DB8C_P* p, int a, int b)
{
    int v = 0;
    Unk8023DB8C_Ctx* c = p->m44C;
    if (c == 0 || c->m6F4 == 1) {
        int k = p->m458;
        if (k == 9) {
            v = a;
            if (v == 2)
                v = 1;
        } else if (k == 1)
            v = 0;
        else
            v = b;
    }
    return v == 1;
}

int fn_8023EBF4(Unk8023DB8C_P* p, int i)
{
    if (i <= 6) {
        if (i < 0)
            i = 0;
    } else
        i = 6;
    return ((Unk8023DB8C_Flags*)((char*)p + i * 32 + 0xD0))->m4;
}

struct Unk8023ECD4_V {
    float m0;
    float m4;
    float m8;
};

void fn_8023EC24(Unk8023DB8C_P* p)
{
    int r = 0;
    Unk8023DB8C_Ctx* c = p->m44C;
    fn_8024CA08(p);
    if (c) {
        if (c->m6F4 == 1) {
            r = fn_8023EB94(p, p->m9FC, p->mA00);
        } else {
            if (p->m458 != 15) {
                int f = 0;
                if (c->m6F8->m14->m1CD0 != 0)
                    f = 1;
                if (f == p->m708)
                    r = p->m9FC == 1;
                else
                    r = p->mA00 == 1;
            } else
                r = p->mA00 == 1;
        }
    }
    p->mA08 = r;
}

void fn_8023ECD4(Unk8023DB8C_P* p, int idx, Unk8023ECD4_V* out)
{
    Unk8023DB8C_Ctx* c = p->m44C;
    out->m8 = 0.0f;
    out->m4 = 0.0f;
    out->m0 = 0.0f;
    if (c) {
        int best = 4;
        Unk8023DB8C_Slot* bs = 0;
        for (int i = 0; i < 6; i++) {
            Unk8023DB8C_Slot* s = p->m628[i];
            if (s) {
                int t = s->m460;
                if (t < best) {
                    best = t;
                    bs = s;
                }
            }
        }
        if (bs)
            *out = *(Unk8023ECD4_V*)((char*)bs + idx * 12 + 0x470);
    }
}

struct Unk8023F29C_O {
    char pad0[0x618];
    void* m618;
};

float fn_80382BB8(void* p);
float fn_8041171C(float x);
float fn_80411554(float x);

inline Unk8023ECD4_V Direction(float angle)
{
    Unk8023ECD4_V r;
    r.m0 = fn_8041171C(angle);
    r.m4 = 0.0f;
    r.m8 = fn_80411554(angle);
    return r;
}

int fn_8023F0FC(Unk8023DB8C_P* p)
{
    if (p->mB58 == 0)
        p->mB58 = fn_80319330(p->m244, 0x18);
    return p->mB58;
}

int fn_8023F144(Unk8023DB8C_P* p)
{
    if (p->mB5C == 0)
        p->mB5C = fn_80319330(p->m244, 0x19);
    return p->mB5C;
}

int fn_8023F18C(Unk8023DB8C_P* p)
{
    if (p->mB60 == 0)
        p->mB60 = fn_80319330(p->m244, 0x1A);
    return p->mB60;
}

int fn_8023F1D4(Unk8023DB8C_P* p)
{
    return (p->m39C >> 22) <= 900;
}

int fn_8023F1EC(Unk8023DB8C_P* p)
{
    if (p->m458 == 17)
        return 0;
    Unk8024EF40_W* w = (Unk8024EF40_W*)((char*)p + 0x588);
    if ((unsigned)(fn_8025416C(w, 0x16) - 3) <= 1)
        return 1;
    float f = fn_80253F54(w, 0, 2, 0);
    return !(f > 2.0f) ? fn_80253F0C(w, 1, 2, 0) > 2 : 1;
}

void fn_8023F298() {}

Unk8023ECD4_V* fn_8023F29C(Unk8023ECD4_V* out, Unk8023F29C_O* o)
{
    float a = fn_80382BB8(o->m618);
    *out = Direction(a);
    return out;
}

struct Unk8024015C_V {
    float x;
    float y;
    float z;
};
struct Unk8024015C_R {
    char pad0[0x60];
    Unk8024015C_V m60;
};
class Unk8024015C_B {
public:
    char pad0[0x98];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Unk8024015C_R* v6();
};
struct Unk8019F8C0_Owner;
void* fn_801A04A8(Unk8019F8C0_Owner* o, int i);
void fn_8031EE20(Unk8024015C_V* out, void* m, Unk8024015C_V* in);
float fn_80313F28(int h, int id);
void fn_80303BC4(int id, float a, float b, ...);
extern int lbl_8061FEDC;
extern float lbl_805D8F5C;
extern float lbl_805D8F60;

void fn_8024015C(Unk8023DB8C_P* p, int n, int* ids, int flag, float x, float y)
{
    Unk8019F8C0_Owner* o = (Unk8019F8C0_Owner*)p->m44C;
    Unk8024015C_V pos = ((Unk8024015C_B*)p)->v6()->m60;
    if (n > 0) {
        Unk8024015C_V out;
        fn_8031EE20(&out, fn_801A04A8(o, 1), &pos);
        for (int i = 0; i < n; i++) {
            Unk8024015C_V t = out;
            int h = lbl_8061FEDC;
            float* q = &lbl_805D8F5C;
            if (flag)
                t.x -= fn_80313F28(h, ids[i]) * lbl_805D8F60;
            fn_80303BC4(ids[i], t.x, t.y);
            out.y += *q;
        }
    }
}

void fn_80240D3C(Unk8023DB8C_P* p)
{
    fn_8023EC24(p);
    p->mB54 = fn_8023DDD0(p);
    fn_8023E448(p);
}

void fn_80240D7C(Unk8023DB8C_P* p, int k, Unk80240D7C_V* v, Unk8023DB8C_Slot* s)
{
    int b = v->m4 < -2.0f;
    int a = v->m0 <= 0.0f;
    switch (k) {
    case 1:
        p->m6C4[s->m460] = 0;
        break;
    case 15:
    case 16:
        p->m6C4[s->m460] = 1;
        break;
    default:
        if (b) {
            if (a)
                p->m6C4[s->m460] = 2;
            else
                p->m6C4[s->m460] = 3;
        } else
            p->m6C4[s->m460] = 0;
        break;
    }
}

void fn_802413A8(Unk8023DB8C_P* p, Unk8023DB8C_Slot* s)
{
    for (int i = 0; i < 6; i++) {
        if (p->m628[i] == s) {
            p->m628[i] = 0;
            s->m46C = s->m46C - 1;
        }
    }
    fn_802C959C(s, 0);
}

/* near-miss: retail keeps the zero in r27 (li r27,0 before the compare) and reuses r27 as the loop counter; ours loads r0 after the branch */
void fn_8024140C(Unk8023DB8C_P* p, Unk8023DB8C_Slot* s)
{
    int z = 0;
    if (p->m628[12] == s) {
        p->m628[12] = (Unk8023DB8C_Slot*)z;
        for (int i = 0; i < 6; i++) {
            Unk8023DB8C_Slot* q = p->m628[i];
            if (q) {
                fn_802C959C(q, 0);
                p->m628[i] = 0;
                q->m46C = q->m46C - 1;
            }
        }
    }
}

void fn_8024148C(Unk8023DB8C_P* p, int i)
{
    p->m6A4[i] = 1;
}

int fn_802419E0(Unk8023DB8C_P* p, int i)
{
    if (i != -1) {
        Unk8023DB8C_Slot* s = p->m628[i];
        int r = 4;
        if (s) {
            if (s->m448[i] == lbl_8061E9F4)
                r = s->m460;
        }
        return r;
    }
    return p->m6BC;
}

int fn_80241A2C(Unk8023DB8C_P* p)
{
    return p->m6C0;
}

/* near-miss: retail special-cases the first slot (cmpwi r0,4) and walks the rest with an index; ours compiles a bdnz loop (19 vs 24 insns) */
int fn_80241A34(Unk8023DB8C_P* p)
{
    int r = 4;
    for (int i = 0; i <= 5; i++) {
        Unk8023DB8C_Slot* s = p->m628[i];
        if (s) {
            int t = s->m460;
            if (t < r) {
                r = t;
                if (r == 0)
                    return r;
            }
        }
    }
    return r;
}
