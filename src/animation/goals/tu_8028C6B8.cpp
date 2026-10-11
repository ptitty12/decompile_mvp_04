/*
 * Part of the animation choosers/goals unity TU (see docs/DECISIONS.md,
 * 2026-10-11): goal logic. Original file name unknown; placeholder.
 *
 * .text 0x8028C6B8-0x8028F178, .rodata 0x805DD754-0x805DD848, .data 0x8061E700-0x8061E778.
 * Data this code uses outside these ranges is declared extern (the unity TU
 * emits .data in source-definition order, not .text order).
 */
#include "game/chooser.h"
#include "game/goals/tu_8028C6B8.h"

#define REACHGOAL_FILE "C:/mvp2004/source/common/animation/goals/reachgoal.cpp"

void Unk8028C6B8_Goal::fn_8028D0EC(Unk8028C6B8_X* x, Unk8028C6B8_Ctx* ctx)
{
    if (!mA8.f15) {
        Unk80270BA0_Obj* p = ctx->m6CC->m36C;

        if (p) {
            float lim = 0.18f * Unk8028D0EC_M540(p->fn_vslot1()) + 0.8f;
            float r;           /* never read: reserves stack slot 0xC */
            Unk8014D8AC_Ctx* c = fn_8027A918();
            float scale = 1.0f;
            const char* file = REACHGOAL_FILE;

            if (!((float)(unsigned int)c->m554->fn_8014D8AC(1000000, file, 1361) * scale * 0.000001f <= lim)) {
                mA8.f14 = 1;
            }
        }
        mA8.f15 = 1;
    }
}

void Unk8028C6B8_Goal::fn_8028D808(Unk8028C6B8_X* x, int c)
{
    if (mA8.f16) {
        m4C = fn_8028D8D8(x);
    }
    unsigned int mode = m4C;
    if (mode <= 1) {
        if (m4->mC > 1 && m4->m4C == 8) {
            mode = 20;
        }
        if (mA8.f11) {
            mode = 20;
        }
    }
    m48 = mode;
    fn_8028C6B8(x, c);
    int r = fn_8028D4E4(mode, x, c);
    m48 = r;
    if (r != mode) {
        fn_8028C6B8(x, c);
    }
    fn_8025596C(x->m58C, m48);
}

int fn_8028DA0C(void* g, Unk8028C6B8_X* x)
{
    if (x && x->m458 == 1) {
        float a = 20.0f;
        float b = 2.25f;

        Unk8028DA0C_FacingDiff(x);
        Unk80273498_Vec3 pos = x->m60;
        Unk80273498_Vec3 w = fn_8014E388(3);

        w.x += a;
        if ((w.x - pos.x) * (w.x - pos.x) + (w.z - pos.z) * (w.z - pos.z) < b * (b * 144.0f)) {
            return 1;
        }
    }
    return 0;
}

unsigned int fn_8028E73C(void* g, int k)
{
    unsigned int r = 0;
    switch (k) {
    case 2:
        r = lbl_806242B4;
        break;
    case 5:
        r = 0x8BF0ACA6;
        break;
    case 7:
        r = 0xA5422C1B;
        break;
    }
    return r;
}

int fn_8026DC5C(int a, int b);

int fn_8028E788(void* g, int a)
{
    return fn_8026DC5C(a, 0);
}

void Unk8028C6B8_Goal::fn_8028E7B0(Unk8028C6B8_X* x)
{
    m4->fn_8028F45C(fn_GetTarget());
    if (m2C && m48 != 2 && m48 != 22 && m48 != 23 && m48 != 24 && m48 != 25) {
        m4->fn_8028F528(fn_GetM1C());
    }
    m4->m98 = m78;
    int t38 = m38;
    m4->m38 = t38;
    int t34 = m34;
    m4->m34 = t34;
    m4->m40 = 10;
    m4->m18C.f18 = mA8.f5;
    if (mA8.f11) {
        float d = m70 - m8->fn_8027A280(0);
        m4->fn_8028F588(d);
        float v = x->m724;
        if (mA8.f12) {
            v = fn_80248FC8(x, m38);
        }
        m4->fn_SetM78(v);
    }
    if (mA8.f17) {
        m4->m54 = 8;
        m4->m18C.f19 = mA8.f18;
    }
}

int Unk8028C6B8_Goal::fn_8028E944(Unk8028C6B8_X* x, int c)
{
    if (m4->m28 == 0) {
        fn_8028E7B0(x);
    }
    int r = m4->fn_80290D1C(x);
    int result = -1;
    switch (r) {
    case 0:
    case 2:
        result = c ? -1 : 2;
        break;
    case 3:
        result = 3;
        break;
    case 1:
        result = 1;
        break;
    }
    return result;
}

void Unk8028C6B8_Goal::fn_8028ED00()
{
    m0 = 2;
    m48 = -1;
    m50 = 0;
    m58 = 0;
    m60I = 0;
    m5C = -1.0f;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028ED30(Unk80273498_Vec3 v)
{
    v.y = 0.0f;
    fn_SetTarget(v);
    m28 = 1;
    m4->fn_8028F45C(v);
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028EDD0(int idx)
{
    m48 = idx;
    Unk80273498_Vec3 p = fn_8027AF54(idx);
    fn_8028ED30(p);
    m4->fn_8028F4B8(idx);
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028EE4C(int idx, Unk80273498_Vec3* pos)
{
    if (pos) {
        fn_8028ED30(*pos);
    } else {
        Unk80273498_Vec3 p = fn_801837F4(fn_8027A90C()->m44C->m6B8, idx);
        fn_8028ED30(p);
    }
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028EEF4()
{
    int v = 1;
    m60I = v;
    m4->m18C.f18 = v;
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028EF14(Unk80273498_Vec3 v)
{
    v.y = 0.0f;
    fn_8027A898(v);
    m4->fn_8028F528(v);
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028EF98(float f)
{
    int flag;
    if (!(f <= 0.0f)) {
        m4CF = f;
        flag = 1;
    } else {
        flag = 0;
    }
    m50 = flag;
    m4->fn_8028F588(f);
    Unk8028F45C_Inner* i = m4;
    float unused;
    float t = fn_8027A90C()->m724;
    i->m78 = t;
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028F01C(float f)
{
    m58 = 1;
    m54 = f;
    m4->fn_8028F5CC(f);
    return this;
}

Unk8028C6B8_Goal* Unk8028C6B8_Goal::fn_8028F068(float f)
{
    m5C = f;
    m4->fn_8028F5F4(f);
    return this;
}

void Unk8028C6B8_Goal::fn_8028F0AC()
{
    m4->fn_8028F610();
}

void Unk8028C6B8_Goal::fn_8028F0D0()
{
    m4->fn_8028F848();
}

void Unk8028C6B8_Goal::fn_8028F0F4(Unk8028C6B8_X* x)
{
    int t38 = m38;
    m4->m38 = t38;
    int t34 = m34;
    m4->m34 = t34;
    m4->m40 = m40;
    if (x->m458 <= 8) {
        fn_8027AFA8(x->m44C, x, 0);
    }
    m4->fn_80290D1C(x);
    mC = m4->mC;
}
