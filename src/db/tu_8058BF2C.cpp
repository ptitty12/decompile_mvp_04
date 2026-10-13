/*
 * Database overlay code, .database_codeoverlay 0x8058BF2C-0x8058E5B8 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_80584CBC.h"

struct Db805822D0_V;

struct Db805822D0_D { int m0; };

struct Db8052E198_E { int m0; int m4; int m8; unsigned mC; unsigned short m10; unsigned short m12; const void* m14; };

struct Db805822D0_V : Db805822D0_D {
    virtual int v08();
    virtual int v10();
    virtual int v18();
};

struct Db8058C9B8_P { int a; int b; };

extern "C" Db805822D0_Base* fn_805822D0(Db805822D0_Base* self);
extern const char lbl_806834C0[];
extern const char lbl_806835F0[];
extern const char lbl_80683098[];
extern const char lbl_80682E18[];
extern "C" void fn_80582314(void* self);
extern "C" void fn_8040B320(void* dst, int c, unsigned n);
extern "C" void fn_80582C54(char* self, int a, Unk80070DDC_Stream* io);
extern "C" Db8052E198_E* fn_8052E198(Db8052E198_E* self, int a, int b, int c, int d, int e, char f, int g, int h, int i);
extern "C" int fn_80582CF8(Db805822D0_V* self, Db8052E198_E* e, int a, int b, int c); /* ends li r3,1 */
extern "C" int fn_8040ABA0();
extern Unk8007A4DC_Screen* lbl_8061930C;
int fn_8007F7D0(Unk8007F198_B* self, unsigned i);
extern "C" Db8052E198_E* fn_8052E234(Db8052E198_E* self, char a, int b, int c, int d, unsigned e, unsigned f, unsigned g, int h);
extern const Db8058C9B8_P lbl_8060095C;
extern const Db8058C9B8_P lbl_80600964;
extern const Db8058C9B8_P lbl_8060096C;

extern "C" int fn_805826AC(void* self, void* rec);
extern "C" int fn_800A4EA4(void* o);
struct Db8058DE40_R {
    char pad0[0x1D4];
    int m1D4;
};
extern "C" Db8058DE40_R* fn_8007FE04__FP13Unk8007F198_D(void* a0);

/* near-miss: 99.5%; retail keeps rec in r30 and the flag in r29 (callee-saved pair swapped) */

extern "C" int fn_8007FDF8__FP13Unk8007F198_D(void* a0);

extern "C" float fn_8007BB28__18Unk8007B2B0_Screeniii(void* a0, int a1, int a2, int a3);
struct Db8058CD14_O {
    char pad0[0x198];
    int m198;
};

extern "C" int fn_800968C0(void* p, int b, int c);
extern "C" int fn_8009764C(void* p, int a, unsigned char c, int d);

extern "C" int fn_80097EA4(void* p, int a, unsigned char b, int c, int d);
/* forward declarations (definitions are in address order) */
extern "C" Db805822D0_Base* fn_8058BF2C(Db805822D0_Base* self);
extern "C" void fn_8058BF68(Db805822D0_V* self);
extern "C" void fn_8058C020(Db805822D0_V* self);
extern "C" int fn_8058C304();
extern "C" Db805822D0_Base* fn_8058C34C(Db805822D0_Base* self);
extern "C" void fn_8058C388(char* self);
extern "C" void fn_8058C9B8(Db8058C9B8_P* out, int unused, int k);
extern "C" int fn_8058CA64(void* self, int a, int b, Db8058CD14_O* o, int c);
extern "C" int fn_8058CBC0(void* self, int a, int b, Db8058CD14_O* o, int c);
extern "C" int fn_8058CD14(void* self, int a, int b, Db8058CD14_O* o, int c);
extern "C" int fn_8058CE38(void* self, unsigned short* rec);
extern "C" void fn_8058CE50(void* self, unsigned short* rec, unsigned short* dst);
extern "C" int fn_8058CF18(int a, int b, void* rec);
extern "C" void fn_8058D028(char* self, int a, Unk80070DDC_Stream* io);
extern "C" Db805822D0_Base* fn_8058D080(Db805822D0_Base* self);
extern "C" int fn_8058D580(int self, int b, void* rec);
extern "C" int fn_8058D78C();
extern "C" void fn_8058D81C(void* self, void* rec, unsigned short* dst);
extern "C" int fn_8058DB0C(void* self, unsigned short* rec);
extern "C" void fn_8058DBEC(void* self, unsigned short* rec, unsigned short* dst);
extern "C" int fn_8058DCB4(int a, int b, void* rec);
extern "C" int fn_8058DE40(void* self, void* rec);
extern "C" void fn_8058DE9C(Db805822D0_V* self, int a, int b, int c, int d);
extern "C" int fn_8058E044(int a, int b, void* rec);
extern "C" Db805822D0_Base* fn_8058E144(Db805822D0_Base* self);
extern "C" void fn_8058E180(Db805822D0_V* self, int a);
extern "C" int fn_8058E244(int self, int b, void* rec);
extern "C" int fn_8058E470();
extern "C" int fn_8058E550();

extern "C" DB_OVERLAY Db805822D0_Base* fn_8058BF2C(Db805822D0_Base* self)
{
    fn_805822D0(self);
    self->m4 = lbl_806834C0;
    return self;
}

extern "C" DB_OVERLAY void fn_8058BF68(Db805822D0_V* self)
{
    int z = self->m0;
    if (z == 0) {
        int r = fn_8040ABA0();
        int m = r % 8;
        Db8052E198_E e;
        fn_8052E198(&e, self->v18(), 0, 0, 0, 0, m, 0, z, z);
        fn_80582CF8(self, &e, 0, 0, 0);
        fn_80360AF0((Db80586420_Ent*)&e, 2);
    }
}

extern "C" DB_OVERLAY void fn_8058C020(Db805822D0_V* self)
{
    int z = self->m0;
    if (z == 0) {
        Unk8007A4DC_Screen* s = lbl_8061930C;
        int t = fn_8007F7D0((Unk8007F198_B*)s, 0);
        int u = ((Unk8007B2B0_Screen*)s)->fn_8007B320(0, t);
        Db8052E198_E e;
        fn_8052E198(&e, self->v18(), u, 0, 0, 1, 0, 0, z, z);
        fn_80582CF8(self, &e, 0, 0, 0);
        fn_80360AF0((Db80586420_Ent*)&e, 2);
    }
}

extern "C" DB_OVERLAY int fn_8058C304()
{
    Db80586420_Ent e;
    Db80586420_Ent* pe = &e;
    int t = pe->mC.e;
    return t;
}

extern "C" DB_OVERLAY Db805822D0_Base* fn_8058C34C(Db805822D0_Base* self)
{
    fn_805822D0(self);
    self->m4 = lbl_806835F0;
    return self;
}

extern "C" DB_OVERLAY void fn_8058C388(char* self)
{
    fn_80582314(self);
    fn_8040B320(self + 8, 0, 0x12);
}

extern "C" DB_OVERLAY void fn_8058C9B8(Db8058C9B8_P* out, int unused, int k)
{
    switch (k) {
    case 0:
        *out = lbl_8060095C;
        break;
    case 1:
        *out = lbl_8060095C;
        break;
    case 2:
        *out = lbl_8060095C;
        break;
    case 3:
        *out = lbl_8060095C;
        break;
    case 4:
        *out = lbl_8060095C;
        break;
    case 5:
        *out = lbl_8060095C;
        break;
    case 6:
        *out = lbl_80600964;
        break;
    case 7:
        *out = lbl_8060096C;
        break;
    case 8:
        *out = lbl_8060096C;
        break;
    default:
        {
            Db8058C9B8_P z = { 0, 0 };
            *out = z;
        }
        break;
    }
}

extern "C" DB_OVERLAY int fn_8058CA64(void* self, int a, int b, Db8058CD14_O* o, int c)
{
    int w = o->m198;
    int k = fn_800968C0(o, a, 1);
    Unk8007A4DC_Screen* s = lbl_8061930C;
    int n = s->fn_800739E0(0xB, a, 1, 2);
    n += fn_80097EA4(o, 0xB, k, 2, 0);
    int t = (int)fn_8007BB28__18Unk8007B2B0_Screeniii(s, 2, w, 1);
    if (t > 0) {
        float x = (float)n * ((float)c / (float)t);
        float y = ((float)b * x) / (float)n;
        return (int)y;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8058CBC0(void* self, int a, int b, Db8058CD14_O* o, int c)
{
    int w = o->m198;
    int k = fn_800968C0(o, a, 1);
    Unk8007A4DC_Screen* s = lbl_8061930C;
    int n = s->fn_80074754(1, a, 1);
    n += fn_8009764C(o, 1, k, 0);
    int t = (int)fn_8007BB28__18Unk8007B2B0_Screeniii(s, 2, w, 1);
    if (t > 0) {
        float x = (float)n * ((float)c / (float)t);
        float y = ((float)b * x) / (float)n;
        return (int)y;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8058CD14(void* self, int a, int b, Db8058CD14_O* o, int c)
{
    Unk8007A4DC_Screen* s = lbl_8061930C;
    int w = o->m198;
    int n = s->fn_80074754(0, a, 1) + 1;
    int t = (int)fn_8007BB28__18Unk8007B2B0_Screeniii(s, 2, w, 1);
    if (t > 0) {
        float x = (float)n * ((float)c / (float)t);
        float y = ((float)b * x) / (float)n;
        return (int)y;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8058CE38(void* self, unsigned short* rec)
{
    int r = 2;
    if (rec[8] & 1)
        r = 13;
    return r;
}

/* near-miss: 99.5%; rec and the flag swap r29/r30 relative to retail */
extern "C" DB_OVERLAY void fn_8058CE50(void* self, unsigned short* rec, unsigned short* dst)
{
    fn_8058233C(self);
    int fl = rec[8] & 1;
    if (fn_800B5758(fn_800B555C()) && fl) {
        Db80586420_Ent e(rec);
        Db80586420_Ent* pe = &e;
        if (pe->m8 != 0) {
            unsigned short b[0x80];
            char n[0x80];
            Unk80090880* tb = lbl_8061977C;
            fn_800DE538((int)n, 3, pe->m8, 1);
            fn_80403DE4(b, ((DbLook)fn_80090880)(tb, 0x5C65), n, dst);
            fn_80403144(dst, b);
        }
    }
}

extern "C" DB_OVERLAY int fn_8058CF18(int a, int b, void* rec)
{
    Db80586420_Tri t = { -1, -1, -1 };
    Db80586420_Ent e(rec);
    int k = ((unsigned short*)rec)[8] & 1;
    int ta[2] = { 0x1D5A, 0x5C51 };
    t.a = ta[k];
    int tbb[2] = { 0x1D75, 0x1D76 };
    t.b = tbb[k];
    int tc[2] = { 0x1E2F, 0x1E30 };
    t.c = tc[k];
    return fn_80582DF4(a, b, t);
}

extern "C" DB_OVERLAY void fn_8058D028(char* self, int a, Unk80070DDC_Stream* io)
{
    fn_80582C54(self, a, io);
    io->v08(a, self + 8, 0x12);
}

extern "C" DB_OVERLAY Db805822D0_Base* fn_8058D080(Db805822D0_Base* self)
{
    fn_805822D0(self);
    self->m4 = lbl_80683098;
    return self;
}

extern "C" DB_OVERLAY int fn_8058D580(int self, int b, void* rec)
{
    Db80586420_Tri t = { -1, -1, -1 };
    Db80586420_Ent e(rec);
    int x = 0;
    int lo = 0, hi = 3;
    int f = e.mC.f;
    if (f != 0) {
        if (f >= lo && f <= hi)
            x = 0x1D5F;
    } else {
        x = 0x1D1A;
    }
    if (e.m4 == 0) {
        if (fn_8007FDF8__FP13Unk8007F198_D(lbl_8061930C) == 12) {
            Db80586420_Tri tb[2] = { { x, 0x1D67, 0x1E1C }, { x, 0x1D67, 0x1E1C } };
            t = tb[((unsigned short*)rec)[8] & 1];
        } else {
            Db80586420_Tri u = { x, 0x1D67, 0x1E1C };
            t = u;
        }
    } else {
        Db80586420_Tri tb[2] = { { 0x1D54, 0x1D81, 0x1E1E }, { 0x1D54, 0x1D81, 0x1E1F } };
        t = tb[((unsigned short*)rec)[8] & 1];
    }
    return fn_80582DF4(self, b, t);
}

extern "C" DB_OVERLAY int fn_8058D78C()
{
    Db80586420_Ent e;
    Db80586420_Ent* pe = &e;
    if (pe->m4 == 0) {
        int t = pe->mC.f;
        int lo = 0, hi = 3;
        if (t != 0 && t >= lo && t <= hi)
            return 8;
        return 7;
    }
    return 4;
}

extern "C" DB_OVERLAY void fn_8058D81C(void* self, void* rec, unsigned short* dst)
{
    fn_8058233C(self);
    if (fn_800B5758(fn_800B555C())) {
        Db80586420_Ent e(rec);
        Db80586420_Ent* pe = &e;
        int t = pe->m8;
        if (pe->m4 == 0 && t != 0) {
            unsigned short b[0x80];
            char n[0x80];
            Unk80090880* tb = lbl_8061977C;
            fn_800DE538((int)n, 0, t, 1);
            fn_80403DE4(b, ((DbLook)fn_80090880)(tb, 0x5C65), n, dst);
            fn_80403144(dst, b);
        }
    }
}

extern "C" int fn_800B56C4(Db800B555C_Obj* o);
extern "C" float fn_8007824C(int a, int b);
extern "C" float fn_8033CDC4(void* tbl, float x);
extern "C" int fn_80582E38(void* self, int a, int b);
extern "C" int fn_80083FC0__Fi(int k);
int fn_8007F1E0(Unk8007F198_A* a, int b, int c);
extern "C" char lbl_8068B4C0[];

extern "C" DB_OVERLAY void fn_8058D8E0(Db805822D0_V* self, int a, int b)
{
    int z = self->m0;
    if (z == 0) {
        Unk8007A4DC_Screen* s = lbl_8061930C;
        Unk8007B2B0_Screen* sb = (Unk8007B2B0_Screen*)s;
        int t = fn_8007F7D0((Unk8007F198_B*)s, 0);
        float f;
        float c;
        Db8052E198_E e;
        Unk8006A138_It<3> it(z);
        int i = 0;
        do {
            if (b == sb->fn_8007B320(fn_80083FC0__Fi(i), t))
                return;
            i = it.Next();
        } while (i <= 3);
        int p = 0;
        if (fn_800B5758(fn_800B555C())) {
            Unk8007A4DC_Screen* s2 = lbl_8061930C;
            int q = fn_8008FE14(6);
            p = ((Unk8007B2B0_Screen*)s2)->fn_8007B380(q, fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0));
        }
        int m = fn_8040ABA0() % 2;
        int n;
        if (fn_800B56C4(fn_800B555C())) {
            n = 0;
        } else {
            int r = fn_8040ABA0();
            if (fn_800B56C4(fn_800B555C()))
                n = r;
            else
                n = r % 2;
        }
        f = fn_8007824C(a, 0);
        c = fn_8033CDC4(lbl_8068B4C0, f);
        if (!(c < 0.8f)) {
            int w = fn_80582E38(self, a, self->v18());
            if (w == 0 && fn_8007F1E0((Unk8007F198_A*)s, a, b) != 0) {
                fn_8052E198(&e, self->v18(), a, b, p, (char)m, n, 0, w, w);
                fn_80582CF8(self, &e, 0, 0, 0);
                fn_80360AF0((Db80586420_Ent*)&e, 2);
            }
        }
    }
}

extern "C" DB_OVERLAY int fn_8058DB0C(void* self, unsigned short* rec)
{
    int k = rec[8] & 3;
    Db80586420_Ent e(rec);
    Db80586420_Ent* pe = &e;
    switch (k) {
    case 0: {
        int t = pe->mC.f;
        int lo = 0, hi = 2;
        if (t != 0 && t >= lo && t <= hi)
            return 1;
        return 2;
    }
    case 1:
        return 13;
    case 2: {
        int t = pe->mC.e;
        if (t == 0)
            return 3;
        if (t == 1)
            return 1;
        return 1;
    }
    case 3:
        return 2;
    default:
        return 2;
    }
}

extern "C" DB_OVERLAY void fn_8058DBEC(void* self, unsigned short* rec, unsigned short* dst)
{
    fn_8058233C(self);
    int fl = rec[8] & 3;
    if (fn_800B5758(fn_800B555C()) && fl == 1) {
        Db80586420_Ent e(rec);
        Db80586420_Ent* pe = &e;
        if (pe->m8 != 0) {
            unsigned short b[0x80];
            char n[0x80];
            Unk80090880* tb = lbl_8061977C;
            fn_800DE538((int)n, 3, pe->m8, 1);
            fn_80403DE4(b, ((DbLook)fn_80090880)(tb, 0x5C65), n, dst);
            fn_80403144(dst, b);
        }
    }
}

extern "C" DB_OVERLAY int fn_8058DCB4(int a, int b, void* rec)
{
    Db80586420_Tri t = { -1, -1, -1 };
    Db80586420_Ent e(rec);
    Db80586420_Tri tb[4] = { { 0x1D5C, 0x1D6B, 0x1E44 }, { 0x5C51, 0x1D86, 0x1E45 }, { 0x1D5C, 0x1D6C, 0x1E46 }, { 0x1D5A, 0x1D87, 0x1E47 } };
    int k = ((unsigned short*)rec)[8] & 3;
    t = tb[k];
    if (k == 0) {
        int a0[3] = { 0x1D5A, 0x1D58, 0x1D55 };
        t.a = a0[e.mC.f];
    } else if (k == 2) {
        int a2[2] = { 0x5CFD, 0x1D5E };
        t.a = a2[e.mC.e];
    }
    return fn_80582DF4(a, b, t);
}

extern "C" DB_OVERLAY int fn_8058DE40(void* self, void* rec)
{
    int r = fn_805826AC(self, rec);
    if (r == 1) {
        if (fn_8007FE04__FP13Unk8007F198_D(lbl_8061930C)->m1D4 == 1 && fn_800A4EA4(lbl_80619948) != 0)
            return 3;
        return 6;
    }
    return r;
}

extern "C" DB_OVERLAY void fn_8058DE9C(Db805822D0_V* self, int a, int b, int c, int d)
{
    if (self->m0 == 0) {
        Unk8007A4DC_Screen* s = lbl_8061930C;
        Unk8007B2B0_Screen* sb = (Unk8007B2B0_Screen*)s;
        if (sb->fn_80078A38(b) == 0) {
            int z = sb->fn_80078A38(d);
            if (z == 0) {
                int x = s->fn_8007A6A0(0x16, a);
                int y = s->fn_8007A6A0(0x16, c);
                if (x > 2 || y > 2) {
                    char p = sb->fn_8007A0D0(b);
                    char q = sb->fn_8007A0D0(d);
                    if (y > x) {
                        Db8052E198_E e;
                        fn_8052E198(&e, self->v18(), c, a, 0, q, p, 0, z, z);
                        fn_80582CF8(self, &e, 0, 0, 0);
                        fn_80360AF0((Db80586420_Ent*)&e, 2);
                    } else {
                        Db8052E198_E e;
                        fn_8052E198(&e, self->v18(), a, c, 0, p, q, 0, z, z);
                        fn_80582CF8(self, &e, 0, 0, 0);
                        fn_80360AF0((Db80586420_Ent*)&e, 2);
                    }
                }
            }
        }
    }
}

extern "C" DB_OVERLAY int fn_8058E044(int a, int b, void* rec)
{
    Db80586420_Tri t = { -1, -1, -1 };
    Db80586420_Ent e(rec);
    Db80586420_Tri tb[2] = { { 0x1D5A, 0x1D6D, 0x1E24 }, { 0x1D5A, 0x1D88, 0x1E25 } };
    t = tb[((unsigned short*)rec)[8] & 1];
    return fn_80582DF4(a, b, t);
}

extern "C" DB_OVERLAY Db805822D0_Base* fn_8058E144(Db805822D0_Base* self)
{
    fn_805822D0(self);
    self->m4 = lbl_80682E18;
    return self;
}

extern "C" DB_OVERLAY void fn_8058E180(Db805822D0_V* self, int a)
{
    Unk8007A4DC_Screen* s = lbl_8061930C;
    int t = fn_8007F7D0((Unk8007F198_B*)s, 0);
    int u = ((Unk8007B2B0_Screen*)s)->fn_8007B320(0, t);
    int k = a == 4 ? -10000000 : a == 3 ? -5000000 : 0;
    Db8052E198_E e;
    fn_8052E234(&e, 15, u, k, 0, 0, (char)a, 0, 0);
    fn_80582CF8(self, &e, 0, 0, 0);
    fn_80360AF0((Db80586420_Ent*)&e, 2);
}

extern "C" DB_OVERLAY int fn_8058E244(int self, int b, void* rec)
{
    int kind = ((int (*)(int, void*))fn_8058E550)(self, rec);
    Db80586420_Tri t = { -1, -1, -1 };
    Db80586420_Ent e(rec);
    t.a = 0x5A15;
    switch (kind) {
    case 1:
        t.b = 0x1D95;
        t.c = 0x5C55;
        break;
    case 2:
        t.b = 0x5C6B;
        t.c = 0x5C6C;
        break;
    case 5:
        t.b = 0x5C56;
        t.c = 0x5C57;
        break;
    case 6:
        t.b = 0x5C58;
        t.c = 0x5C59;
        break;
    case 7:
        t.b = 0x5C5A;
        t.c = 0x5C5B;
        break;
    case 8:
        t.b = 0x5C5C;
        t.c = 0x5C5D;
        break;
    case 9:
        t.b = 0x5C5E;
        t.c = 0x5C5F;
        break;
    case 3:
        t.b = 0x5C60;
        t.c = 0x5C61;
        break;
    case 4:
        t.b = 0x5C62;
        t.c = 0x5C63;
        break;
    case 10:
        t.b = 0x5D0E;
        t.c = 0x5D0F;
        break;
    case 11:
        t.b = 0x5DC2;
        t.c = 0x5DC3;
        break;
    case 12:
        t.b = 0x5DC4;
        t.c = 0x5DC5;
        break;
    case 13:
        t.b = 0x5DC6;
        t.c = 0x5DC7;
        break;
    case 14:
        t.b = 0x5DC8;
        t.c = 0x5DC9;
        break;
    case 15:
        t.b = 0x5DCA;
        t.c = 0x5DCB;
        break;
    case 16:
        t.b = 0x5DCD;
        t.c = 0x5DCE;
        break;
    case 17:
        t.b = 0x5DCF;
        t.c = 0x5DD0;
        break;
    case 18:
        t.b = 0x5DD1;
        t.c = 0x5DD2;
        break;
    }
    return fn_80582DF4(self, b, t);
}

extern "C" DB_OVERLAY int fn_8058E470()
{
    Db80586420_Ent e;
    Db80586420_Ent* pe = &e;
    int t = pe->mC.g;
    switch (t) {
    case 5:
        return 8;
    case 6:
        return 9;
    case 7:
        return 0xA;
    case 8:
        return 0xB;
    case 9:
        return 0xC;
    }
    return -1;
}

extern "C" DB_OVERLAY int fn_8058E550()
{
    Db80586420_Ent e;
    Db80586420_Ent* pe = &e;
    int t = pe->mC.g;
    if ((unsigned)(t - 1) <= 0x11)
        return t;
    return 0;
}
