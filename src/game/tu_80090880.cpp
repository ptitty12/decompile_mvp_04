/*
 * Game code, .text 0x80090880-0x800928B0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 * Table-manager classes (strings name /mvp2004/source/common/database/tablemanager.cpp);
 * types in include/game/tu_80090880.h.
 */
#include "game/tu_80090880.h"

extern const char lbl_805B2CB0[];
extern const char lbl_805B5734[];
extern const char lbl_805B5738[];
extern const char lbl_805B5748[];
extern const char lbl_805B577C[];
extern const char lbl_805B5784[];
extern const char lbl_805B5790[];
extern const char lbl_805B579C[];
extern char lbl_806877CC[];

char* fn_80090880(Unk80090880* p)
{
    char* s = p->m4;
    if (!s)
        s = p->m8;
    if (s) {
        char buf[0x80];
        char* r = fn_80402CAC(s);
        if (!r) {
            fn_804089B4(buf, lbl_805B5734);
            fn_804031BC(lbl_806877CC, buf);
            r = lbl_806877CC;
        }
        return r;
    }
    fn_804031BC(lbl_806877CC, lbl_805B5738);
    return 0;
}

TblBase::TblBase() : m0(0) {}

TblBase::~TblBase()
{
    if (m0) {
        delete m0;
        m0 = 0;
    }
}

int TblBase::v11(int a, DbObj* b)
{
    int tmp;
    int i = a;
    while (v12(i) == 1 || (b && fn_80377E04(b, &tmp, i)))
        i++;
    return i;
}

void TblBase::Fn90A24(int a)
{
    if (v12(a) != 1) {
        if (m0->m4 < m0->mC)
            fn_80377CD8(m0, m0->m4, m0->m4, a);
    }
}

int TblBase::Fn90A90(int key, int flag)
{
    int sp8, spC;
    int* sel = &sp8;
    int* other = sel;
    unsigned cnt = m0->m4;
    int result = 0;
    if (!flag)
        sel = &spC;
    for (unsigned i = 0; i < cnt; i++) {
        fn_80377DBC(m0, &spC, other, i);
        if (*sel == key) {
            result = *(int*)(m0->m0 + i * 12);
            break;
        }
    }
    return result;
}

Tbl80090B28::Tbl80090B28() : m8(0), mC(0), m10(0) {}

Tbl80090B28::~Tbl80090B28() { v6(); }

int Tbl80090B28::v2()
{
    if (m8)
        fn_800716BC(m8);
    if (mC)
        fn_800716BC(mC);
    if (m10)
        fn_8052FB70(m10);
    m0->m4 = 0;
}

void Tbl80090B28::v3(int a) {}

int Tbl80090B28::v4()
{
    int id = fn_80071718(m8);
    int ok;
    if (id == -1)
        ok = 0;
    else {
        m8->v2(id);
        mC->v2(id);
        fn_80377BEC(m0, id);
        ok = 1;
    }
    return ok;
}

void Tbl80090B28::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), 0x22, 0, 0, lbl_805B5748, 0x100);
    if (!m8)
        m8 = fn_8052E654(operator new(0x28, 0), lbl_805B577C, m0, 0x22);
    if (!mC)
        mC = fn_8052F454(operator new(0x28, 0), lbl_805B2CB0, m0, 0x22);
    if (!m10)
        m10 = fn_8052FA84(operator new(0xC, 0), 1);
}

void Tbl80090B28::v6()
{
    if (m0) {
        delete m0;
        m0 = 0;
    }
    if (m8) {
        delete m8;
        m8 = 0;
    }
    if (mC) {
        delete mC;
        mC = 0;
    }
    if (m10) {
        delete m10;
        m10 = 0;
    }
}

void Tbl80090B28::v7()
{
    v2();
    m8->v10();
    mC->v10();
    m10->v3();
}

void Tbl80090B28::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
    mC->v11(a, b);
    m10->v4(a, b);
}

Tbl8009101C::Tbl8009101C() : m8(0), mC(0), m18(0)
{
    for (int i = 0; i < 2; i++)
        m10[i] = 0;
}

Tbl8009101C::~Tbl8009101C() { v6(); }

int Tbl8009101C::v2()
{
    if (m8)
        fn_800716BC(m8);
    if (mC)
        fn_8053BE58(mC);
    for (int i = 0; i < 2; i++)
        fn_800716BC(m10[i]);
    if (m18)
        fn_800716BC(m18);
    m0->m4 = 0;
}

void Tbl8009101C::v3(int a) {}

int Tbl8009101C::v4()
{
    int id = fn_80071718(m8);
    if (id != -1) {
        m8->v2(id);
        for (int i = 0; i < 2; i++)
            m10[i]->v2(id);
        fn_8053B548(mC->m10 + id * 0x1E0, 0);
        m18->v2(id);
        fn_80377BEC(m0, id);
        return 1;
    }
    return 0;
}

void Tbl8009101C::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), 0x7E, 0, 0, lbl_805B5748, 0x1C7);
    if (!m8)
        m8 = fn_8009DCD4(operator new(0x28, 0), lbl_805B5784, m0, 0x7E);
    if (!mC)
        mC = fn_8053BB80(operator new(0x58, 0), lbl_805B5790, m0, 0x7E);
    if (!m10[0])
        m10[0] = fn_8009FCB8(operator new(0x28, 0), lbl_805B2CB0, m0, 0x7E);
    if (!m10[1])
        m10[1] = fn_8009FCB8(operator new(0x28, 0), lbl_805B579C, m0, 0x7E);
    if (!m18)
        m18 = fn_800A06A4(operator new(0x28, 0), lbl_805B2CB0, m0, 0x7E);
}

void Tbl8009101C::v6()
{
    if (m0) {
        delete m0;
        m0 = 0;
    }
    if (m8) {
        delete m8;
        m8 = 0;
    }
    if (mC) {
        delete mC;
        mC = 0;
    }
    for (int i = 0; i < 2; i++) {
        if (m10[i]) {
            delete m10[i];
            m10[i] = 0;
        }
    }
    if (m18) {
        delete m18;
        m18 = 0;
    }
}

void Tbl8009101C::v7()
{
    v2();
    m8->v10();
    fn_8053BEC8(mC);
    m10[0]->v10();
    m10[1]->v10();
    m18->v10();
}

void Tbl8009101C::v8()
{
    char buf[0x10];
    char* p = buf;
    Rec* t = m10[1];
    Rec* u = m10[0];
    m10[0] = t;
    m10[1] = u;
    fn_8040B61C(p, (char*)t);
    fn_8040B61C((char*)m10[1], p);
    const char* e = lbl_805B2CB0;
    fn_8040B61C((char*)m10[0], e);
    v9();
}

void Tbl8009101C::v9() { fn_800716BC(m10[1]); }

void Tbl8009101C::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
    mC->v2(a, b);
    m10[1]->v11(a, b);
    m10[0]->v11(a, b);
    m18->v11(a, b);
}

Tbl80091760::Tbl80091760(const char* name, int c) : m8(0)
{
    fn_8040B61C(m10, name);
    mC = c;
}

Tbl80091760::~Tbl80091760() { v6(); }

int Tbl80091760::v2()
{
    if (m8)
        fn_800716BC(m8);
    if (m0)
        m0->m4 = 0;
}

void Tbl80091760::v3(int a)
{
    if (m8)
        m8->v2(fn_80071814(m8, a));
}

int Tbl80091760::v4()
{
    int id = fn_80071718(m8);
    if (id != -1) {
        m8->v2(id);
        fn_80377BEC(m0, id);
        return 1;
    }
    return 0;
}

void Tbl80091760::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), mC, 0, 0, lbl_805B5748, 0x27D);
    if (!m8)
        m8 = (RecT*)fn_80084A10(operator new(0x28, 0), m10, m0, mC);
}

void Tbl80091760::v6()
{
    if (m0) {
        delete m0;
        m0 = 0;
    }
    if (m8) {
        delete m8;
        m8 = 0;
    }
}

void Tbl80091760::v7()
{
    v2();
    m8->v10();
    unsigned i = 0;
    while (i < RowCount()) {
        m8->v8(0x11, i, 1);
        i++;
    }
}

void Tbl80091760::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
}

void Tbl80091760::v14(Tbl80091760* src)
{
    if (m8) {
        RecT* r = src->m8;
        for (unsigned i = 0; i < src->RowCount(); i++) {
            int id = fn_80071784(r, i);
            Fn90A24(id);
            int j = v13(id);
            Row30* d = (Row30*)(m8->m24 + j * 0x30);
            Row30* s = (Row30*)(r->m24 + i * 0x30);
            *d = *s;
        }
    }
}

void Tbl80091760::v15(Tbl80091760* src)
{
    if (m8) {
        RecT* r = src->m8;
        for (int i = 0; i < src->RowCount(); i++) {
            int id = fn_80071784(r, i);
            Fn90A24(id);
            int j = v13(id);
            RowRef* rr = fn_80085C00(r, i);
            fn_80085C10(m8->m24 + j * 0x30, rr);
        }
    }
}

void Tbl80091760::v16(Tbl80091760* src)
{
    if (m8) {
        RecT* r = src->m8;
        for (int i = 0; i < src->RowCount(); i++) {
            if (r->v5(0x11, i)) {
                int a, b;
                int id = fn_80071784(r, i);
                fn_80377E90(m0, &a, &b, id);
                Row30* d = (Row30*)(m8->m24 + b * 0x30);
                Row30* s = (Row30*)(r->m24 + i * 0x30);
                *d = *s;
            }
        }
    }
}

Tbl80091EAC::Tbl80091EAC(int c) : m8(0), mC(c) {}

Tbl80091EAC::~Tbl80091EAC() { v6(); }

int Tbl80091EAC::v2()
{
    if (m8)
        fn_800716BC(m8);
    if (m0)
        m0->m4 = 0;
}

void Tbl80091EAC::v3(int a)
{
    if (m8)
        m8->v2(fn_80071814(m8, a));
}

int Tbl80091EAC::v4()
{
    int id = fn_80071718(m8);
    if (id != -1) {
        m8->v2(id);
        fn_80377BEC(m0, id);
        return 1;
    }
    return 0;
}

void Tbl80091EAC::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), mC, 0, 0, lbl_805B5748, 0x386);
    if (!m8)
        m8 = fn_80085A3C(operator new(0x28, 0), lbl_805B2CB0, m0, mC);
}

void Tbl80091EAC::v6()
{
    if (m0) {
        delete m0;
        m0 = 0;
    }
    if (m8) {
        delete m8;
        m8 = 0;
    }
}

void Tbl80091EAC::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
}

void Tbl80091EAC::v14(Tbl80091EAC* src)
{
    if (m8) {
        RecT* r = src->m8;
        for (int i = 0; i < src->RowCount(); i++) {
            if (!r->v5(0x11, i)) {
                int a, b;
                int id = fn_80071784(r, i);
                fn_80377E90(m0, &a, &b, id);
                char* p = r->m24 + i * 0x30;
                RowRef* rr = fn_80085BF0(m8, b);
                fn_80085F2C(rr, p);
            }
        }
    }
}

void Tbl80091EAC::Extra(int a, int b)
{
    Fn90A24(a);
    int r = v13(a);
    fn_80085EF8(fn_80085BF0(m8, r), b);
}

Tbl80092370::Tbl80092370(const char* name, int c) : m8(0)
{
    fn_8040B61C(m10, name);
    mC = c;
}

Tbl80092370::~Tbl80092370() { v6(); }

int Tbl80092370::v2()
{
    if (m8)
        fn_800716BC(m8);
    if (m0)
        m0->m4 = 0;
}

void Tbl80092370::v3(int a)
{
    if (m8)
        m8->v2(fn_80071814(m8, a));
}

int Tbl80092370::v4()
{
    int id = fn_80071718(m8);
    if (id != -1) {
        m8->v2(id);
        fn_80377BEC(m0, id);
        return 1;
    }
    return 0;
}

void Tbl80092370::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), mC, 0, 0, lbl_805B5748, 0x43C);
    if (!m8)
        m8 = fn_8052CA60(operator new(0x28, 0), m10, m0, mC);
}

void Tbl80092370::v6()
{
    if (m0) {
        delete m0;
        m0 = 0;
    }
    if (m8) {
        delete m8;
        m8 = 0;
    }
}

void Tbl80092370::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
}

void Tbl80092370::v14(Tbl80092370* src)
{
    if (m8) {
        RecT* r = src->m8;
        for (int i = 0; i < src->RowCount(); i++) {
            int id = fn_80071784(r, i);
            Fn90A24(id);
            int j = v13(id);
            RowRef* rr = fn_8052D9D0(r, i);
            fn_8052D9E0(m8->m24 + j * 0x2C, rr);
        }
    }
}

Tbl800927D0::Tbl800927D0(int c) : m8(0), mC(c) {}

Tbl800927D0::~Tbl800927D0() { v6(); }

int Tbl800927D0::v2()
{
    if (m8)
        fn_800716BC(m8);
    if (m0)
        m0->m4 = 0;
}
