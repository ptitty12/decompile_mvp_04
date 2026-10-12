/*
 * Types for the live-play task code at 0x8020EE9C..0x8022FE34 (reconstructed).
 * Nothing here comes from original headers; layouts are inferred from the
 * matched functions in tu_8020EE9C.cpp .. tu_8022BB90.cpp. Names are
 * placeholders (Unk<addr>, m<offset>).
 */
#ifndef GAME_TU_8020EE9C_H
#define GAME_TU_8020EE9C_H

struct Vec3f {
    float x;
    float y;
    float z;
};

inline Vec3f operator-(const Vec3f& a, const Vec3f& b)
{
    Vec3f r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

extern const Vec3f lbl_806055AC; /* the zero vector (shared) */
extern const Vec3f lbl_806055DC; /* another shared 0xC-byte vector */

extern "C" {
void fn_8035B940(void* p, int v);
void fn_8035BED0(void* p, int v);
}

/* Four int slots (fn_80211B58 clears, fn_80211BA0 clears one, fn_80211BB0 finds). */
struct Slots4 {
    int m[4];
};

inline int GetSlot(Slots4* s, int x)
{
    if (x == -1) {
        return -1;
    }
    return s->m[x];
}

/* Record of 0xD8 bytes in the queue at TaskInner::m3A60 (fn_802124B8, fn_80212550). */
struct Player;
struct Rec {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    Player* m28;
    int m2C;
    int m30;
    int m34;
    Vec3f m38;
    Vec3f m44;
    Vec3f m50;
    int m5C;
    int m60;
    int m64;
    int m68;
    int m6C;
    int m70;
    int m74;
    int m78;
    int m7C;
    float m80;
    float m84;
    float m88;
    float m8C;
    float m90;
    int m94;
    int m98;
    int m9C;
    int mA0;
    int mA4;
    int mA8;
    int mAC;
    int mB0;
    int mB4;
    int mB8;
    int mBC;
    int mC0;
    int mC4;
    int mC8;
    int mCC;
    int mD0;
    int mD4;
};

struct RecQueue {
    int count;
    Rec e[6];
};

/* Sub-object at +0x58C of a player (fn_80254984 .. fn_80255028). */
struct PlayerSub {
    char pad0[4];
    unsigned m4a : 3;
    unsigned m4b : 1;
    unsigned m4c : 28;
    float m8;
    char padC[0x30 - 0xC];
    int m30;
    char pad34[4];
    int m38;
};

/* Player objects walked with fn_80257B40 / fn_80257BD0. */
struct CtxOwner;
struct Player {
    char pad0[0x44C];
    CtxOwner* m44C;
    char pad450[8];
    int m458;
    char pad45C[4];
    int m460;
    char pad464[0x4C8 - 0x464];
    int m4C8;
    char pad4CC[0x570 - 0x4CC];
    int m570;
    char pad574[0x588 - 0x574];
    int m588;
    PlayerSub m58C;
};

struct CtxOuter700 {
    char pad0[0x3B4];
    void* m3B4; /* list head for fn_80257B40 */
    char pad3B8[0x3C4 - 0x3B8];
    void* m3C4;
    char pad3C8[0x41C - 0x3C8];
    int m41C;
};
struct Obj36C {
    char pad0[0x60];
    Vec3f m60;
    char pad6C[0x460 - 0x6C];
    int m460;
};
struct Obj4_36C {
    char pad0[0x36C];
    Obj36C* m36C;
    char pad370[4];
    Obj36C* m374;
    int m378;
    char pad37C[0x38C - 0x37C];
    int m38C;
    char pad390[0x3F4 - 0x390];
    float m3F4;
};
/* Block reached through CtxOwner::m6F8 -> +0x14 (byte at +0x1CC9). */
struct Ctx6F8Inner {
    char pad0[0x1CC9];
    unsigned char m1CC9;
};
struct Ctx6F8 {
    char pad0[0x14];
    Ctx6F8Inner* m14;
};
struct CtxOwner {
    char pad0[0x4C];
    unsigned m4C;
    char pad50[0x680 - 0x50];
    int m680;
    Player* m684;
    char pad688[0x6CC - 0x688];
    Obj4_36C* m6CC;
    char pad6D0[0x6F8 - 0x6D0];
    Ctx6F8* m6F8;
    char pad6FC[4];
    CtxOuter700* m700;
    char m704[0x1C]; /* event queue sub-object (fn_8037893C first argument) */
};

/* 16-byte records at TaskInner+0x9FC, indexed by m3A5C. */
struct Rec16 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct TaskInner;
struct Obj3A64 {
    char pad0[0x9C];
    TaskInner* m9C;
    char padA0[0x794 - 0xA0];
    int m794;
    int m798;
};

/* Iterator object used with fn_8014E09C / fn_8014E108 (loop over 10 slots). */
struct IterObj {
    char pad0[8];
    int m8;
    char padC[0x18 - 0xC];
};

/* 0x5C-byte entries of the table at TaskInner+0x6D0 (fn_80221D0C). */
struct Ent5C {
    float m0;
    int m4;
    char pad8[0x30 - 8];
    int m30;
    int m34;
    char pad38[0x5C - 0x38];
};

/* Block at Task+0x9C: object table at +8 (indexed by m3A5C), two Slots4 at
 * +0xC0 and +0xD4, the record queue at +0x3A60. */
struct TaskInner {
    CtxOwner* m0;
    Obj4_36C* m4;
    void* m8[10];
    int m30;
    char pad34[0x40 - 0x34];
    int m40;
    char pad44[0x5C - 0x44];
    int m5C;
    int m60;
    char pad64[0x70 - 0x64];
    int m70;
    int m74;
    char pad78[0x80 - 0x78];
    int m80;
    char pad84[0xA4 - 0x84];
    int mA4;
    float mA8;
    Vec3f mAC;
    char padB8[0xC0 - 0xB8];
    Slots4 mC0;
    char padD0[0xD4 - 0xD0];
    Slots4 mD4;
    char padE4[0x19C - 0xE4];
    int m19C;
    char pad1A0[0x1C4 - 0x1A0];
    int m1C4;
    char pad1C8[0x1D8 - 0x1C8];
    int m1D8;
    char pad1DC[0x1F4 - 0x1DC];
    int m1F4;
    char pad1F8[0x20C - 0x1F8];
    int m20C;
    char pad210[0x6A8 - 0x210];
    int m6A8;
    char pad6AC[0x6D0 - 0x6AC];
    Ent5C m6D0[8]; /* nine entries are indexed (k <= 8); the ninth reaches 0xA0C and overlaps m9FC in the declaration */
    char pad9B0[0x9FC - 0x9B0];
    Rec16 m9FC[8];
    char padA7C[0xC90 - 0xA7C];
    int mC90;
    char padC94[0xCA8 - 0xC94];
    RecQueue mCA8[4];
    char pad20F8[0x3A5C - 0x20F8];
    int m3A5C;
    RecQueue* m3A60;
    Obj3A64* m3A64;
};

/* First field of the task objects, also present at Task+0x9C (the sub-object
 * methods fn_80210C98.. are called with &task->m9C). */
struct Sub {
    TaskInner* m0;
};

struct Task : Sub {
    char pad4[0x9C - 4];
    TaskInner* m9C;
    char padA0[0xB8 - 0xA0];
    int mB8;
    char padBC[0xE8 - 0xBC];
    float mE8;
    char padEC[0xF8 - 0xEC];
    float mF8;
    char padFC[4];
    float m100;
    float m104;
    char pad108[0x118 - 0x108];
    int m118;
};

/* Objects compared in fn_8021157C .. fn_80211648 (floats at +4, +8). */
struct CmpPos {
    char pad0[4];
    float m4;
    float m8;
};

/* Objects compared in fn_80211E30 (type id at +4, keys at +0xC and +0x10). */
struct CmpKey {
    char pad0[4];
    int m4;
    char pad8[4];
    float mC;
    float m10;
};

/* 0x38-byte entry of EntList (fn_80211C04 initialises it). */
struct Ent38 {
    int m0;
    int m4;
    float m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    Vec3f m2C;
};

/* Three Ent38 at +0xC with the current index at +8 (fn_80211CAC resets it). */
struct EntList {
    float m0;
    int m4;
    int m8;
    Ent38 mC[3];
    int mB4;
    int mB8;
    int mBC;
    int mC0;
    int mC4;
};

/* Sub-records initialised by fn_80211EF8 .. fn_80211FE4 (arrays of four in the
 * object initialised by fn_80212054). */
struct Rec2C {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    float m18;
    float m1C;
    float m20;
    int m24;
    int m28;
};
struct Rec34 {
    int m0;
    int m4;
    int m8;
    float mC;
    float m10;
    float m14;
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
    int m30;
};
struct Rec1C {
    float m0;
    float m4;
    Vec3f m8;
    float m14;
    int m18;
};
struct Rec14 {
    float m0;
    int m4;
    int m8;
    int mC;
    int m10;
};
struct Rec40 {
    int m0;
    int m4;
    float m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    float m28;
    float m2C;
    Vec3f m30;
    int m3C;
};

/* Two-entry int table (fn_80212170 sets one, fn_80212180 clears it). */
struct Pair2 {
    int m0;
    int m4[2];
};

/* Object with a position at +0x60 (fn_80212550). */
struct PosObj {
    char pad0[0x60];
    Vec3f m60;
};

/* Fields set by fn_8021239C. */
struct Obj74 {
    char pad0[0x74];
    int m74;
    float m78;
    Vec3f m7C;
};

extern "C" void fn_80204CCC(Rec* r);

/* Stack event objects (id at +0, vptr at +4, base vtable lbl_80649DA0) posted with
 * fn_8037893C; the derived setter methods live in animation/tu_802A9A04.cpp (names only).
 * The inline ctor/dtor reproduce retail's root-vptr / id / derived-vptr store sequence. */
extern char lbl_80649DA0[];
extern "C" void fn_8037893C(char* queue, int id, void* ev, int a, int b);
struct EvBase {
    int m0;
    const void* m4;
    EvBase(int id)
    {
        m4 = lbl_80649DA0;
        m0 = id;
    }
};

/* Object-table lookup with the byte offset in a local: gives retail's
 * 'lwzx rD,rBase,rIdx' operand order (fn_8021DB40, fn_8022321C). */
inline void* ObjAt(void** a, int i)
{
    int o = i * 4;
    return *(void**)((char*)a + o);
}

/* Functions of tu_8020EE9C.cpp used by the neighbouring units. */
extern "C" {
int fn_80210C98(Sub* t, int kind);
int fn_80210D20(Sub* t, int kind);
int fn_80210FC4(Sub* t, int kind, int x, Player** out);
int fn_80211064(Sub* t, int kind, Player* p, int* out);
Player* fn_80211370(Sub* t);
void fn_80211BA0(Slots4* s, int i);
int fn_80211BB0(Slots4* s, int v);
void fn_80212550(Task* t, Vec3f* pos, float a, float b, int c, int d);
}

#endif
