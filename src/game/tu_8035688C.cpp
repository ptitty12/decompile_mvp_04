/*
 * Game code, .text 0x8035688C-0x8035726C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_80355A6C.h"
extern "C" char* strncpy(char*, const char*, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" UiMsgMgr* fn_800B64BC(void*);
/* Same lazy singleton as the shared view, using its real C constructor entry. */
inline UiMsgMgr* GetUiMsgMgr()
{
    if (lbl_8061A32C == 0)
        lbl_8061A32C = fn_800B64BC(operator new(0xD8, 0));
    return lbl_8061A32C;
}


void fn_8035688C(void* a, char* p) { *p = 0; }

void fn_80356898(void* p, int v) { F(int, p, 0x130) = v; }

int fn_803568A0(void* p) { return F(int, p, 0x130); }

void fn_803568A8() {}

void fn_803568AC() {}

void fn_803568B0(void* self, int c)
{
    PUT(0x10, lbl_8064A550);
    if (c & 1)
        fn_80377408(self);
}

void fn_803568E4(void* self, int c)
{
    PUT(0x6a0, lbl_8065BEF0);
    PUT(0xd8, lbl_8064A550);
    PUT(0x58, lbl_806841F8);
    if (c & 1)
        fn_80377408(self);
}

void* fn_80356930(char* self)
{
    int* p = (int*)(self + 0x88);
    for (int i = 0; i < 13; i++)
        p[i] = 1;
    return self;
}

void fn_80356950(void* self, int c)
{
    PUT(0x1c, lbl_8065BA20);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356984(char* self)
{
    F(int, self, 0x4) = 0;
    F(int, self, 0x8) = 0;
    F(int, self, 0xc) = 0;
    F(int, self, 0x10) = 0;
    F(int, self, 0x14) = 0;
    F(int, self, 0x18) = 0;
}

void fn_803569A4(void* self, int c)
{
    PUT(0x4c, lbl_8065BA00);
    if (c & 1)
        fn_80377408(self);
}

void* fn_803569D8(char* self)
{
    F(int, self, 0x0) = 0;
    F(int, self, 0x4) = 0;
    F(int, self, 0x8) = 0;
    F(int, self, 0xc) = 0;
    F(int, self, 0x10) = 0;
    F(int, self, 0x14) = 0;
    F(int, self, 0x18) = 0;
    for (int i = 0; i < 12; i++) {
        char* b = self + 0x1c;
        int o = i * 4;
        *(int*)(b + o) = 0;
    }
    return self;
}

void fn_80356A1C(void* self, int c)
{
    PUT(0x0, lbl_8065B9C0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356A50() {}

void fn_80356A54() {}

void fn_80356A58() {}

void fn_80356A5C() {}

void fn_80356A60(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356A94(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356AC8(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356AFC(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356B30(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356B64(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356B98(void* self, int c)
{
    PUT(0x18, lbl_8065B6A8);
    fn_800AB308(self, c);
}

int fn_80356BC8() { return 1; }

void fn_80356BD0(void* self, int c)
{
    PUT(0xc, lbl_8065B690);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356C04(void* self, int c)
{
    PUT(0x8, lbl_80649DB8);
    fn_80378620(self, c);
}

void fn_80356C34(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void* fn_80356C68(void* self)
{
    fn_8035710C(self);
    return self;
}

int fn_80356C98(void* p) { return F(int, p, 0x34); }

void fn_80356CA0(void* a, int b) { fn_800D3A38(a, b); }

void fn_80356CC0(void* a, int b) { fn_800C6808(a, b); }

extern "C" void fn_80356CE0(void* self, int c)
{
    PUT(0xc, lbl_80659A60);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356D14(void* self, int c)
{
    PUT(0xc, lbl_80659A60);
    if (c & 1)
        fn_80377408(self);
}

struct Unk80356D48 : UiWRaw {
    int m10;
    Unk80356D48();
};
Unk80356D48::Unk80356D48()
{
    m10 = 0;
    mC = lbl_8065D398;
}

void fn_80356D8C(void* self, int c)
{
    PUT(0xc, lbl_80659A60);
    if (c & 1)
        fn_80377408(self);
}

struct Unk80356DC0 : UiWRaw {
    int m10;
    Unk80356DC0();
};
Unk80356DC0::Unk80356DC0()
{
    m10 = 0;
    mC = lbl_8065D320;
}

void fn_80356E04(void* self, int c)
{
    PUT(0x34, lbl_806597A0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356E38(void* self, int c)
{
    PUT(0x3c, lbl_80658D08);
    fn_8035686C(self, c);
}

int fn_80356E68() { return 1; }

int fn_80356E70() { return 1; }

int fn_80356E78() { return 1; }

int fn_80356E80() { return 1; }

struct Unk80356E88 {
    int m0;
    char m4;
    char pad5[0x404 - 5];
    int m404;
    float m408;
    int m40c;
};
void fn_80356E88(Unk80356E88* s)
{
    s->m408 = lbl_805C2CC8;
    s->m0 = 0;
    s->m4 = 0;
    s->m404 = 0;
    s->m40c = 0;
}

class VT468 {
public:
    char pad0[0x468];
    virtual void s1(int c);
};
void fn_80356EAC(char* self, int c)
{
    PUT(0x5da8, lbl_80658378);
    char* a = self + 0x9c;
    if (a != 0) {
        char* p = self + 0x2cd4;
        if (a != p) {
            do {
                p -= 0x46c;
                ((VT468*)p)->s1(0);
            } while (a != p);
        }
    }
    if (c & 1)
        fn_80377408(self);
}

void fn_80356F30(void* self, int c)
{
    PUT(0xbc, lbl_80658188);
    PUT(0x3c, lbl_80658248);
    fn_803567C8(self, c);
}

void fn_80356F68(void* self, int c)
{
    PUT(0x40, lbl_80655E98);
    if (c & 1)
        fn_80377408(self);
}

void fn_80356F9C(void* a, int b) { fn_8035686C(a, b); }

void fn_80356FBC(void* self, int c)
{
    PUT(0x3c, lbl_8064C028);
    fn_8035686C(self, c);
}

void fn_80356FEC(void* self)
{
    UiMsg m;
    UiMsg* p = &m;
    fn_800ECF18(self);
    fn_8035682C(p->name);
    strncpy(p->name, lbl_805B955C, 15);
    p->name[15] = 0;
    fn_800B7B4C(GetUiMsgMgr(), &m, self);
}

int fn_80357074(float a, float b) { return a < b; }

void* fn_8035709C(void* self)
{
    PUT(0, lbl_8065D2E8);
    return self;
}

void fn_803570B0(int* self, char** pp, const void* src, int n)
{
    if (*self == 0)
        memcpy(*pp, src, n);
    *pp += n;
}

int fn_80357104() { return 1; }

void fn_8035710C(void* self)
{
    F(int, self, 0x34) = 1;
    F(int, self, 0x0) = 0;
    F(int, self, 0x8) = 0;
    F(int, self, 0xc) = 0;
    F(int, self, 0x10) = 0;
    F(int, self, 0x14) = 0;
    F(int, self, 0x18) = 0;
    F(int, self, 0x1c) = 0;
    F(int, self, 0x20) = 0;
    F(int, self, 0x24) = 0;
    F(int, self, 0x28) = 0;
    F(int, self, 0x2c) = 0;
    F(int, self, 0x30) = 0;
    F(int, self, 0x4) = 0;
    F(int, self, 0x38) = 0;
}

void fn_80357154(UiPtr0* p) { fn_800FF590(p); }

int fn_80357174(UiPtr0* p) { return fn_800FF590(p) == 0; }

int fn_8035719C() { return 1; }

int fn_803571A4() { return 1; }

int fn_803571AC() { return 0; }

int fn_803571B4(void* a, Unk6F8* s, int c) { return (s->m6F8->m14->m1CD0 == 0) == c; }

int fn_803571D8(void* a, Unk6F8* s, int c)
{
    int t = 0;
    if (s->m6F8->m14->m1CD0 != 0)
        t = 1;
    return t == c;
}

void fn_80357204(void* a, int b, int c) { fn_800FEB30(lbl_805BE138, c); }

int fn_80357230(void* a, VT3C* s) { return s->s29(0x263c); }
