/*
 * Database overlay code, .database_codeoverlay 0x805881E4-0x8058BF2C (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_80584CBC.h"

extern "C" void* fn_8052E444(void* self, char a);

struct Db80588434_S { char pad[0xB8]; int m[4]; };

struct Db80619948_O { char pad[0x28]; void* m28; };

struct Db805881E4_Item {
    int m0; int m4; char m8[0x18]; int m20; int m24; int m28;
    void Set(int a, int b, int c) { m0 = 0; m4 = 0; fn_8052E444(m8, 0x10); m20 = a; m24 = b; m28 = c; }
};

struct Db805881E4_Q { int m0; const void* m4; Db805881E4_Item it[4]; };

extern "C" void* fn_8052E444(void* self, char a);
extern const char lbl_80683688[];
extern const char lbl_80683720[];
extern "C" int fn_8058252C(void* self, int a);
extern "C" int fn_8058BA94(void* self, int k, int b, int a);
extern "C" void fn_80582314(void* self);
extern "C" void fn_80582C54(char* self, int a, Unk80070DDC_Stream* io);
extern "C" int fn_805826AC(void* self);
extern Unk8007A4DC_Screen* lbl_8061930C;
int fn_8007F7D0(Unk8007F198_B* self, unsigned i);
int fn_80083FC0(int a);
extern "C" int fn_8056B628(void* o, int a, int b);
extern "C" int fn_8056B658(void* o, int a, int b);
extern "C" int fn_8056A5F4(void* o, int a, int b, int c);
extern "C" void fn_8055AC44(void* o, int a);
extern "C" int fn_8055ADD4(void* o, int a);
extern "C" int fn_8055AE1C(void* o, int a);
extern "C" int fn_8055AE68(void* o, int a);
extern "C" int fn_8055AEB4(void* o, int a);

struct Db80588C44_Rec {
    char pad0[0x20];
    int m20;
    int m24;
};
class Db80588C44_C {
public:
    int m0;
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Db80588C44_Rec* v11(int a);
};

struct Db8058AB84_Rec {
    char pad0[0x20];
    int m20;
    int m24;
};
class Db8058AB84_C {
public:
    int m0;
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Db8058AB84_Rec* v11(int a);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17(int a, int b);
};

struct Db8058B628_E {
    int m0;
    int m4;
    int m8;
    unsigned mC;
    unsigned short m10;
    unsigned short m12;
    const void* m14;
};
extern "C" Db8058B628_E* fn_8052E198(Db8058B628_E* self, int a, int b, int c, int d, int e, char f, int g, int h, int i);
extern "C" int fn_80582CF8(void* self, void* e, int a, int b, int c);
extern "C" int fn_80084014__Fii(int a, int b);
extern "C" void* fn_8052E360(void* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern const float lbl_806008B4;
extern const float lbl_806008B8;
extern const float lbl_806008BC;
extern const float lbl_806008C0;
extern "C" int rand(void);
extern "C" int fn_8056A2F8(void* o, int cur, int mode, int a, int b, int who, int p6, int p7, int s8, int sC);
extern "C" int fn_8058AE54(void* self, int id);
extern "C" int fn_8058B048(void* self, int id, int flag, int x);
extern "C" int fn_8058B288(void* self, int a, int b, int flag, int x);
extern "C" int fn_8058B628(void* self, int unused, int id);
extern "C" int fn_8058B788(void* self, int id, int flag, int x);
extern "C" int fn_8058B938(void* self, int id, int flag, int x);
extern "C" int fn_80077BC4(void* g, int a);
extern "C" int fn_800E4584__Fiii(int a, int b, int c);
extern "C" int fn_80552BE0(int a, int b, int* out);
extern "C" int fn_8058320C(void* self, int id, int k);
extern "C" void fn_80582B7C(void* self);
extern "C" int fn_8009005C__Fif(int a, float b);
extern const float lbl_80600890;
extern "C" void* fn_8052E2C4(void* self, int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern "C" int fn_8007E1F8__FP13Unk8007DB74_A(void* s, int id);
extern "C" int fn_8007E154__FP13Unk8007DB74_Aii(void* s, int id, int i);
/* forward declarations (definitions are in address order) */
extern "C" int fn_805881E4(void* self);
extern "C" int fn_80588218();
extern "C" void fn_80588288(void* self, void* rec, unsigned short* dst);
extern "C" Db805881E4_Q* fn_80588340(Db805881E4_Q* self);
extern "C" void fn_80588434(Db80588434_S* self);
extern "C" int fn_80588800(int a, int b, void* rec);
extern "C" int fn_80588C44(Db80588C44_C* self, int k, void* rec);
extern "C" char* fn_80588D8C(char* p, int k);
extern "C" char* fn_80588DE0(char* p, int k);
extern "C" void fn_80588E34(char* self, int a, Unk80070DDC_Stream* io);
extern "C" int fn_80588E8C(void* unused, void* rec);
extern "C" void fn_80588F68(void* self, void* rec, unsigned short* dst);
extern "C" void fn_80589720(void* self, void* rec, unsigned short* dst);
extern "C" int fn_805897D8(int a, int b, void* rec);
extern "C" int fn_805898A4(void* self);
extern "C" int fn_80589F84();
extern "C" void fn_8058A004(void* self, void* rec, unsigned short* dst);
extern "C" int fn_8058A0D8(int a, int b, void* rec);
extern "C" Db805881E4_Q* fn_8058A2D0(Db805881E4_Q* self);
extern "C" int fn_8058A3B8(void* self, void* rec);
extern "C" int fn_8058A884(void* self, void* rec);
extern "C" void fn_8058A960(void* self, void* rec, unsigned short* dst);
extern "C" int fn_8058AA48(void* self, int a);
extern "C" int fn_8058AA90(void* self, int a);
extern "C" int fn_8058AADC(void* self, int a, int b);
extern "C" int fn_8058AB84(Db8058AB84_C* self, int k, void* rec);
extern "C" char* fn_8058ADAC(char* p, int k);
extern "C" char* fn_8058AE00(char* p, int k);
extern "C" int fn_8058B628(void* self, int unused, int id);
extern "C" int fn_8058BD8C(void* self, int a, int b, int* out);
extern "C" int fn_8058BE5C(void* self, int a, int b, int* out);

extern "C" DB_OVERLAY int fn_805881E4(void* self)
{
    int r = fn_805826AC(self);
    if (r == 1)
        return 5;
    return r;
}

extern "C" DB_OVERLAY int fn_80588218()
{
    Db80586420_Ent e;
    Db80586420_Ent* pe = &e;
    int k = pe->mC.e;
    int lo = 0, hi = 3;
    if (k != 0 && k >= lo && k <= hi)
        return 8;
    return 7;
}

extern "C" DB_OVERLAY void fn_80588288(void* self, void* rec, unsigned short* dst)
{
    fn_8058233C(self);
    if (fn_800B5758(fn_800B555C())) {
        Db80586420_Ent e(rec);
        Db80586420_Ent* pe = &e;
        if (pe->m8 != 0) {
            unsigned short b[0x80];
            char n[0x80];
            Unk80090880* tb = lbl_8061977C;
            fn_800DE538((int)n, 0, pe->m8, 1);
            fn_80403DE4(b, ((DbLook)fn_80090880)(tb, 0x5C65), n, dst);
            fn_80403144(dst, b);
        }
    }
}

extern "C" DB_OVERLAY Db805881E4_Q* fn_80588340(Db805881E4_Q* self)
{
    fn_805822D0((Db805822D0_Base*)self);
    self->m4 = lbl_80683688;
    self->it[0].Set(0x1D1A, 0x1E72, 1);
    self->it[1].Set(0x1D1B, 0x1E73, 1);
    self->it[2].Set(0x1D1C, 0x1E74, 1);
    self->it[3].Set(0x1D1D, 0x1E75, 1);
    return self;
}

extern "C" DB_OVERLAY void fn_80588434(Db80588434_S* self)
{
    fn_80582314(self);
    for (int i = 0; i < 4; i++)
        self->m[i] = 0;
}

extern "C" DB_OVERLAY int fn_80588800(int a, int b, void* rec)
{
    Db80586420_Tri t = { -1, -1, -1 };
    Db80586420_Ent e(rec);
    int x = 0;
    int lo = 0, hi = 3;
    int k = e.mC.e;
    if (k != 0) {
        if (k >= lo && k <= hi)
            x = 0x1D5F;
    } else {
        x = 0x1D1A;
    }
    int g = e.mC.g;
    switch (g) {
    case 0: {
        Db80586420_Tri tb[2] = { { x, 0x1D7F, 0x1E19 }, { x, 0x1D80, 0x1E1A } };
        t = tb[((unsigned short*)rec)[8] & 1];
        break;
    }
    case 1:
        t.a = 0x1D5D;
        t.b = 0x1D64;
        t.c = 0x1E39;
        break;
    case 2: {
        Db80586420_Tri tb[3] = { { 0x1D5A, 0x1D65, 0x1E3A }, { 0x1D5A, 0x1D63, 0x1E3B }, { 0x1D5A, 0x1D66, 0x1E3C } };
        unsigned short idx = ((unsigned short*)rec)[8] % 3;
        t = tb[idx];
        break;
    }
    }
    return fn_80582DF4(a, b, t);
}

/* near-miss: same instructions; callee-saved registers permuted (retail id=r31, s=r30; ours s=r31, id=r29): global-alloc priority of s (9 refs/81 insns) just beats id (11/102) */
extern "C" DB_OVERLAY int fn_80588A3C(void* self, int slot)
{
    Db8058B628_E e;
    char* tab = (char*)self + 0xB8;
    int off = slot * 4;
    int id = *(int*)(tab + off);
    if (id == 0)
        return 0;
    Unk8007A4DC_Screen* s = lbl_8061930C;
    int kind = 1;
    int team = fn_8007F7D0((Unk8007F198_B*)s, 0);
    int ev = fn_80077BC4(s, id);
    int w = 3;
    if (ev == 0 || fn_8058320C(self, id, team) == 0) {
        kind = 0;
    } else {
        int p = s->fn_80078A64(ev, 0, id);
        int q = s->fn_80078A64(ev, 1, id);
        int pb = p != 0;
        int qb = q != 0;
        int pq = pb | qb;
        int fl = 0;
        if (s->fn_8007A6A0(0x1F, id) != 0 || s->fn_8007A6A0(0x33, id) != 0)
            fl = 1;
        int r = fn_80552BE0(id, s->fn_8007A6A0(0x1B, id), &w);
        if (pq != 0 && r != 0)
            kind = 3;
        else if (fl != 0) {
            if (r != 0)
                kind = 2;
        } else if (r != 0)
            kind = 4;
    }
    int c = ((Unk8007B2B0_Screen*)s)->fn_80078A38(ev);
    int x = fn_800E4584__Fiii(team, 0, c);
    fn_8052E198(&e, 4, id, ev, x, (char)w, (char)c, (char)slot, kind, 0);
    fn_80582CF8(self, &e, 0, 1, slot);
    fn_80582B7C(self);
    fn_80360AF0((Db80586420_Ent*)&e, 2);
    return 1;
}

extern "C" DB_OVERLAY int fn_80588C44(Db80588C44_C* self, int k, void* rec)
{
    Db80586420_Ent e(rec);
    Db80586420_Ent* pe = &e;
    Db80586420_Tri u;
    {
        Db80588C44_Rec* p = self->v11(pe->mC.g);
        Db80586420_Tri t = { 0, 0, 0 };
        t.a = p->m20;
        t.b = p->m24;
        t.c = -1;
        u = t;
    }
    int hh = pe->mC.h;
    switch (hh) {
    case 0:
        u.c = 0x1E76;
        break;
    case 1:
        u.c = 0x1E77;
        break;
    case 2:
        u.c = 0x1E78;
        break;
    case 3:
        u.c = 0x1E79;
        break;
    case 4:
        u.c = 0x1E7A;
        break;
    }
    return fn_80582DF4((int)self, k, u);
}

extern "C" DB_OVERLAY char* fn_80588D8C(char* p, int k)
{
    switch (k) {
    case 0:
        return p + 0x8;
    case 1:
        return p + 0x34;
    case 2:
        return p + 0x60;
    case 3:
        return p + 0x8C;
    }
    return 0;
}

extern "C" DB_OVERLAY char* fn_80588DE0(char* p, int k)
{
    switch (k) {
    case 0:
        return p + 0x8;
    case 1:
        return p + 0x34;
    case 2:
        return p + 0x60;
    case 3:
        return p + 0x8C;
    }
    return 0;
}

extern "C" DB_OVERLAY void fn_80588E34(char* self, int a, Unk80070DDC_Stream* io)
{
    fn_80582C54(self, a, io);
    io->v08(a, self + 0xB8, 0x10);
}

extern "C" DB_OVERLAY int fn_80588E8C(void* unused, void* rec)
{
    Db80586420_Ent e(rec);
    Db80586420_Ent* pe = &e;
    int r = 7;
    int a = 0;
    int b = 0;
    if (((unsigned*)rec)[3] & 0x40000000) {
        a = 1;
        b = pe->mC.g;
    } else {
        int g = pe->mC.g;
        switch (g) {
        case 0:
            b = pe->mC.e;
            a = 1;
            break;
        case 1:
            r = 4;
            break;
        case 2:
            r = 2;
            break;
        default:
            r = 0;
            break;
        }
    }
    int lo = 0, hi = 3;
    if (a != 0) {
        if (b != 0) {
            if (b >= lo) {
                r = 8;
                if (b > hi)
                    r = 7;
            } else
                r = 7;
        } else
            r = 7;
    }
    return r;
}

extern "C" DB_OVERLAY void fn_80588F68(void* self, void* rec, unsigned short* dst)
{
    fn_8058233C(self);
    if (fn_800B5758(fn_800B555C())) {
        Db80586420_Ent e(rec);
        Db80586420_Ent* pe = &e;
        if (pe->m8 != 0) {
            unsigned short b[0x80];
            char n[0x80];
            Unk80090880* tb = lbl_8061977C;
            fn_800DE538((int)n, 0, pe->m8, 1);
            fn_80403DE4(b, ((DbLook)fn_80090880)(tb, 0x5C65), n, dst);
            fn_80403144(dst, b);
        }
    }
}

extern "C" DB_OVERLAY void fn_80589720(void* self, void* rec, unsigned short* dst)
{
    fn_8058233C(self);
    if (fn_800B5758(fn_800B555C())) {
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

extern "C" DB_OVERLAY int fn_805897D8(int a, int b, void* rec)
{
    Db80586420_Tri t = { -1, -1, -1 };
    Db80586420_Tri tb[2] = { { 0x5C52, 0x1D60, 0x1E15 }, { 0x5C52, 0x1D79, 0x1E16 } };
    t = tb[((unsigned short*)rec)[8] & 1];
    return fn_80582DF4(a, b, t);
}

extern "C" DB_OVERLAY int fn_805898A4(void* self)
{
    int r = fn_805826AC(self);
    if (r == 1)
        return 3;
    return r;
}

extern "C" DB_OVERLAY int fn_80589F84()
{
    Db80586420_Ent e;
    Db80586420_Ent* pe = &e;
    int b = pe->mC.f;
    int a = pe->mC.e;
    int has;
    has = a != 0;
    int r = 8;
    if (has && a == 1) {
        r = 12;
        if (b == 0)
            r = 11;
    }
    return r;
}

/* near-miss: 99.5%; callee-saved pair swapped (retail dst r28 / lbl pointer r27, ours the reverse); allocation order of dst vs the early lbl load */
extern "C" DB_OVERLAY void fn_8058A004(void* self, void* rec, unsigned short* dst)
{
    fn_8058233C(self);
    if (fn_800B5758(fn_800B555C())) {
        Db80586420_Ent e(rec);
        Db80586420_Ent* pe = &e;
        int m8 = pe->m8;
        if (m8 != 0) {
            unsigned short b[0x80];
            char n[0x80];
            Unk80090880* tb = lbl_8061977C;
            int k = 3;
            int t = pe->mC.e;
            if (t != 0) {
                if (t == 1)
                    k = 2;
            }
            fn_800DE538((int)n, k, m8, 1);
            fn_80403DE4(b, ((DbLook)fn_80090880)(tb, 0x5C65), n, dst);
            fn_80403144(dst, b);
        }
    }
}

extern "C" DB_OVERLAY int fn_8058A0D8(int a, int b, void* rec)
{
    Db80586420_Tri t = { -1, -1, -1 };
    Db80586420_Ent e(rec);
    Db80586420_Ent* pe = &e;
    int x = 0;
    int lo = 0, hi = 3;
    int f = pe->mC.f;
    if (f != 0) {
        if (f >= lo && f <= hi)
            x = 0x5C4D;
    } else {
        x = 0x5C4F;
    }
    int ee = pe->mC.e;
    int c = ee != 0;
    if (c) {
        if (ee == 1) {
            Db80586420_Tri tb[2] = { { x, 0x1D7C, 0x1E34 }, { x, 0x1D7D, 0x1E35 } };
            t = tb[((unsigned short*)rec)[8] & 1];
        } else {
            t.a = 0x1D5F;
            t.b = 0x1D7E;
            t.c = 0x1E36;
        }
    } else {
        Db80586420_Tri tb[2] = { { 0x1D5F, 0x1D7A, 0x1E37 }, { 0x1D5F, 0x1D7B, 0x1E38 } };
        t = tb[((unsigned short*)rec)[8] & 1];
    }
    return fn_80582DF4(a, b, t);
}

extern "C" DB_OVERLAY Db805881E4_Q* fn_8058A2D0(Db805881E4_Q* self)
{
    fn_805822D0((Db805822D0_Base*)self);
    self->m4 = lbl_80683720;
    self->it[0].Set(0x5C51, 0x1E6E, 0);
    self->it[1].Set(0x5C52, 0x1E6F, 0);
    self->it[2].Set(0x5C52, 0x1E70, 0);
    self->it[3].Set(0x5C52, 0x1E71, 0);
    return self;
}

extern "C" DB_OVERLAY int fn_8058A3B8(void* self, void* rec)
{
    Db80586420_Ent e(rec);
    Db80586420_Ent* pe = &e;
    int t = pe->mC.g;
    if ((unsigned)(t - 1) <= 6)
        return t;
    return 1;
}

extern "C" DB_OVERLAY void fn_8058A420(int* self, int a, int b, int flag)
{
    if (flag == 0 && fn_800A2EB4(lbl_80619948) == 0 && *self == 0) {
        void* o = ((Db80619948_O*)lbl_80619948)->m28;
        if (fn_8056B628(o, a, b) == 1) {
            int t = fn_8056B658(o, a, b);
            int s = fn_8056A5F4(o, 0, t, b);
            int r = fn_8056A2F8(o, t, 1, 0, 0, b, 0, 2, flag, 0x1A);
            if (r != -1) {
                int u = fn_8056A5F4(o, 0, r, b);
                if (s != u && u != b) {
                    int res = 0;
                    int n = 0;
                    do {
                        int m = rand() % 7;
                        switch (m) {
                        case 0:
                            res = fn_8058AE54(self, s);
                            break;
                        case 1:
                            res = fn_8058B048(self, s, flag, a);
                            break;
                        case 2:
                            res = fn_8058B288(self, t, b, flag, a);
                            break;
                        case 3:
                            res = fn_8058B628(self, t, s);
                            break;
                        case 4:
                            res = fn_8058B788(self, s, flag, a);
                            break;
                        case 5:
                            res = fn_8058B938(self, s, flag, a);
                            break;
                        case 6:
                            res = fn_8058BA94(self, s, 0, 0);
                            break;
                        }
                        n += 1;
                        if (res != 0)
                            return;
                    } while (n <= 6);
                    fn_8058BA94(self, s, 0, 0);
                }
            } else
                fn_8058BA94(self, s, 0, 0);
        }
    }
}

extern "C" DB_OVERLAY int fn_8058A884(void* self, void* rec)
{
    int kind = fn_8058A3B8(self, rec);
    Db80586420_Ent e(rec);
    Db80586420_Ent* pe = &e;
    switch (kind) {
    case 5:
        if (pe->mC.h == 0)
            return 11;
        return 12;
    case 6:
        if (pe->mC.h == 0)
            return 9;
        return 10;
    case 1:
        return 13;
    case 7:
        return 13;
    default:
        return 13;
    }
}

/* near-miss: 98.9%; callee-saved names permuted (self/rec/dst r29/r30/r28 in retail, lbl pointer r27) */
extern "C" DB_OVERLAY void fn_8058A960(void* self, void* rec, unsigned short* dst)
{
    fn_8058233C(self);
    if (fn_800B5758(fn_800B555C())) {
        int kind = fn_8058A3B8(self, rec);
        Db80586420_Ent e(rec);
        Db80586420_Ent* pe = &e;
        int m8 = pe->m8;
        if (m8 != 0) {
            unsigned short b[0x80];
            char n[0x80];
            Unk80090880* tb = lbl_8061977C;
            int k = 3;
            if (kind == 5)
                k = 2;
            else if (kind == 6)
                k = 1;
            fn_800DE538((int)n, k, m8, 1);
            fn_80403DE4(b, ((DbLook)fn_80090880)(tb, 0x5C65), n, dst);
            fn_80403144(dst, b);
        }
    }
}

extern "C" DB_OVERLAY int fn_8058AA48(void* self, int a)
{
    if (fn_8058A3B8(self, (void*)a) == 3)
        return fn_8058252C(self, a);
    return 0;
}

extern "C" DB_OVERLAY int fn_8058AA90(void* self, int a)
{
    int k = ((int (*)(void*, int))fn_8058AADC)(self, a);
    int r = 0;
    if (k != 0)
        r = fn_8058BA94(self, k, 1, a);
    return r;
}

extern "C" DB_OVERLAY int fn_8058AADC(void* self, int a, int b)
{
    int t = fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0);
    void* o = ((Db80619948_O*)lbl_80619948)->m28;
    int h = fn_80083FC0(a);
    int u = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B320(h, t);
    if (fn_8056B628(o, b, u) == 1)
        return fn_8056A5F4(o, a, fn_8056B658(o, b, u), u);
    return 0;
}

extern "C" DB_OVERLAY int fn_8058AB84(Db8058AB84_C* self, int k, void* rec)
{
    Db80586420_Ent e(rec);
    Db80586420_Ent* pe = &e;
    Db80586420_Tri u;
    {
        Db8058AB84_Rec* p = self->v11(pe->mC.h);
        Db80586420_Tri t = { 0, 0, 0 };
        t.a = p->m20;
        t.b = p->m24;
        t.c = self->v17(2, (int)rec);
        u = t;
    }
    return fn_80582DF4((int)self, k, u);
}

extern "C" DB_OVERLAY char* fn_8058ADAC(char* p, int k)
{
    switch (k) {
    case 0:
        return p + 0x8;
    case 1:
        return p + 0x34;
    case 2:
        return p + 0x60;
    case 3:
        return p + 0x8C;
    }
    return 0;
}

extern "C" DB_OVERLAY char* fn_8058AE00(char* p, int k)
{
    switch (k) {
    case 0:
        return p + 0x8;
    case 1:
        return p + 0x34;
    case 2:
        return p + 0x60;
    case 3:
        return p + 0x8C;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8058AE54(void* self, int id)
{
    Db8058B628_E e;
    int a;
    int b;
    b = 0;
    a = 0;
    int pick = 0;
    int sc = 0;
    int bonus = 0;
    if (fn_800B5758(fn_800B555C())) {
        sc = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B380(fn_8008FE14(6), fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0));
        if (sc != 0) {
            int q = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007CBB8(0xE, sc);
            bonus = (fn_8009005C__Fif(q, (float)(rand() % 10000) * lbl_80600890) - 2) * -5;
        } else
            bonus = 0;
    }
    int ra = fn_8058BE5C(self, id, bonus, &a);
    int rb = fn_8058BD8C(self, id, bonus, &b);
    if (a > 9 && b <= 20) {
        if (rand() & 1)
            pick = 1;
    } else if (a <= 10) {
        pick = 1;
    } else {
        if (b <= 19)
            return 0;
        pick = 0;
    }
    int w = rb;
    if (pick != 0)
        w = ra;
    fn_8052E198(&e, 0xB, id, 0, sc, (char)w, 0, 1, 0, 0);
    fn_80582CF8(self, &e, 0, 0, 0);
    fn_80360AF0((Db80586420_Ent*)&e, 2);
    return 1;
}

extern "C" DB_OVERLAY int fn_8058B628(void* self, int unused, int id)
{
    Unk8007A4DC_Screen* s = lbl_8061930C;
    int base = fn_8007E1F8__FP13Unk8007DB74_A(s, id);
    int sc = 0;
    if (fn_800B5758(fn_800B555C())) {
        sc = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B380(fn_8008FE14(6), fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0));
    }
    int found = 0;
    for (int i = 0; i <= 4; i++) {
        if (base == fn_8007E154__FP13Unk8007DB74_Aii(s, id, i)) {
            found = fn_8007E154__FP13Unk8007DB74_Aii(s, id, (i + 1) % 5);
            break;
        }
    }
    if (found == 0)
        return 0;
    char c = ((Unk8007B2B0_Screen*)s)->fn_8007A0D0(id);
    Db8058B628_E e;
    fn_8052E198(&e, 0xB, base, found, sc, 0, c, 4, 0, 0);
    fn_80582CF8(self, &e, 0, 0, 0);
    fn_80360AF0((Db80586420_Ent*)&e, 2);
    return 1;
}

extern "C" DB_OVERLAY int fn_8058B788(void* self, int id, int flag, int x)
{
    float f;
    Db8058B628_E e;
    Db80329FA0_Out o = fn_80329FA0(x);
    if (o.m0 - 1 <= 3)
        return 0;
    int sc = 0;
    if (fn_800B5758(fn_800B555C())) {
        if (flag == 0)
            sc = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B380(fn_8008FE14(4), fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0));
        else
            sc = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B380(fn_8008FE14(5), fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0));
    }
    int w = fn_80084014__Fii(flag, 1);
    f = ((Unk8007A4DC_Screen*)lbl_8061930C)->fn_80077A18(id, w);
    int kind = 1;
    if (f <= lbl_806008B4)
        goto l868;
    kind = 0;
    goto body;
l868:
    if (f >= lbl_806008B4)
        goto l88c;
    if (f <= lbl_806008B8)
        goto l88c;
    kind = 2;
    goto body;
l88c:
    if (!(f > lbl_806008BC))
        return 0;
body:
    fn_8052E360(&e, 0xB, id, (short)(f * lbl_806008C0), 0, sc, 0, kind, 5, (char)flag, 0);
    fn_80582CF8(self, &e, 0, 0, 0);
    fn_80360AF0((Db80586420_Ent*)&e, 2);
    return 1;
}

extern "C" DB_OVERLAY int fn_8058B938(void* self, int id, int flag, int x)
{
    Db8058B628_E e;
    Db80329FA0_Out o = fn_80329FA0(x);
    if (o.m0 - 1 <= 3)
        return 0;
    int sc = 0;
    if (fn_800B5758(fn_800B555C())) {
        if (flag == 0)
            sc = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B380(fn_8008FE14(2), fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0));
        else
            sc = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B380(fn_8008FE14(3), fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0));
    }
    Unk8007A4DC_Screen* s = lbl_8061930C;
    int w = fn_80084014__Fii(flag, 1);
    int a = ((Unk8007B2B0_Screen*)s)->fn_80076A24(id);
    int b = s->fn_80077238(id, w);
    int c = s->fn_80077320(id, w);
    fn_8052E2C4(&e, 0xB, id, (short)b, (short)a, sc, (short)c, 6, (char)flag, 0);
    fn_80582CF8(self, &e, 0, 0, 0);
    fn_80360AF0((Db80586420_Ent*)&e, 2);
    return 1;
}

extern "C" DB_OVERLAY int fn_8058BD8C(void* self, int a, int b, int* out)
{
    char o[0x460];
    fn_8055AC44(o, ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80078A38(a));
    int best = 5;
    *out = fn_8055ADD4(o, a) + b;
    int v = fn_8055AE1C(o, a) + b;
    if (v > *out) {
        *out = v;
        best = 4;
    }
    v = fn_8055AE68(o, a) + b;
    if (v > *out) {
        *out = v;
        best = 6;
    }
    v = fn_8055AEB4(o, a) + b;
    if (v > *out) {
        *out = v;
        best = 7;
    }
    return best;
}

extern "C" DB_OVERLAY int fn_8058BE5C(void* self, int a, int b, int* out)
{
    char o[0x460];
    fn_8055AC44(o, ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80078A38(a));
    int best = 1;
    *out = fn_8055ADD4(o, a) + b;
    int v = fn_8055AE1C(o, a) + b;
    if (v < *out) {
        *out = v;
        best = 0;
    }
    v = fn_8055AE68(o, a) + b;
    if (v < *out) {
        *out = v;
        best = 3;
    }
    v = fn_8055AEB4(o, a) + b;
    if (v < *out) {
        *out = v;
        best = 2;
    }
    return best;
}
