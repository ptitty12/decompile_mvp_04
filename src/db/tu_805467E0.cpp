/*
 * Database overlay code, .database_codeoverlay 0x805467E0-0x805495DC (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8053967C.h"

typedef Db805467E0_Ev Ev;
typedef Db805467E0_Q Q;
typedef Db805467E0_V V;

extern const float lbl_805FF024;
extern const float lbl_805FF028;
extern char lbl_80682D68[];
extern char lbl_80682D50[];
extern int lbl_80622BEC;
extern int lbl_80692E38;
extern int lbl_80622BF4;

static inline int IntAt(char* b, int off)
{
    return *(int*)(b + off);
}

static inline void IntSet(char* b, int off, int v)
{
    *(int*)(b + off) = v;
}

extern "C" {

/* protos */
int fn_80546B18(char* o, int a, int b);
int fn_80546BCC(char* o, int a, int b);
int fn_80546C88(char* o, int i);
int fn_80546CA8(char* o, int a, int b);
void fn_80546D0C(char* o);
void fn_80546D4C(char* o);
void fn_80546D5C(char* o, int a);
int fn_805474B8(char* o, int a);
void fn_80547594(char* o, int a);
void fn_805480E8(char* o);
Ev* fn_80548858(Ev* e);
void fn_80548894(Ev* e, int a, int b, int c, V* v);
void fn_805488E0(Ev* e, int v);
void fn_805488E8(Ev* e, V* v);
void fn_80548908(Ev* e);
Q* fn_80548934(Q* o);
void fn_8054899C(Q* q);
void fn_80548B08(Q* q, int v);
int fn_80548B6C(Ev* e, int id);
int fn_80548BA0(Q* q, int a, int id, V* v, int c, int flag);
void fn_80548C7C(Q* q, int a, int b);
int fn_80548CFC(Ev* q, int id);
int* fn_80548D2C(Q* q, int id);
void* fn_80548D78(Q* q, int id);
int fn_80548DC0(Q* q, int id);
int fn_80548E0C(Q* q, int i);
int fn_80548E1C(Q* q, int i);
int* fn_80548E2C(Q* q, int i);
Ev* fn_80548E3C(Q* q, int i);
Db805467E0_W3* fn_80548E48(Q* q, int i);
int* fn_80548E58(Q* q, int i);
void fn_80548E68(Q* q, int n);
/* end protos */

DB_OVERLAY int fn_80546B18(char* o, int a, int b)
{
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int ao = a * 4;
    int h = s->fn_80075948(*(int*)((char*)*(int**)(o + 0x32E0) + ao));
    unsigned i = 0;
    if (i < *(unsigned*)(o + 4)) {
        int off = 0;
        do {
            int k = IntAt(o + 0x3CCC, off);
            if (k != 0 && s->fn_80075948(k) == h && IntAt(o + 0x3CD0, off) == b)
                return IntAt(o + 0x3CC8, off);
            i++;
            off += 0x10;
        } while (i < *(unsigned*)(o + 4));
    }
    return 0;
}

/* near-miss: retail sets r3 (this) in each arm and jumps to one shared call tail; ours sets it once */
DB_OVERLAY int fn_80546BCC(char* o, int a, int b)
{
    if (*(int*)(o + 0x107F0) == 0) {
        int ao = a * 4;
        return *(int*)((char*)*(int**)(o + 0x32E0) + ao);
    }
    int* arr = *(int**)(o + 0x32E0);
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    int h = s->fn_80075948(arr[a]);
    int k;
    if (b <= 0x18)
        k = 0;
    else if (b <= 0x31)
        k = 1;
    else if (b <= 0x4A)
        k = 2;
    else if (b <= 0x63)
        k = 3;
    else
        return 0;
    return s->fn_8007B320(k, h);
}










void fn_8036179C(void* p);

DB_OVERLAY int fn_80546C88(char* o, int i)
{
    char* b = o + 0x3CCC;
    int off = i * 0x10;
    if (*(int*)(b + off) != 0)
        return 1;
    return 0;
}

int fn_805467E0(char* o, int a);
int fn_805470F0(char* o);
int fn_805425FC(char* s, int a);
void fn_805489FC(Q* q, int i);
void fn_80538258(char* o);
void fn_80537514(void* p);
void fn_805381F0(char* o);
void fn_805362AC(char* o, int a);
void fn_805484A0(char* o);

DB_OVERLAY int fn_80546CA8(char* o, int a, int b)
{
    unsigned n = *(unsigned*)(o + 4);
    int ao = a * 4;
    int key = *(int*)((char*)*(int**)(o + 0x32E0) + ao);
    unsigned i = 0;
    if (i < n) {
        int off = 0;
        do {
            if (IntAt(o + 0x3CCC, off) == key && IntAt(o + 0x3CD0, off) == b)
                return IntAt(o + 0x3CD4, off);
            i++;
            off += 0x10;
        } while (i < n);
    }
    return 0;
}

DB_OVERLAY void fn_80546D0C(char* o)
{
    int off = 0;
    int c = 0xCB2;
    do {
        int z = 0;
        IntSet(o + 0x3CC8, off, z);
        IntSet(o + 0x3CCC, off, z);
        IntSet(o + 0x3CD0, off, -1);
        off += 0x10;
        c--;
    } while (c != 0);
    *(int*)(o + 0x107E8) = 0;
}

DB_OVERLAY void fn_80546D4C(char* o)
{
    *(int*)(o + 0x107E8) = 0;
}

DB_OVERLAY void fn_80546D5C(char* o, int a)
{
    int r;
    if (*(int*)(o + 0x107F0) == 1)
        r = fn_805425FC(o + 0x10800, a);
    else
        r = fn_805470F0(o);
    fn_805467E0(o, r);
}

/* near-miss: 1 slot; retail initialises i with `mr r30,r27` (copy of cnt's zero), ours uses li */
/* near-miss: 1 slot; retail initialises i with `mr r30,r27` (copy of cnt's zero), ours uses li */
DB_OVERLAY int fn_805474B8(char* o, int a)
{
    if (*(int*)(o + 0x107F0) != 0) {
        unsigned cnt = 0;
        Unk8007A4DC_Screen* s = (Unk8007A4DC_Screen*)lbl_8061930C;
        int key = (*(int**)(o + 0x32E0))[*(int*)(o + 0x32EC)];
        unsigned i = 0;
        int ioff = 0;
        int off = 0;
        do {
            if (fn_80546C88(o, i) != 0 && IntAt(o + 0x3CCC, off) == key
                && s->fn_8007A270(*(int*)((char*)*(int**)o + ioff)) != 0)
                cnt++;
            i++;
            ioff += 4;
            off += 0x10;
        } while (i <= 0xCB1);
        if (s->fn_8007A270(a) != 0 && cnt > 0xE)
            return 2;
    }
    return 0;
}

DB_OVERLAY void fn_80547594(char* o, int a)
{
    if (a == 1) {
        fn_80538258(o);
        *(int*)(o + 0x107F0) = 0;
        return;
    }
    int z = 0;
    *(int*)(o + 0x107F0) = z;
    fn_80546D0C(o);
    char* p = o + 0x32E0;
    fn_80537514(p);
    *(int*)(p + 0xC) = z;
    fn_805381F0(o);
    fn_805362AC(o, 1);
}

DB_OVERLAY void fn_805480E8(char* o)
{
    fn_80546D0C(o);
    fn_805484A0(o);
    *(int*)(o + 0x107EC) = *(int*)(o + 4);
}

DB_OVERLAY Ev* fn_80548858(Ev* e)
{
    e->m28 = lbl_80682D68;
    fn_80548908(e);
    return e;
}

DB_OVERLAY void fn_80548894(Ev* e, int a, int b, int c, V* v)
{
    if (e->m0 < v->m0 || a == e->m20) {
        e->m20 = a;
        e->m18 = b;
        *(Db805467E0_W3*)e = *(Db805467E0_W3*)v;
        e->m1C = c;
        e->m24 = 0;
    }
}

DB_OVERLAY void fn_805488E0(Ev* e, int v)
{
    e->m24 = v;
}

DB_OVERLAY void fn_805488E8(Ev* e, V* v)
{
    e->vC = *(Db805467E0_W3*)v;
}

DB_OVERLAY void fn_80548908(Ev* e)
{
    e->m0 = lbl_805FF024;
    e->m18 = 0;
    e->m8 = 0;
    e->m4 = 0;
    e->m20 = 0;
    e->m1C = 0;
    e->m24 = 0;
}

DB_OVERLAY Q* fn_80548934(Q* o)
{
    *(const void**)((char*)o + 0x3FD4) = lbl_80682D50;
    Ev* e = o->ev;
    int c = 0x4A;
    do {
        fn_80548858(e);
        e++;
    } while (c-- != 0);
    fn_8036179C(&o->sCE8);
    fn_8054899C(o);
    return o;
}

DB_OVERLAY void fn_8054899C(Q* q)
{
    int e = (int)q->ev;
    int end = (int)q + 0xCB8;
    do {
        fn_80548908((Ev*)e);
        e += 0x2C;
    } while (e <= end);
    q->sCE8.m0 = 6;
    q->mCE4 = 0;
    Db805467E0_S* s = &q->sCE8;
    s->m4 = 0;
    s->m8 = 0;
}

DB_OVERLAY void fn_80548B08(Q* q, int v)
{
    int i = q->mCE4 - 1;
    if (i >= 0) {
        Ev* p = (Ev*)(i * 0x2C + (int)q);
        do {
            if (p->m24 == v)
                fn_805489FC(q, i);
            p--;
            i--;
        } while (i >= 0);
    }
}

DB_OVERLAY int fn_80548B6C(Ev* e, int id)
{
    int i = 0;
    do {
        if (e->m18 != id) {
            e++;
            i++;
            continue;
        }
        return i;
    } while (i < 75);
    return -1;
}

DB_OVERLAY int fn_80548BA0(Q* q, int a, int id, V* v, int c, int flag)
{
    if (q->mCE4 == 0x4B) {
        fn_80548B08(q, 2);
        if (q->mCE4 == 0x4B) {
            fn_80548B08(q, 1);
            if (q->mCE4 == 0x4B)
                fn_805489FC(q, 0);
        }
    }
    int i = fn_80548B6C(q->ev, id);
    if (i == -1) {
        i = q->mCE4;
        q->mCE4 = i + 1;
    }
    Ev* e = (Ev*)((char*)q + i * 0x2C);
    fn_80548894(e, a, id, c, v);
    if (flag != 0)
        fn_805488E8(e, v);
    return i;
}

DB_OVERLAY void fn_80548C7C(Q* q, int a, int b)
{
    V tmp;
    int i = fn_80548B6C(q->ev, a);
    if (i != -1) {
        tmp.m4 = 0;
        tmp.m0 = lbl_805FF028;
        fn_805488E8(&q->ev[i], &tmp);
        if (b == fn_80548E0C(q, i))
            fn_805489FC(q, i);
    }
}

DB_OVERLAY int fn_80548CFC(Ev* q, int id)
{
    return fn_80548B6C(q, id) == -1 ? 0 : 1;
}

DB_OVERLAY int* fn_80548D2C(Q* q, int id)
{
    int i = fn_80548B6C(q->ev, id);
    if (i != -1)
        return &((Ev*)(i * 0x2C + (int)q))->m24;
    return &lbl_80622BEC;
}

DB_OVERLAY void* fn_80548D78(Q* q, int id)
{
    int i = fn_80548B6C(q->ev, id);
    if (i != -1)
        return (Ev*)(i * 0x2C + (int)q);
    return &lbl_80692E38;
}

DB_OVERLAY int fn_80548DC0(Q* q, int id)
{
    int i = fn_80548B6C(q->ev, id);
    if (i != -1)
        return ((Ev*)(i * 0x2C + (int)q))->m20;
    return lbl_80622BF4;
}

DB_OVERLAY int fn_80548E0C(Q* q, int i)
{
    Ev* e = (Ev*)(i * 0x2C + (int)q);
    return e->m20;
}

DB_OVERLAY int fn_80548E1C(Q* q, int i)
{
    Ev* e = (Ev*)(i * 0x2C + (int)q);
    return e->m18;
}

DB_OVERLAY int* fn_80548E2C(Q* q, int i)
{
    Ev* e = (Ev*)(i * 0x2C + (int)q);
    return &e->m24;
}

DB_OVERLAY Ev* fn_80548E3C(Q* q, int i)
{
    return (Ev*)(i * 0x2C + (int)q);
}

DB_OVERLAY Db805467E0_W3* fn_80548E48(Q* q, int i)
{
    Ev* e = (Ev*)(i * 0x2C + (int)q);
    return &e->vC;
}

DB_OVERLAY int* fn_80548E58(Q* q, int i)
{
    Ev* e = (Ev*)(i * 0x2C + (int)q);
    return &e->m1C;
}

DB_OVERLAY void fn_80548E68(Q* q, int n)
{
    q->sCE8.m0 = 0;
    Db805467E0_S* s = &q->sCE8;
    s->m8 = n;
    s->m4 = 0;
    Db8053967C_List* l = &q->mCF4;
    fn_8040074C(l->m0, l->m8 * 4);
    l->m4 = 0;
    l->mC = 0;
    l->m14 = 0;
}

}
