#ifndef GAME_TU_80050A68_H
#define GAME_TU_80050A68_H

#include "game/tu_8004E364.h"

/*
Types for game/tu_80050A68.cpp (see tu_800493D4.h for the Unk800493D4_Sm state machine).
*/

void fn_80011C38(Unk800493D4_Sm* s);
void fn_80011BE4();
void fn_80052FBC();
/* Empty handler (blr at 0x80052FBC); fn_80051014 keeps s and idx live in r3/r4 up to
 * the call, so it is called with the handler's (s, idx) arguments. */
void fn_80052FBC(Unk800493D4_Sm* s, int idx);
void fn_8000FD5C();
void fn_8000F6D4(int a);
void fn_8000FEBC();
void fn_80017C2C();
void fn_8001A450();
int fn_80044D3C(int a);
int fn_8005000C(Unk800493D4_Sm* s, int idx, int type);

struct Unk8024EF40_W;
struct Unk80052794_Rec;
struct Unk80052794_Obj;

/* Stack message record built by fn_800512FC: fn_80344624 fills the 3-word header; the payload words sit at +0x3C/+0x40. */
struct Unk80050A68_Msg {
    int m0;
    int m4;
    int m8;
    char padC[0x30];
    int m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
};

struct Unk80050A68_T16 {
    int v[16];
};
extern Unk80050A68_T16 lbl_805A928C;
extern int lbl_805B1634[];
int fn_80075E7C(int a);
void fn_8001A9C8(int a);
int fn_80044820(int a);
void fn_8001B064(int a, int b, int c, int d);
/* Event record passed as the third argument of fn_80052670 (m0: kind in the high halfword). */
struct Unk80050A68_Rec {
    int m0;
    char pad4[0x4];
    int m8;
    char padC[0x34];
    int m40;
};

void fn_800883E4(int a, int* b, int* c, int* d);
unsigned fn_80044FAC(unsigned a);
unsigned fn_80044FF0(unsigned a);
void fn_80019CE8(int a, int b);
void fn_8000FE0C();
void fn_800B555C();
int fn_800B57EC();
void fn_800521D0(Unk800493D4_Sm* s, int idx, Unk80050A68_Rec* r, int k);
void fn_80014ED4();
void fn_80014834(int a);
/* Another view of the third argument of the callbacks above: four 0x24-byte slots at +0x70 (m0 owner, m4, m8 state),
 * the slot count at +0x100. Evidence: fn_80050A68, fn_80050BCC. */
struct Unk80050A68_Slot {
    int m0;
    int m4;
    int m8;
    char padC[0x18];
};
struct Unk80050A68_Obj {
    unsigned char m0;
    unsigned char m1;
    char pad2[0x42];
    int m44;
    int m48;
    char pad4C[0x24];
    Unk80050A68_Slot m70[4];
    int m100;
    char pad104[0x2AC];
    int m3B0;
};
void fn_80011588(int a);
extern "C" int rand(void);
int fn_8001F510(Unk80044C10_A* a);
int fn_8001F788(Unk80044C10_A* a);
int fn_80046780(int a);
int fn_8004390C(int a);
void fn_80018E24(int a, int b, int c, int d);
void fn_80018E98(int a, int b, int c, int d);
void fn_80018FE4(int a, int b);
int fn_8001F954(Unk80044C10_A* a);
int fn_8001D974(Unk80044C10_A* a);
void fn_8001A664();
void fn_800119A4();
void fn_80010F3C(int a, int b);
void fn_8001014C(int a, int b, int c, int d);
int fn_8025416C(Unk8024EF40_W* w, int k);
int fn_80044270(Unk80044C10_Vec3* v);
void fn_80013724(int a);
void fn_8000F968(int a);
int fn_80042E58(int a);
int fn_8004475C(int a);
int fn_80044828(int a);
void fn_8001AF38(int a, int b, int c, int d);
int fn_80045E80(int a);
void fn_80018F0C(int a, int b);
void fn_8001467C(int a, int b, int c, int d);
void fn_80344624(Unk80050A68_Msg* m);
void fn_8005695C(Unk80050A68_Msg* m);
void fn_80057AD4(void* sink, Unk80052794_Rec* r, Unk80052794_Obj* o);

#endif
