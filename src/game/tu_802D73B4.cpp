/*
 * Game code, .text 0x802D73B4-0x802DBCB8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802D73B4.h"

int fn_802D73B4()
{
    return 0;
}

void fn_802D73BC()
{
    fn_802D6304(1, 0xFFFF);
}

Unk802D73B4_W::Unk802D73B4_W()
{
    lbl_8061EDF8 = new (0) Unk802D73B4_Mgr;
    lbl_8061EDF8->s2();
    lbl_8061EE10 = 1;
}

Unk802D73B4_W::~Unk802D73B4_W()
{
    lbl_8061EDF8->s3();
    if (lbl_8061EDF8) {
        delete lbl_8061EDF8;
    }
    lbl_8061EDF8 = 0;
}

void fn_802D74FC()
{
    lbl_8061EDF8->s10();
}

void fn_802D7538()
{
    lbl_8061EDF8->s11(-1, -1);
    lbl_8061EE1C = 0;
}

void fn_802D7588()
{
    if (lbl_8061EE10) {
        lbl_8061EDF8->s6();
    }
}

inline float Abs2(float v)
{
    return __builtin_fabsf(v);
}

void fn_802D75D4(int a)
{
    if (lbl_8061EE10 == 0) {
        return;
    }
    lbl_8061EE1C = lbl_8061EE1C + 1;
    lbl_8061EDF8->s8(-1, -1);
    lbl_8061EDF8->s9(-1, -1);
    if (a != 0) {
        float v1[3];
        float v2[3];
        float v3[3];
        fn_802CBE04(a, v1, v2, v3);
        const float eps = 0.00001f;
        if (!(Abs2(v1[0]) >= eps || Abs2(v1[2]) >= eps)) {
            lbl_8061EE04 = fn_80410CE8(v2[0], v2[2]);
        } else {
            lbl_8061EE04 = fn_80410CE8(v1[0], v1[2]);
        }
    } else {
        lbl_8061EE04 = 0.0f;
    }
    if (lbl_8068B618 != 0) {
        Unk802D73B4_Plr* p = lbl_8061B8C0->m8[0];
        int t = lbl_8061EE14 ^ 1;
        if (p != 0 && t != 0 && p->m65C != 0) {
            int f = fn_802D7890(0) < 0;
            f = !f;
            if (fn_802D7C70() != lbl_8061EE18 && lbl_8061EE18 != -1) {
                f = 1;
            }
            if (f != 0 || lbl_8061EE20 > -1) {
                Unk8035F448 ev(0x9c);
                fn_8037893C((char*)p + 0x704, 0x9c, &ev, 0, 0);
            }
        }
    }
    lbl_8061EE18 = fn_802D7C70();
    if (lbl_8061EDFC != lbl_8061EE00) {
        lbl_8061EDFC = lbl_8061EE00;
    }
}

void fn_802D77F0()
{
    unsigned first = fn_80400DA4();
    unsigned cur = first;
    do {
        unsigned t = fn_80400DA4();
        if (t != cur) {
            fn_80400CE4(0);
            lbl_8061EDF8->s8(-1, -1);
            lbl_8061EDF8->s12(1);
        }
        cur = t;
    } while (cur - first <= 4);
}

int fn_802D7890(int a)
{
    int r;
    if (fn_802D78D8(a) == -1) {
        r = -1;
    } else {
        fn_802D77F0();
        r = fn_802D78D8(a);
    }
    return r;
}

int fn_802D78D8(int a)
{
    int done = 0;
    if (lbl_8068B618 != 0) {
        Unk802D73B4_G* g = lbl_8061B8C0;
        Unk802D73B4_Plr** pp = g->m8;
        Unk802D73B4_Plr* p1 = pp[0];
        if (p1 != 0) {
            Unk802D73B4_Rec* rec = p1->m6F8->m10;
            int v1 = -1;
            int v0;
            if ((unsigned)(rec->m74 - 1) <= 1) {
                v0 = rec->m70;
                if (v0 == -1) {
                    v0 = rec->m6C;
                }
                Unk802D73B4_Plr* p2 = pp[1];
                if (p2 != 0) {
                    Unk802D73B4_Rec* rec2 = p2->m6F8->m10;
                    v1 = rec2->m70;
                    if (v1 == -1) {
                        v1 = rec2->m6C;
                    }
                }
            } else {
                v1 = rec->m6C;
                v0 = rec->m70;
            }
            if (v1 >= -1 && v1 <= 3) {
                if (v1 != -1) {
                    if (fn_802D7CE0(v1, a) == 0) {
                        return v1;
                    }
                }
            }
            if (v0 >= -1 && v0 <= 3) {
                if (v0 != -1) {
                    if (fn_802D7CE0(v0, a) == 0) {
                        return v0;
                    }
                }
            }
            done = 1;
        }
    }
    if (done == 0) {
        Unk802D73B4_Rec* rec3 = lbl_806192E0->m4->m10;
        int v0 = rec3->m6C;
        int v1 = rec3->m70;
        if (v0 >= -1 && v0 <= 3) {
            if (v0 != -1) {
                if (fn_802D7CE0(v0, a) == 0) {
                    return v0;
                }
            }
        }
        if (v1 >= -1 && v1 <= 3) {
            if (v1 != -1) {
                if (fn_802D7CE0(v1, a) == 0) {
                    return v1;
                }
            }
        }
    }
    return -1;
}

void fn_802D7A64()
{
    lbl_8061F678 = 0;
}

void fn_802D7A74()
{
    lbl_8061F678 = 1;
}

int fn_802D7A84(int* a)
{
    return lbl_8061EDF8->s5(a);
}

void fn_802D7AC4()
{
}

int fn_802D7AC8(int a)
{
    return a;
}

void fn_802D7ACC()
{
    lbl_8061EE0C = 1;
}

void fn_802D7ADC()
{
    if (lbl_8061EE10) {
        lbl_8061EE0C = 0;
        int i = 0;
        int n = fn_802D8150();
        for (; i < n; i++) {
            if (fn_802D8178(i)->s6()) {
                fn_802D8178(i)->s24(0);
            }
        }
    }
}

void fn_802D7B88(int a, int b, int c, float t)
{
    int v = c * lbl_8061B9C8;
    int idx = fn_802D7AC8(a);
    if (lbl_8061EE0C != 0 && idx != -1 && (b != 1 || fn_802D80EC(a) != 0)) {
        if (b == 0) {
            v = -1;
            t = 0.0f;
        }
        lbl_8061EDF8->m8[idx]->s24(1);
        lbl_8061EDF8->m8[idx]->s23(v, t);
    }
}

int fn_802D7C70()
{
    int cnt = 0;
    for (int i = 0; i < fn_802D8150(); i++) {
        if (fn_802D8178(i)->s6()) {
            cnt++;
        }
    }
    return cnt;
}

int fn_802D7CE0(int a, int b)
{
    int r = 0;
    if (a != -1) {
        Unk802D73B4_Pad* p = fn_802D8178(fn_802D7AC8(a));
        if (p->m10B4 == 0) {
            if (b != 0) {
                r = p->s5();
            } else {
                r = p->s6();
            }
        }
    }
    return r;
}

int fn_802D7D64(int a)
{
    if (a == -1) {
        return 0;
    }
    return fn_802D8178(fn_802D7AC8(a))->s21();
}

int fn_802D7DB4(int a, int b)
{
    if (a != -1) {
        int m = lbl_8061EE24[b];
        if ((lbl_8061EDFC & m) || m == -1) {
            float f = fn_802D81A4(a, b);
            return f != 0.0f;
        }
    }
    return 0;
}

float fn_802D7E2C(int a, int b)
{
    if (a != -1) {
        int m = lbl_8061EE24[b];
        if ((lbl_8061EDFC & m) || m == -1) {
            return fn_802D81A4(a, b);
        }
    }
    return 0.0f;
}

float fn_802D7E88(int a, int b)
{
    if (a != -1) {
        int m = lbl_8061EE24[b];
        if ((lbl_8061EDFC & m) || m == -1) {
            return fn_802D821C(a, b);
        }
    }
    return 6.2831855f;
}

/* near-miss: the index of m8[idx] is in r0 here, r11 in retail (2 slots); about 10 index forms tried */
int fn_802D7EE4(int a)
{
    int idx = fn_802D7AC8(a);
    int r;
    if (idx == -1) {
        r = 0;
    } else {
        r = lbl_8061EDF8->m8[idx]->s20();
    }
    return r;
}

float fn_802D7F40(int a)
{
    if (a == -1) {
        return 0.0f;
    }
    return lbl_8061EDF8->m8[fn_802D7AC8(a)]->s18();
}

float fn_802D7FA0()
{
    return lbl_8061EE04;
}

inline float AbsF(float v)
{
    return __builtin_fabsf(v);
}

inline float AngleDiff(float a, float b)
{
    float d = a - b;
    d -= (float)fn_80410634(d * 0.15915494f + 0.5f) * 6.2831855f;
    return d;
}

int fn_802D7FAC(float a, float b, float c)
{
    return AbsF(AngleDiff(b, a)) < c;
}

int fn_802D804C(float a, float b)
{
    return AbsF(AngleDiff(b, a)) < 0.7853982f;
}

int fn_802D80EC(int a)
{
    Unk802D73B4_Plr* p = lbl_8061B8C0->m8[0];
    if (p != 0) {
        Unk802D73B4_Ref* r = p->m6F8;
        if (r != 0) {
            Unk802D73B4_Rec* rec = r->m10;
            if (rec != 0) {
                return fn_80086D34((Unk80084910_W*)rec, a) == 1;
            }
        }
    }
    return 1;
}

int fn_802D8150()
{
    return lbl_8061EDF8->fn_802D845C();
}

Unk802D73B4_Pad* fn_802D8178(int a)
{
    return lbl_8061EDF8->fn_802D8490(a);
}

float fn_802D81A4(int a, int b)
{
    float r = 0.0f;
    if (a != -1) {
        int idx = fn_802D7AC8(a);
        Unk802D73B4_Pad* p = lbl_8061EDF8->m8[idx];
        p->m10B8 = lbl_8061F24C[b];
        r = fn_802DC1D8(p, b);
    }
    return r;
}

float fn_802D821C(int a, int b)
{
    float r = 6.2831855f;
    if (a != -1) {
        int idx = fn_802D7AC8(a);
        Unk802D73B4_Pad* p = lbl_8061EDF8->m8[idx];
        p->m10B8 = lbl_8061F24C[b];
        r = fn_802DC3E8(p, b);
    }
    return r;
}

void fn_802D8294(int a)
{
    int c = lbl_8061EDFC;
    if (c != 0 && lbl_8061EE00 != c) {
        return;
    }
    if (c == a) {
        return;
    }
    lbl_8061EDFC = 0;
    lbl_8061EE00 = a;
}

void Unk802D73B4_Mgr::s3()
{
    for (int i = 0; i <= 3; i++) {
        fn_802D83E4(i);
    }
    fn_800085AC();
}

void Unk802D73B4_Mgr::fn_802D83E4(int a)
{
    Unk802D73B4_Pad* p = m8[a];
    m8[a] = 0;
    char* b = m18[a];
    m18[a] = 0;
    if (p) {
        delete p;
    }
    if (b) {
        fn_80377488(b);
    }
}

int Unk802D73B4_Mgr::fn_802D845C()
{
    int n = 0;
    for (int i = 0; i < 4; i++) {
        if (m8[i]) {
            n++;
        }
    }
    return n;
}

Unk802D73B4_Pad* Unk802D73B4_Mgr::fn_802D8490(int a)
{
    return m8[a];
}

void Unk802D73B4_Mgr::s2()
{
    fn_803FFC58(m8, 0, 16);
    fn_803FFC58(m18, 0, 16);
    int n = fn_80008540((Unk800085B0**)m8, 4);
    for (int i = 0; i < n; i++) {
        if (m8[i]) {
            fn_802D8B64(m8[i]);
            m18[i] = new (0) char[m8[i]->s41() * lbl_8061F674];
        }
    }
    m4 = 0;
    m0 = 0;
}

void Unk802D73B4_Mgr::s6()
{
    for (int i = 0; i < 4; i++) {
        Unk802D73B4_Pad* p = m8[i];
        lbl_8068DF34 = p;
        if (p) {
            p->s3();
        }
    }
}

void Unk802D73B4_Mgr::s7()
{
    for (int i = 0; i < 4; i++) {
        if (m8[i]) {
            m8[i]->s4();
        }
    }
}

void Unk802D73B4_Mgr::s13()
{
    for (int i = 0; i < 4; i++) {
        if (m8[i]) {
            int sz = m8[i]->s41();
            m8[i]->s42(m18[i] + m4 * sz);
        }
    }
    m4 = (m4 + 1) % lbl_8061F674;
}

void Unk802D73B4_Mgr::fn_802D8624(int a, int b)
{
    if (a == -1 || b == -1) {
        s13();
    } else {
        int sz = m8[a]->s41();
        m8[a]->s42(m18[a] + m4 * sz);
        if (b != a) {
            sz = m8[b]->s41();
            m8[b]->s42(m18[b] + m4 * sz);
        }
        m4 = (m4 + 1) % lbl_8061F674;
    }
}

int Unk802D73B4_Mgr::s14()
{
    if (m0 == m4) {
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        if (m8[i]) {
            int sz = m8[i]->s41();
            m8[i]->s43(m18[i] + m0 * sz);
            fn_802DC61C(m8[i]);
        }
    }
    m0 = (m0 + 1) % lbl_8061F674;
    return 1;
}

int Unk802D73B4_Mgr::s12(int a)
{
    if (m0 == m4) {
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        if (m8[i]) {
            char* buf = m18[i] + m0 * m8[i]->s41();
            if (a) {
                m8[i]->s43(buf);
            }
            fn_802DC61C(m8[i]);
        }
    }
    if (a) {
        m0 = (m0 + 1) % lbl_8061F674;
    }
    return 1;
}

/* near-miss: only the callee-saved registers are permuted (this/offset/&m8/buf in r28..r31) */
int Unk802D73B4_Mgr::fn_802D890C(int a, int b)
{
    if (m0 == m4) {
        return 0;
    }
    if (a == -1 || b == -1) {
        return s14();
    }
    char* buf = m18[a] + m0 * m8[a]->s41();
    if (fn_802DC5C0(m8[a]) == 0) {
        m8[a]->s43(buf);
    }
    fn_802DC61C(m8[a]);
    if (b != a) {
        buf = m18[b] + m0 * m8[b]->s41();
        if (fn_802DC5C0(m8[b]) == 0) {
            m8[b]->s43(buf);
        }
        fn_802DC61C(m8[b]);
    }
    m0 = (m0 + 1) % lbl_8061F674;
    return 1;
}

void Unk802D73B4_Mgr::fn_802D8A84()
{
    for (int i = 0; i < 4; i++) {
        Unk802D73B4_Pad* p = m8[i];
        if (p) {
            fn_802DC8E4(p);
        }
    }
}

void Unk802D73B4_Mgr::fn_802D8AD8(int a, int b)
{
    if (a == -1 || b == -1) {
        for (int i = 0; i < 4; i++) {
            if (m8[i]) {
                fn_802DC974(m8[i]);
            }
        }
    } else {
        fn_802DC974(m8[a]);
        fn_802DC974(m8[b]);
    }
}

int Unk802D73B4_Mgr::s5(int* a)
{
    return 1;
}
