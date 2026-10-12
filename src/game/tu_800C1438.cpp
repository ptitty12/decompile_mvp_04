/*
 * Game code, .text 0x800C1438-0x800C2F90 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800BCD38.h"
#include "game/tu_800BCD38_decls.h"

/* fn_800C1C8C: the list at +0xC0 is the 0x18-byte array-with-buffer object (db_8053967C.h
 * Unk80535650_Tmp family): vtables lbl_8064B298, lbl_8064A550, lbl_8065C1B0 go into the vptr
 * slot in turn around the 0xFA-int buffer at +0xD8. */
extern char lbl_8064B298[];
extern char lbl_8064A550[];
extern char lbl_8065C1B0[];
extern char lbl_806841F8[];
extern "C" void fn_8040074C(void* p, unsigned n);
extern "C" void fn_8052DD58(void* e);
extern "C" void fn_80599B24(void* s);
extern "C" void fn_800C1D6C(Unk800C1D6C_Obj* o);
struct Unk800C1C8C_List {
    int* m0;
    unsigned m4;
    unsigned m8;
    int mC;
    const void* vp;
    int m14;
    void C1(int* buf, int cap)
    {
        vp = lbl_8064B298;
        m0 = buf;
        m8 = cap;
        fn_8040074C(m0, cap << 2);
    }
    void C2()
    {
        m4 = 0;
        mC = 0;
        vp = lbl_8064A550;
        fn_8040074C(m0, m8 << 2);
    }
    void C3(const void* v)
    {
        vp = v;
        m4 = 0;
        mC = 0;
        m14 = 0;
    }
};
struct Unk800C1C8C_Flags {
    char m0;
    char m1;
    short m2;
};
extern "C" void fn_80599B54(void* s);
extern "C" void fn_800C1FA0(Unk800C1D6C_Obj* o);
extern "C" void fn_800C1FF4(Unk800C1D6C_Obj* o);
extern "C" void fn_800C207C(Unk800C1D6C_Obj* o);
extern "C" void fn_800C2100(Unk800C1D6C_Obj* o);
extern "C" void fn_800C218C(Unk800C1D6C_Obj* o, const int* src, int n);
extern "C" {
int fn_8040B574(const char* a, const char* b);
void* fn_803774A8(unsigned n, int heap);
void fn_80377408(void* p);
void fn_800C17D4(Unk800C1754_Pool* p);
void* fn_803ED9D4();
void fn_803ED95C(void* h);
void fn_803ED8EC(void* h);
void fn_803ED720(void* h, const char* name, void* buf, unsigned size, int a, int b, int c, int d, int e, int f);
int fn_8007F7D0(void* a, int b);
void fn_8057CF60(int a, int b);
int fn_800A2AE8(void* a);
void fn_8033E958(const char* fmt, ...);
int fn_800C519C(Unk800C341C_Mgr* mgr, int n);
}

extern "C" {
int fn_804089B4(char* dst, const char* fmt, ...);
int fn_803FAB68(const char* path, int a, int* out);
void fn_800C3054(Unk800C2250_File* f, const char* name, Unk800C1BE4_Widget* w, int c, float t);
}

struct Unk800C2580_Cfg {
    char pad0[0x204];
    int m204;
};
extern Unk800C2580_Cfg* lbl_8061FEDC;
extern const char* lbl_8061ABA4;
extern const char* lbl_8061ABA0;
extern const char* lbl_8061AB8C;
extern const char* lbl_8061AB88;
extern const float lbl_805BBDCC;
extern const float lbl_805BBDD0;
extern const char lbl_805BBD3C[];
extern const char lbl_805BBD44[];
extern const char lbl_805BB0E4[];
extern void* lbl_8061A5A8;
extern void* lbl_8061930C;
extern void* lbl_80619948;
extern const char lbl_805BB014[];
extern const char lbl_805BBD50[];
extern const char lbl_805BBD90[];
extern const char lbl_805BBDD4[];
extern char lbl_805B6F58;

extern "C" int fn_800C16CC(Unk800C16CC_Holder* h, const char* name)
{
    int i = 0;
    if (i < h->m10->m1C4) {
        do {
            if (fn_8040B574(name, h->m10->m34[i]->mC) == 0)
                return 0;
            i++;
        } while (i < h->m10->m1C4);
    }
    return 1;
}

extern "C" void fn_800C1754(Unk800C1754_Pool* p, int n)
{
    int size = n << 10;
    int zero = 0;
    fn_800C17D4(p);
    p->m18 = fn_803774A8(size, 0);
    p->m0 = (int)fn_803ED9D4();
    lbl_8061A5A8 = (void*)p->m0;
    fn_803ED720((void*)p->m0, lbl_805BB014, p->m18, size, 4, 0x80, 0, 0, zero, zero);
}

extern "C" void fn_800C17D4(Unk800C1754_Pool* p)
{
    if ((void*)p->m0 != 0) {
        fn_803ED95C((void*)p->m0);
        fn_803ED8EC((void*)p->m0);
        fn_80377408(p->m18);
        p->m0 = 0;
        lbl_8061A5A8 = 0;
        p->m18 = 0;
    }
}

struct Unk800C1A24_Inner {
    char pad0[0x198];
    int m198;
    char pad19C[0xE60];
    int mFFC;
};
struct Unk800C1A24_X {
    char pad0[0x74];
    int m74;
};
struct Unk800C1A24_Mid {
    char pad0[0x10];
    Unk800C1A24_X* m10;
    Unk800C1A24_Inner* m14;
};
struct Unk800C1A24_Root {
    int m0;
    Unk800C1A24_Mid* m4;
    Unk800C1A24_Mid* m8;
};
extern Unk800C1A24_Root* lbl_806192E0;
extern void* lbl_8061E978;
extern const char lbl_805BB110[];
extern const char lbl_805BB0FC[];
extern "C" {
int fn_800B54BC(int v);
void fn_802B0224(void* obj, const char* buf, int n);
int fn_803FED48(const char* path, int a, int b, int* c);
}

extern "C" void fn_800C1A24()
{
    void* obj = lbl_8061E978;
    Unk800C1A24_Mid** p = &lbl_806192E0->m4;
    Unk800C1A24_Mid* e = *p;
    int src1;
    int src2;
    int lo = 1;
    int hi = 2;
    int k = e->m10->m74;
    if (k >= lo && k <= hi) {
        src1 = e->m14->m198;
        src2 = p[1]->m14->m198;
    } else {
        src1 = e->m14->m198;
        src2 = e->m14->mFFC;
    }
    int a = fn_800B54BC(fn_800B5520((void*)src1)) - 1;
    int b = fn_800B54BC(fn_800B5520((void*)src2)) - 1;
    char b1[0x400] = "";
    char b2[0x400] = "";
    int out = 0;
    fn_803FED48(lbl_805BB0FC, 0x100, 0, &out);
    fn_804089B4(b1, lbl_805BB110, a, lbl_805BB0E4);
    fn_802B0224(obj, b1, 0x400);
    if (a != b) {
        fn_804089B4(b2, lbl_805BB110, b, lbl_805BB0E4);
        fn_802B0224(obj, b2, 0x400);
    }
    fn_803FEDB8((void*)out, 100);
}

extern "C" int fn_800C1B80(const char* s)
{
    int v = 0;
    int neg = 0;
    if (*s == '-') {
        neg = 1;
        s++;
    }
    while ((unsigned char)(*s - '0') <= 9) {
        v = v * 10 + *s - '0';
        s++;
    }
    if (neg)
        return -v;
    return v;
}

extern "C" float fn_800C1BE4(void* unused, int a, int b)
{
    float r = 0.0f;
    if (b <= 0x4D) {
        switch (a) {
        case 0:
            r = 0.0f;
            break;
        case 1:
            r = 1.5707964f;
            break;
        case 2:
            r = 3.1415927f;
            break;
        case 3:
            r = 4.712389f;
            break;
        }
    } else {
        r = (float)a * 0.017453294f;
    }
    return r;
}

extern "C" Unk800C1D6C_Obj* fn_800C1C8C(Unk800C1D6C_Obj* o)
{
    o->mC = 0;
    Unk800C1C8C_Flags* f = (Unk800C1C8C_Flags*)&o->mC;
    f->m1 = 0;
    f->m2 = 0;
    Unk800C1C8C_List* l = (Unk800C1C8C_List*)((char*)o + 0xC0);
    int zero = 0;
    char* e = (char*)o + 0x3C;
    *(const void**)(e + 0x14) = lbl_806841F8;
    fn_8052DD58(e);
    fn_80599B24((char*)o + 0x8C);
    l->C1((int*)((char*)o + 0xD8), 0xFA);
    l->C2();
    l->C3(lbl_8065C1B0);
    fn_800C1D6C(o);
    *(int*)((char*)o + 0x568) = -1;
    return o;
}

extern "C" void fn_800C1D6C(Unk800C1D6C_Obj* o)
{
#define F(off) (*(int*)((char*)o + (off)))
    fn_800C1FA0(o);
    fn_800C207C(o);
    fn_800C1FF4(o);
    fn_800C2100(o);
    F(0x28) = 0;
    F(0x38) = 0;
    fn_8052DD58((char*)o + 0x3C);
    F(0x54) = -1;
    F(0x58) = 0;
    F(0x5C) = 0;
    F(0x60) = 0;
    F(0x64) = 0;
    F(0x68) = 0;
    F(0x6C) = 0;
    F(0x70) = 0;
    F(0x74) = 0;
    F(0x78) = 0;
    F(0x7C) = 0;
    F(0x80) = 0;
    F(0x84) = 1;
    F(0x88) = 0;
    fn_80599B54((char*)o + 0x8C);
    F(0xB8) = 0;
    F(0xBC) = 0;
    Unk800C1C8C_List* l = (Unk800C1C8C_List*)((char*)o + 0xC0);
    fn_8040074C(l->m0, l->m8 << 2);
    l->m4 = 0;
    l->mC = 0;
    l->m14 = 0;
    F(0x508) = 3;
    F(0x520) = 0xA2;
    F(0x4C0) = 0;
    F(0x4C4) = 6;
    F(0x4C8) = 0;
    F(0x4CC) = 0;
    F(0x4D0) = 0;
    F(0x4D4) = 6;
    F(0x4D8) = 0;
    F(0x4DC) = 0;
    F(0x4E0) = 0;
    F(0x4E4) = 0;
    F(0x4E8) = 0;
    F(0x4EC) = 0;
    F(0x4F0) = 0;
    F(0x4F4) = 0;
    F(0x4F8) = -1;
    F(0x4FC) = 0;
    F(0x500) = 0;
    F(0x504) = 0;
    F(0x50C) = 0;
    F(0x510) = 0;
    F(0x514) = 0;
    F(0x518) = 0;
    F(0x51C) = 0;
    F(0x524) = 0;
    F(0x528) = 0;
    F(0x52C) = 0;
    F(0x530) = 0;
    F(0x534) = 0;
    F(0x538) = 0;
    F(0x53C) = 0;
    F(0x540) = 0;
    F(0x544) = 0;
    F(0x548) = 0;
    F(0x54C) = 0;
    F(0x550) = 0;
    F(0x554) = 0;
    F(0x558) = 0;
    F(0x55C) = 0;
    F(0x560) = 0;
    F(0x564) = 0;
    F(0x578) = 0;
    F(0x57C) = 5;
    F(0x580) = 0;
    F(0x584) = 0;
    F(0x588) = 0;
    F(0x58C) = 0;
    F(0x590) = 0;
    F(0x594) = 0;
    F(0x574) = 0xA;
    fn_800C218C(o, 0, 0);
    F(0x618) = 5;
    F(0x630) = 1;
    F(0x64C) = 6;
    F(0x600) = 0;
    F(0x604) = 0;
    F(0x608) = -1;
    F(0x60C) = 0;
    F(0x610) = -1;
    F(0x614) = 0;
    F(0x61C) = 0;
    F(0x620) = 0;
    F(0x624) = 0;
    F(0x628) = 0;
    F(0x62C) = 0;
    F(0x634) = 0;
    F(0x638) = 0;
    F(0x63C) = 0;
    F(0x640) = 0;
    F(0x644) = 0;
    F(0x648) = 0;
    F(0x650) = -1;
    F(0x65C) = 0;
    F(0x2C) = 0;
    F(0x654) = -1;
    F(0x658) = 0x18;
    F(0x30) = 0;
    F(0x664) = 4;
    F(0x34) = 0;
    F(0x668) = 4;
#undef F
}

extern "C" void fn_800C1FA0(Unk800C1D6C_Obj* o)
{
    o->m0 = 1;
    o->m4 = 0;
    o->m8 = 0;
    o->mD = 1;
    o->mC = 1;
    o->mE = 1000;
}

extern "C" void fn_800C1FC8(Unk800C1D6C_Obj* o, int a, int b, int c)
{
    o->m0 = a;
    o->m4 = b;
    o->m8 = c;
}

extern "C" void fn_800C1FD8(Unk800C1D6C_Obj* o, int* a, int* b, int* c)
{
    *a = o->m0;
    *b = o->m4;
    *c = o->m8;
}

extern "C" void fn_800C1FF4(Unk800C1D6C_Obj* o)
{
    o->m14 = 0;
    o->m18 = 0;
    o->m1C = 0;
}

extern "C" void fn_800C2008(Unk800C1D6C_Obj* o, int a, int b, int c)
{
    o->m14 = a;
    o->m18 = b;
    o->m1C = c;
}

extern "C" void fn_800C2018(Unk800C1D6C_Obj* o, int* a, int* b, int* c)
{
    *a = o->m14;
    *b = o->m18;
    *c = o->m1C;
}

extern "C" void fn_800C2034(Unk800C1D6C_Obj* o, int v)
{
    o->m600 = v;
}

extern "C" void fn_800C203C(Unk800C1D6C_Obj* o)
{
    fn_8057CF60(fn_8007F7D0(lbl_8061930C, 0), o->m600);
}

extern "C" void fn_800C207C(Unk800C1D6C_Obj* o)
{
    o->m10 = 0;
}

extern "C" void fn_800C2088(Unk800C1D6C_Obj* o, int a, int b)
{
    if (a == 0) {
        if (b > o->m68)
            o->m64 = a;
    } else {
        o->m64 = a;
        o->m68 = b;
    }
}

extern "C" void fn_800C20B0(Unk800C1D6C_Obj* o, int v)
{
    o->m74 = v;
}

extern "C" int fn_800C20B8(Unk800C1D6C_Obj* o)
{
    return o->m74;
}

extern "C" void fn_800C20C0(Unk800C1D6C_Obj* o, int a, int b)
{
    o->m7C = a;
    o->m80 = b;
}

extern "C" void fn_800C20CC(Unk800C1D6C_Obj* o, int* a, int* b)
{
    *a = o->m7C;
    *b = o->m80;
}

extern "C" void fn_800C20E0(Unk800C1D6C_Obj* o, int a, int b)
{
    o->m84 = a;
    o->m88 = b;
}

extern "C" void fn_800C20EC(Unk800C1D6C_Obj* o, int* a, int* b)
{
    *a = o->m84;
    *b = o->m88;
}

extern "C" void fn_800C2100(Unk800C1D6C_Obj* o)
{
    o->m20 = 0;
    o->m24 = 0;
}

extern "C" void fn_800C2110(Unk800C1D6C_Obj* o, const Unk800C1D6C_Block44* src)
{
    o->m8C = *src;
}

extern "C" Unk800C1D6C_Block44* fn_800C2184(Unk800C1D6C_Obj* o)
{
    return &o->m8C;
}

extern "C" void fn_800C218C(Unk800C1D6C_Obj* o, const int* src, int n)
{
    for (int i = 0; i < 25; i++) {
        if (i < n)
            o->m59C[i] = src[i];
        else
            o->m59C[i] = 0;
    }
    o->m598 = n;
}

extern "C" void fn_800C21D0(Unk800C1D6C_Obj* o)
{
    o->m640 = fn_800A2AE8(lbl_80619948);
}

extern "C" int fn_800C2208(Unk800C1D6C_Obj* o)
{
    return o->m640;
}

extern "C" void fn_800C2210(Unk800C1D6C_Obj* o)
{
    o->m644 = fn_800A2AE8(lbl_80619948);
}

extern "C" int fn_800C2248(Unk800C1D6C_Obj* o)
{
    return o->m644;
}

Unk800C2250_File::Unk800C2250_File()
{
    fn_800C2FF0(this);
}

Unk800C2250_File::~Unk800C2250_File()
{
}

extern "C" int fn_800C32C4(Unk800C2250_File* f, int kind, void** out);
extern const float lbl_805BBD4C;
extern const char* lbl_8061AB80[];

extern "C" int fn_800C22C0(Unk800C2250_File* f, int kind, const char* name, Unk800C1BE4_Widget* w, float t, int flag)
{
    char a[0x400];
    char b[0x400];
    int out;
    fn_804089B4(a, lbl_805BBD3C, name, lbl_805BB0E4);
    if (kind == 2 && lbl_8061FEDC->m204 != 0)
        fn_804089B4(b, lbl_805BBD44, lbl_8061AB8C, a);
    else
        fn_804089B4(b, lbl_805BBD44, lbl_8061AB80[kind], a);
    int c = fn_803FAB68(b, 1, &out);
    int ok = 0;
    if (c)
        ok = 1;
    if (ok != 0) {
        f->m400 = kind;
        f->m460 = fn_800C32C4(f, kind, &f->m45C);
        fn_800C3054(f, name, w, flag, t);
        return 1;
    }
    if (w != 0 && kind != 1) {
        w->fn_vslot28(&lbl_805B6F58, 0);
        w->fn_vslot8(1);
        w->fn_vslot20(lbl_805BBD4C);
    }
    return 0;
}

extern "C" void fn_800C2458(Unk800C2250_File* f)
{
    while (fn_800C2EF0(f) && fn_800C2F88(f))
        fn_800C2B94(f, 0);
}

extern "C" void fn_800C24B0(Unk800C2250_File* f)
{
    f->m400 = 8;
    f->m404 = 1;
    int size = fn_800C519C(fn_800C33D0(), 8);
    f->m45C = fn_803774A8(size, 0x400);
    f->m460 = size;
    fn_8033E958(lbl_805BBD50);
}

extern "C" void fn_800C2518(Unk800C2250_File* f)
{
    f->m400 = 2;
    f->m404 = 1;
    int size = fn_800C519C(fn_800C33D0(), 2);
    f->m45C = fn_803774A8(size, 0x400);
    f->m460 = size;
    fn_8033E958(lbl_805BBD90);
}

extern "C" void fn_800C2580(Unk800C2250_File* f, const char* name, Unk800C1BE4_Widget* w, int c, float t)
{
    char a[0x400];
    char b[0x400];
    int out;
    fn_804089B4(a, lbl_805BBD3C, name, lbl_805BB0E4);
    if (lbl_8061FEDC->m204 != 0)
        fn_804089B4(b, lbl_805BBD44, lbl_8061ABA4, a);
    else
        fn_804089B4(b, lbl_805BBD44, lbl_8061ABA0, a);
    if (fn_803FAB68(b, 1, &out)) {
        fn_800C3054(f, name, w, c, t);
    } else if (w != 0) {
        w->fn_vslot28(&lbl_805B6F58, 0);
        w->fn_vslot8(1);
        w->fn_vslot20(lbl_805BBDCC);
    }
}

extern "C" void fn_800C26D0(Unk800C2250_File* f, const char* name, Unk800C1BE4_Widget* w, float t, int c)
{
    char a[0x400];
    char b[0x400];
    int out;
    if (f->m404 == 4 && !(t >= lbl_805BBDD0))
        t = lbl_805BBDD0;
    fn_804089B4(a, lbl_805BBD3C, name, lbl_805BB0E4);
    if (lbl_8061FEDC->m204 != 0)
        fn_804089B4(b, lbl_805BBD44, lbl_8061AB8C, a);
    else
        fn_804089B4(b, lbl_805BBD44, lbl_8061AB88, a);
    if (fn_803FAB68(b, 1, &out)) {
        fn_800C3054(f, name, w, c, t);
    } else if (w != 0) {
        w->fn_vslot28(&lbl_805B6F58, 0);
        w->fn_vslot8(1);
        w->fn_vslot20(lbl_805BBDD0);
    }
}

extern "C" void fn_800C2848(Unk800C2250_File* f)
{
    while (fn_800C2F44(f) && fn_800C2F88(f))
        fn_800C2B94(f, 0);
    fn_800C31FC(f);
    f->m0 = lbl_805B6F58;
    f->m404 = 1;
    f->m454 = 0;
    f->m458 = 0;
}

extern "C" void fn_800C28C8(Unk800C2250_File* f)
{
    while (fn_800C2F5C(f) && fn_800C2F88(f))
        fn_800C2B94(f, 0);
    fn_800C31FC(f);
    f->m0 = lbl_805B6F58;
    f->m404 = 1;
    f->m454 = 0;
    f->m458 = 0;
}

extern "C" void fn_800C2948(Unk800C2250_File* f)
{
    fn_800C2978(f);
    fn_8033E958(lbl_805BBDD4);
}

extern "C" void fn_800C2978(Unk800C2250_File* f)
{
    f->m0 = lbl_805B6F58;
    f->m404 = 6;
    f->m464 = 12;
}

extern "C" int fn_800C2998(Unk800C2250_File* f, Unk800C1BE4_Widget* w)
{
    for (int i = 0; i < fn_800C2F88(f); i++) {
        if (fn_800C2F90(f, i)) {
            if (w == fn_800C2FC0(f, i))
                return i;
        } else if (w == 0)
            return i;
    }
    return -1;
}

extern "C" void fn_800C2A1C(Unk800C2250_File* f, Unk800C1BE4_Widget* w, float t)
{
    for (int i = 0; i < fn_800C2F88(f); i++) {
        if (fn_800C2F90(f, i) && w == fn_800C2FB0(f, i)) {
            if (fn_800C2F74(f) != 3) {
                f->m404 = 4;
                w->fn_vslot28(fn_800C2F84(f), 0);
                w->fn_vslot8(1);
            }
            return;
        }
    }
    f->m40C[f->m408] = w;
    f->m430[f->m408] = t;
    f->m408 = f->m408 + 1;
    int kind = fn_800C2F74(f);
    if (w != 0 && kind != 3) {
        f->m404 = 4;
        w->fn_vslot28(fn_800C2F84(f), 0);
        w->fn_vslot8(1);
    }
}

extern "C" void fn_800C2B94(Unk800C2250_File* f, int idx)
{
    int i = idx;
    while (i < fn_800C2F88(f)) {
        int next = i + 1;
        if (next <= 8) {
            f->m40C[i] = f->m40C[next];
            f->m430[i] = f->m430[next];
        }
        i = next;
    }
    f->m408 = f->m408 - 1;
    f->m40C[f->m408] = 0;
    f->m430[f->m408] = 1.0f;
    if (fn_800C2F88(f) == 0 && fn_800C2F08(f) == 0 && fn_800C2F1C(f) == 0) {
        fn_800C31FC(f);
        fn_800C2978(f);
    }
}

extern "C" int fn_800C2EF0(Unk800C2250_File* f)
{
    if (f->m404 != 0)
        return 1;
    return 0;
}

extern "C" int fn_800C2F08(Unk800C2250_File* f)
{
    return f->m400 == 8;
}

extern "C" int fn_800C2F1C(Unk800C2250_File* f)
{
    return f->m400 == 2;
}

extern "C" int fn_800C2F30(Unk800C2250_File* f)
{
    return f->m404 == 6;
}

extern "C" int fn_800C2F44(Unk800C2250_File* f)
{
    if (f->m404 != 1)
        return 1;
    return 0;
}

extern "C" int fn_800C2F5C(Unk800C2250_File* f)
{
    if (f->m404 != 1)
        return 1;
    return 0;
}

extern "C" int fn_800C2F74(Unk800C2250_File* f)
{
    return f->m404;
}

extern "C" int fn_800C2F7C(Unk800C2250_File* f)
{
    return f->m400;
}

extern "C" char* fn_800C2F84(Unk800C2250_File* f)
{
    return &f->m0;
}

extern "C" int fn_800C2F88(Unk800C2250_File* f)
{
    return f->m408;
}
