/*
 * Game code, .text 0x802E22EC-0x802E6464 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802E22EC.h"

Unk802E313C::Unk802E313C()
{
    m0 = 10;
    m60 = 0;
    m64 = 0;
}

Unk802E313C::~Unk802E313C()
{
    fn_802E3254();
}

void Unk802E313C::fn_802E3254()
{
    for (int i = 0; i < m60; i++) {
        if (m64[i]) {
            delete m64[i];
        }
        m64[i] = 0;
    }
    m60 = 0;
    if (m64) {
        delete[] m64;
    }
    m64 = 0;
}

void Unk802E313C::fn_802E32F8(int n)
{
    lbl_8061F68C->s2(n > 0, "/mvp2004/source/common/geomlib/geomgroup.cpp", 75);
    m60 = n;
    m64 = new Unk802E22EC_B*[n];
    lbl_8061F68C->s2(m64 != 0, "/mvp2004/source/common/geomlib/geomgroup.cpp", 80);
    for (int i = 0; i < n; i++) {
        m64[i] = 0;
    }
}

void Unk802E313C::fn_802E33D0(Unk802E313C* o, int x)
{
    fn_802E21FC((Unk802E21FC_R*)this, (Unk802E21FC_R*)o);
    fn_802E32F8(o->m60);
    for (int i = 0; i < o->m60; i++) {
        int off = i * 4;
        char* t = (char*)m64;
        *(Unk802E22EC_B**)(t + off) = o->m64[i]->s4(x);
        (*(Unk802E22EC_B**)((char*)m64 + off))->m4 = this;
    }
}

void Unk802E313C::fn_802E3470(Unk802E313C* o, int x)
{
    lbl_8061F68C->s2(o->m0 == 10, "/mvp2004/source/common/geomlib/geomgroup.cpp", 118);
    for (int i = 0; i < o->m60; i++) {
        int off = i * 4;
        (*(Unk802E22EC_B**)((char*)m64 + off))->s5(o->m64[i], x);
    }
}

Unk802E313C* fn_802E3530(Unk802E313C* o, int x)
{
    Unk802E313C* p = new ("X") Unk802E313C;
    lbl_8061F68C->s2(p != 0, "/mvp2004/source/common/geomlib/geomgroup.cpp", 136);
    p->fn_802E33D0(o, x);
    return p;
}

Unk802E4B98::Unk802E4B98()
{
    m0 = 6;
    mF4 = 0;
    mF8 = 0;
    mFC = 0;
    m100 = 0;
    m104 = 0;
    m108 = 0;
    m60 = lbl_806B98B0;
}

Unk802E4B98::~Unk802E4B98()
{
    fn_802E4D30();
}

void Unk802E313C::fn_802E35DC(int a, int b)
{
    for (int i = 0; i < m60; i++) {
        m64[i]->s6(a, b);
    }
    fn_802E366C();
    m3 = 0;
}

void Unk802E313C::fn_802E366C()
{
    Unk802E0914_Box* b = &m30;
    fn_8035F4EC(b, &m64[0]->m30);
    for (int i = 1; i < m60; i++) {
        Unk802E0914_Box* c = &m64[i]->m30;
        if (!(m30.mx <= c->mx)) {
            m30.mx = c->mx;
        }
        if (!(b->my <= c->my)) {
            b->my = c->my;
        }
        if (!(b->mz <= c->mz)) {
            b->mz = c->mz;
        }
        if (!(b->Mx >= c->Mx)) {
            b->Mx = c->Mx;
        }
        if (!(b->My >= c->My)) {
            b->My = c->My;
        }
        if (!(b->Mz >= c->Mz)) {
            b->Mz = c->Mz;
        }
    }
}

void Unk802E22EC_B::fn_802E3770()
{
    m3 = 1;
}

Unk802DE2C8_Pool::Unk802DE2C8_Pool()
{
    if (lbl_8061F688 == 0) {
        lbl_8061F688 = this;
    }
    lbl_8061F68C = 0;
    m4 = 0;
    m0 = 0;
    mC = 0;
    m8 = 0;
    m10 = 0;
    m14 = 0;
}

Unk802DE2C8_List::~Unk802DE2C8_List()
{
    lbl_8061F68C->s2(m0 == 0, "/mvp2004/source/common/geomlib/geomlib.cpp", 62);
}

void Unk802E3A44_Blk::fn_802E3A44()
{
    lbl_8061F68C->s2(mC == 0, "/mvp2004/source/common/geomlib/geomlib.h", 206);
    m8 = m0;
    mC = 0;
    m10 = 0;
    m14 = 0;
}

void Unk802E4B98::fn_802E4D30()
{
    fn_802E5840();
}

/* near-miss: struct copy of the scaled vector is lwz/stw here, lfs/stfs through the address pseudo (addi r9,r1,8) in
   retail; a float-wise copy constructor fixes the loads but not the pseudo (36 slots) */
void Unk802E4B98::fn_802E4D50(Unk802E4B98* o, Unk802E4B98_V4* v)
{
    fn_802E21FC((Unk802E21FC_R*)this, (Unk802E21FC_R*)o);
    Unk802E4B98_V4 r(o->mE0 * v->m0, o->mE4 * v->m4, o->mE8 * v->m8, o->mEC * v->mC);
    fn_802E4F8C(o->mF4, 1, &r);
}

/* near-miss: same as fn_802E4D50 */
void Unk802E4B98::fn_802E4DFC(Unk802E4B98* o, Unk802E4B98_V4* v)
{
    lbl_8061F68C->s2(o->m0 == 6, "/mvp2004/source/common/geomlib/geommesh.cpp", 92);
    Unk802E4B98_V4 r(o->mE0 * v->m0, o->mE4 * v->m4, o->mE8 * v->m8, o->mEC * v->mC);
    fn_802E4F8C(o->mF4, 1, &r);
}

Unk802E4B98* fn_802E4EE0(Unk802E4B98* o, Unk802E4B98_V4* v)
{
    Unk802E4B98* p = new ("X") Unk802E4B98;
    lbl_8061F68C->s2(p != 0, "/mvp2004/source/common/geomlib/geommesh.cpp", 107);
    p->fn_802E4D50(o, v);
    return p;
}

void Unk802E4B98::fn_802E5714(int a, int b)
{
    lbl_8061F68C->s2(a >= 0, "/mvp2004/source/common/geomlib/geommesh.cpp", 246);
    lbl_8061F68C->s2(b >= 0, "/mvp2004/source/common/geomlib/geommesh.cpp", 247);
    if (a != m100 || b != m108) {
        fn_802E5840();
    }
    m100 = a;
    if (a > 0) {
        mFC = new Unk802E5714_E[a];
    }
    m108 = b;
    if (b > 0) {
        m104 = new Unk802E5714_F[b];
    }
    mF8 = 1;
}

void Unk802E4B98::fn_802E5840()
{
    if (mF8) {
        if (mFC) {
            delete[] mFC;
        }
        if (m104) {
            delete[] m104;
        }
        mF8 = 0;
    }
    Unk802E22EC_Counted* c = mF4;
    mFC = 0;
    m100 = 0;
    m104 = 0;
    m108 = 0;
    if (c) {
        c->m0 = c->m0 - 1;
        mF4 = 0;
    }
}

void Unk802E4B98::fn_802E60C4()
{
    lbl_8061F68C->s2(mF8, "/mvp2004/source/common/geomlib/geommesh.cpp", 374);
    m3 = 1;
}

Unk802E6124::~Unk802E6124()
{
    if (m170) {
        delete m170;
    }
}

void Unk802E6124::fn_802E61BC(const Unk802E4B98_M* m, const Unk802E4B98_V4* v)
{
    m60 = *m;
    m160 = *v;
}
