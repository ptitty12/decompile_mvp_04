/*
 * Database overlay code, .database_codeoverlay 0x8059377C-0x805942E0 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_80584CBC.h"

extern "C" int fn_80593E7C(Db80593CD0_Data* self, int i);
extern "C" void fn_805942A8(Db80593CD0_Data* self);
extern "C" int fn_805937A4(Db805937A4_Mgr* m, int id);
extern "C" Db80593CD0_P* fn_80593CD0(Db80593CD0_P* self, Db805937A4_Mgr* m, int b, int n, int c, float f);
extern const char lbl_80682960[];
extern "C" void fn_80593B78(Db80593CD0_Data* self, int i, int a, int b, int c, int d, int e, float f0, float f1);
extern "C" void fn_80594250(Db80593CD0_Data* self, int i, int a, int b, int c, float f0, float f1);
extern const char lbl_80683A88[];
extern void* lbl_8061930C;
void fn_80079FC0(void* self, char** cursor, void* dst, int n);
extern "C" void fn_805919E8(Db805937A4_Mgr* m, int x, int i, int k, float v);
extern "C" void fn_80591AF4(Db805937A4_Mgr* m, int x, int i, int k, float v);

extern "C" DB_OVERLAY int fn_8059377C(Db805937A4_Mgr* m, int id)
{
    return fn_805937A4(m, id) >= 0;
}

extern "C" DB_OVERLAY int fn_805937A4(Db805937A4_Mgr* m, int id)
{
    int r = -1;
    int i = 0;
    if (fn_800A2EB4(lbl_80619948) == 0) {
        for (; i <= m->m12B70; i++) {
            if (id == m->a[i].m0) {
                r = i;
                break;
            }
        }
    } else {
        for (; i <= m->m12B74; i++) {
            if (id == m->b[i].m0) {
                r = i;
                break;
            }
        }
    }
    return r;
}

extern "C" DB_OVERLAY unsigned char fn_80593880(Db805937A4_Mgr* m, int id)
{
    int i = fn_805937A4(m, id);
    if (fn_800A2EB4(lbl_80619948) == 0)
        return m->a[i].mC;
    return m->b[i].mC;
}

extern "C" DB_OVERLAY float fn_805938E8(Db805937A4_Mgr* m, int id)
{
    int i = fn_805937A4(m, id);
    if (fn_800A2EB4(lbl_80619948) == 0)
        return m->a[i].m8;
    return m->b[i].m8;
}

extern "C" DB_OVERLAY int fn_8059394C(Db805937A4_Mgr* m, int id)
{
    int i = fn_805937A4(m, id);
    if (fn_800A2EB4(lbl_80619948) == 0)
        return m->a[i].m4;
    return m->b[i].m4;
}

extern "C" DB_OVERLAY int fn_805939B0(Db805937A4_Mgr* m)
{
    if (fn_800A2EB4(lbl_80619948) != 0)
        return m->m12B8C;
    return m->m12B88;
}

extern "C" DB_OVERLAY Db80593CD0_P* fn_80593A00(Db80593CD0_P* self, Db805937A4_Mgr* m, int c, float f)
{
    fn_80593CD0(self, m, 8, 6, c, f);
    self->m1C = lbl_80682960;
    fn_80593B78(self, 0, 0x5750, 1, 1, 0x32, 0x5751, 250000.0f, 125000.0f);
    fn_80593B78(self, 1, 0x5752, 1, 1, 0x32, 0x5753, 250000.0f, 125000.0f);
    fn_80593B78(self, 2, 0x5754, 1, 1, 0x32, 0x5755, 250000.0f, 125000.0f);
    fn_80593B78(self, 3, 0x5756, 1, 1, 0x32, 0x5757, 250000.0f, 125000.0f);
    fn_80593B78(self, 4, 0x5758, 1, 1, 0x32, 0x5759, 250000.0f, 125000.0f);
    fn_80593B78(self, 5, 0x575A, 1, 1, 0x32, 0x575B, 250000.0f, 125000.0f);
    return self;
}

extern "C" DB_OVERLAY void fn_80593B48(Db80593CD0_Data* self)
{
    fn_805942A8(self);
}

extern "C" DB_OVERLAY char* fn_80593B68(char* self, int i)
{
    return self + (i * 8 + 0x20);
}

extern "C" DB_OVERLAY void fn_80593B78(Db80593CD0_Data* self, int i, int a, int b, int c, int d, int e, float f0, float f1)
{
    fn_80594250(self, i, a, b, c, f0, f1);
    int o = i * 8;
    int* p = (int*)((char*)self + 0x20);
    int* q = (int*)((char*)self + 0x24);
    *(int*)((char*)p + o) = e;
    *(int*)((char*)q + o) = d;
}

extern "C" DB_OVERLAY float fn_80593BD4(Db80593CD0_Data* self)
{
    float a = 0.1666666716337204f;
    float b = 0.0f;
    float c;
    float lo;
    float x;
    float hi;
    int cnt = 0;
    int k = 0;
    do {
        if (fn_80593E7C(self, k) > 0)
            cnt++;
        k++;
    } while (k <= 5);
    b = cnt * 0.1666666716337204f;
    x = b;
    hi = 1.0f;
    c = x <? hi;
    lo = 0.0f;
    b = lo >? c;
    return b;
}

extern "C" DB_OVERLAY Db80593CD0_P* fn_80593CD0(Db80593CD0_P* self, Db805937A4_Mgr* m, int b, int n, int c, float f)
{
    self->m0 = m;
    self->m14 = n;
    self->m1C = lbl_80683A88;
    self->m4 = b;
    self->m8 = f;
    self->mC = c;
    self->m10 = 0;
    self->m18 = 0;
    self->m10 = new (0) Db80593CD0_Ent[n];
    if (self->m18 == 0)
        self->m18 = (int*)operator new[](self->m14 * 4, 0);
    self->Clear();
    return self;
}

extern "C" DB_OVERLAY void fn_80593DD8(Db80593CD0_P* self, int chrg)
{
    self->m1C = lbl_80683A88;
    self->m0 = 0;
    if (self->m10) {
        delete[] self->m10;
        self->m10 = 0;
    }
    if (self->m18) {
        delete[] self->m18;
        self->m18 = 0;
    }
    if (chrg & 1)
        delete self;
}

extern "C" DB_OVERLAY float fn_80593E50(Db80593CD0_Data* self, int i)
{
    return self->m10[i].m0 * self->m8;
}

extern "C" DB_OVERLAY int fn_80593E68(Db80593CD0_Data* self, int i)
{
    return self->m10[i].mC;
}

extern "C" DB_OVERLAY int fn_80593E7C(Db80593CD0_Data* self, int i)
{
    return self->m18[i];
}

extern "C" DB_OVERLAY int fn_80593E8C(Db80593CD0_Data* self, int i)
{
    return self->m10[i].m8 - self->m18[i];
}

extern "C" DB_OVERLAY int fn_80593EB0(Db80593CD0_Data* self, int i, int n)
{
    int r = 0;
    if (self->m0->m12B78 + 0.1f >= self->m10[i].m0 * (float)n || !(self->m10[i].m0 * (float)n > 0.0f))
        r = 1;
    return r;
}

/* near-miss (2 slots): retail loads f1 for the second fn_805919E8 call before r4 (lwz). */
extern "C" DB_OVERLAY void fn_80593F30(Db80593CD0_Data* self, int i, int n, float f0, float f1)
{
    float a = f0 * (float)n;
    if (!(a >= 0.0f))
        a = self->m10[i].m0 * (float)n;
    float b = f1 * (float)n;
    if (!(b >= 0.0f))
        b = self->m10[i].m4 * (float)n;
    fn_805919E8(self->m0, self->m4, i, 0, a);
    fn_805919E8(self->m0, self->m4, i, 1, b);
    self->m18[i] += n;
}

/* near-miss (2 slots): same f1-before-r4 order in the second fn_80591AF4 call. */
extern "C" DB_OVERLAY void fn_8059403C(Db80593CD0_Data* self, int i, int n)
{
    float a = self->m10[i].m0 * self->m8 * (float)n;
    float b = self->m10[i].m4 * (float)n;
    fn_80591AF4(self->m0, self->m4, i, 0, a);
    fn_80591AF4(self->m0, self->m4, i, 1, b);
    self->m18[i] -= n;
}

extern "C" DB_OVERLAY float fn_80594100(Db80593CD0_Data* self, int i, int n)
{
    return self->m10[i].m0 * self->m8 * n;
}

extern "C" DB_OVERLAY void fn_80594148(Db80593CD0_Data* self, int a, Unk80070DDC_Stream* io)
{
    int r = io->v10();
    if (r == 0) {
        int n = r;
        fn_80079FC0(lbl_8061930C, (char**)a, &n, 4);
        if (io->m0 == 0)
            self->m14 = n;
        io->v08(a, self->m18, n * 4);
    } else {
        io->v08(a, &self->m14, 4);
        io->v08(a, self->m18, self->m14 * 4);
    }
}

extern "C" DB_OVERLAY Db80593CD0_Ent* fn_80594240(Db80593CD0_Data* self, int i)
{
    return self->m10 + i;
}

extern "C" DB_OVERLAY void fn_80594250(Db80593CD0_Data* self, int i, int a, int b, int c, float f0, float f1)
{
    self->m10[i].mC = c;
    self->m10[i].m0 = f0;
    self->m10[i].m4 = f1;
    self->m10[i].m8 = b;
    self->m10[i].m10 = a;
}

extern "C" DB_OVERLAY void fn_805942A8(Db80593CD0_Data* self)
{
    int i = 0;
    if (i < self->m14) {
        int off = 0;
        do {
            *(int*)(off + (int)self->m18) = 0;
            i++;
            off += 4;
        } while (i < self->m14);
    }
}
