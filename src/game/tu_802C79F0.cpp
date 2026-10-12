/*
 * Game code, .text 0x802C79F0-0x802CBD04 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802C79F0.h"
#include "game/warp_b.h"
#include "game/tu_8000E618.h"

extern char lbl_806EF9E9;
extern char lbl_806EF9DD;
extern char lbl_806EF9CD;
extern char lbl_806EF9E7;
extern char lbl_806EF9E8;
extern char lbl_806EF9C7;
extern char lbl_806EF9C8;
extern char lbl_8061EC9C;
extern char lbl_806EF9F5;
extern char lbl_806EF9F6;
extern char lbl_805DEEC0[];
extern int lbl_805E1B34[];
extern const char lbl_805E1884[];
extern const char lbl_805E1898[];

void fn_803EDA0C(int p);
void fn_80377408(void* p);
void fn_80377488(void* p);
void* fn_803774A8(unsigned n, int heap);
int fn_80401904(int h);
void fn_804017B0(int h, int p);
void fn_80433004(int p, int n);
void* fn_8040B190(void* dst, const void* src, ...);
int fn_802B9300(const char* name, int a, int b, unsigned int* outn);
void fn_802CA5AC(int a, int b);
void fn_80314D60(int h);
extern const char lbl_805E186C[];
extern int lbl_806EE9F0;
void* operator new[](unsigned int n, int heap);
void* fn_802BB19C();
int fn_802BB27C(void* o, int idx);
void fn_802C851C(Unk802C851C* o);
void fn_802C8564(Unk802C851C* o);
extern const char lbl_8061D2BC[];
void fn_802AD2B8(void* a, void* b, int c, const char* d, int e);
Unk8000E618* fn_8000E65C();
extern int lbl_8061EC60[];
extern int lbl_8061EC70[];
extern int lbl_8061EC80[];
extern int lbl_8061EC90[];
extern const char lbl_805E1918[];
extern const char lbl_805E15E0[];
extern const void* lbl_80664250[];
extern int lbl_806EE9F0;
extern float lbl_805E1920;
extern const char lbl_8060D1CC[];
void fn_802C7C08(Unk802C7B54* o, int n, int i, char* p, int t);
void fn_802C7EF8(Unk802C7B54* o);
void fn_802C86B8(Unk802C7B54* o);
void fn_802C9EF4(void* p);
void fn_802C8748(Unk802C7B54* o, int n, int i, char* p, int t, char* q, int u);
int fn_802C91DC(int v);
int fn_804089B4(char* buf, const char* fmt, ...);
int fn_803ED634(const char* name, int size, int flags);
int fn_803ED604(const char* name, int size, int flags);
void fn_803D74A0(int a, const char* b, int c);
void fn_803E9A54(int a, const char* b, int* c, int* d);
int fn_802C8484(const char* name, int size);
void fn_802C85AC(char* p);
float fn_802AEAA0(Unk802AEB4C* o, int id);
float fn_802AE9C8(Unk802AEB4C* o, int id);

void fn_802C79F0(Unk802C7B54* o, int flag)
{
    int i;
    int n = lbl_805E1B34[0];
    int h = fn_802BB27C(fn_802BB19C(), 1);
    if (n > 0) {
        i = n;
        int off = 0;
        do {
            char* b = (char*)o + 0xA8;
            *(int*)(b + off) = fn_803ED634(lbl_805E186C, 0xD6D8, h | 0x400);
            if (*(int*)(b + off) == 0) {
                *(int*)(b + off) = fn_803ED604(lbl_805E186C, 0xD6D8, lbl_806EE9F0 | 0x400);
            }
            off += 0xC;
        } while (--i != 0);
    }
    o->m3D4 = flag ? 0xA : 0x23;
    int cnt = o->m3D4;
    Unk802C83A4* arr = new (0) Unk802C83A4[cnt];
    o->m3C0 = (char*)arr;
    for (i = 0; i < o->m3D4; i++) {
        fn_802C851C((Unk802C851C*)(o->m3C0 + i * 0x10));
    }
    for (i = 0; i < o->m3D4; i++) {
        fn_802C8564((Unk802C851C*)(o->m3C0 + i * 0x10));
    }
}

void fn_802C7B54(Unk802C7B54* o)
{
    int i = 0;
    if (i < o->m3D4) {
        int off = 0;
        do {
            i++;
            fn_802C85AC(o->m3C0 + off);
            off += 0x10;
        } while (i < o->m3D4);
    }
    int n = lbl_805E1B34[0];
    if (n > 0) {
        i = n;
        int off2 = 0;
        do {
            char* b = (char*)o + 0xA8;
            fn_803EDA0C(*(int*)(b + off2));
            *(int*)(b + off2) = 0;
            off2 += 0xC;
        } while (--i != 0);
    }
    o->m3D4 = 0;
    if (o->m3C0 != 0) {
        fn_80377488(o->m3C0);
        o->m3C0 = 0;
    }
}

Unk802C83A4::Unk802C83A4()
{
    m0 = 0;
    m4 = 0;
    m8 = 0;
    mC = 0;
}

void fn_802C7E80(Unk802C7B54* o)
{
    for (int i = 0; i <= 3; i++) {
        int n = lbl_805E1B34[i];
        if (n > 0) {
            fn_802C7C08(o, n, i, (char*)o + i * 0xC, lbl_8061EC60[i]);
        }
    }
}

/* near-miss (68 vs 68 insns, register names only): retail uses k in r29 and three separate byte-offset registers (r3/r4/r5) for the table loads and
   even indexes the k == 0 arm by r29 itself (k known to be 0 there); ours picks different registers. */
/* near-miss (66/68 insns): shared function-scope counter and invariant temps (b before a) match the loop shape; remaining diffs are the index/base operand order of the first loop's table load and which arm gets the copied base register. */
void fn_802C7EF8(Unk802C7B54* o)
{
    int i;
    for (i = 0; i < 2; i++) {
        fn_802AD2B8((char*)o + 0xF0 + i * 0x168, (char*)o + 0x30 + i * 0xC, *(int*)((char*)lbl_8061EC90 + i * 4), lbl_8061D2BC, 0x2E);
    }
    for (i = 0; i < 4; i++) {
        for (int j = 0; j < lbl_805E1B34[i]; j++) {
            char* b = (char*)o + 0x258;
            char* a = (char*)o + 0xF0;
            if (i == 0) {
                o->m3C4[i][j].m43C = a;
            } else {
                o->m3C4[i][j].m43C = b;
            }
        }
    }
}

void fn_802C8008(Unk802C7B54* o)
{
    fn_802C7E80(o);
    fn_802C7EF8(o);
    fn_802C86B8(o);
    fn_802C9EF4((char*)lbl_8061E978 + 0x125E0);
}

void fn_802C8058(Unk802C7B54* o)
{
    for (int k = 0; k < 4; k++) {
        if (o->m3C4[k] != 0) {
            for (int j = 0; j < lbl_805E1B34[k]; j++) {
                fn_80314D60(o->m3C4[k][j].m0);
                if (o->m3C4[k][j].m438->m0 != 0) {
                    fn_80314D60(o->m3C4[k][j].m438->m0);
                }
            }
        }
    }
}

void* fn_802C83C0(Unk802C83C0* o, int a, int* out)
{
    int h = o->m4;
    int n = fn_80401904(h);
    void* p = fn_803774A8(n, a);
    fn_804017B0(h, (int)p);
    if (out != 0) {
        *out = n;
    }
    return p;
}

void fn_802C8424(Unk802C83C0* o, int dst, int* out)
{
    int h = o->m0;
    int n = fn_80401904(h);
    fn_804017B0(h, dst);
    fn_80433004(dst, n);
    if (out != 0) {
        *out = n;
    }
}

int fn_802C8484(const char* name, int size)
{
    int flags = fn_8000E65C()->fn_8000E6F0() | 0x400;
    int h = fn_803ED634(name, size, flags);
    if (h == 0) {
        h = fn_803ED604(name, size, flags);
        if (h == 0) {
            h = fn_803ED604(name, size, flags);
            if (h == 0) {
                h = fn_803ED604(name, size, lbl_806EE9F0 | 0x400);
            }
        }
    }
    return h;
}

void fn_802C851C(Unk802C851C* o)
{
    o->m0 = fn_802C8484(lbl_805E1884, 0x7918);
    o->m8 = 0;
    o->mC = 0;
}

void fn_802C8564(Unk802C851C* o)
{
    o->m4 = fn_802C8484(lbl_805E1898, 0xFA0);
    o->m8 = 0;
    o->mC = 0;
}

void fn_802C85AC(Unk802C83A4* o)
{
    fn_803EDA0C(o->m0);
    o->m0 = 0;
    fn_803EDA0C(o->m4);
    o->m4 = 0;
}

void fn_802C85F0(Unk802C851C* o, const char* name)
{
    unsigned int n = 0;
    int buf = fn_802B9300(name, 0, 0xE, &n);
    fn_8040B190((void*)o->m0, (void*)buf, n);
    fn_80377408((void*)buf);
}

void fn_802C8654(Unk802C851C* o, const char* name)
{
    unsigned int n = 0;
    int buf = fn_802B9300(name, 0, 0xE, &n);
    fn_8040B190((void*)o->m4, (void*)buf, n);
    fn_80377408((void*)buf);
}

void fn_802C86B8(Unk802C7B54* o)
{
    for (int i = 1; i <= 3; i++) {
        int n = lbl_805E1B34[i];
        if (n > 0) {
            fn_802C8748(o, n, i, (char*)o + 0x48 + i * 0xC, lbl_8061EC70[i], (char*)o + 0x78 + i * 0xC, lbl_8061EC80[i]);
        }
    }
}

int fn_802C91DC(int v)
{
    int r = 0;
    if (v != 0) {
        if (v == 1) {
            r = 0xF;
        } else if (v == 2) {
            r = 0x1E;
        }
    }
    return r;
}

/* near-miss (2 slots): retail does subi r0,r30,0x384 after the call (add r30,r0,r3); ours folds the constant into the call result. */
void fn_802C920C(char* buf, Unk802C920C_Req* req)
{
    int n = req->m2C;
    if (req->m28 == 0) {
        n = fn_802C91DC(req->m74) + (n - 0x384);
    }
    int c = 0x67;
    if (req->m28 != 0) {
        c = 0x63;
    }
    fn_804089B4(buf, lbl_805E1918, c, n);
}

struct Unk802C94A0_List {
    int w[0x52];
};
extern const char lbl_806604E0[];
void* fn_8030AC4C(Unk802C94A0_List* p);

struct Unk802C94A0_SlotD {
    int m0;
    Unk802C94A0_List m4;
    int m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
    int m160;
};

class Unk802C94A0_Slot : public Unk802C94A0_SlotD {
public:
    Unk802C94A0_Slot()
    {
        m0 = 0;
        fn_8030AC4C(&m4);
        m14C = 0;
        m150 = 0;
        m154 = 0;
        m158 = 0;
        m15C = 0;
        m160 = 0;
    }
    virtual ~Unk802C94A0_Slot();
};

struct Unk802C94A0 {
    Unk802C94A0();
    Unk802C94A0_Slot a;
    Unk802C94A0_Slot b;
    Unk802C94A0_Slot c;
    Unk802C94A0_Slot* m438;
    int m43C;
    int m440;
    int m444;
    int m448[6];
    int m460;
    int m464;
    int m468;
    int m46C;
    char pad470[0x4B0 - 0x470];
    int m4B0;
};

/* near-miss (63 vs 64 insns): retail forms only the second slot's pointer (r28 = this + 0x168, shared with the +0x438 store) and addresses the other slots' fields off this; ours keeps pointers for both later slots. */
Unk802C94A0::Unk802C94A0()
{
    m438 = &b;
    m460 = 4;
    m43C = 0;
    m440 = 0;
    m444 = 0;
    for (int i = 0; i < 6; i++)
        m448[i] = 0;
    m464 = 0;
    m468 = 0;
    m46C = 0;
    m4B0 = 0;
}

/* near-miss (3 slots): retail puts the first loop's index in r11 and the found flag in r8 (ours r8/r11); declaration order and flag type did not change the allocation. */
extern "C" {
char* strcpy(char* d, const char* s);
char* strcat(char* d, const char* s);
}
extern const char lbl_805E1858[];
extern const char lbl_805E1860[];
extern int lbl_8061E9F4;
void fn_802C8BC8(Unk802C7B54* o, Unk802C920C_Req* req, void* rec, int c);

struct Unk802C9284_Rec {
    int m0;
    int m4;
    int m8;
    int mC;
};

void fn_802C9284(Unk802C7B54* o, int id, Unk802C920C_Req* req, int c, int skip)
{
    int idx = -1;
    unsigned char i = 0;
    int found = 0;
    if (i < o->m3D4) {
        Unk802C9284_Rec* rec = (Unk802C9284_Rec*)o->m3C0;
        if (rec[0].m8 == id) {
            found = 1;
            idx = 0;
        } else {
            for (;;) {
                i++;
                if (!(i < o->m3D4))
                    break;
                if (rec[i].m8 == id) {
                    idx = i;
                    found = 1;
                    break;
                }
            }
        }
    }
    if (!found) {
        int minVal = lbl_8061E9F4 - 1;
        int emptyIdx = -1;
        int minIdx = -1;
        int fnd2 = 0;
        unsigned char j = 0;
        unsigned char n = o->m3D4;
        if (j < n) {
            Unk802C9284_Rec* rec = (Unk802C9284_Rec*)o->m3C0;
            if (rec[0].m8 == 0) {
                emptyIdx = 0;
                fnd2 = 1;
            } else {
                for (;;) {
                    if (rec[j].mC < minVal) {
                        minVal = rec[j].mC;
                        minIdx = j;
                    }
                    j++;
                    if (!(j < n))
                        break;
                    if (rec[j].m8 == 0) {
                        emptyIdx = j;
                        fnd2 = 1;
                        break;
                    }
                }
            }
        }
        if (fnd2 != 0) {
            idx = emptyIdx;
        } else if (minIdx == -1) {
            return;
        } else {
            idx = minIdx;
        }
        Unk802C9284_Rec* e = (Unk802C9284_Rec*)(o->m3C0 + idx * 16);
        char buf1[0x40] = "";
        char buf2[0x40] = "";
        fn_802C920C(buf1, req);
        strcpy(buf2, buf1);
        strcat(buf2, lbl_805E1858);
        fn_802C85F0((Unk802C851C*)e, buf2);
        strcpy(buf2, buf1);
        strcat(buf2, lbl_805E1860);
        fn_802C8654((Unk802C851C*)e, buf2);
        e->m8 = id;
        e->mC = lbl_8061E9F4;
    }
    if (skip == 0)
        fn_802C8BC8(o, req, o->m3C0 + idx * 16, c);
}

void fn_802C959C(Unk802C95F8* o, int v)
{
    if (v != o->m4B0) {
        if (o->m438->m0 != 0) {
            fn_803D74A0(o->m438->m0, lbl_805E15E0, v);
        }
        o->m4B0 = v;
    }
}

Unk802C9618::Unk802C9618()
{
    m4908 = 0;
    m490C = lbl_80664250;
    for (int i = 0; i < 0x26; i++) {
        for (int j = 0; j < 0x52; j++) {
            rows[i].f[j] = lbl_805E1920;
        }
        for (int k = 0; k < 0x29; k++) {
            rows[i].g[k] = 0;
        }
    }
}

void fn_802C95F8(Unk802C95F8* o, int flag)
{
    if (flag != 0) {
        o->m438 = (Unk802C95F8_Sub*)((char*)o + 0x2D0);
    } else {
        o->m438 = (Unk802C95F8_Sub*)((char*)o + 0x168);
    }
}

void fn_802C968C(Unk802C9618* o, int c)
{
    o->m490C = lbl_80664250;
    o->m4908 = 0;
    if (c & 1) {
        fn_80377408(o);
    }
}

int fn_802CA518(int a, const char* b, int c);
extern const char lbl_805E1144[];
extern const char lbl_805E114C[];
extern const char lbl_805E1158[];
extern const char lbl_805E1164[];
extern const char lbl_805E116C[];
extern const char lbl_805E1174[];
extern const char lbl_805E117C[];
extern const char lbl_805E1184[];
extern const char lbl_805E118C[];
extern const char lbl_805E1194[];
extern const char lbl_805E11A4[];
extern const char lbl_805E11B4[];
extern const char lbl_805E11BC[];
extern const char lbl_805E1924[];
extern const char lbl_805E192C[];
extern const char lbl_805E1930[];
extern const char lbl_805E193C[];
extern const char lbl_805E1948[];
extern const char lbl_805E1950[];
extern const char lbl_805E1958[];
extern const char lbl_805E195C[];
extern const char lbl_805E1964[];
extern const char lbl_805E1970[];
extern const char lbl_805E1978[];
extern const char lbl_805E1980[];
extern const char lbl_805E198C[];
extern const char lbl_805E1998[];
extern const char lbl_805E19A4[];
extern const char lbl_805E19B0[];
extern const char lbl_805E19BC[];
extern const char lbl_805E19C8[];
extern const char lbl_805E19D4[];
extern const char lbl_805E19D8[];
extern const char lbl_805E19E0[];
extern const char lbl_805E19E8[];
extern const char lbl_805E19F0[];
extern const char lbl_805E19F8[];
extern const char lbl_805E1A00[];
extern const char lbl_805E1A08[];
extern const char lbl_805E1A10[];
extern const char lbl_805E1A18[];
extern const char lbl_805E1A20[];
extern const char lbl_805E1A28[];
extern const char lbl_805E1A34[];
extern const char lbl_805E1A40[];
extern const char lbl_805E1A48[];
extern const char lbl_805E1A50[];
extern const char lbl_805E1A58[];
extern char lbl_806EF9C4;
extern char lbl_806EF9C5;
extern char lbl_806EF9C6;
extern char lbl_806EF9C7;
extern char lbl_806EF9C8;
extern char lbl_806EF9C9;
extern char lbl_806EF9CA;
extern char lbl_806EF9CB;
extern char lbl_806EF9CC;
extern char lbl_806EF9CD;
extern char lbl_806EF9DC;
extern char lbl_806EF9DD;
extern char lbl_806EF9DE;
extern char lbl_806EF9DF;
extern char lbl_806EF9E0;
extern char lbl_806EF9E1;
extern char lbl_806EF9E2;
extern char lbl_806EF9E3;
extern char lbl_806EF9E4;
extern char lbl_806EF9E5;
extern char lbl_806EF9E6;
extern char lbl_806EF9E7;
extern char lbl_806EF9E8;
extern char lbl_806EF9E9;
extern char lbl_806EF9EA;
extern char lbl_806EF9EB;
extern char lbl_806EF9EC;
extern char lbl_806EF9ED;
extern char lbl_806EF9EE;
extern char lbl_806EF9EF;
extern char lbl_806EF9F0;
extern char lbl_806EF9F1;
extern char lbl_806EF9F2;
extern char lbl_806EF9F3;
extern char lbl_806EF9F4;
extern char lbl_806EF9F5;
extern char lbl_806EF9F6;
extern char lbl_806EF9F7;
extern char lbl_806EF9F8;
extern char lbl_806EF9F9;
extern char lbl_806EF9FA;
extern char lbl_806EF9FB;
extern char lbl_806EF9FC;
extern char lbl_806EF9FD;
extern char lbl_806EF9FE;
extern char lbl_806EF9FF;
extern char lbl_806EFA00;
extern char lbl_806EFA01;
extern int lbl_8061EC98;
extern int lbl_8068DA50[];

void fn_802C96C8(int a, int b)
{
    if (lbl_8061EC98 == 0) {
        lbl_806EF9C7 = fn_802CA518(a, lbl_805E1924, b);
        lbl_806EF9E6 = fn_802CA518(a, lbl_805E192C, b);
        lbl_806EF9C4 = fn_802CA518(a, lbl_805E1930, b);
        lbl_806EF9C5 = fn_802CA518(a, lbl_805E193C, b);
        lbl_806EF9E7 = fn_802CA518(a, lbl_805E1948, b);
        lbl_806EF9E8 = fn_802CA518(a, lbl_805E1950, b);
        lbl_806EF9E9 = fn_802CA518(a, lbl_805E1958, b);
        lbl_806EF9DD = fn_802CA518(a, lbl_805E1144, b);
        lbl_806EF9CD = fn_802CA518(a, lbl_805E195C, b);
        lbl_806EF9C8 = fn_802CA518(a, lbl_805E1964, b);
        lbl_806EF9CA = fn_802CA518(a, lbl_805E117C, b);
        lbl_806EF9CB = fn_802CA518(a, lbl_805E1164, b);
        lbl_806EF9C6 = fn_802CA518(a, lbl_805E1970, b);
        lbl_806EF9C9 = fn_802CA518(a, lbl_805E1978, b);
        lbl_806EF9DE = fn_802CA518(a, lbl_805E116C, b);
        lbl_806EF9DF = fn_802CA518(a, lbl_805E1174, b);
        lbl_806EF9E0 = fn_802CA518(a, lbl_805E1184, b);
        lbl_806EF9E1 = fn_802CA518(a, lbl_805E118C, b);
        lbl_806EF9DC = fn_802CA518(a, lbl_805E114C, b);
        lbl_806EF9CC = fn_802CA518(a, lbl_805E1158, b);
        lbl_806EF9E2 = fn_802CA518(a, lbl_805E1980, b);
        lbl_806EF9E3 = fn_802CA518(a, lbl_805E198C, b);
        lbl_806EF9E4 = fn_802CA518(a, lbl_805E11B4, b);
        lbl_806EF9E5 = fn_802CA518(a, lbl_805E11BC, b);
        lbl_806EF9F0 = fn_802CA518(a, lbl_805E1998, b);
        lbl_806EF9EB = fn_802CA518(a, lbl_805E19A4, b);
        lbl_806EF9EA = fn_802CA518(a, lbl_805E19B0, b);
        lbl_806EF9EC = fn_802CA518(a, lbl_805E1194, b);
        lbl_806EF9ED = fn_802CA518(a, lbl_805E19BC, b);
        lbl_806EF9EE = fn_802CA518(a, lbl_805E19C8, b);
        lbl_806EF9EF = fn_802CA518(a, lbl_805E11A4, b);
        lbl_806EF9F4 = fn_802CA518(a, lbl_805E19D4, b);
        lbl_806EF9F5 = fn_802CA518(a, lbl_805E19D8, b);
        lbl_806EF9F6 = fn_802CA518(a, lbl_805E19E0, b);
        lbl_806EF9F7 = fn_802CA518(a, lbl_805E19E8, b);
        lbl_806EF9F8 = fn_802CA518(a, lbl_805E19F0, b);
        lbl_806EF9F9 = fn_802CA518(a, lbl_805E19F8, b);
        lbl_806EF9FA = fn_802CA518(a, lbl_805E1A00, b);
        lbl_806EF9FB = fn_802CA518(a, lbl_805E1A08, b);
        lbl_806EF9F1 = fn_802CA518(a, lbl_805E1A10, b);
        lbl_806EF9FC = fn_802CA518(a, lbl_805E1A18, b);
        lbl_806EF9F2 = fn_802CA518(a, lbl_805E1A20, b);
        lbl_806EF9F3 = fn_802CA518(a, lbl_805E1A28, b);
        lbl_806EF9FD = fn_802CA518(a, lbl_805E1A34, b);
        lbl_806EF9FE = fn_802CA518(a, lbl_805E1A40, b);
        lbl_806EF9FF = fn_802CA518(a, lbl_805E1A48, b);
        lbl_806EFA00 = fn_802CA518(a, lbl_805E1A50, b);
        lbl_806EFA01 = fn_802CA518(a, lbl_805E1A58, b);
        lbl_8068DA50[0] = lbl_806EF9C7;
        lbl_8068DA50[1] = lbl_806EF9CC;
        lbl_8068DA50[2] = lbl_806EF9F0;
        lbl_8068DA50[3] = lbl_806EF9DC;
        lbl_8068DA50[4] = lbl_806EF9EB;
        lbl_8068DA50[5] = lbl_806EF9E4;
        lbl_8068DA50[6] = lbl_806EF9EA;
        lbl_8068DA50[7] = lbl_806EF9E2;
        lbl_8068DA50[8] = lbl_806EF9EC;
        lbl_8068DA50[9] = lbl_806EF9ED;
        lbl_8068DA50[10] = lbl_806EF9E5;
        lbl_8068DA50[11] = lbl_806EF9EE;
        lbl_8068DA50[12] = lbl_806EF9E3;
        lbl_8068DA50[13] = lbl_806EF9EF;
        lbl_8068DA50[14] = lbl_806EF9DF;
        lbl_8068DA50[15] = lbl_806EF9DE;
        lbl_8068DA50[16] = lbl_806EF9E1;
        lbl_8068DA50[17] = lbl_806EF9E0;
        lbl_8068DA50[18] = lbl_806EF9CD;
        lbl_8068DA50[19] = lbl_806EF9DD;
        lbl_8068DA50[20] = lbl_806EF9F4;
        lbl_8068DA50[21] = lbl_806EF9CA;
        lbl_8068DA50[22] = lbl_806EF9CB;
        lbl_8068DA50[23] = lbl_806EF9F5;
        lbl_8068DA50[24] = lbl_806EF9F6;
        lbl_8068DA50[25] = lbl_806EF9F7;
        lbl_8068DA50[26] = lbl_806EF9F8;
        lbl_8068DA50[27] = lbl_806EF9F9;
        lbl_8068DA50[28] = lbl_806EF9FA;
        lbl_8068DA50[29] = lbl_806EF9FB;
        lbl_8068DA50[30] = lbl_806EF9F1;
        lbl_8068DA50[31] = lbl_806EF9FC;
        lbl_8068DA50[32] = lbl_806EF9F2;
        lbl_8068DA50[33] = lbl_806EF9F3;
        lbl_8068DA50[34] = lbl_806EF9FD;
        lbl_8068DA50[35] = lbl_806EF9FE;
        lbl_8068DA50[36] = lbl_806EF9FF;
        lbl_8068DA50[37] = lbl_806EFA00;
        lbl_8068DA50[38] = lbl_806EFA01;
        lbl_8068DA50[39] = lbl_806EF9C9;
        lbl_8068DA50[40] = lbl_806EF9C6;
        lbl_8061EC98 = 1;
    }
}

void fn_802C9EA4(Unk802C9618* o, int a)
{
    int sp8 = 0;
    int spC;
    fn_803E9A54(a, lbl_8060D1CC, &sp8, &spC);
    o->m4908 = spC;
}

extern const char lbl_8060D1C4[];
char* fn_8040B448(char* d, const char* s);
void fn_803E910C(int a, const char* b, char* c, int** d);

int fn_802CA518(int a, const char* b, int c)
{
    char buf[14] = "FBXdummyNode.";
    char pad[0x70];
    int* r;
    fn_8040B448(buf, b);
    fn_803E910C(c, lbl_8060D1C4, buf, &r);
    int ret = -1;
    if (r != 0)
        ret = *r;
    return ret;
}

Unk802CA5A0_Elem* fn_802CA5A0(Unk802CA5A0_Elem* t, int i)
{
    return &t[i];
}


float fn_802CB67C(Unk802AEB4C* o, int id)
{
    return o->fn_802AEB4C(id);
}

char* fn_802CB69C()
{
    return lbl_805DEEC0;
}

float fn_802CB6A8(Unk802AEB4C* o, int id)
{
    return fn_802AEAA0(o, id);
}

float fn_802CB6C8(Unk802AEB4C* o, int id)
{
    return fn_802AE9C8(o, id);
}

char fn_802CB6E8()
{
    return lbl_806EF9E9;
}

char fn_802CB6F8()
{
    return lbl_806EF9DD;
}

char fn_802CB708()
{
    return lbl_806EF9CD;
}

char fn_802CB718()
{
    return lbl_806EF9E7;
}

char fn_802CB728()
{
    return lbl_806EF9E8;
}

char fn_802CB738()
{
    return lbl_806EF9C7;
}

char fn_802CB748()
{
    return lbl_806EF9C8;
}

char fn_802CB758()
{
    return lbl_8061EC9C;
}

char fn_802CB768()
{
    return lbl_806EF9E9;
}

int fn_802CB778()
{
    return 0xF;
}

char fn_802CB780()
{
    return lbl_806EF9F5;
}

int fn_802CB790()
{
    return 8;
}

char fn_802CB798()
{
    return lbl_806EF9F6;
}

int fn_802CB7A8()
{
    return 8;
}

void fn_802CB7B0()
{
    fn_802CA5AC(1, 0xFFFF);
}

void fn_802CB7DC()
{
    fn_802CA5AC(0, 0xFFFF);
}
