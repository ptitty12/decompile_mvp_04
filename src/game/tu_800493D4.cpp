/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x800493D4-0x8004B6BC only: every data object is extern by its lbl_ name.
 */
#include "game/tu_800493D4.h"

void fn_8004961C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m50 == 0) {
        fn_80058FE4(s->mA9C, 8, a);
        fn_80058FE4(s->mA9C, 0x3F, a);
    }
}

static inline Unk80044C10_Vec3 Unk80049670_Sub(const Unk80044C10_Vec3& a, const Unk80044C10_Vec3& b)
{
    Unk80044C10_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

static inline float Unk80049670_Len(const Unk80044C10_Vec3& v)
{
    return fn_804028E4(v.x * v.x + v.z * v.z);
}

void fn_80049670(Unk800493D4_Sm* s, int idx)
{
    Unk80044C10_Vec3 pos = ((Unk80049670_P*)EntObj(s, idx)->m6CC)->m60;
    float dist = Unk80049670_Len(Unk80049670_Sub(lbl_805AE414, pos));
    if (!(dist <= s->m9F0))
        s->mA24 = 1;
    if (pos.x < 0.0f || !(pos.z >= 0.0f))
        s->mA24 = 1;
}

void fn_80049778(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m4D4 == 3 || a->m50 == 0) {
        fn_80058FE4(s->mA9C, 7, a);
        fn_8004FCDC(s, idx, a);
    }
    fn_8004B910(s, idx, a);
}

void fn_800497F0(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m50 == 0 && a->m3CC <= 3) {
        fn_80058FE4(s->mA9C, 0x2D);
        fn_80058FE4(s->mA9C, 0x3F, a);
    }
}

extern "C" void fn_80049C0C();

void fn_80049850(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m50 == 0) {
        if (a->m104 == 3) {
            int ok = 0;
            if (a->m1 == 1 && a->m0 >= EntObj(s, idx)->m6F8->m10->m1C && fn_80043884((Unk80043884_Obj*)a) != 0)
                ok = 1;
            if (ok == 0) {
                fn_8000FC58();
                return;
            }
            fn_80050324(s, idx, a, 1, 0x10);
            return;
        }
        if (a->m3D0 == 0) {
            int f = 0;
            char* b = (char*)a + 0x348;
            int o = *(int*)((char*)a->m130 + 0x708) * 0xC;
            if (*(int*)(b + o) == 1 && a->m3B8 != 0)
                f = fn_8040ABA0() % 100 <= 0x31;
            if (f != 0)
                fn_8001A3EC(1, fn_8001F904(a));
            else
                fn_80010E8C();
        }
        Unk8001CE80* g = (Unk8001CE80*)a;
        int t = g->fn_8001D5D8();
        int r;
        if (t == 2)
            r = fn_8001F904(a);
        else
            r = fn_8001F8B8(a);
        fn_800105AC(g->fn_8001DE9C(), fn_8001DEC0(a), g->fn_8001E2EC(), g->fn_8001E31C(), t, r);
        ((int (*)())fn_800B555C)();
        if (fn_800B57EC() != 0 && fn_8040ABA0() % 100 <= 0x31) {
            int p = ((Unk80069F0C*)EntObj(s, idx)->m6F8)->fn_8006A238(0);
            p += ((Unk80069F0C*)EntObj(s, idx)->m6F8)->fn_8006A238(1);
            int w = fn_80253E7C((Unk8024EF40_W*)((char*)a->m130 + 0x588), 0, 2, 0);
            fn_80011DD8(fn_80046734(p), fn_80045774(w));
        }
    }
}

void fn_80049AB8(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m104 == 3) {
        int ok = 0;
        if (a->m1 == 1 && a->m0 >= EntObj(s, idx)->m6F8->m10->m1C && fn_80043884((Unk80043884_Obj*)a) != 0)
            ok = 1;
        if (ok == 0) {
            fn_8001582C();
            return;
        }
        fn_80050324(s, idx, a, 1, 0x10);
        return;
    }
    if (a->m104 == 2) {
        Unk8001CE80* g = (Unk8001CE80*)a;
        int t = g->fn_8001D5D8();
        int r;
        if (t == 2)
            r = fn_8001F904(a);
        else
            r = fn_8001F8B8(a);
        fn_800105AC(g->fn_8001DE9C(), fn_8001DEC0(a), g->fn_8001E2EC(), g->fn_8001E31C(), t, r);
        return;
    }
    fn_80010E38();
}

extern "C" void fn_80049BEC()
{
    fn_80049C0C();
}


void fn_80049C0C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    Unk80044C10_C* c = EntObj(s, idx)->m6F8;
    if (fn_8006BE18(c) == 0) {
        int p = fn_80054684((Unk80052794_Ctx*)s, idx, 0);
        int q = fn_80054684((Unk80052794_Ctx*)s, idx, 1);
        int hi;
        int lo;
        int side;
        if (p > q) {
            hi = p;
            side = 0;
            lo = q;
        } else {
            hi = q;
            side = 1;
            lo = p;
        }
        if (hi >= lo + 10) {
            Unk8001CE80* g = (Unk8001CE80*)a;
            fn_800134B4(fn_8009E1D4((char*)c->m14 + side * 0xE64 + 0x8C, 2, 0), g->fn_8001D694(), fn_8001F614(a),
                        g->fn_8001DA7C(), fn_8001F2A0(a));
        }
    }
    if ((*(int*)a & 0xFFFF0000) == 0x01000000)
        ((void (*)(Unk800493D4_Sm*, int, Unk80044C10_A*))fn_80051370)(s, idx, a);
    s->m9F4 = 1;
}

extern "C" int rand();
void fn_800143D0(int a, int b);
void fn_80014914(int a, int b);
void fn_80015AD0(int a);
void fn_800171E8(int a);
void fn_800116BC(int a);
void fn_80019ECC(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80019F60(int a, int b, int c, int d, int e);
void fn_80019FDC(int a, int b, int c, int d);
void fn_8004A15C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
extern float lbl_805A9200;
extern float lbl_805A9204;
extern float lbl_805A9208;
extern int* lbl_8061B9C4;

void fn_80049D3C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    Unk8001CE80* g = (Unk8001CE80*)a;
    if (s->mA84 == 0 && a->m3D0 < *lbl_8061B9C4) {
        int f = 0;
        int t = fn_8004FF78(s, s->m9D8, 0x48);
        if (*(int*)((char*)s + s->m9E0 * 0x48) != 0x2D)
            f = fn_8004FF78(s, idx, 0x2D) == -1;
        float v, v1, v2;
        fn_8018CA5C(a->m130->m44C->m6CC, &v, &v1, &v2);
        v = v * lbl_805A9200;
        if (!(v < lbl_805A9204) && !(v > lbl_805A9208) && f != 0) {
            s->mA84 = 1;
            fn_800143D0(g->fn_8001D780(), g->fn_8001DA4C());
            return;
        }
        if (s->mA84 == 0) {
            int w;
            if (t != -1 && (w = a->m3BC) == 1) {
                s->mA84 = w;
                char* b4 = (char*)s + 4;
                Unk80044C10_A* o = *(Unk80044C10_A**)(b4 + t * 0x48);
                if ((void*)o == (void*)a->m3B0) {
                    fn_80015AD0(g->fn_8001DA4C());
                    return;
                }
                if (o->m460 == 1)
                    fn_800171E8(g->fn_8001DA4C());
                return;
            }
            if (s->mA84 == 0) {
                if ((unsigned)(*(int*)((char*)a + 0x408) - 4) <= 3) {
                    if (a->m3E8 == 1) {
                        fn_8004A15C(s, idx, a);
                    }
                    return;
                }
                if (a->m444 == 0x10 && a->m3D0 <= 1) {
                    s->mA84 = 1;
                    fn_80014914(g->fn_8001D454(), g->fn_8001DA4C());
                    return;
                }
                if (s->mA84 == 0) {
                    if (a->m448 == 3) {
                        if (rand() % 100 <= 0x31) {
                            s->mA84 = 1;
                            fn_800116BC(g->fn_8001DA4C());
                        }
                        return;
                    }
                    if (a->m458 == 0) {
                        fn_8004A15C(s, idx, a);
                        return;
                    }
                }
            }
        }
        int k = a->m458;
        if (k == 0xA || k == 0xC) {
            fn_8004A15C(s, idx, a);
            return;
        }
        if ((s->mA84 == 0 && a->m3F0 != 0) || k == 1 || k == 9) {
            int m = a->m448;
            if (m == 0 || (m == 4 && a->m3D0 <= 1)) {
                fn_8004A15C(s, idx, a);
                return;
            }
            if (*(int*)((char*)a + 0x550) != 0 && a->m3DC == 0 && s->mA74 == 0) {
                if (fn_80050850(s, idx, a) != 0) {
                    int p = g->fn_8001D780();
                    int q = g->fn_8001DA28();
                    int r = g->fn_8001D6CC();
                    fn_80019F60(p, q, r, 0, g->fn_8001D75C());
                } else if (a->m418 != 0) {
                    int p = g->fn_8001DA28();
                    int q = g->fn_8001D75C();
                    fn_80019FDC(p, 0, q, g->fn_8001D6CC());
                } else {
                    int p = g->fn_8001D780();
                    int q = g->fn_8001DA28();
                    int r = g->fn_8001D75C();
                    int u = g->fn_8001D70C();
                    int w = g->fn_8001D7D0();
                    int x = g->fn_8001D6CC();
                    fn_80019ECC(p, q, 0, r, u, w, x, g->fn_8001DB70());
                }
                s->mA74 = 1;
            }
            return;
        }
        fn_8004A15C(s, idx, a);
    }
}

void fn_8004A15C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (s->mA84 == 0) {
        s->mA84 = 1;
        Unk8001CE80* g = (Unk8001CE80*)a;
        if (a->m418 != 0) {
            fn_80019950(g->fn_8001DA4C(), g->fn_8001DA28(), fn_8001F904(a), g->fn_8001D7D0(), fn_8001EDE4(a),
                        g->fn_8001D454(), g->fn_8001D42C(), g->fn_8001D780());
        } else {
            fn_800110EC(g->fn_8001DA4C(), g->fn_8001D454(), fn_8001F904(a), g->fn_8001D780());
        }
    }
}

void fn_800107B8(int a, int b, int c, int d);
void fn_80011090(int a);
void fn_80011718();
void fn_8001176C(int a);
void fn_800117C8(int a, int b);
void fn_8001182C(int a, int b);
extern "C" int rand();
int fn_8001F3FC(Unk80044C10_A* a, int k);
void fn_80019ECC(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_80019F60(int a, int b, int c, int d, int e);
void fn_80019FDC(int a, int b, int c, int d);
void fn_80015994(int a, int b, int c);
void fn_80019B30(int a, int b, int c);
int fn_801BBF30(int a, int b);
int fn_801DC570(int a);
void fn_8004A8A4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
extern float lbl_805A920C;

/* near-miss 95.1%: 380 of retail's 383 insns. Retail reloads the owner pointer (s + 0x3C + idx * 0x48) before each
 * loop and use; ours keeps it in a register, which shifts the saved registers r25-r30 and the loop-setup order. */
void fn_8004A268(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    Unk8001CE80* g = (Unk8001CE80*)a;
    int off = idx * 0x48;
    char* b = (char*)s + 0x3C;
    int ti = a->m3B4;
    int sumA = 0;
    int i = 0;
    int n = 0x80;
    Unk80044C10_Side* sd = &(*(Unk80044C10_B**)(b + off))->m6F8->m14->sides[ti];
    do {
        sumA += sd->m1B4[(unsigned char)i];
        i++;
    } while (--n != 0);
    int other = ti == 0;
    int lim = sumA + a->m104 - *(int*)((char*)a + 0x48) + 1;
    unsigned sumB = 0;
    int j = 0;
    n = 0x80;
    Unk80044C10_Side* sd2 = &(*(Unk80044C10_B**)(b + off))->m6F8->m14->sides[other];
    do {
        sumB += sd2->m1B4[(unsigned char)j];
        j++;
    } while (--n != 0);
    int c = 0;
    if (a->m0 >= (*(Unk80044C10_B**)(b + off))->m6F8->m10->m1C && a->m1 == 1)
        c = sumB < (unsigned)lim;
    if (*(int*)((char*)a + 0x3D8) != 0 && c == 0) {
        fn_80011718();
        return;
    }
    if ((a->m3E0 != 0 || a->m3F8 != 0) && a->m3E8 != 0) {
        int p = g->fn_8001DA28();
        fn_8001182C(p, g->fn_8001D75C());
        s->mA68 = 1;
        return;
    }
    if ((unsigned)(*(int*)((char*)a + 0x408) - 4) <= 3 && s->mA84 == 0) {
        fn_8004A8A4(s, idx, a);
        return;
    }
    int w25 = 0;
    if ((*(int*)((char*)s + s->m9E0 * 0x48) != 0xB && fn_8004FF78(s, idx, 0xB) == -1) || a->m44C == 0)
        w25 = 1;
    int w30 = 0;
    if (*(int*)((char*)s + s->m9E0 * 0x48) != 0x2D)
        w30 = fn_8004FF78(s, idx, 0x2D) == -1;
    int t3 = fn_8004FF78(s, s->m9D8, 0x58);
    int w10 = t3 == -1;
    if (w10 == 0) {
        char* b4 = (char*)s + 4;
        char* b8 = (char*)s + 8;
        if ((*(Unk80044C10_A**)(b4 + t3 * 0x48))->m460 == 0 && !(*(float*)(b8 + t3 * 0x48) <= lbl_805A920C))
            w10 = 1;
    }
    if (w25 != 0 && w30 != 0 && w10 != 0 && s->mA84 == 0) {
        int u = g->fn_8001D70C();
        Unk80044C10_B* o = *(Unk80044C10_B**)(b + off);
        int v = fn_801DC570(*(int*)((char*)o->m700 + 0x3B8));
        if (*(int*)((char*)a + 0x3C4) == 1) {
            int r;
            if (rand() % 100 > 0x32)
                r = g->fn_8001DB70();
            else
                r = g->fn_8001DC58();
            int p = g->fn_8001D7D0();
            fn_80015994(p, g->fn_8001D6CC(), r);
        } else if (*(int*)((char*)a + 0x550) != 0 && u != 0 && s->mA74 == 0) {
            if ((a->m448 != 0 || fn_801BBF30(*(int*)((char*)o->m700 + 0x3BC), (int)o->m6CC) != 0) &&
                (g->fn_8001D8DC() == 0 || rand() % 100 <= 0x31)) {
                if (fn_80050850(s, idx, a) != 0) {
                    fn_8001176C(g->fn_8001D70C());
                } else if (a->m418 != 0) {
                    int p = g->fn_8001DA28();
                    int q = g->fn_8001D70C();
                    fn_80019B30(p, q, g->fn_8001D6CC());
                } else {
                    fn_80011090(g->fn_8001D70C());
                }
                s->mA74 = 1;
            }
        } else if (fn_80050850(s, idx, a) != 0) {
            int p = fn_8001F3FC(a, v);
            fn_800117C8(p, g->fn_8001D75C());
        } else {
            int p = g->fn_8001DA28();
            int q = g->fn_8001D75C();
            int r = fn_8001F3FC(a, v);
            fn_800107B8(p, q, r, g->fn_8001DB70());
        }
        if (fn_80050850(s, idx, a) != 0) {
            int p = g->fn_8001D780();
            int q = g->fn_8001DA28();
            int r = g->fn_8001D6CC();
            int t = fn_8001F3FC(a, v);
            fn_80019F60(p, q, r, t, g->fn_8001D75C());
            return;
        }
        if (a->m418 != 0) {
            int p = g->fn_8001DA28();
            int q = fn_8001F3FC(a, v);
            int r = g->fn_8001D75C();
            fn_80019FDC(p, q, r, g->fn_8001D6CC());
            return;
        }
        int p = g->fn_8001D780();
        int q = g->fn_8001DA28();
        int r = fn_8001F3FC(a, v);
        int t = g->fn_8001D75C();
        int u2 = g->fn_8001D70C();
        int w = g->fn_8001D7D0();
        int x = g->fn_8001D6CC();
        fn_80019ECC(p, q, r, t, u2, w, x, g->fn_8001DB70());
    }
}

void fn_8004A864(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m3DC == 0) {
        fn_80011890();
        s->mA68 = 1;
    }
}

void fn_8004A8A4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m3DC == 0) {
        int p = fn_8001F4F0(a);
        fn_8000F670(p, fn_8001E054(a));
    }
}

void fn_8004A8F8(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    s->mA34 = 0;
    fn_80058FE4(s->mA9C, 0x39, a);
    s->mA90 = 1;
    char* b = (char*)s + 0x3C;
    int o = idx * 0x48;
    fn_80046078(*(Unk80044C10_B**)(b + o));
}

void fn_8004A950(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int o = idx * 0x48;
    char* b4 = (char*)s + 4;
    Unk8004A950_Obj* p4 = *(Unk8004A950_Obj**)(b4 + o);
    if (p4 != 0) {
        char* b8 = (char*)s + 8;
        if (*(int*)(b8 + o) != 0) {
            char* b10 = (char*)s + 0x10;
            if (*(int*)(b10 + o) != 0 && p4->m460 == 1) {
                int x = fn_80044D3C(fn_80247858(*(Unk8004A950_Obj**)(b8 + o), 0));
                char* bC = (char*)s + 0xC;
                int y = fn_80044240(*(int*)(bC + o));
                int z = fn_8001F3FC(a, *(int*)(b8 + o));
                fn_8001101C(x, y, z, fn_8001F45C(a, *(int*)(b4 + o)));
            }
            if ((*(Unk8004A950_Obj**)(b4 + o))->m460 == 2 && (*(Unk8004A950_Obj**)(b8 + o))->m460 == 0
                && fn_80247858(*(Unk8004A950_Obj**)(b8 + o), 0) == 0) {
                fn_800170DC();
            }
        }
    }
}

void fn_8004AA40()
{
}

void fn_8004ADE0()
{
}

void fn_8004ADE4(Unk800493D4_Sm* s, int idx, Unk8004ADE4_Arg* a)
{
    int found = 0;
    int i;
    for (i = 0; i < a->m100; i++) {
        float v = fn_804028E4(a->m70[i].m0->m8E8) / ((float)lbl_8061B9C8 * 0.016666668f);
        if (!(v <= 0.0f)) {
            found = 1;
            break;
        }
    }
    if (found != 0)
        fn_80012988();
}

void fn_8004AEB4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    char* b = (char*)s + 0x3C;
    int o = idx * 0x48;
    if (fn_80258C90((*(Unk80044C10_B**)(b + o))->m700->m3B4) != 0)
        fn_8000F808();
}

void fn_8004AEF4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    char* b = (char*)s + 0x3C;
    int o = idx * 0x48;
    if (fn_80258C90((*(Unk80044C10_B**)(b + o))->m700->m3B4) != 0) {
        Unk800493D4_Ent* e = (Unk800493D4_Ent*)((char*)s + o);
        if (e->m8 != 0) {
            fn_80017130();
            return;
        }
        int x = fn_8001F3FC(a, e->m4);
        int y = fn_8001D8DC(a);
        fn_800119F8(x, y, fn_8001F45C(a, e->m4));
    }
}

void fn_8004AF90()
{
}

void fn_8004AF94(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int ok = 0;
    if (a->m104 == 3 && a->m1 == 1 && a->m0 >= EntObj(s, idx)->m6F8->m10->m1C
        && fn_80043884((Unk80043884_Obj*)a) != 0)
        ok = 1;
    if (ok == 1) {
        fn_80050324(s, idx, a, 1, 1);
        return;
    }
    int t = ((Unk8001CE80*)a)->fn_8001D5D8();
    int r;
    if (t == 2)
        r = fn_8001F904(a);
    else
        r = fn_8001F8B8(a);
    fn_80010548(t, r);
}

void fn_8004B070(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    char* b4 = (char*)s + 4;
    int o = idx * 0x48;
    int cur = *(int*)(b4 + o);
    if (cur < a->m4D4) {
        char* rec = (char*)a + (cur * 0x18 + 0x48C);
        int k = fn_8005000C(s, idx, 0xB);
        Unk8001CE80* g = (Unk8001CE80*)a;
        if (k != -1) {
            int ko = k * 0x48;
            int id = *(int*)(rec + 8);
            if (*(int*)(b4 + ko) == id) {
                char* e = (char*)s + ko + 4;
                int st = *(int*)(e + 4);
                if (a->m3F8 != 0) {
                    if (a->m3E8 != 0)
                        fn_80018694();
                } else {
                    if (!(*(float*)(e + 0x10) >= 0.7f) && st != 6 && st != 7 && st != 8 && st != 5 && a->m3E0 != 0) {
                        int x = g->fn_8001D6CC();
                        fn_80015880(x, fn_8001F45C(a, *(int*)(rec + 8)));
                    } else {
                        int flag = 0;
                        if ((id != 0 && fn_8024D41C((Unk80270BA0_X*)id) != 0 && a->m464 != 0) || !(*(float*)(e + 0x10) <= 0.7f))
                            flag = 1;
                        if (flag == 1 || st == 6 || st == 8 || st == 5 || st == 7) {
                            if (a->m3E8 != 0) {
                                int x = fn_8001F3FC(a, *(int*)(rec + 8));
                                int y = g->fn_8001D70C();
                                int z = fn_8001F45C(a, *(int*)(rec + 8));
                                fn_80010BC0(x, y, z, g->fn_8001D6CC());
                            } else {
                                fn_800183E8(g->fn_8001DA4C());
                            }
                        } else if (a->m3E8 != 0) {
                            int x = fn_8001F3FC(a, *(int*)(rec + 8));
                            int y = fn_8001F45C(a, *(int*)(rec + 8));
                            fn_80010B54(x, y, g->fn_8001DA28());
                        } else {
                            int t = g->fn_8001DA4C();
                            fn_80018384(t, fn_8001F45C(a, *(int*)(rec + 8)));
                        }
                    }
                }
            }
        } else if (a->m3E8 == 0) {
            int t = g->fn_8001DA4C();
            fn_80018384(t, fn_8001F45C(a, *(int*)(rec + 8)));
        }
        fn_8004FCDC(s, idx, a);
        fn_8004B910(s, idx, a);
    }
}

void fn_8004B314(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (fn_8004FF78(s, s->m9D8, 0x2D) == -1 && fn_8004FF78(s, s->m9D8, 0x49) == -1) {
        if ((a->m454 == 2 || a->m454 == 0) && a->m3FC != 0) {
            fn_80015BDC();
            return;
        }
        if ((a->m454 == 2 && a->m430 < 15.0f) || (a->m454 == 0 && !(a->m428 >= 15.0f))) {
            fn_80011160(((Unk8001CE80*)a)->fn_8001D6CC());
        }
    }
}

void fn_8004B3DC(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (s->mA84 == 0) {
        if (a->m3F0 == 1) {
            s->mA84 = a->m3F0;
            fn_80015B88();
            return;
        }
        Unk8001CE80* g = (Unk8001CE80*)a;
        if ((a->m454 == 2 || a->m454 == 0) && a->m3FC != 0) {
            s->mA84 = 1;
            fn_80011B80(g->fn_8001D6CC(), g->fn_8001DA4C());
            return;
        }
        if (a->m3F8 == 0 && ((a->m454 == 2 && a->m430 > -15.0f) || (a->m454 == 0 && !(a->m428 <= -15.0f)))) {
            s->mA84 = 1;
            if (a->m418 != 0) {
                fn_800199E4(g->fn_8001DA4C(), g->fn_8001D42C(), g->fn_8001D454(), g->fn_8001DA28());
                return;
            }
            fn_80011A64(g->fn_8001DA4C());
            return;
        }
        fn_8004A15C(s, idx, a);
    }
}

void fn_8004B534()
{
}

void fn_8004B538(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    s->m9DC = idx;
    char* base = (char*)s + 0x3C;
    int off = idx * 0x48;
    fn_801A6D84(*(Unk80044C10_A**)(base + off), 1);
    if (fn_8016B9F4() == 0) {
        if (fn_8006BE18((*(Unk80044C10_B**)(base + off))->m6F8) == 0)
            fn_8004B5C0(s, idx, a);
        fn_80057B54(fn_800475EC()->mFC.mA9C, 0);
    }
}

void fn_8004B5C0(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    fn_8004CB40();
    fn_8004D738(s, idx, a);
    Unk8004B5C0_Obj* o = (Unk8004B5C0_Obj*)a->m3B0;
    if ((o->m590 & 0x20000000) != 0 && !(fn_80253F54((Unk8024EF40_W*)o->m588, 1, 2, 0) < 3.0f)
        && fn_80253F54((Unk8024EF40_W*)((Unk8004B5C0_Obj*)a->m3B0)->m588, 0, 2, 0) == 0.0f) {
        Unk8004B5C0_Obj* p = (Unk8004B5C0_Obj*)a->m3B0;
        if (!((fn_8024F20C(p->mA0C, p->mA04, p->m44C, p->m708, 1)
               + fn_8024F048(((Unk8004B5C0_Obj*)a->m3B0)->mA0C, ((Unk8004B5C0_Obj*)a->m3B0)->mA04,
                             ((Unk8004B5C0_Obj*)a->m3B0)->m44C, ((Unk8004B5C0_Obj*)a->m3B0)->m708, 1))
              < 1.6f))
            fn_80014628();
    }
}
