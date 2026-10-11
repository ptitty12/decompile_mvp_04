/*
 * Front-end overlay code, .frontend_codeoverlay 0x8044F550-0x80452120 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/tu_8043FDC0.h"

extern "C" FE_OVERLAY int fn_8044F550(FeScr6* self, FeObj* a, int b, int c)
{
    if (a == self->m138) {
        ((FeObj2*)self)->v67(c, 0);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_8044F5A8(FeScr6* self)
{
    ((FeObj1*)self)->v80(0);
    ((FeObj2*)self)->v67(((FeObjI*)self->m138)->v60(), 0);
    return 1;
}

/*
 * Front-end overlay code, .frontend_codeoverlay 0x8044F550-0x80452120 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

extern char lbl_8067C328[];
extern "C" FE_OVERLAY FeScrRaw* fn_8044F634(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067C328;
    self->m130 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_8044F984(FeW138* self)
{
    self->m138->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044F9C0(FeW138* self)
{
    self->m138->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044F9FC(FeW138* self)
{
    self->m138->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044FA38(FeW138* self)
{
    self->m138->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8044FA74(FeScr6* self, FeObj* a, int b, int c)
{
    if (a == self->m138) {
        ((FeObj2*)self)->v67(c, 0);
        return 1;
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_8044FACC(FeScr6* self)
{
    ((FeObj1*)self)->v80(0);
    ((FeObj2*)self)->v67(((FeObjI*)self->m138)->v60(), 0);
    return 1;
}

extern char lbl_8067C058[];
extern "C" FE_OVERLAY FeScr6Raw* fn_8044FB58(FeScr6Raw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D1070(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067C058;
    self->m10F0 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8044FBA4(FeScr6* self)
{
    fn_804D10D8(self);
    self->m10F0 = fn_800B7AB8(UiGetMsgMgr(), "BATPITCHSTATS");
}

extern "C" FE_OVERLAY void fn_80450284(FeScr6* self)
{
    if (((FeObjI*)self->m134)->v59() > 0) {
        int v = fn_804D1278(self);
        fn_80123858(self->m10F0, v, 1);
    } else
        fn_801240C0(self->m10F0);
}

extern "C" FE_OVERLAY void fn_804502F4(int a, FeScr6* b)
{
    Unk8007A4DC_Screen* s = (Unk8007A4DC_Screen*)lbl_8061930C;
    if (a == 0) {
        s->fn_8007A808(0xB, fn_804D1278(b), 1);
        if (b->m13C->m24 < 0)
            ((FeObj2*)b)->v67(2, 0);
    }
    fn_8044FE0C(b);
    fn_80450388(b);
}

extern "C" FE_OVERLAY void fn_80450460(FeScr6* self, int a)
{
    fn_800ED310(self, a);
    if (a != 0)
        ((FeObj1*)self->m134)->v14(1);
    else
        ((FeObj1*)self->m134)->v14(0);
}

extern "C" FE_OVERLAY void fn_804504DC(void)
{
    FePopupW* p = (FePopupW*)fn_800B7A94(UiGetMsgMgr(), "POPUP");
    ((FeObj1*)p)->v85(0);
    p->m314 = 1;
}

extern "C" FE_OVERLAY void fn_8045055C(void* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "EDIT", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), &m, self);
}

extern char lbl_8067BDB0[];
extern "C" FE_OVERLAY FeScr6Raw* fn_80450688(FeScr6Raw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648((FeScrRaw*)self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8067BDB0;
    self->m130 = 0;
    self->m17C = 0;
    self->m180 = 0;
    self->m184 = 0;
    self->m188 = 0;
    self->m18C = 0;
    self->m190 = 0;
    self->m198 = 4;
    return self;
}

extern "C" FE_OVERLAY void fn_804506F4(FeScr6* self)
{
    self->m188 = fn_800C8060(((FeObj*)self)->v32("GAMEGRID", 1));
    fn_800ECE34(self);
}

extern "C" FE_OVERLAY void fn_80450750(FeScr6* self)
{
    int i;
    for (i = 0; i < 72; i += 4)
        FeSetI((char*)&self->m134, i, -1);
    self->m17C = 0;
}

extern "C" FE_OVERLAY void fn_8045077C(FeScr6* self)
{
    fn_800ECF18(self);
    self->m198 = fn_800B555C()->m608;
    self->m194 = fn_800B7A94(UiGetMsgMgr(), "NAVBAR");
    fn_80450FCC(self);
    fn_80450C4C(self);
    fn_804509E0(self, 0, self->m198);
    self->m18C->m2F0 = fn_8045081C;
}

extern "C" FE_OVERLAY void fn_80450988(FeScr6* self, int a)
{
    self->m198 = a;
    fn_804509E0(self, ((FeObjI*)self->m188)->v60(), self->m198);
}

extern "C" FE_OVERLAY int fn_80450C44(void)
{
    return 1;
}

extern "C" FE_OVERLAY void fn_80450E44(FeScr6* self, int a)
{
    ((FeObj1*)fn_800C8040(((FeObj*)self)->v32("DATE", 1)))->v8(a);
    ((FeObj1*)fn_800C8040(((FeObj*)self)->v32("DATESHADOW", 1)))->v8(a);
}

extern "C" FE_OVERLAY void fn_80450FCC(FeScr6* self)
{
    fn_80450E44(self, 1);
    fn_80450EF8(self);
}

extern "C" FE_OVERLAY void fn_80451004(FeScr6* self)
{
    fn_80125BC0(self->m194);
}

extern int lbl_8062164C;
extern "C" FE_OVERLAY void fn_80451C78(void)
{
    int z = 0;
    lbl_8062164C = z;
}

extern "C" FE_OVERLAY void fn_80451E10(FeScr6* self, int a)
{
    if (a == (int)self->m188)
        fn_80451028(self, a);
}
