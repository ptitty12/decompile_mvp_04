/*
 * Game code, .text 0x802DBCB8-0x802DE2C8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802DBCB8.h"

void Unk803414A4::vslot2()
{
    fn_803FFC58(m10BC, 0, 0x480);
    m1550 = 0;
    m1554 = 0;
}

float Unk803414A4::fn_802DBCFC(int a, int b)
{
    return vslot8(vslot25(a)) - vslot8(vslot25(b));
}

float Unk803414A4::fn_802DC1D8(int idx)
{
    Unk803414A4_Entry* e = &m0[idx];
    short a = vslot25(e->m0);
    short b = vslot25(e->m2);
    return fn_802DC264(a, b, e->m8, e->m4, e->m6, e->mC);
}

/* near-miss: same code except the switch tree (retail omits the c == 1 and c == 3 compares
   via bounded nodes; ours emits cmpwi 1 / keeps the c == 3 test); enum index did not help */
float Unk803414A4::fn_802DC264(int a, int b, int c, int d, int e, float f)
{
    float res = 0.0f;
    if (a != -2) {
        float v1 = fn_802DBDAC(a, d);
        if (c == -1) {
            res = v1;
        } else {
            float v2 = fn_802DBDAC(b, e);
            unsigned t;
            switch (c) {
            case 0:
                t = v1 != 0.0f || v2 != 0.0f;
            conv:
                res = (float)t;
                break;
            case 1:
                t = v1 != 0.0f && v2 != 0.0f;
                goto conv;
            case 2:
                t = v2 == 0.0f && v1 != 0.0f;
                goto conv;
            case 3:
                res = v1 - v2;
                break;
            case 4:
                if (v1 == 0.0f) {
                    res = 0.0f;
                } else {
                    res = v2;
                }
                break;
            case 5:
                if (v1 != 0.0f) {
                    res = 0.0f;
                } else {
                    res = v2;
                }
                break;
            }
        }
    }
    return res * f;
}

float Unk803414A4::fn_802DC3E8(int idx)
{
    float res = 6.2831855f;
    if (m0[idx].m0 == -2) {
        res = 6.2831855f;
    } else {
        switch (idx) {
        case 0x3a:
        case 0xc9:
        case 0xca:
            res = fn_802DBDAC(0xba, 5);
            break;
        case 0x3d:
            res = fn_802DBDAC(0xbe, 5);
            break;
        case 0x3c:
            res = fn_802DBDAC(0xbe, 5);
            break;
        case 0xbd:
            res = fn_802DBDAC(0xba, 5);
            break;
        case 0x3b:
        case 0x74:
        case 0xb3:
        case 0xbc:
            res = fn_802DBDAC(0xb6, 5);
            break;
        case 0x42:
            res = fn_802DC264(7, 0xb6, 5, 2, 5, 1.0f);
            break;
        case 0x41:
            res = fn_802DC264(7, 0xba, 5, 2, 5, 1.0f);
            break;
        default:
            res = 6.2831855f;
            break;
        }
    }
    return res;
}

void Unk803414A4::fn_802DC518(int a)
{
    vslot2();
    m1550 = 0;
    m1558.fn_802DCA6C(a);
}

void Unk803414A4::fn_802DC570()
{
    vslot2();
    m1550 = 0;
    m1558.fn_802DCB5C();
}

int Unk803414A4::fn_802DC5C0()
{
    return m1558.m0 == 2;
}

void Unk803414A4::fn_802DC5D4(int name)
{
    m1558.fn_802DCBB8(name);
}

void Unk803414A4::fn_802DC5F8(int name)
{
    m1558.fn_802DCD60(name);
}

void Unk803414A4::fn_802DC8E4()
{
    m10B8 = -1;
    m1550 = m1550 + 1;
    int n = vslot7();
    for (int i = n - 1; i >= 0; i--) {
        m10BC[i].m0 = 0;
        m10BC[i].m4 = 0;
        m10BC[i].mC = 0;
        m10BC[i].m14 = 0;
    }
}

void Unk803414A4::fn_802DC974()
{
    m10B8 = -1;
    fn_803FFC58(m10BC, 0, 0x480);
    m1550 = 0;
    m1554 = 0;
}

int fn_802DC9C0()
{
    return lbl_806EFA04;
}

Unk802DC9F8::Unk802DC9F8()
{
    m0 = 0;
    m4 = 0;
    m8 = 0;
    mC = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    m1C = 0;
}

Unk802DC9F8::~Unk802DC9F8()
{
    if (mC) {
        delete mC;
        mC = 0;
    }
    if (m10) {
        delete m10;
        m10 = 0;
    }
}

void Unk802DC9F8::fn_802DCA64(Unk803414A4* o)
{
    m4 = o;
}

int Unk802DC9F8::fn_802DCA6C(int a)
{
    if (mC == 0) {
        mC = new (0) char[m4->vslot7() * 8];
        fn_803FFC58(mC, 0, m4->vslot7() * 8);
    }
    m18 = 0;
    if (a != m14) {
        if (m10 != 0) {
            delete m10;
            m10 = 0;
        }
        m14 = a;
        m10 = new (0) char[a * 12];
    }
    int r;
    if (m10 == 0) {
        r = 0;
    } else {
        m0 = 1;
        r = 1;
    }
    return r;
}

int Unk802DC9F8::fn_802DCB5C()
{
    m0 = 2;
    m1C = 0;
    m20 = m4->vslot18();
    return 1;
}

int Unk802DC9F8::fn_802DCBB8(int name)
{
    int h;
    fn_803FEBDC(name, 6, 100, &h);
    if (h != 0) {
        char buf[0x100];
        fn_804089B4(buf, "%d
", m18);
        int i = 0;
        int pos = fn_803FEC74(h, 0, buf, fn_8040B6A0(buf), 100);
        for (; i < m18; i++) {
            int off = i * 12;
            fn_804089B4(buf, "%d %d %d %d
", *(int*)(m10 + off), *(short*)(m10 + off + 4), *(short*)(m10 + off + 6), *(int*)(m10 + off + 8));
            pos += fn_803FEC74(h, pos, buf, fn_8040B6A0(buf), 100);
        }
        fn_803FEC9C(h, 100);
    }
    return 1;
}

int fn_802DCCCC(int h, int* pos, int* out)
{
    char buf[0x14];
    fn_803FEC4C(h, *pos, buf, 0x14, 0x64);
    int i = 0;
    while (buf[i] != 10 && buf[i] != 32) {
        i++;
    }
    *pos = *pos + i + 1;
    buf[i] = 0;
    *out = fn_80409DAC(buf);
    return 1;
}

int Unk802DC9F8::fn_802DCD60(int name)
{
    int h;
    fn_803FEBDC(name, 1, 100, &h);
    if (h != 0) {
        int pos = 0;
        int count;
        fn_802DCCCC(h, &pos, &count);
        m18 = count;
        for (int i = 0; i < m18; i++) {
            int a;
            int b;
            int c;
            int d;
            fn_802DCCCC(h, &pos, &a);
            fn_802DCCCC(h, &pos, &b);
            fn_802DCCCC(h, &pos, &c);
            fn_802DCCCC(h, &pos, &d);
            ((int*)m10)[i * 3] = a;
            ((short*)m10)[i * 6 + 2] = b;
            ((short*)m10)[i * 6 + 3] = c;
            ((float*)m10)[i * 3 + 2] = *(float*)&d;
        }
        fn_803FEC9C(h, 100);
    }
    return 1;
}

void Unk802DC9F8::fn_802DCE80(int frame)
{
    switch (m0) {
    case 0:
        break;
    case 1:
        fn_802DCEC4(frame);
        break;
    case 2:
        fn_802DD0BC(frame);
        break;
    }
}

void Unk803414A4::vslot3()
{
}

void Unk803414A4::vslot4()
{
}

void Unk803414A4::vslot5()
{
    vslot6();
}

int Unk803414A4::vslot12()
{
    return -1;
}

void Unk803414A4::vslot13()
{
}

int Unk803414A4::vslot14()
{
    return 0;
}

int Unk803414A4::vslot15()
{
    return 0;
}

int Unk803414A4::vslot16()
{
    return 0;
}

void Unk803414A4::vslot17()
{
}

int Unk803414A4::vslot20()
{
    return fn_802DC9C0();
}

int Unk803414A4::vslot21()
{
    return 0;
}

void Unk803414A4::vslot22(int a, float f)
{
}

void Unk803414A4::vslot23(int a, float f)
{
}

void Unk803414A4::vslot24(int a)
{
}

int Unk803414A4::vslot25(int n)
{
    return n;
}

const char* Unk803414A4::vslot26()
{
    return "";
}

const char* Unk803414A4::vslot27()
{
    return "";
}

int Unk803414A4::vslot28() { return 0; }
int Unk803414A4::vslot29() { return 0; }
int Unk803414A4::vslot30() { return 0; }
int Unk803414A4::vslot31() { return 0; }
int Unk803414A4::vslot32() { return 0; }
int Unk803414A4::vslot33() { return 0; }
int Unk803414A4::vslot34() { return 0; }
int Unk803414A4::vslot35() { return 0; }

void Unk803414A4::vslot36()
{
}

void Unk803414A4::vslot37()
{
}

int Unk803414A4::vslot38()
{
    return 0;
}

void Unk803414A4::vslot39()
{
}

void Unk803414A4::vslot40(float f)
{
}

void Unk803414A4::vslot44(Unk8000B258_State* s)
{
    vslot42(s);
}

void Unk803414A4::vslot45(const Unk8000B258_State* s)
{
    vslot43(s);
}

void Unk802DC9F8::fn_802DCEC4(int frame)
{
    int i = 0;
    int off = 0;
    m4->vslot19(m20);
    while (i < m4->vslot7()) {
        float v = m4->vslot8(i);
        float t = v * 255.0f + 0.5f;
        short q = (short)t;
        float u = (float)q * 0.003921569f;
        m4->vslot9(i, u);
        if (q != *(short*)(off + (int)mC)) {
            m8 = m8 + 1;
            *(int*)(m18 * 12 + (int)m10) = frame;
            *(short*)(m18 * 12 + (int)m10 + 4) = i;
            *(short*)(m18 * 12 + (int)m10 + 6) = q;
            *(float*)(m18 * 12 + (int)m10 + 8) = m4->vslot18();
            m20 = m4->vslot18();
            m18 = m18 + 1;
            *(short*)(off + (int)mC) = q;
            *(int*)(off + (int)mC + 4) = frame;
        }
        off += 8;
        i++;
    }
}

/* near-miss: playback of the recorded frames; retail keeps the record index in a register through the
   skip loop (mulli per iteration, no pointer bump) and re-reads m1C/m10 for the do-while (about 40 slots) */
void Unk802DC9F8::fn_802DD0BC(int frame)
{
    if (m1C == m18) {
        return;
    }
    m4->vslot19(m20);
    while (*(int*)(m1C * 12 + (int)m10) < frame) {
        m1C = m1C + 1;
    }
    while (*(int*)(m1C * 12 + (int)m10) == frame) {
        m4->vslot9(*(short*)(m1C * 12 + (int)m10 + 4), (float)*(short*)(m1C * 12 + (int)m10 + 6) * 0.003921569f);
        m4->vslot19(*(float*)(m1C * 12 + (int)m10 + 8));
        int c = m1C;
        m1C = c + 1;
        m20 = *(float*)(c * 12 + (int)m10 + 8);
    }
}
