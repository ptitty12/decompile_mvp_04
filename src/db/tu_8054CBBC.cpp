/*
 * Database overlay code, .database_codeoverlay 0x8054CBBC-0x8054FA04 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8053967C.h"

typedef Db8054CBBC_O O;

static inline int IntAt(int* b, int off)
{
    return *(int*)((char*)b + off);
}

extern char lbl_80649EC0[];
extern const float lbl_805FF260;

char* fn_800D7898(int a);
int fn_800D7C10(char* p, int a, int b);
int fn_800D7FB4(char* p, int a, float f);
int fn_800D8304(void* p, int a);
int fn_800D833C(void* p, int a);
int fn_800D8358(void* p, int a);
int fn_800D8320(void* p, int a);
int fn_80084014(int a, int b);
int fn_80083FC0(int a);

extern "C" {

/* protos */
O* fn_8054CBBC(O* o, int a, Unk8007B2B0_Screen* b);
void fn_8054CBD8(O* o, int a);
void fn_8054CC48(O* o, int i);
void fn_8054CCAC(O* o, int i, int v);
int fn_8054F5B4(int u, unsigned x, int f);
int fn_8054F5E4(int u, unsigned x, int f);
int fn_8054F614(int u, int x, int f);
int fn_8054F630(int u, int x);
int fn_8054F640(int u, int x);
int fn_8054F650(int u, int x);
int fn_8054F734(int u, int x);
int fn_8054F8D4(O* o);
int fn_8054CDC4(O* o, int v);
int fn_8054CE20(O* o, int a);
void fn_8054CF38(O* o, int a);
void fn_8054EE44(O* o);
void fn_8054F104(O* o);
void fn_8054F194(O* o);
void fn_8054F064(O* o, int a);
void fn_8054F224(O* o);
void fn_8054F3CC(O* o);
int fn_8054F658(O* o, int a);
int fn_8054F6C8(O* o, int a);
void fn_8054F900(O* o, int a, int c);
int fn_8054CCF0(O* o, int i, int k);
int fn_8054CE90(O* o, int a, int c);
void fn_8054EED4(O* o);
void fn_8054EFB0(O* o);
void fn_8054F2C4(O* o);
void fn_8054F970(O* o, int a, int c);
/* end protos */
int fn_8054F748(O* o, int i);
int fn_8054CCF0(O* o, int i, int k);
float fn_8054CF78(O* o, int i, int k);
int fn_8054E314(O* o, int i);
int fn_8054F658(O* o, int a);






int fn_800A2E6C(void* g);
int fn_800A2EFC(void* g);
int fn_800A2E90(void* g);
void fn_8053F79C(void* p);
int fn_800D7CBC(char* p, int a, int b, int c, float f);
int fn_800D7930(char* p, int a, int b, int c);
int fn_800D8108(char* p, int a, int b, int c, float f);
int fn_8057C3F8();
int fn_8057C21C();
int fn_8057C270();

DB_OVERLAY O* fn_8054CBBC(O* o, int a, Unk8007B2B0_Screen* b)
{
    o->m0 = a;
    o->m8 = lbl_80649EC0;
    o->m4 = b;
    return o;
}

DB_OVERLAY void fn_8054CBD8(O* o, int a)
{
    unsigned i = 0;
    if (a != 0)
        i = 3;
    if (i <= 7) {
        int off = i * 4;
        do {
            int t = IntAt(lbl_806025EC, off);
            i++;
            off += 4;
            o->m4->fn_8007B4A8(t, o->m0, 0);
        } while (i <= 7);
    }
}

DB_OVERLAY void fn_8054CC48(O* o, int i)
{
    if (i != -1) {
        int t = lbl_806025EC[i];
        int c = o->m4->fn_8007B3E0(t, o->m0) + 1;
        o->m4->fn_8007B4A8(t, o->m0, c);
    }
}

DB_OVERLAY void fn_8054CCAC(O* o, int i, int v)
{
    if (i != -1)
        o->m4->fn_8007B4A8(lbl_806025EC[i], o->m0, v);
}

DB_OVERLAY int fn_8054CCF0(O* o, int i, int k)
{
    int add = 0;
    if ((k == 6 || k == 8 || k == 0xB || k == 5 || k == 7)
        && ((fn_800A2EFC(lbl_80619948) == 0 && fn_800A2E90(lbl_80619948) == 0) || k == 7))
        add = (int)fn_8054CF78(o, i, k);
    if (i != -1)
        return o->m4->fn_8007B3E0(lbl_806025EC[i], o->m0) + add;
    return 0;
}

DB_OVERLAY int fn_8054CDC4(O* o, int v)
{
    int i = 0;
    do {
        if (fn_8054F748(o, i) != v) {
            i++;
            continue;
        }
        return i;
    } while (i <= 7);
    return -1;
}

DB_OVERLAY int fn_8054CE20(O* o, int a)
{
    int k = fn_8054F748(o, a);
    int v = fn_8054CCF0(o, a, k);
    char* t = fn_800D7898(fn_8054F8D4(o));
    return t != 0 ? fn_800D7C10(t, k, v) : 0;
}

DB_OVERLAY int fn_8054CE90(O* o, int a, int c)
{
    int k = fn_8054F748(o, a);
    float f = lbl_805FF260;
    if ((unsigned)(k - 2) > 1)
        f = fn_8054CF78(o, a, k);
    int v = fn_8054CCF0(o, a, k);
    char* t = fn_800D7898(fn_8054F8D4(o));
    int r;
    if (t != 0)
        r = fn_800D7CBC(t, k, v, c, f);
    else
        r = 0;
    return r;
}

DB_OVERLAY void fn_8054CF38(O* o, int a)
{
    int c = fn_80083FC0(fn_8054F658(o, a));
    o->m4->fn_8007B320(c, o->m0);
}

DB_OVERLAY void fn_8054EE44(O* o)
{
    if (fn_800A2E6C(lbl_80619948) == 0) {
        int i = fn_8054CDC4(o, 7);
        if (i != -1) {
            o->m4->fn_8007B320(0, o->m0);
            int t = fn_8057C3F8();
            fn_8054CCAC(o, i, t + fn_8054CCF0(o, i, 7));
        }
    }
}

/* near-miss: fn_8007BB28 returns a float in retail (fctiwz after the call); the shared Screen header declares int */
DB_OVERLAY void fn_8054EED4(O* o)
{
    if (fn_800A2E6C(lbl_80619948) == 0) {
        int t0 = o->m4->fn_8007B320(0, o->m0);
        int v = o->m4->fn_8007BB28(0, t0, 1);
        int i = fn_8054CDC4(o, 0xE);
        if (i != -1)
            fn_8054CCAC(o, i, v + fn_8054CCF0(o, i, 0xE));
        int j = fn_8054CDC4(o, 0xD);
        if (j != -1)
            fn_8054CCAC(o, j, v + fn_8054CCF0(o, j, 0xE));
    }
}

DB_OVERLAY void fn_8054EFB0(O* o)
{
    if (fn_800A2E6C(lbl_80619948) == 0) {
        int i = fn_8054CDC4(o, 0xC);
        if (i != -1) {
            int t0 = fn_80083FC0(0);
            int t = o->m4->fn_8007B320(t0, o->m0);
            int t1 = fn_80084014(0, 1);
            int u = ((Unk8007A4DC_Screen*)o->m4)->fn_80077238(t, t1);
            fn_8054CCAC(o, i, u + fn_8054CCF0(o, i, 0xC));
        }
    }
}

DB_OVERLAY void fn_8054F064(O* o, int a)
{
    if (fn_800A2E6C(lbl_80619948) == 0) {
        int i = fn_8054CDC4(o, a);
        if (i != -1) {
            fn_8054CCAC(o, i, (int)fn_8054CF78(o, i, a) + fn_8054CCF0(o, i, a));
        }
    }
}

DB_OVERLAY void fn_8054F104(O* o)
{
    if (fn_800A2E6C(lbl_80619948) == 0) {
        int i = fn_8054CDC4(o, 9);
        if (i != -1) {
            o->m4->fn_8007B320(0, o->m0);
            int t = fn_8057C21C();
            fn_8054CCAC(o, i, t + fn_8054CCF0(o, i, 9));
        }
    }
}

DB_OVERLAY void fn_8054F194(O* o)
{
    if (fn_800A2E6C(lbl_80619948) == 0) {
        int i = fn_8054CDC4(o, 0xA);
        if (i != -1) {
            o->m4->fn_8007B320(0, o->m0);
            int t = fn_8057C270();
            fn_8054CCAC(o, i, t + fn_8054CCF0(o, i, 0xA));
        }
    }
}

DB_OVERLAY void fn_8054F224(O* o)
{
    if (fn_800A2E6C(lbl_80619948) == 0) {
        int i = 0;
        do {
            char* t = fn_800D7898(fn_8054F8D4(o));
            if (t != 0 && fn_800D8304(t, fn_8054F748(o, i)) != 0 && fn_8054E314(o, i) != 0)
                fn_8054CC48(o, i);
            i++;
        } while (i <= 7);
    }
}

DB_OVERLAY void fn_8054F2C4(O* o)
{
    if (fn_800A2E6C(lbl_80619948) == 0) {
        int i = 0;
        fn_8053F79C(*(void**)((char*)lbl_80619948 + 0x5C));
        do {
            char* t = fn_800D7898(fn_8054F8D4(o));
            int r = fn_8054F748(o, i);
            if (t != 0 && fn_800D8320(t, r) != 0 && fn_8054E314(o, i) != 0)
                fn_8054CC48(o, i);
            i++;
        } while (i <= 7);
        fn_8054EE44(o);
        fn_8054EED4(o);
        fn_8054EFB0(o);
        fn_8054F104(o);
        fn_8054F194(o);
        fn_8054F064(o, 2);
        fn_8054F064(o, 0);
        fn_8054F064(o, 0x10);
        fn_8054F064(o, 0x11);
    }
}

DB_OVERLAY void fn_8054F3CC(O* o)
{
    if (fn_800A2E6C(lbl_80619948) == 0) {
        int i = 0;
        do {
            char* t = fn_800D7898(fn_8054F8D4(o));
            if (t != 0 && fn_800D833C(t, fn_8054F748(o, i)) != 0 && fn_8054E314(o, i) != 0)
                fn_8054CC48(o, i);
            i++;
        } while (i <= 7);
    }
}

DB_OVERLAY int fn_8054F5B4(int u, unsigned x, int f)
{
    int a = 0xF;
    if (f != 0)
        a = 0;
    unsigned m = 6;
    if (f != 0)
        m = 7;
    return a + x % m;
}

DB_OVERLAY int fn_8054F5E4(int u, unsigned x, int f)
{
    int a = 0x15;
    if (f != 0)
        a = 7;
    unsigned m = 6;
    if (f != 0)
        m = 4;
    return a + x % m;
}

DB_OVERLAY int fn_8054F614(int u, int x, int f)
{
    int a = 0x1B;
    if (f != 0)
        a = 0xB;
    return a + (x & 3);
}

DB_OVERLAY int fn_8054F630(int u, int x)
{
    return (x ^ 3) == 0;
}

DB_OVERLAY int fn_8054F640(int u, int x)
{
    return (x ^ 4) == 0;
}

DB_OVERLAY int fn_8054F650(int u, int x)
{
    return 0;
}

DB_OVERLAY int fn_8054F658(O* o, int a)
{
    if (fn_8054F630((int)o, a) == 1)
        return 1;
    if (fn_8054F640((int)o, a) == 1)
        return 2;
    if (fn_8054F650((int)o, a) == 1)
        return 3;
    return 0;
}

DB_OVERLAY int fn_8054F6C8(O* o, int a)
{
    int r = 0;
    if (fn_8054F630((int)o, a) != 0 || fn_8054F640((int)o, a) != 0 || fn_8054F650((int)o, a) != 0)
        r = 1;
    return r;
}

DB_OVERLAY int fn_8054F734(int u, int x)
{
    return x <= 2;
}

DB_OVERLAY int fn_8054F8D4(O* o)
{
    return o->m4->fn_8007B3E0(0x10, o->m0);
}

DB_OVERLAY void fn_8054F900(O* o, int a, int c)
{
    char* t = fn_800D7898(fn_8054F8D4(o));
    if (t != 0) {
        int k = fn_8054F748(o, a);
        fn_800D7930(t, k, c, fn_8054F658(o, a));
    }
}

/* near-miss: retail evaluates the float fn_8054CF78 first and keeps it in f31 across fn_8054CCF0; ours calls it last */
DB_OVERLAY void fn_8054F970(O* o, int a, int c)
{
    char* t = fn_800D7898(fn_8054F8D4(o));
    if (t != 0) {
        int k = fn_8054F748(o, a);
        fn_800D8108(t, k, fn_8054CCF0(o, a, k), c, fn_8054CF78(o, a, k));
    }
}

}
