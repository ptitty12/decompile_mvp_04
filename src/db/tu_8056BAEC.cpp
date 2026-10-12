/*
 * Database overlay code, .database_codeoverlay 0x8056BAEC-0x8056EC68 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8056BAEC.h"

/* ---- event classes (stack objects posted with fn_8037893C) ---- */

/* vtable lbl_8065F9E0 */
class Ev2D : public DbEv {
public:
    Ev2D(void* x) : DbEv(0x2d) { m8 = x; }
    virtual ~Ev2D() {}
    void* m8;
};

/* vtable lbl_8065F9C8 */
class Ev34 : public DbEv {
public:
    Ev34(void* x) : DbEv(0x34) { m8 = x; }
    virtual ~Ev34() {}
    void* m8;
};

/* vtable lbl_80660650 */
class Ev5B : public DbEv {
public:
    Ev5B() : DbEv(0x5b) {}
    virtual ~Ev5B();
    void Set(int a, int b)
    {
        m8 = a;
        mC = b;
    }
    int m8;
    int mC;
};

/* Event with fields shared by several event kinds at +0xC and +0x10 (set by the base part). */
class EvM : public DbEv {
public:
    EvM(int id, int c, int d) : DbEv(id)
    {
        m10 = c;
        mC = d;
    }
    virtual ~EvM() {}
    int m8;
    int mC;
    int m10;
};

/* vtable lbl_80660E90 */
class Ev76 : public EvM {
public:
    Ev76(int c, int d) : EvM(0x76, c, d) {}
    void Set(int a, int d, int e)
    {
        m8 = a;
        m14 = d;
        m18 = e;
    }
    virtual ~Ev76() {}
    int m14;
    int m18;
};

/* vtable lbl_8065FA78 */
class Ev79 : public DbEv {
public:
    Ev79() : DbEv(0x79) {}
    virtual ~Ev79() {}
    void Set(int a, int b)
    {
        m8 = a;
        mC = b;
    }
    int m8;
    int mC;
};

/* vtable lbl_80660398 */
class Ev61 : public DbEv {
public:
    Ev61() : DbEv(0x61) {}
    virtual ~Ev61() {}
    void Set(int a, int b, int c, int d, int e)
    {
        m8 = a;
        mC = b;
        m10 = c;
        m14 = d;
        m18 = e;
    }
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};

#include "game/clampiter.h"

/* vtable lbl_80660680 */
class Ev7D : public DbEv {
public:
    Ev7D() : DbEv(0x7d) {}
    virtual ~Ev7D();
    void Set(int a, int b, int c, int d, int e)
    {
        m8 = a;
        mC = b;
        m10 = c;
        m14 = d;
        m18 = e;
    }
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};

/* vtable lbl_80660368 */
class Ev3A : public DbEv {
public:
    Ev3A() : DbEv(0x3a)
    {
        m10 = 0;
        m20 = 0;
    }
    virtual ~Ev3A() {}
    void Set(int a, int b, int c, int d, int p0, int p1)
    {
        m8 = a;
        mC = b;
        m10 = c;
        m14 = d;
        m18 = p0;
        m1C = p1;
        m20 = 0;
    }
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
};

/* vtable lbl_80660FC8 */
class Ev84 : public DbEv {
public:
    Ev84(int x) : DbEv(0x84)
    {
        m8 = -1.0f;
        m10 = -1;
        mC = x;
    }
    virtual ~Ev84() {}
    float m8;
    int mC;
    int m10;
};

/* vtable lbl_80660668 */
class Ev7E : public DbEv {
public:
    Ev7E() : DbEv(0x7e) {}
    virtual ~Ev7E();
    void Set(int a, int b)
    {
        m8 = a;
        mC = b;
    }
    int m8;
    int mC;
};

/* vtable lbl_80660380; the setter is out of line (fn_802A9C34 in the animation unit). */
class Unk802A9C34 : public DbEv {
public:
    Unk802A9C34() : DbEv(0x39)
    {
        m8 = 0;
        m18 = 0;
        m1C = -1.0f;
    }
    virtual ~Unk802A9C34() {}
    int m8;
    int mC;
    float m10;
    char m14;
    char m15;
    char m16;
    int m18;
    float m1C;
};

/* Setter of the animation unit (member Unk802A9C34::fn_802A9C34); the byte arguments arrive zero-extended. */
extern "C" void fn_802A9C34__11Unk802A9C34ifcicc(Unk802A9C34* e, int a, float f, unsigned char b, int c, unsigned char d, unsigned char g);

/* vtable lbl_80660FF8 */
class Ev83 : public DbEv {
public:
    Ev83() : DbEv(0x83)
    {
        m8 = -1.0f;
        mC = -1;
        m10 = -1;
    }
    virtual ~Ev83() {}
    float m8;
    int mC;
    int m10;
};

/* vtable lbl_80660FE0 */
class Ev85 : public DbEv {
public:
    Ev85() : DbEv(0x85)
    {
        m8 = -1.0f;
        mC = -1;
        m14 = -1;
        m10 = -1;
    }
    virtual ~Ev85() {}
    float m8;
    int mC;
    int m10;
    int m14;
};

/* vtable lbl_80660608 */
class Ev5F : public DbEv {
public:
    Ev5F() : DbEv(0x5f) {}
    virtual ~Ev5F();
    void Set(int a, int b, int c)
    {
        m8 = a;
        mC = b;
        m10 = c;
    }
    int m8;
    int mC;
    int m10;
};

/* vtable lbl_80660308 */
class Ev86 : public DbEv {
public:
    Ev86() : DbEv(0x86) {}
    virtual ~Ev86() {}
    void Set(int a, int b, int c)
    {
        m8 = a;
        mC = b;
        m10 = c;
    }
    int m8;
    int mC;
    int m10;
};

extern const float lbl_805FFA4C;
extern const float lbl_805FFB98;
extern const float lbl_805FFB9C;

/* Twelve floats (four vectors of three) at the start of the object. */
struct DbF12 {
    float m0, m4, m8, mC, m10, m14, m18, m1C, m20, m24, m28, m2C;
};

/* Object with three words at +0x30..+0x38 followed by the setup calls. */
struct Db8056CC8C {
    char pad0[0x30];
    int m30;
    int m34;
    int m38;
};
extern "C" void fn_8056D15C(Db8056CC8C* self, int a);

extern "C" void fn_8056ED54(DbSel* self, int a);

extern const float lbl_805FFB6C;
extern const float lbl_805FFB70;
extern const float lbl_805FFB74;
extern const float lbl_805FFB78;

struct Db8056CCD0_T {
    char pad0[0x1B4];
    unsigned char m1B4[0x80];
};

extern const float lbl_805FFC64;
extern const float lbl_805FFC68;

extern const float lbl_805FFC6C;
extern const float lbl_805FFC70;
extern "C" int fn_8056EC68(DbSel* self, int a, int b, int c, int d);

extern const float lbl_805FFC74;
extern const float lbl_805FFC78;

extern "C" int rand(void);
extern const float lbl_805FFA04;
extern const float lbl_805FFA08;
extern const float lbl_805FFA0C;
extern const float lbl_805FFA10;
extern const float lbl_805FFA14;
extern const float lbl_805FFA18;
extern int lbl_806215D4;
extern float lbl_8061D818;
extern float lbl_8061D81C;
extern int lbl_8061D9B0[];
extern int lbl_8061DA78[];
extern int lbl_8061D820[];
extern int lbl_8061D8E8[];
struct Db8056BAEC_T {
    char pad0[0x234];
    unsigned char m234;
};

extern const float lbl_805FFB64;
extern const float lbl_805FFB68;
struct Db8056D994_S {
    float m0, m4, m8, mC, m10, m14, m18, m1C, m20, m24, m28, m2C;
    int* m30;
    int m34;
    DbScrB* m38;
};

extern const float lbl_805FFB90;
extern const float lbl_805FFB94;
/* forward declarations (definitions are in address order) */
extern "C" void fn_8056BAEC(DbScr* self, int a, int b, int c);
extern "C" void fn_8056BD50(void* self);
extern "C" void fn_8056BDD0(void* self);
extern "C" void fn_8056BE34(void* self);
extern "C" void fn_8056BE98(void* self);
extern "C" void fn_8056BEC8(DbScr* self);
extern "C" void fn_8056BF80(DbScr* self, int a, int b, int c, int d, int e);
extern "C" void fn_8056C014(DbScr* self, int a, int b);
extern "C" void fn_8056C0A0(DbScr* self, int a);
extern "C" void fn_8056C1C4(DbScr* self, int a);
extern "C" void fn_8056C2B4(DbScr* self);
extern "C" void fn_8056C3AC(void* q, int x);
extern "C" void fn_8056C424(DbScr* self);
extern "C" void fn_8056C520(DbScr* self);
extern "C" void fn_8056C610(DbScr* self, int a);
extern "C" void fn_8056C6BC(DbScr* self);
extern "C" void fn_8056C7A0(void* q, int a1, int a2, int a3, int a4, int a5);
extern "C" void fn_8056C8E4(void* q, int a);
extern "C" void fn_8056C988(DbScr* self, int a, int b);
extern "C" void fn_8056CA20(void* q, int a);
extern "C" void fn_8056CAC4(void* q, int a, int b, int c);
extern "C" void fn_8056CB30(DbScr* self, int a);
extern "C" void fn_8056CC50(DbF12* p);
extern "C" void fn_8056CC8C(Db8056CC8C* self, int a, int b, int c, int d);
extern "C" int fn_8056CCD0(void* unused, DbScrB* scr, int side);
extern "C" void fn_8056D994(Db8056D994_S* self);
extern "C" void fn_8056DA98(DbF12* p);
extern "C" void fn_8056DBB8(Db8056CC8C* self);
extern "C" void fn_8056DE14(DbF12* p);
extern "C" void fn_8056DE4C(void* p);
extern "C" void fn_8056DE50(DbSel* self, DbSelSrc* src, DbScr* scr, int* sidep, void* x);
extern "C" void fn_8056DEF4(DbSel* self);
extern "C" void fn_8056E02C(DbSel* self, int a, int flags);
extern "C" void fn_8056E130(DbSel* p);
extern "C" void fn_8056E13C(DbSel* self);
extern "C" void fn_8056E630(DbSel* self);
extern "C" void fn_8056E6E4(DbSel* self, int flags);
extern "C" void fn_8056E858(DbSel* self, int flags);
extern "C" void fn_8056E8B4(DbSel* self, int a, int flags);
extern "C" void fn_8056EA58(DbSel* self, int a, int flags);

extern "C" DB_OVERLAY void fn_8056BAEC(DbScr* self, int a, int b, int c)
{
    Db8056BAEC_T* t = (Db8056BAEC_T*)TeamAt(self->m14->m14, b);
    if (t->m234 != 0 && self->m10 != 0) {
        int side = 0;
        if (self->m14->m14->m1CD0 != 0)
            side = 1;
        if (b == side && fn_800971C8(t, a) == 1)
            return;
        float f = ((float (*)(void*, int, int))fn_8007189C__FP1Wii)((char*)t + 0xC9C, 0x12, a);
        f = lbl_805FFA04 - f;
        if (!(f >= lbl_805FFA08))
            f = lbl_805FFA08;
        switch (c) {
        case 0:
            f = f * lbl_805FFA0C;
            break;
        case 1:
            f = f * lbl_805FFA10;
            break;
        case 2:
            f = f * lbl_805FFA14;
            break;
        }
        float r = fn_8056FFB0();
        if (lbl_806215D4 == 1)
            r = lbl_805FFA18;
        if (!(r >= f)) {
            float g1 = lbl_8061D818 * lbl_805FFA08;
            r = fn_8056FFB0();
            int idx;
            if (!(r >= g1))
                idx = rand() % 24 + 25;
            else
                idx = rand() % 24 + 1;
            float g2 = lbl_8061D81C * lbl_805FFA08;
            r = fn_8056FFB0();
            int x;
            int y;
            if (!(r >= g2)) {
                x = lbl_8061D9B0[idx];
                y = lbl_8061DA78[idx];
            } else {
                x = lbl_8061D820[idx];
                y = lbl_8061D8E8[idx];
            }
            fn_8056BF80(self, a, idx, y, x, b);
        }
    }
}

extern "C" DB_OVERLAY void fn_8056BD50(void* self)
{
    fn_8037893C(self, 0x2a, 0, 0, 0);
    Ev2D e(self);
    fn_8037893C(self, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056BDD0(void* self)
{
    Ev2D e(self);
    fn_8037893C(self, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056BE34(void* self)
{
    Ev34 e(self);
    fn_8037893C(self, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056BE98(void* self)
{
    fn_8037893C(self, 0x36, 0, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056BEC8(DbScr* self)
{
    DbScrB* o = self->m14;
    int side = 0;
    if (o->m14->m1CD0 != 0)
        side = 1;
    int other = o->m14->m1CD0 == 0;
    Ev5B e;
    DbT* t = TeamAt(o->m14, side);
    e.Set(TeamAt(o->m14, other)->m17C, t->m168[t->m174]);
    fn_8037893C(self, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056BF80(DbScr* self, int a, int b, int c, int d, int e)
{
    Ev76 ev(c, d);
    DbT* t = TeamAt(self->m14->m14, e);
    ev.Set(b, t->m3E8[(unsigned char)a].m0, e);
    fn_8037893C(self, ev.m0, &ev, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056C014(DbScr* self, int a, int b)
{
    Ev79 ev;
    DbT* t = TeamAt(self->m14->m14, b);
    ev.Set(t->m3E8[(unsigned char)a].m0, b);
    fn_8037893C(self, ev.m0, &ev, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056C0A0(DbScr* self, int a)
{
    Ev61 e;
    int side = 0;
    DbG* g = self->m14->m14;
    if (g->m1CD0 != 0)
        side = 1;
    int found = 0;
    DbT* t = TeamAt(g, side);
    unsigned char cur = t->m168[t->m174];
    if (a != cur) {
        Unk8006A138_It<3> it(0);
        while (it.v <= 2) {
            if (fn_80081D08__FP13Unk8007FF8C_Yi(g, it.v)->m0 == a) {
                if (fn_80081D08__FP13Unk8007FF8C_Yi(g, it.v)->m4 == 0)
                    found = 1;
                break;
            }
            it.Next();
        }
    }
    e.Set(side, a, cur, found, found ^ 1);
    fn_8037893C(self, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056C1C4(DbScr* self, int a)
{
    DbScrB* o = self->m14;
    int side = 0;
    if (o->m14->m1CD0 != 0)
        side = 1;
    int other = o->m14->m1CD0 == 0;
    Ev7D e;
    DbT* t = TeamAt(o->m14, side);
    int p0 = lbl_8060558C[0];
    int p1 = lbl_8060558C[1];
    int v = EntAt(t->m3E8, t->m168[t->m174]);
    e.Set(a, v, fn_80097210(TeamAt(o->m14, other), 0), p0, p1);
    fn_8037893C(self, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056C2B4(DbScr* self)
{
    DbScrB* o = self->m14;
    int side = 0;
    if (o->m14->m1CD0 != 0)
        side = 1;
    int other = o->m14->m1CD0 == 0;
    Ev3A e;
    DbT* t = TeamAt(o->m14, side);
    int v = EntAt(t->m3E8, t->m168[t->m174]);
    e.Set(v, fn_80097210(TeamAt(o->m14, other), 0), 0, 0, lbl_8060558C[0], lbl_8060558C[1]);
    fn_8037893C(self, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056C3AC(void* q, int x)
{
    Ev84 e(x);
    fn_8037893C(q, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056C424(DbScr* self)
{
    DbScrB* o = self->m14;
    int side = 0;
    if (o->m14->m1CD0 != 0)
        side = 1;
    int other = o->m14->m1CD0 == 0;
    Ev3A e;
    DbT* t = TeamAt(o->m14, side);
    int v = EntAt(t->m3E8, t->m168[t->m174]);
    e.Set(v, fn_80097210(TeamAt(o->m14, other), 0), 0, 1, lbl_8060558C[0], lbl_8060558C[1]);
    fn_8037893C(self, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056C520(DbScr* self)
{
    int side = 0;
    DbG* g = self->m14->m14;
    if (g->m1CD0 != 0)
        side = 1;
    int other = g->m1CD0 == 0;
    DbT* t = TeamAt(g, side);
    int v = EntAt(t->m3E8, t->m168[t->m174]);
    int r = fn_80097210(TeamAt(g, other), 0);
    Ev3A e;
    e.Set(v, r, 1, 0, lbl_8060558C[0], lbl_8060558C[1]);
    fn_8037893C(self, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056C610(DbScr* self, int a)
{
    Ev7E e;
    int side = 0;
    DbG* g = self->m14->m14;
    if (g->m1CD0 != 0)
        side = 1;
    DbT* t = TeamAt(g, side);
    e.Set(a, EntAt(t->m3E8, t->m168[t->m174]));
    fn_8037893C(self, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056C6BC(DbScr* self)
{
    int side = 0;
    DbScrB* o = self->m14;
    if (o->m14->m1CD0 != 0)
        side = 1;
    int other = o->m14->m1CD0 == 0;
    Unk802A9C34 e;
    DbT* t = TeamAt(o->m14, side);
    DbT* u = TeamAt(o->m14, other);
    fn_802A9C34__11Unk802A9C34ifcicc(&e, 6, 0.0f, t->m168[t->m174], -1, u->m17C, 0xFF);
    fn_8037893C(self, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056C7A0(void* q, int a1, int a2, int a3, int a4, int a5)
{
    Unk802A9C34 e1;
    Ev83 e2;
    Ev85 e3;
    e2.mC = a3;
    e3.mC = a4;
    if (a3 != a4)
        fn_8037893C(q, e3.m0, &e3, 0, 0);
    fn_8037893C(q, e2.m0, &e2, 0, 0);
    fn_802A9C34__11Unk802A9C34ifcicc(&e1, a5, 0.0f, a2, a1, 0xFF, 0xFF);
    fn_8037893C(q, e1.m0, &e1, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056C8E4(void* q, int a)
{
    Unk802A9C34 e;
    fn_802A9C34__11Unk802A9C34ifcicc(&e, 3, 0.0f, a, -1, 0xFF, 0xFF);
    fn_8037893C(q, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056C988(DbScr* self, int a, int b)
{
    DbScrB* o = self->m14;
    DbG* g = o->m14;
    int own = g->m1CD0 == 0;
    Ev5F e;
    e.Set(b, TeamAt(o->m14, own)->m17D, a);
    fn_8037893C(self, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056CA20(void* q, int a)
{
    Unk802A9C34 e;
    fn_802A9C34__11Unk802A9C34ifcicc(&e, 2, 0.0f, a, -1, 0xFF, 0xFF);
    fn_8037893C(q, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056CAC4(void* q, int a, int b, int c)
{
    Ev86 e;
    e.Set(c, a, b);
    fn_8037893C(q, e.m0, &e, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056CB30(DbScr* self, int a)
{
    Unk802A9C34 e;
    int side = 0;
    DbG* g = self->m14->m14;
    if (g->m1CD0 != 0)
        side = 1;
    DbT* t = TeamAt(g, side);
    fn_802A9C34__11Unk802A9C34ifcicc(&e, 5, 0.0f, t->m168[t->m174], -1, 0xFF, 0xFF);
    fn_8037893C(self, e.m0, &e, 0, 0);
    Ev83 e2;
    e2.mC = a;
    fn_8037893C(self, e2.m0, &e2, 0, 0);
}

extern "C" DB_OVERLAY void fn_8056CC50(DbF12* p)
{
    p->m0 = lbl_805FFA4C;
    p->m4 = lbl_805FFA4C;
    p->m8 = lbl_805FFA4C;
    p->mC = lbl_805FFA4C;
    p->m10 = lbl_805FFA4C;
    p->m20 = lbl_805FFA4C;
    p->m24 = lbl_805FFA4C;
    p->m14 = lbl_805FFA4C;
    p->m28 = lbl_805FFA4C;
    p->m2C = lbl_805FFA4C;
    p->m18 = lbl_805FFA4C;
    p->m1C = lbl_805FFA4C;
}

extern "C" DB_OVERLAY void fn_8056CC8C(Db8056CC8C* self, int a, int b, int c, int d)
{
    self->m30 = a;
    self->m34 = b;
    self->m38 = c;
    fn_8056D15C(self, d);
    fn_8056DBB8(self);
}

extern "C" DB_OVERLAY int fn_8056CCD0(void* unused, DbScrB* scr, int side)
{
    DbG* g = scr->m14;
    unsigned char q0 = fn_80081CF8__FP13Unk8007FF8C_Yi(g, 0)->m0;
    unsigned char q1 = fn_80081CF8__FP13Unk8007FF8C_Yi(g, 1)->m0;
    unsigned char q2 = fn_80081CF8__FP13Unk8007FF8C_Yi(g, 2)->m0;
    Db8056CCD0_T* tb = (Db8056CCD0_T*)TeamAt(scr->m14, side == 0);
    Db8056CCD0_T* ta = (Db8056CCD0_T*)TeamAt(scr->m14, side);
    int sa = 0;
    for (int i = 0; i < 0x80; i++)
        sa += ta->m1B4[(unsigned char)i];
    int sb = 0;
    for (int i = 0; i < 0x80; i++)
        sb += tb->m1B4[(unsigned char)i];
    int d = sa - sb;
    if (d < 0)
        d = -d;
    if (Round(g) <= 1 && q0 != 0xFF && (q1 == 0xFF || q2 == 0xFF) && d <= 2)
        return 1;
    return 0;
}

extern "C" DB_OVERLAY void fn_8056D994(Db8056D994_S* self)
{
    int side = *self->m30;
    DbScrB* scr = self->m38;
    DbT* t = TeamAt(scr->m14, side);
    if (fn_8056CCD0(self, scr, side) == 1) {
        int r = fn_8008CFD8((char*)t + 0xC9C, 5, t->m168[t->m174]);
        self->m2C = lbl_805FFB64;
        if (r == 0 || r == 10) {
            float s1 = self->m4 + self->m8 + self->mC + self->m10 + self->m20;
            float s2 = (self->m14 = self->m14 * lbl_805FFB68) + (self->m18 = self->m18 * lbl_805FFB68) + (self->m1C = self->m1C * lbl_805FFB68);
            self->m4 = lbl_805FFB64;
            self->m8 = lbl_805FFB64;
            self->mC = lbl_805FFB64;
            self->m10 = lbl_805FFB64;
            self->m20 = lbl_805FFB64;
            self->m2C = s1 + s2;
        }
    }
}

extern "C" DB_OVERLAY void fn_8056DA98(DbF12* p)
{
    float a = p->m28;
    float b = p->m4 * lbl_805FFB6C;
    float c = p->m8 * lbl_805FFB6C;
    float d = p->mC * lbl_805FFB6C;
    float e = p->m10 * lbl_805FFB6C;
    p->m4 = p->m4 - b;
    float sum = a + b + c + d + e;
    p->m8 = p->m8 - c;
    p->mC = p->mC - d;
    p->m10 = p->m10 - e;
    float f = sum * lbl_805FFB74;
    float g = sum * lbl_805FFB78;
    p->m0 = p->m4 + p->m8 + p->mC + p->m10;
    p->m28 = lbl_805FFB70;
    float h = sum - f - g;
    p->m14 = p->m14 + f;
    p->m20 = p->m20 + g;
    p->m1C = p->m1C + h;
}

extern "C" DB_OVERLAY void fn_8056DBB8(Db8056CC8C* self)
{
    Db8056D994_S* p = (Db8056D994_S*)self;
    DbG* g = p->m38->m14;
    int qb = g->m1CCB;
    int qa = g->m1CCA;
    if (qb > 0) {
        float k = (float)qb * lbl_805FFB90;
        p->m20 += k * p->m2C;
        p->m20 += k * p->m14;
        p->m20 += k * p->m18;
        p->m20 += k * p->m1C;
        p->m20 += k * p->m0;
        p->m2C -= k * p->m2C;
        p->m14 -= k * p->m14;
        p->m18 -= k * p->m18;
        p->m1C -= k * p->m1C;
        p->m0 -= k * p->m0;
        p->m4 -= k * p->m4;
        p->m8 -= k * p->m8;
        p->mC -= k * p->mC;
        p->m10 -= k * p->m10;
    }
    if (qa > 0) {
        float k = (float)qa * lbl_805FFB94;
        p->m14 += k * p->m2C;
        p->m14 += k * p->m20;
        p->m14 += k * p->m18;
        p->m14 += k * p->m1C;
        p->m14 += k * p->m0;
        p->m2C -= k * p->m2C;
        p->m20 -= k * p->m20;
        p->m18 -= k * p->m18;
        p->m1C -= k * p->m1C;
        p->m0 -= k * p->m0;
        p->m4 -= k * p->m4;
        p->m8 -= k * p->m8;
        p->mC -= k * p->mC;
        p->m10 -= k * p->m10;
    }
}

extern "C" DB_OVERLAY void fn_8056DE14(DbF12* p)
{
    p->m18 += p->m20 * lbl_805FFB98;
    p->m4 += p->m20 * lbl_805FFB98;
    p->m20 = lbl_805FFB9C;
}

extern "C" DB_OVERLAY void fn_8056DE4C(void* p)
{
}

extern "C" DB_OVERLAY void fn_8056DE50(DbSel* self, DbSelSrc* src, DbScr* scr, int* sidep, void* x)
{
    self->mC = src;
    self->m10 = src->m14;
    self->m20 = 0;
    self->m2C = 0;
    self->m28 = -1;
    self->m18 = scr;
    self->m14 = sidep;
    self->m1C = x;
    self->m0 = fn_80081CF8__FP13Unk8007FF8C_Yi(self->m10, 0);
    self->m4 = fn_80081CF8__FP13Unk8007FF8C_Yi(self->m10, 1);
    self->m8 = fn_80081CF8__FP13Unk8007FF8C_Yi(self->m10, 2);
    if (src->m10->m28 == 1)
        self->m24 = src->m10->m28;
    else
        self->m24 = 0;
}

extern "C" DB_OVERLAY void fn_8056DEF4(DbSel* self)
{
    int a = 1;
    int side = *self->m14;
    DbT* t = TeamAt(self->m10, side);
    int other = side == 0;
    unsigned char vOther = TeamAt(self->m10, other)->m17C;
    unsigned char vCur = t->m168[t->m174];
    unsigned char x0 = self->m0->m0;
    unsigned char x1 = self->m4->m0;
    unsigned char x2 = self->m8->m0;
    if (x0 == 0xFF)
        a = 0;
    int b = 0;
    if (a != 0 && x1 != 0xFF)
        b = 1;
    int c = 0;
    if (b != 0 && x2 != 0xFF)
        c = 1;
    self->m2C = 0;
    if (c == 1) {
        fn_8056C0A0(self->m18, x2);
        fn_80080B98__FP13Unk8007FF8C_Q(self->m8);
    }
    if (b == 1) {
        DbQ* q = self->m4;
        fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m8, q->m0, q->m1, q->m4);
        fn_80080B98__FP13Unk8007FF8C_Q(self->m4);
    }
    if (a == 1) {
        DbQ* q = self->m0;
        fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m4, q->m0, q->m1, q->m4);
        fn_80080B98__FP13Unk8007FF8C_Q(self->m0);
    }
    fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m0, vCur, vOther, 1);
}

/* near-miss: 5 slots; retail does the andi. tests into r0 and emits li r0,k after them */
extern "C" DB_OVERLAY void fn_8056E02C(DbSel* self, int a, int flags)
{
    self->m2C = 0;
    self->m28 = 8;
    if ((flags & 1) == 0) {
        int k;
        if (flags & 2) {
            k = 7;
            if (!(flags & 0x10))
                k = 5;
        } else {
            k = 4;
            if (flags & 0x10)
                k = 6;
        }
        self->m28 = k;
    }
    if (self->m8->m0 != 0xFF && Round(self->m10) <= 2)
        fn_8056E858(self, flags);
    if (self->m4->m0 != 0xFF && Round(self->m10) <= 2)
        fn_8056E8B4(self, a, flags);
    if (self->m0->m0 != 0xFF && Round(self->m10) <= 2)
        fn_8056EA58(self, a, flags);
}

extern "C" DB_OVERLAY void fn_8056E130(DbSel* p)
{
    p->m2C = 0;
}

extern "C" DB_OVERLAY void fn_8056E13C(DbSel* self)
{
    if (Round(self->m10) <= 1) {
        if (self->m8->m0 == 0xFF && self->m4->m0 != 0xFF)
            fn_8056ED54(self, 1);
        if (Round(self->m10) <= 1 && self->m4->m0 == 0xFF && self->m0->m0 != 0xFF)
            fn_8056ED54(self, 0);
    }
}

extern "C" DB_OVERLAY void fn_8056E630(DbSel* self)
{
    int side = 0;
    if (self->m10->m1CD0 != 0)
        side = 1;
    unsigned char x = self->m8->m0;
    if (x != 0xFF) {
        fn_8056C0A0(self->m18, x);
        fn_8056BAEC(self->m18, x, side, 0);
        fn_80081CCC__FP13Unk8007FF8C_Yi(self->m10, 2);
    }
    DbQ* q = self->m4;
    fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m8, q->m0, q->m1, q->m4);
    q = self->m0;
    fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m4, q->m0, q->m1, q->m4);
    fn_80080B98__FP13Unk8007FF8C_Q(self->m0);
}

extern "C" DB_OVERLAY void fn_8056E6E4(DbSel* self, int flags)
{
    int side = 0;
    DbG* g = self->m10;
    if (g->m1CD0 != 0)
        side = 1;
    unsigned char c = self->m8->m0;
    if (c != 0xFF) {
        float f = ((float (*)(void*, int, int))fn_8007189C__FP1Wii)((char*)TeamAt(g, side) + 0xC9C, 0xD, c);
        if (!(f <= lbl_805FFC64)) {
            fn_8056C0A0(self->m18, c);
            fn_8056BAEC(self->m18, c, side, 0);
            fn_8056C610(self->m18, 2);
            fn_80080B98__FP13Unk8007FF8C_Q(self->m8);
        }
    }
    if (flags & 3) {
        DbQ* q1 = self->m4;
        if (q1->m0 != 0xFF) {
            if (self->m8->m0 == 0xFF) {
                fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m8, q1->m0, q1->m1, q1->m4);
                fn_80080B98__FP13Unk8007FF8C_Q(self->m4);
            }
        }
    }
    if (flags & 6) {
        DbQ* q0 = self->m0;
        if (q0->m0 != 0xFF) {
            if (self->m4->m0 == 0xFF) {
                float f2 = ((float (*)(void*, int, int))fn_8007189C__FP1Wii)((char*)TeamAt(self->m10, side) + 0xC9C, 0xD, q0->m0);
                if (!(f2 <= lbl_805FFC68)) {
                    DbQ* q2 = self->m0;
                    fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m4, q2->m0, q2->m1, q2->m4);
                    fn_80080B98__FP13Unk8007FF8C_Q(self->m0);
                }
            }
        }
    }
}

extern "C" DB_OVERLAY void fn_8056E858(DbSel* self, int flags)
{
    unsigned char x = self->m8->m0;
    fn_8056C0A0(self->m18, x);
    fn_8056BAEC(self->m18, x, *self->m14, 0);
    fn_80080B98__FP13Unk8007FF8C_Q(self->m8);
}

extern "C" DB_OVERLAY void fn_8056E8B4(DbSel* self, int a, int flags)
{
    if (self->m4->m0 != 0xFF) {
        if (fn_8006BE18__11Unk80069F0C(self->mC) == 1) {
            DbQ* q = self->m4;
            fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m8, q->m0, q->m1, q->m4);
            fn_80080B98__FP13Unk8007FF8C_Q(self->m4);
        } else if (a > 0 || (a == 0 && self->m20 != 0 && (flags & 0x10))) {
            fn_8056C0A0(self->m18, self->m4->m0);
            fn_8056BAEC(self->m18, self->m4->m0, self->m14[0], 0);
            fn_80080B98__FP13Unk8007FF8C_Q(self->m4);
        } else {
            float f = ((float (*)(void*, int, int))fn_8007189C__FP1Wii)((char*)TeamAt(self->m10, self->m14[0]) + 0xC9C, 0xD, self->m4->m0);
            if (flags & 8) {
                DbQ* q = self->m4;
                fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m8, q->m0, q->m1, q->m4);
                fn_80080B98__FP13Unk8007FF8C_Q(self->m4);
            } else if (!(f <= lbl_805FFC6C)) {
                fn_8056C0A0(self->m18, self->m4->m0);
                fn_8056BAEC(self->m18, self->m4->m0, self->m14[0], 1);
                fn_80080B98__FP13Unk8007FF8C_Q(self->m4);
            } else {
                DbQ* q = self->m4;
                fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m8, q->m0, q->m1, q->m4);
                fn_80080B98__FP13Unk8007FF8C_Q(self->m4);
                if (!(fn_8056FFB0() >= f * lbl_805FFC70))
                    fn_8056EC68(self, self->m8->m0, 1, self->m28, 2);
            }
        }
    }
}

extern "C" DB_OVERLAY void fn_8056EA58(DbSel* self, int a, int flags)
{
    if (self->m0->m0 != 0xFF) {
        if (fn_8006BE18__11Unk80069F0C(self->mC) == 1) {
            DbQ* q = self->m0;
            fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m4, q->m0, q->m1, q->m4);
            fn_80080B98__FP13Unk8007FF8C_Q(self->m0);
        } else if (a > 1 || (a == 1 && self->m20 != 0)) {
            fn_8056C0A0(self->m18, self->m0->m0);
            fn_8056BAEC(self->m18, self->m0->m0, self->m14[0], 0);
            fn_80081CCC__FP13Unk8007FF8C_Yi(self->m10, 0);
        } else {
            float f = ((float (*)(void*, int, int))fn_8007189C__FP1Wii)((char*)TeamAt(self->m10, self->m14[0]) + 0xC9C, 0xD, self->m0->m0);
            if (a == 0) {
                DbQ* q = self->m0;
                fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m4, q->m0, q->m1, q->m4);
                fn_80080B98__FP13Unk8007FF8C_Q(self->m0);
                if ((self->m8->m0 == 0xFF && !(f <= lbl_805FFC74) && (flags & 0x10) && ((flags & 1) || flags != 0)) || (self->m20 == 1 && (flags & 0x10))) {
                    DbQ* q2 = self->m4;
                    fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m8, q2->m0, q2->m1, q2->m4);
                    fn_80080B98__FP13Unk8007FF8C_Q(self->m4);
                }
            } else if (a == 1) {
                DbQ* q = self->m0;
                fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m8, q->m0, q->m1, q->m4);
                fn_80080B98__FP13Unk8007FF8C_Q(self->m0);
                if (!(f <= lbl_805FFC78)) {
                    fn_8056C0A0(self->m18, self->m8->m0);
                    fn_8056BAEC(self->m18, self->m8->m0, self->m14[0], 1);
                    fn_80080B98__FP13Unk8007FF8C_Q(self->m8);
                }
            }
        }
    }
}
