/*
 * Game code, .text 0x80094578-0x800975A8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 * Table-manager classes (strings name /mvp2004/source/common/database/tablemanager.cpp)
 * then a game-object class with an 0x34-stride record array; types in include/game/tu_80090880.h.
 */
#include "game/tu_80090880.h"
#include "game/tu_80094578.h"

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

/* strcpy through an inline wrapper: an inline argument is expanded as an address sum, so
   &buf (frame offset 16) is rebuilt with `addi r3,r1,24` at every call instead of being
   CSE'd into a callee-saved register. */
inline void StrCpy(char* d, const char* src) { fn_8040B61C(d, src); }

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
    char buf[0x10];
    StrCpy(buf, (char*)m14[0].a);
    StrCpy((char*)m14[1].a, buf);
    const char* e = lbl_805B2CB0;
    StrCpy((char*)m14[0].a, e);
    StrCpy(buf, (char*)m14[0].b[1]);
    StrCpy((char*)m14[1].b[1], buf);
    StrCpy((char*)m14[0].b[1], e);
    StrCpy(buf, (char*)m14[0].b[0]);
    StrCpy((char*)m14[1].b[0], buf);
    StrCpy((char*)m14[0].b[0], e);
    StrCpy(buf, (char*)m2C[0]);
    StrCpy((char*)m2C[1], buf);
    StrCpy((char*)m2C[0], e);
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
    char buf[0x10];
    StrCpy(buf, (char*)mC[0].a);
    StrCpy((char*)mC[1].a, buf);
    const char* e = lbl_805B2CB0;
    StrCpy((char*)mC[0].a, e);
    StrCpy(buf, (char*)mC[0].b[1]);
    StrCpy((char*)mC[1].b[1], buf);
    StrCpy((char*)mC[0].b[1], e);
    StrCpy(buf, (char*)mC[0].b[0]);
    StrCpy((char*)mC[1].b[0], buf);
    StrCpy((char*)mC[0].b[0], e);
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

extern "C" void fn_800961E0(Sub198* p);

extern "C" void fn_8009619C(Sub198* p)
{
    p->m0 = 0;
    p->m4 = 4;
    p->m8 = 0;
    p->mC = 0;
    p->m10 = 0;
    p->m14 = 0;
    fn_800961E0(p);
}

extern "C" void fn_800961E0(Sub198* p)
{
    for (int i = 0; i < 0x80; i++)
        p->m1C[i] = 0;
}

/* near-miss: retail copies x through r0 before the call */
extern int lbl_8061930C;
struct Unk8007B2B0_Screen {
    int fn_80078A38(int a);
};

extern "C" void fn_80096204(Sub198* p, int x)
{
    p->m0 = x;
    p->m4 = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80078A38(x);
}

extern "C" void* fn_803FFA60(void* dst, const void* src, unsigned n); /* memcpy */

extern "C" Sub198* fn_80096244(Sub198* d, Sub198* s)
{
    d->m0 = s->m0;
    d->m4 = s->m4;
    d->m8 = s->m8;
    d->mC = s->mC;
    d->m10 = s->m10;
    d->m14 = s->m14;
    fn_803FFA60(d->m1C, s->m1C, 0x80);
    return d;
}

extern "C" void fn_80096AB4(Obj3* o);
extern "C" void fn_80099C48(Obj3* o, int a);
extern "C" unsigned fn_8007E0E4(int g, int a, int b);
extern "C" int fn_8007DF5C(int g, int a, int b, int i);

extern "C" void fn_800965E8(Obj3* o, int a, int b)
{
    fn_80096AB4(o);
    unsigned j = 0;
    fn_80096204(&o->m198, a);
    int g = lbl_8061930C;
    o->m164 = b;
    o->m188 = 1;
    unsigned n = fn_8007E0E4(g, a, b);
    if (j < n) {
        do {
            int r = fn_8007DF5C(g, a, b, j);
            unsigned char cnt = o->m3E4;
            ByteVec* v = &o->m168;
            o->m3E8[cnt].m0 = r;
            unsigned c = v->m4;
            if (c < v->m8) {
                v->m0[c] = cnt;
                v->m4 = v->m4 + 1;
            }
            j++;
            o->m3E4 = o->m3E4 + 1;
        } while (j < n);
    }
    fn_80099C48(o, 0);
}

extern "C" void fn_80096AB4(Obj3* o);
extern "C" void fn_80099C48(Obj3* o, int a);

extern "C" void fn_800966CC(Obj3* o, int a, int b)
{
    fn_80096AB4(o);
    fn_80096204(&o->m198, a);
    unsigned char n = o->m3E4;
    o->m164 = 4;
    o->m188 = 1;
    o->mD6C = b;
    o->m3E8[n].m0 = b;
    ByteVec* v = &o->m168;
    unsigned c = v->m4;
    if (c < v->m8) {
        v->m0[c] = n;
        v->m4 = v->m4 + 1;
    }
    o->m3E4 = o->m3E4 + 1;
    fn_80099C48(o, 0);
}

/* near-miss (25 of 48 slots): retail keeps the incremented count unextended in r9 and copies it */
extern "C" int fn_8007DDC8(int g, int a, int b, int c);

extern "C" void fn_80096770(Obj3* o, int a, int b, int flag)
{
    Slot34* rows = o->m3E8;
    fn_80096AB4(o);
    fn_80096204(&o->m198, a);
    unsigned char n = o->m3E4;
    o->m164 = 4;
    o->m188 = 2;
    rows[n].m0 = b;
    o->m17C[0] = n;
    int n2 = o->m3E4 + 1;
    o->m3E4 = n2;
    if (flag == 1) {
        rows[(unsigned char)n2].m0 = fn_8007DDC8(lbl_8061930C, a, 1, 1);
        o->m17C[1] = n2;
        o->m3E4 = o->m3E4 + 1;
    }
    fn_80099C48(o, 0);
}

extern "C" unsigned char fn_800968C0(Obj3* o, int key, int flag);
extern "C" void fn_80099A44(Obj3* o, int a, int b);

extern "C" void fn_80096830(Obj3* o, int a) { fn_80099A44(o, fn_800968C0(o, a, 1), 0); }

/* near-miss: retail loads the two bytes in the opposite register order */
extern "C" void fn_80096870(Obj3* o, unsigned a, unsigned b)
{
    ByteVec* v = &o->m168;
    unsigned char* p = v->m0;
    unsigned char ta = p[a];
    unsigned char tb = p[b];
    if (a >= v->m4)
        v->m4 = a + 1;
    v->m0[a] = tb;
    if (b >= v->m4)
        v->m4 = b + 1;
    v->m0[b] = ta;
}

extern "C" unsigned char fn_800968C0(Obj3* o, int key, int flag)
{
    unsigned char n = o->m3E4;
    unsigned char i = 0;
    unsigned char r = 0xFF;
    if (i < n) {
        Slot34* rows = o->m3E8;
        if (rows[0].m0 == key) {
            r = 0;
        } else {
            do {
                i++;
                if (!(i < n))
                    break;
            } while (rows[i].m0 != key);
            if (i < n)
                r = i;
        }
    }
    if (r == 0xFF && flag == 1)
        r = 0;
    return r;
}

/* near-miss: retail re-reads the count in the loop instead of keeping it in a register */
extern "C" unsigned char fn_8009692C(Obj3* o, int key)
{
    ByteVec* v = &o->m168;
    unsigned char i = 0;
    unsigned char r = 0xFF;
    if (i < v->m4) {
        unsigned char* p = v->m0;
        if (p[0] == key) {
            r = 0;
        } else {
            do {
                i++;
                if (!(i < v->m4))
                    break;
            } while (p[i] != key);
            if (i < v->m4)
                r = i;
        }
    }
    return r;
}

extern "C" int fn_80097148(Obj3* o, unsigned i)
{
    int r = 2;
    if (i != 0xFF && i < o->m3E4)
        r = o->m3E8[i].m4;
    return r;
}

extern "C" void fn_80097174(Obj3* o, unsigned i, int v)
{
    if (i < o->m3E4)
        o->m3E8[i].m4 = v;
}

extern "C" unsigned char fn_80097190(Obj3* o, int k)
{
    ByteVec* v = &o->m168;
    unsigned char r = 0xFF;
    if (v->m4 != 0)
        r = (v->mF + k + v->m4) % v->m4;
    return r;
}

extern "C" int fn_8008CFD8(void* p, int a, int b);

extern "C" int fn_800971C8(Obj3* o, int x)
{
    int r = fn_8008CFD8((char*)o + 0xC9C, 5, x);
    int ok = 0;
    if (r == 0 || r == 10)
        ok = 1;
    return ok;
}

extern "C" int fn_80097210(Obj3* o, int i)
{
    unsigned char s = o->m17C[i];
    if (s != 0xFF)
        return o->m3E8[s].m0;
    return 0;
}

extern "C" int fn_80097238(Obj3* o, int key)
{
    volatile int sp = 0;
    int i = 0;
    do {
        if (key == o->m17C[i])
            return i;
        int t;
        if (i > 9)
            t = i;
        else
            t = i + 1;
        sp = t;
        i = t;
    } while (i <= 9);
    return -1;
}

extern "C" int fn_80097288(Obj3* o, int key)
{
    volatile int sp = 0;
    int i = 0;
    do {
        if (key == fn_80097210(o, i))
            return sp;
        int c = sp;
        int t;
        if (c > 9)
            t = c;
        else
            t = c + 1;
        sp = t;
        i = t;
    } while (i <= 9);
    return -1;
}

extern "C" int fn_80097300(Obj3* o, int i)
{
    return o->m3E8[o->m168.m0[i]].m0;
}

/* near-miss: retail does no loop-invariant hoisting here (reloads +0, +4, +0x3E8 each pass) */
struct Unk80097318 {
    unsigned char* m0;
    unsigned m4;
    char pad8[0x3E8 - 8];
    Slot34 m3E8[10];
};

extern "C" int fn_80097318(Unk80097318* o, int key)
{
    int found = 0;
    unsigned char i = 0;
    if (i < o->m4) {
        int v = o->m3E8[o->m0[i]].m0;
        for (;;) {
            if (key == v) {
                found = 1;
                break;
            }
            i++;
            if (!(i < o->m4))
                break;
            v = o->m3E8[o->m0[i]].m0;
        }
    }
    return found;
}

extern "C" int fn_80097520(Obj3* o, int a)
{
    int k = fn_800968C0(o, a, 1);
    int r = fn_8008CFD8((char*)o + 0xC9C, 5, k);
    int ok = 0;
    if (r == 0 || r == 10)
        ok = 1;
    return ok;
}

extern "C" void fn_8006FC40(void* a, void* b);

extern "C" void fn_8009757C(char* o, void* a, int b, int c, int i)
{
    fn_8006FC40((char*)(i * 0x128 + (int)o) + 0x92C, a);
}
