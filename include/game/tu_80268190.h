/*
 * Shared types for game code 0x80268190-0x802B9218 (units game/tu_80268190 ..
 * game/tu_802B5234; reconstructed, placeholder names, everything is named by
 * offset). Nothing here comes from original headers. Layouts copy what the
 * range-19 header (tu_8024EF40.h) established for the player / controller.
 *
 * Evidence:
 *  - Unk80268190_Pl is the player: m44C (the world/queue Q), m458 (type 9..12),
 *    m58C (embedded controller A), m5BC, m70C seen in fn_80268190/fn_80268228.
 *  - Unk80268190_Q is the world: m438[] player list (count m448), m65C[13]
 *    player slots by type (fn_802684B0, fn_80268998), m6F8 chain, m700 context,
 *    m704 message queue (fn_8037893C target).
 *  - Unk80268190_M is a per-team manager: m0 = Q, m4 flag, four 0x18-byte
 *    entries at +8 indexed by (player type - 9) (fn_80268658, fn_80268724).
 */
#ifndef GAME_TU_80268190_H
#define GAME_TU_80268190_H

struct Unk80268190_Pl;
struct Unk80268190_Q;

extern char lbl_80649DA0[];

struct Unk80268190_A {
    Unk80268190_Pl* m0;
    union {
        unsigned m4;
        struct {
            unsigned b0 : 1;
            unsigned b1 : 1;
            unsigned b2 : 1;
            unsigned b3 : 29;
        };
    };
    float m8;
    float mC;
    int m10;
    float m14;
    float m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    float m48;
    char pad4C[8];
};


struct Unk80268190_Ctx {
    char pad0[0x3B4];
    void* m3B4;
    int m3B8;
    int m3BC;
};

struct Unk80268190_X {
    char pad0[0xC];
    void* mC;
};

struct Unk80268190_Sub6F8 {
    char pad0[0xC];
    Unk80268190_X* mC;
};

struct Unk80268190_Q {
    char pad0[0x48];
    char m48[4];
    unsigned int m4C;
    char pad50[0x1F0 - 0x50];
    void* m1F0;
    char pad1F4[0x438 - 0x1F4];
    Unk80268190_Pl* m438[4];
    int m448;
    char pad44C[0x65C - 0x44C];
    Unk80268190_Pl* m65C[13];
    char pad690[0x6CC - 0x690];
    Unk80268190_Pl* m6CC;
    char pad6D0[0x6F8 - 0x6D0];
    Unk80268190_Sub6F8* m6F8;
    char pad6FC[4];
    Unk80268190_Ctx* m700;
    char m704[4];
};

struct Unk80268190_Pl {
    char pad0[0x264];
    int m264;
    char pad268[0x44C - 0x268];
    Unk80268190_Q* m44C;
    char pad450[8];
    int m458;
    char pad45C[0x58C - 0x45C];
    Unk80268190_A m58C;
    char pad5E0[0x70C - 0x5E0];
    unsigned char m70C;
};

struct Unk80268190_Ent {
    int f8;
    int fC;
    Unk80268190_Pl* p10;
    int f14;
    int f18;
    int f1C;
};

struct Unk80268190_M {
    Unk80268190_Q* m0;
    int m4;
    Unk80268190_Ent e[4];
};

/* Event message base: vptr lbl_80649DA0 (the derived classes set their own vptr
   in the ctor; the inline dtor leaves the base vptr, as in retail). */
struct Unk80268190_MsgB {
    int m0;
    Unk80268190_MsgB(int id) : m0(id) {}
    virtual ~Unk80268190_MsgB() {}
};

/* Player slot by type (9..21 index into the world's slot table). */
inline Unk80268190_Pl* PlayerAt(Unk80268190_Q* q, unsigned t)
{
    return t <= 12 ? q->m65C[t] : 0;
}

/* Float table object (fn_80268918 / fn_80268928 / fn_80268980 / fn_80268998). */
struct Unk80268190_T {
    char pad0[0x1EC];
    Unk80268190_Q* m1EC;
    char pad1F0[0x438 - 0x1F0];
    Unk80268190_Pl* m438[4];
    int m448;
};

struct Unk80268190_S {
    float f0[4][4];
    int m40;
    Unk80268190_T* m44;
    int m48;
    float m4C[7];
};

/* History table: 4 rows of 6 {a0, f4, c8} records plus a count per row. */
struct Unk80268190_HE {
    int a0;
    float f4;
    int c8;
};

struct Unk80268190_H {
    Unk80268190_HE e[4][6];
    int cnt[4];
    Unk80268190_Q* m130;
};

/* Three-record tracker (fn_80268E90 ctor): records of 0x1C bytes at +4. */
struct Unk80268190_Rec {
    int a0;
    int a4;
    int a8;
    int aC;
    float a10;
    float a14;
    float a18;
};

struct Unk80268190_R {
    Unk80268190_Q* m0;
    Unk80268190_Rec rec[3];
    Unk80268190_Pl* m58;
    int m5C;
};

/* Per-player lead-style state: 12-byte records at +0xC indexed by (type - 9). */
struct Unk80268190_G12 {
    int a;
    int b;
    int c;
};

struct Unk80268190_G {
    int m0;
    int m4;
    int m8;
    Unk80268190_G12 rec[4];
};

/* Runner controller (fn_8026B8C0.. / fn_8026BE3C): m1EC world, m1F4 context. */
struct Unk80268190_C {
    char pad0[0x4];
    char m4[4];
    char pad8[0x48 - 0x8];
    char m48[4];
    char pad4C[0x1EC - 0x4C];
    Unk80268190_Q* m1EC;
    char pad1F0[4];
    Unk80268190_Ctx* m1F4;
    int m1F8;
    int m1FC;
    char pad200[0x42C - 0x200];
    int m42C;
    int m430;
    int m434;
    char pad438[0x44C - 0x438];
    unsigned int m44C;
    char pad450[0x4C4 - 0x450];
    int m4C4[4];
};

struct Unk80268190_V3 {
    int a;
    int b;
    int c;
};

/* Runner command record filled by fn_8026BD5C (size 0x38). */
struct Unk80268190_Cmd {
    int m0;
    int m4;
    int m8;
    int mC;
    Unk80268190_Pl* m10;
    int m14;
    float m18;
    float m1C;
    int m20;
    int m24;
    Unk80268190_V3 m28;
    int m34;
};

#endif /* GAME_TU_80268190_H */
