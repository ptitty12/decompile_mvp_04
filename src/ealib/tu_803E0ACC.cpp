/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803E0ACC-0x803E1F98 (code-only unit, 17 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

#include "../../include/game/tu_803E097C.h"

struct Unk803E1B54_Init {
    int a, b, c;
};

extern Unk803E097C_Blk64 lbl_8060E938;
extern Unk803E097C_Blk64 lbl_806AA990;
extern int lbl_8062C2BC;
extern Unk803E1B54_Init lbl_8062C2C0;

extern "C" void fn_80377408(void* p);
extern "C" void fn_803E0F9C(Unk803E1F98_Node* n);
extern "C" void fn_803E1F0C(Unk803E198C_View* v);

/* Orthographic projection setup: the matrix helper at 0x80431564 takes (mtx, t, b, l, r, n, f); the
 * result is mirrored into the node's 4x4 block at Node+0x18 and loaded by fn_80430194(mtx, 1). */
extern "C" void fn_80431564(float* m, float t, float b, float l, float r, float n, float f);
extern "C" void fn_80430194(float* m, int type);
/* Fog parameter block (pointed to by the first word of the owner at View+0). */
struct Unk803E1A38Fog {
    int m0;
    float m4;
    float m8;
    int mC;
    int m10;
    int m14;
};
struct Unk803E1A38Col {
    int v;
};
struct Unk803E1A38Mid {
    Unk803E1A38Fog* m0;
};
extern "C" void fn_8042F93C(int type, Unk803E1A38Col color, float startz, float endz, float nearz, float farz);
extern "C" void fn_8042FB50(unsigned short* table, unsigned short width, float* projmtx);
extern "C" void fn_8042FD00(int enable, unsigned short center, unsigned short* table);

extern "C" Unk803E198C_View* fn_803E198C(Unk803E198C_View* v, Unk803E1F98_Node* node)
{
    v->m4 = 1;
    v->m0 = 0;
    v->m8 = 0;
    v->m18C = 0;
    v->m194 = 0;
    v->mCC = -1.0f;
    v->m198 = 0;
    v->mD0 = -1.0f;
    v->mD4 = -1.0f;
    v->mD8 = -1.0f;
    v->mDC = -1.0f;
    v->m19C = node;
    v->mE0 = -1.0f;
    v->mE4 = -1.0f;
    v->mE8 = -1.0f;
    v->mEC = -1.0f;
    v->mF0 = -1.0f;
    v->m14C[0] = 1.0f;
    v->m14C[1] = 0.0f;
    v->m14C[2] = 0.0f;
    v->m14C[3] = 0.0f;
    v->m14C[4] = 0.0f;
    v->m14C[5] = 1.0f;
    v->m14C[6] = 0.0f;
    v->m14C[7] = 0.0f;
    v->m14C[8] = 0.0f;
    v->m14C[9] = 0.0f;
    v->m14C[10] = 1.0f;
    v->m14C[11] = 0.0f;
    v->m14C[12] = 0.0f;
    v->m14C[13] = 0.0f;
    v->m14C[14] = 0.0f;
    v->m14C[15] = 1.0f;
    return v;
}

extern "C" void fn_803E1A38(Unk803E198C_View* v)
{
    Unk803E1A38Mid* o = (Unk803E1A38Mid*)v->m0;
    if (o) {
        Unk803E1A38Col color = *(Unk803E1A38Col*)&o->m0->m10;
        if (o->m0->m0) {
            fn_8042F93C(o->m0->mC, color, o->m0->m4, o->m0->m8, v->mEC, v->mF0);
            if (((Unk803E1A38Mid*)v->m0)->m0->m14) {
                unsigned short tbl[10];
                unsigned short* t = tbl;
                fn_8042FB50(t, (unsigned short)(int)v->mD4, v->m14C);
                int w = (int)(v->mD4 * 0.5f + v->mCC);
                if (w < 0)
                    w = 0;
                fn_8042FD00(1, (unsigned short)w, t);
            } else {
                fn_8042FD00(0, 0, 0);
            }
        } else {
            fn_8042F93C(0, color, 0.0f, 0.0f, 0.0f, 0.0f);
        }
    }
}

/* static initializer: copies a 64-byte constant block and sets two more globals */
extern "C" void fn_803E1B54(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize) {
        lbl_806AA990 = lbl_8060E938;
        lbl_8062C2BC = 0x12345678;
        lbl_8062C2C0.a = 4;
        lbl_8062C2C0.b = 4;
        lbl_8062C2C0.c = 1;
    }
}

extern "C" void fn_803E1C10(Unk803E1F98_Node* n, float* a, float* b, float* c, float* d, float* e, float* f)
{
    *a = n->mC.mCC;
    *b = n->mC.mD0;
    *c = n->mC.mD4;
    *d = n->mC.mD8;
    *e = n->mC.mDC;
    *f = n->mC.mE0;
}

extern "C" void fn_803E1C44(Unk803E1F98_Node* n, Unk803E097C_Blk64* src)
{
    n->mC.m4C = *src;
    if (n->mC.m18C)
        fn_803E1F0C(&n->mC);
}

extern "C" void fn_803E1CDC(Unk803E1F98_Node* n, float a, float b, float c)
{
    const float zero = 0.0f;
    n->mC.mE4 = zero;
    n->mC.mE8 = a;
    n->mC.mEC = b;
    n->mC.mF0 = c;
    fn_80431564(n->mC.m14C, a, -a, -1.0f, 1.0f, b, c);
    n->mC.mC.w[8] = zero;
    n->mC.mC.w[9] = zero;
    n->mC.mC.w[0] = n->mC.m14C[0];
    n->mC.mC.w[5] = n->mC.m14C[5];
    n->mC.mC.w[11] = zero;
    n->mC.mC.w[10] = n->mC.m14C[10];
    n->mC.mC.w[12] = n->mC.m14C[3];
    n->mC.mC.w[13] = n->mC.m14C[7];
    n->mC.mC.w[14] = n->mC.m14C[11];
    n->mC.mC.w[15] = 1.0f;
    n->mC.m4 = 1;
    fn_80430194(n->mC.m14C, 1);
}

extern "C" void fn_803E1DB0(Unk803E1F98_Node* n, float a, float b)
{
    const float zero = 0.0f;
    n->mC.mE4 = zero;
    n->mC.mE8 = 0.75f;
    n->mC.mEC = a;
    n->mC.mF0 = b;
    fn_80431564(n->mC.m14C, zero, n->mC.mD8, zero, n->mC.mD4, a, b);
    n->mC.m4 = 1;
    n->mC.mC.w[0] = n->mC.m14C[0];
    n->mC.mC.w[5] = n->mC.m14C[5];
    n->mC.mC.w[8] = zero;
    n->mC.mC.w[10] = n->mC.m14C[10];
    n->mC.mC.w[12] = n->mC.m14C[3];
    n->mC.mC.w[13] = n->mC.m14C[7];
    n->mC.mC.w[9] = zero;
    n->mC.mC.w[14] = n->mC.m14C[11];
    n->mC.mC.w[15] = 1.0f;
    n->mC.mC.w[11] = zero;
    fn_80430194(n->mC.m14C, 1);
}

extern "C" void fn_803E1E88(Unk803E1F98_Node* n)
{
    ((lbl_Owner*)n->mC.m0->m8)->fn_803DA154(0);
    n->mC.m18C = 0;
    if (n->m4 > 1)
        fn_803E0F9C((Unk803E1F98_Node*)n->m4);
    n->m4 = 0;
}

extern "C" void fn_803E1EDC(void* self, void* node)
{
    *(void**)self = node;
}

extern "C" void fn_803E1EE4(void* p, int c)
{
    if (c & 1)
        fn_80377408(p);
}

extern "C" void fn_803E1F0C(Unk803E198C_View* v)
{
    Unk803E1F98_Node* n = v->m19C;
    ((lbl_Owner*)n->mC.m0->m8)->fn_803DA154(0);
    n->mC.m18C = 0;
    if (n->m4 > 1)
        fn_803E0F9C((Unk803E1F98_Node*)n->m4);
    n->m4 = 0;
    fn_803E0F9C(v->m19C);
}

extern "C" void fn_803E1F6C()
{
    fn_803E1B54(1, 0xFFFF);
}

/*
 * Not matched yet: fn_803E0ACC, fn_803E0DD0, fn_803E0F9C, fn_803E1578, fn_803E1850 (collision test through
 * fn_803DED40). The original code stays linked for these.
 */
