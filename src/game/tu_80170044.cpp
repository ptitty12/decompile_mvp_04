/*
 * Game code, .text 0x80170044-0x80171A10 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80170044.h"

extern int lbl_8068B87C;
extern int lbl_8061977C;
extern const Unk80170518_Fn lbl_805CB054;
extern const Unk80170518_Fn lbl_805CB05C;
extern const Unk80170518_Fn lbl_805CB064;
extern const Unk80170518_Fn lbl_805CB06C;
extern const Unk80170518_Fn lbl_805CB074;
extern const Unk80170518_Fn lbl_805CB07C;
extern char lbl_8065EDB8[];
extern char lbl_8065ED60[];
struct Unk80170488_T {
    void* m0;
    int m4;
};
extern Unk80170488_T lbl_8068B884;
struct Unk801704C0_T {
    void* m0;
    char pad4[0x10];
    int m14;
    char pad18[0x330 - 0x18];
    int m330;
};
extern Unk801704C0_T lbl_8068B8AC;

int Unk8016FF40::fn_80170044(int x)
{
    if (m0 == 0) {
        return 0;
    }
    if (x != 0) {
        if (x == m74) {
            return 1;
        }
    } else if (m4 != 0) {
        return 1;
    }
    return 0;
}

void fn_8017008C(Unk8016FF40* info, const char* name)
{
    char* p = info->mE4;
    fn_8040074C(p, 0x1B);
    if (name) {
        fn_8040B61C(p, name);
    }
}

void fn_801700D8(Unk8016FF40* info, unsigned short* ws)
{
    unsigned short* a = info->mAE;
    unsigned short* b = info->m18;
    fn_8040074C(a, 0x36);
    fn_8040074C(b, 0x36);
    if (ws) {
        fn_8040316C(a, ws, 0x1B);
        fn_8040316C(b, ws, 0x1B);
        info->mAE[0x1A] = 0;
        info->m18[0x1A] = 0;
    }
}

void fn_80170158(Unk8016FF40* info, unsigned short* ws)
{
    unsigned short* p = info->m78;
    fn_8040074C(p, 0x16);
    if (ws) {
        fn_8040316C(p, ws, 0xB);
        info->m78[10] = 0;
    }
}

void fn_801701B4(Unk8016FF40* info, unsigned short* ws, int a)
{
    unsigned short* p = info->m8E;
    fn_8040074C(p, 0x20);
    if (ws) {
        fn_8040316C(p, ws, 0x10);
        info->m74 = a;
        info->m8E[15] = 0;
    }
}

int Unk8016FF40::fn_80170218(Unk8016FF40* other)
{
    return fn_8040B574(mE4, other->mE4) == 0;
}

int Unk8016FF40::fn_80170248()
{
    for (int i = 0; i < 4; i++) {
        if (m8[i] == -1) {
            return 1;
        }
    }
    if (m0 != 0 && m4 != 0 && m74 == 0) {
        return 1;
    }
    return 0;
}

void Unk8016FF40::fn_801702A4()
{
    int check;
    Unk8016FF40_Entry* e0 = m108[0];
    int base = e0->m0 + 0x10;
    int size = e0->m4 - 0x10;
    for (int i = 0; i < 4; i++) {
        Unk8016FF40_Entry* e = m108[i];
        fn_80170420(e->m0, e->m4, &check);
        int ok = fn_8040B100(&check, &m50[i], 4) == 0;
        m8[i] = ok ? 1 : -1;
    }
    fn_80170420(base, size, &check);
    m8[0] = fn_8040B100(&check, m50, 4) == 0 ? 1 : -1;
}

void fn_8017037C(Unk8016FF40* info)
{
    Unk8016FF40_Entry* e0 = info->m108[0];
    int base = e0->m0 + 0x10;
    int size = e0->m4 - 0x10;
    for (int i = 0; i < 4; i++) {
        Unk8016FF40_Entry* e = info->m108[i];
        info->fn_80170420(e->m0, e->m4, &info->m50[i]);
        info->m60[i] = info->m108[i]->m4;
        info->m8[i] = 0;
    }
    info->fn_80170420(base, size, info->m50);
}

void Unk8016FF40::fn_80170420(int p, int n, int* out)
{
    int r = p;
    if (r != 0) {
        r = fn_80400560(p, n);
    }
    *out = r;
}

void fn_8017045C()
{
    fn_80359B78(&lbl_8068B87C, 2);
}

void fn_80170488()
{
    lbl_8068B884.m0 = lbl_8065EDB8;
    fn_804007FC(&lbl_8068B884.m4);
}

void fn_801704C0()
{
    lbl_8068B8AC.m0 = lbl_8065ED60;
    if (lbl_8068B8AC.m330 != 0) {
        fn_8035A09C(&lbl_8068B8AC, 0);
        fn_803FFEB8(&lbl_8068B8AC.m14);
    }
}

Unk80170518::Unk80170518(int mode)
{
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m3C = 0;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    mBC = 0;
    mC0 = 0;
    mCC = 0;
    mD0 = 0;
    mC4 = 1;
    m2C = mode;
    m4C = &m48;
    mC8 = 1;
    fn_801709F8();
    mA0 = 0;
    for (int i = 0; i < 4; i++) {
        mA4[i] = 0;
    }
    mB4 = 0;
    mB8 = 0;
    fn_80403144(m68, (unsigned short*)fn_80090880(lbl_8061977C, 0x604));
    int n = fn_80403060(m68);
    for (int i = 0; i < n; i++) {
        if (m68[i] == 0x20) {
            m68[i] = 0xA0;
        }
    }
}

Unk80170518::~Unk80170518()
{
    fn_801709F8();
}

void Unk80170518::fn_80170668(Unk8016FF40* info, int state)
{
    m38 = info;
    m28 = state;
    switch (state) {
    case 6:
        fn_800060B4();
        break;
    case 4:
        fn_8017095C(lbl_805CB054);
        break;
    case 5:
        fn_8017095C(lbl_805CB05C);
        break;
    case 3:
        fn_8017095C(lbl_805CB064);
        break;
    case 2:
        fn_8017095C(lbl_805CB06C);
        break;
    case 1:
        fn_8017095C(lbl_805CB074);
        break;
    case 0:
        fn_8017095C(lbl_805CB07C);
        break;
    }
    m30 = 2;
}

void Unk80170518::fn_80170780(int a, int b, const void* name, int c)
{
    m3C = a;
    m40 = b;
    fn_80402FCC(m50, name);
    m60 = c;
    fn_8017095C(lbl_805CB05C);
    m30 = 2;
}

void Unk80170518::fn_801707F0()
{
    Unk80170518_Fn f = fn_801709A8();
    if (f) {
        (this->*f)();
        if (m30 == 0) {
            m30 = 2;
        }
        if (m30 != 2) {
            fn_801709F8();
        }
        fn_801708C0();
    } else {
        m30 = 0;
    }
}

int Unk80170518::fn_801708C0()
{
    if (m30 == 1) {
        fn_80005C8C();
    }
    if (m30 == 2) {
        fn_80005C8C();
        if (m30 == 0) {
            fn_801707F0();
        } else if (m30 != 2) {
            fn_801709F8();
        }
    }
    return m30;
}

int Unk80170518::fn_8017095C(Unk80170518_Fn f)
{
    Unk80170518_Fn* slot = m0;
    for (int i = 0; i < 5; i++) {
        if (((Unk80170518_Slot*)slot)->m2 == 0) {
            *slot = f;
            return 1;
        }
        slot++;
    }
    m30 = 4;
    return 0;
}

Unk80170518_Fn Unk80170518::fn_801709A8()
{
    Unk80170518_Fn front = m0[0];
    for (int i = 0; i < 4; i++) {
        m0[i] = m0[i + 1];
    }
    m0[4] = 0;
    return front;
}

void Unk80170518::fn_801709F8()
{
    for (int i = 0; i < 5; i++) {
        m0[i] = 0;
    }
}

int fn_80170A1C(Unk80170518* self)
{
    self->m38->fn_801702A4();
    return self->m38->fn_80170248();
}

void Unk80170518::fn_80170A54(int a)
{
    if (mBC != 0 && a > 0) {
        if (mB4 != 0) {
            m64->vslot22(5, 0);
            mB4 = 0;
        } else if (mB8 != 0) {
            m64->vslot22(a == 3 ? 4 : 3, 0);
            mB8 = 0;
        } else {
            m64->vslot22(a, 0);
        }
        mBC = 0;
    }
}

int Unk80170518::fn_80170B3C()
{
    return 0;
}
