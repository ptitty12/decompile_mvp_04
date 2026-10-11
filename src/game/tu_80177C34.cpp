/*
 * Game code, .text 0x80177C34-0x8017A930 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80177C34.h"

extern char lbl_8065FBC8[];

class Unk80178A64 {
public:
    virtual ~Unk80178A64();
};

Unk80178A64::~Unk80178A64() {}

void fn_80178BB8() {}

void fn_80178C08() {}

void fn_80178CF4() {}

void fn_80178D9C(unsigned* p)
{
    if (*p > 1) {
        *p = 0;
    }
}

void fn_801791DC(Unk801791DC_T* p, int a, int b)
{
    p->m84 = a;
    p->m88 = b;
    fn_80179250(p);
}

void fn_80179250(void* self)
{
    fn_80179208(self);
    fn_801792BC(self);
}

int fn_80179284(Unk80179284_T* p, Unk80179284_Ctx* ctx)
{
    int v = ctx->m704;
    for (int i = 0; i < 14; i++) {
        if (p->m20[i] == v) {
            return 1;
        }
    }
    return 0;
}

int fn_80179464()
{
    return 6;
}

void fn_80179784()
{
    fn_801794B8();
}

void fn_801797A4()
{
    fn_801794B8();
}

int fn_8017995C(int* arr, int v)
{
    for (int i = 0; i < 8; i++) {
        if (arr[i] == v) {
            return i;
        }
    }
    return -1;
}

int fn_80179990(int* arr, unsigned i)
{
    if (i > 8) {
        return 0;
    }
    return arr[i];
}

int* fn_80179B58(int* p)
{
    *p = 0;
    fn_80179BDC();
    return p;
}

void fn_80179B90(Unk80179B90_T* p, int a, int b)
{
    p->m4 = a;
    p->m8 = b;
    fn_80179BBC(p);
}

void fn_80179BBC(void* self)
{
    fn_80179BDC();
}

void fn_80179BDC() {}
