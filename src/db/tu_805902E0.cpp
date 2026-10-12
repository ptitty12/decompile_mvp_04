/*
 * Database overlay code, .database_codeoverlay 0x805902E0-0x8059377C (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_80584CBC.h"

struct Db80590EB4_S { Db805919E8_M* m0; char pad4[0x20]; int m24; };

struct Db80619948_G { char pad[0x84]; int m84; };

struct Db80590EB4_S2 { Db805919E8_M* m0; };

struct Db805909D4_S { Db805919E8_M* m0; char pad4[0x20]; int m24; int m28; int m2C; float m30[1]; };

struct Db8059124C_S { char pad[0x28]; void* m28; };

struct Db80590A4C_S {
    Db805919E8_M* m0;
    Db8058F924_V* m4;
    Db8058F924_V* m8;
    Db8058F924_V* mC;
    Db8058F924_V* m10;
    Db805942E0_V* m14;
    Db805942E0_V* m18;
    Db805942E0_V* m1C;
    int m20;
    int m24;
    void* m28;
    int m2C;
    float m30[30];
    int mA8;
    int mAC;
    int mB0;
    int mB4;
    float mB8;
    float mBC;
    int mC0;
};

extern "C" void fn_80591DEC(Db805919E8_M* m);
extern "C" float fn_805922D4(Db805919E8_M* m, int x, int i);
extern "C" float fn_80592288(Db805919E8_M* m, int x);
extern "C" Db800B555C_Obj* fn_800B555C();
extern "C" int fn_800B5758(Db800B555C_Obj* o);
extern "C" int fn_800A2E90(void* p);
extern "C" void fn_805921E4(Db805919E8_M* m);
extern Unk8007A4DC_Screen* lbl_8061930C;
int fn_8007F7D0(Unk8007F198_B* self, unsigned i);
extern "C" void fn_80591B40(Db805919E8_M* m, int x);
extern "C" void fn_805919E8(Db805919E8_M* m, int x, int i, int k, float f);
extern "C" float fn_80079CF8(Unk8007B2B0_Screen* s, int a);
extern "C" int fn_805560A8(int a, int b);
extern "C" void fn_805920BC(Db805919E8_M* m);
unsigned fn_8007FBC0(Unk8007F198_C* self, int a, int c);
int fn_8007FB2C(Unk8007F198_C* self, int idx);
extern "C" void fn_80596E3C(void* p);
extern "C" void fn_80596FCC(void* p);
extern "C" void fn_8059209C(Db805919E8_M* m, float f);
extern "C" void fn_80591D3C(Db805919E8_M* m);
extern "C" void fn_80596E00(void* p);
extern "C" void fn_80591FC8(Db805919E8_M* m);
extern "C" void fn_805913C0(Db80590A4C_S* s, int a);
extern "C" void fn_805907B8(Db80590A4C_S* s, int a);
extern "C" void fn_80590BA0(Db80590EB4_S2* s);
extern "C" void fn_80590C24(Db80590EB4_S2* s);

extern "C" DB_OVERLAY void fn_80590910(Db80590A4C_S* s)
{
    if (fn_800B5758(fn_800B555C()) == 1) {
        void* g = lbl_80619948;
        int t = fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0);
        s->m10->v48();
        fn_80591FC8(s->m0);
        if (fn_800A2E90(g) != 0) {
            fn_805913C0(s, 1);
            fn_80590BA0((Db80590EB4_S2*)s);
            fn_80590C24((Db80590EB4_S2*)s);
        }
        s->mB4 = 0;
        if (s->mC0 == 0)
            fn_805907B8(s, t);
    }
}

extern "C" DB_OVERLAY void fn_805909D4(Db805909D4_S* self)
{
    if (fn_800B5758(fn_800B555C()) == 1 && self->m24 != 0) {
        Db80329FA0_Out o = fn_80329FA0(self->m24);
        int t = o.m2 - 0x7D5;
        if (t >= 0)
            self->m30[t] = self->m0->m12B78;
    }
}

extern "C" DB_OVERLAY void fn_80590A48()
{
}

extern "C" DB_OVERLAY void fn_80590A4C(Db80590A4C_S* s)
{
    if (fn_800B5758(fn_800B555C()) == 1) {
        s->mB8 = 0.0f;
        s->mBC = 0.0f;
        for (int i = 0; i < 30; i++)
            s->m30[i] = 0.0f;
        fn_8059209C(s->m0, 0.0f);
        fn_80591D3C(s->m0);
        fn_80596E00(s->m28);
        s->m4->v28();
        s->mC->v28();
        s->m14->v18();
        s->m18->v18();
        s->m1C->v18();
        s->m8->v28();
        s->m10->v28();
        s->mC0 = 0;
        s->mB4 = 0;
    }
}

extern "C" DB_OVERLAY void fn_80590BA0(Db80590EB4_S2* self)
{
    if (fn_800B5758(fn_800B555C()) == 1) {
        Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
        int t = fn_8007F7D0((Unk8007F198_B*)s, 0);
        fn_80591B40(self->m0, 0);
        float f = fn_80079CF8(s, t);
        fn_805919E8(self->m0, 0, 0, 1, f);
    }
}

extern "C" DB_OVERLAY void fn_80590C24(Db80590EB4_S2* self)
{
    if (fn_800B5758(fn_800B555C()) == 1) {
        Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
        int t = fn_8007F7D0((Unk8007F198_B*)s, 0);
        fn_80591B40(self->m0, 1);
        float f = s->fn_80079BF8(t);
        fn_805919E8(self->m0, 1, 0, 1, f);
    }
}

extern "C" DB_OVERLAY void fn_80590EB4(Db80590EB4_S* self)
{
    if (fn_800B5758(fn_800B555C()) == 1) {
        Db80619948_G* g = (Db80619948_G*)lbl_80619948;
        int n = g->m84;
        if (n > self->m24) {
            do {
                if (fn_800A2E90(g) != 0 || fn_800A2EB4(g) != 0)
                    fn_805921E4(self->m0);
                self->m24++;
            } while (n > self->m24);
        }
    }
}

extern "C" DB_OVERLAY void fn_8059124C(Db8059124C_S* self)
{
    fn_80596E3C(self->m28);
}

extern "C" DB_OVERLAY void fn_80591378(Db8059124C_S* self)
{
    fn_80596FCC(self->m28);
}

extern "C" DB_OVERLAY float fn_8059139C(Db805909D4_S* self, int id)
{
    int t = id - 0x7D5;
    return t >= 0 ? self->m30[t] : 0.0f;
}

extern "C" DB_OVERLAY void fn_805919E8(Db805919E8_M* m, int x, int i, int k, float f)
{
    if (k != 0) {
        m->t0[x][i] = m->t0[x][i] + f;
        return;
    }
    m->t2[x][i] = m->t2[x][i] + f;
    m->m12B78 = m->m12B78 - f;
}

extern "C" DB_OVERLAY int fn_80591A50(Db805919E8_M* m)
{
    if (fn_800A2EB4(lbl_80619948) != 0)
        return m->m12B74;
    return m->m12B70;
}

extern "C" DB_OVERLAY int fn_80591AA0(Db805919E8_M* m)
{
    int r;
    if (fn_800A2EB4(lbl_80619948) == 0)
        r = m->m12B70;
    else
        r = m->m12B74;
    return r + 1;
}

extern "C" DB_OVERLAY void fn_80591AF4(Db805919E8_M* m, int x, int i, int k, float f)
{
    if (k != 0) {
        m->t0[x][i] = m->t0[x][i] - f;
        return;
    }
    m->m12B78 = m->m12B78 + f;
}

extern "C" DB_OVERLAY void fn_80591B40(Db805919E8_M* m, int x)
{
    for (int j = 0; j < 16; j++)
        m->t0[x][j] = 0.0f;
}

extern "C" DB_OVERLAY void fn_80591B6C(Db805919E8_M* m, int x, int i)
{
    char* b = (char*)m + 0x340;
    int o = i * 4 + (x << 6);
    *(float*)(b + o) = 0.0f;
}

/* near-miss (83 slots): retail folds the three field stores into separate base+offset forms and reloads m12B70 for each. */
extern "C" DB_OVERLAY void fn_80591B8C(Db805919E8_M* m, int x, int j, int a3, int a4, int flag, float f)
{
    if (flag != 0) {
        m->t1[x][j] = m->t1[x][j] + f;
        return;
    }
    if (fn_800A2EB4(lbl_80619948) == 0) {
        int o = j * 0xC + x * 0xC0;
        *(float*)((char*)m + 0x880 + (o + m->m12B70 * 0x300)) = f;
        *(int*)((char*)m + 0x884 + (o + m->m12B70 * 0x300)) = a3;
        *(int*)((char*)m + 0x888 + (o + m->m12B70 * 0x300)) = a4;
        m->m12B78 = f * (float)a4 + m->m12B78;
        return;
    }
    int o = j * 0xC + x * 0xC0;
    *(float*)((char*)m + 0x109C0 + (o + m->m12B74 * 0x300)) = f;
    *(int*)((char*)m + 0x109C4 + (o + m->m12B74 * 0x300)) = a3;
    *(int*)((char*)m + 0x109C8 + (o + m->m12B74 * 0x300)) = a4;
    m->m12B78 = f * (float)a4 + m->m12B78;
}

extern "C" DB_OVERLAY void fn_80591D3C(Db805919E8_M* m)
{
    int r, j;
    for (r = 0; r < 13; r++)
        for (j = 0; j < 16; j++)
            m->t0[r][j] = 0.0f;
    for (r = 0; r < 4; r++)
        for (j = 0; j < 16; j++)
            m->t1[r][j] = 0.0f;
    fn_80591DEC(m);
    m->m12B78 = m->m12B7C;
}

extern "C" DB_OVERLAY void fn_80591FC8(Db805919E8_M* m)
{
    int k = 0;
    fn_80591DEC(m);
    Unk8007F198_C* s = (Unk8007F198_C*)lbl_8061930C;
    int lo = fn_8007FBC0(s, 0, 0);
    int hi = fn_8007FBC0(s, fn_8007FB2C(s, 0) - 1, 0);
    do {
        int n = fn_8007FB2C(s, k);
        if (n > 0) {
            int v = fn_8007FBC0(s, 0, k);
            if (v < lo)
                lo = v;
            v = fn_8007FBC0(s, n - 1, k);
            if (v > hi)
                hi = v;
        }
        k++;
    } while (k <= 3);
    m->m12B80 = hi - lo + 1;
}

extern "C" DB_OVERLAY void fn_8059209C(Db805919E8_M* m, float f)
{
    m->m12B7C = f;
    m->m12B78 = f;
}

/* near-miss (62 slots): retail runs the outer 13/4-row loops on ctr (bdnz) and the 16-slot inner loops on an explicit counter. */
extern "C" DB_OVERLAY void fn_805920BC(Db805919E8_M* m)
{
    float t = 0.0f;
    int r = 0;
    int cr = 13;
    do {
        int o = r;
        int n = 16;
        do {
            t = *(float*)((char*)m + o) / (float)m->m12B80;
            *(float*)((char*)m + 0x440 + o) = *(float*)((char*)m + 0x440 + o) + t;
            o += 4;
            m->m12B78 = m->m12B78 - t;
            n--;
        } while (n != 0);
        r += 0x40;
        cr--;
    } while (cr != 0);
    float u = 0.0f;
    r = 0;
    cr = 4;
    do {
        int o = 0;
        int n = 16;
        do {
            int q = o + r;
            u = *(float*)((char*)m + 0x340 + q) / (float)m->m12B80;
            *(float*)((char*)m + 0x780 + q) = *(float*)((char*)m + 0x780 + q) + u;
            o += 4;
            n--;
            m->m12B78 = m->m12B78 + u;
        } while (n != 0);
        r += 0x40;
        cr--;
    } while (cr != 0);
}

extern "C" DB_OVERLAY void fn_805921E4(Db805919E8_M* m)
{
    if (fn_800A2E90(lbl_80619948) != 0) {
        fn_805920BC(m);
        int t = m->m12B84;
        if (t < m->m12B80)
            m->m12B84 = t + 1;
    } else if (fn_800A2EB4(lbl_80619948) != 0) {
        int r = fn_805560A8(fn_8007F7D0((Unk8007F198_B*)lbl_8061930C, 0), 0);
        if (r != 2 && r != 0)
            fn_805920BC(m);
    }
}

extern "C" DB_OVERLAY float fn_80592288(Db805919E8_M* m, int x)
{
    float s = 0.0f;
    for (int j = 0; j < 16; j++)
        s += m->t2[x][j];
    return s;
}

extern "C" DB_OVERLAY float fn_805922D4(Db805919E8_M* m, int x, int i)
{
    return m->t2[x][i];
}

/* near-miss (85 slots): retail walks the group pointers by +0x300 per step, as here, but keeps m in r31 with addis r28,r31,1 for the counters. */
extern "C" DB_OVERLAY float fn_80592474(Db805919E8_M* m, int x, int j)
{
    float r = 0.0f;
    int k = 0;
    int n = m->m12B70;
    if (n >= 0) {
        Db805922EC_Grp* g = m->a;
        do {
            k++;
            Db805922EC_Cell* c = &g->c[x][j];
            g++;
            r += c->m0 * (float)c->m8;
        } while (k <= n);
    }
    r += m->t3[x][j];
    if (fn_800A2EB4(lbl_80619948) != 0) {
        int n2 = m->m12B74;
        k = 0;
        if (n2 >= 0) {
            Db805922EC_Grp* g = m->b;
            do {
                k++;
                Db805922EC_Cell* c = &g->c[x][j];
                g++;
                r += c->m0 * (float)c->m8;
            } while (k <= n2);
        }
    }
    return r;
}

extern "C" DB_OVERLAY float fn_805925D0(Db805919E8_M* m, int x)
{
    float r = fn_80592288(m, x);
    float s = 0.0f;
    if (fn_800A2EB4(lbl_80619948) == 0) {
        for (int j = 0; j < 16; j++)
            s += m->t0[x][j] / (float)m->m12B80;
        r += s * (float)(m->m12B80 - m->m12B84);
    }
    return r;
}

extern "C" DB_OVERLAY float fn_805926B8(Db805919E8_M* m, int x, int i)
{
    float r = fn_805922D4(m, x, i);
    if (fn_800A2EB4(lbl_80619948) == 0) {
        float t = m->t0[x][i] / (float)m->m12B80;
        r += t * (float)(m->m12B80 - m->m12B84);
    }
    return r;
}

extern "C" DB_OVERLAY float fn_805929F0(Db805919E8_M* m, int x)
{
    float s = 0.0f;
    for (int j = 0; j < 16; j++)
        s += m->t0[x][j] / (float)m->m12B80;
    return s;
}

extern "C" DB_OVERLAY float fn_80592A68(Db805919E8_M* m, int x, int i)
{
    float r = m->t0[x][i] / (float)m->m12B80;
    return r;
}

extern "C" DB_OVERLAY float fn_80592B38(Db805919E8_M* m, int x, int i)
{
    char* b = (char*)m + 0x340;
    int o = i * 4 + (x << 6);
    float r = *(float*)(b + o) / (float)m->m12B80;
    return r;
}

extern "C" DB_OVERLAY int fn_80592E04(Db805937A4_Mgr* m, int i)
{
    if (fn_800A2EB4(lbl_80619948) == 0) {
        if (i >= 0 && i <= m->m12B70)
            return m->a[i].m0;
    } else {
        if (i >= 0 && i <= m->m12B74)
            return m->b[i].m0;
    }
    return -1;
}

extern "C" DB_OVERLAY char* fn_805932E4(char* m, int a, int b, int c)
{
    if (fn_800A2EB4(lbl_80619948) == 0)
        return m + (c * 0x300 + 0x880) + a * 0xC0 + b * 0xC;
    return m + (c * 0x300 + 0x109C0) + a * 0xC0 + b * 0xC;
}
