/*
 * Game code, .text 0x80094578-0x800975A8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 * Table-manager classes (strings name /mvp2004/source/common/database/tablemanager.cpp)
 * then a game-object class with an 0x34-stride record array; types in include/game/tu_80090880.h.
 */
#include "game/tu_80090880.h"

extern const char lbl_805B2CB0[];
extern const char lbl_805B5748[];
extern const char lbl_805B57A8[];
extern const char lbl_805B57B4[];
extern const char lbl_805B57C4[];
extern const char lbl_805B57D4[];
extern const char lbl_805B57E0[];
extern const char lbl_805B57F0[];
extern const char lbl_805B5800[];
extern const char lbl_805B580C[];
extern const char lbl_805B581C[];
extern const char lbl_805B5828[];
extern const char lbl_805B5834[];
extern const char lbl_805B5840[];
extern const char lbl_805B5850[];
extern const char lbl_805B5860[];

void Tbl8009433C::v6()
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

void Tbl8009433C::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
}

void Tbl8009433C::v14(Tbl8009433C* src)
{
    if (m8) {
        RecT* r = src->m8;
        for (int i = 0; i < src->RowCount(); i++) {
            if (!r->v5(0x6, i)) {
                int a, b;
                int id = fn_80071784(r, i);
                fn_80377E90(m0, &a, &b, id);
                char* p = r->m24 + i * 0x28;
                RowRef* rr = fn_805997A4(m8, b);
                fn_805999E8(rr, p);
            }
        }
    }
}

void Tbl8009433C::Extra(int a, int b)
{
    Fn90A24(a);
    int r = v13(a);
    fn_805999B4(fn_805997A4(m8, r), b);
}

Tbl80094800::Tbl80094800() : m8(0), m40(0)
{
    unsigned i;
    for (i = 0; i <= 1; i++)
        mC[i] = 0;
    for (i = 0; i <= 1; i++) {
        m14[i].a = 0;
        for (int j = 0; j < 2; j++)
            m14[i].b[j] = 0;
    }
    for (int i = 0; i < 5; i++)
        m2C[i] = 0;
}

Tbl80094800::~Tbl80094800() { v6(); }

int Tbl80094800::v2()
{
    for (int i = 0; i < 2; i++) {
        fn_800716BC(m14[i].a);
        for (int j = 0; j < 2; j++)
            fn_800716BC(m14[i].b[j]);
    }
    for (int i = 0; i < 5; i++)
        fn_800716BC(m2C[i]);
    fn_800716BC(m40);
    m0->m4 = 0;
}

void Tbl80094800::v3(int a)
{
    for (int i = 0; i < 2; i++) {
        m14[i].a->v2(fn_80071814(m14[i].a, a));
        for (int j = 0; j < 2; j++)
            m14[i].b[j]->v2(fn_80071814(m14[i].b[j], a));
    }
    for (int i = 0; i < 5; i++)
        m2C[i]->v2(fn_80071814(m2C[i], a));
    m40->v2(fn_80071814(m40, a));
}

int Tbl80094800::v4()
{
    int id = fn_80071718(m8);
    if (id != -1) {
        m8->v2(id);
        for (int i = 0; i < 2; i++)
            mC[i]->v2(id);
        for (int i = 0; i < 2; i++) {
            m14[i].a->v2(id);
            for (int j = 0; j < 2; j++)
                m14[i].b[j]->v2(id);
        }
        for (int i = 0; i < 5; i++)
            m2C[i]->v2(id);
        m40->v2(id);
        fn_80377BEC(m0, id);
        return 1;
    }
    return 0;
}

void Tbl80094800::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), 0xcb2, 0, 0, lbl_805B5748, 0xa0d);
    if (!m8)
        m8 = fn_8008CAF8(operator new(0x28, 0), lbl_805B57A8, m0, 0xcb2);
    if (!mC[0])
        mC[0] = fn_8008EA7C(operator new(0x28, 0), lbl_805B57B4, m0, 0xcb2);
    if (!mC[1])
        mC[1] = fn_8008EA7C(operator new(0x28, 0), lbl_805B57C4, m0, 0xcb2);
    if (!m14[0].a)
        m14[0].a = fn_8006F9FC(operator new(0x28, 0), lbl_805B2CB0, m0, 0xcb2);
    if (!m14[1].a)
        m14[1].a = fn_8006F9FC(operator new(0x28, 0), lbl_805B57D4, m0, 0xcb2);
    if (!m14[0].b[0])
        m14[0].b[0] = fn_8006FE88(operator new(0x28, 0), lbl_805B2CB0, m0, 0xcb2);
    if (!m14[0].b[1])
        m14[0].b[1] = fn_8006FE88(operator new(0x28, 0), lbl_805B2CB0, m0, 0xcb2);
    if (!m14[1].b[0])
        m14[1].b[0] = fn_8006FE88(operator new(0x28, 0), lbl_805B57E0, m0, 0xcb2);
    if (!m14[1].b[1])
        m14[1].b[1] = fn_8006FE88(operator new(0x28, 0), lbl_805B57F0, m0, 0xcb2);
    if (!m2C[0])
        m2C[0] = fn_800805FC(operator new(0x28, 0), lbl_805B2CB0, m0, 0xcb2);
    if (!m2C[1])
        m2C[1] = fn_800805FC(operator new(0x28, 0), lbl_805B5800, m0, 0xcb2);
    if (!m2C[2])
        m2C[2] = fn_800805FC(operator new(0x28, 0), lbl_805B580C, m0, 0xcb2);
    if (!m2C[3])
        m2C[3] = fn_800805FC(operator new(0x28, 0), lbl_805B580C, m0, 0xcb2);
    if (!m2C[4])
        m2C[4] = fn_800805FC(operator new(0x28, 0), lbl_805B580C, m0, 0xcb2);
    if (!m40)
        m40 = fn_80071020(operator new(0x28, 0), lbl_805B581C, m0, 0xcb2);
}

void Tbl80094800::v6()
{
    unsigned i = 0;
    int j;
    if (m0) {
        delete m0;
        m0 = 0;
    }
    if (m8) {
        delete m8;
        m8 = 0;
    }
    for (i = 0; i <= 1; i++) {
        if (mC[i]) {
            delete mC[i];
            mC[i] = 0;
        }
    }
    for (i = 0; i <= 1; i++) {
        if (m14[i].a) {
            delete m14[i].a;
            m14[i].a = 0;
        }
        for (j = 0; j < 2; j++) {
            if (m14[i].b[j]) {
                delete m14[i].b[j];
                m14[i].b[j] = 0;
            }
        }
    }
    for (i = 0; i <= 4; i++) {
        if (m2C[i]) {
            delete m2C[i];
            m2C[i] = 0;
        }
    }
    if (m40) {
        delete m40;
        m40 = 0;
    }
}

void Tbl80094800::v7()
{
    unsigned i = 0;
    v2();
    m8->v10();
    mC[0]->v10();
    mC[1]->v10();
    m14[1].a->v10();
    m14[1].b[1]->v10();
    m14[1].b[0]->v10();
    m2C[1]->v10();
    m40->v10();
    unsigned n = m0->m4;
    int x = m8->v3(0x1D);
    while (i < n) {
        m8->v8(0x1D, i, x);
        m8->v8(0x1C, i, 0);
        i++;
    }
}

void Tbl80094800::v8()
{
    Grp3 t = m14[0];
    m14[0] = m14[1];
    m14[1] = t;
    Rec* u = m2C[0];
    m2C[0] = m2C[1];
    m2C[1] = u;
    char buf[0x14];
    fn_8040B61C(buf, (char*)m14[0].a);
    fn_8040B61C((char*)m14[1].a, buf);
    const char* e = lbl_805B2CB0;
    fn_8040B61C((char*)m14[0].a, e);
    fn_8040B61C(buf, (char*)m14[0].b[1]);
    fn_8040B61C((char*)m14[1].b[1], buf);
    fn_8040B61C((char*)m14[0].b[1], e);
    fn_8040B61C(buf, (char*)m14[0].b[0]);
    fn_8040B61C((char*)m14[1].b[0], buf);
    fn_8040B61C((char*)m14[0].b[0], e);
    fn_8040B61C(buf, (char*)m2C[0]);
    fn_8040B61C((char*)m2C[1], buf);
    fn_8040B61C((char*)m2C[0], e);
    v9();
}

void Tbl80094800::v9()
{
    for (int i = 1; i < 2; i++) {
        fn_800716BC(m14[i].a);
        for (int j = 0; j < 2; j++)
            fn_800716BC(m14[i].b[j]);
    }
    for (int i = 1; i < 5; i++)
        fn_800716BC(m2C[i]);
}

void Tbl80094800::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
    for (int i = 0; i < 2; i++)
        mC[i]->v11(a, b);
    for (int i = 0; i < 2; i++) {
        m14[i].a->v11(a, b);
        for (int j = 0; j < 2; j++)
            m14[i].b[j]->v11(a, b);
    }
    for (int i = 0; i < 5; i++)
        m2C[i]->v11(a, b);
    m40->v11(a, b);
}

int Tbl80094800::Fn956B8(int a, int b) { return Fn90A90(a, b); }

Tbl800956D8::Tbl800956D8() : m8(0), m24(0)
{
    for (int i = 0; i < 2; i++) {
        mC[i].a = 0;
        for (int j = 0; j < 2; j++)
            mC[i].b[j] = 0;
    }
}

Tbl800956D8::~Tbl800956D8() { v6(); }

int Tbl800956D8::v2()
{
    if (m8)
        fn_800716BC(m8);
    for (int i = 0; i < 2; i++) {
        if (mC[i].a)
            fn_800716BC(mC[i].a);
        for (int j = 0; j < 2; j++) {
            if (mC[i].b[j])
                fn_800716BC(mC[i].b[j]);
        }
    }
    fn_800716BC(m24);
    m0->m4 = 0;
}

void Tbl800956D8::v3(int a)
{
    if (m8)
        m8->v2(fn_80071814(m8, a));
    for (int i = 0; i < 2; i++) {
        if (mC[i].a)
            mC[i].a->v2(fn_80071814(mC[i].a, a));
        for (int j = 0; j < 2; j++) {
            if (mC[i].b[j])
                mC[i].b[j]->v2(fn_80071814(mC[i].b[j], a));
        }
    }
    m24->v2(fn_80071814(m24, a));
}

int Tbl800956D8::v4()
{
    int id = fn_80071718(m8);
    if (id != -1) {
        m8->v2(id);
        for (int i = 0; i < 2; i++) {
            mC[i].a->v2(id);
            for (int j = 0; j < 2; j++)
                mC[i].b[j]->v2(id);
        }
        m24->v2(id);
        fn_80377BEC(m0, id);
        return 1;
    }
    return 0;
}

void Tbl800956D8::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), 0x708, 0, 0, lbl_805B5748, 0xb68);
    if (!m8)
        m8 = fn_800897B8(operator new(0x28, 0), lbl_805B5828, m0, 0x708);
    if (!mC[0].a)
        mC[0].a = fn_8008B254(operator new(0x28, 0), lbl_805B2CB0, m0, 0x708);
    if (!mC[1].a)
        mC[1].a = fn_8008B254(operator new(0x28, 0), lbl_805B5834, m0, 0x708);
    if (!mC[0].b[1])
        mC[0].b[1] = fn_8008BDDC(operator new(0x28, 0), lbl_805B2CB0, m0, 0x708);
    if (!mC[0].b[0])
        mC[0].b[0] = fn_8008BDDC(operator new(0x28, 0), lbl_805B2CB0, m0, 0x708);
    if (!mC[1].b[1])
        mC[1].b[1] = fn_8008BDDC(operator new(0x28, 0), lbl_805B5840, m0, 0x708);
    if (!mC[1].b[0])
        mC[1].b[0] = fn_8008BDDC(operator new(0x28, 0), lbl_805B5850, m0, 0x708);
    if (!m24)
        m24 = fn_8008AB04(operator new(0x28, 0), lbl_805B5860, m0, 0x708);
}

void Tbl800956D8::v6()
{
    int i, j;
    if (m0) {
        delete m0;
        m0 = 0;
    }
    if (m8) {
        delete m8;
        m8 = 0;
    }
    for (i = 0; i < 2; i++) {
        if (mC[i].a) {
            delete mC[i].a;
            mC[i].a = 0;
        }
        for (j = 0; j < 2; j++) {
            if (mC[i].b[j]) {
                delete mC[i].b[j];
                mC[i].b[j] = 0;
            }
        }
    }
    if (m24) {
        delete m24;
        m24 = 0;
    }
}

void Tbl800956D8::v7()
{
    unsigned i = 0;
    v2();
    m8->v10();
    mC[1].a->v10();
    mC[1].b[1]->v10();
    mC[1].b[0]->v10();
    m24->v10();
    unsigned n = m0->m4;
    while (i < n) {
        int x = m8->v5(0, i);
        m8->v8(0x1B, i, x);
        i++;
    }
}

void Tbl800956D8::v8()
{
    Grp3 t = mC[0];
    mC[0] = mC[1];
    mC[1] = t;
    char buf[0x14];
    fn_8040B61C(buf, (char*)mC[0].a);
    fn_8040B61C((char*)mC[1].a, buf);
    const char* e = lbl_805B2CB0;
    fn_8040B61C((char*)mC[0].a, e);
    fn_8040B61C(buf, (char*)mC[0].b[1]);
    fn_8040B61C((char*)mC[1].b[1], buf);
    fn_8040B61C((char*)mC[0].b[1], e);
    fn_8040B61C(buf, (char*)mC[0].b[0]);
    fn_8040B61C((char*)mC[1].b[0], buf);
    fn_8040B61C((char*)mC[0].b[0], e);
    v9();
}

void Tbl800956D8::v9()
{
    for (int i = 1; i < 2; i++) {
        fn_800716BC(mC[i].a);
        fn_800716BC(mC[i].b[1]);
        fn_800716BC(mC[i].b[0]);
    }
}

void Tbl800956D8::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
    for (int i = 0; i < 2; i++) {
        mC[i].a->v11(a, b);
        for (int j = 0; j < 2; j++)
            mC[i].b[j]->v11(a, b);
    }
    m24->v11(a, b);
}
