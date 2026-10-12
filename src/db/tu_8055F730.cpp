/*
 * Database overlay code, .database_codeoverlay 0x8055F730-0x80563954 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8054FA04.h"

struct Db8055FCF4_S {
    int* m0;
};

/* Int list: data pointer and used count (see Unk805352B0_List). */
enum Db8055F9B0_E { Db8055F9B0_Neg = -1, Db8055F9B0_Lo = 1, Db8055F9B0_Hi = 5 };
struct Db8055F7B8_List {
    int* m0;
    unsigned m4;
    int At(unsigned i)
    {
        int o = i * 4;
        return *(int*)((char*)m0 + o);
    }
};

extern Unk8007A4DC_Screen* lbl_8061930C;
extern "C" int fn_8055FD00(int x);
extern "C" int fn_8055F7B8(Db8055F7B8_List* l, int x);
extern "C" int fn_8055F848(Db8055F7B8_List* l, int x);
extern "C" int fn_8055F8D8(Db8055F7B8_List* l, int x);
extern "C" int fn_8055F9B0(Db8055F7B8_List* l, int x);
extern "C" int fn_8055FB50(Db8055F7B8_List* l, int x);
extern "C" int fn_8055FCF4(Db8055FCF4_S* s);

extern "C" DB_OVERLAY int fn_8055F730(Db8055F7B8_List* l, int x, int kind)
{
    switch (kind) {
    case 0:
        return fn_8055F7B8(l, x);
    case 1:
        return fn_8055F848(l, x);
    case 2:
        return fn_8055F8D8(l, x);
    case 3:
        return fn_8055F9B0(l, x);
    case 4:
        return fn_8055FB50(l, x);
    case 5:
        return fn_8055FCF4((Db8055FCF4_S*)l);
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8055F7B8(Db8055F7B8_List* l, int x)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    int v = fn_8055FD00(x);
    unsigned i;
    for (i = 0; i < l->m4; i++) {
        int e = l->At(i);
        if (sc->fn_8007A6A0(5, e) == v)
            return e;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8055F848(Db8055F7B8_List* l, int x)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    int v = fn_8055FD00(x);
    unsigned i;
    for (i = 0; i < l->m4; i++) {
        int e = l->At(i);
        if (sc->fn_8007A6A0(6, e) == v)
            return e;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8055F8D8(Db8055F7B8_List* l, int x)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    int a;
    int b;
    if ((unsigned)(x - 1) <= 4) {
        a = 12;
        b = 13;
    } else if (x == 6) {
        a = 8;
        b = 7;
    } else if (x == 7) {
        a = 8;
        b = 8;
    } else if (x == 8) {
        a = 6;
        b = 7;
    } else {
        return 0;
    }
    unsigned i;
    for (i = 0; i < l->m4; i++) {
        int e = l->At(i);
        int v = sc->fn_8007A6A0(6, e);
        if (v == a || v == b)
            return e;
    }
    return 0;
}

/* near-miss: tree, both loops and the register split match except the callee-saved assignment (sc r25 vs r26,
 * list r28 vs r27) and one insn in the 6..8 arm (103 vs 104 insns). Tried shared and per-arm a/b, split case bodies,
 * enum-typed index. */
extern "C" DB_OVERLAY int fn_8055F9B0(Db8055F7B8_List* l, int x)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    int a;
    int b;
    if ((unsigned)(x - 1) <= 4) {
        switch ((Db8055F9B0_E)x) {
        case 1:
            a = 4;
            b = 4;
            break;
        case 2:
            a = 4;
            b = 4;
            break;
        case 3:
            a = 5;
            b = 4;
            break;
        case 4:
            a = 3;
            b = 5;
            break;
        case 5:
            a = 3;
            b = 4;
            break;
        default:
            return 0;
        }
        unsigned i;
        for (i = 0; i < l->m4; i++) {
            int e = l->At(i);
            int v5 = sc->fn_8007A6A0(5, e);
            int v6 = sc->fn_8007A6A0(6, e);
            if (v5 == a || v5 == b || v6 == a || v6 == b)
                return e;
        }
    } else if ((unsigned)(x - 6) <= 2) {
        switch (x) {
        case 6:
        case 8:
            a = 13;
            break;
        case 7:
            a = 6;
            break;
        default:
            return 0;
        }
        unsigned i;
        for (i = 0; i < l->m4; i++) {
            int e = l->At(i);
            if (sc->fn_8007A6A0(6, e) == a)
                return e;
        }
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8055FCF4(Db8055FCF4_S* s)
{
    return *s->m0;
}

extern "C" DB_OVERLAY int fn_8055FD00(int x)
{
    switch (x) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    }
    return 1;
}

extern "C" DB_OVERLAY int fn_8055FD8C(int unused, Db8055F7B8_List* l)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    unsigned i;
    for (i = 0; i < l->m4; i++) {
        int e = l->At(i);
        if (sc->fn_8007A6A0(6, e) == 9)
            return e;
    }
    return 0;
}
