/*
 * Game code, .text 0x800928B0-0x80094578 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 * Table-manager classes (strings name /mvp2004/source/common/database/tablemanager.cpp);
 * types in include/game/tu_80090880.h.
 */
#include "game/tu_80090880.h"

extern const char lbl_805B2CB0[];
extern const char lbl_805B5748[];

void Tbl800927D0::v3()
{
    if (m8)
        m8->v2(fn_80071814(m8));
}

int Tbl800927D0::v4()
{
    int id = fn_80071718(m8);
    if (id != -1) {
        m8->v2(id);
        fn_80377BEC(m0, id);
        return 1;
    }
    return 0;
}

void Tbl800927D0::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), mC, 0, 0, lbl_805B5748, 0x4E5);
    if (!m8)
        m8 = fn_8052D80C(operator new(0x28, 0), lbl_805B2CB0, m0, mC);
}

void Tbl800927D0::v6()
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

void Tbl800927D0::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
}

void Tbl800927D0::v14(Tbl800927D0* src)
{
    if (m8) {
        RecT* r = src->m8;
        for (int i = 0; i < src->RowCount(); i++) {
            if (!r->v5(0x9, i)) {
                int a, b;
                int id = fn_80071784(r, i);
                fn_80377E90(m0, &a, &b, id);
                char* p = r->m24 + i * 0x2C;
                RowRef* rr = fn_8052D9C0(m8, b);
                fn_8052DC94(rr, p);
            }
        }
    }
}

void Tbl800927D0::Extra(int a, int b)
{
    Fn90A24(a);
    int r = v13(a);
    fn_8052DC60(fn_8052D9C0(m8, r), b);
}

Tbl80092C94::Tbl80092C94(const char* name, int c) : m8(0)
{
    fn_8040B61C(m10, name);
    mC = c;
}

Tbl80092C94::~Tbl80092C94() { v6(); }

int Tbl80092C94::v2()
{
    if (m8)
        fn_800716BC(m8);
    if (m0)
        m0->m4 = 0;
}

void Tbl80092C94::v3()
{
    if (m8)
        m8->v2(fn_80071814(m8));
}

int Tbl80092C94::v4()
{
    int id = fn_80071718(m8);
    if (id != -1) {
        m8->v2(id);
        fn_80377BEC(m0, id);
        return 1;
    }
    return 0;
}

void Tbl80092C94::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), mC, 0, 0, lbl_805B5748, 0x59F);
    if (!m8)
        m8 = fn_8052FF10(operator new(0x28, 0), m10, m0, mC);
}

void Tbl80092C94::v6()
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

void Tbl80092C94::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
}

void Tbl80092C94::v14(Tbl80092C94* src)
{
    if (m8) {
        RecT* r = src->m8;
        for (int i = 0; i < src->RowCount(); i++) {
            int id = fn_80071784(r, i);
            Fn90A24(id);
            int j = v13(id);
            RowRef* rr = fn_80530EFC(r, i);
            fn_80530F0C(m8->m24 + j * 0x2C, rr);
        }
    }
}

Tbl800930F4::Tbl800930F4(int c) : m8(0), mC(c) {}

Tbl800930F4::~Tbl800930F4() { v6(); }

int Tbl800930F4::v2()
{
    if (m8)
        fn_800716BC(m8);
    if (m0)
        m0->m4 = 0;
}

void Tbl800930F4::v3()
{
    if (m8)
        m8->v2(fn_80071814(m8));
}

int Tbl800930F4::v4()
{
    int id = fn_80071718(m8);
    if (id != -1) {
        m8->v2(id);
        fn_80377BEC(m0, id);
        return 1;
    }
    return 0;
}

void Tbl800930F4::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), mC, 0, 0, lbl_805B5748, 0x648);
    if (!m8)
        m8 = fn_80530D38(operator new(0x28, 0), lbl_805B2CB0, m0, mC);
}

void Tbl800930F4::v6()
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

void Tbl800930F4::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
}

void Tbl800930F4::v14(Tbl800930F4* src)
{
    if (m8) {
        RecT* r = src->m8;
        for (int i = 0; i < src->RowCount(); i++) {
            if (!r->v5(0x9, i)) {
                int a, b;
                int id = fn_80071784(r, i);
                fn_80377E90(m0, &a, &b, id);
                char* p = r->m24 + i * 0x2C;
                RowRef* rr = fn_80530EEC(m8, b);
                fn_805311D8(rr, p);
            }
        }
    }
}

void Tbl800930F4::Extra(int a, int b)
{
    Fn90A24(a);
    int r = v13(a);
    fn_805311A4(fn_80530EEC(m8, r), b);
}

Tbl800935B8::Tbl800935B8(const char* name, int c) : m8(0)
{
    fn_8040B61C(m10, name);
    mC = c;
}

Tbl800935B8::~Tbl800935B8() { v6(); }

int Tbl800935B8::v2()
{
    if (m8)
        fn_800716BC(m8);
    if (m0)
        m0->m4 = 0;
}

void Tbl800935B8::v3()
{
    if (m8)
        m8->v2(fn_80071814(m8));
}

int Tbl800935B8::v4()
{
    int id = fn_80071718(m8);
    if (id != -1) {
        m8->v2(id);
        fn_80377BEC(m0, id);
        return 1;
    }
    return 0;
}

void Tbl800935B8::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), mC, 0, 0, lbl_805B5748, 0x702);
    if (!m8)
        m8 = fn_8053CC9C(operator new(0x28, 0), m10, m0, mC);
}

void Tbl800935B8::v6()
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

void Tbl800935B8::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
}

void Tbl800935B8::v14(Tbl800935B8* src)
{
    if (m8) {
        RecT* r = src->m8;
        for (int i = 0; i < src->RowCount(); i++) {
            int id = fn_80071784(r, i);
            Fn90A24(id);
            int j = v13(id);
            RowRef* rr = fn_8053DB20(r, i);
            fn_8053DB30(m8->m24 + j * 0x2C, rr);
        }
    }
}

Tbl80093A18::Tbl80093A18(int c) : m8(0), mC(c) {}

Tbl80093A18::~Tbl80093A18() { v6(); }

int Tbl80093A18::v2()
{
    if (m8)
        fn_800716BC(m8);
    if (m0)
        m0->m4 = 0;
}

void Tbl80093A18::v3()
{
    if (m8)
        m8->v2(fn_80071814(m8));
}

int Tbl80093A18::v4()
{
    int id = fn_80071718(m8);
    if (id != -1) {
        m8->v2(id);
        fn_80377BEC(m0, id);
        return 1;
    }
    return 0;
}

void Tbl80093A18::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), mC, 0, 0, lbl_805B5748, 0x7AB);
    if (!m8)
        m8 = fn_8053D95C(operator new(0x28, 0), lbl_805B2CB0, m0, mC);
}

void Tbl80093A18::v6()
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

void Tbl80093A18::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
}

void Tbl80093A18::v14(Tbl80093A18* src)
{
    if (m8) {
        RecT* r = src->m8;
        for (int i = 0; i < src->RowCount(); i++) {
            if (!r->v5(0x3, i)) {
                int a, b;
                int id = fn_80071784(r, i);
                fn_80377E90(m0, &a, &b, id);
                char* p = r->m24 + i * 0x2C;
                RowRef* rr = fn_8053DB10(m8, b);
                fn_8053DD68(rr, p);
            }
        }
    }
}

void Tbl80093A18::Extra(int a, int b)
{
    Fn90A24(a);
    int r = v13(a);
    fn_8053DD34(fn_8053DB10(m8, r), b);
}

Tbl80093EDC::Tbl80093EDC(const char* name, int c) : m8(0)
{
    fn_8040B61C(m10, name);
    mC = c;
}

Tbl80093EDC::~Tbl80093EDC() { v6(); }

int Tbl80093EDC::v2()
{
    if (m8)
        fn_800716BC(m8);
    if (m0)
        m0->m4 = 0;
}

void Tbl80093EDC::v3()
{
    if (m8)
        m8->v2(fn_80071814(m8));
}

int Tbl80093EDC::v4()
{
    int id = fn_80071718(m8);
    if (id != -1) {
        m8->v2(id);
        fn_80377BEC(m0, id);
        return 1;
    }
    return 0;
}

void Tbl80093EDC::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), mC, 0, 0, lbl_805B5748, 0x865);
    if (!m8)
        m8 = fn_805989A0(operator new(0x28, 0), m10, m0, mC);
}

void Tbl80093EDC::v6()
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

void Tbl80093EDC::v10(int a, TblBase* b)
{
    if (!b->v2() && !b->m0)
        v2();
    m0->v4(a, b);
    m8->v11(a, b);
}

void Tbl80093EDC::v14(Tbl80093EDC* src)
{
    if (m8) {
        RecT* r = src->m8;
        for (int i = 0; i < src->RowCount(); i++) {
            int id = fn_80071784(r, i);
            Fn90A24(id);
            int j = v13(id);
            RowRef* rr = fn_805997B4(r, i);
            fn_805997C4(m8->m24 + j * 0x28, rr);
        }
    }
}

Tbl8009433C::Tbl8009433C(int c) : m8(0), mC(c) {}

Tbl8009433C::~Tbl8009433C() { v6(); }

int Tbl8009433C::v2()
{
    if (m8)
        fn_800716BC(m8);
    if (m0)
        m0->m4 = 0;
}

void Tbl8009433C::v3()
{
    if (m8)
        m8->v2(fn_80071814(m8));
}

int Tbl8009433C::v4()
{
    int id = fn_80071718(m8);
    if (id != -1) {
        m8->v2(id);
        fn_80377BEC(m0, id);
        return 1;
    }
    return 0;
}

void Tbl8009433C::v5()
{
    if (!m0)
        m0 = fn_803779B8(operator new(0x18, 0), mC, 0, 0, lbl_805B5748, 0x90E);
    if (!m8)
        m8 = fn_805995F0(operator new(0x28, 0), lbl_805B2CB0, m0, mC);
}
