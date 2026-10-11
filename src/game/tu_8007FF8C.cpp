/*
 * Game code, .text 0x8007FF8C-0x80082248 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8007FF8C.h"

typedef Unk8007FF8C_G G;
typedef Unk8007FF8C_EI EI;
typedef Unk8007FF8C_List List;
typedef Unk8007FF8C_Item Item;
typedef Unk8007FF8C_Slot Slot;

void fn_8059A490(EI* p);
void fn_8059A4B4(EI* p);
void fn_8059A4D8(EI* p);
void fn_8059A4FC(EI* p);
void fn_8052DEE8(List* l);
void fn_8052DFDC(List* l);
void fn_8052DE9C(List* l);
void fn_8052A404(Slot* s, float f, int x);
void fn_8052A894(Slot* s, int x);
void fn_8059AB5C(void* p);
void fn_8059AB6C(void* p);
void fn_80329FA0(Unk8007FF8C_Pair* out, unsigned short v, ...);

int fn_8007FF8C(G* self)
{
    return self->m1C->m800;
}

void fn_8007FF98(G* self)
{
    fn_8059A490(self->m1C);
}

void fn_8007FFBC(G* self)
{
    fn_8059A4B4(self->m1C);
}

void fn_8007FFE0(G* self)
{
    fn_8059A4D8(self->m1C);
}

void fn_80080004(G* self)
{
    fn_8059A4FC(self->m1C);
}

void fn_80080028(G* self)
{
    fn_8052DEE8(self->m20);
}

void fn_8008004C(G* self)
{
    fn_8052DFDC(self->m20);
}

unsigned fn_80080070(G* self)
{
    return self->m20->m0;
}

Item* fn_8008007C(G* self, unsigned i)
{
    List* l = self->m20;
    return i < l->m0 ? &l->m4[i] : 0;
}

void fn_800800A4(G* self)
{
    fn_8052DE9C(self->m20);
}

void fn_800800C8(G* self, unsigned i, float f, int x)
{
    Slot* b = self->m24;
    fn_8052A404(i <= 0x18 ? &b[i] : 0, f, x);
}

void fn_80080110(G* self, unsigned i, int x)
{
    Slot* b = self->m24;
    fn_8052A894(i <= 0x18 ? &b[i] : 0, x);
}

void fn_80080150(G* self)
{
    fn_8059AB5C(self->m28);
}

void fn_80080174(G* self)
{
    fn_8059AB6C(self->m28);
}

unsigned short fn_80080198(G* self)
{
    unsigned short r = 0x7D5;
    if (self->mC) {
        Unk8007FF8C_Pair tmp;
        fn_80329FA0(&tmp, *self->mC->m8);
        r = tmp.b;
    }
    return r;
}

int fn_800801DC(G* self, int x)
{
    int r = 0;
    switch (x) {
    case 0:
    case 1:
        if (self->m1F0 == 1 && x == 0)
            r = 1;
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}

void* operator new[](unsigned int size, int heap); /* 0x803774A8 */

typedef Unk8007FF8C_Y Y;
typedef Unk8007FF8C_Q Q;
typedef Unk8007FF8C_Z Z;
typedef Unk8007FF8C_Node Node;
typedef Unk8007FF8C_I I;
typedef Unk8007FF8C_W W;

unsigned fn_8007F198(void* self, int a);
int fn_8007F24C(void* self, int a, int i);
int fn_8007A6A0(void* self, int x, int v);
int fn_8007A6A0(void* self, int x);
void fn_8007A808(void* self, int x, int b, int v);
int fn_8007AA10(void* self, int b);
extern int lbl_805B62C8[];
extern int lbl_805B62E0[];

int fn_8008021C(void* self, int a, int skip, int lvl)
{
    for (unsigned char i = 0; i < fn_8007F198(self, a); i++) {
        int v = fn_8007F24C(self, a, i);
        if (v != 0 && v != skip && fn_8007A6A0(self, 4, v) == lvl)
            return v;
    }
    return 0;
}

static inline int Used(void* self, int a, int n)
{
    return fn_8008021C(self, a, 0, n) != 0;
}

int fn_800802B8(void* self, int a, int x)
{
    int i;
    for (i = x + 1; i <= 99; i++) {
        if (!Used(self, a, i))
            return i;
    }
    for (i = x - 1; i >= 0; i--) {
        if (!Used(self, a, i))
            return i;
    }
    return x;
}

/* near-miss: same code; retail keeps a, b and the level in r28, r30, r29. */
void fn_80080374(void* self, int a, int b)
{
    int lvl = fn_8007A6A0(self, 4);
    if (fn_8008021C(self, a, b, lvl)) {
        int n = fn_800802B8(self, a, lvl);
        fn_8007A808(self, 4, b, n);
    }
}

int fn_800803F0(void* self, int a, int b)
{
    int v = fn_8007AA10(self, b);
    if (v <= 59) {
        int r = a - lbl_805B62C8[v / 10];
        if (r < 0)
            r = 0;
        a = r;
    }
    return a;
}

int fn_80080464(void* self, int a, int b)
{
    int v = fn_8007AA10(self, b);
    if (v <= 59) {
        int r = a - lbl_805B62E0[v / 10];
        if (r < 0)
            r = 0;
        a = r;
    }
    return a;
}

void fn_80071604(I* self);
void fn_80071688(I* self, int flags);
void* fn_8007366C(const char* a, const char* b);
void fn_8040074C(void* p, int n);
extern char lbl_8064AFE8[];
extern char lbl_805B3B4C[];
extern char lbl_805B40B8[];

I* fn_800805FC(I* self)
{
    fn_80071604(self);
    self->m20 = lbl_8064AFE8;
    self->m24 = 0;
    W* p = new (0) W[self->m1C];
    self->m24 = p;
    fn_8040074C(p, self->m1C * 4);
    self->m14 = fn_8007366C(lbl_805B3B4C, lbl_805B40B8);
    return self;
}

void fn_8008067C(I* self, int flags)
{
    self->m20 = lbl_8064AFE8;
    if (self->m24) {
        delete[] self->m24;
        self->m24 = 0;
    }
    fn_80071688(self, flags);
}

void fn_800806D8(I* self, unsigned i)
{
    if (i < self->m1C)
        fn_8040074C(&self->m24[i], 4);
}

int fn_80080714(void* self)
{
    return 0;
}

int fn_8008071C(void* self)
{
    return 0;
}

void fn_80071E2C(I* self);
extern float lbl_805B40D0;

/* Entry of the vtable behind Unk8007FF8C_I::m20 at +0x28: a this-adjustment
 * (halfword) and a function pointer. */
static inline int CallSlot(I* self, int k, int a)
{
    Unk8007FF8C_VT2* vt = (Unk8007FF8C_VT2*)self->m20;
    return vt->pfn((char*)self + vt->delta, k, a);
}

float fn_800808F8(I* self, int arg)
{
    float a = (float)CallSlot(self, 0, arg);
    float b = (float)CallSlot(self, 2, arg);
    float c = (float)CallSlot(self, 1, arg);
    float s = a + b + c;
    return s;
}

float fn_80080A08(I* self, int arg)
{
    float a = (float)CallSlot(self, 0, arg);
    float b = (float)CallSlot(self, 2, arg);
    float c = (float)CallSlot(self, 1, arg);
    float total;
    float r = lbl_805B40D0;
    total = a + b + c;
    if (!(total <= lbl_805B40D0))
        r = (a + b) / total;
    return r;
}

/* near-miss: same code, but retail keeps self, obj and a in r29, r30, r28. */
void fn_80080B3C(I* self, int a, Unk8007FF8C_VObj* obj)
{
    fn_80071E2C(self);
    Unk8007FF8C_VT* vt = obj->m4;
    vt->pfn((char*)obj + vt->delta, a, self->m24, self->m1C * 4);
}

unsigned fn_80080724(I* self, unsigned t, unsigned i)
{
    unsigned r = 0;
    if (i < self->m1C) {
        switch (t) {
        case 0: r = self->m24[i].a; break;
        case 1: r = self->m24[i].b; break;
        case 2: r = self->m24[i].c; break;
        }
    }
    return r;
}

void fn_80080828(I* self, unsigned t, unsigned i, int v)
{
    if (i >= self->m1C)
        return;
    switch (t) {
    case 0: {
        W* w = (W*)(i * 4 + (int)self->m24);
        if (!(v > 0x7FF)) { if (v < 0) v = 0; } else v = 0x7FF;
        w->a = v;
        break;
    }
    case 1: {
        W* w = (W*)(i * 4 + (int)self->m24);
        if (!(v > 0x3F)) { if (v < 0) v = 0; } else v = 0x3F;
        w->b = v;
        break;
    }
    case 2: {
        W* w = (W*)(i * 4 + (int)self->m24);
        int c;
        if (!(v > 0x3FF)) { c = v; if (c < 0) c = 0; } else c = 0x3FF;
        w->c = c;
        break;
    }
    }
}

void fn_80080B98(Q* q)
{
    q->m8 = 0;
    q->m4 = 0;
    q->m0 = 0xFF;
    q->m1 = 0xFF;
}

void fn_80080BB4(Q* q, int a, int b, int c)
{
    q->m8 = 0;
    q->m4 = c;
    q->m0 = a;
    q->m1 = b;
    if (a > 0x1C && a != 0xFF)
        q->m0 = 0xFF;
    if (b > 0x1C && b != 0xFF)
        q->m1 = 0xFF;
}

void fn_80096AB4(void* p);
void fn_80096C10(void* p);
void fn_8009C398(void* p);
void fn_800999CC(void* p, int v);
void fn_80082034(Y* self);
extern float lbl_805B40D4;

/* near-miss: two slots (an iterator init store is scheduled before the byte
 * stores here, after them in retail). */
void fn_80080BFC(Y* self)
{
    Unk8007FF8C_Iter<1> it1;
    int k = 0;
    do {
        fn_80096AB4((char*)self + k * 0xE64);
        k = it1.Next();
    } while (k <= 1);
    self->m1D50 = 0;
    self->m1D40 = 2;
    self->m1D44 = lbl_805B40D4;
    self->m1D48 = lbl_805B40D4;
    self->m1D4C = lbl_805B40D4;
    fn_80082034(self);
    Z* z = &self->z1;
    z->b0 = 0;
    z->m8 = 1;
    z->b3 = 0;
    z->b2 = 0;
    z->b4 = 0;
    z->b5 = 0;
    z->b1 = 0;
    Unk8007FF8C_Iter<3> it2;
    k = 0;
    do {
        fn_80080B98(&z->q[k]);
        k = it2.Next();
    } while (k <= 3);
}

void fn_80080CEC(Y* self)
{
    {
        Unk8007FF8C_Iter<1> it;
        int k = 0;
        do {
            fn_80096C10((char*)self + k * 0xE64);
            k = it.Next();
        } while (k <= 1);
    }
    fn_80082034(self);
    self->z0 = self->z1;
}

void fn_80080DBC(Y* self)
{
    {
        Unk8007FF8C_Iter<1> it;
        int k = 0;
        do {
            fn_8009C398((char*)self + k * 0xE64);
            k = it.Next();
        } while (k <= 1);
    }
    self->z1 = self->z0;
}

void fn_80096204(void* p);
void fn_80096204(void* p, int x);
void fn_80096770(void* self, int a, int b, int c);
void fn_800966CC(void* self, int a, int b);
void fn_800965E8(void* self);
void fn_80096544(void* self, int a, int b, int c, float f);
void fn_80080BFC(Y* self);
Q* fn_80081CF8(Y* self, int i);
void fn_80081C94(Y* self, int i, int a, int b, int c);
void fn_80081D88(Y* self);
void fn_800810E8(Y* self);

void fn_80080E84(Y* self, int a, int b)
{
    fn_80096204((char*)self + 0x198);
    fn_80096204((char*)self + 0xFFC, b);
}

void fn_80080EC4(Y* self, int a, int b, int c, int d, float f)
{
    if (d == 0)
        fn_80080BFC(self);
    self->m1D48 = f;
    self->m1D4C = -f;
    fn_80096544(self, a, c, d, self->m1D48);
    fn_80096544((char*)self + 0xE64, b, c, d, self->m1D4C);
    if (c == 0) {
        fn_80081D88(self);
        fn_800810E8(self);
    }
}

void fn_80080F60(Y* self, int a, int b, int c)
{
    fn_80080BFC(self);
    fn_80096770(self, a, b, 0);
    fn_800966CC((char*)self + 0xE64, a, c);
}

void fn_80080FBC(Y* self, int a, int b)
{
    fn_80080BFC(self);
    fn_80096770(self, a, b, 1);
}

void fn_80081004(Y* self)
{
    fn_800965E8((char*)self + 0xE64);
}

void fn_80081028(Y* self, int a, int b, int c, int d)
{
    fn_80080BFC(self);
    fn_80096770(self, a, c, 1);
    fn_800966CC((char*)self + 0xE64, b, d);
}

void fn_80081088(Y* self, int a, int b, int c, int d)
{
    fn_80080BFC(self);
    fn_80096770(self, a, c, 1);
    fn_800966CC((char*)self + 0xE64, b, d);
}

int fn_80081B60(Y* self)
{
    switch (self->m164) {
    case 0:
    case 2:
        return 1;
    case 1:
    case 3:
    case 4:
        return 0;
    }
    return 0;
}

/* near-miss: r29/r30 are swapped for tab and q, one extra lwz. */
void fn_80081BA8(Y* self, int p, int q, int v)
{
    char* sub = (char*)self + p * 0xE64;
    char* tab = sub + 0x17C;
    int old = (unsigned char)tab[q];
    fn_800999CC(sub, v);
    if ((unsigned char)tab[q] == v) {
        int f = 0;
        if (self->z0.m8 != 0)
            f = 1;
        if (p == f) {
            Unk8007FF8C_Iter<3> it;
            int k = 0;
            do {
                if (fn_80081CF8(self, k)->m0 == old) {
                    int m4 = fn_80081CF8(self, it.i)->m4;
                    fn_80081C94(self, it.i, v, fn_80081CF8(self, it.i)->m1, m4);
                }
                k = it.Next();
            } while (k <= 3);
        }
    }
}

void fn_80081C94(Y* self, int i, int a, int b, int c)
{
    fn_80080BB4(&self->z0.q[i], a, b, c);
}

void fn_80081CCC(Y* self, int i)
{
    fn_80080B98(&self->z0.q[i]);
}

Q* fn_80081CF8(Y* self, int i)
{
    return &self->z0.q[i];
}

Q* fn_80081D08(Y* self, int i)
{
    return &self->z0.q[i];
}

void fn_80081D18(Y* self, int i, int j)
{
    Q* a = fn_80081CF8(self, i);
    Q* b = fn_80081CF8(self, j);
    fn_80080BB4(b, a->m0, a->m1, a->m4);
    fn_80080B98(a);
}

void fn_80081D70(Y* self)
{
    self->z0.b3 = 0;
    self->z0.b2 = 0;
    self->z0.b4 = 0;
    self->z0.b5 = 0;
}

/* near-miss: same iterator-init scheduling difference as fn_80080BFC. */
void fn_80082034(Y* self)
{
    Z* z = &self->z0;
    z->b0 = 0;
    z->m8 = 1;
    z->b5 = 0;
    z->b1 = 0;
    z->b3 = 0;
    z->b2 = 0;
    z->b4 = 0;
    {
        Unk8007FF8C_Iter<3> it;
        int k = 0;
        do {
            fn_80080B98(&z->q[k]);
            k = it.Next();
        } while (k <= 3);
    }
}

void fn_80082308(Node* n);

Node* fn_800820C0(Y* self, int a, int b, int c)
{
    for (Node* n = self->m14; n; n = n->m0) {
        if (n->h4 == a && n->b6 == b && n->c == c)
            return n;
    }
    return 0;
}

void fn_80082108(Y* self, Node* nn)
{
    if (self->m14) {
        Node* last = self->m14;
        int cnt = 1;
        while (last->m0 && last->m0->f) {
            last = last->m0;
            cnt++;
        }
        while (cnt > 5) {
            Node* h = self->m14;
            self->m14 = h->m0;
            if (h == last)
                last = 0;
            cnt--;
            fn_80082308(h);
        }
        if (last) {
            last->m0 = nn;
            nn->m0 = 0;
        } else {
            self->m14 = nn;
            nn->m0 = last;
        }
    } else {
        self->m14 = nn;
    }
}

void fn_80082200(Y* self);
void fn_80377408(void* p);

void fn_800821C0(Y* self, int flags)
{
    fn_80082200(self);
    if (flags & 1)
        fn_80377408(self);
}

void fn_80082200(Y* self)
{
    while (self->m14) {
        Node* n = self->m14;
        self->m14 = n->m0;
        fn_80082308(n);
    }
}
