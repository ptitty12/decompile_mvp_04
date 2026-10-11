/*
 * Game code, .text 0x800C2F90-0x800C5158 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800BCD38.h"

extern "C" {
int fn_804089B4(char* dst, const char* fmt, ...);
}

extern const float lbl_805BBE14;
extern float lbl_805BBE18;
extern const float lbl_805BBE28;
extern const float lbl_805BBE34;
extern const float lbl_805BBE40;
extern const float lbl_805BBE54;
extern const char lbl_805BBE1C[];
extern const char lbl_805BBE2C[];
extern const char lbl_805BBE38[];
extern const char lbl_805BBE4C[];
extern char lbl_805B6F58;
extern const float lbl_805BBF48;
extern const float lbl_805BBEA8;
extern const float lbl_805BBEC4;
extern const char lbl_805BBF40[];
extern const char lbl_805BBEA0[];
extern const char lbl_805BBEBC[];
struct Unk800C493C_Letters {
    char c[6];
};
struct Unk800C49C4_Letters {
    char c[13];
};
extern const Unk800C493C_Letters lbl_805BBE98 __attribute__((aligned(4)));
extern const Unk800C49C4_Letters lbl_805BBEAC __attribute__((aligned(4)));
extern "C" int fn_8040B574(const char* a, const char* b);
extern "C" void fn_80433004(void* a, int b);
extern "C" int fn_800C5CF8(Unk800C341C_Mgr* m, const char* name);
extern "C" void* fn_803774A8(unsigned n, int heap);
extern "C" void fn_80377488(void* p);
extern "C" int fn_800C519C(Unk800C341C_Mgr* mgr, int n);
extern const float lbl_805BBE44;
extern const float lbl_805BBE48;
extern const char lbl_805BBE6C[];
extern const char lbl_805BB0E4[];
extern Unk800C341C_Mgr* lbl_8061ABDC;
extern int lbl_8061A708[];
extern "C" {
int fn_800C2FE8(Unk800C2250_File* f);
void fn_803FB764(int a, int b, int c);
void fn_80400CE4(int a);
void fn_803FB888(int a);
int fn_803FB6FC(int a);
void fn_803FFFA8(int a);
void* fn_802B0638(void* obj, const char* name, int a);
}

extern void* lbl_8061E978;
struct Unk800C4C48_Tbl {
    int v[16];
};
extern const Unk800C4C48_Tbl lbl_805BBEF4 __attribute__((aligned(4)));
extern const char lbl_805BBF34[];
extern const float lbl_805BBF3C;
extern const float lbl_805BBE74;
extern const float lbl_805BBE78;
extern const float lbl_805BBE7C;
extern const float lbl_805BBE80;
extern const float lbl_805BBE94;
extern const float lbl_805BBED0;
extern const float lbl_805BBEDC;
extern const float lbl_805BBEE8;
extern const float lbl_805BBEEC;
extern const float lbl_805BBEF0;
extern const char lbl_805BBE84[];
extern const char lbl_805BBE8C[];
extern const char lbl_805BBEC8[];
extern const char lbl_805BBED4[];
extern const char lbl_805BBEE0[];
extern const char* lbl_8061A864[];
extern const char* lbl_8061AA40[];
extern const char* lbl_8061AB78[];
extern const char* lbl_8061AB3C[];

extern "C" int fn_800C2F90(Unk800C2250_File* f, int i)
{
    if (f->m40C[i] != 0)
        return 1;
    return 0;
}

extern "C" Unk800C1BE4_Widget* fn_800C2FB0(Unk800C2250_File* f, int i)
{
    return f->m40C[i];
}

extern "C" Unk800C1BE4_Widget* fn_800C2FC0(Unk800C2250_File* f, int i)
{
    return f->m40C[i];
}

extern "C" float fn_800C2FD0(Unk800C2250_File* f, int i)
{
    return f->m430[i];
}

extern "C" void* fn_800C2FE0(Unk800C2250_File* f)
{
    return f->m45C;
}

extern "C" int fn_800C2FE8(Unk800C2250_File* f)
{
    return f->m458;
}

extern "C" void fn_800C2FF0(Unk800C2250_File* f)
{
    f->m0 = lbl_805B6F58;
    f->m400 = 0;
    f->m404 = 0;
    f->m408 = 0;
    for (int i = 0; i < 9; i++) {
        f->m40C[i] = 0;
        f->m430[i] = lbl_805BBE14;
    }
    f->m454 = 0;
    f->m458 = 0;
    f->m45C = 0;
    f->m460 = 0;
    f->m464 = 0;
}

extern "C" void fn_800C313C(Unk800C2250_File* f)
{
    int i = 0;
    fn_80433004(f->m45C, f->m460);
    for (; i < fn_800C2F88(f); i++) {
        if (fn_800C2F90(f, i)) {
            Unk800C1BE4_Widget* w = fn_800C2FB0(f, i);
            w->fn_vslot28(fn_800C2F84(f), 0);
            w->fn_vslot8(1);
        }
    }
}

/* near-miss: 1 slot (retail ble where we emit blt after the case-3 beq); switch spellings tried: case order, if chain, enum index */
extern "C" void fn_800C31FC(Unk800C2250_File* f)
{
    switch (fn_800C2F74(f)) {
    case 3:
        if (fn_800C33D0()->m0 != 0) {
            fn_803FB764(fn_800C2FE8(f), 0, 0);
            fn_80400CE4(0);
        } else {
            fn_803FB888(fn_800C2FE8(f));
            while (!fn_803FB6FC(fn_800C2FE8(f))) {
                fn_803FFFA8(50);
                fn_80400CE4(0);
            }
        }
        break;
    case 4:
    case 5:
        fn_802B0638(lbl_8061E978, fn_800C2F84(f), 0);
        break;
    }
}

extern "C" int fn_800C32C4(void* unused, int kind, void** out)
{
    int size = fn_800C519C(fn_800C33D0(), kind);
    switch (kind) {
    case 0:
        break;
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        *out = fn_803774A8(size, 0x500);
        break;
    }
    return size;
}

extern "C" void fn_800C334C(Unk800C2250_File* f)
{
    if (f->m45C != 0) {
        switch (f->m400) {
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            delete[] (char*)f->m45C;
            f->m45C = 0;
            f->m464 = 60;
            break;
        }
    }
}

extern "C" Unk800C341C_Mgr* fn_800C33D0()
{
    if (lbl_8061ABDC == 0)
        lbl_8061ABDC = fn_800C341C((Unk800C341C_Mgr*)operator new(0x5DAC, 0));
    return lbl_8061ABDC;
}

extern "C" void fn_800C3774(Unk800C341C_Mgr* m)
{
    fn_800C3D50(m);
    fn_800C5010(m);
    fn_800C5AF8(m);
    fn_800C5080(m);
    fn_800C5B58(m);
    fn_800C3A4C(m);
    fn_800C3A10(m);
    if (m->m8 != 0) {
        fn_803FEDB8(m->m8, 100);
        m->m8 = 0;
    }
    if (m->m1C != 0) {
        fn_803FEDB8(m->m1C, 100);
        m->m1C = 0;
    }
    if (m->m4 == 1)
        fn_800C3828(m);
    fn_803FB4B0();
    m->m4 = 0;
}

/* near-miss: the loop matches except the order of the five stores (retail: stw 0, stb 4, stw 0x404, lfs, stw 0x40C, stfs 0x408); lbl_805BBE18 must be non-const to keep the lfs in the loop */
extern "C" void fn_800C3A10(Unk800C341C_Mgr* m)
{
    Unk800C3A10_Rec* r = m->recs;
    for (int i = 0; i < 12; i++) {
        r->m0 = 0;
        r->m4 = 0;
        r->m404 = 0;
        r->m40C = 0;
        r->m408 = lbl_805BBE18;
        r++;
    }
    m->m5D94 = 0;
}

extern "C" void fn_800C3A4C(Unk800C341C_Mgr* m)
{
    for (int i = 0; i < 10; i++) {
        Unk800C2250_File* f = &m->files[i];
        if (fn_800C2EF0(f) && fn_800C2F74(f) == 6) {
            fn_800C334C(f);
            fn_800C2FF0(f);
        }
    }
}

extern "C" void fn_800C3AB4(Unk800C341C_Mgr* m, int n)
{
    if (n > 10)
        n = 10;
    m->m5DA4 = n;
}

extern "C" void fn_800C3AC8(Unk800C341C_Mgr* m)
{
    for (int i = 0; i < 10; i++)
        fn_800C2C78(&m->files[i]);
    fn_800C3B14(m);
}

extern "C" void fn_800C3B14(Unk800C341C_Mgr* m)
{
    int i = 0;
    int n = m->m5D94;
    if (i < n) {
        do {
            if (fn_800C58E8(m, m->recs[0].m0) == -1)
                break;
            switch (m->recs[0].m0) {
            case 2:
                fn_800C435C(m, m->recs[0].m404, m->recs[0].m408, m->recs[0].m4_name(), m->recs[0].m40C);
                break;
            case 8:
                fn_800C4D90(m, m->recs[0].m404, m->recs[0].m408, m->recs[0].m4_name(), m->recs[0].m40C);
                break;
            default:
                fn_800C537C(m, m->recs[0].m0, m->recs[0].m4_name(), m->recs[0].m404, m->recs[0].m408, m->recs[0].m40C);
                break;
            }
            fn_800C56C0(m, 0);
            i++;
        } while (i < n);
    }
}

extern "C" void fn_800C3BE0(Unk800C341C_Mgr* m)
{
    m->m0 = 1;
    for (int i = 0; i < 10; i++) {
        Unk800C2250_File* f = &m->files[i];
        if (fn_800C2EF0(f) && !fn_800C2F08(f) && !fn_800C2F1C(f) && !fn_800C2F30(f))
            fn_800C2458(f);
    }
    m->m0 = 0;
    fn_800C3A10(m);
    m->m5DA4 = 10;
}

extern "C" void fn_800C3C80(Unk800C341C_Mgr* m, Unk800C1BE4_Widget* w)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk800C2250_File* f = &m->files[i];
        if (fn_800C2EF0(f) && !fn_800C2F08(f) && !fn_800C2F30(f)) {
            int idx = fn_800C2998(f, w);
            if (idx != -1)
                fn_800C2B94(f, idx);
        }
    }
    int n = m->m5D94;
    for (i = 0; i < n; i++) {
        if (m->recs[i].m404 == (int)w)
            fn_800C56C0(m, i);
    }
}

extern "C" void fn_800C3D50(Unk800C341C_Mgr* m)
{
    for (int i = 0; i < 10; i++) {
        Unk800C2250_File* f = &m->files[i];
        if (fn_800C2EF0(f) && !fn_800C2F08(f) && !fn_800C2F1C(f))
            fn_800C2458(f);
    }
    fn_800C3A10(m);
}

extern "C" void fn_800C422C(Unk800C341C_Mgr* m, int idx, int a, int b, int unused, int d)
{
    char buf[1024];
    fn_804089B4(buf, lbl_805BBE1C, a + 0x61, b + 0x61, 0x64, d + 0x61);
    fn_800C537C(m, 1, buf, idx, lbl_805BBE28, 1);
}

extern "C" void fn_800C429C(Unk800C341C_Mgr* m, int idx, int x)
{
    char buf[1024];
    fn_804089B4(buf, lbl_805BBE2C, x);
    fn_800C537C(m, 1, buf, idx, lbl_805BBE34, 1);
}

extern "C" void fn_800C42FC(Unk800C341C_Mgr* m, int idx, int x)
{
    char buf[1024];
    fn_804089B4(buf, lbl_805BBE38, x);
    fn_800C537C(m, 1, buf, idx, lbl_805BBE40, 1);
}

extern "C" void fn_800C44E8(Unk800C341C_Mgr* m, Unk800C1BE4_Widget* w, int idx)
{
    int name = lbl_8061A708[idx];
    if (w != 0)
        w->fn_vslot20(lbl_805BBE44);
    fn_800C537C(m, 4, (const char*)name, (int)w, lbl_805BBE48, 1);
}

extern "C" void fn_800C4568(Unk800C341C_Mgr* m, int idx, int x)
{
    char buf[1024];
    fn_804089B4(buf, lbl_805BBE4C, x);
    fn_800C537C(m, 5, buf, idx, lbl_805BBE54, 1);
}

extern "C" void fn_800C4720(Unk800C341C_Mgr* m, Unk800D2338_Obj* w)
{
    char buf[0x400];
    fn_804089B4(buf, lbl_805BBE6C, w->fn_vslot33(0), lbl_805BB0E4);
    int idx = fn_800C5CF8(m, buf);
    if (idx != -1) {
        Unk800C2250_File* f = &m->files[idx];
        fn_800C2B94(f, fn_800C2998(f, 0));
    }
    ((Unk800CFEEC_Sel*)((char*)w + 0x98))->fn_vslot15();
}

extern "C" void fn_800C47DC(Unk800C341C_Mgr* m, int idx, int x)
{
    fn_800C537C(m, 13, lbl_8061A864[x], idx, lbl_805BBE74, 1);
}

extern "C" void fn_800C4820(Unk800C341C_Mgr* m, int idx, int x)
{
    fn_800C537C(m, 10, lbl_8061AA40[x], idx, lbl_805BBE78, 1);
}

extern "C" void fn_800C4864(Unk800C341C_Mgr* m, int idx, int x)
{
    fn_800C537C(m, 0xb, *(const char**)((char*)lbl_8061AB78 + x * 4), idx, lbl_805BBE7C, 1);
}

extern "C" void fn_800C48A8(Unk800C341C_Mgr* m, int idx, int x)
{
    fn_800C537C(m, 12, lbl_8061AB3C[x], idx, lbl_805BBE80, 1);
}

extern "C" void fn_800C48EC(Unk800C341C_Mgr* m, int idx, int flag)
{
    const char* name;
    if (flag != 0)
        name = lbl_805BBE84;
    else
        name = lbl_805BBE8C;
    fn_800C537C(m, 0xc, name, idx, lbl_805BBE94, 1);
}

extern "C" void fn_800C493C(Unk800C341C_Mgr* m, int idx, int k)
{
    Unk800C493C_Letters t __attribute__((aligned(4))) = lbl_805BBE98;
    char buf[24];
    fn_804089B4(buf, lbl_805BBEA0, t.c[k]);
    fn_800C537C(m, 0xe, buf, idx, lbl_805BBEA8, 1);
}

extern "C" void fn_800C49C4(Unk800C341C_Mgr* m, int idx, int k, int z)
{
    Unk800C49C4_Letters t __attribute__((aligned(4))) = lbl_805BBEAC;
    char buf[24];
    if (k == 0)
        z = 0;
    fn_804089B4(buf, lbl_805BBEBC, t.c[k], z);
    fn_800C537C(m, 0xf, buf, idx, lbl_805BBEC4, 1);
}

extern "C" void fn_800C4A68(Unk800C341C_Mgr* m, int idx, int x)
{
    char buf[24];
    fn_804089B4(buf, lbl_805BBEC8, x);
    fn_800C537C(m, 16, buf, idx, lbl_805BBED0, 1);
}

extern "C" void fn_800C4AC8(Unk800C341C_Mgr* m, int idx, int x)
{
    char buf[24];
    fn_804089B4(buf, lbl_805BBED4, x);
    fn_800C537C(m, 17, buf, idx, lbl_805BBEDC, 1);
}

extern "C" void fn_800C4B28(Unk800C341C_Mgr* m, int idx, int x)
{
    char buf[24];
    fn_804089B4(buf, lbl_805BBEE0, x);
    fn_800C537C(m, 18, buf, idx, lbl_805BBEE8, 1);
}

extern "C" void fn_800C4B88(Unk800C341C_Mgr* m, int idx, int x)
{
    char buf[24];
    fn_804089B4(buf, lbl_805BBEE0, x);
    fn_800C537C(m, 18, buf, idx, lbl_805BBEEC, 1);
}

extern "C" void fn_800C4BE8(Unk800C341C_Mgr* m, int idx, int x)
{
    char buf[24];
    fn_804089B4(buf, lbl_805BBEC8, x);
    fn_800C537C(m, 16, buf, idx, lbl_805BBEF0, 1);
}

extern "C" void fn_800C4C48(Unk800C341C_Mgr* m, int w, int idx)
{
    Unk800C4C48_Tbl t __attribute__((aligned(4))) = lbl_805BBEF4;
    char buf[20];
    fn_804089B4(buf, lbl_805BBF34, t.v[idx]);
    fn_800C537C(m, 0x13, buf, w, lbl_805BBF3C, 1);
}

extern "C" void fn_800C4D28(Unk800C341C_Mgr* m, int idx, int x, int y)
{
    char buf[24];
    fn_804089B4(buf, lbl_805BBF40, x, (char)(y + 0x61));
    fn_800C537C(m, 0x14, buf, idx, lbl_805BBF48, 1);
}

extern "C" void fn_800C4EEC(Unk800C341C_Mgr* m, const char* name)
{
    int idx = fn_800C5CF8(m, name);
    if (idx != -1) {
        Unk800C2250_File* f;
        while (fn_800C2F88(f = &m->files[idx])) {
            if (fn_800C2F90(f, 0))
                fn_800C2B94(f, 0);
        }
    }
}

extern "C" void fn_800C4F64(Unk800C341C_Mgr* m, const char* name)
{
    int idx = fn_800C5CF8(m, name);
    if (idx != -1)
        fn_800C2848(&m->files[idx]);
}

extern "C" void fn_800C4FA8(Unk800C341C_Mgr* m, const char* name)
{
    if (fn_8040B574(name, &lbl_805B6F58) != 0) {
        int idx = fn_800C5CF8(m, name);
        if (idx != -1)
            fn_800C28C8(&m->files[idx]);
    }
}

extern "C" void fn_800C5010(Unk800C341C_Mgr* m)
{
    for (int i = 0; i < 10; i++) {
        Unk800C2250_File* f = &m->files[i];
        if (fn_800C2F08(f) && fn_800C2F44(f) && !fn_800C2F30(f))
            fn_800C2848(f);
    }
}

extern "C" void fn_800C5080(Unk800C341C_Mgr* m)
{
    if (m->m5DA0 == 0) {
        for (int i = 0; i < 10; i++) {
            Unk800C2250_File* f = &m->files[i];
            if (fn_800C2F1C(f) && fn_800C2F5C(f))
                fn_800C28C8(f);
        }
    }
}

extern "C" int fn_800C50EC(Unk800C341C_Mgr* m, Unk800C1BE4_Widget* w)
{
    return fn_800C5C68(m, w);
}

extern "C" int fn_800C510C(Unk800C341C_Mgr* m, const char* name)
{
    return fn_800C5CF8(m, name);
}

extern "C" int fn_800C512C(Unk800C341C_Mgr* m, int idx)
{
    return fn_800C2F74(&m->files[idx]);
}
