/*
 * Translation unit at 0x80272B20 (original file name unknown; placeholder).
 * Same directory evidence as animation/choosers/tu_80271748.cpp.
 *
 * .text 0x80272B20-0x80275F24, .rodata 0x805DC7E4-0x805DCCB0, .data 0x8061E670-0x8061E674.
 *
 * cLinearChooser: vtable 0x80662088 slot 3 (0x802ACAE4) returns the pointer at
 * 0x8061E670 -> "cLinearChooser". Its helper class (vtable 0x80662120, ctor
 * 0x80272B20) is defined first, as in tu_80271F14.cpp. The 12-byte object at
 * 0x805DCB7C is also read by fn_8029D2E0 (another unit), so it is a global.
 *
 * Not attempted (tier C, 10.5 KB): fn_802735F4, the chooser's vtable slot 17.
 */
#include "game/chooser.h"

float fn_804028E4(float x);               /* square root */
float fn_8041171C(float x);
float fn_80411554(float x);
float fn_80382BB8(Unk80271DBC_Link* p);
void fn_8024D178(Unk80270BA0_X* x, Unk80270BA0_X* target);
void fn_8024D1A4(Unk80270BA0_X* x, Unk80273498_Vec3* v);

inline Unk80273498_Vec3 operator-(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline float Length(Unk80273498_Vec3 v)
{
    return fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline Unk80273498_Vec3 operator+(const Unk80273498_Vec3& a, const Unk80273498_Vec3& b)
{
    Unk80273498_Vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

inline Unk80273498_Vec3 operator*(Unk80273498_Vec3 v, float s)
{
    Unk80273498_Vec3 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}

inline Unk80273498_Vec3 Direction(float angle)
{
    Unk80273498_Vec3 r;
    r.x = fn_8041171C(angle);
    r.y = 0.0f;
    r.z = fn_80411554(angle);
    return r;
}

inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

/* One list entry (16 bytes). Evidence: stride 0x10 in fn_80272BE8 (parse),
 * fn_80272DAC (id resolve) and fn_80272E28 (+0x8 compared with the input,
 * +0xC read as the end of the entry's span). */
struct Unk80272B20_Entry {
    unsigned int hash;
    int id;                    /* resolved from hash by fn_80272DAC */
    float m8;                  /* start position */
    float mC;                  /* end position */
};

/* Position-keyed list of ids used by cLinearChooser (vtable 0x80662120 with
 * the parse function in slot 1 and the dtor in slot 2; base ctor 0x80356798;
 * size 0x1C, embedded in the chooser at +0xC).
 *
 * Parse format (slot 1): "count#" then per entry "hash,m8,<unused>,mC#" and a
 * final "m18#" token. Offsets seen: +4 count, +8 entries, +0x10 set by the
 * chooser's slot 17 before fn_80272E28 is called, +0x14 ids resolved,
 * +0x18 value that replaces the input when the player flag 0x800 is set. */
class Unk80272B20 : public Unk80356798 {
public:
    Unk80272B20();
    virtual void fn_vslot1(char* buf, int len);
    virtual ~Unk80272B20();
    void fn_80272DAC();
    int fn_80272E28(Unk80270BA0_X* x, float a, Unk80270BA0_Result* out, int flag);

    int m4;                    /* entry count */
    Unk80272B20_Entry* m8;
    int mC;                    /* not touched by any function in this unit */
    int m10;                   /* selects nearest-entry mode in fn_80272E28 */
    int m14;                   /* ids resolved */
    float m18;
};

Unk80272B20::Unk80272B20()
{
    m18 = 0.0f;
    m4 = 0;
    m14 = 0;
    m8 = 0;
}

Unk80272B20::~Unk80272B20()
{
    if (m4) {
        m4 = 0;
        if (m8) {
            delete[] m8;
        }
        m8 = 0;
    }
}

void Unk80272B20::fn_vslot1(char* buf, int len)
{
    m14 = 0;
    if (len) {
        char* cursor;
        int remaining;
        char* token;
        int tokenLen;
        int done;
        int i;

        cursor = buf;
        remaining = len;
        fn_80378E48(&cursor, &remaining, '#', &token, &tokenLen);
        m4 = fn_80409DAC(token);
        if (m8) {
            delete[] m8;
            m8 = 0;
        }
        done = 0;
        i = 0;
        m8 = new (lbl_806EF9B4 | 0x100) Unk80272B20_Entry[m4];
        while (i < m4 && !done) {
            char* tokenA;
            int tokenALen;
            char* tokenB;
            int tokenBLen;
            char* tokenC;
            int tokenCLen;
            char* tokenD;
            int tokenDLen;

            fn_80378E48(&cursor, &remaining, ',', &tokenA, &tokenALen);
            fn_80378E48(&cursor, &remaining, ',', &tokenB, &tokenBLen);
            fn_80378E48(&cursor, &remaining, ',', &tokenC, &tokenCLen);
            fn_80378E48(&cursor, &remaining, '#', &tokenD, &tokenDLen);
            if (tokenALen && tokenBLen) {
                m8[i].hash = fn_80378568(tokenA, tokenALen);
                m8[i].m8 = fn_80409D88(tokenB);
                m8[i].mC = fn_80409D88(tokenD);
            } else {
                done = 1;
            }
            i++;
        }
        fn_80378E48(&cursor, &remaining, '#', &token, &tokenLen);
        m18 = fn_80409D88(token);
    }
}

void Unk80272B20::fn_80272DAC()
{
    if (!m14) {
        for (int i = 0; i < m4; i++) {
            m8[i].id = fn_80383334(m8[i].hash);
        }
        m14 = 1;
    }
}

/* Picks the entry, or the two entries to blend, for input position `a`
 * (returns 0 for an empty list). With player flag 0x800 set the input is
 * replaced by m18 and, if `flag` is set, a point 1080 units from the player at
 * a heading derived from it goes to fn_8024D178/fn_8024D1A4.
 * Matching notes: `dist` is const so that its register is reused after the
 * calls, and `pos` is a reference declared first so that x+0x60 is computed
 * before them. */
int Unk80272B20::fn_80272E28(Unk80270BA0_X* x, float a, Unk80270BA0_Result* out, int flag)
{
    int idx = -1;
    int next;

    fn_80272DAC();
    if (x->m71C & 0x800) {
        a = m18;
        if (flag) {
            const float dist = 1080.0f;
            const Unk80273498_Vec3& pos = x->m60;
            float rot = (a + a - 1.0f) * 3.1415927f;
            float diff = AngleDiff(fn_80382BB8(x->m618), rot);
            Unk80273498_Vec3 target = pos + Direction(diff) * dist;

            fn_8024D178(x, x);
            fn_8024D1A4(x, &target);
        }
    }
    if (m4 == 0) {
        return 0;
    }
    for (int i = 0; i < m4; i++) {
        if (!(m8[i].m8 <= a)) {
            idx = i;
            break;
        }
    }
    if (idx != -1) {
        next = idx;
    } else {
        next = m4 - 1;
    }
    if (m4 > 1 && idx != 0 && idx != -1) {
        int lo = idx - 1;
        float dHi = m8[idx].m8 - a;
        float dLo = a - (&m8[idx])[-1].m8;

        if (m10) {
            next = idx;
            if (!(a >= m8[lo].mC)) {
                next = lo;
            }
        } else {
            next = idx;
            if (!(dHi <= dLo)) {
                next = lo;
            }
            if (!(dHi <= 0.001f) && !(dLo <= 0.001f)) {
                float mid = m8[lo].mC;
                if (!(a >= mid)) {
                    float lov = m8[lo].m8;
                    float range = mid - lov;
                    out->m18 = dLo / range * 0.5f;
                    out->m14 = 1.0f - out->m18;
                } else if (!(a <= mid)) {
                    float hi = m8[idx].m8;
                    float range = hi - mid;
                    out->m14 = dHi / range * 0.5f;
                    out->m18 = 1.0f - out->m14;
                } else {
                    out->m14 = 0.5f;
                    out->m18 = 1.0f - out->m14;
                }
                out->type = 2;
                out->id = m8[lo].id;
                out->m8 = m8[idx].id;
                return 1;
            }
        }
    }
    out->type = 1;
    out->id = m8[next].id;
    out->m14 = 1.0f;
    return 1;
}

/* Class name; read by cLinearChooser's vtable slot 3 (0x802ACAE4). */
const char* lbl_8061E670 = "cLinearChooser";

class cLinearChooser : public Unk8037B3E8 {
public:
    /* Declared first and defined in the unit at 0x802AC8xx (vtable slots 3/4),
     * which makes g++ 2.95 emit this class's vtable there, as in retail. */
    virtual const char* fn_vslot3();
    virtual int fn_vslot4();

    cLinearChooser();
    virtual void fn_vslot2();
    virtual Unk8037B3E8* fn_vslot5();
    virtual int fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
    virtual int fn_vslot14(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj);
    virtual int fn_vslot17(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj, int c, int d, int e, int f);
    int fn_80273498(Unk80270BA0_Obj* obj);

    int m4;
    int m8;                    /* "type" enum */
    Unk80272B20 mC;            /* "matrix1dx"/"scale" */
};

cLinearChooser::cLinearChooser() : Unk8037B3E8(0xF8EB0036u)
{
    m4 = 0;
    m8 = 1;
}

void cLinearChooser::fn_vslot2()
{
    fn_8037B6B0(lbl_805DC394, &m8, "SharpTurn,ThrowAngle,ThrowDist,StartAngle,StartSpeed,AnimStyle,BareHandStyle,FielderCallBall,LeadOffDist,TeamMomentum,StartAngleSnap,DroppedBall,StrafeType,IdleIntensity,ByTheWallType,IsBaseHome,ReadyToThrow,OnPlaceRotation,UmpireSignal,StopAngle,StopSpeed,RunnerReachStyle,RunnerSlideStyle,StopAngleSnap,HitByBall,OnPlaceRotationIntensity,LeadRetreatStyle,ShortReachDistance,ThrowAngleSnap,RunnerReachIntensity,DodgePitchType,BullpenPitcherCatchType,ObviousHomeRun,ManualActionStick,CatchPerformance,CatchExtension,ThrowAngleSpecial,LeftRightStickDifference,RightStick,IsBaserunner,UseStartToStrafe,ManualWallClimbRunning,ManualRunStretch,ManualStandStretch,PitcherWalkbackStyle,BattedBallSpeed,ManualRunSlide,TagBaseStyle,UseOBStretchTag,SwingClassification,CatcherUrgentPlay,DoublePlaySide,ManualWallClimbStanding");
    fn_8037B728("matrix1dx", "scale", &mC, 0);
}

int cLinearChooser::fn_vslot13(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    return m4 ? 0 : fn_vslot17(out, obj, 3, 0, 0, 0);
}

int cLinearChooser::fn_vslot14(Unk80270BA0_Result* out, Unk80270BA0_Obj* obj)
{
    if (m4 == 2) {
        return fn_vslot17(out, obj, 1, 0, 0, 0);
    }
    if (m4 == 0) {
        return fn_vslot17(out, obj, 3, 0, 0, 0);
    }
    return 0;
}

Unk8037B3E8* cLinearChooser::fn_vslot5()
{
    return new (lbl_806EF9B4) cLinearChooser;
}

float fn_8027342C(float a, float b, float c)
{
    if (!(a <= b || a >= c)) {
        float mid = (b + c) * 0.5f;
        a = !(a >= mid) ? b : c;
    }
    return a;
}

int cLinearChooser::fn_80273498(Unk80270BA0_Obj* obj)
{
    Unk80270BA0_X* x = obj->fn_vslot1();
    Unk8014D8AC_Ctx* ctx = x->m44C;
    Unk80273498_Pos* target = ctx->m54C->mC;
    Unk80273498_Vec3 a = ctx->m6CC->m60;
    float d0 = Length(a - target->m60);
    float d1 = Length(x->m60 - target->m60);

    return d0 > d1;
}
