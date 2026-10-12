/*
 * Database overlay code, .database_codeoverlay 0x80531A20-0x80534078 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"
#include "game/tu_8052A220.h"

extern float lbl_805FE96C;
extern float lbl_805FE9D0;
extern float lbl_805FE9F0;
extern float lbl_805FEA0C;
extern float lbl_805FEA24;
extern float lbl_805FEA3C;
extern float lbl_805FEA50;
extern float lbl_805FEA68;
extern float lbl_805FEAB0;
extern float lbl_805FEAC8;
extern float lbl_805FEAE4;
extern float lbl_805FEAF8;
extern float lbl_805FEAF4;
extern float lbl_805FEA00;
extern char lbl_805FE998[];
extern float lbl_805FEB08;
extern "C" int fn_80379174(const char* s);
extern char lbl_805FEA90[];
extern float lbl_805FEAA8;
extern "C" int fn_8040B750(const char* a, const char* b, int n);
extern "C" void fn_80532D68(Unk80532D68_T* self, int i, int a, float f, int b, int c);
extern float lbl_805FEA60;
extern float lbl_805FEAC0;
extern "C" void fn_805330E0(Unk80531A20_Tbl<10, 4>* self, int i, int j, float f);
extern float lbl_805FEAF0;
extern "C" void fn_805337C8(Unk805337C8_T* self, int v, int c, float f);
extern float lbl_805FEAD8;
extern "C" void fn_805334B0(Unk805334B0_T* self, int a, int c, float f);
extern float lbl_805FEA48;
extern "C" void fn_80532764(Unk80531A20_Tbl<20, 2>* self, int i, int j, float f);
extern float lbl_805FEA18;
extern "C" void fn_805323E0(Unk80531A20_Tbl<20, 5>* self, int i, int j, float f);
extern "C" void fn_805329A8(Unk80532A18_T4* self, int i, int j, int k, int w, float f);
extern "C" void fn_80532144(Unk80531A20_Tbl<20, 3>* self, int i, int j, float f);
extern float lbl_805FEA30;
extern "C" char* fn_802B9300(const char* path, int a, int b, unsigned* n);
extern "C" void fn_802B961C(char* buf, int b);
extern "C" int fn_80409DAC(const char* s);
extern "C" void fn_80533B74(Unk80533B74_T* self, int v, int c, int d);
extern float lbl_805FE9E4;
extern "C" float fn_80532050(Unk80531D2C_T3* self, int a, int b, int c);
extern float lbl_805FE9EC;
extern float lbl_805FEA64;
extern float lbl_805FEAAC;
extern float lbl_805FEAC4;
extern float lbl_805FEAE0;
extern "C" float fn_80532DA0(Unk80532D68_T* self, int i);
extern "C" float fn_80533108(Unk80531A20_Tbl<10, 4>* self, int i, int j);

extern "C" DB_OVERLAY void fn_80531A20(Unk80531A20_T14* self)
{
    unsigned i;
    for (i = 0; i <= 13; i++) {
        self->m8[i] = lbl_805FE96C;
        unsigned j;
        for (j = 0; j < 5; j++)
            self->m40[i][j] = lbl_805FE96C;
    }
}

extern "C" double fn_80409D88(const char* s);

extern "C" DB_OVERLAY void fn_80531A7C(Unk80531A20_T14* self, const char* path)
{
    Unk80533E58_Names nm = *(Unk80533E58_Names*)lbl_805FE998;
    unsigned n = 0;
    char* buf = fn_802B9300(path, 0x100, 6, &n);
    char* end = buf + n;
    char* p = buf;
    while (*p != 10 && p < end)
        p++;
    char c;
    do {
        c = *++p;
    } while (!((unsigned)(c - 0x30) <= 9 || (unsigned)(c - 0x61) <= 0x19 || (unsigned)(c - 0x41) <= 0x19));
    unsigned idx = 2;
    while (p < end) {
        int len = fn_80379174(p);
        unsigned k;
        for (k = 0; k <= 13; k++) {
            if (fn_8040B750(nm.w[k], p, len) == 0) {
                idx = k;
                break;
            }
        }
        while (*p != 0x2C && p < end)
            p++;
        p++;
        float f = (float)fn_80409D88(p);
        self->m8[idx] = f;
        unsigned m = 0;
        unsigned j = 0;
        do {
            while (*p != 0x2C && p < end)
                p++;
            p++;
            m++;
            float g = (float)fn_80409D88(p);
            self->m40[idx][j] = g;
            j++;
        } while (m <= 4);
        while (*p != 10 && p < end)
            p++;
        c = *p;
        while (!((unsigned)(c - 0x30) <= 9 || (unsigned)(c - 0x61) <= 0x19 || (unsigned)(c - 0x41) <= 0x19) && p < end)
            c = *++p;
    }
    fn_802B961C(buf, 6);
}

extern "C" DB_OVERLAY float fn_80531D04(Unk80531A20_T14* self, int i)
{
    return self->m8[i];
}

extern "C" DB_OVERLAY float fn_80531D14(Unk80531A20_T14* self, int i, int j)
{
    return self->m40[i][j];
}

extern "C" DB_OVERLAY void fn_80531D2C(Unk80531D2C_T3* self)
{
    unsigned i;
    for (i = 0; i <= 4; i++) {
        unsigned j;
        for (j = 0; j <= 7; j++) {
            unsigned k;
            for (k = 0; k < 20; k++)
                self->m8[i][j][k] = lbl_805FE9D0;
        }
    }
}

extern const char* lbl_80622A28[];
extern int lbl_8060137C[];
extern unsigned char lbl_8060139C[];
extern float lbl_805FE9E0;
extern "C" void fn_80532078(Unk80531D2C_T3* self, int a, int b, int c, float f);

/* near-miss: 3 differing slots. Control flow, the peeled lookup loop and every call match; the
 * second-loop counter k2 lands in r28 where retail keeps it in r27 (sharing k with the first
 * loop, or reordering declarations, moves the first-loop registers instead). */
extern "C" DB_OVERLAY void fn_80531D84(Unk80531D2C_T3* self, const char* path)
{
    int cols[20];
    unsigned n = 0;
    char* buf = fn_802B9300(path, 0x100, 6, &n);
    char* end = buf + n;
    if (buf != 0 && (int)n > 0) {
        char* p = buf;
        while (*p != 0x2C && p < end)
            p++;
        p++;
        unsigned k = 0;
        do {
            while (*p != 0x2C && p < end)
                p++;
            p++;
            int v = fn_80409DAC(p);
            unsigned m;
            for (m = 0; m <= 19; m++) {
                if (v == lbl_8060139C[m]) {
                    cols[k] = m;
                    break;
                }
            }
            k++;
        } while (k <= 19);
        while (*p != 10 && p < end)
            p++;
        char c;
        do {
            c = *++p;
        } while (p < end && !((unsigned)(c - 0x30) <= 9) && c != 0x2D);
        int kind = 0;
        if (p < end) {
            do {
                int col = fn_80409DAC(p) - 1;
                if (col >= 0) {
                    while (p < end && *p != 0x2C)
                        p++;
                    p++;
                    char* q = p;
                    while (p < end && *p != 0x2C)
                        p++;
                    int len = p - q;
                    unsigned s;
                    for (s = 0; s <= 7; s++) {
                        if (fn_8040B750(lbl_80622A28[s], q, len) == 0) {
                            kind = lbl_8060137C[s];
                            break;
                        }
                    }
                    unsigned k2 = 0;
                    unsigned j = 0;
                    do {
                        while (*p != 0x2C && p < end)
                            p++;
                        p++;
                        k2++;
                        float f = (float)fn_80409DAC(p) * lbl_805FE9E0;
                        fn_80532078(self, col, kind, cols[j], f);
                        j++;
                    } while (k2 <= 19);
                }
                while (*p != 10 && p < end)
                    p++;
                p++;
            } while (p < end);
        }
    }
    fn_802B961C(buf, 6);
}

extern "C" DB_OVERLAY float fn_80532050(Unk80531D2C_T3* self, int a, int b, int c)
{
    return self->m8[a][b][c];
}

extern "C" DB_OVERLAY void fn_80532078(Unk80531D2C_T3* self, int a, int b, int c, float f)
{
    self->m8[a][b][c] = f;
}

extern "C" DB_OVERLAY int fn_805320B0(Unk80531D2C_T3* self, int a, int b, float x)
{
    int r = 0;
    float acc = lbl_805FE9E4;
    unsigned i;
    for (i = 0; i <= 19; i++) {
        acc = acc + fn_80532050(self, a, b, i);
        if (!(x >= acc)) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_80532144(Unk80531A20_Tbl<20, 3>* self, int i, int j, float f)
{
    if (i <= 0x13 && j <= 2)
        self->m8[i][j] = f;
}

/* near-miss: loop and exits match; retail keeps the result in r3 (base pointer in r10) and branches
 * the first compare with blt, ours reuses r3 for the base. */
extern "C" DB_OVERLAY int fn_8053217C(Unk80531A20_Tbl<20, 3>* self, int col, float x)
{
    float acc = lbl_805FE9EC;
    int r = 0;
    unsigned i = 0;
    acc = acc + self->m8[0][col];
    if (!(x < acc)) {
        while (++i <= 19) {
            acc = acc + self->m8[i][col];
            if (!(x >= acc)) {
                r = i;
                break;
            }
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_80532200(Unk80531A20_Tbl<20, 3>* self)
{
    unsigned i;
    for (i = 0; i <= 0x13; i++) {
        unsigned j;
        for (j = 0; j < 3; j++)
            self->m8[i][j] = lbl_805FE9F0;
    }
}

extern "C" DB_OVERLAY void fn_80532244(Unk80531A20_Tbl<20, 3>* self, const char* path)
{
    unsigned n = 0;
    char* buf = fn_802B9300(path, 0x100, 6, &n);
    char* end = buf + n;
    if (buf != 0 && (int)n > 0) {
        char* p = buf;
        while (*p != 10 && p < end)
            p++;
        char c = *++p;
        if (p < end) {
            for (;;) {
                while (!((unsigned)(c - 0x30) <= 9) && c != 0x2D) {
                    c = *++p;
                    if (p >= end)
                        goto done;
                }
            done:
                int j = 0;
                unsigned col = fn_80409DAC(p) - 1;
                if (col <= 2 && p < end) {
                    do {
                        while (p < end && *p != 0x2C)
                            p++;
                        p++;
                        float f = (float)fn_80409DAC(p) * lbl_805FEA00;
                        fn_80532144(self, j, col, f);
                        j++;
                    } while (j <= 19 && p < end);
                }
                while (p < end && *p != 10)
                    p++;
                p++;
                if (!(p < end))
                    break;
            }
        }
    }
    fn_802B961C(buf, 6);
}

extern "C" DB_OVERLAY void fn_805323E0(Unk80531A20_Tbl<20, 5>* self, int i, int j, float f)
{
    if (i <= 0x13 && j <= 4)
        self->m8[i][j] = f;
}

extern "C" DB_OVERLAY void fn_80532418(Unk80531A20_Tbl<20, 5>* self)
{
    unsigned i;
    for (i = 0; i <= 0x13; i++) {
        unsigned j;
        for (j = 0; j < 5; j++)
            self->m8[i][j] = lbl_805FEA0C;
    }
}

extern "C" DB_OVERLAY void fn_8053245C(Unk80531A20_Tbl<20, 5>* self, const char* path)
{
    unsigned n = 0;
    char* buf = fn_802B9300(path, 0x100, 6, &n);
    char* end = buf + n;
    if (buf != 0 && (int)n > 0) {
        char* p = buf;
        while (*p != 10 && p < end)
            p++;
        char c = *++p;
        if (p < end) {
            for (;;) {
                while (!((unsigned)(c - 0x30) <= 9) && c != 0x2D) {
                    c = *++p;
                    if (p >= end)
                        goto done;
                }
            done:
                int j = 0;
                unsigned col = fn_80409DAC(p) - 1;
                if (col <= 4 && p < end) {
                    do {
                        while (p < end && *p != 0x2C)
                            p++;
                        p++;
                        float f = (float)fn_80409DAC(p) * lbl_805FEA18;
                        fn_805323E0(self, j, col, f);
                        j++;
                    } while (j <= 19 && p < end);
                }
                while (p < end && *p != 10)
                    p++;
                p++;
                if (!(p < end))
                    break;
            }
        }
    }
    fn_802B961C(buf, 6);
}

extern "C" DB_OVERLAY void fn_805325F8(Unk805325F8_T20* self)
{
    unsigned i;
    for (i = 0; i < 20; i++)
        self->m8[i] = lbl_805FEA24;
}

extern "C" DB_OVERLAY void fn_80532620(void* self, const char* path)
{
    float vals[20];
    unsigned n = 0;
    char* buf = fn_802B9300(path, 0x100, 6, &n);
    char* end = buf + n;
    if (buf != 0 && (int)n > 0) {
        char* p = buf;
        while (*p != 10 && p < end)
            p++;
        char c;
        do {
            c = *++p;
        } while (p < end && !((unsigned)(c - 0x30) <= 9) && c != 0x2D);
        int i = 0;
        int j = 0;
        if (p < end) {
            do {
                i++;
                vals[j] = (float)fn_80409DAC(p) * lbl_805FEA30;
                j++;
                while (p < end && *p != 0x2C)
                    p++;
                p++;
            } while (p < end && i <= 19);
        }
    }
    fn_802B961C(buf, 6);
}

extern "C" DB_OVERLAY void fn_80532764(Unk80531A20_Tbl<20, 2>* self, int i, int j, float f)
{
    if (i <= 0x13)
        self->m8[i][j] = f;
}

extern "C" DB_OVERLAY void fn_80532794(Unk80531A20_Tbl<20, 2>* self)
{
    unsigned i;
    for (i = 0; i <= 0x13; i++) {
        unsigned j;
        for (j = 0; j <= 1; j++)
            self->m8[i][j] = lbl_805FEA3C;
    }
}

extern "C" DB_OVERLAY void fn_805327DC(Unk80531A20_Tbl<20, 2>* self, const char* path)
{
    unsigned n = 0;
    char* buf = fn_802B9300(path, 0x100, 6, &n);
    char* end = buf + n;
    if (buf != 0 && (int)n > 0) {
        char* p = buf;
        while (*p != 10 && p < end)
            p++;
        char c = *++p;
        if (p < end) {
            for (;;) {
                while (!((unsigned)(c - 0x30) <= 9) && c != 0x2D) {
                    c = *++p;
                    if (p >= end)
                        goto done;
                }
            done:
                char t = *p;
                int col = (t == 0x4C || t == 0x6C) ? 0 : ((t == 0x52 || t == 0x72) ? 1 : 2);
                int j = 0;
                if (col != 2 && p < end) {
                    do {
                        while (p < end && *p != 0x2C)
                            p++;
                        p++;
                        float f = (float)fn_80409DAC(p) * lbl_805FEA48;
                        fn_80532764(self, j, col, f);
                        j++;
                    } while (j <= 19 && p < end);
                }
                while (p < end && *p != 10)
                    p++;
                p++;
                if (!(p < end))
                    break;
            }
        }
    }
    fn_802B961C(buf, 6);
}

extern "C" DB_OVERLAY void fn_805329A8(Unk80532A18_T4* self, int i, int j, int k, int w, float f)
{
    w = w > 0x64 ? 0x64 : (w >? 0x24);
    self->m8[(w - 0x1E) / 10][k][i][j] = f;
}

extern "C" DB_OVERLAY void fn_80532A18(Unk80532A18_T4* self)
{
    unsigned a;
    for (a = 0; a <= 6; a++) {
        unsigned b;
        for (b = 0; b <= 2; b++) {
            unsigned c;
            for (c = 0; c <= 1; c++) {
                unsigned d;
                for (d = 0; d <= 1; d++)
                    self->m8[a][b][c][d] = lbl_805FEA50;
            }
        }
    }
}

extern "C" DB_OVERLAY void fn_80532AA4(Unk80532A18_T4* self, const char* path)
{
    unsigned n = 0;
    char* buf = fn_802B9300(path, 0x100, 6, &n);
    char* end = buf + n;
    if (buf != 0 && (int)n > 0) {
        char* p = buf;
        while (*p != 10 && p < end)
            p++;
        char c = *++p;
        if (p < end) {
            for (;;) {
                while (!((unsigned)(c - 0x30) <= 9) && c != 0x2D) {
                    c = *++p;
                    if (p >= end)
                        goto done;
                }
            done:
                int a = fn_80409DAC(p);
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                int b = fn_80409DAC(p);
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                int w = fn_80409DAC(p);
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                float f0 = (float)fn_80409DAC(p) * lbl_805FEA60;
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                float f1 = (float)fn_80409DAC(p) * lbl_805FEA60;
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                float f2 = (float)fn_80409DAC(p) * lbl_805FEA60;
                if (w != 0) {
                    fn_805329A8(self, a, b, 0, w, f0);
                    fn_805329A8(self, a, b, 1, w, f1);
                    fn_805329A8(self, a, b, 2, w, f2);
                }
                while (p < end && *p != 10)
                    p++;
                p++;
                if (!(p < end))
                    break;
            }
        }
    }
    fn_802B961C(buf, 6);
}

extern "C" DB_OVERLAY void fn_80532D68(Unk80532D68_T* self, int i, int a, float f, int b, int c)
{
    self->m8[i].m0 = a;
    self->m8[i].m4 = f;
    self->m8[i].m8 = b;
    self->m8[i].mC = c;
}

extern "C" DB_OVERLAY float fn_80532DA0(Unk80532D68_T* self, int i)
{
    return self->m8[i].m4;
}

extern "C" DB_OVERLAY int fn_80532DB0(Unk80532D68_T* self, float x)
{
    int r = 0;
    float acc = lbl_805FEA64;
    unsigned i;
    for (i = 0; i <= 14; i++) {
        acc = acc + fn_80532DA0(self, i);
        if (!(x >= acc)) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_80532E34(Unk80532D68_T* self)
{
    unsigned i;
    for (i = 0; i < 15; i++) {
        self->m8[i].m0 = 0;
        self->m8[i].m4 = lbl_805FEA68;
        self->m8[i].m8 = 0;
        self->m8[i].mC = 0;
    }
}

extern "C" DB_OVERLAY void fn_80532E78(Unk80532D68_T* self, const char* path)
{
    Unk80532E78_Names nm = *(Unk80532E78_Names*)lbl_805FEA90;
    unsigned n = 0;
    int cnt = 0;
    char* buf = fn_802B9300(path, 0x100, 6, &n);
    char* end = buf + n;
    if (buf != 0 && (int)n > 0) {
        char* p = buf;
        while (*p != 10 && p < end)
            p++;
        char c = *++p;
        if (p < end) {
            for (;;) {
                while (!((unsigned)(c - 0x30) <= 9) && c != 0x2D) {
                    c = *++p;
                    if (p >= end)
                        goto done;
                }
            done:
                int a = fn_80409DAC(p);
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                int w = fn_80409DAC(p);
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                float f = (float)fn_80409DAC(p) * lbl_805FEAA8;
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                int kind = 0;
                if (fn_8040B750(p, nm.w[1], 3) == 0)
                    kind = 1;
                else if (fn_8040B750(p, nm.w[2], 3) == 0)
                    kind = 2;
                else if (fn_8040B750(p, nm.w[3], 3) == 0)
                    kind = 3;
                if (w != 0) {
                    fn_80532D68(self, cnt, kind, f, a, w);
                    cnt++;
                }
                while (p < end && *p != 10)
                    p++;
                p++;
                if (!(p < end))
                    break;
            }
        }
    }
    fn_802B961C(buf, 6);
}

extern "C" DB_OVERLAY void fn_805330E0(Unk80531A20_Tbl<10, 4>* self, int i, int j, float f)
{
    self->m8[i][j] = f;
}

extern "C" DB_OVERLAY float fn_80533108(Unk80531A20_Tbl<10, 4>* self, int i, int j)
{
    return self->m8[i][j];
}

/* `unsigned i = 0;` and then `for (i = r; ...)`: CSE keeps the copy because i already holds r's value
 * (0), flow deletes the dead first zero, and the extra use of r gives it r30 (retail `mr r31,r30`). */
extern "C" DB_OVERLAY int fn_80533120(Unk80531A20_Tbl<10, 4>* self, int col, float x)
{
    int r = 0;
    unsigned i = 0;
    float acc = lbl_805FEAAC;
    for (i = r; i <= 9; i++) {
        acc = acc + fn_80533108(self, i, col);
        if (!(x >= acc)) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_805331AC(Unk80531A20_Tbl<10, 4>* self)
{
    unsigned i;
    for (i = 0; i <= 9; i++) {
        unsigned j;
        for (j = 0; j < 4; j++)
            self->m8[i][j] = lbl_805FEAB0;
    }
}

extern "C" DB_OVERLAY void fn_805331F0(Unk80531A20_Tbl<10, 4>* self, const char* path)
{
    unsigned n = 0;
    char* buf = fn_802B9300(path, 0x100, 6, &n);
    char* end = buf + n;
    if (buf != 0 && (int)n > 0) {
        char* p = buf;
        while (*p != 10 && p < end)
            p++;
        char c = *++p;
        if (p < end) {
            for (;;) {
                while (!((unsigned)(c - 0x30) <= 9) && c != 0x2D) {
                    c = *++p;
                    if (p >= end)
                        goto done;
                }
            done:
                int id = fn_80409DAC(p);
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                float a = (float)fn_80409DAC(p) * lbl_805FEAC0;
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                float b = (float)fn_80409DAC(p) * lbl_805FEAC0;
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                float d = (float)fn_80409DAC(p) * lbl_805FEAC0;
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                float e = (float)fn_80409DAC(p) * lbl_805FEAC0;
                if (id != 0) {
                    fn_805330E0(self, id, 0, a);
                    fn_805330E0(self, id, 1, b);
                    fn_805330E0(self, id, 2, d);
                    fn_805330E0(self, id, 3, e);
                }
                while (p < end && *p != 10)
                    p++;
                p++;
                if (!(p < end))
                    break;
            }
        }
    }
    fn_802B961C(buf, 6);
}

extern "C" DB_OVERLAY void fn_805334B0(Unk805334B0_T* self, int a, int c, float f)
{
    unsigned k = c - 0x42;
    if (k <= 0x12) {
        self->m8[k].m8 = c;
        self->m8[k].m4 = a;
        self->m8[k].m0 = f;
    }
}

extern "C" DB_OVERLAY int fn_805334EC(Unk805334B0_T* self, unsigned i)
{
    int r = 0;
    if (i <= 0x12)
        r = self->m8[i].m4;
    return r;
}

extern "C" DB_OVERLAY int fn_8053350C(Unk805334B0_T* self, unsigned i)
{
    int r = 0x42;
    if (i <= 0x12)
        r = self->m8[i].m8;
    return r;
}

/* near-miss: same as fn_8053217C (retail keeps the result in r3 and branches the first compare with
 * blt; ours reuses r3 for the base pointer). */
extern "C" DB_OVERLAY int fn_8053352C(Unk805334B0_T* self, float x)
{
    int r = 0;
    float acc = lbl_805FEAC4;
    unsigned i;
    for (i = 0; i <= 18; i++) {
        acc = acc + self->m8[i].m0;
        if (!(x >= acc)) {
            r = i;
            break;
        }
    }
    return r;
}

/* near-miss: two slots (addi r9,r3,12 and lfs are swapped). */
extern "C" DB_OVERLAY void fn_805335A8(Unk805334B0_T* self)
{
    unsigned i;
    for (i = 0; i < 19; i++) {
        self->m8[i].m8 = 0;
        self->m8[i].m4 = 0;
        self->m8[i].m0 = lbl_805FEAC8;
    }
}

extern "C" DB_OVERLAY void fn_805335E4(Unk805334B0_T* self, const char* path)
{
    unsigned n = 0;
    char* buf = fn_802B9300(path, 0x100, 6, &n);
    char* end = buf + n;
    if (buf != 0 && (int)n > 0) {
        char* p = buf;
        while (*p != 10 && p < end)
            p++;
        char c = *++p;
        if (p < end) {
            for (;;) {
                while (!((unsigned)(c - 0x30) <= 9) && c != 0x2D) {
                    c = *++p;
                    if (p >= end)
                        goto done;
                }
            done:
                float f = (float)fn_80409DAC(p) * lbl_805FEAD8;
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                int k = fn_80409DAC(p);
                while (p < end && *p != 0x2C)
                    p++;
                char t = *++p;
                int kind = 3;
                if (t == 0x53 || t == 0x73)
                    kind = 0;
                else if (t == 0x41 || t == 0x61)
                    kind = 1;
                else if (t == 0x54 || t == 0x74)
                    kind = 2;
                if (kind != 3)
                    fn_805334B0(self, kind, k, f);
                while (p < end && *p != 10)
                    p++;
                p++;
                if (!(p < end))
                    break;
            }
        }
    }
    fn_802B961C(buf, 6);
}

extern "C" DB_OVERLAY void fn_805337C8(Unk805337C8_T* self, int v, int c, float f)
{
    unsigned k = (unsigned)(v - 0x96) / 10;
    if (k <= 13 && c <= 2) {
        self->m8[c][k].m0 = f;
        self->m8[c][k].m4 = v;
    }
}

extern "C" DB_OVERLAY int fn_8053381C(Unk805337C8_T* self, int a, unsigned b)
{
    int r = 0;
    if (a <= 2 && b <= 13)
        r = self->m8[a][b].m4;
    return r;
}

/* near-miss: same as fn_8053217C. */
extern "C" DB_OVERLAY int fn_8053384C(Unk805337C8_T* self, int row, float x)
{
    int r = 0;
    float acc = lbl_805FEAE0;
    unsigned i;
    for (i = 0; i <= 13; i++) {
        acc = acc + self->m8[row][i].m0;
        if (!(x >= acc)) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_805338D0(Unk805337C8_T* self)
{
    unsigned i;
    for (i = 0; i <= 2; i++) {
        unsigned j;
        for (j = 0; j < 14; j++) {
            self->m8[i][j].m0 = lbl_805FEAE4;
            self->m8[i][j].m4 = 0;
        }
    }
}

extern "C" DB_OVERLAY void fn_80533920(Unk805337C8_T* self, const char* path)
{
    unsigned n = 0;
    char* buf = fn_802B9300(path, 0x100, 6, &n);
    char* end = buf + n;
    if (buf != 0 && (int)n > 0) {
        char* p = buf;
        while (*p != 10 && p < end)
            p++;
        char c = *++p;
        if (p < end) {
            for (;;) {
                while (!((unsigned)(c - 0x30) <= 9) && c != 0x2D) {
                    c = *++p;
                    if (p >= end)
                        goto done;
                }
            done:
                int id = fn_80409DAC(p);
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                float a = (float)fn_80409DAC(p) * lbl_805FEAF0;
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                float b = (float)fn_80409DAC(p) * lbl_805FEAF0;
                while (p < end && *p != 0x2C)
                    p++;
                p++;
                float d = (float)fn_80409DAC(p) * lbl_805FEAF0;
                if (id != 0) {
                    fn_805337C8(self, id, 0, a);
                    fn_805337C8(self, id, 1, b);
                    fn_805337C8(self, id, 2, d);
                }
                while (p < end && *p != 10)
                    p++;
                p++;
                if (!(p < end))
                    break;
            }
        }
    }
    fn_802B961C(buf, 6);
}

extern "C" DB_OVERLAY void fn_80533B74(Unk80533B74_T* self, int v, int c, int d)
{
    unsigned k = (unsigned)(v - 0x96) / 10;
    unsigned r = c - 0x42;
    if (k <= 13 && r <= 18)
        self->m8[r][k] = d;
}

extern "C" DB_OVERLAY int fn_80533BB4(Unk80533B74_T* self, int v, int c)
{
    int out = 0;
    unsigned k = (unsigned)(v - 0x96) / 10;
    unsigned r = c - 0x42;
    if (k <= 13 && r <= 18)
        out = self->m8[r][k];
    return out;
}

extern "C" DB_OVERLAY void fn_80533BFC(Unk80533B74_T* self)
{
    unsigned i;
    for (i = 0; i <= 18; i++) {
        unsigned j;
        for (j = 0; j < 14; j++)
            self->m8[i][j] = 0;
    }
}

extern "C" DB_OVERLAY void fn_80533C3C(Unk80533B74_T* self, const char* path)
{
    unsigned n = 0;
    char* buf = fn_802B9300(path, 0x100, 6, &n);
    char* end = buf + n;
    if (buf != 0 && (int)n > 0) {
        char* p = buf;
        while (*p != 10 && p < end)
            p++;
        char c = *++p;
        if (p < end) {
            for (;;) {
                while (!((unsigned)(c - 0x30) <= 9) && c != 0x2D) {
                    c = *++p;
                    if (p >= end)
                        goto done;
                }
                done:
                int a = fn_80409DAC(p);
                if (a != 0) {
                    int b = fn_80409DAC(p);
                    while (p < end && *p != 0x2C)
                        p++;
                    p++;
                    fn_80533B74(self, a, 0x42, b);
                }
                while (p < end && *p != 10)
                    p++;
                p++;
                if (!(p < end))
                    break;
            }
        }
    }
    fn_802B961C(buf, 6);
}

extern "C" DB_OVERLAY int fn_80533D80(Unk80533E14_T* self, int row, float x)
{
    int r = 2;
    float acc = lbl_805FEAF4;
    unsigned i;
    for (i = 0; i <= 13; i++) {
        acc = acc + self->m8[row][i];
        if (!(x >= acc)) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_80533E14(Unk80533E14_T* self)
{
    unsigned i;
    for (i = 0; i <= 13; i++) {
        unsigned j;
        for (j = 0; j < 14; j++)
            self->m8[i][j] = lbl_805FEAF8;
    }
}

extern "C" DB_OVERLAY void fn_80533E58(Unk80533E14_T* self, const char* path)
{
    Unk80533E58_Names nm = *(Unk80533E58_Names*)lbl_805FE998;
    unsigned j = 0;
    unsigned n = 0;
    char* buf = fn_802B9300(path, 0x100, 6, &n);
    char* end = buf + n;
    if (buf != 0 && (int)n > 0) {
        char* p = buf;
        while (*p != 10 && p < end)
            p++;
        p++;
        while (p < end) {
            int len = fn_80379174(p);
            int idx = 14;
            for (j = 0; j <= 13; j++) {
                if (fn_8040B750(p, nm.w[j], len) == 0) {
                    idx = j;
                    break;
                }
            }
            if (idx != 14) {
                int k = 0;
                if (p < end) {
                    do {
                        while (p < end && *p != 0x2C)
                            p++;
                        p++;
                        float f = (float)fn_80409DAC(p) * lbl_805FEB08;
                        if (k <= 13 && idx <= 13)
                            self->m8[k][idx] = f;
                        k++;
                    } while (k <= 13 && p < end);
                }
            }
            while (p < end && *p != 10)
                p++;
            p++;
        }
    }
    fn_802B961C(buf, 6);
}
