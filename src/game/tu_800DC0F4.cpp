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

void fn_800DC580(UiS* self, float f)
{
    if (f > 1.0f)
        f = 1.0f;
    else if (!(f >= 0.0f))
        f = 0.0f;
    float w = self->v32(lbl_805BC188, 1)->m2A;
    float h = *(short*)((char*)self->v32(lbl_805BC188, 1) + 0x26);
    UiS* t = self->v32(lbl_805BD8C0, 1);
    int a = (int)w - (int)(f * w);
    t->v12(a);
    t->v9((int)h + ((int)w - a));
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

void fn_800DD204(UiS* a, UiS* b)
{
    int g = lbl_8061E978;
    int o = a->v34() * 4;
    char* base = (char*)g + 0x11E88;
    int e = *(int*)(base + o);
    int r = a->v31();
    float x;
    float y;
    fn_800D4254(r, e, &x, &y);
    int c = 0x23;
    if (!(y <= lbl_805BD900))
        c = 0x2D;
    b->v12((int)y + c);
    a->v9(0x36);
    a->v10(0x24);
    b->v9(0x29);
    b->v10(0x31);
}

void fn_800DD344(Udd344_T* t, void* dst)
{
    unsigned char h = t->m0;
    int am = 1;
    unsigned char hh;
    if (h > 11) {
        am = 0;
        hh = h % 12;
    } else
        hh = h;
    if (hh == 0)
        hh = 12;
    char buf[0x18];
    if (am != 0)
        fn_80403DE4(buf, (const char*)fn_80090880(lbl_8061977C, 0x2332), hh, t->m1, fn_80090880(lbl_8061977C, 0x1A7C));
    else
        fn_80403DE4(buf, (const char*)fn_80090880(lbl_8061977C, 0x2332), hh, t->m1, fn_80090880(lbl_8061977C, 0x1A7B));
    fn_80403144(dst, buf);
}

void fn_800DD44C(Unk800DD610_P* t, void* dst, int mode)
{
    char b8[0x40];
    char b48[0x18];
    if (mode == 0) {
        fn_80403DE4(b8, (const char*)fn_80090880(lbl_8061977C, 0x2333), t->m0, t->m1, t->m2);
    } else if (mode == 1) {
        const char* a = (const char*)fn_80090880(lbl_8061977C, 0x2336);
        const char* x = (const char*)fn_80090880(lbl_8061977C, fn_800DD610(t));
        const char* y = (const char*)fn_80090880(lbl_8061977C, fn_800DD5FC(t->m0 - 1));
        fn_80403DE4(b8, a, x, y, fn_800DD6D4(t->m1), t->m2);
    } else if (mode == 2) {
        char* a = (char*)fn_80090880(lbl_8061977C, 0x2334);
        char* y = (char*)fn_80090880(lbl_8061977C, fn_800DD5FC(t->m0 - 1));
        fn_8040321C(b8, a, y, fn_800DD6D4(t->m1));
    } else {
        fn_804031BC(b48, lbl_805BD904);
        fn_80403DE4(b8, b48, fn_80090880(lbl_8061977C, fn_800DD5E8(t->m0 - 1)), t->m1);
    }
    fn_80403144(dst, b8);
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

/* near-miss: 76 vs 75 insns; retail keeps the high half of lbl_806E02B8 in a callee-saved `lis` register (r30) for the three uses; tried a local pointer (worse) */
char* fn_800DD6D4(int n)
{
    char a[0x10];
    char b[0x10];
    fn_804031BC(a, lbl_805BD90C);
    if (n <= 0) {
        fn_804031BC(lbl_806E02B8, lbl_805BD914);
    } else {
        switch (n) {
        case 11:
        case 12:
        case 13:
            fn_804031BC(b, lbl_805BD918);
            break;
        default:
            switch (n % 10) {
            case 1:
                fn_804031BC(b, lbl_805BD91C);
                break;
            case 2:
                fn_804031BC(b, lbl_805BD920);
                break;
            case 3:
                fn_804031BC(b, lbl_805BD924);
                break;
            default:
                fn_804031BC(b, lbl_805BD918);
                break;
            }
            break;
        }
        fn_80403DE4(lbl_806E02B8, a, n, b);
    }
    return lbl_806E02B8;
}

extern char lbl_805B7FE4[];
extern char lbl_805B7FF0[];
extern char lbl_805BD93C[];
extern char lbl_805BD948[];
extern char lbl_805BD950[];
extern char lbl_805BD934[];

void fn_800DDF2C(UiS* self)
{
    ((UiS*)fn_800C8040(fn_800C8044(self->v32(lbl_805B7FE4, 1))->v32(lbl_805BD934, 1)))->v29(0x3EC);
    ((UiS*)fn_800C8040(fn_800C8044(self->v32(lbl_805B7FF0, 1))->v32(lbl_805BD934, 1)))->v29(0x3EC);
    ((UiS*)fn_800C8040(fn_800C8044(self->v32(lbl_805BD93C, 1))->v32(lbl_805BD934, 1)))->v29(0x3EC);
    ((UiS*)fn_800C8040(fn_800C8044(self->v32(lbl_805BD948, 1))->v32(lbl_805BD934, 1)))->v29(0x3EC);
    ((UiS*)fn_800C8040(fn_800C8044(self->v32(lbl_805BD950, 1))->v32(lbl_805BD934, 1)))->v29(0x4D9D);
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

extern "C" void fn_800DE274(int a0, UdE274_T* x, int a2)
{
    char* sub = (char*)x + 0x588;
    char b8[0x18];
    char b20[0x18];
    char b38[0x20];
    fn_802542E8((Unk8024EF40_W*)sub, 0, (int)b20);
    fn_802542E8((Unk8024EF40_W*)sub, 1, (int)b8);
    fn_8040B320(b38, 0, 0x20);
    if (a2 & 0x10) {
        Unk800DB840_Slot* o = 0;
        int s = 5;
        int p = x->m704;
        fn_800DC3D8((int*)&o, &s, p);
        fn_8040B61C(b38, fn_800E5F38(fn_800DBAE0(o, 5, s, p)));
    }
    fn_800DE6A8(a0, b20, b8, a2, x->m384 >> 25, b38);
}

inline void W354b(char* sub, int a, int r, char* out)
{
    fn_8008D738(sub, a, r, out);
}
void fn_800DE354(int a0, UdE354_T* o, int idx, int b, int fl)
{
    char* e = o->m14 + idx * 0xE64;
    char* sub = e + 0xC9C;
    unsigned char r = fn_800968C0(e, b, 1);
    char b8[0x18];
    char b20[0x18];
    char b38[0x20];
    W354b(sub, 0, r, b20);
    W354b(sub, 1, r, b8);
    int v = fn_8008CFD8(sub, 4, r);
    fn_8040B320(b38, 0, 0x20);
    if (fl & 0x10) {
        fn_8040B61C(b38, fn_800E5F38(fn_8008CFD8(sub, 5, r)));
    }
    fn_800DE6A8(a0, b20, b8, fl, v, b38);
}

extern "C" void fn_800DE440(int a0, int a1, int a2)
{
    Unk800DB840_Slot* o = 0;
    int s = 5;
    char b8[0x18];
    char b20[0x18];
    char b38[0x20];
    fn_800DC3D8((int*)&o, &s, a1);
    fn_800DBC50(o, 0, s, a1, (int)b8);
    fn_800DBC50(o, 1, s, a1, (int)b20);
    fn_8040B320(b38, 0, 0x20);
    if (a2 & 0x10) {
        fn_8040B61C(b38, fn_800E5F38(fn_800DBAE0(o, 5, s, a1)));
    }
    fn_800DE6A8(a0, b8, b20, a2, fn_800DBAE0(o, 4, s, a1), b38);
}

void fn_800DE538(int a0, int a1, int a2, int a3)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    char b8[0x18];
    char b20[0x18];
    switch (a1) {
    case 0:
        s->fn_8007C5DC(0, a2, b8);
        s->fn_8007C5DC(1, a2, b20);
        break;
    case 1:
        s->fn_8007C838(0, a2, b8);
        s->fn_8007C838(1, a2, b20);
        break;
    case 2:
        s->fn_8007CA5C(0, a2, b8);
        s->fn_8007CA5C(1, a2, b20);
        break;
    case 3:
        s->fn_8007CC80(0, a2, b8);
        s->fn_8007CC80(1, a2, b20);
        break;
    case 4:
        s->fn_8007CEA4(0, a2, b8);
        s->fn_8007CEA4(1, a2, b20);
        break;
    default:
        b8[0] = 0;
        b20[0] = 0;
        break;
    }
    fn_800DE6A8(a0, b8, b20, a3, 0, 0);
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

void fn_800DF1EC(int n, int* a, int* b);

extern "C" int fn_800DF0DC(int v, int digits)
{
    int cnt;
    int p;
    int r = v < 0 ? -v : v;
    int rem = r;
    fn_800DF1EC(r, &cnt, &p);
    if (cnt > digits) {
        int i = 0;
        if (i < digits) {
            int q = p / 10;
            rem = r % p;
            p = q;
            if (q > 0) {
                int t = q;
                do {
                    i++;
                    if (i < digits) {
                        int tmp = (rem / t) * t;
                        t /= 10;
                        rem -= tmp;
                    } else
                        break;
                } while (t > 0);
                p = t;
                goto round;
            }
        } else {
        round:
            if (p > 0) {
                rem = rem / p;
                if (rem > 4)
                    r += p * 10;
                int t10 = p * 10;
                r = (r / t10) * t10;
            }
        }
    }
    if (v < 0)
        r = -r;
    return r;
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

extern "C" int fn_80403060(const unsigned short* s);

extern "C" void fn_800DFF5C(unsigned short* s)
{
    int n = fn_80403060(s);
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
        case 0x61:
            s[i] = 0x41;
            break;
        case 0x62:
            s[i] = 0x42;
            break;
        case 0x63:
            s[i] = 0x43;
            break;
        case 0x64:
            s[i] = 0x44;
            break;
        case 0x65:
            s[i] = 0x45;
            break;
        case 0x66:
            s[i] = 0x46;
            break;
        case 0x67:
            s[i] = 0x47;
            break;
        case 0x68:
            s[i] = 0x48;
            break;
        case 0x69:
            s[i] = 0x49;
            break;
        case 0x6A:
            s[i] = 0x4A;
            break;
        case 0x6B:
            s[i] = 0x4B;
            break;
        case 0x6C:
            s[i] = 0x4C;
            break;
        case 0x6D:
            s[i] = 0x4D;
            break;
        case 0x6E:
            s[i] = 0x4E;
            break;
        case 0x6F:
            s[i] = 0x4F;
            break;
        case 0x70:
            s[i] = 0x50;
            break;
        case 0x71:
            s[i] = 0x51;
            break;
        case 0x72:
            s[i] = 0x52;
            break;
        case 0x73:
            s[i] = 0x53;
            break;
        case 0x74:
            s[i] = 0x54;
            break;
        case 0x75:
            s[i] = 0x55;
            break;
        case 0x76:
            s[i] = 0x56;
            break;
        case 0x77:
            s[i] = 0x57;
            break;
        case 0x78:
            s[i] = 0x58;
            break;
        case 0x79:
            s[i] = 0x59;
            break;
        case 0x7A:
            s[i] = 0x5A;
            break;
        }
    }
}
