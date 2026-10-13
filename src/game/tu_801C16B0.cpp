/*
 * Game code, .text 0x801C16B0-0x801C2C64 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801C16B0.h"

typedef Unk801B7FB0_P P;
typedef Unk801C16B0_Cmp C;

extern "C" {
void fn_801C0538(int a, int b);
void fn_801C38F0(void* self, float f);
void fn_801D6044(void* p);
void fn_801D7FCC(void* p);
void fn_801C1E44(void* self);
const char* fn_801C1710(void);
const char* fn_801C1778(void);
const char* fn_801C17E0(void);
}

typedef Unk801C16B0_Z Z;
typedef Unk801B7FB0_Ai A;
extern "C" {
P* fn_801A4B34(P* ctx);
void fn_801A656C(P* ctx, P* p, int k);
void fn_8017B1A4(Unk801C16B0_M4* a);
int fn_801C3FD0(Z* z, P* p);
void fn_801C3B04(Z* z, P* p);
void fn_801D5C5C(void* p);
void fn_801D5C1C(void* p);
void fn_801D7FD8(void* p);
void fn_801D5CBC(void* p);
void fn_801C34AC(Z* z, int k);
void fn_801D5F2C(void* p);
int fn_801D0294(void* p);
int fn_801C3F00(Z* z);
void fn_801CF1BC(Z* z);
int fn_801C4128(Z* z);
void fn_801D6178(void* p, int a, int b);
void fn_801D8788(void* p, P* q, int k);
void fn_801D801C(void* p, int a);
}
extern int* lbl_8061B9C4;

extern int lbl_8061CB38;
extern int lbl_8061CB34;
extern int lbl_8061CBBC;
extern const char lbl_805CCCE4[];
extern const char lbl_805CD948[];
extern const char lbl_805CD958[];







class Unk801C171C : public Unk8037B3E8 {
public:
    Unk801C171C();
    virtual ~Unk801C171C();
};

class Unk801C1784 : public Unk8037B3E8 {
public:
    Unk801C1784();
    virtual ~Unk801C1784();
};

/* Base with 0x18 bytes of data and the vptr after them (dtor at 0x80328374, defined elsewhere). */
class Unk80328374 {
public:
    char pad0[0x18];
    Unk80328374();
    virtual ~Unk80328374();
};
class Unk801C1810 : public Unk80328374 {
public:
    Unk801C1810();
    virtual ~Unk801C1810();
};

class Unk801C1AF0 {
public:
    virtual ~Unk801C1AF0();
};

extern "C" void fn_801C16B0(void) {}

extern "C" int fn_801C16B4(void) { return lbl_8061CB38; }

extern "C" unsigned fn_801C16C0(void) { return 0xEA9F4BCE; }

extern "C" int fn_801C16CC(void) { return lbl_8061CB34; }

extern "C" unsigned fn_801C16D8(void) { return 0xE608C67F; }

extern "C" const char* fn_801C16E4(void) { return fn_801C1710(); }

extern "C" unsigned fn_801C1704(void) { return 0x6F618F85; }

extern "C" const char* fn_801C1710(void) { return lbl_805CCCE4; }

Unk801C171C::~Unk801C171C() {}

extern "C" const char* fn_801C174C(void) { return fn_801C1778(); }

extern "C" unsigned fn_801C176C(void) { return 0xDA319B21; }

extern "C" const char* fn_801C1778(void) { return lbl_805CD948; }

Unk801C1784::~Unk801C1784() {}

extern "C" const char* fn_801C17B4(void) { return fn_801C17E0(); }

extern "C" unsigned fn_801C17D4(void) { return 0x0F245603; }

extern "C" const char* fn_801C17E0(void) { return lbl_805CD958; }

extern "C" float fn_801C17EC(P* p)
{
    P* q = p->m44C->m65C[9];
    if (q != 0)
        return q->mAB4;
    return 1.0f;
}

Unk801C1810::~Unk801C1810() {}

extern "C" void fn_801C1840(void) {}

extern "C" void fn_801C1844(void) {}

extern "C" void fn_801C1848(void) {}

extern "C" int fn_801C184C(C* c, int a, int b) { return a > b; }

extern "C" int fn_801C185C(C* c, int a, int b) { return a >= b; }

extern "C" int fn_801C1870(C* c, int a, int b) { return a < b; }

extern "C" int fn_801C1880(C* c, int a, int b) { return a <= b; }

extern "C" int fn_801C1894(C* c, int a, int b) { return a == b; }

extern "C" int fn_801C18A4(C* c, int lo, int hi, int x)
{
    int r = 0;
    if (x >= lo)
        r = x <= hi;
    return r;
}

extern "C" int fn_801C18C4(C* c, int a, int b) { return b <= a; }

extern "C" int fn_801C18D8(C* c, int a, int b) { return b >= a; }

extern "C" int fn_801C18EC(C* c, int a) { return a >= 0; }

extern "C" int fn_801C18F8(C* c, int a)
{
    if (a <= 0)
        return 1;
    return 0;
}

extern "C" int fn_801C190C(C* c, int a) { return a == 0; }

extern "C" int fn_801C1918(C* c, int a)
{
    if (a > 0)
        return 1;
    return 0;
}

extern "C" int fn_801C192C(C* c, int a) { return a < 0; }

extern "C" int fn_801C1934(void) { return lbl_8061CBBC; }

extern "C" unsigned fn_801C1940(void) { return 0xD1E132A4; }

extern "C" void fn_801C194C(void) {}

extern "C" int fn_801C1950(A* a) { return a->m8->mC; }

extern "C" void fn_801C195C(void) { fn_801C0538(1, 0xFFFF); }

extern "C" void fn_801C1988(void) { fn_801C0538(0, 0xFFFF); }

extern "C" float fn_80410CE8(float y, float x);
extern "C" float fn_804028E4(float x);
extern float lbl_806203AC;
extern float lbl_806203B0;
extern float lbl_806203B4;
extern float lbl_806203BC;
extern float lbl_806203C0;
extern float lbl_806203C4;
extern Vec3 lbl_80691AF4;
extern Vec3 lbl_806203CC;
extern int lbl_80691CA8;

extern "C" void fn_801C19B4(const Vec3* a, const Vec3* b, const Vec3* c)
{
    float yaw = fn_80410CE8(a->x, a->z);
    float pitch = fn_80410CE8(a->y, fn_804028E4(a->x * a->x + a->z * a->z));
    lbl_806203AC = yaw * 57.295773f;
    lbl_806203B0 = pitch * 57.295773f;
    lbl_806203B4 = fn_804028E4(a->x * a->x + a->y * a->y + a->z * a->z) * 0.05681818f;
    if (lbl_80691CA8 == 0) {
        lbl_806203BC = lbl_806203AC;
        lbl_806203C0 = lbl_806203B0;
        lbl_806203C4 = lbl_806203B4;
    }
    lbl_80691AF4 = *b;
    lbl_806203CC = *c;
}

Unk801C1AF0::~Unk801C1AF0() {}

extern "C" void fn_801C1E24(void* self) { fn_801C1E44(self); }

struct Unk801C16B0_V2 {
    float x;
    float y;
};
struct Unk801C16B0_S120 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
    Unk801C16B0_V2 m30;
    char pad38[0x44 - 0x38];
    float m44;
    char pad48[0x60 - 0x48];
    float m60;
    char pad64[0x88 - 0x64];
    int m88;
    int m8C;
    char pad90[0xA8 - 0x90];
    int mA8;
    int mAC;
    float mB0;
    float mB4;
    float mB8;
    float mBC[6];
    char padD4[0xD4 - 0xD4];
    int mD4;
    float mD8;
};
extern const Vec3 lbl_806055AC;
extern Unk801C16B0_V2 lbl_8060558C;
extern "C" void fn_801D7918(void* a);
inline float FOne() { return 1.0f; }
extern "C" void fn_801D03FC(void* a, void* b, P* c);
extern "C" void fn_801D7FC8(void* a);

extern "C" void fn_801C1E44(void* self)
{
    Z* z = (Z*)self;
    z->m208 = 10;
    z->m128 = 0;
    z->m288 = 0;
    z->m294 = 0.0f;
    z->m1FC = 0.0f;
    z->m200 = 6;
    Unk801C16B0_Mode* md = &z->m28C;
    md->m0 = 0;
    md->m4 = 0;
    fn_801D7918(z->m8);
    z->m120 = 0;
    Unk801C16B0_S120* s = (Unk801C16B0_S120*)&z->m120;
    s->m4 = 0;
    s->m10 = 5;
    s->mC = 0;
    s->m14 = 0;
    s->m1C = 0.0f;
    s->m20 = 0.0f;
    s->m24 = 0.0f;
    s->m28 = 0.0f;
    s->m2C = FOne();
    s->m30 = lbl_8060558C;
    s->m18 = 0.0f;
    s->m60 = 0.0f;
    z->m184 = lbl_806055AC;
    z->m190 = lbl_806055AC;
    s->m44 = 0.0f;
    z->m158 = lbl_806055AC;
    z->m168 = lbl_806055AC;
    z->m174 = lbl_806055AC;
    z->m19C = lbl_806055AC;
    s->m88 = 6;
    s->m8C = 0;
    z->m1B0 = lbl_806055AC;
    z->m1BC = lbl_806055AC;
    s->mA8 = 0;
    s->mAC = 0;
    s->mD4 = 0;
    s->mB0 = 0.0f;
    s->mB4 = 0.0f;
    s->mB8 = 0.0f;
    s->mD8 = 0.0f;
    for (int i = 0; i < 6; i++)
        s->mBC[i] = 0.0f;
    fn_801D03FC(z->m20C, z, z->m204);
    fn_801D7FC8(z->mE0);
    for (int i = 0; i < 3; i++) {
        z->m29C[i].a = lbl_806055AC;
        z->m29C[i].b = lbl_806055AC;
    }
    z->m298 = 0;
}

extern "C" void fn_801C20A8(char* self) { fn_801D6044(self + 0x20C); }

extern "C" void fn_801C20CC(Z* z)
{
    P* c = z->m204;
    if (c->m6F4 == 3) {
        P* q = fn_801A4B34(c);
        if (q)
            q->v8(1);
    }
}

extern "C" void fn_801C2120(char* self) { fn_801D7FCC(self + 0xE0); }

extern "C" void fn_801C2144(Z* z)
{
    P* p = 0;
    while (p != fn_801A4B34(z->m204)) {
        p = fn_801A4B34(z->m204);
        if (p->m458 != 9) {
            fn_801A656C(z->m204, p, 9);
            fn_8017B1A4(z->m4);
        }
    }
    if (p)
        p->m92C = 0xF;
    if (fn_801C3FD0(z, p))
        fn_801C3B04(z, p);
    fn_801D5C5C(z->m20C);
}

extern "C" void fn_801C21EC(Z* z)
{
    fn_801D5C1C(z->m20C);
    z->m288 = 0;
    z->m4->s8.SetC(0);
    if (z->m208 == 9 || z->m208 == 7)
        fn_801C34AC(z, 0);
    fn_801D7FD8(z->mE0);
    P* p = fn_801A4B34(z->m204);
    if (fn_801C3FD0(z, p))
        fn_801C3B04(z, p);
}

extern char lbl_80660650[];
struct Unk801C16B0_Msg5B {
    int m0;
    const void* vptr;
    int m8;
    int mC;
    void Base(int id)
    {
        vptr = lbl_80649DA0;
        m0 = id;
    }
    void Derived(int b, int a)
    {
        vptr = lbl_80660650;
        mC = b;
        m8 = a;
    }
};
struct Unk801C16B0_PW {
    char pad0[0x70C];
    unsigned char m70C;
};
struct Unk8024EF40_A;
void fn_80254DA4(Unk8024EF40_A* a, int b);
extern "C" int fn_80097190(Unk801B7FB0_Team* t, int a);
extern "C" int fn_80097300(Unk801B7FB0_Team* t, int a);
extern "C" P* fn_801A49F0(P* p, int k, int v);
extern "C" void fn_801A6A5C(P* p, Unk801B7FB0_Team* t, int idx, P* a, P* c, P* b);
extern "C" void fn_8037893C(void* mgr, int type, void* ev, int a, void* t);
void fn_8035B508(void* self, int c);
inline int Byte1CC9(unsigned char c) { return c; }
extern "C" void fn_801D043C(void* p);
extern "C" void fn_801C2284(Z* z);
extern "C" void fn_801D7AC4(void* p, P* q);

inline Vec3 Scale(const Vec3* v, float s)
{
    Vec3 r;
    r.x = v->x * s;
    r.y = v->y * s;
    r.z = v->z * s;
    return r;
}
inline Vec3 operator-(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}
inline Vec3 operator+(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}
inline Vec3 VNormalize(const Vec3& v, float len)
{
    Vec3 r;
    float inv = 1.0f / len;
    r.x = v.x * inv;
    r.y = v.y * inv;
    r.z = v.z * inv;
    return r;
}
inline float LengthR(const Vec3& v)
{
    return fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
}
extern const Vec3 lbl_806055AC;
inline Vec3 VUnit(const Vec3& v)
{
    float len = LengthR(v);
    if (len != 0.0f) {
        return VNormalize(v, len);
    }
    return lbl_806055AC;
}
extern "C" Vec3 fn_801C36EC(Z* z);
struct Unk801C16B0_ZW {
    char pad0[0x298];
    int m298;
};

extern "C" void fn_801C2284(Z* z)
{
    Vec3 p = fn_801C36EC(z);
    Vec3 dir = VUnit(Scale(&p, -1.0f));
    z->m29C[0].a = p - Scale(&dir, 3.0f);
    z->m29C[1].a = p;
    z->m29C[2].a = p + Scale(&dir, 3.0f);
    for (int i = 0; i < 3; i++)
        z->m29C[i].b = z->m29C[i].a;
    ((Unk801C16B0_ZW*)z)->m298 = 0;
}

extern "C" void fn_801C2544(Z* z)
{
    fn_801C2284(z);
    fn_801D043C(z->m20C);
    fn_801D7AC4(z->m8, z->m204);
    fn_801C34AC(z, 0);
    P* c = z->m204->m65C[9];
    int idx = c->m708;
    if (c)
        fn_80254DA4((Unk8024EF40_A*)&c->m58C, 0);
    if (Byte1CC9(z->m204->m6F8->m14->m1CC9) <= 2) {
        P* d = z->m204->m65C[0];
        unsigned char e1 = 0xFF;
        unsigned char e2 = 0xFF;
        if (c)
            e1 = ((Unk801C16B0_PW*)c)->m70C;
        if (d)
            e2 = ((Unk801C16B0_PW*)d)->m70C;
        Unk801C16B0_Msg5B m;
        m.Base(0x5B);
        m.Derived(e1, e2);
        fn_8037893C(&z->m204->m704, m.m0, &m, 0, 0);
        z->m288 = 0;
        fn_8035B508(&m, 2);
    }
    P* a = 0;
    P* b = 0;
    Unk801B7FB0_Team* t = &z->m204->m6F8->m14->t[idx];
    int e1 = fn_80097300(t, fn_80097190(t, -1));
    int e2 = fn_80097300(t, fn_80097190(t, 1));
    Unk801B7FB0_Team* t2 = &z->m204->m6F8->m14->t[idx];
    if (e1 != 0)
        a = fn_801A49F0(z->m204, idx, e1);
    if (e2 != 0)
        b = fn_801A49F0(z->m204, idx, e2);
    fn_801A6A5C(z->m204, t2, idx, a, c, b);
}

extern "C" void fn_801C26FC(void* self) { fn_801C38F0(self, 2.0f); }

extern "C" void fn_801C2724(Z* z)
{
    Unk801C16B0_Mode* m = &z->m28C;
    m->m0 = 1;
    m->m4 = 0;
    if (z->m124 == 2 && m->m0 != 0)
        m->m4 = 4;
    fn_801D5CBC(z->m20C);
}

extern "C" void fn_801C2A18(void* self) { fn_801C38F0(self, 0.0f); }

extern "C" void fn_801C2A40(Z* z)
{
    fn_801D5F2C(z->m20C);
    if (fn_801D0294(&z->m28C) == 1 && z->m4->s8.m8 == *lbl_8061B9C4 - 1) {
        P* c = z->m204;
        if (c->m65C[10] == 0 || c->m6F8->m14->m1CC9 == 2)
            fn_801C34AC(z, 9);
    }
}

extern "C" void fn_801C2AD0(Z* z, int flag)
{
    z->m28C.m0 = 0;
    if (flag) {
        fn_801C38F0(z, 0.0f);
    } else {
        if (z->m208 == 4)
            fn_801C34AC(z, 9);
        int s = z->m288;
        if ((unsigned)(s - 3) <= 1 || s == 7) {
            if (fn_801C3F00(z)) {
                fn_801CF1BC(z);
                z->m288 = 4;
                fn_801C34AC(z, 4);
            } else
                fn_801C34AC(z, 4);
        }
    }
}

extern "C" void fn_801C2B84(Z* z, int a, int b)
{
    if (fn_801C4128(z))
        fn_801D6178(z->m20C, a, b);
    if (a)
        fn_801C34AC(z, 8);
    else
        fn_801C34AC(z, 9);
    P* p = fn_801A4B34(z->m204);
    if (p)
        fn_801D8788(z->mE0, p, 0);
}

extern "C" void fn_801C2C10(Z* z, int a)
{
    if (fn_801C3F00(z))
        fn_801C38F0(z, 0.0f);
    fn_801D801C(z->mE0, a);
}
