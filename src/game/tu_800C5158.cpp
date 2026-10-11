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

extern "C" int fn_800C5158(Unk800C341C_Mgr* m, const char* name)
{
    int idx = fn_800C510C(m, name);
    if (idx == -1)
        return 0;
    return fn_800C512C(m, idx);
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
