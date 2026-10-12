/*
 * Game code, .text 0x801D31D8-0x801D771C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_801D31D8.h"
#include "game/tu_801800FC.h"

inline void* operator new(unsigned int, void* p) { return p; }

typedef Unk801D31D8 B;

extern float lbl_805D2C40;
extern const float lbl_805D2CD8;
extern const float lbl_805D2CDC;
extern const float lbl_805D2CE8;
extern float lbl_805D2CEC;
extern float lbl_805D2CF0;
extern float lbl_8061CBDC;
extern const float lbl_805D2CF4;
extern float lbl_805D2CF8;
extern float lbl_805D2D08;
extern float lbl_805D2D0C;
extern const char lbl_805D25E0[];
extern float lbl_805D29D8;
extern const float lbl_805D29DC;
extern float lbl_805D29E8;
extern float lbl_805D29EC;
extern float lbl_805D2BFC;
extern float lbl_805D2C00;
extern float lbl_805D2C10;
extern float lbl_805D2C14;
extern float lbl_805D2CC0;
extern const float lbl_805D2CC4;
extern float lbl_805D2CC8;
extern float lbl_805D2CCC;
extern float lbl_805D2CD0;
extern float lbl_805D2CD4;
extern float lbl_805D2C50;
extern float lbl_805D2C54;
extern float lbl_805D2C7C;
extern const float lbl_805D2D78;
extern float lbl_805D2D7C;
extern float lbl_805D2D80;
extern float lbl_805D2D84;
extern float lbl_8061CBE0;
extern float lbl_805D2C80;
extern float lbl_805D2D98;
extern float lbl_805D2C84;

extern "C" {
void fn_801D5CF0(B* s);
void fn_801D5D00(B* s);
void fn_801D67CC(B* s);
void fn_801D6D30(B* s, float a, float b);
void fn_801D6CE4(B* s, float a, float b);
void fn_801D6A1C(B* s, float* a, float* b);
void fn_801D7084(Unk801D31D8_Pair* s, int i, float v);
int fn_801C1638(Unk801D31D8_Game* g, int i);
void fn_801D7030(Unk801D31D8_Pair* s, int i, float v);
int fn_8035B3BC(void* p);
int fn_8018AD20(Unk801D31D8_Obj* o);
float fn_8022E7F0(int a, int b);
float fn_804028E4(float x);
Unk80183918_Vec3 fn_80189618(Unk801D31D8_Obj* o, float t);
float fn_801CF8CC(void* p, float f);
float fn_801CF740(void* p);
}

typedef void (*Pair2Fn)(Unk801D31D8_Pair*, int);

static inline int FlagZ(B* s)
{
    return s->m30->m6F8->m14->m1CD0 == 0;
}

static inline int FlagNZ(B* s)
{
    int t = 0;
    if (s->m30->m6F8->m14->m1CD0 != 0)
        t = 1;
    return t;
}

extern "C" void fn_801D34E4(B* s)
{
    float lo = lbl_805D29D8;
    float t;
    float hi;
    volatile int pad;
    float x = lbl_805D29DC;
    const char* file = lbl_805D25E0;
    unsigned r = s->m30->m554->fn_8014D8AC(1000000, file, 0x552);
    hi = lbl_805D29DC;
    t = (float)r * x * lbl_805D29E8;
    s->m44.m10 = lbl_805D29EC;
    s->m44.mC = t * (hi - lo) + lo;
}

static inline int Ok(int f) { if (f == -1 || f == 0) return 0; if ((f & 8) == 0) return 0; return 1; }
/* near-miss: 2 slots: retail sets li r0,1 before the andi. test of the flag word (andi. goes to r11); ours schedules andi. first.
 * Tried Ok() as && chain, early-return chains, nested if, unsigned range test, r=1 then clear. */
extern "C" int fn_801D3798(B* s)
{
    Unk801D31D8_Game* g = s->m30;
    int ok = Ok(g->m700->m3C0->m14);
    int r = 0;
    if (ok) {
        int a = 1;
        if (fn_801C1638(g, 0xA) == 0)
            a = 0;
        int b = 1;
        if (fn_801C1638(g, 0xB) == 0)
            b = 0;
        int c = fn_801C1638(g, 0xC) != 0;
        int t = 0;
        if (a != 0 || b != 0 || c != 0)
            t = 1;
        r = t ^ 1;
    }
    return r;
}

extern "C" void fn_801D5650(B* s)
{
    float a;
    float b;
    float lo;
    float t;
    float hi;
    volatile int pad;
    float x;
    s->m44.m8 = 1;
    a = fn_801CF8CC(s->m2C, s->m44.mC);
    b = fn_801CF740(s->m2C);
    lo = lbl_805D2BFC;
    x = lbl_805D2C00;
    const char* file = lbl_805D25E0;
    unsigned r = s->m30->m554->fn_8014D8AC(1000000, file, 0x824);
    t = (float)r * x * lbl_805D2C10;
    hi = lbl_805D2C14;
    s->m44.m4 = b * (t * (hi - lo) + lo) + a;
}

extern "C" int fn_801D5914(B* s, int a, int b)
{
    if (s->m38 != 0 && s->m44.m14 != 0) {
        if (s->m44.m1C != 0) {
            if (b != 0)
                return 1;
            return 0;
        }
        return (unsigned)(a + s->m44.m18) < s->m30->m4C;
    }
    return 0;
}

struct Unk801D31D8_Q {
    char pad0[0x64];
    int m64;
    float m68;
};

extern "C" int fn_801D5974(B* s)
{
    if (((Unk801D31D8_Q*)s)->m64 != 0 && ((Unk801D31D8_Q*)s)->m68 < (float)s->m30->m4C * lbl_805D2C40)
        return 1;
    return 0;
}

extern "C" int fn_801D59D8(B* s)
{
    if (fn_8035B3BC((char*)s->m2C + 0x28C) == 0 || (s->m38 != 0 && s->m44.m0 == 0))
        return 1;
    return fn_8018AD20(s->m30->m6CC) != 0;
}

extern "C" void fn_801D5A50(B* s, float* a, float* b)
{
    *a = s->m44.mC;
    *b = s->m44.m10;
}

extern "C" void fn_801D5C1C(B* s)
{
    int* a = &s->m44.m0;
    int* b = &s->m38;
    *b = 0;
    *a = 0;
    Unk801D31D8_Blk* q = &s->m44;
    q->m4 = lbl_805D2C50;
    q->m8 = 0;
    q->mC = lbl_805D2C50;
    q->m10 = lbl_805D2C50;
    q->m14 = 0;
    q->m18 = 0;
    q->m1C = 0;
    q->m20 = 0;
    q->m24 = lbl_805D2C50;
}

extern "C" void fn_801D5C5C(B* s)
{
    fn_801D5CF0(s);
}

extern "C" void fn_801D5C7C(B* s)
{
    int* a = &s->m44.m0;
    int* b = &s->m38;
    *b = 0;
    *a = 0;
    Unk801D31D8_Blk* q = &s->m44;
    q->m4 = lbl_805D2C54;
    q->m8 = 0;
    q->mC = lbl_805D2C54;
    q->m10 = lbl_805D2C54;
    q->m14 = 0;
    q->m18 = 0;
    q->m1C = 0;
    q->m20 = 0;
    q->m24 = lbl_805D2C54;
}

extern "C" void fn_801D5CBC(B* s)
{
    fn_801D5D00(s);
}

extern "C" void fn_801D5CDC(B* s, int* a, int* b)
{
    *a = s->m3C;
    *b = s->m40;
}

extern "C" void fn_801D5CF0(B* s)
{
    s->m3C = 0;
    s->m40 = 0;
}

extern "C" void fn_801D5F2C(B* s)
{
    if (s->m30->m6F4 == 0)
        return;
    int* a = &s->m44.m0;
    int* b = &s->m38;
    *b = 0;
    *a = 0;
    Unk801D31D8_Blk* q = &s->m44;
    q->m4 = lbl_805D2C7C;
    q->m8 = 0;
    q->mC = lbl_805D2C7C;
    q->m10 = lbl_805D2C7C;
    q->m14 = 0;
    q->m18 = 0;
    q->m1C = 0;
    q->m20 = 0;
    q->m24 = lbl_805D2C7C;
}

extern "C" void fn_801D5F7C(B* s)
{
    int* a = &s->m38;
    int* b = &s->m44.m0;
    *a = 0;
    *b = 0;
    Unk801D31D8_Blk* q = &s->m44;
    q->m4 = lbl_805D2C80;
    q->m8 = 0;
    q->mC = lbl_805D2C80;
    q->m10 = lbl_805D2C80;
    q->m14 = 0;
    q->m18 = 0;
    q->m1C = 0;
    q->m20 = 0;
    q->m24 = lbl_805D2C80;
    float len;
    Unk80183918_Vec3 v = fn_80189618(s->m30->m6CC, lbl_805D2C80);
    len = fn_804028E4(v.m0 * v.m0 + v.m4 * v.m4 + v.m8 * v.m8) * lbl_805D2C84;
    fn_801D7030(&s->m6C, FlagZ(s), len);
}

extern "C" void fn_801D6044(B* s)
{
    Unk801D31D8_Pair* p = &s->m6C;
    fn_8022E7F0(s->m30->m700->m3B0, FlagZ(s));
    ((Pair2Fn)fn_801D7084)(p, FlagZ(s));
    fn_8022E7F0(s->m30->m700->m3B0, FlagNZ(s));
    ((Pair2Fn)fn_801D7084)(p, FlagNZ(s));
}

extern "C" void fn_801D6108(B* s)
{
    Unk801D31D8_Pair* p = &s->m6C;
    fn_8022E7F0(s->m30->m700->m3B0, FlagZ(s));
    ((Pair2Fn)fn_801D7084)(p, FlagZ(s));
}

extern "C" void fn_801D63A8(B* s)
{
    s->m44.mC = lbl_805D2CC0;
    s->m44.m10 = lbl_805D2CC0;
    s->m44.m0 = 1;
    s->m44.m8 = 1;
    float r = fn_801CF8CC(s->m2C, s->m44.mC);
    s->m44.m4 = r;
}

extern "C" void fn_801D6404(B* s, int flag)
{
    s->m44.m10 = lbl_805D2CC4;
    s->m44.mC = lbl_805D2CC4;
    s->m44.m0 = 1;
    s->m44.m8 = 1;
    float a = fn_801CF740(s->m2C);
    float b = fn_801CF8CC(s->m2C, s->m44.mC);
    float c;
    if (flag != 0)
        c = lbl_805D2CC4;
    else
        c = lbl_805D2CC8;
    s->m44.m4 = a * c + b;
}

extern "C" void fn_801D64A0(B* s, int flag)
{
    s->m44.m0 = 1;
    s->m44.m8 = 1;
    s->m44.m10 = lbl_805D2CCC;
    s->m44.mC = lbl_805D2CCC;
    float a = fn_801CF740(s->m2C);
    float b = fn_801CF8CC(s->m2C, s->m44.mC);
    float c;
    if (flag != 0)
        c = lbl_805D2CD0;
    else
        c = lbl_805D2CD4;
    s->m44.m4 = a * c + b;
}

/* near-miss: second lerp's load order after the 2nd RNG call differs (hi2/x2 reload order, ~8 slots) */
extern "C" void fn_801D6538(B* s)
{
    float lo;
    float t;
    float hi;
    volatile int pad1;
    float x;
    volatile int pad2;
    float a;
    float b;
    float x2;
    s->m44.m0 = 1;
    s->m44.m8 = 1;
    lo = lbl_8061CBDC - lbl_805D2CD8;
    x = lbl_805D2CDC;
    const char* file = lbl_805D25E0;
    unsigned r = s->m30->m554->fn_8014D8AC(1000000, file, 0xA1F);
    hi = lbl_8061CBDC + lbl_805D2CD8;
    t = (float)r * x * lbl_805D2CE8;
    s->m44.mC = lbl_805D2CDC;
    s->m44.m10 = t * (hi - lo) + lo;
    a = fn_801CF740(s->m2C);
    b = fn_801CF8CC(s->m2C, s->m44.mC);
    lo = lbl_805D2CEC;
    x2 = lbl_805D2CDC;
    unsigned r2 = s->m30->m554->fn_8014D8AC(1000000, file, 0xA24);
    hi = lbl_805D2CF0;
    t = (float)r2 * x2 * lbl_805D2CE8;
    s->m44.m4 = a * (t * (hi - lo) + lo) + b;
}

extern "C" void fn_801D66C8(B* s)
{
    float a;
    float b;
    float lo;
    float t;
    float hi;
    volatile int pad;
    float x;
    s->m44.m10 = lbl_805D2CF4;
    s->m44.mC = lbl_805D2CF4;
    s->m44.m0 = 1;
    s->m44.m8 = 0;
    a = fn_801CF740(s->m2C);
    b = fn_801CF8CC(s->m2C, s->m44.mC);
    lo = lbl_805D2CF8;
    x = lbl_805D2CF4;
    const char* file = lbl_805D25E0;
    unsigned r = s->m30->m554->fn_8014D8AC(1000000, file, 0xA31);
    t = (float)r * x * lbl_805D2D08;
    hi = lbl_805D2D0C;
    s->m44.m4 = a * (t * (hi - lo) + lo) + b;
}

extern "C" void fn_801D67CC(B* s)
{
    s->m44.m0 = 0;
    s->m44.m8 = 0;
}

extern "C" void fn_801D6CE4(B* s, float a, float b)
{
    if (!(b >= lbl_8061CBE0))
        fn_801D6D30(s, a, b);
    else
        fn_801D67CC(s);
}

extern "C" void fn_801D6F6C(B* s)
{
    float a = lbl_805D2D78;
    float b = lbl_805D2D78;
    fn_801D6A1C(s, &a, &b);
    if (!(b <= lbl_805D2D78))
        fn_801D6CE4(s, a, b);
    else
        fn_801D6D30(s, a, b);
}

extern "C" Unk801D31D8_Pair* fn_801D6FE4(Unk801D31D8_Pair* s)
{
    fn_801D7084(s, 0, lbl_805D2D7C);
    fn_801D7084(s, 1, lbl_805D2D7C);
    return s;
}

extern "C" void fn_801D7030(Unk801D31D8_Pair* s, int i, float v)
{
    float k;
    s->m0[i] = s->m8[i] * (k = lbl_805D2D80) + s->m0[i] * lbl_805D2D84;
    s->m8[i] = v;
}

extern "C" float fn_801D7078(Unk801D31D8_Pair* s, int i)
{
    return s->m0[i];
}

extern "C" void fn_801D7084(Unk801D31D8_Pair* s, int i, float v)
{
    s->m8[i] = v;
    s->m0[i] = v;
}

/* Table object built by fn_801D70A8 (vtable lbl_80660700, name hash 0xC12D4655). */
extern "C" void fn_8033CCE0(void* p);
struct Unk801D70A8_E18 {
    float m0;
    char m4;
    char pad5[0x13];
    Unk801D70A8_E18()
    {
        m0 = lbl_805D2D98;
        m4 = 0;
    }
};
struct Unk801D70A8_E20 {
    float m0;
    float m4;
    float m8;
    char mC;
    char padD[0x13];
    Unk801D70A8_E20()
    {
        m0 = lbl_805D2D98;
        m4 = lbl_805D2D98;
        m8 = lbl_805D2D98;
        mC = 0;
    }
};
struct Unk801D70A8_List {
    int d0;
    int d1;
    int d2;
    Unk801D70A8_List() { fn_8033CCE0(this); }
};
class Unk801D70A8_Obj : public Unk8037B3E8 {
public:
    virtual const char* fn_vslot3();
    Unk801D70A8_Obj() : Unk8037B3E8(0xC12D4655u) {}
    Unk801D70A8_E18 m4[2];
    Unk801D70A8_E20 m34[4];
    Unk801D70A8_E20 mB4[6];
    Unk801D70A8_E18 m174[3];
    Unk801D70A8_List m1BC;
    Unk801D70A8_List m1C8;
    Unk801D70A8_List m1D4;
};

extern "C" void* fn_801D70A8(void* mem)
{
    return new (mem) Unk801D70A8_Obj;
}

