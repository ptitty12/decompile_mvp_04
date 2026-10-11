/*
 * Types shared by game/tu_801EE438.cpp .. game/tu_8020ADC4.cpp (reconstructed,
 * placeholder names; nothing here comes from original headers).
 *
 * These units are front-end/game "screen" code. A screen object has a pointer
 * to a large context object G at +0x9C (and a second view of the same context
 * at +0 in some screens). Evidence: tu_801EE438 getters/setters load
 * 0x9C(screen) then a field of G (+0x1B8, +0x1BC, +0x1CC, +0x1D0), and
 * fn_80205450(G, i) stores i at G+0x3A5C and &G[0xCA8 + i*0x514] at G+0x3A60.
 */
#ifndef GAME_TU_801EE438_H
#define GAME_TU_801EE438_H

struct Unk801EE438_Player;

struct Unk801EE438_Vec {           /* 12-byte vector, passed by value (copied by the caller) */
    float m0;
    float m4;
    float m8;
};

struct Unk801EE438_Sub {           /* 0x14 bytes, G+0xC0 and G+0xD4 */
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

struct Unk801EE438_Ent {           /* 0xD8 bytes, Slot+4 + i*0xD8 */
    int m0;                        /* kind (switch in fn_80204E58 / fn_80204F8C) */
    int m4;
    char pad8[0x1C - 8];
    int m1C;
    char pad20[0xA8 - 0x20];
    int mA8;
    char padAC[0xD8 - 0xAC];
};

struct Unk801EE438_Slot {          /* stride 0x514 = 4 + 6 * 0xD8, G+0xCA8 */
    int m0;                        /* entry count */
    Unk801EE438_Ent m4[6];
};

struct Unk801EE438_It {            /* iterator (24 bytes) filled by fn_8014E09C; m8 = current (10 = end) */
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

struct Unk801EE438_Game {           /* G->m4 */
    char pad0[0x36C];
    Unk801EE438_Player* m36C;
    char pad370[0x374 - 0x370];
    Unk801EE438_Player* m374;
    Unk801EE438_Player* m378;
    char pad37C[0x38C - 0x37C];
    int m38C;
};

struct Unk801EE438_Sub6A8 {        /* fn_80204AC8(&G->m6A8) */
    int m0;
};

struct Unk801EE438_Ent18 {         /* 0x18 bytes, G+0x1DC (9 entries) */
    int m0;
    int m4;
    float m8;
    float mC;
    float m10;
    void* m14;
};

struct Unk801EE438_Rec2C {         /* stride 0x2C, G+0x3DC (indices 9..12 used) */
    int m0;
    char pad4[0x24 - 4];
    int m24;
    char pad28[4];
};

struct Unk801EE438_Sub2B4 {        /* G+0x2B4 */
    float m0;
    char pad4[0x128 - 4];
    Unk801EE438_Rec2C m128[8];     /* really indexed 9..12 (guarded); the tail overlaps m2AC */
    char pad288[0x2AC - 0x288];
    int m2AC;                      /* G+0x560 */
    char pad2B0[0x364 - 0x2B0];
};

struct Unk801EE438_Rec14 {         /* stride 0x14, G+0x62C (4 entries) */
    int m0;
    float m4;
    float m8;
    int mC;
    int m10;
};

struct Unk801EE438_Rec5C {         /* stride 0x5C, G+0x6B8 (10 entries) */
    char pad0[0x50];
    float m50;
    char pad54[0x5C - 0x54];
};

struct Unk801EE438_Player {         /* G->m8[i] */
    char pad0[0x60];
    float m60;
    float m64;
    float m68;
    char pad6C[0x460 - 0x6C];
    int m460;                       /* index */
    char pad464[0x4D8 - 0x464];
    int m4D8;                       /* sub-object starts here (address passed to fn_8024FC74) */
    char pad4DC[0x58C - 0x4DC];
    int m58C;
};

struct Unk801EE438_O700 {
    char pad0[0x3B4];
    int m3B4;
};

struct Unk801EE438_Owner {
    char pad0[0x4C];
    unsigned m4C;
    char pad50[0x65C - 0x50];
    Unk801EE438_Player* m65C[13];
    char pad690[0x6CC - 0x690];
    Unk801EE438_Game* m6CC;
    char pad6D0[0x6F8 - 0x6D0];
    struct Unk802028E4_Y* m6F8;
    char pad6FC[4];
    Unk801EE438_O700* m700;
};

struct Unk801EE438_G {
    Unk801EE438_Owner* m0;
    Unk801EE438_Game* m4;
    Unk801EE438_Player* m8[10];
    int m30;
    int m34;
    int m38;
    char pad3C[0x44 - 0x3C];
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
    int m5C;
    int m60;
    char pad64[0x6C - 0x64];
    int m6C;
    char pad70[0xA4 - 0x70];
    int mA4;
    char padA8[0xC0 - 0xA8];
    Unk801EE438_Sub mC0;
    Unk801EE438_Sub mD4;
    int mE8;                       /* sub-object (address passed to fn_80211D34) */
    char padEC[0x1B8 - 0xEC];
    int m1B8;
    int m1BC;
    int m1C0;
    int m1C4;
    int m1C8;
    int m1CC;
    int m1D0;
    char pad1D4[0x1D8 - 0x1D4];
    int m1D8;                      /* entry count */
    Unk801EE438_Ent18 m1DC[9];
    Unk801EE438_Sub2B4 m2B4;
    char pad618[0x62C - 0x618];
    Unk801EE438_Rec14 m62C[4];
    char pad67C[0x6A8 - 0x67C];
    Unk801EE438_Sub6A8 m6A8;
    char pad6AC[0x6B8 - 0x6AC];
    Unk801EE438_Rec5C m6B8[10];
    char pad_A50[0xC4C - 0xA50];
    Unk801EE438_Vec mC4C;
    char padC58[0xC80 - 0xC58];
    float mC80;
    char padC84[0xC88 - 0xC84];
    int mC88;
    int mC8C;
    char padC90[0xCA4 - 0xC90];
    int mCA4;
    Unk801EE438_Slot mCA8[9];
    int m3A5C;
    Unk801EE438_Slot* m3A60;
    int m3A64;
    int m3A68;
    int m3A6C;
};

struct Unk801EE438_Scr {
    Unk801EE438_G* m0;
    char pad4[0x9C - 4];
    Unk801EE438_G* m9C;
    char padA0[0xE8 - 0xA0];
    float mE8;
    char padEC[0xF4 - 0xEC];
    float mF4;
};

struct Unk801EE438_Sel {           /* G->m3A64 viewed as an object (fn_801E816C / fn_801E82CC take it) */
    char pad0[0x794];
    int m794;
    int m798;
};

struct Unk801EE438_Scr;
extern "C" {
int fn_801E816C(Unk801EE438_Sel* o, int a);
int fn_801E82CC(Unk801EE438_Sel* o, int a);
void fn_80213988(Unk801EE438_Scr* p, int a, int b);
int fn_801EE6F4(Unk801EE438_Scr* p, int a);
void fn_8024FBEC(int* p, int a);
int fn_80259C50(int h, int e);
int fn_80254EA4(int* p, int a);
void fn_8024FC94(int* p);
unsigned fn_8014E2B4(int e);
int fn_80216590(Unk801EE438_Scr* p, int a, Unk801EE438_Vec v, int b, int c, int d);
void fn_8020E074(Unk801EE438_Scr* p, int a1, int a2, const Unk801EE438_Vec& v, int t, int a7, int a8);
void fn_8020E2A0(Unk801EE438_Scr* p, int a1, int a2, const Unk801EE438_Vec& v, int t, int a7, int a8, int a9);
void fn_8020E71C(Unk801EE438_Scr* p, int a1, int a2, const Unk801EE438_Vec& v, int t);
void fn_8020E8B4(Unk801EE438_Scr* p, int a1, int a2, const Unk801EE438_Vec& v, int t, int a7);
int fn_80248488(int a, int b, int c, int d, int e, int f, int g);
void fn_802049E8(Unk801EE438_Rec5C* r);
void fn_80212054(Unk801EE438_Sub2B4* s);
void fn_80209AC0(Unk801EE438_Scr* p, int a);
void fn_80209EEC(Unk801EE438_Scr* p, int a);
void fn_8020A654(Unk801EE438_Scr* p, int a);
void fn_8020A90C(Unk801EE438_Scr* p, int a);
void fn_8020B00C(Unk801EE438_Scr* p, int a);
void fn_80201738(Unk801EE438_G* g);
void fn_802121D0(int* s);
void fn_80204AC8(Unk801EE438_Sub6A8* s);
Unk801EE438_Player* fn_801EDE4C(Unk801EE438_Scr* p, Unk801EE438_Game* g);
void fn_801F2668(Unk801EE438_Scr* p, void* out, void* v, int k);
void fn_8024FC74(void* sub, int a);
void fn_8014E09C(Unk801EE438_It* it, Unk801EE438_Owner* owner, int k);
void fn_8014E108(Unk801EE438_It* it);
void fn_80205450(Unk801EE438_G* g, int i);
void fn_80211B58(Unk801EE438_Sub* s);
void fn_802123D4(Unk801EE438_Scr* p, int a, int b);
void fn_8021B6EC(Unk801EE438_Scr* p, int a, int b);
void fn_8021BA44(Unk801EE438_Scr* p);
void fn_8021C4E0(Unk801EE438_Scr* p);
void fn_8021CE28(Unk801EE438_Scr* p, float f);
void fn_801F0EA8(Unk801EE438_Scr* p, int a);
int fn_801E817C(int x);
int fn_801E82DC(int x, int slot);
int fn_80204E58(Unk801EE438_Ent* e);
int fn_80204F8C(Unk801EE438_Ent* e);
int fn_80211BB0(Unk801EE438_Sub* s, int a);
void fn_80211BA0(Unk801EE438_Sub* s, int a);
}
#endif
