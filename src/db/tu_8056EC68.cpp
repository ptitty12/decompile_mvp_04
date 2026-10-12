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
