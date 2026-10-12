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
extern "C" void fn_80582CF8(Db805822D0_V* self, Db8052E198_E* e, int a, int b, int c);
extern "C" int fn_8040ABA0();
extern const Db8058C9B8_P lbl_8060095C;
extern const Db8058C9B8_P lbl_80600964;
extern const Db8058C9B8_P lbl_8060096C;

extern "C" DB_OVERLAY Db805822D0_Base* fn_8058BF2C(Db805822D0_Base* self)
{
    fn_805822D0(self);
    self->m4 = lbl_806834C0;
    return self;
}

/* near-miss (2 slots): retail sets r4 (addi) before r3 (mr) in the fn_80582CF8 call. */
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

extern "C" DB_OVERLAY int fn_8058CE38(void* self, unsigned short* rec)
{
    int r = 2;
    if (rec[8] & 1)
        r = 13;
    return r;
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

extern "C" DB_OVERLAY Db805822D0_Base* fn_8058E144(Db805822D0_Base* self)
{
    fn_805822D0(self);
    self->m4 = lbl_80682E18;
    return self;
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
