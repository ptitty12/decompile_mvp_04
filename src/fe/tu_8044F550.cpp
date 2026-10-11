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

extern "C" FE_OVERLAY void fn_8044F884(FeScr6* self, int k)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    if (k == 4) {
        fn_8040B830(p->name, (char*)lbl_80621648, 15);
        p->name[15] = 0;
    } else {
        FeObjQ* cell = (FeObjQ*)fn_800C8060(((FeObj*)self)->v32("CELL", 1));
        FeObjQ* o = cell->v70();
        UiItemN* it = o->v33(5, 1);
        fn_8040B830(p->name, it->name, 15);
        p->name[15] = 0;
    }
    fn_800B7B4C(UiGetMsgMgr(), &m, self);
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

/* near-miss: popup args built in r4 by retail, in r3 here (call result is saved and reloaded); 4 slots */
extern "C" FE_OVERLAY void fn_8045017C(FeScr6* self, int a)
{
    if (a != 1) {
        if (a == 4) {
            FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
            fn_80131F34(p, self, (FeCb)fn_804502F4, fn_80528918, 0x38C2, 2, -1, 1, 0x35E9, 0x26DF, 0, 0, 0, 0);
            p->v86();
        } else {
            fn_804D1CB8(self);
        }
    } else {
        FeSt8* q = (FeSt8*)((char*)fn_800B555C() + 8);
        q->m4F4 = fn_804D1278(self);
        ((FeObj*)self)->v88();
    }
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

extern "C" FE_OVERLAY void fn_80450388(FeScr6* self)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    fn_80131F34(p, self, (FeCb)fn_80528920, 0, 0x1FED, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    ((FeObj1*)p)->v84(0);
    p->v86();
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

/* near-miss: retail hoists the second lis lbl_8061A32C above the first vcall pair (7 slots) */
extern "C" FE_OVERLAY void fn_80450C4C(FeScr6* self)
{
    if (self->m18C == 0) {
        self->m18C = (FeSlotObj*)fn_800B7A94(UiGetMsgMgr(), "NOTIFIEDSIMPROG");
        self->m18C->m30C = fn_80451C78;
        ((FeObj1*)self->m18C)->v8(0);
        ((FeObj1*)self->m18C)->v16(0);
    }
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
    self->m190 = p;
    ((FeObj1*)p)->v16(0);
    ((FeObj1*)self->m190)->v8(0);
}

inline int FeSlotAt(char* b, int k)
{
    int o = k * 4;
    return *(int*)(b + o);
}

extern "C" FE_OVERLAY void fn_80450D78(FeScr6* self, int a)
{
    fn_800ED310(self, a);
    ((FeObj1*)fn_800B7AB8(UiGetMsgMgr(), "FTOPBAR"))->v16(a);
    if (a != 0)
        ((FeObj1*)self->m188)->v14(1);
    else
        ((FeObj1*)self->m188)->v14(0);
}

extern "C" FE_OVERLAY void fn_80450E44(FeScr6* self, int a)
{
    ((FeObj1*)fn_800C8040(((FeObj*)self)->v32("DATE", 1)))->v8(a);
    ((FeObj1*)fn_800C8040(((FeObj*)self)->v32("DATESHADOW", 1)))->v8(a);
}

extern "C" FE_OVERLAY void fn_80450EF8(FeScr6* self)
{
    char buf[0x40];
    int d;
    FeObj* date = fn_800C8040(((FeObj*)self)->v32("DATE", 1));
    FeObj* shadow = fn_800C8040(((FeObj*)self)->v32("DATESHADOW", 1));
    d = fn_800B555C()->m14;
    fn_800DD44C(&d, buf, 1);
    ((FeObj1*)date)->v28((int)buf);
    ((FeObj1*)shadow)->v28((int)buf);
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

/* near-miss: 6 slots; retail keeps the byte offset in r0 and the array base in r9 */
extern "C" FE_OVERLAY void fn_80451028(FeScr6* self, int a)
{
    fn_80124FA8(self->m194, self);
    fn_80125154(self->m194, 0);
    if (self->m17C > 0
        && fn_8007FDA8((Unk8007F198_C*)lbl_8061930C, FeSlotAt((char*)&self->m134, self->m17C - 1), self->m198) == 0)
        fn_801251CC(self->m194, 0, 0x37E6, 1);
    else
        fn_80125084(self->m194, 0);
    int e = FeGetI((char*)&self->m134, ((FeObjI*)self->m188)->v60() * 4);
    if (e != -1 && fn_8007FDA8((Unk8007F198_C*)lbl_8061930C, e, self->m198) != 0)
        fn_801251CC(self->m194, 3, 0x27D7, 5);
    else
        fn_80125084(self->m194, 3);
    if (self->m184 != 0)
        fn_801251CC(self->m194, 2, 0x23F3, 4);
    else
        fn_80125084(self->m194, 2);
}

extern "C" FE_OVERLAY int fn_8045115C(FeW188* self)
{
    self->m188->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_80451198(FeW188* self)
{
    self->m188->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804511D4(FeW188* self)
{
    self->m188->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_80451210(FeW188* self)
{
    self->m188->v53();
    return 1;
}

extern int lbl_8062164C;
extern "C" FE_OVERLAY void fn_80451C78(void)
{
    int z = 0;
    lbl_8062164C = z;
}

extern "C" FE_OVERLAY void fn_80451C88(int a)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "DAYSGAMES");
    switch (a) {
    case 0:
        ((FeObj2*)p)->v67(2, 0);
        break;
    case 1:
        ((FeObj2*)p)->v67(3, 0);
        break;
    case 2:
        break;
    }
}

extern "C" FE_OVERLAY void fn_80451D40(FeScr6* self)
{
    int t = lbl_8062164C;
    if (t == 0) {
        lbl_8062164C = -1;
        fn_804509E0(self, ((FeObjI*)self->m188)->v60(), self->m198);
        if (self->m180 != 0) {
            UiMsg m;
            UiMsg* p = &m;
            fn_8035682C(p);
            fn_8040B830(p->name, "PLAY", 15);
            p->name[15] = t;
            fn_800B7B4C(UiGetMsgMgr(), &m, self);
        }
    }
}

extern "C" FE_OVERLAY void fn_80451E10(FeScr6* self, int a)
{
    if (a == (int)self->m188)
        fn_80451028(self, a);
}
