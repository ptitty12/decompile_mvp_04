/*
 * Game code, .text 0x8006902C-0x8006D05C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8006902C.h"
#include "game/tu_8007A4DC.h"
extern Unk8007A4DC_Screen* lbl_8061930C;

void* operator new(unsigned int size, int heap);
void fn_8007824C(void* a, Unk80069F0C* b);
void fn_80089108(void* a, int b);
void fn_80080BFC(Unk8006902C_Players* p);
void fn_80080CEC(Unk8006902C_Players* p);
void fn_803539B8(Unk8006902C_Handle* h);
void fn_8006F6C0(Unk8006902C_Ctx* c);
void fn_8006F74C(Unk8006902C_Ctx* c);
int fn_80329FA0(int* out, int c, ...);
void fn_80081CCC(Unk8006902C_Players* p, int i);
void fn_80081D70(Unk8006902C_Players* p);
void fn_8037893C(int a, int b, int c, int d, int e);
void fn_8031883C(int a);
int fn_800968C0(Unk8006902C_Side* s, int e, int k);
int fn_80097A9C(Unk8006902C_Side* s, int a, int b, int c, int d);
int fn_800971C8(Unk8006902C_Side* s, int r);
int fn_80099704(Unk8006902C_Side* s);
int fn_80099670(Unk8006902C_Side* s);
void fn_80097174(Unk8006902C_Side* s, int r, int k);
int fn_80099620(Unk8006902C_Side* s);
int fn_8014D8AC(Unk8014D81C_Obj* o, int size, const char* file, int line);
extern const char lbl_805B39E0[];
void fn_8008D850(void* attrs, int k, int id, int v);
int fn_8006FB28(void* l, int k, int c);
unsigned char* fn_80081D08(Unk8006902C_Players* p, int k);
void fn_8006FC40(void* l, int k, int c, int v);
struct Unk8061FEDC {
    char pad0[0x3C];
    int m3C;
};
extern Unk8061FEDC* lbl_8061FEDC;
extern char lbl_8064A1B8[];
extern char lbl_80649DB8[];
void fn_803785E4(Unk80069F0C* self, Unk8006902C_Ctx* a);
void fn_80378620(Unk80069F0C* self, int chrg);
void fn_8006F4D0(Unk8006902C_Handle* h);
void fn_8014D81C(Unk8014D81C_Obj* p);
Unk8006902C_Mode* fn_80086210(void* p);

inline int SumBytes(Unk8006902C_Side* s)
{
    int t = 0;
    int i;
    for (i = 0; i < 0x80; i++)
        t += s->m1B4[(unsigned char)i];
    return t;
}

int fn_80075808(int id);
void fn_80080DBC(Unk8006902C_Players* p);
int fn_8008CFD8(void* attrs, int k, unsigned char j);
void fn_80096EE8(Unk8006902C_Side* s, int a, int b);

void fn_80069EE0(void)
{
    fn_8006902C(1, 0xFFFF);
}

/* near-miss: 2 slots; retail computes this+0x28 (r29) before the root-ctor call, ours after it. */
Unk80069F0C* Unk80069F0C::fn_80069F0C(Unk8006902C_Ctx* a)
{
    Unk8014D81C_Obj* p = &m28;
    fn_803785E4(this, a);
    m8 = lbl_8064A1B8;
    mC = a;
    m10 = 0;
    fn_8006F4D0(&m14);
    fn_8014D81C(p);
    fn_8014D81C(p);
    if (m10 == 0)
        m10 = fn_80086210(operator new(0x3A0, 0));
    fn_8006A004();
    return this;
}

void Unk80069F0C::fn_80069F9C(int chrg)
{
    m8 = lbl_8064A1B8;
    if (m10) {
        delete m10;
        m10 = 0;
    }
    m8 = lbl_80649DB8;
    fn_80378620(this, chrg);
}

void Unk80069F0C::fn_8006A004()
{
    Unk8006902C_Handle* h = &m14;
    fn_80080BFC(h->m0);
    fn_803539B8(h);
    fn_8006F6C0(mC);
    fn_8006C064();
    if (lbl_8061FEDC)
        fn_8031883C(lbl_8061FEDC->m3C);
    m24 = 0;
}

void Unk80069F0C::fn_8006A070()
{
    Unk8006902C_Handle* h = &m14;
    fn_80080CEC(h->m0);
    fn_803539B8(h);
    fn_8006F74C(mC);
    fn_8006C064();
    fn_8006C698();
}

void Unk80069F0C::fn_8006A0C4(int a, int b, int c, int d)
{
    Unk8006902C_Ctx* t = mC;
    int out;
    fn_80329FA0(&out, c);
    t->m7C = out;
    mC->m84 = a;
    mC->m88 = b;
    mC->m80 = d;
}

void Unk80069F0C::fn_8006A12C(int a)
{
    mC->m80 = a;
}

int Unk80069F0C::fn_8006A138()
{
    int ok = 1;
    Unk8006A138_It<1> it(0);
    int idx = 0;
    while (idx <= 1) {
        if (!fn_80075808(SideAt(idx * 0xE64)->m198))
            ok = 0;
        idx = it.Next();
    }
    return ok;
}

/* near-miss: 2 slots; retail compares 12 before 13 (cmpwi 12; beq; cmpwi 13), the switch tree tests 13 first. */
int Unk80069F0C::fn_8006A1B4()
{
    switch (m10->m22C) {
    case 0xC:
    case 0xD:
        return fn_8006A138();
    }
    return 0;
}

int Unk80069F0C::fn_8006A214()
{
    return this == mC->m20;
}

void Unk80069F0C::fn_8006A22C()
{
    mC->m20 = this;
}

int Unk80069F0C::fn_8006A238(int idx)
{
    Unk8006902C_Side* s = &m14.m0->s[idx];
    int total = 0;
    int i;
    for (i = 0; i < s->m235; ) {
        int e = s->m238[(unsigned char)i].m0;
        i++;
        total += fn_80097A9C(s, 0, fn_800968C0(s, e, 1), 2, 0);
    }
    return total;
}

/* near-miss: 3 slots; the order of the argument moves for the two fn_8007A94C calls differs. */
void Unk80069F0C::fn_8006B880()
{
    Unk8007A4DC_Screen* o = lbl_8061930C;
    Unk8006A138_It<1> it(0);
    int idx = 0;
    while (idx <= 1) {
        Unk8006902C_Side* sd = SideAt(idx * 0xE64);
        unsigned char j = 0;
        unsigned char n = sd->m3E4;
        for (; j < n; j++) {
            char* attrs = sd->mC9C;
            int a = fn_8008CFD8(attrs, 0x1E, j);
            int b = fn_8008CFD8(attrs, 0x1F, j);
            if (a != 0 && a != 0x31 && b > 0) {
                Unk8006902C_Rec* rr = sd->m3E8;
                int off = j * 0x34;
                int e = o->fn_8007A11C(*(int*)((char*)rr + off));
                o->fn_8007A94C(0x1E, e, a);
                o->fn_8007A94C(0x1F, e, b);
            }
        }
        idx = it.Next();
    }
}

void Unk80069F0C::fn_8006B990()
{
    Unk8007A4DC_Screen* o = lbl_8061930C;
    Unk8006A138_It<1> it(0);
    int idx = 0;
    while (idx <= 1) {
        int id = SideAt(idx * 0xE64)->m198;
        unsigned char j = 0;
        unsigned n = o->fn_8007F198(id);
        for (; j < n; j++) {
            int e = o->fn_8007A11C(o->fn_8007F24C(id, j));
            if (o->fn_8007A8DC(0x1E, e) == 0x31)
                o->fn_8007A94C(0x1F, e, o->fn_8007A8DC(0x1F, e) - 1);
        }
        idx = it.Next();
    }
}

int Unk80069F0C::fn_8006BDCC()
{
    int r = 0;
    if (m14.m0->GetC9() > 2 || fn_8006BE18() == 1)
        r = 1;
    return r;
}

/* near-miss: ~50 slots; the sums, the cror-based >= and the return chain are right,
 * but register allocation of the three flags (r5/r4/r12 in retail) differs. */
int Unk80069F0C::fn_8006BE18()
{
    Unk8006902C_Players* p = m14.m0;
    int c = 0;
    int a = p->m1CC8 >= m10->m1C - 1;
    if (p->m1CD0 == 0 || p->GetC9() > 2)
        c = 1;
    int d = 0;
    int lim = 3;
    if (p->m1CD0 == 0)
        d = p->GetC9() >= lim;
    int s0 = 0;
    int i;
    for (i = 0; i < 0x80; i++)
        s0 += p->s[0].m1B4[(unsigned char)i];
    int s1 = 0;
    int j;
    for (j = 0; j < 0x80; j++)
        s1 += p->s[1].m1B4[(unsigned char)j];
    if (a == 1) {
        if (d == 1)
            return s0 != s1;
        if (c == 1 && s0 > s1)
            return 1;
        return 0;
    }
    return 0;
}

/* near-miss: 17 slots; the second SumBytes loop uses r10/r11 where retail reuses r8/r10,
 * and the final return arms are laid out in the other order. */
int Unk80069F0C::fn_8006BF10()
{
    Unk8006902C_Players* p = m14.m0;
    if (p->GetC8() <= 0 && p->m1CD0 != 0) {
        if (SumBytes(&p->s[1]) <= 0) {
            if (SumBytes(&p->s[0]) > 0 || p->GetC9() > 0 || p->GetCB() > 0 || p->GetCA() > 0
                || *fn_80081D08(p, 0) != 0xFF || *fn_80081D08(m14.m0, 1) != 0xFF
                || *fn_80081D08(m14.m0, 2) != 0xFF)
                return 1;
            return 0;
        }
    }
    return 1;
}

void Unk80069F0C::fn_8006C02C()
{
    m54 = 0;
}

void Unk80069F0C::fn_8006C038(void* a)
{
    fn_8007824C(a, this);
}

void Unk80069F0C::fn_8006C064()
{
    m44 = 0;
    m48 = -1;
    m4C = 0;
    m50 = 0;
    m54 = 0;
    m58 = 0;
}

void Unk80069F0C::fn_8006C088(Unk8006902C_EvC088* ev)
{
    int off = ev->m18 * 0xE64;
    int id = ev->m14;
    if (SideAt(off)->m234 != 0) {
        int lo = ev->mC;
        int a = ev->m8;
        int n = ev->m10 - lo;
        int hi;
        if (n > 0)
            hi = lo + fn_8014D8AC(&m28, n, lbl_805B39E0, 0x4C0);
        else
            hi = lo;
        unsigned char r = fn_800968C0(SideAt(off), id, 1);
        fn_8008D850(SideAt(off)->mC9C, 0x1E, r, a);
        fn_8008D850(SideAt(off)->mC9C, 0x1F, r, hi);
        fn_80097174(SideAt(off), r, 1);
        SideAt(off)->m234--;
    }
}

void Unk80069F0C::fn_8006C17C(Unk8006902C_EvC17C* ev)
{
    Unk8006902C_Side* s = &m14.m0->s[ev->mC];
    int r = fn_800968C0(s, ev->m8, 1);
    int ok;
    if (fn_800971C8(s, r) == 1)
        ok = fn_80099704(s);
    else
        ok = fn_80099670(s);
    if (ok) {
        fn_80097174(s, r, 3);
        if (fn_80099620(s) == 0)
            s->m234 = 0;
    }
}

void Unk80069F0C::fn_8006C698()
{
    fn_80080DBC(m14.m0);
    Unk8006A138_It<1> it(0);
    int idx = 0;
    while (idx <= 1) {
        Unk8006902C_Side* sd = SideAt(idx * 0xE64);
        if (sd->m198 != 0)
            fn_80096EE8(sd, m10->m74, m10->m22C);
        idx = it.Next();
    }
    Unk8006902C_Mode* md = m10;
    int x = md->m74;
    if ((unsigned)(x - 5) > 1 && x != 1 && md->m1C <= 8)
        mC->m600 = 1;
    m58 = 1;
}

void Unk80069F0C::fn_8006C75C(Unk8006902C_Ev75C* ev)
{
    fn_80081CCC(m14.m0, 0);
    fn_80081CCC(m14.m0, 1);
    fn_80081CCC(m14.m0, 2);
    fn_80081D70(m14.m0);
    m14.m0->m1CC9 = 0;
    if (m14.m0->m1CD0 == 1)
        fn_8037893C(ev->m8, 0x2C, 0, 0, 0);
}

void Unk80069F0C::fn_8006C7E8(int a)
{
    fn_80089108(mC->mC, a);
}

void Unk80069F0C::fn_8006C810(Unk8006902C_Ev75C* ev)
{
    fn_80081CCC(m14.m0, 0);
    fn_80081CCC(m14.m0, 1);
    fn_80081CCC(m14.m0, 2);
    Unk8006902C_Players* p = m14.m0;
    int si = p->m1CD0 == 0;
    Unk8006A138_It<9> it(0);
    Unk8006902C_Side* sd = &p->s[si];
    int j = 0;
    while (j <= 9) {
        int k = sd->m17C[j];
        if (k != 0xFF)
            sd->m3E8[k].mC[j]++;
        j = it.Next();
    }
    int r = fn_8006BE18();
    if (r == 0) {
        fn_80081D70(m14.m0);
        m14.m0->m1CC9 = r;
        int t = m14.m0->m1CD0 == 0;
        if (t == 1) {
            fn_8037893C(ev->m8, 0x35, 0, 0, 0);
            m14.m0->m1CD0 = t;
        } else
            m14.m0->m1CD0 = r;
    }
}

void Unk80069F0C::fn_8006C930()
{
    if (fn_8006BE18() == 0)
        m14.m0->m1CC8++;
}

/* near-miss: 4 slots; retail keeps the m14 pointer in a caller-saved register. */
void Unk80069F0C::fn_8006CFA4(Unk8006902C_EvCFA4* ev)
{
    int side = 0;
    if (m14.m0->m1CD0 != 0)
        side = 1;
    unsigned char c = ev->m13;
    Unk8006902C_Side* sd = &m14.m0->s[side];
    void* l = sd->m92C;
    fn_8006FC40(l, 1, c, fn_8006FB28(l, 1, c) + 1);
    if (ev->m8 == 3)
        ((unsigned char*)sd + c * 0x34)[0x3F2]++;
    fn_8006EC94(c, 9);
    fn_8006EC94(c, 2);
}
