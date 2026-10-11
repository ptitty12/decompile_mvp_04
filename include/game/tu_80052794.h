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
struct Unk80052794_Quad;
struct Unk800B555C_Obj;

struct Unk80052794_B3B0 {
    char pad0[0x98];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
};

/* Element of the 0x48-byte records at Ctx+4. Evidence: fn_800527DC (m38), fn_80052FE0 (m4), fn_800533A0 (m0, m4, m8, mC), fn_80053754 (m10), fn_80054328 (m20). */
struct Unk80052794_Entry {
    union {
        int m0;
        Unk80052794_S3B0* m0p;
    };
    union {
        int m4;
        float m4f;
    };
    int m8;
    int mC;
    int m10;
    char pad14[0xC];
    int m20;
    char pad24[0x14];
    Unk80052794_S44C* m38;
    char pad3C[0xC];
};

/* Context passed as the first argument of the AI/event callbacks in 0x80052794..0x8005DF2C (placeholder). Evidence: fn_800527DC, fn_80052908, fn_800533A0. */
struct Unk80052794_Ctx {
    int m0;
    Unk80052794_Entry m4[33];
    char pad94C[0x8C];
    int m9D8;
    int m9DC;
    int m9E0;
    char pad9E4[0x20];
    int mA04;
    int mA08;
    char padA0C[0x2C];
    int mA38[6];
    int mA50;
    int mA54;
    char padA58[0x10];
    int mA68;
    int mA6C;
    char padA70[0x4];
    int mA74;
    char padA78[0x4];
    int mA7C;
    char padA80[0x4];
    int mA84;
    char padA88[0x8];
    int mA90;
    char padA94[0x8];
    int mA9C;
};

struct Unk80052794_S10 {
    char pad0[0x1C];
    int m1C;
};

/* One 0xE64-byte record per side at S6F8.m14 (two of them). Evidence: fn_80053220 and fn_80054684 sum the 0x80 bytes at +0x1B4. */
struct Unk80052794_Row {
    char pad0[0x17C];
    unsigned char m17C;
    char pad17D[0x37];
    unsigned char vals[0x80];
    char pad234[0xC30];
};

struct Unk80052794_S6F8 {
    char pad0[0x10];
    Unk80052794_S10* m10;
    Unk80052794_Row* m14;
};

struct Unk80052794_Quad {
    unsigned m0;
    int m4;
    int m8;
    int mC;
};

struct Unk800B555C_Obj {
    char pad0[0x688];
    Unk80052794_Quad m688;
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
    char pad450[0x2B8];
    int m708;
};

/* Class with a vptr at +0x98 (fn_80052A34 and fn_800543B4 call virtual slots 24 and 4 through it). */
struct Unk80052794_S3B0 : Unk80052794_B3B0 {
    char pad9C[0x3C4];
    int m460;
    char pad464[0x124];
    char m588;
    char pad589[0x7];
    unsigned m590;
    char pad594[0x174];
    int m708;
};

struct Unk80052794_Obj13C {
    int m0;
    char pad4[0x24];
};

struct Unk80052794_Obj48C {
    int m0;
    Unk80052794_S3B0* m4;
    char pad8[0x10];
};

/* The object (usually a player/fielder) passed as the third argument. Evidence: fn_800527DC, fn_80052908, fn_80053220. */
struct Unk80052794_Obj {
    unsigned char m0;
    char pad1[0x37];
    int m38;
    char pad3C[0x8];
    int m44;
    char pad48[0x4];
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
    char pad134[0x8];
    Unk80052794_Obj13C m13C[5];
    char pad204[0x70];
    int m274;
    char pad278[0x4];
    int m27C;
    char pad280[0x130];
    Unk80052794_S3B0* m3B0;
    int m3B4;
    char pad3B8[0xC];
    int m3C4;
    char pad3C8[0x8];
    int m3D0;
    char pad3D4[0x8];
    int m3DC;
    int m3E0;
    char pad3E4[0x4];
    int m3E8;
    char pad3EC[0xC];
    int m3F8;
    char pad3FC[0xC];
    unsigned m408;
    char pad40C[0x38];
    int m444;
    int m448;
    int m44C;
    char pad450[0x8];
    int m458;
    char pad45C[0x4];
    int m460;
    char pad464[0x28];
    Unk80052794_Obj48C m48C[3];
    int m4D4;
    int m4D8;
    char pad4DC[0x70];
    int m54C;
};

/* Address of the record's data at ctx + idx * 0x48 + 4 (retail forms ctx + idx*0x48 first, then +4). */
static inline Unk80052794_Entry* EntryOf(Unk80052794_Ctx* c, int i)
{
    return (Unk80052794_Entry*)((char*)c + i * 0x48 + 4);
}

/* Callee prototypes (guessed from call sites; most callees are not matched yet). */
extern const float lbl_805A92D4;
extern int* lbl_8061B9C4;
void fn_800527DC(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj);
void fn_80052908(Unk80052794_Ctx* ctx, int idx, Unk80052794_Obj* obj);
void fn_8004E68C(void);
void fn_80012648(void);
int fn_8001DB70(Unk80052794_Obj* obj);
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
Unk800B555C_Obj* fn_800B555C(void);
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

/* unit 0x8005371C */
extern int lbl_80687600;
extern const float lbl_805A92D8;
extern const float lbl_805A92F0;
extern int lbl_80617F5C;
void fn_8005371C(void);
int fn_8005481C(Unk80052794_Ctx* ctx, int idx);
int fn_80054750(Unk80052794_Ctx* ctx, int idx);
void fn_800149CC(void);
void fn_80014BFC(void);
int fn_80056E34(int a, int b);
int fn_8001DA28(Unk80052794_Obj* obj);
void fn_80013E5C(int a, int b);
void fn_80015B2C(int a);
int fn_8001D8DC(Unk80052794_Obj* obj);
int fn_8001D6CC(Unk80052794_Obj* obj);
void fn_800119F8(int a, int b, int c);
void fn_80018918(int a, int b);
void fn_8001897C(void);
void fn_80014978(void);
void fn_80012834(void);
int fn_80054DAC(Unk80052794_Ctx* ctx, Unk80052794_Obj* obj, int a);
int fn_80054DCC(Unk80052794_Ctx* ctx, Unk80052794_Obj* obj, int a);
void fn_80012418(void);
void fn_8000FA98(int a, int b);
void fn_80013724(int a);
void fn_8000F968(int a);
void fn_8017DD80(Unk80052794_S700* s, int k, void* a, void* b);
int fn_8017DD64(Unk80052794_S700* s, int k);
float fn_80253434(void* p);
void fn_800173E8(int a);
void fn_8001A1F4(void);
void fn_8001A398(void);
void fn_8001A050(void);
void fn_8001A0A4(void);
void fn_8001A14C(void);
void fn_8001A0F8(void);
void fn_8001A1A0(void);
void fn_8001A29C(void);
void fn_8001A248(void);
void fn_8001A2F0(void);
void fn_8001A344(void);
int fn_80043460(Unk80052794_Entry* e, int a);
int fn_8001D694(Unk80052794_Obj* obj);
int fn_8001D47C(Unk80052794_Obj* obj);
void fn_80013370(int a, int b, int c);
void fn_80043650(void);
void fn_800150E4(void);
int fn_8009E1D4(void* p, int a, int b);
int fn_800461F8(int a, int b, int c);
void fn_800152B0(int a, int b, int c);
int fn_8009DB0C(Unk80052794_Row* r, unsigned char b);
int fn_8009DA60(Unk80052794_Row* r, unsigned char b);
int fn_8001DBE0(Unk80052794_Obj* obj);
void fn_80013674(void);
void fn_80014E24(void);
int fn_8001F954(Unk80052794_Obj* obj);

#endif
