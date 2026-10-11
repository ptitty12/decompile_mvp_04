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
void fn_80123610(Unk80121CCC_Scr* self);
void* fn_80123648(Unk80123648_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80123830(int a, int b, int c, int d, int e, int f);
void fn_80123858(int a, int b, int c);
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

void* fn_80121994(Unk80121994_Scr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m134 = 5;
    self->m130 = 0;
    self->SetVptr(lbl_8064E0E0);
    self->m138 = 5;
    return self;
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

void fn_80122570(Unk80121CCC_Scr* self, char* out)
{
    char* name = (char*)self->m134->fn_vslot70()->fn_vslot33(5, 1) + 0xC;
    int r = fn_8040B574(name, lbl_805C0300);
    if (r == 0) {
        UnkFESub* q = &fn_800B555C()->m8;
        q->m4D0 = self->m148;
        q->m4C4 = self->m140;
        q->m4C8 = self->m144;
        q->m4CC = r;
    } else {
        r = fn_8040B574(name, lbl_805C030C);
        if (r == 0) {
            UnkFESub* q = &fn_800B555C()->m8;
            q->m4D0 = self->m148;
            q->m4C4 = 2;
            q->m4C8 = self->m144;
            q->m4CC = r;
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

void fn_80123830(int a, int b, int c, int d, int e, int f)
{
    fn_80123900(a, b, c, d, e, 0, f);
}

void fn_80123858(int a, int b, int c)
{
    fn_80123900(a, b, c, 1, 2, 1, 0);
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
