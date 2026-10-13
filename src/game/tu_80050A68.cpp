/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80050A68-0x80052794 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80050A68.h"

/* fn_80050D24: 0x18-byte entries at a + 0x45C (m8 the linked object, mC a flag). */
struct Unk80050D24_Ent {
    int m0;
    int m4;
    Unk80044C10_A* m8;
    int mC;
    int m10;
    int m14;
};

void fn_80050A68(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    Unk80050A68_Obj* o = (Unk80050A68_Obj*)a;
    if (s->mA70 == 0) {
        s->mABC = 0;
        Unk80050A68_Slot* q = 0;
        int i;
        for (i = o->m100 - 1; i >= 0; i--) {
            int off = i * 0x24;
            char* b = (char*)o + 0x70;
            if (*(int*)(b + off) == o->m3B0) {
                char* c = (char*)o + 0x78;
                if (*(int*)(c + off) == 2) {
                    q = (Unk80050A68_Slot*)((char*)o + (off + 0x70));
                    break;
                }
            }
        }
        if (q != 0 && o->m44 == 0) {
            fn_8005039C(s, idx, a);
            if (o->m48 > 0) {
                int x = ((Unk8001CE80*)a)->fn_8001DB4C();
                fn_80010F3C(x, ((Unk8001CE80*)a)->fn_8001DB70());
                return;
            }
            if (fn_8001F954(a) == 4) {
                fn_8001A664();
                s->mABC = 1;
                return;
            }
            if (fn_80050850(s, idx, a) != 0) {
                fn_800119A4();
                return;
            }
            int x = fn_8001D974(a);
            int y = ((Unk8001CE80*)a)->fn_8001DE9C();
            int z = ((Unk8001CE80*)a)->fn_8001DB70();
            fn_8001014C(x, y, z, fn_8001F904(a));
        }
    }
}

int fn_80050D24(Unk800493D4_Sm* s, Unk80044C10_A* a)
{
    int r = -1;
    if (a->m448 == 0 || a->m444 == 8) {
        int k = a->m4D4;
        if (k == 3) {
            r = 8;
        } else if ((a->m4D8 == 2 && a->m448 == 0) || a->m444 == 8) {
            int off = k * 0x18;
            Unk80044C10_A* p = (Unk80044C10_A*)s->mA14[0];
            Unk80050D24_Ent* e0 = (Unk80050D24_Ent*)((char*)a + (off + 0x45C));
            Unk80050D24_Ent* e1 = (Unk80050D24_Ent*)((char*)a + (off + 0x474));
            if (p != 0) {
                int pv = p->m460;
                if (pv == 2) {
                    if (e0->mC == 1) {
                        Unk80044C10_A* x = e0->m8;
                        if (x != 0 && x->m460 == 5 && e1->mC == 0) {
                            Unk80044C10_A* y = e1->m8;
                            if (y != 0) {
                                int v = y->m460;
                                if (v == 0)
                                    r = 0;
                                else if (v == 2)
                                    r = 1;
                            }
                        }
                    }
                } else if (pv == 3) {
                    if (e0->mC == 1) {
                        Unk80044C10_A* x = e0->m8;
                        if (x != 0 && x->m460 == 5 && e1->mC == 0) {
                            Unk80044C10_A* y = e1->m8;
                            if (y != 0 && y->m460 == 2)
                                r = 2;
                        }
                    }
                } else if (pv == 4) {
                    if (e0->mC == 1) {
                        Unk80044C10_A* x = e0->m8;
                        if (x != 0 && x->m460 == 3 && e1->mC == 0) {
                            Unk80044C10_A* y = e1->m8;
                            if (y != 0 && y->m460 == 2)
                                r = 3;
                        }
                    }
                } else if (pv == 5) {
                    if (e0->mC == 1) {
                        Unk80044C10_A* x = e0->m8;
                        if (x != 0 && e1->mC == 0) {
                            Unk80044C10_A* y = e1->m8;
                            if (y != 0 && y->m460 == 2) {
                                int v = x->m460;
                                if (v == 5)
                                    r = 4;
                                else if (v == 3)
                                    r = 5;
                            }
                        }
                    }
                }
            }
        }
    }
    if (fn_8004FF78(s, s->m9D8, 0x33) >= 0)
        r = 6;
    if (fn_8004FF78(s, s->m9D8, 0x1C) >= 0 && fn_8004FF78(s, s->m9D8, 8) >= 0 && a->m4D4 == 3)
        r = 7;
    return r;
}

void fn_80050F9C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (s->mA6C == 0) {
        Unk80044C10_Obj590* o = a->m3B0;
        if (o != 0 && (o->m590 & 0x20000000) == 0) {
            fn_80011C38(s);
            s->mA6C = 1;
        }
    }
}

void fn_80050FF4()
{
    fn_80011BE4();
}

void fn_80051014(Unk800493D4_Sm* s, int idx)
{
    char* b = (char*)s + 0x3C;
    Unk80044C10_E* e = (*(Unk80044C10_B**)(b + idx * 0x48))->m6F8->m14;
    if (e->m1CC8 == 0 && e->m1CD0 == 1)
        fn_80052FBC(s, idx);
}

void fn_80051060(Unk800493D4_Sm* s, int idx)
{
    char* b = (char*)s + 0x3C;
    int o = idx * 0x48;
    int t = fn_80075E7C((*(Unk80044C10_B**)(b + o))->m6F8->mC->m24);
    int v = 0;
    if (t == 0x37) {
        Unk80050A68_T16 tbl = lbl_805A928C;
        unsigned int i = (*(Unk80044C10_B**)(b + o))->m6F8->mC->m78 - 1;
        if (i <= 15)
            v = tbl.v[i];
    } else {
        v = lbl_805B1634[t];
    }
    if (v != 0)
        fn_8001A9C8(v);
}

void fn_80051168()
{
}

void fn_8005116C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    char* b = (char*)s + 8;
    int off = idx * 0x48;
    Unk80044C10_A* o = *(Unk80044C10_A**)(b + off);
    if (o->m708 != a->m3B0->m708) {
        Unk8024EF40_W* w = (Unk8024EF40_W*)o->m588;
        int x = fn_80042E58(fn_8025416C(w, 0));
        int g = fn_8025416C(w, 0) > 0x4E1F;
        fn_8001AF38(fn_8004475C(o->m460), x, 1, fn_80044828(g));
    }
}

void fn_80051208(Unk800493D4_Sm* s, int idx)
{
    char* b4 = (char*)s + 4;
    char* b8 = (char*)s + 8;
    int off = idx * 0x48;
    Unk80044C10_A* p = *(Unk80044C10_A**)(b4 + off);
    Unk80044C10_A* q = *(Unk80044C10_A**)(b8 + off);
    Unk8024EF40_W* wp = (Unk8024EF40_W*)p->m588;
    Unk8024EF40_W* wq = (Unk8024EF40_W*)q->m588;
    int xp = fn_80042E58(fn_8025416C(wp, 0));
    int xq = fn_80042E58(fn_8025416C(wq, 0));
    int gp = fn_8025416C(wp, 0) > 0x4E1F;
    int gq = fn_8025416C(wq, 0) > 0x4E1F;
    int z = fn_80044820(p->m708);
    fn_8001B064(fn_8004475C(p->m460), xp, z, fn_80044828(gp));
    fn_8001B064(fn_8004475C(q->m460), xq, z, fn_80044828(gq));
}

void fn_800512FC(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    Unk80050A68_Msg m;
    Unk80050A68_Msg* p = &m;
    fn_80344624(p);
    fn_8005695C(p);
    m.m3C = a->m3B0->m704;
    m.m40 = a->m130->m704;
    *(int*)((char*)s->mA9C + 0x100) = 1;
    fn_80057AD4(s->mA9C, (Unk80052794_Rec*)p, (Unk80052794_Obj*)a);
}

void fn_80051370()
{
}

void fn_80051860(Unk800493D4_Sm* s, int idx)
{
    char* p = (char*)s + idx * 0x48;
    if (*(int*)(p + 8) > 1) {
        fn_8000FD5C();
        return;
    }
    fn_8000F6D4(fn_80044D3C(*(int*)(p + 4)));
}

void fn_800518A4()
{
    fn_8000FEBC();
}

void fn_800518C4()
{
}

void fn_800518C8()
{
}

void fn_80051D20(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    char* b8 = (char*)s + 8;
    int off = idx * 0x48;
    Unk80044C10_A* p8 = *(Unk80044C10_A**)(b8 + off);
    if (s->mA98 != 0) {
        int x = fn_8001F510(a);
        fn_80018FE4(x, fn_80043B78(p8->m460));
        return;
    }
    char* b4 = (char*)s + 4;
    char* bc = (char*)s + 0xC;
    int w = *(int*)(b4 + off);
    int v = *(int*)(bc + off);
    if (rand() % 10 <= 4) {
        int f = 0;
        if (v == 0)
            f = fn_8001F788(a);
        int x = fn_8001F45C(a, w);
        int y = fn_80046780(v);
        fn_80018E98(x, y, fn_80043B78(v), f);
        return;
    }
    int x = fn_8001F45C(a, (int)p8);
    int y = fn_8001F3FC(a, (int)p8);
    fn_80018E24(x, y, fn_8004390C(((Unk8001CE80*)a)->fn_8001D204(fn_8025416C((Unk8024EF40_W*)a->m130->m588, 0x16))), 0);
}

void fn_80051E68(Unk800493D4_Sm* s, int idx)
{
    if (fn_8005000C(s, idx, 0x2E) >= 0) {
        char* b = (char*)s + 8;
        if (*(int*)(b + idx * 0x48) != 0)
            fn_80017C2C();
    }
}

void fn_80051EBC(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    char* b = (char*)s + 8;
    int off = idx * 0x48;
    int k = *(int*)(b + off);
    int x = fn_80045E80(*((unsigned char*)s + off + 0xF));
    fn_80018F0C(x, fn_8001F45C(a, k));
}

void fn_80051F18()
{
}

static inline int At(char* b, int off)
{
    return *(int*)(b + off);
}

void fn_80051F1C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    char* b = (char*)s + 4;
    int off = idx * 0x48;
    Unk80044C10_A* p = *(Unk80044C10_A**)(b + off);
    if ((Unk80044C10_Obj590*)p == a->m3B0) {
        if (p->m590 & 0x20000000)
            fn_80014ED4();
    } else if (p->m708 == a->m3B0->m708) {
        Unk80044C10_Vec3 v = p->m60;
        if (!(v.x < 0.0f) && !(v.z < 0.0f))
            fn_80014ED4();
    } else {
        int r = fn_8004FF78(s, idx, 0xB);
        if ((r == -1 || *(int*)(b + r * 0x48) != (int)p)
            && (At((char*)s, s->m9E0 * 0x48) != 0xB || At(b, s->m9E0 * 0x48) != (int)p)
            && p->m460 != 1) {
            int f = fn_80043B78(p->m460);
            if (p->m708 == a->m130->m708)
                f |= 0x20000;
            fn_80014834(f);
        }
    }
}

void fn_8005203C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int me = a->m3B0->m708;
    Unk80044C10_A* r7 = 0;
    Unk80044C10_A* r8 = 0;
    char* b4 = (char*)s + 4;
    char* b8 = (char*)s + 8;
    int off = idx * 0x48;
    Unk80044C10_A* p = *(Unk80044C10_A**)(b4 + off);
    Unk80044C10_A* q = *(Unk80044C10_A**)(b8 + off);
    if (p->m708 == me)
        r7 = p;
    else
        r8 = p;
    if (q->m708 == me)
        r7 = q;
    else
        r8 = q;
    if (r7 != 0 && r8 != 0) {
        if (r7->m590 & 0x20000000) {
            Unk80044C10_Vec3 v = r8->m60;
            fn_80013724(fn_80044270(&v));
            return;
        }
        Unk80044C10_Vec3 v = r8->m60;
        fn_8000F968(fn_80044270(&v));
    }
}

void fn_80052124()
{
    fn_8001A450();
}

void fn_80052144()
{
}

void fn_80052148(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (fn_8004FF78(s, s->m9D8, 0x58) == -1) {
        int x = ((Unk8001CE80*)a)->fn_8001D70C();
        int y = ((Unk8001CE80*)a)->fn_8001DA28();
        int z = fn_8001D8DC(a);
        fn_8001467C(x, y, z, ((Unk8001CE80*)a)->fn_8001DB70());
    }
    s->mA24 = 1;
}

void fn_80052670(Unk800493D4_Sm* s, int idx, Unk80050A68_Rec* r)
{
    int sp8;
    int spC;
    int sp10;
    s->mA34 = s->mA34 + 1;
    fn_800883E4(EntObj(s, idx)->m6F8->mC->mC, &sp8, &spC, &sp10);
    if (r->m8 == 0) {
        int x = fn_80044FF0(spC);
        fn_80019CE8(x, fn_80044FAC(r->m40));
    }
    if (s->mA34 == 1) {
        if (s->mA88 == 1) {
            fn_800B555C();
            if (fn_800B57EC() == 1 && (r->m0 & 0xFFFF0000) != 0x01000000)
                fn_800521D0(s, idx, r, 0);
            s->mA88 = 0;
        } else {
            fn_800521D0(s, idx, r, 1);
        }
    }
    if ((r->m0 & 0xFFFF0000) == 0x07000000)
        fn_8000FE0C();
    s->mAC0 = 0;
}

void fn_80052790()
{
}
