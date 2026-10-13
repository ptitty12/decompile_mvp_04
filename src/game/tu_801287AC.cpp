/*
 * Game code, .text 0x801287AC-0x8012C8CC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk800C7B40_Widget Wid;

/* Button widget as seen through fn_8012B960 (its id is at +0x138). */
struct Unk8012B960_Btn : Unk800C7B40_Widget {
    char pad40[0xF8];
    int m138;
};
/* Screen with two button widgets at +0x188 / +0x18C (fn_8012B960, fn_8012BBF4 ...). */
struct Unk8012B960_Scr : Unk800C7B40_Widget {
    char pad40[0xF4];
    int m134;
    int m138;
    int m13C;
    char pad140[8];
    int m148;
    int m14C;
    char pad150[0x14];
    int m164;
    int m168;
    int m16C;
    int m170;
    char pad174[0x10];
    int m184;
    Unk8012B960_Btn* m188;
    Unk8012B960_Btn* m18C;
};
typedef Unk8012B960_Scr Scr;

extern const float lbl_805C068C;
extern const float lbl_805C0690;
extern const float lbl_805C0694;
extern const float lbl_805C06A0;
extern const int lbl_805C06A4[];
extern const char lbl_805C0424[];
extern const char lbl_805C0438[];
extern const char lbl_805C088C[];
extern const char lbl_805C0890[];
extern const char lbl_805BC19C[];
extern const char lbl_805BC1A0[];

extern "C" float fn_8007ABFC(int, int, int);
extern "C" int fn_800E01C8(float);
extern const char lbl_805B7FF0[];
extern const char lbl_805C0828[];
extern "C" int fn_80127550();
extern "C" int fn_800DBE54(int, int, int, int, int);
extern "C" int fn_800DBAE0(int, int, int, int);
extern "C" int fn_800E0208(int, unsigned int);
extern "C" int fn_804089B4(char*, const char*, ...);
extern const char lbl_805BC1A8[];
extern const char lbl_805BDE0C[];
extern const char lbl_805C087C[];
extern "C" int fn_800DC01C(int, int, int, int);
extern "C" float fn_800DC088(int, int, int, int);
extern "C" void fn_80119F48(char*, float);
extern const char lbl_805C0830[];
extern const char lbl_805BDC1C[];
extern const char lbl_805C0840[];
extern const char lbl_805C0848[];
extern const char lbl_805BA6A4[];
extern const char lbl_805C084C[];
extern const char lbl_805BDEE0[];
extern const char lbl_805BDEDC[];
extern "C" void fn_8012B2A0(int a, int c, Wid* b, Wid* w, int f);
extern const char lbl_805C0864[];
extern const char lbl_805C0874[];
extern const char lbl_805C07F4[];
extern const char lbl_805C0250[];
extern "C" int fn_800DBF44(int, int, int, int);
extern "C" float fn_800DBFB0(int, int, int, int);
extern "C" void fn_80119FF0(char*, float);
extern const char lbl_805C062C[];
extern "C" int fn_800DB8B8(int, int, int, int, int, int);
extern "C" float fn_800DB930(int, int, int, int, int, int);
extern "C" int fn_800DBCC8(int, int, int, int, int, int, int);
extern const char lbl_805C0814[];
extern const char lbl_805C0820[];
extern "C" int fn_800DB840(int, int, int, int, int, int);
extern "C" int fn_800DBD4C(int, int, int, int, int, int, int);
extern "C" float fn_800DBDD0(int, int, int, int, int, int, int);
extern const char lbl_805BDBD0[];
extern const char lbl_805BDBD4[];
extern const char lbl_805BDBD8[];
extern const char lbl_805BDBDC[];
extern const char lbl_805BDBE0[];
extern const char lbl_805BDBE4[];
extern const char lbl_805BDBE8[];
extern const char lbl_805BDBEC[];
extern const char lbl_805BDBF0[];
extern int lbl_8061930C;
extern int lbl_8061977C;
extern const char lbl_805C064C[];
extern const char lbl_805C0658[];
extern const char lbl_805C0660[];
extern const char lbl_805C066C[];
extern const char lbl_805C0678[];
extern const char lbl_805C0680[];
extern const char lbl_805C02E8[];
extern const int lbl_805C3D34[];
extern const int lbl_805C3D44[];
extern const int lbl_805C3D58[];
extern "C" int fn_8007A270(int, int);
extern "C" void fn_8012E514(int, short*);
extern "C" void fn_800DFE40(short*, int);
extern "C" void fn_804031BC(short*, const char*);
extern "C" void fn_80403DE4(short*, short*, ...);
extern "C" int fn_80090880(int, int);
// PROTOS-BEGIN
extern "C" {
void fn_801287AC(int a, int b, int c, int d);
int fn_801295DC(int a, int b, int c);
int fn_8012964C(int a, int c, float v);
int fn_801296DC(int a, int b, int c);
void fn_8012981C(int a, int b, int* out);
void fn_8012A490(int a, int b, int c, int d);
Wid* fn_8012B960(Scr* self, int id, int* out);
int fn_8012BBF4(Scr* self, int id);
}
// PROTOS-END
extern "C" {
void fn_80128850(int a, int b, int c, int d);
void fn_80128BD8(int a, int b, int c);
void fn_801292A4(int a, int b, int c);
void fn_8012A0E8(int a, int b, int c);
void fn_80129A44(int a, int b);
void fn_8012A554(int a, int b, int c, int d);
void fn_8012A8D0(int a, int b, int c);
void fn_8012AB7C(int a, int b, int c);
void fn_8012AF28(int a, int b, int c);
void fn_8012B678(int a, int b, int c);
int fn_8007AB9C(int a, int b, int c);
int fn_8012E3F4(Scr* self);
void fn_8012D0D0(Scr* self);
int fn_80126CF4(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
Wid* fn_8012B960(Scr* self, int id, int* out);
int fn_8007AA84(int a, int b, int c, int d);
int fn_8007A6A0(int a, int b, int c);
}

extern "C" {

void fn_801287AC(int a, int b, int c, int d)
{
    fn_80128850(a, b, c, d);
    fn_80128BD8(a, b, c);
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    if (lbl_8061A32C->mB8 == 0) {
        fn_801292A4(a, b, c);
        fn_8012A0E8(a, b, c);
        fn_80129A44(b, c);
    }
}

void fn_80128850(int a, int b, int c, int d)
{
    int slot = 0;
    int k = 5;
    int p = *(int*)(a + 0x178);
    if (p != 0) {
        slot = *(int*)(p + 0x14);
        k = fn_80127550();
    }
    UnkTextBox* t = fn_800C8060(fn_800C8044(((Wid*)b)->fn_vslot32(lbl_805C062C, 1))->fn_vslot32(lbl_805BDE0C, 1));
    char buf[0x68];
    int v1 = fn_800DB8B8(slot, 1, k, c, 1, d);
    float f1 = (float)v1 + (float)fn_800DB8B8(slot, 2, k, c, 1, d) * 0.1f;
    fn_804089B4(buf, lbl_805C0250, f1);
    t->fn_vslot44(0, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800DB8B8(slot, 3, k, c, 1, d));
    t->fn_vslot44(1, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800DB8B8(slot, 4, k, c, 1, d));
    t->fn_vslot44(2, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800DB8B8(slot, 7, k, c, 1, d));
    t->fn_vslot44(3, 1, buf, 4);
    float f2 = fn_800DB930(slot, 1, k, c, 1, d);
    fn_80119FF0(buf, f2);
    t->fn_vslot44(4, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800DBCC8(slot, 2, k, c, 2, 1, d));
    t->fn_vslot44(5, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800DBCC8(slot, 0, k, c, 2, 1, d));
    t->fn_vslot44(6, 1, buf, 4);
}

void fn_801292A4(int a, int b, int c)
{
    int g = lbl_8061930C;
    Wid* w = fn_800C8044(((Wid*)b)->fn_vslot32(lbl_805C064C, 1));
    short wfmt[100];
    short sD0[52];
    short s138[100];
    short s200[1000];
    int r29 = fn_8007A6A0(g, 0x19, c);
    int r30;
    if (r29 == 1) {
        r30 = fn_80090880(lbl_8061977C, 0x1C5F);
    } else {
        r30 = fn_80090880(lbl_8061977C, 0x1C5E);
    }
    fn_804031BC(wfmt, lbl_805C0658);
    fn_80403DE4(s138, wfmt, r29, r30);
    fn_800C8040(w->fn_vslot32(lbl_805C0660, 1))->fn_vslot28(s138);
    fn_800DFE40(sD0, c);
    fn_804031BC(wfmt, lbl_805C066C);
    fn_80403DE4(s138, wfmt, sD0, fn_80090880(lbl_8061977C, 0x2351), fn_80090880(lbl_8061977C, 0x2352));
    fn_800C8040(w->fn_vslot32(lbl_805C064C, 1))->fn_vslot28(s138);
    int k = fn_8007A6A0(g, 0x32, c);
    int t1;
    int t2;
    if (fn_8007A270(g, c) != 0) {
        t2 = lbl_805C3D44[k % 5];
        t1 = lbl_805C3D58[k / 5];
    } else {
        t2 = lbl_805C3D34[k % 4];
        t1 = lbl_805C3D58[k / 4];
    }
    fn_804031BC(wfmt, lbl_805C02E8);
    fn_80403DE4(s138, wfmt, fn_80090880(lbl_8061977C, t1), fn_80090880(lbl_8061977C, t2));
    fn_800C8040(w->fn_vslot32(lbl_805C0678, 1))->fn_vslot28(s138);
    Wid* x = w->fn_vslot30(lbl_805C0680, 1);
    if (x != 0) {
        fn_8012E514(c, s200);
        fn_800C8040(x)->fn_vslot28(s200);
    }
}

int fn_801295DC(int a, int b, int c)
{
    int r = 0;
    if (b > 0x14) {
        if (b <= 0x28) {
            r = 3;
        } else if (b <= 0x3C) {
            r = 6;
        } else if (b <= 0x50) {
            r = 9;
        } else {
            r = 0xC;
        }
    }
    if (a <= 0x16)
        return c + 0xF;
    if (a > 0x1D) {
        if (a <= 0x22)
            return r + 1;
        return r + 2;
    }
    return r;
}

int fn_8012964C(int a, int c, float v)
{
    int r = 0;
    if (!(v < lbl_805C068C)) {
        if (!(v >= lbl_805C0690))
            r = 3;
        else if (!(v >= lbl_805C0694))
            r = 6;
        else
            r = 9;
    }
    if (a <= 0x16)
        return c + 0xC;
    if (a > 0x1D) {
        if (a <= 0x22)
            return r + 1;
        return r + 2;
    }
    return r;
}

int fn_801296DC(int a, int b, int c)
{
    int r = 0;
    switch (b) {
    case 0: {
        int t = fn_8007AA84(a, b, c, 0) + fn_8007AA84(a, b, c, 1);
        r = t / 2;
        break;
    }
    case 1: {
        int t = fn_8007AA84(a, b, c, 0) + fn_8007AA84(a, b, c, 1);
        r = t / 2;
        break;
    }
    case 2:
        r = fn_8007A6A0(a, 0xD, c);
        break;
    case 3:
        r = (int)((float)fn_8007A6A0(a, 0x10, c) * lbl_805C06A0);
        break;
    case 4:
        r = (int)((float)fn_8007A6A0(a, 0xE, c) * lbl_805C06A0);
        break;
    }
    return r;
}

void fn_8012981C(int a, int b, int* out)
{
    for (int i = 0; i < 4; i++) {
        const char* t = (const char*)lbl_805C06A4;
        int off = fn_8007AB9C(a, 6 + i * 5, b) * 4;
        out[i] = *(const int*)(t + off);
    }
}

int fn_8012988C(int a, int id, int c)
{
    int k = 0;
    switch (id) {
    case 0:
        break;
    case 0x2C7C:
        k = 1;
        break;
    case 0x2C90:
        k = 2;
        break;
    case 0x2CA4:
        k = 3;
        break;
    case 0x2CB8:
        k = 4;
        break;
    case 0x2CCC:
        k = 5;
        break;
    case 0x2CE0:
        k = 6;
        break;
    case 0x2CF4:
        k = 7;
        break;
    case 0x2D08:
        k = 8;
        break;
    case 0x2D1C:
        k = 9;
        break;
    case 0x2D30:
        k = 10;
        break;
    case 0x2D44:
        k = 11;
        break;
    case 0x2D58:
        k = 12;
        break;
    case 0x2D6C:
        k = 13;
        break;
    case 0x2D80:
        k = 14;
        break;
    }
    int r = 0;
    if (k == 0) {
        r = fn_800E01C8(fn_8007ABFC(a, 0, c));
    } else {
        for (int i = 0; i <= 3; i++) {
            if (fn_8007AB9C(a, 6 + i * 5, c) == k)
                r = fn_800E01C8(fn_8007ABFC(a, i + 1, c));
        }
    }
    return r;
}

void fn_8012A0E8(int a, int b, int c)
{
    int slot = 0;
    int k = 5;
    int p = *(int*)(a + 0x178);
    if (p != 0) {
        slot = *(int*)(p + 0x14);
        k = fn_80127550();
    }
    UnkTextBox* t = fn_800C8060(fn_800C8044(((Wid*)b)->fn_vslot32(lbl_805C07F4, 1))->fn_vslot32(lbl_805BDE0C, 1));
    char buf[0x68];
    int v0 = fn_800DBF44(slot, 0, k, c);
    int v7 = fn_800DBF44(slot, 7, k, c);
    int v8 = fn_800DBF44(slot, 8, k, c);
    int v3 = fn_800DBF44(slot, 3, k, c);
    int v2 = fn_800DBF44(slot, 2, k, c);
    int v4 = fn_800DBF44(slot, 4, k, c);
    int v6 = fn_800DBF44(slot, 6, k, c);
    int v5 = fn_800DBF44(slot, 5, k, c);
    float f0 = fn_800DBFB0(slot, 0, k, c);
    fn_804089B4(buf, lbl_805BC1A8, v0);
    t->fn_vslot44(0, 1, buf, 4);
    float f1 = (float)v7 + (float)v8 * 0.1f;
    fn_804089B4(buf, lbl_805C0250, f1);
    t->fn_vslot44(1, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, v3);
    t->fn_vslot44(2, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, v2);
    t->fn_vslot44(3, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, v4);
    t->fn_vslot44(4, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, v6);
    t->fn_vslot44(5, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, v5);
    t->fn_vslot44(6, 1, buf, 4);
    fn_80119FF0(buf, f0);
    t->fn_vslot44(7, 1, buf, 4);
}

void fn_8012A490(int a, int b, int c, int d)
{
    fn_8012A554(a, b, c, d);
    fn_8012A8D0(a, b, c);
    fn_8012AB7C(a, b, c);
    fn_8012AF28(a, b, c);
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    if (lbl_8061A32C->mB8 == 0) {
        fn_801292A4(a, b, c);
        fn_8012B678(a, b, c);
        fn_80129A44(b, c);
    }
}

void fn_8012A554(int a, int b, int c, int d)
{
    int slot = 0;
    int k = 5;
    int p = *(int*)(a + 0x178);
    if (p != 0) {
        slot = *(int*)(p + 0x14);
        k = fn_80127550();
    }
    UnkTextBox* t = fn_800C8060(fn_800C8044(((Wid*)b)->fn_vslot32(lbl_805C0814, 1))->fn_vslot32(lbl_805C0820, 1));
    char buf[0x68];
    float f0 = fn_800DBDD0(slot, 2, k, c, 2, 1, d);
    fn_80119F48(buf, f0);
    t->fn_vslot44(0, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800DBD4C(slot, 0, k, c, 2, 1, d));
    t->fn_vslot44(1, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800DBD4C(slot, 1, k, c, 2, 1, d));
    t->fn_vslot44(2, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800DB840(slot, 3, k, c, 1, d));
    t->fn_vslot44(3, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800DB840(slot, 1, k, c, 1, d));
    t->fn_vslot44(4, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, (int)fn_800DBDD0(slot, 0, k, c, 2, 1, d));
    t->fn_vslot44(5, 1, buf, 4);
    float f3 = fn_800DBDD0(slot, 3, k, c, 2, 1, d);
    fn_80119F48(buf, f3);
    t->fn_vslot44(6, 1, buf, 4);
    float f5 = fn_800DBDD0(slot, 5, k, c, 2, 1, d);
    fn_80119F48(buf, f5);
    t->fn_vslot44(7, 1, buf, 4);
}

void fn_8012A8D0(int a, int b, int c)
{
    int slot = 0;
    int k = 5;
    int p = *(int*)(a + 0x178);
    if (p != 0) {
        slot = *(int*)(p + 0x14);
        k = fn_80127550();
    }
    UnkTextBox* t = fn_800C8060(fn_800C8044(((Wid*)b)->fn_vslot32(lbl_805B7FF0, 1))->fn_vslot32(lbl_805C0828, 1));
    char buf[0x68];
    fn_804089B4(buf, lbl_805BC1A8, fn_800DBE54(slot, 1, k, c, 0));
    t->fn_vslot44(0, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800DBE54(slot, 0, k, c, 0));
    t->fn_vslot44(1, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800DBE54(slot, 1, k, c, 1));
    t->fn_vslot44(2, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800DBE54(slot, 0, k, c, 1));
    t->fn_vslot44(3, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800E0208(0xC, fn_800DBAE0(slot, 0xC, k, c)));
    t->fn_vslot44(4, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800E0208(0x13, fn_800DBAE0(slot, 0x13, k, c)));
    t->fn_vslot44(5, 1, buf, 4);
}

void fn_8012AB7C(int a, int b, int c)
{
    int slot = 0;
    int k = 5;
    int p = *(int*)(a + 0x178);
    if (p != 0) {
        slot = *(int*)(p + 0x14);
        k = fn_80127550();
    }
    Wid* w = fn_800C8044(((Wid*)b)->fn_vslot32(lbl_805C0830, 1));
    fn_8012B2A0(a, c, (Wid*)b, fn_800C8044(w->fn_vslot32(lbl_805BDC1C, 1)), 0);
    fn_8012B2A0(a, c, (Wid*)b, fn_800C8044(w->fn_vslot32(lbl_805C0840, 1)), 1);
    char buf[0x68];
    int v = fn_800DBE54(slot, 0x14, k, c, 0);
    int t0 = (int)((float)(v + fn_800DBE54(slot, 0x14, k, c, 1)) * 0.5f);
    fn_804089B4(buf, lbl_805C0848, t0);
    fn_800C8040(fn_800C8044(w->fn_vslot32(lbl_805BA6A4, 1))->fn_vslot32(lbl_805C084C, 1))->fn_vslot30(buf);
    v = fn_800DBE54(slot, 0x16, k, c, 0);
    int t1 = (int)((float)(v + fn_800DBE54(slot, 0x16, k, c, 1)) * 0.5f);
    fn_804089B4(buf, lbl_805C0848, t1);
    fn_800C8040(fn_800C8044(w->fn_vslot32(lbl_805BDEE0, 1))->fn_vslot32(lbl_805C084C, 1))->fn_vslot30(buf);
    v = fn_800DBE54(slot, 0x15, k, c, 0);
    int s = v + fn_800DBE54(slot, 0x15, k, c, 1);
    int r = 0;
    if (s != 0)
        r = 100 - t0 - t1;
    fn_804089B4(buf, lbl_805C0848, r);
    fn_800C8040(fn_800C8044(w->fn_vslot32(lbl_805BDEDC, 1))->fn_vslot32(lbl_805C084C, 1))->fn_vslot30(buf);
}

void fn_8012AF28(int a, int b, int c)
{
    int slot = 0;
    int k = 5;
    int p = *(int*)(a + 0x178);
    if (p != 0) {
        slot = *(int*)(p + 0x14);
        k = fn_80127550();
    }
    UnkTextBox* t = fn_800C8060(fn_800C8044(((Wid*)b)->fn_vslot32(lbl_805C0864, 1))->fn_vslot32(lbl_805C0874, 1));
    char buf[0x68];
    fn_804089B4(buf, lbl_805BC1A8, fn_800E0208(0x12, fn_800DBAE0(slot, 0x12, k, c)));
    t->fn_vslot44(0, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800DBAE0(slot, 0xD, k, c));
    t->fn_vslot44(1, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800E0208(0x14, fn_800DBAE0(slot, 0x14, k, c)));
    t->fn_vslot44(2, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800E0208(0x15, fn_800DBAE0(slot, 0x15, k, c)));
    t->fn_vslot44(3, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800E0208(0x10, fn_800DBAE0(slot, 0x10, k, c)));
    t->fn_vslot44(4, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800E0208(0x11, fn_800DBAE0(slot, 0x11, k, c)));
    t->fn_vslot44(5, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800E0208(0xE, fn_800DBAE0(slot, 0xE, k, c)));
    t->fn_vslot44(6, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, fn_800E0208(0xF, fn_800DBAE0(slot, 0xF, k, c)));
    t->fn_vslot44(7, 1, buf, 4);
}

void fn_8012B2A0(int a, int c, Wid* b, Wid* w, int f)
{
    int v;
    int slot = 0;
    int k = 5;
    int p = *(int*)(a + 0x178);
    if (p != 0) {
        slot = *(int*)(p + 0x14);
        k = ((int (*)(int, Wid*))fn_80127550)(a, b);
    }
    v = fn_800DBE54(slot, 2, k, c, f);
    ((UnkSub*)((char*)fn_800C8054(w->fn_vslot32(lbl_805BDBD0, 1)) + 0x98))->fn_vslot6(v);
    v = fn_800DBE54(slot, 3, k, c, f);
    ((UnkSub*)((char*)fn_800C8054(w->fn_vslot32(lbl_805BDBD4, 1)) + 0x98))->fn_vslot6(v);
    v = fn_800DBE54(slot, 4, k, c, f);
    ((UnkSub*)((char*)fn_800C8054(w->fn_vslot32(lbl_805BDBD8, 1)) + 0x98))->fn_vslot6(v);
    v = fn_800DBE54(slot, 5, k, c, f);
    ((UnkSub*)((char*)fn_800C8054(w->fn_vslot32(lbl_805BDBDC, 1)) + 0x98))->fn_vslot6(v);
    v = fn_800DBE54(slot, 6, k, c, f);
    ((UnkSub*)((char*)fn_800C8054(w->fn_vslot32(lbl_805BDBE0, 1)) + 0x98))->fn_vslot6(v);
    v = fn_800DBE54(slot, 7, k, c, f);
    ((UnkSub*)((char*)fn_800C8054(w->fn_vslot32(lbl_805BDBE4, 1)) + 0x98))->fn_vslot6(v);
    v = fn_800DBE54(slot, 8, k, c, f);
    ((UnkSub*)((char*)fn_800C8054(w->fn_vslot32(lbl_805BDBE8, 1)) + 0x98))->fn_vslot6(v);
    v = fn_800DBE54(slot, 9, k, c, f);
    ((UnkSub*)((char*)fn_800C8054(w->fn_vslot32(lbl_805BDBEC, 1)) + 0x98))->fn_vslot6(v);
    v = fn_800DBE54(slot, 10, k, c, f);
    ((UnkSub*)((char*)fn_800C8054(w->fn_vslot32(lbl_805BDBF0, 1)) + 0x98))->fn_vslot6(v);
}

void fn_8012B678(int a, int b, int c)
{
    int slot = 0;
    int k = 5;
    int p = *(int*)(a + 0x178);
    if (p != 0) {
        slot = *(int*)(p + 0x14);
        k = fn_80127550();
    }
    UnkTextBox* t = fn_800C8060(fn_800C8044(((Wid*)b)->fn_vslot32(lbl_805C087C, 1))->fn_vslot32(lbl_805BDE0C, 1));
    char buf[0x68];
    int v0 = fn_800DC01C(slot, 0, k, c);
    int v1 = fn_800DC01C(slot, 2, k, c);
    float f = fn_800DC088(slot, 0, k, c);
    int v3 = fn_800DC01C(slot, 3, k, c);
    int v4 = fn_800DC01C(slot, 4, k, c);
    int v5 = fn_800DC01C(slot, 5, k, c);
    int v6 = fn_800DC01C(slot, 6, k, c);
    fn_804089B4(buf, lbl_805BC1A8, v0);
    t->fn_vslot44(0, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, v1);
    t->fn_vslot44(1, 1, buf, 4);
    fn_80119F48(buf, f);
    t->fn_vslot44(2, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, v3);
    t->fn_vslot44(3, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, v4);
    t->fn_vslot44(4, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, v5);
    t->fn_vslot44(5, 1, buf, 4);
    fn_804089B4(buf, lbl_805BC1A8, v6);
    t->fn_vslot44(6, 1, buf, 4);
}

Wid* fn_8012B960(Scr* self, int id, int* out)
{
    if (self->m188->m138 == id) {
        *out = 0;
        return fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
    } else if (self->m18C->m138 == id) {
        *out = 1;
        return fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
    }
    return 0;
}

int fn_8012B9EC(Scr* self, int id)
{
    int out;
    int c;
    if (self->m188 != 0 || self->m18C != 0)
        c = 1;
    else
        c = 0;
    if (c != 0) {
        Wid* w = fn_8012B960(self, id, &out);
        if (w != 0) {
            fn_800C8034(w->fn_vslot32(lbl_805C088C, 1))->fn_vslot15(1);
            if (out == 0) {
                if (self->m164 != 0) {
                    int a = self->m188->fn_vslot95();
                    int b = self->m168;
                    fn_80126CF4(self, a, b, self->m134, self->m16C, self->m170, 0, self->m138, self->m13C, self->m148, self->m14C);
                    return 1;
                }
            } else if (self->m168 != 0) {
                int b = self->m18C->fn_vslot95();
                int a = self->m164;
                fn_80126CF4(self, a, b, self->m134, self->m16C, self->m170, 0, self->m138, self->m13C, self->m148, self->m14C);
                return 1;
            }
        }

    } else if (self->m138 != 0 && fn_8012E3F4(self) != 0) {
        Wid* w;
        if (self->m184 == 0)
            w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
        else
            w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
        fn_800C8034(w->fn_vslot32(lbl_805C088C, 1))->fn_vslot15(1);
    }
    return 0;
}

int fn_8012BBF4(Scr* self, int id)
{
    int out;
    int c;
    if (self->m188 != 0 || self->m18C != 0)
        c = 1;
    else
        c = 0;
    if (c != 0) {
        Wid* w = fn_8012B960(self, id, &out);
        if (w != 0)
            fn_800C8034(w->fn_vslot32(lbl_805C088C, 1))->fn_vslot15(0);
        return 1;
    }
    if (fn_8012E3F4(self) != 0) {
        Wid* w;
        if (self->m184 == 0)
            w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
        else
            w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
        fn_800C8034(w->fn_vslot32(lbl_805C088C, 1))->fn_vslot15(0);
    }
    return 0;
}

int fn_8012BD48(Scr* self, int id)
{
    int out;
    int c;
    if (self->m188 != 0 || self->m18C != 0)
        c = 1;
    else
        c = 0;
    if (c != 0) {
        Wid* w = fn_8012B960(self, id, &out);
        if (w != 0) {
            fn_800C8034(w->fn_vslot32(lbl_805C0890, 1))->fn_vslot15(1);
            if (out == 0) {
                if (self->m164 != 0) {
                    int a = self->m188->fn_vslot94();
                    int b = self->m168;
                    fn_80126CF4(self, a, b, self->m134, self->m16C, self->m170, 0, self->m138, self->m13C, self->m148, self->m14C);
                    return 1;
                }
            } else if (self->m168 != 0) {
                int b = self->m18C->fn_vslot94();
                int a = self->m164;
                fn_80126CF4(self, a, b, self->m134, self->m16C, self->m170, 0, self->m138, self->m13C, self->m148, self->m14C);
                return 1;
            }
        }

    } else if (self->m138 != 0 && fn_8012E3F4(self) != 0) {
        Wid* w;
        if (self->m184 == 0)
            w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
        else
            w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
        fn_800C8034(w->fn_vslot32(lbl_805C0890, 1))->fn_vslot15(1);
    }
    return 0;
}

int fn_8012BF50(Scr* self, int id)
{
    int out;
    int c;
    if (self->m188 != 0 || self->m18C != 0)
        c = 1;
    else
        c = 0;
    if (c != 0) {
        Wid* w = fn_8012B960(self, id, &out);
        if (w != 0) {
            fn_800C8034(w->fn_vslot32(lbl_805C0890, 1))->fn_vslot15(0);
            return 1;
        }
        return 0;
    }
    if (fn_8012E3F4(self) != 0) {
        Wid* w;
        if (self->m184 == 0)
            w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
        else
            w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
        fn_800C8034(w->fn_vslot32(lbl_805C0890, 1))->fn_vslot15(0);
    }
    return 0;
}

/* near-miss: same layout difference as fn_8012C2BC. */
int fn_8012C0A4(Scr* self, int id)
{
    int out;
    int c;
    if (self->b0) {
        if (self->m188 != 0 || self->m18C != 0)
            c = 1;
        else
            c = 0;
        if (c != 0) {
            Wid* w = fn_8012B960(self, id, &out);
            if (w != 0) {
                fn_800C805C(fn_800C8044(w->fn_vslot32(lbl_805BC1A0, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot38(1);
                fn_8012D0D0(self);
            }
            return 1;
        }
        if (fn_8012E3F4(self) != 0) {
            int k = self->fn_vslot85();
            Wid* w;
            if (k != 2) {
                if (k == 0) {
                    if (self->fn_vslot86() == 0)
                        return 0;
                    w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
                } else {
                    if (self->fn_vslot87() == 0)
                        return 0;
                    w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
                }
                fn_800C805C(fn_800C8044(w->fn_vslot32(lbl_805BC1A0, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot38(1);
            } else
                return 0;
        }
        return 1;
    }
    return 0;
}

/* near-miss: 1 extra insn; retail places the shared `li r3,0` block between the slot-87 test and the second name arm, and
 * does not merge the first chain with the shared one (GCC merges them when the early returns are hoisted). */
int fn_8012C2BC(Scr* self, int id)
{
    int out;
    int c;
    if (self->m188 != 0 || self->m18C != 0)
        c = 1;
    else
        c = 0;
    if (c != 0) {
        Wid* w = fn_8012B960(self, id, &out);
        if (w != 0)
            fn_800C805C(fn_800C8044(w->fn_vslot32(lbl_805BC1A0, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot39();
    } else if (fn_8012E3F4(self) != 0) {
        int r = self->fn_vslot85();
        if (r == 2)
            return 0;
        Wid* w;
        if (r == 0) {
            if (self->fn_vslot86() == 0)
                return 0;
            w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
        } else {
            if (self->fn_vslot87() == 0)
                return 0;
            w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
        }
        fn_800C805C(fn_800C8044(w->fn_vslot32(lbl_805BC1A0, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot39();
    }
    return 1;
}

/* near-miss (99.1%): one pair swapped in the first widget chain (retail: lis r4 / li r5,1 / addi r4; here addi before li). Tried local splits of the chain. */
int fn_8012C4B8(Scr* self, int id)
{
    int out;
    int c;
    if (!self->b0)
        return 0;
    if (self->m188 != 0 || self->m18C != 0)
        c = 1;
    else
        c = 0;
    if (c != 0) {
        Wid* w = fn_8012B960(self, id, &out);
        if (w != 0) {
            fn_800C805C(fn_800C8044(w->fn_vslot32(lbl_805BC1A0, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot40(1);
            fn_8012D0D0(self);
        }
    } else if (fn_8012E3F4(self) != 0) {
        int r = self->fn_vslot85();
        if (r == 2)
            return 0;
        Wid* w;
        if (r == 0) {
            if (self->fn_vslot86() == 0)
                return 0;
            w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
        } else {
            if (self->fn_vslot87() == 0)
                return 0;
            w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
        }
        fn_800C805C(fn_800C8044(w->fn_vslot32(lbl_805BC1A0, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot40(1);
    }
    return 1;
}

int fn_8012C6D0(Scr* self, int id)
{
    int out;
    int c;
    if (self->m188 != 0 || self->m18C != 0)
        c = 1;
    else
        c = 0;
    if (c != 0) {
        Wid* w = fn_8012B960(self, id, &out);
        if (w != 0)
            fn_800C805C(fn_800C8044(w->fn_vslot32(lbl_805BC1A0, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot41();
    } else if (fn_8012E3F4(self) != 0) {
        int r = self->fn_vslot85();
        if (r == 2)
            return 0;
        Wid* w;
        if (r == 0) {
            if (self->fn_vslot86() == 0)
                return 0;
            w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
        } else {
            if (self->fn_vslot87() == 0)
                return 0;
            w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
        }
        fn_800C805C(fn_800C8044(w->fn_vslot32(lbl_805BC1A0, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot41();
    }
    return 1;
}

}
