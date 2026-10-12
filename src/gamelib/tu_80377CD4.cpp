/*
 * EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib), built with
 * the game flags (cflags_game: -Os -G0 -ffloat-store),
 * .text 0x80377CD4-0x80378D70 (code-only unit, 39 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 *
 * Name-hash keyed sorted-array helpers (SortArr, see tu_80377048.h) and the
 * hash function fn_80378568 (h = h * 33 + c from 5381; the one every chooser
 * hashes its names with).
 */
#include "game/tu_80377048.h"

struct Unk802FCAC0_At8 {
    char pad0[8];
    const void* m8;
};

/* Polymorphic 8-byte objects (m0, vptr at +4): a stack instance stays in memory,
 * so retail recomputes its address after the call. */
struct Unk803567AC {
    int m0;
    Unk803567AC();
    virtual void vf0();
};

/* The real object is 8 bytes (m0, vptr at +4); a 7-byte stand-in keeps it in
 * memory (BLKmode) without the implicit ctor call. */
struct Unk80353218 {
    char b[7];
};

extern char lbl_80684950[];
extern const char lbl_80605504[];

/*
 * Link table lbl_806E4684: 0x400 entries of 0x14 bytes, each a node of a
 * doubly linked list threaded by index (next m4, prev m8), with the peer
 * node's index (mC) and the peer's list head / object (m10).
 */
struct LinkEnt {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};
struct LinkHead {
    int first;
    int last;
};
extern LinkEnt lbl_806E4684[];

/* Serializer stream: m0 = mode flag, vptr at +4; slot 1 transfers `size` bytes
 * between *buf and `data`, slot 2 returns the direction (1 = write, 0 = read). */
struct StreamV {
    int m0;
    virtual void v1(char** buf, void* data, int size);
    virtual int v2();
};

struct MapperV {
    char pad0[0];
    virtual int v1(int key);
};

struct LinkObjV {
    char pad0[8];
    virtual void v1();
    virtual void v2(int a, int b, int c);
};

extern "C" {
void fn_80377CD4(SortArr* a, int idx, const char* s, int z);
int fn_80377B1C(SortArr* a, int key);
void fn_80377DE4(SortArr* a, int v1, int v2, int idx);
void fn_80377DBC(SortArr* a, int* o1, int* o2, int idx);
int fn_80377E04(SortArr* a, int* out, int key);
int fn_80377E90(SortArr* a, int* o1, int* o2, int key);
int fn_80377F00(SortArr* a, int* o1, int* o2, const char* s, int n);
int fn_80377A14(SortArr* a, int key, int* out);
void fn_80378734(int* p);
void fn_80377408(void* p);
void fn_8037866C(LinkHead* h);
void fn_803787E4(int idx);
int fn_80378780();
void fn_80378824(int idx);
int fn_8037888C(LinkHead* h, int obj);
int fn_803789F0(int obj, LinkHead* h, int idx);
void fn_80378AD0(LinkHead* h, int idx);
void fn_80378B1C(LinkHead* h, int idx);
void fn_8040B190(void* dst, const void* src, int n);
void fn_8040B320(void* dst, int c, unsigned n);
int fn_8040B750(const char* a, const char* b, unsigned n);
void fn_8040A208(void* base, int n, int size, int (*cmp)(const SortRec*, const SortRec*));
}

unsigned fn_80378568(const char* s, int n);

Unk80353218* fn_80353218(Unk80353218* p);

extern "C" void fn_80377CD4(SortArr* a, int idx, const char* s, int z) {}

extern "C" void fn_80377CD8(SortArr* a, int v1, int v2, int key)
{
    int idx = fn_80377B1C(a, key);
    fn_80377DE4(a, v1, v2, idx);
    fn_80377CD4(a, idx, lbl_80605504, 0);
}

extern "C" void fn_80377D40(SortArr* a, int v1, int v2, const char* s, int n)
{
    int idx = fn_80377B1C(a, fn_80378568(s, n));
    fn_80377DE4(a, v1, v2, idx);
    fn_80377CD4(a, idx, s, n);
}

extern "C" void fn_80377DBC(SortArr* a, int* o1, int* o2, int idx)
{
    *o1 = a->m0[idx].m4;
    *o2 = a->m0[idx].m8;
}

extern "C" void fn_80377DE4(SortArr* a, int v1, int v2, int idx)
{
    a->m0[idx].m4 = v1;
    a->m0[idx].m8 = v2;
}

extern "C" int fn_80377E04(SortArr* a, int* out, int key)
{
    int n = fn_80377A14(a, key, out);
    if (n == 0)
        *out = -1;
    return n;
}

extern "C" int fn_80377E48(SortArr* a, int* out, const char* s, int n)
{
    return fn_80377E04(a, out, fn_80378568(s, n));
}

extern "C" int fn_80377E90(SortArr* a, int* o1, int* o2, int key)
{
    int idx;
    *o1 = -1;
    *o2 = -1;
    if (fn_80377E04(a, &idx, key)) {
        fn_80377DBC(a, o1, o2, idx);
        return 1;
    }
    return 0;
}

extern "C" int fn_80377F00(SortArr* a, int* o1, int* o2, const char* s, int n)
{
    return fn_80377E90(a, o1, o2, fn_80378568(s, n));
}

extern "C" void fn_80377F50(SortArr* a, MapperV* map)
{
    for (int i = 0; i < a->m4; i++)
        a->m0[i].key = map->v1(a->m0[i].key);
}

extern "C" void fn_80377FCC(SortArr* a, int v1, int v2, int key)
{
    int idx;
    if (fn_80377E04(a, &idx, key))
        fn_80377DE4(a, v1, v2, idx);
}

extern "C" int fn_80378024(SortArr* a, int key)
{
    int o1;
    int o2;
    if (!fn_80377E90(a, &o1, &o2, key))
        return -1;
    return o1;
}

extern "C" int fn_80378060(SortArr* a, const char* s, int n)
{
    int o1;
    int o2;
    if (!fn_80377F00(a, &o1, &o2, s, n))
        return -1;
    return o1;
}

extern "C" int fn_803780A0(SortArr* a, int idx)
{
    int o1;
    int o2;
    fn_80377DBC(a, &o1, &o2, idx);
    return o1;
}

extern "C" void fn_803780D0(SortArr* a, int v1, int v2, int key)
{
    if (a->m8 < a->m4)
        a->m8 = a->m4;
    a->m0[a->m8].key = key;
    int old = a->m4;
    a->m4 = a->m8 + 1;
    fn_80377DE4(a, v1, v2, a->m8);
    fn_80377CD4(a, a->m8, lbl_80605504, 0);
    a->m4 = old;
    a->m8++;
}

extern "C" int fn_8037815C(const SortRec* a, const SortRec* b)
{
    if (a->key < b->key)
        return -1;
    if (a->key == b->key)
        return 0;
    return 1;
}

extern "C" void fn_80378184(SortArr* a)
{
    if (a->m8 < a->m4)
        a->m8 = a->m4;
    fn_8040A208(a->m0, a->m8, 12, fn_8037815C);
    int n = a->m8;
    a->m8 = 0;
    a->m4 = n;
}

extern "C" void fn_803781E8(SortArr* a, int x)
{
    Unk803567AC tmp;
    ((SortArrV*)a)->v4(x, &tmp);
}

extern "C" void fn_8037823C(SortArr* a, int x)
{
    Unk80353218 tmp;
    fn_80353218(&tmp);
    ((SortArrV*)a)->v4(x, &tmp);
}

/* near-miss: retail keeps the write loop counter in r29 with the byte offset in r28 and the zero constant in r29 for the read branch; mine shares the zero register with the read counter (1 insn fewer) */
extern "C" void fn_80378290(SortArr* a, char** buf, StreamV* st)
{
    int sp8;
    int spC;
    int sp10;
    int sp14;
    int sp18;
    int sp1C;
    int sp20;
    int sp24;
    int sp28;
    int sp2C;
    if (st->v2() == 1) {
        spC = a->m4;
        sp8 = a->mC;
        sp14 = 0;
        sp18 = 0;
        sp10 = 0;
        st->v1(buf, &sp8, 4);
        st->v1(buf, &spC, 4);
        fn_8040B320(*buf, 0, sp8 * 12);
        for (unsigned i = 0; i < (unsigned)sp8; i++) {
            if (i < (unsigned)spC) {
                fn_80377DBC(a, &sp10, &sp14, i);
                sp18 = a->m0[i].key;
            } else {
                sp18 = 0;
                sp14 = 0;
                sp10 = 0;
            }
            st->v1(buf, &sp18, 4);
            st->v1(buf, &sp10, 4);
            st->v1(buf, &sp14, 4);
        }
    } else {
        int r = st->v2();
        if (r == 0) {
            sp1C = r;
            sp20 = r;
            sp24 = 0;
            sp28 = 0;
            sp2C = 0;
            if (st->m0 == 0)
                a->m4 = 0;
            int n = 0;
            fn_8040B190(&sp1C, *buf, 4);
            *buf += 4;
            fn_8040B190(&sp20, *buf, 4);
            *buf += 4;
            for (; n < sp1C; n++) {
                st->v1(buf, &sp24, 4);
                st->v1(buf, &sp28, 4);
                st->v1(buf, &sp2C, 4);
                if (sp24 != 0 && st->m0 == 0)
                    fn_80377CD8(a, sp28, sp2C, sp24);
            }
        }
    }
}

unsigned fn_80378568(const char* s, int n)
{
    unsigned h = 5381;
    int c = *s;
    if (n != 0) {
        while (c != 0 && n != 0) {
            h = h * 33 + c;
            c = *++s;
            n--;
        }
        return h;
    }
    if (c != 0) {
        while (c != 0) {
            h = h * 33 + c;
            c = *++s;
        }
        return h;
    }
    return 0;
}

extern "C" void* fn_803785E4(Unk802FCAC0_At8* p)
{
    p->m8 = lbl_80684950;
    fn_80378734((int*)p);
    return p;
}

extern "C" void fn_80378620(Unk802FCAC0_At8* p, int chrg)
{
    p->m8 = lbl_80684950;
    fn_8037866C((LinkHead*)p);
    if (chrg & 1)
        fn_80377408(p);
}

extern "C" void fn_8037866C(LinkHead* h)
{
    int i = h->first;
    while (i != -1) {
        int peer = lbl_806E4684[i].mC;
        LinkHead* ph = (LinkHead*)lbl_806E4684[i].m10;
        int next = lbl_806E4684[i].m4;
        fn_80378AD0(ph, peer);
        fn_80378B1C(h, i);
        i = next;
    }
    i = h->last;
    while (i != -1) {
        int peer = lbl_806E4684[i].mC;
        LinkHead* ph = (LinkHead*)lbl_806E4684[i].m10;
        int next = lbl_806E4684[i].m4;
        fn_80378B1C(ph, peer);
        fn_80378AD0(h, i);
        i = next;
    }
    fn_80378734((int*)h);
}

extern "C" void fn_80378734(int* p)
{
    p[0] = -1;
    p[1] = -1;
}

extern "C" void fn_80378744()
{
    for (int i = 0; i <= 0x3ff; i++)
        fn_803787E4(i);
}

extern "C" int fn_80378780()
{
    int i = 0;
    for (; i <= 0x3ff; i++) {
        if (lbl_806E4684[i].m0 != 0) {
            fn_803787E4(i);
            return i;
        }
    }
    return -1;
}

extern "C" void fn_803787E4(int idx)
{
    lbl_806E4684[idx].m0 = 1;
    lbl_806E4684[idx].m4 = -1;
    lbl_806E4684[idx].m8 = -1;
    lbl_806E4684[idx].mC = -1;
    lbl_806E4684[idx].m10 = 0;
}

extern "C" void fn_80378824(int idx)
{
    if (lbl_806E4684[idx].m0 == 0) {
        int p = lbl_806E4684[idx].m8;
        int n = lbl_806E4684[idx].m4;
        if (p != -1)
            lbl_806E4684[p].m4 = n;
        if (n != -1)
            lbl_806E4684[n].m8 = p;
        fn_803787E4(idx);
    }
}

extern "C" int fn_8037888C(LinkHead* h, int obj)
{
    int idx = fn_80378780();
    int next = -1;
    int prev = -1;
    if (h->first != -1) {
        next = lbl_806E4684[h->first].m4;
        if (next != -1)
            lbl_806E4684[next].m8 = idx;
        lbl_806E4684[h->first].m4 = idx;
        prev = h->first;
    } else {
        h->first = idx;
    }
    lbl_806E4684[idx].m10 = obj;
    lbl_806E4684[idx].m0 = 0;
    lbl_806E4684[idx].m4 = next;
    lbl_806E4684[idx].m8 = prev;
    return idx;
}

extern "C" void fn_8037893C(LinkHead* h, int a, int b, int c, LinkObjV* obj)
{
    int i = h->last;
    while (i != -1) {
        ((LinkObjV*)lbl_806E4684[i].m10)->v2(a, b, c);
        i = lbl_806E4684[i].m4;
    }
    if (obj != 0)
        obj->v2(a, b, c);
}

extern "C" int fn_803789F0(int obj, LinkHead* h, int idx)
{
    int r = fn_8037888C((LinkHead*)(obj + 4), (int)h);
    lbl_806E4684[r].mC = idx;
    return r;
}

extern "C" void fn_80378A34(LinkHead* h, int key)
{
    int i = h->first;
    while (i != -1) {
        if (lbl_806E4684[i].m10 == key)
            return;
        i = lbl_806E4684[i].m4;
    }
    int idx = fn_8037888C(h, key);
    lbl_806E4684[idx].mC = fn_803789F0(key, h, idx);
}

extern "C" void fn_80378ACC() {}

extern "C" void fn_80378AD0(LinkHead* h, int idx)
{
    if (h->last == idx)
        h->last = lbl_806E4684[idx].m4;
    fn_80378824(idx);
}

extern "C" void fn_80378B1C(LinkHead* h, int idx)
{
    if (h->first == idx)
        h->first = lbl_806E4684[idx].m4;
    fn_80378824(idx);
}

extern "C" void fn_80378B68(const char* str, unsigned n, char* dst, int limit, const char* delims, unsigned ndelims, int* out)
{
    if (n != 0 && limit != 0 && ndelims <= n) {
        *out = 0;
        int a = 0;
        int b = 0;
        const char* p;
        while ((b == 0 || a == 0) && (p = str + *out, str[*out]) != 0 && fn_8040B750(p, delims, ndelims) != 0) {
            if (*out == limit)
                *out = *out - 1;
            dst[*out] = str[*out];
            *out = *out + 1;
        }
        if (*out != 0)
            ((void (*)(char*, const char*, ...))fn_8040B190)(dst, str, *out);
        dst[*out] = 0;
    }
}

extern "C" void fn_80378C5C(const unsigned char* str, int n, char* dst, unsigned len, const unsigned char* set, unsigned setlen, int* out)
{
    if (n != 0 && len != 0) {
        *out = 0;
        int a = 0;
        int found = 0;
        while ((found == 0 || a == 0) && (unsigned)*out < len - 1) {
            const unsigned char* p = str + *out;
            for (unsigned j = 0; j <= setlen; j++) {
                if (*p == set[j]) {
                    found = 1;
                    break;
                }
            }
            if (found)
                break;
            *out = *out + 1;
        }
        if (*out != 0)
            ((void (*)(char*, const unsigned char*, ...))fn_8040B190)(dst, str, *out);
        dst[*out] = 0;
    }
}

extern "C" void fn_80378D40(const char* s, int ch, int* out)
{
    const char* p = s;
    while (*p != ch && *p != 0)
        p++;
    *out = p - s;
}
