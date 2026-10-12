/*
 * Game code, .text 0x801A22F4-0x801A57C8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8019F8C0.h"
#include "game/tu_801A57C8.h"
#include "game/tu_80177C34.h"

struct Unk801A22F4_S {
    char m0[0xA0];
};
/* Value returned through memory by fn_801855A4 (a word read from +0x370 of its argument). The
 * caller's slot is a BLKmode local of at most 8 bytes, so the type is a 6-byte record. */
struct Unk801A22F4_U32 {
    char m0[6];
};
extern "C" Unk801A22F4_U32 fn_801855A4(void* o, ...);
extern Unk801A22F4_S lbl_8068F0CC;
void fn_803E4450(Unk801A22F4_S* a, Unk801A22F4_S* b, Unk801A22F4_U32* c, float f);
extern float lbl_805CE6D4;

void fn_8017C82C(void* p);
int fn_80178EBC(Unk80178BBC_T* p, Unk80179284_Ctx* o);
class Unk801A24FC_VB {
public:
    char pad0[0x98];
};
class Unk801A24FC_V : public Unk801A24FC_VB {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
};
int fn_80178E08(Unk80178BBC_T* p, Unk80179284_Ctx* o);
extern "C" int fn_801A4910(Unk8019F8C0_Owner* o, int a, int b);
void fn_8024BE80(void* o, int a);
/* Objects with a vptr at +8 whose virtual 3 takes three ints. */
class Unk801A4D1C_VB {
public:
    char pad0[8];
};
class Unk801A4D1C_V : public Unk801A4D1C_VB {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3(int a, int b, int c);
};
struct Unk801A4D1C_X {
    char pad0[0x20];
    int m20;
    int m24;
    int m28;
};
extern "C" Unk801A4D1C_X* fn_801A6DB8(Unk8019F8C0_Owner* o);
void fn_8017E2E8(void* p, int a, int b, int c);
void fn_800AB8C8(void* g, Unk8019F8C0_Owner* o, int a, int b, int c);
extern void* lbl_80619D10;
struct Unk801A22F4_Ctx {
    char pad0[0x458];
    int m458;
    char pad45C[4];
    unsigned m460;
};
void fn_8016B2B8(void* p);
void fn_8040B574(void* a, void* b);
void fn_8040A208(void* a, void* b, int n, void (*f)(char*, char*));
int fn_802AE374(void* a, void* b, void* c, void* d, void* e);
Unk8019F8C0_Ref* fn_801A6D84(Unk8019F8C0_Owner* o, int n);
Unk8019F8C0_Sub* fn_801A04A8(Unk8019F8C0_Owner* o, int i);
void fn_801A27E0(void* p);
int fn_800A8898(void* m);
void fn_80081D70(void* p);
void fn_80187354(void* p);
void fn_80242E28(int a, float f);
extern float lbl_805CE7E4;
void fn_8016C4A0(void* p);
int fn_802D7DB4(int a, int b);
void fn_801A2608(Unk8019F8C0_Owner* o);
void fn_8033E4F0(void* p);
void fn_8017A930(void* p);
void fn_801A55A8(Unk8019F8C0_Owner* o);
void fn_801A4E4C(Unk8019F8C0_Owner* o);
void fn_80164DDC(void* p);
void fn_801A7AB0(void* p);
void fn_801A2C84(Unk8019F8C0_Owner* o);
void fn_8017AC0C(void* p);
void fn_801A33E4(Unk8019F8C0_Owner* o);
void fn_801A9428(void* p);
void fn_801A6FBC(Unk8019F8C0_Owner* o);
void fn_801A6ED8(Unk8019F8C0_Owner* o);
void fn_801C4530(void* p);
void fn_80235164(void* p);
extern "C" Unk8019F8C0_M2* fn_801A4CE8(Unk8019F8C0_Owner* o, int i);
extern int lbl_8061B9C8;
extern int lbl_8061B3BC;
inline int Unk801A22F4_At(int* a, int off)
{
    return *(int*)((char*)a + off);
}

void fn_801A22F4(Unk8019F8C0_Owner* o, Unk801A22F4_S* src)
{
    Unk801A22F4_S* g = &lbl_8068F0CC;
    *g = *src;
    int t = o->m6B8;
    if (t != 0) {
        Unk801A22F4_U32 v = fn_801855A4((void*)t);
        fn_803E4450(g, g, &v, lbl_805CE6D4);
    }
}

void fn_8024C0D0(int v);
int fn_800968C0(Unk8019F8C0_Inner* t, int key, int c);
int fn_80097300(Unk8019F8C0_Inner* t, int v);
int fn_80097190(Unk8019F8C0_Inner* t, int v);
extern "C" int fn_801A49F0(Unk8019F8C0_Owner* o, int team, int key);
unsigned char fn_801A48F8(Unk8019F8C0_Owner* o, int i);
void fn_8016C4FC(void* p);
struct Unk801A22F4_G {
    char pad0[0x2C];
    int m2C;
};
extern Unk801A22F4_G* lbl_8068B618;
void fn_8031E1D4(void* a, void* b);
void fn_80316BC0(void* a, int b);
extern char lbl_805CE77C[];
extern char lbl_805CE78C[];
extern void* lbl_8061FEDC;
extern "C" Unk8019F8C0_W* fn_801A4B34(Unk8019F8C0_Owner* o);
void fn_801A3860(Unk8019F8C0_Owner* o);
void fn_801A3920(Unk8019F8C0_Owner* o);
extern void* lbl_8061E978;

/* Object with a vptr at +0x98; slot 11 fills a 0xBC-byte record (ctor fn_80356930). */
class Unk801A3B68_VB {
public:
    char pad0[0x98];
};
class Unk801A3B68_V : public Unk801A3B68_VB {
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
    virtual void fn_vslot11(void* out, int n);
};
struct Unk801A3B68_Rec {
    char m0[0xBC];
};
struct Unk801A3B68_Elem {
    Unk801A3B68_V* m0;
    char m4[0x10];
};
void fn_80356930(Unk801A3B68_Rec* r);
void fn_802C920C(void* dst, Unk801A3B68_Rec* src);

/* Object built by ctor fn_80198AA0 (0x420 bytes); a sub-object at +0xA0 has its vptr at +0xB8. */
class Unk80198AA0_SubB {
public:
    char pad0[0x18];
};
class Unk80198AA0_Sub : public Unk80198AA0_SubB {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4(const char* s);
};
struct Unk80198AA0 {
    char pad0[0x420];
};
Unk80198AA0* fn_80198AA0(Unk80198AA0* mem, Unk8019F8C0_Owner* o);
void* operator new(unsigned int size, int heap);
void* operator new[](unsigned int size, int heap);
extern float lbl_805CE804;
extern char lbl_805CE818[];
extern char lbl_805CE81C[];

int fn_801BBC0C(void* p);
int fn_8017C8C0(void* p);
void fn_801A0790(Unk8019F8C0_Owner* o, float f);
void fn_80327274(void* p);
extern int lbl_80620860;
extern float lbl_805CE7F4;
extern float lbl_805CE800;
extern float lbl_805CE7F0;

int fn_802D8150();
int fn_802D8178(int i);
void fn_802DC518(int h, int v);
void fn_802DC5D4(int h, char* s);
void fn_802DC5F8(int h, char* s);
void fn_802DC570(int h);
int fn_804089B4(char* dst, const char* fmt, ...);
extern int lbl_8061CA40;
extern int lbl_8061CA44;
extern char lbl_805CE7C4[];

void fn_801A23B8(Unk8019F8C0_Owner* o, int flag)
{
    o->m58C[0] = o->m6F8->m10->m6C;
    o->m58C[1] = o->m6F8->m10->m70;
    if (flag) {
        fn_8017C82C(o->m700);
    }
}

int fn_801A2400(Unk8019F8C0_Owner* o)
{
    int r = 0;
    if ((unsigned)o->m4C <= 9 || o->m784 != 0 || o->m78C != 0 || o->m794 != 0 || o->m780 != 0
        || fn_801A4CE8(o, 1)->mC != 0 || fn_801A6D84(o, 1)->m3D90 != 0
        || ((Unk801A57C8_Mode*)o->m560)->m4->m14 == 4) {
        r = 1;
    }
    return r;
}

void fn_801A24AC(Unk8019F8C0_Owner* o)
{
    int i = 0;
    do {
        Unk8019F8C0_Ref* r = fn_801A6D84(o, i);
        i++;
        if (r) {
            fn_8016B2B8(r);
        }
    } while (i <= 5);
}

/* near-miss: same code; retail's second scan loop is rotated (test at the bottom, no entry jump); ours keeps the jump (8 slots). */
Unk801A22F4_Ctx* fn_801A24FC(Unk8019F8C0_Owner* o)
{
    Unk801A22F4_Ctx* r = 0;
    int i;
    for (i = 0; i <= 8; i++) {
        Unk801A22F4_Ctx* c = (Unk801A22F4_Ctx*)fn_801A4910(o, 3, i);
        if (c->m458 == 0x12) {
            r = c;
            break;
        }
    }
    if (r == 0) {
        for (i = 0; i <= 8; i++) {
            Unk801A22F4_Ctx* c = (Unk801A22F4_Ctx*)fn_801A4910(o, 3, i);
            int f = 0;
            if (o->m700 && o->m700->m3AC && fn_80178E08(o->m700->m3AC, (Unk80179284_Ctx*)c)) {
                f = 1;
            }
            if (c->m458 == 0xd && f == 0) {
                r = c;
                break;
            }
        }
    }
    if (r != 0) {
        fn_8024BE80(r, 0x12);
        ((Unk801A24FC_V*)r)->fn_vslot8(0);
    }
    return r;
}

void fn_801A27E0(void* p) {}

void fn_801A27E4(Unk8019F8C0_Owner* o)
{
    if (o->m6F4 != 1) {
        if (o->m4C == 0) {
            ((Unk8019F8C0_OV*)o)->fn_vslot7();
        } else {
            lbl_8061B9C8 = 1;
            fn_801A6FBC(o);
            fn_801A6ED8(o);
            if (o->m700) {
                fn_801C4530(o->m700->m3A4);
                if (o->m6F8->m14[2].GetM1() <= 2) {
                    fn_80235164(o->m700->m3B0);
                }
            }
        }
    }
}

void fn_801A2890(Unk8019F8C0_Owner* o)
{
    if (o->m6F4 != 1) {
        lbl_8061B9C8 = 1;
        fn_801A6ED8(o);
        if (o->m700) {
            fn_801C4530(o->m700->m3A4);
            if (o->m6F8->m14[2].GetM1() <= 2) {
                fn_80235164(o->m700->m3B0);
            }
        }
        lbl_8061B9C8 = 2;
        ((Unk8019F8C0_OV*)o)->fn_vslot5();
    }
}

void fn_801A292C(Unk8019F8C0_Owner* o)
{
    if (o->m6F4 != 1) {
        fn_801A27E0(o);
        if (fn_802D7DB4(0, 0xa9)) {
            fn_801A2608(o);
        }
        fn_8033E4F0(o->m560);
        if (o->m700) {
            fn_8017A930(o->m700);
        }
        fn_801A55A8(o);
        fn_801A4E4C(o);
        fn_80164DDC(o->m710);
        fn_801A7AB0(o->m744);
    }
}

void fn_801A29B8(Unk8019F8C0_Owner* o)
{
    if (o->m6F4 != 1 && o->m6F4 != 0xc) {
        fn_801A2C84(o);
        if (o->m700) {
            fn_8017AC0C(o->m700);
        }
        fn_801A4CE8(o, 1)->fn_vslot5();
        fn_801A33E4(o);
        fn_801A9428(o->m744);
    }
}

void fn_801A3704(Unk8019F8C0_Owner* o, int v)
{
    if (v != 0) {
        if (o->m780 == 0) {
            Unk8019F8C0_Sub* s = fn_801A04A8(o, 5);
            if (s && s->m40) {
                fn_8016C4A0(s->m40);
            }
            s = fn_801A04A8(o, 0);
            if (s && s->m40) {
                fn_8016C4A0(s->m40);
            }
            s = fn_801A04A8(o, 1);
            if (s) {
                Unk8019F8C0_Ref* r = s->m40;
                if (r && r->m3D90 != 0) {
                    fn_8016C4FC(r);
                }
            }
        }
    } else if (o->m780 != 0) {
        lbl_8068B618->m2C = 7;
    }
    o->m780 = v;
}

/* near-miss: same code; the two 0/1 flag registers are swapped (r10/r11, 6 slots). */
int fn_801A37D8(Unk8019F8C0_Owner* o)
{
    int a = 0;
    if (o->m780 != 0 || o->m784 != 0) {
        a = 1;
    }
    int b = 1;
    if (o->m720->mCC == -1) {
        b = 0;
    }
    int c = (a != 0) ? 1 : 0;
    int d = (b != 0) ? 1 : 0;
    int e = ((c | d) != 0) ? 1 : 0;
    int z = 0;
    int g = (lbl_8061B3BC != z) ? 1 : 0;
    return e | g;
}

void fn_801A3860(Unk8019F8C0_Owner* o)
{
    Unk8019F8C0_Sub* s = fn_801A04A8(o, 5);
    if (s) {
        Unk8019F8C0_W* w = fn_801A4B34(o);
        if (w && w->fn_vslot4() != 0) {
            fn_8031E1D4(s, lbl_805CE77C);
        } else {
            fn_8031E1D4(s, lbl_805CE78C);
        }
        s->m4 = 1;
        Unk8019F8C0_Sub* t = fn_801A04A8(o, 0);
        if (t) {
            t->m4 = 0;
        }
        fn_80316BC0(lbl_8061FEDC, 1);
    }
}

void fn_801A3920(Unk8019F8C0_Owner* o)
{
    Unk8019F8C0_Sub* s = fn_801A04A8(o, 5);
    if (s) {
        s->m4 = 0;
        if (fn_801A6D84(o, 0) && fn_801A6D84(o, 0)->m3D90 != 0) {
            Unk8019F8C0_Sub* t = fn_801A04A8(o, 0);
            if (t) {
                t->m4 = 1;
            }
            fn_80316BC0(lbl_8061FEDC, 0);
        }
    }
}

void fn_801A39B8(Unk8019F8C0_Owner* o, int v)
{
    if (v != o->m784) {
        if (v != 0 && o->m784 == 0) {
            Unk8019F8C0_Sub* s = fn_801A04A8(o, 0);
            if (s && s->m40) {
                fn_8016C4A0(s->m40);
            }
            fn_801A3860(o);
        }
        if (o->m784 != 0 && v == 0) {
            fn_801A3920(o);
        }
        o->m784 = v;
    }
}

void fn_801A3A54(Unk8019F8C0_Owner* o, int v)
{
    if (v != o->m78C) {
        if (v != 0 && o->m78C == 0) {
            fn_801A3860(o);
        }
        if (o->m78C != 0 && v == 0) {
            fn_801A3920(o);
        }
        o->m78C = v;
    }
}

void fn_801A3ACC(Unk8019F8C0_Owner* o, int v)
{
    if (v != o->m794) {
        if (v != 0 && o->m794 == 0) {
            Unk8019F8C0_Sub* s = fn_801A04A8(o, 0);
            if (s && s->m40) {
                fn_8016C4A0(s->m40);
            }
            fn_801A3860(o);
        }
        if (o->m794 != 0 && v == 0) {
            fn_801A3920(o);
        }
        o->m794 = v;
    }
}

void fn_801A3B68(Unk801A3B68_V* v, Unk801A3B68_Elem* arr, int* n, int max)
{
    if (*n < max) {
        arr[*n].m0 = v;
        Unk801A3B68_Rec rec;
        fn_80356930(&rec);
        v->fn_vslot11(&rec, -1);
        fn_802C920C(arr[*n].m4, &rec);
        *n = *n + 1;
    }
}

int fn_801A3BF8(Unk8019F8C0_Owner* o, Unk801A22F4_Ctx* c)
{
    if (c->m460 <= 8) {
        return 1;
    }
    switch (c->m458) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6:
        case 7: case 8: case 9: case 10: case 11: case 12:
        case 16: case 17:
        return 1;
    case 13: {
        Unk8019F8C0_Pl* p = o->m700;
        if (p && p->m3AC) {
            if (fn_80178EBC(p->m3AC, (Unk80179284_Ctx*)c)) {
                return 1;
            }
        }
        break;
    }
    }
    return 0;
}

void fn_801A3C7C(char* a, char* b)
{
    fn_8040B574(a + 4, b + 4);
}

void fn_801A3CA4(void* a, void* b)
{
    fn_8040A208(a, b, 0x14, fn_801A3C7C);
}

void fn_801A40E8()
{
    int n = fn_802D8150();
    for (int i = 0; i < n; i++) {
        int h = fn_802D8178(i);
        if (lbl_8061CA40 != 0) {
            fn_802DC518(h, 0x5dc);
        } else {
            char buf[256];
            fn_804089B4(buf, lbl_805CE7C4, i);
            fn_802DC5D4(h, buf);
            fn_802DC5F8(h, buf);
            fn_802DC570(h);
        }
    }
    if (lbl_8061CA40 == 1) {
        lbl_8061CA40 = 0;
    } else {
        if (--lbl_8061CA44 == 0) {
            lbl_8061CA40 = 1;
            lbl_8061CA44 = 5;
        }
    }
}

/* The team counter lives in memory (stack slot reloaded per use): a volatile local reproduces it. */
/* near-miss: same code; retail's registers for the memory counter / index (r0 vs r9) differ (5 slots). */
void fn_801A4674(Unk8019F8C0_Owner* o)
{
    volatile int c = 0;
    int t = 0;
    do {
        unsigned n = fn_801A48F8(o, t);
        unsigned k = 0;
        if (k < n) {
            int j = 0;
            do {
                k++;
                int v = Unk801A22F4_At(o->m594, j + c * 100);
                j += 4;
                fn_8024C0D0(v);
            } while (k < n);
        }
        int w = c;
        int r;
        if (w > 1) {
            r = w;
        } else {
            r = w + 1;
        }
        c = r;
        t = r;
    } while (t <= 1);
}

/* near-miss: same code; retail shares r0 between the byte offset and the loaded value (4 slots differ). */
class Unk801A4710_VB {
public:
    char pad0[0x98];
};
class Unk801A4710_V : public Unk801A4710_VB {
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
    virtual void fn_vslot24();
    virtual void fn_vslot25();
};

/* near-miss: written from the asm. */
inline int* Unk801A4710_Row(int* a, int r)
{
    return a + r * 25;
}

void fn_801A4710(Unk8019F8C0_Owner* o)
{
    volatile int c = 0;
    int t = 0;
    do {
        unsigned k = 0;
        unsigned n = fn_801A48F8(o, t);
        if (k < n) {
            int j = 0;
            do {
                char* b = (char*)o->m594;
                int o2 = j + c * 100;
                int v = *(int*)(b + o2);
                k++;
                j += 4;
                if (v != 0) {
                    ((Unk801A4710_V*)v)->fn_vslot25();
                }
            } while (k < n);
        }
        unsigned k2 = 0;
        do {
            int v = o->m6A0[c][k2];
            k2++;
            if (v != 0) {
                ((Unk801A4710_V*)v)->fn_vslot25();
            }
        } while (k2 <= 1);
        int v = o->m6B0[c];
        if (v != 0) {
            ((Unk801A4710_V*)v)->fn_vslot25();
        }
        int w = c;
        int r;
        if (w > 1) {
            r = w;
        } else {
            r = w + 1;
        }
        c = r;
        t = r;
    } while (t <= 1);
    unsigned k = 0;
    do {
        int v = o->m690[k];
        k++;
        if (v != 0) {
            ((Unk801A4710_V*)v)->fn_vslot25();
        }
    } while (k <= 3);
}
void fn_801A4884(Unk8019F8C0_Owner* o)
{
    int row = 0;
    for (int a = 2; a != 0; a--) {
        int col = 0;
        for (int b = 25; b != 0; b--) {
            int v = Unk801A22F4_At(o->m594, col + row);
            col += 4;
            if (v) {
                fn_80242E28(v, lbl_805CE7E4);
            }
        }
        row += 100;
    }
}

unsigned char fn_801A48F8(Unk8019F8C0_Owner* o, int i)
{
    Unk8019F8C0_Inner* p = o->m6F8->m14 + i;
    return p->m3E4;
}

extern "C" int fn_801A4910(Unk8019F8C0_Owner* o, int a, int b)
{
    if (b == 0xff) {
        return 0;
    }
    if (a > 2) {
        int f = 0;
        if (o->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        if (a != 3) {
            a = f ^ 1;
        } else {
            a = f;
        }
    }
    if ((unsigned)b > 0x18 || a > 1) {
        return 0;
    }
    return Unk801A22F4_At(o->m594, a * 100 + b * 4);
}

extern "C" int fn_801A497C(Unk8019F8C0_Owner* o, int a, int b)
{
    if (a > 2) {
        int f = 0;
        if (o->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        if (a != 3) {
            a = f ^ 1;
        } else {
            a = f;
        }
    }
    Unk8019F8C0_Inner* t = o->m6F8->m14 + a;
    b = t->m17C[b];
    if (b != 0xff) {
        return Unk801A22F4_At(o->m594, a * 100 + b * 4);
    }
    return 0;
}

extern "C" int fn_801A49F0(Unk8019F8C0_Owner* o, int team, int key)
{
    int a = team;
    if (a > 2) {
        int f = 0;
        if (o->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        if (a != 3) {
            a = f ^ 1;
        } else {
            a = f;
        }
        team = a;
    }
    int r = fn_800968C0(o->m6F8->m14 + team, key, 1);
    int v = 0;
    if (r != 0xff) {
        v = Unk801A22F4_At(o->m594, team * 100 + r * 4);
    }
    return v;
}

int fn_801A4A94(Unk8019F8C0_Owner* o, int key)
{
    volatile int c = 0;
    int i = 0;
    for (;;) {
        int r = fn_800968C0(&o->m6F8->m14[i], key, 0);
        if (r != 0xFF) {
            return Unk801A22F4_At(o->m594, c * 100 + r * 4);
        }
        int v = c;
        int n;
        if (v > 1) {
            n = v;
        } else {
            n = v + 1;
        }
        c = n;
        i = n;
        if (i > 1) {
            return 0;
        }
    }
}

extern "C" Unk8019F8C0_W* fn_801A4B34(Unk8019F8C0_Owner* o)
{
    int f = 0;
    if (o->m6F8->m14[2].m8 != 0) {
        f = 1;
    }
    Unk8019F8C0_Inner* t = &o->m6F8->m14[f];
    /* near-miss: 2 slots (add operand order / dest register of the byte-offset sum). */
    return (Unk8019F8C0_W*)Unk801A22F4_At(o->m594, t->m168.m0[t->m168.mC] * 4 + f * 100);
}

void fn_801A4B7C(Unk8019F8C0_Owner* o, int a, int flag)
{
    int team;
    if (flag != 0) {
        int f = 0;
        if (o->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        team = f;
    } else {
        team = o->m6F8->m14[2].m8 == 0;
    }
    Unk8019F8C0_Inner* t = &o->m6F8->m14[team];
    fn_801A49F0(o, team, fn_80097300(t, fn_80097190(t, a)));
}

int fn_801A4C20(Unk8019F8C0_Owner* o)
{
    if (o->m6F4 == 1) {
        return o->m594[0];
    }
    return 0;
}

int fn_801A4C3C(Unk8019F8C0_Owner* o, int a, int b)
{
    if (a == 0) {
        return o->m6B0[b];
    }
    return 0;
}

int fn_801A4C5C(Unk8019F8C0_Owner* o, int a, int b)
{
    return o->m6A0[a][b];
}

int fn_801A4C74(Unk8019F8C0_Owner* o, int i)
{
    return o->m690[i];
}

void fn_801A4C84(Unk8019F8C0_Owner* o)
{
    Unk8019F8C0_Mgr* m = o->m6F8;
    Unk8019F8C0_Ring* r = &m->m14[fn_800A8898(m)].m168;
    r->mC = (r->mC + 1) % r->m4;
    fn_80081D70(m->m14);
}

extern "C" Unk8019F8C0_M2* fn_801A4CE8(Unk8019F8C0_Owner* o, int i)
{
    Unk8019F8C0_Sub* s = fn_801A04A8(o, i);
    if (s) {
        return s->m3C;
    }
    return 0;
}

void fn_801A4D1C(Unk8019F8C0_Owner* o, int a, int b, int c)
{
    Unk801A4D1C_V* m = (Unk801A4D1C_V*)((Unk801A57C8_Mode*)o->m560)->m4;
    if (m) {
        m->fn_vslot3(a, 0, 0);
    }
    if (o->m700) {
        fn_8017E2E8(o->m700, a, b, c);
    }
    if (!((a == 0x39 && fn_801A6DB8(o)->m20 == 0) || (a == 0x48 && fn_801A6DB8(o)->m28 == 0)
          || (a == 0x45 && fn_801A6DB8(o)->m24 == 0) || (a == 0x41 && fn_801A6DB8(o)->m24 == 0))) {
        ((Unk801A4D1C_V*)o->m6F8)->fn_vslot3(a, b, c);
    }
    fn_800AB8C8(lbl_80619D10, o, a, b, c);
}

void fn_801A4E4C(Unk8019F8C0_Owner* o)
{
    if (o->m6FC != 0) {
        int s = o->m6F4;
        if (s == 0) {
            if (fn_801BBC0C(o->m700->m3BC)) {
                if (lbl_80620860 == 0) {
                    fn_801A0790(o, (float)(unsigned)o->m4C * lbl_805CE7F0);
                }
                o->m6FC = 0;
            }
        } else if (((Unk801A57C8_Mode*)o->m560)->m4->m14 != 0xf) {
            fn_801A0790(o, (float)(unsigned)o->m4C * lbl_805CE7F0);
            o->m6FC = 0;
        }
    }
}

int fn_801A4F40(Unk8019F8C0_Owner* o)
{
    int s = o->m6F4;
    if (s != 0 && s != 7) {
        return 0;
    }
    int a = fn_801BBC0C(o->m700->m3BC);
    int b = fn_8017C8C0(o->m700);
    if (a != 0 || b == 0) {
        return 0;
    }
    const float base = lbl_805CE7F4;
    o->m6FC = 1;
    if (lbl_80620860 == 0) {
        fn_801A0790(o, (float)(unsigned)o->m4C * lbl_805CE800 + lbl_805CE7F4);
    }
    fn_80327274((char*)o + 0x50);
    return 1;
}

void fn_801A5014(Unk8019F8C0_Owner* o)
{
    o->m6B8 = fn_802AE374(lbl_8061E978, o, &o->m6BC, &o->m6C0, &o->m740);
}

/* near-miss: same code; retail's indexed accesses print the offset register first (lwzx/add/stwx on m6E0[i], 3 slots). */
Unk8019F8C0_Obj4A4* fn_801A5218(Unk8019F8C0_Owner* o)
{
    float best = lbl_805CE804;
    int bi = 0;
    for (int i = 0; i < o->m6D8; i++) {
        Unk8019F8C0_Ent* e = &o->m6E0[i];
        if (e->m0 != 1 && (int)e->m4 != o->m6CC) {
            if (e->m0 == 0) {
                e->m0 = 2;
                return o->m6E0[i].m4;
            }
            float v = e->m4->m3F4;
            if (!(v <= best)) {
                best = v;
                bi = i;
            }
        }
    }
    o->m6D4 = bi;
    return o->m6E0[bi].m4;
}

int fn_801A52D4(Unk8019F8C0_Owner* o, int key)
{
    int n = o->m6D8;
    for (int i = 0; i < n; i++) {
        if ((int)o->m6E0[i].m4 == key) {
            return i;
        }
    }
    return 0;
}

int fn_801A5318(Unk8019F8C0_Owner* o, int i)
{
    return (int)o->m6E0[i].m4;
}

void fn_801A532C(Unk8019F8C0_Owner* o)
{
    for (int i = 0; i < o->m6D8; i++) {
        fn_80187354(o->m6E0[i].m4);
    }
    o->m6CC = 0;
}

Unk8019F8C0_Obj4A4* fn_801A552C(Unk8019F8C0_Owner* o)
{
    int idx = o->m6D0;
    int n = o->m6D8;
    Unk8019F8C0_Obj4A4* found = 0;
    int start = idx;
    do {
        Unk8019F8C0_Obj4A4* e = o->m6E0[idx].m4;
        if (e->m4A4 & 0x4000000) {
            found = e;
        }
        idx--;
        idx = (idx + n) % n;
    } while (idx != start);
    return found;
}

int fn_801A5580(Unk8019F8C0_Owner* o)
{
    int i = o->m6D4;
    if (i == -1) {
        return 0;
    }
    return (int)o->m6E0[i].m4;
}

void fn_801A5708(Unk8019F8C0_Owner* o)
{
    if (o->m6E4 == 0) {
        o->m6E4 = fn_80198AA0(new (0) Unk80198AA0, o);
        ((Unk80198AA0_Sub*)((char*)o->m6E4 + 0xA0))->fn_vslot4(lbl_805CE818);
        o->m6E8 = fn_80198AA0(new (0) Unk80198AA0, o);
        ((Unk80198AA0_Sub*)((char*)o->m6E8 + 0xA0))->fn_vslot4(lbl_805CE81C);
    }
}

void fn_801A57B4() {}

int fn_801A57B8()
{
    char buf[0x80];
    return 0;
}
