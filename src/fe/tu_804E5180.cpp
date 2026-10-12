/*
 * Front-end overlay code, .frontend_codeoverlay 0x804E5180-0x804E750C (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

class FeObjQ13 : public UiBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(int a); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(int a); virtual void v17(); virtual void v18(int a);
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(char* b); virtual void v29(); virtual void v30(); virtual void v31();
    virtual FeObjQ13* v32(const char* a, int b); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
    virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
    virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
    virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
    virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
    virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115();
    virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
    virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123();
    virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127();
};
extern const char lbl_805FA6F4[];
extern const char lbl_805FA6FC[];
extern const char lbl_805FA704[];
extern const char lbl_805FA708[];
extern const char lbl_805F4EF4[];
struct FeStQ13 {
    char pad0[0x4F0];
    int m4F0;
    char pad4F4[0x614 - 0x4F4];
    int m614;
    int m618;
};
void fn_800E2944(int a, int b);
extern "C" void fn_800ECE34(void* x);

extern char lbl_8066C4D0[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E5180(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066C4D0;
    self->m130 = 0;
    self->m134 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_804E5518(FeScr_80447264* self)
{
    self->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E5554(FeScr_80447264* self)
{
    self->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E5590(FeScr_80447264* self)
{
    self->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E55CC(FeScr_80447264* self)
{
    self->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E58BC(FeObj* self)
{
    ((FeObj2*)self)->v67(1, fn_800C8070(self));
    return 1;
}

extern "C" FE_OVERLAY void fn_804E5914(void)
{
    fn_800E25E0((int)fn_800B7A94(UiGetMsgMgr(), "NAVBAR"), 0);
}

extern char lbl_8066C228[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E5974(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066C228;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_804E5EFC(FeS5* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    switch (((FeObjK*)self->m138)->v61()) {
    case 0:
        fn_8040B830(p->name, "CREDITS", 15);
        p->name[15] = 0;
        break;
    case 1:
        fn_8040B830(p->name, "TEAMS", 15);
        p->name[15] = 0;
        break;
    case 2:
        fn_8040B830(p->name, "PLAYERS", 15);
        p->name[15] = 0;
        break;
    case 3:
        fn_8040B830(p->name, "JERSEYS", 15);
        p->name[15] = 0;
        break;
    case 4:
        fn_8040B830(p->name, "STADIUMS", 15);
        p->name[15] = 0;
        break;
    default:
        return 0;
    }
    fn_800B7B4C(UiGetMsgMgr(), &m, self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E6030(FeObj* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "BACK", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), p, self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E60B8(FeWf138* self)
{
    self->m138->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E60F4(FeWf138* self)
{
    self->m138->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E6130(FeWf138* self)
{
    self->m138->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E616C(FeWf138* self)
{
    self->m138->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E61A8(FeWf138* self)
{
    self->m138->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E61E4(FeWf138* self)
{
    self->m138->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E6220(FeWf138* self)
{
    self->m138->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E625C(FeWf138* self)
{
    self->m138->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E6298(FeObj* self)
{
    ((FeObj1*)self)->v41(fn_800C8070(self));
    return 1;
}

extern "C" FE_OVERLAY void fn_804E62EC(FeS5* self)
{
    int v = ((FeObjK*)self->m138)->v61();
    if (self->m13C != v) {
        self->m13C = v;
        for (int i = 1; i <= 4; i++) {
            ((FeObj1*)((FeObjQ*)((FeObjK*)self->m138)->v73(0, i))->v32("UNLOCKED", 1))->v8(i == self->m13C);
        }
    }
}

extern char lbl_8066BF80[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E63C0(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066BF80;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804E6428(FeS6* self)
{
    fn_800ECE34(self);
    fn_800C3AB4(fn_800C33D0(), 9);
    self->m134 = fn_800C8044(self->v32("USER", 1));
    self->m138 = fn_800C805C(self->v32("SPIN", 1));
    self->m13C = fn_800C8058(self->m138->v32("TROPHY", 1));
    self->m140 = fn_800C8040(self->v32("DESCRIPTION", 1));
    self->m144 = fn_800C8038(self->v32("TROPHY", 1));
    self->m148 = fn_800C8044(self->v32("HISTORY", 1));
    self->m14C = fn_800C8044(self->v32("TOTAL", 1));
}

extern "C" FE_OVERLAY int fn_804E687C(FeObj* self)
{
    fn_800C33D0();
    fn_800C3BE0();
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "BACK", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), p, self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E690C(FeWf138b* self)
{
    self->m138->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E694C(FeWf138* self)
{
    self->m138->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E6988(FeWf138b* self)
{
    self->m138->v38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E69C8(FeWf138* self)
{
    self->m138->v39();
    return 1;
}

extern "C" FE_OVERLAY void fn_804E6A04(FeS4* self)
{
    FeHolder* h = (FeHolder*)self->m13C;
    self->m154 = ((FeSub*)&h->mDC)->s11();
    fn_804E6A58(self);
}

extern char lbl_8066BCD8[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E7218(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066BCD8;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = -1;
    self->m140 = 0;
    self->m144 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804E7278(FeScrRaw* self, int chrg)
{
    self->m3C = lbl_8066BCD8;
    fn_8035686C(self, chrg);
}

extern "C" FE_OVERLAY void fn_804E72A8(FeScr_80447264* self)
{
    char buf[0x320];
    fn_800ECE34(self);
    self->m134 = fn_800C8060(((FeObjQ13*)self)->v32(lbl_805FA6F4, 1));
    self->m144 = (FePopup*)fn_800C8044(((FeObjQ13*)self)->v32(lbl_805FA6FC, 1));
    self->m140 = fn_800C8060(((FeObjQ13*)self->m144)->v32(lbl_805F4EF4, 1));
    ((FeObjQ13*)self->m140)->v16(0);
    ((FeObjQ13*)self->m144)->v8(0);
    int t = ((UiBase*)self->m144)->m2E + 3;
    ((FeObjQ13*)self->m144)->v18(t);
    ((FeObjQ13*)self->m140)->v18(t);
    ((FeObjQ13*)self->m144)->v32(lbl_805FA704, 1)->v18(t);
    ((FeObjQ13*)self->m144)->v32(lbl_805FA708, 1)->v18(t);
    fn_80403DE4(buf, fn_80090880(lbl_8061977C, 0x3FCD), 4);
    ((FeObjQ13*)fn_800C8040(((FeObjQ13*)self->m144)->v32(lbl_805FA704, 1)))->v28(buf);
    FeStQ13* s = (FeStQ13*)((char*)fn_800B555C() + 8);
    if (s->m614 != 0) {
        s->m614 = 0;
        int v = s->m618;
        if (s->m4F0 != 0) {
            fn_800E2944(lbl_8061930C->fn_8007DA28(), v);
        }
    }
}
