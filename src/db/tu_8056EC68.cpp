/*
 * Database overlay code, .database_codeoverlay 0x8056EC68-0x805721F8 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8056BAEC.h"

extern char lbl_80693C7C[];
extern const float lbl_805FFDF8;
extern const float lbl_805FFD70;

extern const float lbl_805FFCD4;
extern const float lbl_805FFCD8;
extern const float lbl_805FFCDC;
extern const float lbl_805FFCE0;
extern const float lbl_805FFCE4;
extern const float lbl_805FFCE8;
extern const float lbl_805FFCEC;
extern const float lbl_805FFCF0;

extern "C" void fn_8056DE50(DbSel* self, DbSelSrc* src, DbScr* scr, int* sidep, void* x);

extern "C" {
void fn_805706B8(DbMgr* self, int mode);
int fn_8056FDC8(int a, int b);
}

/* Stack-slot down counter (saturates at -1), cf. Unk8006A138_It. */
struct DbDownIt {
    int v;
    DbDownIt(int x) { v = x; }
    ~DbDownIt() {}
    int Next()
    {
        int t;
        if (v > -1)
            t = v - 1;
        else
            t = v;
        v = t;
        return t;
    }
};

extern "C" void fn_8056EEA8(DbSel* self, int idx, int flag);

extern "C" void fn_8056E1D8(DbSel* s);

extern "C" {
float fn_8056CDDC(void* a, int idx, void* c);
void fn_8056C3AC(void* q, int x);
}

extern "C" void fn_8056C7A0(void* q, int a1, int a2, int a3, int a4, int a5);

struct Db805701E4_GS {
    char pad0[0x68];
    int m68;
};
extern Db805701E4_GS* lbl_80619948;

struct Db8056FDC8_Tbl {
    int w[5][4];
};
extern Db8056FDC8_Tbl lbl_805FFD18;

struct Unk80361600 {
    char pad0[0x18];
    Unk80361600();
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}
extern "C" void fn_8056CC50(void* p);
extern "C" void fn_8056B9DC(void* p);
extern "C" void fn_8014D860(void* rng, int seed);
extern "C" int rand(void);
extern "C" void* memset(void* p, int c, unsigned n);
typedef void* (*Db8056FE8C_MemsetV)(void*, int, ...);

extern "C" void fn_8057378C(DbMgr* self);
extern "C" void fn_8056DA98(void* p);
extern "C" void fn_80570828(DbMgr* self);
extern "C" void fn_80570E80(DbMgr* self);
extern "C" void fn_80571618(DbMgr* self);

extern "C" void fn_8056BEC8(DbScr* self);
extern "C" void fn_8056BE98(void* self);
extern "C" int fn_80570AB0(DbMgr* self);
extern "C" void fn_8056CC50(void* p);
extern "C" void fn_8056CC8C(void* self, int a, int b, int c, int d);
extern "C" int fn_800A8898(void* a);
extern "C" int fn_80571060(DbMgr* self, int a);

extern "C" void fn_805738F0(DbSub50* p, DbSelSrc* src);
extern "C" void fn_8056DE14(void* p);

struct Db80570D4C_F {
    char pad0[0x14];
    float m14;
    char pad18[8];
    float m20;
};
extern "C" void fn_80571928(DbMgr* self, int a);

extern const float lbl_805FFDEC;
extern const float lbl_805FFDF0;
extern const float lbl_805FFDF4;
extern "C" void fn_8056E6E4(DbSel* self, int a);
extern "C" void fn_8056C610(DbScr* s, int a);
extern "C" void fn_8056E630(DbSel* s, int a);

#include "game/clampiter.h"
extern "C" int fn_80572710(DbMgr* self);
extern "C" int fn_805721F8(DbMgr* self);
extern "C" int fn_80571F4C(DbMgr* self, int a, int b);

template <int MAX>
struct Db80571060_It {
    int v;
    ~Db80571060_It() {}
    int Next()
    {
        int t;
        if (v > MAX)
            t = v;
        else
            t = v + 1;
        v = t;
        return t;
    }
};

extern const float lbl_805FFCA8;
extern const float lbl_805FFCAC;

struct Db8056ED54_T {
    char pad0[0x1B4];
    unsigned char m1B4[0x80];
};
extern const float lbl_805FFC7C;
/* forward declarations (definitions are in address order) */
extern "C" int fn_8056EC68(DbSel* self, int a, int b, int c, int d);
extern "C" void fn_8056ED54(DbSel* self, int idx);
extern "C" void fn_8056F10C(DbSel* self);
extern "C" void fn_8056F494(DbSel* self);
extern "C" int fn_8056F51C(DbSel* self, int idx, void* p3);
extern "C" void fn_8056F640(DbSel* self);
extern "C" int fn_8056F6C8(void);
extern "C" int fn_8056FDC8(int a, int b);
extern "C" DbMgr* fn_8056FE8C(DbMgr* self);
extern "C" void fn_8056FF68(DbMgr* self, int c);
extern "C" float fn_8056FFB0(void);
extern "C" void fn_8057001C(DbMgr* self, DbSelSrc* src);
extern "C" void fn_805700C0(DbMgr* self, DbSelSrc* src);
extern "C" void fn_80570138(DbMgr* self);
extern "C" void fn_80570170(DbMgr* self);
extern "C" void fn_805701AC(DbMgr* self);
extern "C" int fn_805701E4(DbMgr* self);
extern "C" void fn_805702CC(DbMgr* self, int a, int b, int c);
extern "C" void fn_805704CC(DbMgr* self);
extern "C" void fn_80570630(DbMgr* self);
extern "C" void fn_80570C14(DbMgr* self);
extern "C" void fn_80570C38(DbMgr* self, int a, int b);
extern "C" void fn_80570D4C(DbMgr* self);
extern "C" int fn_80571060(DbMgr* self, int mode);
extern "C" void fn_805714C0(DbMgr* self);
extern "C" void fn_805715D8(DbMgr* self);
extern "C" void fn_805718E8(DbMgr* self);
extern "C" void fn_80571928(DbMgr* self, int mode);
extern "C" void fn_80571A94(DbMgr* self);
extern "C" void fn_80571AF8(DbMgr* self);
extern "C" void fn_80571BD0(DbMgr* self);
extern "C" void fn_80571EA0(DbMgr* self);

/* near-miss: 2 slots (addi r26,r27,1 lands after the call); CR4 flag form reproduced */
extern "C" DB_OVERLAY int fn_8056EC68(DbSel* self, int a, int b, int c, int d)
{
    int next = d + 1;
    int r = fn_8056F51C(self, b, (void*)b);
    if (r == 0) {
        int* sub = self->m14;
        DbT* t = TeamAt(self->m10, sub[1]);
        int side = sub[1];
        fn_8056BAEC(self->m18, a, sub[0], 0);
        unsigned char* row = (unsigned char*)t + 0x17C;
        fn_8056BAEC(self->m18, row[b], side, 0);
        int v = next;
        if (b == 1)
            v = 3;
        fn_8056C7A0(self->m18, v, a, b, c, 4);
        if (d >= 0)
            fn_80081CCC__FP13Unk8007FF8C_Yi(self->m10, d);
    } else {
        fn_8056F640(self);
    }
    return r == 0;
}

extern "C" DB_OVERLAY void fn_8056ED54(DbSel* self, int idx)
{
    DbQ* q = fn_80081CF8__FP13Unk8007FF8C_Yi(self->m10, idx);
    if (q->m0 != 0xFF && q->m8 != 1) {
        int* sub = self->m14;
        DbG* g = self->m10;
        Db8056ED54_T* ta = (Db8056ED54_T*)TeamAt(g, sub[0]);
        Db8056ED54_T* tb = (Db8056ED54_T*)TeamAt(g, sub[1]);
        int rd = Round(g);
        int sa = 0;
        for (int i = 0; i < 0x80; i++)
            sa += ta->m1B4[(unsigned char)i];
        int sb = 0;
        for (int i = 0; i < 0x80; i++)
            sb += tb->m1B4[(unsigned char)i];
        if (rd <= 1 && sa - sb <= 4) {
            if (fn_80081CF8__FP13Unk8007FF8C_Yi(self->m10, idx + 1)->m0 == 0xFF) {
                unsigned char b = q->m0;
                if (b != 0xFF) {
                    q->m8 = 1;
                    float f = ((float (*)(void*, int, int))fn_8007189C__FP1Wii)((char*)ta + 0xC9C, 0x14, b);
                    float p = f * lbl_805FFC7C * f;
                    float rr = fn_8056FFB0();
                    if (!(rr >= p))
                        fn_8056EEA8(self, idx, 0);
                }
            }
        }
    }
}

extern "C" DB_OVERLAY void fn_8056F10C(DbSel* self)
{
    float f;
    float p;
    int did = 0;
    if (Round(self->m10) <= 1) {
        Unk8006A138_It<3> it(0);
        int i = 0;
        do {
            if (fn_80081CF8__FP13Unk8007FF8C_Yi(self->m10, i)->m0 != 0xFF) {
                int side = self->m14[0];
                unsigned char bt = fn_80081CF8__FP13Unk8007FF8C_Yi(self->m10, it.v)->m0;
                f = ((float (*)(void*, int, int))fn_8007189C__FP1Wii)((char*)TeamAt(self->m10, side) + 0xC9C, 0x15, bt);
                p = (lbl_805FFCA8 - f) * lbl_805FFCAC;
                if (!(fn_8056FFB0() >= p)) {
                    self->m20 = 1;
                    fn_8056EEA8(self, it.v, 0);
                    did = 1;
                    self->m20 = 0;
                    break;
                }
            }
            i = it.Next();
        } while (i <= 2);
    }
    if (did == 0)
        self->m20 = 1;
}

/* near-miss: ~8 slots; retail stores the counter before loading r3 and schedules li r5,0 later */
extern "C" DB_OVERLAY void fn_8056F494(DbSel* self)
{
    DbDownIt it(2);
    if (fn_80081CF8__FP13Unk8007FF8C_Yi(self->m10, 2)->m0 != 0xFF) {
        int i;
        do {
            if (Round(self->m10) > 2)
                break;
            fn_8056EEA8(self, it.v, 0);
            i = it.Next();
        } while (i >= 0);
    }
}

extern "C" DB_OVERLAY int fn_8056F51C(DbSel* self, int idx, void* p3)
{
    if (self->m24 == 0)
        return 0;
    int side = self->m14[1];
    float a = fn_8056CDDC(self->m1C, idx, p3);
    float b = 2.0f * fn_8056FFB0();
    int r = 0;
    if (!(b >= a)) {
        fn_8056C3AC(self->m18, idx);
        unsigned char* row = (unsigned char*)TeamAt(self->m10, side) + 0x17C;
        fn_8056BAEC(self->m18, row[idx], side, 0);
        if (Round(self->m10) > 1) {
            unsigned char x1 = self->m4->m0;
            DbQ* q0 = self->m0;
            unsigned char x2 = self->m8->m0;
            if (q0->m0 != 0xFF)
                fn_80080BB4__FP13Unk8007FF8C_Qiii(q0, q0->m0, q0->m1, 0);
            if (x1 != 0xFF) {
                DbQ* q1 = self->m4;
                fn_80080BB4__FP13Unk8007FF8C_Qiii(q1, x1, q1->m1, 0);
            }
            if (x2 != 0xFF) {
                DbQ* q2 = self->m8;
                fn_80080BB4__FP13Unk8007FF8C_Qiii(q2, x2, q2->m1, 0);
            }
        }
        r = 1;
    }
    return r;
}

extern "C" DB_OVERLAY void fn_8056F640(DbSel* self)
{
    unsigned char x = self->m8->m0;
    if (x != 0xFF) {
        fn_8056C0A0(self->m18, x);
        fn_80080B98__FP13Unk8007FF8C_Q(self->m8);
    }
    DbQ* q = self->m4;
    fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m8, q->m0, q->m1, 0);
    fn_80080B98__FP13Unk8007FF8C_Q(self->m4);
    q = self->m0;
    fn_80080BB4__FP13Unk8007FF8C_Qiii(self->m4, q->m0, q->m1, 0);
    fn_80080B98__FP13Unk8007FF8C_Q(self->m0);
}

extern "C" DB_OVERLAY int fn_8056F6C8(void)
{
    int r = 2;
    float x = fn_8056FFB0();
    if (!(x < lbl_805FFCD4)) {
        if (!(x >= lbl_805FFCD8))
            r = 3;
        else if (!(x >= lbl_805FFCDC))
            r = 5;
        else if (!(x >= lbl_805FFCE0))
            r = 4;
        else if (!(x >= lbl_805FFCE4))
            r = 1;
        else if (!(x >= lbl_805FFCE8))
            r = 8;
        else if (!(x >= lbl_805FFCEC))
            r = 7;
        else {
            int f = x < lbl_805FFCF0;
            r = f << 3;
        }
    }
    return r;
}

extern "C" DB_OVERLAY int fn_8056FDC8(int a, int b)
{
    if (a == 5)
        return 12;
    Db8056FDC8_Tbl t = lbl_805FFD18;
    int k = 3;
    if (b & 0x10) {
        if (b & 1)
            k = 0;
        if (b & 4)
            k = 2;
        if (b & 2)
            k = 1;
    }
    return t.w[a - 1][k];
}

extern "C" DB_OVERLAY DbMgr* fn_8056FE8C(DbMgr* self)
{
    DbSub50* sub = &self->m50;
    self->m0 = 0;
    self->m4 = 0;
    self->m8 = 0;
    self->mC = 0;
    self->m10 = 0;
    fn_8056CC50((char*)self + 0x14);
    Unk80361600* e = (Unk80361600*)((char*)self + 0x64);
    int k = 1;
    do {
        new (e) Unk80361600;
        e++;
    } while (k-- != 0);
    fn_80573840(sub);
    ((Db8056FE8C_MemsetV)memset)(&self->mCC, 0, 0x30);
    fn_8056B9DC(&self->mFC);
    self->m114 = 0;
    self->m118 = 0x2A;
    fn_8014D860(lbl_80693C7C, rand() % 0x7FFFFFFF);
    return self;
}

extern "C" DB_OVERLAY void fn_8056FF68(DbMgr* self, int c)
{
    fn_8056BA20(&self->mFC, 2);
    if (c & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY float fn_8056FFB0(void)
{
    float f = (float)fn_8014D8AC(lbl_80693C7C, 1000000, 0, 0) * lbl_805FFD70;
    return f;
}

extern "C" DB_OVERLAY void fn_8057001C(DbMgr* self, DbSelSrc* src)
{
    fn_80573840(&self->m50);
    int flag = 1;
    int k = src->m10->m20;
    if (k == 0 || (k == 2 && src->mC->m84 != 0))
        flag = 0;
    self->m8 = src;
    self->mC = src->m14;
    fn_8056BA80(&self->mFC, src, flag);
    fn_8056DE50(&self->mCC, self->m8, &self->mFC, &self->m50.m0, &self->m14);
    self->m10 = 1;
}

extern "C" DB_OVERLAY void fn_805700C0(DbMgr* self, DbSelSrc* src)
{
    self->m8 = src;
    self->mC = src->m14;
    fn_8056BA80(&self->mFC, src, 1);
    fn_80573918(&self->m50, src);
    fn_8056DE50(&self->mCC, self->m8, &self->mFC, &self->m50.m0, &self->m14);
    self->m10 = 1;
}

extern "C" DB_OVERLAY void fn_80570138(DbMgr* self)
{
    fn_8056BACC(&self->mFC);
    self->m10 = 0;
}

extern "C" DB_OVERLAY void fn_80570170(DbMgr* self)
{
    fn_80573918(&self->m50, self->m8);
    fn_8056BD50(&self->mFC);
}

extern "C" DB_OVERLAY void fn_805701AC(DbMgr* self)
{
    while (fn_805701E4(self) == 0) {
    }
}

extern "C" DB_OVERLAY int fn_805701E4(DbMgr* self)
{
    if (fn_8006BE18__11Unk80069F0C(self->m8) == 1)
        return 1;
    int k = 0;
    lbl_80619948->m68 = 1;
    DbSelSrc* s = self->m8;
    int a = s->m14->m1CC8;
    int f = a >= s->m10->m1C - 1;
    if (s->m14->m1CD0 != 0)
        k = 1;
    if (f == 1) {
        while (self->m50.m0 == k) {
            if (fn_8006BE18__11Unk80069F0C(self->m8) == 1)
                return 1;
            fn_805704CC(self);
        }
    } else {
        while (self->m50.m0 == k)
            fn_805704CC(self);
    }
    return fn_8006BE18__11Unk80069F0C(self->m8);
}

extern "C" DB_OVERLAY void fn_805702CC(DbMgr* self, int a, int b, int c)
{
    *(int*)((char*)self + 0xC4) = (c == 0 || c == 2) ? 1 : 0;
    if ((unsigned)(c - 1) <= 1)
        *(int*)((char*)self + 0xC8) = 1;
    else
        *(int*)((char*)self + 0xC8) = 0;
    self->m118 = 0x2A;
    DbSub50* sub = &self->m50;
    fn_805738F0(sub, self->m8);
    if (self->m8->m14->m1CC8 != 0)
        fn_80571060(self, 1);
    fn_80573918(sub, self->m8);
    fn_8056BEC8(&self->mFC);
    if ((unsigned)(a - 5) <= 3) {
        ((void (*)(DbMgr*, int, int))fn_80570C14)(self, a, b);
        fn_80570630(self);
        if (fn_8006BE18__11Unk80069F0C(self->m8) != 0)
            fn_8056BE98(&self->mFC);
        self->m118 = 0x2A;
    } else {
        fn_8056CC8C((char*)self + 0x14, (int)sub, (int)self->mC, (int)self->m8, 1);
        if ((unsigned)(a - 3) <= 1)
            fn_8056DE14((char*)self + 0x14);
        fn_80570C38(self, a, b);
        fn_8056BAEC(&self->mFC, TeamAt(self->mC, sub->m4)->m17C, sub->m4, 0);
        DbSelSrc* src = self->m8;
        DbBL* bl = (DbBL*)((char*)TeamAt(src->m14, fn_800A8898(src)) + 0x168);
        bl->mC = (bl->mC + 1) % bl->m4;
        fn_80081D70__FP13Unk8007FF8C_Y(src->m14);
        if (fn_80571060(self, 0) == 1)
            fn_80573918(sub, self->m8);
        fn_80570630(self);
        if (fn_8006BE18__11Unk80069F0C(self->m8) == 1) {
            fn_8056BE98(&self->mFC);
        } else if (self->m8->m14->m1CC8 != 0) {
            fn_80571060(self, 1);
        }
    }
}

extern "C" DB_OVERLAY void fn_805704CC(DbMgr* self)
{
    self->m118 = 0x2A;
    DbSub50* sub = &self->m50;
    sub->m78 = 0;
    sub->m74 = 0;
    fn_80573918(sub, self->m8);
    fn_8056BEC8(&self->mFC);
    fn_8056CC50((char*)self + 0x14);
    fn_8056CC8C((char*)self + 0x14, (int)sub, (int)self->mC, (int)self->m8, 0);
    fn_80570828(self);
    fn_8057378C(self);
    fn_8056BAEC(&self->mFC, TeamAt(self->mC, sub->m4)->m17C, sub->m4, 0);
    DbSelSrc* src = self->m8;
    DbBL* b = (DbBL*)((char*)TeamAt(src->m14, fn_800A8898(src)) + 0x168);
    b->mC = (b->mC + 1) % b->m4;
    fn_80081D70__FP13Unk8007FF8C_Y(src->m14);
    if (fn_80571060(self, 0) == 1)
        fn_80573918(sub, self->m8);
    fn_80570630(self);
    if (fn_8006BE18__11Unk80069F0C(self->m8) != 0) {
        fn_8056BE98(&self->mFC);
    } else if (self->m8->m14->m1CC8 != 0 && fn_80571060(self, 1) == 1) {
        fn_80573918(sub, self->m8);
    }
}

extern "C" DB_OVERLAY void fn_80570630(DbMgr* self)
{
    if (Round(self->mC) > 2) {
        DbG* g = self->m8->m14;
        unsigned char a = g->m1CC8;
        int b = g->m1CD0;
        DbScr* s = &self->mFC;
        fn_8056BE34(s);
        DbG* g2 = self->m8->m14;
        if (g2->m1CC8 != a || g2->m1CD0 != b)
            fn_8056BDD0(s);
        fn_80573918(&self->m50, self->m8);
    }
}

extern "C" DB_OVERLAY void fn_80570C14(DbMgr* self)
{
    fn_8056F228(&self->mCC);
}

extern "C" DB_OVERLAY void fn_80570C38(DbMgr* self, int a, int b)
{
    if (fn_80570AB0(self) == 0) {
        switch (b) {
        case 0:
            break;
        case 1:
            fn_8056DA98((char*)self + 0x14);
            break;
        case 2:
            fn_805718E8(self);
            return;
        case 3:
            fn_80571618(self);
            return;
        }
        switch (a) {
        case 1:
            fn_80570D4C(self);
            break;
        case 2:
            fn_80570E80(self);
            break;
        case 3:
        case 4: {
            DbSel* s = &self->mCC;
            fn_8056F10C(s);
            fn_80570828(self);
            if (self->m118 == 0x11)
                self->m118 = 0x10;
            if (self->m118 == 0x10)
                fn_8056F494(s);
            break;
        }
        case 0:
            fn_80570828(self);
            break;
        }
        fn_8057378C(self);
    }
}

extern "C" DB_OVERLAY void fn_80570D4C(DbMgr* self)
{
    DbQ* q0 = fn_80081CF8__FP13Unk8007FF8C_Yi(self->mC, 0);
    DbQ* q1 = fn_80081CF8__FP13Unk8007FF8C_Yi(self->mC, 1);
    DbQ* q2 = fn_80081CF8__FP13Unk8007FF8C_Yi(self->mC, 2);
    if (q0->m0 == 0xFF && q1->m0 == 0xFF && q2->m0 == 0xFF) {
        fn_80570E80(self);
        return;
    }
    Db80570D4C_F* f = (Db80570D4C_F*)((char*)self + 0x14);
    float a = f->m14;
    float b = f->m20;
    float r = fn_8056FFB0();
    float lo = a;
    float hi = lo + b;
    if (!(r >= lo)) {
        fn_80571A94(self);
    } else if (!(r >= hi)) {
        fn_805715D8(self);
    } else if (Round(self->mC) <= 1) {
        fn_80571928(self, 1);
    } else {
        fn_805714C0(self);
        if (self->m118 == 0x19 || self->m118 == 0x1B)
            self->m118 = 0x1D;
    }
}

extern "C" DB_OVERLAY int fn_80571060(DbMgr* self, int mode)
{
    int result = 0;
    Db80571060_It<9> ii;
    Db80571060_It<1> oi;
    if (fn_8006BE18__11Unk80069F0C(self->m8) == 0) {
        oi.v = 0;
        int i = 0;
        do {
            DbSub50* sub = &self->m50;
            if ((sub->m78 == 0 && i == 1) || (sub->m74 == 0 && oi.v == 0) || *(int*)((char*)TeamAt(self->m8->m14, oi.v) + 0x108) == 1) {
                DbT* t = TeamAt(self->m8->m14, oi.v);
                unsigned char p = t->m17C;
                if (fn_80097148(t, p) == 1 || fn_80097148(t, p) == 3 || mode == 1) {
                    int r;
                    int sd = self->m50.m0;
                    if (oi.v == sd)
                        r = fn_80572710(self);
                    else
                        r = fn_805721F8(self);
                    if (r == 1)
                        result = 1;
                }
                ii.v = 1;
                int j = 1;
                do {
                    unsigned char* base = &t->m17C;
                    unsigned char q = base[j];
                    if (q != 0xFF) {
                        if (fn_80097148(t, q) == 1 || fn_80097148(t, q) == 3) {
                            if (fn_80571F4C(self, oi.v, ii.v) == 1)
                                result = 1;
                        }
                    }
                    j = ii.Next();
                } while (j <= 9);
            }
            i = oi.Next();
        } while (i <= 1);
    }
    return result;
}

extern "C" DB_OVERLAY void fn_805714C0(DbMgr* self)
{
    DbSel* s = &self->mCC;
    fn_8056E1D8(s);
    int v;
    if (s->m2C == 1) {
        switch (s->m28) {
        case 2:
            v = 0x1E;
            break;
        case 3:
            v = 0x1F;
            break;
        case 4:
            v = 0x20;
            break;
        case 5:
            v = 0x21;
            break;
        case 1:
            v = 0x22;
            break;
        case 0:
            v = 0x23;
            break;
        default:
            return;
        }
    } else {
        switch (s->m28) {
        case 2:
            v = 0x18;
            break;
        case 3:
            v = 0x19;
            break;
        case 4:
            v = 0x1A;
            break;
        case 5:
            v = 0x1B;
            break;
        case 1:
            v = 0x1C;
            break;
        case 0:
            v = 0x1D;
            break;
        default:
            return;
        }
    }
    self->m118 = v;
}

extern "C" DB_OVERLAY void fn_805715D8(DbMgr* self)
{
    self->m118 = 13;
    fn_8056C2B4(&self->mFC);
    fn_8056DEF4(&self->mCC);
}

extern "C" DB_OVERLAY void fn_805718E8(DbMgr* self)
{
    self->m118 = 15;
    fn_8056DEF4(&self->mCC);
    fn_8056C520(&self->mFC);
}

extern "C" DB_OVERLAY void fn_80571928(DbMgr* self, int mode)
{
    if (mode == 2) {
        fn_8056E6E4(&self->mCC, self->m0);
        return;
    }
    if (Round(self->mC) > 1) {
        fn_805714C0(self);
        return;
    }
    self->m0 |= 8;
    fn_8056C610(&self->mFC, 1);
    fn_8056E630(&self->mCC, 0);
    float r = fn_8056FFB0();
    int k = 1;
    int st;
    if (!(r >= lbl_805FFDEC)) {
        st = 0x1D;
        k = 0;
    } else if (!(r >= lbl_805FFDF0)) {
        st = 0x1C;
    } else if (!(r >= lbl_805FFDF4)) {
        st = 0x18;
        k = 2;
    } else {
        st = 0x1A;
        k = 4;
    }
    self->m118 = st;
    int v = ((int (*)(DbSel*, int))fn_8056F51C)(&self->mCC, k);
    DbSub50* sub = &self->m50;
    DbT* t = TeamAt(self->mC, sub->m0);
    unsigned char p = t->m168[t->m174];
    if (v != 0) {
        fn_80081C94__FP13Unk8007FF8C_Yiiii(self->mC, 0, p, TeamAt(self->mC, sub->m4)->m17C, 0);
    } else {
        fn_8056C7A0(&self->mFC, 0, p, 2, 1, 4);
    }
}

/* near-miss: 5 slots; retail places li r0,0x11 between fcmpu and cror */
extern "C" DB_OVERLAY void fn_80571A94(DbMgr* self)
{
    float r = fn_8056FFB0();
    int v = 0x11;
    if (!(r >= lbl_805FFDF8))
        v = 0x10;
    self->m118 = v;
    fn_8056C6BC(&self->mFC);
    fn_8056E130(&self->mCC);
}

extern "C" DB_OVERLAY void fn_80571AF8(DbMgr* self)
{
    fn_805706B8(self, self->m4);
    self->m118 = fn_8056FDC8(self->m4, self->m0);
    DbG* g = self->m8->m14;
    fn_8056E02C(&self->mCC, 0, self->m0);
    if (Round(g) <= 2) {
        int side = 0;
        if (g->m1CD0 != 0)
            side = 1;
        DbT* t = TeamAt(g, side);
        DbT* u = TeamAt(g, side ^ 1);
        unsigned char other = u->m17C;
        unsigned char cur = t->m168[t->m174];
        DbScr* s = &self->mFC;
        fn_8056C1C4(s, 1);
        fn_8056BAEC(s, cur, side, 0);
        fn_80081C94__FP13Unk8007FF8C_Yiiii(g, 0, cur, other, 1);
    }
}

extern "C" DB_OVERLAY void fn_80571BD0(DbMgr* self)
{
    fn_805706B8(self, self->m4);
    self->m118 = fn_8056FDC8(self->m4, self->m0);
    DbG* g = self->m8->m14;
    fn_8056E02C(&self->mCC, 1, self->m0);
    if (Round(g) <= 2) {
        int sa = self->m50.m0;
        int sb = self->m50.m4;
        DbT* ta = TeamAt(g, sa);
        unsigned char p = ta->m168[ta->m174];
        unsigned char cur = TeamAt(g, sb)->m17C;
        if (fn_80081CF8__FP13Unk8007FF8C_Yi(g, 1)->m0 == 0xFF) {
            fn_8056C1C4(&self->mFC, 2);
            fn_8056BAEC(&self->mFC, p, sa, 0);
            fn_80081C94__FP13Unk8007FF8C_Yiiii(g, 1, p, cur, 1);
        } else {
            self->m4 = 1;
            unsigned m = self->m0;
            if (m & 4)
                self->m118 = 2;
            else if (m & 2)
                self->m118 = 1;
            else
                self->m118 = 0;
            fn_8056C1C4(&self->mFC, 1);
            fn_80081C94__FP13Unk8007FF8C_Yiiii(g, 0, p, cur, 1);
        }
    }
}

extern "C" DB_OVERLAY void fn_80571EA0(DbMgr* self)
{
    fn_805706B8(self, self->m4);
    self->m118 = fn_8056FDC8(self->m4, self->m0);
    DbG* g = self->m8->m14;
    fn_8056E02C(&self->mCC, 3, self->m0);
    if (Round(g) <= 2) {
        int side = self->m50.m0;
        DbT* t = TeamAt(g, side);
        unsigned char cur = t->m168[t->m174];
        DbScr* s = &self->mFC;
        fn_8056C1C4(s, 4);
        fn_8056BAEC(s, cur, side, 0);
        fn_8056C0A0(s, cur);
    }
}
