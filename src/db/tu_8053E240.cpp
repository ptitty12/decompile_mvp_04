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

extern "C" {

int fn_8053E2E8(C30* c, int k, int a, int b, int n, C30* c2, float f);

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

}
