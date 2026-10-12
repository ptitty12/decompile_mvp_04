#ifndef GAME_TU_800493D4_H
#define GAME_TU_800493D4_H

#include "game/tu_80047B08.h"

/*
Types for game/tu_800493D4.cpp (see tu_80044C10.h for the shared game object).

Unk800493D4_Sm is the state-machine object whose methods fill 0x800493D4..0x8004B6BC:
entries of 0x48 bytes start at +0 (entry i holds the game object pointer at
+0x3C), +0x9DC holds a current index, and +0xA9C a message sink pointer
(shared with the Unk80048A10_Sub at the manager's +0xFC).
*/

struct Unk800493D4_Sm;

struct Unk800493D4_Sm {
    char pad0[0x9D8];
    int m9D8;
    int m9DC;
    int m9E0;
    char pad9E4[0x20];
    int mA04;
    int mA08;
    int mA0C[2];
    int mA14[3];
    int mA20;
    int mA24;
    char padA28[0xC];
    int mA34;
    char padA38[0x10];
    int mA48;
    int mA4C;
    int mA50;
    int mA54;
    int mA58;
    int mA5C;
    int mA60;
    char padA64[0x4];
    int mA68;
    int mA6C;
    int mA70;
    int mA74;
    int mA78;
    int mA7C;
    int mA80;
    int mA84;
    int mA88;
    char padA8C[0x4];
    int mA90;
    int mA94;
    int mA98;
    void* mA9C;
    char padAA0[0x10];
    int mAB0;
    int mAB4;
    int mAB8;
    int mABC;
    int mAC0;
    char padAC4[0x20];
};

struct Unk80256C80_M;

/* Placeholder view of the class whose method fn_8006BE18 takes the +0x6F8 record (Unk80044C10_C) as this. */
class Unk80069F0C {
public:
    int fn_8006BE18();
};

/* Placeholder view of the game object's methods (Unk80044C10_A is the same object); fn_8001D6CC returns the value
 * of its tail call (callers pass r3 on). */
class Unk8001CE80 {
public:
    int fn_8001D6CC();
    int fn_8001D694();
    int fn_8001D5D8();
    int fn_8001E054();
    int fn_8001DB4C();
    int fn_8001DE9C();
    int fn_8001D204(int v);
    int fn_8001D538();
    int fn_8001DC88();
    int fn_8001DCCC();
    int fn_8001D70C();
    int fn_8001DA28();
    int fn_8001DB70();
    void fn_8001CEA8(float* b, float* a);
};

struct Unk80044C10_F {
    char pad0[0x3B4];
    Unk80256C80_M* m3B4;
};

/* Entry i of the state machine: Sm + i*0x48 (m0 kind, m4/m8 object pointers, mC id). Evidence: fn_8004AEF4. */
struct Unk800493D4_Ent {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    char pad14[0x34];
};

/* Third argument of fn_8004ADE4: a record of four 0x24-byte slots at +0x70 whose first word points to a
 * 0x8E8-byte object, and the slot count at +0x100. */
struct Unk8004ADE4_Slot {
    struct Unk8004ADE4_Obj* m0;
    char pad4[0x20];
};
struct Unk8004ADE4_Obj {
    char pad0[0x8E8];
    float m8E8;
};
struct Unk8004ADE4_Arg {
    char pad0[0x70];
    Unk8004ADE4_Slot m70[4];
    int m100;
};

/* The game object of entry idx (the pointer at Sm + 0x3C + idx*0x48). */
static inline Unk80044C10_B* EntObj(Unk800493D4_Sm* s, int idx)
{
    char* b = (char*)s + 0x3C;
    int o = idx * 0x48;
    return *(Unk80044C10_B**)(b + o);
}

int fn_80058FE4(void* sink, int msg); /* returns 1 (li r3,1 at 0x800596BC) */
int fn_80058FE4(void* sink, int msg, Unk80044C10_A* a);
void fn_8004FCDC(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
void fn_8004B910(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
void fn_80011890();
void fn_8000F670(int a, int b);
int fn_8001F4F0(Unk80044C10_A* a);
int fn_8001E054(Unk80044C10_A* a);
void fn_80046078(Unk80044C10_B* b);
void fn_801A6D84(Unk80044C10_A* a, int b);
int fn_8016B9F4();
int fn_8006BE18(Unk80044C10_C* c);
void fn_8004B5C0(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
void fn_80057B54(void* sink, int a);
int fn_80258C90(Unk80256C80_M* m);
void fn_8000F808();
struct Unk80043884_Obj;
int fn_80043884(Unk80043884_Obj* o);
void fn_80050324(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a, int b, int c);
int fn_8001F904(Unk80044C10_A* a);
int fn_8001F8B8(Unk80044C10_A* a);
void fn_80010548(int a, int b);
void fn_80015BDC();
void fn_80011160(int a);
int fn_8004FF78(Unk800493D4_Sm* s, int a, int b);
int fn_8005000C(Unk800493D4_Sm* s, int idx, int type);
int fn_80044D3C(int a);
void fn_80013FD4(int a);
void fn_8004EB58(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
void fn_8004FA94(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
void fn_8004D56C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
struct Unk80052794_Ctx;
int fn_80054684(Unk80052794_Ctx* c, int idx, int k);
void fn_800178A0(int a, int b);
int fn_8001E664(Unk80044C10_A* a);
void fn_80010EE0(int a);
void fn_80010AA4();
void fn_80010C34(int a, int b, int c, int d);
float fn_800547A4(Unk80052794_Ctx* c, unsigned char* p, int idx);
void fn_8004E954(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
void fn_80013AE8();
void fn_8000F794(int a, int b, int c, int d);
void fn_8000F85C(int a);
int fn_8001F764(Unk80044C10_A* a);
void fn_80015700(int a, int b);
void fn_8004E68C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
int fn_80050094(Unk800493D4_Sm* s, int i);

/* Record at (object + 0x58C): flags word at +4, a count at +0x3C. Evidence: fn_8004EC18. */
struct Unk8004EC18_Q {
    char pad0[0x4];
    unsigned m4;
    char pad8[0x34];
    int m3C;
};
void fn_8004FBE4(Unk800493D4_Sm* s, Unk80044C10_A* a);
int fn_800500A8(Unk800493D4_Sm* s, int i);
void fn_8004EAD4(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
int fn_800507D8(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
void fn_8005039C(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
int fn_80050850(Unk800493D4_Sm* s, int idx, Unk80044C10_A* a);
void fn_80012988();
void fn_80017130();
float fn_804028E4(float x);
extern int lbl_8061B9C8;
int fn_8001F3FC(Unk80044C10_A* a, int k);
int fn_8001F45C(Unk80044C10_A* a, int k);
int fn_8001D8DC(Unk80044C10_A* a);
void fn_800119F8(int a, int b, int c);

#endif
