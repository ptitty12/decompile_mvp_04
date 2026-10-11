/*
 * Game code, .text 0x80089894-0x8008CE64 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8007A4DC.h"
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

extern float lbl_805B4E60;
extern float lbl_805B4E64;
extern float lbl_805B4E68;
extern float lbl_805B4E78;
extern float lbl_805B4E7C;
extern float lbl_805B4E88;
float fn_8008C45C(W* self, int a);
float fn_8008C54C(W* self, int a);
float fn_8008C724(W* self, int a);
float fn_8008C884(W* self, int a);
float fn_8008C94C(W* self, int a);


extern int lbl_80620758;
extern float lbl_8062075C;
extern float lbl_805B4BB4;
extern float lbl_805B4BB8;
extern float lbl_805B4BBC;
extern float lbl_805B4BC0;
extern float lbl_805B4BC4;
extern float lbl_805B4BC8;
extern float lbl_805B4BCC;
extern float lbl_805B4BD0;
extern float lbl_805B4BD4;
extern float lbl_805B4BD8;
float fn_8008A9DC(int kind, float a, float b, float c, float d);



extern Unk80089894_Pmf lbl_805B6BD0[];


float fn_8008BA24(W* self, int a);










void fn_80089894(Unk80089894_K<Unk80089894_T14>* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(&self->m24[i], 0x14);
}

unsigned fn_80089AA0(Unk80089894_PackTabD* self, unsigned t, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (t) {
        case 0: r = self->m24[i].a0; break;
        case 1: r = self->m24[i].a1; break;
        case 2: r = self->m24[i].a2; break;
        case 3: r = self->m24[i].a3; break;
        case 4: r = self->m24[i].a4; break;
        case 5: r = self->m24[i].a5; break;
        case 6: r = self->m24[i].a6; break;
        case 7: r = self->m24[i].b0; break;
        case 8: r = self->m24[i].b1; break;
        case 9: r = self->m24[i].b2; break;
        case 10: r = self->m24[i].b3; break;
        case 11: r = self->m24[i].b4; break;
        case 12: r = self->m24[i].b5; break;
        case 13: r = self->m24[i].b6; break;
        case 14: r = self->m24[i].c0; break;
        case 15: r = self->m24[i].c1; break;
        case 16: r = self->m24[i].c2; break;
        case 17: r = self->m24[i].c3; break;
        case 18: r = self->m24[i].c4; break;
        case 19: r = self->m24[i].c5; break;
        case 20: r = self->m24[i].d0; break;
        case 21: r = self->m24[i].d1; break;
        case 22: r = self->m24[i].d2; break;
        case 23: r = self->m24[i].d3; break;
        case 24: r = self->m24[i].d4; break;
        case 25: r = self->m24[i].d5; break;
        case 26: r = self->m24[i].e0; break;
        case 27: r = self->m24[i].e1; break;
        }
    }
    return r;
}

float fn_80089E48(Unk80089894_Obj* o, int i, int a)
{
    float r = (o->*lbl_805B6BA8[i])(a);
    return r;
}

void fn_80089EE0(Unk80089894_PackTabD* self, unsigned t, unsigned i, int v)
{
    if (i < self->m1C) {
        switch (t) {
        case 0: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->a0 = v;
            break;
        }
        case 1: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->a1 = v;
            break;
        }
        case 2: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->a2 = v;
            break;
        }
        case 3: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x1) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1;
            p->a3 = v;
            break;
        }
        case 4: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->a4 = v;
            break;
        }
        case 5: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->a5 = v;
            break;
        }
        case 6: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->a6 = v;
            break;
        }
        case 7: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->b0 = v;
            break;
        }
        case 8: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->b1 = v;
            break;
        }
        case 9: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->b2 = v;
            break;
        }
        case 10: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->b3 = v;
            break;
        }
        case 11: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->b4 = v;
            break;
        }
        case 12: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->b5 = v;
            break;
        }
        case 13: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->b6 = v;
            break;
        }
        case 14: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->c0 = v;
            break;
        }
        case 15: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->c1 = v;
            break;
        }
        case 16: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->c2 = v;
            break;
        }
        case 17: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->c3 = v;
            break;
        }
        case 18: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->c4 = v;
            break;
        }
        case 19: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->c5 = v;
            break;
        }
        case 20: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->d0 = v;
            break;
        }
        case 21: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->d1 = v;
            break;
        }
        case 22: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0xF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xF;
            p->d2 = v;
            break;
        }
        case 23: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7;
            p->d3 = v;
            break;
        }
        case 24: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->d4 = v;
            break;
        }
        case 25: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->d5 = v;
            break;
        }
        case 26: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->e0 = v;
            break;
        }
        case 27: {
            Unk80089894_PackD* p = (Unk80089894_PackD*)(i * 20 + (int)self->m24);
            int w;
            if (v <= 0x7F) {
                w = v;
                if (w < 0)
                    w = 0;
            } else
                w = 0x7F;
            p->e1 = w;
            break;
        }
        }
    }
}

float fn_8008A624(W* self, int a)
{
    float s2 = fn_8007189C(self, 2, a);
    const float z = 0.0f;
    float s4 = fn_8007189C(self, 4, a);
    float s5 = fn_8007189C(self, 5, a);
    float r = fn_8008A9DC(0, s2, z, s4, s5);
    return r;
}

float fn_8008A6BC(W* self, int a)
{
    int h = self->v28(6, a);
    float r = 0.0f;
    if (h != 0) {
        float s7 = fn_8007189C(self, 7, a);
        const float z = 0.0f;
        float s9 = fn_8007189C(self, 9, a);
        float s10 = fn_8007189C(self, 10, a);
        r = fn_8008A9DC(h, s7, z, s9, s10);
    }
    return r;
}

float fn_8008A784(W* self, int a)
{
    int h = self->v28(11, a);
    float r = 0.0f;
    if (h != 0) {
        float s7 = fn_8007189C(self, 12, a);
        const float z = 0.0f;
        float s9 = fn_8007189C(self, 14, a);
        float s10 = fn_8007189C(self, 15, a);
        r = fn_8008A9DC(h, s7, z, s9, s10);
    }
    return r;
}

float fn_8008A84C(W* self, int a)
{
    int h = self->v28(16, a);
    float r = 0.0f;
    if (h != 0) {
        float s7 = fn_8007189C(self, 17, a);
        const float z = 0.0f;
        float s9 = fn_8007189C(self, 19, a);
        float s10 = fn_8007189C(self, 20, a);
        r = fn_8008A9DC(h, s7, z, s9, s10);
    }
    return r;
}

float fn_8008A914(W* self, int a)
{
    int h = self->v28(21, a);
    float r = 0.0f;
    if (h != 0) {
        float s7 = fn_8007189C(self, 22, a);
        const float z = 0.0f;
        float s9 = fn_8007189C(self, 24, a);
        float s10 = fn_8007189C(self, 25, a);
        r = fn_8008A9DC(h, s7, z, s9, s10);
    }
    return r;
}

float fn_8008A9DC(int kind, float a, float b, float c, float d)
{
    if (lbl_80620758 != 0)
        return lbl_8062075C;
    float r = 0.0f;
    if (kind == 0)
        r = (c + d) * 0.5f + d - 0.93f;
    else
        r = (c + a) * 0.5f + 0.04f;
    r = !(r > 1.0f) ? (r >? 0.0f) : 1.0f;
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

float fn_8008ADCC(Unk80089894_Obj* o, int i, int a)
{
    float r = (o->*(lbl_805B6BD0 + i)[0])(a);
    return r;
}

void fn_8008AE60(Unk80089894_PackTab* self, unsigned t, unsigned i, int v)
{
    if (i < self->m1C) {
        switch (t) {
        case 0: {
            Unk80089894_Pack* p = (Unk80089894_Pack*)(i * 12 + (int)self->m24);
            if (v <= 0x7FF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7FF;
            p->a0 = v;
            break;
        }
        case 1: {
            Unk80089894_Pack* p = (Unk80089894_Pack*)(i * 12 + (int)self->m24);
            if (v <= 0xFFF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xFFF;
            p->a1 = v;
            break;
        }
        case 2: {
            Unk80089894_Pack* p = (Unk80089894_Pack*)(i * 12 + (int)self->m24);
            if (v <= 0x1FF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1FF;
            p->a2 = v;
            break;
        }
        case 3: {
            Unk80089894_Pack* p = (Unk80089894_Pack*)(i * 12 + (int)self->m24);
            if (v <= 0x3FF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3FF;
            p->b0 = v;
            break;
        }
        case 4: {
            Unk80089894_Pack* p = (Unk80089894_Pack*)(i * 12 + (int)self->m24);
            if (v <= 0x3FF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3FF;
            p->b1 = v;
            break;
        }
        case 5: {
            Unk80089894_Pack* p = (Unk80089894_Pack*)(i * 12 + (int)self->m24);
            if (v <= 0xFFF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0xFFF;
            p->b2 = v;
            break;
        }
        case 6: {
            Unk80089894_Pack* p = (Unk80089894_Pack*)(i * 12 + (int)self->m24);
            if (v <= 0x1FFF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1FFF;
            p->c0 = v;
            break;
        }
        case 7: {
            Unk80089894_Pack* p = (Unk80089894_Pack*)(i * 12 + (int)self->m24);
            if (v <= 0x1FFF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1FFF;
            p->c1 = v;
            break;
        }
        case 8: {
            Unk80089894_Pack* p = (Unk80089894_Pack*)(i * 12 + (int)self->m24);
            int w;
            if (v <= 3) {
                w = v;
                if (w < 0)
                    w = 0;
            } else
                w = 3;
            p->c2 = w;
            break;
        }
        }
    }
}

float fn_8008B0BC(W* self, int a)
{
    float s = (float)self->v28(1, a);
    int b = self->v28(7, a);
    float tot = (float)b + (float)self->v28(8, a) * 0.33333334f;
    float r = tot != 0.0f ? s * 9.0f / tot : 0.0f;
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

extern "C" unsigned fn_8008B42C(Unk80089894_PackTabC* self, unsigned t, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (t) {
        case 0: r = self->m24[i].a0; break;
        case 1: r = self->m24[i].a1; break;
        case 2: r = self->m24[i].a2; break;
        case 3: r = self->m24[i].a3; break;
        case 4: r = self->m24[i].a4; break;
        case 5: r = self->m24[i].b0; break;
        case 6: r = self->m24[i].b1; break;
        case 7: r = self->m24[i].b2; break;
        case 8: r = self->m24[i].b3; break;
        case 9: r = self->m24[i].c0; break;
        case 10: r = self->m24[i].c1; break;
        case 11: r = self->m24[i].c2; break;
        case 12: r = self->m24[i].c3; break;
        case 13: r = self->m24[i].c4; break;
        }
    }
    return r;
}

float fn_8008B5F8(Unk80089894_Obj* o, int i, int a)
{
    float r = (o->*lbl_805B6BD8[i])(a);
    return r;
}

extern "C" void fn_8008B690(Unk80089894_PackTabC* self, unsigned t, unsigned i, int v)
{
    if (i < self->m1C) {
        switch (t) {
        case 0: {
            Unk80089894_PackC* b = self->m24;
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)b);
            if (v <= 0xFF) {
                if (v < 0)
                    v = 0;
                p->a0 = v;
            } else
                p->a0 = 0xFF;
            break;
        }
        case 1: {
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)self->m24);
            if (v <= 0x1FF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1FF;
            p->a1 = v;
            break;
        }
        case 2: {
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)self->m24);
            if (v <= 0x3) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3;
            p->a2 = v;
            break;
        }
        case 3: {
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)self->m24);
            if (v <= 0x3F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3F;
            p->a3 = v;
            break;
        }
        case 4: {
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)self->m24);
            if (v <= 0x3F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3F;
            p->a4 = v;
            break;
        }
        case 5: {
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)self->m24);
            int w;
            if (v <= 0xFF) {
                w = v;
                if (w < 0)
                    w = 0;
            } else
                w = 0xFF;
            p->b0 = w;
            break;
        }
        case 6: {
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)self->m24);
            int w;
            if (v <= 0xFF) {
                w = v;
                if (w < 0)
                    w = 0;
            } else
                w = 0xFF;
            p->b1 = w;
            break;
        }
        case 7: {
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->b2 = v;
            break;
        }
        case 8: {
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->b3 = v;
            break;
        }
        case 9: {
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)self->m24);
            if (v <= 0x3F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3F;
            p->c0 = v;
            break;
        }
        case 10: {
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)self->m24);
            if (v <= 0x3F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3F;
            p->c1 = v;
            break;
        }
        case 11: {
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)self->m24);
            if (v <= 0x3F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3F;
            p->c2 = v;
            break;
        }
        case 12: {
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)self->m24);
            if (v <= 0x3F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3F;
            p->c3 = v;
            break;
        }
        case 13: {
            Unk80089894_PackC* p = (Unk80089894_PackC*)(i * 12 + (int)self->m24);
            int w;
            if (v <= 0x3F) {
                w = v;
                if (w < 0)
                    w = 0;
            } else
                w = 0x3F;
            p->c4 = w;
            break;
        }
        }
    }
}

float fn_8008BA24(W* self, int a)
{
    float r = (float)self->v28(1, a);
    r += (float)self->v28(2, a) * 0.33333334f;
    return r;
}

float fn_8008BAF0(W* self, int a)
{
    float s = (float)self->v28(6, a);
    float d = fn_8008BA24(self, a);
    float r = 0.0f;
    if (!(d <= 0.0f))
        r = s * 9.0f / d;
    return r;
}

float fn_8008BBAC(W* self, int a)
{
    float s = (float)self->v28(3, a);
    int b = self->v28(4, a);
    float tot;
    float r = 0.0f;
    tot = s + (float)b;
    if (!(tot <= 0.0f))
        r = s / tot;
    return r;
}

float fn_8008BC94()
{
    return lbl_805B4E34;
}

float fn_8008BCA0(W* self, int a)
{
    int x = self->v28(7, a);
    float r = (float)x + (float)self->v28(8, a);
    return r;
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

/* near-miss (5 slots): retail keeps the dead cmplwi compares and merges all
 * `li r3,0; blr` tails; see PATTERNS (dead cmpwi before li r3,0 family). */
int fn_8008BEF0(void* self, int k)
{
    switch ((unsigned)k) {
    case 2:
        return 0;
    case 5:
        return 0;
    case 8:
        return 0;
    }
    return 0;
}

unsigned fn_8008BF58(Unk80089894_PackTabB* self, unsigned t, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (t) {
        case 0: r = self->m24[i].a0; break;
        case 1: r = self->m24[i].a1; break;
        case 2: r = self->m24[i].a2; break;
        case 3: r = self->m24[i].a3; break;
        case 4: r = self->m24[i].b0; break;
        case 5: r = self->m24[i].b1; break;
        case 6: r = self->m24[i].b2; break;
        case 7: r = self->m24[i].b3; break;
        case 8: r = self->m24[i].b4; break;
        case 9: r = self->m24[i].c0; break;
        case 10: r = self->m24[i].c1; break;
        }
    }
    return r;
}

float fn_8008C0DC(Unk80089894_Obj* o, int i, int a)
{
    float r = (o->*lbl_805B6C18[i])(a);
    return r;
}

void fn_8008C174(Unk80089894_PackTabB* self, unsigned t, unsigned i, int v)
{
    if (i < self->m1C) {
        switch (t) {
        case 0: {
            Unk80089894_PackB* b = self->m24;
            Unk80089894_PackB* p = (Unk80089894_PackB*)(i * 12 + (int)b);
            if (v <= 0xFF) {
                if (v < 0)
                    v = 0;
                p->a0 = v;
            } else
                p->a0 = 0xFF;
            break;
        }
        case 1: {
            Unk80089894_PackB* p = (Unk80089894_PackB*)(i * 12 + (int)self->m24);
            if (v <= 0x3F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3F;
            p->a1 = v;
            break;
        }
        case 2: {
            Unk80089894_PackB* p = (Unk80089894_PackB*)(i * 12 + (int)self->m24);
            if (v <= 0x1FF) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1FF;
            p->a2 = v;
            break;
        }
        case 3: {
            Unk80089894_PackB* p = (Unk80089894_PackB*)(i * 12 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->a3 = v;
            break;
        }
        case 4: {
            Unk80089894_PackB* p = (Unk80089894_PackB*)(i * 12 + (int)self->m24);
            int w;
            if (v <= 0xFF) {
                w = v;
                if (w < 0)
                    w = 0;
            } else
                w = 0xFF;
            p->b0 = w;
            break;
        }
        case 5: {
            Unk80089894_PackB* p = (Unk80089894_PackB*)(i * 12 + (int)self->m24);
            if (v <= 0x3F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3F;
            p->b1 = v;
            break;
        }
        case 6: {
            Unk80089894_PackB* p = (Unk80089894_PackB*)(i * 12 + (int)self->m24);
            if (v <= 0x3F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x3F;
            p->b2 = v;
            break;
        }
        case 7: {
            Unk80089894_PackB* p = (Unk80089894_PackB*)(i * 12 + (int)self->m24);
            if (v <= 0x7F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x7F;
            p->b3 = v;
            break;
        }
        case 8: {
            Unk80089894_PackB* p = (Unk80089894_PackB*)(i * 12 + (int)self->m24);
            if (v <= 0x1F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1F;
            p->b4 = v;
            break;
        }
        case 9: {
            Unk80089894_PackB* p = (Unk80089894_PackB*)(i * 12 + (int)self->m24);
            if (v <= 0x1F) {
                if (v < 0)
                    v = 0;
            } else
                v = 0x1F;
            p->c0 = v;
            break;
        }
        case 10: {
            Unk80089894_PackB* p = (Unk80089894_PackB*)(i * 12 + (int)self->m24);
            int w;
            if (v <= 0x3FF) {
                w = v;
                if (w < 0)
                    w = 0;
            } else
                w = 0x3FF;
            p->c1 = w;
            break;
        }
        }
    }
}

float fn_8008C45C(W* self, int a)
{
    int x0 = self->v28(4, a);
    int x1 = self->v28(5, a);
    int x2 = self->v28(6, a);
    float r = (float)(x0 + x1 + x2 + self->v28(7, a));
    return r;
}

float fn_8008C54C(W* self, int a)
{
    float s0 = (float)self->v28(4, a);
    float s1 = (float)self->v28(5, a);
    float s2 = (float)self->v28(6, a);
    float s3 = (float)self->v28(7, a);
    float r = s3 * lbl_805B4E64 + (s2 * lbl_805B4E60 + (s0 + 2.0f * s1));
    return r;
}

float fn_8008C6B4(W* self, int a)
{
    float x = fn_8008C45C(self, a);
    float d = fn_8008C94C(self, a);
    float r = lbl_805B4E68;
    if (!(d <= lbl_805B4E68))
        r = x / d;
    return r;
}

float fn_8008C724(W* self, int a)
{
    float t = fn_8008C45C(self, a);
    float b0 = (float)self->v28(0, a);
    float b3 = (float)self->v28(3, a);
    float b8 = (float)self->v28(8, a);
    float d = fn_8008C94C(self, a);
    float tot = d + b0 + b3 + b8;
    float r = lbl_805B4E78;
    if (!(tot <= lbl_805B4E78))
        r = (t + b0 + b3) / tot;
    return r;
}

float fn_8008C884(W* self, int a)
{
    float x = fn_8008C54C(self, a);
    float d = fn_8008C94C(self, a);
    float r = lbl_805B4E7C;
    if (!(d <= lbl_805B4E7C))
        r = x / d;
    return r;
}

float fn_8008C8F4(W* self, int a)
{
    float x = fn_8008C724(self, a);
    float y = fn_8008C884(self, a);
    float r = x + y;
    return r;
}

float fn_8008C94C(W* self, int a)
{
    int x = self->v28(10, a);
    int p = self->v28(0, a);
    int q = self->v28(3, a);
    int s = self->v28(8, a);
    float r = (float)x - (float)(p + q + s + self->v28(9, a));
    if (!(r >= lbl_805B4E88))
        r = lbl_805B4E88;
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
