/*
 * Game code, .text 0x80233F08-0x802362A8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8022FE34.h"
#include "game/goals/tu_8027C728.h"

struct Unk8028989C_Goal;
int fn_8028B068(Unk8028989C_Goal* g, float* out);
void fn_8027D368(Unk8027C728_Goal* g);

extern const float lbl_80620754;
extern const float lbl_8062074C;
extern int lbl_80620750;
extern int lbl_80620748;
extern int lbl_8061EDCC;

void fn_8022F2B8(Unk8022FE34_Owner* t, int v);
void fn_8022F174(Unk8022FE34_U* u, int v);
void fn_8023A7F4(Unk8022FE34_W* w);
void fn_802361F8(void* p, float f);
void fn_802361F4();
Unk8022FE34_V3 fn_80233F08(Unk8022FE34_Ent* e, int a, ...);
extern "C" int fn_801C3E68(void* p);
struct Unk8026C414_O;
struct Unk8026C414_X;
int fn_8026D5FC(Unk8026C414_O* o, Unk8026C414_X* x);

struct V3f {
    float x;
    float y;
    float z;
};
extern const V3f lbl_805D7DCC;
extern const float lbl_805D7288;
extern const float lbl_805D728C;

inline V3f operator-(const V3f& a, const V3f& b)
{
    V3f r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline V3f FlatPos(const V3f& p)
{
    V3f r = p;
    r.y = lbl_805D7288;
    return r;
}

void fn_8025191C(Unk8022FE34_Pl* pl, int a, float f);
float fn_8025356C(Unk8022FE34_Obj480* o);
void fn_802516CC(Unk8022FE34_Pl* pl);
void fn_802517F4(Unk8022FE34_Pl* pl);
Unk8022FE34_Pl* fn_801A497C(Unk8022FE34_Ctx* c, int i, int j);
int fn_8033E420(void* p);
int fn_801A2034(Unk8022FE34_Ctx* c, int i);
struct Unk8024EF40_P;
int fn_802536D0(Unk8024EF40_P* p);
extern "C" void fn_80252DF4(char* p, float f);
extern "C" int fn_8018AD2C(int o);
extern "C" float* fn_80191800(int id);
extern int lbl_8061C958[];
struct Unk8024EF40_W;
float fn_80254618(Unk8024EF40_W* w, int i);
extern "C" void fn_80252EB8(char* p, float f);

inline float Lerp(float a, float t, float b)
{
    return a + t * (b - a);
}

extern "C" void fn_80189300(int a, void* b);
void fn_80234B18(Unk8022FE34_U* u);
void fn_80234E4C(Unk8022FE34_U* u);

void fn_802349E8(Unk8022FE34_Owner* t);
void fn_80233444(Unk8022FE34_Owner* t);
float fn_802398C8(Unk8022FE34_W* w);
Unk8022FE34_X6D* fn_801A6DB8(Unk8022FE34_Ctx* c);
void fn_80188698(int a, float f);
int fn_801A48F8(Unk8022FE34_Ctx* c, int i);
Unk8022FE34_Pl* fn_801A4910(Unk8022FE34_Ctx* c, int i, int k);
void fn_80253244(Unk8022FE34_Obj480* o, int a, int b);
extern const float lbl_805D730C;
extern float lbl_805D7328[1];
/* Declared as an array so that loads of it count as in-struct memory and stay below the int stores
   (a scalar global is hoisted above them by the scheduler). */
extern float lbl_805D7310[1];
extern const float lbl_805D7314;
extern const float lbl_805D7318;
extern const float lbl_805D731C;
extern float lbl_805D7320[1];
extern float lbl_805D7324[1];
extern int lbl_8061D150[];
int fn_80088234(void* o, int i);

inline void Set728b(Unk8022FE34_Owner* t, float v)
{
    t->m728 = v;
}

inline void Set728a(Unk8022FE34_Owner* t, float v)
{
    Set728b(t, v);
}

int Unk8022FE34_U::fn_802348F4()
{
    Unk8022FE34_Pl* pl = fn_801A497C((Unk8022FE34_Ctx*)m0, 4, 0);
    V3f p = FlatPos(*(V3f*)((char*)pl + 0x60));
    V3f d = p - lbl_805D7DCC;
    if (!(d.x * d.x + d.z * d.z >= lbl_805D728C)) {
        if (fn_8026D5FC((Unk8026C414_O*)pl, 0) != 0) {
            return 1;
        }
    }
    return 0;
}

void fn_802349E8(Unk8022FE34_Owner* t)
{
    if (fn_801A6DB8(t->m0)->m48 != 0) {
        Unk8022FE34_Pl* pl = fn_801A497C(t->m0, 4, 0);
        float* o = fn_80191800(lbl_8061C958[t->mC]);
        if (o != 0) {
            float* tb = t->m738;
            float c;
            float a;
            float b;
            a = 100.0f / tb[0x1C / 4];
            b = 36.0f / tb[0x20 / 4];
            c = o[1];
            float d = fn_80254618((Unk8024EF40_W*)((char*)pl + 0x588), 0);
            float r = Lerp(b, d, a);
            if (fn_801A6DB8(t->m0)->m48 != 0) {
                if (*(int*)((char*)pl + 0x480) == 0) {
                    const float k = 1.1f;
                    c = c * k;
                }
            }
            fn_80252EB8((char*)pl + 0x480, c * r);
        }
    }
}

int Unk8022FE34_U::fn_80234D5C()
{
    const float c = 4.0f;
    int r = fn_801C3E68(m8->m3A4);
    float t = (float)fn_80235FA8()->m4C * 0.016666668f;
    if (r == 0) {
        if (!(t - m6C <= c)) {
            r = 1;
        }
    }
    return r;
}

void Unk8022FE34_U::fn_80234E0C(float f)
{
    Set728a(m4, f);
}

Unk8022FE34_Pai* Unk8022FE34_U::fn_80234E38()
{
    return &m4->m38;
}

int Unk8022FE34_U::fn_80234E44()
{
    return 0;
}

inline void ArmA(Unk8022FE34_Owner* t, float f)
{
    t->m438.a = 1;
    t->m438.b = (int)(f * lbl_805D7310[0]);
}

void Unk8022FE34_U::fn_802350F8()
{
    if (m4->fn_802324EC()) {
        fn_8022F2B8(m4, 3);
        m80 = 0;
        m44 = 1;
        fn_802349E8(m4);
    } else
        m4->fn_8023246C();
}

void Unk8022FE34_U::fn_80235160() {}

void Unk8022FE34_U::fn_80235164()
{
    if (lbl_8061EDCC == 0 && m4->m18 != 0 && fn_8033E420((char*)fn_80235FA8() + 0x560) == 0) {
        switch (m4->m8) {
        case 0:
            fn_80234B18(this);
            break;
        case 1:
            fn_80234E4C(this);
            break;
        case 2:
            fn_802350F8();
            break;
        case 3:
            fn_80235160();
            break;
        case 4: /* no code in retail; the extra node moves the switch tree's root from case 1 to case 2 */
            break;
        }
    }
}

void Unk8022FE34_U::fn_80235220()
{
    char buf[0x80];
}

void Unk8022FE34_U::fn_8023522C(int a)
{
    if (a == 0x3d)
        m44 = 1;
}

void Unk8022FE34_U::fn_80235240()
{
    fn_8022F2B8(m4, 0);
    m4->fn_802326C4(0, 1);
    m4->fn_802326C4(1, 1);
}

void Unk8022FE34_U::fn_80235294()
{
    if (fn_80235FA8()->m6F4 == 2) {
        Unk8022FE34_VObj* o = fn_801C1638(fn_80235FA8(), 0);
        if (o != 0)
            o->v40(1);
    }
}

void Unk8022FE34_U::fn_80235300()
{
    fn_8022F2B8(m4, 0);
    fn_80235FB4();
}

void Unk8022FE34_U::fn_8023533C()
{
    fn_8023A7F4(&m4->m440);
}

void Unk8022FE34_U::fn_80235364()
{
    fn_8022F2B8(m4, 0);
}

void Unk8022FE34_U::fn_8023538C()
{
    fn_80235FB4();
    int a = fn_80235FA8()->m6CC;
    void* b = fn_80235FA8()->m65C;
    if (a != 0 && b != 0) {
        if (fn_8018AD2C(a) == 1) {
            fn_80189300(a, b);
        }
    }
    if (fn_80235FA8()->m6F4 == 3) {
        Unk8022FE34_Pl* pl = fn_801A497C(fn_80235FA8(), 0, 0);
        float f = 1.0f;
        switch (fn_802536D0((Unk8024EF40_P*)pl)) {
        case 0:
            f = 0.85f;
            break;
        case 1:
            f = 0.55f;
            break;
        case 2:
            f = 0.35f;
            break;
        case 3:
            f = 0.15f;
            break;
        }
        fn_80252DF4((char*)pl + 0x480, f);
    }
    m4->m72C = 0;
}

void Unk8022FE34_U::fn_80235618()
{
    if (m4->m8 == 2)
        fn_80235AD4();
    if (m80 == 0)
        m6C = lbl_805D730C;
    fn_8022F2B8(m4, 0);
    m78 = 0;
    m64 = 0;
    m44 = 0;
    float f = fn_802354AC();
    ArmA(m4, f);
    fn_802398C8(&m4->m440);
}

void Unk8022FE34_U::fn_802356D4()
{
    fn_8022F2B8(m4, 3);
    Unk8022FE34_U8s* p = &m8->m8;
    p->m10 = 0;
    p->mC = 1;
    fn_8022F174(this, 1);
    m80 = 1;
}

void Unk8022FE34_U::fn_80235730()
{
    fn_80233444(m4);
    m68++;
    fn_80235780(1, 0, 0);
}

void Unk8022FE34_U::fn_80235780(int a, int b, int c)
{
    Unk8022FE34_Ctx* ctx = fn_80235FA8();
    if (ctx->m6F4 == 0) {
        int i = 0;
        do {
            Unk8022FE34_Pl* pl = 0;
            if (c != 0)
                pl = fn_801A497C(fn_80235FA8(), i, 0);
            int n = fn_801A48F8(ctx, i);
            for (int k = 0; k < n; k++) {
                Unk8022FE34_Pl* q = fn_801A4910(ctx, i, k);
                if (pl != q)
                    fn_80253244(&q->m480, a, b);
            }
            i++;
        } while (i <= 1);
    }
}

void Unk8022FE34_U::fn_8023584C()
{
    fn_8022F174(this, 1);
    int v = fn_801A6DB8(fn_80235FA8())->m14;
    if (v != 0) {
        Unk8022FE34_U8s* p = &m8->m8;
        p->mC = 1;
        p->m10 = 0;
    } else
        m8->m8.mC = v;
    fn_80188698(fn_80235FA8()->m6CC, lbl_805D7314);
}

void Unk8022FE34_U::fn_802358D0()
{
    Unk8022FE34_U8s* p = &m8->m8;
    p->mC = 1;
    p->m10 = 0;
    fn_8022F174(this, 1);
}

void Unk8022FE34_U::fn_8023590C()
{
    Unk8022FE34_U8s* p = &m8->m8;
    p->mC = 1;
    p->m10 = 0;
    fn_8022F174(this, 1);
    fn_80188698(fn_80235FA8()->m6CC, lbl_805D7318);
}

void Unk8022FE34_U::fn_8023596C()
{
    fn_8022F174(this, 0);
    fn_8022F2B8(m4, 0);
    Unk8022FE34_Owner* t = m4;
    float f = lbl_805D731C;
    t->m438.a = 1;
    t->m438.b = (int)(f * lbl_805D7320[0]);
    Unk8022FE34_VObj* o = fn_801C1638(fn_80235FA8(), 0);
    if (o != 0) {
        int k = *(int*)((char*)o + 0x708);
        *(int*)(k * 4 + (int)lbl_8061D150) = fn_80088234(fn_80235FA8()->m6F8->mC->mC, k);
    }
}

void Unk8022FE34_U::fn_80235A28()
{
    m4->mC = 0;
    m4->m18 = 0;
}

inline void ArmP(Unk8022FE34_Pair* p, float f)
{
    p->a = 1;
    p->b = (int)(f * lbl_805D7324[0]);
}

void Unk8022FE34_U::fn_80235A40()
{
    int k = fn_80235C68();
    if (k <= 1) {
        if (k >= 0) {
            Unk8022FE34_Owner* t = m4;
            ArmP(&t->m438, fn_802354AC());
        }
    }
}

int Unk8022FE34_U::fn_80235AB8()
{
    return m4->m18;
}

void Unk8022FE34_U::fn_80235AC4()
{
    m4->m18 = 1;
}

void Unk8022FE34_U::fn_80235AD4()
{
    m4->m18 = 0;
}

inline float FAt(char* b, int i)
{
    int o = i * 4;
    return *(float*)(b + o);
}

/* near-miss: 63/63 insns, ~9 slots: retail keeps the table index in r0 (slwi r0,r0,2 / lfsx base,r0), ours in r9 */
void Unk8022FE34_U::fn_80235AE4()
{
    if (m64 == 0) {
        if (mC == 0 && m2C == 0 && m38 == 0 && m3C == 0) {
            float* tbl = m4->m738;
            int a = fn_801A2034(fn_80235FA8(), 4);
            int b = fn_801A2034(fn_80235FA8(), 3);
            int idx;
            if (a == -1) {
                idx = 1;
                if (b == -1) {
                    idx = 0;
                }
            } else {
                idx = 3;
                if (b == -1) {
                    idx = 2;
                }
            }
            float f = FAt((char*)tbl + 0x68, idx);
            Unk8022FE34_Owner* t = m4;
            t->m438.a = 1;
            t->m438.b = (int)(f * lbl_805D7328[0]);
        }
        m64 = 1;
    }
}

extern "C" Unk8022FE34_V2 fn_80235BE0(Unk8022FE34_U* u)
{
    return u->m4->m28;
}

Unk8022FE34_V2 Unk8022FE34_U::fn_80235BFC()
{
    return m4->m20;
}

extern "C" Unk8022FE34_V2 fn_80235C18(Unk8022FE34_U* u)
{
    return u->m4->m30;
}

Unk8022FE34_V3 Unk8022FE34_U::fn_80235C34()
{
    return m4->fn_80231E4C();
}

int Unk8022FE34_U::fn_80235C68()
{
    return m4->m8;
}

inline int Flag(Unk8022FE34_Ctx* c)
{
    int f = 0;
    if (c->m6F8->m14[2].m8 != 0)
        f = 1;
    return f;
}

float Unk8022FE34_U::fn_80235C74(int a)
{
    int f = Flag(fn_80235FA8());
    f = f ^ 1;
    Unk8022FE34_Ent e;
    m4->m38.fn_80230268(f, a, &e);
    return e.m8;
}

Unk8022FE34_V3 Unk8022FE34_U::fn_80235CEC(int a)
{
    int f = Flag(fn_80235FA8());
    f = f ^ 1;
    Unk8022FE34_Ent e;
    m4->m38.fn_80230268(f, a, &e);
    return fn_80233F08(&e, 0);
}

float Unk8022FE34_U::fn_80235D80()
{
    Unk8022FE34_Owner* t = m4;
    if (lbl_80620750 == 0)
        return t->m14;
    return lbl_80620754;
}

float Unk8022FE34_U::fn_80235DA8()
{
    Unk8022FE34_Owner* t = m4;
    if (lbl_80620748 == 0)
        return t->m10;
    return lbl_8062074C;
}

float Unk8022FE34_U::fn_80235DD0(int a, int b)
{
    Unk8022FE34_Ent e;
    Unk8022FE34_Ent* p = &e;
    m4->m38.fn_80230268(a, b, p);
    return p->m20;
}

int Unk8022FE34_U::fn_80235E28()
{
    return m4->mC;
}

int Unk8022FE34_U::fn_80235E34(int a, int idx)
{
    return m4C[idx];
}

int Unk8022FE34_U::fn_80235E44(int a, int key)
{
    for (int i = 0; i < m48; i++)
        if (m4C[i] == key)
            return i;
    return -1;
}

int Unk8022FE34_U::fn_80235E84(int a, int b)
{
    Unk8022FE34_Ent e;
    m4->m38.fn_80230268(a, b, &e);
    return e.m18;
}

Unk8022FE34_Z::Unk8022FE34_Z(Unk8022FE34_Ctx* c)
{
    m0 = c;
    fn_802361F4();
}

void Unk8022FE34_U::fn_80235EDC(float f)
{
    fn_802361F8(m4->m734, f);
}

int Unk8022FE34_U::fn_80235F0C(float* out)
{
    int r = 0;
    Unk8027C728_Goal* g = m4->fn_80231E90();
    if (g != 0) {
        Unk8028989C_Goal* sub = 0;
        if (g->m10 == 1) {
            sub = (Unk8028989C_Goal*)g->m18;
        }
        if (sub != 0) {
            r = fn_8028B068(sub, out);
        }
        fn_8027D368(g);
    }
    return r;
}

void Unk8022FE34_U::fn_80235F7C()
{
    fn_80235780(5, 1, 1);
}

Unk8022FE34_Ctx* Unk8022FE34_U::fn_80235FA8()
{
    return m4->m0;
}

extern "C" void fn_80236090(Unk8022FE34_U* u, int* dst, int* src);

void Unk8022FE34_U::fn_80235FB4()
{
    int side = Flag(fn_80235FA8());
    side = side ^ 1;
    m48 = m4->m38.fn_80230024(side);
    int arr[5];
    for (int i = 0; i <= 4; i++) {
        if (i < m48) {
            Unk8022FE34_Ent e;
            m4->m38.fn_8023003C(side, i, &e, 0);
            arr[i] = e.m0;
        } else {
            arr[i] = 0;
        }
    }
    fn_80236090(this, m4C, arr);
}

extern "C" void fn_80236090(Unk8022FE34_U* u, int* dst, int* src)
{
    int order[16] = { 15, 8, 9, 2, 6, 1, 5, 7, 3, 4, 10, 11, 12, 13, 14, 0 };
    int mark[16];
    for (int k = 0; k < 16; k++) {
        mark[k] = 0;
    }
    for (int k = 0; k < 5; k++) {
        mark[src[k]] = 1;
    }
    int k = 0;
    int n = 0;
    for (; k < 16 && n <= 4; k++) {
        int v = order[k];
        if (mark[v] != 0) {
            dst[n] = v;
            n++;
        }
    }
    for (; n <= 4; n++) {
        dst[n] = 0;
    }
}

void fn_802361F4() {}

void Unk8022FE34_Z::fn_802361F8(float f, int a)
{
    Unk8022FE34_Pl* pl = fn_801A497C(m0, 4, 0);
    fn_8025191C(pl, a, f);
}

void Unk8022FE34_Z::fn_80236240(float f)
{
    Unk8022FE34_Pl* pl = fn_801A497C(m0, 4, 0);
    if (!(fn_8025356C(&pl->m480) >= f))
        fn_802516CC(pl);
    else
        fn_802517F4(pl);
}
