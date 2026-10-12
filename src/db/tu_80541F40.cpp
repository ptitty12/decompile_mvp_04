/*
 * Database overlay code, .database_codeoverlay 0x80541F40-0x805467E0 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8053967C.h"

typedef Db8053967C_List L;

extern const char lbl_805FEF00[];
extern const char lbl_805FEF40[];
extern int lbl_80622B80;
extern int lbl_80622B84[];
extern const float lbl_805FEF4C;

extern "C" {

/* protos */
void* fn_80541F40(void* self);
void fn_80541F98(void* self, int chrg);
int fn_805421B8(Db8053967C_DbObj* list, const char* str);
void fn_80542274();
void fn_805422EC(int id);
void fn_8054247C();
int fn_805424AC(int id);
void fn_80542580(Db80541F40_Slots* o);
int fn_805425FC(Db80541F40_Slots* o, int a);
void fn_80542688(Db80541F40_Slot* e, int id);
int fn_8054289C(void* self, int id, int k);
int fn_805428CC(int a, int id, int k);
int fn_80542AD4(int x, int b, int k);
int fn_80542B2C(char* o);
void* fn_80542F88(void* self);
void fn_80542FC0(Db80541F40_Obj* o, int a, int b);
void fn_80542FCC();
int fn_80543A68(Db80541F40_Obj* o);
void fn_80543D28(L* l);
int fn_805464B4(int a, int b);
int fn_80546548(int a, int x);
/* end protos */

void* fn_803779B8(void* self, int a, int b, int c, const char* path, int line);
void fn_803778EC(void* self, int a);
void fn_80377408(void* p);
void fn_80541FDC(void* self, const char* s);
void fn_80542688(Db80541F40_Slot* e, int id);
int fn_805424AC(int a);
void fn_80599B24(void* p);
void fn_80361580(void* p);
void fn_8057DA7C(int a, int b);
void fn_8057DDC4(int a, int b);
int fn_8040ABA0();
void* fn_800A199C(void* g);
Db80541F40_Cur* fn_800A1960(void* g);
int fn_805426B8(Db80541F40_Slot* s, int a);
int fn_80552D98();
int fn_8040B6A0(const char* s);
unsigned fn_80599C40(int a, int b);
int fn_80599C50(int a, int b, unsigned char c);
int fn_80546548(int a, int x);
int fn_805428FC(void* self, int id, int v);
int fn_80542AD4(int x, int b, int k);

DB_OVERLAY void* fn_80541F40(void* self)
{
    fn_803779B8(self, 0x76C, 0, 0, lbl_805FEF00, 0x1D);
    fn_80541FDC(self, lbl_805FEF40);
    return self;
}

DB_OVERLAY void fn_80541F98(void* self, int chrg)
{
    fn_803778EC(self, 2);
    if (chrg & 1)
        fn_80377408(self);
}

DB_OVERLAY int fn_805421B8(Db8053967C_DbObj* list, const char* str)
{
    char buf[0x80];
    unsigned n = fn_8040B6A0(str);
    unsigned i = 0;
    for (; i < n; i++) {
        int c = (signed char)str[i];
        if (*(unsigned char*)(c + (int)lbl_8060E9F1) & 1)
            c += 0x20;
        buf[i] = c;
    }
    buf[n] = 0;
    int h = fn_80378568(buf, 0);
    int sp88 = 0;
    int sp8C = 0;
    int ok = fn_80377E90(list, &sp88, &sp8C, h);
    int r = 0;
    if (ok != 0)
        r = sp88;
    return r;
}

DB_OVERLAY void fn_80542274()
{
    unsigned i = 0;
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    unsigned n = s->fn_8007B2B0();
    if (i < n) {
        do {
            if (s->fn_8007B648(0xE, i) != 0)
                fn_805422EC(s->fn_8007B2FC(i));
            i++;
        } while (i < n);
    }
}

DB_OVERLAY void fn_805422EC(int id)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    float f = s->fn_80079E74(id) * lbl_805FEF4C;
    f = f - s->m1F4;
    s->fn_8007B4A8(0x15, id, (int)(f / s->m204));
}

DB_OVERLAY void fn_8054247C()
{
    fn_805424AC(fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0));
}

DB_OVERLAY int fn_805424AC(int id)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int cur = fn_8007F7D0((Unk8007F198_B*)s, 0);
    int b = fn_80552D98();
    int row = s->fn_8007B8C4(0x36, s->fn_8007B320(0, id));
    int v = *(int*)((char*)lbl_80602DC0 + (row * 0x2C + b * 4));
    if (id == cur) {
        if (b == 0)
            v = 0;
    } else {
        v = lbl_80622B80;
    }
    int r = s->fn_80079F90(s->fn_80079B14(id)) + v;
    if (r < 0)
        r = 0;
    s->fn_8007B4A8(0x15, id, r);
    return v;
}

DB_OVERLAY void fn_80542580(Db80541F40_Slots* o)
{
    unsigned i = 0;
    Db80541F40_IL* t = (Db80541F40_IL*)fn_800A199C(lbl_80619948);
    unsigned n = t->m4;
    *(unsigned*)((char*)o + 0x3528) = n;
    if (i < n) {
        Db80541F40_Slot* p = o->s;
        int off = 0;
        do {
            Db80541F40_Slot* cur = p;
            i++;
            p++;
            int id = *(int*)((char*)t->m0 + off);
            off += 4;
            fn_80542688(cur, id);
        } while (i < *(unsigned*)((char*)o + 0x3528));
    }
}

/* near-miss: retail keeps i*0x6C as a per-iteration mulli (no strength reduction); ours reduces it */
DB_OVERLAY int fn_805425FC(Db80541F40_Slots* o, int a)
{
    Db80541F40_Cur* g = fn_800A1960(lbl_80619948);
    unsigned i = 0;
    unsigned n = *(unsigned*)((char*)o + 0x3528);
    int key = g->m32E0[g->m32EC];
    if (i < n) {
        do {
            int off = i * 0x6C;
            if (*(int*)((char*)o + off) == key)
                return fn_805426B8((Db80541F40_Slot*)((char*)o + off), a);
            i++;
        } while (i < n);
    }
    return 0;
}

DB_OVERLAY void fn_80542688(Db80541F40_Slot* e, int id)
{
    e->m0 = id;
    e->m4 = 0;
    for (int i = 0; i < 25; i++)
        e->m8[i] = 0;
}

DB_OVERLAY int fn_8054289C(void* self, int id, int k)
{
    return fn_805428FC(self, id, lbl_80622B84[k]);
}

DB_OVERLAY int fn_805428CC(int a, int id, int k)
{
    return fn_80542AD4(a, id, lbl_80622B84[k]);
}

DB_OVERLAY int fn_80542AD4(int x, int b, int k)
{
    int r = 0;
    if ((unsigned)(k - 6) <= 1 || k == 0xB)
        r = 1;
    int t = r ^ ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_8007A270(b);
    return t == 0;
}

/* near-miss: retail's first p[n] test is an lwzx with n in a register (not folded to a displacement) */
DB_OVERLAY int fn_80542B2C(char* o)
{
    int* p = (int*)(o + 8);
    int n = 0;
    while (p[n] != 0)
        n++;
    int lim = 0x18;
    if (n <= 0xD)
        lim = 0xD;
    int c = fn_8040ABA0() % 24;
    if (c > 0) {
        do {
            int d = lim + 1;
            int k = n + 1;
            for (;;) {
                n = k % d;
                if (p[n] == 0)
                    break;
                k = n + 1;
            }
            c--;
        } while (c != 0);
    }
    return n;
}

DB_OVERLAY void* fn_80542F88(void* self)
{
    fn_80599B24(self);
    fn_80361580((char*)self + 0x2C);
    return self;
}

DB_OVERLAY void fn_80542FC0(Db80541F40_Obj* o, int a, int b)
{
    o->m40 = b;
    o->m44 = a;
}

DB_OVERLAY void fn_80542FCC()
{
    lbl_80622BE8 = -1;
}

DB_OVERLAY int fn_80543A68(Db80541F40_Obj* o)
{
    fn_8057DA7C(lbl_80619948->m44, o->m44);
    fn_8057DDC4(lbl_80619948->m44, o->m44);
    return 1;
}

DB_OVERLAY void fn_80543D28(L* l)
{
    unsigned n = l->m4;
    if (n > 1) {
        unsigned i = 0;
        unsigned rem = n;
        if (i < n) {
            int off = n * 4;
            do {
                unsigned r;
                if (rem != 0)
                    r = fn_8040ABA0() % rem;
                else
                    r = 0;
                int* d = l->m0;
                off -= 4;
                rem--;
                int ro = r * 4;
                int x = *(int*)((char*)d + ro);
                int y = *(int*)((char*)d + off);
                if (rem >= l->m4)
                    l->m4 = rem + 1;
                *(int*)(off + (int)l->m0) = x;
                if (r >= l->m4)
                    l->m4 = r + 1;
                i++;
                *(int*)(ro + (int)l->m0) = y;
            } while (i < n);
        }
    }
}

DB_OVERLAY int fn_805464B4(int a, int b)
{
    int i = 0;
    for (;;) {
        unsigned n = fn_80599C40(b, i);
        unsigned k = 0;
        if (k < n) {
            do {
                if (fn_80546548(a, fn_80599C50(b, i, k)) != 0)
                    return 1;
                k++;
            } while (k < n);
        }
        i++;
        if (i > 1)
            return 0;
    }
}

DB_OVERLAY int fn_80546548(int a, int x)
{
    Unk8007F198_E* e = (Unk8007F198_E*)lbl_8061930C;
    unsigned s = 0;
    unsigned n = fn_8007FE0C(e);
    if (s < n) {
        do {
            int t = 0;
            do {
                unsigned k = 0;
                unsigned m = fn_8007FE60(e, s, t);
                if (k < m) {
                    do {
                        if (fn_8007FE84(e, s, t, k) == x)
                            return 1;
                        k++;
                    } while (k < m);
                }
                t++;
            } while (t <= 1);
            s++;
        } while (s < n);
    }
    return 0;
}

}
