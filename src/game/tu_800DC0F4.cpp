/*
 * Game code, .text 0x800DC0F4-0x800E0164 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800DC0F4.h"

extern "C" int fn_800DC0F4(char* arr, int idx, int b)
{
    if (arr != 0) {
        char* e = arr + idx * 0xE64;
        int t = fn_800968C0(e, b, 1);
        int r = fn_8008CFD8(e + 0xC9C, 5, t);
        return r == 0 || r == 10;
    }
    return ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_8007A270(b);
}

int fn_800DC178(int a, int b)
{
    UiW* w = 0;
    if (a != 0)
        w = lbl_806192E0->m4;
    return fn_8007824C(b, w);
}

void fn_800DC3D8(int* a, int* b, int c)
{
    if (UiGetMsgMgr()->mB8 == 1) {
        Ui8011AA24* g = fn_8011AA24(0);
        *a = g->m6F8->m14;
        *b = fn_801A4A94(g, c)->m708;
    } else if (fn_800B555C()->m650 == 1) {
        char* w = lbl_806192E0->m4->m14;
        *a = (int)w;
        int r = fn_800968C0(w + 0xE64, c, 0);
        *b = r != 0xFF;
    } else {
        *a = 0;
        *b = 5;
    }
}

int fn_800DC4BC(UiS* self)
{
    int ok = (int)self->v30(lbl_805BC188, 1);
    int t = 0;
    if (ok)
        t = 1;
    return t;
}

void fn_800DC50C(UiS* self, float f1, float f2)
{
    if (!(f2 <= lbl_805BD8BC))
        f2 = lbl_805BD8BC;
    self->v12((int)(f2 * f1));
}

void fn_800DC728(UiS* self, float f1, float f2)
{
    self->v13((int)(f2 * f1));
}

float fn_800DC77C(UiS* self)
{
    float a = self->v32(lbl_805BC188, 1)->m2A;
    float b = self->v32(lbl_805BD8C0, 1)->m2A;
    float c = a - b;
    return c / a;
}

void fn_800DD140(UiS* self)
{
    UiGetMsgMgr();
    UiGetMsgMgr();
    int h = self->m2C;
    self->v9((640 - self->m2A) / 2);
    self->v10((480 - h) / 2);
}

int fn_800DD5E8(int i)
{
    return lbl_805C2EB4[i];
}

int fn_800DD5FC(int i)
{
    return lbl_805C2E84[i];
}

int fn_800DD610(Unk800DD610_P* p)
{
    return lbl_805C2EE4[fn_8032A130(p->m0 - 1, p->m1, p->m2)];
}

int fn_800DD658(int x)
{
    switch (x) {
    case 0:
        return 0x1A52;
    case 1:
        return 0x1A53;
    case 2:
        return 0x1A54;
    case 3:
        return 0x1A55;
    case 4:
        return 0x1A56;
    case 5:
        return 0x1A57;
    case 6:
        return 0x1A58;
    default:
        return 0x1A7A;
    }
}

void* fn_800DE160(int x)
{
    int id = 0;
    switch (x) {
    case 0:
        id = 0x2B34;
        break;
    case 1:
        id = 0x2B33;
        break;
    case 2:
        id = 0x2B35;
        break;
    }
    return fn_80090880(lbl_8061977C, id);
}

char* fn_800DE1C4(char* dst, int x)
{
    int a = ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_8007A6A0(8, x);
    int b = ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_8007A6A0(9, x);
    void* na = fn_800DE160(a);
    void* nb = fn_800DE160(b);
    char buf[0x28];
    fn_804031BC(buf, lbl_805BA46C);
    fn_80403DE4(dst, buf, na, fn_80090880(lbl_8061977C, 0x2351), nb);
    return dst;
}

int fn_800DE930(int i)
{
    Unk800DE930_T loc = lbl_805BD9BC;
    return loc.m[i];
}

int fn_800DE980(int i, int id)
{
    float w;
    float h;
    float x;
    float y;
    int* arr = (int*)((char*)lbl_8061E978 + 0x11E88);
    fn_803EB434(arr[i], fn_80090880(lbl_8061977C, id), &w, &h, &x, &y);
    return (int)x;
}

extern "C" int fn_800DE9F4(void* a, int b, int c)
{
    if (c != 0) {
        float w, h, x, y;
        int t = fn_800DE980(b, fn_800DE930(c));
        int* arr = (int*)((char*)lbl_8061E978 + 0x11E88);
        fn_803EB434(arr[b], a, &w, &h, &x, &y);
        return (int)x > t;
    }
    return 0;
}

int fn_800DEDC0(int i, int b)
{
    int out = 0;
    int sel = 5;
    fn_800DC3D8(&out, &sel, b);
    int o = i * 8;
    int v = *(int*)((char*)lbl_805BD894 + o);
    int r;
    if (v == -1)
        r = 0xF;
    else
        r = fn_800DB9A8(out, v, sel, b);
    return r;
}

float fn_800DEE38(int i, int b)
{
    Unk800DB840_Slot* out = 0;
    int sel = 5;
    fn_800DC3D8((int*)&out, &sel, b);
    Unk800DEDC0_Row* row = &lbl_805BD894[i];
    float r = fn_800DBA74(out, row->m4, sel, b);
    return r;
}

/* near-miss: retail keeps a redundant second test of the first byte (cmpwi r0,0; beqlr) that
 * the compiler removes here */
char* fn_800DF034(char* s)
{
    if (s[0] == '0') {
        int i = 0;
        while (s[i] != 0) {
            s[i] = s[i + 1];
            i++;
        }
    }
    return s;
}

void fn_800DF064(void* d, int n)
{
    if (n <= 3) {
        *(unsigned char*)d = lbl_805B6F58;
        return;
    }
    if (n <= 6) {
        *(unsigned short*)d = lbl_805BDADC;
        return;
    }
    if (n <= 9) {
        *(unsigned short*)d = lbl_805BDAE0;
        return;
    }
    if (n <= 12) {
        *(unsigned short*)d = lbl_805BDAE4;
        return;
    }
    if (n <= 15) {
        *(unsigned short*)d = lbl_805BDAE8;
    }
}

void fn_800DF1EC(int n, int* a, int* b)
{
    *a = 1;
    *b = 1;
    while ((n /= 10) != 0) {
        (*a)++;
        *b = *b * 10;
    }
}

inline void Call254(UiS* self, float f)
{
    fn_800DF254(self, 0, 3, f);
}

void fn_800DFE40(UiS* self, int b)
{
    Unk8007B2B0_Screen* s = lbl_8061930C;
    float f = s->fn_800799D0(((Unk8007A4DC_Screen*)s)->fn_8007A6A0(0x18, b));
    Call254(self, f);
}

extern "C" void fn_800DFEAC(char* dst, const char* name)
{
    char a[0x190];
    char b[0x190];
    fn_804031BC(a, lbl_805BDBA8);
    fn_804031BC(b, name);
    fn_8040321C(dst, a, dst, b);
}

extern "C" void fn_800DFF0C(char* dst, const char* name)
{
    char a[0x190];
    fn_804031BC(a, lbl_805BDBA8);
    fn_8040321C(dst, a, dst, name);
}
