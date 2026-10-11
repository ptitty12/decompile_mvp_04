/*
 * Game code, .text 0x802E6464-0x802EBA64 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802E6464.h"

Unk802E78EC::Unk802E78EC()
{
    m0 = 11;
    m60 = 0;
    m64 = 0;
    m68 = 0;
}

Unk802E78EC::~Unk802E78EC()
{
    fn_802E7A08();
}

Unk802E6124* fn_802E65BC(Unk802E6124* o, Unk802E4B98_V4* v)
{
    Unk802E6124* p = new ("X") Unk802E6124;
    lbl_8061F68C->s2(p != 0, "/mvp2004/source/common/geomlib/geomobb.cpp", 171);
    p->fn_802E624C(o, v);
    return p;
}

void Unk802E6124::fn_802E715C()
{
    m3 = 1;
    if (m170) {
        m170->s6((char*)this + 0xA0, 1);
    }
}

void Unk802E7314::fn_802E7200(Unk802E7314* o, int x)
{
    fn_802E21FC((Unk802E21FC_R*)this, (Unk802E21FC_R*)o);
    m60 = o->m60;
    m70 = o->m70;
    mB0 = o->mB0;
    mB8 = o->mB8;
    mBC = o->mBC;
}

void Unk802E7314::fn_802E7298(Unk802E7314* o, float* s)
{
    lbl_8061F68C->s2(o->m0 == 1, "/mvp2004/source/common/geomlib/geomray.cpp", 55);
    mB0 = o->mB0 * *s;
}

Unk802E7314* fn_802E7314(Unk802E7314* o, int x)
{
    Unk802E7314* p = new ("X") Unk802E7314;
    lbl_8061F68C->s2(p != 0, "/mvp2004/source/common/geomlib/geomray.cpp", 72);
    p->fn_802E7200(o, x);
    return p;
}

void Unk802E7314::fn_802E78D4()
{
    m3 = 1;
    mB4 = mB0 * mB0;
}

void Unk802E78EC::fn_802E7A08()
{
    if (m64) {
        for (int i = 0; i < m60; i++) {
            if (m64[i].m0) {
                delete m64[i].m0;
            }
        }
        if (m68) {
            if (m64) {
                lbl_8061F68C->s5((char*)m64 - 8);
            }
            m68 = 0;
        }
        m60 = 0;
        m64 = 0;
    }
}

void Unk802E78EC::fn_802E7AE0(Unk802E78EC_Entry* a, int n)
{
    m64 = a;
    m60 = n;
}

void Unk802E78EC::fn_802E7AEC(Unk802E78EC* o, int x)
{
    fn_802E21FC((Unk802E21FC_R*)this, (Unk802E21FC_R*)o);
    m68 = 1;
    int n = o->m60;
    Unk802E78EC_Entry* a = (Unk802E78EC_Entry*)((char*)lbl_8061F68C->s4(n * 8 + 8, "X") + 8);
    *(int*)((char*)a - 8) = n;
    lbl_8061F68C->s2(a != 0, "/mvp2004/source/common/geomlib/geomskeleton.cpp", 99);
    for (int i = 0; i < o->m60; i++) {
        int off = i * 8;
        a[i].m0 = (*(Unk802E78EC_Entry*)((char*)o->m64 + off)).m0->s4(x);
        a[i].m0->m4 = this;
        a[i].m4 = (*(Unk802E78EC_Entry*)((char*)o->m64 + off)).m4;
    }
    fn_802E7AE0(a, o->m60);
}

void Unk802E78EC::fn_802E7C1C(Unk802E78EC* o, int x)
{
    lbl_8061F68C->s2(o->m0 == 11, "/mvp2004/source/common/geomlib/geomskeleton.cpp", 121);
    for (int i = 0; i < o->m60; i++) {
        int off = i * 8;
        m64[i].m0->s5(*(Unk802E22EC_B**)((char*)o->m64 + off), x);
    }
}

Unk802E78EC* fn_802E7CDC(Unk802E78EC* o, int x)
{
    Unk802E78EC* p = new ("X") Unk802E78EC;
    lbl_8061F68C->s2(p != 0, "/mvp2004/source/common/geomlib/geomskeleton.cpp", 139);
    p->fn_802E7AEC(o, x);
    return p;
}

void Unk802E78EC::fn_802E7D88(char* mats)
{
    lbl_8061F68C->s2(mats != 0, "/mvp2004/source/common/geomlib/geomskeleton.cpp", 156);
    for (int i = 0; i < m60; i++) {
        m64[i].m0->s6((char*)(m64[i].m4 * 64 + (int)mats), 1);
    }
    fn_802E7E60();
    m3 = 1;
}

void Unk802E78EC::fn_802E7E60()
{
    lbl_8061F68C->s2(m60 > 0, "/mvp2004/source/common/geomlib/geomskeleton.cpp", 179);
    Unk802E0914_Box* b = &m30;
    fn_8035F4EC(b, &m64[0].m0->m30);
    for (int i = 1; i < m60; i++) {
        Unk802E0914_Box* c = &m64[i].m0->m30;
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

Unk802E869C::Unk802E869C()
{
    m0 = 7;
    m60 = 0;
    m64 = 0;
    m68 = 0;
}

Unk802E869C::~Unk802E869C()
{
    fn_802E87B8();
}

void Unk802E869C::fn_802E87B8()
{
    fn_802E8AC4();
    Unk802E22EC_Counted* c = m60;
    if (c) {
        c->m0 = c->m0 - 1;
        m60 = 0;
    }
}

void Unk802E869C::fn_802E8804(Unk802E869C* o, Unk802E4B98_V4* v)
{
    fn_802E21FC((Unk802E21FC_R*)this, (Unk802E21FC_R*)o);
    fn_802E8B6C(o->m60, 1, v);
}

Unk802E869C* fn_802E884C(Unk802E869C* o, Unk802E4B98_V4* v)
{
    Unk802E869C* p = new ("X") Unk802E869C;
    lbl_8061F68C->s2(p != 0, "/mvp2004/source/common/geomlib/geomspheregroup.cpp", 87);
    p->fn_802E8804(o, v);
    return p;
}

void Unk802E869C::fn_802E8AC4()
{
    if (m68) {
        delete[] m68;
    }
    m64 = 0;
    m68 = 0;
}

Unk802E8FB0::Unk802E8FB0()
{
    m0 = 8;
    m60 = 0;
    m64 = 0;
}

Unk802E8FB0::~Unk802E8FB0()
{
    fn_802E90C8();
}

void Unk802E8FB0::fn_802E90C8()
{
    if (m60) {
        delete m60;
        m60 = 0;
    }
    if (m64) {
        delete m64;
        m64 = 0;
    }
}

void Unk802E8FB0::fn_802E9150(Unk802E22EC_B* o)
{
    lbl_8061F68C->s2(o->m0 == 8, "/mvp2004/source/common/geomlib/geomspheremesh.cpp", 74);
    lbl_8061F68C->s2(0, "/mvp2004/source/common/geomlib/geomspheremesh.cpp", 75);
}

void Unk802E8FB0::fn_802E9380()
{
    m60->s1();
    m64->s1();
    m3 = 1;
}
