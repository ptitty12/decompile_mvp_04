/*
 * Front-end overlay code, .frontend_codeoverlay 0x804EA2E4-0x804ECDE0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

/* Q16-DECL-BEGIN */
extern "C" void fn_800B8268(FeB8144* b, float a, float c, float d, float e);
struct FeP4SlotX {
    int a;
    unsigned char b;
    int c;
};
struct FeP4RecX {
    int m0;
    int m4;
    unsigned m8;
    int mC;
    FeP4SlotX s[0x68];
    int m4F0;
};
struct FeP4TabX {
    int m0;
    FeP4RecX e[4];
};
struct FeS13b : FeObj {
    char pad40[0x1D8 - 0x40];
    int m1D8;
    int m1DC;
    int m1E0;
    int m1E4;
    int m1E8;
    int m1EC;
    int m1F0;
};
void fn_8031370C();
extern "C" void fn_80131794();
extern "C" void fn_804EB2C8(void* self);
#define FE_LO30(X) \
    X(1) X(2) X(3) X(4) X(5) X(6) X(7) X(8) X(9) X(10) X(11) X(12) X(13) X(14) X(15) X(16) X(17) \
    X(18) X(19) X(20) X(21) X(22) X(23) X(24) X(25) X(26) X(27) X(28) X(29) X(30)
class FeObjR31 : public UiBase {
public:
    FE_LO30(FE_V0) virtual const void* v31(); virtual FeObj* v32(const char* a, int b); FE_HI(FE_V0)
};
class FeD64b {
public:
    char pad0[0x64];
    virtual int s1(); virtual int s2(); virtual int s3(); virtual int s4(); virtual int s5(); virtual int s6(); virtual int s7(); virtual int s8();
    virtual int s9(int a);
};
struct FeS14c : FeObj {
    char pad40[0x148 - 0x40];
    FeObjR31* m148;
    FeObjR31* m14C;
    FeObj1* m150;
    FeObj1* m154;
    int m158;
};
extern "C" int* fn_800ED2B0(void* w, const char* name);
extern "C" void fn_800CFB38(void* w);
extern "C" void fn_804EBC7C(FeS14* self);
class FeObjZ : public UiBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual FeObj* v32(const char* a, int b); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual int v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual FeObjQ* v73(int a, int b);
    virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78();
    virtual void v79(int a, int b); virtual void v80(); virtual void v81(); virtual void v82();
    virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92();
    virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97();
    virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102();
    virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
    virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111(); virtual void v112();
    virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117();
    virtual void v118(); virtual void v119(); virtual void v120(); virtual void v121(); virtual void v122();
    virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127();
};
struct FeS16z : FeObj {
    char pad40[0x144 - 0x40];
    FeObjZ* m144;
    char pad148[0x158 - 0x148];
    int m158;
};
extern "C" int fn_804EC3E8(void* self, FeD64* o, FeObjZ* w, int* out);
class FeD64c {
public:
    char pad0[0x64];
    virtual int s1(); virtual int s2(); virtual int s3(); virtual int s4(); virtual int s5(); virtual int s6();
    virtual int s7(); virtual int s8(); virtual int s9(); virtual int s10(); virtual int s11(); virtual int s12();
    virtual int s13(); virtual int s14(); virtual int s15(); virtual int s16(); virtual int s17(); virtual int s18();
};
extern "C" void fn_800ECAA4(void* x);
extern float lbl_806221E8;
extern float lbl_806221EC;
extern float lbl_806221F0;
extern float lbl_806221F4;
extern "C" void fn_804EC734(FeS15* self);
extern char lbl_805F5A48[];
extern "C" void fn_804ECD6C();
class FeObjQ14 : public UiBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(int a); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual FeObjQ14* v29(const char* a); virtual void v30(); virtual void v31();
    virtual FeObjQ14* v32(const char* a, int b); virtual FeObjQ14* v33(int a, int b);
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68();
    virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72();
    virtual FeObjQ14* v73(int a, int b); virtual void v74(); virtual void v75(); virtual void v76();
    virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81();
    virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86();
    virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
    virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96();
    virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100();
    virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104();
    virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108();
    virtual void v109(); virtual void v110(); virtual void v111(); virtual void v112();
    virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116();
    virtual void v117(); virtual void v118(); virtual void v119(); virtual void v120();
    virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124();
    virtual void v125(); virtual void v126(); virtual void v127();
};
struct FeS15c : FeObj {
    char pad40[0x13C - 0x40];
    int m13C;
    int m140;
    int m144;
    int m148;
    int m14C;
    int m150;
    int m154;
    char pad158[0x164 - 0x158];
    int m164;
    char pad168[0x17C - 0x168];
    int m17C[25];
    int m1E0[25];
};
struct FeP204 {
    char pad0[0x204];
    int m204;
    int m208;
};
extern const char lbl_805FA80C[];
extern const char lbl_805FA81C[];
extern const char lbl_805FA82C[];
extern const char lbl_805FA83C[];
extern const char lbl_805FA84C[];
extern const char lbl_805FA85C[];
extern const char lbl_805FA86C[];
extern const char lbl_805F4F84[];
class FeObjQ34 : public UiBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(int a); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(int a);
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68();
    virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73();
    virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78();
    virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88();
    virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93();
    virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98();
    virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102();
    virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106();
    virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110();
    virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114();
    virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118();
    virtual void v119(); virtual void v120(); virtual void v121(); virtual void v122();
    virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126();
    virtual void v127();
};
class FeD64d {
public:
    char pad0[0x64];
    virtual int s1(); virtual int s2(); virtual int s3(); virtual int s4(); virtual int s5(); virtual int s6();
    virtual int s7(); virtual int s8(); virtual int s9(int a); virtual int s10();
};
extern "C" int fn_804EC980(FeS15* s, int v);
extern "C" void fn_804EC9C4(FeS15* s);
/* Q16-DECL-END */

extern char lbl_80667378[];
extern char lbl_80667390[];

extern char lbl_8066B4E0[];

extern "C" FE_OVERLAY FeScrRaw* fn_804EA2E4(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066B4E0;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804EA33C(FeS12* self)
{
    fn_800ECF18(self);
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "NAVBAR");
    fn_80124FA8(p, self);
    fn_80125100(p);
    self->m138 = fn_800C8060(self->v32("STATS", 1));
    self->m13C = fn_800C805C(self->m138->v32("SG1", 1));
    fn_804EA6D0(self);
}

extern "C" FE_OVERLAY int fn_804EA410(FeObj* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, "BACK", 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), p, self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA498(FeW138* self)
{
    self->m138->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA4D4(FeW138* self)
{
    self->m138->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA510(FeW138* self)
{
    self->m138->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA54C(FeW138* self)
{
    self->m138->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA588(FeWf138* self)
{
    self->m138->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA5C4(FeWf138* self)
{
    self->m138->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA600(FeWf138* self)
{
    self->m138->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA63C(FeWf138* self)
{
    self->m138->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA678(FeS12* self, FeObj2* a, int b, int c, int d)
{
    if ((FeObj*)a == self->m138) {
        a->v67(c, d);
        return 1;
    } else
        return 0;
}

extern "C" FE_OVERLAY void fn_804EAD3C(void* self, int* out)
{
    for (int i = 4; i > 0; i--)
        out[i - 1] = i;
}

extern "C" FE_OVERLAY FeP4TabX* fn_804EAD5C(FeP4TabX* self)
{
    self->m0 = 0;
    FeP4RecX* r = self->e;
    int i = 3;
    do {
        r->m0 = 0;
        r->m4 = 0;
        r->m8 = 0;
        r->mC = 0;
        FeP4SlotX* p = r->s;
        int j = 0x68;
        do {
            p->a = -1;
            p->b = 0;
            p->c = 0;
            p++;
        } while (--j);
        r->m4F0 = 0;
        r++;
    } while (i-- != 0);
    return self;
}

extern "C" FE_OVERLAY void fn_804EADC4(FeP4Tab* t, int idx, int v)
{
    FeSetAt((char*)t + 8, idx * 0x4F4, v);
}

extern "C" FE_OVERLAY void fn_804EAEE0(FeP4Tab* t)
{
    for (int i = 0; i < 4; i++) {
        t->e[i].m0 = 0;
        t->e[i].m8 = 0;
        t->e[i].m4F0 = 0;
    }
    t->m0 = 0;
}

extern "C" FE_OVERLAY void fn_804EAF18(FeP4Tab* t)
{
    for (int i = 0; i < 4; i++) {
        if (t->e[i].m4F0 * (t->e[i].m4 + 1) == 0)
            t->e[i].m0 = 0;
    }
}

extern "C" FE_OVERLAY int fn_804EAF54(FeP4Tab* t)
{
    int n = 0;
    for (int i = 0; i < 4; i++) {
        if (t->e[i].m0 != 0)
            n++;
    }
    return n;
}

extern "C" FE_OVERLAY int fn_804EAF88(FeP4Tab* t)
{
    for (int i = 0; i < 4; i++) {
        if (t->e[i].m0 != 0)
            return i;
    }
    return -1;
}

extern "C" FE_OVERLAY FeRaw1D8* fn_804EAFC0(FeRaw1D8* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_80135180(self, a, b, c, d, e, f, g, h, 1);
    self->m17C = lbl_80667378;
    self->m3C = lbl_80667390;
    self->m1D8 = 1;
    self->m1DC = 0;
    self->m1E0 = 0;
    self->m1E4 = 0;
    self->m1E8 = 0;
    self->m1EC = 0;
    self->m1F0 = 0;
    self->m1FC = 0;
    self->m200 = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804EB040(FeRaw1D8* self, int chrg)
{
    self->m17C = lbl_80667378;
    self->m3C = lbl_80667390;
    fn_80135200(self, chrg);
}

extern "C" FE_OVERLAY void fn_804EB078(FeS13* self)
{
    ((FeMsgMgrB*)UiGetMsgMgr())->mC0 = 0;
    self->m1E4 = 0;
    ((FeObj1*)self->v32("LOADING", 1))->v8(0);
    self->m1DC = lbl_8061A328;
    if (self->m1E4 != 0) {
        self->m1D8 = 8;
    } else {
        self->m1D8 = self->m1E4;
        fn_804EB2C8(self);
    }
    ((FeObj1*)self->v32("LEGAL", 1))->v8(0);
}

extern "C" FE_OVERLAY int fn_804EB184(FeS13* self)
{
    switch (self->m1D8) {
    case 6:
    case 7:
        fn_800B8144()->m1C = 0;
        fn_800B82D0(fn_800B8144(), -1, 1);
        self->m1E0 = 1;
        fn_8001BC4C()->fn_8001BDAC(0x9D);
        fn_804EB2C8(self);
    }
    return 0;
}

extern "C" FE_OVERLAY int fn_804EB1FC(void)
{
    return 1;
}

extern "C" FE_OVERLAY void fn_804EB204(FeObj1* self)
{
    self->v45(-1);
}

/* near-miss: retail keeps a in r3 and stores a fresh li r0,1; ours CSEs the constant with a (r31). switch / constant-in-local spellings tried (26 vs 25 insns) */
extern "C" FE_OVERLAY void fn_804EB23C(int a, FeS13* self)
{
    if (a == 0)
        fn_80313634(lbl_8061FEDC);
    else if (a == 1) {
        fn_803136A0(lbl_8061FEDC);
        self->m200 = 1;
        self->m1FC = 1;
    }
    fn_804EB2C8(self);
}

extern "C" FE_OVERLAY void fn_804EB2A4(int a, void* b)
{
    fn_804EB2C8(b);
}

extern "C" FE_OVERLAY void fn_804EB650(FeS13b* self)
{
    switch (self->m1D8) {
    case 0:
        break;
    case 1:
        if (lbl_8061A328 > self->m1E8) {
            fn_800B7AB8(UiGetMsgMgr(), "POPUP");
            fn_80131794();
        }
        break;
    case 2:
        if (lbl_8061A328 > self->m1EC) {
            ((void (*)(void*))fn_8031370C)(lbl_8061FEDC);
            fn_804EB2C8(self);
        }
        break;
    case 3:
        break;
    case 4:
        if (lbl_8061A328 > self->m1F0) {
            ((FeObj*)fn_800B7AB8(UiGetMsgMgr(), "POPUP"))->v87();
            fn_804EB2C8(self);
        }
        break;
    case 5:
    case 6:
    case 7:
        if (self->m1E0 != 0)
            fn_804EB2C8(self);
        break;
    case 8:
        if (self->m1E4 != 0 || lbl_8061A328 > self->m1DC + 0xC) {
            self->m1DC = lbl_8061A328;
            UiMsg m;
            UiMsg* mp = &m;
            fn_8035682C(mp);
            fn_8040B830(mp->name, "ADVANCE", 15);
            mp->name[15] = 0;
            fn_800B7B4C(UiGetMsgMgr(), mp, self);
        }
        break;
    }
}

extern "C" FE_OVERLAY void fn_804EB834(void)
{
    ((FeS13*)fn_800B7A94(UiGetMsgMgr(), "TITLE"))->m1E0 = 1;
}

extern char lbl_80681448[];
extern "C" FE_OVERLAY FeRaw14* fn_804EB894(FeRaw14* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648((FeScrRaw*)self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80681448;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m16C = 0;
    self->m170 = 0;
    self->m174 = 0;
    self->m178 = 0;
    self->m134 = (int)fn_800B5E68(fn_803773D8(0xB98), lbl_806221E4);
    return self;
}

extern "C" FE_OVERLAY void fn_804EB940(FeRawD* self, int chrg)
{
    self->m3C = lbl_80681448;
    if (self->m134 != 0) {
        delete self->m134;
        self->m134 = 0;
    }
    self->m134 = 0;
    fn_800E2BCC();
    fn_8035686C(self, chrg);
}

extern "C" FE_OVERLAY void fn_804EB9C0(FeS15c* self)
{
    fn_800ECF18(self);
    FeP204* g = (FeP204*)lbl_8061FEDC;
    if (g->m204 != 0 && g->m208 == 0) {
        lbl_806221E8 = 520.0f;
        lbl_806221EC = 180.0f;
        lbl_806221F0 = 680.0f;
        lbl_806221F4 = 360.0f;
    }
    int i = 0;
    int off = 0;
    self->m140 = (int)fn_800C8060(((FeObjQ14*)self)->v29(lbl_805FA80C));
    self->m144 = (int)fn_800C8060(((FeObjQ14*)self)->v29(lbl_805FA81C));
    self->m148 = (int)fn_800C8040(((FeObjQ14*)self)->v29(lbl_805FA82C));
    self->m14C = (int)fn_800C8040(((FeObjQ14*)self)->v29(lbl_805FA83C));
    self->m150 = (int)fn_800C8040(((FeObjQ14*)self)->v29(lbl_805FA84C));
    self->m154 = (int)fn_800C8040(((FeObjQ14*)self)->v29(lbl_805FA85C));
    ((FeObjQ14*)self->m140)->v8(0);
    ((FeObjQ14*)self->m144)->v8(0);
    FeObjQ14* t = (FeObjQ14*)fn_800C8060(((FeObjQ14*)self)->v32(lbl_805FA86C, 1));
    do {
        FeObjQ14* w = t->v73(i, 0);
        i++;
        FeObjQ14* e = w->v33(4, 1);
        int r = (int)fn_800C8040(e);
        char* b1 = (char*)self + 0x17C;
        char* b2 = (char*)self + 0x1E0;
        *(int*)(b1 + off) = r;
        *(int*)(b2 + off) = 0;
        off += 4;
    } while (i <= 0x18);
    self->m13C = (int)fn_800B7A94(UiGetMsgMgr(), lbl_805F4F84);
    fn_80124FA8((FeObj*)self->m13C, self);
    fn_80125100((FeObj*)self->m13C);
    self->m164 = lbl_8061A328 + 0xB4;
}

extern "C" FE_OVERLAY void fn_804EBC74(FeScrRaw* s, int v)
{
    s->m15C = v;
}

extern "C" FE_OVERLAY void fn_804EBC7C(FeS14* self)
{
    int n = self->m158 + 1;
    if (n >= self->m134->mB90) {
        self->m158 = 0;
        self->m15C = 0;
    } else {
        self->m158 = n;
        self->m15C = 0;
    }
}

extern "C" FE_OVERLAY void fn_804EBCB4(FeS16* self)
{
    ((FeObj1*)self->m140)->v8(0);
    ((FeObj1*)self->m144)->v8(0);
    FeD64* o = fn_80528400(self, self->m158);
    if (o->s2() != 0)
        fn_804EBD68(self, o);
    else
        fn_804EC68C(self, o);
}

extern "C" FE_OVERLAY void fn_804EBD68(void* p, FeD64* o)
{
    FeS14c* self = (FeS14c*)p;
    fn_800CFB38(fn_800ED2B0(self, "CATEGORYIN"));
    fn_800CFB38(fn_800ED2B0(self, "CATEGORYOUT"));
    self->m150->v28((int)self->m148->v31());
    self->m154->v28((int)self->m14C->v31());
    ((FeObj1*)(void*)self->m148)->v28(((FeD64b*)o)->s9(0));
    ((FeObj1*)(void*)self->m14C)->v28(((FeD64b*)o)->s9(0));
    fn_804EBC7C((FeS14*)self);
    FeD64* d = fn_80528400(self, self->m158);
    if (d->s2() == 0) {
        if (d->s4() != 0 || d->s3() != 0)
            fn_804EBF7C(self, d);
        else if (d->s5() != 0)
            fn_804EC294(self, d);
    }
}

extern "C" FE_OVERLAY void fn_804EC294(void* p, FeD64* o)
{
    FeS16z* self = (FeS16z*)p;
    int n = 0;
    int cnt = self->m144->v62();
    if (fn_804EC3E8(self, o, self->m144, &n) != 0) {
        FeD64* d = fn_80528400(self, self->m158);
        if (d->s5() != 0 && n < cnt) {
            ((FeObjS*)fn_800C8040(self->m144->v73(n, 0)->v33(4, 1)))->v30(" ");
            n++;
            self->m144->v79(n, 0);
            fn_804EC3E8(self, d, self->m144, &n);
        }
    }
}

extern "C" FE_OVERLAY void fn_804EC68C(FeS16* self, FeD64* o)
{
    if (o->s4() != 0 || o->s3() != 0)
        fn_804EBF7C(self, o);
    else if (o->s5() != 0)
        fn_804EC294(self, o);
}

extern "C" FE_OVERLAY void fn_804EC734(FeS15* self)
{
    int ok = 1;
    int cnt = self->m160;
    if (cnt > 0) {
        int k = cnt;
        do {
            if (((UiBase*)self->m17C[0])->m28 <= 0x31)
                fn_804EC9C4(self);
            k--;
        } while (k != 0);
    }
    if (self->m160 <= 0x18) {
        FeD64d* w = (FeD64d*)fn_80528400(self, ((FeS14*)self)->m158);
        int r = ((FeS14*)self)->m15C;
        if (w->s2() != 0) {
            FeObjQ34* o = (FeObjQ34*)fn_804EC980(self, (int)w);
            if (o == 0)
                goto done;
            o->v33(w->s10());
            o->v28(w->s9(r));
            goto done;
        }
        goto tests;
    fail:
        ok = 0;
        fn_804EBC74((FeScrRaw*)self, r);
        goto done;
    tests:
        if (w->s4() == 0) {
            if (w->s3() == 0)
                goto done;
        }
        goto test;
    body: {
            FeObjQ34* o = (FeObjQ34*)fn_804EC980(self, (int)w);
            if (o == 0)
                goto fail;
            o->v33(w->s10());
            int r0 = r;
            r++;
            o->v28(w->s9(r0));
        }
    test:
        if (r < w->s8())
            goto body;
    done:
        if (ok != 0)
            fn_804EBC7C((FeS14*)self);
    }
}

extern "C" FE_OVERLAY int fn_804EC980(FeS15* s, int v)
{
    if (s->m160 + 1 <= 0x18) {
        s->m1E0[s->m160] = v;
        int r = s->m17C[s->m160];
        s->m160++;
        return r;
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804EC9C4(FeS15* s)
{
    FeObj1* top = (FeObj1*)s->m17C[0];
    top->v10(0x1A4);
    s->m17C[0] = 0;
    for (int i = 0; i < 24; i++) {
        s->m1E0[i] = s->m1E0[i + 1];
        s->m17C[i] = s->m17C[i + 1];
    }
    s->m1E0[24] = 0;
    s->m17C[24] = (int)top;
    s->m160--;
}

/* near-miss: 99.7%; retail allocates the +0x17C pointer copy to r0 and the lha temps to r4 (ours r9/r0). Statement-order and declaration variants tried */
extern "C" FE_OVERLAY void fn_804ECA60(FeS15* self)
{
    fn_800ECAA4(self);
    fn_800B8144()->m1C = (FeVf)fn_804ECD6C;
    self->m178 = 1;
    fn_800B82D0(fn_800B8144(), 8, 0);
    fn_800B8268(fn_800B8144(), lbl_806221E8, lbl_806221EC, lbl_806221F0, lbl_806221F4);
    int* p = fn_800ED2B0(self, lbl_805F5A48);
    if (self->m16C == 0 && *p == 0 && (self->m24 & 0x40000000)) {
        fn_80125180(((FeS12*)self)->m13C, 3, 0x39F9);
        fn_80125180(((FeS12*)self)->m13C, 0, 0x39F8);
        if (!(lbl_8061A328 < self->m164)) {
            self->m164 = lbl_8061A328 + 0xB4;
            if (self->m168 != 0) {
                int n = 0;
                fn_804EC734(self);
                if (self->m160 > 0) {
                    FeObj1* o = (FeObj1*)self->m17C[0];
                    int* p0 = self->m17C;
                    int h = o->m2C;
                    int base = o->m28 - 3;
                    if (base >= 0) {
                        int k = 0;
                        int* pp = p0;
                        int lim;
                        do {
                            n++;
                            FeD64c* w = (FeD64c*)self->m1E0[k];
                            k++;
                            lim = base + h + w->s18();
                            o->v10(base);
                            if (n >= self->m160)
                                break;
                            o = (FeObj1*)*++pp;
                            h = o->m2C;
                            base = o->m28 - 3;
                        } while (base >= lim);
                    }
                }
            } else
                fn_804EBCB4((FeS16*)self);
        }
    }
}

extern "C" FE_OVERLAY int fn_804ECC0C(FeObj* self)
{
    fn_800B8144()->m1C = 0;
    fn_800B82D0(fn_800B8144(), -1, 1);
    fn_800B82AC(fn_800B8144());
    fn_800B7ADC(UiGetMsgMgr(), self);
    return 1;
}

extern "C" FE_OVERLAY int fn_804ECC8C(FeS15* self)
{
    if (self->m178 != 0) {
        fn_804EBCB4((FeS16*)self);
        fn_8001BC4C()->fn_8001BDAC(0xA3);
        self->m164 = lbl_8061A328 + 0xB4;
    }
    return 1;
}

extern "C" FE_OVERLAY int fn_804ECCE4(void)
{
    return 1;
}

extern "C" FE_OVERLAY int fn_804ECCEC(FeS15* self)
{
    if (self->m178 != 0) {
        int t;
        if (self->m16C != 0) {
            fn_80125180((FeObj*)((FeS12*)self)->m13C, 3, 0x39F9);
            t = 0;
        } else {
            fn_80125180((FeObj*)((FeS12*)self)->m13C, 3, 0x389E);
            t = 1;
        }
        self->m16C = t;
        fn_8001BC4C()->fn_8001BDAC(0xA3);
    }
    return 1;
}

extern "C" FE_OVERLAY void fn_804ECD6C()
{
    fn_800B82D0(fn_800B8144(), -1, 1);
    fn_800B8144()->m1C = (FeVf)fn_804ECD6C;
    fn_800B82D0(fn_800B8144(), 8, 0);
    fn_800B8268(fn_800B8144(), 260.0f, 115.0f, 340.0f, 215.0f);
}
