/*
 * Database overlay code, .database_codeoverlay 0x8053E240-0x80541F40 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8053967C.h"

typedef Db8053E240_Ctx C30;

extern const float lbl_805FEE08;
extern const float lbl_805FEE0C;
extern const float lbl_805FEEE4;
extern const float lbl_805FEEE8;

struct Db8053E240_Ent12 {
    int w0;
    int w4;
    int w8;
};
int fn_8007F330(Unk8007F198_A* a, int b, int c);

/* Q18 types */
struct Db8053E240_EntF {
    int w0;
    int w4;
    float w8;
};

int fn_8007F1E0(Unk8007F198_A* a, int b, int c);
/* end Q18 types */

extern "C" {
/* Q18 protos */
int fn_8053E240(C30* c, int k, int a, int b, int n, float* f);
void fn_8053E8B8(C30* c, int a, int b, float* f);
void fn_8053E8F0(C30* c, int a, int b, int n, C30* c2, float f);
void fn_8053E934(C30* c, int a, int b, float* f);
void fn_8053E96C(C30* c, int a, int b, float* f);
void fn_8053E9A4(C30* c, int a, int b, int n, C30* c2, float f);
void fn_8053E9E8(C30* c, int a, int b, float* f);
C30* fn_8053EA20(C30* c, int k, int a, int b, float* f);
int fn_8053EB90(C30* c, int k);
int fn_8053EBFC(C30* c, int k);
int fn_8053EC38(C30* c, int x);
int fn_8053F100(C30* c);
int fn_8053F1B4(C30* c);
int fn_8053F268(C30* c);
void fn_8053FAD4(C30* c);
void fn_8053FB70(C30* c);
void fn_8053FC0C(C30* c);
void fn_8053FCC4(C30* c, int kind, int id);
void fn_8053FE0C(C30* c, int mode, int id);
int fn_8054016C(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, float f);
int fn_805401EC(int p0, int p1, int p2, int p3, int p4, int p5, int p6, float f);
void fn_805404C8();
void fn_80540B14(int self, Db8053E240_Ent12* buf, int n, int a);
void fn_80540BBC(int a, Db8053E240_Ent12* e, int n);
void fn_80541C04(Db8053E240_EntF* arr, int n, int id, int v, float key);
int fn_80541CAC(Db8053E240_Ent12* e, int n);
float fn_80541CDC(float a, float b, float c, float d, float e);
float fn_80541D3C(int a, int b, float base);
int fn_80541EC8(int id, int flag, int n, Db8053E240_Ent12* e);
/* end Q18 protos */

int fn_8053E2E8(C30* c, int k, int a, int b, int n, C30* c2, float f);
/* Q18 decls */
extern "C" float fn_80073C10(void* s, int a, int b, int c, int d);
extern char lbl_80649EC0[];
Db8054CBBC_O* fn_8054CBBC(Db8054CBBC_O* o, int a, Unk8007B2B0_Screen* b);
void fn_8054F4F8(Db8054CBBC_O* o);
extern "C" void fn_80537C60(void* l, int a, int b);
extern "C" int fn_800A2AE8(void* p);
extern "C" int fn_8033E888(int a, int b);
extern float lbl_805FEE38;
extern "C" float fn_8007BB28__18Unk8007B2B0_Screeniii(void* s, int a, int b, int c);
extern "C" int fn_800A2ED8(void* p);
extern "C" int fn_80080174__FP13Unk8007FF8C_G(void* g, int a);
extern Db80541F40_Obj* lbl_80619948;
int fn_8053ED0C(C30* c);
int fn_8053F3B0(C30* c, Db8053E240_Tmp* t);
int fn_80540F10(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, float x);
int fn_805419C8(int a, int b, int c, int d, int e, int f, float x);
void fn_80540258(int self, int a, int b, int n, int buf);
void fn_80540530(int k);
/* end Q18 decls */

DB_OVERLAY int fn_8053E240(C30* c, int k, int a, int b, int n, float* f)
{
    fn_8040074C(c, 0x30);
    if (fn_8053E2E8(c, k, a, b, n, c, lbl_805FEE08) < n)
        fn_8053E2E8(c, k, a, b, n, c, lbl_805FEE0C);
    if (f)
        *f = c->m8;
    return c->m0;
}

DB_OVERLAY void fn_8053E8B8(C30* c, int a, int b, float* f)
{
    fn_8053E240(c, 1, a, b, 1, f);
}

DB_OVERLAY void fn_8053E8F0(C30* c, int a, int b, int n, C30* c2, float f)
{
    fn_8053E2E8(c, 1, a, b, n, c2, f);
}

DB_OVERLAY void fn_8053E934(C30* c, int a, int b, float* f)
{
    fn_8053E240(c, 2, a, b, 1, f);
}

DB_OVERLAY void fn_8053E96C(C30* c, int a, int b, float* f)
{
    fn_8053E240(c, 0, a, b, 1, f);
}

DB_OVERLAY void fn_8053E9A4(C30* c, int a, int b, int n, C30* c2, float f)
{
    fn_8053E2E8(c, 0, a, b, n, c2, f);
}

DB_OVERLAY void fn_8053E9E8(C30* c, int a, int b, float* f)
{
    fn_8053E240(c, 3, a, b, 1, f);
}

DB_OVERLAY C30* fn_8053EA20(C30* c, int k, int a, int b, float* f)
{
    int n = k == 0xE ? 3 : 1;
    fn_8053E240(c, k, a, b, n, f);
    return c;
}

DB_OVERLAY int fn_8053EB90(C30* c, int k)
{
    switch (k) {
    case 4:
        return fn_8053ED0C(c);
    case 5:
        return fn_8053F100(c);
    case 6:
        return fn_8053F1B4(c);
    case 7:
        return fn_8053F268(c);
    }
    return 0;
}

DB_OVERLAY int fn_8053EBFC(C30* c, int k)
{
    void* g = lbl_8061930C;
    if (k != 4)
        return 0;
    return fn_80080174__FP13Unk8007FF8C_G(g, 10);
}

DB_OVERLAY int fn_8053EC38(C30* c, int x)
{
    Db8053E240_Tmp t;
    int buf[0x82];
    Db8053E240_Tmp* q = &t;
    q->C1(buf, 0x82);
    q->C2();
    q->C3z(lbl_8064A2A8);
    fn_80537C60(q, x, x);
    int r = fn_8053F3B0(c, q);
    q->D();
    return r;
}

DB_OVERLAY int fn_8053F100(C30* c)
{
    Db8053E240_Tmp t;
    int buf[0x82];
    Db8053E240_Tmp* q = &t;
    q->C1(buf, 0x82);
    q->C2();
    q->C3(lbl_8064A2A8);
    fn_805371C4(q, 0x70000038);
    int r = fn_8053F3B0(c, q);
    q->D();
    return r;
}

DB_OVERLAY int fn_8053F1B4(C30* c)
{
    Db8053E240_Tmp t;
    int buf[0x82];
    Db8053E240_Tmp* q = &t;
    q->C1(buf, 0x82);
    q->C2();
    q->C3(lbl_8064A2A8);
    fn_805371C4(q, 0x70000007);
    int r = fn_8053F3B0(c, q);
    q->D();
    return r;
}

DB_OVERLAY int fn_8053F268(C30* c)
{
    Db8053E240_Sides* sd = lbl_806192E0->m4->m14;
    Db8053E240_Side* o = &sd->s[0];
    Db8053E240_Side* o2 = &sd->s[1];
    int s1 = 0;
    int i;
    for (i = 0; i < 0x80; i++)
        s1 += o2->b1B4[(unsigned char)i];
    int s2 = 0;
    for (i = 0; i < 0x80; i++)
        s2 += o->b1B4[(unsigned char)i];
    Db8053E240_Tmp t;
    int buf[0x82];
    Db8053E240_Tmp* q = &t;
    q->C1(buf, 0x82);
    q->C2();
    q->C3(lbl_8064A2A8);
    Db8053E240_Side* pick = o;
    if (s1 > s2)
        pick = o2;
    int v = pick->m198;
    q->Z();
    fn_80537C60(q, v, v);
    int r = fn_8053F3B0(c, q);
    q->D();
    return r;
}

DB_OVERLAY void fn_8053FAD4(C30* c)
{
    if (fn_800A2ED8(lbl_80619948) == 1) {
        Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
        int h = s->fn_8007B320(0, fn_8007F7D0((Unk8007F198_B*)s, 0));
        if ((int)fn_8007BB28__18Unk8007B2B0_Screeniii(s, 0, h, 1) == 3)
            fn_8053FE0C(c, 2, h);
    }
}

DB_OVERLAY void fn_8053FB70(C30* c)
{
    if (fn_800A2ED8(lbl_80619948) == 2) {
        Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
        int h = s->fn_8007B320(0, fn_8007F7D0((Unk8007F198_B*)s, 0));
        if ((int)fn_8007BB28__18Unk8007B2B0_Screeniii(s, 0, h, 1) == 7)
            fn_8053FE0C(c, 1, h);
    }
}

DB_OVERLAY void fn_8053FC0C(C30* c)
{
    if (fn_800A2ED8(lbl_80619948) == 10) {
        Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
        int h = s->fn_8007B320(0, fn_8007F7D0((Unk8007F198_B*)s, 0));
        int v = (int)fn_8007BB28__18Unk8007B2B0_Screeniii(s, 0, h, 1);
        int r = fn_8053EB90(c, 7);
        if (v == 11) {
            fn_8053FCC4(c, 7, r);
            fn_8053FE0C(c, 0, h);
        }
    }
}

DB_OVERLAY void fn_8053FCC4(C30* c, int kind, int id)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int h = s->fn_8007B320(0, fn_8007F7D0((Unk8007F198_B*)s, 0));
    if (fn_8007F1E0((Unk8007F198_A*)s, id, h) != 0) {
        Db8053CC9C_Buf3 buf;
        int idx = s->fn_8007DA28();
        fn_80329FA0(&buf, fn_800A2AE8(lbl_80619948));
        unsigned short y = buf.b;
        int k = 0;
        if (idx != -1) {
            if ((unsigned)(kind - 8) <= 6) {
                k = 9;
            } else if ((unsigned)(kind - 0xf) <= 7) {
                k = 8;
            } else {
                switch (kind) {
                case 0:
                    k = 3;
                    break;
                case 1:
                    k = 4;
                    break;
                case 2:
                    k = 7;
                    break;
                case 3:
                    k = 5;
                    break;
                case 4:
                    k = 10;
                    break;
                case 7:
                    k = 1;
                    break;
                }
            }
            s->fn_8007D724(idx, k, y, h, id);
        }
    }
}

/* near-miss: 97.6%; retail reads the halfword straight from the frame (lhz r6,10(r1)) while the buffer address stays in r30; ours reads through r30 into r0 then mr r6 */
DB_OVERLAY void fn_8053FE0C(C30* c, int mode, int id)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    if (id == s->fn_8007B320(0, fn_8007F7D0((Unk8007F198_B*)s, 0))) {
        Db8053CC9C_Buf3 buf;
        int idx = s->fn_8007DA28();
        fn_80329FA0(&buf, fn_800A2AE8(lbl_80619948));
        unsigned short y = buf.b;
        int k = 0;
        if (idx != -1) {
            switch (mode) {
            case 0:
                break;
            case 1:
                k = 2;
                break;
            case 2:
                k = 6;
                break;
            }
            s->fn_8007D724(idx, k, y, id, 0);
        }
    }
}

DB_OVERLAY int fn_8054016C(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, float f)
{
    if (p1 == 0x10)
        return fn_805419C8(p2, p3, p5, p6, 0, 0, f);
    return fn_80540F10(p1, p2, p3, p4, p5, p6, 0, 0, 0, p7, f);
}

DB_OVERLAY int fn_805401EC(int p0, int p1, int p2, int p3, int p4, int p5, int p6, float f)
{
    return fn_80540F10(0x17, p0, p1, p2, p3, p4, 1, p5, p6, 0, f);
}

DB_OVERLAY void fn_805404C8()
{
    fn_80540530(0);
    fn_80540530(1);
    Db8054CBBC_O o;
    fn_8054CBBC(&o, fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0), (Unk8007B2B0_Screen*)lbl_8061930C);
    fn_8054F4F8(&o);
    o.m8 = lbl_80649EC0;
}

DB_OVERLAY void fn_80540B14(int self, Db8053E240_Ent12* buf, int n, int a)
{
    fn_8040074C(buf, n * 12);
    int k = fn_805401EC(self, 1, a, n, (int)buf, 0, 0, lbl_805FEE38);
    fn_805401EC(self, 0, a, n - k, (int)(buf + k), k, (int)buf, lbl_805FEE38);
    fn_80540258(self, 1, a, n, (int)buf);
}

DB_OVERLAY void fn_80540BBC(int a, Db8053E240_Ent12* e, int n)
{
    Unk8007F198_A* scr = (Unk8007F198_A*)lbl_8061930C;
    if (n > 0) {
        Db8053E240_Ent12* p = e;
        int k = n;
        do {
            int v = p->w0;
            p++;
            fn_8007F330(scr, a, v);
            k--;
        } while (k != 0);
    }
}

DB_OVERLAY void fn_80541C04(Db8053E240_EntF* arr, int n, int id, int v, float key)
{
    int i = 0;
    for (; i < n; i++) {
        Db8053E240_EntF* e = arr + i;
        int w = e->w0;
        if (w == 0 || !(key <= e->w8)) {
            int j = n - 1;
            while (j > i) {
                arr[j] = arr[j - 1];
                j--;
            }
            e->w0 = id;
            e->w4 = v;
            e->w8 = key;
            return;
        }
        if (w == id)
            return;
    }
}

DB_OVERLAY int fn_80541CAC(Db8053E240_Ent12* e, int n)
{
    int c = 0;
    for (int i = 0; i < n; i++) {
        int v = e->w0;
        e++;
        if (v != 0)
            c++;
    }
    return c;
}

/* near-miss: 2 slots; retail returns the selected parameter slot without spilling the selection */
DB_OVERLAY float fn_80541CDC(float a, float b, float c, float d, float e)
{
    float r;
    if (a == lbl_805FEEE4)
        r = c;
    else if (!(a > lbl_805FEEE8))
        r = e;
    else
        r = d;
    return r * b;
}

DB_OVERLAY float fn_80541D3C(int a, int b, float base)
{
    Unk8007A4DC_Screen* s = (Unk8007A4DC_Screen*)lbl_8061930C;
    float f0 = s->fn_80073710(3, a, b);
    float f1 = s->fn_800739E0(1, a, b, 2);
    float f2 = fn_80073C10(s, 3, a, b, 2);
    float f3 = fn_80073C10(s, 5, a, b, 2);
    float f4 = s->fn_80073710(1, a, b);
    float f5 = s->fn_8007A6A0(0x16, a);
    return f5 * 10.0f + (f3 * 100.0f + f2 * 100.0f + f1 + f0 + f4) + base;
}

DB_OVERLAY int fn_80541EC8(int id, int flag, int n, Db8053E240_Ent12* e)
{
    for (int i = 0; i < n; i++) {
        int v = e->w0;
        e++;
        if (id == v)
            return 1;
    }
    if (flag != 0 && ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_8007A6A0(0x1f, id) > 0)
        return 1;
    return 0;
}

}
