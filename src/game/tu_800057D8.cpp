/*
 * Translation unit at 0x800057D8 (original file name unknown; placeholder).
 * A real TU: it ends with its static-initializer wrapper (docs/UNITS.md
 * ctor anchors). 37 functions.
 *
 * .text 0x800057D8-0x80008540, .rodata 0x805A344C-0x805A3A54, .data 0x8060F720-0x80615848, .bss 0x806869B0-0x80686A4C.
 * Not split (declare extern if used): small-data (.sdata/.sbss) objects and
 * any second, non-contiguous range of a section.
 */
#include "game/tu_800057D8.h"

extern "C" {
void* fn_8040B320(void* dst, int c, unsigned n);       /* memset */
char* fn_8040B61C(char* dst, const char* src);         /* strcpy */
int fn_8040B6A0(const char* s);                        /* strlen */
char* fn_8040B830(char* dst, const char* src, unsigned n); /* strncpy */
char* fn_8040B948(const char* hay, const char* needle); /* strstr */
char* fn_8040B4D8(const char* s, int c);               /* strchr */
int fn_8040B574(const char* a, const char* b);         /* strcmp */
int fn_804089B4(char* dst, const char* fmt, ...);      /* sprintf */
void fn_80402FCC(char* dst, const char* src);
Unk80170034_Entry* fn_80170034(Unk80170034_Info* info, int idx);
void fn_8017008C(Unk80170034_Info* info, const char* name);
void fn_80436204(int a, int b, int c);
int fn_80400DAC();
int fn_80400E84();
void fn_803FFFA8(int a);
int fn_8017037C(Unk80170034_Info* info);
}
extern int lbl_8061C668;

struct Unk8060F740 {
    char pad0[0x28];
    float m28;
};
extern Unk8060F740 lbl_8060F740;
extern Unk8060F740* lbl_806EF98C;
extern int lbl_8060F720;
extern const char* lbl_80615840;
extern const char* lbl_80615844;
extern const char lbl_805A3800[];
extern char* lbl_806EEA1C;

extern "C" Unk8060F740* fn_803EB2EC(Unk8060F740*);

extern "C" Unk8060F740* fn_800057D8()
{
    return &lbl_8060F740;
}

extern "C" Unk8060F740* fn_800057E4()
{
    return lbl_806EF98C;
}

extern "C" void fn_800057F0()
{
    Unk8060F740* p = fn_803EB2EC(&lbl_8060F740);
    lbl_806EF98C = p;
    float f = 0.0f;
    p->m28 = f;
    lbl_8060F720 = 1;
}

extern "C" Unk800058BC* fn_80005840(int mode)
{
    return new (0x100) Unk800058BC(mode);
}

extern "C" void fn_8000587C(Unk800058BC* p)
{
    delete p;
}

Unk800058BC::Unk800058BC(int mode)
    : Unk80170518(mode), m14C(0), m150(0), m154(0), m1FC(0), m200(0), m244(0), m248(0), m24C(0), m250(0)
{
    m140.m0 = mode;
    m144 = 0;
    fn_8040B320(&m158, 0, 0x30);
    m158.m0 = 1;
    m158.m4 = 0;
    m158.m28 = 0;
    fn_8040B320(&m188, 0, 8);
    m188.m4 = 0;
    m188.m0 = 0;
    fn_8040B61C(m190, lbl_805A3800);
    fn_8040B61C(m1AB, lbl_80615840);
    m110.mC = m190;
    m110.m10 = fn_8040B6A0(m190);
    m110.m14 = m1AB;
    m110.m18 = fn_8040B6A0(m1AB);
    m110.m1C = &m158;
    m110.m20 = &m188;
    m110.m2C = 1;
    m34 = -1;
}

Unk800058BC::~Unk800058BC()
{
}

void Unk800058BC::fn_80005A50()
{
    fn_80436204(1, 1, 1);
}

void Unk800058BC::fn_80005A7C(Unk80170034_Info* info)
{
    fn_80005AB0(info);
}

void Unk800058BC::fn_80005AB0(Unk80170034_Info* info)
{
    char a[16];
    char b[16];
    char c[32];
    fn_80402FCC(a, info->m78);
    fn_80402FCC(b, info->m8E);
    fn_804089B4(c, "%s_%s%s", b, a, lbl_80615844);
    char* p = fn_8040B4D8(b, 0x20);
    if (p) {
        *p = 0;
    }
    fn_8040B61C(m190, lbl_805A3800);
    fn_804089B4(m1AB, lbl_80615840, b, a);
    fn_8017008C(info, c);
}

int Unk800058BC::fn_80005B74(int a)
{
    return a <= 0;
}

void Unk800058BC::fn_80005B88(Unk80170034_Info* info)
{
    Unk80005B88_Obj* o = m64->vslot26();
    m110.m0 = lbl_806EEA1C;
    Unk80170034_Entry* e0 = fn_80170034(info, 0);
    m110.m4 = e0->m4 + fn_80170034(info, 1)->m4;
    m158.m4 = fn_80170034(info, 2)->m0 + 0x40;
    m188.m4 = fn_80170034(info, 3)->m0 + 0x40;
    o->vslot1();
    o->vslot3(&m140, &m110);
    o->vslot2();
}

void Unk800058BC::fn_80005C8C()
{
    if (m144) {
        m30 = 0;
        (this->*m144)();
        if (m30 != 8) {
            m30 = m144 ? 2 : 0;
        }
    } else {
        m30 = 0;
    }
}

void Unk800058BC::fn_80005D40()
{
    fn_8040B830(mD8, m38->mE4, 0x1B);
    m44 = fn_80170034(m38, 0)->m0;
    Unk80170034_Entry* e = fn_80170034(m38, 0);
    m48 = e->m4 + fn_80170034(m38, 1)->m4;
    m200 = 1;
    m158.m4 = fn_80170034(m38, 2)->m0 + 0x40;
    m188.m4 = fn_80170034(m38, 3)->m0 + 0x40;
    m110.m10 = fn_8040B6A0(m190);
    m110.m18 = fn_8040B6A0(m1AB);
    m110.m8 = m68;
    m110.m24 = m38->m8E;
    m110.m28 = m38->m78;
    m110.m0 = mD8;
    m110.m4 = m48;
}

void Unk800058BC::fn_80005E38()
{
    fn_80005AB0(m38);
    fn_8040B61C(mD8, m38->mE4);
}

int Unk800058BC::fn_80005E8C()
{
    int done = 0;
    m64->vslot10(&m140);
    mC0 = 0;
    do {
        Unk800074BC_Msg* msg = m64->vslot21(10000);
        if (msg) {
            if (msg->m0 == 8) {
                done = 1;
                int v = 0;
                if (msg->m4 == 0 || msg->m4 == 3) {
                    v = 1;
                }
                mC0 = v;
            }
        } else {
            fn_803FFFA8(1);
        }
    } while (!done);
    return mC0;
}

void Unk800058BC::fn_80005F4C(int a, int b, int clear)
{
    Unk80005B88_Obj* o = m64->vslot26();
    if (clear) {
        for (int i = 0; i < 5; i++) {
            m204[i].m0 = 0;
            m204[i].m4 = 0;
        }
        m154 = 0;
        m240 = 0;
    }
    o->vslot1();
    m158.m4 = fn_80170034(m38, 2)->m0 + 0x40;
    m188.m4 = fn_80170034(m38, 3)->m0 + 0x40;
    m110.m4 = b;
    m110.m0 = lbl_806EEA1C;
    o->vslot3(&m140, &m110);
    m240 += o->vslot2();
    m204[m154].m8 = o->vslot2();
    m204[m154++].m0 = a;
}

void Unk800058BC::fn_800060B4()
{
    Unk800060B4_Req req;
    // PERM_BEGIN
    m244 = 1;
    req.m48 = 0;
    req.m4 = 0;
    req.m38 = 0;
    req.m34 = m140;
    req.m8 = m68;
    m24C = 0;
    req.m2C = 1;
    req.m30 = m240;
    req.m40 = m154;
    req.m0 = lbl_806EEA1C;
    // PERM_END
    fn_80400DAC();
    m64->vslot3(&req);
    m144 = &Unk800058BC::fn_800061C8;
}

void Unk800058BC::fn_800061C8()
{
    if (m144) {
        int ms = fn_80400DAC() * 1000 / fn_80400E84();
        Unk800074BC_Msg* msg = m64->vslot21(ms);
        if (msg) {
            if (m1FC) {
                delete m1FC;
                m1FC = 0;
            }
            switch (msg->m0) {
            case 0x18:
                fn_800074BC(msg);
                break;
            case 0x17: {
                char a[0x20];
                char b[0x10];
                int found = 0;
                fn_8040B61C(a, msg->m40);
                char* p = fn_8040B948(a, "_");
                if (p) {
                    *p = 0;
                    for (int i = 0; i < m154; i++) {
                        fn_80402FCC(b, (const char*)m204[i].m0);
                        if (fn_8040B574(a, b) == 0) {
                            if (m204[i].m4 == 0) {
                                m204[i].m4 = 1;
                                if (fn_8040B574(b, "Options") == 0) {
                                    m24C = 1;
                                }
                            }
                            break;
                        }
                    }
                }
                if (found) {
                    m64->vslot22(10, 0);
                } else {
                    m64->vslot22(11, 0);
                }
                break;
            }
            case 1: {
                mA0 = 0;
                m144 = 0;
                for (int i = 0; i < 4; i++) {
                    mA4[i] = 0;
                }
                m244 = 1;
                int code = msg->m4;
                if (code == 0x18 || code == 3) {
                    fn_800060B4();
                } else if (code == 0x1A) {
                    fn_80005A50();
                } else if (m248) {
                    if (m24C) {
                        fn_80006B60();
                    } else {
                        mC4 = 0;
                    }
                } else {
                    mC4 = code == 0;
                }
                break;
            }
            }
        } else {
            fn_803FFFA8(1);
        }
    }
}
