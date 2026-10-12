/*
 * Game code, .text 0x801A96E0-0x801AB63C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801A96E0.h"
#include "game/tu_801A57C8.h"
#include "game/tu_801AB63C.h"
#include "game/clampiter.h"

void fn_801AA088(void* p);
void fn_801AB49C(void* p);
void fn_801AA284(void* p);
void fn_801AA570(void* p);
void fn_801AB2EC(void* p);
void fn_801AB188(void* p, int v);
void fn_801AB470(void* p);
extern float lbl_805CEEF8;
extern int lbl_80620388;
extern unsigned lbl_80620394[];
int fn_801A96A8(int x);
extern "C" int fn_801A9D9C(Unk801A96E0_Init* o, int i);
int fn_801A9E98(Unk801A96E0_Init* o);
int fn_801B5F8C(Unk801AB63C_P* p);
int fn_801AB0D8(Unk801AB63C_P* p);
int fn_801AAC4C(Unk801AB63C_P* p);
int fn_801AAE28(Unk801AB63C_P* p);
int fn_801AAE10(Unk801AB63C_P* p);
int fn_801AAE18(Unk801AB63C_P* p);
int fn_801AAE20(Unk801AB63C_P* p);
int fn_801AB130(Unk801AB63C_P* p);
int fn_801AB000(Unk801AB63C_P* p);
int fn_801AAEF4(Unk801AB63C_P* p);
inline int Unk801A96E0_U8(Unk8019F8C0_Inner* a, int off)
{
    return *((unsigned char*)a + off);
}
int fn_801B5AD0(Unk801AB63C_P* p, int i);
int fn_801B5F4C(Unk801AB63C_P* p);
int fn_801B5F70(Unk801AB63C_P* p);
int fn_801B5FC4(Unk801AB63C_P* p, int i);
int fn_801C1638(Unk8019F8C0_Owner* o, int i);
extern float lbl_805CEEFC;
extern float lbl_805CEF08;
int fn_801AB460(Unk801A96E0_Init* o, int i);
extern unsigned lbl_8062038C;
extern unsigned lbl_80620390;
extern unsigned lbl_806203A4;
extern unsigned lbl_806203A8;
int fn_801A9B78(Unk801A96E0_Sel* a, int b);
int fn_801A9B90(Unk801A96E0_Sel* a, int b);
int fn_801A9BA8(Unk801A96E0_Sel* a, int b);
int fn_801A9BC0(Unk801A96E0_Sel* a, int b, int c);
int fn_801A99B4(Unk801A96E0_Init* o);
int fn_801A9A20(Unk801A96E0_Init* o);
int fn_801A9A8C(Unk801A96E0_Init* o);
void fn_801A9684(void* p);
void fn_801AA038(void* p, int n);
void fn_801AA284(void* p, int n);
void fn_801AB5CC(void* p);

/* Object seen by fn_801AB5CC: a Unk801B2490 with two cleared pair tables at +0x60 and +0x74. */
struct Unk801AB338_Q {
    char pad0[0x5D8];
    float m5D8;
};
Unk801AB338_Q* fn_801B6438(Unk801AB63C_P* p, int id);
extern float lbl_805CEEF0;
extern float lbl_805CEEF4;
struct Unk801AE30C_Clr {
    int m0;
    Unk801AB63C_E m4[2];
    Unk801AE30C_Clr();
};
void fn_801AE360(Unk801AE30C_Clr* p);
struct Unk801AB5CC_Obj {
    char pad0[0xC];
    int mC;
    int m10;
    char pad14[0x5C - 0x14];
    int m5C;
    Unk801AE30C_Clr m60;
    Unk801AE30C_Clr m74;
};
/* Result object of fn_801B63A0 as the float probe fn_8024F048 sees it. */
struct Unk801AB0D8_Q {
    char pad0[0x44C];
    void* m44C;
    char pad450[0x5D8 - 0x450];
    float m5D8;
    char pad5DC[0x708 - 0x5DC];
    int m708;
    char pad70C[0xA04 - 0x70C];
    void* mA04;
    char padA08[4];
    char mA0C[4];
};
/* The same object with its vptr at +0x98 (virtual 24 returns a state code). */
class Unk801AAEF4_VB {
public:
    char pad0[0x98];
};
class Unk801AAEF4_V : public Unk801AAEF4_VB {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual int fn_vslot24();
};
class Unk801AAEF4_Q : public Unk801AAEF4_V {
public:
    char pad9C[0x44C - 0x9C];
    void* m44C;
    char pad450[0x5D8 - 0x450];
    float m5D8;
    char pad5DC[0x708 - 0x5DC];
    int m708;
    char pad70C[0xA04 - 0x70C];
    void* mA04;
    char padA08[4];
    char mA0C[4];
};
Unk801AB0D8_Q* fn_801B63A0(Unk801AB63C_P* p, int t);
float fn_8024EF40(void* t, void* a, int b);
extern const float lbl_805CEED0;
extern const float lbl_805CEED4;
extern const float lbl_805CEED8;
extern const float lbl_805CEEDC;
extern const float lbl_805CEEE0;
float fn_8024F048(void* a, void* b, void* c, int d, int e);
float fn_8024F20C(void* a, void* b, void* c, int d, int e);
extern float lbl_805CEEE4;
int fn_801B5B18(Unk801AB63C_P* p, int a, int b);
int fn_80253678(int v);
float fn_80254474(void* t, int a, int b);
float fn_8025454C(void* t, int a);
extern float lbl_805CEEC8;
extern float lbl_805CEECC;
extern float lbl_805CEEE8;
extern float lbl_805CEEEC;
extern float lbl_805CEDE8;

struct Unk801A9CFC_T {
    char pad0[0x38];
    int m38[1];
};

struct Unk801A9D0C_T {
    char pad0[0x40];
    int m40[1];
};

struct Unk801A9D1C_T {
    char pad0[0x48];
    int m48[1];
};

struct Unk801A9D2C_T {
    char pad0[0x50];
    int m50[1];
};

struct Unk801AB460_T {
    char pad0[0x2C];
    int m2C[1];
};
int fn_801AB460(Unk801AB460_T* p, int i);
void fn_801AB338(Unk801A96E0_Init* o);
void fn_801AB188(Unk801A96E0_Init* p, int v);

void fn_801A96E0(void* p)
{
    fn_801A9684(p);
}

void fn_801A9700(void* p)
{
    fn_801AA038(p, 0);
}

extern char lbl_80649DA0[];
extern char lbl_8065FC90[];
int fn_801A9AF8(Unk801A96E0_Init* o);
void fn_801AA598(void* p);
void fn_8037893C(void* a, int b, void* c, void* d, int e);
void fn_8035AD88(void* self, int c);
/* Stack message (id at +0, vptr at +4: root vtable, then the derived one); four before/after pairs. */
struct Unk801A9724_Base {
    int m0;
    const void* m4;
    Unk801A9724_Base(int id)
    {
        m4 = lbl_80649DA0;
        m0 = id;
    }
};
struct Unk801A9724_Msg : public Unk801A9724_Base {
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    Unk801A9724_Msg(int a0, int a1, int a2, int a3, int b0, int b1, int b2, int b3) : Unk801A9724_Base(0x92)
    {
        m4 = lbl_8065FC90;
        m8 = 0;
        mC = a0;
        m14 = a1;
        m1C = a2;
        m24 = a3;
        m10 = b0;
        m18 = b1;
        m20 = b2;
        m28 = b3;
    }
};

void fn_801A9724(Unk801A96E0_Init* o)
{
    int a0 = fn_801A99B4(o);
    int a1 = fn_801A9A20(o);
    int a2 = fn_801A9A8C(o);
    int a3 = fn_801A9AF8(o);
    fn_801AA598(o);
    int b0 = fn_801A99B4(o);
    int b1 = fn_801A9A20(o);
    int b2 = fn_801A9A8C(o);
    int b3 = fn_801A9AF8(o);
    if (a0 != b0 || a1 != b1 || a2 != b2 || a3 != b3) {
        Unk801A9724_Msg msg(a0, a1, a2, a3, b0, b1, b2, b3);
        fn_8037893C((char*)o->m8 + 0x704, msg.m0, &msg, 0, 0);
        fn_8035AD88(&msg, 2);
    }
    o->m58 = b0;
    o->m5C = b1;
    o->m60 = b2;
    o->m64 = b3;
    fn_801AB470((Unk801A96E0_Late*)o);
}

void fn_801A985C(void* p)
{
    fn_801AB470(p);
}

void fn_801A987C(void* p)
{
    fn_801AA038(p, 0);
}

void fn_801A98A0(void* p)
{
    fn_801AA284(p, 1);
}

void fn_801A9980(void* p)
{
    fn_801AA088(p);
    fn_801AB49C(p);
}

int fn_801A99B4(Unk801A96E0_Init* o)
{
    if (lbl_80620388 == 1) {
        unsigned v = lbl_8062038C;
        if (v > 1) {
            return v;
        }
    }
    int f = o->m8->m6F8->m14[2].m8 == 0;
    return fn_801A9B78((Unk801A96E0_Sel*)o, o->m38[f]);
}

int fn_801A9A20(Unk801A96E0_Init* o)
{
    if (lbl_80620388 == 1) {
        unsigned v = lbl_80620390;
        if (v > 1) {
            return v;
        }
    }
    int f = o->m8->m6F8->m14[2].m8 == 0;
    return fn_801A9B90((Unk801A96E0_Sel*)o, o->m40[f]);
}

int fn_801A9A8C(Unk801A96E0_Init* o)
{
    if (lbl_80620388 == 1) {
        unsigned v = lbl_806203A4;
        if (v > 1) {
            return v;
        }
    }
    int f = o->m8->m6F8->m14[2].m8 == 0;
    return fn_801A9BA8((Unk801A96E0_Sel*)o, o->m48[f]);
}

int fn_801A9AF8(Unk801A96E0_Init* o)
{
    if (lbl_80620388 == 1) {
        unsigned v = lbl_806203A8;
        if (v > 1) {
            return v;
        }
    }
    int f = o->m8->m6F8->m14[2].m8 == 0;
    int a = fn_801A9A8C(o);
    return fn_801A9BC0((Unk801A96E0_Sel*)o, a, o->m50[f]);
}

int fn_801A9B78(Unk801A96E0_Sel* a, int b)
{
    if (b == 1) {
        return a->mC;
    }
    return b;
}

int fn_801A9B90(Unk801A96E0_Sel* a, int b)
{
    if (b == 1) {
        return a->m10;
    }
    return b;
}

int fn_801A9BA8(Unk801A96E0_Sel* a, int b)
{
    if (b == 1) {
        return a->m24;
    }
    return b;
}

int fn_801A9BC0(Unk801A96E0_Sel* a, int b, int c)
{
    if (b != 0xb) {
        if (c != 1) {
            return c;
        }
        return a->m28;
    }
    return 2;
}

unsigned fn_801A9BE8(Unk801A96E0_Init* o, int x)
{
    unsigned t = x - 2;
    int r = 1;
    if (t <= 3) {
        unsigned v;
        if (lbl_80620388 == 1 && (v = lbl_80620394[fn_801A96A8(x)]) > 1) {
            return v;
        }
        r = o->m14[t];
        if (r <= 2 && o->m68 == 1) {
            volatile int c = 0;
            int idx = -1;
            int i = 0;
            do {
                if (fn_801A9D9C(o, i) == x) {
                    idx = c;
                }
                int w = c;
                int n;
                if (w > 3) {
                    n = w;
                } else {
                    n = w + 1;
                }
                c = n;
                i = n;
            } while (i <= 3);
            if (idx != -1 && idx <= 2 && (o->m6C == -1 || o->m6C == idx) && fn_801AB460(o, idx) != 0) {
                r = 3;
            }
        }
    }
    return r;
}

void fn_801A9CFC(Unk801A9CFC_T* p, int i, int v)
{
    p->m38[i] = v;
}

void fn_801A9D0C(Unk801A9D0C_T* p, int i, int v)
{
    p->m40[i] = v;
}

void fn_801A9D1C(Unk801A9D1C_T* p, int i, int v)
{
    p->m48[i] = v;
}

void fn_801A9D2C(Unk801A9D2C_T* p, int i, int v)
{
    p->m50[i] = v;
}

void fn_801A9D3C(Unk801A96E0_Pair* p, int a, int b)
{
    p->m70 = a;
    p->m74 = b;
}

void fn_801A9D48(Unk801A96E0_Late* p, int v)
{
    if (p->m78 != v) {
        p->m78 = v;
        p->m7C = (float)(unsigned)p->m8->m4C * lbl_805CEDE8;
    }
}

extern "C" int fn_801A9D9C(Unk801A96E0_Init* o, int i)
{
    int r = 0;
    switch (i) {
    case 0:
        r = 2;
        break;
    case 1:
        r = fn_801A9E98(o);
        break;
    case 2:
        r = 4;
        break;
    case 3:
        r = 1;
        break;
    }
    return r;
}

int fn_801A9E0C(Unk801A96E0_Init* o, int i)
{
    int r = -1;
    switch (i) {
    case 1:
        r = 3;
        break;
    case 2:
        r = 0;
        break;
    case 3:
    case 5:
        if (fn_801A9E98(o) == i) {
            r = 1;
        }
        break;
    case 4:
        r = 2;
        break;
    }
    return r;
}

void fn_801AA038(void* p)
{
    fn_801AA284(p);
    fn_801AA570(p);
    fn_801AB2EC(p);
    fn_801AB188(p, 0);
    fn_801AB470(p);
}

struct Unk8017A930_T;
void fn_8017B434(Unk8017A930_T* t);
struct Unk801AA088_Msg : public Unk801A9724_Base {
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    Unk801AA088_Msg(Unk801A96E0_Init* o, int b0, int b1, int b2, int b3) : Unk801A9724_Base(0x92)
    {
        int v58 = o->m58;
        int v64 = o->m64;
        int v5C = o->m5C;
        int v60 = o->m60;
        m4 = lbl_8065FC90;
        m8 = 1;
        m10 = b0;
        m14 = v5C;
        m18 = b1;
        m1C = v60;
        m20 = b2;
        m24 = v64;
        m28 = b3;
        mC = v58;
    }
};

void fn_801AA088(void* p)
{
    Unk801A96E0_Init* o = (Unk801A96E0_Init*)p;
    int f0 = 0;
    int f1 = 0;
    int f2 = 0;
    int f3 = 0;
    int b0 = fn_801A99B4(o);
    int b1 = fn_801A9A20(o);
    int b2 = fn_801A9A8C(o);
    int b3 = fn_801A9AF8(o);
    if (b0 != o->m58 && b0 != 0 && o->m58 != 0) {
        f0 = 1;
    }
    if (b1 != o->m5C && b1 != 0 && o->m5C != 0) {
        f1 = 1;
    }
    if (b2 != o->m60 && b2 != 0 && o->m60 != 0) {
        f2 = 1;
    }
    if (b3 != o->m64 && b3 != 0 && o->m64 != 0) {
        f3 = 1;
    }
    if (f0 == 1 || f1 == 1 || f2 == 1 || f3 == 1) {
        fn_8017B434(*(Unk8017A930_T**)((char*)o + 4));
        Unk801AA088_Msg msg(o, b0, b1, b2, b3);
        fn_8037893C((char*)o->m8 + 0x704, msg.m0, &msg, 0, 0);
        fn_8035AD88(&msg, 2);
    }
    o->m58 = fn_801A99B4(o);
    o->m5C = fn_801A9A20(o);
    o->m60 = fn_801A9A8C(o);
    o->m64 = fn_801A9AF8(o);
}

void fn_801AA248(Unk801A96E0_Init* p)
{
    for (int i = 0; i < 2; i++) {
        p->m38[i] = 2;
        p->m48[i] = 2;
        p->m40[i] = 2;
        p->m50[i] = 2;
    }
}

void fn_801AA570(Unk801A96E0_Init* p)
{
    p->mC = 0;
    p->m10 = 0;
    p->m24 = 0;
    p->m28 = 0;
    p->m58 = 0;
    p->m5C = 0;
    p->m60 = 0;
    p->m64 = 0;
}

int fn_801AABC4(Unk801AB63C_P* p);
int fn_801AACE4(Unk801AB63C_P* p);
int fn_801AAD40(Unk801AB63C_P* p);

int fn_801AA800(Unk801AB63C_P* p)
{
    int r = 0;
    if (fn_801AABC4(p) == 1) {
        r = 9;
    }
    if (r == 0) {
        if (fn_801AAD40(p) != 0) {
            int t = fn_801C1638(p->m8, 0xB);
            int c = 1;
            if (t == 0) {
                c = 0;
            }
            if (c != 0) {
                r = 0xE;
            } else if (fn_801B5AD0(p, 2) == 1) {
                r = 0xD;
            } else {
                r = 0xC;
            }
        }
        if (r == 0) {
            if (fn_801AACE4(p) == 1) {
                r = 0xA;
                if (fn_801B5AD0(p, 2) == 1) {
                    r = 0xB;
                }
            }
            if (r == 0) {
                if (fn_801AAE10(p) == 1) {
                    r = 0xF;
                    if (fn_801B5AD0(p, 2) == 1) {
                        r = 0x10;
                    }
                }
                if (r == 0) {
                    if (fn_801AAE18(p) == 1) {
                        r = 8;
                    }
                    if (r == 0) {
                        if (fn_801AAE20(p) == 1) {
                            r = 6;
                            if (fn_801B5AD0(p, 2) == 1) {
                                r = 7;
                            }
                        }
                        if (r == 0) {
                            if (fn_801AAE28(p) == 1) {
                                r = 4;
                                if (fn_801B5AD0(p, 2) == 1) {
                                    r = 5;
                                }
                            }
                            if (r == 0) {
                                r = 2;
                                if (fn_801B5AD0(p, 2) == 1) {
                                    r = 3;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return r;
}

int fn_801AA9B0(Unk801AB63C_P* p)
{
    int r = 2;
    if ((unsigned)(p->mC - 0xc) > 2) {
        if (fn_801AB000(p) == 1) {
            r = 4;
            if (fn_801B5AD0(p, 2) == 1) {
                r = 5;
            }
        }
    }
    if (r == 2 && fn_801AAEF4(p) == 1) {
        r = 3;
    }
    return r;
}

int fn_801AAA34(Unk801AB63C_P* p)
{
    int r = 0;
    if (fn_801AAC4C(p) == 1) {
        r = 0xb;
    }
    if (r == 0) {
        if (fn_801AAE10(p) == 1) {
            r = 0xc;
            if (fn_801B5AD0(p, 2) == 1) {
                r = 0xd;
            }
        }
    }
    if (r == 0) {
        if (fn_801AAE18(p) == 1) {
            r = 8;
            if (fn_801B5AD0(p, 2) == 1) {
                r = 9;
            }
        }
    }
    if (r == 0) {
        if (fn_801AAE20(p) == 1) {
            r = 6;
            if (fn_801B5AD0(p, 2) == 1) {
                r = 7;
            }
        }
    }
    if (r == 0) {
        if (fn_801AAE28(p) == 1) {
            r = 4;
            if (fn_801B5AD0(p, 2) == 1) {
                r = 5;
            }
        }
    }
    if (r == 0) {
        r = 2;
        if (fn_801B5AD0(p, 2) == 1) {
            r = 3;
        }
    }
    return r;
}

int fn_801AAB68(Unk801AB63C_P* p)
{
    int r = 2;
    if (fn_801AB0D8(p) == 1) {
        r = 3;
    }
    if (r == 2 && fn_801AB130(p) == 1) {
        r = 4;
    }
    return r;
}

int fn_801AABC4(Unk801AB63C_P* p)
{
    int r = 0;
    if (fn_801B5F4C(p) <= 2) {
        if ((unsigned)fn_801B5FC4(p, 4) <= 1) {
            int c = fn_801C1638(p->m8, 0xc);
            int f = 1;
            if (c == 0) {
                f = 0;
            }
            if (f == 1) {
                if (fn_801B5F8C(p) <= 1) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

int fn_801AAC4C(Unk801AB63C_P* p)
{
    int r = 0;
    if (fn_801B5F4C(p) <= 0) {
        if (fn_801B5F70(p) == 1) {
            if (fn_801B5FC4(p, 4) == 0) {
                int c = fn_801C1638(p->m8, 0xc);
                int f = 1;
                if (c == 0) {
                    f = 0;
                }
                if (f == 1) {
                    if (fn_801B5F8C(p) <= 1) {
                        r = 1;
                    }
                }
            }
        }
    }
    return r;
}

int fn_801AACE4(Unk801AB63C_P* p)
{
    int r = 0;
    int f = 1;
    if (p->m8->m65C[10] == 0) {
        f = 0;
    }
    if (f == 1) {
        if (fn_801B5F8C(p) <= 1) {
            r = 1;
        }
    }
    return r;
}

int fn_801AAD40(Unk801AB63C_P* p)
{
    int r = 0;
    int k = fn_801B5B18(p, 0, 0);
    if (k != 0) {
        if (k == 1) {
            r = 1;
        } else {
            char* o = (char*)fn_801B63A0(p, 2);
            int h = fn_801C1638(p->m8, 0);
            char* t = o + 0x588;
            float a = fn_80254474(t, 1, fn_80253678(h + 0x480));
            float b = fn_8025454C(t, 0xc);
            if (!(a > lbl_805CEEC8)) {
                r = b >= lbl_805CEECC;
            }
        }
    }
    return r;
}

int fn_801AAE10() { return 0; }

int fn_801AAE18() { return 0; }

int fn_801AAE20() { return 0; }

int fn_801AAE28(Unk801AB63C_P* p)
{
    int r = 0;
    Unk801AB0D8_Q* q = fn_801B63A0(p, 2);
    if (q) {
        char* t = q->mA0C;
        if (!(fn_8024F048(t, q->mA04, q->m44C, q->m708, 1) > lbl_805CEED0)) {
            if (!(fn_8024F20C(t, q->mA04, q->m44C, q->m708, 1) < lbl_805CEED4)) {
                if (!(q->m5D8 < lbl_805CEED8)) {
                    r = fn_8024EF40(t, q->m44C, q->m708) >= lbl_805CEED0;
                }
            }
        }
    }
    return r;
}

int fn_801AAEF4(Unk801AB63C_P* p)
{
    int r = 0;
    Unk801AAEF4_Q* q = (Unk801AAEF4_Q*)fn_801B63A0(p, 2);
    if (q) {
        if (q->fn_vslot24() == 1) {
            char* t = q->mA0C;
            if (!(fn_8024F048(t, q->mA04, q->m44C, q->m708, 1) > lbl_805CEEDC)) {
                if (!(fn_8024F20C(t, q->mA04, q->m44C, q->m708, 1) < lbl_805CEEE0)) {
                    if (!(q->m5D8 < lbl_805CEEE0)) {
                        if (!(fn_8024EF40(t, q->m44C, q->m708) < lbl_805CEEE0)) {
                            Unk8019F8C0_Inner* e = p->m8->m6F8->m14;
                            if (Unk801A96E0_U8(e, 0x1cca) <= 1) {
                                r = Unk801A96E0_U8(e, 0x1ccb) <= 2;
                            }
                        }
                    }
                }
            }
        }
    }
    return r;
}

int fn_801AB000(Unk801AB63C_P* p)
{
    int r = 0;
    if (fn_801B5F4C(p) <= 2) {
        int a = 1;
        if (fn_801C1638(p->m8, 0xb) == 0) {
            a = 0;
        }
        int c = fn_801C1638(p->m8, 0xc);
        int b = 1;
        if (c == 0) {
            b = 0;
        }
        if (a == 0 && b == 0) {
            if ((unsigned)(fn_801B5FC4(p, 4) + 1) <= 2) {
                Unk801AB0D8_Q* q = fn_801B63A0(p, 2);
                if (!(fn_8024F20C(q->mA0C, q->mA04, q->m44C, q->m708, 1) < lbl_805CEEE4)) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

int fn_801AB0D8(Unk801AB63C_P* p)
{
    Unk801AB0D8_Q* q = fn_801B63A0(p, 2);
    return fn_8024F048(q->mA0C, q->mA04, q->m44C, q->m708, 1) >= lbl_805CEEE8;
}

int fn_801AB130(Unk801AB63C_P* p)
{
    Unk801AB0D8_Q* q = fn_801B63A0(p, 2);
    return fn_8024F048(q->mA0C, q->mA04, q->m44C, q->m708, 1) <= lbl_805CEEEC;
}

/* The loop counter lives in memory (stack slot reloaded every iteration): a volatile local reproduces it. */
void fn_801AB188(Unk801A96E0_Init* p, int v)
{
    for (int i = 0; i < 4; i++) {
        p->m14[i] = v;
    }
}

/* near-miss: same code; the iterator read is reloaded after the table store and the (a == 2 || a == 3) / range tests fold differently (22 slots). */
void fn_801AB1A8(Unk801A96E0_Init* o)
{
    int arr[3];
    fn_801AB338(o);
    fn_801AB188(o, 1);
    Unk8006A138_It<3> it(0);
    int idx = 0;
    do {
        arr[it.v] = fn_801A96A8(fn_801A9D9C(o, idx));
        idx = it.Next();
    } while (idx <= 2);
    int a = fn_801AB460((Unk801AB460_T*)o, 0);
    if (a == 2 || a == 3) {
        o->m14[arr[0]] = a;
    } else {
        o->m14[arr[0]] = 1;
    }
    int b = fn_801AB460((Unk801AB460_T*)o, 1);
    if (b <= 3) {
        if (b >= 2) {
            o->m14[arr[1]] = 2;
        } else {
            o->m14[arr[1]] = 1;
        }
    } else {
        o->m14[arr[1]] = 1;
    }
    int c = fn_801AB460((Unk801AB460_T*)o, 2);
    if (c <= 3) {
        if (c >= 2) {
            o->m14[arr[2]] = 2;
        } else {
            o->m14[arr[2]] = 1;
        }
    } else {
        o->m14[arr[2]] = 1;
    }
}

void fn_801AB2EC(Unk801A96E0_Init* o)
{
    volatile int c = 0;
    int i = 0;
    do {
        o->m2C[i] = 0;
        int v = c;
        int r = v + 1;
        if (v > 3) {
            r = v;
        }
        c = r;
        i = r;
    } while (i <= 2);
}

void fn_801AB338(Unk801A96E0_Init* o)
{
    Unk801AB63C_P* p = (Unk801AB63C_P*)o;
    fn_801AB2EC(o);
    Unk8006A138_It<3> it(0);
    int idx = 0;
    do {
        Unk801AB338_Q* q = fn_801B6438(p, idx);
        if (q != 0) {
            int f = 0;
            if (it.v <= 1) {
                f = fn_801B6438(p, it.v + 1) != 0 ? 1 : 0;
            }
            if (f == 1) {
                o->m2C[it.v] = f;
            } else if (fn_801B5F8C(p) <= 1) {
                if (!(q->m5D8 <= lbl_805CEEF0)) {
                    o->m2C[it.v] = 3;
                } else {
                    o->m2C[it.v] = 2;
                }
            } else {
                if (!(q->m5D8 <= lbl_805CEEF4)) {
                    o->m2C[it.v] = 3;
                } else {
                    o->m2C[it.v] = 2;
                }
            }
        }
        idx = it.Next();
    } while (idx <= 2);
}

int fn_801AB460(Unk801AB460_T* p, int i)
{
    return p->m2C[i];
}

void fn_801AB470(Unk801A96E0_Late* p)
{
    p->m7C = lbl_805CEEF8;
    p->m68 = 0;
    p->m70 = 0;
    p->m78 = 0;
    p->m74 = -1;
    p->m6C = -1;
}

void fn_801AB49C(Unk801A96E0_Late* p)
{
    float lo = 0.2f;
    float k = (float)(unsigned)p->m8->m4C * 0.016666668f;
    int s = p->m70;
    int t;
    if (s == 1) {
        int w = p->m74;
        p->m68 = s;
        t = w;
    } else {
        if (p->m68 != p->m78) {
            if (!(k <= p->m7C + 0.2f)) {
                p->m68 = p->m78;
            }
        }
        t = -1;
    }
    p->m6C = t;
}

inline void* operator new(unsigned int, void* p) { return p; }

Unk801AB59C::Unk801AB59C(int a, int b) : Unk801B2490(a, b)
{
    Unk801AE30C_Clr* e = (Unk801AE30C_Clr*)((char*)this + 0x60);
    int i = 1;
    do {
        new (e) Unk801AE30C_Clr;
        e++;
    } while (i-- != 0);
    fn_801AB5CC(this);
}

void fn_801AB5CC(void* p)
{
    Unk801AB5CC_Obj* o = (Unk801AB5CC_Obj*)p;
    int z = 0;
    ((Unk801B2490*)o)->Setup();
    o->m5C = z;
    fn_801AE360(&o->m60);
    fn_801AE360(&o->m74);
    o->mC = z;
    o->m10 = z;
}

Unk801AB59C::~Unk801AB59C() {}

void fn_801AB618(void* p)
{
    fn_801AB5CC(p);
}

void fn_801AB638() {}
