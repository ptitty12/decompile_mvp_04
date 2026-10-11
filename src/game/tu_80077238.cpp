/*
 * Game code, .text 0x80077238-0x8007A4DC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8007A4DC.h"

void fn_8009532C(Handle* h);
void fn_80095EE4(Handle* h);
void fn_80091574(Handle* h);
void fn_80095460(Handle* h);
void fn_80095FE4(Handle* h);
void fn_800915F0(Handle* h);
void fn_80083448(Unk8007A4DC_Obj1E8* o, int a, unsigned short b);
void fn_800835E8(Unk8007A4DC_Obj1E8* o, int a, unsigned short b);
void fn_80083CEC(Unk8007A4DC_Obj1E8* o);
void fn_80084114(void);
int fn_80377E04(Obj* o, int* out, int id);
void fn_80400CE4(int a);
int fn_80377E04(Obj* o, int* out, int id);
void fn_800949B4(Handle* h, int a);
void fn_80095844(Handle* h, int a);
void fn_80377E90(Obj* list, int* a, int* b, int idx);
void* fn_8040B190(void* dst, const void* src, int n);
void fn_80400CE4(int a);
extern Unk8007A4DC_Screen* lbl_8061930C;
extern int lbl_80619310;
extern float lbl_80619314;
extern const float lbl_805B4078;
void fn_8059A3CC(void* p);
struct Unk80079240_Obj {
    char pad0[0x1C];
    void* m1C;
};

void Unk8007A4DC_Screen::fn_80077CF8()
{
    fn_8009532C(&m17C);
    fn_80095EE4(&m1C0);
    fn_80091574(&m4C);
}

void Unk8007A4DC_Screen::fn_80077D38(int a, int b)
{
    fn_80083448(m1E8, a, b);
}

void Unk8007A4DC_Screen::fn_80077D60(int a, int b)
{
    fn_800835E8(m1E8, a, b);
}

void Unk8007A4DC_Screen::fn_80077D88()
{
    fn_80083CEC(m1E8);
}

void Unk8007A4DC_Screen::fn_80077DAC()
{
    fn_80095460(&m17C);
    fn_80095FE4(&m1C0);
    fn_800915F0(&m4C);
}

void Unk8007B2B0_Screen::fn_80078A38(int a)
{
    fn_8007B8C4(0, a);
    fn_80084114();
}

int Unk8007A4DC_Screen::fn_80078A64(int a, int b, int c)
{
    unsigned n = fn_8007F674(a, b);
    unsigned i;
    for (i = 0; i < n; i++) {
        if (fn_8007F6C4(a, b, i) == c)
            return 1;
    }
    return 0;
}

void Unk8007A4DC_Screen::fn_80078AE0(int a, int* o1, int* o2, int* o3, int* o4)
{
    *o1 = 0;
    *o2 = 0;
    *o3 = 0;
    *o4 = 0;
    unsigned i = 0;
    unsigned n = fn_8007F198(a);
    for (; i < n; i++) {
        int e = fn_8007F24C(a, (unsigned char)i);
        int p = fn_8007A6A0(0x1E, e);
        int q = fn_8007A6A0(0x1F, e);
        int r = fn_8007A270(e);
        int f = 0;
        if (p != 0 && q > 0)
            f = 1;
        if (r != 0) {
            if (f)
                (*o1)++;
            else
                (*o2)++;
        } else {
            if (f)
                (*o3)++;
            else
                (*o4)++;
        }
    }
}

/* near-miss: 3 slots; retail evaluates `spC == 6` through cr7 (cmpwi cr7 / mfcr / extrwi),
 * we get xori/subfic/adde. */
int Unk8007A4DC_Screen::fn_80078D00(int a)
{
    int sp14 = 0;
    int sp8 = 0;
    int spC = 0;
    int sp10 = 0;
    fn_80078AE0(a, &sp8, &spC, &sp10, &sp14);
    int r = spC == 6;
    if (sp14 <= 9)
        r = 0;
    int i = 0;
    do {
        if (fn_8007F674(a, i) > 1)
            r = 0;
        i++;
    } while (i <= 1);
    return r;
}

int fn_80078DA4(void* self, int a, int b, int c)
{
    if (a == 10)
        a = 0;
    int f = 0;
    if ((c == 0 && a == 0) || (c == 1 && a == 1) || c == 2)
        f = 1;
    if (f == 0) {
        if (b != 0)
            return 3;
        return 1;
    }
    if (b == 0)
        return 0;
    return 2;
}

int fn_8007900C(void* self, int x)
{
    Unk8007A4DC_Screen* o = lbl_8061930C;
    int cnt = 0;
    unsigned i = 0;
    while (i < o->fn_8007F198(x)) {
        int e = o->fn_8007F24C(x, (unsigned char)i);
        if (e != 0 && o->fn_8007A270(e) != 0)
            cnt++;
        i++;
    }
    return cnt;
}

void fn_80079240(Unk80079240_Obj* o)
{
    fn_8059A3CC(o->m1C);
}

float Unk8007B2B0_Screen::fn_800799D0(int n)
{
    float v = m1F4;
    v = (float)n * m1F8 + v;
    return v;
}

float Unk8007B2B0_Screen::fn_80079A1C()
{
    return fn_800799D0(C1()->fn_8007A550(0x18));
}

int Unk8007B2B0_Screen::fn_80079A58(float f)
{
    f = f - m1F4;
    return (int)(f / m1F8);
}

float Unk8007B2B0_Screen::fn_80079A90(int n)
{
    float v = m1FC;
    v = (float)n * m200 + v;
    return v;
}

int Unk8007B2B0_Screen::fn_80079ADC(float f)
{
    f = f - m1FC;
    return (int)(f / m200);
}

float Unk8007B2B0_Screen::fn_80079B14(int a)
{
    float r = fn_80079F54(fn_8007B3E0(0x15, a));
    return r;
}

float Unk8007B2B0_Screen::fn_80079B5C(int a, int kind)
{
    int sel;
    if (kind != 0) {
        if (kind != 1) {
            sel = 0x19;
            if (kind == 2)
                sel = 0x18;
        } else {
            sel = 0x17;
        }
    } else {
        sel = 0x16;
    }
    float r = (float)fn_8007B3E0(sel, a) * m204;
    return r;
}

float Unk8007B2B0_Screen::fn_80079E74(int a)
{
    if (lbl_80619310 == 0) {
        float f = lbl_805B4078;
        f += fn_80079CF8(a);
        f += fn_80079BF8(a);
        return f;
    }
    return lbl_80619314;
}

float Unk8007B2B0_Screen::fn_80079EFC(int a)
{
    float x = fn_80079B14(a);
    float y = fn_80079E74(a);
    float r = x - y;
    return r;
}

/* near-miss: 3 slots; retail loads m204 before the int->float conversion and m1F4 after
 * it (fmadds f1,f1,f13,f0), ours loads them the other way round. */
float Unk8007B2B0_Screen::fn_80079F54(int n)
{
    return m1F4 + (float)n * m204;
}

int Unk8007B2B0_Screen::fn_80079F90(float f)
{
    return (int)((f - m1F4) / m204);
}

void fn_80079FC0(void* self, char** cursor, void* dst, int n)
{
    fn_8040B190(dst, *cursor, n);
    *cursor += n;
}

void Unk8007A4DC_Screen::fn_8007A008(int a)
{
    int x;
    Handle* h = &m17C;
    int f = fn_80377E04(fn_800A883C(h), &x, a) != 0;
    if (f == 1)
        fn_800949B4(h, a);
}

void Unk8007A4DC_Screen::fn_8007A06C(int a)
{
    int x;
    Handle* h = &m1C0;
    int f = fn_80377E04(fn_800A883C(h), &x, a) != 0;
    if (f == 1)
        fn_80095844(h, a);
}

int Unk8007B2B0_Screen::fn_8007A0D0(int idx)
{
    int x, y;
    int* px = &x;
    int* py = &y;
    fn_80377E90(fn_800A883C(&m4C), px, py, idx);
    return x;
}

int Unk8007A4DC_Screen::fn_8007A11C(int idx)
{
    int x, y;
    int* px = &x;
    int* py = &y;
    fn_80377E90(fn_800A883C(&m17C), px, py, idx);
    return x;
}

int Unk8007A4DC_Screen::fn_8007A168(int idx)
{
    int x, y;
    int* px = &x;
    int* py = &y;
    fn_80377E90(fn_800A883C(&m1C0), px, py, idx);
    return x;
}

int Unk8007A4DC_Screen::fn_8007A1B4(int a)
{
    return fn_80071814(m1C8, a);
}

int Unk8007A4DC_Screen::fn_8007A1D8(int a)
{
    int x;
    return fn_80377E04(fn_800A883C(&m17C), &x, a) != 0;
}

int Unk8007A4DC_Screen::fn_8007A224(int a)
{
    int x;
    return fn_80377E04(fn_800A883C(&m1C0), &x, a) != 0;
}

int Unk8007A4DC_Screen::fn_8007A270(int a)
{
    int r = fn_8007A6A0(5, a);
    int x = 0;
    if (r == 0 || r == 10)
        x = 1;
    return x;
}

/* near-miss: 8 slots; the order of the argument moves (mr r3,r30 first) differs. */
void Unk8007A4DC_Screen::fn_8007A2B4(int flags)
{
    unsigned i = 0;
    unsigned n = fn_8007B1EC();
    int v = fn_8007A550(0x1D);
    for (; i < n; i++) {
        if ((i & 0x1F) == 0)
            fn_80400CE4(0);
        if (flags & 1) {
            fn_8007A94C(0x1D, i, v);
            fn_8007A94C(0x1C, i, 0);
        }
        if (flags & 2) {
            fn_8007A94C(0x1E, i, 0);
            fn_8007A94C(0x1F, i, 0);
        }
    }
}

void Unk8007A4DC_Screen::fn_8007A380()
{
    unsigned n = fn_8007B238();
    unsigned i;
    for (i = 0; i < n; i++) {
        if ((i & 0x1F) == 0)
            fn_80400CE4(0);
        fn_8007ACFC(0x1B, i, fn_8007ACC4(0, i));
    }
}

float Unk8007A4DC_Screen::fn_8007A3FC(int a, int b)
{
    W* w = m184;
    return fn_8007189C(w, a, fn_80071814(w, b));
}

float Unk8007A4DC_Screen::fn_8007A444(int a, int b)
{
    W* w = m1C8;
    return fn_8007189C(w, a, fn_80071814(w, b));
}

float Unk8007A4DC_Screen::fn_8007A48C(int a, int b, int i)
{
    W* w = m188[i];
    return fn_8007189C(w, a, fn_80071814(w, b));
}
