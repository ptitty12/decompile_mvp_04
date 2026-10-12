/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80047B08-0x800493D4 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80047B08.h"

void fn_80047CA4(Unk8004763C* t)
{
    int i = 0;
    fn_80392708();
    fn_80392DF4();
    do {
        fn_80048464(t, i);
        i++;
    } while (i <= 7);
    if (t->mF0 != 0) {
        fn_80377488((void*)t->mF0);
        t->mF0 = 0;
    }
    if (t->mE4 != 0) {
        fn_80377488((void*)t->mE4);
        t->mE4 = 0;
    }
    lbl_80617804 = 0;
    lbl_80617808 = 0;
    t->mE0 = 0;
    t->mEC = 0;
    t->mF8 = 0;
}

/* near-miss: same loop shape as fn_80047958 (li r9,0 / addi r11 order) */
void fn_80047D40(Unk8004763C* t, int idx)
{
    if (t->mF4 == 1) {
        int* a = t->mBE0;
        int off = idx * 4;
        if (*(int*)((char*)a + off) >= 0) {
            fn_80392708();
            *(int*)((char*)a + off) = -1;
            t->mC00 = -1;
            int k;
            for (k = 0; k < 8; k++) {
                if (a[k] >= 0) {
                    t->mC00 = a[k];
                    break;
                }
            }
            if (idx == 3 || idx == 6)
                fn_800490F8(&t->mFC);
        }
    }
}

/* near-miss: not matched (38 vs 27 insns): retail walks the slots with a running byte offset and enters
 * the loop through a jump to the bottom test; every while/for spelling here duplicates the first test */
int fn_80047FB0(Unk8004763C* t, int x)
{
    int r = -1;
    int i;
    for (i = 0; i < 8; i++) {
        Unk8004763C_Slot* s = &t->mSlots[i];
        if (s->m0 == 1 && s->m4 == 1 && !(x < s->m14) && x < s->m14 + s->m10) {
            r = i;
            break;
        }
    }
    return r;
}

void fn_80048464(Unk8004763C* t, int idx)
{
    char* base = (char*)t + 0xC;
    int off = idx * 0x1C;
    if (*(int*)(base + off) != 0) {
        fn_803EDA0C(*(void**)(base + off));
        *(int*)(base + off) = 0;
    }
}

void fn_80048818(Unk8004763C* t, int idx)
{
    int off = idx * 0x1C;
    char* b8 = (char*)t + 8;
    if (*(int*)(b8 + off) != 0) {
        fn_803EDA0C(*(void**)(b8 + off));
        *(int*)(b8 + off) = 0;
    }
    char* b14 = (char*)t + 0x14;
    char* b10 = (char*)t + 0x10;
    int v = *(int*)(b14 + off);
    if (v < v + *(int*)(b10 + off)) {
        int o = v * 8;
        do {
            v++;
            fn_803917D0(*(int*)(o + t->mF0));
            lbl_80617808 -= 1;
            *(int*)(o + t->mF0) = -1;
            o += 8;
        } while (v < *(int*)(b14 + off) + *(int*)(b10 + off));
    }
}

void fn_800488C4(Unk8004763C* t, int id, float f, int* a, void* b, void* w)
{
    unsigned flag = 0;
    if (t->mF4 == 1) {
        int v = t->mC00;
        flag = (unsigned)~v >> 31;
    }
    if (flag == 1)
        fn_80048E50(&t->mFC, id, f, a, b, w);
}

void fn_80048914(Unk8004763C* t, int a)
{
    if (a != 0) {
        unsigned flag = 0;
        if (t->mF4 == 1) {
            int v = t->mC00;
            flag = (unsigned)~v >> 31;
        }
        if (flag == 1)
            fn_80049090(&t->mFC, a);
    }
    fn_80392708();
}

void fn_80048968(Unk8004763C* t)
{
    unsigned flag = 0;
    if (t->mF4 == 1) {
        int v = t->mC00;
        flag = (unsigned)~v >> 31;
    }
    if (flag == 1) {
        fn_800490D0(&t->mFC);
        fn_80392708();
    }
}

/* near-miss: retail does addi r3,r3,24 in place; here the pointer is copied (r9) */
void fn_800489B4(Unk8004763C* t, int idx, int v)
{
    t = (Unk8004763C*)((char*)t + 0x18);
    *(int*)((char*)t + idx * 0x1C) = v;
    void* o = fn_8005BA9C(t);
    fn_8005C654(o, *(void**)((char*)lbl_805B09F4 + 0xD4 + idx * 0xD8), v, 0);
}

void fn_80048B2C(Unk80048A10_Sub* s, int flags)
{
    s->mAE0 = lbl_80649AB0;
    if (s->mA9C != 0) {
        fn_800575E4(s->mA9C, 3);
        s->mA9C = 0;
    }
    if (s->mADC != 0) {
        delete s->mADC;
        s->mADC = 0;
    }
    if (flags & 1)
        fn_80377408(s);
}

void fn_80048BC0(Unk80048A10_Sub* s)
{
    fn_80057778(s->mA9C);
}

void fn_80048BE4(Unk80048A10_Sub* s)
{
    fn_80057950(s->mA9C);
}

/* near-miss: retail uses a bdnz loop with byte offsets (16 vs 13 insns) */
void fn_80049090(Unk80048A10_Sub* s, int a)
{
    int i = 0;
    do {
        Unk80048A10_Ent* e = &s->mEnt[i];
        if (e->m3C == a && e->m44 == 1)
            e->m44 = 0;
        i++;
    } while (i < 35);
}

void fn_800490D0(Unk80048A10_Sub* s)
{
    int i = 0;
    do {
        s->mEnt[i].m44 = 0;
        i++;
    } while (i < 35);
}

void fn_800490F4(Unk80048A10_Sub*)
{
}

void fn_800490F8(Unk80048A10_Sub*)
{
}

void fn_800490FC(Unk80048A10_Sub*)
{
}
