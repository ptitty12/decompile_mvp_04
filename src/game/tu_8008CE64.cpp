/*
 * Game code, .text 0x8008CE64-0x80090880 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8007A4DC.h"
#include "game/tu_8008CE64.h"

void* operator new(unsigned int size, int heap);      /* 0x80377428 */
void* operator new[](unsigned int size, int heap);    /* 0x803774A8 */
void fn_80071604(void* self);
void fn_80071688(void* self, int flags);
/* fn_80071E2C is the base-class version of these functions: it takes the same
 * (self, a, obj) and calls obj's slot 1 itself (r4/r5 used without a copy). */
void fn_80071E2C(void* self, int a, void* obj);
void* fn_8007366C(const char* a, const char* b);
void fn_8040074C(void* p, int n);
void* fn_8040B61C(char* dst, const char* src);
extern char lbl_805B3B4C[];
typedef Unk8008CE64_G G;
typedef Unk8008CE64_VObj VObj;

extern char lbl_8064B138[];



extern char lbl_8064A220[];



extern void* lbl_8061930C;
extern float lbl_805B55F8;
extern float lbl_805B5608;
extern float lbl_805B5628;
extern char* lbl_80619308;
extern int lbl_80619738[];
extern void* lbl_80619760;
extern Unk8008CE64_Own* lbl_8061977C;
extern char lbl_805B56C0[];
float fn_800799D0(void* a, int v);
float fn_80079A90(void* a, int v);
void* fn_80329FA0(void* out, int v, ...);
void fn_803EDA0C(void* p);
void fn_80377408(void* p);
void fn_80534E80(void* a, const char* b);
Unk8008CE64_Own* fn_80090744(Unk8008CE64_Own* p);
void fn_8009075C(Unk8008CE64_Own* p, int flags);
void fn_80090814(Unk8008CE64_Own* p, int a, int b);
int fn_800903B8(void* a);




struct Unk8008CE64_Buf3 {
    unsigned short a;
    unsigned short b;
};
struct Unk8008CE64_Buf2 {
    unsigned char a;
    unsigned char b;
    unsigned short pad;
};

char* fn_8008D738(Unk8008CE64_K<Unk8008CE64_T3C>* self, int t, unsigned i, char* buf);
float fn_8008E77C(G* self, int a);
float fn_8008E7F0(G* self, int a);
float fn_8008E864(G* self, int a);
float fn_8008E8D4(G* self, int a);
float fn_8008E950(G* self, int a);
float fn_8008E9CC(G* self, int a);
void fn_8008EA20(Unk8008CE64_K<Unk8008CE64_T3C>* self, int a, VObj* obj);
Unk8008CE64_K<Unk8008CE64_T10>* fn_8008EA7C(Unk8008CE64_K<Unk8008CE64_T10>* self);
void fn_8008EAF8(Unk8008CE64_K<Unk8008CE64_T10>* self, int flags);
void fn_8008EB54(Unk8008CE64_K<Unk8008CE64_T10>* self, unsigned i);
void* fn_8008F08C(void* self, int a, int b, char* buf);
float fn_8008F0B8();
void fn_8008F7E0();
void fn_8008F7E4(Unk8008CE64_K<Unk8008CE64_T10>* self, int a, VObj* obj);
Unk8008CE64_K<Unk8008CE64_T1C>* fn_8008F840(Unk8008CE64_K<Unk8008CE64_T1C>* self);
void fn_8008F8A8(Unk8008CE64_K<Unk8008CE64_T1C>* self, int flags);
void fn_8008F904(Unk8008CE64_K<Unk8008CE64_T1C>* self, unsigned i);
int fn_8008F940(void* self);
int fn_8008F948(void* self);
int fn_8008FCC8(int t);
int fn_8008FD14(int t);
void fn_8009010C();
void fn_80090164();
int fn_800901A4();
float fn_80090380(void* a);
void fn_800906B8();
void fn_80090700();
Unk8008CE64_Own* fn_80090744(Unk8008CE64_Own* self);
void fn_8009075C(Unk8008CE64_Own* self, int flags);
void fn_80090814(Unk8008CE64_Own* self, int a, int b);
































extern Unk8008CE64_Pmf lbl_805B6C50[];

char* fn_8008D738(Unk8008CE64_K<Unk8008CE64_T3C>* self, int t, unsigned i, char* buf);
float fn_8008D7B8(Unk8008CE64_Obj* o, int i, int a);
float fn_8008E77C(G* self, int a);
float fn_8008E7F0(G* self, int a);
float fn_8008E864(G* self, int a);
float fn_8008E8D4(G* self, int a);
float fn_8008E950(G* self, int a);
float fn_8008E9CC(G* self, int a);
void fn_8008EA20(Unk8008CE64_K<Unk8008CE64_T3C>* self, int a, VObj* obj);
Unk8008CE64_K<Unk8008CE64_T10>* fn_8008EA7C(Unk8008CE64_K<Unk8008CE64_T10>* self);
void fn_8008EAF8(Unk8008CE64_K<Unk8008CE64_T10>* self, int flags);
void fn_8008EB54(Unk8008CE64_K<Unk8008CE64_T10>* self, unsigned i);
void* fn_8008F08C(void* self, int a, int b, char* buf);
float fn_8008F0B8();
void fn_8008F7E0();
void fn_8008F7E4(Unk8008CE64_K<Unk8008CE64_T10>* self, int a, VObj* obj);
Unk8008CE64_K<Unk8008CE64_T1C>* fn_8008F840(Unk8008CE64_K<Unk8008CE64_T1C>* self);
void fn_8008F8A8(Unk8008CE64_K<Unk8008CE64_T1C>* self, int flags);
void fn_8008F904(Unk8008CE64_K<Unk8008CE64_T1C>* self, unsigned i);
int fn_8008F940(void* self);
int fn_8008F948(void* self);
unsigned fn_8008F950(Unk8008CE64_K<Unk8008CE64_E1C>* self, int t, unsigned i);
char* fn_8008F99C(Unk8008CE64_K<Unk8008CE64_T1C>* self, int t, unsigned i, char* buf);
void fn_8008FB90(Unk8008CE64_K<Unk8008CE64_T1C>* self, int a, VObj* obj);
int fn_8008FBE8(int v);
int fn_8008FCC8(int t);
int fn_8008FD14(int t);
void fn_8009010C();
void fn_80090164();
int fn_800901A4();
float fn_80090380(void* a);
void fn_800906B8();
void fn_80090700();
Unk8008CE64_Own* fn_80090744(Unk8008CE64_Own* self);
void fn_8009075C(Unk8008CE64_Own* self, int flags);
void fn_80090814(Unk8008CE64_Own* self, int a, int b);





































int fn_8040B6A0(const char* s);
void fn_8040B830(char* dst, const char* src, int n);

char* fn_8008D738(Unk8008CE64_K<Unk8008CE64_T3C>* self, int t, unsigned i, char* buf);
float fn_8008D7B8(Unk8008CE64_Obj* o, int i, int a);
float fn_8008E77C(G* self, int a);
float fn_8008E7F0(G* self, int a);
float fn_8008E864(G* self, int a);
float fn_8008E8D4(G* self, int a);
float fn_8008E950(G* self, int a);
float fn_8008E9CC(G* self, int a);
void fn_8008EA20(Unk8008CE64_K<Unk8008CE64_T3C>* self, int a, VObj* obj);
Unk8008CE64_K<Unk8008CE64_T10>* fn_8008EA7C(Unk8008CE64_K<Unk8008CE64_T10>* self);
void fn_8008EAF8(Unk8008CE64_K<Unk8008CE64_T10>* self, int flags);
void fn_8008EB54(Unk8008CE64_K<Unk8008CE64_T10>* self, unsigned i);
void* fn_8008F08C(void* self, int a, int b, char* buf);
float fn_8008F0B8();
void fn_8008F7E0();
void fn_8008F7E4(Unk8008CE64_K<Unk8008CE64_T10>* self, int a, VObj* obj);
Unk8008CE64_K<Unk8008CE64_T1C>* fn_8008F840(Unk8008CE64_K<Unk8008CE64_T1C>* self);
void fn_8008F8A8(Unk8008CE64_K<Unk8008CE64_T1C>* self, int flags);
void fn_8008F904(Unk8008CE64_K<Unk8008CE64_T1C>* self, unsigned i);
int fn_8008F940(void* self);
int fn_8008F948(void* self);
unsigned fn_8008F950(Unk8008CE64_K<Unk8008CE64_E1C>* self, int t, unsigned i);
char* fn_8008F99C(Unk8008CE64_K<Unk8008CE64_T1C>* self, int t, unsigned i, char* buf);
void fn_8008FA1C(Unk8008CE64_K<Unk8008CE64_E1C>* self, int t, unsigned i, int v);
void fn_8008FAA8(Unk8008CE64_K<Unk8008CE64_T1C>* self, signed char t, unsigned i, const char* str, int n);
void fn_8008FB90(Unk8008CE64_K<Unk8008CE64_T1C>* self, int a, VObj* obj);
int fn_8008FBE8(int v);
int fn_8008FCC8(int t);
int fn_8008FD14(int t);
void fn_8009010C();
void fn_80090164();
int fn_800901A4();
float fn_80090380(void* a);
void fn_800906B8();
void fn_80090700();
Unk8008CE64_Own* fn_80090744(Unk8008CE64_Own* self);
void fn_8009075C(Unk8008CE64_Own* self, int flags);
void fn_80090814(Unk8008CE64_Own* self, int a, int b);




extern const char* lbl_80619764[];
extern "C" void fn_80534F64(void* obj, int a, int b, int c, int d, int e, int f);
extern "C" const char* fn_802B9300(const char* s, int a, int b, unsigned int* outn);
extern "C" void fn_80402DE4(const void* p, int n);



extern int lbl_805B6B90[];


extern int lbl_805B6D70[];
extern float lbl_805B6C80[][5];






/* Column table: one assignment per case; the dead compares are left by jump2
   (PATTERNS, "Hard-case families 4"). */
int fn_8008CE64(void* l, int k)
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
    case 15:
        r = 0;
        break;
    case 16:
        r = 0;
        break;
    case 17:
        r = 0;
        break;
    case 18:
        r = 0;
        break;
    case 19:
        r = 0;
        break;
    case 20:
        r = 0;
        break;
    case 21:
        r = 0;
        break;
    case 22:
        r = 0;
        break;
    case 23:
        r = 0;
        break;
    case 24:
        r = 0;
        break;
    case 25:
        r = 0;
        break;
    case 26:
        r = 0;
        break;
    case 27:
        r = 0;
        break;
    case 28:
        r = 0;
        break;
    case 29:
        r = 0;
        break;
    case 30:
        r = 0;
        break;
    case 31:
        r = 0;
        break;
    case 32:
        r = 0;
        break;
    case 33:
        r = 0;
        break;
    case 34:
        r = 0;
        break;
    case 35:
        r = 0;
        break;
    case 36:
        r = 0;
        break;
    case 37:
        r = 0;
        break;
    case 38:
        r = 0;
        break;
    case 39:
        r = 0;
        break;
    case 40:
        r = 0;
        break;
    case 41:
        r = 0;
        break;
    case 42:
        r = 0;
        break;
    case 43:
        r = 0;
        break;
    case 44:
        r = 0;
        break;
    case 45:
        r = 0;
        break;
    case 46:
        r = 0;
        break;
    case 47:
        r = 0;
        break;
    case 48:
        r = 0;
        break;
    case 49:
        r = 0;
        break;
    case 50:
        r = 0;
        break;
    case 51:
        r = 0;
        break;
    case 52:
        r = 0;
        break;
    case 53:
        r = 0;
        break;
    case 54:
        r = 0;
        break;
    }
    return r;
}

extern "C" unsigned fn_8008CFD8(Unk8008CE64_PackTabE* self, unsigned t, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (t) {
        case 0: r = self->m24[i].h0; break;
        case 1: r = self->m24[i].h2; break;
        case 2: r = self->m24[i].f02; break;
        case 3: r = self->m24[i].f03; break;
        case 4: r = self->m24[i].f04; break;
        case 5: r = self->m24[i].f05; break;
        case 6: r = self->m24[i].f06; break;
        case 7: r = self->m24[i].f07; break;
        case 8: r = self->m24[i].f08; break;
        case 9: r = self->m24[i].f09; break;
        case 10: r = self->m24[i].f0A; break;
        case 11: r = self->m24[i].f0B; break;
        case 12: r = self->m24[i].f0C; break;
        case 13: r = self->m24[i].f0D; break;
        case 14: r = self->m24[i].f0E; break;
        case 15: r = self->m24[i].f0F; break;
        case 16: r = self->m24[i].f10; break;
        case 17: r = self->m24[i].f11; break;
        case 18: r = self->m24[i].f12; break;
        case 19: r = self->m24[i].f13; break;
        case 20: r = self->m24[i].f14; break;
        case 21: r = self->m24[i].f15; break;
        case 22: r = self->m24[i].f16; break;
        case 23: r = self->m24[i].f17; break;
        case 24: r = self->m24[i].f18; break;
        case 25: r = self->m24[i].f19; break;
        case 26: r = self->m24[i].f1A; break;
        case 27: r = self->m24[i].f1B; break;
        case 28: r = self->m24[i].f1C; break;
        case 29: r = self->m24[i].f1D; break;
        case 30: r = self->m24[i].f1E; break;
        case 31: r = self->m24[i].f1F; break;
        case 32: r = self->m24[i].f20; break;
        case 33: r = self->m24[i].f21; break;
        case 34: r = self->m24[i].f22; break;
        case 35: r = self->m24[i].f23; break;
        case 36: r = self->m24[i].f24; break;
        case 37: r = self->m24[i].f25; break;
        case 38: r = self->m24[i].f26; break;
        case 39: r = self->m24[i].f27; break;
        case 40: r = self->m24[i].f28; break;
        case 41: r = self->m24[i].f29; break;
        case 42: r = self->m24[i].f2A; break;
        case 43: r = self->m24[i].f2B; break;
        case 44: r = self->m24[i].f2C; break;
        case 45: r = self->m24[i].f2D; break;
        case 46: r = self->m24[i].f2E; break;
        case 47: r = self->m24[i].f2F; break;
        case 48: r = self->m24[i].f30; break;
        case 49: r = self->m24[i].f31; break;
        case 50: r = self->m24[i].f32; break;
        case 51: r = self->m24[i].f33; break;
        case 52: r = self->m24[i].f34; break;
        case 53: r = self->m24[i].f35; break;
        case 54: r = self->m24[i].f36; break;
        }
    }
    return r;
}

char* fn_8008D738(Unk8008CE64_K<Unk8008CE64_T3C>* self, int t, unsigned i, char* buf)
{
    if (i < self->m1C) {
        switch (t) {
        case 0:
            fn_8040B61C(buf, (char*)self->m24 + i * 0x3C + 0x1F);
            break;
        case 1:
            fn_8040B61C(buf, (char*)self->m24 + i * 0x3C + 0x2B);
            break;
        }
    }
    return buf;
}

float fn_8008D7B8(Unk8008CE64_Obj* o, int i, int a)
{
    float r = (o->*lbl_805B6C50[i])(a);
    return r;
}

extern "C" void fn_8008D850(Unk8008CE64_PackTabE* self, unsigned t, unsigned i, int v)
{
    if (i < self->m1C) {
        switch (t) {
        case 0: {
            Unk8008CE64_PackE* b = self->m24;
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)b);
            if (v <= 0xFFFF) {
                if (v < 0)
                    v = 0;
                p->h0 = v;
            } else
                p->h0 = 0xFFFF;
            break;
        }
        case 1: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xFFFF) {
                if (v < 0)
                    v = 0;
                p->h2 = v;
            } else
                p->h2 = 0xFFFF;
            break;
        }
        case 2: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x3F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3F;
            p->f02 = v;
            break;
        }
        case 3: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xFF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xFF;
            p->f03 = v;
            break;
        }
        case 4: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->f04 = v;
            break;
        }
        case 5: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f05 = v;
            break;
        }
        case 6: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x1F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1F;
            p->f06 = v;
            break;
        }
        case 7: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f07 = v;
            break;
        }
        case 8: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f08 = v;
            break;
        }
        case 9: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->f09 = v;
            break;
        }
        case 10: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->f0A = v;
            break;
        }
        case 11: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->f0B = v;
            break;
        }
        case 12: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f0C = v;
            break;
        }
        case 13: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x64) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x64;
            p->f0D = v;
            break;
        }
        case 14: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f0E = v;
            break;
        }
        case 15: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f0F = v;
            break;
        }
        case 16: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f10 = v;
            break;
        }
        case 17: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f11 = v;
            break;
        }
        case 18: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f12 = v;
            break;
        }
        case 19: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f13 = v;
            break;
        }
        case 20: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f14 = v;
            break;
        }
        case 21: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f15 = v;
            break;
        }
        case 22: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->f16 = v;
            break;
        }
        case 23: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->f17 = v;
            break;
        }
        case 24: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            int w;
            if (v <= 0xFF) {
                w = v;
                if (w < 0)
                    w = 0;
            } else
                w = 0xFF;
            p->f18 = w;
            break;
        }
        case 25: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->f19 = v;
            break;
        }
        case 26: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f1A = v;
            break;
        }
        case 27: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f1B = v;
            break;
        }
        case 28: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xFF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xFF;
            p->f1C = v;
            break;
        }
        case 29: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x64) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x64;
            p->f1D = v;
            break;
        }
        case 30: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->f1E = v;
            break;
        }
        case 31: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            int w;
            if (v <= 0xFF) {
                w = v;
                if (w < 0)
                    w = 0;
            } else
                w = 0xFF;
            p->f1F = w;
            break;
        }
        case 32: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->f20 = v;
            break;
        }
        case 33: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->f21 = v;
            break;
        }
        case 34: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->f22 = v;
            break;
        }
        case 35: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f23 = v;
            break;
        }
        case 36: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f24 = v;
            break;
        }
        case 37: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->f25 = v;
            break;
        }
        case 38: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->f26 = v;
            break;
        }
        case 39: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->f27 = v;
            break;
        }
        case 40: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->f28 = v;
            break;
        }
        case 41: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f29 = v;
            break;
        }
        case 42: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f2A = v;
            break;
        }
        case 43: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->f2B = v;
            break;
        }
        case 44: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x3FF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3FF;
            p->f2C = v;
            break;
        }
        case 45: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->f2D = v;
            break;
        }
        case 46: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f2E = v;
            break;
        }
        case 47: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f2F = v;
            break;
        }
        case 48: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->f30 = v;
            break;
        }
        case 49: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->f31 = v;
            break;
        }
        case 50: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x1F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1F;
            p->f32 = v;
            break;
        }
        case 51: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->f33 = v;
            break;
        }
        case 52: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f34 = v;
            break;
        }
        case 53: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f35 = v;
            break;
        }
        case 54: {
            Unk8008CE64_PackE* p = (Unk8008CE64_PackE*)(i * 60 + (int)self->m24);
            int w;
            if (v <= 0x7) {
                w = v;
                if (w < 0)
                    w = 0;
            } else
                w = 0x7;
            p->f36 = w;
            break;
        }
        }
    }
}

void fn_8008E690(Unk8008CE64_K<Unk8008CE64_T3C>* self, signed char t, unsigned i, const char* str, int n)
{
    if (i < self->m1C) {
        if (n <= 0)
            n = fn_8040B6A0(str);
        int mx = lbl_805B6B90[t] - 1;
        if (n > mx)
            n = mx;
        switch (t) {
        case 0: {
            int o = i * 0x3C;
            fn_8040B830((char*)self->m24 + o + 0x1F, str, n);
            char* d = (char*)(o + (int)self->m24 + 0x1F);
            d[n] = 0;
            break;
        }
        case 1: {
            int o = i * 0x3C;
            fn_8040B830((char*)self->m24 + o + 0x2B, str, n);
            char* d = (char*)(o + (int)self->m24 + 0x2B);
            d[n] = 0;
            break;
        }
        }
    }
}

float fn_8008E77C(G* self, int a)
{
    float r = (float)self->m20->pfn((char*)self + self->m20->delta, 2, a) + lbl_805B55F8;
    return r;
}

float fn_8008E7F0(G* self, int a)
{
    float r = (float)self->m20->pfn((char*)self + self->m20->delta, 3, a) + lbl_805B5608;
    return r;
}

float fn_8008E864(G* self, int a)
{
    unsigned char buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 1, a));
    return (float)buf;
}

float fn_8008E8D4(G* self, int a)
{
    Unk8008CE64_Buf3 buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 1, a));
    return (float)buf.b;
}

float fn_8008E950(G* self, int a)
{
    Unk8008CE64_Buf2 buf;
    fn_80329FA0(&buf, self->m20->pfn((char*)self + self->m20->delta, 1, a));
    return (float)buf.b;
}

float fn_8008E9CC(G* self, int a)
{
    int v = self->m20->pfn((char*)self + self->m20->delta, 0x18, a);
    float r = fn_800799D0(lbl_8061930C, v);
    return r;
}

void fn_8008EA20(Unk8008CE64_K<Unk8008CE64_T3C>* self, int a, VObj* obj)
{
    fn_80071E2C(self, a, obj);
    Unk8008CE64_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 0x3C);
}

Unk8008CE64_K<Unk8008CE64_T10>* fn_8008EA7C(Unk8008CE64_K<Unk8008CE64_T10>* self)
{
    fn_80071604(self);
    self->m20 = lbl_8064B138;
    self->m24 = 0;
    Unk8008CE64_T10* p = new (0) Unk8008CE64_T10[self->m1C];
    self->m24 = p;
    fn_8040074C(p, self->m1C * 0x10);
    self->m14 = fn_8007366C(lbl_805B3B4C, lbl_805B3B4C);
    return self;
}

void fn_8008EAF8(Unk8008CE64_K<Unk8008CE64_T10>* self, int flags)
{
    self->m20 = lbl_8064B138;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, flags);
}

void fn_8008EB54(Unk8008CE64_K<Unk8008CE64_T10>* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(&self->m24[i], 0x10);
}

int fn_8008EB90(void* l, int k)
{
    int r = 0;
    switch ((unsigned)k) {
    case 0:
        r = 100;
        break;
    case 1:
        r = 100;
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
    case 15:
        r = 0;
        break;
    case 16:
        r = 0;
        break;
    case 17:
        r = 0;
        break;
    case 18:
        r = 0;
        break;
    case 19:
        r = 0;
        break;
    case 20:
        r = 0;
        break;
    case 21:
        r = 0;
        break;
    case 22:
        r = 0;
        break;
    case 23:
        r = 0;
        break;
    case 24:
        r = 0;
        break;
    case 25:
        r = 0;
        break;
    case 26:
        r = 0;
        break;
    }
    return r;
}

int fn_8008EC78(void* l, int k)
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
    case 15:
        r = 0;
        break;
    case 16:
        r = 0;
        break;
    case 17:
        r = 0;
        break;
    case 18:
        r = 0;
        break;
    case 19:
        r = 0;
        break;
    case 20:
        r = 0;
        break;
    case 21:
        r = 0;
        break;
    case 22:
        r = 0;
        break;
    case 23:
        r = 0;
        break;
    case 24:
        r = 0;
        break;
    case 25:
        r = 0;
        break;
    case 26:
        r = 0;
        break;
    }
    return r;
}

unsigned fn_8008ED04(Unk8008CE64_PackTabF* self, unsigned t, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (t) {
        case 0: r = self->m24[i].f00; break;
        case 1: r = self->m24[i].f01; break;
        case 2: r = self->m24[i].f02; break;
        case 3: r = self->m24[i].f03; break;
        case 4: r = self->m24[i].f04; break;
        case 5: r = self->m24[i].f05; break;
        case 6: r = self->m24[i].f06; break;
        case 7: r = self->m24[i].f07; break;
        case 8: r = self->m24[i].f08; break;
        case 9: r = self->m24[i].f09; break;
        case 10: r = self->m24[i].f0A; break;
        case 11: r = self->m24[i].f0B; break;
        case 12: r = self->m24[i].f0C; break;
        case 13: r = self->m24[i].f0D; break;
        case 14: r = self->m24[i].f0E; break;
        case 15: r = self->m24[i].f0F; break;
        case 16: r = self->m24[i].f10; break;
        case 17: r = self->m24[i].f11; break;
        case 18: r = self->m24[i].f12; break;
        case 19: r = self->m24[i].f13; break;
        case 20: r = self->m24[i].f14; break;
        case 21: r = self->m24[i].f15; break;
        case 22: r = self->m24[i].f16; break;
        case 23: r = self->m24[i].f17; break;
        case 24: r = self->m24[i].f18; break;
        case 25: r = self->m24[i].f19; break;
        case 26: r = self->m24[i].f1A; break;
        }
    }
    return r;
}

void* fn_8008F08C(void* self, int a, int b, char* buf)
{
    return fn_8040B61C(buf, lbl_80619308);
}

float fn_8008F0B8()
{
    float f;
    return f = lbl_805B5628;
}

void fn_8008F0D4(Unk8008CE64_PackTabF* self, unsigned t, unsigned i, int v)
{
    if (i < self->m1C) {
        switch (t) {
        case 0: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x64) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x64;
            p->f00 = v;
            break;
        }
        case 1: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x64) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x64;
            p->f01 = v;
            break;
        }
        case 2: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f02 = v;
            break;
        }
        case 3: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f03 = v;
            break;
        }
        case 4: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f04 = v;
            break;
        }
        case 5: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f05 = v;
            break;
        }
        case 6: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f06 = v;
            break;
        }
        case 7: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f07 = v;
            break;
        }
        case 8: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f08 = v;
            break;
        }
        case 9: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f09 = v;
            break;
        }
        case 10: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->f0A = v;
            break;
        }
        case 11: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f0B = v;
            break;
        }
        case 12: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f0C = v;
            break;
        }
        case 13: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f0D = v;
            break;
        }
        case 14: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f0E = v;
            break;
        }
        case 15: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f0F = v;
            break;
        }
        case 16: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f10 = v;
            break;
        }
        case 17: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f11 = v;
            break;
        }
        case 18: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f12 = v;
            break;
        }
        case 19: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->f13 = v;
            break;
        }
        case 20: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->f14 = v;
            break;
        }
        case 21: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->f15 = v;
            break;
        }
        case 22: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->f16 = v;
            break;
        }
        case 23: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->f17 = v;
            break;
        }
        case 24: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->f18 = v;
            break;
        }
        case 25: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->f19 = v;
            break;
        }
        case 26: {
            Unk8008CE64_PackF* p = (Unk8008CE64_PackF*)(i * 16 + (int)self->m24);
            int w;
            if (v <= 0x7F) {
                w = v;
                if (w < 0)
                    w = 0;
            } else
                w = 0x7F;
            p->f1A = w;
            break;
        }
        }
    }
}

void fn_8008F7E0()
{
}

void fn_8008F7E4(Unk8008CE64_K<Unk8008CE64_T10>* self, int a, VObj* obj)
{
    fn_80071E2C(self, a, obj);
    Unk8008CE64_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 0x10);
}

Unk8008CE64_K<Unk8008CE64_T1C>* fn_8008F840(Unk8008CE64_K<Unk8008CE64_T1C>* self)
{
    fn_80071604(self);
    self->m20 = lbl_8064A220;
    self->m24 = 0;
    Unk8008CE64_T1C* p = new (0) Unk8008CE64_T1C[self->m1C];
    self->m24 = p;
    fn_8040074C(p, self->m1C * 0x1C);
    return self;
}

void fn_8008F8A8(Unk8008CE64_K<Unk8008CE64_T1C>* self, int flags)
{
    self->m20 = lbl_8064A220;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, flags);
}

void fn_8008F904(Unk8008CE64_K<Unk8008CE64_T1C>* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(&self->m24[i], 0x1C);
}

int fn_8008F940(void* self)
{
    return 0;
}

int fn_8008F948(void* self)
{
    return 0;
}

unsigned fn_8008F950(Unk8008CE64_K<Unk8008CE64_E1C>* self, int t, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (t) {
        case 0:
            r = self->m24[i].h0;
            break;
        case 1:
            r = self->m24[i].f;
            break;
        }
    }
    return r;
}

char* fn_8008F99C(Unk8008CE64_K<Unk8008CE64_T1C>* self, int t, unsigned i, char* buf)
{
    if (i < self->m1C) {
        switch (t) {
        case 0:
            fn_8040B61C(buf, (char*)self->m24 + i * 0x1C + 3);
            break;
        case 1:
            fn_8040B61C(buf, (char*)self->m24 + i * 0x1C + 0xE);
            break;
        }
    }
    return buf;
}

void fn_8008FA1C(Unk8008CE64_K<Unk8008CE64_E1C>* self, int t, unsigned i, int v)
{
    if (i < self->m1C) {
        switch (t) {
        case 0: {
            Unk8008CE64_E1C* b = self->m24;
            Unk8008CE64_E1C* p = (Unk8008CE64_E1C*)(i * 0x1C + (int)b);
            if (v <= 0xFFFF) {
                if (v < 0)
                    v = 0;
                p->h0 = v;
            } else
                p->h0 = 0xFFFF;
            break;
        }
        case 1: {
            Unk8008CE64_E1C* p = (Unk8008CE64_E1C*)(i * 0x1C + (int)self->m24);
            int w;
            if (v <= 1) {
                w = v;
                if (w < 0)
                    w = 0;
            } else
                w = 1;
            p->f = w;
            break;
        }
        }
    }
}

void fn_8008FAA8(Unk8008CE64_K<Unk8008CE64_T1C>* self, signed char t, unsigned i, const char* str, int n)
{
    if (i < self->m1C) {
        if (n == 0)
            n = fn_8040B6A0(str);
        switch (t) {
        case 0: {
            int m = n;
            if (m > 10)
                m = 10;
            int o = i * 0x1C;
            fn_8040B830((char*)self->m24 + o + 3, str, m);
            char* d = (char*)(o + (int)self->m24 + 3);
            d[m] = 0;
            break;
        }
        case 1: {
            int m = n;
            if (m > 13)
                m = 13;
            int o = i * 0x1C;
            fn_8040B830((char*)self->m24 + o + 0xE, str, m);
            char* d = (char*)(o + (int)self->m24 + 0xE);
            d[m] = 0;
            break;
        }
        }
    }
}

void fn_8008FB90(Unk8008CE64_K<Unk8008CE64_T1C>* self, int a, VObj* obj)
{
    fn_80071E2C(self, a, obj);
    Unk8008CE64_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, 0x348);
}

int fn_8008FBE8(int v)
{
    int n = 0;
    int k = 0;
    Unk8008CE64_IterW<9> it;
    do {
        if (lbl_80619738[k] == v)
            n++;
        k = it.Next(k);
    } while (k <= 9);
    return n;
}

int fn_8008FC40(int v, int nth)
{
    int cnt = 0;
    int res = 10;
    Unk8008CE64_Iter<9> it;
    for (int k = 0; k <= 9; k = it.Next()) {
        if (lbl_80619738[k] == v) {
            if (cnt == nth) {
                res = k;
                break;
            }
            cnt++;
        }
    }
    return res;
}

int fn_8008FCC8(int t)
{
    switch (t) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 0;
    case 3:
        return 0;
    case 4:
        return 0;
    }
    return 0;
}

int fn_8008FD14(int t)
{
    switch (t) {
    case 0:
        return 0x5942;
    case 1:
        return 0x5944;
    case 2:
        return 0x5943;
    case 3:
        return 0x5945;
    case 4:
        return 0x5B05;
    }
    return 0;
}

int fn_8008FD78(int t)
{
    switch (t) {
    case 0:
        return 0;
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 1;
    case 4:
        return 2;
    case 5:
        return 2;
    case 6:
        return 3;
    case 7:
        return 3;
    case 8:
        return 3;
    case 9:
        return 4;
    }
    return 5;
}

int fn_8008FE14(int t)
{
    switch (t) {
    case 0:
        return 4;
    case 1:
        return 5;
    case 2:
        return 6;
    case 3:
        return 7;
    case 4:
        return 8;
    case 5:
        return 9;
    case 6:
        return 10;
    case 7:
        return 11;
    case 8:
        return 12;
    case 9:
        return 13;
    }
    return 4;
}

int fn_8008FED8(int v)
{
    int tbl[10] = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    Unk8008CE64_IterW<9> it;
    for (int k = 0; k <= 9; k = it.Next(k)) {
        if (tbl[k] == v)
            return k;
    }
    return 10;
}

int fn_8008FF98(int t)
{
    switch (t) {
    case 0:
        return 0x5AA0;
    case 1:
        return 0x5AA1;
    case 2:
        return 0x5AA2;
    case 3:
        return 0x5AA3;
    case 4:
        return 0x5AA4;
    case 5:
        return 0x5AA5;
    case 6:
        return 0x5AA6;
    case 7:
        return 0x5AA7;
    case 8:
        return 0x5AA8;
    case 9:
        return 0x5AA9;
    }
    return 0;
}

int fn_8009005C(int a, float f)
{
    int row = 0;
    int i = 0;
    float acc = 0.0f;
    int n = 12;
    if (a >= lbl_805B6D70[0]) {
    top:
        i++;
        if (i >= n)
            goto done;
        if (a >= lbl_805B6D70[i])
            goto top;
        row = i;
    }
done:
    for (i = 0; i < 5; i++) {
        acc += lbl_805B6C80[row][i];
        if (f < acc)
            return i;
    }
    return 4;
}

void fn_8009010C()
{
    if (lbl_80619760 == 0)
        lbl_80619760 = operator new(0xE294, 0x100);
    fn_80534E80(lbl_80619760, lbl_805B56C0);
}

void fn_80090164()
{
    if (lbl_80619760) {
        fn_80377408(lbl_80619760);
        lbl_80619760 = 0;
    }
}

int fn_800901A4()
{
    if (lbl_80619760)
        return 1;
    return 0;
}

void fn_800901C0(int a0, int a1, int a2, int a3, int a4, int a5)
{
    if (fn_800901A4() == 1) {
        int m = *(int*)((char*)lbl_80619760 + 0xE290);
        fn_80534F64(lbl_80619760, a0, a1, a2 % m, a3, a4, a5 % m);
    }
}

int fn_80090244(int a)
{
    float z = 64.0f;
    float f = (float)a * 0.5f;
    return (int)(f + 36.0f);
}

int fn_800902B0(int t, int a)
{
    int r = 0;
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    switch (t) {
    case 0:
        r = s->fn_8007C514(2, a) != 0;
        break;
    case 1:
        r = s->fn_8007C770(8, a) != 0;
        break;
    case 2:
        r = s->fn_8007C994(1, a) != 0;
        break;
    case 3:
        r = s->fn_8007CBB8(6, a) != 0;
        break;
    case 4:
        r = s->fn_8007CDDC(5, a) != 0;
        break;
    }
    return r;
}

float fn_80090380(void* a)
{
    int v = fn_800903B8(a);
    float r = fn_80079A90(lbl_8061930C, v);
    return r;
}

int fn_800903B8(int t, int a)
{
    int r = 0;
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    switch (t) {
    case 0:
        r = s->fn_8007C514(15, a);
        break;
    case 1:
        r = s->fn_8007C770(11, a);
        break;
    case 2:
        r = s->fn_8007C994(11, a);
        break;
    case 3:
        r = s->fn_8007CBB8(9, a);
        break;
    case 4:
        r = s->fn_8007CDDC(8, a);
        break;
    }
    return r;
}

int fn_8009047C(int t, int a)
{
    int r = 0;
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    switch (t) {
    case 0:
        r = s->fn_8007C514(16, a);
        break;
    case 1:
        r = s->fn_8007C770(12, a);
        break;
    case 2:
        r = s->fn_8007C994(12, a);
        break;
    case 3:
        r = s->fn_8007CBB8(5, a);
        break;
    case 4:
        r = s->fn_8007CDDC(9, a);
        break;
    }
    return r;
}

void fn_80090540(int t, int a, int v)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    switch (t) {
    case 0:
        s->fn_8007C574(15, a, v);
        break;
    case 1:
        s->fn_8007C7D0(11, a, v);
        break;
    case 2:
        s->fn_8007C9F4(11, a, v);
        break;
    case 3:
        s->fn_8007CC18(9, a, v);
        break;
    case 4:
        s->fn_8007CE3C(8, a, v);
        break;
    }
}

void fn_800905FC(int t, int a, int v)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    switch (t) {
    case 0:
        s->fn_8007C574(16, a, v);
        break;
    case 1:
        s->fn_8007C7D0(12, a, v);
        break;
    case 2:
        s->fn_8007C9F4(12, a, v);
        break;
    case 3:
        s->fn_8007CC18(5, a, v);
        break;
    case 4:
        s->fn_8007CE3C(9, a, v);
        break;
    }
}

void fn_800906B8()
{
    if (lbl_8061977C == 0)
        lbl_8061977C = fn_80090744((Unk8008CE64_Own*)operator new(0xC, 0));
}

void fn_80090700()
{
    if (lbl_8061977C) {
        fn_8009075C(lbl_8061977C, 3);
        lbl_8061977C = 0;
    }
}

Unk8008CE64_Own* fn_80090744(Unk8008CE64_Own* self)
{
    self->m0 = 0;
    self->m4 = 0;
    self->m8 = 0;
    return self;
}

void fn_8009075C(Unk8008CE64_Own* self, int flags)
{
    fn_80090814(self, 1, 1);
    if (flags & 1)
        fn_80377408(self);
}

void fn_800907A4(Unk8008CE64_Own* p, int idx, int flag)
{
    void** slot = &p->m8;
    if (flag != 0)
        slot = &p->m4;
    if (*slot == 0) {
        p->m0 = idx;
        const char* r = fn_802B9300(lbl_80619764[idx], 0, 0xE, 0);
        *slot = (void*)r;
        fn_80402DE4(r, 1);
    }
}

void fn_80090814(Unk8008CE64_Own* self, int a, int b)
{
    if (self->m4 != 0 && a != 0) {
        fn_803EDA0C(self->m4);
        self->m4 = 0;
    }
    if (self->m8 != 0 && b != 0) {
        fn_803EDA0C(self->m8);
        self->m8 = 0;
    }
}
