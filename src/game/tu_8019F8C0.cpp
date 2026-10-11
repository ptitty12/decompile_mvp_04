/*
 * Game code, .text 0x8019F8C0-0x801A22F4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8019F8C0.h"

int fn_80162534(void* p);
int fn_80162598(void* p);
void fn_801593D8(void* p);
void fn_80158FCC(void* p);
void fn_8017B238(void* p);
void fn_8017BBF4(void* p);
void fn_8017BCB4(void* p);
void fn_8017BDD4(void* p);
int fn_8017C8C0(void* p);
int fn_80235C68(void* p);
int fn_801BBC0C(void* p);
void fn_802592B4(void* p);
int fn_8006BDCC(void* p);
int fn_8006BE18(void* p);
void fn_800AB9A8(void* p, int n);
Unk8019F8C0_Ref* fn_801A6D84(Unk8019F8C0_Owner* o, int n);
void fn_8033E3FC(Unk8019F8C0_State* s, int n);
float fn_80323848(int p);
void fn_8031F04C(void* p, int a);
void fn_8037EBE8(void* p);
float fn_801A2158(Unk8019F8C0_Owner* o, int idx);
Unk8019F8C0_Sub* fn_801A04A8(Unk8019F8C0_Owner* o);
void fn_803D6098(void* a, void* b);
void fn_803D5D34(void* a);
void fn_8033E5C4(void* a, int n);
int fn_801A2034(Unk8019F8C0_Owner* o, int i);
float fn_801A20F8(Unk8019F8C0_Owner* o, int idx, float a, float b);
struct Unk8019F8C0_S32 { int a[8]; };
extern Unk8019F8C0_S32 lbl_8068B4CC;
extern int lbl_80620164;
extern float lbl_805CE630;
extern float lbl_805CE6BC;
extern int lbl_80620860;
float fn_801A04B8(Unk8019F8C0_Owner* o, Unk8019F8C0_Sub* s);
void fn_8031E034(void* p);
extern int lbl_80620298;
extern float lbl_805CE628;
extern void* lbl_80619D10;
extern Unk8019F8C0_Glob* lbl_8061B8C0;

void Unk8019F8C0_S3::fn_vslot5()
{
    if (fn_80162534(m18->m710)) {
        fn_8033E3FC(this, 4);
    }
}

void Unk8019F8C0_S3::fn_vslot6()
{
    fn_801593D8(m18->m710);
}

Unk8019F930::Unk8019F930(Unk8019F8C0_Owner* o) : Unk8019F8C0_State(o, 4) {}

void Unk8019F930::fn_vslot4()
{
    fn_8017B238(m18->m700);
}

void Unk8019F930::fn_vslot5()
{
    int f = 0;
    Unk8019F8C0_Ctrl* o = m18->m700->m3B0;
    Unk8019F8C0_Ctl* s = &o->mC;
    if (fn_80235C68(o) == 2 || (s->m0 && s->m4) || s->m30) {
        f = 1;
    }
    int r = fn_8017C8C0(m18->m700);
    if (f || r) {
        fn_8033E3FC(this, 5);
    }
}

void Unk8019F930::fn_vslot6() {}

Unk8019FA50::Unk8019FA50(Unk8019F8C0_Owner* o) : Unk8019F8C0_State(o, 5) {}

void Unk8019FA50::fn_vslot4() {}

void Unk8019FA50::fn_vslot5()
{
    if (fn_8017C8C0(m18->m700)) {
        fn_8033E3FC(this, 6);
    }
}

void Unk8019FA50::fn_vslot6() {}

Unk8019FAF8::Unk8019FAF8(Unk8019F8C0_Owner* o) : Unk8019F8C0_State(o, 6) {}

void Unk8019FAF8::fn_vslot4() {}

void Unk8019FAF8::fn_vslot5()
{
    if (fn_801BBC0C(m18->m700->m3BC)) {
        fn_802592B4(m18->m700->m3B4);
        fn_8033E3FC(this, 7);
    }
}

void Unk8019FAF8::fn_vslot6() {}

Unk8019FBB4::Unk8019FBB4(Unk8019F8C0_Owner* o) : Unk8019F8C0_State(o, 7) {}

void Unk8019FBB4::fn_vslot5()
{
    if (fn_80162598(m18->m710)) {
        fn_8033E3FC(this, 8);
    }
}

void Unk8019FBB4::fn_vslot6() {}

Unk8019FD50::Unk8019FD50(Unk8019F8C0_Owner* o) : Unk8019F8C0_State(o, 8) {}

void Unk8019FD50::fn_vslot4()
{
    fn_8017BBF4(m18->m700);
}

void Unk8019FD50::fn_vslot5()
{
    if (fn_8006BE18(m18->m6F8) == 1) {
        fn_8033E3FC(this, 9);
        fn_8033E3FC(this, 0xb);
    } else if (fn_8006BDCC(m18->m6F8) == 1) {
        fn_8033E3FC(this, 9);
    } else {
        fn_8033E3FC(this, 3);
    }
}

void Unk8019FD50::fn_vslot6() {}

Unk8019FE5C::Unk8019FE5C(Unk8019F8C0_Owner* o) : Unk8019F8C0_State(o, 9) {}

void Unk8019FE5C::fn_vslot4()
{
    if (!fn_8006BE18(m18->m6F8)) {
        fn_80158FCC(m18->m710);
    }
}

void Unk8019FE5C::fn_vslot5()
{
    if (fn_801A6D84(m18, 1)->m3D90 == 0) {
        fn_8033E3FC(this, 0xa);
    }
}

void Unk8019FE5C::fn_vslot6()
{
    if (fn_8006BDCC(m18->m6F8) == 1) {
        fn_8017BCB4(m18->m700);
        if (!fn_8006BE18(m18->m6F8)) {
            fn_8017BDD4(m18->m700);
        }
    }
}

Unk8019FFB0::Unk8019FFB0(Unk8019F8C0_Owner* o) : Unk8019F8C0_State(o, 0xb), m1C(o) {}

void Unk8019FFB0::fn_vslot5()
{
    if (fn_801A6D84(m18, 1)->m3D90 == 0 && lbl_8061B8C0->m20 != 2) {
        fn_800AB9A8(lbl_80619D10, 1);
    }
}

void Unk8019FFB0::fn_vslot6() {}

void fn_801A02F0(char* self)
{
    fn_8033E5C4(self + 0x560, 1);
}

void fn_801A0488(Unk8019F8C0_Owner* o)
{
    o->m55C = 0;
    o->m48 = 0;
    o->m4C = 0;
    o->m54C = 0;
    o->m550 = 0;
    o->m548 = 0;
}

Unk8019F8C0_Sub* fn_801A04A8(Unk8019F8C0_Owner* o, int i)
{
    return o->m30[i];
}

void fn_801A06A8(Unk8019F8C0_Owner* o)
{
    int i = 0;
    do {
        Unk8019F8C0_Sub* s = fn_801A04A8(o, i);
        if (s) {
            if (i == 1) {
                if (lbl_80620298 != 0) {
                    float v = fn_801A04B8(o, s);
                    s->SetM4C(v);
                } else {
                    fn_8031E034(s);
                }
            } else {
                fn_8031E034(s);
            }
        }
        i++;
    } while (i <= 5);
}

float fn_801A0744(Unk8019F8C0_Owner* o)
{
    Unk8019F8C0_Sub* c = fn_801A04A8(o, 1);
    int t;
    if (c->m44 != 0 || (t = c->m48) == 0) {
        return c->m4C;
    }
    return fn_80323848(t);
}

void fn_801A0790(Unk8019F8C0_Owner* o, float v)
{
    if (lbl_80620860 == 0) {
        fn_801A04A8(o, 1)->SetM4C(v);
    }
}

void fn_801A07D8(Unk8019F8C0_Owner* o, float v)
{
    fn_801A04A8(o, 1)->SetM50(v * lbl_805CE628);
}

void fn_801A081C(Unk8019F8C0_Owner* o, int a)
{
    int i = 0;
    do {
        Unk8019F8C0_Sub* c = fn_801A04A8(o, i);
        i++;
        if (c) {
            fn_8031F04C(c, a);
        }
    } while (i <= 5);
}

int fn_801A0874(Unk8019F8C0_Owner* o)
{
    float x = fn_801A0744(o);
    return (int)(x * lbl_805CE630) + 2 <= o->m4C;
}

void fn_801A08D8(Unk8019F8C0_Owner* o)
{
    unsigned n = o->m4C + 1;
    o->m4C = n;
    if (n > (unsigned)o->m48) {
        o->m48 = n;
    }
    lbl_8068B4CC = lbl_8068B4CC;
}

void fn_801A15A0(Unk8019F8C0_Owner* o)
{
    fn_801A0488(o);
    for (int i = 0; i < 13; i++) {
        o->m65C[i] = 0;
    }
    o->m6FC = 0;
    o->m780 = 0;
    o->m784 = 0;
    o->m788 = 0;
    o->m78C = 0;
    o->m790 = 0;
    o->m794 = 0;
    o->m6CC = 0;
    o->m6D0 = -1;
    o->m6D4 = -1;
    o->m6DC = 0;
}

int fn_801A161C(Unk8019F8C0_Owner* o)
{
    int* p = o->m6C4;
    if (p) {
        return *p;
    }
    return 0;
}

void fn_801A1E90(Unk8019F8C0_Owner* o)
{
    if (o) {
        for (int i = 0; i < 3; i++) {
            fn_8037EBE8(o->m618[i]);
        }
    }
}

int fn_801A1FFC(Unk8019F8C0_Owner* o, int a, int b)
{
    return fn_801A2034(o, a) == b;
}

int fn_801A2034(Unk8019F8C0_Owner* o, int i)
{
    /* near-miss: retail compares i == 3 before `mr r4,r11` and branches after it (3 slots differ). */
    if (i > 2) {
        int f = 0;
        if (o->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        if (i == 3) {
            i = f;
        } else {
            i = f ^ 1;
        }
    }
    return o->m58C[i];
}

float fn_801A2078(Unk8019F8C0_Owner* o, int i, int a, int b, float c, float d)
{
    float r = lbl_805CE6BC;
    if (fn_801A2034(o, i) == -1) {
        r = fn_801A20F8(o, a, c, d);
    } else {
        r = fn_801A20F8(o, b, c, d);
    }
    return r;
}

inline float Unk8019F8C0_Lerp(float a, float t, float b)
{
    return a + t * (b - a);
}

float fn_801A20F8(Unk8019F8C0_Owner* o, int idx, float a, float b)
{
    float t = fn_801A2158(o, idx);
    float r = Unk8019F8C0_Lerp(a, t, b);
    return r;
}

int fn_801A2238(Unk8019F8C0_Owner* o, int a)
{
    if (o->m58C[1] == a) {
        return 1;
    }
    if (o->m58C[0] == a) {
        return 0;
    }
    return 2;
}

void fn_801A2264(Unk8019F8C0_Owner* o)
{
    char buf[0x3C];
    if (lbl_80620164) {
        Unk8019F8C0_Sub* s = fn_801A04A8(o);
        if (s && s->m4 && !s->m38) {
            s->mC->fn_vslot4(buf);
            fn_803D6098(o->m588, buf);
            fn_803D5D34(o->m588);
        }
    }
}
