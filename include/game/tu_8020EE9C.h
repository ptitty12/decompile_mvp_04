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
struct Rec {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[0x38 - 0x10];
    Vec3f m38;
    char pad44[0x50 - 0x44];
    Vec3f m50;
    char pad5C[0x80 - 0x5C];
    float m80;
    char pad84[0x88 - 0x84];
    float m88;
    char pad8C[0x94 - 0x8C];
    int m94;
    char pad98[0x9C - 0x98];
    int m9C;
    char padA0[0xA4 - 0xA0];
    int mA4;
    char padA8[0xAC - 0xA8];
    int mAC;
    char padB0[0xD8 - 0xB0];
};

struct RecQueue {
    int count;
    Rec e[6];
};

/* Sub-object at +0x58C of a player (fn_80254984 .. fn_80255028). */
struct PlayerSub {
    char pad0[8];
    float m8;
    char padC[0x38 - 0xC];
    int m38;
};

/* Player objects walked with fn_80257B40 / fn_80257BD0. */
struct Player {
    char pad0[0x458];
    int m458;
    char pad45C[0x4C8 - 0x45C];
    int m4C8;
    char pad4CC[0x588 - 0x4CC];
    int m588;
    PlayerSub m58C;
};

struct CtxOuter700 {
    char pad0[0x3B4];
    void* m3B4; /* list head for fn_80257B40 */
    char pad3B8[0x3C4 - 0x3B8];
    void* m3C4;
};
struct CtxOwner {
    char pad0[0x684];
    Player* m684;
    char pad688[0x700 - 0x688];
    CtxOuter700* m700;
};

/* 16-byte records at TaskInner+0x9FC, indexed by m3A5C. */
struct Rec16 {
    int m0;
    int m4;
    int m8;
    int mC;
};

/* Block at Task+0x9C: object table at +8 (indexed by m3A5C), two Slots4 at
 * +0xC0 and +0xD4, the record queue at +0x3A60. */
struct TaskInner {
    CtxOwner* m0;
    char pad4[4];
    void* m8[10];
    int m30;
    char pad34[0xC0 - 0x34];
    Slots4 mC0;
    char padD0[0xD4 - 0xD0];
    Slots4 mD4;
    char padE4[0x9FC - 0xE4];
    Rec16 m9FC[8];
    char padA7C[0x3A5C - 0xA7C];
    int m3A5C;
    RecQueue* m3A60;
};

/* First field of the task objects, also present at Task+0x9C (the sub-object
 * methods fn_80210C98.. are called with &task->m9C). */
struct Sub {
    TaskInner* m0;
};

struct Task : Sub {
    char pad4[0x9C - 4];
    TaskInner* m9C;
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
