/*
 * SN libgcc (GCC 2.95.3 libgcc2.c DI-mode helpers and terminate support; one object
 * per function in the original archive),
 * .text 0x80413940-0x80414F30 (code-only unit, 11 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 *
 * Flags: fn_804139C0 / fn_80413F84 / __udivdi3 / __umoddi3 inline __udivmoddi4 with the table-based
 * count_leading_zeros, which reads __clz_tab (a 256-byte .sdata2 table, one private copy per original
 * object: lbl_806F0880/0980/0A80/0B80) through r2 (`li rX,sym@sda21`). That needs -G >= 256 (-O2 -G 1024
 * matches all four; -G0 and the default -G8 cannot make a 256-byte table small data). The eh_context
 * pair below is reached through lis/addi (.bss), so its externs are incomplete types.
 */

typedef int Wtype;
typedef unsigned int UWtype;
typedef long long DWtype;
typedef unsigned long long UDWtype;
typedef unsigned char UQItype;
typedef unsigned int USItype;
typedef int word_type;

typedef struct {
    Wtype high;
    Wtype low;
} DWstruct;

typedef union {
    DWstruct s;
    DWtype ll;
} DWunion;

extern const UQItype lbl_806F0880[256];
extern const UQItype lbl_806F0980[256];
extern const UQItype lbl_806F0A80[256];
extern const UQItype lbl_806F0B80[256];

#define W_TYPE_SIZE 32
#define __BITS4 (W_TYPE_SIZE / 4)
#define __ll_B ((UWtype)1 << (W_TYPE_SIZE / 2))
#define __ll_lowpart(t) ((UWtype)(t) & (__ll_B - 1))
#define __ll_highpart(t) ((UWtype)(t) >> (W_TYPE_SIZE / 2))

#define __udiv_qrnnd_c(q, r, n1, n0, d)                                                             \
    do {                                                                                            \
        UWtype __d1, __d0, __q1, __q0;                                                              \
        UWtype __r1, __r0, __m;                                                                     \
        __d1 = __ll_highpart(d);                                                                    \
        __d0 = __ll_lowpart(d);                                                                     \
                                                                                                    \
        __r1 = (n1) % __d1;                                                                         \
        __q1 = (n1) / __d1;                                                                         \
        __m = (UWtype)__q1 * __d0;                                                                  \
        __r1 = __r1 * __ll_B | __ll_highpart(n0);                                                   \
        if (__r1 < __m) {                                                                           \
            __q1--, __r1 += (d);                                                                    \
            if (__r1 >= (d))                                                                        \
                if (__r1 < __m)                                                                     \
                    __q1--, __r1 += (d);                                                            \
        }                                                                                           \
        __r1 -= __m;                                                                                \
                                                                                                    \
        __r0 = __r1 % __d1;                                                                         \
        __q0 = __r1 / __d1;                                                                         \
        __m = (UWtype)__q0 * __d0;                                                                  \
        __r0 = __r0 * __ll_B | __ll_lowpart(n0);                                                    \
        if (__r0 < __m) {                                                                           \
            __q0--, __r0 += (d);                                                                    \
            if (__r0 >= (d))                                                                        \
                if (__r0 < __m)                                                                     \
                    __q0--, __r0 += (d);                                                            \
        }                                                                                           \
        __r0 -= __m;                                                                                \
                                                                                                    \
        (q) = (UWtype)__q1 * __ll_B | __q0;                                                         \
        (r) = __r0;                                                                                 \
    } while (0)

#define udiv_qrnnd(q, r, n1, n0, d) __udiv_qrnnd_c(q, r, n1, n0, d)

#define count_leading_zeros(count, x, __clz_tab)                                                               \
    do {                                                                                            \
        UWtype __xr = (x);                                                                          \
        UWtype __a;                                                                                 \
                                                                                                    \
        __a = __xr < ((UWtype)1 << 2 * __BITS4) ? (__xr < ((UWtype)1 << __BITS4) ? 0 : __BITS4)     \
                                                : (__xr < ((UWtype)1 << 3 * __BITS4) ? 2 * __BITS4 : 3 * __BITS4); \
        (count) = W_TYPE_SIZE - (__clz_tab[__xr >> __a] + __a);                                     \
    } while (0)

#define umul_ppmm(w1, w0, u, v)                                                                     \
    do {                                                                                            \
        UWtype __x0, __x1, __x2, __x3;                                                              \
        UWtype __ul, __vl, __uh, __vh;                                                              \
                                                                                                    \
        __ul = __ll_lowpart(u);                                                                     \
        __uh = __ll_highpart(u);                                                                    \
        __vl = __ll_lowpart(v);                                                                     \
        __vh = __ll_highpart(v);                                                                    \
                                                                                                    \
        __x0 = (UWtype)__ul * __vl;                                                                 \
        __x1 = (UWtype)__ul * __vh;                                                                 \
        __x2 = (UWtype)__uh * __vl;                                                                 \
        __x3 = (UWtype)__uh * __vh;                                                                 \
                                                                                                    \
        __x1 += __ll_highpart(__x0);                                                                \
        __x1 += __x2;                                                                               \
        if (__x1 < __x2)                                                                            \
            __x3 += __ll_B;                                                                         \
                                                                                                    \
        (w1) = __x3 + __ll_highpart(__x1);                                                          \
        (w0) = __ll_lowpart(__x1) * __ll_B + __ll_lowpart(__x0);                                    \
    } while (0)

#define sub_ddmmss(sh, sl, ah, al, bh, bl)                                                          \
    do {                                                                                            \
        UWtype __x;                                                                                 \
        __x = (al) - (bl);                                                                          \
        (sh) = (ah) - (bh) - (__x > (al));                                                          \
        (sl) = __x;                                                                                 \
    } while (0)

#define UDIVMODDI4(NAME, CLZTAB) \
static inline UDWtype NAME(UDWtype n, UDWtype d, UDWtype *rp) \
{ \
    DWunion ww; \
    DWunion nn, dd; \
    DWunion rr; \
    UWtype d0, d1, n0, n1, n2; \
    UWtype q0, q1; \
    UWtype b, bm; \
    nn.ll = n; \
    dd.ll = d; \
    d0 = dd.s.low; \
    d1 = dd.s.high; \
    n0 = nn.s.low; \
    n1 = nn.s.high; \
    if (d1 == 0) { \
        if (d0 > n1) { \
            count_leading_zeros(bm, d0, CLZTAB); \
            if (bm != 0) { \
                d0 = d0 << bm; \
                n1 = (n1 << bm) | (n0 >> (W_TYPE_SIZE - bm)); \
                n0 = n0 << bm; \
            } \
            udiv_qrnnd(q0, n0, n1, n0, d0); \
            q1 = 0; \
        } else { \
            if (d0 == 0) \
                d0 = 1 / d0; \
            count_leading_zeros(bm, d0, CLZTAB); \
            if (bm == 0) { \
                n1 -= d0; \
                q1 = 1; \
            } else { \
                b = W_TYPE_SIZE - bm; \
                d0 = d0 << bm; \
                n2 = n1 >> b; \
                n1 = (n1 << bm) | (n0 >> b); \
                n0 = n0 << bm; \
                udiv_qrnnd(q1, n1, n2, n1, d0); \
            } \
            udiv_qrnnd(q0, n0, n1, n0, d0); \
        } \
        if (rp != 0) { \
            rr.s.low = n0 >> bm; \
            rr.s.high = 0; \
            *rp = rr.ll; \
        } \
    } else { \
        if (d1 > n1) { \
            q0 = 0; \
            q1 = 0; \
            if (rp != 0) { \
                rr.s.low = n0; \
                rr.s.high = n1; \
                *rp = rr.ll; \
            } \
        } else { \
            count_leading_zeros(bm, d1, CLZTAB); \
            if (bm == 0) { \
                if (n1 > d1 || n0 >= d0) { \
                    q0 = 1; \
                    sub_ddmmss(n1, n0, n1, n0, d1, d0); \
                } else \
                    q0 = 0; \
                q1 = 0; \
                if (rp != 0) { \
                    rr.s.low = n0; \
                    rr.s.high = n1; \
                    *rp = rr.ll; \
                } \
            } else { \
                UWtype m1, m0; \
                b = W_TYPE_SIZE - bm; \
                d1 = (d1 << bm) | (d0 >> b); \
                d0 = d0 << bm; \
                n2 = n1 >> b; \
                n1 = (n1 << bm) | (n0 >> b); \
                n0 = n0 << bm; \
                udiv_qrnnd(q0, n1, n2, n1, d1); \
                umul_ppmm(m1, m0, q0, d0); \
                if (m1 > n1 || (m1 == n1 && m0 > n0)) { \
                    q0--; \
                    sub_ddmmss(m1, m0, m1, m0, d1, d0); \
                } \
                q1 = 0; \
                if (rp != 0) { \
                    sub_ddmmss(n1, n0, n1, n0, m1, m0); \
                    rr.s.low = (n1 << b) | (n0 >> bm); \
                    rr.s.high = n1 >> bm; \
                    *rp = rr.ll; \
                } \
            } \
        } \
    } \
    ww.s.low = q0; \
    ww.s.high = q1; \
    return ww.ll; \
}


UDIVMODDI4(udivmoddi4_0880, lbl_806F0880)
UDIVMODDI4(udivmoddi4_0980, lbl_806F0980)
UDIVMODDI4(udivmoddi4_0A80, lbl_806F0A80)
UDIVMODDI4(udivmoddi4_0B80, lbl_806F0B80)

static inline DWtype __negdi2(DWtype u)
{
    DWunion w;
    DWunion uu;

    uu.ll = u;

    w.s.low = -uu.s.low;
    w.s.high = -uu.s.high - ((UWtype)w.s.low > 0);

    return w.ll;
}

/* libgcc2.c L_ashldi3 */
DWtype fn_80413940(DWtype u, word_type b)
{
    DWunion w;
    word_type bm;
    DWunion uu;

    if (b == 0)
        return u;

    uu.ll = u;

    bm = (sizeof(Wtype) * 8) - b;
    if (bm <= 0) {
        w.s.low = 0;
        w.s.high = (UWtype)uu.s.low << -bm;
    } else {
        UWtype carries = (UWtype)uu.s.low >> bm;
        w.s.low = (UWtype)uu.s.low << b;
        w.s.high = ((UWtype)uu.s.high << b) | carries;
    }

    return w.ll;
}

/* libgcc2.c L_ashrdi3 */
DWtype fn_80413980(DWtype u, word_type b)
{
    DWunion w;
    word_type bm;
    DWunion uu;

    if (b == 0)
        return u;

    uu.ll = u;

    bm = (sizeof(Wtype) * 8) - b;
    if (bm <= 0) {
        /* w.s.high = 1..1 or 0..0 */
        w.s.high = uu.s.high >> (sizeof(Wtype) * 8 - 1);
        w.s.low = uu.s.high >> -bm;
    } else {
        UWtype carries = (UWtype)uu.s.high << bm;
        w.s.high = uu.s.high >> b;
        w.s.low = ((UWtype)uu.s.low >> b) | carries;
    }

    return w.ll;
}

DWtype fn_804139C0(DWtype u, DWtype v)
{
    word_type c = 0;
    DWunion uu, vv;
    DWtype w;

    uu.ll = u;
    vv.ll = v;

    if (uu.s.high < 0)
        c = ~c, uu.ll = __negdi2(uu.ll);
    if (vv.s.high < 0)
        c = ~c, vv.ll = __negdi2(vv.ll);

    w = udivmoddi4_0880(uu.ll, vv.ll, (UDWtype *)0);
    if (c)
        w = __negdi2(w);

    return w;
}

/* libgcc2.c L_lshrdi3 */
DWtype fn_80413F44(DWtype u, word_type b)
{
    DWunion w;
    word_type bm;
    DWunion uu;

    if (b == 0)
        return u;

    uu.ll = u;

    bm = (sizeof(Wtype) * 8) - b;
    if (bm <= 0) {
        w.s.high = 0;
        w.s.low = (UWtype)uu.s.high >> -bm;
    } else {
        UWtype carries = (UWtype)uu.s.high << bm;
        w.s.high = (UWtype)uu.s.high >> b;
        w.s.low = ((UWtype)uu.s.low >> b) | carries;
    }

    return w.ll;
}

DWtype fn_80413F84(DWtype u, DWtype v)
{
    word_type c = 0;
    DWunion uu, vv;
    DWtype w;

    uu.ll = u;
    vv.ll = v;

    if (uu.s.high < 0)
        c = ~c, uu.ll = __negdi2(uu.ll);
    if (vv.s.high < 0)
        vv.ll = __negdi2(vv.ll);

    (void)udivmoddi4_0980(uu.ll, vv.ll, (UDWtype *)&w);
    if (c)
        w = __negdi2(w);

    return w;
}

UDWtype __udivdi3(UDWtype n, UDWtype d)
{
    return udivmoddi4_0A80(n, d, (UDWtype *)0);
}

UDWtype __umoddi3(UDWtype u, UDWtype v)
{
    UDWtype w;

    (void)udivmoddi4_0B80(u, v, &w);

    return w;
}

/* libgcc2.c L_eh: static exception context (eh_context_initialize, eh_context_static).
 * The externs are incomplete arrays so that they stay out of small data under -G 1024. */
struct eh_context {
    void *dynamic_handler_chain;
    void *top_elt;
    void *m8;
    void *mC;
};

extern int memset();
extern struct eh_context *(*lbl_8062F918[])(void);
extern struct eh_context lbl_806C37F4[];
extern int lbl_806C3804[];
extern void *lbl_806C3808[];

struct eh_context *fn_80414EC4(void);

struct eh_context *fn_80414E90(void)
{
    lbl_8062F918[0] = &fn_80414EC4;
    return (*lbl_8062F918[0])();
}

struct eh_context *fn_80414EC4(void)
{
    if (!lbl_806C3804[0]) {
        lbl_806C3804[0] = 1;
        memset(lbl_806C37F4, 0, sizeof(struct eh_context));
        lbl_806C37F4->top_elt = lbl_806C3808;
    }
    return lbl_806C37F4;
}
