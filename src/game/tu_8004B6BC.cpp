/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8004B6BC-0x8004E364 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_8004B6BC.h"
int fn_802540E4(Unk8024EF40_W* w, int a, int b);
int fn_80253F0C(Unk8024EF40_W* w, int a, int b, int c);
void fn_800120AC(int a, int b, int c);
int fn_80043004(unsigned a);
int fn_80043024(int a);
void fn_80013530(int a, int b, int c, int d);
void fn_80012AAC();
void fn_80012A40(int a, int b, int c);
inline int Unk8004CE04_M4(Unk800493D4_Sm* s, int idx)
{
    char* b = (char*)s + 4;
    int o = idx * 0x48;
    return *(int*)(b + o);
}
inline int Unk8004CE04_M8(Unk800493D4_Sm* s, int idx)
{
    char* b = (char*)s + 8;
    int o = idx * 0x48;
    return *(int*)(b + o);
}
struct Unk8004BF14_R {
    char pad0[4];
    unsigned m4;
    char pad8[0x30];
    int m38;
};
int fn_80056D0C(int a);
unsigned fn_80253DB0(Unk8024EF40_W* w, int a, int b);
void fn_800129DC(int a, int b);
void fn_80013024();
void fn_80014328();
void fn_80019348(int a);
void fn_80011D6C(int a, int b, int c);
int fn_80042FE4(int a);
void fn_800B555C();
int fn_800B57EC();
extern "C" int rand();
void fn_80011F78();
void fn_800135A4(int a, int b);
void fn_800136D0();
int fn_800974B8(void* p, int a);
int fn_80253DF4(Unk8024EF40_W* w, int a, int b);
int fn_80045C8C(Unk80044C10_A* a);
struct Unk8004D56C_Slot {
    int m0;
    int m4;
    int m8;
    char padC[0x18];
};
struct Unk8004D56C_AV {
    char pad0[0x38];
    int m38;
    char pad3C[0x48 - 0x3C];
    int m48;
    char pad4C[0x70 - 0x4C];
    Unk8004D56C_Slot m70[4];
    int m100;
    int m104;
    char pad108[0x274 - 0x108];
    int m274;
};
void fn_80014B00();
void fn_80016F84();
void fn_8001702C(int a);
inline int Unk8004D56C_At(char* b, int o)
{
    return *(int*)(b + o);
}
void fn_800109F4();
void fn_80011378(int a);
void fn_80011534();
void fn_800108C8(int a, int b, int c);
struct Unk8004BC9C_Row {
    char pad0[0x1B4];
    unsigned char m1B4[0x80];
    char pad234[0xE64 - 0x234];
};
struct Unk80052794_Obj;
void fn_8000FDB0(int a);
void fn_80052908(Unk80052794_Ctx* c, int idx, Unk80052794_Obj* o);

inline int Unk8004BC9C_SumRow(Unk8004BC9C_Row* r)
{
    int s = 0;
    for (int i = 0; i < 0x80; i++) {
        s += r->m1B4[(unsigned char)i];
    }
    return s;
}

float fn_80253EC4(Unk8024EF40_W* w, int a, int b, int c);
void fn_80058060(Unk80057204_Mgr* m, int a);
void fn_80044918();
int fn_800461B4(int a);
void fn_80015534(int a);
void fn_800189D0(int a);
void fn_8001319C();
struct Unk8004E14C_SmV {
    char pad0[0xA54];
    int mA54;
};
struct Unk8004E14C_AV {
    char pad0[0x38];
    int m38;
    char pad3C[0x408 - 0x3C];
    unsigned m408;
};
extern int* lbl_8061B9C4;
void fn_8004FC60(Unk800493D4_Sm* s, Unk80044C10_A* a);
void fn_80052A34(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
extern "C" int fn_800507A8(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
void fn_80011430(int a);
void fn_80010934(int a);
struct Unk8004E28C_View {
    char pad0[0x120];
    char* m120;
    char pad124[0x44C - 0x124];
    int m44C;
};
int fn_8001F3FC(Unk80044C10_A* a);
void fn_80013868(int a);
void fn_800130DC(int a, int b);
void fn_80010754(int a, int b);
void fn_80011218();

int fn_8004B6BC(Unk800493D4_Sm* s, int idx, Unk80044C10_A* unused)
{
    int a = fn_8005000C(s, idx, 0x24);
    int b = fn_8005000C(s, a, 0x24);
    if (fn_8005000C(s, b, 0x24) != -1)
        return 0;
    if (fn_8005000C(s, idx, 0x51) == -1 && a != -1 && b != -1) {
            char* k = (char*)s + 8;
            char* p = (char*)s + 4;
            int oa = a * 0x48;
            int ob = b * 0x48;
            int ka = *(int*)(k + oa);
            int oba = *(int*)(p + oa);
            int obb = *(int*)(p + ob);
            int kb = *(int*)(k + ob);
            Unk80044C10_Obj590* x;
            Unk80044C10_Obj590* y;
            if (ka == 1 && kb == 2) {
                x = (Unk80044C10_Obj590*)oba;
                y = (Unk80044C10_Obj590*)obb;
            } else if (ka == 2 && kb == 1) {
                y = (Unk80044C10_Obj590*)oba;
                x = (Unk80044C10_Obj590*)obb;
            } else {
                return 0;
            }
            if (x->m590 & 0x20000000) {
                fn_800189D0(2);
                return 1;
            }
            if (y->m590 & 0x20000000) {
                fn_800189D0(4);
                return 1;
            }
            fn_8001319C();
            return 1;
    }
    return 0;
}

void fn_8004B7E0(Unk800493D4_Sm* s, int v, Unk80044C10_A* a)
{
    fn_80044918();
    s->m9D8 = v;
    s->mA80 = 0;
    s->mA88 = 0;
    for (int i = 0; i < 3; i++)
        s->mA14[i] = 0;
    s->mA20 = 0;
    s->mA24 = 0;
    s->mA5C = 0;
    s->mA60 = 0;
    s->mA68 = 0;
    s->mA6C = 0;
    s->mA94 = 0;
    s->mA84 = 0;
    s->mA74 = 0;
    s->mA78 = 0;
    s->mA7C = 0;
    s->mA4C = 0;
    s->mA50 = 0;
    s->mAB4 = 0;
    s->mAB8 = 0;
    if (s->mA04 == 1) {
        if ((int)fn_80253EC4((Unk8024EF40_W*)((char*)a->m130 + 0x588), 1, 2, 0) != 0) {
            fn_80015534(fn_800461B4(s->mA08));
        }
        s->mA04 = 0;
    }
    fn_80044918();
    fn_80058060((Unk80057204_Mgr*)s->mA9C, 3);
    fn_80058FE4(s->mA9C, 6, a);
    if (s->mAB0 != 0) {
        fn_80058FE4(s->mA9C, 1, a);
        s->mAB0 = 0;
    }
}

void fn_8004B910(Unk800493D4_Sm* s)
{
    int v = s->mA58;
    if (v != 0)
        s->mA58 = v - 1;
}

void fn_8004BC9C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int t = a->m3B4;
    Unk80044C10_B* b = EntObj(s, idx);
    int o0 = t * 0xE64;
    int sa = Unk8004BC9C_SumRow((Unk8004BC9C_Row*)((char*)b->m6F8->m14 + o0));
    int z = t == 0;
    int o1 = z * 0xE64;
    int sb = Unk8004BC9C_SumRow((Unk8004BC9C_Row*)((char*)b->m6F8->m14 + o1));
    int ok = 0;
    if (a->m0 >= b->m6F8->m10->m1C && a->m1 == 1)
        ok = (unsigned)sb < (unsigned)sa;
    if (ok) {
        fn_80050324(s, idx, a, a->m104 + 1, 0x40);
    } else {
        fn_8000FDB0(((Unk8001CE80*)a)->fn_8001DB70());
        fn_80052908((Unk80052794_Ctx*)s, idx, (Unk80052794_Obj*)a);
    }
}

void fn_8004BDC4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int k = a->m284;
    if (k <= 9 || (k & 3) == 0) {
        if (k > 2) {
            if (k & 1)
                fn_8000F85C(fn_8001F8B8(a));
        } else {
            char* b = (char*)s + 4;
            int o = idx * 0x48;
            int x = fn_80044D3C(*(int*)(b + o));
            fn_8000F794(x, 0, fn_8001F8B8(a), 1);
        }
    }
}

void fn_8004BE50(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (s->mA80 == 0) {
        int o = idx * 0x48;
        char* b8 = (char*)s + 8;
        int kind = *(int*)(b8 + o);
        if (kind == 3) {
            int x = fn_80044D3C(kind);
            char* b = (char*)s + 4;
            fn_80010754(x, fn_8001F45C(a, *(int*)(b + o)));
            s->mA80 = 1;
        } else {
            int k = a->m50;
            if (k == 2) {
                fn_80011218();
                s->mA80 = 1;
            } else if (k == 1) {
                int x = fn_80044D3C(kind);
                char* b = (char*)s + 4;
                fn_80010754(x, fn_8001F45C(a, *(int*)(b + o)));
                s->mA80 = k;
            }
        }
    }
}

void fn_8004BF14(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (s->mA70 == 0) {
        int m = a->m4D8;
        int ok = 0;
        if (m == 0 || (m == 1 && (a->m3B0->m590 & 0x20000000)))
            ok = 1;
        if (ok != 0) {
            int o = idx * 0x48;
            char* b4 = (char*)s + 4;
            char* b8 = (char*)s + 8;
            int ent = *(int*)(b4 + o);
            int kind = *(int*)(b8 + o);
            int f = fn_80056D0C(0xE7);
            if (ent != 0 && f != 0) {
                Unk8024EF40_W* q = (Unk8024EF40_W*)(ent + 0x588);
                unsigned cnt = fn_80253DB0(q, 1, 0);
                if (fn_8004B6BC(s, idx, a) == 0) {
                    Unk8004BF14_R* r = (Unk8004BF14_R*)(ent + 0x58C);
                    int k = r->m38;
                    if (k == kind) {
                        if (!(r->m4 & 0x20000000)) {
                            int x = fn_80044D3C(k);
                            fn_800129DC(x, fn_8001F45C(a, ent));
                            if (fn_8005000C(s, idx, 0xA) == -1 && k != 3)
                                fn_80013024();
                            if (cnt > 1) {
                                fn_800B555C();
                                if (fn_800B57EC() == 1)
                                    fn_80253DB0(q, 1, 1);
                                if (rand() % 100 > 0x14) {
                                    int y = fn_80042FE4(cnt);
                                    fn_80011D6C(y, 0x1000, fn_8001F45C(a, ent));
                                } else {
                                    fn_80019348(0x4000);
                                }
                            }
                        }
                    } else if (!(r->m4 & 0x20000000)) {
                        fn_80014328();
                    }
                }
            }
        }
    }
}

void fn_8004C0E0(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (fn_8005000C(s, idx, 6) == -1) {
        char* b = (char*)s + 4;
        int o = idx * 0x48;
        fn_80013FD4(fn_80044D3C(*(int*)(b + o)));
    }
}

void fn_8004C3F4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    float v = fn_800547A4((Unk80052794_Ctx*)s, (unsigned char*)a, idx);
    char* b = (char*)s + 4;
    int k = *(int*)(b + idx * 0x48);
    if (k < a->m4D4) {
        int off = k * 0x18 + 0x48C;
        char* rec = (char*)a + off;
        if (fn_800507A8(s, idx, a) && !(v <= 0.67f)) {
            fn_80011430(fn_80044D3C(*(int*)(rec + 0xC)));
        } else {
            fn_80010934(fn_80044D3C(*(int*)(rec + 0xC)));
        }
        if (*(int*)(rec + 4))
            fn_8004B910(s, idx, a);
        fn_8004FCDC(s, idx, a);
    }
}

void fn_8004C4D0(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int o = idx * 0x48;
    char* b4 = (char*)s + 4;
    int k = *(int*)(b4 + o);
    if (k < a->m4D4) {
        int off = k * 0x18 + 0x48C;
        char* rec = (char*)a + off;
        if (*(int*)(rec + 4) != 0) {
            fn_8004B910(s);
            if (fn_8004B6BC(s, idx, a) == 0) {
                int m = a->m4D8;
                if (m == 2 && s->mA5C == 0 && a->m104 == 1) {
                    fn_8004E954(s, idx, a);
                } else if (m == 3 && s->mA60 == 0) {
                    fn_8004EAD4(s, idx, a);
                } else {
                    int t = fn_8005000C(s, idx, 0x59);
                    if (t != -1 && *(int*)(b4 + t * 0x48) == *(int*)(rec + 4))
                        fn_800109F4();
                    if (fn_800507D8(s, idx, a) != 0 || *(int*)(rec + 0xC) == 3) {
                        fn_80011378(fn_80044D3C(*(int*)(rec + 0xC)));
                    } else {
                        int x = fn_80044D3C(*(int*)(rec + 0xC));
                        int y = ((Unk8001CE80*)a)->fn_8001DE9C();
                        fn_800108C8(x, y, fn_8001F45C(a, *(int*)(rec + 8)));
                    }
                    if (*(int*)(rec + 0x10) == 1)
                        fn_80011534();
                }
                fn_8004FCDC(s, idx, a);
            }
        }
    }
}

void fn_8004C8E0(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    unsigned sa = 0;
    int t = a->m3B4;
    Unk80044C10_B* b = EntObj(s, idx);
    int o0 = t * 0xE64;
    unsigned char* base = (unsigned char*)b->m6F8->m14;
    sa = Unk8004BC9C_SumRow((Unk8004BC9C_Row*)(base + o0));
    int z = t == 0;
    int o1 = z * 0xE64;
    unsigned sb = Unk8004BC9C_SumRow((Unk8004BC9C_Row*)(base + o1));
    if (rand() % 10 == 5 && a->m0 > 1)
        fn_80011F78();
    Unk80044C10_A* g = a->m130;
    if (fn_800974B8((char*)b->m6F8->m14 + g->m708 * 0xE64, g->m704) != 0 && fn_80253DF4((Unk8024EF40_W*)((char*)a->m130 + 0x588), 1, 0) == 1)
        fn_800136D0();
    if (fn_80253DF4((Unk8024EF40_W*)((char*)a->m130 + 0x588), 1, 0) == 7 && a->m0 == 7 && sb < sa) {
        int x = fn_80045C8C(a->m130);
        fn_800135A4(x, ((Unk8001CE80*)a)->fn_8001DC58());
    }
    s->mA54 = 0;
    s->mA58 = (unsigned)rand() % 6;
    fn_80058060((Unk80057204_Mgr*)s->mA9C, 1);
}

void fn_8004CA98(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    fn_8004EB58(s, idx, a);
    fn_8004FA94(s, idx, a);
    fn_8004D56C(s, idx, a);
}

void fn_8004CAEC(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    fn_8004EB58(s, idx, a);
    fn_8004FA94(s, idx, a);
    fn_8004D56C(s, idx, a);
}

/* near-miss (96%): retail copies the loop offset (mr r9,r5; addi r5,r9,8) and increments in the order off, i */
void fn_8004CE04(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int f = fn_80056D0C(0xE7);
    char* b8 = (char*)s + 8;
    int o = idx * 0x48;
    char* b4 = (char*)s + 4;
    int ent = *(int*)(b4 + o);
    int kind = *(int*)(b8 + o);
    if (*(int*)(ent + 0x5C4) == kind && f != 0 && a->m54 == 1) {
        int m = a->m4D8;
        int ok = 0;
        if (m == 0 || (m == 1 && (a->m3B0->m590 & 0x20000000)))
            ok = 1;
        if (ok != 0) {
            int i = 0;
            int off = 0;
            for (; i <= 2; off += 8, i++) {
                char* p110 = (char*)a + 0x110;
                if (*(int*)(p110 + off) == Unk8004CE04_M4(s, idx)) {
                    char* p114 = (char*)a + 0x114;
                    if (*(int*)(p114 + off) > 1)
                        fn_80012AAC();
                    break;
                }
            }
            int r = fn_80253DB0((Unk8024EF40_W*)(Unk8004CE04_M4(s, idx) + 0x588), 1, 0);
            int fl = (r > 2) << 12;
            int x = fn_80044D3C(Unk8004CE04_M8(s, idx));
            fn_80012A40(x, 0x80, fl);
        }
    }
}

void fn_8004D56C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    Unk8004D56C_AV* v = (Unk8004D56C_AV*)a;
    if (v->m38 > 0 && a->m4D4 <= 2 && fn_8004FF78(s, s->m9D8, 3) == -1) {
        int f = 1;
        int t = fn_8004FF78(s, s->m9D8, 0x2A);
        if (t >= 0 && fn_8004FF78(s, t, 0x21) >= 0 && fn_8004FF78(s, s->m9D8, 0x38) == -1)
            f = 0;
        if (f != 0) {
            if (Unk8004D56C_At((char*)a + 0x13C, v->m274 * 0x28) != 0 && Unk8004D56C_At((char*)a + 0x134, v->m274 * 0x28) == 0) {
                if (a->m3D0 == 3) {
                    int i = 0;
                    Unk8004D56C_Slot* p = v->m70;
                    for (; i < v->m100; p++, i++) {
                        if (p->m0 != 0 && p->m8 == 0 && p->m4 == -1) {
                            fn_80014B00();
                            break;
                        }
                    }
                }
                if (v->m48 == 0) {
                    int n = v->m104;
                    if (n == 1 && v->m38 == 1) {
                        Unk8004D56C_Slot* q = v->m70;
                        if (q->m8 == q->m4 + 1)
                            fn_80016F84();
                    } else if (v->m104 > 1 && v->m38 == v->m104 && a->m4D8 == 0) {
                        int i = 0;
                        Unk8004D56C_Slot* q = v->m70;
                        for (; i < v->m104; q++, i++) {
                            if (q->m8 == q->m4 + 1) {
                                fn_8001702C(((Unk8001CE80*)a)->fn_8001DB4C());
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void fn_8004DC18(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    fn_80058FE4(s->mA9C, 2);
    fn_80058FE4(s->mA9C, 0x3C, a);
}

/* near-miss (99.33%): retail saves r29 too (stmw r29, frame 0x18) although nothing uses it; ours saves r30-r31 only (frame 0x10) */
void fn_8004DC60(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (fn_8004FF78(s, s->m9D8, 3) >= 0) {
        fn_80054684((Unk80052794_Ctx*)s, idx, 0);
        fn_80054684((Unk80052794_Ctx*)s, idx, 1);
    }
}

void fn_8004E010(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int w28 = fn_80253F0C((Unk8024EF40_W*)((char*)a->m3B0 + 0x588), 0xA, 2, 0);
    int w27 = 0;
    fn_800B555C();
    if (fn_800B57EC() == 1)
        w27 = fn_802540E4((Unk8024EF40_W*)((char*)a->m3B0 + 0x588), 0xA, 2);
    if (fn_8004FF78(s, s->m9D8, 0x47) == -1) {
        if (fn_8004FF78(s, s->m9D8, 0x63) != 0) {
            int sel = ((Unk8001CE80*)a)->fn_8001D5D8();
            int p = sel == 2 ? fn_8001F904(a) : fn_8001F8B8(a);
            fn_800120AC(sel, p, ((Unk8001CE80*)a)->fn_8001D62C());
            int q = sel == 2 ? ((Unk8001CE80*)a)->fn_8001E2EC() : ((Unk8001CE80*)a)->fn_8001E31C();
            int r = fn_80043004(w28);
            fn_80013530(r, fn_80043024(w27), sel, q);
        }
    }
}

/* near-miss (96%): m3CC+m3D0 sum registers swapped (retail loads m3CC into r9, sum in r0) */
void fn_8004E14C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (idx >= 0 && a->m3D0 < *lbl_8061B9C4 && a->m50 == 0 && ((Unk8004E14C_AV*)a)->m38 == 0) {
        fn_80058FE4(s->mA9C, 3);
        fn_80058FE4(s->mA9C, 0x3C, a);
        if (((Unk8004E14C_AV*)a)->m408 - 4 <= 3 && a->m40C == 1) {
            fn_8004FC60(s, a);
            return;
        }
        int ok = 0;
        if (((Unk8004E14C_SmV*)s)->mA54 == 0 && s->mA58 == 0) {
            int x = a->m3CC + a->m3D0;
            ok = x <= 2;
        }
        if (ok)
            fn_80052A34(s, idx, a);
    }
}

int fn_8004E248(Unk800493D4_Sm* s, int idx)
{
    int r = -1;
    int off = idx * 0x48;
    int k = *(int*)((char*)s + off);
    if (k == 0x14 || k == 0x1B || k == 8 || k == 0x1C || k == 0xE) {
        char* b = (char*)s + 4;
        r = *(int*)(b + off);
    }
    return r;
}

/* near-miss (96%): retail loads a->m3B0 into r4 (cmpw r4,r0); ours r11 */
void fn_8004E28C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int i = fn_8004FF78(s, s->m9D8, 0x1B);
    if (i != -1) {
        char* b = (char*)s + 4;
        int k = *(int*)(b + i * 0x48);
        int off = k * 0x18 + 0x48C;
        char* rec = (char*)a + off;
        if ((int)a->m3B0 == *(int*)(rec + 4) && *(int*)rec == 5) {
            char* p = ((Unk8004E28C_View*)a)->m120;
            if (p) {
                Unk8004EC18_Q* q = (Unk8004EC18_Q*)(p + 0x58C);
                if (q->m4 & 0x20000000) {
                    fn_80013868(fn_8001F3FC(a));
                } else if (q->m3C == 2 && ((Unk8004E28C_View*)a)->m44C > 0) {
                    int x = ((Unk8001CE80*)a)->fn_8001E054();
                    fn_800130DC(x, ((Unk8001CE80*)a)->fn_8001DB70());
                }
            }
        }
    }
}
