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
extern "C" int fn_8058A3B8(void* self, void* rec);
extern "C" int fn_8058252C(void* self, int a);
extern "C" int fn_8058AADC(void* self, int a, int b);
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

/* near-miss (4 slots): retail copies the call result to r0 first (mr r0,r3), compares r0 and builds the result in r3. */
extern "C" DB_OVERLAY int fn_805881E4(void* self)
{
    int r = fn_805826AC(self);
    int k = 5;
    if (r != 1)
        k = r;
    return k;
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
