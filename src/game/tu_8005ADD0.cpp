/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x8005ADD0-0x8005C514 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80052794.h"

int fn_8005ADD0(Unk8005ADD0_Obj* o, int ch)
{
    if (o->m7C == 0) {
        o->mE8[ch] = -3;
    } else if (o->mE8[ch] < 0) {
        o->mE8[ch] = 1;
        o->m108 = -1;
        for (int i = 0; i < 8; i++) {
            if (o->mE8[i] >= 0) {
                o->m108 = o->mE8[i];
                break;
            }
        }
    }
    switch (o->mE8[ch]) {
    case -3:
        return -3;
    case -2:
        return -2;
    case -1:
        return -1;
    case 0:
        return 0;
    case 1:
        return 1;
    default:
        return -2;
    }
}

void fn_8005AEB0(Unk8005ADD0_Obj* o, int ch)
{
    o->mE8[ch] = -1;
    o->m108 = -1;
    if (o->m7C == 1) {
        for (int i = 0; i < 8; i++) {
            if (o->mE8[i] >= 0) {
                o->m108 = o->mE8[i];
                break;
            }
        }
    }
}

/* near-miss (1 slot): retail reloads o->mA4 for the final return; this reuses cur. */
int fn_8005B6E4(Unk8005ADD0_Obj* o)
{
    int cur = o->mA4;
    for (int i = cur + 1; i <= 8; i++) {
        if (o->mC[o->m80[i]].mState != 6) {
            return i;
        }
    }
    for (int i = 0; i < cur; i++) {
        if (o->mC[o->m80[i]].mState != 6) {
            return i;
        }
    }
    return o->mA4;
}

int fn_8005B864(Unk8005ADD0_Obj* o)
{
    return lbl_805B1DC0[o->mA8];
}

int fn_8005B9B0(Unk8005ADD0_Obj* o, int i)
{
    int r = 1;
    if (o->mC[i].mState == 6) {
        r = 0;
    }
    return r;
}

void fn_8005B9D4(Unk8005ADD0_Obj* o, int a)
{
    fn_8005B58C(o, 0);
    fn_8005AF00(o, a);
    fn_8005B06C(o);
}

Unk8005BA1C_Obj::Unk8005BA1C_Obj()
{
    m2C = -1;
    m0 = 0;
    m4 = 0;
    m8 = 0;
    m80 = 0;
    for (int i = 0; i < 4; i++) {
        m30[i].m0 = 0;
        m30[i].m8 = 0;
        m30[i].m4 = 0;
        m30[i].mC = 0;
        m30[i].m10 = 0;
    }
    for (int j = 0; j < 8; j++) {
        mC[j] = -1;
    }
}

Unk8005BA1C_Obj* fn_8005BA9C(void)
{
    if (lbl_80618F8C == 0) {
        lbl_80618F8C = new (0) Unk8005BA1C_Obj;
    }
    return lbl_80618F8C;
}

Unk8005BA1C_Obj::~Unk8005BA1C_Obj()
{
}

void fn_8005BDA8(Unk8005BA1C_Obj* o)
{
    for (int i = 0; i < 4; i++) {
        if (o->m30[i].m0 != 0) {
            fn_8005A814(o->m30[i].m0, 0);
            delete o->m30[i].m0;
            o->m30[i].m0 = 0;
        }
    }
}

void fn_8005BE30(Unk8005BA1C_Obj* o)
{
    for (int i = 0; i < 4; i++) {
        if (o->m30[i].m0 != 0) {
            fn_8005A814(o->m30[i].m0, 0);
            delete o->m30[i].m0;
            o->m30[i].m0 = 0;
        }
    }
    if (o->m80 != 0) {
        delete[] (char*)o->m80;
        o->m80 = 0;
    }
    if (lbl_80618F8C != 0) {
        delete lbl_80618F8C;
        lbl_80618F8C = 0;
    }
}

void fn_8005C250(Unk8005BA1C_Obj* o, int ch)
{
    int r = 0;
    if (o->m0 == 1 && o->mC[ch] >= 0) {
        for (int i = 0; i < 4; i++) {
            if (o->m30[i].m0 != 0 && lbl_805B10B4[ch].mA0[i] == 1) {
                int k = lbl_805AE420[ch].e[i].m24;
                if (k == 0) {
                    fn_8005A010(o->m30[i].m0, 0, ch);
                } else if (k == 1 && r == 0) {
                    r = fn_8005A010(o->m30[i].m0, 1, ch);
                }
            }
        }
    }
}

int fn_8005C344(Unk8005BA1C_Obj* o, int k)
{
    int r = 0;
    Unk8005BA1C_Voice* v = o->m30[k].m0;
    if (v != 0) {
        int ok = 1;
        if (v->m0 == -1) {
            ok = 0;
        }
        if (ok != 0) {
            r = 1;
        }
    }
    return r;
}

void fn_8005C384(Unk8005BA1C_Obj* o, int a)
{
    int ok = 0;
    if (o->m0 == 1) {
        ok = o->m2C >= 0;
    }
    if (ok == 1) {
        int k = lbl_805B09F4[a].mD4;
        if (fn_8005C344(o, k) == 1) {
            fn_8005A2E4(o->m30[k].m0, a);
        }
    }
}

int fn_8005C410(Unk8005BA1C_Obj* o, int k, float f)
{
    int r = 0;
    int ok = 0;
    if (o->m0 == 1) {
        ok = o->m2C >= 0;
    }
    if (ok == 1 && fn_8005C344(o, k) == 1) {
        r = fn_8005A118(o->m30[k].m0, f);
    }
    return r;
}

int fn_8005C498(Unk8005BA1C_Obj* o, int k)
{
    int r = -1;
    int ok = 0;
    if (o->m0 == 1) {
        ok = o->m2C >= 0;
    }
    if (ok == 1 && fn_8005C344(o, k) == 1) {
        r = o->m30[k].m0->m28;
    }
    return r;
}
