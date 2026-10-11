/*
 * Game code, .text 0x8007A4DC-0x8007B714 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8007A4DC.h"

int Unk8007A4DC_Screen::fn_8007A4DC(int a)
{
    return fn_8007189C(m184, a);
}

int Unk8007A4DC_Screen::fn_8007A500(int a)
{
    return fn_8007189C(m1C8, a);
}

int Unk8007A4DC_Screen::fn_8007A524(int a, int b, int i)
{
    return fn_8007189C(m188[i], a);
}

int Unk8007A4DC_Screen::fn_8007A550(int a)
{
    return m184->v18(a);
}

int Unk8007A4DC_Screen::fn_8007A588(int a)
{
    return m1C8->v18(a);
}

int Unk8007A4DC_Screen::fn_8007A5C0(int a)
{
    return m188[1]->v18(a);
}

int Unk8007A4DC_Screen::fn_8007A5F8()
{
    return m184->v20();
}

int Unk8007A4DC_Screen::fn_8007A630()
{
    return m1C8->v20();
}

int Unk8007A4DC_Screen::fn_8007A668()
{
    return m188[1]->v20();
}

int Unk8007A4DC_Screen::fn_8007A6A0(int a, int b)
{
    return m184->v28(a, fn_80071814(m184, b));
}

int Unk8007A4DC_Screen::fn_8007A700(int a, int b, char* c)
{
    return m184->v30(a, fn_80071814(m184, b), c);
}

int Unk8007A4DC_Screen::fn_8007A768(int a, int b)
{
    return m184->v38(a, fn_80071814(m184, b));
}

char* Unk8007A4DC_Screen::fn_8007A7C8(int a, int b, char* out)
{
    char buf[0x400];
    fn_8007A700(a, b, buf);
    fn_80402EF8(out, buf);
    return out;
}

int Unk8007A4DC_Screen::fn_8007A808(int a, int b, int c)
{
    return m184->v40(a, fn_80071814(m184, b), c);
}

int Unk8007A4DC_Screen::fn_8007A870(int a, int b, int c)
{
    return m184->v48(a, fn_80071814(m184, b), c, 0);
}

int Unk8007A4DC_Screen::fn_8007A8DC(int a, int b)
{
    return m184->v28(a, b);
}

int Unk8007A4DC_Screen::fn_8007A914(int a, int b, char* c)
{
    return m184->v30(a, b, c);
}

int Unk8007A4DC_Screen::fn_8007A94C(int a, int b, int c)
{
    return m184->v40(a, b, c);
}

int Unk8007A4DC_Screen::fn_8007A984(int a)
{
    if (m0->m1F0 != 1)
        m184->v18(0x1D);
    else
        m184->v28(0x1D, fn_80071814(m184, a));
}

int Unk8007A4DC_Screen::fn_8007AA10(int a)
{
    if (m0->m1F0 != 1)
        m184->v18(0x1D);
    else
        m184->v28(0x1D, a);
}

int Unk8007A4DC_Screen::fn_8007AA84(int a, int b, int i)
{
    W* w = m188[i];
    return w->v28(a, fn_80071814(w, b));
}

int Unk8007A4DC_Screen::fn_8007AAEC(int a, int b, int i, int c)
{
    W* w = m188[i];
    return w->v40(a, fn_80071814(w, b), c);
}

int Unk8007A4DC_Screen::fn_8007AB5C(int a, int b, int i)
{
    return m188[i]->v28(a, b);
}

int Unk8007A4DC_Screen::fn_8007AB9C(int a, int b)
{
    return m1C8->v28(a, fn_80071814(m1C8, b));
}

int Unk8007A4DC_Screen::fn_8007ABFC(int a, int b)
{
    return m1C8->v38(a, fn_80071814(m1C8, b));
}

int Unk8007A4DC_Screen::fn_8007AC5C(int a, int b, int c)
{
    return m1C8->v40(a, fn_80071814(m1C8, b), c);
}

int Unk8007A4DC_Screen::fn_8007ACC4(int a, int b)
{
    return m1C8->v28(a, b);
}

int Unk8007A4DC_Screen::fn_8007ACFC(int a, int b, int c)
{
    return m1C8->v40(a, b, c);
}

int Unk8007A4DC_Screen::fn_8007AD34(int sel, int x, int y)
{
    int r;
    int p, q;
    int p2, q2;
    if (sel == 0xD) {
        fn_80377E90(fn_800A883C(&m17C), &p, &q, x);
        r = fn_800803F0(this, y, p);
    } else if (sel != 0x10) {
        r = y;
    } else {
        fn_80377E90(fn_800A883C(&m17C), &p2, &q2, x);
        r = fn_80080464(this, y, p2);
    }
    return r;
}

int Unk8007A4DC_Screen::fn_8007ADD0(unsigned sel, int x, int y)
{
    int p, q;
    int r;
    if (sel > 1)
        r = y;
    else {
        fn_80377E90(fn_800A883C(&m17C), &p, &q, x);
        r = fn_800803F0(this, y, p);
    }
    return r;
}

int Unk8007A4DC_Screen::fn_8007AE38(int sel, int x, int y)
{
    if (sel == 0xD)
        return fn_800803F0(this, y, x);
    if (sel == 0x10)
        return fn_80080464(this, y, x);
    return y;
}

int Unk8007A4DC_Screen::fn_8007AE84(unsigned sel, int x, int y)
{
    if (sel > 1)
        return y;
    return fn_800803F0(this, y, x);
}

int Unk8007A4DC_Screen::fn_8007AEBC(int a, int b)
{
    return m1BC->v28(a, fn_80071814(m1BC, b));
}

int Unk8007A4DC_Screen::fn_8007AF1C(int a, int b)
{
    return m1BC->v38(a, fn_80071814(m1BC, b));
}

int Unk8007A4DC_Screen::fn_8007AF7C(int a, int b, int c)
{
    return m1BC->v40(a, fn_80071814(m1BC, b), c);
}

int Unk8007A4DC_Screen::fn_8007AFE4(int a, int b)
{
    return m1BC->v28(a, b);
}

int Unk8007A4DC_Screen::fn_8007B01C(int a, int b, int c)
{
    return m1BC->v40(a, b, c);
}

int Unk8007A4DC_Screen::fn_8007B054(int a, int b)
{
    return m1E4->v28(a, fn_80071814(m1E4, b));
}

int Unk8007A4DC_Screen::fn_8007B0B4(int a, int b)
{
    return m1E4->v38(a, fn_80071814(m1E4, b));
}

int Unk8007A4DC_Screen::fn_8007B114(int a, int b, int c)
{
    return m1E4->v40(a, fn_80071814(m1E4, b), c);
}

int Unk8007A4DC_Screen::fn_8007B17C(int a, int b)
{
    return m1E4->v28(a, b);
}

int Unk8007A4DC_Screen::fn_8007B1B4(int a, int b, int c)
{
    return m1E4->v40(a, b, c);
}

int Unk8007A4DC_Screen::fn_8007B1EC()
{
    return fn_800A883C(&m17C) ? fn_800A883C(&m17C)->m4 : 0;
}

int Unk8007A4DC_Screen::fn_8007B238()
{
    return fn_800A883C(&m1C0) ? fn_800A883C(&m1C0)->m4 : 0;
}

int Unk8007A4DC_Screen::fn_8007B284(int a, int i)
{
    return fn_80071784(m190[i].m0, a);
}

int Unk8007B2B0_Screen::fn_8007B2B0()
{
    return fn_800A883C(&m38) ? fn_800A883C(&m38)->m4 : 0;
}

int Unk8007B2B0_Screen::fn_8007B2FC(int a)
{
    return fn_80071784(m40, a);
}

int Unk8007B2B0_Screen::fn_8007B320(int a, int b)
{
    return m40->v28(a, fn_80071814(m40, b));
}

int Unk8007B2B0_Screen::fn_8007B380(int a, int b)
{
    return m40->v28(a, fn_80071814(m40, b));
}

int Unk8007B2B0_Screen::fn_8007B3E0(int a, int b)
{
    return m40->v28(a, fn_80071814(m40, b));
}

int Unk8007B2B0_Screen::fn_8007B440(int a, int b, int c)
{
    return m40->v40(a, fn_80071814(m40, b), c);
}

int Unk8007B2B0_Screen::fn_8007B4A8(int a, int b, int c)
{
    return m40->v40(a, fn_80071814(m40, b), c);
}

int Unk8007B2B0_Screen::fn_8007B510(int a, int b)
{
    return m44->v28(a, fn_80071814(m44, b));
}

int Unk8007B2B0_Screen::fn_8007B570(int a, int b, int c)
{
    return m44->v40(a, fn_80071814(m44, b), c);
}

int Unk8007B2B0_Screen::fn_8007B5D8()
{
    return m40->v68();
}

int Unk8007B2B0_Screen::fn_8007B610(int a, int b)
{
    return m40->v70(a, b);
}

int Unk8007B2B0_Screen::fn_8007B648(int a, int b)
{
    return m40->v28(a, b);
}

int Unk8007B2B0_Screen::fn_8007B680(int a, int b, int c)
{
    return m40->v78(a, b, c);
}

int Unk8007B2B0_Screen::fn_8007B6B8(int a, int b, int c)
{
    return m40->v40(a, b, c);
}

int Unk8007B2B0_Screen::fn_8007B6F0()
{
    return fn_8052FC1C(m48);
}
