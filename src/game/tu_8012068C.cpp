/*
 * Game code, .text 0x8012068C-0x80124738 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk800C7B40_Widget Wid;
typedef Unk80120450_Diff Scr;
/* Small screen (vtable lbl_8064E0E0, ctor fn_80121994). */
struct Unk80121994_Scr : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
};
/* Screen with vtable lbl_80656A30 (ctor fn_80121CCC copies three words of the front-end state). */
struct Unk80121CCC_Scr : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    Wid* m134;
    Wid* m138;
    char pad13C[0x4];
    int m140;
    int m144;
    int m148;
};

/* STATS screen (vtable lbl_8064D8A8, ctor fn_80122A90). */
struct Unk80122A90_Scr : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    int m150;
    int m154;
    int m158;
    int m15C;
};
/* STATS screen (vtable lbl_8064D600, ctor fn_80123648). */
struct Unk80123648_Scr : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
};
extern const char lbl_8064D8A8[];
extern const char lbl_8064D600[];
extern const char lbl_8064CD98[];
extern int lbl_8061A48C;
extern int lbl_80619948;
extern const char lbl_805BFAB4[];
extern const char lbl_805BE1D8[];
extern const char lbl_805BE1E4[];
extern const char lbl_805BFAF8[];
extern const char lbl_805BC1A8[];
extern const char lbl_805BE138[];
extern const char lbl_805BE368[];
extern const char lbl_805C0300[];
extern const char lbl_805C030C[];
extern const char lbl_805C0318[];
extern const char lbl_805C0274[];
extern const char lbl_805C0280[];
extern const char lbl_805C02B0[];
extern const char lbl_805BA040[];
extern const char lbl_805BA054[];
extern const char lbl_805BA058[];
extern const char lbl_805B6F58[];
extern const char lbl_8064E388[];
extern const char lbl_8064E0E0[];
extern const char lbl_80656A30[];

extern "C" unsigned int strlen(const char*);
extern "C" void fn_800ECF18(void*);
extern "C" void fn_80121088(void*, Wid*);
extern "C" void fn_8012141C(void*, Wid*);
struct Unk801219EC_VD {
    char pad0[0x3C];
};
struct Unk801219EC_V : Unk801219EC_VD {
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual void fn_vslot28();
    virtual void fn_vslot29();
    virtual void fn_vslot30();
    virtual void fn_vslot31();
    virtual void fn_vslot32();
    virtual void fn_vslot33();
    virtual void fn_vslot34();
    virtual void fn_vslot35();
    virtual void fn_vslot36();
    virtual void fn_vslot37();
    virtual void fn_vslot38();
    virtual void fn_vslot39();
    virtual void fn_vslot40();
    virtual void fn_vslot41();
    virtual void fn_vslot42();
    virtual void fn_vslot43();
    virtual void fn_vslot44();
    virtual void fn_vslot45();
    virtual void fn_vslot46();
    virtual void fn_vslot47();
    virtual void fn_vslot48();
    virtual void fn_vslot49();
    virtual void fn_vslot50();
    virtual void fn_vslot51();
    virtual void fn_vslot52();
    virtual void fn_vslot53();
    virtual void fn_vslot54();
    virtual void fn_vslot55();
    virtual void fn_vslot56();
    virtual void fn_vslot57();
    virtual void fn_vslot58();
    virtual void fn_vslot59();
    virtual void fn_vslot60();
    virtual void fn_vslot61();
    virtual void fn_vslot62();
    virtual void fn_vslot63();
    virtual void fn_vslot64();
    virtual void fn_vslot65();
    virtual void fn_vslot66();
    virtual void fn_vslot67(int a, int b);
};
extern const char lbl_805BA6D0[];
extern const char lbl_805C02D0[];
extern const char lbl_805C02D8[];
struct Unk801219EC_Obj {
    char padD8[0xD8];
    int mD8;
};
extern "C" Unk801219EC_Obj* fn_800AEC80(int);
extern "C" Wid* fn_8011AB48(int);
extern "C" int fn_80125128(Wid*, int);
extern "C" void fn_80124FA8(Wid*, void*);
extern const char lbl_805BDC04[];
extern const char lbl_805BDBF4[];
extern const char lbl_805BDC1C[];
extern const char lbl_805BDC24[];
extern const char lbl_805C0288[];
extern const char lbl_805C029C[];
extern const char lbl_805BE224[];
extern const char lbl_805B9718[];
extern "C" void fn_800A7404(char*, int, int, int, void*, int*);
extern const char lbl_805BDC84[];
extern const char lbl_805BE3D0[];
extern const char lbl_805BDD84[];
extern const char lbl_805BE644[];
extern const char lbl_805BE654[];
extern const char lbl_805BE678[];
extern const char lbl_805C02BC[];
extern const char lbl_805C0028[];
struct Unk80121088_O {
    int m0;
    char pad4[8];
    int mC;
    int m10;
    char pad14[4];
    int m18;
};
extern "C" int fn_801A4B34();
extern "C" void fn_8011A14C(int a, Wid* w, const char* name, int v);
extern "C" void fn_800C3DCC(int a, Wid* w, int b);
extern "C" Unk80121088_O* fn_800ABF3C(int a, UnkGame* g);
extern "C" int fn_80403DE4(void* buf, int fmt, ...);
extern "C" int fn_80090880(int, int);
extern int lbl_8061977C;
// PROTOS-BEGIN
extern "C" {
void fn_8012068C(Scr* self);
void fn_80120730(Scr* self, Wid* a);
int fn_80120AE8(Scr* self, int a);
int fn_80120B34(Scr* self, int a);
int fn_80120B8C(Scr* self, int a);
int fn_80120BE0(Scr* self, int a);
int fn_80120C38(Scr* self, int a);
void* fn_80120C8C(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
const char* fn_80120E80(int unused, int a);
void fn_80120EE8(Scr* self);
void fn_80120F40(void* unused, Wid* w);
void fn_80120FF4(void* unused, Wid* w);
void* fn_80121994(Unk80121994_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80121B90(Scr* self);
void fn_80121BD0();
void* fn_80121CCC(Unk80121CCC_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_801223A4(Unk80121CCC_Scr* self);
int fn_801223D4(Unk80121CCC_Scr* self);
int fn_801223F8(void* a);
int fn_80122480(Unk80121CCC_Scr* self);
int fn_801224BC(Unk80121CCC_Scr* self);
int fn_801224F8(Unk80121CCC_Scr* self);
int fn_80122534(Unk80121CCC_Scr* self);
void fn_80122570(Unk80121CCC_Scr* self, char* out);
int fn_80122664(Unk80121CCC_Scr* self, Wid* a);
void fn_801226A0(Unk80121CCC_Scr* self);
void fn_801227B8(Unk80121CCC_Scr* self);
void fn_8012289C(int a, Wid* w);
void fn_80122944(Unk80121CCC_Scr* self);
void fn_801229F8(int a, Wid* w);
void* fn_80122A90(Unk80122A90_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80122D40(int a, int b, int c, int d, int e, int f);
void fn_80123610(Unk80121CCC_Scr* self);
void* fn_80123648(Unk80123648_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80123830(int a, int b, int c, int d, int e, int f);
void fn_80123858(int a, int b, int c);
void fn_80123888(void* unused, UnkTextBox* w, int* idx, int v);
void fn_801240C0(Unk80123648_Scr* self);
void* fn_801240F8(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
}
// PROTOS-END
extern "C" {
void fn_800ECE34(Scr* self);
void fn_8012075C(Scr* self);
void fn_800EC648(void* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_802D7ADC();
void fn_8035686C(void* self);
void fn_800ED254(void* self);
void fn_80122D6C(int a, int b, int c, int d, int e, int f, int g);
void fn_8011820C(Wid* w);
void fn_80118B2C(Wid* w);
void fn_80118F8C(Wid* w);
int fn_804089B4(char* buf, const char* fmt, ...);
void fn_800C3AB4(int m, int a);
void fn_8011989C(Wid* w, int a, int b);
int fn_8011AA4C();
void fn_800C3BE0(int a);
int fn_800C33D0();
void fn_800AE964(int a, int b);
int fn_800AB5C8(int a);
extern int lbl_80619D10;
void fn_8035682C(void* name);
void fn_8040B830(void* dst, const char* src, int n);
void fn_800B7B4C(UnkFEMgr* m, const void* name, void* obj);
int fn_8040B574(const char* a, const char* b);
int fn_800B56C4(UnkFEState* s);
int fn_800B5758(UnkFEState* s);
void fn_801227B8(Unk80121CCC_Scr* self);
void fn_80122944(Unk80121CCC_Scr* self);
void fn_801240C0(Unk80123648_Scr* self);
void fn_800A2030(int a, int b);
void fn_80146560();
void fn_80123900(int a, int b, int c, int d, int e, int f, int g);
void fn_80131F34(Wid* w, void* self, void (*cb)(int, Wid*), void (*cb2)(), int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
void fn_801229F8(int a, Wid* w);
void fn_8012289C(int a, Wid* w);
void fn_800B7ADC(UnkFEMgr* m, void* obj);
extern const char lbl_805C02E0[];
extern const char lbl_805B97B4[];
extern const char lbl_805BE628[];
extern const char lbl_805BDDD4[];
extern const char lbl_805C0320[];
extern const char lbl_805BDDB0[];
extern const char lbl_805C0328[];
extern const char lbl_805C0334[];
extern const char lbl_805C0340[];
}

extern "C" {

void fn_8012068C(Scr* self)
{
    fn_800ECE34(self);
    self->m134 = fn_800C8044(self->fn_vslot29(lbl_805BFAB4));
    self->m138 = fn_800C805C(self->m134->fn_vslot29(lbl_805C0274));
    self->m13C = fn_800C8058(self->m138->fn_vslot29(lbl_805C0280));
}

void fn_80120730(Scr* self, Wid* a)
{
    if (a == self->m138)
        fn_8012075C(self);
}

void fn_8012075C(Scr* self)
{
    int i = 0;
    int a = 1;
    char* base = (char*)lbl_806192E0->m4->mC + 0xA0;
    switch (((UnkSub*)((char*)self->m13C + 0xDC))->fn_vslot5()) {
    case 1:
        break;
    case 0:
        a = 0;
        break;
    case 2:
        a = 2;
        break;
    case 3:
        a = 3;
        break;
    }
    int b = 0;
    switch (fn_8011AA4C()) {
    case 5:
        break;
    case 6:
        b = 2;
        if (fn_800AEC80(fn_800AB5C8(lbl_80619D10))->mD8 == 1)
            b = 1;
        break;
    }
    int n = 8;
    do {
        char out[0x18];
        char buf[0x18];
        UnkLabel* l;
        Wid* c;
        int n;
        fn_800A7404(base, b, a, i, out, &n);
        fn_804089B4(buf, lbl_805C0288, i);
        c = fn_800C8044(self->fn_vslot29(buf));
        l = fn_800C8040(c->fn_vslot29(lbl_805BE224));
        if (n == -1)
            l->fn_vslot30(lbl_805B6F58);
        else
            l->fn_vslot28(out);
        fn_804089B4(buf, lbl_805C029C, i);
        c = fn_800C8044(self->fn_vslot29(buf));
        l = fn_800C8040(c->fn_vslot29(lbl_805B9718));
        if (n == -1) {
            l->fn_vslot30(lbl_805B6F58);
        } else {
            fn_804089B4(buf, lbl_805BC1A8, n);
            l->fn_vslot30(buf);
        }
        i++;
    } while (--n != 0);
}

void fn_801209E0(Scr* self, int mode, int x)
{
    if (fn_80120AE8(self, x) != 0) {
        switch (mode) {
        case 0: {
            char name[16];
            char* np = name;
            fn_8035682C(np);
            fn_8040B830(np, lbl_805B97B4, 0xF);
            np[15] = mode;
            if (lbl_8061A32C == 0)
                lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
            fn_800B7B4C(lbl_8061A32C, np, self);
            break;
        }
        case 1: {
            char name[16];
            char* np = name;
            fn_8035682C(np);
            fn_8040B830(np, lbl_805BE628, 0xF);
            np[15] = 0;
            if (lbl_8061A32C == 0)
                lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
            fn_800B7B4C(lbl_8061A32C, np, self);
            break;
        }
        }
    }
}

int fn_80120AE8(Scr* self, int a)
{
    int v = fn_800B555C()->m570;
    if (a == v || v == -1)
        return 1;
    return 0;
}

int fn_80120B34(Scr* self, int a)
{
    if (fn_80120AE8(self, a))
        self->m138->fn_vslot40(1);
    return 1;
}

int fn_80120B8C(Scr* self, int a)
{
    if (fn_80120AE8(self, a))
        self->m138->fn_vslot41();
    return 1;
}

int fn_80120BE0(Scr* self, int a)
{
    if (fn_80120AE8(self, a))
        self->m138->fn_vslot38(1);
    return 1;
}

int fn_80120C38(Scr* self, int a)
{
    if (fn_80120AE8(self, a))
        self->m138->fn_vslot39();
    return 1;
}

void* fn_80120C8C(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8064E388);
    self->m134 = 0;
    return self;
}

extern "C" void fn_80120CDC(Unk80117D20_Scr* self)
{
    fn_800ECF18(self);
    if (fn_800B555C()->m0 == 0x2B)
        self->m134 = 1;
    Wid* w = 0;
    int k = fn_8011AA24(0)->m6F8->m10->m74;
    const char* s = fn_80120E80((int)self, k);
    if (strlen(s) != 0)
        w = fn_800C8044(self->fn_vslot32(s, 1));
    switch (k) {
    case 1:
        fn_80120FF4(self, w);
        break;
    case 0:
        fn_80120F40(self, w);
        break;
    case 5:
        fn_80121088(self, w);
        break;
    case 6:
        fn_8012141C(self, w);
        break;
    }
    if (w != 0)
        w->fn_vslot8(1);
    for (int i = 0; i <= 10; i++) {
        const char* nm = fn_80120E80((int)self, i);
        if (strlen(nm) != 0) {
            Wid* c = self->fn_vslot30(nm, 1);
            if (c != 0 && c != w)
                c->fn_vslot8(0);
        }
    }
}

const char* fn_80120E80(int unused, int a)
{
    switch (a) {
    case 0:
        return lbl_805C02B0;
    case 1:
        return lbl_805BA040;
    case 5:
        return lbl_805BA054;
    case 6:
        return lbl_805BA058;
    default:
        return lbl_805B6F58;
    }
}

void fn_80120EE8(Scr* self)
{
    fn_800ED254(self);
    switch (fn_8011AA24(0)->m6F8->m10->m74) {
    case 1:
    case 5:
    case 6:
        fn_800C3BE0(fn_800C33D0());
        break;
    }
}

void fn_80120F40(void* unused, Wid* w)
{
    if (w != 0) {
        Wid* x = fn_800C8044(fn_800C8044(w->fn_vslot32(lbl_805BE1D8, 1))->fn_vslot32(lbl_805BE1E4, 1));
        fn_8011820C(x);
        fn_80118B2C(x);
        fn_80118F8C(fn_800C8044(w->fn_vslot32(lbl_805BE1D8, 1)));
    }
}

void fn_80120FF4(void* unused, Wid* w)
{
    if (w != 0) {
        fn_800C3AB4(fn_800C33D0(), 2);
        int v = fn_8011AA24(0)->m6F8->m54;
        Wid* x = fn_800C8044(w->fn_vslot32(lbl_805BFAF8, 1));
        fn_8011989C(x, fn_8011AA24(0)->m6F8->m10->m74, v);
    }
}

extern "C" void fn_80121088(void* sv, Wid* b)
{
    Unk80121994_Scr* self = (Unk80121994_Scr*)sv;
    fn_800C3AB4(fn_800C33D0(), 2);
    Wid* c = fn_800C8044(b->fn_vslot32(lbl_805BE224, 1));
    UnkGame* g = fn_8011AA24(0);
    int r29 = fn_801A4B34();
    fn_8011A14C(r29, c, lbl_805BDC84, 0);
    int r30 = fn_800C33D0();
    fn_800C3DCC(r30, fn_800C8038(c->fn_vslot32(lbl_805BE3D0, 1)), r29);
    int idx = 0;
    UnkTeamArr* ta = g->m6F8->m14;
    if (ta->m1CD0 != 0)
        idx = 1;
    UnkPlayerRec* pr = ta->rec + idx;
    int v30 = pr->m198;
    ((UnkSub*)((char*)fn_800C8054(c->fn_vslot32(lbl_805BDD84, 1)) + 0x98))->fn_vslot20(v30, 0);
    int t = lbl_80619D10;
    Unk80121088_O* o = fn_800ABF3C(t, fn_8011AA24(0));
    char buf[0x68];
    int v31;
    if (self->m134 != 1) {
        v31 = o->m10;
        fn_804089B4(buf, lbl_805BC1A8, o->mC);
        fn_800C8040(b->fn_vslot32(lbl_805BE644, 1))->fn_vslot30(buf);
        fn_804089B4(buf, lbl_805BC1A8, o->m0);
        fn_800C8040(b->fn_vslot32(lbl_805BE654, 1))->fn_vslot30(buf);
        fn_804089B4(buf, lbl_805BC1A8, o->m18 + o->mC);
        fn_800C8040(b->fn_vslot32(lbl_805BE678, 1))->fn_vslot30(buf);
    } else {
        v31 = o->m10;
        b->fn_vslot32(lbl_805C02BC, 1)->fn_vslot8(0);
        fn_804089B4(buf, lbl_805BC1A8, o->m18);
        fn_800C8040(b->fn_vslot32(lbl_805BE678, 1))->fn_vslot30(buf);
    }
    short wbuf[100];
    fn_80403DE4(wbuf, fn_80090880(lbl_8061977C, 0x2338), v31);
    fn_800C8040(b->fn_vslot32(lbl_805C0028, 1))->fn_vslot28(wbuf);
}

void* fn_80121994(Unk80121994_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m134 = 5;
    self->m130 = 0;
    self->SetVptr(lbl_8064E0E0);
    self->m138 = 5;
    return self;
}

extern "C" void fn_801219EC(Unk80121994_Scr* self)
{
    fn_800ECF18(self);
    if (fn_8011AA24(0)->m6F8->m10->m120 == 1) {
        ((Unk801219EC_V*)self)->fn_vslot67(0, 0);
        return;
    }
    self->m134 = (int)fn_8011AB48(0);
    self->m138 = (int)fn_8011AB48(1);
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    Wid* w = 0;
    Wid* mg = fn_800B7AB8(lbl_8061A32C, lbl_805BA6D0);
    fn_80124FA8(mg, self);
    fn_80125128(mg, 0);
    switch (fn_8011AA4C()) {
    case 5:
        w = fn_800C8044(self->fn_vslot32(lbl_805BA054, 0));
        break;
    case 6:
        if (fn_800AEC80(fn_800AB5C8(lbl_80619D10))->mD8 == 0)
            w = fn_800C8044(self->fn_vslot32(lbl_805C02D0, 0));
        else
            w = fn_800C8044(self->fn_vslot32(lbl_805C02D8, 0));
        fn_800AE964(fn_800AB5C8(lbl_80619D10), 0);
        break;
    }
    w->fn_vslot8(1);
}

void fn_80121B90(Scr* self)
{
    fn_800ED254(self);
    if (fn_8011AA4C() == 6)
        fn_800AE964(fn_800AB5C8(lbl_80619D10), 1);
}

void fn_80121BD0()
{
    if (lbl_8061B8C0->m24 == 0) {
        lbl_8061B8C0->m24 = 1;
        fn_802D7ADC();
    }
}

void fn_80121C0C(Unk80121CCC_Scr* self, int flag, Wid* x)
{
    if (x == self->m134 || x == self->m138 || fn_8011AA24(0)->m6F8->m10->m120 == 1) {
        if (flag == 0) {
            char name[16];
            char* np = name;
            fn_8035682C(np);
            fn_8040B830(np, lbl_805C02E0, 0xF);
            np[15] = flag;
            if (lbl_8061A32C == 0)
                lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
            fn_800B7B4C(lbl_8061A32C, np, self);
        }
    }
}

void* fn_80121CCC(Unk80121CCC_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80656A30);
    self->m130 = 0;
    self->m138 = 0;
    UnkFESub* q = &fn_800B555C()->m8;
    self->m140 = q->m4D4;
    self->m144 = q->m4D8;
    self->m148 = q->m4DC;
    return self;
}

void fn_801223A4(Unk80121CCC_Scr* self)
{
    self->SetVptr(lbl_80656A30);
    fn_8035686C(self);
}

int fn_801223D4(Unk80121CCC_Scr* self)
{
    fn_801226A0(self);
    return 1;
}

int fn_801223F8(void* a)
{
    char name[16];
    char* np = name;
    fn_8035682C(np);
    fn_8040B830(np, lbl_805BE138, 0xF);
    np[15] = 0;
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_800B7B4C(lbl_8061A32C, np, a);
    return 1;
}

int fn_80122480(Unk80121CCC_Scr* self)
{
    self->m134->fn_vslot50();
    return 1;
}

int fn_801224BC(Unk80121CCC_Scr* self)
{
    self->m134->fn_vslot51();
    return 1;
}

int fn_801224F8(Unk80121CCC_Scr* self)
{
    self->m134->fn_vslot52();
    return 1;
}

int fn_80122534(Unk80121CCC_Scr* self)
{
    self->m134->fn_vslot53();
    return 1;
}

/* near-miss: 1 slot (retail compares the first strcmp as `mr. r29,r3`, ours `cmpwi r3,0`; store orders solved by permutation). */
void fn_80122570(Unk80121CCC_Scr* self, char* out)
{
    char* name = (char*)self->m134->fn_vslot70()->fn_vslot33(5, 1) + 0xC;
    int r = fn_8040B574(name, lbl_805C0300);
    if (r == 0) {
        UnkFESub* q = &fn_800B555C()->m8;
        int b = self->m140;
        int c = self->m144;
        int a = self->m148;
        q->m4C4 = b;
        q->m4C8 = c;
        q->m4D0 = a;
    } else {
        r = fn_8040B574(name, lbl_805C030C);
        if (r == 0) {
            UnkFESub* q = &fn_800B555C()->m8;
            int c = self->m144;
            int a = self->m148;
            q->m4C4 = 2;
            q->m4C8 = c;
            q->m4CC = r;
            q->m4D0 = a;
        }
    }
    fn_8040B830(out, name, 0x10);
}

int fn_80122664(Unk80121CCC_Scr* self, Wid* a)
{
    if (a != self->m134)
        return 0;
    fn_801226A0(self);
    return 1;
}

void fn_801226A0(Unk80121CCC_Scr* self)
{
    if (fn_8040B574((char*)self->m134->fn_vslot70()->fn_vslot33(5, 1) + 0xC, lbl_805BE368) == 0) {
        fn_801227B8(self);
        return;
    }
    if (fn_8040B574((char*)self->m134->fn_vslot70()->fn_vslot33(5, 1) + 0xC, lbl_805C0318) == 0) {
        fn_80122944(self);
        return;
    }
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    fn_800B7ADC(lbl_8061A32C, self);
}

void fn_801227B8(Unk80121CCC_Scr* self)
{
    int v = 0x1D;
    self->m138->fn_vslot84(1);
    if (fn_800B56C4(fn_800B555C()) != 0) {
        v = 0x4FBA;
    } else {
        if (fn_800B5758(fn_800B555C()) != 0)
            v = 0x5740;
    }
    fn_80131F34(self->m138, self, fn_8012289C, fn_80146560, v, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    self->m138->fn_vslot86();
}

void fn_8012289C(int a, Wid* w)
{
    if (lbl_8061A48C != 0)
        a = 1;
    if (a != 0) {
        if (a == 1) {
            fn_800A2030(lbl_80619948, 1);
            w->fn_vslot80(1);
            if (lbl_8061A32C == 0)
                lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
            fn_800B7ADC(lbl_8061A32C, w);
        }
    }
}

void fn_80122944(Unk80121CCC_Scr* self)
{
    self->m138->fn_vslot84(1);
    fn_80131F34(self->m138, self, fn_801229F8, fn_80146560, 0x5C94, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    self->m138->fn_vslot86();
}

void fn_801229F8(int a, Wid* w)
{
    if (lbl_8061A48C != 0)
        a = 1;
    if (a != 0) {
        if (a == 1) {
            w->fn_vslot80(1);
            if (lbl_8061A32C == 0)
                lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
            fn_800B7ADC(lbl_8061A32C, w);
        }
    }
}

void* fn_80122A90(Unk80122A90_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8064D8A8);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    return self;
}

void fn_80122B08(Unk80122A90_Scr* self)
{
    fn_800ECE34((Scr*)self);
    self->m158 = (int)fn_800C8044(self->fn_vslot32(lbl_805C0320, 1));
    self->m15C = (int)fn_800C8044(self->fn_vslot32(lbl_805BDDB0, 1));
    self->m134 = (int)fn_800C8040(self->fn_vslot29(lbl_805C0328));
    self->m138 = (int)fn_800C8038(self->fn_vslot29(lbl_805C0334));
    self->m13C = (int)fn_800C8054(self->fn_vslot29(lbl_805C0340));
    self->m140 = (int)fn_800C8060(((Wid*)self->m15C)->fn_vslot32(lbl_805BDC04, 1));
    self->m144 = (int)fn_800C8060(((Wid*)self->m15C)->fn_vslot32(lbl_805BDDD4, 1));
    self->m148 = (int)fn_800C8060(((Wid*)self->m158)->fn_vslot32(lbl_805BDBF4, 1));
    self->m14C = (int)fn_800C8060(((Wid*)self->m158)->fn_vslot32(lbl_805BDDD4, 1));
    self->m150 = (int)fn_800C8044(((Wid*)self->m148)->fn_vslot32(lbl_805BDC1C, 1));
    self->m154 = (int)fn_800C8044(((Wid*)self->m148)->fn_vslot32(lbl_805BDC24, 1));
    ((Wid*)self->m138)->fn_vslot8(0);
}

void fn_80122D40(int a, int b, int c, int d, int e, int f)
{
    fn_80122D6C(a, b, c, d, 0, e, f);
}

void fn_80123610(Unk80121CCC_Scr* self)
{
    self->fn_vslot8(0);
}

void* fn_80123648(Unk80123648_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_8064D600);
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    fn_801240C0(self);
    return self;
}

void fn_801236B8(Unk80123648_Scr* self)
{
    fn_800ECE34((Scr*)self);
    self->m144 = (int)fn_800C8044(self->fn_vslot32(lbl_805C0320, 1));
    self->m148 = (int)fn_800C8044(self->fn_vslot32(lbl_805BDDB0, 1));
    self->m134 = (int)fn_800C8040(self->fn_vslot29(lbl_805C0328));
    self->m138 = (int)fn_800C8038(self->fn_vslot29(lbl_805C0334));
    self->m13C = (int)fn_800C8060(((Wid*)self->m148)->fn_vslot32(lbl_805BDDD4, 1));
    self->m140 = (int)fn_800C8060(((Wid*)self->m144)->fn_vslot32(lbl_805BDDD4, 1));
    self->m14C = (int)fn_800C8054(self->fn_vslot29(lbl_805C0340));
    ((Wid*)self->m138)->fn_vslot8(0);
}

void fn_80123830(int a, int b, int c, int d, int e, int f)
{
    fn_80123900(a, b, c, d, e, 0, f);
}

void fn_80123858(int a, int b, int c)
{
    fn_80123900(a, b, c, 1, 2, 1, 0);
}

void fn_80123888(void* unused, UnkTextBox* w, int* idx, int v)
{
    char buf[0x68];
    fn_804089B4(buf, lbl_805BC1A8, v);
    w->fn_vslot44(*idx, 0, buf, 4);
    *idx = *idx + 1;
}

void fn_801240C0(Unk80123648_Scr* self)
{
    self->fn_vslot8(0);
}

void* fn_801240F8(Unk80117D20_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m130 = 0;
    self->SetVptr(lbl_8064CD98);
    self->m134 = 0;
    return self;
}

}
