/*
 * Front-end overlay code, .frontend_codeoverlay 0x804439E4-0x80446CE8 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

extern "C" void fn_80330BC8(void* self);
extern "C" FE_OVERLAY void fn_80444090(void* self)
{
    fn_80330BC8(self);
}

extern int lbl_80621630;
extern int lbl_80621634;
extern int lbl_80621638;
extern int lbl_8061A328;

extern "C" FE_OVERLAY int fn_80444714(void)
{
    return lbl_80621630;
}

extern "C" FE_OVERLAY void fn_80444720(void)
{
    lbl_80621634 = lbl_8061A328 + 0x3C;
}

extern "C" FE_OVERLAY void fn_80444738(int a)
{
    if (a != 0) {
        lbl_80621630 = 0;
        fn_80444720();
    } else {
        lbl_80621630 = -1;
    }
}

extern "C" FE_OVERLAY int fn_8044477C(void)
{
    if (lbl_80621630 != -1 && lbl_8061A328 >= lbl_80621634) {
        lbl_80621630 = (lbl_80621630 + 1) % 4;
        fn_80444720();
        return 1;
    }
    return 0;
}

extern char lbl_8067CEB0[];
extern "C" FE_OVERLAY void fn_80444850(FeTimerRaw* self);
extern "C" FE_OVERLAY FeTimerRaw* fn_804447F0(FeTimerRaw* self)
{
    self->m20 = lbl_8067CEB0;
    self->mC4.Clear();
    self->m4 = 0;
    self->m0 = 0;
    fn_80444850(self);
    return self;
}

extern int lbl_8062163C;
extern "C" FE_OVERLAY void fn_80444850(FeTimerRaw* self)
{
    self->m8 = 3;
    self->mC = 3;
    self->mD = 0;
    self->mE = 1000;
    lbl_8062163C = 0;
    self->m10 = -1;
    self->m14 = -1;
    self->m18 = -1;
    self->m1C = 0;
}

extern "C" FE_OVERLAY void fn_80445090(FeTimer* self)
{
    int t = self->m8;
    if ((unsigned)(t - 1) <= 1 || (t == 0 && self->m14 != -1) || t == 4)
        self->s12();
    fn_80444FE4(self);
}

extern "C" FE_OVERLAY void fn_80445454(void* self)
{
    fn_800ECF18(self);
    if (fn_800A2E6C(lbl_80619948) != 0)
        fn_804A763C(fn_800B7AB8(UiGetMsgMgr(), "FTOPBAR"), 1);
}

extern "C" FE_OVERLAY void fn_80445564(FeScr2* self, int a, int b)
{
    self->m14C = b;
    ((FeObj1*)self)->v88(b);
    fn_80445DA8(self);
}

extern "C" FE_OVERLAY void fn_80445B18(FeScr2* self)
{
    ((FeObj1*)self)->v88(self->m14C);
    ((FeObj*)self)->v84();
}

extern "C" FE_OVERLAY void fn_80445B74(FeScr2* self)
{
    fn_80445BB4(self, fn_800A2AE8(lbl_80619948));
}

extern "C" FE_OVERLAY int fn_80445D5C(int a, int idx)
{
    return idx / 7;
}

extern "C" FE_OVERLAY int fn_80445D7C(int a, int idx)
{
    return idx % 7;
}

extern "C" FE_OVERLAY int fn_80446430(FeScr2* self, int i)
{
    return self->m148 + i;
}

extern "C" FE_OVERLAY int fn_8044643C(FeScr2* self, int a, int b)
{
    int r = 0;
    if (a >= self->m148) {
        int t = fn_804464B0(self, a + 1);
        if (t != 0 && b >= t)
            return a - (self->m148 - 1);
        r = a - self->m148;
    }
    return r;
}

extern "C" FE_OVERLAY int fn_80446534(void)
{
    if ((fn_8044477C() != 0 && lbl_80621638 == 0) || lbl_80621638 == 1)
        return 1;
    return 0;
}

extern "C" FE_OVERLAY int fn_804468F8(FeScr2* self, FeRec1C* rec)
{
    if (rec->m1C == 1 && fn_8040B574(rec->mC, "SELECTED") == 0) {
        ((FeObj2*)self)->v67(-1, 0);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_80446974(FeScr2* self)
{
    self->m158 = ((FeObjI*)self->m13C)->v60();
    self->m15C = ((FeObjI*)self->m13C)->v61();
}
