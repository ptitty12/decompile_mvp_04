/*
 * Game code, .text 0x8022FE34-0x80233F08 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8022FE34.h"

extern const float lbl_805D6ED0;
extern const float lbl_805D6ED4;
extern const float lbl_805D6ED8;
extern "C" float fn_8023A888(Unk8022FE34_Ent* e);
void fn_80230B50(Unk8022FE34_Sub* s);
void fn_8022F4D4(Unk8022FE34_Sub* s);
void fn_8022F328(Unk8022FE34_Sub* s, int i);

/* near-miss: right length and structure; retail hoists all the table addresses and keeps
   the 1.0 load after the -1.0 stores (7 saved regs r25-r31 vs our 5). Tried 40+ store orders. */

extern "C" int fn_8018AA44(int v);

class Unk8014D8AC {
public:
    int fn_8014D8AC(int max, const char* file, int line);
};
extern const char lbl_805D6EDC[];

inline float RandF(Unk8014D8AC* r, const char* file, float scale, int line)
{
    return (float)(unsigned)r->fn_8014D8AC(1000000, file, line) * scale * 1e-6f;
}

void Unk8022FE34_Sub::fn_8022FE34(Unk8022FE34_Owner* o)
{
    m0 = o;
    m1D0 = 0;
    m1D8 = 0;
    m1D4 = 0;
    Unk8022FE34_Ent* e = m4;
    for (int i = 0; i < 5; i++, e++) {
        e->m14 = 2;
        e->m0 = 0;
        e->m28 = 1;
        e->m1C = -1;
        e->m20 = lbl_805D6ED0;
        e->m8 = lbl_805D6ED0;
        e->m10 = lbl_805D6ED0;
        e->mC = lbl_805D6ED0;
        e->m4 = lbl_805D6ED0;
        e->m24 = lbl_805D6ED4;
        m194[i].m0 = -1;
        m158[i].m0 = -1;
        m11C[i].m0 = -1;
        mE0[i].m0 = -1;
        m158[i].m4 = lbl_805D6ED8;
        m194[i].m4 = lbl_805D6ED8;
        m11C[i].m4 = lbl_805D6ED8;
        mE0[i].m4 = lbl_805D6ED8;
        m158[i].m8 = lbl_805D6ED0;
        m194[i].m8 = lbl_805D6ED0;
        m11C[i].m8 = lbl_805D6ED0;
        mE0[i].m8 = lbl_805D6ED0;
    }
}

Unk8022FE34_Pai::Unk8022FE34_Pai(Unk8022FE34_Owner* o)
{
    m0 = o;
    fn_8022FFC4(o, 0);
    fn_8022FFC4(o, 1);
}

void Unk8022FE34_Pai::fn_8022FFC4(Unk8022FE34_Owner* o, int i)
{
    if (m0 != 0)
        m3F4 = o->m0;
    else
        m3F4 = (Unk8022FE34_Ctx*)m0;
    m4[i].fn_8022FE34(o);
    m0 = o;
}

int Unk8022FE34_Pai::fn_80230024(int i)
{
    return m4[i].m1D0;
}

extern Unk8022FE34_Ent lbl_8068C978[3];
extern Unk8022FE34_Ent lbl_8068C9FC[3];

/* Object at Ctx::m65C: vptr at +0x98, the called virtual is entry 22 (offset 0xB0). */
struct Unk8022FE34_VObj22 : Unk8022FE34_VBase {
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual int s22();
};

inline int SideFlag(Unk8022FE34_Ctx* c)
{
    int f = 0;
    if (c->m6F8->m14[2].m8 != 0)
        f = 1;
    return f;
}

/* near-miss: 139/139 insns, ~20 slots: retail copies this into r10 first and keeps the Ctx pointer (m3F4) in r3, ours keeps
   this in r3 and puts the Ctx in r9. Tried a Ctx local, self alias, direct m3F4 reads. */
void Unk8022FE34_Pai::fn_8023003C(int i, int idx, Unk8022FE34_Ent* out, int flag)
{
    int side = SideFlag(m3F4);
    side = side ^ 1;
    if (flag) {
        idx = idx % 3;
        *out = lbl_8068C978[idx];
        Unk8022FE34_VObj22* o = (Unk8022FE34_VObj22*)m3F4->m65C;
        if (o != 0) {
            if (o->s22() == 1) {
                *out = lbl_8068C9FC[idx];
            }
        }
    } else {
        *out = m4[side].m4[idx];
    }
}

void Unk8022FE34_Pai::fn_80230500(int i, Unk8022FE34_Ent* out)
{
    float r = RandF((Unk8014D8AC*)m3F4->m554, lbl_805D6EDC, 1.0f, 0x3A1);
    float acc = 0.0f;
    float prev = 0.0f;
    float hi = 0.0f;
    float w;
    int k = 0;
    while (k < fn_80230024(i)) {
        prev = acc;
        w = m4[i].mE0[k].m4;
        hi = acc + w;
        if (!(r < prev) && !(r > hi)) {
            *out = m4[i].m4[k];
            return;
        }
        acc = acc + w;
        k++;
    }
    fn_8023003C(i, 0, out, 0);
}

void Unk8022FE34_Pai::fn_802306CC(int i, Unk8022FE34_Ent* out)
{
    if (m4[i].m1DC == 0) {
        fn_80230500(i, out);
        return;
    }
    float r = RandF((Unk8014D8AC*)m3F4->m554, lbl_805D6EDC, 1.0f, 0x3C1);
    float acc = 0.0f;
    float prev = 0.0f;
    float hi = 0.0f;
    float w;
    int k = 0;
    while (k < m4[i].m1DC) {
        prev = acc;
        w = m4[i].m194[k].m4;
        hi = acc + w;
        if (!(r < prev) && r <= hi) {
            fn_8023003C(i, m4[i].m194[k].m0, out, 0);
            return;
        }
        acc = acc + w;
        k++;
    }
    fn_8023003C(i, 0, out, 0);
}

void Unk8022FE34_Pai::fn_8023084C(int i, Unk8022FE34_Ent* out)
{
    if (m4[i].m1D4 == 0) {
        fn_80230500(i, out);
        return;
    }
    float r = RandF((Unk8014D8AC*)m3F4->m554, lbl_805D6EDC, 1.0f, 0x3E3);
    float acc = 0.0f;
    float prev = 0.0f;
    float hi = 0.0f;
    float w;
    int k = 0;
    while (k < m4[i].m1D4) {
        prev = acc;
        w = m4[i].m11C[k].m4;
        hi = acc + w;
        if (!(r < prev) && r <= hi) {
            fn_8023003C(i, m4[i].m11C[k].m0, out, 0);
            return;
        }
        acc = acc + w;
        k++;
    }
    fn_8023003C(i, 0, out, 0);
}

void Unk8022FE34_Pai::fn_802309CC(int i, Unk8022FE34_Ent* out)
{
    if (m4[i].m1D8 == 0) {
        fn_80230500(i, out);
        return;
    }
    float r = RandF((Unk8014D8AC*)m3F4->m554, lbl_805D6EDC, 1.0f, 0x404);
    float acc = 0.0f;
    float prev = 0.0f;
    float hi = 0.0f;
    float w;
    int k = 0;
    while (k < m4[i].m1D8) {
        prev = acc;
        w = m4[i].m158[k].m4;
        hi = acc + w;
        if (!(r < prev) && r <= hi) {
            fn_8023003C(i, m4[i].m158[k].m0, out, 0);
            return;
        }
        acc = acc + w;
        k++;
    }
    fn_8023003C(i, 0, out, 0);
}

void fn_80230B4C() {}

void fn_80230B50(Unk8022FE34_Sub* s) {}

void Unk8022FE34_Pai::fn_80230B54(int i)
{
    fn_80230B50(&m4[i]);
}

void Unk8022FE34_Pai::fn_80230B88(int i)
{
    fn_8022F4D4(&m4[i]);
}

void Unk8022FE34_Pai::fn_80230BBC(int i)
{
    fn_8022F328(&m4[i], i);
}

void Unk8022FE34_Sub::fn_80230BF4()
{
    m1DC = 0;
    float f = fn_8023A888(m4);
    m1EC = 0.0f;
    m1DC = 0;
    for (int i = 0; i < m1D0; i++) {
        if (m4[i].m0 != 3) {
            const float c = 0.1f;
            if (!(f - fn_8023A888(&m4[i]) > c)) {
                m194[m1DC].m0 = i;
                m1DC++;
            }
        }
    }
}

void Unk8022FE34_Sub::fn_80230CC8(const Unk8022FE34_Ent* e)
{
    m4[m1D0] = *e;
    m1D0++;
}

void Unk8022FE34_Sub::fn_80230D54()
{
    m1E8 = 0.0f;
    m1D8 = 0;
    int i = 0;
    for (; i < m1D0; i++) {
        Unk8022FE34_Ent e = m4[i];
        if (fn_8018AA44(e.m0) == 0) {
            m1E8 += fn_8023A888(&e);
            m158[m1D8].m0 = i;
            m158[m1D8].m4 = 0.0f;
            m1D8++;
        }
    }
    for (; i <= 4; i++) {
        m158[i].m0 = i;
        m158[i].m4 = 0.0f;
    }
}

void Unk8022FE34_Sub::fn_80230EB4()
{
    m1E4 = 0.0f;
    m1D4 = 0;
    int i = 0;
    for (; i < m1D0; i++) {
        Unk8022FE34_Ent e = m4[i];
        if (fn_8018AA44(e.m0) != 0) {
            m1E4 += fn_8023A888(&e);
            m11C[m1D4].m0 = i;
            m11C[m1D4].m4 = 0.0f;
            m1D4++;
        }
    }
    for (; i <= 4; i++) {
        m11C[i].m0 = -1;
        m11C[i].m4 = 0.0f;
    }
}

struct Unk8017A930_T;
extern const Unk8022FE34_V3 lbl_8068C8D4;
Unk8022FE34_Pl* fn_801A497C(Unk8022FE34_Ctx* c, int i, int j);
int fn_801A2034(Unk8022FE34_Ctx* c, int i);
int fn_802530E8(Unk8022FE34_Obj480* p);
void fn_8023135C(Unk8022FE34_Owner* t, Unk8022FE34_Pl* p);
void fn_80231520(Unk8022FE34_Owner* t, Unk8022FE34_Pl* p);
void fn_802F9410(void* obj, int idx, Unk8022FE34_V2* p, Unk8022FE34_V2 v);
void fn_802FAD5C(void* obj, int idx, void* p);
void fn_80238ECC(Unk8022FE34_W* w, Unk8022FE34_V2* a, int* b);
void fn_80239AE0(Unk8022FE34_W* w, int* b);
void fn_80239040(Unk8022FE34_W* w, Unk8022FE34_V2* a);
void fn_8023A6C8(Unk8022FE34_W* w, int b);
void fn_8022F2B8(Unk8022FE34_Owner* u, int v);
int fn_80097148(Unk8022FE34_Row* r, int b);
void fn_802531FC(Unk8022FE34_Obj480* p);
void fn_80252A94(Unk8022FE34_Obj480* p, int v);
int fn_80099B50(Unk8022FE34_Row* r, int i);
void fn_801A6C1C(Unk8022FE34_Ctx* c, Unk8022FE34_Row* r, int i, int a, int b, int d);
void fn_8040A208(void* arr, int n, int sz, void (*f)(void*));
void fn_8022F2C0(void* p);

void Unk8022FE34_Sub::fn_80231018()
{
    fn_8040A208(m4, 5, 0x2c, fn_8022F2C0);
}

static inline int Pick(Unk8022FE34_Ctx* c, int i)
{
    if (i > 2) {
        int f = 0;
        if (c->m6F8->m14[2].m8 != 0)
            f = 1;
        int g;
        if (i != 3)
            g = f ^ 1;
        else
            g = f;
        i = g;
    }
    return i;
}

extern float lbl_8061D158;
extern float lbl_8061D15C;

inline float Norm(float lo, float x, float hi)
{
    float d = hi - lo;
    if (!(d <= 0.0f)) {
        return (x - lo) / d;
    }
    return 0.0f;
}

inline float Lerp(float a, float t, float b)
{
    return a + t * (b - a);
}

float fn_8023125C(float x)
{
    if ((int)x == 0) {
        return 0.0f;
    }
    float t = Norm(1.0f, x, 7.0f);
    t = !(t > 1.0f) ? (t >? 0.0f) : 1.0f;
    float r = Lerp(lbl_8061D158, t, lbl_8061D15C);
    return r;
}

void Unk8022FE34_Owner::fn_80231D0C(int i)
{
    Unk8022FE34_Ctx* c = m0;
    i = Pick(c, i);
    Unk8022FE34_Pl* pl = fn_801A497C(c, i, 0);
    Unk8022FE34_Pai* pai = &m38;
    pai->fn_8022FFC4(this, i);
    if (fn_802530E8(&pl->m480) == 0)
        fn_8023135C(this, pl);
    else
        fn_80231520(this, pl);
    pai->fn_80230B88(i);
    pai->fn_80230B54(i);
}

int Unk8022FE34_Owner::fn_80231DDC()
{
    int idx = fn_801A2034(m0, 4);
    if (idx != -1) {
        void* o = m0->m720;
        if (o != 0)
            fn_802F9410(o, idx, &m20, m20);
    }
    return 1;
}

Unk8022FE34_V3 Unk8022FE34_Owner::fn_80231E4C()
{
    Unk8022FE34_V3 v = lbl_8068C8D4;
    return v;
}

void Unk8022FE34_Owner::fn_80231FC0()
{
    if (fn_801A2034(m0, 4) == -1 && m430 == 0 && m434 == 0 && m440.m0 == 0) {
        if (m0->m6F4 == 8) {
            fn_80238ECC(&m440, &m20, &mC);
        } else {
            Unk8022FE34_W* w = &m440;
            fn_80239AE0(w, &mC);
            fn_80239040(w, &m20);
        }
        m30 = m20;
        fn_8023A6C8(&m440, mC);
        m440.m0 = 1;
    }
}

struct Unk8026C414_O;
struct Unk8026C414_X;
int fn_8026DC18(Unk8026C414_O* o, Unk8026C414_X* x);
int fn_8026D6AC(Unk8026C414_O* o, Unk8026C414_X* x);
struct Obj5BC {
    char pad0[0x5BC];
    int m5BC;
};

extern const float lbl_805D7098;

/* near-miss: 78/78 insns, register roles differ: retail loads the Ctx (m0) into the register that held this (lwz r28,0(r28))
   before copying the weight table and keeps the result in r31; ours keeps this in r31 and reloads m0 later. */
int Unk8022FE34_Owner::fn_80232084()
{
    int r = 0;
    if (fn_801A2034(m0, 4) == -1) {
        Obj5BC* g = (Obj5BC*)m0->m68C;
        if (g != 0 && g->m5BC == 3) {
            if (fn_8026DC18((Unk8026C414_O*)g, 0) != 0 || fn_8026D6AC((Unk8026C414_O*)g, 0) != 0) {
                Unk8022FE34_Ctx* c = m0;
                float tbl[4] = { 0.6f, 0.5f, 0.25f, 0.0f };
                int idx = c->m6F8->m14[2].m3;
                if (!(RandF((Unk8014D8AC*)c->m554, lbl_805D6EDC, lbl_805D7098, 0x668) >= tbl[idx])) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

extern "C" void fn_80190F04(int a, int b);
void fn_8027D33C(Unk8027C728_Goal* g);
extern "C" void fn_8037893C(char* queue, int id, void* ev, int a, int b);
void fn_8017B4F8(Unk8017A930_T* p);

void Unk8022FE34_Owner::fn_802321BC()
{
    if (mC == 0) {
        fn_80231FC0();
    }
    Unk8022FE34_Pl* pl = fn_801A497C(m0, 4, 0);
    fn_80190F04(fn_802324E0(), mC);
    fn_8027D33C(fn_80231E90());
    pl->m8F0 = 1;
    fn_8037893C(m0->m704, 0x5A, 0, 0, 0);
    fn_8017B4F8((Unk8017A930_T*)m4->m8);
}

void Unk8022FE34_Owner::fn_8023246C()
{
    int idx = fn_801A2034(m0, 4);
    void* o = m0->m720;
    if (m18 != 0) {
        char* p = (char*)m4 + 0xc;
        if (idx != -1)
            fn_802FAD5C(o, idx, p);
        m14 = *(float*)(p + 0x18);
        m10 = *(float*)(p + 0x14);
    }
}

int Unk8022FE34_Owner::fn_802324E0()
{
    return m0->m6CC;
}

int Unk8022FE34_Owner::fn_802324EC()
{
    return m1C == 1;
}

void Unk8022FE34_Owner::fn_8023262C(int i, Unk8022FE34_Pl* pl, Unk8022FE34_Row* r)
{
    m18 = 0;
    fn_8022F2B8(this, 0);
    fn_802326C4(i, 0);
    int k = fn_80097148(&m0->m6F8->m14[i], r->m70C);
    if (k == 1 || k == 3) {
        Unk8022FE34_Obj480* o = &pl->m480;
        fn_802531FC(o);
        o->m44 |= 0x20000000;
    }
}

void Unk8022FE34_Owner::fn_802326C4(int i, int j)
{
    Unk8022FE34_Pl* pl = fn_801A497C(m0, i, 0);
    if (pl != 0) {
        fn_80252A94(&pl->m480, j);
        i = Pick(m0, i);
        fn_80231D0C(i);
        m4->fn_8023276C(i);
    }
}

void Unk8022FE34_U::fn_8023276C(int i)
{
    int a = 0;
    int b = 0;
    Unk8022FE34_Row* r = &fn_80235FA8()->m6F8->m14[i];
    Unk8022FE34_Pl* pl = fn_801A497C(fn_80235FA8(), i, 0);
    int n = r->m78;
    int c = pl->m704;
    if (n > 0)
        a = fn_80099B50(r, 0);
    if (n > 1)
        b = fn_80099B50(r, 1);
    fn_801A6C1C(fn_80235FA8(), r, i, c, a, b);
}

int fn_80232A34()
{
    return 1;
}
