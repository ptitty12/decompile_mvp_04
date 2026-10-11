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

void fn_800F49FC(UiObj* self)
{
    fn_800EBEA8(self);
    fn_800F4A30(self);
}

extern char lbl_805BAF10[];
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
