/*
 * Game code, .text 0x8019C1F8-0x8019F8C0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8019C1F8.h"
extern char lbl_80649DA0[];
extern char lbl_8065F9E0[];
struct Unk8019F644_Base {
    int m0;
    const void* m4;
    Unk8019F644_Base(int id)
    {
        m4 = lbl_80649DA0;
        m0 = id;
    }
};
struct Unk8019F644_Msg : public Unk8019F644_Base {
    void* m8;
    Unk8019F644_Msg(int id, void* p) : Unk8019F644_Base(id)
    {
        m4 = lbl_8065F9E0;
        m8 = p;
    }
    ~Unk8019F644_Msg() { m4 = lbl_80649DA0; }
};
class Unk8019F36C_E {
public:
    char pad0[0x18];
    virtual ~Unk8019F36C_E();
};
struct Unk8019F36C_S {
    char pad0[0x18];
    const void* m18;
    char pad1C[0x30 - 0x1C];
    const void* m30;
    char pad34[4];
    Unk8019F36C_E* m38[2];
};
extern char lbl_80660140[];
extern char lbl_80660158[];
extern "C" void fn_803BD720();
void fn_8035A5C4(void* p, int c);
extern "C" void fn_80328374(void* p, int c);
struct Unk8019DD34_E {
    float k;
    float v;
};
struct Unk8019DD34_C {
    float m0;
    Unk8019DD34_E e[8];
};
struct Unk8019CD04_E {
    float lo;
    float hi;
};
struct Unk8019CD04_O {
    float m0[2];
    char pad8[8];
    int m10[2];
    Unk8019CD04_E* m18[2];
    int m20;
    float m24;
    float m28;
    float m2C;
    float m30;
};
inline int Unk8019CD04_Cell(Unk8019CD04_O* o, int k, float x)
{
    float d = x - o->m0[k];
    if (!(d >= 0.0f))
        return -1;
    return (int)(d * 0.008333334f);
}
//@BODY
//@8019C41C
extern "C" float fn_8019C41C(float x)
{
    if (x > 0.0f)
        return (float)fn_80410634(x);
    return -(float)fn_80410634(-x);
}

//@8019CCE4
extern "C" void fn_8019CCE4(void* o, const float* a, const float* b)
{
    fn_8019CD04(o, a, b);
}

//@8019CD04
extern "C" int fn_8019CD04(void* op, const float* a, const float* b)
{
    Unk8019CD04_O* o = (Unk8019CD04_O*)op;
    if (o->m20 == 0)
        return 0;
    if (!(a[0] <= o->m24 || b[0] <= o->m24 || a[0] >= o->m2C || b[0] >= o->m2C || a[2] <= o->m28 || b[2] <= o->m28 || a[2] >= o->m30 || b[2] >= o->m30))
        return 1;
    for (int k = 0; k <= 1; k++) {
        float a1 = k == 0 ? a[0] : a[2];
        float b1 = k == 0 ? b[0] : b[2];
        float a2 = k == 0 ? a[2] : a[0];
        float b2 = k == 0 ? b[2] : b[0];
        int ia = Unk8019CD04_Cell(o, k, a1);
        int ib = Unk8019CD04_Cell(o, k, b1);
        if (ia < o->m10[k] && ia >= 0 && ia == ib) {
            Unk8019CD04_E* e = (Unk8019CD04_E*)((ia << 3) + (int)o->m18[k]);
            if (!(a2 >= e->hi || a2 <= e->lo || b2 >= e->hi) && b2 > e->lo)
                return 1;
        }
    }
    return 0;
}

//@8019CF24
extern "C" char* fn_8019CF24(void** o)
{
    return (char*)*o + 0x198;
}

//@8019CF30
extern "C" char* fn_8019CF30(void** o)
{
    return (char*)*o + 0x1A4;
}

//@8019CF3C
extern "C" float fn_8019CF3C(float t)
{
    float u = Unk8019CF3C_Norm(616.0f, t, 1408.0f);
    u = !(u > 1.0f) ? (u >? 0.0f) : 1.0f;
    return Unk8019CF3C_Lerp(lbl_8068BEB0, u, lbl_8068BEB4);
}

//@8019D010
extern "C" void fn_8019D010()
{
}

//@8019D014
Unk8019D014::~Unk8019D014()
{
}

//@8019DBA0
extern "C" float fn_8019DBA0(Unk8019DD34_C* arr, int idx, float t)
{
    Unk8019DD34_C* c = &arr[idx];
    if (!(t <= c->e[1].k)) {
        if (!(t >= c->e[0].k)) {
            float u = Unk8019CF3C_Norm(c->e[1].k, t, c->e[0].k);
            float r = Unk8019CF3C_Lerp(c->e[1].v, u, c->e[0].v);
            return r;
        }
    } else {
        for (int i = 2; i < 8; i++) {
            if (!(t <= c->e[i].k)) {
                float u = Unk8019CF3C_Norm(c->e[i].k, t, c->e[i - 1].k);
                float r = Unk8019CF3C_Lerp(c->e[i].v, u, c->e[i - 1].v);
                return r;
            }
        }
    }
    return 15.0f;
}

//@8019DD34
extern "C" int fn_8019DD34(void* self, Unk8019DD34_C* c, float* out, float* out0, float t)
{
    *out0 = c->m0;
    int found = 0;
    for (int i = 0; i < 7; i++) {
        if (c->e[i].k == t) {
            found = 1;
            *out = c->e[i].v;
        } else if (!(c->e[i].k < t)) {
            if (!(c->e[i + 1].k > t)) {
                float u = Unk8019CF3C_Norm(c->e[i + 1].k, t, c->e[i].k);
                *out = Unk8019CF3C_Lerp(c->e[i + 1].v, u, c->e[i].v);
                found = 1;
            }
        }
        if (found)
            break;
    }
    return found;
}

struct Unk8019DE2C_R {
    float m0;
    char pad4[0x10];
    float m14;
    char pad18[0x44 - 0x18];
};
struct Unk8019DE2C_T {
    Unk8019DE2C_R r[24];
};
inline Unk80183918_Vec3 Unk8019DE2C_Sub(const Unk80183918_Vec3& a, const Unk80183918_Vec3& b)
{
    Unk80183918_Vec3 r;
    r.m0 = a.m0 - b.m0;
    r.m4 = a.m4 - b.m4;
    r.m8 = a.m8 - b.m8;
    return r;
}
inline float Unk8019DE2C_LenR(const Unk80183918_Vec3& v)
{
    return fn_804028E4(v.m0 * v.m0 + v.m4 * v.m4 + v.m8 * v.m8);
}
//@8019DE2C
extern "C" float fn_8019DE2C(void* tp, void* unused, int ia, int ib)
{
    Unk8019DE2C_T* t = (Unk8019DE2C_T*)tp;
    float res = -1.0f;
    float len = Unk8019DE2C_LenR(Unk8019DE2C_Sub(*(const Unk80183918_Vec3*)ia, *(const Unk80183918_Vec3*)ib));
    Unk8019DE2C_R* p = &t->r[1];
    for (int i = 0; i < 23; i++, p++) {
        if (!(len <= p->m14)) {
            float u = Unk8019CF3C_Norm(p->m14, len, p[-1].m14);
            res = Unk8019CF3C_Lerp(p->m0, u, p[-1].m0);
            break;
        }
    }
    return res;
}

//@8019DF6C
extern "C" float fn_8019DF6C(void* tp, void* unused, int ia, int ib, float f)
{
    Unk8019DD34_C* t = (Unk8019DD34_C*)tp;
    float res = -1.0f;
    float len = Unk8019DE2C_LenR(Unk8019DE2C_Sub(*(const Unk80183918_Vec3*)ia, *(const Unk80183918_Vec3*)ib));
    float x1, y1, x2, y2;
    for (int i = 0; i <= 22; i++) {
        if (!(len > t[i].e[0].k)) {
            if (fn_8019DD34(tp, &t[i], &x1, &y1, len)) {
                if (fn_8019DD34(tp, &t[i + 1], &x2, &y2, len)) {
                    if (!(f < x1) && !(f > x2)) {
                        float u = Unk8019CF3C_Norm(x1, f, x2);
                        res = Unk8019CF3C_Lerp(y2, u, y1);
                        break;
                    }
                }
            }
        }
    }
    return res;
}

//@8019E3C0
Unk8019E3C0::Unk8019E3C0(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(12, owner)
{
}

//@8019E418
void Unk8019E3C0::v4()
{
    m1C = 0.0f;
    ((Unk8019E418_P*)m18->m700)->v0();
    fn_8017AFA0(m18->m700);
    fn_8017B0D8(m18->m700);
    fn_80157734(m18->m710);
}

//@8019E490
void Unk8019E3C0::v5()
{
    int* a = (int*)fn_801A6D84(m18, 1);
    if (*(int*)((char*)a + 0x3D90) == 0) {
        if (fn_801A6DB8(m18)->m6C != 0) {
            fn_801A04A8(lbl_8061B8C0->m8, 1)->m4 = 1;
            fn_8031E1D4(fn_801A04A8(lbl_8061B8C0->m8, 1), "hrdsplit1");
            fn_801A04A8(lbl_8061B8C0->mC, 1)->m4 = 1;
            fn_8031E1D4(fn_801A04A8(lbl_8061B8C0->mC, 1), "hrdsplit2");
        }
        fn_8033E3FC(this, 0xD);
    }
}

//@8019E558
void Unk8019E3C0::v6()
{
}

//@8019E55C
Unk8019E55C::Unk8019E55C(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(13, owner)
{
}

//@8019E5B4
void Unk8019E55C::v4()
{
    fn_8017B0D8(m18->m700);
    if (m18->m6F4 == 6)
        fn_801594A8(m18->m710);
}

//@8019E600
void Unk8019E55C::v5()
{
    if (fn_80162534(m18->m710) != 0) {
        if (lbl_80619D10->v25() != 0)
            fn_8033E3FC(this, 0x11);
        else if (m18->m6F4 == 9)
            fn_8033E3FC(this, 0xF);
        else
            fn_8033E3FC(this, 0xE);
    }
}

//@8019E6A0
void Unk8019E55C::v6()
{
}

//@8019E6A4
Unk8019E6A4::Unk8019E6A4(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(14, owner)
{
}

//@8019E6FC
void Unk8019E6A4::v4()
{
    fn_8017B238(m18->m700);
    m1C = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    Unk8019E3C0_Own* c = m18;
    if (c->m6F4 == 3) {
        int f = c->m6F8->m14->m1CD0 == 0;
        if (fn_801A2034(c, f) == -1)
            m24 = 0x3C;
    }
    ((Unk8019E6FC_Mid*)m18->m700)->m3B0->m7C = 0;
}

//@8019EB0C
void Unk8019E6A4::v6()
{
}

//@8019EB10
Unk8019EB10::Unk8019EB10(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(15, owner)
{
}

//@8019EB68
void Unk8019EB10::v4()
{
    int s = m18->m6F4;
    if (s == 6) {
        m1C = 0x3C;
        return;
    }
    if (s == 7) {
        m1C = 0x3C;
        return;
    }
    if (s == 9) {
        m1C = 0x3C;
        return;
    }
    m1C = fn_8040ABA0() % 20 + 0x91;
}

//@8019EF6C
void Unk8019EB10::v6()
{
}

//@8019EF70
Unk8019EF70::Unk8019EF70(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(16, owner)
{
}

//@8019EFC8
void Unk8019EF70::v4()
{
    switch (m18->m6F4) {
    case 7:
    case 9:
        break;
    default: {
        Unk8019E3C0_Own* c = m18;
        void* old = c->m6CC;
        fn_801A505C(c);
        if (m18->m6CC == old)
            fn_801A505C(m18);
    }
    }
    if (m18->m6F4 != 9)
        fn_8017BB60(m18->m700);
}

//@8019F040
void Unk8019EF70::v5()
{
    if (lbl_80619D10->v25() != 0)
        fn_8033E3FC(this, 0x11);
    if (m18->m6F4 == 9) {
        if (m18->m71C->m68 != 2)
            return;
        fn_8017BB60(m18->m700);
    }
    fn_8033E3FC(this, 0xD);
}

//@8019F0D0
void Unk8019EF70::v6()
{
    fn_8017BBF4(m18->m700);
}

//@8019F0F8
Unk8019F0F8::Unk8019F0F8(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(17, owner)
{
    m20 = 0;
    m1C = 0;
}

//@8019F158
void Unk8019F0F8::v4()
{
    m20 = 0;
    m1C = 0;
    fn_800AB9A8(lbl_80619D10, 0);
}

//@8019F194
void Unk8019F0F8::v5()
{
    int lim = 0x78 / lbl_8061B9C8;
    m1C = m1C + 1;
    if (m1C == lim) {
        fn_8017BE28(m18->m700);
        fn_801580A0(m18->m710);
    } else if (m1C > lim) {
        int* r = (int*)fn_801A6D84(m18, 1);
        if (*(int*)((char*)r + 0x3D90) == 0 && m20 == 0) {
            fn_800AB9A8(lbl_80619D10, 1);
            m20 = 1;
        }
    }
}

//@8019F23C
void Unk8019F0F8::v6()
{
}

//@8019F240
extern "C" void fn_8019F240(Unk8019E3C0_Own* m)
{
    char* list = (char*)m + 0x560;
    fn_8033E464(list, new (0) Unk8019E3C0(m));
    fn_8033E464(list, new (0) Unk8019E55C(m));
    fn_8033E464(list, new (0) Unk8019E6A4(m));
    fn_8033E464(list, new (0) Unk8019EB10(m));
    fn_8033E464(list, new (0) Unk8019EF70(m));
    fn_8033E464(list, new (0) Unk8019F0F8(m));
}

//@8019F32C
extern "C" void fn_8019F32C(char* m)
{
    void* list = m + 0x560;
    fn_8033E530(list, 0);
    fn_8033E5C4(list, 0xC);
}

//@8019F36C
extern "C" void fn_8019F36C(Unk8019F36C_S* self, int c)
{
    self->m30 = lbl_80660140;
    self->m18 = lbl_80660158;
    for (int i = 0; i < 2; i++) {
        delete self->m38[i];
        self->m38[i] = 0;
    }
    fn_803BD720();
    fn_8035A5C4((char*)self + 0x24, 0);
    fn_80328374(self, c);
}

//@8019F414
Unk8019F414::Unk8019F414(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(0, owner)
{
}

//@8019F468
void Unk8019F414::v5()
{
    fn_8033E3FC(this, 1);
}

//@8019F48C
Unk8019F48C::Unk8019F48C(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(1, owner)
{
}

//@8019F4E4
void Unk8019F48C::v4()
{
    if (fn_8011AA4C(this) != 10) {
        ((Unk8019E418_P*)m18->m700)->v0();
        fn_8017AFA0(m18->m700);
        m1C = 0;
    }
}

//@8019F54C
void Unk8019F48C::v5()
{
    if (m1C == 2) {
        fn_80158994(m18->m710);
    } else if (m1C > 2) {
        int* r = (int*)fn_801A6D84(m18, 1);
        if (*(int*)((char*)r + 0x3D90) == 0)
            fn_8033E3FC(this, 3);
    }
    m1C = m1C + 1;
}

//@8019F5C4
void Unk8019F48C::v6()
{
    fn_8017AF30(m18->m700);
}

//@8019F5EC
Unk8019F5EC::Unk8019F5EC(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(10, owner)
{
}

//@8019F644
void Unk8019F5EC::v4()
{
    fn_8017AFA0(m18->m700);
    Unk8019F644_Msg m(0x2D, (char*)m18 + 0x704);
    fn_8037893C((char*)m18 + 0x704, m.m0, (int)&m, 0, 0);
    fn_8037893C((char*)m18 + 0x704, 0x2E, 0, 0, 0);
}

//@8019F6DC
void Unk8019F5EC::v5()
{
    fn_8033E3FC(this, 2);
}

//@8019F700
void Unk8019F5EC::v6()
{
    fn_8017AF7C(m18->m700);
}

//@8019F728
Unk8019F728::Unk8019F728(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(2, owner)
{
}

//@8019F780
void Unk8019F728::v4()
{
    fn_80158CB8(m18->m710);
}

//@8019F7A8
void Unk8019F728::v5()
{
    int* r = (int*)fn_801A6D84(m18, 1);
    if (*(int*)((char*)r + 0x3D90) == 0)
        fn_8033E3FC(this, 3);
}

//@8019F7F4
void Unk8019F728::v6()
{
    fn_8017B0A4(m18->m700);
}

//@8019F81C
Unk8019F81C::Unk8019F81C(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(3, owner)
{
}

//@8019F874
void Unk8019F81C::v4()
{
    fn_8017B0D8(m18->m700);
    fn_80169674(m18->m710);
    fn_801593F8(m18->m710);
}

