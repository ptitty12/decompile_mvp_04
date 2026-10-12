/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803ED700-0x803EE8F8 (code-only unit, 32 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

/*
 * RealCore heap manager types (src/ealib/tu_803ED700.cpp and neighbours).
 * Evidence: fn_803ED700 (block header init), fn_803EDE64/fn_803EDEE8 (free list
 * insert/unlink through +0x10/+0x14), fn_803ED188 (allocator), heap pointer table lbl_806AABF4[64].
 * Block tags: 0x4246 'BF' free (linked), 0x424D 'BM' allocated, 0x424F 'BO' unlinked, 0x4253 'BS' sentinel.
 */
struct RcBlk {
    unsigned short m0;
    unsigned short m2;
    int m4;
    RcBlk* m8;
    RcBlk* mC;
    RcBlk* m10;
    RcBlk* m14;
};

struct RcHeap {
    int m0;
    int m4;
    RcBlk* m8;
    int mC;
    RcBlk head;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    char m3C[0x1c];
    void* m58;
};

extern RcHeap* lbl_806AABF4[64];

extern "C" int fn_804007FC(void*);
extern "C" int fn_803FFC58(void*, int, int);
extern "C" int fn_803EDA0C(void*);
extern "C" int fn_803EE020(int, const void*, int (*)(void));
extern "C" int fn_803EE81C();
extern "C" void fn_803EE878();
extern "C" int fn_803EDF10();
extern "C" int fn_803EE238();
extern "C" int fn_803ED720(int, const void*, int, int, int, int, int, int, int, int);
extern "C" int fn_803EDC98(void*, int);
extern "C" int fn_803EDC04(int);
extern "C" int fn_80400690(int (*)(void));
extern "C" void* fn_80432A50(void*, int);
extern "C" int fn_80432CBC();
extern "C" int fn_80432CB4();
extern "C" int fn_80432BD8(int, int, int);
extern "C" int fn_80432CCC(int);
extern "C" int fn_80432C48(int, int);
extern "C" int fn_80432BC8();
extern char lbl_8060DF60[];
extern char lbl_8060DF64[];
extern void* lbl_806EF2C8;
extern int lbl_806EE9F0;
extern int lbl_806EEA08;
extern int lbl_806EEA0C;
extern int lbl_806EEA00;
extern "C" int fn_80400828(void*);
extern "C" int fn_8040084C(void*);
extern "C" RcBlk* fn_803EDCEC(RcHeap*, int, int);
extern "C" int fn_803EDDF8(RcHeap*, int);
extern "C" int fn_80400E8C(void*, int, int);
extern "C" int fn_803EE450(RcBlk*);
extern "C" int fn_803EE4B8(RcBlk*);
extern "C" int fn_803EE5A0(RcBlk*);
extern "C" int fn_803EE688(RcBlk*);
extern "C" int fn_803EE708(int);

inline unsigned RcRdBE(const unsigned char* b)
{
    return (b[0] << 24) | (b[1] << 16) | (b[2] << 8) | b[3];
}

extern "C" int fn_803ED700(RcBlk* b, int a, int size, int c, int tag, int flags, RcBlk* d, RcBlk* e)
{
    b->mC = d;
    b->m0 = tag;
    b->m2 = flags;
    b->m8 = e;
    b->m4 = size;
    return size + 0x10;
}

extern "C" int fn_803ED8EC(int idx)
{
    RcHeap** tab = lbl_806AABF4;
    int off = (idx & 0x3f) * 4;
    int r = 0;
    RcHeap* h = *(RcHeap**)((char*)tab + off);
    if (h != 0) {
        if (h->m38 != 0)
            fn_804007FC(h->m3C);
        fn_803FFC58(h, 0, 0x5c);
        *(RcHeap**)((char*)tab + off) = 0;
        r = 1;
    }
    return r;
}

extern "C" int fn_803ED95C(int idx)
{
    RcHeap** tab = lbl_806AABF4;
    int off = (idx & 0x3f) * 4;
    int r = 1;
    RcBlk* b = (*(RcHeap**)((char*)tab + off))->m8;
    for (; b != 0 && r != 0; b = b->m8) {
        if ((b->m2 & 0xc000) == 0)
            r = fn_803EDA0C((char*)b + 0x10);
    }
    return r;
}

extern "C" int fn_803ED9D4()
{
    int i = 2;
    if (lbl_806AABF4[2] != 0) {
        RcHeap** p = &lbl_806AABF4[2];
        for (;;) {
            i++;
            if (i > 0x3f)
                break;
            if (*++p == 0)
                break;
        }
    }
    return i;
}

extern "C" int fn_803EDC04(int a)
{
    int r = 0;
    fn_80400690(fn_803EE238);
    fn_803EE878();
    void* p = fn_80432A50(lbl_806EF2C8, a);
    if (p != 0) {
        r = fn_803EDC98(p, a);
        lbl_806AABF4[0]->m58 = p;
    }
    return r;
}

extern "C" int fn_803EDC74()
{
    return fn_803EDC04(fn_803EE81C());
}

extern "C" int fn_803EDC98(void* a, int b)
{
    return fn_803ED720(0, lbl_8060DF60, (int)a, b, 0x20, 0x20, 0, 0, 0, 1);
}

extern "C" RcBlk* fn_803EDCEC(RcHeap* h, int n, int rev)
{
    RcBlk* best = 0;
    RcBlk* p = &h->head;
    n--;
    if (n < 0)
        n = 0;
    if (rev == 0) {
        for (;;) {
            p = p->m10;
            if (p->m4 - 0x10 > n) {
                if (p->m0 == 0x4253)
                    break;
                best = p;
                n = best->m4 - 0x10;
            }
        }
    } else {
        for (;;) {
            p = p->m14;
            if (p->m4 - 0x10 > n) {
                if (p->m0 == 0x4253)
                    break;
                best = p;
                n = best->m4 - 0x10;
            }
        }
    }
    return best;
}

extern "C" RcBlk* fn_803EDD8C(RcHeap* h, int n, int rev, int off, int mask, int* out)
{
    RcBlk* p = &h->head;
    int pad;
    if (rev == 0) {
        do {
            p = p->m10;
            pad = ((mask & ~((int)p + off)) + 1) & mask;
        } while (n + pad > p->m4);
    } else {
        do {
            p = p->m14;
            pad = ((int)p + (p->m4 + off)) & mask;
        } while (n + pad > p->m4);
    }
    if (p->m0 == 0x4253)
        p = 0;
    *out = pad;
    return p;
}

extern "C" int fn_803EDDF8(RcHeap* h, int rev)
{
    RcBlk* p = &h->head;
    int total = 0;
    if (rev == 0) {
        p = p->m10;
        while (p->m0 != 0x4253) {
            total += p->m4 - 0x10;
            p = p->m10;
        }
    } else {
        p = p->m14;
        while (p->m0 != 0x4253) {
            total += p->m4 - 0x10;
            p = p->m14;
        }
    }
    return total;
}

extern "C" void fn_803EDE64(RcHeap* h, RcBlk* blk)
{
    RcBlk* head = &h->head;
    RcBlk* prev = head;
    RcBlk* next = head;
    int size = (char*)blk->m8 - (char*)blk;
    RcBlk* mid = (RcBlk*)((char*)head->m10 + ((int)head->m14 - (int)head->m10) / 2);
    if (blk > mid) {
        do {
            prev = prev->m14;
        } while (blk < prev);
        next = prev->m10;
    } else {
        do {
            next = next->m10;
        } while (blk > next);
        prev = next->m14;
    }
    blk->m4 = size;
    blk->m10 = next;
    blk->m14 = prev;
    prev->m10 = blk;
    next->m14 = blk;
    blk->m0 = 0x4246;
    blk->m2 |= 0x4000;
}

extern "C" void fn_803EDEE8(RcBlk* b)
{
    RcBlk* prev = b->m14;
    RcBlk* next = b->m10;
    prev->m10 = next;
    next->m14 = prev;
    b->m0 = 0x424f;
    b->m2 &= 0xbfff;
}

extern "C" int fn_803EDFCC(int a)
{
    return fn_803EE020(a, lbl_8060DF64, fn_803EDF10);
}

extern "C" int fn_803EDFFC()
{
    return fn_803EDFCC(lbl_806EE9F0);
}

extern "C" int fn_803EE310(char* p)
{
    return *(int*)(p - 0xc);
}

extern "C" int fn_803EE318()
{
    return 0;
}

extern "C" int fn_803EE320(char* p)
{
    RcBlk* b = (RcBlk*)(p - 0x10);
    int r = 0;
    if (b->m2 & 0x800)
        r = *(int*)(p + b->m4 + 4);
    return r;
}

extern "C" int fn_803EE348(int idx)
{
    if (idx == 0)
        idx = lbl_806EE9F0;
    RcHeap* h = lbl_806AABF4[idx & 0x3f];
    if (h->m38 != 0)
        fn_80400828(h->m3C);
    RcBlk* b = fn_803EDCEC(h, 0, 0);
    if (h->m38 != 0)
        fn_8040084C(h->m3C);
    return b ? b->m4 : 0;
}

extern "C" int fn_803EE3D4(int idx)
{
    if (idx == 0)
        idx = lbl_806EE9F0;
    RcHeap* h = lbl_806AABF4[idx & 0x3f];
    if (h->m38 != 0)
        fn_80400828(h->m3C);
    int r = fn_803EDDF8(h, 0);
    if (h->m38 != 0)
        fn_8040084C(h->m3C);
    return r;
}

extern "C" int fn_803EE450(RcBlk* p)
{
    int r = 0;
    if (fn_80400E8C(p, 0x18, 0) != 0 && (p->m0 == 0x4246 || p->m0 == 0x4253))
        r = 1;
    else
        lbl_806EEA00 = 1;
    return r;
}

extern "C" int fn_803EE4B8(RcBlk* p)
{
    int r = 0;
    int t = p->m0;
    if (t == 0x4253) {
        if (p->m2 & 0x8000)
            r = 1;
        else
            lbl_806EEA00 = 2;
    } else if (t == 0x4246) {
        if (p->m2 & 0x4000) {
            r = fn_803EE450(p->m10);
            if (r != 0)
                r = fn_803EE450(p->m14);
        }
    } else if (t == 0x424d) {
        if (p->m2 & 0x2000) {
            if (RcRdBE((unsigned char*)(p->m4 + (int)p) + 0x10) == 0x42454e44)
                r = 1;
            else
                lbl_806EEA00 = 3;
        } else
            r = 1;
    } else
        lbl_806EEA00 = 4;
    return r;
}

extern "C" int fn_803EE5A0(RcBlk* p)
{
    int r = 0;
    if (p != 0) {
        int t = p->m0;
        if (t == 0x4253) {
            if (p->m2 & 0x8000)
                r = 1;
            else
                lbl_806EEA00 = 2;
        } else if (t == 0x4246) {
            if (p->m2 & 0x4000) {
                RcBlk* n = p->m10;
                if (n != 0 && n->m14 == p) {
                    RcBlk* q = p->m14;
                    if (q != 0)
                        r = q->m10 == p;
                }
                if (r == 0)
                    lbl_806EEA00 = 5;
            }
        } else if (t == 0x424d) {
            RcBlk* n = p->m8;
            if (n != 0 && n->mC == p) {
                RcBlk* q = p->mC;
                if (q != 0)
                    r = q->m8 == p;
            }
            if (r == 0)
                lbl_806EEA00 = 5;
        } else
            lbl_806EEA00 = 4;
    }
    return r;
}

extern "C" int fn_803EE688(RcBlk* p)
{
    RcBlk* head = p;
    int r = 0;
    do {
        p = p->m10;
    } while ((*(unsigned*)p & 0xffff4000) == 0x42464000);
    if (p->m0 == 0x4253) {
        do {
            p = p->m14;
        } while ((*(unsigned*)p & 0xffff4000) == 0x42464000);
        if (p == head)
            r = 1;
    }
    if (r == 0)
        lbl_806EEA00 = 6;
    return r;
}

extern "C" int fn_803EE708(int idx)
{
    RcHeap* h = lbl_806AABF4[idx & 0x3f];
    if (h->m38 != 0)
        fn_80400828(h->m3C);
    RcBlk* b = h->m8;
    int ok;
    do {
        ok = 0;
        if (fn_803EE4B8(b) != 0) {
            if (fn_803EE5A0(b) != 0)
                ok = 1;
        }
        if (ok != 0)
            b = b->m8;
    } while (b != 0 && ok != 0);
    if (ok != 0)
        ok = fn_803EE688(&h->head);
    if (h->m38 != 0)
        fn_8040084C(h->m3C);
    return ok;
}

extern "C" int fn_803EE7BC()
{
    int r = 1;
    RcHeap** p = lbl_806AABF4;
    int i = 0;
    do {
        if (*p++ != 0)
            r = fn_803EE708(i);
        i++;
    } while (i <= 0x3f && r != 0);
    return r;
}

extern "C" int fn_803EE81C()
{
    int r;
    if (lbl_806EEA0C != 0)
        r = 0;
    else {
        int a = fn_80432CBC();
        int b = fn_80432CB4();
        a = (a + 0x1f) & ~0x1f;
        b &= ~0x1f;
        r = b - a - lbl_806EEA08;
    }
    return r;
}

extern "C" void fn_803EE878()
{
    if (lbl_806EEA0C == 0) {
        lbl_806EEA0C = 1;
        int a = fn_80432CBC();
        int b = fn_80432CB4();
        a = fn_80432BD8(a, b, 1);
        b &= ~0x1f;
        fn_80432CCC(a);
        fn_80432C48((a + 0x1f) & ~0x1f, b);
        fn_80432BC8();
        fn_80432CCC(b);
    }
}
