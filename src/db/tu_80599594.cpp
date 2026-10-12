/*
 * Database overlay code, .database_codeoverlay 0x80599594-0x8059A728 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

struct Obj {
    char* m0;
    int m4;
};

struct Unk80071604 {
    char m0[16];
    Obj* m10;
    int m14;
    int m18;
    unsigned m1C;
    void* m20;
    char* m24;
};

extern char lbl_80684230[];

void fn_80071688(Unk80071604* self, int chrg);

extern "C" DB_OVERLAY void fn_8059966C(Unk80071604* self, int chrg)
{
    self->m20 = lbl_80684230;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, chrg);
}

extern "C" void fn_8040074C(void* p, unsigned n);

extern "C" DB_OVERLAY void fn_805996C8(Unk80071604* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(self->m24 + i * 8, 8);
}

extern const float lbl_806012A8;

extern "C" DB_OVERLAY float fn_80599724()
{
    float f;
    return f = lbl_806012A8;
}

struct Unk80084910_VT {
    char pad0[8];
    short delta;
    short padA;
    void (*pfn)(void* self, int a, void* p, int n);
};

struct Unk80084910_VObj {
    char pad0[4];
    Unk80084910_VT* m4;
};

typedef Unk80084910_VObj VObj;

struct Unk80070DDC_Stream0 {
    int m0;
};

struct Unk80070DDC_Stream : Unk80070DDC_Stream0 {
    virtual int v08(int a, void* data, int size);
    virtual int v10();
};

void fn_80071E2C(Unk80071604* self, int a, Unk80070DDC_Stream* io);

extern "C" DB_OVERLAY void fn_80599748(Unk80071604* self, int a, VObj* obj)
{
    fn_80071E2C(self, a, (Unk80070DDC_Stream*)obj);
    Unk80084910_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 8);
}

struct Unk80084910_T8 {
    char pad0[8];
};

template <class T>
struct Unk80084910_K {
    char pad0[0x14];
    void* m14;
    char pad18[4];
    unsigned m1C;
    void* m20;
    T* m24;
};

typedef Unk80084910_K<Unk80084910_T8> K8;

extern "C" DB_OVERLAY Unk80084910_T8* fn_805997A4(K8* self, int i)
{
    return &self->m24[i];
}

extern "C" DB_OVERLAY Unk80084910_T8* fn_805997B4(K8* self, int i)
{
    return &self->m24[i];
}

extern "C" void* fn_803FFA60(void* s, int a, int n);

extern "C" DB_OVERLAY void* fn_805999B4(void* self, int a)
{
    fn_803FFA60(self, a, 8);
    return self;
}

struct U {
    char pad0[0x4000];
};

extern "C" void fn_80599B54(void* p);

extern "C" DB_OVERLAY U* fn_80599B24(U* self)
{
    fn_80599B54(self);
    return self;
}
