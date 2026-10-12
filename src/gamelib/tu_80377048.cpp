/*
 * EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib), built with
 * the game flags (cflags_game: -Os -G0 -ffloat-store),
 * .text 0x80377048-0x80377CD4 (code-only unit, 29 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 *
 * The "soa" allocator front end: a pool manager (lbl_8062421C) that keeps a
 * table of heaps, each with size-class free lists, and a sorted array.
 */

#include "game/tu_8000C2C4.h"
#include "game/tu_80377048.h"

struct SoaIface {
    virtual int* v1(int idx);
    virtual void v2();
    virtual unsigned v3();
    virtual unsigned v4();
};

struct SoaPool {
    int m0;
    int m4[32];
    int m84[16];
    int mC4[16];
    unsigned m104;
    unsigned m108;
    char pad10C[0xC0];
    int m1CC[16];
    char pad20C[0xC];
    int m218;
    int m21C;
    int m220;
};

struct SoaMgr {
    int m0;
    char pad4[8];
    unsigned mC;
    int* m10;
    int pad14;
    SoaIface* m18;
};

extern SoaMgr* lbl_8062421C;

extern "C" {
void* fn_8037704C(void* a, const char* name, unsigned size, int heap, int flag);
void* fn_803771F4(void* a, const char* name, unsigned size, int flags);
void fn_803772E0(void* p);
unsigned fn_803EE310(void* p);
void fn_803EDA0C(void* p);
void fn_80377408(void* p);
void fn_80377488(void* p);
void fn_80408774(const char* fmt, ...);
void* fn_803ED634(const char* name, unsigned size, int flags);
void fn_803FFC58(void* p, unsigned pat, unsigned size);

int fn_80377814(const char* fmt, ...);
int fn_80409BF0(char* buf, const char* fmt, va_list ap);
SoaMgr* fn_803774D8();
SoaPool* fn_803774E4(SoaMgr* m, int idx);
SoaPool* fn_80377554(SoaMgr* m, unsigned a);
int fn_80377614(SoaMgr* m, int idx);
int fn_80377624(SoaMgr* m, int key);
int fn_803776A4(SoaMgr* m, int idx);
int fn_803776F4(SoaMgr* m, int key);
unsigned fn_80377790(SoaMgr* m, int idx);
}

inline int SoaOn()
{
    return lbl_8062421C != 0;
}

inline int InRange(SoaPool* p, unsigned a)
{
    int r = 0;
    if (a >= p->m104)
        r = a < p->m104 + p->m108;
    if (r != 0)
        return 1;
    return 0;
}

extern "C" void fn_80377048() {}

extern void* lbl_80624234;
extern const char lbl_80605478[];

/* near-miss: 91.7%; retail keeps the loop index in a stack slot (stw r11,8(r1)) and walks the size table with lwzu from the pool base, rounding as (size + 4) - (size & 3); mine lets CSE fold both and puts the index in r31/r29 */
extern "C" void* fn_8037704C(void* a, const char* name, unsigned size, int heap, int flag)
{
    void* r;
    if (!SoaOn()) {
        return fn_803771F4(a, name, size, 0x100);
    }
    SoaMgr* mgr = fn_803774D8();
    SoaPool* pool = 0;
    int fl = fn_803776A4(mgr, heap);
    if (flag != 0)
        pool = fn_803774E4(mgr, heap);
    
    if (pool != 0 && size <= fn_80377790(mgr, heap)) {
        unsigned sz = size;
        if (size > 0x2300) {
            r = fn_8037704C(lbl_80624234, lbl_80605478, size, pool->m220, 0);
        } else {
            unsigned rem = size & 3;
            if (rem != 0)
                sz = (size + 4) - rem;
            int i = 0;
            unsigned* q = (unsigned*)pool + 1;
            while (sz > *q++)
                i++;
            if (pool->m84[i] == 0) {
                pool->m1CC[i]++;
                r = fn_8037704C(lbl_80624234, lbl_80605478, sz, pool->m218, 0);
            } else {
                r = 0;
            }
            if (r == 0) {
                r = (void*)pool->m84[i];
                pool->m84[i] = *(int*)r;
            }
        }
    } else {
        r = fn_803ED634(name, size, fl);
    }
    if (r == 0)
        r = fn_803ED634(name, size, 0x100);
    return r;
}

extern const char lbl_8060548C[];
extern void (*lbl_80624248)();

extern "C" void* fn_803771F4(void* a, const char* name, unsigned size, int flags)
{
    if (flags != 0 && (flags & 0x100) == 0 && SoaOn() == 1) {
        int idx = fn_803776F4(fn_803774D8(), flags);
        if (idx != -1)
            return fn_8037704C(a, name, size, idx, 1);
    }
    void* p = fn_803ED634(name, size, flags);
    if (p == 0)
        fn_80377814(lbl_8060548C, name);
    fn_803FFC58(p, 0xBB55BB55, size);
    if (lbl_80624248)
        lbl_80624248();
    return p;
}

/* near-miss: 98.4%; do-while form gives retail's bdnz loop, but retail also has a redundant li r11,0 after it (final-value store) that no spelling tried reproduced */
extern "C" void fn_803772E0(void* p)
{
    if (p == 0)
        return;
    if (SoaOn() == 1) {
        SoaPool* pool = fn_80377554(fn_803774D8(), (unsigned)p);
        if (pool != 0) {
            unsigned base = pool->m104;
            if ((unsigned)p < base || (unsigned)p >= base + pool->m108) {
                fn_80377488(p);
                return;
            }
            unsigned off = (unsigned)p - base;
            int i = 15;
            do {
                if ((unsigned)pool->mC4[i - 1] <= off)
                    break;
                i--;
            } while (i > 0);
            *(int*)p = pool->m84[i];
            pool->m84[i] = (int)p;
            return;
        }
    }
    fn_803FFC58(p, 0xAA55AA55, fn_803EE310(p));
    fn_803EDA0C(p);
}

extern "C" void* fn_803773D8(unsigned size)
{
    return fn_803771F4(0, 0, size, 0);
}

extern "C" void fn_80377408(void* p)
{
    fn_803772E0(p);
}

void* operator new(unsigned int size, int heap)
{
    return fn_803771F4(0, 0, size, heap);
}

extern "C" void* fn_80377458(unsigned size)
{
    return fn_803771F4(0, 0, size, 0);
}

extern "C" void fn_80377488(void* p)
{
    fn_803772E0(p);
}

extern "C" void* fn_803774A8(unsigned size, int heap)
{
    return fn_803771F4(0, 0, size, heap);
}

extern "C" SoaMgr* fn_803774D8()
{
    return lbl_8062421C;
}

extern "C" SoaPool* fn_803774E4(SoaMgr* m, int idx)
{
    if (m->m0 == 0 || idx == -1)
        return 0;
    int k = fn_80377614(m, idx);
    return (SoaPool*)m->m18->v1(k)[2];
}

extern "C" SoaPool* fn_80377554(SoaMgr* m, unsigned a)
{
    if (m->m0 == 0)
        return 0;
    unsigned i = 0;
    for (; i < m->mC; i++) {
        SoaPool* p = fn_803774E4(m, fn_80377624(m, i));
        if (p != 0 && InRange(p, a))
            return p;
    }
    return 0;
}

extern "C" int fn_80377614(SoaMgr* m, int idx)
{
    return m->m10[idx];
}

extern "C" int fn_80377624(SoaMgr* m, int key)
{
    unsigned n = m->m18->v3();
    unsigned i = 0;
    for (; i < n; i++) {
        if (m->m10[i] == key)
            return i;
    }
    return -1;
}

extern "C" int fn_803776A4(SoaMgr* m, int idx)
{
    int k = fn_80377614(m, idx);
    return *m->m18->v1(k);
}

extern "C" int fn_803776F4(SoaMgr* m, int key)
{
    unsigned n = m->m18->v4();
    unsigned i = 0;
    for (; i < n; i++) {
        int k = fn_80377624(m, i);
        if (k != -1 && fn_803776A4(m, k) == key)
            return k;
    }
    return -1;
}

extern "C" unsigned fn_80377790(SoaMgr* m, int idx)
{
    return 0x2300;
}

struct SoaTab {
    char pad0[0x10];
    void* m10;
    int pad14;
    const void* m18;
};
extern const char lbl_80684850[];
extern const char lbl_80684970[];

extern "C" void fn_80377798(SoaTab* t, int chrg)
{
    t->m18 = lbl_80684850;
    if (t->m10)
        fn_80377488(t->m10);
    if (chrg & 1)
        fn_80377408(t);
}

extern "C" void fn_803777F0(const char* fmt)
{
    fn_80408774(fmt);
}

extern char lbl_80693E8C[];
extern void (*lbl_80624220)(char*);

extern "C" int fn_80377814(const char* fmt, ...)
{
    if (fmt) {
        va_list ap;
        va_start(ap, fmt);
        fn_80409BF0(lbl_80693E8C, fmt, ap);
    } else
        lbl_80693E8C[0] = 0;
    if (lbl_80624220)
        lbl_80624220(lbl_80693E8C);
    return 0;
}

extern "C" void fn_803778EC(SortArr* a, int chrg)
{
    a->m14 = lbl_80684970;
    if (a->m0)
        fn_80377488(a->m0);
    if (chrg & 1)
        fn_80377408(a);
}

extern "C" void* fn_803FFA60(void* dst, const void* src, unsigned n);

/* near-miss: 90%; retail loads src->mC into r3 and stores/multiplies it there, with this/src in r31/r30 (2 saved regs); mine uses r29/r30 */
extern "C" SortArr* fn_80377944(SortArr* a, SortArr* src, int heap)
{
    a->m14 = lbl_80684970;
    a->m10 = src->m10;
    a->m0 = (SortRec*)fn_803774A8((a->mC = src->mC) * 12, heap);
    a->m4 = src->m4;
    fn_803FFA60(a->m0, src->m0, a->mC * 12);
    return a;
}

/* near-miss: 45%; retail uses cap in r4 directly for stw and mulli (one saved reg); mine copies it to r0 and saves r30/r31 */
extern "C" SortArr* fn_803779B8(SortArr* a, int cap, int heap, int flag)
{
    a->m10 = flag;
    a->m14 = lbl_80684970;
    a->mC = cap;
    a->m0 = (SortRec*)fn_803774A8(cap * 12, heap);
    a->m8 = 0;
    a->m4 = 0;
    return a;
}

/* near-miss: 99.3%; 7 slots differ: retail keeps mid in r11 and the 12*mid product in r9 (lwzx offset-first), mine uses r9/r0 */
extern "C" int fn_80377A14(SortArr* a, int key, int* out)
{
    int hi = a->m4 - 1;
    int lo = 0;
    *out = 0;
    while (hi >= lo) {
        int mid = (hi + lo + 1) >> 1;
        *out = mid;
        SortRec* r = a->m0;
        if (key == r[mid].key) {
            if (a->m10 != 0) {
            int n = 1;
            int j = mid + 1;
            while (key == r[j].key && j <= hi) {
                n++;
                j++;
            }
            j = *out - 1;
            while (key == r[j].key && j >= lo) {
                n++;
                j--;
            }
            *out = j + 1;
            return n;
            }
            return 1;
        }
        if (key > r[mid].key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    *out = (hi + lo + 1) >> 1;
    return 0;
}

extern int lbl_80624224;

extern "C" int fn_80377B1C(SortArr* a, int key)
{
    int idx;
    int found = fn_80377A14(a, key, &idx);
    if (found == 0 || a->m10 != 0) {
        idx += found;
        for (int i = a->m4 - 1; i >= idx; i--) {
            a->m0[i + 1] = a->m0[i];
            lbl_80624224++;
        }
        a->m0[idx].key = key;
        a->m4++;
    }
    return idx;
}

extern "C" void fn_80377BEC(SortArr* a, int idx)
{
    for (; idx < a->m4 - 1; idx++)
        a->m0[idx] = a->m0[idx + 1];
    a->m4--;
}

extern "C" int fn_80377E48(SortArr* a, int* out, int key, int flag);
extern "C" int fn_80377E04(SortArr* a, int* out, int key);

extern "C" void fn_80377C50(SortArr* a, int key)
{
    int idx;
    fn_80377E48(a, &idx, key, 0);
    fn_80377BEC(a, idx);
}

extern "C" void fn_80377C94(SortArr* a, int key)
{
    int idx;
    fn_80377E04(a, &idx, key);
    fn_80377BEC(a, idx);
}
