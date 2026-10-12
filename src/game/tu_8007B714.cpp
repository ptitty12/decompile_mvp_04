/*
 * Game code, .text 0x8007B714-0x8007CAC4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8007A4DC.h"
#include "game/clampiter.h"

int Unk8007B2B0_Screen::fn_8007B714()
{
    return fn_8052FC34(m48);
}

int Unk8007B2B0_Screen::fn_8007B738()
{
    return fn_8052FC4C(m48);
}

int Unk8007B2B0_Screen::fn_8007B75C()
{
    return fn_8052FDC8(m48);
}

int Unk8007B2B0_Screen::fn_8007B780()
{
    return fn_8052FDD8(m48);
}

int Unk8007B2B0_Screen::fn_8007B7A4()
{
    return fn_8052FDFC(m48);
}

int Unk8007B2B0_Screen::fn_8007B7C8()
{
    return fn_8052FE0C(m48);
}

int Unk8007B2B0_Screen::fn_8007B7EC()
{
    return fn_8052FE20(m48);
}

int Unk8007B2B0_Screen::fn_8007B810()
{
    return fn_8052FE34(m48);
}

int Unk8007B2B0_Screen::fn_8007B834()
{
    return fn_8052FE48(m48);
}

int Unk8007B2B0_Screen::fn_8007B858()
{
    return fn_8052FE5C(m48);
}

int Unk8007B2B0_Screen::fn_8007B87C()
{
    return fn_8052FE70(m48);
}

int Unk8007B2B0_Screen::fn_8007B8A0()
{
    return fn_8052FE94(m48);
}

int Unk8007B2B0_Screen::fn_8007B8C4(int a, int b)
{
    return m54->v28(a, fn_80071814(m54, b));
}

int Unk8007B2B0_Screen::fn_8007B924(int a, int b, char* c)
{
    return m54->v30(a, fn_80071814(m54, b), c);
}

int Unk8007B2B0_Screen::fn_8007B98C(int a, int b, int c)
{
    return m54->v40(a, fn_80071814(m54, b), c);
}

char* Unk8007B2B0_Screen::fn_8007B9F4(int a, int b, char* out)
{
    char buf[0x400];
    fn_8007B924(a, b, buf);
    fn_80402EF8(out, buf);
    return out;
}

int Unk8007B2B0_Screen::fn_8007BA34(int a, int b, int c)
{
    W* w = m5C[c ? 1 : 0];
    return w->v28(a, fn_80071814(w, b));
}

int Unk8007B2B0_Screen::fn_8007BAA8(int a, int b, int c, int d)
{
    W* w = m5C[c ? 1 : 0];
    return w->v40(a, fn_80071814(w, b), d);
}

int Unk8007B2B0_Screen::fn_8007BB28(int a, int b, int c)
{
    W* w = m5C[c ? 1 : 0];
    return w->v38(a, fn_80071814(w, b));
}

int Unk8007B2B0_Screen::fn_8007BB9C(int a, int b)
{
    return m64->v28(a, fn_80071814(m64, b));
}

int Unk8007B2B0_Screen::fn_8007BBFC(int a, int b, int c)
{
    return m64->v40(a, fn_80071814(m64, b), c);
}

int Unk8007B2B0_Screen::fn_8007BC64(int a, int b, char* c)
{
    return m54->v30(a, b, c);
}

int Unk8007B2B0_Screen::fn_8007BC9C()
{
    return m54->m10->m4;
}

int Unk8007B2B0_Screen::fn_8007BCAC(int a, int b, int* c)
{
    unsigned i;
    for (i = 0; i < fn_8007B2B0(); i++) {
        if (fn_8007B648(0xE, i)) {
            int j = 0;
            int n = fn_8008FBE8(a);
            for (; j < n; j++) {
                int x = fn_8008FC40(a, j);
                if (fn_8007B610(fn_8008FE14(x), i) == b) {
                    if (c)
                        *c = x;
                    return fn_8007B2FC(i);
                }
            }
        }
    }
    if (c)
        *c = 10;
    return 0;
}

int Unk8007B2B0_Screen::fn_8007BD94(int a)
{
    switch (a) {
    case 0:
        return fn_8007C3E8();
    case 1:
        return fn_8007C6B4();
    case 2:
        return fn_8007C8D8();
    case 3:
        return fn_8007CAFC();
    case 4:
        return fn_8007CD20();
    }
    return 0;
}

int Unk8007B2B0_Screen::fn_8007BE10(int a, int b)
{
    switch (a) {
    case 0:
        return fn_8007C434(b);
    case 1:
        return fn_8007C700(b);
    case 2:
        return fn_8007C924(b);
    case 3:
        return fn_8007CB48(b);
    case 4:
        return fn_8007CD6C(b);
    }
    return 0;
}

int Unk8007B2B0_Screen::fn_8007BEA0(int a, int c)
{
    int r = fn_800909A4(&mAC, a, m8C.m0);
    fn_8009230C(&mAC, r, c);
    return r;
}

int Unk8007B2B0_Screen::fn_8007BEF4(int a, int c)
{
    int r = fn_800909A4(&mDC, a, 0);
    fn_80092C30(&mDC, r, c);
    return r;
}

int Unk8007B2B0_Screen::fn_8007BF44(int a, int c)
{
    int r = fn_800909A4(&m10C, a, 0);
    fn_80093554(&m10C, r, c);
    return r;
}

int Unk8007B2B0_Screen::fn_8007BF94(int a, int c)
{
    int r = fn_800909A4(&m13C, a, 0);
    fn_80093E78(&m13C, r, c);
    return r;
}

int Unk8007B2B0_Screen::fn_8007BFE4(int a, int c)
{
    int r = fn_800909A4(&m16C, a, 0);
    fn_8009479C(&m16C, r, c);
    return r;
}

int Unk8007B2B0_Screen::fn_8007C034(int a, int b)
{
    int r = 0;
    fn_8007C088(a, b);
    if (a == 0)
        r = fn_800918AC(&m8C, b);
    return r;
}

void Unk8007B2B0_Screen::fn_8007C088(int a, int b)
{
    int n = fn_8008FBE8(a);
    unsigned i;
    for (i = 0; i < fn_8007B2B0(); i++) {
        int j = 0;
        while (j < n) {
            int id = fn_8008FE14(fn_8008FC40(a, j++));
            if (fn_8007B610(id, i) == b)
                fn_8007B680(id, i, 0);
        }
    }
}

void Unk8007B2B0_Screen::fn_8007C134()
{
    unsigned i;
    for (i = 0; i < fn_8007B2B0(); i++) {
        int k;
        for (k = 0; k <= 4; k++) {
            int j;
            int n = fn_8008FBE8(k);
            for (j = 0; j < n; j++)
                fn_8007B680(fn_8008FE14(fn_8008FC40(k, j)), i, 0);
        }
    }
}

int Unk8007B2B0_Screen::fn_8007C1D0(int a, int b, int d, Unk8007B2B0_Pair* e)
{
    int id = fn_8008FE14(d);
    if (fn_8007B380(id, b) != 0)
        return 2;
    fn_8007B440(id, b, a);
    int t = fn_80079ADC(e->m0);
    int o = fn_8008FD78(d);
    fn_80090540(o, a, t);
    fn_800905FC(o, a, e->m4);
    fn_80590C24(m30);
    return 0;
}

int Unk8007B2B0_Screen::fn_8007C288(int a, int b, Unk8007B2B0_Pair* c, int d, int e, int f)
{
    int r = fn_8007B380(fn_8008FE14(b), f);
    if (r == a) {
        int t = fn_80079ADC(c->m0);
        int o = fn_8008FD78(b);
        fn_80090540(o, r, t);
        fn_800905FC(o, r, c->m4);
    }
    fn_80590C24(m30);
    return 0;
}

void Unk8007B2B0_Screen::fn_8007C328(int a, int b)
{
    int found = 0;
    int id = 0x23;
    Unk8006A138_It<9> it(0);
    while (it.v <= 9) {
        id = fn_8008FE14(it.v);
        if (fn_8007B380(id, b) == a) {
            found = 1;
            break;
        }
        it.Next();
    }
    if (found) {
        fn_8007B440(id, b, 0);
        fn_800905FC(fn_8008FD78(it.v), a, 0);
    }
    fn_80590C24(m30);
}

int Unk8007B2B0_Screen::fn_8007C3E8()
{
    return fn_800A883C(&m6C) ? fn_800A883C(&m6C)->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007C434(int a)
{
    return fn_80071784(m74, a);
}

int Unk8007B2B0_Screen::fn_8007C458()
{
    return fn_800A883C(&m8C) ? fn_800A883C(&m8C)->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007C4A4(int a)
{
    return fn_80071784(m94, a);
}

int Unk8007B2B0_Screen::fn_8007C4C8()
{
    return fn_800A883C(&mAC) ? fn_800A883C(&mAC)->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007C514(int a, int b)
{
    return m74->v28(a, fn_80071814(m74, b));
}

int Unk8007B2B0_Screen::fn_8007C574(int a, int b, int c)
{
    return m74->v40(a, fn_80071814(m74, b), c);
}

int Unk8007B2B0_Screen::fn_8007C5DC(int a, int b, char* c)
{
    return m74->v30(a, fn_80071814(m74, b), c);
}

int Unk8007B2B0_Screen::fn_8007C644(int a, int b, int c)
{
    return m74->v40(a, b, c);
}

int Unk8007B2B0_Screen::fn_8007C67C(int a, int b)
{
    return m94->v28(a, b);
}

int Unk8007B2B0_Screen::fn_8007C6B4()
{
    return fn_800A883C(&mBC) ? fn_800A883C(&mBC)->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007C700(int a)
{
    return fn_80071784(mC4, a);
}

int Unk8007B2B0_Screen::fn_8007C724()
{
    return fn_800A883C(&mDC) ? fn_800A883C(&mDC)->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007C770(int a, int b)
{
    return mC4->v28(a, fn_80071814(mC4, b));
}

int Unk8007B2B0_Screen::fn_8007C7D0(int a, int b, int c)
{
    return mC4->v40(a, fn_80071814(mC4, b), c);
}

int Unk8007B2B0_Screen::fn_8007C838(int a, int b, char* c)
{
    return mC4->v30(a, fn_80071814(mC4, b), c);
}

int Unk8007B2B0_Screen::fn_8007C8A0(int a, int b, int c)
{
    return mC4->v40(a, b, c);
}

int Unk8007B2B0_Screen::fn_8007C8D8()
{
    return fn_800A883C(&mEC) ? fn_800A883C(&mEC)->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007C924(int a)
{
    return fn_80071784(mF4, a);
}

int Unk8007B2B0_Screen::fn_8007C948()
{
    return fn_800A883C(&m10C) ? fn_800A883C(&m10C)->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007C994(int a, int b)
{
    return mF4->v28(a, fn_80071814(mF4, b));
}

int Unk8007B2B0_Screen::fn_8007C9F4(int a, int b, int c)
{
    return mF4->v40(a, fn_80071814(mF4, b), c);
}

int Unk8007B2B0_Screen::fn_8007CA5C(int a, int b, char* c)
{
    return mF4->v30(a, fn_80071814(mF4, b), c);
}
