/*
 * Database overlay code, .database_codeoverlay 0x805A2604-0x805A2BB0 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

struct U {
    char pad0[0x4000];
};

#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))

extern char lbl_806837B8[];

extern "C" void fn_80377408(void* p);

extern "C" DB_OVERLAY int fn_805A2604()
{
    return 4;
}

extern "C" DB_OVERLAY int fn_805A260C()
{
    return 1;
}

extern "C" DB_OVERLAY int fn_805A2614()
{
    return 4;
}

struct SlotB8 {
    char pad0[0xB8];
    int mB8[1];
};

extern "C" DB_OVERLAY void fn_805A261C(SlotB8* self, int i, int v)
{
    self->mB8[i] = v;
}

extern "C" DB_OVERLAY void fn_805A262C(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A2660()
{
    return 12;
}

extern "C" DB_OVERLAY int fn_805A2668()
{
    return 7;
}

extern "C" DB_OVERLAY void fn_805A2670(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A26A4()
{
    return 14;
}

extern "C" DB_OVERLAY int fn_805A26AC()
{
    return 1;
}

extern "C" DB_OVERLAY int fn_805A26B4()
{
    return 0;
}

extern "C" DB_OVERLAY void fn_805A26BC(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A26F0()
{
    return 0;
}

extern "C" DB_OVERLAY int fn_805A26F8()
{
    return 0;
}

extern "C" DB_OVERLAY int fn_805A2700()
{
    return 0;
}

extern "C" DB_OVERLAY void fn_805A2708(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A273C()
{
    return 13;
}

extern "C" DB_OVERLAY int fn_805A2744()
{
    return 2;
}

extern "C" DB_OVERLAY int fn_805A274C()
{
    return 4;
}

extern "C" DB_OVERLAY void fn_805A2754(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A2788()
{
    return 10;
}

extern "C" DB_OVERLAY int fn_805A2790()
{
    return 8;
}

extern "C" DB_OVERLAY int fn_805A2798()
{
    return 1;
}

extern "C" DB_OVERLAY void fn_805A27A0(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A27D4()
{
    return 8;
}

extern "C" DB_OVERLAY int fn_805A27DC()
{
    return 5;
}

extern "C" DB_OVERLAY void fn_805A27E4(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A2818()
{
    return 9;
}

extern "C" DB_OVERLAY int fn_805A2820()
{
    return 2;
}

extern "C" DB_OVERLAY int fn_805A2828()
{
    return 4;
}

extern "C" DB_OVERLAY int fn_805A2830()
{
    return 0;
}

extern "C" DB_OVERLAY void fn_805A2838(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A286C()
{
    return 6;
}

extern "C" DB_OVERLAY int fn_805A2874()
{
    return 16;
}

extern "C" DB_OVERLAY int fn_805A287C()
{
    return 3;
}

extern "C" DB_OVERLAY void fn_805A2884(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A28B8()
{
    return 7;
}

extern "C" DB_OVERLAY int fn_805A28C0()
{
    return 4;
}

extern "C" DB_OVERLAY void fn_805A28C8(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A28FC()
{
    return 5;
}

extern "C" DB_OVERLAY int fn_805A2904()
{
    return 1;
}

extern "C" DB_OVERLAY int fn_805A290C()
{
    return 0;
}

extern "C" DB_OVERLAY void fn_805A2914(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A2948()
{
    return 3;
}

extern "C" DB_OVERLAY int fn_805A2950()
{
    return 2;
}

extern "C" DB_OVERLAY void fn_805A2958(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A298C()
{
    return 1;
}

extern "C" DB_OVERLAY int fn_805A2994()
{
    return 14;
}

extern "C" DB_OVERLAY int fn_805A299C()
{
    return 0;
}

extern "C" DB_OVERLAY void fn_805A29A4(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A29D8()
{
    return 2;
}

extern "C" DB_OVERLAY int fn_805A29E0()
{
    return 1;
}

extern "C" DB_OVERLAY void fn_805A29E8(U* self, int chrg)
{
    PUT(0x4, lbl_806837B8);
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY int fn_805A2A1C()
{
    return 15;
}

extern "C" DB_OVERLAY int fn_805A2A24()
{
    return 5;
}

extern "C" DB_OVERLAY int fn_805A2A2C()
{
    return 0;
}

struct DtorAt14 { char pad[0x14]; const void* m; };

extern "C" void fn_805943A0(void* self, int a);

extern char lbl_80682CC8[];

extern "C" DB_OVERLAY void fn_805A2A34(DtorAt14* self, int a)
{
    self->m = lbl_80682CC8;
    fn_805943A0(self, a);
}

struct DtorAt1C { char pad[0x1c]; const void* m; };

extern char lbl_80682C50[];

extern "C" void fn_80593DD8(void* self, int a);

extern "C" DB_OVERLAY void fn_805A2A64(DtorAt1C* self, int a)
{
    self->m = lbl_80682C50;
    fn_80593DD8(self, a);
}

extern char lbl_80682960[];

extern "C" DB_OVERLAY void fn_805A2A94(DtorAt1C* self, int a)
{
    self->m = lbl_80682960;
    fn_80593DD8(self, a);
}

extern char lbl_80682910[];

extern "C" DB_OVERLAY void fn_805A2AC4(DtorAt1C* self, int a)
{
    self->m = lbl_80682910;
    fn_80593DD8(self, a);
}

extern char lbl_806828C8[];

extern "C" DB_OVERLAY void fn_805A2AF4(DtorAt14* self, int a)
{
    self->m = lbl_806828C8;
    fn_805943A0(self, a);
}

extern char lbl_80682878[];

extern "C" DB_OVERLAY void fn_805A2B24(DtorAt1C* self, int a)
{
    self->m = lbl_80682878;
    fn_80593DD8(self, a);
}

extern char lbl_80682830[];

extern "C" DB_OVERLAY void fn_805A2B54(DtorAt14* self, int a)
{
    self->m = lbl_80682830;
    fn_805943A0(self, a);
}

extern "C" void fn_805A07C4(int a, int b);

extern "C" DB_OVERLAY void fn_805A2B84()
{
    fn_805A07C4(1, 0xFFFF);
}
