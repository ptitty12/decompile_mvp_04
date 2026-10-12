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
    int m1C;
    int m20;
    int m24;
    int m28;
};

struct Unk8002D15C;
struct Unk8002F894_Obj;

struct Unk8002D15C_P700 {
    char pad0[0x3E0];
    int m3E0;
    float m3E4;
};

struct Unk8002D15C_P44C {
    char pad0[0x700];
    Unk8002D15C_P700* m700;
};

/* Sub-record at +0x58C of the players (flags word at +4, a count at +0x30). */
struct Unk8002D15C_Sub58C {
    int m0;
    unsigned int m4;
    char pad8[0x30 - 8];
    int m30;
};

/* Per-player data (the object at +0x510 / +0x7A0 / +0x7A4 / +0x7CC). */
struct Unk8002D15C_Player {
    char pad0[0x44C];
    Unk8002D15C_P44C* m44C;
    char pad450[0x460 - 0x450];
    int m460;
    char pad464[0x588 - 0x464];
    char m588[4];
    Unk8002D15C_Sub58C m58C;
    char pad5C0[0x704 - 0x5C0];
    int m704;
    int m708;
};

/* Element (0xE64 bytes) of the per-player array behind Unk8002D15C_Sub6F8::m14. */
struct Unk8002D15C_PI {
    char pad0[0x238];
    int m238;
    char pad23C[0xE64 - 0x23C];
};

/* Table behind +0x6F8 of the owner: m10 points to ints at +0x6C. */
struct Unk8002D15C_Tbl10 {
    char pad0[0x6C];
    int m6C[2];
};

struct Unk8002D15C_Data14 {
    char pad0[0x198];
    int m198;
    char pad19C[0xFFC - 0x19C];
    int mFFC;
    char padFFC[0x1CC8 - 0x1000];
    unsigned char m1CC8;
    unsigned char m1CC9;
    unsigned char m1CCA;
    unsigned char m1CCB;
    char pad1CCC[4];
    int m1CD0;
};

struct Unk8002D15C_C8C {
    char pad0[0x28];
    int m28;
};

struct Unk8002D15C_C8 {
    char pad0[0xC];
    Unk8002D15C_C8C* mC;
    char pad10[4];
    Unk8002D15C_Data14* m14;
};

/* Object at +0x6C8 (virtual call through slot 12: reset). */
struct Unk8002D15C_Obj6C8 {
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
};

struct Unk8002D15C_Sub6F8 {
    char pad0[0x10];
    Unk8002D15C_Tbl10* m10;
    Unk8002D15C_Data14* m14;
};

struct Unk8002D15C_Q700;
/* Owner object at +0x80 of the handler object. */
struct Unk8002D15C_Owner {
    char pad0[0x48];
    unsigned int m48;
    char pad4C[0x6BC - 0x4C];
    int m6BC;
    char pad6C0[0x6CC - 0x6C0];
    struct Unk8002D15C_Cc* m6CC;
    char pad6D0[0x6E4 - 0x6D0];
    char* m6E4;
    char pad6E8[0x6F4 - 0x6E8];
    int m6F4;
    Unk8002D15C_Sub6F8* m6F8;
    char pad6FC[0x700 - 0x6FC];
    Unk8002D15C_Q700* m700;
};

struct Unk8002D15C_Cc {
    char pad0[0x60];
    Unk8002D15C_Vec3 m60;
    char pad6C[0x374 - 0x6C];
    struct Unk8002D15C_Cc* m374;
    char pad378[0x388 - 0x378];
    int m388;
    int m38C;
    char pad390[0x3F4 - 0x390];
    float m3F4;
    float m3F8;
    char pad3FC[0x448 - 0x3FC];
    int m448;
};

struct Unk8002D15C_Q3B8 {
    char pad0[4];
    struct Unk8002D15C_Q4* m4;
};
struct Unk8002D15C_Q4 {
    char pad0[0x9C];
    int m9C;
};
struct Unk8002D15C_Q700 {
    char pad0[0x3B8];
    Unk8002D15C_Q3B8* m3B8;
};

struct Unk8002D15C_Tri {
    int m0;
    int m4;
    int m8;
};

/* 0x24-byte entry of the table at +0x1D0 (four of them, count at +0x260). */
struct Unk8002D15C_Ent {
    int m0;
    int m4;
    int m8;
    char padC[0x14 - 0xC];
    int m14;
    char pad18[0x20 - 0x18];
    int m20;
};

struct Unk8002D15C_Pair {
    int m0;
    int m4;
};

/*
 * Common base of the objects the manager in game/tu_80030778.cpp keeps in its
 * slots (the 0x7F8-byte Unk8002D15C, and the 0x144, 0xD8, 0xE4, 0x150 byte
 * ones). Data to +0xB8, then the vptr, so the first virtual is at vtable
 * entry 1 (a virtual destructor: called with in-charge 3 by the manager).
 * Evidence: fn_80030C90 .. fn_80031088 (calls through [obj+0xB8] with the
 * delta adjust), fn_8002D314 (entry 11).
 */
struct Unk80030C90_Base {
    char pad0[0x80];
    Unk8002D15C_Owner* m80;
    char pad84[0xB8 - 0x84];
    virtual ~Unk80030C90_Base();
    virtual void v2(int);
    virtual void v3(int, float);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(int);
    virtual void v8(int);
    virtual void v9();
    virtual void v10();
    virtual void v11(int);
};

struct Unk8002D15C : public Unk80030C90_Base {
    char padBC[0xC8 - 0xBC];
    Unk8002D15C_C8* mC8;
    int mCC;
    int mD0;
    int mD4;
    char padD8[0xE4 - 0xD8];
    int mE4;
    int mE8;
    char padEC[0xF0 - 0xEC];
    int mF0;
    char padF4[0xFC - 0xF4];
    int mFC;
    char pad100[0x11C - 0x100];
    int m11C;
    int m120;
    int m124;
    int m128;
    int m12C;
    int m130;
    int m134;
    int m138;
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    char pad150[0x160 - 0x150];
    unsigned char m160;
    char pad161[3];
    int m164;
    int m168;
    int m16C;
    int m170[2];
    int m178[2];
    int m180[2];
    int m188[2];
    int m190[2];
    char pad198[4];
    int m19C;
    int m1A0;
    char pad1A4[0x1C0 - 0x1A4];
    int m1C0[4];
    Unk8002D15C_Ent m1D0[4];
    int m260;
    int m264;
    int m268;
    int m26C;
    Unk8002D15C_Pair m270[3];
    char pad288[0x290 - 0x288];
    Unk8002D15C_Player* m290;
    char pad294[0x3F0 - 0x294];
    int m3F0[2];
    int m3F8[2];
    int m400[2];
    int m408[2];
    int m410[2];
    int m418[2];
    int m420[2];
    int m428[2];
    int m430[2];
    int m438[2];
    int m440[2];
    int m448[2];
    int m450[2];
    int m458[2];
    int m460[2];
    int m468[2];
    int m470[2];
    int m478[2][3];
    int m490[2][3];
    int m4A8[2][3];
    int m4C0;
    int m4C4;
    int m4C8[2][3];
    int m4E0[2][3];
    int m4F8[2][3];
    Unk8002D15C_Player* m510;
    int m514;
    char pad518[0x524 - 0x518];
    int m524;
    char pad528[0x52C - 0x528];
    int m52C;
    int m530;
    char pad534[0x560 - 0x534];
    int m560;
    char pad564[0x57C - 0x564];
    int m57C;
    char pad580[0x5A8 - 0x580];
    int m5A8;
    char pad5AC[0x634 - 0x5AC];
    int m634;
    char pad638[0x6BC - 0x638];
    Unk8002D15C_Msg* m6BC;
    float m6C0;
    float m6C4;
    int m6C8;
    char pad6CC[0x6F0 - 0x6CC];
    int m6F0;
    char pad6F4[0x6FC - 0x6F4];
    unsigned int m6FC;
    int m700;
    int m704;
    int m708;
    char pad70C[0x714 - 0x70C];
    int m714;
    char pad718[0x7A0 - 0x718];
    Unk8002D15C_Player* m7A0;
    Unk8002D15C_Player* m7A4;
    int m7A8;
    int m7AC;
    int m7B0;
    int m7B4;
    Unk8002D15C_Player* m7B8;
    int m7BC;
    char pad7C0[0x7C8 - 0x7C0];
    int m7C8;
    Unk8002D15C_Player* m7CC;
    int m7D0;
    int m7D4;
    int m7D8;
    char pad7DC[0x7E0 - 0x7DC];
    int m7E0;
    char pad7E4[0x7F0 - 0x7E4];
    float m7F0;
    int m7F4;
};

typedef void (Unk8002D15C::*Unk8002D15C_Handler)();

/* Message dispatch table at 0x80616528: 0x53 entries of {message id, pointer to member function}. */
struct Unk8002D15C_HEnt {
    int id;
    Unk8002D15C_Handler h;
};
extern Unk8002D15C_HEnt lbl_80616528[];
extern int lbl_80620860;
extern "C" void* fn_8040B320(void* dst, int c, unsigned int n);

/* Iterator (24 bytes on the stack) filled by fn_8014E09C; m8 is the current element (10 = end). */
struct Unk8014E09C_It {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

extern float lbl_805A6684;

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
void fn_800233B4(void* self, int a, int b, int c);
int fn_80023430(void* self, int a, int b, int c);
void fn_80023490(void* self, int a, int b);
void fn_8002A244(Unk8002D15C* self, int id, float t);
int fn_8002A2D4(Unk8002D15C* self);
void fn_8003B394(int a, int b);
void fn_8003B3B8(int a, int b);
int fn_801A497C(Unk8002D15C_Owner* o, int a, int b);
int fn_801A4B34(Unk8002D15C_Owner* o);
float fn_804028E4(float x);
int fn_80211DB8(int x);
int fn_80211D78(int x);
void fn_8003F14C(int a, int b);
void fn_8003EF1C(int a);
void fn_8014E09C(struct Unk8014E09C_It* it, Unk8002D15C_Owner* o, int k);
void fn_8014E108(struct Unk8014E09C_It* it);
int fn_801DC964(struct Unk8002D15C_Q3B8* q, int x);
void fn_8002F1E4(Unk8002D15C* self);
void fn_800303A4(Unk8002D15C* self, int a);
void fn_80030380(Unk8002D15C* self, int a);
void fn_8003049C(Unk8002D15C* self, int id, int a, int b);
void fn_80035EEC(int a, int b, int c);
void fn_80039A3C(int a, int b, int c);
void fn_80021E30(void* self, void* o, int a);
void fn_8003F460(int a, int b);
void fn_8003F698(int a);
void fn_8003FA44(int a);
void fn_8003B0F4(int a, Unk8002D15C_Msg* m);
void fn_80036064(int a, int b, int c, int d);
void fn_8003C710(int a, int b);
int fn_80038EB4();
void fn_80039E2C(int a, int b);
void fn_80039E94();
void fn_8003F6D4(int a, int b);
char* fn_800475EC();
void fn_80048968();
void* fn_8005BA9C();
void fn_8005C75C(void* p, int a, int b);
int fn_8005C498(void* p, int a);
void fn_803EE7BC();
void fn_8003B23C(int a, int b, int c);
void fn_8002F160(Unk8002D15C* self);
void fn_80021BE8(Unk8002D15C* self);
void fn_80048C08(void* p);
void fn_8003968C(int a, int b);
float fn_8017FA08(int a);
void fn_80035E94(int a);
void fn_80030130(Unk8002D15C* self);
void fn_8002FE88(Unk8002D15C* self);
int fn_8040ABA0();
Unk8002D15C_Vec3* fn_8019CF24(int a);
Unk8002D15C_Vec3* fn_8019CF30(float f, int a);
float fn_80253EC4(void* p, int a, int b, int c);
int fn_80253E7C(void* p, int a, int b, int c);
int fn_80253DF4(void* p, int a, int b);
void fn_8003F250(int a, int b);
void fn_8003F0D0(int a);
void fn_8037893C(void* q, int id, Unk8002F894_Obj* o, int a, int b);
void fn_803444D0(Unk8002F894_Obj* o, int a);
void fn_8003F37C(int a, int b);
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

/* Event passed to fn_8002F894: m4 selects the action, m8 is the player. */
struct Unk8002F894_Ev {
    int m0;
    int m4;
    Unk8002D15C_Player* m8;
};

/* Local object built by fn_8002F894 (vptr at +4: two vtable stores, base then derived). */
extern char lbl_80649D88[];
extern char lbl_80649DA0[];
struct Unk8002F894_Obj {
    int m0;
    const void* vptr;
    Unk8002D15C_Player* m8;
    int mC;
    /* inline base constructor, then the derived one (second vtable store) */
    void Base(int id)
    {
        vptr = lbl_80649DA0;
        m0 = id;
        m8 = 0;
        mC = 0;
    }
    void Derived()
    {
        vptr = lbl_80649D88;
    }
    void Set(int x, Unk8002D15C_Player* p)
    {
        mC = x;
        m8 = p;
    }
};

extern float lbl_80686DCC;
extern int* lbl_8061B9C4;

struct Unk8061B8C0 {
    char pad0[8];
    Unk8002D15C_Owner* m8;
    char padC[0x24 - 0xC];
    int m24;
};
extern Unk8061B8C0* lbl_8061B8C0;

#endif /* GAME_TU_8002D15C_H */
