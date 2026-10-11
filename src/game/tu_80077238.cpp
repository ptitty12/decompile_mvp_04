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
