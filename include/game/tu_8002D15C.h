#ifndef GAME_TU_8002D15C_H
#define GAME_TU_8002D15C_H

/*
 * Types for src/game/tu_8002D15C.cpp .. tu_80037250.cpp (reconstructed;
 * nothing here comes from original headers).
 *
 * The functions of these units are handlers of one object (called
 * Unk8002D15C here): a state machine with an owner pointer at +0x80, a
 * "current message" pointer at +0x6BC (cleared at the end of each handler)
 * and state words at +0x6F0 / +0x6FC / +0x700. Each handler reads the message
 * through the same checked cast (`m6BC` non-null and `m0 == <message id>`).
 * Evidence: fn_8002D188, fn_8002D42C, fn_8002E058 .. fn_8002EAF0.
 * Offsets are what the functions access; everything is named by offset.
 */

struct Unk8002D15C_Vec3 {
    float m0;
    float m4;
    float m8;
};

/* Message record: m0 is the message id (checked by the cast below). */
struct Unk8002D15C_Msg {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};

struct Unk8002D15C;

/* Sub-record at +0x58C of the players (flags word at +4, a count at +0x30). */
struct Unk8002D15C_Sub58C {
    int m0;
    unsigned int m4;
    char pad8[0x30 - 8];
    int m30;
};

/* Per-player data (the object at +0x510 / +0x7A0 / +0x7A4 / +0x7CC). */
struct Unk8002D15C_Player {
    char pad0[0x460];
    int m460;
    char pad464[0x588 - 0x464];
    char m588[4];
    Unk8002D15C_Sub58C m58C;
    char pad5C0[0x708 - 0x5C0];
    int m708;
};

/* Table behind +0x6F8 of the owner: m10 points to ints at +0x6C. */
struct Unk8002D15C_Tbl10 {
    char pad0[0x6C];
    int m6C[1];
};

struct Unk8002D15C_Data14 {
    char pad0[0x1CD0];
    int m1CD0;
};

struct Unk8002D15C_Sub6F8 {
    char pad0[0x10];
    Unk8002D15C_Tbl10* m10;
    Unk8002D15C_Data14* m14;
};

/* Owner object at +0x80 of the handler object. */
struct Unk8002D15C_Owner {
    char pad0[0x48];
    unsigned int m48;
    char pad4C[0x6CC - 0x4C];
    struct Unk8002D15C_Cc* m6CC;
    char pad6D0[0x6E4 - 0x6D0];
    char* m6E4;
    char pad6E8[0x6F8 - 0x6E8];
    Unk8002D15C_Sub6F8* m6F8;
};

struct Unk8002D15C_Cc {
    char pad0[0x3F4];
    float m3F4;
};

struct Unk8002D15C_Pair {
    int m0;
    int m4;
};

struct Unk8002D15C {
    char pad0[0x80];
    Unk8002D15C_Owner* m80;
    char pad84[0xD0 - 0x84];
    int mD0;
    char padD4[0xE4 - 0xD4];
    int mE4;
    int mE8;
    char padEC[0x12C - 0xEC];
    int m12C;
    int m130;
    int m134;
    int m138;
    char pad13C[0x264 - 0x13C];
    int m264;
    char pad268[0x270 - 0x268];
    Unk8002D15C_Pair m270[3];
    char pad288[0x290 - 0x288];
    Unk8002D15C_Player* m290;
    char pad294[0x3F0 - 0x294];
    int m3F0[32];
    int m470[1];
    char pad474[0x4C0 - 0x474];
    int m4C0;
    int m4C4;
    char pad4C8[0x510 - 0x4C8];
    Unk8002D15C_Player* m510;
    int m514;
    char pad518[0x524 - 0x518];
    int m524;
    char pad528[0x530 - 0x528];
    int m530;
    char pad534[0x634 - 0x534];
    int m634;
    char pad638[0x6BC - 0x638];
    Unk8002D15C_Msg* m6BC;
    char pad6C0[0x6C8 - 0x6C0];
    int m6C8;
    char pad6CC[0x6F0 - 0x6CC];
    int m6F0;
    char pad6F4[0x6FC - 0x6F4];
    unsigned int m6FC;
    int m700;
    char pad704[0x7A0 - 0x704];
    Unk8002D15C_Player* m7A0;
    Unk8002D15C_Player* m7A4;
    int m7A8;
    int m7AC;
    int m7B0;
    int m7B4;
    char pad7B8[0x7BC - 0x7B8];
    int m7BC;
    char pad7C0[0x7C8 - 0x7C0];
    int m7C8;
    Unk8002D15C_Player* m7CC;
    int m7D0;
    int m7D4;
    int m7D8;
};

/* Checked cast of the current message: null unless it has the given id. */
inline Unk8002D15C_Msg* Unk8002D15C_AsMsg(Unk8002D15C_Msg* m, int id)
{
    if (m) {
        if (m->m0 == id)
            return m;
        return 0;
    }
    return 0;
}

extern "C" {
void fn_800221E4(Unk8002D15C* self, Unk8002D15C_Owner* owner, int a, int b);
void fn_80022270(Unk8002D15C* self, Unk8002D15C_Owner* owner, int a);
void fn_80021C9C(Unk8002D15C* self, Unk8002D15C_Owner* owner, Unk8002D15C_Vec3 v);
void fn_80021D04(Unk8002D15C* self, Unk8002D15C_Owner* owner, Unk8002D15C_Vec3 v, int flag, const Unk8002D15C_Vec3& w);
void fn_800233B4(Unk8002D15C* self, int a, int b, int c);
int fn_80023430(Unk8002D15C* self, int a, int b, int c);
void fn_80023490(Unk8002D15C* self, int a, int b);
void fn_8002A244(Unk8002D15C* self, int id, float t);
int fn_8002A2D4(Unk8002D15C* self);
void fn_8002F1E4(Unk8002D15C* self);
void fn_800303A4(Unk8002D15C* self, int a);
void fn_8003049C(Unk8002D15C* self, int id, int a, int b);
void fn_80035EEC(int a, int b, int c);
void fn_80039A3C(int a, int b, int c);
void fn_8003F460(int a, int b);
void fn_8003F6D4(int a, int b);
void fn_800475EC();
void fn_80048968();
void* fn_8005BA9C();
void fn_8005C75C(void* p, int a, int b);
int fn_8005C498(void* p, int a);
float fn_80253EC4(void* p, int a, int b, int c);
}

/*
 * Starts animation `id`, scaled by the owner's tick count in 1/60 s units.
 * Most handlers in these units end with this exact expression. It must be an
 * inline function: written out in each handler, the constant-pool loads get
 * hoisted above the field stores (see docs/PATTERNS.md).
 */
inline void StartAnim(Unk8002D15C* self, int id)
{
    fn_8002A244(self, id, (float)self->m80->m48 * (1.0f / 60.0f));
}

struct Unk8061B8C0 {
    char pad0[0x24];
    int m24;
};
extern Unk8061B8C0* lbl_8061B8C0;

#endif /* GAME_TU_8002D15C_H */
