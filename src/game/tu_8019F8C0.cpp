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
struct Unk80087A58_O;
float fn_80087ABC(Unk80087A58_O* s, int a, int w);
extern float lbl_805CE6C0;
void fn_8017BB60(void* p);
void fn_8015A5A4(void* p);
void fn_8035AF30(void* p, int inchrg);
extern "C" Unk8019F8C0_M2* fn_801A4CE8(Unk8019F8C0_Owner* o, int i);
extern char lbl_80649DA0[];
extern char lbl_8065FAA8[];
extern char lbl_80649DB8[];
extern char lbl_80660520[];
extern char lbl_80660548[];
void fn_80328234(void* p, int a, int b);
void fn_803785E4(void* p);
void* fn_803263C4(void* p, void* o);
void fn_8032850C(void* p);
void fn_80326410(void* p, int a);
void fn_80378620(void* p, int c);
void fn_80328374(void* p, int c);
void fn_801A0488(Unk8019F8C0_Owner* o);

/* Message object built on the stack (vptr at +4; base vtable lbl_80649DA0, derived lbl_8065FAA8).
 * Destroyed by calling the base destructor 0x8035AF30 with in-charge 2. */
struct Unk8035AF30_Base {
    int m0;
    const void* m4;
    Unk8035AF30_Base(int id) : m0(id) { m4 = lbl_80649DA0; }
};
struct Unk8019FBB4_Msg : public Unk8035AF30_Base {
    int m8;
    Unk8019FBB4_Msg(int id, Unk8019F8C0_Owner* o) : Unk8035AF30_Base(id) { m8 = o->m65C[8]; m4 = lbl_8065FAA8; }
};
void fn_8017BE28(void* p);
void fn_801A0790(Unk8019F8C0_Owner* o, float v);
void fn_8037893C(void* a, int b, void* c, void* d, int e);
void fn_80169674(void* p);
void fn_80166E40(void* p);
extern float lbl_805CE610;
extern float lbl_805CE6C4;
extern float lbl_805CE6C8;
extern float lbl_805CE6CC;
extern float lbl_805CE6D0;
void* fn_80326534(void* p);
void fn_803296AC(void* p);

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

/* near-miss: same code; retail schedules the owner load and the msg stores differently (12 slots). */
void Unk8019FBB4::fn_vslot4()
{
    Unk8019FBB4_Msg msg(0x7c, m18);
    fn_8037893C(m18->m704, msg.m0, &msg, 0, 0);
    fn_8017BB60(m18->m700);
    if (lbl_80620860 == 0) {
        fn_8015A5A4(m18->m710);
    }
    if (fn_801A4CE8(m18, 1)->fn_vslot9() == 0 && fn_801A6D84(m18, 1)->m3D90 == 0) {
        lbl_8061B8C0->m2C = 4;
    }
    fn_8035AF30(&msg, 2);
}

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

void Unk8019FFB0::fn_vslot4()
{
    if (lbl_80620860 != 0) {
        lbl_80620860 = 0;
        fn_801A0790(m1C, (float)(unsigned)m1C->m4C * lbl_805CE610);
    }
    fn_8017BE28(m1C->m700);
    fn_80169674(m18->m710);
    fn_8037893C((char*)m1C + 0x704, 0x36, 0, 0, 0);
    ((Unk8019F8C0_OV*)lbl_80619D10)->fn_vslot24(0);
    fn_80166E40(m1C->m710);
}

void Unk8019FFB0::fn_vslot5()
{
    if (fn_801A6D84(m18, 1)->m3D90 == 0 && lbl_8061B8C0->m20 != 2) {
        fn_800AB9A8(lbl_80619D10, 1);
    }
}

void Unk8019FFB0::fn_vslot6() {}

/* The first five states of the state list belong to the earlier unit (ctors take the owner as
 * Unk8019E3C0_Own); only their sizes are needed here. */
struct Unk8019E3C0_Own;
class Unk8019F414 { public: Unk8019F414(Unk8019E3C0_Own* o); char pad0[0x1C]; };
class Unk8019F48C { public: Unk8019F48C(Unk8019E3C0_Own* o); char pad0[0x20]; };
class Unk8019F5EC { public: Unk8019F5EC(Unk8019E3C0_Own* o); char pad0[0x1C]; };
class Unk8019F728 { public: Unk8019F728(Unk8019E3C0_Own* o); char pad0[0x1C]; };
class Unk8019F81C { public: Unk8019F81C(Unk8019E3C0_Own* o); char pad0[0x1C]; };
void fn_8033E464(void* list, void* obj);
void* operator new(unsigned int size, int heap);

void fn_801A0144(Unk8019F8C0_Owner* o)
{
    char* list = (char*)o + 0x560;
    fn_8033E464(list, new (0) Unk8019F414((Unk8019E3C0_Own*)o));
    fn_8033E464(list, new (0) Unk8019F48C((Unk8019E3C0_Own*)o));
    fn_8033E464(list, new (0) Unk8019F5EC((Unk8019E3C0_Own*)o));
    fn_8033E464(list, new (0) Unk8019F728((Unk8019E3C0_Own*)o));
    fn_8033E464(list, new (0) Unk8019F81C((Unk8019E3C0_Own*)o));
    fn_8033E464(list, new (0) Unk8019F930(o));
    fn_8033E464(list, new (0) Unk8019FA50(o));
    fn_8033E464(list, new (0) Unk8019FAF8(o));
    fn_8033E464(list, new (0) Unk8019FBB4(o));
    fn_8033E464(list, new (0) Unk8019FD50(o));
    fn_8033E464(list, new (0) Unk8019FE5C(o));
    fn_8033E464(list, new (0) Unk8019FFB0(o));
}

void fn_801A02F0(char* self)
{
    fn_8033E5C4(self + 0x560, 1);
}

Unk8019F8C0_Owner* fn_801A0318(Unk8019F8C0_Owner* self)
{
    fn_80328234(self, 0, 0);
    char* sub = (char*)self + 0x24;
    fn_803785E4(sub);
    *(const void**)(sub + 8) = lbl_80649DB8;
    *(const void**)((char*)self + 0x2C) = lbl_80660520;
    *(const void**)((char*)self + 0x18) = lbl_80660548;
    fn_803263C4((char*)self + 0x50, self);
    self->m554 = 0;
    self->m558 = 0;
    for (int i = 0; i < 6; i++) {
        self->m30[i] = 0;
    }
    fn_801A0488(self);
    return self;
}

void fn_801A03C0(Unk8019F8C0_Owner* self, int c)
{
    *(const void**)((char*)self + 0x2C) = lbl_80660520;
    *(const void**)((char*)self + 0x18) = lbl_80660548;
    fn_8032850C(self);
    fn_80326410((char*)self + 0x50, 2);
    char* sub = (char*)self + 0x24;
    *(const void**)(sub + 8) = lbl_80649DB8;
    fn_80378620(sub, 0);
    fn_80328374(self, c);
}

void fn_801A043C(Unk8019F8C0_Owner* o)
{
    ((Unk8019F8C0_OV*)o)->fn_vslot17();
    fn_803296AC(fn_80326534((char*)o + 0x50));
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

class Unk8014D8AC {
public:
    int fn_8014D8AC(int max, const char* file, int line);
};
extern const char lbl_805CB8F0[];
extern "C" float logf(float x);
extern "C" float fn_804028E4(float x);

float fn_801A0958(Unk8019F8C0_Owner* o, float mean, float sd)
{
    Unk8014D8AC* rng = (Unk8014D8AC*)o->m554;
    float a;
    float b;
    float x;
    float y;
    float s;
    do {
        x = 2.0f * ((float)(unsigned)rng->fn_8014D8AC(10000, lbl_805CB8F0, 0x1CF) * 0.0001f) - 1.0f;
        y = 2.0f * ((float)(unsigned)rng->fn_8014D8AC(10000, lbl_805CB8F0, 0x1CF) * 0.0001f) - 1.0f;
        s = x * x + y * y;
    } while (s >= 1.0f);
    s = fn_804028E4(logf(s) * -2.0f / s);
    a = x * s;
    b = y * s;
    volatile float pad;
    float r = sd * a + mean;
    return r;
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

struct Unk801A1EDC_R {
    char pad0[0x6C];
    int m6C;
};
extern "C" Unk801A1EDC_R* fn_801A6DB8(Unk8019F8C0_Owner* o);
extern "C" Unk8019F8C0_Owner* fn_801A4910(Unk8019F8C0_Owner* o, int a, int b);
extern "C" void fn_803BD720();

inline Unk8019F8C0_Inner* Unk801A1EDC_At(Unk8019F8C0_Inner* a, int i)
{
    return &a[i];
}

void fn_801A1EDC(Unk8019F8C0_Owner* o)
{
    unsigned j;
    if (fn_801A6DB8(o)->m6C == 0) {
        if (o->m6F4 != 1) {
            for (int t = 0; t <= 1; t++) {
                for (j = 0; j < Unk801A1EDC_At(o->m6F8->m14, t)->m3E4; ) {
                    fn_801A1E90(fn_801A4910(o, t, j++));
                }
                fn_801A1E90((Unk8019F8C0_Owner*)o->m6B0[t]);
                for (j = 0; j <= 1; j++) {
                    fn_801A1E90((Unk8019F8C0_Owner*)o->m6A0[t][j]);
                }
            }
        } else if (o->m594[0] != 0) {
            fn_801A1E90((Unk8019F8C0_Owner*)o->m594[0]);
        }
        for (j = 0; j <= 3; j++) {
            if (o->m690[j] != 0) {
                fn_801A1E90((Unk8019F8C0_Owner*)o->m690[j]);
            }
        }
        fn_803BD720();
    }
}
int fn_801A1FFC(Unk8019F8C0_Owner* o, int a, int b)
{
    return fn_801A2034(o, a) == b;
}

int fn_801A2034(Unk8019F8C0_Owner* o, int i)
{
    if (i > 2) {
        int f = 0;
        if (o->m6F8->m14[2].m8 != 0) {
            f = 1;
        }
        if (i != 3) {
            i = f ^ 1;
        } else {
            i = f;
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

/* near-miss: same code; retail stores the clamp result straight into v's slot (sp+8), ours via the
   inline's return temp (sp+0x20), 2 slots. */
inline float Unk8019F8C0_Clamp(float lo, float t, float hi)
{
    t = !(t > hi) ? (t >? lo) : hi;
    return t;
}

float fn_801A2158(Unk8019F8C0_Owner* o, int idx)
{
    Unk8019F8C0_Mgr10* m = o->m6F8->m10;
    if (m == 0) {
        return lbl_805CE6C0;
    }
    float v = fn_80087ABC((Unk80087A58_O*)m, idx, 0);
    switch (idx) {
    case 0x18:
        v = v + lbl_805CE6C4;
        break;
    case 0x25:
        v = v - lbl_805CE6C8;
        break;
    }
    return Unk8019F8C0_Clamp(lbl_805CE6CC, v, lbl_805CE6D0);
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
