/*
 * Game code, .text 0x80174318-0x80177C34 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80174318.h"

extern const Unk80174318_Fn lbl_805CB1CC;
extern int lbl_8061C668;
extern int lbl_8061C674;
extern char lbl_8065FCF0[];

void fn_80174318(Unk80174318_T* p, int state, Unk80174318_Fn f)
{
    p->m7C = state;
    p->m80 = f;
    Unk80174318_Fn g = lbl_805CB1CC;
    p->m74 = g;
}

void fn_801744AC(Unk80174318_T* p)
{
    for (int i = 0; i < 4; i++) {
        p->m1C[i].m0 = 0;
        p->m1C[i].m4 = 0;
    }
}

int fn_801747A0()
{
    return lbl_8061C668;
}

void fn_80174824(int a)
{
    fn_80402CAC(lbl_8061C674, a);
}

int fn_801757C0(void* p, int a)
{
    return a;
}

int fn_801757C8()
{
    return 0;
}

void fn_801757D0() {}

int fn_801757D4(Unk801757D4_T* p)
{
    return p->mC0;
}

void fn_801757DC() {}

void fn_801757E0() {}

void fn_801757E4()
{
    fn_8017493C(1, 0xFFFF);
}

void fn_801765F4()
{
    fn_80175810(1, 0xFFFF);
}

class Unk80176620 {
public:
    virtual ~Unk80176620();
};

Unk80176620::~Unk80176620() {}

void fn_801766F8() {}

void fn_801766FC(void* self)
{
    fn_80176C0C(self);
}

void fn_8017671C(char* self)
{
    fn_80177B40(self + 0x12C);
}

void fn_80176B70(void* self)
{
    fn_8017696C(self);
}

void fn_80176FD0() {}

int fn_80177148(int* p, int a)
{
    if (p[0x60 / 4] == a || p[0xF0 / 4] == a) {
        return 1;
    }
    return 0;
}

void fn_80177B40(void* self)
{
    fn_80177974(self);
    fn_80177A0C(self);
}

void fn_80177BCC(void* self, void* a)
{
    if (a) {
        fn_80177C34(self, a);
    }
}
