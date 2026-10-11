/*
 * Game code, .text 0x800E4234-0x800E8890 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800E4234.h"

void fn_800E442C(UiS* self, int x)
{
    int k = fn_800E4504(x);
    int en = fn_800B57EC(fn_800B555C());
    for (int i = 0; i <= 4; i++) {
        char buf[16];
        fn_804089B4(buf, lbl_805BDE14, i);
        UiS* w = self->v30(buf, 1);
        if (en != 0)
            w->v8(i == k);
        else
            w->v8(0);
    }
}

int fn_800E4504(int a)
{
    float v = fn_805520E4(a, 0, 0, 0, 0);
    int i = 0;
    int r = 0;
    if (!(v > lbl_805C3C70[0])) {
        while (++i <= 4) {
            if (!(v <= lbl_805C3C70[i])) {
                r = i;
                break;
            }
        }
    }
    return r;
}

int fn_800E4584(int a, int b, int c)
{
    if (fn_800B5758(fn_800B555C()) == 0)
        return 0;
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int id = 0;
    switch (b) {
    case 0:
        id = c == 0 ? 0 : 1;
        break;
    case 1:
        id = c == 0 ? 2 : 3;
        break;
    case 2:
        id = c == 0 ? 4 : 5;
        break;
    case 3:
        id = c == 0 ? 6 : 7;
        break;
    case 4:
        id = 9;
        break;
    }
    return s->fn_8007B380(fn_8008FE14(id), a);
}

int fn_800E4674(int x)
{
    switch (x) {
    case 14:
        return 3;
    case 13:
        return 3;
    case 12:
        return 2;
    case 11:
        return 2;
    case 10:
        return 1;
    case 9:
        return 1;
    case 8:
        return 0;
    case 7:
        return 0;
    case 16:
        return 4;
    }
    return 0;
}

int fn_800E4874(void* a)
{
    int s = lbl_8061930C;
    int n = fn_80080070(s);
    if (n > 0) {
        int i = n - 1;
        int c = n;
        do {
            Ue12* e = fn_8008007C(s, i);
            if (e->m12 != 0 || fn_800E46FC(a, e) == 0)
                n--;
            i--;
        } while (--c != 0);
    }
    return n;
}

int fn_800E48FC(int x)
{
    switch (x) {
    case 0:
        return 0;
    case 13:
    case 14:
    case 15:
        return 1;
    case 1:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        return 2;
    case 16:
        return 3;
    case 2:
        return 4;
    case 3:
        return 5;
    case 4:
        return 6;
    }
    return 0;
}

void fn_800E49A4()
{
    Unk800E49A4_S* s = (Unk800E49A4_S*)((char*)fn_800B555C() + 8);
    s->m510 = 0;
    s->m514 = 0;
    s->m518 = 0;
    s->m51C = 0;
}

void fn_800E4B70()
{
    int flags = 2;
    if (fn_800B555C()->m530 == 0)
        flags = 6;
    if (fn_800B555C()->m588 != 0) {
        switch (fn_800B555C()->m58C) {
        case 0:
            flags |= 8;
            break;
        case 1:
            flags |= 0x10;
            break;
        case 2:
            flags |= 0x20;
            break;
        default:
            flags |= 8;
            break;
        }
    }
    int a = fn_800B555C()->m588;
    int b = fn_800B555C()->m590;
    fn_800A1F24(lbl_80619948, flags, a, b);
}

int fn_800E4FDC()
{
    return 1;
}

void fn_800E4FE4(UiS* self, int x)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    UiS* w = (UiS*)fn_800C8040(self->v32(lbl_805BDC74, 1));
    char buf[200];
    float f;
    if (fn_800B56C4(fn_800B555C())) {
        f = s->fn_80079EFC(x);
        fn_800DF254(buf, 0, 3, f);
        if (fn_8007FE04(s)->m1E0 == 1)
            w->v28(buf);
        else
            w->v29(0x1A4B);
    } else {
        f = *(float*)(**(int**)((char*)s + 0x30) + 0x10000 + 0x2B78);
        fn_800DF254(buf, 0, 0, f);
        w->v28(buf);
    }
}

int fn_800E52F8(int n)
{
    int r = 0;
    int* p = **(int***)(lbl_8061930C + 0x30);
    if (n > 0) {
        int sum = 0;
        int idx = fn_80591A50(p);
        for (int i = 0; i < n; i++) {
            sum += fn_8059394C(p, fn_80592E04(p, idx));
            idx--;
        }
        r = sum / n;
    }
    return r;
}

int fn_800E5BF0(int a)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int k = 0;
    unsigned i = 0;
    void* o = fn_8007F7D0(lbl_8061930C, 0);
    for (; i < (unsigned)fn_8007B7A4(s, o); i++) {
        if (fn_8007B7EC(s, o, i) == a)
            k++;
    }
    return k;
}

int fn_800E5D48(int x)
{
    switch (x) {
    case 0x42:
        return 7;
    case 0x43:
        return 8;
    default:
        return 7;
    }
}

extern "C" const char* fn_800E5E4C(int x)
{
    switch (x) {
    case 0:
        return lbl_805BDEC8;
    case 1:
        return lbl_805BDECC;
    case 2:
        return lbl_805BDED0;
    case 3:
        return lbl_805BDED4;
    case 4:
        return lbl_805BDED8;
    case 5:
        return lbl_805BA658;
    case 6:
        return lbl_805BA6A4;
    case 7:
        return lbl_805BDEDC;
    case 8:
        return lbl_805BDEE0;
    case 9:
        return lbl_805BDEE4;
    }
    return 0;
}

const char* fn_800E5F38(int x)
{
    switch (x) {
    case 0:
        return lbl_805BDEE8;
    case 1:
        return lbl_805BDECC;
    case 2:
        return lbl_805BDED0;
    case 3:
        return lbl_805BDED4;
    case 4:
        return lbl_805BDED8;
    case 5:
        return lbl_805BA658;
    case 6:
        return lbl_805BA6A4;
    case 7:
        return lbl_805BDEDC;
    case 8:
        return lbl_805BDEE0;
    case 9:
        return lbl_805BDEE4;
    case 10:
        return lbl_805BDEEC;
    case 11:
        return lbl_805BDEF0;
    case 12:
        return lbl_805BDEF4;
    case 13:
        return lbl_805BDEF8;
    }
    return 0;
}

int fn_800E60E0(int x)
{
    int r;
    if (x > 2) {
        r = 0x2B34;
    } else {
        Unk800E60E0_T loc = lbl_805BDFC8;
        r = loc.m[x];
    }
    return r;
}

void fn_800E6128()
{
    fn_800E6158();
    fn_800E6318(fn_8007DA28(lbl_8061930C));
}

void fn_800E6158()
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int h = s->fn_8007DA28();
    if (h != -1) {
        for (int i = 0; i <= 0x76; i++)
            s->fn_8007D1C8(h, i, 1);
        for (int i = 0; i <= 0xE; i++)
            s->fn_8007D25C(h, i, 1);
        for (int i = 0; i <= 0x3E; i++) {
            s->fn_8007D2A8(h, i, 1);
            fn_80075A44(s, h, i);
        }
        for (int i = 0; i <= 1; i++)
            s->fn_8007D2F4(h, i, 1);
        s->fn_8007D340(h, 0, 1);
        s->fn_8007DB40(h);
    }
}

void fn_800E6258(int a, int b)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    if (a != -1) {
        if (fn_800E62C4(a, b) == 0) {
            if (b == 4) {
                s->fn_8007D214(a, 0);
                s->fn_8007DB40(a);
            }
        }
    }
}

int fn_800E62C4(int a, int b)
{
    int o = lbl_8061930C;
    if (a == -1) {
        return 0;
    }
    int r = 0;
    if (b == 4) {
        r = fn_8007D3D4(o, a, 0);
    }
    return r;
}

void fn_800E6318(int a)
{
    fn_800E6258(a, 4);
}

void fn_800E633C(char* s)
{
    int n = fn_8040B6A0(s);
    for (int i = 0; i < n; i++) {
        int c = s[i];
        int o = c;
        if (*(unsigned char*)((char*)lbl_8060E9F1 + o) & 1)
            c += 0x20;
        s[i] = c;
    }
}

void fn_800E63A4(Ue63A4* t)
{
    int a = t->m14;
    int m = t->m18;
    if (m > a)
        m = a;
    switch (m) {
    case 0:
        t->mC = 2;
        t->m184 = 1;
        t->m148 = 0;
        t->m14C = 0;
        t->m188 = 1;
        t->m10 = 1;
        break;
    case 1:
        t->m148 = 0;
        t->mC = 1;
        t->m184 = 1;
        t->m14C = 1;
        t->m188 = 1;
        t->m10 = 1;
        break;
    case 2:
        t->mC = 1;
        t->m184 = 0;
        t->m148 = 1;
        t->m14C = 1;
        t->m188 = 0;
        t->m10 = 0;
        break;
    case 3:
        t->mC = 0;
        t->m184 = 0;
        t->m148 = 1;
        t->m14C = 1;
        t->m188 = 0;
        t->m10 = 0;
        break;
    }
}

Unk800E6470_O* fn_800E6470(Unk800E6470_O* t)
{
    t->m0 = 0;
    t->m4 = 0;
    t->m8 = 0;
    t->mC = 1;
    t->m10 = 0;
    t->mDC = 0;
    t->mE0 = 0;
    t->mE4 = 0;
    t->mE8 = -1;
    t->mF4 = 0;
    return t;
}

void fn_800E64AC(void* t, int f)
{
    if (f & 1) {
        fn_80377408(t);
    }
}

void fn_800E6888(Ue6888* t)
{
    UiS* a = t->p0;
    UiS* b = t->p4;
    ((UiVF*)a)->v79(t->m10, 0);
    ((UiVF*)a)->v68(0);
    ((UiVF*)b)->v79(t->m10, 0);
    ((UiVF*)b)->v68(0);
    ((UiVF*)b)->v14(1);
}
