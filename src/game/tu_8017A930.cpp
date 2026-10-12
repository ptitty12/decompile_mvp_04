/*
 * Game code, .text 0x8017A930-0x8017D640 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8017A930.h"
extern char lbl_80660368[];
extern char lbl_80649DA0[];
struct Unk8017B6C0_Pair {
    int a;
    int b;
};
struct Unk8017B6C0_Msg {
    int m0;
    const void* vptr;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    void Base(int id)
    {
        vptr = lbl_80649DA0;
        m0 = id;
    }
    void Derived()
    {
        vptr = lbl_80660368;
        m20 = 0;
        m10 = 0;
    }
    void Fill(int a18, int a1C, int a8, int aC, int a10, int a14, int a20)
    {
        m18 = a18;
        m1C = a1C;
        m8 = a8;
        mC = aC;
        m10 = a10;
        m14 = a14;
        m20 = a20;
    }
    void End() { vptr = lbl_80649DA0; }
};
struct Unk8017B6C0_A {
    char pad0[0x38];
    int m38;
};
struct Unk8017B6C0_B {
    char pad0[0x24];
    int m24;
};
struct Unk8017B6C0_P {
    char pad0[0x704];
    int m704;
};
extern "C" Unk8017B6C0_Pair fn_8022EA60(...);
inline Unk8017B6C0_Pair Unk8017B6C0_Now()
{
    return fn_8022EA60();
}
void fn_801BB544(void* p, int a, int b);
void fn_801DBC00(void* p, int a, int b);
void fn_80258194(void* p, int a, int b);
void fn_802358D0(void* p, int a, int b);
void fn_801C2B84(void* p, int a, int b);
void fn_801BBB34(void* p);
extern int lbl_80620864;
struct Unk8017B238_O {
    char pad0[0x2C];
    int m2C;
};
void fn_8017EE58(Unk8017EE24_T* p);
void fn_8017EED0(void* p);
void fn_801A4884(void* p);
void fn_80235618(void* p);
void fn_801C21EC(void* p);
void fn_801B0334(void* p);
void fn_801ABB0C(void* p);
void fn_801B127C(void* p);
void fn_801BAFA4(void* p);
void fn_801DBAE4(void* p);
void fn_80258668(void* p);
void fn_80178CA8(void* p);
void fn_8017BEAC(void* p, char* q);
void fn_80258E70(void* p, int q);
void fn_801DBC24(void* p, int a);
void fn_801C2A18(void* p, int a);
void fn_8024F930(void* p, int a, int b);
extern char lbl_8065F9C8[];
struct Unk8017BCB4_R {
    char pad0[0x1C];
    int m1C;
};
struct Unk8017BCB4_Msg {
    int m0;
    const void* vptr;
    void* m8;
    void Base(int id)
    {
        vptr = lbl_80649DA0;
        m0 = id;
    }
    void Derived() { vptr = lbl_8065F9C8; }
    void Set(void* a) { m8 = a; }
    void End() { vptr = lbl_80649DA0; }
};
extern "C" {
void fn_801BAF08(void* p);
void fn_801DBD5C(void* p);
Unk8017BCB4_R* fn_801A6DB8(void* o);
void fn_80198DD8(void* o, int a);
void fn_80189300(void* o, int a);
}
void fn_80235A28(void* p);
void fn_80257258(void* p);
void fn_801A987C(void* p);
void fn_801B131C(void* p);
extern int lbl_80620860;
extern int lbl_80620870;
extern float lbl_8062086C;
void fn_801A0790(Unk8017B0A4_Ctx* o, float v);
void fn_8017EE54();
void fn_801A9700(void* p);
void fn_801AB63C(void* p);
void fn_801DBB08(void* p);
void fn_80235300(void* p);
void fn_801C2120(void* p);
void fn_80176884(void* p);
void fn_80178BBC(void* p);

inline float Unk8017D0F4_Clamp(float lo, float v, float hi)
{
    return !(v > hi) ? (v >? lo) : hi;
}

struct Unk8017CC70_Ev {
    int m0;
    char pad4[0xC];
    float m10;
};
extern float lbl_805EBA04;
extern float lbl_805EBA08;

void fn_8017AC0C(Unk8017A930_T* p)
{
    fn_80235220(p->m3B0);
    fn_801C4D04(p->m3A4);
    if (p->m4->m6F4 == 0) {
        fn_80176FD0(p->m3A8);
    }
    fn_80178CF8(p->m3AC);
    fn_802570E0(p->m3B4);
    fn_80179D90(p->m4);
    fn_8017A1FC(p->m4);
}

void fn_8017AF30(Unk8017A930_T* p)
{
    fn_8017C6BC(p);
    fn_8017EE24((Unk8017EE24_T*)((char*)p + 8));
    if (p->m4->m6F4 == 0) {
        fn_80176740(p->m3A8);
    }
}

void fn_8017AF7C(Unk8017A930_T* p)
{
    fn_80176B90(p->m3A8);
}

extern "C" void fn_8017AFA0(void* self)
{
    Unk8017A930_T* p = (Unk8017A930_T*)self;
    if (lbl_80620860 != 0) {
        int t = lbl_80620870;
        if (t == 1) {
            Unk8017B0A4_Ctx* o = p->m4;
            lbl_80620860 = 0;
            lbl_8062086C = (float)o->m4C * 0.016666668f - 0.033333335f;
            fn_801A0790(o, lbl_8062086C);
            lbl_80620860 = t;
        }
    }
    ((void (*)(void*))fn_8017EE54)((char*)p + 8);
    fn_801A9700(p->m3C4);
    fn_801AB63C(p->m3C8);
    fn_801DBB08(p->m3B8);
    fn_80235300(p->m3B0);
    fn_801C2120(p->m3A4);
    if (p->m4->m6F4 == 0) {
        fn_80176884(p->m3A8);
    }
    fn_80178BBC(p->m3AC);
    p->m3D8 = -1;
    fn_8017E264(p);
    fn_803295F0();
}

void fn_8017B0A4(Unk8017A930_T* p)
{
    if (p->m4->m6F4 == 0) {
        fn_8017671C(p->m3A8);
    }
}

void fn_8017B0D8(Unk8017A930_T* p)
{
    fn_80186890(p->m4->m6C0);
    fn_801A1EDC(p->m4);
    if (p->m4->m6F4 != 9) {
        fn_801C2144(p->m3A4);
        fn_8023538C(p->m3B0);
    }
    if (p->m4->m6F4 == 0) {
        fn_801ABAA0(p->m3C8);
        fn_801B1220(p->m3CC);
        fn_801A9724(p->m3C4);
    }
    fn_801DBA9C(p->m3B8);
    fn_80258644(p->m3B4);
    fn_80176B70(p->m3A8);
    fn_80178C5C(p->m3AC);
    p->m418 = 0;
    fn_8037893C((char*)p->m4 + 0x704, 0x2F, 0, 0, 0);
    fn_803295F0();
}

void fn_8017B1A4(Unk8017A930_T* p)
{
    fn_801C2544(p->m3A4);
    fn_8023533C(p->m3B0);
    fn_801A98A0(p->m3C4);
    if (p->m4->m6F4 == 0) {
        fn_801AB6A0(p->m3C8);
        fn_801B1190(p->m3CC);
    }
    fn_801BAE90(p->m3BC);
    fn_801DBAC0(p->m3B8);
    fn_802585E8(p->m3B4);
    fn_80178C08(p->m3AC);
    p->m3D4 = 0;
    fn_8017E264(p);
    fn_803295F0();
}

extern "C" void fn_8017B238(void* self)
{
    Unk8017A930_T* p = (Unk8017A930_T*)self;
    if (lbl_80620860 != 0) {
        if (lbl_80620870 == 2) {
            Unk8017B0A4_Ctx* o = p->m4;
            lbl_80620860 = 0;
            lbl_8062086C = (float)o->m4C * 0.016666668f - 0.033333335f;
            fn_801A0790(o, lbl_8062086C);
            lbl_80620860 = 1;
        }
    }
    (*(Unk8017B238_O**)((char*)p->m4 + 0x720))->m2C = 1;
    if (lbl_80620860 != 0) {
        int t = lbl_80620864;
        if (t > 0) {
            if (!(t > p->m4->m6F8->m14->m1CC8)) {
                Unk8017B0A4_Ctx* c = p->m4;
                lbl_80620860 = 0;
                fn_801A0790(c, (float)c->m4C * 0.016666668f);
            }
        }
    }
    fn_8017EE58((Unk8017EE24_T*)((char*)p + 8));
    int z = 0;
    fn_801A4884(p->m4);
    *(int*)((char*)p->m4 + 0x6FC) = z;
    fn_80235618(p->m3B0);
    fn_801C21EC(p->m3A4);
    if (p->m4->m6F4 == 0) {
        fn_801B0334(p->m3C0);
        fn_801ABB0C(p->m3C8);
        fn_801B127C(p->m3CC);
    }
    fn_801BAFA4(p->m3BC);
    fn_801DBAE4(p->m3B8);
    fn_80258668(p->m3B4);
    fn_80178CA8(p->m3AC);
    p->m414 = z;
    p->m418 = z;
    *(int*)((char*)p + 0x41C) = 10;
    fn_8017EED0((char*)p + 0x228);
    fn_8037893C((char*)p->m4 + 0x704, 0x31, 0, 0, 0);
    fn_801A1EDC(p->m4);
    if (p->m4->m6F4 == 0) {
        fn_8017BEAC(p, lbl_8068BE40);
    }
    fn_803295F0();
}

void fn_8017B434(Unk8017A930_T* p)
{
    fn_801A98C4(p->m3C4);
    fn_801DBB2C(p->m3B8);
    fn_80258E64(p->m3B4);
    fn_80235364(p->m3B0);
}

void fn_8017B47C(Unk8017A930_T* p)
{
    fn_801DBB50(p->m3B8);
}

void fn_8017B4A0(Unk8017A930_T* p, int a)
{
    fn_801BB0F4(p->m3BC);
    fn_80258BA8(p->m3B4, a);
    fn_802356D4(p->m3B0, a);
    fn_801C26FC(p->m3A4, a);
}

void fn_8017B4F8(Unk8017A930_T* p)
{
    p->m18 = 1;
    fn_801A985C(p->m3C4);
    fn_801BB13C(p->m3BC);
    fn_801DBB74(p->m3B8);
    fn_80258000(p->m3B4);
    fn_801C2724(p->m3A4);
    fn_801A1EDC(p->m4);
}

void fn_8017B558(Unk8017A930_T* p, int a)
{
    fn_80235730(p->m3B0);
    fn_80258048(p->m3B4, a);
    fn_801C277C(p->m3A4, a);
}

void fn_8017B5A4(Unk8017A930_T* p)
{
    if (fn_801DC10C(p->m3B8) != 0xB) {
        fn_801BB194(p->m3BC);
        fn_80258390(p->m3B4);
        fn_801C2A40(p->m3A4);
    }
}

void fn_8017B5F4(Unk8017A930_T* p, int a)
{
    fn_801BB1E0(p->m3BC);
    fn_801DBB98(p->m3B8, a);
    fn_80258098(p->m3B4, a);
    fn_8023584C(p->m3B0, a);
    fn_801C2AD0(p->m3A4, a);
}

void fn_8017B658(Unk8017A930_T* p, int a)
{
    fn_801BB4D8(p->m3BC);
    fn_801DBBBC(p->m3B8, a);
    fn_80258250(p->m3B4, a);
    fn_801C2C10(p->m3A4, a);
    if (a == 0) {
        p->m410 = 1;
    }
}

/* near-miss: 96.5%; extra callee-saved register: ours keeps &pr (the 8-byte struct fn_8022EA60 returns through r3) in
 * r30 across the call, retail addresses it off r1 and has no frame word for it. Fill() gives the this-relative
 * (r31) msg stores. fn_8022EA60 is called with an empty ellipsis (crclr). */
extern "C" void fn_8017B6C0(void* self, int a, int b)
{
    Unk8017A930_T* p = (Unk8017A930_T*)self;
    if (b == 1) {
        fn_8037893C((char*)p->m4 + 0x704, 0x30, 0, 0, 0);
    }
    fn_801BB544(p->m3BC, a, b);
    fn_801DBC00(p->m3B8, a, b);
    fn_80258194(p->m3B4, a, b);
    fn_802358D0(p->m3B0, a, b);
    fn_801C2B84(p->m3A4, a, b);
    if (b == 1) {
        fn_801BBB34(p->m3BC);
    }
    Unk8017B6C0_Msg m;
    m.Base(0x3A);
    m.Derived();
    int flag = 0;
    if (((Unk8017B6C0_A*)p->m3B0)->m38 != 0 || b != 0) {
        flag = 1;
    }
    Unk8017B6C0_P* x = *(Unk8017B6C0_P**)((char*)p->m4 + 0x65C);
    Unk8017B6C0_P* y = *(Unk8017B6C0_P**)((char*)p->m4 + 0x680);
    Unk8017B6C0_Pair pr = Unk8017B6C0_Now();
    m.Fill(pr.a, pr.b, y->m704, x->m704, flag, a, ((Unk8017B6C0_B*)p->m3BC)->m24);
    fn_8037893C((char*)p->m4 + 0x704, m.m0, (int)&m, 0, 0);
    m.End();
}

struct Unk8017B83C_S {
    char pad0[0xC];
    int mC;
    int m10;
};
void fn_8017B83C(Unk8017A930_T* p, int a)
{
    Unk8017B83C_S* s = (Unk8017B83C_S*)((char*)p + 8);
    s->mC = 1;
    s->m10 = 0;
    *(int*)((char*)p + 0x41C) = a;
    fn_80258E70(p->m3B4, a);
    fn_801DBC24(p->m3B8, a);
    fn_801C2A18(p->m3A4, a);
    switch (a) {
    case 0xC:
        fn_8024F930((char*)p->m4->m660 + 0x4D8, 3, 0);
        break;
    case 0xF:
    case 0x10:
        fn_8024F930((char*)fn_801C1638(p->m4, 0) + 0x4D8, 2, 0);
        break;
    }
    switch (a) {
    case 0xC:
        fn_8037893C((char*)p->m4 + 0x704, 0x4C, 0, 0, 0);
        break;
    case 0xF:
        fn_8037893C((char*)p->m4 + 0x704, 0x4F, 0, 0, 0);
        break;
    case 0x10:
        fn_8037893C((char*)p->m4 + 0x704, 0x4B, 0, 0, 0);
        break;
    case 0xE:
        fn_8037893C((char*)p->m4 + 0x704, 0x4E, 0, 0, 0);
        break;
    case 0x11:
        fn_8037893C((char*)p->m4 + 0x704, 0x4D, 0, 0, 0);
        break;
    }
}

void fn_8017B994(Unk8017A930_T* p)
{
    p->m414 = 1;
    fn_801BB1A4(p->m3BC);
    fn_801DBC48(p->m3B8);
    fn_80258354(p->m3B4);
    fn_8037893C((char*)p->m4 + 0x704, 0x74, 0, 0, 0);
}

void fn_8017B9F8(Unk8017A930_T* p)
{
    fn_801B03B8(p->m3C0);
    fn_801BB65C(p->m3BC);
    fn_801DBC6C(p->m3B8);
    fn_80258444(p->m3B4);
    fn_8023590C(p->m3B0);
    fn_801C2C64(p->m3A4);
}

/* near-miss: argument copies land in r27..r29 in a different order (7 slots). */
void fn_8017BA50(Unk8017A930_T* p, int a, int b, int c)
{
    fn_802595E0(p->m3B4);
    fn_801DBE78(p->m3B8, a, b, c);
}

/* near-miss: same argument register order issue as fn_8017BA50. */
void fn_8017BAA0(Unk8017A930_T* p, int a, int b, int c)
{
    fn_801DBC90(p->m3B8);
    fn_80258E40(p->m3B4, a, b, c);
    fn_801C2F28(p->m3A4, a, b, c);
    fn_801B0354(p->m3C0, a, b, c);
}

void fn_8017BB18(Unk8017A930_T* p)
{
    fn_801BB800(p->m3BC);
}

void fn_8017BB3C(Unk8017A930_T* p)
{
    fn_801DBCB4(p->m3B8);
}

void fn_8017BB60(Unk8017A930_T* p)
{
    fn_8017EE70((Unk8017EE24_T*)((char*)p + 8));
    fn_801DBD14(p->m3B8);
    fn_801C30F8(p->m3A4);
    fn_802592E8(p->m3B4);
    fn_8023596C(p->m3B0);
    fn_801BB994(p->m3BC);
    p->m410 = 0;
    fn_8037893C((char*)p->m4 + 0x704, 0x32, 0, 0, 0);
    fn_8017EEAC((char*)p + 0x228, p->m4);
    fn_801A1EDC(p->m4);
    fn_803295F0();
}

void fn_8017BBF4(Unk8017A930_T* p)
{
    fn_801BB988(p->m3BC);
    fn_801DBD38(p->m3B8);
    fn_802591D0(p->m3B4);
    if (p->m4->m6F4 != 9) {
        fn_8017EA6C(p);
        if (lbl_8061C688 != 0) {
            lbl_8061B8C0->m20 = 2;
        }
    }
    if (p->m4->m6F4 == 0) {
        fn_801ABBA8(p->m3C8);
        fn_801B12C0(p->m3CC);
    }
    fn_8037893C((char*)p->m4 + 0x704, 0x33, 0, 0, 0);
    fn_801A1EDC(p->m4);
    fn_803295F0();
}

void fn_8017BCB4(void* self)
{
    Unk8017A930_T* p = (Unk8017A930_T*)self;
    fn_801BAF08(p->m3BC);
    fn_80235A28(p->m3B0);
    fn_801DBD5C(p->m3B8);
    fn_80257258(p->m3B4);
    fn_801A987C(p->m3C4);
    fn_801B131C(p->m3CC);
    if (fn_801A6DB8(p->m4)->m1C != 0) {
        fn_80198DD8(p->m4->m6E4, 0);
        p->m4->m6E4->fn_vslot8(1);
        fn_80189300(p->m4->m6CC, 0);
        p->m4->m6CC->fn_vslot8(1);
    }
    Unk8017BCB4_Msg m;
    m.Base(0x34);
    m.Derived();
    m.Set((char*)p->m4 + 0x704);
    fn_8037893C((char*)p->m4 + 0x704, m.m0, (int)&m, 0, 0);
    fn_803295F0();
    m.End();
}

void fn_8017BDD4(Unk8017A930_T* p)
{
    if (p->m4->m6F4 == 0) {
        fn_801AD38C(p->m3C8);
    }
    fn_802572CC(p->m3B4);
    fn_80176780(p->m3A8);
    fn_803295F0();
}

void fn_8017BE28(Unk8017A930_T* p)
{
    p->m4->m6CC->fn_vslot8(1);
    if (p->m4->m6F4 == 0) {
        fn_801B032C(p->m3C0);
    }
    fn_801766FC(p->m3A8);
    fn_801C20CC(p->m3A4);
    fn_80235294(p->m3B0);
    fn_801DBD80(p->m3B8);
}

void fn_8017C5F0(Unk8017A930_T* p, int a)
{
    int s0;
    int s1;
    Unk8017C954_Mid* m = p->m4->m6F8;
    if (a != 0) {
        s0 = 0;
        s1 = 0;
    } else {
        int y = (int)m->m14;
        s0 = SumYBytes(y);
        s1 = SumYBytes(y + 0xE64);
    }
    fn_8017C228(p, 1, s0, s1);
    fn_8017C228(p, 0, s1, s0);
}

/* near-miss: retail ends the success path with `li r3,1; b end` and the failure path with `li r3,0`
 * after it (28 instrs); the spellings tried here give 27 or hoist the li. */
int fn_8017C6BC(Unk8017A930_T* p)
{
    if (lbl_8061C688 != 0) {
        return fn_8018019C(lbl_8068BE40);
    }
    if (fn_801A57B8(p->m4) != 0) {
        fn_8017C5F0(p, 1);
        return 1;
    }
    return 0;
}

void fn_8017C72C(Unk8017A930_T* p)
{
    p->m418 = 1;
    fn_80235AD4(p->m3B0);
}

/* near-miss: only the register of the switch value differs (retail r0, here r4); if-ladder
 * spellings change the compare tree (8 variants). */
void fn_8017C75C(Unk8017A930_T* p, Unk8017C75C_Obj* o)
{
    if (o) {
        int t = o->m458;
        switch (t) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
            fn_801DBDA4(p->m3B8);
            break;
        case 9:
            fn_801C3B04(p->m3A4);
            break;
        case 10: case 11: case 12:
            fn_80258070(p->m3B4);
            break;
        case 13: case 17:
            fn_80178F10(p->m3AC);
            break;
        case 15: case 16:
            fn_8017696C(p->m3A8);
            break;
        }
    }
}

void fn_8017C808(Unk8017A930_T* p)
{
    fn_80176F04(p->m3A8);
}

void fn_8017C82C(Unk8017A930_T* p)
{
    fn_801DC918(p->m3B8);
    fn_80235A40(p->m3B0);
}

void fn_8017C864(Unk8017A930_T* p)
{
    void* a = fn_801A4B34(p->m4);
    if (a) {
        fn_80252460(a);
    }
    void* b = fn_801C1638(p->m4, 0);
    if (b) {
        fn_80252460(b);
    }
    fn_801BB520(p->m3BC);
}

int fn_8017C8C0(Unk8017A930_T* p)
{
    return p->m14;
}

int fn_8017C8C8(Unk8017A930_T* p)
{
    return p->m18;
}

int fn_8017C8D0(Unk8017A930_T* p)
{
    int r = 0;
    int t = p->m4->m564->m14;
    if (fn_8017D5F8(p) == 1 && fn_801A6D84(p->m4, 1)->m3D90 == 0 && t != 8 && t != 10 && t != 9) {
        r = 1;
    }
    return r;
}

int fn_8017C94C(Unk8017A930_T* p)
{
    return p->m414;
}

int fn_8017C954(Unk8017A930_T* p)
{
    Unk8017C954_Rec* r = p->m4->m6F8->m14;
    return r->m1CCB + r->m1CCA * 4;
}

int fn_8017C974(Unk8017A930_T* p)
{
    int a = (int)fn_801C1638(p->m4, 0);
    int b = (int)fn_801A4B34(p->m4);
    Unk8017C954_Rec* r = p->m4->m6F8->m14;
    int k = r->m1CD0;
    int c = r->m1CC8;
    if (fn_8017E030(p, k == 0, 0) == 0 && !(a == p->m3D0 && p->m3D8 == c) && p->m3D4 != b) {
        return 1;
    }
    return 0;
}

/* near-miss: retail ends with `cmpwi r3,0; li r3,0; beq; li r3,1; b end; li r3,0` (30 instrs); the
 * return/flag spellings tried give 28 (4 slots differ). */
int fn_8017CA14(Unk8017A930_T* p, int idx)
{
    Unk8017B0A4_Ctx* c = p->m4;
    int off = idx * 0xE64;
    Unk8017C954_Rec* r = (Unk8017C954_Rec*)((char*)c->m6F8->m14 + off);
    if (r->m108 == 0 && r->m10C == 0 && p->m3DC == 2) {
        if (fn_803272D0((char*)c + 0x50, 9) != 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}

float fn_8017CC70(void* pl, int team, Unk8017CC70_Ev* ev)
{
    float v = ev->m10;
    float w = 0.0f;
    if (ev->m0 == 0x48 || ev->m0 == 0x41) {
        w = lbl_805EBA04;
    } else {
        w = lbl_805EBA08;
    }
    float t = (w - v) / w;
    t = t * 0.5f;
    if (!(t <= 1.0f)) {
        t = 1.0f;
    }
    return t;
}

void fn_8017CF00(Unk8017A930_T* p)
{
    int old = p->m3DC;
    p->m3DC = 2;
    p->m3E0 = old;
}

void fn_8017D0F4(Unk8017A930_T* p)
{
    const float step = 0.01f;
    p->m3E4 = p->m3E4 + step;
    p->m3E4 = Unk8017D0F4_Clamp(0.0f, p->m3E4, 1.0f);
    fn_8037893C((char*)p->m4 + 0x704, 0x9A, 0, 0, 0);
}

void fn_8017D190(Unk8017A930_T* p)
{
    const float step = 0.07f;
    p->m3E4 = p->m3E4 + step;
    p->m3E4 = Unk8017D0F4_Clamp(0.0f, p->m3E4, 1.0f);
    fn_8037893C((char*)p->m4 + 0x704, 0x9A, 0, 0, 0);
}

void fn_8017D22C(Unk8017A930_T* p)
{
    const float k = 0.006f;
    p->m3E4 = p->m3E4 - k;
    p->m3E4 = Unk8017D0F4_Clamp(0.0f, p->m3E4, 1.0f);
}

int fn_8017D5F8(Unk8017A930_T* p)
{
    switch (p->m4->m564->m14) {
    case 1:
    case 2:
    case 5:
    case 6:
    case 7:
    case 11:
        return 0;
    }
    return 1;
}
