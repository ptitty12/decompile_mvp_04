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
/* forward declarations (definitions are in address order) */
extern "C" int fn_8056F6C8(void);
extern "C" void fn_8056FF68(DbMgr* self, int c);
extern "C" float fn_8056FFB0(void);
extern "C" void fn_8057001C(DbMgr* self, DbSelSrc* src);
extern "C" void fn_805700C0(DbMgr* self, DbSelSrc* src);
extern "C" void fn_80570138(DbMgr* self);
extern "C" void fn_80570170(DbMgr* self);
extern "C" void fn_80570C14(DbMgr* self);
extern "C" void fn_805715D8(DbMgr* self);
extern "C" void fn_805718E8(DbMgr* self);
extern "C" void fn_80571A94(DbMgr* self);
extern "C" void fn_8056F640(DbSel* self);
extern "C" void fn_80570630(DbMgr* self);
extern "C" void fn_80571AF8(DbMgr* self);
extern "C" void fn_80571EA0(DbMgr* self);
extern "C" void fn_8056F494(DbSel* self);

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
