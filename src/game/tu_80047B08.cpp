/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80047B08-0x800493D4 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80047B08.h"

int fn_80047B08(Unk8004763C* t)
{
    int* a = &lbl_80617804;
    Unk800642F0** b = &lbl_80618FBC;
    Unk80047B08_Cb* cb = fn_80395864();
    cb->m0 = fn_80047B04;
    cb->m4 = fn_80377814;
    cb->m8 = fn_80400DA4;
    fn_80392B6C(fn_8001B950, fn_8001B9C0);
    int ok = 1;
    int h = fn_80392C28(0x5622, 0x10, 1);
    t->mE0 = h;
    fn_80392D08(fn_80044C98, t->mC04, h);
    fn_80392C94(fn_8004483C, fn_80044B94);
    fn_80392CE4(fn_80044C10);
    fn_80392708();
    *a = fn_800480FC(t);
    Unk800642F0* m = new Unk800642F0;
    *b = m;
    *a = *a + m->fn_800644CC() + 1;
    t->mF0 = (int)operator new[](*a * 8, 0x400);
    fn_803EE7BC();
    if (t->mF0 != 0) {
        int n = fn_803913F4(*a);
        t->mEC = n;
        t->mE4 = (int)operator new[](n, 0x400);
        fn_803EE7BC();
        int p = t->mE4;
        if (p != 0) {
            fn_803913FC(*a, p);
        } else {
            if (t->mF0 != 0)
                fn_80377488((void*)t->mF0);
            t->mF0 = p;
            *a = p;
            lbl_80617808 = p;
            ok = 0;
            fn_80047CA4(t);
        }
    } else {
        lbl_80617808 = *a = t->mF0;
        fn_80047CA4(t);
        ok = 0;
    }
    return ok;
}

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

void fn_8004801C(Unk8004763C* t, int idx)
{
    unsigned flag = 0;
    if (t->mF4 == 1) {
        int v = t->mC00;
        flag = (unsigned)~v >> 31;
    }
    if (flag == 1) {
        int i = 0;
        do {
            if (lbl_805B10B4[idx].m80[i] == 1 && t->mSlots[i].m0 == 1 && t->mSlots[i].m4 == 1
                && lbl_805B09F4[i].mD4 != -1) {
                fn_8005C384(fn_8005BA9C(), i);
            }
            i++;
        } while (i <= 7);
        fn_80048DA4(&t->mFC);
    }
}

int fn_800480FC(Unk8004763C* t)
{
    int total = 0;
    int i;
    for (i = 0; i < 8; i++) {
        int found = 0;
        int k;
        for (k = 0; k < 8; k++) {
            if (lbl_805B10B4[k].m80[i] == 1) {
                found = 1;
                break;
            }
        }
        if (found == 1) {
            const char* name = lbl_805B0A09 + i * 0xD8;
            int ok = fn_802B96C4(name, 0);
            if (ok == 0) {
                t->mSlots[i].m0 = ok;
                t->mSlots[i].m10 = -1;
            } else {
                const char* buf = 0;
                const char* cur = 0;
                unsigned len = 0;
                int dummy;
                int n = 0;
                if (fn_80329DF0(name, &buf, &len) != 0) {
                    if (len != 0) {
                        cur = buf;
                        do {
                            n++;
                            fn_80329C4C(&cur, &len, &dummy, 0, 1000000000, 0x2C);
                            fn_80329C4C(&cur, &len, &dummy, 0, 1000000000, 0x2C);
                        } while (len != 0);
                        fn_80329E50(buf);
                    }
                    t->mSlots[i].m10 = n - 1;
                    t->mSlots[i].m14 = total;
                    total += t->mSlots[i].m10;
                }
            }
        }
    }
    return total;
}

/* near-miss: 8 slots differ (fail/i callee-saved registers swapped: retail fail=r27, i=r26; tail layout) */
int fn_80048294(Unk8004763C* t, int idx)
{
    int any = 0;
    int i = 0;
    int fail = 0;
    do {
        if (lbl_805B10B4[idx].m80[i] == 1) {
            int s0 = t->mSlots[i].m0;
            if (s0 != 0) {
                int rr;
                if (t->mSlots[i].m4 == 1) {
                    any = 1;
                } else if (s0 == 1 && t->mSlots[i].mC != 0
                           && (rr = fn_800484A8(t, i), t->mSlots[i].m0 != 0 && rr > 0)) {
                    t->mSlots[i].m4 = s0;
                    any = 1;
                } else {
                    fail = 1;
                }
            } else {
                fail = 1;
            }
        }
        i++;
    } while (i <= 7);
    int r = -2;
    if (any != 0 || fail != 1)
        r = fail ^ 1;
    return r;
}

/* near-miss: 1 slot differs (lwzx r4,r9,r27 vs r4,r27,r9 operand order for the lbl_805B0A95+0x23 word) */
int fn_8004838C(Unk8004763C* t, int idx)
{
    int sp8 = 0;
    int r = -2;
    int off = idx * 0xD8;
    char* p = lbl_805B0A95 + off;
    if (fn_802B96C4(p, 0) == 0) {
        t->mSlots[idx].m0 = 0;
    } else {
        int buf = fn_802B9300(p, 0x400, 0xE, &sp8);
        t->mSlots[idx].mC = buf;
        if (sp8 <= 0 || buf == 0) {
            t->mSlots[idx].m0 = 0;
            t->mSlots[idx].mC = 0;
        } else if (fn_80395250(buf, *(int*)(lbl_805B0A95 + 0x23 + off)) <= 0) {
            t->mSlots[idx].m0 = 0;
            fn_803EDA0C((void*)t->mSlots[idx].mC);
            t->mSlots[idx].mC = 0;
        } else {
            r = 1;
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

Unk80048A10_Sub* fn_80048A10(Unk80048A10_Sub* s)
{
    s->mAE0 = lbl_80649AB0;
    s->m9D8 = -1;
    s->m9DC = -1;
    s->m9E0 = -1;
    s->m9E4 = 0.0f;
    s->m9E8 = 0.0f;
    s->m9EC = 90.0f;
    s->m9F0 = 0.0f;
    s->m9F4 = 1;
    s->m9FC = 0;
    s->mA00 = 0;
    s->mA20 = 0;
    s->mA24 = 0;
    s->mA2C = 0;
    s->mA30 = 0;
    s->mA34 = 0;
    s->mA40 = 0;
    s->mA44 = 0;
    s->mA48 = 0;
    s->mA4C = 0;
    s->mA50 = 0;
    s->mA54 = 0;
    s->mA58 = 0;
    s->mA5C = 0;
    s->mA60 = 0;
    s->mA64 = 0;
    s->mA68 = 0;
    s->mA6C = 0;
    s->mA70 = 0;
    s->mA74 = 0;
    s->mA78 = 0;
    s->mA7C = 0;
    s->mA8C = 1;
    s->mA80 = 0;
    s->mA90 = 0;
    s->mA9C = 0;
    s->mADC = 0;
    s->mA9C = fn_80057370(operator new(0x110, 0), s);
    s->mADC = (Unk80048B2C_Obj*)new (0) Unk800652F4;
    fn_803EE7BC();
    fn_80048C08(s);
    return s;
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

void fn_80048C08(Unk80048A10_Sub* s)
{
    s->mAD0 = 0;
    s->mACC = 0;
    s->m9FC = 0;
    s->mA00 = 0;
    s->m9F4 = 1;
    s->mA20 = 0;
    s->mA24 = 0;
    s->mA2C = 0;
    s->mA30 = 0;
    s->mA34 = 0;
    s->mA40 = 0;
    s->mA44 = 0;
    s->mA48 = 0;
    s->mA4C = 0;
    s->mA50 = 0;
    s->mA54 = 0;
    s->m9D8 = -1;
    s->m9DC = -1;
    s->m9E0 = -1;
    s->mA58 = (unsigned)fn_8040ABA0() % 6;
    s->mA5C = 0;
    s->mA60 = 0;
    s->mA64 = 0;
    s->mA68 = 0;
    s->mA6C = 0;
    s->mA70 = 0;
    s->mA74 = 0;
    s->mA78 = 0;
    s->mA7C = 0;
    s->mA80 = 0;
    s->mA88 = 1;
    s->mA90 = 0;
    s->m9F8 = 0;
    s->mA04 = 0;
    s->mAC0 = 0;
    s->mA8C = 1;
    s->mA94 = 0;
    s->mAC4 = 0;
    s->mAC8 = 0;
    for (int i = 0; i < 35; i++) {
        s->mEnt[i].m0 = -1;
        s->mEnt[i].m38 = 0;
        s->mEnt[i].m3C = 0;
        s->mEnt[i].m40 = 0.0f;
        s->mEnt[i].m44 = 0;
    }
    for (int i = 0; i < 2; i++) {
        s->mA0C[i] = 0;
        s->mA38[i] = 0;
    }
    for (int i = 0; i < 3; i++)
        s->mA14[i] = 0;
    fn_80057A4C(s->mA9C);
    fn_800449D8();
    ((Unk800652F4*)s->mADC)->fn_80065338();
    s->mAD8 = -1;
    s->mAD4 = -1;
}

void fn_80048DA4(Unk80048A10_Sub* s)
{
    int i;
    for (i = 0; i < 35; i++) {
        if (s->mEnt[i].m44 == 1) {
            if (!(s->mEnt[i].m40 > (float)*(unsigned*)(s->mEnt[i].m3C + 0x48) * 0.016666668f))
                fn_80048F84(s, i, s->mEnt[i].m38);
        }
    }
}

/* near-miss: 4 slots differ (stfs f1 placement after the increment; `add r3,r3,r31` operand order) */
int fn_80048E50(Unk80048A10_Sub* s, unsigned id, float f, int* a, void* b, void* w)
{
    int n = s->m9E0;
    n++;
    if (n > 34)
        n = 0;
    s->m9E0 = n;
    if (id <= 0x88) {
        s->mEnt[n].m0 = id;
        fn_8040B320(&s->mEnt[s->m9E0].m4, 0, 0x34);
        s->mEnt[s->m9E0].m4 = *(Unk80048A10_Blk*)a;
        s->mEnt[s->m9E0].m38 = (int)b;
        s->mEnt[s->m9E0].m3C = (int)w;
        s->mEnt[s->m9E0].m40 = f;
        s->mEnt[s->m9E0].m44 = 1;
        return 1;
    }
    return 0;
}

void fn_80048F84(Unk80048A10_Sub* s, int i, int v)
{
    Unk8004763C* t = fn_800475EC();
    unsigned flag = 0;
    if (t->mF4 == 1) {
        int c = t->mC00;
        flag = (unsigned)~c >> 31;
    }
    if (flag == 1) {
        int k = 0;
        do {
            if (lbl_8061780C[k].key == s->mEnt[i].m0) {
                (((Unk8061780C_Cls*)s)->*lbl_8061780C[k].fn)(i, v);
                break;
            }
            k++;
        } while (k <= 124);
    }
    s->mEnt[i].m44 = 0;
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
