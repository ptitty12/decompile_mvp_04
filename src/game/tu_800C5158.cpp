/*
 * Game code, .text 0x800C5158-0x800C7A4C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800BCD38.h"

extern "C" {
int fn_8040B574(const char* a, const char* b);
void fn_803FED48(const char* path, int a, int b, int* c);
int fn_800C5C0C(const char* path);
}

extern Unk800C5E74_Obj* lbl_8061ABE0;
extern "C" void fn_800C5010(Unk800C341C_Mgr* m);
extern "C" void fn_800C5080(Unk800C341C_Mgr* m);
extern char lbl_805B6F58;
extern "C" {
void fn_800C5798(Unk800C341C_Mgr* m, Unk800C1BE4_Widget* w);
void fn_800C5574(Unk800C341C_Mgr* m, int kind, const char* name, int w, float t, int flag);
void fn_800C4F64(Unk800C341C_Mgr* m, const char* name);
void fn_800C4FA8(Unk800C341C_Mgr* m, const char* name);
char* fn_8040B61C(char* dst, const char* src);
void fn_800C2B94(Unk800C2250_File* f, int i);
int fn_800C5980(Unk800C341C_Mgr* m);
int fn_800C59E8(Unk800C341C_Mgr* m);
int fn_802B9804(const char* path, int a);
int fn_803FC410(int h, int a, int b, int c, int d);
int fn_803FC034(int size);
void fn_803EDA0C(int h);
int fn_803FAB68(const char* path, int a, int* out);
}

extern const char* lbl_8061AB80[];
extern Unk800C6794_Pair lbl_805BC06C;
extern Unk800C6794_Pair lbl_805BC074;

extern "C" int fn_800C5158(Unk800C341C_Mgr* m, const char* name)
{
    int idx = fn_800C510C(m, name);
    if (idx == -1)
        return 0;
    return fn_800C512C(m, idx);
}

extern "C" int fn_800C519C(Unk800C341C_Mgr* m, int kind)
{
    int* w = (int*)m;
    switch (kind) {
    case 0:
        return 0;
    case 1:
        return w[20];
    case 2:
        return w[21];
    case 4:
        return w[22];
    case 5:
        return w[24];
    case 6:
        return w[23];
    case 7:
        return w[25];
    case 8:
        return w[26];
    case 10:
        return w[27];
    case 11:
        return w[28];
    case 12:
        return w[29];
    case 13:
        return w[30];
    case 14:
        return w[31];
    case 15:
        return w[32];
    case 16:
        return w[33];
    case 17:
        return w[34];
    case 18:
        return w[35];
    case 19:
        return w[36];
    case 20:
        return w[37];
    }
    return 0;
}

extern "C" int fn_800C52EC(void* unused, int idx, const char* name)
{
    char a[0x400];
    char b[0x400];
    int out;
    fn_804089B4(a, "%s.%s", name, "gsh");
    fn_804089B4(b, "%s|%s", lbl_8061AB80[idx], a);
    int r = fn_803FAB68(b, 1, &out);
    return r != 0;
}

extern "C" {
int fn_800C50EC(Unk800C341C_Mgr* m, Unk800C1BE4_Widget* w);
int fn_800C22C0(Unk800C2250_File* f, int kind, const char* name, Unk800C1BE4_Widget* w, int flag, float t);
void fn_800C2A1C(Unk800C2250_File* f, Unk800C1BE4_Widget* w, float t);
int fn_800C58E8(Unk800C341C_Mgr* m, int kind);
}

extern const char lbl_805BBF4C[];
extern const float lbl_805BBF54;

/* near-miss: control flow matches; saved-register order differs (retail kind=r27 name=r28 idx=r31 w=r30) and our two fn_800C2A1C tails are not cross-jumped */
extern "C" void fn_800C537C(Unk800C341C_Mgr* m, int kind, const char* name, int wi, float t, int flag)
{
    Unk800C1BE4_Widget* w = (Unk800C1BE4_Widget*)wi;
    int idx = fn_800C5CF8(m, name);
    if (idx != -1) {
        if (wi != 0) {
            if (fn_800C2998(&m->files[idx], w) == -1)
                fn_800C5798(m, w);
        }
        fn_800C2A1C(&m->files[idx], w, t);
    } else {
        if (wi != 0) {
            int j;
            if (kind == 1 && fn_800C52EC(m, 1, name) == 0 && (j = fn_800C50EC(m, w)) != -1
                && fn_8040B574(fn_800C2F84(&m->files[j]), lbl_805BBF4C) == 0) {
                w->fn_vslot8(1);
                w->fn_vslot20(lbl_805BBF54);
                return;
            }
            fn_800C5798(m, w);
        }
        int k = fn_800C58E8(m, kind);
        if (k == -1) {
            fn_800C5574(m, kind, name, wi, t, flag);
        } else {
            Unk800C2250_File* f = &m->files[k];
            int r = fn_800C22C0(f, kind, name, w, flag, t);
            if (kind == 1 && r == 0) {
                const char* nm = lbl_805BBF4C;
                int q = fn_800C5CF8(m, nm);
                if (q == -1)
                    fn_800C22C0(f, 1, nm, w, flag, t);
                else
                    fn_800C2A1C(&m->files[q], w, t);
            }
        }
    }
}

extern "C" void fn_8033E958(const char* fmt, ...);

extern "C" void fn_800C5574(Unk800C341C_Mgr* m, int kind, const char* name, int w, float t, int flag)
{
    for (int i = 0; i < m->m5D94; i++) {
        if (m->recs[i].m404 == w) {
            m->recs[i].m0 = kind;
            fn_8040B61C(&m->recs[i].m4, name);
            m->recs[i].m404 = w;
            m->recs[i].m408 = t;
            m->recs[i].m40C = flag;
            return;
        }
    }
    if (m->m5D94 <= 11) {
        m->recs[m->m5D94].m0 = kind;
        fn_8040B61C(&m->recs[m->m5D94].m4, name);
        m->recs[m->m5D94].m404 = w;
        m->recs[m->m5D94].m408 = t;
        m->recs[m->m5D94].m40C = flag;
        m->m5D94 = m->m5D94 + 1;
    } else {
        fn_8033E958("=====>cOnDemandManager::AddToLoadQueue can't find slot for %s - IGNORING REQUEST
", name);
    }
}

extern float lbl_805BBFAC;

extern "C" void fn_800C56C0(Unk800C341C_Mgr* m, int idx)
{
    int n = m->m5D94 - 1;
    m->m5D94 = n;
    int i = idx;
    if (i < n) {
        do {
            m->recs[i] = m->recs[i + 1];
            i++;
        } while (i < m->m5D94);
    }
    Unk800C3A10_Rec* r = (Unk800C3A10_Rec*)(i * 1040 + (int)m);
    r = (Unk800C3A10_Rec*)((char*)r + 11476);
    r->m0 = 0;
    r->m4 = 0;
    r->m404 = 0;
    r->m408 = lbl_805BBFAC;
    r->m40C = 0;
}

/* near-miss: 2 slots (retail loads the slot-28 delta into r0 and the pfn into r9; ours swaps them) and the loop-back to the fn_800C2998 call */
extern "C" void fn_800C5798(Unk800C341C_Mgr* m, Unk800C1BE4_Widget* w)
{
    Unk800C2250_File* f = &m->files[0];
    w->fn_vslot28(&lbl_805B6F58, 0);
    w->fn_vslot8(0);
    for (int i = 0; i < 10; i++) {
        if (fn_800C2EF0(f) && (!fn_800C2F08(f) || fn_800C2F44(f))) {
            int r = fn_800C2998(f, w);
            while (r != -1) {
                fn_800C2B94(f, r);
                r = fn_800C2EF0(f) ? fn_800C2998(f, w) : -1;
            }
        }
        f++;
    }
}

extern "C" int fn_800C587C(Unk800C341C_Mgr* m)
{
    int i = 0;
    if (i < m->m5DA4) {
        Unk800C2250_File* f = &m->files[0];
        do {
            if (!fn_800C2EF0(f))
                return i;
            i++;
            f++;
        } while (i < m->m5DA4);
    }
    return -1;
}

extern "C" int fn_800C58E8(Unk800C341C_Mgr* m, int kind)
{
    switch (kind) {
    case 2:
        return fn_800C59E8(m);
    case 8:
        return fn_800C5980(m);
    default: {
        int i = 0;
        if (i < m->m5DA4) {
            Unk800C2250_File* f = &m->files[0];
            do {
                if (!fn_800C2EF0(f))
                    return i;
                i++;
                f++;
            } while (i < m->m5DA4);
        }
        return -1;
    }
    }
}

extern "C" int fn_800C5980(Unk800C341C_Mgr* m)
{
    for (int i = 0; i <= 9; i++) {
        Unk800C2250_File* f = &m->files[i];
        if (fn_800C2F08(f) && !fn_800C2F44(f))
            return i;
    }
    return -1;
}

extern "C" int fn_800C59E8(Unk800C341C_Mgr* m)
{
    for (int i = 0; i <= 9; i++) {
        Unk800C2250_File* f = &m->files[i];
        if (fn_800C2F1C(f) && !fn_800C2F5C(f))
            return i;
    }
    return -1;
}

extern "C" void fn_800C5A50(Unk800C341C_Mgr* m)
{
    for (int i = 0; i < 2; i++)
        fn_800C24B0(&m->files[fn_800C587C(m)]);
    m->m5D98 = 1;
}

extern "C" void fn_800C5AA4(Unk800C341C_Mgr* m)
{
    for (int i = 0; i < 2; i++)
        fn_800C2518(&m->files[fn_800C587C(m)]);
    m->m5D9C = 1;
}

extern "C" void fn_800C5AF8(Unk800C341C_Mgr* m)
{
    if (m->m5D98 != 0) {
        for (int i = 0; i < 2; i++)
            fn_800C2948(&m->files[fn_800C5DAC(m, 8)]);
        m->m5D98 = 0;
    }
}

extern "C" void fn_800C5B58(Unk800C341C_Mgr* m)
{
    if (m->m5D9C != 0) {
        for (int i = 0; i < 2; i++)
            fn_800C2948(&m->files[fn_800C5DAC(m, 2)]);
        m->m5D9C = 0;
        m->m5DA0 = 1;
    }
}

extern "C" void fn_800C5BC0(void* unused, const char* path, int* h, int* out)
{
    fn_803FED48(path, 0, 100, h);
    *out = fn_800C5C0C(path);
}

extern "C" int fn_800C5C0C(const char* path)
{
    int h = fn_802B9804(path, 0);
    int size = fn_803FC410(h, 0, 0, 0, 0);
    int p = fn_803FC034(size + 1);
    fn_803EDA0C(h);
    return p + 0x3E8;
}

extern "C" int fn_800C5C68(Unk800C341C_Mgr* m, Unk800C1BE4_Widget* w)
{
    for (int i = 0; i <= 9; i++) {
        Unk800C2250_File* f = &m->files[i];
        if (fn_800C2EF0(f) && (!fn_800C2F08(f) || fn_800C2F44(f)) && fn_800C2998(f, w) != -1)
            return i;
    }
    return -1;
}

extern "C" int fn_800C5CF8(Unk800C341C_Mgr* m, const char* name)
{
    for (int i = 0; i <= 9; i++) {
        Unk800C2250_File* f = &m->files[i];
        if (fn_800C2EF0(f) && (!fn_800C2F08(f) || fn_800C2F44(f)) && (!fn_800C2F1C(f) || fn_800C2F5C(f))
            && fn_8040B574(fn_800C2F84(f), name) == 0)
            return i;
    }
    return -1;
}

extern "C" int fn_800C5DAC(Unk800C341C_Mgr* m, int kind)
{
    for (int i = 0; i <= 9; i++) {
        Unk800C2250_File* f = &m->files[i];
        if (fn_800C2EF0(f) && !fn_800C2F30(f) && fn_800C2F7C(f) == kind)
            return i;
    }
    return -1;
}

extern "C" Unk800C5E74_Obj* fn_800C5E28()
{
    if (lbl_8061ABE0 == 0)
        lbl_8061ABE0 = new (0) Unk800C5E74_Obj;
    return lbl_8061ABE0;
}

Unk800C5E74_Obj::Unk800C5E74_Obj()
{
    fn_800C5EB0();
}

void Unk800C5E74_Obj::fn_800C5EB0()
{
    m0 = 0;
    m10 = -1;
    m14 = 0;
    m28 = 0;
    m2C = 1;
    m4 = lbl_805B6F58;
    m18 = lbl_805B6F58;
    m38 = 0;
    m30 = 0;
    m3C = 1;
}

Unk800C5E74_Obj::~Unk800C5E74_Obj()
{
    fn_800C6624();
}

extern "C" void fn_800C4EEC(Unk800C341C_Mgr* m, const char* name);

extern "C" void fn_800C618C(Unk800C5E74_Obj* o)
{
    if (o->m10 != -1)
        fn_800C512C(fn_800C33D0(), o->m10);
    if (o->m28 != 0) {
        ((Unk800C7B40_Widget*)o->m0)->fn_vslot8(1);
        ((Unk800C7B40_Widget*)o->m0)->fn_vslot20(1.0f);
        ((Unk800C7B40_Widget*)o->m14)->fn_vslot8(0);
        ((Unk800C1BE4_Widget*)o->m14)->fn_vslot28(&lbl_805B6F58, 0);
        if (o->m2C != 0)
            fn_800C4F64(fn_800C33D0(), &o->m18);
        else
            fn_800C4FA8(fn_800C33D0(), &o->m18);
        char z = lbl_805B6F58;
        o->m28 = 0;
        o->m18 = z;
    }
    if (o->m10 != -1)
        fn_800C4EEC(fn_800C33D0(), &o->m4);
}

void Unk800C5E74_Obj::fn_800C650C(Unk800C1BE4_Widget* a, const char* n1, Unk800C1BE4_Widget* b, const char* n2, float f, int flag)
{
    if (m2C != 0)
        fn_800C5010(fn_800C33D0());
    m2C = 0;
    a->fn_vslot8(1);
    b->fn_vslot8(0);
    fn_800C435C(fn_800C33D0(), (int)a, 1.0f, n1, flag);
    fn_800C435C(fn_800C33D0(), (int)b, 1.0f, n2, flag);
    m0 = (int)a;
    m34 = f;
    fn_8040B61C(&m4, n1);
    fn_8040B61C(&m18, n2);
    m14 = (int)b;
    m30 = 1;
}

void Unk800C5E74_Obj::fn_800C6604()
{
    m34 = -m34;
    m38 = 1;
    m3C = 0;
}

void Unk800C5E74_Obj::fn_800C6624()
{
    fn_800C5010(fn_800C33D0());
    fn_800C5AF8(fn_800C33D0());
    fn_800C5080(fn_800C33D0());
    fn_800C5B58(fn_800C33D0());
    m4 = lbl_805B6F58;
    m18 = lbl_805B6F58;
    m10 = -1;
    m0 = 0;
    m14 = 0;
    m28 = 0;
}

extern "C" void fn_800C6698(Unk800C5E74_Obj* o)
{
    int z = o->m2C;
    if (z != 0) {
        if (fn_8040B574(&o->m4, &lbl_805B6F58) != 0)
            fn_800C4F64(fn_800C33D0(), &o->m4);
        if (fn_8040B574(&o->m18, &lbl_805B6F58) != 0)
            fn_800C4F64(fn_800C33D0(), &o->m18);
    } else {
        if (fn_8040B574(&o->m4, &lbl_805B6F58) != 0)
            fn_800C4FA8(fn_800C33D0(), &o->m4);
        if (fn_8040B574(&o->m18, &lbl_805B6F58) != 0)
            fn_800C4FA8(fn_800C33D0(), &o->m18);
        o->m30 = 0;
    }
    o->m4 = lbl_805B6F58;
    o->m18 = lbl_805B6F58;
    o->m10 = -1;
    o->m0 = 0;
    o->m14 = 0;
}

extern "C" Unk800C6794_Raw* fn_800C6794(Unk800C6794_Raw* o, const char* name)
{
    o->m0 = 0;
    o->m4 = 0;
    o->m1C4 = 0;
    o->m1C8 = lbl_8065A470;
    fn_8040B830(o->m8, name, 41);
    for (int i = 0; i < 100; i++)
        o->m34[i] = 0;
    return o;
}

extern "C" void fn_800C6808(Unk800C6794_Raw* o, int c)
{
    o->m1C8 = lbl_8065A470;
    for (int i = 0; i < o->m1C4; i++) {
        if (o->m34[i] != 0)
            delete o->m34[i];
        o->m34[i] = 0;
    }
    o->m1C4 = 0;
    if (c & 1)
        fn_80377408(o);
}

void Unk800C68B4_List::fn_800C68B4(Unk800C7B40_Widget* e)
{
    m34[m1C4++] = e;
}

Unk800C7B40_Widget* Unk800C68B4_List::fn_800C68D0(const char* name)
{
    int i = 0;
    if (i < m1C4) {
        do {
            if (fn_8040B574(m34[i]->mC, name) == 0)
                return m34[i];
            i++;
        } while (i < m1C4);
    }
    return 0;
}

void Unk800C68B4_List::fn_800C694C(const char* name)
{
    fn_800C68D0(name);
}

void Unk800C68B4_List::fn_800C696C()
{
    int i = 0;
    if (i < m1C4) {
        do {
            m34[i]->fn_vslot4();
            i++;
        } while (i < m1C4);
    }
}

void Unk800C68B4_List::fn_800C6A94(void (Unk800C7B40_Widget::*f)())
{
    for (int i = 0; i < m1C4; i++)
        (m34[i]->*f)();
}

void Unk800C68B4_List::fn_800C6B5C(void (Unk800C7B40_Widget::*f)())
{
    for (int i = 0; i < m1C4; i++)
        (m34[i]->*f)();
}

/* near-miss: same instructions as retail but the register split differs (retail: base r8, widget r10, index r11; here r10/r11/r9);
 * tried loop shapes, local widget, ptmf copy, break/return forms. */
void Unk800C68B4_List::fn_800C6C24(int a, int (Unk800C7B40_Widget::*f)(int))
{
    for (int i = m1C4 - 1; i >= 0; i--) {
        if (m34[i]->b1) {
            if ((m34[i]->*f)(a))
                return;
        }
    }
}

extern "C" void fn_800C69DC(Unk800C6794_Obj* o)
{
    Unk800C6794_Pair p = lbl_805BC06C;
    lbl_8061A330 = 1;
    o->fn_vslot4(&p);
}

extern "C" void fn_800C6A38(Unk800C6794_Obj* o)
{
    Unk800C6794_Pair p = lbl_805BC074;
    lbl_8061A330 = 1;
    o->fn_vslot4(&p);
}

extern "C" Unk800C7B40_Widget* fn_800C6CEC(Unk800C6794_Obj* o, const char* name)
{
    int i = 0;
    if (i < o->m1C4) {
        do {
            Unk800C7B40_Widget* r = o->m34[i]->fn_vslot30(name, 1);
            if (r != 0)
                return r;
            i++;
        } while (i < o->m1C4);
    }
    return 0;
}

extern "C" Unk800D1614_Raw* fn_800C6D74(Unk800D1614_Raw* self, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int s0,
                                        int s1, int s2, int s3, int s4)
{
    fn_800C7B40(self, p1, 1, p2, p3, p4, p5, p6, p7, s0, s3, s4, 0, 1.0f);
    self->m3C = lbl_80657D88;
    self->m40 = 0;
    self->m44 = 0;
    self->m48 = 0;
    self->m4C = 0;
    self->m50 = 0;
    self->m54 = (Unk800C7B40_Widget*)s2;
    self->b7 = s1;
    return self;
}

extern "C" void fn_800C6E34(Unk800C6E34_Raw* o, int c)
{
    o->m3C = lbl_80657D88;
    if (o->m40 != 0)
        delete o->m40;
    if (o->m44 != 0)
        delete o->m44;
    if (o->m48 != 0)
        delete o->m48;
    if (o->m4C != 0)
        delete o->m4C;
    if (o->m50 != 0)
        delete o->m50;
    o->m3C = lbl_8065CCE8;
    if (c & 1)
        fn_80377408(o);
}

extern "C" void fn_800C6F50(Unk800D1614_Obj* o)
{
    if (o->b0) {
        Unk800C7B40_Widget* w = (Unk800C7B40_Widget*)o->m40;
        if (!o->b1)
            w = o->m4C;
        else if (o->b4)
            w = o->m44;
        else if (o->b2)
            w = o->m50;
        else if (o->b3)
            w = o->m48;
        if (w != 0)
            w->fn_vslot2();
    }
}

extern "C" void fn_800C6FD8(Unk800C7A4C_Group* g)
{
    fn_800C7EE8(g);
    if (g->m40 != 0)
        g->m40->fn_vslot4();
    if (g->m44 != 0)
        g->m44->fn_vslot4();
    if (g->m48 != 0)
        g->m48->fn_vslot4();
    if (g->m4C != 0)
        g->m4C->fn_vslot4();
    if (g->m50 != 0)
        g->m50->fn_vslot4();
}

extern "C" void fn_800C70B8(Unk800D1614_Obj* o, int v)
{
    fn_800C7E38(o, v);
    if (o->m48 != 0) {
        o->m48->fn_vslot14(v);
        o->m48->fn_vslot24(v);
    }
}

extern "C" void fn_800C7130(Unk800C7A4C_Group* g, int a, int b, int c, int d)
{
    fn_800C8010(g, a, b, c, d);
    if (g->m40 != 0)
        g->m40->fn_vslot5(a, b, c, d);
    if (g->m44 != 0)
        g->m44->fn_vslot5(a, b, c, d);
    if (g->m48 != 0)
        g->m48->fn_vslot5(a, b, c, d);
    if (g->m4C != 0)
        g->m4C->fn_vslot5(a, b, c, d);
    if (g->m50 != 0)
        g->m50->fn_vslot5(a, b, c, d);
}

extern "C" void fn_800C7270(Unk800C7A4C_Group* g, int v)
{
    int d = v - g->m26;
    g->m26 = v;
    if (g->m40 != 0)
        g->m40->fn_vslot9(g->m40->m26 + d);
    if (g->m44 != 0)
        g->m44->fn_vslot9(g->m44->m26 + d);
    if (g->m48 != 0)
        g->m48->fn_vslot9(g->m48->m26 + d);
    if (g->m4C != 0)
        g->m4C->fn_vslot9(g->m4C->m26 + d);
    if (g->m50 != 0)
        g->m50->fn_vslot9(g->m50->m26 + d);
}

extern "C" void fn_800C7380(Unk800C7A4C_Group* g, int v)
{
    int d = v - g->m28;
    g->m28 = v;
    if (g->m40 != 0)
        g->m40->fn_vslot10(g->m40->m28 + d);
    if (g->m44 != 0)
        g->m44->fn_vslot10(g->m44->m28 + d);
    if (g->m48 != 0)
        g->m48->fn_vslot10(g->m48->m28 + d);
    if (g->m4C != 0)
        g->m4C->fn_vslot10(g->m4C->m28 + d);
    if (g->m50 != 0)
        g->m50->fn_vslot10(g->m50->m28 + d);
}

extern "C" void fn_800C7490(Unk800C7A4C_Group* g, int v)
{
    g->m2E = v;
    if (g->m40 != 0)
        g->m40->fn_vslot18(v);
    if (g->m44 != 0)
        g->m44->fn_vslot18(v);
    if (g->m48 != 0)
        g->m48->fn_vslot18(v);
    if (g->m4C != 0)
        g->m4C->fn_vslot18(v);
    if (g->m50 != 0)
        g->m50->fn_vslot18(v);
}

void Unk800C7A4C_Group::fn_800C7584(Unk800C7B40_Widget* c)
{
    m40 = c;
    c->fn_vslot18(m2E);
    m40->fn_vslot8(1);
}

void Unk800C7A4C_Group::fn_800C75F0(Unk800C7B40_Widget* c)
{
    m44 = c;
    c->fn_vslot18(m2E);
    m44->fn_vslot8(1);
}

void Unk800C7A4C_Group::fn_800C765C(Unk800C7B40_Widget* c)
{
    m48 = c;
    c->fn_vslot18(m2E);
    m48->fn_vslot8(1);
}

void Unk800C7A4C_Group::fn_800C76C8(Unk800C7B40_Widget* c)
{
    m4C = c;
    c->fn_vslot18(m2E);
    m4C->fn_vslot8(1);
}

void Unk800C7A4C_Group::fn_800C7734(Unk800C7B40_Widget* c)
{
    m50 = c;
    c->fn_vslot18(m2E);
    m50->fn_vslot8(1);
}

extern "C" void fn_800C77A0(Unk800C77A0_Obj* w, int v)
{
    if (w->m54 != 0 && fn_800C80D4(w) != 0) {
        if (lbl_8061A32C == 0)
            lbl_8061A32C = fn_800B64BC((Unk800B64BC_Mgr*)operator new(0xD8, 0));
        Unk800CBAD0_Sub* t = *(Unk800CBAD0_Sub**)(lbl_8061A32C->mA0 + 0x1CC);
        if (t != 0)
            t->fn_vslot29(w->m54);
    }
    if (w->b7) {
        fn_802D7EE4(fn_800C8070(w));
        fn_802D7EE4(fn_800C8070(w));
        if (fn_800C80D4(w) != 0 && !w->b3)
            w->fn_vslot14(1);
        else if (fn_800C80D4(w) == 0 && w->b3)
            w->fn_vslot14(0);
    }
    fn_800C80DC(w, v);
}

extern "C" void fn_800C78DC(Unk800C7A4C_Group* g, float f)
{
    Unk800C7B40_Widget* kids[5] = {g->m40, g->m44, g->m48, g->m4C, g->m50};
    for (int i = 0; i < 5; i++) {
        if (kids[i] != 0)
            kids[i]->fn_vslot20(f);
    }
}

extern "C" void fn_800C7994(Unk800C7A4C_Group* g, float f)
{
    Unk800C7B40_Widget* kids[5] = {g->m40, g->m44, g->m48, g->m4C, g->m50};
    for (int i = 0; i < 5; i++) {
        Unk800C7B40_Widget* c = kids[i];
        if (c != 0)
            c->fn_vslot21(f);
    }
}
