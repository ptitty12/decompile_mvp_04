/*
 * Database overlay code, .database_codeoverlay 0x80534078-0x80535360 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"
#include "game/tu_8052A220.h"

extern float lbl_805FEB0C;
extern float lbl_805FEB38;
extern float lbl_805FEB60;
extern float lbl_805FEB64;
extern float lbl_805FEB68;
extern float lbl_805FEB20;
extern "C" char* fn_802B9300(const char* path, int a, int b, unsigned* n);
extern "C" void fn_802B961C(char* buf, int b);
extern "C" int fn_80409DAC(const char* s);
extern float lbl_805FEB10;
extern float lbl_805FEB24;
extern float lbl_805FEB28;
extern float lbl_805FEB48;
extern float lbl_805FEB4C;
extern float lbl_805FEB50;
extern int lbl_80622A48;
extern "C" void fn_802B8E1C();
extern "C" void fn_802B8E84();
extern Unk8007A4DC_Screen* lbl_8061930C;
extern "C" void fn_8053502C(Unk80534598_T* self, int a);
extern "C" char* fn_8040B61C(char* dst, const char* src);
extern "C" char* fn_8040B830(char* dst, const char* src, int n);
extern "C" int fn_8040B6A0(const char* s);
extern "C" unsigned fn_8040ABA0();
extern "C" void fn_80534F64(Unk80534EA0_T* self, char* dstA, unsigned nA, unsigned a, char* dstB, unsigned nB, unsigned b);

extern "C" DB_OVERLAY int fn_80534078(Unk80534078_T* self, int row, float x)
{
    int r = 0x53;
    float acc = lbl_805FEB0C;
    unsigned i;
    for (i = 0; i <= 15; i++) {
        acc = acc + self->m8[row][i];
        if (!(x >= acc)) {
            r = 0x62 - i;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_8053410C(Unk80534078_T* self)
{
    unsigned i;
    for (i = 0; i <= 4; i++) {
        unsigned j;
        for (j = 0; j < 16; j++)
            self->m8[i][j] = lbl_805FEB10;
    }
}

extern "C" DB_OVERLAY void fn_80534150(Unk80534078_T* self, const char* path)
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
                unsigned j = 0;
                int row = fn_80409DAC(p);
                if (row != 0 && p < end) {
                    do {
                        while (p < end && *p != 0x2C)
                            p++;
                        p++;
                        float f = (float)fn_80409DAC(p) * lbl_805FEB20;
                        if (j <= 15) {
                            unsigned idx = row - 1;
                            if (idx <= 4) {
                                self->m8[idx][j] = f;
                                j++;
                            }
                        }
                        if (j > 15)
                            break;
                    } while (p < end);
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

extern "C" DB_OVERLAY int fn_80534304(Unk80534304_T* self, float x)
{
    int r = 0x3A;
    float acc = lbl_805FEB24;
    unsigned i;
    for (i = 0; i <= 12; i++) {
        acc = acc + self->m8[i];
        if (!(x >= acc)) {
            r = 0x46 - i;
            break;
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_80534390(Unk80534304_T* self)
{
    unsigned i;
    for (i = 0; i < 13; i++)
        self->m8[i] = lbl_805FEB28;
}

extern "C" DB_OVERLAY void fn_805343B8(Unk80534304_T* self, const char* path)
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
            int off = 0;
            for (;;) {
                while (!((unsigned)(c - 0x30) <= 9) && c != 0x2D) {
                    c = *++p;
                    if (p >= end)
                        goto done;
                }
            done:
                if (fn_80409DAC(p) != 0) {
                    while (p < end && *p != 0x2C)
                        p++;
                    p++;
                    float f = (float)fn_80409DAC(p) * lbl_805FEB38;
                    float* q = self->m8;
                    *(float*)((char*)q + off) = f;
                    off += 4;
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

extern "C" DB_OVERLAY void fn_80534530(Unk80534530_Obj* self, int a)
{
    if (lbl_80622A48 == 0) {
        fn_802B8E1C();
        lbl_80622A48 = 1;
        self->v10(a);
        fn_802B8E84();
    }
}

extern "C" DB_OVERLAY void fn_80534598(Unk80534598_T* self, int a, int b, int v)
{
    unsigned k = a > 0x12 ? a - 0x12 : 0;
    if (k > 0x2C)
        k = 0x2C;
    self->m8[k][b][0] = v;
}

extern "C" DB_OVERLAY void fn_805345CC(Unk80534598_T* self, int a, int b, int v)
{
    unsigned k = a > 0x12 ? a - 0x12 : 0;
    if (k > 0x2C)
        k = 0x2C;
    self->m8[k][b][1] = v;
}

extern "C" DB_OVERLAY void fn_80534600(Unk80534598_T* self, int a, int b, int v)
{
    unsigned k = a > 0x12 ? a - 0x12 : 0;
    if (k > 0x2C)
        k = 0x2C;
    self->m8[k][b][2] = v;
}

extern "C" DB_OVERLAY void fn_80534634(Unk80534598_T* self, int a, int b, int v)
{
    unsigned k = a > 0x12 ? a - 0x12 : 0;
    if (k > 0x2C)
        k = 0x2C;
    self->m8[k][b][3] = v;
}

extern "C" DB_OVERLAY void fn_80534668(Unk80534598_T* self, int a, int b, int v)
{
    unsigned k = a > 0x12 ? a - 0x12 : 0;
    if (k > 0x2C)
        k = 0x2C;
    self->m8[k][b][4] = v;
}

extern "C" DB_OVERLAY void fn_8053469C(Unk80534598_T* self, int a, int b, int v)
{
    unsigned k = a > 0x12 ? a - 0x12 : 0;
    if (k > 0x2C)
        k = 0x2C;
    self->m8[k][b][5] = v;
}

extern "C" DB_OVERLAY int fn_805346D0(Unk80534598_T* self, int a, int b)
{
    unsigned k = a > 0x12 ? a - 0x12 : 0;
    if (k > 0x2C)
        k = 0x2C;
    return self->m8[k][b][3];
}

extern "C" DB_OVERLAY int fn_80534704(Unk80534598_T* self, int a, int b)
{
    unsigned k = a > 0x12 ? a - 0x12 : 0;
    if (k > 0x2C)
        k = 0x2C;
    return self->m8[k][b][4];
}

extern "C" DB_OVERLAY int fn_80534738(Unk80534598_T* self, int a, int b)
{
    unsigned k = a > 0x12 ? a - 0x12 : 0;
    if (k > 0x2C)
        k = 0x2C;
    return self->m8[k][b][5];
}

extern "C" DB_OVERLAY void fn_8053476C(Unk80534598_T* self)
{
    unsigned i;
    for (i = 0; i <= 27; i++) {
        unsigned j;
        for (j = 0; j < 5; j++) {
            self->m8[i][j][0] = 0;
            self->m8[i][j][1] = 0;
            self->m8[i][j][2] = 0;
            self->m8[i][j][3] = 0;
            self->m8[i][j][4] = 0;
            self->m8[i][j][5] = 0;
        }
    }
}

extern "C" DB_OVERLAY float fn_80534BAC(Unk80534BAC_T* self, int a, int b)
{
    a -= 0x12;
    if (a < 0)
        a = 0;
    if (a > 0x1B)
        a = 0x1B;
    if (b < 0)
        b = 0;
    if (b > 4)
        b = 4;
    float r = self->m8[a][b];
    r = (r <? lbl_805FEB48) >? lbl_805FEB4C;
    return r;
}

extern "C" DB_OVERLAY void fn_80534C3C(Unk80534BAC_T* self)
{
    int i;
    for (i = 0; i <= 27; i++) {
        unsigned j;
        for (j = 0; j < 5; j++)
            self->m8[i][j] = lbl_805FEB50;
    }
}

/* near-miss: same instruction count; the lis/lfs of the clamp constants are scheduled differently. */
extern "C" DB_OVERLAY void fn_80534C7C(Unk80534BAC_T* self, const char* path)
{
    unsigned n = 0;
    char* buf = fn_802B9300(path, 0, 14, &n);
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
                    while (p < end && *p != 0x2C)
                        p++;
                    p++;
                    int b = fn_80409DAC(p) - 1;
                    if (b < 0)
                        b = 0;
                    if (b > 4)
                        b = 4;
                    while (p < end && *p != 0x2C)
                        p++;
                    p++;
                    int raw = fn_80409DAC(p);
                    unsigned i = a - 0x12;
                    if (i > 0x1B)
                        i = 0x1B;
                    float v = (float)raw * lbl_805FEB60;
                    v = (v <? lbl_805FEB64) >? lbl_805FEB68;
                    self->m8[i][b] = v;
                }
                while (p < end && *p != 10)
                    p++;
                p++;
                if (!(p < end))
                    break;
            }
        }
    }
    fn_802B961C(buf, 14);
}

extern "C" DB_OVERLAY void fn_80534E80(Unk80534598_T* self, int a)
{
    fn_8053502C(self, a);
}

extern "C" DB_OVERLAY void fn_80534EA0(Unk80534EA0_T* self, char* dstA, unsigned nA, char* dstB, unsigned nB)
{
    unsigned a = self->mE290 ? fn_8040ABA0() % self->mE290 : 0;
    unsigned b = self->mE290 ? fn_8040ABA0() % self->mE290 : 0;
    if (self->mC350[a] == 1)
        b = a;
    fn_80534F64(self, dstA, nA, a, dstB, nB, b);
}

extern "C" DB_OVERLAY void fn_80534F64(Unk80534EA0_T* self, char* dstA, unsigned nA, unsigned a, char* dstB, unsigned nB, unsigned b)
{
    char* src = self->m0 + a * 11;
    if ((unsigned)fn_8040B6A0(src) >= nA) {
        fn_8040B830(dstA, src, nA - 1);
        dstA[nA - 1] = 0;
    } else {
        fn_8040B61C(dstA, src);
    }
    src = self->m55F0 + b * 14;
    if ((unsigned)fn_8040B6A0(src) >= nB) {
        fn_8040B830(dstB, src, nB - 1);
        dstB[nB - 1] = 0;
    } else {
        fn_8040B61C(dstB, src);
    }
}

extern "C" DB_OVERLAY void fn_805352B0(Unk805352B0_List* self)
{
    unsigned i = 1;
    fn_8040074C(self->m0, self->m8 << 2);
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    self->m4 = 0;
    self->mC = 0;
    self->m14 = 0;
    unsigned n = sc->fn_8007B1EC();
    for (; i < n; i++) {
        int v = sc->fn_800728BC(i);
        if (self->m4 < self->m8) {
            self->m0[self->m4] = v;
            self->m4++;
        }
    }
    self->m14 = 1;
}
