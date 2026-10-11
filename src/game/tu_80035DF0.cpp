/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80035DF0-0x80037250 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80035DF0.h"

#define TBL ((Unk80038EB4_Tbl*)fn_80038EB4())

extern "C" void fn_80035DF0(Unk80034E14* self)
{
    self->m10 = fn_800412AC(fn_8004072C(), 0x44, 0, 0, 0, 0);
}

extern "C" void fn_80035E38(Unk80034E14* self)
{
    if (self->m10 != -1)
        fn_8004181C(fn_8004072C(), 0x44, self->m10, 0, 0, 0, 0);
    self->m10 = -1;
}

extern "C" void fn_80035E94(int selfi)
{
    Unk80034E14* self = (Unk80034E14*)selfi;
    if (self->m10 != -1)
        fn_80035E38(self);
    if (self->mC != -1)
        fn_80035D94(self);
    self->m10 = -1;
    self->mC = -1;
}

extern "C" void fn_80035EEC(int self, int a, int b)
{
    if (a == 1) {
        switch (b) {
        case 0:
            fn_80039A3C(3, 1, 0);
            break;
        case 1:
            fn_80039A3C(3, 2, 0);
            fn_80039A3C(9, 1, 0);
            break;
        case 2:
            fn_80039A3C(3, 1, 0);
            fn_80039A3C(9, 1, 0);
            break;
        case 3:
            fn_80039A3C(0, 1, 0);
            fn_80039A3C(9, 1, 0);
            break;
        }
    } else if (a == 0) {
        switch (b) {
        case 0:
            fn_80039A3C(7, 1, 0);
            break;
        case 1:
            if (fn_8040ABA0() % 100 <= 0x4A)
                fn_80039A3C(5, 1, 0);
            break;
        case 2:
            if (fn_8040ABA0() % 100 <= 0x4A)
                fn_80039A3C(5, 0, 0);
            break;
        case 3:
            fn_80039A3C(5, 0, 0);
            break;
        }
    }
}

extern "C" void fn_80036064(int selfi, int ai, int b, int d)
{
    Unk80034E14* self = (Unk80034E14*)selfi;
    unsigned int a = ai;
    int t = (b == 1);
    if (a <= 1 && d <= 3 && d >= 0)
        self->v2(&TBL->m4E70[a][t][d]);
}

extern "C" int* fn_800360F4(int* self)
{
    *(const void**)((char*)self + 0x80) = lbl_80649A78;
    return self;
}

extern "C" void fn_80036108(int* self, int chrg)
{
    *(const void**)((char*)self + 0x80) = lbl_80649A78;
    if (chrg & 1)
        operator delete(self);
}

extern "C" void fn_8003613C(char* buf, const char** pp, unsigned int* pn)
{
    unsigned int n = 0;
    fn_80378D70(*pp, *pn, buf, 0x80, 0x2C, &n);
    if (n < *pn) {
        fn_80379094(buf, n, 0);
        *pp += n;
        *pp += 1;
        *pn -= 1;
        *pn -= n;
    } else {
        *pn = 0;
    }
}

extern "C" int fn_800361D8(char* buf, const char** pp, unsigned int* pn, int* out, int lo, int hi, int delim)
{
    unsigned int n = 0;
    fn_80378D70(*pp, *pn, buf, 0x80, delim, &n);
    int ok = 1;
    if (n < *pn) {
        fn_80379094(buf, n, 0);
        int v = fn_80409DAC(buf);
        if (v < lo || v > hi || v < 0)
            ok = 0;
        else
            *out = v;
        *pp += n;
        *pp += 1;
        *pn -= 1;
        *pn -= n;
    } else {
        *pn = 0;
    }
    return ok;
}

extern "C" int fn_800362B4(char* buf, int* out, const char** pp, unsigned int* pn)
{
    int r = 0;
    fn_8003613C(buf, pp, pn);
    if (fn_8040B948(buf, lbl_80616C0C)) {
        *out = 1;
        r = 1;
    } else if (fn_8040B948(buf, lbl_80616C10)) {
        *out = r;
        r = 1;
    }
    return r;
}

extern "C" int fn_8003633C(char* buf, const char** pp, unsigned int* pn)
{
    int r = 11;
    int i = 0;
    fn_8003613C(buf, pp, pn);
    for (i = 0; i <= 11; i++) {
        if (fn_8040B948(buf, lbl_80616CA0[i])) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" int fn_800363AC(char* buf, const char** pp, unsigned int* pn)
{
    int r = 2;
    int i = 0;
    fn_8003613C(buf, pp, pn);
    for (i = 0; i <= 2; i++) {
        if (fn_8040B948(buf, lbl_80616C2C[i])) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" int fn_8003641C(char* buf, unsigned char* out, const char** pp, unsigned int* pn)
{
    int ok = 1;
    int a;
    int b;
    int v0 = fn_8003633C(buf, pp, pn);
    int v1 = fn_80036538(buf);
    if (fn_800361D8(buf, pp, pn, &a, 0, 100, 0x2C)) {
        int v2 = fn_800363AC(buf, pp, pn);
        int v3 = fn_8003633C(buf, pp, pn);
        int v4 = fn_80036538(buf);
        if (fn_800361D8(buf, pp, pn, &b, 0, 100, 0xD)) {
            out[2] = ((unsigned char*)&b)[3];
            out[0] = ((unsigned char*)&a)[3];
            out[1] = v0 | (((v1 * 16) & 0xF0) | ((v2 << 6) & 0x3FC0));
            out[3] = v3 | ((v4 * 16) & 0xFF0);
        } else {
            ok = 0;
        }
    } else {
        ok = 0;
    }
    return ok;
}

extern "C" int fn_80036538(char* buf)
{
    int r = 0;
    for (int i = 0; i <= 2; i++) {
        if (fn_8040B948(buf, lbl_80616C94[i])) {
            r = i;
            break;
        }
    }
    return r;
}

extern "C" int fn_800365A4(char* buf, int* out, const char** pp, unsigned int* pn)
{
    int r = 0;
    *out = 0;
    fn_8003613C(buf, pp, pn);
    for (int i = 0; i <= 1; i++) {
        if (fn_8040B948(buf, lbl_80616C24[i])) {
            *out = i;
            r = 1;
            break;
        }
    }
    return r;
}

extern "C" int fn_80036628(char* buf, int* out, const char** pp, unsigned int* pn)
{
    int r = 0;
    fn_8003613C(buf, pp, pn);
    for (int i = 0; i <= 3; i++) {
        if (fn_8040B948(buf, lbl_80616C14[i])) {
            *out = i;
            r = 1;
            break;
        }
    }
    return r;
}

extern "C" int fn_800366A8(char* buf, int* out, const char** pp, unsigned int* pn)
{
    int r = 0;
    fn_8003613C(buf, pp, pn);
    for (int i = 0; i <= 2; i++) {
        if (fn_8040B948(buf, lbl_80616C60[i])) {
            *out = i;
            r = 1;
            break;
        }
    }
    return r;
}

extern "C" int fn_80036728(char* buf, int* out, const char** pp, unsigned int* pn)
{
    int r = 0;
    fn_8003613C(buf, pp, pn);
    for (int i = 0; i <= 4; i++) {
        if (fn_8040B948(buf, lbl_80616C6C[i])) {
            *out = i;
            r = 1;
            break;
        }
    }
    return r;
}

extern "C" int fn_800367A8(char* buf, int* out, const char** pp, unsigned int* pn)
{
    int r = 0;
    fn_8003613C(buf, pp, pn);
    for (int i = 0; i <= 4; i++) {
        if (fn_8040B948(buf, lbl_80616C80[i])) {
            *out = i;
            r = 1;
            break;
        }
    }
    return r;
}

extern "C" int fn_80036828(char* buf, int* out, const char** pp, unsigned int* pn)
{
    int r = 0;
    fn_8003613C(buf, pp, pn);
    for (int i = 0; i <= 4; i++) {
        if (fn_8040B948(buf, lbl_80616CD0[i])) {
            *out = i;
            r = 1;
            break;
        }
    }
    return r;
}

extern "C" int fn_800368A8(char* buf, int* out, const char** pp, unsigned int* pn)
{
    int r = 0;
    fn_8003613C(buf, pp, pn);
    for (int i = 0; i <= 9; i++) {
        if (fn_8040B948(buf, lbl_80616C38[i])) {
            *out = i;
            r = 1;
            break;
        }
    }
    return r;
}

extern "C" int fn_80036928(char* buf, int* out, const char** pp, unsigned int* pn)
{
    int r = 0;
    fn_8003613C(buf, pp, pn);
    for (int i = 0; i <= 2; i++) {
        if (fn_8040B948(buf, lbl_80616CE4[i])) {
            *out = i;
            r = 1;
            break;
        }
    }
    return r;
}

extern "C" int fn_800369A8(char* buf, int* out, const char** pp, unsigned int* pn)
{
    int r = 0;
    fn_8003613C(buf, pp, pn);
    for (int i = 0; i <= 2; i++) {
        if (fn_8040B948(buf, lbl_80616CF0[i])) {
            *out = i;
            r = 1;
            break;
        }
    }
    return r;
}

extern "C" int fn_80036A28(void* x, const char** pp, unsigned int* pn, int delim)
{
    const char* p = 0;
    int r = -1;
    fn_80329AEC(pp, &p, pn, 0x2C);
    if (p != 0) {
        for (int i = 0; i <= 73; i++) {
            if (fn_8040B948(p, lbl_80616E24[i])) {
                r = i;
                break;
            }
        }
    }
    return r;
}

extern "C" int fn_80036AB4(void* x, const char** pp, unsigned int* pn, int delim)
{
    const char* p = 0;
    int r = -1;
    fn_80329AEC(pp, &p, pn, 0x2C);
    if (p != 0) {
        for (int i = 0; i <= 73; i++) {
            if (fn_8040B948(p, lbl_80616CFC[i])) {
                r = i;
                break;
            }
        }
    }
    return r;
}

extern "C" int fn_80036B40(void* x, const char** pp, unsigned int* pn, int delim)
{
    const char* p = 0;
    int r = -1;
    fn_80329AEC(pp, &p, pn, 0x2C);
    if (p != 0) {
        for (int i = 0; i <= 19; i++) {
            if (fn_8040B948(p, lbl_80616E38[i])) {
                r = i;
                break;
            }
        }
    }
    return r;
}

/* fn_80036BCC / fn_80036D70 / fn_80036F14 (row parsers, 0x1A4 bytes each) are not matched: the stores come out as
 * pointer-stepped stb with constant offsets, retail keeps `stbx` with a separate index register. */
