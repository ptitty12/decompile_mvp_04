/*
 * Front-end overlay code, .frontend_codeoverlay 0x804E1A6C-0x804E5180 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"
extern "C" void fn_800DFEAC(char* a, const char* b);
extern "C" void fn_804031BC(char* dst, const char* src);
struct Fe3W {
    int a;
    int b;
    int c;
};
extern Fe3W lbl_805FD58C[];
class FeVP30 : public UiBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual FeObj* v30(const char* a, int b);
};
class FeVS28 : public UiBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27();
    virtual void v28(char* a);
};
extern "C" const char* fn_80090880__FP11Unk80090880(void* t, int id);
class FeVQ44 : public UiBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
    virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
    virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(int a, int b, const char* c, int d);
    virtual void v44(int a, int b, const char* c, int d);
};
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" UiMsgMgr* fn_800B64BC(void* p);
inline UiMsgMgr* UiMgrB()
{
    if (lbl_8061A32C == 0)
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    return lbl_8061A32C;
}

struct Unk8007F198_D;
struct FeRetA {
    char pad0[0xA];
    unsigned short mA;
};
FeRetA* fn_8007FE04(Unk8007F198_D* g);

extern "C" FE_OVERLAY int fn_804E1A6C(FeMask* self)
{
    FeObjK* o = (FeObjK*)self->m184;
    ((FeObj1*)fn_800C805C(((FeObjQ*)o->v73(o->v60(), 2))->v33(11, 1)))->v15(0);
    ((FeObjK*)self->m184)->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1B34(FeWf184* self)
{
    self->m184->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1B70(FeMask* self)
{
    FeObjK* o = (FeObjK*)self->m184;
    ((FeObj1*)fn_800C805C(((FeObjQ*)o->v73(o->v60(), 2))->v33(11, 1)))->v15(0);
    ((FeObjK*)self->m184)->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1C38(FeWf184* self)
{
    self->m184->v53();
    return 1;
}

extern "C" FE_OVERLAY void fn_804E1C74(FeMask* self)
{
    int v = ((FeObjK*)self->m184)->v60();
    if (v >= 0) {
        fn_804E26E4(self, v);
        ((FeObj1*)self->m184)->v14(1);
    }
}

extern "C" FE_OVERLAY int fn_804E1CEC(FeMask* self)
{
    ((FeObjK*)self->m184)->v69(1);
    FeObjK* o = (FeObjK*)self->m184;
    ((FeObj1*)fn_800C805C(((FeObjQ*)o->v73(o->v60(), 2))->v33(11, 1)))->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1DB8(FeMask* self)
{
    ((FeObjK*)self->m184)->v69(1);
    FeObjK* o = (FeObjK*)self->m184;
    fn_800C805C(((FeObjQ*)o->v73(o->v60(), 2))->v33(11, 1))->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1E80(FeMask* self)
{
    ((FeObjK*)self->m184)->v69(1);
    FeObjK* o = (FeObjK*)self->m184;
    ((FeObj1*)fn_800C805C(((FeObjQ*)o->v73(o->v60(), 2))->v33(11, 1)))->v38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1F4C(FeMask* self)
{
    ((FeObjK*)self->m184)->v69(1);
    FeObjK* o = (FeObjK*)self->m184;
    fn_800C805C(((FeObjQ*)o->v73(o->v60(), 2))->v33(11, 1))->v39();
    return 1;
}

extern "C" FE_OVERLAY void fn_804E2014(FeMask* self)
{
    for (unsigned i = 0; i <= 8; i++)
        fn_8005B87C(fn_8005ACE4(), i, fn_804E2274(self, self->m18A, i));
}

extern "C" FE_OVERLAY void fn_804E2074(int a, FeMask* self)
{
    if (a == 1) {
        fn_804E2014(self);
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, "BACK", 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
    }
}

extern "C" FE_OVERLAY int fn_804E2108(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_804E2110(FeMask* self, int sel)
{
    switch (sel) {
    case 0: {
        FeObj* p = fn_800B7A94(UiGetMsgMgr(), "POPUP");
        if (self->m180 != 0) {
            fn_80131F34(p, self, (FeCb)fn_804E2074, fn_804E2108, 0x3364, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
            p->v86();
        } else {
            fn_804E2074(1, self);
        }
        break;
    }
    case 1: {
        fn_8007FE04((Unk8007F198_D*)lbl_8061930C)->mA = self->m188;
        UiMsg m;
        UiMsg* mp = &m;
        fn_8035682C(mp);
        fn_8040B830(mp->name, "BACK", 15);
        mp->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), mp, self);
        break;
    }
    }
}

extern "C" FE_OVERLAY int fn_804E2274(void* self, int v, int i)
{
    return (v >> i) & 1;
}

extern "C" FE_OVERLAY void fn_804E2280(FeMask* self, int idx)
{
    FeObj1* w = (FeObj1*)fn_800C805C(((FeObjQ*)((FeObjK*)self->m184)->v73(idx, 2))->v33(11, 1));
    w->v37(fn_804E2274(self, self->m188, idx) == 0);
}

extern "C" FE_OVERLAY void fn_804E232C(FeMask* self)
{
    fn_800ECF18(self);
    unsigned short v = fn_8007FE04((Unk8007F198_D*)lbl_8061930C)->mA;
    self->m180 = 0;
    self->m188 = v;
    self->m18A = v;
    FeObj* h = fn_800B7A94(UiMgrB(), "NAVBAR");
    fn_80124FA8(h, self);
    ((int (*)(FeObj*, int))fn_80125154)(h, 0);
    ((int (*)(FeObj*, int, int, int))fn_801251CC)(h, 0, 0x1A0A, 1);
    ((FeObj2*)self->m184)->v79(9, 0);
    ((FeObj*)self->m184)->v3();
    ((FeObj1*)self->m184)->v69(1);
    unsigned i = 0;
    do {
        char nbuf[0x20];
        char wbuf[0x200];
        unsigned n = i + 1;
        sprintf(nbuf, "%d", n);
        int off = i * 12;
        ((FeVQ44*)self->m184)->v44(i, 0, nbuf, 4);
        fn_804031BC(wbuf, "");
        char* t = (char*)lbl_805FD58C;
        char* t4 = t + 4;
        fn_800DFF0C(wbuf, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, *(int*)(t4 + off)));
        fn_800DFEAC(wbuf, " - \"");
        fn_800DFF0C(wbuf, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, *(int*)(t + off)));
        fn_800DFEAC(wbuf, "\"");
        ((FeVQ44*)self->m184)->v43(i, 1, wbuf, 5);
        fn_804E2280(self, i);
        i = n;
    } while (i <= 8);
    ((FeObj1*)self->m184)->v14(1);
}

extern "C" FE_OVERLAY void fn_804E2560(FeMask* self, FeObj* w)
{
    if (w == self->m184) {
        int sel = ((FeObjK*)w)->v60();
        if (sel >= 0) {
            char buf[0x200];
            fn_804031BC(buf, "");
            fn_800DFF0C(buf, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, 0x3799));
            fn_800DFEAC(buf, " ");
            fn_800DFF0C(buf, (char*)fn_80090880__FP11Unk80090880(lbl_8061977C, lbl_805FD58C[sel].c));
            ((FeVS28*)fn_800C8040(((FeVP30*)self)->v30("ALBUM", 1)))->v28(buf);
            ((FeObj1*)fn_800C8040(((FeVP30*)self)->v30("ALBUM", 1)))->v8(1);
        } else {
            ((FeObj1*)fn_800C8040(((FeVP30*)self)->v30("ALBUM", 1)))->v8(0);
        }
    }
}

extern "C" FE_OVERLAY void fn_804E26E4(FeMask* self, int idx)
{
    self->m188 ^= 1 << idx;
    fn_8005B87C(fn_8005ACE4(), idx, fn_804E2274(self, self->m188, idx));
    fn_804E2280(self, idx);
    fn_8001BC4C()->fn_8001BDAC(0xA3);
}

extern "C" FE_OVERLAY void fn_804E2764(FeMask* self)
{
    fn_804E1C74(self);
    self->m180 = 1;
}

extern char lbl_8066B238[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E2798(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066B238;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    return self;
}

extern "C" FE_OVERLAY int fn_804E2B14(FeS3* self)
{
    self->m138->v50();
    fn_804E3174(self, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2B68(FeW138* self)
{
    self->m138->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2BA4(FeS3* self)
{
    self->m138->v52();
    fn_804E3174(self, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2BF8(FeW138* self)
{
    self->m138->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2C34(FeS3* self)
{
    if (fn_804EAF54(((FeGameB*)lbl_80619948)->m64) > 1) {
        ((FeObjS2*)self->m13C)->v56();
        do {
            self->m144--;
            if (self->m144 < 0)
                self->m144 = 3;
        } while (FeKeyAt((char*)((FeGameB*)lbl_80619948)->m64 + 4, self->m144 * 0x4F4) == 0);
        fn_804E3174(self, 1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2CE0(FeWf13C* self)
{
    self->m13C->v57();
    return 0;
}

extern "C" FE_OVERLAY int fn_804E2D1C(FeS3* self)
{
    if (fn_804EAF54(((FeGameB*)lbl_80619948)->m64) > 1) {
        ((FeObjS2*)self->m13C)->v54();
        do {
            self->m144++;
            if (self->m144 >= 4)
                self->m144 = 0;
        } while (FeKeyAt((char*)((FeGameB*)lbl_80619948)->m64 + 4, self->m144 * 0x4F4) == 0);
        fn_804E3174(self, 1);
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2DC4(FeWf13C* self)
{
    self->m13C->v55();
    return 0;
}

extern "C" FE_OVERLAY int fn_804E2F28(FeS3* self, FeObjR* a, int b, int c)
{
    if ((FeObj*)a == self->m138) {
        a->v68(c);
        return 1;
    } else
        return 0;
}

extern "C" FE_OVERLAY void fn_804E3154(void* self, int a)
{
    fn_800ECAA4(self);
}

extern char lbl_8066C778[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E378C(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066C778;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = -1;
    return self;
}

extern "C" FE_OVERLAY void fn_804E3B08(FeS3* self)
{
    fn_800ECAA4(self);
    int v = ((FeObjK*)self->m13C)->v77();
    if (v != self->m14C) {
        self->m14C = v;
        fn_804E46B8(self);
    }
}

extern "C" FE_OVERLAY int fn_804E3B68(FeObj* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "BACK", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), p, self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3BF0(FeS3* self)
{
    fn_804E46B8(self);
    self->m13C->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3C3C(FeWf13C* self)
{
    self->m13C->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3C78(FeS3* self)
{
    fn_804E46B8(self);
    self->m13C->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3CC4(FeWf13C* self)
{
    self->m13C->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3D00(FeWf140b* self)
{
    self->m140->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3D40(FeWf140* self)
{
    self->m140->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3D7C(FeWf140b* self)
{
    self->m140->v38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3DBC(FeWf140* self)
{
    self->m140->v39();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3DF8(FeS3* self, FeObjR* a, int b, int c)
{
    if ((FeObj*)a == self->m13C) {
        a->v68(c);
        return 1;
    } else
        return 0;
}

extern "C" FE_OVERLAY void fn_804E3E4C(FeS3* self, FeObj* a)
{
    if (a == self->m140) {
        FeObj* c = fn_800C8058(a->v32("CATEGORY", 1));
        FeSub* sb = (FeSub*)((char*)c + 0xDC);
        self->m148 = sb->s11();
        fn_800C33D0();
        fn_800C3BE0();
        fn_800C3AB4(fn_800C33D0(), 9);
        self->m150 = -1;
        fn_804E3EF8(self);
        fn_804E46B8(self);
    }
}

extern "C" FE_OVERLAY int fn_804E4694(void* self, unsigned idx)
{
    if (idx > 0x67)
        return 6;
    return lbl_805F9DEC[idx];
}
