/*
 * Database overlay code, .database_codeoverlay 0x805902E0-0x8059377C (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_80584CBC.h"

struct Db80590EB4_S { Db805919E8_M* m0; char pad4[0x20]; int m24; };

struct Db80619948_G { char pad[0x84]; int m84; };

struct Db80590EB4_S2 { Db805919E8_M* m0; };

struct Db805909D4_S { Db805919E8_M* m0; char pad4[0x20]; int m24; int m28; int m2C; float m30[1]; };

struct Db8059124C_S { char pad[0x28]; void* m28; };

struct Db80590A4C_S {
    Db805919E8_M* m0;
    Db8058F924_V* m4;
    Db8058F924_V* m8;
    Db8058F924_V* mC;
    Db8058F924_V* m10;
    Db805942E0_V* m14;
    Db805942E0_V* m18;
    Db805942E0_V* m1C;
    int m20;
    int m24;
    void* m28;
    int m2C;
    float m30[30];
    int mA8;
    int mAC;
    int mB0;
    int mB4;
    float mB8;
    float mBC;
    int mC0;
};

extern "C" void fn_80591DEC(Db805919E8_M* m);
extern "C" Db800B555C_Obj* fn_800B555C();
extern "C" int fn_800B5758(Db800B555C_Obj* o);
extern "C" int fn_800A2E90(void* p);
extern Unk8007A4DC_Screen* lbl_8061930C;
int fn_8007F7D0(Unk8007F198_B* self, unsigned i);
extern "C" float fn_80079CF8(Unk8007B2B0_Screen* s, int a);
extern "C" int fn_805560A8(int a, int b);
unsigned fn_8007FBC0(Unk8007F198_C* self, int a, int c);
int fn_8007FB2C(Unk8007F198_C* self, int idx);
extern "C" void fn_80596E3C(void* p);
extern "C" void fn_80596FCC(void* p);
extern "C" void fn_80596E00(void* p);
extern "C" void fn_805913C0(Db80590A4C_S* s, int a);
extern "C" void fn_80590BA0(Db80590EB4_S2* s);
extern "C" void fn_80590C24(Db80590EB4_S2* s);

struct Db805934C0_G {
    char pad0[0x28];
    int m28;
};
extern "C" int fn_8056A5F4(int a, int b, int c, int d);
extern "C" int fn_8007FB98__FP13Unk8007F198_Ciii(void* p, int a, int b, int c);

inline float Db80591270_Min(float a, float b)
{
    return a <? b;
}
inline float Db80591270_Max(float a, float b)
{
    return b >? a;
}
struct Db80591270_Scr {
    char pad0[0x34];
    void* m34;
};
extern float lbl_806E03A0[];
extern "C" float fn_805948E8(void* p);
extern "C" float fn_80593BD4(void* p);
extern "C" float fn_80595470(void* p);
extern "C" float fn_8058F420(void* p);

extern "C" int fn_8056B840(int a, int b);
extern "C" float fn_80593370(Db805919E8_M* m, int g);

struct Db805907B8_Rec {
    char pad0[0x1E4];
    int m1E4;
};
extern "C" Db805907B8_Rec* fn_8007FE04__FP13Unk8007F198_D(void* p);

struct Db805935B8_Inner {
    char pad0[0x14];
    int m14;
    float m18;
};
struct Db805935B8_Obj {
    char pad0[0xC];
    Db805935B8_Inner* mC;
};
struct Db805935B8_Mgr {
    char pad0[4];
    Db805935B8_Obj* m4;
};
struct Db805935B8_Sums {
    int m0;
    int m4[5];
};
struct Db805935B8_Rec30 {
    char pad0[0x2C];
    Db805935B8_Sums* m2C;
};
struct Db805935B8_Scr {
    char pad0[0x30];
    Db805935B8_Rec30* m30;
};
extern Db805935B8_Mgr* lbl_806192E0;

extern char lbl_80684640[];
extern "C" Db805919E8_M* fn_805917F4(Db805919E8_M* m);

void* operator new(unsigned int size, int heap);
extern char lbl_80682D10[];
extern "C" void* fn_805945A4(void* p, void* m, int id, float f);
extern "C" void* fn_80593A00(void* p, void* m, int id, float f);
extern "C" void* fn_80594A10(void* p, void* a, void* m, int id);
extern "C" void* fn_805951B8(void* p, void* m, int id, float f);
extern "C" void* fn_80595598(void* p, void* a, void* m, int id);
extern "C" void* fn_80595F8C(void* p, void* m, int id);
extern "C" void* fn_80595B64(void* p, void* m, int id);
extern "C" void* fn_80596040(void* p, void* m, int id);
extern "C" void* fn_80596D88(void* p);
extern "C" void* fn_80597A5C(void* p);

struct Db8059055C_D18Data {
    char pad0[0x18];
};
struct Db8059055C_D18 : Db8059055C_D18Data {
    virtual void v08(int chrg);
};
struct Db8059055C_D34Data {
    char pad0[0x34];
};
struct Db8059055C_D34 : Db8059055C_D34Data {
    virtual void v08(int chrg);
};
struct Db8059055C_DMData {
    char pad0[0x12B90];
};
struct Db8059055C_DM : Db8059055C_DMData {
    virtual void v08(int chrg);
};
extern "C" void fn_80377408(void* p);

struct Db80590F40_PadM { char pad[0x12B90]; };
struct Db80590F40_SM : Db80590F40_PadM {
    virtual void v08(int chrg);
    virtual void v10(int a, Unk80070DDC_Stream* io);
};
struct Db80590F40_Pad34 { char pad[0x34]; };
struct Db80590F40_S34 : Db80590F40_Pad34 { virtual void v08(int chrg); virtual void v10(int a, Unk80070DDC_Stream* io); };
struct Db80590F40_Pad18 { char pad[0x18]; };
struct Db80590F40_S18 : Db80590F40_Pad18 { virtual void v08(int chrg); virtual void v10(int a, Unk80070DDC_Stream* io); };
struct Db80590F40_Pad1C { char pad[0x1C]; };
struct Db80590F40_S1C : Db80590F40_Pad1C {
    virtual void v08(int chrg);
    virtual void v10();
    virtual void v18();
    virtual void v20();
    virtual void v28();
    virtual void v30(int a, Unk80070DDC_Stream* io);
};
struct Db80590F40_Pad14 { char pad[0x14]; };
struct Db80590F40_S14 : Db80590F40_Pad14 {
    virtual void v08(int chrg);
    virtual void v10();
    virtual void v18();
    virtual void v20(int a, Unk80070DDC_Stream* io);
};
extern "C" void fn_80551A04(int a, Unk80070DDC_Stream* io);
/* forward declarations (definitions are in address order) */
extern "C" Db80590A4C_S* fn_805902E0(Db80590A4C_S* s);
extern "C" void fn_8059055C(Db80590A4C_S* s, int chrg);
extern "C" void fn_805907B8(Db80590A4C_S* s, int a);
extern "C" void fn_80590910(Db80590A4C_S* s);
extern "C" void fn_805909D4(Db805909D4_S* self);
extern "C" void fn_80590A48();
extern "C" void fn_80590A4C(Db80590A4C_S* s);
extern "C" void fn_80590BA0(Db80590EB4_S2* self);
extern "C" void fn_80590C24(Db80590EB4_S2* self);
extern "C" void fn_80590EB4(Db80590EB4_S* self);
extern "C" void fn_80590F40(Db80590A4C_S* s, int a, Unk80070DDC_Stream* io);
extern "C" void fn_8059124C(Db8059124C_S* self);
extern "C" float fn_80591270(Db80590A4C_S* s);
extern "C" void fn_80591378(Db8059124C_S* self);
extern "C" float fn_8059139C(Db805909D4_S* self, int id);
extern "C" void fn_805919E8(Db805919E8_M* m, int x, int i, int k, float f);
extern "C" int fn_80591A50(Db805919E8_M* m);
extern "C" int fn_80591AA0(Db805919E8_M* m);
extern "C" void fn_80591AF4(Db805919E8_M* m, int x, int i, int k, float f);
extern "C" void fn_80591B40(Db805919E8_M* m, int x);
extern "C" void fn_80591B6C(Db805919E8_M* m, int x, int i);
extern "C" void fn_80591B8C(Db805919E8_M* m, int x, int j, int a3, int a4, int flag, float f);
extern "C" void fn_80591D3C(Db805919E8_M* m);
extern "C" void fn_80591FC8(Db805919E8_M* m);
extern "C" void fn_8059209C(Db805919E8_M* m, float f);
extern "C" void fn_805920BC(Db805919E8_M* m);
extern "C" void fn_805921E4(Db805919E8_M* m);
extern "C" float fn_80592288(Db805919E8_M* m, int x);
extern "C" float fn_805922D4(Db805919E8_M* m, int x, int i);
extern "C" float fn_805922EC(Db805919E8_M* m, int x);
extern "C" float fn_80592474(Db805919E8_M* m, int x, int j);
extern "C" float fn_805925D0(Db805919E8_M* m, int x);
extern "C" float fn_805926B8(Db805919E8_M* m, int x, int i);
extern "C" float fn_80592780(Db805919E8_M* m, int x);
extern "C" float fn_805928E0(Db805919E8_M* m, int x, int i);
extern "C" float fn_805929F0(Db805919E8_M* m, int x);
extern "C" float fn_80592A68(Db805919E8_M* m, int x, int i);
extern "C" float fn_80592ABC(Db805919E8_M* m, int x);
extern "C" float fn_80592B38(Db805919E8_M* m, int x, int i);
extern "C" void fn_80592B90(Db805919E8_M* m, int a, Unk80070DDC_Stream* io);
extern "C" int fn_80592E04(Db805937A4_Mgr* m, int i);
extern "C" float fn_80592E98(Db805919E8_M* m, int x, int i);
extern "C" float fn_80592F94(Db805919E8_M* m, int x, int i, int n);
extern "C" int fn_80593088(Db805919E8_M* m, int x, int i);
extern "C" int fn_805931BC(Db805919E8_M* m, int x, int i, int n);
extern "C" char* fn_805932E4(char* m, int a, int b, int c);
extern "C" int fn_805934C0(Db805919E8_M* m, int key, int start, int flag);
extern "C" void fn_805935B8(Db805919E8_M* m, int id);

/* near-miss (97.5%): the scheduler hoists the mA8/mAC stores above the mBC/mC0 pair; retail keeps source order (120 orders of the
   last five stores tried). */
extern "C" DB_OVERLAY Db80590A4C_S* fn_805902E0(Db80590A4C_S* s)
{
    *(const void**)((char*)s + 0xC4) = lbl_80682D10;
    s->m24 = -1;
    *(float*)((char*)s + 0xBC) = 0.0f;
    s->mC0 = 0;
    s->m0 = 0;
    s->m4 = 0;
    s->m8 = 0;
    s->mC = 0;
    s->m10 = 0;
    s->m14 = 0;
    s->m18 = 0;
    s->m1C = 0;
    s->m20 = 0;
    s->m28 = 0;
    s->m2C = 0;
    s->mB0 = 0;
    s->mB4 = 0;
    s->mA8 = 0;
    s->mB8 = 0.0f;
    *(float*)&s->mAC = 0.0f;
    for (int i = 0; i < 30; i++)
        s->m30[i] = 0.0f;
    if (s->m0 == 0)
        s->m0 = fn_805917F4((Db805919E8_M*)operator new(0x12B94, 0));
    if (s->m8 == 0)
        s->m8 = (Db8058F924_V*)fn_80593A00(operator new(0x50, 0), s->m0, 0x574F, 0.3f);
    if (s->m4 == 0)
        s->m4 = (Db8058F924_V*)fn_805945A4(operator new(0x1F4, 0), s->m0, 0x577E, 0.3f);
    if (s->m18 == 0)
        s->m18 = (Db805942E0_V*)fn_80594A10(operator new(0x1C, 0), s->m4, s->m0, 0x577F);
    if (s->mC == 0)
        s->mC = (Db8058F924_V*)fn_805951B8(operator new(0x170, 0), s->m0, 0x583A, 0.3f);
    if (s->m1C == 0)
        s->m1C = (Db805942E0_V*)fn_80595598(operator new(0x1C, 0), s->mC, s->m0, 0x583B);
    if (s->m20 == 0)
        s->m20 = (int)fn_80595F8C(operator new(0x18, 0), s->m0, 0x5C6D);
    if (s->m14 == 0)
        s->m14 = (Db805942E0_V*)fn_80595B64(operator new(0x18, 0), s->m0, 0x14C9);
    if (s->m10 == 0)
        s->m10 = (Db8058F924_V*)fn_80596040(operator new(0x544, 0), s->m0, 0x14CC);
    if (s->m28 == 0)
        s->m28 = fn_80596D88(operator new(0x38, 0));
    if (s->m2C == 0)
        s->m2C = (int)fn_80597A5C(operator new(0x1C, 0));
    return s;
}

extern "C" DB_OVERLAY void fn_8059055C(Db80590A4C_S* s, int chrg)
{
    *(const void**)((char*)s + 0xC4) = lbl_80682D10;
    if (s->m2C != 0) {
        ((Db8059055C_D18*)s->m2C)->v08(3);
        s->m2C = 0;
    }
    if (s->m28 != 0) {
        ((Db8059055C_D34*)s->m28)->v08(3);
        s->m28 = 0;
    }
    if (s->m10 != 0) {
        s->m10->v08(3);
        s->m10 = 0;
    }
    if (s->m14 != 0) {
        s->m14->v08(3);
        s->m14 = 0;
    }
    if (s->m20 != 0) {
        ((Db805942E0_V*)s->m20)->v08(3);
        s->m20 = 0;
    }
    if (s->m1C != 0) {
        s->m1C->v08(3);
        s->m1C = 0;
    }
    if (s->mC != 0) {
        s->mC->v08(3);
        s->mC = 0;
    }
    if (s->m18 != 0) {
        s->m18->v08(3);
        s->m18 = 0;
    }
    if (s->m4 != 0) {
        s->m4->v08(3);
        s->m4 = 0;
    }
    if (s->m8 != 0) {
        s->m8->v08(3);
        s->m8 = 0;
    }
    if (s->m0 != 0) {
        ((Db8059055C_DM*)s->m0)->v08(3);
        s->m0 = 0;
    }
    if (chrg & 1)
        fn_80377408(s);
}

extern "C" DB_OVERLAY void fn_805907B8(Db80590A4C_S* s, int a)
{
    if (fn_800B5758(fn_800B555C()) == 1 && s->mC0 == 0) {
        Unk8007B2B0_Screen* scr = (Unk8007B2B0_Screen*)lbl_8061930C;
        float sp = scr->fn_80079E74(fn_8007F7D0((Unk8007F198_B*)scr, 0));
        float v = 0.0f;
        switch (fn_8007FE04__FP13Unk8007F198_D(scr)->m1E4) {
        case 0:
            v = 0.0f;
            break;
        case 1:
            v = 2000000.0f;
            break;
        case 2:
            v = 5000000.0f;
            break;
        default:
            v = sp * 0.03f;
            break;
        }
        fn_8059209C(s->m0, v);
        s->mC0 = 1;
        s->mB4 = 0;
        int lo = fn_8007FBC0((Unk8007F198_C*)scr, 0, 0);
        fn_8007FB2C((Unk8007F198_C*)scr, 0);
        int j = 0;
        do {
            if (fn_8007FB2C((Unk8007F198_C*)scr, j) > 0) {
                int t = fn_8007FBC0((Unk8007F198_C*)scr, 0, j);
                if (t < lo)
                    lo = t;
            }
            j++;
        } while (j <= 3);
        s->m24 = lo;
    }
}

extern "C" DB_OVERLAY void fn_80590910(Db80590A4C_S* s)
{
    if (fn_800B5758(fn_800B555C()) == 1) {
        void* g = lbl_80619948;
        int t = fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0);
        s->m10->v48();
        fn_80591FC8(s->m0);
        if (fn_800A2E90(g) != 0) {
            fn_805913C0(s, 1);
            fn_80590BA0((Db80590EB4_S2*)s);
            fn_80590C24((Db80590EB4_S2*)s);
        }
        s->mB4 = 0;
        if (s->mC0 == 0)
            fn_805907B8(s, t);
    }
}

extern "C" DB_OVERLAY void fn_805909D4(Db805909D4_S* self)
{
    if (fn_800B5758(fn_800B555C()) == 1 && self->m24 != 0) {
        Db80329FA0_Out o = fn_80329FA0(self->m24);
        int t = o.m2 - 0x7D5;
        if (t >= 0)
            self->m30[t] = self->m0->m12B78;
    }
}

extern "C" DB_OVERLAY void fn_80590A48()
{
}

extern "C" DB_OVERLAY void fn_80590A4C(Db80590A4C_S* s)
{
    if (fn_800B5758(fn_800B555C()) == 1) {
        s->mB8 = 0.0f;
        s->mBC = 0.0f;
        for (int i = 0; i < 30; i++)
            s->m30[i] = 0.0f;
        fn_8059209C(s->m0, 0.0f);
        fn_80591D3C(s->m0);
        fn_80596E00(s->m28);
        s->m4->v28();
        s->mC->v28();
        s->m14->v18();
        s->m18->v18();
        s->m1C->v18();
        s->m8->v28();
        s->m10->v28();
        s->mC0 = 0;
        s->mB4 = 0;
    }
}

extern "C" DB_OVERLAY void fn_80590BA0(Db80590EB4_S2* self)
{
    if (fn_800B5758(fn_800B555C()) == 1) {
        Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
        int t = fn_8007F7D0((Unk8007F198_B*)s, 0);
        fn_80591B40(self->m0, 0);
        float f = fn_80079CF8(s, t);
        fn_805919E8(self->m0, 0, 0, 1, f);
    }
}

extern "C" DB_OVERLAY void fn_80590C24(Db80590EB4_S2* self)
{
    if (fn_800B5758(fn_800B555C()) == 1) {
        Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
        int t = fn_8007F7D0((Unk8007F198_B*)s, 0);
        fn_80591B40(self->m0, 1);
        float f = s->fn_80079BF8(t);
        fn_805919E8(self->m0, 1, 0, 1, f);
    }
}

extern "C" DB_OVERLAY void fn_80590EB4(Db80590EB4_S* self)
{
    if (fn_800B5758(fn_800B555C()) == 1) {
        Db80619948_G* g = (Db80619948_G*)lbl_80619948;
        int n = g->m84;
        if (n > self->m24) {
            do {
                if (fn_800A2E90(g) != 0 || fn_800A2EB4(g) != 0)
                    fn_805921E4(self->m0);
                self->m24++;
            } while (n > self->m24);
        }
    }
}

extern "C" DB_OVERLAY void fn_80590F40(Db80590A4C_S* s, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, &s->m24, 4);
    ((Db80590F40_SM*)s->m0)->v10(a, io);
    ((Db80590F40_S1C*)s->m8)->v30(a, io);
    ((Db80590F40_S1C*)s->m4)->v30(a, io);
    ((Db80590F40_S14*)s->m18)->v20(a, io);
    ((Db80590F40_S14*)s->m14)->v20(a, io);
    ((Db80590F40_S14*)s->m20)->v20(a, io);
    ((Db80590F40_S1C*)s->mC)->v30(a, io);
    ((Db80590F40_S14*)s->m1C)->v20(a, io);
    ((Db80590F40_S1C*)s->m10)->v30(a, io);
    fn_80551A04(a, io);
    ((Db80590F40_S34*)s->m28)->v10(a, io);
    ((Db80590F40_S18*)s->m2C)->v10(a, io);
    io->v08(a, s->m30, 0x78);
    io->v08(a, &s->mA8, 4);
    io->v08(a, &s->mAC, 4);
    io->v08(a, &s->mB0, 4);
    io->v08(a, &s->mB4, 4);
    io->v08(a, &s->mB8, 4);
    io->v08(a, &s->mBC, 4);
    io->v08(a, &s->mC0, 4);
}

extern "C" DB_OVERLAY void fn_8059124C(Db8059124C_S* self)
{
    fn_80596E3C(self->m28);
}

extern "C" DB_OVERLAY float fn_80591270(Db80590A4C_S* s)
{
    float r = 0.0f;
    Db80591270_Scr* scr = (Db80591270_Scr*)lbl_8061930C;
    r = lbl_806E03A0[0] * fn_805948E8(s->m4) + lbl_806E03A0[1] * fn_80593BD4(s->m8) + lbl_806E03A0[2] * fn_80595470(s->mC) + lbl_806E03A0[3] * fn_8058F420(scr->m34);
    r = Db80591270_Max(Db80591270_Min(r, 1.0f), 0.0f);
    return r;
}

extern "C" DB_OVERLAY void fn_80591378(Db8059124C_S* self)
{
    fn_80596FCC(self->m28);
}

extern "C" DB_OVERLAY float fn_8059139C(Db805909D4_S* self, int id)
{
    int t = id - 0x7D5;
    return t >= 0 ? self->m30[t] : 0.0f;
}

extern "C" DB_OVERLAY void fn_805919E8(Db805919E8_M* m, int x, int i, int k, float f)
{
    if (k != 0) {
        m->t0[x][i] = m->t0[x][i] + f;
        return;
    }
    m->t2[x][i] = m->t2[x][i] + f;
    m->m12B78 = m->m12B78 - f;
}

extern "C" DB_OVERLAY int fn_80591A50(Db805919E8_M* m)
{
    if (fn_800A2EB4(lbl_80619948) != 0)
        return m->m12B74;
    return m->m12B70;
}

extern "C" DB_OVERLAY int fn_80591AA0(Db805919E8_M* m)
{
    int r;
    if (fn_800A2EB4(lbl_80619948) == 0)
        r = m->m12B70;
    else
        r = m->m12B74;
    return r + 1;
}

extern "C" DB_OVERLAY void fn_80591AF4(Db805919E8_M* m, int x, int i, int k, float f)
{
    if (k != 0) {
        m->t0[x][i] = m->t0[x][i] - f;
        return;
    }
    m->m12B78 = m->m12B78 + f;
}

extern "C" DB_OVERLAY void fn_80591B40(Db805919E8_M* m, int x)
{
    for (int j = 0; j < 16; j++)
        m->t0[x][j] = 0.0f;
}

extern "C" DB_OVERLAY void fn_80591B6C(Db805919E8_M* m, int x, int i)
{
    char* b = (char*)m + 0x340;
    int o = i * 4 + (x << 6);
    *(float*)(b + o) = 0.0f;
}

/* near-miss (83 slots): retail folds the three field stores into separate base+offset forms and reloads m12B70 for each. */
extern "C" DB_OVERLAY void fn_80591B8C(Db805919E8_M* m, int x, int j, int a3, int a4, int flag, float f)
{
    if (flag != 0) {
        m->t1[x][j] = m->t1[x][j] + f;
        return;
    }
    if (fn_800A2EB4(lbl_80619948) == 0) {
        int o = j * 0xC + x * 0xC0;
        *(float*)((char*)m + 0x880 + (o + m->m12B70 * 0x300)) = f;
        *(int*)((char*)m + 0x884 + (o + m->m12B70 * 0x300)) = a3;
        *(int*)((char*)m + 0x888 + (o + m->m12B70 * 0x300)) = a4;
        m->m12B78 = f * (float)a4 + m->m12B78;
        return;
    }
    int o = j * 0xC + x * 0xC0;
    *(float*)((char*)m + 0x109C0 + (o + m->m12B74 * 0x300)) = f;
    *(int*)((char*)m + 0x109C4 + (o + m->m12B74 * 0x300)) = a3;
    *(int*)((char*)m + 0x109C8 + (o + m->m12B74 * 0x300)) = a4;
    m->m12B78 = f * (float)a4 + m->m12B78;
}

extern "C" DB_OVERLAY void fn_80591D3C(Db805919E8_M* m)
{
    int r, j;
    for (r = 0; r < 13; r++)
        for (j = 0; j < 16; j++)
            m->t0[r][j] = 0.0f;
    for (r = 0; r < 4; r++)
        for (j = 0; j < 16; j++)
            m->t1[r][j] = 0.0f;
    fn_80591DEC(m);
    m->m12B78 = m->m12B7C;
}

extern "C" DB_OVERLAY void fn_80591FC8(Db805919E8_M* m)
{
    int k = 0;
    fn_80591DEC(m);
    Unk8007F198_C* s = (Unk8007F198_C*)lbl_8061930C;
    int lo = fn_8007FBC0(s, 0, 0);
    int hi = fn_8007FBC0(s, fn_8007FB2C(s, 0) - 1, 0);
    do {
        int n = fn_8007FB2C(s, k);
        if (n > 0) {
            int v = fn_8007FBC0(s, 0, k);
            if (v < lo)
                lo = v;
            v = fn_8007FBC0(s, n - 1, k);
            if (v > hi)
                hi = v;
        }
        k++;
    } while (k <= 3);
    m->m12B80 = hi - lo + 1;
}

extern "C" DB_OVERLAY void fn_8059209C(Db805919E8_M* m, float f)
{
    m->m12B7C = f;
    m->m12B78 = f;
}

/* near-miss (62 slots): retail runs the outer 13/4-row loops on ctr (bdnz) and the 16-slot inner loops on an explicit counter. */
extern "C" DB_OVERLAY void fn_805920BC(Db805919E8_M* m)
{
    float t = 0.0f;
    int r = 0;
    int cr = 13;
    do {
        int o = r;
        int n = 16;
        do {
            t = *(float*)((char*)m + o) / (float)m->m12B80;
            *(float*)((char*)m + 0x440 + o) = *(float*)((char*)m + 0x440 + o) + t;
            o += 4;
            m->m12B78 = m->m12B78 - t;
            n--;
        } while (n != 0);
        r += 0x40;
        cr--;
    } while (cr != 0);
    float u = 0.0f;
    r = 0;
    cr = 4;
    do {
        int o = 0;
        int n = 16;
        do {
            int q = o + r;
            u = *(float*)((char*)m + 0x340 + q) / (float)m->m12B80;
            *(float*)((char*)m + 0x780 + q) = *(float*)((char*)m + 0x780 + q) + u;
            o += 4;
            n--;
            m->m12B78 = m->m12B78 + u;
        } while (n != 0);
        r += 0x40;
        cr--;
    } while (cr != 0);
}

extern "C" DB_OVERLAY void fn_805921E4(Db805919E8_M* m)
{
    if (fn_800A2E90(lbl_80619948) != 0) {
        fn_805920BC(m);
        int t = m->m12B84;
        if (t < m->m12B80)
            m->m12B84 = t + 1;
    } else if (fn_800A2EB4(lbl_80619948) != 0) {
        int r = fn_805560A8(fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0), 0);
        if (r != 2 && r != 0)
            fn_805920BC(m);
    }
}

extern "C" DB_OVERLAY float fn_80592288(Db805919E8_M* m, int x)
{
    float s = 0.0f;
    for (int j = 0; j < 16; j++)
        s += m->t2[x][j];
    return s;
}

extern "C" DB_OVERLAY float fn_805922D4(Db805919E8_M* m, int x, int i)
{
    return m->t2[x][i];
}

extern "C" DB_OVERLAY float fn_805922EC(Db805919E8_M* m, int x)
{
    float s = 0.0f;
    int k;
    int j;
    for (k = 0; k <= m->m12B70; k++) {
        for (j = 0; j < 16; j++) {
            Db805922EC_Cell* c = &m->a[k].c[x][j];
            s += c->m0 * (float)c->m8;
        }
    }
    for (j = 0; j < 16; j++)
        s += m->t3[x][j];
    if (fn_800A2EB4(lbl_80619948) != 0) {
        for (k = 0; k <= m->m12B74; k++) {
            for (j = 0; j < 16; j++) {
                Db805922EC_Cell* c = &m->b[k].c[x][j];
                s += c->m0 * (float)c->m8;
            }
        }
    }
    return s;
}

/* near-miss (85 slots): retail walks the group pointers by +0x300 per step, as here, but keeps m in r31 with addis r28,r31,1 for the counters. */
extern "C" DB_OVERLAY float fn_80592474(Db805919E8_M* m, int x, int j)
{
    float r = 0.0f;
    int k;
    for (k = 0; k <= m->m12B70; k++) {
        Db805922EC_Cell* c = &m->a[k].c[x][j];
        r += c->m0 * (float)c->m8;
    }
    r += m->t3[x][j];
    if (fn_800A2EB4(lbl_80619948) != 0) {
        for (k = 0; k <= m->m12B74; k++) {
            Db805922EC_Cell* c = &m->b[k].c[x][j];
            r += c->m0 * (float)c->m8;
        }
    }
    return r;
}

extern "C" DB_OVERLAY float fn_805925D0(Db805919E8_M* m, int x)
{
    float r = fn_80592288(m, x);
    float s = 0.0f;
    if (fn_800A2EB4(lbl_80619948) == 0) {
        for (int j = 0; j < 16; j++)
            s += m->t0[x][j] / (float)m->m12B80;
        r += s * (float)(m->m12B80 - m->m12B84);
    }
    return r;
}

extern "C" DB_OVERLAY float fn_805926B8(Db805919E8_M* m, int x, int i)
{
    float r = fn_805922D4(m, x, i);
    if (fn_800A2EB4(lbl_80619948) == 0) {
        float t = m->t0[x][i] / (float)m->m12B80;
        r += t * (float)(m->m12B80 - m->m12B84);
    }
    return r;
}

extern "C" DB_OVERLAY float fn_80592780(Db805919E8_M* m, int x)
{
    float sa = 0.0f;
    float sb = 0.0f;
    int j = 0;
    float r = fn_805922EC(m, x);
    if (fn_800A2EB4(lbl_80619948) == 0) {
        for (; j < 16; j++) {
            sa += fn_80592E98(m, x, j);
            sb += m->t1[x][j] / (float)m->m12B80;
        }
        int d = fn_8056B840(((Db805934C0_G*)lbl_80619948)->m28, 0) - fn_80591AA0(m);
        r = (sa * (float)d + r) + sb * (float)(m->m12B80 - m->m12B84);
    }
    return r;
}

extern "C" DB_OVERLAY float fn_805928E0(Db805919E8_M* m, int x, int i)
{
    float r = fn_80592474(m, x, i);
    if (fn_800A2EB4(lbl_80619948) == 0) {
        int a = fn_8056B840(((Db805934C0_G*)lbl_80619948)->m28, 0) - fn_80591AA0(m);
        r = (fn_80592E98(m, x, i) * (float)a + r) + m->t1[x][i] / (float)m->m12B80 * (float)(m->m12B80 - m->m12B84);
    }
    return r;
}

extern "C" DB_OVERLAY float fn_805929F0(Db805919E8_M* m, int x)
{
    float s = 0.0f;
    for (int j = 0; j < 16; j++)
        s += m->t0[x][j] / (float)m->m12B80;
    return s;
}

extern "C" DB_OVERLAY float fn_80592A68(Db805919E8_M* m, int x, int i)
{
    float r = m->t0[x][i] / (float)m->m12B80;
    return r;
}

extern "C" DB_OVERLAY float fn_80592ABC(Db805919E8_M* m, int x)
{
    float s = 0.0f;
    for (int j = 0; j < 16; j++)
        s += m->t1[x][j] / (float)m->m12B80;
    return s;
}

extern "C" DB_OVERLAY float fn_80592B38(Db805919E8_M* m, int x, int i)
{
    char* b = (char*)m + 0x340;
    int o = i * 4 + (x << 6);
    float r = *(float*)(b + o) / (float)m->m12B80;
    return r;
}

extern "C" DB_OVERLAY void fn_80592B90(Db805919E8_M* m, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, m, 0x340);
    io->v08(a, m->t1, 0x100);
    io->v08(a, m->t2, 0x340);
    io->v08(a, m->t3, 0x100);
    io->v08(a, m->a, 0xFC00);
    io->v08(a, m->b, 0x2100);
    io->v08(a, m->ra, 0x540);
    io->v08(a, m->rb, 0xB0);
    io->v08(a, &m->m12B70, 4);
    io->v08(a, &m->m12B74, 4);
    io->v08(a, &m->m12B78, 4);
    io->v08(a, &m->m12B7C, 4);
    io->v08(a, &m->m12B80, 4);
    io->v08(a, &m->m12B84, 4);
    io->v08(a, &m->m12B88, 4);
    io->v08(a, &m->m12B8C, 4);
}

extern "C" DB_OVERLAY int fn_80592E04(Db805937A4_Mgr* m, int i)
{
    if (fn_800A2EB4(lbl_80619948) == 0) {
        if (i >= 0 && i <= m->m12B70)
            return m->a[i].m0;
    } else {
        if (i >= 0 && i <= m->m12B74)
            return m->b[i].m0;
    }
    return -1;
}

extern "C" DB_OVERLAY float fn_80592E98(Db805919E8_M* m, int x, int i)
{
    float s = 0.0f;
    int k;
    for (k = 0; k <= m->m12B70; k++) {
        Db805922EC_Cell c = m->a[k].c[x][i];
        s += c.m0 * (float)c.m8;
    }
    if (m->m12B70 >= 0)
        s = s / (float)(m->m12B70 + 1);
    return s;
}

extern "C" DB_OVERLAY float fn_80592F94(Db805919E8_M* m, int x, int i, int n)
{
    float s = 0.0f;
    for (int k = 0; k < n; k++) {
        Db805922EC_Cell c = m->a[m->m12B70 - k].c[x][i];
        s += c.m0 * (float)c.m8;
    }
    s = s / (float)n;
    return s;
}

extern "C" DB_OVERLAY int fn_80593088(Db805919E8_M* m, int x, int i)
{
    float s = 0.0f;
    int skipped = 0;
    int k = 0;
    for (k = skipped; k <= m->m12B70; k++) {
        Db805922EC_Cell c = m->a[k].c[x][i];
        if (c.m4 > 0)
            s += (float)(c.m8 * 100 / c.m4);
        else
            skipped++;
    }
    int cnt = m->m12B70 - skipped;
    if (cnt >= 0)
        s = s / (float)(cnt + 1);
    else
        s = 0.0f;
    return (int)s;
}

extern "C" DB_OVERLAY int fn_805931BC(Db805919E8_M* m, int x, int i, int n)
{
    float s = 0.0f;
    int skipped = 0;
    int k = 0;
    for (k = skipped; k < n; k++) {
        Db805922EC_Cell c = m->a[m->m12B70 - k].c[x][i];
        if (c.m4 > 0)
            s += (float)(c.m8 * 100 / c.m4);
        else
            skipped++;
    }
    if (n - skipped > 0)
        s = s / (float)n;
    else
        s = 0.0f;
    return (int)s;
}

extern "C" DB_OVERLAY char* fn_805932E4(char* m, int a, int b, int c)
{
    if (fn_800A2EB4(lbl_80619948) == 0)
        return m + (c * 0x300 + 0x880) + a * 0xC0 + b * 0xC;
    return m + (c * 0x300 + 0x109C0) + a * 0xC0 + b * 0xC;
}

extern "C" DB_OVERLAY int fn_805934C0(Db805919E8_M* m, int key, int start, int flag)
{
    void* scr = lbl_8061930C;
    int m28 = ((Db805934C0_G*)lbl_80619948)->m28;
    int i = start;
    if (flag != 0)
        i--;
    int done = 0;
    while (i >= 0) {
        int r;
        if (fn_800A2EB4(lbl_80619948) == 0) {
            int t = fn_8007FB98__FP13Unk8007F198_Ciii(scr, m->ra[i].m0, 0, 0);
            r = fn_8056A5F4(m28, 0, m->ra[i].m0, t);
        } else {
            int t = fn_8007FB98__FP13Unk8007F198_Ciii(scr, m->rb[i].m0, 0, 0);
            r = fn_8056A5F4(m28, 0, m->rb[i].m0, t);
        }
        if (r == key)
            break;
        i--;
        if (done != 0)
            break;
    }
    return i;
}

/* near-miss (98.2%): the call to fn_800A2E90 reads lbl_80619948 through a hoisted `lis` above the m4 store; retail keeps it below. */
extern "C" DB_OVERLAY void fn_805935B8(Db805919E8_M* m, int id)
{
    Db805935B8_Obj* o = lbl_806192E0->m4;
    Db805935B8_Sums* sums = ((Db805935B8_Scr*)lbl_8061930C)->m30->m2C;
    int total = 0;
    for (int k = 0; k < 5; k++)
        total += sums->m4[k];
    char* mc = (char*)m;
    int* ids;
    int* vals;
    float* fs;
    int idx;
    if (fn_800A2EB4(lbl_80619948) == 0) {
        ids = (int*)(mc + 0x10480);
        vals = (int*)(mc + 0x10484);
        fs = (float*)(mc + 0x10488);
        m->m12B70++;
        ids[m->m12B70 * 4] = id;
        {
            int t = o->mC->m14;
            { char* p = mc + m->m12B70 * 16; *(p + 0x1048C) = t; }
        }
        fs[m->m12B70 * 4] = o->mC->m18;
        idx = m->m12B70;
    } else {
        ids = (int*)(mc + 0x12AC0);
        vals = (int*)(mc + 0x12AC4);
        fs = (float*)(mc + 0x12AC8);
        m->m12B74++;
        ids[m->m12B74 * 4] = id;
        {
            int t = o->mC->m14;
            { char* p = mc + m->m12B74 * 16; *(p + 0x12ACC) = t; }
        }
        fs[m->m12B74 * 4] = o->mC->m18;
        idx = m->m12B74;
    }
    vals[idx * 4] = total;
    void** gp = &lbl_80619948;
    if (fn_800A2E90(*gp) != 0) {
        int n = m->m12B70;
        if (n <= 0)
            m->m12B88 = total;
        else
            m->m12B88 = (m->m12B88 * n + total) / (n + 1);
    } else if (fn_800A2EB4(lbl_80619948) != 0) {
        int n = m->m12B74;
        if (n <= 0)
            m->m12B8C = total;
        else
            m->m12B8C = (m->m12B8C * n + total) / (n + 1);
    }
}
