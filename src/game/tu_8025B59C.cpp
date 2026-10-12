/*
 * Game code, .text 0x8025B59C-0x8025F708 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8024EF40.h"

typedef Unk8024EF40_A A;
typedef Unk8024EF40_P P;
typedef Unk8024EF40_Q Q;
typedef Unk80256C80_M M;
typedef Unk80256C80_Inner I;

extern "C++" {
extern char lbl_806617E8[];
extern char lbl_80661800[];
struct Unk8025C960_F {
    float m0;
    int m4[4];
    Q* m14;
    int m18;
    int m1C;
};
typedef Unk8025C960_F F;
void fn_8025C998(F* self);
void fn_8025CAF0(F* self);
int fn_8025C9FC(F* self, P* p);
void fn_80259EC0(void* x, int a);
void fn_80377408(void* p);
int fn_8014E374(int a);
void fn_8025D0D4(I* i, int a, int b, int c);
struct Unk8025CF04_I {
    char pad0[0x18C];
    const void* m18C;
    char pad190[0x544 - 0x190];
    const void* m544;
};
void fn_8025E55C(I* self, P* p);
}

F* fn_8025C960(F* self, int a, int b)
{
    self->m14 = (Q*)a;
    self->m18 = b;
    fn_8025C998(self);
    return self;
}

void fn_8025C998(F* self)
{
    fn_8025CAF0(self);
}

void fn_8025C9B8(F* self)
{
    self->m0 = Secs(self->m14) ;
}

void fn_8025CAF0(F* self)
{
    self->m1C = 0;
    self->m0 = -1.0f;
    for (int i = 0; i < 4; i++)
        self->m4[i] = -1;
}

/* near-miss: self/p callee-saved registers swapped (retail self r31, p r30; no mr before the call) */
int fn_8025CBFC(F* self, P* p)
{
    if (p == 0 || fn_8025C9FC(self, p) == 0)
        return -1;
    return self->m4[p->m458 - 9];
}

/* near-miss: retail compares with cmpwi cr7,r3,11 + cror eq,gt + mfcr; ours folds x >= 11 into x > 10 (cmpwi 10 + rlwinm) */
int fn_8025CDD8(int x)
{
    int r = 0;
    if (x <= 0x10)
        r = x >= 0xB;
    return r;
}

void fn_8025CF04(Unk8025CF04_I* self, int a)
{
    self->m544 = lbl_806617E8;
    fn_80259EC0((char*)self + 0x468, 2);
    self->m18C = lbl_80661800;
    if (a & 1)
        fn_80377408(self);
}

struct Unk8025D054_I {
    char pad0[0x1FC];
    int m1FC;
    int m200;
};
void fn_8025D054(Unk8025D054_I* self, int a)
{
    int t = self->m1FC;
    if (self->m200 != t)
        self->m200 = t;
    self->m1FC = a;
}

void fn_8025D070(int self, int a, int* o1, int* o2)
{
    int t = fn_8014E374(a);
    *o1 = t;
    *o2 = fn_8014E374(t);
}

void fn_8025D0B0(I* self, int a, int b)
{
    fn_8025D0D4(self, a, b, a);
}

void fn_8025E55C(I* self, P* p)
{
    int found = 0;
    for (int i = 0; i < self->m448; i++) {
        if (found == 0) {
            if (self->m438[i] == p) {
                self->m438[i] = (P*)found;
                found = 1;
            }
        } else {
            self->m438[i - 1] = self->m438[i];
            self->m438[i] = 0;
        }
    }
    if (found != 0)
        self->m448 = self->m448 - 1;
}

/* near-miss: retail keeps two compares (ble 8; ble 12); ours folds the range test (28 vs 29 instructions) */
void fn_8025E5E0(I* self)
{
    int i = 0;
    if (self->m448 > 0) {
        do {
            P* p = self->m438[i];
            int t = p->m458;
            if (t <= 8 || t > 0xC)
                fn_8025E55C(self, p);
            i += 1;
        } while (i < self->m448);
    }
}

void fn_8025E654(I* self)
{
    self->m448 = 0;
    for (int i = 0; i < 4; i++)
        self->m438[i] = 0;
}

extern "C" void fn_8025E804(F* self);

extern "C" void fn_8025E7E4(F* self)
{
    fn_8025E804(self);
}
