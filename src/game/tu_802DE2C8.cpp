/*
 * Game code, .text 0x802DE2C8-0x802E22EC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_802DE2C8.h"
#include "game/tu_802E22EC.h"

inline int Ov2(Unk802E0914_Box* a, Unk802E0914_Box* b)
{
    int r = 0;
    if (!(a->mx >= b->Mx || a->Mx <= b->mx || a->my >= b->My || a->My <= b->my || a->mz >= b->Mz))
        r = a->Mz > b->mz;
    return r;
}
inline Unk802E0914_Obj* ChildAt(Unk802E0914_Obj** arr, int off) { return *(Unk802E0914_Obj**)((char*)arr + off); }
inline Unk802E0914_Obj* ChildAt8(Unk802E0914_Ent* arr, int off) { return *(Unk802E0914_Obj**)((char*)arr + off); }

void Unk803414A4::vslot46()
{
    vslot41();
}

int Unk803414A4::vslot47()
{
    return 0;
}

int Unk803414A4::vslot48()
{
    return 0;
}

Unk802D73B4_Mgr::~Unk802D73B4_Mgr()
{
}

void Unk802D73B4_Mgr::s4()
{
}

void fn_802DE344()
{
    fn_802DD224(1, 0xFFFF);
}

void fn_802DFCD8(void* a, void* b, void* c)
{
    fn_802DF870(b, a, c);
}

void fn_802E03D4(void* a, void* b, void* c)
{
    fn_802DFD04(b, a, c);
}

int Unk802DE2C8_List::fn_802E0400(Unk802DE2C8_Node* n)
{
    lbl_8061F68C->s2(n != 0, "/mvp2004/source/common/geomlib/constraintgroup.cpp", 39);
    if (n->m4) {
        n->m4->m0 = n->m0;
    } else {
        m0 = n->m0;
    }
    if (n->m0) {
        n->m0->m4 = n->m4;
    } else {
        m4 = n->m4;
    }
    m8 = m8 - 1;
    return 1;
}

int Unk802DE2C8_List::fn_802E04BC(Unk802DE2C8_Node* n)
{
    fn_802E0400(n);
    Unk802DE2C8_Pool* p = lbl_8061F688;
    lbl_8061F68C->s2(n != 0, "/mvp2004/source/common/geomlib/geomlib.h", 268);
    n->m4 = 0;
    n->m0 = p->m10;
    if (p->m10) {
        p->m10->m4 = n;
    } else {
        p->m14 = n;
    }
    p->m10 = n;
    p->mC = p->mC - 1;
    return 1;
}

void Unk802DE2C8_List::fn_802E056C()
{
    Unk802DE2C8_Node* n = m0;
    if (n) {
        Unk802DE2C8_Pool* p = lbl_8061F688;
        Unk802DE2C8_Node* last = m4;
        int cnt = m8;
        lbl_8061F68C->s2(1, "/mvp2004/source/common/geomlib/geomlib.h", 300);
        n->m4 = p->m14;
        if (p->m14) {
            p->m14->m0 = n;
        } else {
            p->m10 = n;
        }
        p->m14 = last;
        lbl_8061F68C->s2(last->m0 == 0, "/mvp2004/source/common/geomlib/geomlib.h", 319);
        p->mC = p->mC - cnt;
        m8 = 0;
        m0 = 0;
        m4 = 0;
    }
}

int fn_802E0658(Unk802E0914_Obj* a, Unk802E0914_Obj* b, Unk802E0914_Out* c)
{
    lbl_8061F68C->s2(b->m0 == 10, "/mvp2004/source/common/geomlib/findintersection.cpp", 0x2C);
    int saved = c->m8;
    for (int i = b->m60 - 1; i >= 0; i--) {
        int o = i * 4;
        Unk802E0914_Obj* it = ChildAt(b->m64, o);
        if (Ov2(&it->m30, &a->m30)) {
            if (it->m3 == 0) {
                it->s1();
            }
            if (a->m3 == 0) {
                a->s1();
            }
            ((void (*)(Unk802E0914_Obj*, Unk802E0914_Obj*, Unk802E0914_Out*))lbl_806E0554[it->m0][a->m0])(it, a, c);
        }
        it = ChildAt(b->m64, o);
        if (Ov2(&a->m30, &it->m30)) {
            if (a->m3 == 0) {
                a->s1();
            }
            if (it->m3 == 0) {
                it->s1();
            }
            ((void (*)(Unk802E0914_Obj*, Unk802E0914_Obj*, Unk802E0914_Out*))lbl_806E0554[a->m0][it->m0])(a, it, c);
        }
    }
    if (saved != c->m8)
        return c->m0;
    return 0;
}

int fn_802E0914(Unk802E0914_Obj* a, Unk802E0914_Obj* b, Unk802E0914_Out* c)
{
    lbl_8061F68C->s2(a->m0 == 10, "/mvp2004/source/common/geomlib/findintersection.cpp", 0x47);
    int saved = c->m8;
    for (int i = a->m60 - 1; i >= 0; i--) {
        int o = i * 4;
        Unk802E0914_Obj* it = ChildAt(a->m64, o);
        if (Ov2(&it->m30, &b->m30)) {
            if (it->m3 == 0) {
                it->s1();
            }
            if (b->m3 == 0) {
                b->s1();
            }
            ((void (*)(Unk802E0914_Obj*, Unk802E0914_Obj*, Unk802E0914_Out*))lbl_806E0554[it->m0][b->m0])(it, b, c);
        }
    }
    if (saved != c->m8)
        return c->m0;
    return 0;
}

int fn_802E0AC4(Unk802E0914_Obj* a, Unk802E0914_Obj8* b, Unk802E0914_Out* c)
{
    lbl_8061F68C->s2(b->m0 == 11, "/mvp2004/source/common/geomlib/findintersection.cpp", 0x62);
    int saved = c->m8;
    for (int i = b->m60 - 1; i >= 0; i--) {
        int o = i * 8;
        Unk802E0914_Obj* it = ChildAt8(b->m64, o);
        if (Ov2(&a->m30, &it->m30)) {
            if (a->m3 == 0) {
                a->s1();
            }
            if (it->m3 == 0) {
                it->s1();
            }
            ((void (*)(Unk802E0914_Obj*, Unk802E0914_Obj*, Unk802E0914_Out*))lbl_806E0554[a->m0][it->m0])(a, it, c);
        }
    }
    if (saved != c->m8)
        return c->m0;
    return 0;
}

int fn_802E0C74(Unk802E0914_Obj8* a, Unk802E0914_Obj* b, Unk802E0914_Out* c)
{
    lbl_8061F68C->s2(a->m0 == 11, "/mvp2004/source/common/geomlib/findintersection.cpp", 0x7C);
    int saved = c->m8;
    for (int i = a->m60 - 1; i >= 0; i--) {
        int o = i * 8;
        Unk802E0914_Obj* it = ChildAt8(a->m64, o);
        if (Ov2(&it->m30, &b->m30)) {
            if (it->m3 == 0) {
                it->s1();
            }
            if (b->m3 == 0) {
                b->s1();
            }
            ((void (*)(Unk802E0914_Obj*, Unk802E0914_Obj*, Unk802E0914_Out*))lbl_806E0554[it->m0][b->m0])(it, b, c);
        }
    }
    if (saved != c->m8)
        return c->m0;
    return 0;
}

void fn_802E0E24(void* a, void* b, void* c)
{
    fn_802E0E50(b, a, c);
}

int fn_802E212C()
{
    return 0;
}

int fn_802E2134()
{
    return 0;
}

void fn_802E213C()
{
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            lbl_806E0554[i][j] = fn_802E212C;
            lbl_806E0B98[i][j] = fn_802E2134;
        }
    }
    lbl_8061F680 = 1;
    lbl_8061F68C->s3("GeomLib Initialised\n");
}

void fn_802E21E0(int a, int b, Unk802DE2C8_Fn c)
{
    lbl_806E0554[a][b] = c;
}

void fn_802E21FC(Unk802E21FC_R* d, Unk802E21FC_R* s)
{
    d->m8 = s->m8;
    d->mC = s->mC;
    d->m1 = s->m1;
}

Unk802E22C4_T::~Unk802E22C4_T()
{
}

void fn_802E22C4(Unk802E22C4_T* t)
{
    Unk802E22C4_E* p = t->m60;
    for (int i = 0; i < 2; i++) {
        p->m8 = t->m8;
        p->mC = t->mC;
        p++;
    }
}
