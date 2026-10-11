/*
 * Game code, .text 0x80089894-0x8008CE64 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80089894.h"

typedef float (Unk80089894_Obj::*Unk80089894_Pmf)(int);
extern Unk80089894_Pmf lbl_805B6BA8[];



void* operator new[](unsigned int size, int heap); /* 0x803774A8 */
void fn_80071604(void* self);
void fn_80071688(void* self, int flags);
/* fn_80071E2C is the base-class version of these functions: it takes the same
 * (self, a, obj) and calls obj's slot 1 itself (r4/r5 used without a copy). */
void fn_80071E2C(void* self, int a, void* obj);
void* fn_8007366C(const char* a, const char* b);
void fn_8040074C(void* p, int n);
extern char lbl_805B3B4C[];


extern char lbl_8064ADB8[];



extern char lbl_8064AF78[];



extern char lbl_8064AF08[];



extern char lbl_8064B1A8[];



extern float lbl_805B4E34;


extern float lbl_805B4E40;


extern float lbl_805B4E44;


extern float lbl_805B4E48;


extern Unk80089894_Pmf lbl_805B6BD8[];


extern Unk80089894_Pmf lbl_805B6C18[];

void fn_80089894(Unk80089894_K<Unk80089894_T14>* self, unsigned i);
float fn_80089E48(Unk80089894_Obj* o, int i, int a);
void fn_8008AAA8(Unk80089894_K<Unk80089894_T14>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_TC>* fn_8008AB04(Unk80089894_K<Unk80089894_TC>* self);
void fn_8008AB80(Unk80089894_K<Unk80089894_TC>* self, int flags);
void fn_8008ABDC(Unk80089894_K<Unk80089894_TC>* self, unsigned i);
void fn_8008B1F8(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_TC>* fn_8008B254(Unk80089894_K<Unk80089894_TC>* self);
void fn_8008B2D0(Unk80089894_K<Unk80089894_TC>* self, int flags);
void fn_8008B32C(Unk80089894_K<Unk80089894_TC>* self, unsigned i);
float fn_8008B5F8(Unk80089894_Obj* o, int i, int a);
float fn_8008BC94();
float fn_8008BD5C();
float fn_8008BD68();
float fn_8008BD74();
void fn_8008BD80(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_TC>* fn_8008BDDC(Unk80089894_K<Unk80089894_TC>* self);
void fn_8008BE58(Unk80089894_K<Unk80089894_TC>* self, int flags);
void fn_8008BEB4(Unk80089894_K<Unk80089894_TC>* self, unsigned i);
float fn_8008C0DC(Unk80089894_Obj* o, int i, int a);
void fn_8008CA9C(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_T3C>* fn_8008CAF8(Unk80089894_K<Unk80089894_T3C>* self);
void fn_8008CB74(Unk80089894_K<Unk80089894_T3C>* self, int flags);
void fn_8008CBD0(Unk80089894_K<Unk80089894_T3C>* self, unsigned i);

void fn_80089894(Unk80089894_K<Unk80089894_T14>* self, unsigned i);
float fn_80089E48(Unk80089894_Obj* o, int i, int a);
void fn_8008AAA8(Unk80089894_K<Unk80089894_T14>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_TC>* fn_8008AB04(Unk80089894_K<Unk80089894_TC>* self);
void fn_8008AB80(Unk80089894_K<Unk80089894_TC>* self, int flags);
void fn_8008ABDC(Unk80089894_K<Unk80089894_TC>* self, unsigned i);
unsigned fn_8008AC94(Unk80089894_PackTab* self, unsigned t, unsigned i);
void fn_8008B1F8(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_TC>* fn_8008B254(Unk80089894_K<Unk80089894_TC>* self);
void fn_8008B2D0(Unk80089894_K<Unk80089894_TC>* self, int flags);
void fn_8008B32C(Unk80089894_K<Unk80089894_TC>* self, unsigned i);
float fn_8008B5F8(Unk80089894_Obj* o, int i, int a);
float fn_8008BC94();
float fn_8008BD5C();
float fn_8008BD68();
float fn_8008BD74();
void fn_8008BD80(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_TC>* fn_8008BDDC(Unk80089894_K<Unk80089894_TC>* self);
void fn_8008BE58(Unk80089894_K<Unk80089894_TC>* self, int flags);
void fn_8008BEB4(Unk80089894_K<Unk80089894_TC>* self, unsigned i);
float fn_8008C0DC(Unk80089894_Obj* o, int i, int a);
void fn_8008CA9C(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_T3C>* fn_8008CAF8(Unk80089894_K<Unk80089894_T3C>* self);
void fn_8008CB74(Unk80089894_K<Unk80089894_T3C>* self, int flags);
void fn_8008CBD0(Unk80089894_K<Unk80089894_T3C>* self, unsigned i);



























void fn_80089894(Unk80089894_K<Unk80089894_T14>* self, unsigned i);
float fn_80089E48(Unk80089894_Obj* o, int i, int a);
void fn_8008AAA8(Unk80089894_K<Unk80089894_T14>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_TC>* fn_8008AB04(Unk80089894_K<Unk80089894_TC>* self);
void fn_8008AB80(Unk80089894_K<Unk80089894_TC>* self, int flags);
void fn_8008ABDC(Unk80089894_K<Unk80089894_TC>* self, unsigned i);
unsigned fn_8008AC94(Unk80089894_PackTab* self, unsigned t, unsigned i);
void fn_8008B1F8(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_TC>* fn_8008B254(Unk80089894_K<Unk80089894_TC>* self);
void fn_8008B2D0(Unk80089894_K<Unk80089894_TC>* self, int flags);
void fn_8008B32C(Unk80089894_K<Unk80089894_TC>* self, unsigned i);
float fn_8008B5F8(Unk80089894_Obj* o, int i, int a);
float fn_8008BC94();
float fn_8008BD5C();
float fn_8008BD68();
float fn_8008BD74();
void fn_8008BD80(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_TC>* fn_8008BDDC(Unk80089894_K<Unk80089894_TC>* self);
void fn_8008BE58(Unk80089894_K<Unk80089894_TC>* self, int flags);
void fn_8008BEB4(Unk80089894_K<Unk80089894_TC>* self, unsigned i);
float fn_8008C0DC(Unk80089894_Obj* o, int i, int a);
void fn_8008CA9C(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_T3C>* fn_8008CAF8(Unk80089894_K<Unk80089894_T3C>* self);
void fn_8008CB74(Unk80089894_K<Unk80089894_T3C>* self, int flags);
void fn_8008CBD0(Unk80089894_K<Unk80089894_T3C>* self, unsigned i);

void fn_80089894(Unk80089894_K<Unk80089894_T14>* self, unsigned i);
float fn_80089E48(Unk80089894_Obj* o, int i, int a);
void fn_8008AAA8(Unk80089894_K<Unk80089894_T14>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_TC>* fn_8008AB04(Unk80089894_K<Unk80089894_TC>* self);
void fn_8008AB80(Unk80089894_K<Unk80089894_TC>* self, int flags);
void fn_8008ABDC(Unk80089894_K<Unk80089894_TC>* self, unsigned i);
unsigned fn_8008AC94(Unk80089894_PackTab* self, unsigned t, unsigned i);
void fn_8008B1F8(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_TC>* fn_8008B254(Unk80089894_K<Unk80089894_TC>* self);
void fn_8008B2D0(Unk80089894_K<Unk80089894_TC>* self, int flags);
void fn_8008B32C(Unk80089894_K<Unk80089894_TC>* self, unsigned i);
float fn_8008B5F8(Unk80089894_Obj* o, int i, int a);
float fn_8008BC94();
float fn_8008BD5C();
float fn_8008BD68();
float fn_8008BD74();
void fn_8008BD80(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_TC>* fn_8008BDDC(Unk80089894_K<Unk80089894_TC>* self);
void fn_8008BE58(Unk80089894_K<Unk80089894_TC>* self, int flags);
void fn_8008BEB4(Unk80089894_K<Unk80089894_TC>* self, unsigned i);
float fn_8008C0DC(Unk80089894_Obj* o, int i, int a);
void fn_8008CA9C(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj);
Unk80089894_K<Unk80089894_T3C>* fn_8008CAF8(Unk80089894_K<Unk80089894_T3C>* self);
void fn_8008CB74(Unk80089894_K<Unk80089894_T3C>* self, int flags);
void fn_8008CBD0(Unk80089894_K<Unk80089894_T3C>* self, unsigned i);

void fn_80089894(Unk80089894_K<Unk80089894_T14>* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(&self->m24[i], 0x14);
}

float fn_80089E48(Unk80089894_Obj* o, int i, int a)
{
    float r = (o->*lbl_805B6BA8[i])(a);
    return r;
}

void fn_8008AAA8(Unk80089894_K<Unk80089894_T14>* self, int a, Unk80089894_VObj* obj)
{
    fn_80071E2C(self, a, obj);
    Unk80089894_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 0x14);
}

Unk80089894_K<Unk80089894_TC>* fn_8008AB04(Unk80089894_K<Unk80089894_TC>* self)
{
    fn_80071604(self);
    self->m20 = lbl_8064ADB8;
    self->m24 = 0;
    Unk80089894_TC* p = new (0) Unk80089894_TC[self->m1C];
    self->m24 = p;
    fn_8040074C(p, self->m1C * 0xC);
    self->m14 = fn_8007366C(lbl_805B3B4C, lbl_805B3B4C);
    return self;
}

void fn_8008AB80(Unk80089894_K<Unk80089894_TC>* self, int flags)
{
    self->m20 = lbl_8064ADB8;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, flags);
}

void fn_8008ABDC(Unk80089894_K<Unk80089894_TC>* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(&self->m24[i], 0xC);
}

unsigned fn_8008AC94(Unk80089894_PackTab* self, unsigned t, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (t) {
        case 0: r = self->m24[i].a0; break;
        case 1: r = self->m24[i].a1; break;
        case 2: r = self->m24[i].a2; break;
        case 3: r = self->m24[i].b0; break;
        case 4: r = self->m24[i].b1; break;
        case 5: r = self->m24[i].b2; break;
        case 6: r = self->m24[i].c0; break;
        case 7: r = self->m24[i].c1; break;
        case 8: r = self->m24[i].c2; break;
        }
    }
    return r;
}

void fn_8008B1F8(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj)
{
    fn_80071E2C(self, a, obj);
    Unk80089894_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 0xC);
}

Unk80089894_K<Unk80089894_TC>* fn_8008B254(Unk80089894_K<Unk80089894_TC>* self)
{
    fn_80071604(self);
    self->m20 = lbl_8064AF78;
    self->m24 = 0;
    Unk80089894_TC* p = new (0) Unk80089894_TC[self->m1C];
    self->m24 = p;
    fn_8040074C(p, self->m1C * 0xC);
    self->m14 = fn_8007366C(lbl_805B3B4C, lbl_805B3B4C);
    return self;
}

void fn_8008B2D0(Unk80089894_K<Unk80089894_TC>* self, int flags)
{
    self->m20 = lbl_8064AF78;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, flags);
}

void fn_8008B32C(Unk80089894_K<Unk80089894_TC>* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(&self->m24[i], 0xC);
}

float fn_8008B5F8(Unk80089894_Obj* o, int i, int a)
{
    float r = (o->*lbl_805B6BD8[i])(a);
    return r;
}

float fn_8008BC94()
{
    return lbl_805B4E34;
}

float fn_8008BD5C()
{
    return lbl_805B4E40;
}

float fn_8008BD68()
{
    return lbl_805B4E44;
}

float fn_8008BD74()
{
    return lbl_805B4E48;
}

void fn_8008BD80(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj)
{
    fn_80071E2C(self, a, obj);
    Unk80089894_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 0xC);
}

Unk80089894_K<Unk80089894_TC>* fn_8008BDDC(Unk80089894_K<Unk80089894_TC>* self)
{
    fn_80071604(self);
    self->m20 = lbl_8064AF08;
    self->m24 = 0;
    Unk80089894_TC* p = new (0) Unk80089894_TC[self->m1C];
    self->m24 = p;
    fn_8040074C(p, self->m1C * 0xC);
    self->m14 = fn_8007366C(lbl_805B3B4C, lbl_805B3B4C);
    return self;
}

void fn_8008BE58(Unk80089894_K<Unk80089894_TC>* self, int flags)
{
    self->m20 = lbl_8064AF08;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, flags);
}

void fn_8008BEB4(Unk80089894_K<Unk80089894_TC>* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(&self->m24[i], 0xC);
}

float fn_8008C0DC(Unk80089894_Obj* o, int i, int a)
{
    float r = (o->*lbl_805B6C18[i])(a);
    return r;
}

void fn_8008CA9C(Unk80089894_K<Unk80089894_TC>* self, int a, Unk80089894_VObj* obj)
{
    fn_80071E2C(self, a, obj);
    Unk80089894_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 0xC);
}

Unk80089894_K<Unk80089894_T3C>* fn_8008CAF8(Unk80089894_K<Unk80089894_T3C>* self)
{
    fn_80071604(self);
    self->m20 = lbl_8064B1A8;
    self->m24 = 0;
    Unk80089894_T3C* p = new (0) Unk80089894_T3C[self->m1C];
    self->m24 = p;
    fn_8040074C(p, self->m1C * 0x3C);
    self->m14 = fn_8007366C(lbl_805B3B4C, lbl_805B3B4C);
    return self;
}

void fn_8008CB74(Unk80089894_K<Unk80089894_T3C>* self, int flags)
{
    self->m20 = lbl_8064B1A8;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, flags);
}

void fn_8008CBD0(Unk80089894_K<Unk80089894_T3C>* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(&self->m24[i], 0x3C);
}
