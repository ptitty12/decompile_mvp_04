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
extern "C" int fn_8055FB50(Db8055F7B8_List* l, int x);

#include "game/clampiter.h"
extern "C" void fn_80535F5C(Unk805352B0_List* self, int a);
extern "C" void fn_80079564(Unk8007A4DC_Screen* sc, int v, int z);
extern char lbl_8065C1B0[];
extern "C" void fn_80563628(int a, int b, int c);
int fn_8007F724(Unk8007F198_A* self, int a, int b, int c, int d);
extern "C" void fn_80563740(int a, int b);
extern "C" void fn_80563140(int a, int b);
int fn_8007F6C4(Unk8007F198_A* self, int a, int b, int c);
void fn_8007F61C(Unk8007F198_A* self, int a, int b, int c);
void fn_8007F330(Unk8007F198_A* self, int a, int b);
extern Unk80538DD8_G* lbl_80619948;
extern float lbl_805FF7C4;
extern float lbl_805FF7D8;
extern float lbl_805FF7DC;
extern "C" int fn_80546B18(void* self, int a, int b);
extern "C" int fn_80546CA8(void* self, int a, int b);
extern "C" void fn_80546A24(void* self, int a, float f, int b, int c);
extern "C" void fn_80563F3C(void* m3c, int a, int b, float* f, int* z, int* o, int x, int y);
extern "C" float fn_80560630(void* self, int i);
void fn_8007F29C(Unk8007F198_A* self, int a, int b);
int fn_8007F5BC(Unk8007F198_A* self, int a, int b, int c, int d);
unsigned fn_8007F198(Unk8007F198_A* self, int x);
int fn_8007F24C(Unk8007F198_A* self, int a, int x);
int fn_8007F674(Unk8007F198_A* self, int a, int x);
int fn_80083FC0(int a);
extern "C" int fn_800A2AE8(Unk80538DD8_G* g);
struct Db8055FF28_Obj {
    char pad0[0x107E8];
    unsigned m107E8;
};
struct Db8055FF28_G {
    char pad0[0x3C];
    void* m3C;
};
/* forward declarations (definitions are in address order) */
extern "C" int fn_8055F730(Db8055F7B8_List* l, int x, int kind);
extern "C" int fn_8055F7B8(Db8055F7B8_List* l, int x);
extern "C" int fn_8055F848(Db8055F7B8_List* l, int x);
extern "C" int fn_8055F8D8(Db8055F7B8_List* l, int x);
extern "C" int fn_8055F9B0(Db8055F7B8_List* l, int x);
extern "C" int fn_8055FCF4(Db8055FCF4_S* s);
extern "C" int fn_8055FD00(int x);
extern "C" int fn_8055FD8C(int unused, Db8055F7B8_List* l);
extern "C" void fn_8055FF28(int a, Db8055FF28_Obj* self, int b);
extern "C" void fn_80560010(int x, int k);
extern "C" int fn_805600F8(int s, int id);
extern "C" int fn_8056087C(void* self);
extern "C" void fn_80560314(int a, int b, int c);
extern "C" void fn_80539020(Unk805352B0_List* self, int x);
inline void Db805625F8_Append(Unk805352B0_List* dst, Unk80535650_Tmp* src)
{
    unsigned i;
    for (i = 0; i < src->Count(); i++)
        dst->Push(src->At(i));
    dst->m14 = 1;
}
extern "C" void fn_805362AC(Unk805352B0_List* self, int mode);
extern "C" void fn_80538EC4(Unk805352B0_List* self, int x, int y);
extern "C" void fn_80539128(Unk805352B0_List* self, Unk805352B0_List* out);
extern "C" int fn_80077BC4(void* g, int a);

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

extern "C" DB_OVERLAY int fn_8055FB50(Db8055F7B8_List* l, int x)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    int e;
    if (x == 2) {
        unsigned i;
        for (i = 0; i < l->m4; i++) {
            int e2 = l->At(i);
            int v5 = sc->fn_8007A6A0(5, e2);
            int v6 = sc->fn_8007A6A0(6, e2);
            if ((unsigned)(v5 - 6) <= 2 || v6 == 6 || v6 == 7 || v6 == 8)
                return e2;
        }
    } else if (x == 3 || x == 5 || x == 4 || x == 1) {
        unsigned i;
        for (i = 0; i < l->m4; i++) {
            e = l->At(i);
            if (sc->fn_8007A6A0(9, e) == 0)
                goto found;
        }
    } else if (x == 6 || x == 8) {
        return *l->m0;
    } else if (x == 7) {
        unsigned i;
        for (i = 0; i < l->m4; i++) {
            e = l->At(i);
            if (sc->fn_8007A6A0(6, e) == 13)
                goto found;
        }
    }
    goto out;
found:
    return e;
out:
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

extern "C" DB_OVERLAY int fn_8055FE10(int unused, Db8055F7B8_List* l)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    int best = 0;
    int bestv = 0;
    unsigned i = 0;
    for (; i < l->m4; i++) {
        int e = l->At(i);
        int a = (sc->fn_8007AA84(1, e, 0) * 2 + sc->fn_8007AA84(1, e, 1) * 4) / 6;
        int b = (sc->fn_8007AA84(0, e, 0) * 2 + sc->fn_8007AA84(0, e, 1) * 4) / 6;
        int t = a + b;
        if (best == 0 || t > bestv) {
            best = e;
            bestv = t;
        }
    }
    return best;
}

extern "C" DB_OVERLAY void fn_8055FF28(int a, Db8055FF28_Obj* self, int b)
{
    Db8055FF28_G* g = (Db8055FF28_G*)lbl_80619948;
    unsigned n = self->m107E8;
    void* m3c = g->m3C;
    unsigned i = 0;
    for (; i < n; i++) {
        int p = fn_80546B18(self, b, i);
        int q = fn_80546CA8(self, b, i);
        if (q == 0) {
            float f = lbl_805FF7C4;
            int z = q;
            int o;
            int w = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B320(0, a);
            fn_80563F3C(m3c, w, p, &f, &z, &o, 1, 0);
            fn_80546A24(self, p, f, z, 2);
        }
    }
}

/* near-miss: callee-saved r30/r31 swapped (s and id) */
extern "C" DB_OVERLAY void fn_80560010(int x, int k)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    Unk8006A138_It<3> it(k);
    int cur = k;
    if (cur <= 3) {
        do {
            unsigned j = 0;
            int id0 = fn_80083FC0(cur);
            int s = ((Unk8007B2B0_Screen*)sc)->fn_8007B320(id0, x);
            while (j < fn_8007F198((Unk8007F198_A*)sc, s)) {
                int id = fn_8007F24C((Unk8007F198_A*)sc, s, (unsigned char)j);
                int v = sc->fn_8007A6A0(0x1E, id);
                if (v == 0 || v == 0x31 || fn_805600F8(s, id) == 0)
                    j++;
            }
            cur = it.Next();
        } while (cur <= 3);
    }
}

extern "C" DB_OVERLAY int fn_805600F8(int s, int id)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    int r = 0;
    int w = fn_800A2AE8(lbl_80619948);
    int v = sc->fn_8007A6A0(0x1F, id);
    if (v > 14) {
        if (v <= 0x27) {
            if ((unsigned)fn_8007F674((Unk8007F198_A*)sc, s, 0) <= 1) {
                r = 1;
                fn_8007F29C((Unk8007F198_A*)sc, s, id);
                fn_8007F5BC((Unk8007F198_A*)sc, s, 0, id, w);
            }
        } else {
            if ((unsigned)fn_8007F674((Unk8007F198_A*)sc, s, 1) <= 1) {
                r = 1;
                fn_8007F29C((Unk8007F198_A*)sc, s, id);
                fn_8007F5BC((Unk8007F198_A*)sc, s, 1, id, w);
            }
        }
    }
    return r;
}

extern "C" DB_OVERLAY void fn_805601F0(int x, int k)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    Unk8006A138_It<3> it(k);
    int cur = k;
    if (cur <= 3) {
        do {
            int h = 0;
            int g = ((Unk8007B2B0_Screen*)sc)->fn_8007B320(fn_80083FC0(cur), x);
            int found;
            do {
                do {
                    found = 0;
                    unsigned n = fn_8007F674((Unk8007F198_A*)sc, g, h);
                    unsigned i = 0;
                    if (i < n) {
                        do {
                            int v = fn_8007F6C4((Unk8007F198_A*)sc, g, h, i);
                            if (fn_8007F724((Unk8007F198_A*)sc, g, h, v, fn_800A2AE8(lbl_80619948)) <= 0) {
                                fn_80560314(g, h, i);
                                found = 1;
                                break;
                            }
                            i++;
                        } while (i < n);
                    }
                } while (found);
                h++;
            } while (h <= 1);
            cur = it.Next();
        } while (cur <= 3);
    }
}

/* near-miss: 6 slots (retail copies the index zero into the counter: li r30,0 / mr r31,r30; ours uses two li) */
extern "C" DB_OVERLAY int fn_8056087C(void* self)
{
    float a = lbl_805FF7D8;
    float best = lbl_805FF7DC;
    int idx = 0;
    unsigned i = 0;
    for (; i <= 8; i++) {
        a = fn_80560630(self, i);
        if (!(best <= a)) {
            best = a;
            idx = i;
        }
    }
    return idx;
}

extern "C" DB_OVERLAY int fn_80560900(int x)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    Unk80535650_Tmp t;
    int buf[0xFA];
    Unk80535650_Tmp* q = &t;

    q->C1(buf, 0xFA);
    q->C2();
    q->C3(lbl_8065C1B0);

    fn_80535F5C((Unk805352B0_List*)q, x);

    int n = q->m4;
    int i = 0;
    for (; i < n; i++) {
        int v = t.m0[q->mC];
        if (sc->fn_8007A6A0(0x19, v) == 0) {
            q->vp = lbl_8064A550;
            return 1;
        }
        q->mC = (q->mC + 1) % q->m4;
    }
    t.vp = lbl_8064A550;
    return 0;
}

extern "C" DB_OVERLAY void fn_80560A24(int x)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    Unk80535650_Tmp t;
    int buf[0xFA];
    Unk80535650_Tmp* q = &t;
    q->C1(buf, 0xFA);
    q->C2();
    q->C3(lbl_8065C1B0);
    fn_80535F5C((Unk805352B0_List*)q, x);
    int n = q->m4;
    if (n > 0) {
        int k = n;
        do {
            int v = t.m0[q->mC];
            if (sc->fn_8007A6A0(0x19, v) == 0)
                fn_80079564(sc, v, 0);
            q->mC = (q->mC + 1) % q->m4;
            k--;
        } while (k != 0);
    }
    t.vp = lbl_8064A550;
}

extern "C" DB_OVERLAY void fn_805625F8(int x, Unk805352B0_List* self, int kind)
{
    Unk8007B2B0_Screen* sc = (Unk8007B2B0_Screen*)lbl_8061930C;
    Unk80535650_Tmp t;
    int buf[0x28];
    Unk80535650_Tmp* q = &t;
    q->C1(buf, 0x28);
    q->C2();
    q->C3(lbl_8064A4C8);
    if (kind == 0) {
        fn_80539020(self, x);
    } else if (kind == 1) {
        int s = sc->fn_80078A38(x);
        int h = sc->fn_80075948(x);
        int g1 = sc->fn_8007B320(1, h);
        int g2 = sc->fn_8007B320(2, h);
        int g3 = sc->fn_8007B320(3, h);
        fn_8040074C(self->m0, self->m8 << 2);
        self->m4 = 0;
        self->mC = 0;
        self->m14 = 0;
        if (s <= 0) {
            fn_80539020((Unk805352B0_List*)&t, g1);
            Db805625F8_Append(self, &t);
        }
        if (s <= 1) {
            fn_80539020((Unk805352B0_List*)&t, g2);
            Db805625F8_Append(self, &t);
        }
        if (s <= 2) {
            fn_80539020((Unk805352B0_List*)&t, g3);
            Db805625F8_Append(self, &t);
        }
    }
    t.D();
}

/* near-miss: one store differs (the final vptr store of the found branch: retail writes it frame-relative, 24(r1); ours 16(r29));
 * tried t.D()/q->D()/references/explicit stores. */
extern "C" DB_OVERLAY int fn_80562BC8(int x, int y)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    int r = 0;
    int kind;
    for (kind = 0; kind <= 1; kind++) {
        Unk80535650_Tmp t;
        int buf[0x28];
        Unk80535650_Tmp* q = &t;
        q->C1(buf, 0x28);
        q->C2();
        q->C3(lbl_8064A4C8);
        fn_805625F8(x, (Unk805352B0_List*)q, kind);
        fn_80539128((Unk805352B0_List*)q, 0);
        if (q->Count() == 0) {
            q->D();
            continue;
        }
        fn_805362AC((Unk805352B0_List*)q, 1);
        unsigned i;
        for (i = 0; i < q->Count(); i++) {
            if (y == (sc->fn_8007A6A0(5, t.At(i)) == 0)) {
                r = t.At(i);
                break;
            }
        }
        if (r == 0)
            r = *t.m0;
        t.D();
        break;
    }
    if (r != 0) {
        int g = fn_80077BC4(sc, r);
        fn_8007F29C((Unk8007F198_A*)sc, g, r);
        if (g != x && fn_8007F198((Unk8007F198_A*)sc, x) > 0x18) {
            Unk80535650_Tmp t2;
            int buf2[0x28];
            Unk80535650_Tmp* q2 = &t2;
            q2->C1(buf2, 0x28);
            q2->C2();
            q2->C3(lbl_8064A4C8);
            fn_80538EC4((Unk805352B0_List*)q2, x, 0);
            fn_805362AC((Unk805352B0_List*)q2, 0);
            int e = *t2.m0;
            fn_8007F29C((Unk8007F198_A*)sc, x, e);
            fn_8007F330((Unk8007F198_A*)sc, g, e);
            q2->D();
        }
        fn_8007F330((Unk8007F198_A*)sc, x, r);
    }
    return r;
}

extern "C" DB_OVERLAY void fn_8056350C(int x)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    Unk8006A138_It<3> it(0);
    int cur = 0;
    do {
        int h = 0;
        int g = ((Unk8007B2B0_Screen*)sc)->fn_8007B320(fn_80083FC0(cur), x);
        int found;
        do {
            do {
                found = 0;
                unsigned n = fn_8007F674((Unk8007F198_A*)sc, g, h);
                unsigned i = 0;
                if (i < n) {
                    do {
                        int v = fn_8007F6C4((Unk8007F198_A*)sc, g, h, i);
                        if (fn_8007F724((Unk8007F198_A*)sc, g, h, v, fn_800A2AE8(lbl_80619948)) <= 0) {
                            fn_80563628(g, h, i);
                            found = 1;
                            break;
                        }
                        i++;
                    } while (i < n);
                }
            } while (found);
            h++;
        } while (h <= 1);
        cur = it.Next();
    } while (cur <= 3);
}

extern "C" DB_OVERLAY void fn_80563628(int a, int b, int c)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    int r = fn_8007F6C4((Unk8007F198_A*)sc, a, b, c);
    int v = sc->fn_8007A6A0(0x1F, r);
    int w = fn_800A2AE8(lbl_80619948);
    fn_8007F61C((Unk8007F198_A*)sc, a, b, r);
    if (v > 0x3B) {
        fn_8007F5BC((Unk8007F198_A*)sc, a, b, r, w);
        return;
    }
    if (v > 0xE && (unsigned)fn_8007F674((Unk8007F198_A*)sc, a, b) <= 1) {
        fn_8007F5BC((Unk8007F198_A*)sc, a, 0, r, w);
        return;
    }
    fn_80563740(a, sc->fn_8007A270(r));
    fn_8007F330((Unk8007F198_A*)sc, a, r);
    fn_80563140(a, r);
}
