/*
 * Database overlay code, .database_codeoverlay 0x8053CC9C-0x8053E240 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8053967C.h"

typedef Db8053CC9C_Rec R2C;
typedef Unk80084910_K<Unk80084910_T8> K8;
typedef Unk80084910_VObj VObj;
typedef Unk80084910_G G;

extern char lbl_80684380[];
extern char lbl_80684310[];
extern const char lbl_805FE19C[];
extern int lbl_806015D8[];
extern DbPmf lbl_806015A8[];
extern const float lbl_805FEDA0;
extern Db8053CC9C_A5 lbl_805FEDA4;

/* Q18 types */
struct Db8053CC9C_R1C {
    char pad0[0x1C];
    unsigned m1C;
};

int fn_800849C0(int a);
/* end Q18 types */

extern "C" {
/* Q18 protos */
Unk80071604* fn_8053CC9C(Unk80071604* self, const char* name, Obj* type, unsigned count);
void fn_8053CD18(Unk80071604* self, int chrg);
void fn_8053CD74(Unk80071604* self, unsigned i);
int fn_8053CDB0(void* l, int k);
int fn_8053CE50(void* l, int k);
int fn_8053CE9C(void* l, int k, unsigned c);
char* fn_8053D090(void* l, int k, unsigned c, char* out);
float fn_8053D110(void* o, int i, int a);
void fn_8053D1A8(void* l, int k, unsigned c, int v);
void fn_8053D580(Unk80071604* a, signed char k, unsigned c, const char* src, int n);
float fn_8053D66C(G* self, int a);
float fn_8053D6D8(G* self, int a);
float fn_8053D744(G* self, int a);
float fn_8053D7B4(G* self, int a);
float fn_8053D830(G* self, int a);
float fn_8053D8AC(G* self, int a);
void fn_8053D900(Unk80071604* self, int a, VObj* obj);
Unk80071604* fn_8053D95C(Unk80071604* self, const char* name, Obj* type, unsigned count);
void fn_8053D9D8(Unk80071604* self, int chrg);
void fn_8053DA34(Unk80071604* self, unsigned i);
int fn_8053DA70(void* self);
int fn_8053DA78(void* self);
int fn_8053DA80(void* self);
int fn_8053DA88(void* self, int a, int b, int c);
float fn_8053DA90();
void fn_8053DAAC();
void fn_8053DAB0();
void fn_8053DAB4(Unk80071604* self, int a, VObj* obj);
Unk80084910_T8* fn_8053DB10(K8* self, int i);
Unk80084910_T8* fn_8053DB20(K8* self, int i);
R2C* fn_8053DB30(R2C* dst, Db8053CC9C_Src* src);
void* fn_8053DD34(void* self, int a);
Db8053CC9C_SrcBits* fn_8053DD68(Db8053CC9C_SrcBits* dst, Db8053CC9C_Src2* src);
int fn_8053DDE8();
int fn_8053DDF0(int i);
int fn_8053DE38(void* c, int id, int k, float f);
int fn_8053DF70(void* c, int id, int k, float f);
/* end Q18 protos */

/* Q18 decls */
float fn_8053E0B4(void* c, int k);
extern "C" float fn_8007BB28__18Unk8007B2B0_Screeniii(void* s, int a, int b, int c);
extern "C" int fn_80539A84(int k);
extern "C" float fn_800748D4(void* s, int a, int b, int c);
extern "C" Db8053CC9C_R1C* fn_8007FE04__FP13Unk8007F198_D(void* g);
extern "C" int fn_800A2E6C(void* g);
extern "C" float fn_80541CDC(float a, float b, float c, float d, float e);
/* end Q18 decls */

DB_OVERLAY Unk80071604* fn_8053CC9C(Unk80071604* self, const char* name, Obj* type, unsigned count)
{
    fn_80071604(self, name, type, count);
    self->m20 = lbl_80684380;
    self->m24 = 0;
    self->m24 = (char*)operator new[](self->m1C * 0x2C, 0);
    fn_8040074C(self->m24, self->m1C * 0x2C);
    self->m14 = fn_8007366C(lbl_805FE19C, lbl_805FE19C);
    return self;
}

DB_OVERLAY void fn_8053CD18(Unk80071604* self, int chrg)
{
    self->m20 = lbl_80684380;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

DB_OVERLAY void fn_8053CD74(Unk80071604* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(self->m24 + i * 0x2C, 0x2C);
}

/* Column table: one assignment per case; the dead compares are left by jump2
   (PATTERNS, "Hard-case families 4"). */
DB_OVERLAY int fn_8053CDB0(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 0;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    case 4:
        r = 0;
        break;
    case 5:
        r = 0;
        break;
    case 6:
        r = 0;
        break;
    case 7:
        r = 0;
        break;
    case 8:
        r = 0;
        break;
    case 9:
        r = 0;
        break;
    case 10:
        r = 100;
        break;
    case 11:
        r = 100;
        break;
    case 12:
        r = 100;
        break;
    case 13:
        r = 100;
        break;
    case 14:
        r = 100;
        break;
    }
    return r;
}

DB_OVERLAY int fn_8053CE50(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 0;
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = 0;
        break;
    case 4:
        r = 0;
        break;
    case 5:
        r = 0;
        break;
    case 6:
        r = 0;
        break;
    case 7:
        r = 0;
        break;
    case 8:
        r = 0;
        break;
    case 9:
        r = 0;
        break;
    case 10:
        r = 0;
        break;
    case 11:
        r = 0;
        break;
    case 12:
        r = 0;
        break;
    case 13:
        r = 0;
        break;
    case 14:
        r = 0;
        break;
    }
    return r;
}

DB_OVERLAY int fn_8053CE9C(void* l, int k, unsigned c)
{
    Unk80071604* a = (Unk80071604*)l;
    unsigned r = 0;
    if (c < a->m1C) {
        switch ((unsigned)k) {
        case 0:
            r = ((R2C*)a->m24)[c].f0;
            break;
        case 1:
            r = ((R2C*)a->m24)[c].f1;
            break;
        case 2:
            r = ((R2C*)a->m24)[c].f2;
            break;
        case 3:
            r = ((R2C*)a->m24)[c].f3;
            break;
        case 4:
            r = ((R2C*)a->m24)[c].f4;
            break;
        case 5:
            r = ((R2C*)a->m24)[c].f5;
            break;
        case 6:
            r = ((R2C*)a->m24)[c].f6;
            break;
        case 7:
            r = ((R2C*)a->m24)[c].f7;
            break;
        case 8:
            r = ((R2C*)a->m24)[c].f8;
            break;
        case 9:
            r = ((R2C*)a->m24)[c].f9;
            break;
        case 10:
            r = ((R2C*)a->m24)[c].f10;
            break;
        case 11:
            r = ((R2C*)a->m24)[c].f11;
            break;
        case 12:
            r = ((R2C*)a->m24)[c].f12;
            break;
        case 13:
            r = ((R2C*)a->m24)[c].f13;
            break;
        case 14:
            r = ((R2C*)a->m24)[c].f14;
            break;
        }
    }
    return r;
}

DB_OVERLAY char* fn_8053D090(void* l, int k, unsigned c, char* out)
{
    Unk80071604* a = (Unk80071604*)l;
    if (c < a->m1C) {
        switch (k) {
        case 0:
            fn_8040B61C(out, a->m24 + c * 0x2C + 0xE);
            break;
        case 1:
            fn_8040B61C(out, a->m24 + c * 0x2C + 0x1A);
            break;
        }
    }
    return out;
}

DB_OVERLAY float fn_8053D110(void* o, int i, int a)
{
    float r = (((DbPObj*)o)->*lbl_806015A8[i])(a);
    return r;
}

DB_OVERLAY void fn_8053D1A8(void* l, int k, unsigned c, int v)
{
    Unk80071604* a = (Unk80071604*)l;
    if (c < a->m1C) {
        switch ((unsigned)k) {
        case 0: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            if (v <= 0xffff) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0xffff;
            }
            r->f0 = v;
            return;
        }
        case 1: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            if (v <= 0x3f) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x3f;
            }
            r->f1 = v;
            return;
        }
        case 2: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            int t;
            if (v <= 0xff) {
                t = v;
                if (t < 0)
                    t = 0;
            } else {
                t = 0xff;
            }
            r->f2 = t;
            return;
        }
        case 3: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x1;
            }
            r->f3 = v;
            return;
        }
        case 4: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x1;
            }
            r->f4 = v;
            return;
        }
        case 5: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x7;
            }
            r->f5 = v;
            return;
        }
        case 6: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x1;
            }
            r->f6 = v;
            return;
        }
        case 7: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            if (v <= 0x7f) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x7f;
            }
            r->f7 = v;
            return;
        }
        case 8: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            if (v <= 0x3f) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x3f;
            }
            r->f8 = v;
            return;
        }
        case 9: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            int t;
            if (v <= 0xff) {
                t = v;
                if (t < 0)
                    t = 0;
            } else {
                t = 0xff;
            }
            r->f9 = t;
            return;
        }
        case 10: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            if (v <= 0x64) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x64;
            }
            r->f10 = v;
            return;
        }
        case 11: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            if (v <= 0x64) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x64;
            }
            r->f11 = v;
            return;
        }
        case 12: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            if (v <= 0x64) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x64;
            }
            r->f12 = v;
            return;
        }
        case 13: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            if (v <= 0x64) {
                if (v < 0)
                    v = 0;
            } else {
                v = 0x64;
            }
            r->f13 = v;
            return;
        }
        case 14: {
            R2C* r = (R2C*)(c * 0x2C + (int)a->m24);
            int t;
            if (v <= 0x64) {
                t = v;
                if (t < 0)
                    t = 0;
            } else {
                t = 0x64;
            }
            r->f14 = t;
            return;
        }
        }
    }
}

DB_OVERLAY void fn_8053D580(Unk80071604* a, signed char k, unsigned c, const char* src, int n)
{
    if (c < a->m1C) {
        if (n <= 0)
            n = fn_8040B6A0(src);
        int lim = lbl_806015D8[k] - 1;
        if (n > lim)
            n = lim;
        switch (k) {
        case 0:
            fn_8040B830(a->m24 + c * 0x2C + 0xE, src, n);
            {
                char* q = (char*)(c * 0x2C + (int)a->m24) + 0xE;
                q[n] = 0;
            }
            break;
        case 1:
            fn_8040B830(a->m24 + c * 0x2C + 0x1A, src, n);
            {
                char* q = (char*)(c * 0x2C + (int)a->m24) + 0x1A;
                q[n] = 0;
            }
            break;
        }
    }
}

DB_OVERLAY float fn_8053D66C(G* self, int a)
{
    float r = (float)(self->m20->pfn((char*)self + self->m20->delta, 1, a) + 0x30);
    return r;
}

DB_OVERLAY float fn_8053D6D8(G* self, int a)
{
    float r = (float)(self->m20->pfn((char*)self + self->m20->delta, 2, a) + 0x64);
    return r;
}

DB_OVERLAY float fn_8053D744(G* self, int a)
{
    unsigned char buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 0, a));
    return (float)buf;
}

DB_OVERLAY float fn_8053D7B4(G* self, int a)
{
    Db8053CC9C_Buf3 buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 0, a));
    return (float)buf.b;
}

DB_OVERLAY float fn_8053D830(G* self, int a)
{
    Db8053CC9C_Buf2 buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 0, a));
    return (float)buf.b;
}

DB_OVERLAY float fn_8053D8AC(G* self, int a)
{
    int v = self->m20->pfn((char*)self + self->m20->delta, 9, a);
    float r = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80079A90(v);
    return r;
}

DB_OVERLAY void fn_8053D900(Unk80071604* self, int a, VObj* obj)
{
    fn_80071E2C(self, a, (Unk80070DDC_Stream*)obj);
    Unk80084910_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 0x2C);
}

DB_OVERLAY Unk80071604* fn_8053D95C(Unk80071604* self, const char* name, Obj* type, unsigned count)
{
    fn_80071604(self, name, type, count);
    self->m20 = lbl_80684310;
    self->m24 = 0;
    self->m24 = (char*)operator new[](self->m1C * 8, 0);
    fn_8040074C(self->m24, self->m1C * 8);
    self->m14 = fn_8007366C(lbl_805FE19C, lbl_805FE19C);
    return self;
}

DB_OVERLAY void fn_8053D9D8(Unk80071604* self, int chrg)
{
    self->m20 = lbl_80684310;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

DB_OVERLAY void fn_8053DA34(Unk80071604* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(self->m24 + i * 8, 8);
}

DB_OVERLAY int fn_8053DA70(void* self)
{
    return 0;
}

DB_OVERLAY int fn_8053DA78(void* self)
{
    return 0;
}

DB_OVERLAY int fn_8053DA80(void* self)
{
    return 0;
}

DB_OVERLAY int fn_8053DA88(void* self, int a, int b, int c)
{
    return c;
}

DB_OVERLAY float fn_8053DA90()
{
    float f;
    return f = lbl_805FEDA0;
}

DB_OVERLAY void fn_8053DAAC()
{
}

DB_OVERLAY void fn_8053DAB0()
{
}

DB_OVERLAY void fn_8053DAB4(Unk80071604* self, int a, VObj* obj)
{
    fn_80071E2C(self, a, (Unk80070DDC_Stream*)obj);
    Unk80084910_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 8);
}

DB_OVERLAY Unk80084910_T8* fn_8053DB10(K8* self, int i)
{
    return &self->m24[i];
}

DB_OVERLAY Unk80084910_T8* fn_8053DB20(K8* self, int i)
{
    return &self->m24[i];
}

struct Db8053DB30_W4 {
    unsigned p0 : 1;
    unsigned a : 7;
    unsigned p1 : 1;
    unsigned b : 7;
    unsigned p2 : 1;
    unsigned c : 7;
    unsigned p3 : 1;
    unsigned d : 7;
};
/* near-miss: 99.1%. The one remaining difference is the date (Db8053CC9C_Date at sp+0x10): retail
 * stores its bytes straight into the frame, ours forms `addi rX,r1,16` for the nonzero-offset
 * stores (one extra insn). Tried: ctor/dtor/none on the Date, declaration position, aggregate
 * init, volatile views, byte-pointer stores. The dtor form puts the Date in an early frame slot
 * (sp+8) and moves the call temps, which breaks the layout. Matched parts: the fn_80329FA0 output
 * is read as a whole word then truncated (gives retail's lhz 14(r1)); the four byte-aligned
 * w4 fields are read as 7-bit bitfields (a plain shift by 24/16 is narrowed to lbz/lhz). */
DB_OVERLAY R2C* fn_8053DB30(R2C* dst, Db8053CC9C_Src* src)
{
    fn_8040074C(dst, 0x2C);
    fn_800901C0(dst->name1, lbl_806015D8[0], (src->w4 >> 19) & 0x3FF, dst->name2, lbl_806015D8[1],
                (src->w4 >> 8) & 0x3FF);
    Db8053CC9C_Buf3 buf;
    fn_80329FA0(&buf, 1);
    unsigned bw = *(unsigned*)&buf;
    int tt = (unsigned short)bw;
    unsigned short yr = *(unsigned char*)src + tt;
    unsigned mon = ((src->w0 >> 10) & 0xF) % 12;
    unsigned dim = fn_8032A2CC(mon, yr);
    Db8053CC9C_Date d;
    d.m0 = mon + 1;
    d.m2 = yr;
    d.m1 = ((src->w0 >> 4) & 0x1F) % dim + 1;
    dst->f0 = fn_80329E74(d);
    dst->f6 = (src->w0 >> 14) & 1;
    dst->f9 = (src->w0 >> 18) & 0x3F;
    dst->f5 = (src->w0 >> 15) & 7;
    dst->f1 = (src->w0 & 7) + 0x15;
    dst->f2 = (src->w4 >> 29) * 5 + 0x50;
    dst->f7 = (src->w4 & 0x7F) % 100;
    dst->f8 = (src->w0 >> 8) & 0x3F;
    dst->f10 = fn_80090244((src->w0 >> 3) & 0x7F);
    dst->f11 = fn_80090244(((Db8053DB30_W4*)&src->w4)->a);
    dst->f12 = fn_80090244(((Db8053DB30_W4*)&src->w4)->b);
    dst->f13 = fn_80090244(((Db8053DB30_W4*)&src->w4)->c);
    dst->f14 = fn_80090244(((Db8053DB30_W4*)&src->w4)->d);
    return dst;
}

DB_OVERLAY void* fn_8053DD34(void* self, int a)
{
    fn_803FFA60(self, a, 8);
    return self;
}

/* Same layout as Db8053CC9C_Buf3, but with a trivial destructor: that makes it BLKmode and
   addressable from its declaration, so each `&b` is rebuilt (`addi r3,r1,N`) and the fields
   are read straight from the frame. */
struct Db8053DD68_Buf {
    unsigned short a;
    unsigned short b;
    ~Db8053DD68_Buf() {}
};

DB_OVERLAY Db8053CC9C_SrcBits* fn_8053DD68(Db8053CC9C_SrcBits* dst, Db8053CC9C_Src2* src)
{
    Db8053DD68_Buf b1;
    Db8053DD68_Buf b2;
    fn_80329FA0(&b1, 1);
    unsigned short y1 = b1.b;
    fn_80329FA0(&b2, src->f0);
    unsigned short y2 = b2.b;
    dst->yr = y2 - y1;
    dst->g1 = src->f9;
    dst->g2 = src->f5;
    return dst;
}

DB_OVERLAY int fn_8053DDE8()
{
    return 5;
}

DB_OVERLAY int fn_8053DDF0(int i)
{
    Db8053CC9C_A5 a = lbl_805FEDA4;
    return a.w[i];
}

DB_OVERLAY int fn_8053DE38(void* c, int id, int k, float f)
{
    Unk8007A4DC_Screen* s = (Unk8007A4DC_Screen*)lbl_8061930C;
    int t = s->fn_8007A6A0(5, id);
    if (t == 0 || t == 10) {
        float a = fn_800748D4(s, 0, id, k);
        float b = fn_8007FE04__FP13Unk8007F198_D(s)->m1C;
        float d = fn_8053E0B4(c, k);
        float thr = 0.0f;
        if (!(d <= 0.0f)) {
            if (t == 0)
                thr = a * 9.0f;
            else
                thr = a * 27.0f;
            if (thr >= f * d * b)
                return 1;
        }
    }
    return 0;
}

DB_OVERLAY int fn_8053DF70(void* c, int id, int k, float f)
{
    Unk8007A4DC_Screen* s = (Unk8007A4DC_Screen*)lbl_8061930C;
    float b = fn_8007FE04__FP13Unk8007F198_D(s)->m1C;
    float g = 0.0f;
    float d = fn_8053E0B4(c, k);
    if (!(d > 0.0f))
        return 0;
    if (fn_800A2E6C(lbl_80619948) != 0)
        return 1;
    g = fn_80541CDC(b, d, 3.1f, 2.0f, 1.0f);
    float h = s->fn_800739E0(0xB, id, k, 2);
    return h >= f * g;
}

DB_OVERLAY float fn_8053E0B4(void* c, int k)
{
    Db8053E240_Tmp t;
    int buf[0x82];
    Db8053E240_Tmp* q = &t;
    void* s = lbl_8061930C;
    q->C1(buf, 0x82);
    q->C2();
    q->C3(lbl_8064A2A8);
    int best = 0;
    int w = 1;
    int h = fn_800849C0(k);
    if (k == 0)
        w = 0;
    int m = fn_80539A84(h);
    q->Z();
    fn_805371C4(q, m);
    unsigned n = q->m4;
    q->mC = 0;
    for (unsigned i = 0; i < n; i++) {
        int v = (int)fn_8007BB28__18Unk8007B2B0_Screeniii(s, 2, *(int*)((char*)t.m0 + q->mC * 4), w);
        if (v > best)
            best = v;
        q->mC = (q->mC + 1) % q->m4;
    }
    t.vp = lbl_8064A550;
    return best;
}

}
