/*
 * Game code, .text 0x800E4234-0x800E8890 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
/* newlib ctype table: byte zero is the EOF sentinel. */
extern "C" const char _ctype_[];

#include "game/tu_800E4234.h"

void fn_800E4234(int a0, int mode, unsigned short* out)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    char b8[0x68];
    char b70[0xC8];
    char b138[0x190];
    char b2C8[8];
    char b2D0[4];
    s->fn_8007B924(1, a0, b8);
    fn_80402EF8(b70, b8);
    int v = s->fn_80078A38(a0);
    if (v == 4)
        v = 0;
    unsigned short* t = fn_80090880(lbl_8061977C, fn_80083F6C(v));
    fn_80403DE4(b138, (const char*)fn_80090880(lbl_8061977C, 0x4F35), b70, t);
    int id;
    switch (mode) {
    case 0:
        id = 0x44CB;
        break;
    case 1:
        id = 0x44CC;
        break;
    case 2:
        id = 0x44CD;
        break;
    case 3:
        id = 0x44CE;
        break;
    case 4:
        id = 0x44CF;
        break;
    case 5:
        id = 0x44D0;
        break;
    case 6:
        id = 0x4629;
        break;
    case 7:
        id = 0x484C;
        break;
    default:
        *out = 0;
        return;
    }
    unsigned short* tx = fn_80090880(lbl_8061977C, id);
    if (mode == 5) {
        int w = -1;
        switch (v) {
        case 0:
            w = 0x19;
            break;
        case 1:
            w = 0x14;
            break;
        case 2:
            w = 0x14;
            break;
        case 3:
            w = 0x14;
            break;
        }
        fn_804031BC(b2C8, lbl_805BC1A8);
        fn_80403DE4(b2D0, b2C8, w);
        fn_8040321C(out, tx, b138, b2D0);
        return;
    }
    fn_804031F8(out, tx, b138);
}

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

int fn_800A1C54(void* g, int b, int c, int d, int e, int f);
extern "C" void fn_800A19E4(int a, int flag);
extern int lbl_8061A308;
void fn_800E63A4(Ue63A4* t);

extern "C" void fn_800E49DC()
{
    int sel = 3;
    if (fn_800B56C4(fn_800B555C()) == 1)
        sel = 0;
    else if (fn_800B5758(fn_800B555C()) == 1)
        sel = 1;
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
    int i = 0;
    int a = fn_800B555C()->m588;
    int b = fn_800B555C()->m590;
    int c = *(int*)((char*)fn_800B555C() + 0x528);
    fn_800A1C54(lbl_80619948, sel, flags, a, b, c);
    fn_800A19E4(0x3F, 1);
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int n = s->fn_8007B2B0();
    if (i < n) {
        do {
            int h = s->fn_8007B2FC(i);
            i++;
            s->fn_8007B4A8(0x10, h, s->fn_8007B8C4(0x37, s->fn_8007B320(0, h)));
        } while (i < n);
    }
    fn_800B555C()->m530 = 1;
    if (lbl_8061A308 == 0)
        fn_800E63A4((Ue63A4*)fn_8007FE04((Unk8007B2B0_Screen*)lbl_8061930C));
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

/* near-miss: 14 slots; k and the inner counter i have their callee-saved registers swapped (r25/r24) and two argument-setup pairs are ordered differently */
void fn_800E5100(unsigned short* out, int arg1)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    char b8[0xC8];
    char bD0[0xC8];
    char b198[0x68];
    char b200[0xC8];
    int e = fn_800B57EC(fn_800B555C());
    int k = 0;
    fn_80403144(out, fn_80090880(lbl_8061977C, 0x238C));
    fn_800DFF0C(out, fn_80090880(lbl_8061977C, 0x4ED2));
    do {
        unsigned i = 0;
        while (i < fn_80599C40(arg1, k)) {
            int id = fn_80599C50(arg1, k, i);
            int w = fn_80077BC4(s, id);
            int o;
            if ((e == 0 || fn_8007FE04(s)->m1DC != 1 || (o = (int)fn_8007F7D0((int)s, 0), w == s->fn_8007B320(0, o)) || w == s->fn_8007B320(1, o) || w == s->fn_8007B320(2, o) || w == s->fn_8007B320(3, o)) && w != 0) {
                fn_800DE440(bD0, id, 1);
                s->fn_8007B924(2, w, b198);
                fn_804031BC(b200, b198);
                fn_80403DE4(b8, (const char*)fn_80090880(lbl_8061977C, 0x4ED3), bD0, b200);
                fn_800DFF0C(out, (unsigned short*)b8);
            }
            i++;
        }
        if (k == 0 && e == 0)
            fn_800DFF0C(out, fn_80090880(lbl_8061977C, 0x4ED4));
        k++;
    } while (k <= 1);
}

/* near-miss: 35 vs 34 insns; retail keeps the `li r3,0` result in r3 while ours merges the zero with the sum register */
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

void fn_800E5380(UiS* self)
{
    void* o = fn_8007F7D0(lbl_8061930C, 0);
    int t = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B320(0, (int)o);
    float f = fn_80551A80(t, 0);
    fn_800DC580(fn_800C8044(self->v32(lbl_805BC180, 1)), f);
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

int fn_800E5C74(int a, int b, int c)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int k = 0;
    unsigned i = 0;
    void* o = fn_8007F7D0(lbl_8061930C, 0);
    for (; i < (unsigned)fn_8007B7A4(s, o); i++) {
        if (fn_8007B7C8(s, o, i) == a && fn_8007B7EC(s, o, i) == b && (b != 7 || fn_8007B858(s, o, i) == c))
            k += fn_8007B834(s, o, i);
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

int fn_800E5D74(int a)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int flag = 0;
    int e = fn_800B57EC(fn_800B555C());
    int d = fn_800B5758(fn_800B555C());
    int x = fn_8007FE04(s)->m1E0 == 1;
    if (e != 0 && (x != 0 || d != 0))
        flag = 1;
    int n = ((Unk8007A4DC_Screen*)s)->fn_8007A6A0(0x19, a);
    int r;
    if (n <= 0 || flag == 0)
        r = 0x1A47;
    else if (n <= 1)
        r = 0x4D6C;
    else if (n > 2) {
        r = 0x4D6E;
        if (n > 3)
            r = 0x4D6F;
    } else
        r = 0x4D6D;
    return r;
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

int fn_800E6058(int x)
{
    if (x <= 0x31) {
        Ue6058_T loc = lbl_805BDF00;
        return loc.m[x];
    }
    return 8;
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
        if (*(unsigned char*)((char*)((const unsigned char*)_ctype_ + 1) + o) & 1)
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

/* near-miss: 17 slots, only the callee-saved registers of b and the inner counter j are swapped (r30/r29); tried all 24 declaration orders */
void fn_800E6708(Ue6888* t)
{
    UiVK* a = (UiVK*)t->p0;
    UiVK* b = (UiVK*)t->p4;
    int i = 0;
    int j;
    a->v79(0xFA, 0);
    b->v79(0xFA, 0);
    while (i < a->v59()) {
        j = 0;
        while (j < a->v58()) {
            int jj = j;
            j++;
            a->v44(i, jj, (const char*)lbl_805B6F58, 4);
        }
        i++;
    }
    i = 0;
    while (i < b->v59()) {
        j = 0;
        while (j < b->v58()) {
            int jj = j;
            j++;
            b->v44(i, jj, (const char*)lbl_805B6F58, 4);
        }
        i++;
    }
    t->m10 = 0;
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

class Ue7888_W {
public:
    char pad0[0x3C];
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43(int a, int b, unsigned short* c, int d);
};
struct Ue7888_T {
    char pad0[0x14];
    char* m14;
};
struct Ue7888_O {
    Ue7888_W* m0;
    int m4;
    Ue7888_T* m8;
    int mC;
    int m10;
};
extern "C" int fn_8009764C(char* r, int a, int b, int c);
extern "C" int fn_800968C0(char* r, int q, int c);
extern "C" void fn_800DFEAC(unsigned short* d, const char* s);
void fn_800DE354(int a0, void* o, int idx, int q, int f);
extern "C" int fn_80403060(unsigned short* s);
extern "C" int sprintf(char*, const char*, ...);
extern char lbl_805BDFE8[];
extern char lbl_805BE020[];
extern char lbl_805BE024[];
extern char lbl_805BE02C[];

void fn_800E7888(Ue7888_O* o, int idx)
{
    unsigned short t1[0xC8];
    unsigned short t2[0xC8];
    char t3[0x10];
    int* c = &o->m10;
    Ue7888_W* w = o->m0;
    char* rec = o->m8->m14 + idx * 0xE64;
    *c = *c + 1;
    int count = 0;
    int i = 0;
    fn_80403144(t1, fn_80090880(lbl_8061977C, 0xC82));
    fn_800DFEAC(t1, lbl_805BDFE8);
    w->s43(*c, 0, t1, 4);
    *c = *c + 1;
    fn_80403144(t1, fn_80090880(lbl_8061977C, 0x1982));
    fn_800DFEAC(t1, lbl_805BE020);
    unsigned char cnt = rec[0x235];
    for (; i < cnt; i++) {
        int off = (i * 8) & 0x7F8;
        char* b = rec + 0x238;
        int q = *(int*)(b + off);
        int n = fn_8009764C(rec, 0xD, fn_800968C0(rec, q, 1), 0);
        if (n > 0) {
            count++;
            if (count > 1)
                fn_800DFEAC(t1, lbl_805BE024);
            fn_800DE354((int)t2, o->m8, idx, q, 1);
            if (n > 1) {
                sprintf(t3, lbl_805BE02C, n);
                fn_800DFEAC(t2, t3);
            }
            if (fn_80403060(t1) + fn_80403060(t2) > 0x3E) {
                w->s43(*c, 0, t1, 4);
                fn_80403144(t1, t2);
                *c = *c + 1;
            } else {
                fn_800DFF0C(t1, t2);
            }
        }
    }
    if (count > 0) {
        w->s43(*c, 0, t1, 4);
        *c = *c + 1;
    }
    *c = *c + 1;
}
