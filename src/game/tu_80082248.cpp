/*
 * Game code, .text 0x80082248-0x80084910 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80082248.h"

typedef Unk80082248_Node Node;
typedef Unk80082248_Link Link;
typedef Unk80082248_Tree Tree;
typedef Unk80082248_Holder Holder;
typedef Unk80082248_Key Key;

void* operator new(unsigned int size, int heap);      /* 0x80377428 */
void* operator new[](unsigned int size, int heap);    /* 0x803774A8 */

extern Node lbl_8061932C;
extern char lbl_80649ED8[];
extern char lbl_80649F08[];
extern char* lbl_80619324;
extern int lbl_80619328;

void fn_8040B320(void* p, int v, int n);
void fn_80082200(Node* n);
void fn_80082510(Tree* t);
void fn_80082944(void* self, int a, Key* k);
Tree* fn_80082318(Tree* t);
void fn_80082DA8(Tree* t);

void fn_80082308(Link* l)
{
    l->m4 = l->m4 & ~1;
}

Tree* fn_80082318(Tree* self)
{
    self->m15F9C = lbl_80649ED8;
    self->m0 = &lbl_8061932C;
    self->m4 = &lbl_8061932C;
    self->m15F98 = 0;
    fn_80082510(self);
    return self;
}

void fn_800824D4(void* unused, Node* n)
{
    fn_80082200(n);
    n->mC = n->mC & ~1;
}

void fn_80082510(Tree* self)
{
    fn_8040B320(lbl_80619324, 0, 0x64000);
    lbl_80619328 = 0;
    fn_8040B320((char*)self + 8, 0, 0x15F90);
    self->m15F98 = 0;
    self->m0 = &lbl_8061932C;
    self->m4 = &lbl_8061932C;
}

/* near-miss: 21 instructions here, 30 in retail (the descent loop is laid out
 * with a second copy of the compare and of the cache store). */
void fn_80082F4C(Tree* t, int key)
{
    if (key == t->m4->m10)
        return;
    Node* n = t->m0;
    if (n == &lbl_8061932C)
        return;
    if (key == n->m10) {
        t->m4 = n;
        return;
    }
    while (1) {
        if (key < n->m10)
            n = n->m4;
        else
            n = n->m8;
        if (n == &lbl_8061932C)
            return;
        if (key == n->m10) {
            t->m4 = n;
            return;
        }
    }
}

int fn_80082FC4(Tree* t, Node* n)
{
    int c = 0;
    if (n->m4 != &lbl_8061932C)
        c = fn_80082FC4(t, n->m4);
    if (n != &lbl_8061932C)
        c++;
    if (n->m8 != &lbl_8061932C)
        c += fn_80082FC4(t, n->m8);
    return c;
}

void fn_80083258(void* self, int a, int h, int b, Key* k, int c)
{
    k->h4 = h;
    k->b6 = b;
    k->m0 = 0;
    k->c = c;
    fn_80082944(self, a, k);
}

void fn_8035300C();
void fn_80353110();

void fn_8008395C()
{
    fn_8035300C();
}

void fn_8008397C()
{
    fn_80353110();
}

int fn_80083AAC(short* a, short* b)
{
    if (*a > *b)
        return 1;
    if (*a < *b)
        return -1;
    return 0;
}

Holder* fn_80083BEC(Holder* self)
{
    self->m4 = lbl_80649F08;
    lbl_80619324 = new (0) char[0x64000];
    self->m0 = fn_80082318((Tree*)operator new(0x15FA0, 0));
    return self;
}

void fn_80083CEC(Holder* self)
{
    fn_80082DA8(self->m0);
}

void fn_80083DF4(Holder* self)
{
    fn_80082510(self->m0);
}

void fn_80083E84(int t, int* a, int* b)
{
    switch (t) {
    case 0: *a = t; *b = 1; break;
    case 1: *a = 2; *b = 3; break;
    case 2: *a = 4; *b = 6; break;
    case 3: *a = 7; *b = 9; break;
    default: *a = 0; *b = 1; break;
    }
}

void fn_80083EF8(int t, int* a, int* b)
{
    switch (t) {
    case 0: *a = t; *b = 5; break;
    case 1: *a = 6; *b = 12; break;
    case 2: *a = 13; *b = 18; break;
    case 3: *a = 19; *b = 24; break;
    default: *a = 0; *b = 5; break;
    }
}

int fn_80083F6C(int t)
{
    switch (t) {
    case 0: return 0x3FB7;
    case 1: return 0x3FB8;
    case 2: return 0x3FB9;
    case 3: return 0x5975;
    }
    return 0;
}

int fn_80083FC0(int t)
{
    switch (t) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return 0;
}

int fn_80084014(int t, int x)
{
    switch (t) {
    case 0: return x == 1;
    case 1: return 2;
    case 2: return 3;
    case 3: return 4;
    }
    return 1;
}

int fn_80084114(int t)
{
    switch (t) {
    case 0:
    case 1:
        return 0;
    case 2:
    case 3:
        return 1;
    case 4:
    case 5:
    case 6:
        return 2;
    case 7:
    case 8:
    case 9:
        return 3;
    case 10:
        return 0;
    }
    return 4;
}

int fn_800845E4(int t)
{
    if (t <= 2) {
        if (t >= 0)
            return 1;
    }
    return 0;
}

/* near-miss: retail compares with cmpwi r3,5 / bgelr; here the range test is
 * canonicalised to cmpwi r3,4 / bgtlr. */
int fn_80084600(int t)
{
    if (t <= 9) {
        if (t >= 5)
            return 1;
    }
    return 0;
}

int fn_8008461C(int t)
{
    return t == 6;
}

int fn_8008462C(int t)
{
    return t == 7;
}
