/*
 * Game code, .text 0x800F1AEC-0x800F56B4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"


void fn_800F1AEC(UiObj* self)
{
    self->v80(1);
    fn_800F1970(self);
}

extern char lbl_8061B340[];
extern char lbl_8064BA88[];
UiScrRaw* fn_800F1B38(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 0, 0x3364, 16, lbl_8061B340);
    self->m3C = lbl_8064BA88;
    self->m174 = 0;
    self->m178 = 0;
    return self;
}

void fn_800F1D98()
{
    lbl_806192E0->m4->m10->m1C = 9;
    fn_8006C698(lbl_806192E0->m4);
}

int fn_800F1DD4(int a, int b, int c)
{
    if (b >= a)
        return b - a;
    return b + c - a;
}

struct UiColor4 {
    float m0;
    float m4;
    float m8;
    float mC;
};
class UiX35v : public UiBase {
public:
  virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
  virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
  virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
  virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
  virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
  virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
  virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(UiColor4 c);
};
class UiX35 : public UiX35v {
public:
    char pad40[0x8C - 0x40];
    UiColor4 m8C;
    UiColor4 m9C;
};
UiColor4* fn_8014DBA0(UiColor4* out, int r, int g, int b, int a);
void fn_800F2068(int unused, UiX35* self, int on)
{
    UiColor4 c;
    if (on)
        fn_8014DBA0(&c, 0xE0, 0xE0, 0xE0, 0xFF);
    else
        fn_8014DBA0(&c, 0xDA, 0x1E, 0x22, 0xFF);
    self->v35(c);
    self->m8C = c;
    self->m9C = c;
}

struct UiP16C {
    char pad0[0x16C];
    int m16C;
};
struct UiV21D4 : UiObj {
    char pad40[0x194 - 0x40];
    int m194;
    char pad198[0x1B0 - 0x198];
    int a1B0[2];
    char pad1B8[0x1C4 - 0x1B8];
    int m1C4;
};
int fn_800968C0(UiP16C* p, int a, int b);
int fn_8009692C(UiP16C* p, int a);
struct UiV2298 : UiObj {
    char pad40[0x194 - 0x40];
    int m194;
    int m198;
    char pad19C[0x1B0 - 0x19C];
    int m1B0;
    int m1B4;
};
int fn_800F2148(UiV2298* self);
int fn_800F21D4(UiV21D4* self, int idx, UiP16C* p)
{
    unsigned char x = fn_8009692C(p, fn_800968C0(p, self->m1C4, 1));
    unsigned y = fn_800F1DD4(x, (self->a1B0[idx] + 6) % p->m16C, p->m16C);
    switch (self->m194) {
    case 1:
        if (idx == 0)
            return x == 0;
        return y <= 3;
    case 2:
        if (idx == 0)
            return y <= 3;
        return 1;
    default:
        return 1;
    }
}


extern int lbl_805C3D24[];
int fn_800F1DF4(UiV2298* self, int a, int b, int c, int d);
int fn_800F2298(UiV2298* self, int a, int b, int c)
{
    int ok = 1;
    for (int i = 0; i <= 3; i++) {
        char* base = (char*)self + 0x1B8;
        int o = lbl_805C3D24[i] * 4;
        ok = (ok != 0) & (fn_800F1DF4(self, a, b, *(int*)(base + o), i) != 0);
    }
    ok = (ok & (fn_800F2148(self) ^ 1)) != 0;
    return (ok != 0) & (fn_800F21D4((UiV21D4*)self, a == 0, (UiP16C*)c) != 0);
}

void fn_800F26A0(UiScr168* self, int a)
{
    UiRing* r = (UiRing*)&self->m168;
    if (self->entries[self->m168[r->mC]].m0 == a)
        return;
    while (1) {
        r->mC = (r->mC + 1) % r->m4;
        if (self->entries[self->m168[r->mC]].m0 == a)
            break;
    }
}

void fn_800F2878(UiObj* self, UiObj* other)
{
    fn_800F289C(other);
}

void fn_800F289C(UiObj* self)
{
    fn_804D2D50(self)->v16(0);
    fn_804D2D50(self)->v8(0);
    self->v16(1);
    fn_804D2CE0(self)->v16(1);
}

void fn_800F2948(UiObj* self, int a)
{
    if (fn_804D2D50(self) != 0)
        fn_800F289C(self);
    self->v16(0);
    fn_804D2CE0(self)->v16(0);
    fn_80131F34(fn_804D2D50(self), self, fn_800F2878, 0, a, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    UiV_2F0i* t = fn_804D2D50(self);
    t->m2F0 = fn_800B555C()->m570;
    fn_800C80C0(fn_804D2D50(self), fn_800B555C()->m570);
    fn_804D2D50(self)->v86();
}

void fn_800F2C84(UiV_174i_178i* self, int a)
{
    char* e = lbl_806192E0->m4->m14;
    fn_80096830(e + 0xE64, self->m178);
    fn_80096830(e, self->m174);
    fn_804D3328(self, a);
}

/* near-miss: the else store to m1A8 is index-folded here (retail keeps addi/stwx with the call result as index); callee-saved regs b/g swapped */
extern int lbl_8061930C;
extern int lbl_805C2E5C[];
void fn_800F3100(int unused, UiV_194i_1A8i_1ACi_1B8i_1BCi* self)
{
    int lvl = self->m194;
    Ui806192E0_B* b = lbl_806192E0->m4;
    int g = lbl_8061930C;
    if (lvl > 10)
        lvl = 10;
    int r = fn_8007E48C(g, ((Ui1CD0*)b->m14)->m198, self->m1B8);
    if (r != 0)
        self->m1A8 = lbl_805C2E5C[lvl - 1] + fn_8040ABA0() % 10;
    else
        (&self->m1A8)[r] = 100;
    if (fn_8007E48C(g, ((Ui1CD0*)b->m14)->mFFC, self->m1BC) != 0)
        self->m1AC = lbl_805C2E5C[lvl - 1] + fn_8040ABA0() % 10;
    else
        self->m1AC = 100;
}

extern char lbl_806549D8[];
UiScrRaw* fn_800F3220(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_806549D8;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

extern char lbl_806549D8[];
void fn_800F3274(UiScrRaw* self)
{
    self->m3C = lbl_806549D8;
    fn_8035686C(self);
}

int fn_800F362C(UiV_134* self)
{
    self->m134->v50();
    return 1;
}

int fn_800F3668(UiV_134* self)
{
    self->m134->v51();
    return 1;
}

int fn_800F36A4(UiV_134* self)
{
    self->m134->v52();
    return 1;
}

int fn_800F36E0(UiV_134* self)
{
    self->m134->v53();
    return 1;
}

int fn_800F371C(UiObj* self)
{
    self->v67(1, 0);
    return 1;
}

class UiX79v : public UiBase {
public:
  virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
  virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
  virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
  virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
  virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
  virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
  virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
  virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
  virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
  virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
  virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
  virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
  virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
  virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70();
  virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
  virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(UiMsg* m);
};
class UiX79 : public UiX79v {
public:
    char pad40[0x138 - 0x40];
    int m138;
};
extern char lbl_805BE414[];
extern char lbl_805BE138[];
void fn_800F375C(UiX79* self, int kind, int a)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    switch (kind) {
    case 0:
        if (fn_800B57EC(fn_800B555C()) != 0) {
            fn_8040B830(p->name, lbl_805BE414, 15);
            p->name[15] = 0;
        } else {
            fn_8040B830(p->name, lbl_805BE138, 15);
            p->name[15] = 0;
        }
        fn_800B7B4C(UiGetMsgMgr(), &m, (UiObj*)self);
        break;
    case 1:
        if (self->m138 == 0) {
            fn_800B555C()->m570 = a;
            self->v79(p);
            fn_800B7B4C(UiGetMsgMgr(), p, (UiObj*)self);
        }
        break;
    }
}

void fn_800F388C(UiV_134* self, char* out)
{
    UiObj* o = self->m134->v70();
    fn_8040B830(out, o->v33(5, 1)->name, 16);
}

extern char lbl_80654730[];
UiScrRaw* fn_800F3900(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80654730;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    return self;
}

extern char lbl_80654730[];
void fn_800F3958(UiScrRaw* self)
{
    self->m3C = lbl_80654730;
    fn_8035686C(self);
}

extern char lbl_805B955C[];
void fn_800F3D74(UiObj* self, int a)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    if (a == 0) {
        fn_8040B830(p->name, lbl_805B955C, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
    }
}

/* near-miss: store order matches; the last three vtable/pointer values use r11/r9 where retail uses r10/r11 */
extern char lbl_80654130[];
extern char lbl_8064A550[];
extern char lbl_806800B0[];
extern char lbl_80655E98[];
extern char lbl_80655BA8[];
void fn_800F3FCC(UiScr3FCC* self, int a)
{
    self->m3C = lbl_80654130;
    self->m7F0 = lbl_8064A550;
    fn_804D3DD0(self->m678, 2);
    fn_804D61F4(self->m4F0, 2);
    fn_80360F48(self->m37C, 2);
    UiSub1CC* p = &self->m1CC;
    p->m3C = lbl_806800B0;
    fn_800EC5F4(p, 2);
    self->m1C8 = lbl_80655E98;
    self->m184 = lbl_80655E98;
    self->m3C = lbl_80655BA8;
    fn_8035686C(self, a);
}

void fn_800F4078(Ui4078* self)
{
    fn_8055AC44((char*)self + 0x898, 0);
    fn_800EB56C(self);
    if (fn_800B555C()->m4 & 1) {
        fn_804D292C((Ui144*)((char*)self + 0x144), 0);
        self->m138->m198 = 0;
        fn_80086EC0(lbl_806192E0->m4->m10, 1, 0);
    }
    Ui144* p = (Ui144*)((char*)self + 0x144);
    fn_804D292C(p, p->m38);
    if (fn_800B555C()->m0 == 0x42) {
        fn_8012E1C4(self->m138, 1, 0x245F);
        return;
    }
    if (fn_800B555C()->m0 == 0x43 || fn_800B555C()->m0 == 0x44)
        fn_8012E1C4(self->m138, 1, 0x245E);
}

struct UiS;
void fn_800EB704(UiS* self);
void fn_800DD204(UiS* a, UiS* b);
void* fn_800B8144();
void fn_800B83F8(void* self, int a, int b);
void fn_80125128(UiObj* o, int a);
void fn_80125154(UiObj* o, int a);
void fn_804D28B4(void* p);
extern char lbl_805BAFF0[];
extern char lbl_805BE43C[];
class UiX94v : public UiBase {
public:
  virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
  virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
  virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
  virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
  virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
  virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
  virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
  virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
  virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
  virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
  virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
  virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
  virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
  virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70();
  virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
  virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80();
  virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85();
  virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90();
  virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(int a);
};
extern char lbl_805BA6D0[];
/* near-miss: three arg-setup pairs (li r4 before mr r3) are ordered the other way round */
void fn_800F4158(UiObj* self)
{
    fn_800EB704((UiS*)self);
    fn_800B83F8(fn_800B8144(), 1, 1);
    UiObj* w = (UiObj*)fn_800B7AB8(UiGetMsgMgr(), lbl_805BA6D0);
    fn_80124FA8(w, self);
    fn_80125128(w, -1);
    fn_80125154(w, -2);
    fn_801251CC(w, 3, 0x3BEE, -4);
    UiObj* o = fn_800C8044(self->v32((int)lbl_805BAFF0, 1));
    UiObj* p = fn_800C8040(o->v32((int)lbl_805BAFF0, 1));
    UiObj* q = fn_800C8038(o->v32((int)lbl_805BE43C, 1));
    if (fn_800B555C()->m0 == 0x42)
        p->v29(0x110);
    else if (fn_800B555C()->m0 == 0x43)
        p->v29(0x111);
    else if (fn_800B555C()->m0 == 0x44)
        p->v29(0x119);
    if (fn_800B57EC(fn_800B555C()) == 0)
        fn_801251CC(w, 2, 0x3CA5, 0);
    fn_800DD204((UiS*)p, (UiS*)q);
    ((UiX94v*)self)->v94(1);
    fn_804D28B4((char*)self + 0x144);
}

void fn_800F49FC(UiObj* self)
{
    fn_800EBEA8(self);
    fn_800F4A30(self);
}

extern char lbl_805BAF10[];
class UiX84v : public UiBase {
public:
  virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
  virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
  virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
  virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
  virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
  virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
  virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
  virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
  virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
  virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
  virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
  virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
  virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
  virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70();
  virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
  virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80();
  virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(int a, int b);
};
class UiScrH : public UiX84v {
public:
    char pad40[0x134 - 0x40];
    int m134;
    int m138;
    int m13C;
    char pad140[0x148 - 0x140];
    int m148;
    int m14C;
    char pad150[0x164 - 0x150];
    int m164;
    char pad168[0x16C - 0x168];
    int m16C;
    int m170;
};
struct UiSub144 {
    char pad0[0x34];
    int m34;
    int m38;
};
class UiS4A30 : public UiObj {
public:
    char pad40[0x138 - 0x40];
    UiScrH* m138;
    char pad13C[0x144 - 0x13C];
    UiSub144 m144;
    char pad180[0x7E0 - 0x180];
    int* m7E0;
};
inline int UiIntAtF(char* b, int i)
{
    int o = i * 4;
    return *(int*)(b + o);
}
int fn_804D24B0(UiSub144* s);
int fn_80126CF4(UiScrH* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern char lbl_805BE454[];
/* near-miss: arg setup of the first fn_80126CF4 call (mr r3 / li r9) is ordered the other way round */
extern "C" void fn_800F4A30(UiS4A30* self)
{
    UiSub144* s = &self->m144;
    if (fn_804D24B0(s) == 0) {
        int p = s->m34 != -1;
        if (!p && s->m38 != -1) {
            UiObj* o = (UiObj*)fn_800C8060(self->v32((int)lbl_805BE454, 1));
            UiScrH* h = self->m138;
            fn_80126CF4(h, h->m164, UiIntAtF((char*)self->m7E0, o->v60() - 1), h->m134, h->m16C, h->m170, 0, h->m138, h->m13C, h->m148, h->m14C);
            self->m138->v84(1, 0);
            return;
        }
    }
    fn_80126CF4(self->m138, self->m138->m164, 0, self->m138->m134, self->m138->m16C, self->m138->m170, 0, self->m138->m138, self->m138->m13C, self->m138->m148, self->m138->m14C);
}

void fn_800F4EA8(UiObj* self)
{
    UiObj* o = fn_800B7AB8(UiGetMsgMgr(), lbl_805BAF10);
    if (o != 0) {
        Ui806192E0_C* c = lbl_806192E0->m4->m10;
        if (fn_800B555C()->m0 == 0x43 || fn_800B555C()->m0 == 0x44) {
            fn_80086EC0(c, 0, o->v88(1));
            fn_80086EC0(c, 1, -1);
        } else {
            fn_80086EC0(c, 1, o->v88(1));
            fn_80086EC0(c, 0, -1);
        }
        self->v89();
    }
}

void fn_800F4FD0(UiObj* self)
{
    fn_800EB7D4(self);
    fn_800C33D0();
    fn_800C3BE0();
}

extern char lbl_805BA6D8[];
void fn_800F4FF8(UiObj* self)
{
    UiObj* o = fn_800B7AB8(UiGetMsgMgr(), lbl_805BA6D8);
    fn_80131F34(o, self, fn_800F50B8, 0, 0x5B9A, 2, -1, 1, 0x3E9, 0x3E8, 0, 0, 0, 0);
    o->v86();
}

void fn_800F50B8(int a, UiV_17Ci* b)
{
    if (a == 1)
        fn_800EB968(b, -1, b->m17C);
}

extern char lbl_8061B380[];
extern char lbl_80653B90[];
UiScrRaw* fn_800F50EC(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 0, 0x3364, 7, lbl_8061B380);
    self->m3C = lbl_80653B90;
    return self;
}

void fn_800F5154(UiV_13Ci* self)
{
    fn_804D3164(self);
    fn_804D2DC0(self, 0x10F);
    self->m13C = 1;
    self->v87();
    fn_804D3CA8(self, 1);
    if (fn_800B57EC(fn_800B555C()) != 0) {
        UiX* o = fn_804D2ED0(self, 0x4B);
        o->x5(fn_800B555C()->m664);
        fn_8051F42C(o)->v16(0);
    }
}

void fn_800F5224()
{
    fn_8006C698(lbl_806192E0->m4);
}

/* near-miss: right shape but the strncpy tail is not cross-jumped and self lands in r29 (retail r30); v40 takes no argument here (UiObjC) */
extern char lbl_805BE4A0[];
extern char lbl_805B955C[];
int fn_800F5250(UiObjC* self)
{
    if (fn_804D3B18(self) == 1) {
        fn_804D2F9C(self);
        if (fn_800B555C()->m4 & 0x200)
            fn_804D304C(self);
        self->v40();
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        if (fn_800B57EC(fn_800B555C()) == 1)
            fn_8040B830(p->name, lbl_805BE4A0, 15);
        else
            fn_8040B830(p->name, lbl_805B955C, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, (UiObj*)self);
        return 1;
    }
    return 0;
}

void fn_800F5344(UiObj* self)
{
    fn_800ECAA4(self);
    self->v87();
}

extern char lbl_8061B39C[];
extern char lbl_806538C0[];
UiScrRaw* fn_800F5388(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_804D2AC0(self, a, b, c, d, e, f, g, h, 0, 0x3364, 7, lbl_8061B39C);
    self->m3C = lbl_806538C0;
    return self;
}

void fn_800F53F0(UiV_13Ci* self)
{
    fn_804D3164(self);
    fn_804D2DC0(self, 0x10F);
    self->m13C = 1;
    self->v87();
    fn_804D3CA8(self, 1);
}

void fn_800F5454()
{
    fn_8006C698(lbl_806192E0->m4);
}

/* near-miss: copy of fn_800F5250 (see there) */
extern char lbl_805BE4A0[];
extern char lbl_805B955C[];
int fn_800F5480(UiObjC* self)
{
    if (fn_804D3B18(self) == 1) {
        fn_804D2F9C(self);
        if (fn_800B555C()->m4 & 0x200)
            fn_804D304C(self);
        self->v40();
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        if (fn_800B57EC(fn_800B555C()) == 1)
            fn_8040B830(p->name, lbl_805BE4A0, 15);
        else
            fn_8040B830(p->name, lbl_805B955C, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, (UiObj*)self);
        return 1;
    }
    return 0;
}

void fn_800F5574(UiObj* self)
{
    fn_800ECAA4(self);
    self->v87();
}

extern char lbl_80651B88[];
UiScrRaw* fn_800F55B8(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80651B88;
    self->m130 = 0;
    return self;
}

void fn_800F5604(UiObj* self)
{
    if (fn_800EC8B8(self) != 0)
        fn_800ECAA4(self);
}

extern char lbl_80650E20[];
UiScr5640* fn_800F5640(UiScr5640* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_80650E20;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    for (int i = 0; i < 5; i++)
        self->m13C[i] = 5;
    return self;
}
