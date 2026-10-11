#ifndef GAME_TU_80052794_H
#define GAME_TU_80052794_H

/*
 * Shared placeholder types and callee prototypes for the code-only units
 * game/tu_80052794 .. game/tu_8005D268 (AI / event callbacks in the game TU
 * 0x8000F598..0x8006902C). Nothing here comes from original headers; layouts
 * contain only the fields the units actually touch.
 */

struct Unk80052794_Ctx;
struct Unk80052794_Obj;
struct Unk80052794_S130;
struct Unk80052794_S44C;
struct Unk80052794_S6CC;
struct Unk80052794_S6F8;
struct Unk80052794_S10;
struct Unk80052794_S700;
struct Unk80052794_S3B0;
struct Unk80052794_Entry;
struct Unk80052794_Row;

/* Element of the 0x48-byte records at Ctx+4. Evidence: fn_800527DC (m38), fn_80052FE0 (m4), fn_800533A0 (m0, m4, m8, mC). */
struct Unk80052794_Entry {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[0x28];
    Unk80052794_S44C* m38;
    char pad3C[0xC];
};

/* Context passed as the first argument of the AI/event callbacks in 0x80052794..0x8005DF2C (placeholder). Evidence: fn_800527DC, fn_80052908, fn_800533A0. */
struct Unk80052794_Ctx {
    int m0;
    Unk80052794_Entry m4[33];
    char pad94C[0x8C];
    int m9D8;
    char pad9DC[0x4];
    int m9E0;
    char pad9E4[0x54];
    int mA38[7];
    int mA54;
    char padA58[0x44];
    int mA9C;
};

struct Unk80052794_S10 {
    char pad0[0x1C];
    unsigned m1C;
};

/* One 0xE64-byte record per side at S6F8.m14 (two of them). Evidence: fn_80053220 sums the 0x80 bytes at +0x1B4 of both. */
struct Unk80052794_Row {
    char pad0[0x1B4];
    unsigned char vals[0x80];
    char pad234[0xC30];
};

struct Unk80052794_S6F8 {
    char pad0[0x10];
    Unk80052794_S10* m10;
    Unk80052794_Row* m14;
};

struct Unk80052794_S6CC {
    char pad0[0x36C];
    int m36C;
};

struct Unk80052794_S700 {
    char pad0[0x3A4];
    int m3A4;
    char pad3A8[0x14];
    int m3BC;
};

struct Unk80052794_S44C {
    char pad0[0x6CC];
    Unk80052794_S6CC* m6CC;
    char pad6D0[0x28];
    Unk80052794_S6F8* m6F8;
    char pad6FC[0x4];
    Unk80052794_S700* m700;
    char pad704[0x1C];
    int m720;
};

struct Unk80052794_S130 {
    char pad0[0x44C];
    Unk80052794_S44C* m44C;
};

struct Unk80052794_S3B0 {
    char pad0[0x588];
    char m588;
    char pad589[0x7];
    unsigned m590;
    char pad594[0x174];
    int m708;
};

/* The object (usually a player/fielder) passed as the third argument. Evidence: fn_800527DC, fn_80052908, fn_80053220. */
struct Unk80052794_Obj {
    unsigned char m0;
    char pad1[0x37];
    int m38;
    char pad3C[0x10];
    int m4C;
    int m50;
    char pad54[0xB0];
    int m104;
    char pad108[0x8];
    int m110;
    char pad114[0x4];
    int m118;
    char pad11C[0x14];
    Unk80052794_S130* m130;
    char pad134[0x148];
    int m27C;
    char pad280[0x130];
    Unk80052794_S3B0* m3B0;
    int m3B4;
    char pad3B8[0xC];
    int m3C4;
    char pad3C8[0x8];
    int m3D0;
    char pad3D4[0x34];
    unsigned m408;
    char pad40C[0xC8];
    int m4D4;
    int m4D8;
};

/* Callee prototypes (guessed from call sites; most callees are not matched yet). */
extern const float lbl_805A92D4;
extern int* lbl_8061B9C4;
void fn_800527DC(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj);
void fn_80052908(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj);
void fn_8004E68C(void);
void fn_80012648(void);
void fn_8001DB70(Unk80052794_Obj* obj);
void fn_80010290(void);
void fn_80010754(int a, int b);
void fn_80011090(int a);
int fn_80054D98(void);
int fn_8001D780(Unk80052794_Obj* obj);
int fn_8001DCF8(Unk80052794_Obj* obj);
int fn_8001DA9C(Unk80052794_Obj* obj);
int fn_8001D454(Unk80052794_Obj* obj);
int fn_8001DA4C(Unk80052794_Obj* obj);
void fn_80017978(int a, int b, int c);
void fn_80017594(int a, int b);
float fn_80253F54(void* p, int a, int b, int c);
int fn_80253F0C(void* p, int a, int b, int c);
int fn_802F92CC(int a);
int fn_8040ABA0(void);
int fn_8006BE18(Unk80052794_S6F8* p);
int fn_801BBF24(int a);
int fn_801BBF30(int a, Unk80052794_S6CC* b, Unk80052794_Obj* c);
int fn_801A49F0(void* a, int b, int c);
int fn_8005000C(Unk80052794_Ctx* ctx, int idx, int code);
int fn_8004FF78(Unk80052794_Ctx* ctx, int a, int b);
void fn_8004FC60(Unk80052794_Ctx* ctx, Unk80052794_Obj* obj);
void fn_80058FE4(int a, int b);
int fn_8001F3FC(Unk80052794_Obj* obj, int a);
int fn_8001F45C(Unk80052794_Obj* obj, int a);
int fn_8001E31C(Unk80052794_Obj* obj);
int fn_800463E4(int a);
int fn_800465D4(int a, int b);
int fn_80046580(int a);
int fn_800465C0(int a);
int fn_80046658(int a);
int fn_800464C4(int a);
void fn_80044D3C(int a);
void fn_800B555C(void);
int fn_800B57EC(void);
void fn_80014A7C(int a, int b, int c, int d, int e, int f);
void fn_80017904(int a, int b, int c, int d);
void fn_800124C0(void);
void fn_8001422C(void);
void fn_80013140(void);
void fn_8001525C(void);
void fn_80015140(int a, int b);
void fn_800151A4(int a);
void fn_80015200(int a);
void fn_800158E4(void);
void fn_80017A50(void);
void fn_80015C84(int a);
void fn_80014DD0(void);
void fn_80015388(void);
void fn_80013DAC(void);
void fn_80013E08(void);
void fn_800186E8(void);
void fn_80015C30(void);
void fn_80015658(void);
void fn_800155FC(void);
void fn_800156AC(void);
void fn_800127E0(void);
void fn_80014514(void);

#endif
