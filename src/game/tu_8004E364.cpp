/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8004E364-0x80050A68 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_8004E364.h"
void fn_80012834();
int fn_80056D0C(int a);
void fn_80012784(int a);
float fn_8025454C(Unk8024EF40_W* w, int a);
int fn_80045F28(float f);
void fn_80012B8C(int a, int b);
struct Unk8004ECAC_Obj {
    char pad0[0x460];
    int m460;
};
struct Unk800500B8_AV {
    char pad0[0x28];
    int m28;
    int m2C;
    char pad30[0x104 - 0x30];
    int m104;
    char pad108[0x138 - 0x108];
    int m138;
    int m13C;
    int m140;
    char pad144[0x278 - 0x144];
    int m278;
    char pad27C[0x290 - 0x27C];
    int m290[16];
    char pad2D0[0x300 - 0x2D0];
    int m300[16];
    char pad340[0x410 - 0x340];
    int m410;
};
int fn_8001F64C(Unk80044C10_A* a);
int fn_8001F6C0(Unk80044C10_A* a);
void fn_80010630(int a, int b, int c, int d);
void fn_80012EAC(int a);
void fn_80012F08(int a);
void fn_80012F64(int a, int b);
void fn_80013CE4(int a, int b);
void fn_800172EC();
void fn_800B555C();
int fn_800B57EC();
void fn_80017AA4(int a, int b);
extern "C" int rand();
extern "C" int fn_800507A8(Unk80052794_Ctx* ctx, int idx);
int fn_80050D24(Unk800493D4_Sm* s, Unk80044C10_A* a);
int fn_800457E4(int a);
void fn_80010A48(int a);
void fn_80011324();
int fn_80047584(int a);
void fn_80017B74(int a, int b);
int fn_8009E1D4(void* p, int a, int b);
struct Unk8004FA94_AV {
    char pad0[0x20];
    int m20[2];
    char pad28[0x1C];
    int m44;
};
void fn_80017C80();
void fn_800154E0();
int fn_80044D28(int a);
void fn_80010448(int a, int b);
struct Unk8004F990_AV {
    char pad0[0x450];
    int m450;
};
void fn_80012418();
void fn_800125A0();
void fn_80012254();
void fn_80012050(int a);
void fn_800106F8(int a);

void fn_8004E954(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m4D8 == 2 && s->mA5C == 0) {
        float v = fn_800547A4((Unk80052794_Ctx*)s, (unsigned char*)a, idx);
        s->mA0C[a->m3B4 == 0]++;
        s->mA5C = 1;
        if (((int (*)(Unk800493D4_Sm*, int, Unk80044C10_A*))fn_800507A8)(s, idx, a) && !(v <= 0.34f) && a->m448 == 0) {
            fn_80011324();
        } else {
            fn_80010A48(fn_800457E4(fn_80050D24(s, a)));
        }
        if (rand() % 100 > 0x46) {
            int sum = s->mA0C[0] + s->mA0C[1];
            int o = a->m3B4 * 0xE64;
            int x = fn_8009E1D4((char*)a->m130->m44C->m6F8->m14 + o + 0x8C, 2, 0);
            fn_80017B74(fn_80047584(sum), x);
        }
        if (((Unk80069F0C*)a->m130->m44C->m6F8)->fn_8006BE18() != 0)
            fn_80050324(s, idx, a, 0, 0);
    }
}

void fn_8004EAD4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m4D8 == 3 && s->mA60 == 0) {
        s->mA60 = 1;
        fn_80010AA4();
        if (((Unk80069F0C*)a->m130->m44C->m6F8)->fn_8006BE18() != 0)
            fn_80050324(s, idx, a, 0, 0);
    }
}

void fn_8004EB58(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m4D8 > 0) {
        fn_8004FBE4(s, a);
        if (a->m4D8 == 2)
            fn_8004E954(s, idx, a);
        else if (a->m4D8 == 3)
            fn_8004EAD4(s, idx, a);
    }
}

/* near-miss: retail computes addi r9,r3,4 then lwzx (index in r0); here mulli/add/lwz 4(r9) */
void fn_8004EBD4(Unk800493D4_Sm* s, int idx)
{
    char* b = (char*)s + 4;
    if (idx >= 0 && *(int*)(b + idx * 0x48) != 0) {
        fn_8001A714();
        return;
    }
    fn_800106A4();
}

void fn_8004EC18(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m54 == 0 && a->m40C != 0) {
        char* b8 = (char*)s + 8;
        int off = idx * 0x48;
        if (*(int*)(b8 + off) == 1) {
            char* b4 = (char*)s + 4;
            Unk8004EC18_Q* q = (Unk8004EC18_Q*)(*(char**)(b4 + off) + 0x58C);
            if (((q->m4 & 0x20000000) != 0 || q->m3C == 0) && (a->m3BC == 0 || a->m3E8 != 0) && s->mA84 == 0)
                fn_80013AE8();
        }
    }
}

void fn_8004ECAC(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (fn_80056D0C(0xB8) != 0 || rand() % 100 <= 0x32) {
        int e = fn_8004FF78(s, s->m9D8, 0x59);
        if (e != -1 && s->mA50 == 0) {
            int e2 = fn_8004FF78(s, s->m9D8, 0x1C);
            if (e2 != -1) {
                char* b = (char*)s + 4;
                int o2 = e2 * 0x48;
                int o1 = e * 0x48;
                int k = *(int*)(b + o2);
                char* ba = (char*)a + 0x490;
                int off = k * 0x18;
                if (*(int*)(ba + off) == *(int*)(b + o1)) {
                    fn_80012834();
                    s->mA50 = 1;
                }
            }
        } else if (fn_8004FF78(s, s->m9D8, 3) == -1 && fn_8004FF78(s, s->m9D8, 0x10) == -1) {
            int v = 0;
            if (fn_8005000C(s, idx, 0x3C) >= 0) {
                int t = fn_8004FF78(s, s->m9D8, 0xA);
                if (t != -1) {
                    char* b = (char*)s + 4;
                    Unk8004ECAC_Obj* ob = *(Unk8004ECAC_Obj**)(b + t * 0x48);
                    v = (ob->m460 == 1) * 2;
                }
            }
            if (fn_8005000C(s, idx, 0x11) >= 0)
                v = 2;
            fn_80012784(v);
            if (v != 2) {
                float f = -1.0f;
                int t2 = fn_8005000C(s, idx, 0xA);
                if (t2 >= 0) {
                    char* b = (char*)s + 4;
                    int o = t2 * 0x48;
                    int ent = *(int*)(b + o);
                    if (ent != 0)
                        f = fn_8025454C((Unk8024EF40_W*)(ent + 0x588), 0xE);
                    int r = fn_80045F28(f);
                    fn_80012B8C(r, fn_8001F45C(a, *(int*)(b + o)));
                }
            }
            fn_8004E68C(s, idx, a);
        }
    }
}

void fn_8004F990(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (s->mA48 == 0 && fn_8005000C(s, s->m9DC, 0x38) != 0) {
        int t = fn_8005000C(s, s->m9DC, 0x20);
        if (t >= 0) {
            char* b = (char*)s + 4;
            if (*(int*)(b + t * 0x48) == (int)a->m3B0)
                fn_80012418();
        } else if (fn_8004FF78(s, s->m9D8, 0x28) >= 0 && ((Unk8004F990_AV*)a)->m450 > 0) {
            fn_800125A0();
        } else if (fn_8004FF78(s, s->m9D8, 0x27) >= 0) {
            fn_80012254();
        }
        if (fn_8004FF78(s, s->m9D8, 0x2B) >= 0) {
            fn_80012050(0);
        } else {
            fn_800106F8(((Unk8001CE80*)a)->fn_8001D694());
        }
        s->mA48 = 1;
    }
}

void fn_8004FA94(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int o = idx * 0x48;
    int e = *(int*)((char*)s + o) != 0x38 ? fn_8005000C(s, idx, 0x38) : idx;
    int f = *(int*)((char*)s + o) != 0x55 ? fn_8005000C(s, idx, 0x55) : idx;
    int eq = 0;
    if (e != -1 && f != -1) {
        int of = f * 0x48;
        char* b10 = (char*)s + 0x10;
        if (*(int*)(b10 + of) == 1) {
            char* b = (char*)s + 4;
            eq = *(int*)(b + e * 0x48) == *(int*)(b + of);
        }
    }
    if (((Unk8004FA94_AV*)a)->m44 > 0 && s->mA4C == 0) {
        if (eq) {
            fn_80017C80();
        } else if (e != -1) {
            if (fn_8005000C(s, idx, 0x2D) >= 0) {
                fn_800154E0();
            } else {
                int x = fn_80044D28(((Unk8004FA94_AV*)a)->m20[a->m3B4 == 0]);
                char* b = (char*)s + 4;
                fn_80010448(x, fn_8001F45C(a, *(int*)(b + e * 0x48)));
            }
        }
        s->mA4C = 1;
    }
}

void fn_8004FBE4(Unk800493D4_Sm* s, Unk80044C10_A* a)
{
    if (a->m3D0 < *lbl_8061B9C4 && a->m448 == 4 && a->m4D4 <= 2 && s->mAB4 == 0) {
        fn_80058FE4(s->mA9C, 0x3D, a);
        s->mAB4 = 1;
    }
}

void fn_8004FC60(Unk800493D4_Sm* s, Unk80044C10_A* a)
{
    if (a->m3D0 < *lbl_8061B9C4 && a->m448 == 4 && a->m4D4 <= 2 && s->mAB8 == 0) {
        fn_80058FE4(s->mA9C, 0x2A, a);
        s->mAB8 = 1;
    }
}

void fn_8004FEA4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (idx >= 0 && a->m4D4 == 3 && a->m50 == 0) {
        Unk80044C10_C* c = EntObj(s, idx)->m6F8;
        if (a->m1 == 1 && a->m4 == 0 && a->mC > 0) {
            Unk80044C10_E* e = c->m14;
            char* rec = (char*)e + a->m130->m708 * 0xE64;
            int f = *(int*)(rec + 0x198);
            fn_80015700(fn_8001F764(a), f);
        }
    }
    if (a->m4D4 <= 2)
        fn_80058FE4(s->mA9C, 4, a);
    fn_8004E68C(s, idx, a);
}

int fn_8004FF78(Unk800493D4_Sm* s, int idx, int type)
{
    int r = -1;
    if ((unsigned)idx <= 0x22 && *(int*)((char*)s + idx * 0x48) != 0x16 && idx != s->m9E0) {
        int i = idx;
        for (;;) {
            i = fn_80050094(s, i);
            int k = *(int*)((char*)s + i * 0x48);
            if (type == k) {
                r = i;
                break;
            }
            if (k == 0x16)
                break;
            if (i == s->m9E0)
                break;
        }
    }
    return r;
}

int fn_8005000C(Unk800493D4_Sm* s, int idx, int type)
{
    int r = -1;
    if ((unsigned)idx <= 0x22 && *(int*)((char*)s + idx * 0x48) != 0x15) {
        int i = idx;
        for (;;) {
            i = fn_800500A8(s, i);
            int k = *(int*)((char*)s + i * 0x48);
            if (type == k) {
                r = i;
                break;
            }
            if (k == 0x15)
                break;
            if (i == s->m9E0)
                break;
        }
    }
    return r;
}

int fn_80050094(Unk800493D4_Sm* s, int i)
{
    int n = i + 1;
    if (n > 0x22)
        n = 0;
    return n;
}

int fn_800500A8(Unk800493D4_Sm* s, int i)
{
    int n = i - 1;
    if (n < 0)
        n = 0x22;
    return n;
}

void fn_800500B8(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    Unk800500B8_AV* v = (Unk800500B8_AV*)a;
    if (idx >= 0 && fn_8004FF78(s, s->m9D8, 0x25) == -1 && fn_8004FF78(s, s->m9D8, 0x1C) == -1 && v->m410 == 0) {
        int sel = ((Unk8001CE80*)a)->fn_8001D5D8();
        int p = sel == 2 ? fn_8001F904(a) : fn_8001F8B8(a);
        int x = fn_8001E664(a);
        fn_80010630(x, sel, p, ((Unk8001CE80*)a)->fn_8001D62C());
        if (v->m278 > 6) {
            int y = ((Unk8001CE80*)a)->fn_8001D7F8();
            fn_80013CE4(y, ((Unk8001CE80*)a)->fn_8001D5D8());
        }
        int k = a->m3B4;
        if (((k == 0 && v->m28 > 1) || (k == 1 && v->m2C > 1)) && v->m104 == 3)
            fn_80012F64(0xA0000, 1);
        if (v->m278 <= 8) {
            if (v->m140 != 0)
                fn_80012EAC(((Unk8001CE80*)a)->fn_8001D5D8());
            else if (v->m138 != 0)
                fn_80012F08(((Unk8001CE80*)a)->fn_8001D5D8());
        }
        fn_800B555C();
        if (fn_800B57EC() != 0 && rand() % 100 > 0x46) {
            int z = fn_8001F64C(a);
            fn_80017AA4(z, fn_8001F6C0(a));
        }
        int lim = 4;
        int o = a->m130->m708 * 4;
        char* b300 = (char*)a + 0x300;
        char* b290 = (char*)a + 0x290;
        int tv = *(int*)(b300 + o);
        if (*(int*)(b290 + o) != 0)
            lim = 6;
        if (tv > lim && s->mAC0 <= 0) {
            fn_800172EC();
            s->mAC0 = s->mAC0 + 1;
        }
    }
}

void fn_800502D4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    float sp8;
    float spC;
    ((Unk8001CE80*)a)->fn_8001CEA8(&spC, &sp8);
    if (a->m104 <= 2)
        fn_80010EE0(fn_8001E664(a));
}

void fn_80050324(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a, int b, int c)
{
    if (s->mA70 == 0) {
        int x = ((Unk8001CE80*)a)->fn_8001D538();
        int y = ((Unk8001CE80*)a)->fn_8001DC88();
        fn_80010C34(c, x, y, ((Unk8001CE80*)a)->fn_8001DCCC());
        s->mA70 = 1;
    }
}

void fn_8005039C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    if (a->m4D4 == 2 && a->m4D8 == 0) {
        int x = ((Unk8001CE80*)a)->fn_8001E054();
        fn_800178A0(x, ((Unk8001CE80*)a)->fn_8001DB4C());
    }
}

struct Unk80052794_Ctx;

int fn_8005481C(Unk80052794_Ctx* ctx, int idx);

extern "C" int fn_800507A8(Unk80052794_Ctx* ctx, int idx)
{
    return fn_8005481C(ctx, idx) <= 3;
}

int fn_800507D8(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    float f = fn_800547A4((Unk80052794_Ctx*)s, (unsigned char*)a, idx);
    int r = 0;
    if (((int (*)(Unk800493D4_Sm*, int, Unk80044C10_A*))fn_800507A8)(s, idx, a) != 0)
        r = f > 0.67f;
    return r;
}

int fn_80050850(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a)
{
    int r = 0;
    if (fn_800507D8(s, idx, a) != 0 && a->m104 > 0)
        r = 1;
    return r;
}
