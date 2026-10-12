/*
 * Front-end overlay code, .frontend_codeoverlay 0x80488CDC-0x8048E6A0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/fe_80471EBC.h"
extern "C" FeW* fn_800C805C(FeW* w);
extern "C" {
void fn_80489BEC(void* x, int a);
void fn_804898CC(void* x);
}
struct FeRow9B3C {
    char pad0[0x1B4];
    unsigned char m1B4[0x80];
};

static inline int FeSumRow(FeRow9B3C* r)
{
    int s = 0;
    for (int i = 0; i < 0x80; i++) {
        s += r->m1B4[(unsigned char)i];
    }
    return s;
}

typedef int (*Fn9764_t)(void*, int, int, int);
/* fn_8009764C takes its third argument as int here (the header's unsigned char adds a clrlwi). */
static inline int FeCheck9764(void* t, int k, int r, int z)
{
    return ((Fn9764_t)fn_8009764C)(t, k, r, z);
}

extern "C" FE_OVERLAY FeScrH* fn_80488CDC(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_806765D8);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeI(self, 0x138) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_80488D30(FeScrB* self)
{
    fn_800ECE34(self);
    fn_800C3AB4(fn_800C33D0(), 9);
}

extern "C" FE_OVERLAY void fn_80489324(void)
{
    fn_800C33D0();
    fn_800C3BE0();
}

extern "C" FE_OVERLAY int fn_8048977C(void* x)
{
    FeAt(x, 0x154)->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804897B8(void* x)
{
    FeAt(x, 0x154)->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804897F4(void* x)
{
    FeAt(x, 0x154)->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_80489830(void* x)
{
    FeAt(x, 0x154)->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048986C(FeW* x, int w)
{
    if (w == FeI(x, 0x154))
        x->fn_vslot41(fn_800C8070(x));
    return 1;
}

extern "C" FE_OVERLAY void fn_804898CC(void* xv)
{
    FeW* x = (FeW*)xv;
    char buf[12];
    FeNode4* n = lbl_806192E0->m4;
    FeW* w0 = ((FeW* (*)(FeW*))fn_800C8040)(x->fn_vslot29("TEAMSCORE/HOMESCORE"));
    FeW* w1 = ((FeW* (*)(FeW*))fn_800C8040)(x->fn_vslot29("TEAMSCORE/AWAYSCORE"));
    w0->fn_vslot8(1);
    w1->fn_vslot8(1);
    fn_804089B4(buf, "%d", FeSumRow((FeRow9B3C*)n->m14));
    ((FeWV*)w0)->s30(buf);
    fn_804089B4(buf, "%d", FeSumRow((FeRow9B3C*)((char*)n->m14 + 0xE64)));
    ((FeWV*)w1)->s30(buf);
}

extern "C" FE_OVERLAY int fn_80489A44(int u, int idx, int mode)
{
    char* team = (char*)lbl_806192E0->m4->m14 + idx * 0xE64;
    int i;
    int n = *(unsigned char*)(team + 0x235);
    for (i = 0; i < n; i++) {
        int off = (unsigned char)i * 8;
        char* arr = team + 0x238;
        int id = *(int*)(arr + off);
        int r = fn_800968C0(team, id, 1);
        if (FeCheck9764(team, 3, r, 0) != 0) {
            if (mode == 0) {
                return id;
            }
        } else if (FeCheck9764(team, 4, r, 0) != 0 && mode == 1) {
            return id;
        }
        if (FeCheck9764(team, 7, r, 0) != 0 && mode == 2) {
            return id;
        }
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_80489B3C(void* self, int mode)
{
    int a = FeSumRow((FeRow9B3C*)((char*)lbl_806192E0->m4->m14 + 0xE64));
    int b = FeSumRow((FeRow9B3C*)lbl_806192E0->m4->m14);
    int gt = a > b;
    if ((mode == 1 && gt) || (mode == 0 && !gt))
        return 1;
    return 0;
}

extern "C" FE_OVERLAY void fn_8048A144(FeW* x)
{
    char* t0 = (char*)lbl_806192E0->m4->m14;
    char* t1 = t0 + 0xE64;
    int a;
    int b;
    if (fn_80489B3C(x, 1) != 0) {
        a = fn_80489A44((int)x, 1, 0);
        b = fn_80489A44((int)x, 0, 1);
    } else {
        b = fn_80489A44((int)x, 0, 0);
        a = fn_80489A44((int)x, 1, 1);
    }
    FeW* wl = ((FeW* (*)(FeW*))fn_800C8044)(x->fn_vslot32("LEFTPLAYER", 1));
    FeW* wr = ((FeW* (*)(FeW*))fn_800C8044)(x->fn_vslot32("RIGHTPLAYER", 1));
    fn_800E2F24(wl, (int)t1, a);
    fn_800E2F24(wr, (int)t0, b);
    fn_800E31A8(wl, (int)t1, a);
    fn_800E31A8(wr, (int)t0, b);
    fn_80489BEC(x, 1);
    fn_80489BEC(x, 0);
    fn_804898CC(x);
    fn_80590CA8(*(int*)((char*)lbl_8061930C + 0x30));
}

/* near-miss: 2 slots differ (order of the final m4/mC stores after the vptr store) */
extern "C" FE_OVERLAY FeScrArr* fn_8048A2AC(FeScrArr* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80676330);
    self->m144 = 2;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    FeArr* s = &self->m148;
    s->m10 = lbl_8064B298;
    s->m0 = self->m160;
    s->m8 = 0xCB2;
    fn_8040074C(s->m0, 0x32C8);
    s->m4 = 0;
    s->mC = 0;
    s->m10 = lbl_8064A550;
    fn_8040074C(s->m0, s->m8 * 4);
    s->mC = 0;
    s->m10 = lbl_8064A3B8;
    s->m4 = 0;
    s->m14 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8048A378(FeScrCell* x)
{
    fn_800ECE34(x);
    x->fn_vslot32("CELL", 1);
    x->m134 = fn_800C8060();
    x->m138 = fn_800B7AB8(FeGetMgr(), "PLAYERINFOBAR");
    x->m13C = fn_800B7AB8(FeGetMgr(), "BATPITCHSTATS");
}

extern "C" FE_OVERLAY void fn_8048AB24(void* x)
{
    fn_800ED254(x);
    FeI(fn_800B555C(), 0x640) = 0;
}

extern "C" FE_OVERLAY void fn_8048AB50(void* x)
{
    if (FeWp(x, 0x134)->fn_vslot59() > 0) {
        int a = FeWp(x, 0x138)->fn_vslot87();
        int v = FePick((char*)FeVp(x, 0x148), FeWp(x, 0x134)->fn_vslot60() * 4);
        if (a != 0 && a != v) {
            char* s = (char*)FeVp(x, 0x138);
            fn_80126CF4((FeList*)s, FeI(s, 0x164), v, FeI(s, 0x134), FeI(s, 0x16C), FeI(s, 0x170), 0, FeI(s, 0x138), FeI(s, 0x13C), FeI(s, 0x148), FeI(s, 0x14C));
        }
        fn_80123858(FeVp(x, 0x13C), v, 1);
    }
}

extern "C" FE_OVERLAY int fn_8048AC44(void* x)
{
    FeAt(x, 0x134)->fn_vslot50();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AC80(void* x)
{
    FeAt(x, 0x134)->fn_vslot51();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048ACBC(void* x)
{
    FeAt(x, 0x134)->fn_vslot52();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048ACF8(void* x)
{
    FeAt(x, 0x134)->fn_vslot53();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AD34(void* x)
{
    if (FeW24(FeWp(x, 0x138)) >= 0)
        FeWp(x, 0x134)->fn_vslot56();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AD80(void* x)
{
    if (FeW24(FeWp(x, 0x138)) >= 0)
        FeWp(x, 0x134)->fn_vslot57();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048ADCC(void* x)
{
    if (FeW24(FeWp(x, 0x138)) >= 0)
        FeWp(x, 0x134)->fn_vslot54();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AE18(void* x)
{
    if (FeW24(FeWp(x, 0x138)) >= 0)
        FeWp(x, 0x134)->fn_vslot55();
    return 1;
}

extern "C" FE_OVERLAY int fn_8048AE64(FeW* x, FeW* w, int b, int c)
{
    if (w == FeWp(x, 0x134)) {
        w->fn_vslot68(c);
        x->fn_vslot67(2, fn_800C8070(x));
    }
    return 0;
}

extern "C" FE_OVERLAY FeScrH* fn_8048B248(FeScrH* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->SetVptr(lbl_80682508);
    self->m130 = 0;
    FeI(self, 0x134) = 0;
    FeF(self, 0x13C) = 0.0f;
    FeI(self, 0x140) = 0;
    FeI(self, 0x144) = 1;
    FeI(self, 0x148) = 0;
    FeI(self, 0x14C) = 0;
    FeI(self, 0x150) = 0;
    FeI(self, 0x154) = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_8048B2C0(void* x)
{
    fn_800ECE34(x);
    fn_8048E7E4(x);
    fn_8048E6A0(x);
}

extern "C" FE_OVERLAY void fn_8048B76C(void* x)
{
    FeI(fn_800B555C(), 0x18) = FeI(x, 0x134);
}

extern "C" FE_OVERLAY void fn_8048B7A0(FeW* x)
{
    if (FeW24(x) < 0) {
        fn_800C805C(x->fn_vslot32("INFOMODE", 1))->fn_vslot33(10, 1);
        FeI(x, 0x138) = ((FeSub*)((char*)fn_800C8058() + 0xDC))->s5();
    }
}

extern "C" FE_OVERLAY int fn_8048B840(void* xv)
{
    FeW* x = (FeW*)xv;
    FeW* w = ((FeW* (*)(FeW*))fn_800C8058)(fn_800C805C(x->fn_vslot32("INFOMODE", 1))->fn_vslot33(10, 1));
    int cur = FeI(x, 0x134);
    if (!(FeW24(x->fn_vslot32("INFOMODE", 1)) & 0x40000000))
        return 0;
    fn_800C805C(x->fn_vslot32("INFOMODE", 1))->fn_vslot40(1);
    do {
        cur--;
        if (cur < 0)
            cur = 5;
    } while ((fn_8048E450(x) == 0 && cur == 3) || (fn_8048E480(x) == 0 && cur == 2) || (fn_8048E4D8(x) == 0 && (unsigned)(cur - 4) <= 1));
    ((FeSub*)((char*)w + 0xDC))->s6(cur);
    FeI(x, 0x134) = cur;
    fn_8048BCE4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8048B9B8(FeW* x)
{
    FeW* p = x->fn_vslot32("INFOMODE", 1);
    ((FeWV*)fn_800C805C(p))->s41();
    return 0;
}

extern "C" FE_OVERLAY int fn_8048BA18(void* xv)
{
    FeW* x = (FeW*)xv;
    FeW* w = ((FeW* (*)(FeW*))fn_800C8058)(fn_800C805C(x->fn_vslot32("INFOMODE", 1))->fn_vslot33(10, 1));
    int cur = FeI(x, 0x134);
    if (!(FeW24(x->fn_vslot32("INFOMODE", 1)) & 0x40000000))
        return 0;
    fn_800C805C(x->fn_vslot32("INFOMODE", 1))->fn_vslot38(1);
    do {
        if (cur++ == 5)
            cur = 0;
    } while ((fn_8048E450(x) == 0 && cur == 3) || (fn_8048E480(x) == 0 && cur == 2) || (fn_8048E4D8(x) == 0 && (unsigned)(cur - 4) <= 1));
    ((FeSub*)((char*)w + 0xDC))->s6(cur);
    FeI(x, 0x134) = cur;
    fn_8048BCE4(x);
    return 1;
}

extern "C" FE_OVERLAY int fn_8048BB94(FeW* x)
{
    FeW* p = x->fn_vslot32("INFOMODE", 1);
    fn_800C805C(p)->fn_vslot39();
    return 0;
}

extern "C" FE_OVERLAY void fn_8048BBF4(void* x, int v)
{
    FeI(x, 0x140) = v;
    fn_8048BCE4(x);
}

extern "C" FE_OVERLAY void fn_8048BC18(void* x)
{
    fn_8048E8B0(x)->fn_vslot32("MOMENTUM", 1);
    fn_800C8044()->fn_vslot32("METER", 1);
    FeF(x, 0x13C) = (float)fn_800C8044()->fn_vslot32("METERBAR", 1)->m2A;
}

extern "C" FE_OVERLAY void fn_8048E3BC(FeW* x)
{
    void* t = fn_8007F7D0__FP13Unk8007F198_BUi(lbl_8061930C, 0);
    fn_8007B320__18Unk8007B2B0_Screenii(lbl_8061930C, 0, t);
    int v = fn_8059897C();
    x->fn_vslot32("OWNERRATINGVAL", 1);
    ((FeWV29*)fn_800C8040())->s29(v);
}

extern "C" FE_OVERLAY int fn_8048E450(void* x)
{
    return fn_8057CE00(0) == -1;
}

extern "C" FE_OVERLAY int fn_8048E480(void* x)
{
    int r = 0;
    if (fn_8007FE04((Unk8007F198_D*)lbl_8061930C)->m1E0 == 1)
        r = fn_8048E4D8(x) == 0;
    return r;
}

extern "C" FE_OVERLAY int fn_8048E4D8(void* x)
{
    fn_800B555C();
    return fn_800B5758();
}

extern "C" FE_OVERLAY void fn_8048E4FC(void* xv, int unused, int mode)
{
    FeW* x = (FeW*)xv;
    FeW* w = ((FeW* (*)(FeW*))fn_800C8058)(fn_800C805C(x->fn_vslot32("INFOMODE", 1))->fn_vslot33(10, 1));
    int cur = FeI(x, 0x134);
    if (FeW24(x->fn_vslot32("INFOMODE", 1)) & 0x40000000) {
        switch (mode) {
        case 0:
            do {
                cur--;
                if (cur < 0)
                    cur = 5;
            } while ((fn_8048E450(x) == 0 && cur == 3) || (fn_8048E480(x) == 0 && cur == 2) || (fn_8048E4D8(x) == 0 && (unsigned)(cur - 4) <= 1));
            break;
        case 1:
            do {
                if (cur++ == 5)
                    cur = 0;
            } while ((fn_8048E450(x) == 0 && cur == 3) || (fn_8048E480(x) == 0 && cur == 2) || (fn_8048E4D8(x) == 0 && (unsigned)(cur - 4) <= 1));
            break;
        }
        ((FeSub*)((char*)w + 0xDC))->s6(cur);
        FeI(x, 0x134) = cur;
        fn_8048BCE4(x);
    }
}
