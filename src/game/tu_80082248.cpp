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








void fn_8035300C();
void fn_80353110();

















void fn_80377408(void* p);

void fn_80082308(Link* l);
Tree* fn_80082318(Tree* self);
void fn_800824D4(void* unused, Node* n);
void fn_80082510(Tree* self);
Node* fn_80082F4C(Tree* t, int key);
int fn_80082FC4(Tree* t, Node* n);
void fn_80083258(void* self, int a, int h, int b, Key* k, int c);
void fn_8008395C();
void fn_8008397C();
int fn_80083AAC(short* a, short* b);
Holder* fn_80083BEC(Holder* self);
void fn_80083C54(Holder* self, int flags);
void fn_80083CEC(Holder* self);
void fn_80083DF4(Holder* self);
void fn_80083E84(int t, int* a, int* b);
void fn_80083EF8(int t, int* a, int* b);
int fn_80083F6C(int t);
int fn_80083FC0(int t);
int fn_80084014(int t, int x);
int fn_80084114(int t);
int fn_800845E4(int t);
int fn_80084600(int t);
int fn_8008461C(int t);
int fn_8008462C(int t);

void fn_80082308(Link* l);
Tree* fn_80082318(Tree* self);
void fn_800824D4(void* unused, Node* n);
void fn_80082510(Tree* self);
Node* fn_80082F4C(Tree* t, int key);
int fn_80082FC4(Tree* t, Node* n);
void fn_80083258(void* self, int a, int h, int b, Key* k, int c);
void fn_8008395C();
void fn_8008397C();
int fn_80083AAC(short* a, short* b);
Holder* fn_80083BEC(Holder* self);
void fn_80083C54(Holder* self, int flags);
void fn_80083CEC(Holder* self);
void fn_80083DF4(Holder* self);
void fn_80083E84(int t, int* a, int* b);
void fn_80083EF8(int t, int* a, int* b);
int fn_80083F6C(int t);
int fn_80083FC0(int t);
int fn_80084014(int t, int x);
int fn_80084114(int t);
int fn_800844A8(int t);
int fn_800845E4(int t);
int fn_80084600(int t);
int fn_8008461C(int t);
int fn_8008462C(int t);
int fn_80084660(int t);

typedef Unk80082248_Rec Rec;
typedef Unk80082248_V3 V3;

extern int lbl_8061930C;
extern const char* lbl_80622810;
extern const char* lbl_80622814;
unsigned fn_800736EC(const char* s);
int fn_8007A0D0(int h, int b);
Link* fn_800820C0(Node* n, int a, int b, int c);
int fn_80083778(Tree* t, int key, int a, int b, Rec* out, int mode);


#define RING_ENT ((Rec*)(lbl_80619324 + lbl_80619328 * 0x14))
#include "game/clampiter.h"
typedef Unk80082248_Stream Stream;
int fn_8008399C(Holder* h, int a, int b, int* out);
void fn_80083038(Tree* t, char** cursor, Node* root, Stream* s);
void fn_80083160(Tree* t, char** cursor, int v, Stream* s);
void fn_80083D10(Holder* self, char** cursor, Stream* s);
void fn_80079FC0(void* self, char** cursor, void* dst, int n);
int fn_80078A38(int self, int id);
const char* fn_802B9300(const char* s, int a, int b, unsigned int* outn);
void fn_802B961C(const char* p, int a);
extern char lbl_805B4254[];







extern "C" void fn_80400CE4(int a);
Rec* fn_80082248();


struct P8 {
    int a;
    int b;
};
extern P8 lbl_805B4244;
extern P8 lbl_805B424C;
void fn_80082A90(Node** root, Node** cur, P8* a, P8* b);


void fn_800826D0(Node** root, Node** cur, P8* a, P8* b);


extern "C" void fn_8040A208(void* base, int n, int size, int (*cmp)(short*, short*));
extern "C" void* fn_803774A8(unsigned size, int heap);


int fn_80072934(int self, unsigned char b);


Rec* fn_80082248()
{
    int start = lbl_80619328;
    while (RING_ENT->used) {
        lbl_80619328++;
        if (lbl_80619328 == 0x5000)
            lbl_80619328 = 0;
        if (lbl_80619328 == start)
            break;
    }
    RING_ENT->used = 1;
    RING_ENT->m0 = 0;
    RING_ENT->h4 = 0;
    RING_ENT->b6 = 0xff;
    RING_ENT->c = 0;
    RING_ENT->d = 0;
    return RING_ENT;
}

#undef RING_ENT

void fn_80082308(Link* l)
{
    l->m4 = l->m4 & ~1;
}

Tree* fn_80082318(Tree* self)
{
    *(void**)((char*)self + 0x15F9C) = lbl_80649ED8;
    self->m0 = &lbl_8061932C;
    self->m4 = &lbl_8061932C;
    self->m15F98 = 0;
    fn_80082510(self);
    return self;
}

/* Ring entry seen through its flag word (+0x14 from the tree base). */
struct RingV {
    char pad[0x14];
    unsigned f;
};
inline RingV* AtR(RingV* a, int i) { return &a[i]; }
Node* fn_8008241C(Tree* t)
{
    int start = t->m15F98;
    while ((AtR((RingV*)t, t->m15F98))->f & 1) {
        t->m15F98++;
        if (t->m15F98 == 0xEA6)
            t->m15F98 = 0;
        if (t->m15F98 == start)
            break;
    }
    (AtR((RingV*)t, t->m15F98))->f |= 1;
    t->m8[t->m15F98].m0 = 0;
    t->m8[t->m15F98].m4 = 0;
    t->m8[t->m15F98].m8 = 0;
    t->m8[t->m15F98].m14 = 0;
    return &t->m8[t->m15F98];
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

void fn_80082840(Node** root, Node** cur)
{
    P8 a;
    P8 b;
    while (*cur != *root && (((*cur)->m0->mC & ~1) == 2)) {
        Node* p = (*cur)->m0;
        if (p == p->m0->m4) {
            a = lbl_805B4244;
            b = lbl_805B424C;
            fn_800826D0(root, cur, &a, &b);
        } else {
            b = lbl_805B424C;
            a = lbl_805B4244;
            fn_800826D0(root, cur, &b, &a);
        }
    }
    (*root)->mC = (*root)->mC & 1;
}

void fn_80082CB0(Node** root, Node** cur)
{
    P8 a;
    P8 b;
    while (*cur != *root && ((*cur)->mC & ~1) == 0) {
        Node* x = *cur;
        if (x == x->m0->m4) {
            a = lbl_805B424C;
            b = lbl_805B4244;
            fn_80082A90(root, cur, &a, &b);
        } else {
            b = lbl_805B4244;
            a = lbl_805B424C;
            fn_80082A90(root, cur, &b, &a);
        }
    }
    (*cur)->mC = (*cur)->mC & 1;
}

Node* fn_80082F4C(Tree* t, int key)
{
    if (key == t->m4->m10)
        return t->m4;
    Node* n = t->m0;
    if (n == &lbl_8061932C)
        return n;
    if (key == n->m10) {
        t->m4 = n;
        return n;
    }
    while (key != n->m10) {
        if (key < n->m10)
            n = n->m4;
        else
            n = n->m8;
        if (n == &lbl_8061932C)
            return n;
    }
    t->m4 = n;
    return n;
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

void fn_80083038(Tree* t, char** cursor, Node* n, Stream* s)
{
    if (n->m4 != &lbl_8061932C)
        fn_80083038(t, cursor, n->m4, s);
    if (n != &lbl_8061932C) {
        Link* p = (Link*)n->m14;
        unsigned char cnt = 0;
        if (p != 0) {
            do {
                cnt++;
                p = p->m0;
            } while (p != 0);
        }
        p = (Link*)n->m14;
        s->v08(cursor, &n->m10, 4);
        s->v08(cursor, &cnt, 1);
        if (p != 0) {
            do {
                s->v08(cursor, p, 0x14);
                p = p->m0;
            } while (p != 0);
        }
    }
    if (n->m8 != &lbl_8061932C)
        fn_80083038(t, cursor, n->m8, s);
}

void fn_80083160(Tree* t, char** cursor, int count, Stream* s)
{
    if (count > 0) {
        int c = count;
        do {
            int key;
            unsigned char cnt;
            fn_80400CE4(0);
            s->v08(cursor, &key, 4);
            fn_80079FC0((void*)lbl_8061930C, cursor, &cnt, 1);
            for (int j = 0; j < cnt; j++) {
                Rec* r = fn_80082248();
                s->v08(cursor, r, 0x14);
                if (s->m0 == 0) {
                    r->m0 = 0;
                    fn_80082944(t, key, (Key*)r);
                }
            }
            c--;
        } while (c != 0);
    }
}

void fn_80083258(void* self, int a, int h, int b, Key* k, int c)
{
    k->h4 = h;
    k->b6 = b;
    k->m0 = 0;
    k->c = c;
    fn_80082944(self, a, k);
}

void fn_80083298(Holder* h, int key, int a, int b, V3* val)
{
    if (val->m0 != 0 || val->m4 != 0) {
        int id = fn_8007A0D0(lbl_8061930C, b);
        Node* n = fn_80082F4C(h->m0, key);
        Link* l;
        if (n != 0)
            l = fn_800820C0(n, a, id, 1);
        else
            l = 0;
        if (l == 0) {
            l = (Link*)fn_80082248();
            fn_80083258(h->m0, key, a, id, (Key*)l, 1);
        }
        *(V3*)((char*)l + 8) = *val;
    }
}

void fn_80083370(Holder* h, int key, int a, int b, V3* val)
{
    if (val->m0 != 0 || val->m4 != 0) {
        int id = fn_8007A0D0(lbl_8061930C, b);
        Node* n = fn_80082F4C(h->m0, key);
        Link* l;
        if (n != 0)
            l = fn_800820C0(n, a, id, 2);
        else
            l = 0;
        if (l == 0) {
            l = (Link*)fn_80082248();
            fn_80083258(h->m0, key, a, id, (Key*)l, 2);
        }
        *(V3*)((char*)l + 8) = *val;
    }
}

int fn_80083778(Tree* t, int key, int a, int b, Rec* out, int mode)
{
    Node* n;
    Link* l;
    while ((n = fn_80082F4C(t, key)) != &lbl_8061932C
           && (l = fn_800820C0(n, a, (unsigned char)fn_8007A0D0(lbl_8061930C, b), mode)) != 0) {
        *out = *(Rec*)l;
        return 1;
    }
    fn_8040B320(out, 0, 0x14);
    return 0;
}

void fn_80083838(Holder* h, int a, int b, int c, V3* out)
{
    Rec r;
    fn_80083778(h->m0, a, b, c, &r, 1);
    *out = *(V3*)&r.m8;
}

void fn_8008388C(Holder* h, int a, int b, int c, V3* out)
{
    Rec r;
    fn_80083778(h->m0, a, b, c, &r, 2);
    *out = *(V3*)&r.m8;
}

int fn_800838E0(Holder* h, int a, int b, int want, int* out)
{
    int n = fn_8008399C(h, a, b, out);
    for (int i = 0; i < n; i++) {
        if (out[i] != 0) {
            if (want != fn_80078A38(lbl_8061930C, out[i]))
                out[i] = 0;
        }
    }
    return n;
}

void fn_8008395C()
{
    fn_8035300C();
}

void fn_8008397C()
{
    fn_80353110();
}

int fn_8008399C(Holder* h, int key, int a, int* out)
{
    Node* n = fn_80082F4C(h->m0, key);
    if (n == &lbl_8061932C)
        return 0;
    int own = out == 0;
    if (own)
        out = (int*)fn_803774A8(0x200, 0);
    Key* l = (Key*)n->m14;
    int cnt = 0;
    if (l != 0) {
        int* w = out;
        do {
            if (l->h4 == a) {
                int id = fn_80072934(lbl_8061930C, l->b6);
                int found = 0;
                for (int j = cnt - 1; j >= 0; j--) {
                    if (out[j] == id) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    *w = id;
                    cnt++;
                    w++;
                }
            }
            l = *(Key**)l;
        } while (l != 0);
    }
    if (own && out)
        fn_80377408(out);
    return cnt;
}

int fn_80083AAC(short* a, short* b)
{
    if (*a > *b)
        return 1;
    if (*a < *b)
        return -1;
    return 0;
}

int fn_80083AD4(Holder* h, int key, unsigned short* out)
{
    Node* n = fn_80082F4C(h->m0, key);
    if (n == &lbl_8061932C)
        return 0;
    int own = out == 0;
    if (own)
        out = (unsigned short*)fn_803774A8(0x3C, 0);
    Key* l = (Key*)n->m14;
    int cnt = 0;
    if (l != 0) {
        unsigned short* w = out;
        do {
            int found = 0;
            for (int j = cnt - 1; j >= 0; j--) {
                if (out[j] == l->h4) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                cnt++;
                *w = l->h4;
                w++;
            }
            l = *(Key**)l;
        } while (l != 0);
    }
    fn_8040A208(out, cnt, 2, fn_80083AAC);
    if (own && out)
        fn_80377408(out);
    return cnt;
}

Holder* fn_80083BEC(Holder* self)
{
    self->m4 = lbl_80649F08;
    lbl_80619324 = new (0) char[0x64000];
    self->m0 = fn_80082318((Tree*)operator new(0x15FA0, 0));
    return self;
}

void fn_80083C54(Holder* self, int flags)
{
    self->m4 = lbl_80649F08;
    if (self->m0) {
        delete self->m0;
        self->m0 = 0;
    }
    if (lbl_80619324) {
        fn_80377408(lbl_80619324);
        lbl_80619324 = 0;
    }
    if (flags & 1)
        fn_80377408(self);
}

void fn_80083CEC(Holder* self)
{
    fn_80082DA8(self->m0);
}

void fn_80083D10(Holder* self, char** cursor, Stream* s)
{
    if (s->v10() == 1) {
        int n = fn_80082FC4(self->m0, self->m0->m0);
        s->v08(cursor, &n, 4);
        fn_80083038(self->m0, cursor, self->m0->m0, s);
        return;
    }
    if (s->m0 == 0)
        fn_80083DF4(self);
    int v = 0;
    fn_80079FC0((void*)lbl_8061930C, cursor, &v, 4);
    fn_80083160(self->m0, cursor, v, s);
}

void fn_80083DF4(Holder* self)
{
    fn_80082510(self->m0);
}

void fn_80083E18(Holder* self)
{
    char* buf = (char*)fn_802B9300(lbl_805B4254, 0x100, 4, 0);
    char* cur = buf;
    Stream s;
    fn_80083D10(self, &cur, &s);
    fn_802B961C(buf, 4);
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

int fn_80084070(int t)
{
    int hi = 0xB;
    int lo = 0xB;
    fn_80083E84(t, &lo, &hi);
    int r = 0;
    Unk8006A138_It<10> it(lo);
    int i = lo;
    while (i < hi) {
        r = r || fn_8008462C(i);
        i = it.Next();
    }
    return r;
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

void fn_80084170(int t, int* a, int* b)
{
    switch (t) {
    case 0: *a = t; *b = 2; break;
    case 1: *a = 3; *b = 5; break;
    case 2: *a = 6; *b = 8; break;
    case 3: *a = 9; *b = 12; break;
    case 4: *a = 13; *b = 14; break;
    case 5: *a = 15; *b = 16; break;
    case 6: *a = 17; *b = 18; break;
    case 7: *a = 19; *b = 20; break;
    case 8: *a = 21; *b = 22; break;
    case 9: *a = 23; *b = 24; break;
    default: *a = 0; *b = 5; break;
    }
}

int fn_80084268(int t)
{
    switch (t) {
    case 10:
        return 0x4065;
    case 0:
        return 0x1C3E;
    case 1:
        return 0x1C3F;
    case 2:
        return 0x2080;
    case 3:
        return 0x2081;
    case 4:
        return 0x2082;
    case 5:
        return 0x2083;
    case 6:
        return 0x2084;
    case 7:
        return 0x5979;
    case 8:
        return 0x597A;
    case 9:
        return 0x597B;
    default:
        return 0;
    }
}

int fn_80084338(int t)
{
    switch (t) {
    case 10:
        return 0x5CBC;
    case 0:
        return 0x404D;
    case 1:
        return 0x404E;
    case 2:
        return 0x404F;
    case 3:
        return 0x4050;
    case 4:
        return 0x4051;
    case 5:
        return 0x4052;
    case 6:
        return 0x4053;
    case 7:
        return 0x5976;
    case 8:
        return 0x5977;
    case 9:
        return 0x5978;
    default:
        return 0;
    }
}

unsigned fn_80084408(int t)
{
    if (t == 0)
        return fn_800736EC(lbl_80622810);
    if (t == 1)
        return fn_800736EC(lbl_80622814);
    return fn_800736EC(lbl_80622810);
}

unsigned fn_80084458(int t)
{
    if (t == 0)
        return fn_800736EC(lbl_80622814);
    if (t == 1)
        return fn_800736EC(lbl_80622810);
    return fn_800736EC(lbl_80622814);
}

int fn_800844A8(int t)
{
    switch (t) {
    case 0:
        return 0xA2;
    case 1:
        return 0xA2;
    case 2:
        return 0x90;
    case 3:
        return 0x90;
    case 4:
        return 0x8E;
    case 5:
        return 0x8C;
    case 6:
        return 0x8C;
    case 7:
        return 0x8C;
    case 8:
        return 0x8C;
    case 9:
        return 0x8C;
    default:
        return 0;
    }
}

void fn_8008453C(int t, int flag, int* a, int* b)
{
    int n = fn_800844A8(t);
    int r = fn_80084600(t);
    if (r == 1) {
        if (flag == 0) {
            *a = r;
            *b = n / 2;
        } else {
            *a = n / 2 + 1;
            *b = n;
        }
    } else {
        if (flag == 0) {
            *a = 1;
            *b = n;
        } else {
            *a = n + 1;
            *b = n + 1;
        }
    }
}

int fn_800845E4(int t)
{
    if (t <= 2) {
        if (t >= 0)
            return 1;
    }
    return 0;
}

int fn_80084600(int t)
{
    switch (t) {
    case 5: case 6: case 7: case 8: case 9:
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

int fn_8008463C(int t)
{
    return fn_80084114(fn_80084660(t));
}

int fn_80084660(int t)
{
    int r = 0;
    switch (t) {
    case 0:
    case 1:
    case 2:
        r = 0;
        break;
    case 3:
    case 4:
    case 5:
        r = 1;
        break;
    case 6:
    case 7:
    case 8:
        r = 2;
        break;
    case 9:
    case 10:
    case 11:
    case 12:
        r = 3;
        break;
    case 13:
    case 14:
        r = 4;
        break;
    case 15:
    case 16:
        r = 5;
        break;
    case 17:
    case 18:
        r = 6;
        break;
    case 19:
    case 20:
        r = 7;
        break;
    case 21:
    case 22:
        r = 8;
        break;
    case 23:
    case 24:
        r = 9;
        break;
    case 25:
        r = 10;
        break;
    }
    return r;
}

int fn_800848EC(int t)
{
    return fn_800844A8(fn_80084660(t));
}
