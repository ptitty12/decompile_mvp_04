/*
 * Game code, .text 0x801A57C8-0x801A96E0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801A57C8.h"
#include "game/clampiter.h"

void fn_801A57C8(Unk8019F8C0_Owner* o, int a);
int fn_801A57B8();
void fn_801A62D0(Unk8019F8C0_Owner* o, int a);
void fn_801B2538(Unk8019F8C0_Owner* o);
void fn_80235AD4(void* p);
void fn_8033E5C4(void* a, int n);
Unk8019F8C0_Sub* fn_801A04A8(Unk8019F8C0_Owner* o, int i);
void* fn_803FFC58(void* p, int v, int n);
void fn_8037893C(void* a, int b, void* c, void* d, int e);
void fn_801AA038(void* p, int n);
void fn_801AA248(void* p);
extern Unk801A57C8_G lbl_8068BF34;
void fn_8023C514(void* a, Unk8019F8C0_Owner* o);
void fn_8033E958(const char* s, ...);
void fn_801A5394(Unk8019F8C0_Owner* o);
void fn_801A5708(Unk8019F8C0_Owner* o);
void fn_801A57B4(Unk8019F8C0_Owner* o);
void fn_801A5014(Unk8019F8C0_Owner* o);
void fn_8006F918(int a, int b);
int fn_800A8874(void* m, int a, int b, int c);
void fn_801A594C(Unk8019F8C0_Owner* o, int i);
/* near-miss: same code; retail forms o+0x6B0 inside the branch (r30/r31 roles swap), keeps buf at sp+8 with a
 * recomputed address, and holds idx in r7 (about 3 extra insns here). */
void fn_801A5D3C(Unk8019F8C0_Owner* o);
void fn_801A5C1C(Unk8019F8C0_Owner* o);
void fn_801A5B44(Unk8019F8C0_Owner* o);
void fn_80378A34(void* a, void* b);
extern char lbl_8068CCA8[];
extern char lbl_805CEA04[];
extern char lbl_805CEA28[];
void fn_8028709C(void* x, unsigned h);
int fn_801A2034(Unk8019F8C0_Owner* o, int i);
void fn_801A7764(void* w, int t);
struct Unk801A7764_St {
    char pad0[0x570];
    int m570;
};
Unk801A7764_St* fn_800B555C();
extern char lbl_805CEAD4[];
int fn_80400E84();
int fn_80400DA4();
void fn_80107F74(int a, int b, int c);

struct Unk801A57C8_Ob {
    char pad0[0x18];
    int m18;
    int m1C;
    char pad20[0x38 - 0x20];
    int m38;
};
float fn_802D7E2C(int a, int b);
void fn_801A81A4(Unk801A57C8_Ob* o);
void fn_801A82A8(Unk801A57C8_Ob* o, int x);
void fn_801A8198(char* p);

/* Short string buffer (ctor 0x8035682C), copied into with fn_8040B830 and terminated at +0xF. */
class Unk8035682C {
public:
    Unk8035682C();
    char m0[0x10];
};
/* Singleton queue behind lbl_8061A32C (size 0xD8, ctor 0x800B64BC). */
class Unk800B64BC {
public:
    Unk800B64BC();
    char m0[0xD8];
};
void* operator new(unsigned int size, int heap);
void fn_8040B830(void* dst, const char* src, int n);
void fn_800B7B4C(Unk800B64BC* q, Unk8035682C* s, int n);
extern Unk800B64BC* lbl_8061A32C;
extern char lbl_805CEB0C[];

/* Result record of fn_80326F44 (returned through memory; id at +0, value at +4). */
struct Unk801A78E4_Rec {
    int m0;
    float m4;
    int m8;
    int mC;
    int m10;
    int m14;
};
void fn_80326F44(Unk801A78E4_Rec* out, char* obj, int a, int b, float f);
extern float lbl_805CEAF0;

/* Owner's mode objects, as fn_801A72E0 sees them (+0x58C sub-record with state words at +0x40/+0x44). */
struct Unk801A72E0_Sub {
    char pad0[0x40];
    int m40;
    int m44;
};
struct Unk801A72E0_Obj {
    char pad0[0x58C];
    Unk801A72E0_Sub m58C;
};

inline int Unk801A57C8_At(int* a, int off)
{
    return *(int*)((char*)a + off);
}

/* Timer-like object: owner at +0, a flag at +0x18; fn_801A745C reads the owner's value at +0x6CC. */
struct Unk801A745C_T {
    Unk8019F8C0_Owner* m0;
    char pad4[0x18 - 0x4];
    int m18;
    int m1C;
    char pad20[0x38 - 0x20];
    int m38;
};
int fn_80326E64(void* p, int a);
int fn_80326DF0(void* p, int a);
extern float lbl_805CEAE8;
extern float lbl_805CEAEC;
void fn_801A0790(Unk8019F8C0_Owner* o, float v);
extern "C" float fn_80189D60(int a);
extern float lbl_805CEAA8;
extern float lbl_805CEAAC;

/* Object built by fn_802AE610: vptr at +0x98 (slot 8 takes a flag); a sub-object at +0xA0 has its vptr at +0xB8. */
class Unk801A5A9C_VB {
public:
    char pad0[0x98];
};
class Unk801A5A9C_V : public Unk801A5A9C_VB {
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
struct Unk801A5A9C_Obj {
    char pad0[0x708];
    int m708;
};
class Unk802AE610_SubB {
public:
    char pad0[0x18];
};
class Unk802AE610_Sub : public Unk802AE610_SubB {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4(const char* s);
};
Unk801A5A9C_Obj* fn_802AE610(void* mgr, Unk8019F8C0_Owner* a, int b, Unk8019F8C0_Owner* c, int d, int e);
void fn_8024BE80(Unk801A5A9C_Obj* o, int a);
extern char lbl_805CE8E8[];
extern int lbl_805CEA60[];
void fn_802B8888(void* mgr, Unk8019F8C0_Inner* t, int v);
int fn_80097300(Unk8019F8C0_Inner* t, int v);
extern void* lbl_8061E978;

/* Timer-like object of fn_801A9428: owner at +0, flags at +0x18 and +0x20. */
struct Unk801A9428_T {
    Unk8019F8C0_Owner* m0;
    char pad4[0x18 - 0x4];
    int m18;
    char pad1C[4];
    int m20;
};
struct Unk801A9428_Pair {
    char pad0[0x24];
    int m24;
};
class Unk8016ACAC {
public:
    char pad0[4];
    int fn_8016AD44();
    int fn_8016AEEC();
};
extern "C" void fn_80188044(int h, int v);
extern "C" void fn_80188698(int h, float f);
extern "C" void fn_801889C0(int h);
void fn_801A94EC(void* p);
extern float lbl_805CEB90;

struct Unk801A94EC_V {
    float x;
    float y;
    float z;
};
struct Unk801A94EC_T {
    void* m0;
    Unk801A94EC_V m4;
    int m10;
    int m14;
    char pad18[0x38 - 0x18];
    int m38;
};
float fn_80301E44(void* o, Unk801A94EC_V* v);
void fn_802FFAD4(Unk801A94EC_V* v, int a, int b, float f);
extern float lbl_805CEB94;
extern Unk801A734C_V3 lbl_806055AC;
extern float lbl_805CEA98;

/* Iterator object of fn_801A62D0 (ctor 0x8014E09C, advance 0x8014E108); current index at +8. */
struct Unk801A62D0_It {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};
struct Unk801A62D0_X {
    char pad0[0x460];
    int m460;
};
void fn_8014E09C(Unk801A62D0_It* it, Unk8019F8C0_Owner* o, int a);
void fn_8014E108(Unk801A62D0_It* it);
int fn_802D7DB4(int a, int b);

struct Unk801A7048_T744 {
    char pad0[0x20];
    int m20;
};
struct Unk801A7048_P {
    char pad0[0x38C];
    int m38C;
};
extern "C" Unk8019F8C0_M2* fn_801A4CE8(Unk8019F8C0_Owner* o, int i);
int fn_8018AD2C(Unk801A7048_P* p);

struct Unk801A6750_X {
    char pad0[0x380];
    int m380;
};
struct Unk801A6750_V {
    float x;
    float y;
    float z;
};
void fn_80198E70(void* o, int a);
void fn_8019A5E0(void* o, int a, Unk801A6750_V* v, int c);

void* fn_802AE7D4(void* mgr, Unk8019F8C0_Owner* a, int i, Unk8019F8C0_Owner* c);
int fn_804089B4(char* dst, const char* fmt, ...);
extern char lbl_805CE8F8[];
extern char lbl_805CE97C[];
extern char lbl_805CE944[];
extern char lbl_805CE96C[];
extern char lbl_805CE9A0[];
extern char lbl_805CE918[];
extern char lbl_805CE924[];

int fn_803270C4(char* p, int a, int b, float f);
int fn_8014E2B4(int a);
extern float lbl_805CEA5C;
struct Unk801A71D0_Sub {
    char pad0[4];
    unsigned m4;
    char pad8[0x38 - 0x8];
    int m38;
};
struct Unk801A71D0_Obj {
    char pad0[0x58C];
    Unk801A71D0_Sub m58C;
};

struct Unk801A7950_C {
    char pad0[0x38C];
    int m38C;
    char pad390[0x3F4 - 0x390];
    float m3F4;
};
int fn_80326C20(void* p);
float fn_80190F0C(Unk801A7950_C* c);
extern float lbl_805CEAF4;
extern float lbl_805CEB00;
extern float lbl_805CEB04;
struct Unk801A57C8_Wrap {
    Unk8019F8C0_Owner* m0;
};
float fn_801A78E4(Unk801A57C8_Wrap* w);
int fn_801A7950(Unk801A57C8_Wrap* w);
float fn_801A745C(Unk801A745C_T* t);
struct Unk801A57C8_Timer {
    char pad0[0x28];
    int m28;
    int m2C;
    int m30;
    int m34;
};

void fn_801A58FC(Unk8019F8C0_Owner* o, int a)
{
    if (o->m6F4 == 0 && fn_801A57B8()) {
        fn_801A57C8(o, a);
    }
}

void fn_801A5A9C(Unk8019F8C0_Owner* o)
{
    fn_801A5394(o);
    Unk801A5A9C_Obj* x = fn_802AE610(lbl_8061E978, o, 0, o, 0, 0);
    ((Unk802AE610_Sub*)((char*)x + 0xA0))->fn_vslot4(lbl_805CE8E8);
    x->m708 = 0;
    fn_8024BE80(x, 0);
    ((Unk801A5A9C_V*)x)->fn_vslot8(0);
    o->m594[0] = (int)x;
}

void fn_801A5B44(Unk8019F8C0_Owner* o)
{
    fn_8033E958(lbl_805CE8F8);
    int i = 0;
    do {
        o->m690[i] = (int)fn_802AE7D4(lbl_8061E978, o, i, o);
        char buf[16];
        fn_804089B4(buf, lbl_805CE918, i);
        ((Unk802AE610_Sub*)((char*)o->m690[i] + 0xA0))->fn_vslot4(buf);
        char* x = (char*)o->m690[i];
        fn_80378A34(o->m704, x ? x + 0x5e4 : 0);
        i++;
    } while (i <= 3);
    fn_8033E958(lbl_805CE924);
}

void fn_801A5C1C(Unk8019F8C0_Owner* o)
{
    fn_8033E958(lbl_805CE944);
    char buf[16];
    Unk8006A138_It<1> it(0);
    do {
        int j = 0;
        int off = 0;
        do {
            o->m6A0[it.v][j] = (int)fn_802AE610(lbl_8061E978, o, 0, o, it.v, 0);
            fn_804089B4(buf, lbl_805CE96C, it.v, j);
            ((Unk802AE610_Sub*)((char*)o->m6A0[it.v][j] + 0xA0))->fn_vslot4(buf);
            ((Unk801A5A9C_V*)o->m6A0[it.v][j])->fn_vslot8(1);
            j++;
            off += 4;
        } while (j <= 1);
    } while (it.Next() <= 1);
}

void fn_801A5D3C(Unk8019F8C0_Owner* o)
{
    fn_8033E958(lbl_805CE97C);
    Unk8006A138_It<1> it(0);
    int idx = 0;
    do {
        int v = o->m6F8->m14[idx].m1A0;
        if (v != 0) {
            o->m6B0[it.v] = (int)fn_802AE610(lbl_8061E978, o, v, o, idx, 0xff);
            char buf[16];
            fn_804089B4(buf, lbl_805CE9A0, it.v);
            ((Unk802AE610_Sub*)((char*)o->m6B0[it.v] + 0xA0))->fn_vslot4(buf);
            ((Unk801A5A9C_V*)o->m6B0[it.v])->fn_vslot8(1);
        }
        idx = it.Next();
    } while (idx <= 1);
}

struct Unk801A5E50_Obj {
    char pad0[0x618];
    int m618;
};
int fn_80381E9C(int obj, unsigned hash, int a, int b);
void fn_803814A4(int obj, int a, int b, float f);
extern char lbl_805CE9AC[];
extern char lbl_805CE9D4[];
extern float lbl_805CEA00;

void fn_801A5E50(Unk8019F8C0_Owner* o)
{
    fn_8033E958(lbl_805CE9AC);
    Unk801A5E50_Obj* p = (Unk801A5E50_Obj*)o->m594[0];
    if (p) {
        int t = p->m618;
        if (t != 0) {
            fn_80381E9C(t, 0xDB7AB022u, 0, 0);
            fn_80381E9C(t, 0x0E246B08u, 0, 0);
            fn_80381E9C(t, 0x7BF65171u, 0, 0);
            fn_80381E9C(t, 0xF4318E1Du, 0, 0);
            fn_80381E9C(t, 0x4C226115u, 0, 0);
            fn_80381E9C(t, 0x512ADB3Cu, 0, 0);
            fn_80381E9C(t, 0xEE1B6C46u, 0, 0);
            fn_80381E9C(t, 0x8CFB37B7u, 0, 0);
            fn_80381E9C(t, 0x1F8D6080u, 0, 0);
            fn_80381E9C(t, 0x9D44D7EEu, 0, 0);
            fn_80381E9C(t, 0x5C53C627u, 0, 0);
            fn_80381E9C(t, 0xC0F46231u, 0, 0);
            fn_80381E9C(t, 0xE14981C4u, 0, 0);
            fn_80381E9C(t, 0x9D803AF7u, 0, 0);
            fn_80381E9C(t, 0xD484ACC6u, 0, 0);
            fn_80381E9C(t, 0x8249F53Cu, 0, 0);
            fn_80381E9C(t, 0xE433AA50u, 0, 0);
            fn_80381E9C(t, 0x9CEA8000u, 0, 0);
            fn_80381E9C(t, 0x8C1988B6u, 0, 0);
            fn_80381E9C(t, 0xFA01EA4Au, 0, 0);
            fn_80381E9C(t, 0x34CFAED1u, 0, 0);
            fn_80381E9C(t, 0xA68012D3u, 0, 0);
            fn_80381E9C(t, 0x0C0032D1u, 0, 0);
            fn_80381E9C(t, 0x1407B459u, 0, 0);
            fn_80381E9C(t, 0x07CBFA4Bu, 0, 0);
            fn_80381E9C(t, 0x36E74862u, 0, 0);
            fn_80381E9C(t, 0xE9868307u, 0, 0);
            fn_80381E9C(t, 0x8CFF6EBEu, 0, 0);
            fn_80381E9C(t, 0xC7BBCB74u, 0, 0);
            fn_80381E9C(t, 0x7455EBC7u, 0, 0);
            fn_80381E9C(t, 0x2F83EEFCu, 0, 0);
            fn_80381E9C(t, 0x7BEFBEB9u, 0, 0);
            fn_80381E9C(t, 0x9EF2CB16u, 0, 0);
            fn_80381E9C(t, 0x15EA1EBDu, 0, 0);
            fn_80381E9C(t, 0xA87C30D2u, 0, 0);
            fn_80381E9C(t, 0x4F7CB175u, 0, 0);
            fn_80381E9C(t, 0x9EF2CB16u, 0, 0);
            fn_803814A4(t, 0, 0, lbl_805CEA00);
        }
    }
    fn_8033E958(lbl_805CE9D4);
}

void fn_801A6240(Unk8019F8C0_Owner* o)
{
    void* t = (void*)o->m594[0];
    if (t) {
        fn_8028709C(t, 0xC3FB7E21u);
        fn_8028709C(t, 0x4901B7BCu);
        fn_8028709C(t, 0x5112B944u);
        fn_8028709C(t, 0x6BCA31A3u);
        fn_8028709C(t, 0xBEE24601u);
        fn_8028709C(t, 0x52D3659Du);
    }
}

/* near-miss: same code; callee-saved registers match, the table index temporaries differ (10 slots). */
void fn_801A62D0(Unk8019F8C0_Owner* o, int team)
{
    Unk801A62D0_It it;
    fn_8014E09C(&it, o, 1);
    Unk801A62D0_It* p = &it;
    while (p->m8 != 10) {
        Unk8019F8C0_Inner* q = o->m6F8->m14 + team;
        int slot = q->m17C[p->m8];
        if (slot != 0xff) {
            Unk801A62D0_X* x = (Unk801A62D0_X*)Unk801A57C8_At(o->m594, slot * 4 + team * 100);
            x->m460 = p->m8;
        }
        fn_8014E108(p);
    }
    Unk8019F8C0_Inner* t = o->m6F8->m14 + team;
    int s = t->m164;
    if (s == 0 || s == 2) {
        int slot = t->m17C[9];
        if (slot != 0xff) {
            Unk801A62D0_X* x = (Unk801A62D0_X*)Unk801A57C8_At(o->m594, team * 100 + slot * 4);
            x->m460 = 9;
        }
    }
}

/* near-miss: same code; retail keeps the loop counter and byte offset in r10/r11 and the row offset in r0 (8 slots). */
void fn_801A63B0(Unk8019F8C0_Owner* o, int key, int team, int* out)
{
    if (team > 2) {
        int f = 0;
        if (o->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        int a = team;
        if (a != 3) {
            team = f ^ 1;
        } else {
            team = f;
        }
    }
    for (int i = 0; i < 25; i++) {
        if (key == Unk801A57C8_At(o->m594, team * 100 + i * 4)) {
            *out = i;
            return;
        }
    }
    *out = 0xff;
}

void fn_801A642C(Unk8019F8C0_Owner* o)
{
    fn_8023C514(lbl_8068CCA8, o);
    fn_8033E958(lbl_805CEA04);
    fn_801A5394(o);
    fn_801A5708(o);
    fn_801A57B4(o);
    fn_801A5014(o);
    Unk8019F8C0_Mgr* m = o->m6F8;
    int t = m->mC;
    fn_8006F918(t, fn_800A8874(m, 0x64, 0, 0));
    volatile int c = 0;
    int i = 0;
    do {
        fn_801A594C(o, i);
        int w = c;
        int n;
        if (w > 1) {
            n = w;
        } else {
            n = w + 1;
        }
        c = n;
        i = n;
    } while (i <= 1);
    fn_801A5D3C(o);
    fn_801A5C1C(o);
    fn_801A5B44(o);
    fn_80378A34(o->m24, o->m704);
    fn_8033E958(lbl_805CEA28);
}

void fn_801A6528(Unk8019F8C0_Owner* o)
{
    fn_801A62D0(o, 1);
    fn_801A62D0(o, 0);
    fn_801B2538(o);
}

void fn_801A674C() {}

void fn_801A6750(Unk8019F8C0_Owner* o, int a, Unk801A6750_V* v, int c)
{
    fn_80198E70(o->m6E4, 2);
    ((Unk801A5A9C_V*)o->m6E8)->fn_vslot8(0);
    fn_80198E70(o->m6E8, 3);
    Unk801A6750_X* p = (Unk801A6750_X*)o->m6E4;
    Unk801A6750_X* q = (Unk801A6750_X*)o->m6E8;
    int t = p->m380;
    if (t > 7) {
        t = 7;
    }
    q->m380 = t;
    Unk801A6750_V w = *v;
    fn_8019A5E0(o->m6E8, a, &w, c);
    fn_8037893C(o->m704, 0x52, 0, 0, 0);
}

void fn_801A6820(Unk8019F8C0_Owner* o)
{
    Unk801A57C8_Mode* p = (Unk801A57C8_Mode*)o->m560;
    if (p->m4->m14 - 3 <= 1) {
        fn_80235AD4(o->m700->m3B0);
        fn_8033E5C4(p, 3);
    }
}

void fn_801A69EC(Unk8019F8C0_Owner* o)
{
    Unk8019F8C0_Inner* t = &o->m6F8->m14[1];
    unsigned i = 0;
    if (i < o->m6F8->m14[1].m168.m4) {
        do {
            int v = fn_80097300(t, (unsigned char)i);
            i++;
            fn_802B8888(lbl_8061E978, t, v);
        } while (i < t->m168.m4);
    }
}

Unk8019F8C0_Ref* fn_801A6D84(Unk8019F8C0_Owner* o, int i)
{
    Unk8019F8C0_Sub* s = fn_801A04A8(o, i);
    if (s) {
        return s->m40;
    }
    return 0;
}

void fn_801A6ED8(Unk8019F8C0_Owner* o)
{
    int a = fn_801A2034(o, o->m6F8->m14[2].m8 == 0);
    int f = 0;
    if (o->m6F8->m14[2].m8 != 0) {
        f = 1;
    }
    int b = fn_801A2034(o, f);
    Unk801A57C8_G* g = &lbl_8068BF34;
    if (g->m310 == 0) {
        g->m310 = fn_802D7DB4(a, 0xc4);
    }
    if (g->m31C == 0) {
        g->m31C = fn_802D7DB4(a, 0xc7);
    }
    if (g->m314 == 0) {
        g->m314 = fn_802D7DB4(a, 0xc5);
    }
    if (g->m0[0x76] == 0) {
        g->m0[0x76] = fn_802D7DB4(b, 0x76);
    }
}

void fn_801A6FBC()
{
    fn_803FFC58(&lbl_8068BF34, 0, 0x424);
    lbl_8068BF34.m310 = 0;
    lbl_8068BF34.m31C = 0;
    lbl_8068BF34.m314 = 0;
    lbl_8068BF34.m318 = 0;
}

int fn_801A700C(int a, int b, int idx)
{
    return lbl_8068BF34.m0[idx];
}

int fn_801A7020(Unk8019F8C0_Owner* o)
{
    Unk8019F8C0_Mgr10* p = o->m6F8->m10;
    int r = 0;
    if (p) {
        r = p->m22C == 0xb;
    }
    return r;
}

int fn_801A7048(Unk8019F8C0_Owner* o)
{
    Unk801A57C8_ModeObj* m = ((Unk801A57C8_Mode*)o->m560)->m4;
    if (m != 0 && m->m14 == 6) {
        Unk8019F8C0_M2* a = fn_801A4CE8(o, 1);
        Unk8019F8C0_Sub* b = fn_801A04A8(o, 1);
        Unk801A7048_P* p = (Unk801A7048_P*)o->m6CC;
        if (a->fn_vslot9() == 0 && ((Unk801A7048_T744*)o->m744)->m20 == 0 && b->m44 == 0) {
            return 1;
        }
        if (a->fn_vslot9() != 0 && p->m38C == 1) {
            if (fn_8018AD2C(p)) {
                return 1;
            }
        }
    }
    return 0;
}

int fn_801A7130(Unk8019F8C0_Owner* o, int i)
{
    if (o->m58C[i] != -1) {
        Unk8019F8C0_Inner* e = &o->m6F8->m14[i];
        return e->m108 != 0;
    }
    return 1;
}

void fn_801A7174(void* a, int b, void* c, void* d)
{
    fn_8037893C(a, b, c, d, 0);
}

int fn_801A7198(Unk8019F8C0_Owner* o)
{
    int* p = o->m65C;
    int r = 0;
    if (p[10] || p[11] || p[12]) {
        r = 1;
    }
    return r;
}

int fn_801A71D0(Unk8019F8C0_Owner* o)
{
    char* sub = (char*)o + 0x50;
    int a = fn_803270C4(sub, 0x39, 1, lbl_805CEA5C);
    if (fn_803270C4(sub, 0x61, 1, lbl_805CEA5C) > 0) {
        return 1;
    }
    if (a > 1 || o->m6F8->m14[2].m1 == 3) {
        return 0;
    }
    int r = 0;
    Unk8006A138_It<0x15> it(9);
    int idx = 9;
    do {
        unsigned k = idx;
        Unk801A71D0_Obj* p = k <= 12 ? (Unk801A71D0_Obj*)o->m65C[k] : 0;
        if (p != 0) {
            Unk801A71D0_Sub* s = &p->m58C;
            if (s->m4 & 0x20000000) {
                r = 0;
            } else {
                r = it.v < fn_8014E2B4(s->m38);
            }
        }
        idx = it.Next();
    } while (idx <= 12);
    return r;
}

int fn_801A72E0(Unk8019F8C0_Owner* o)
{
    int n = 0;
    for (int i = 0; i < 4; i++) {
        unsigned k = i + 9;
        Unk801A72E0_Obj* p = k <= 12 ? (Unk801A72E0_Obj*)o->m65C[k] : 0;
        if (p != 0) {
            Unk801A72E0_Sub* sub = &p->m58C;
            if (sub->m40 == 3 && sub->m44 == 0) {
                n++;
            }
        }
    }
    return n;
}

Unk801A734C::Unk801A734C(int a)
{
    m0 = a;
    m28 = 0;
    Reset();
}

void Unk801A734C::Reset()
{
    m1C = 0;
    m18 = 0;
    m38 = 0;
    m4 = lbl_806055AC;
    m24 = lbl_805CEA98;
    m10 = 0;
    m14 = 0;
    m20 = 0;
    m2C = 0;
    m30 = 0;
    m34 = 0;
}

Unk801A734C::~Unk801A734C() {}

void Unk801A734C::Clear()
{
    Init(0);
    Reset();
}

float fn_801A745C(Unk801A745C_T* t)
{
    float f = (float)fn_80326E64((char*)t->m0 + 0x50, 0) * lbl_805CEAA8;
    if (t->m18 != 0) {
        float g = fn_80189D60(t->m0->m6CC) + lbl_805CEAAC;
        if (!(g >= f)) {
            f = g;
        }
    }
    return f;
}

/* near-miss: same code; callee-saved roles differ (retail: buffer pointer r31, w r30, t r29, queue global r30;
 * mine: w/global r31, t r30, buffer r29), 13 slots. */
void fn_801A7764(void* w, int t)
{
    if (fn_801A7950((Unk801A57C8_Wrap*)w)) {
        *(int*)((char*)w + 0x18) = 1;
        fn_800B555C()->m570 = t;
        Unk8035682C buf;
        Unk8035682C* s = &buf;
        fn_8040B830(s, lbl_805CEAD4, 0xF);
        s->m0[0xF] = 0;
        if (lbl_8061A32C == 0) {
            lbl_8061A32C = new (0) Unk800B64BC;
        }
        fn_800B7B4C(lbl_8061A32C, s, 0);
    }
}

void fn_801A7808(Unk801A745C_T* t)
{
    t->m1C = 1;
    t->m38 = 2;
    t->m18 = 1;
    float a = fn_801A78E4((Unk801A57C8_Wrap*)t);
    float b = (float)fn_80326DF0((char*)t->m0 + 0x50, 0) * lbl_805CEAE8;
    float c = fn_801A745C(t);
    a = !((a + lbl_805CEAEC) > c) ? ((a + lbl_805CEAEC) >? b) : c;
    fn_801A0790(t->m0, a);
}

float fn_801A78E4(Unk801A57C8_Wrap* w)
{
    Unk801A78E4_Rec r;
    fn_80326F44(&r, (char*)w->m0 + 0x50, 0x3d, 1, lbl_805CEAF0);
    int ok = 1;
    if (r.m0 == 0xc7) {
        ok = 0;
    }
    return ok != 0 ? r.m4 : lbl_805CEAF0;
}

/* near-miss: same code; retail loads c->m3F4 into f31 before the fn_80190F0C call without a stack store (a register float
 * temporary), ours loads it after the call (86 vs 88 insns). */
int fn_801A7950(Unk801A57C8_Wrap* w)
{
    char* sub = (char*)w->m0 + 0x50;
    if (!fn_80326C20(sub)) {
        return 0;
    }
    if (!((Unk8016ACAC*)fn_801A6D84(w->m0, 1))->fn_8016AEEC()) {
        return 0;
    }
    float a = fn_801A78E4(w);
    if (a < lbl_805CEAF4) {
        return 0;
    }
    float b = (float)fn_80326DF0(sub, 0) * lbl_805CEB00;
    if (a < b) {
        return 0;
    }
    Unk801A7950_C* c = (Unk801A7950_C*)w->m0->m6CC;
    if (c->m38C == 2) {
        if (!(c->m3F4 >= fn_80190F0C(c) + lbl_805CEB04)) {
            return 0;
        }
    }
    if (((Unk801A57C8_Mode*)w->m0->m560)->m4->m14 == 6) {
        if (fn_801A4CE8(w->m0, 1)->fn_vslot9() == 0) {
            return 0;
        }
    }
    return 1;
}

void fn_801A7AB0(Unk801A57C8_Wrap* w)
{
    if (w->m0->m6F4 == 0) {
        int t = fn_801A2034(w->m0, 3);
        if (t != -1 && fn_801A700C((int)w->m0, t, 0x76) != 0) {
            fn_801A7764(w, t);
        }
    }
}

int fn_801A7B20(Unk8019F8C0_Owner** a, int* b)
{
    if ((*a)->m6F4 == 0xc) {
        int n = *b + 1;
        if (n <= 3) {
            *b = n;
            return 1;
        }
        return 0;
    }
    return 0;
}

/* near-miss: 32/32 insns; retail keeps the buffer pointer in r31 and the queue global's address in r30
 * (mine swaps them), 9 slots differ. */
void fn_801A7CBC()
{
    Unk8035682C buf;
    Unk8035682C* s = &buf;
    fn_8040B830(s, lbl_805CEB0C, 0xF);
    s->m0[0xF] = 0;
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = new (0) Unk800B64BC;
    }
    fn_800B7B4C(lbl_8061A32C, s, 0);
}

void fn_801A8198(char* p)
{
    *(int*)(p + 0x1C) = 0;
}

void fn_801A81A4(Unk801A57C8_Ob* o)
{
    int done = 0;
    do {
        int n = o->m38 + 1;
        o->m38 = n;
        if (n > 13) {
            o->m38 = 0;
        }
        if (o->m18 != 0) {
            if ((unsigned)lbl_805CEA60[o->m38] <= 1) {
                done = 1;
            }
        } else {
            int v = lbl_805CEA60[o->m38];
            if (v == 0 || v == 2) {
                done = 1;
            }
        }
    } while (done == 0);
}

void fn_801A8224(Unk801A57C8_Ob* o, int x)
{
    int f = (int)fn_802D7E2C(x, 0x39) != 0 ? 1 : 0;
    if (f != 0) {
        fn_801A81A4(o);
        fn_801A8198((char*)o);
    }
    if (o->m38 == 0) {
        fn_801A82A8(o, x);
    }
}

void fn_801A9428(Unk801A9428_T* t)
{
    if (t->m20 != 0) {
        fn_801A94EC(t);
        if (t->m18 != 0) {
            fn_80188044(t->m0->m6CC, 0);
        } else {
            int h = t->m0->m6CC;
            fn_80188698(h, lbl_805CEB90);
            fn_801889C0(h);
        }
    }
    Unk8019F8C0_Owner* o = t->m0;
    Unk8019F8C0_Sub* s = (Unk8019F8C0_Sub*)o->m54C;
    if (((Unk801A9428_Pair*)o->m700->m3BC)->m24 == 0) {
        if ((int)s == (int)fn_801A04A8(o, 5)) {
            if (((Unk8016ACAC*)s->m40)->fn_8016AD44()) {
                fn_80188044(t->m0->m6CC, 0);
            }
        }
    }
}

void fn_801A94EC(void* p)
{
    Unk801A94EC_T* t = (Unk801A94EC_T*)p;
    if (t->m14 == 0 && t->m38 == 0) {
        Unk801A94EC_V a = t->m4;
        Unk801A94EC_V b = a;
        a.y = fn_80301E44(t->m0, &b);
        fn_802FFAD4(&a, 0, 0, lbl_805CEB94);
    }
}

void fn_801A9584(Unk801A57C8_Timer* p)
{
    p->m34 = 1;
    int t = fn_80400E84() / 10;
    p->m30 = fn_80400DA4() + t;
    if (p->m28 != 0) {
        fn_80107F74(p->m28, 1, p->m2C);
        fn_80107F74(p->m28, 0, p->m2C ^ 1);
    }
}

Unk801A9610::Unk801A9610(int a, int b) : Unk801B5A44(a, b)
{
    Init();
}

Unk801A9610::~Unk801A9610() {}

void Unk801A9610::Init()
{
    fn_801AA038(this, 1);
}

int fn_801A96A8(int x)
{
    unsigned t = x - 2;
    int r = t;
    if (t <= 3) {
        return r;
    }
    return 0;
}

void fn_801A96C0(void* p)
{
    fn_801AA248(p);
}
