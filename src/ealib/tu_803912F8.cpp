/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803912F8-0x803927E4 (code-only unit, 37 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

/* FLAGS EVIDENCE (for the lead): this unit has no r13 use and its loops are not strength-reduced or turned into
 * counted (bdnz) loops. fn_803913FC and fn_80391784 match exactly with `-O2 -G0 -fno-strength-reduce`
 * (cflags_ealib plus that flag), and fn_80391E2C and fn_80391C04 as well; under the unit's current lib flags
 * (-O2 default -G8) only the loop-free functions match. The data below is declared as arrays of unknown size
 * so that -G8 does not put it in small data.
 *
 * Resource table of the MAD/VP6 file layer: lbl_806243F8[0] = entries (8 bytes each), lbl_80624400[0] = capacity,
 * lbl_80624404[0] = used count. Evidence: fn_803913FC clears n entries, fn_80391784 searches them. */
struct McEntry {
    int m0;
    void* m4;
};

struct McEntryHdr {
    char pad0[0xA];
    unsigned short mA;
};

/* Record behind McEntry::m4 (and McSlot::m0). Evidence: fn_803915D0 searches the table on the u16 at +0,
 * fn_80391734 reads +0xA, fn_80391C68 compares the bytes at +8/+9 with a tag, fn_803919B0/fn_8039188C/
 * fn_80391914 walk a byte ring buffer after the header (m4 low 7 bits and m5 size it, m6 = depth). */
struct McRec {
    unsigned short m0;
    unsigned short m2;
    unsigned char m4;
    unsigned char m5;
    volatile unsigned char m6;
    char pad7;
    unsigned char m8;
    unsigned char m9;
    unsigned short mA;
    char padC[4];
    unsigned short m10;
    unsigned short m12;
    unsigned short m14;
    char pad16[2];
    unsigned short m18[1];
};

/* 8-entry table lbl_8069B7CC: pointer to the record, then an extra word (cleared by fn_80391E2C). */
struct McSlot {
    McRec* m0;
    void* m4;
};

/* Tag word built by fn_80391C04: halfword, then the two bytes compared with McRec::m9/m8. */
struct McTag {
    unsigned short c;
    unsigned char b;
    unsigned char a;
};

/* Channel table lbl_8069B80C (fn_80391EA4 resets it, fn_80392708 tears it down): eight counters, eight
 * positions (-1 = none), then 16 channel records of 16 bytes (flag at +6, slot index at +7, buffer at +0xC). */
struct McChan {
    int m0;
    short m4;
    char m6;
    unsigned char m7;
    int m8;
    void* mC;
};
struct McState {
    int cnt[8];
    int pos[8];
    McChan ch[16];
};
extern McState lbl_8069B80C;
extern int lbl_8069B9B8[];
extern short lbl_8069B9BC[];
extern "C" void fn_80392BC0(void* p);
extern "C" void fn_80392BF4();

/* Declared as arrays of unknown size: retail reaches these with lis/lwz (not r13), i.e. this part of the
 * library was built without small data; an array of unknown size is never put in .sdata by -G8. */
extern McEntry* lbl_806243F8[];
extern int lbl_806243FC[];
extern int lbl_80624400[];
extern int lbl_80624404[];
extern McSlot lbl_8069B7CC[8];
extern int lbl_806243F4[];
extern int lbl_8069B98C[];
extern "C" void fn_803919B0(McRec* r);
extern "C" void fn_80391A3C(McRec* r);
extern "C" int fn_80391C68(McTag* k, McSlot** out);

extern "C" void fn_803912F8()
{
    lbl_806243F8[0] = 0;
    lbl_80624400[0] = 0;
    lbl_80624404[0] = 0;
    lbl_806243FC[0] = 0;
}

extern "C" void fn_80391320()
{
    lbl_806243F8[0] = 0;
    lbl_80624400[0] = 0;
    lbl_80624404[0] = 0;
    lbl_806243FC[0] = 0;
}

extern "C" void fn_80391348(int x)
{
    if (lbl_806243F4[0] != 0) {
        lbl_8069B98C[0] = x;
        if (lbl_806243F8[0] != 0) {
            for (int i = 0; i < lbl_80624400[0]; i++) {
                McRec* r = (McRec*)lbl_806243F8[0][i].m4;
                if (r != 0 && (r->m4 & 0x80)) {
                    fn_803919B0(r);
                    fn_80391A3C(r);
                }
            }
        }
    }
}

extern "C" int fn_803913F4(int x)
{
    return x << 3;
}

extern "C" void fn_803913FC(int n, McEntry* tbl)
{
    lbl_80624400[0] = n;
    lbl_806243F8[0] = tbl;
    if (tbl == 0)
        return;
    for (int i = 0; i < n; i++) {
        tbl[i].m0 = 0;
        tbl[i].m4 = 0;
    }
}

extern "C" short fn_803915D0(unsigned key, int* out)
{
    int lo = 0;
    int hi = lbl_80624404[0] - 1;
    if (lbl_806243F8[0] != 0 && lbl_80624404[0] != 0 && lo <= hi) {
        do {
            int mid = (lo + hi) / 2;
            McRec* r = (McRec*)lbl_806243F8[0][mid].m4;
            if (key == r->m0) {
                *out = lbl_806243F8[0][mid].m0;
                return mid;
            }
            if (key > r->m0)
                lo = mid + 1;
            else
                hi = mid - 1;
        } while (lo <= hi);
    }
    return -1;
}

extern "C" short fn_80391668(unsigned a, unsigned b, int* out)
{
    int lo = 0;
    int hi = lbl_80624404[0] - 1;
    if (lbl_806243F8[0] != 0 && lbl_80624404[0] != 0 && lo <= hi) {
        do {
            int mid = (lo + hi) / 2;
            McRec* r = (McRec*)lbl_806243F8[0][mid].m4;
            if (a == r->m0 && b == r->m2) {
                *out = lbl_806243F8[0][mid].m0;
                return mid;
            }
            r = (McRec*)lbl_806243F8[0][mid].m4;
            if (a > r->m0 || (a == r->m0 && b > r->m2))
                lo = mid + 1;
            else
                hi = mid - 1;
        } while (lo <= hi);
    }
    return -1;
}

extern "C" int fn_80391734(int idx, unsigned x)
{
    int r = 0;
    McEntry* tbl = lbl_806243F8[0];
    if (tbl != 0 && idx >= 0) {
        McEntryHdr* h = (McEntryHdr*)tbl[idx].m4;
        unsigned v = h->mA;
        if (v != 0xFFFF)
            r = x < v;
    }
    return r;
}

extern "C" int fn_80391784(int x)
{
    for (int i = 0; i < lbl_80624404[0]; i++) {
        if (lbl_806243F8[0][i].m0 == x)
            return i;
    }
    return -1;
}

/* near-miss (96%): retail loads the count into r0 for the guard and copies it (mr r7,r0) for the loop; 6 spellings tried. */
extern "C" void fn_803917D0(int key)
{
    if (lbl_806243F8[0] != 0) {
        int idx = fn_80391784(key);
        if (idx >= 0) {
            int n = lbl_80624404[0];
            if (idx < n) {
                McEntry* tbl = lbl_806243F8[0];
                do {
                    if (idx == n - 1) {
                        tbl[idx].m0 = 0;
                        tbl[idx].m4 = 0;
                    } else {
                        tbl[idx].m0 = tbl[idx + 1].m0;
                    }
                    tbl[idx].m4 = tbl[idx + 1].m4;
                    idx++;
                } while (idx < n);
            }
            lbl_80624404[0]--;
        }
    }
}

extern "C" void fn_8039188C(McRec* r, char v)
{
    if (r->m6 != 0) {
        int n = r->m4 & 0x7F;
        int w = r->m5;
        int n4 = n << 2;
        unsigned char* p = (unsigned char*)r + ((w * (n + 2) + 0xF) & ~3) + n4;
        int off = 0;
        if (r->m4 & 0x80)
            off = ((w + 7) / 8) + 1;
        unsigned char* q = p + off;
        unsigned char i = *q;
        if (i < r->m6)
            q[i + 1] = v;
        i = i + 1;
        if (i >= r->m6)
            i = 0;
        *q = i;
    }
}

extern "C" int fn_80391914(McRec* r, int key)
{
    int res = 0;
    int cnt = r->m6;
    if (cnt > 0) {
        int n = r->m4 & 0x7F;
        int w = r->m5;
        int n4 = n << 2;
        unsigned char* p = (unsigned char*)r + ((w * (n + 2) + 0xF) & ~3) + n4;
        int off = 0;
        if (r->m4 & 0x80)
            off = ((w + 7) / 8) + 1;
        unsigned char* q = p + off;
        int pos = *q;
        q++;
        int i = 0;
        if (i < cnt) {
            do {
                pos--;
                if (pos < 0)
                    pos = cnt - 1;
                if (q[pos] == key) {
                    res = i + 1;
                    break;
                }
                i++;
            } while (i < cnt);
        }
    }
    return res;
}

extern "C" void fn_803919B0(McRec* r)
{
    int n = r->m4 & 0x7F;
    int w = r->m5;
    int n4 = n << 2;
    unsigned char* b = (unsigned char*)r + ((w * (n + 2) + 0xF) & ~3);
    unsigned char* q = b + n4;
    if (b[n4] != 0) {
        int cnt = (w + 7) / 8;
        for (int i = 1; i <= cnt; i++)
            q[i] = 0;
    }
}

/* near-miss (with -fno-strength-reduce too): one extra `mr r0,r3` for a; 4 spellings tried. */
extern "C" int fn_80391A10(unsigned a, int b, int c)
{
    int q = b / c;
    unsigned r = b - q * c;
    if (a > r)
        return q * a + r;
    return q * a + a;
}

extern "C" void fn_80391A3C(McRec* r)
{
    int n = r->m4 & 0x7F;
    int w = r->m5;
    int n4 = n << 2;
    unsigned char* b = (unsigned char*)r + ((w * (n + 2) + 0xF) & ~3);
    int cnt = b[n4];
    unsigned char* q = b + n4;
    if (cnt > 0) {
        unsigned seed = lbl_8069B98C[0];
        seed = seed % cnt;
        unsigned a = fn_80391A10(seed, w, cnt);
        int len = fn_80391A10(seed + 1, w, cnt) - a;
        int byte = (a >> 3) + 1;
        int bit = a & 7;
        for (int i = 0; i < len; i++) {
            q[byte] |= 1 << bit;
            if (bit++ == 7) {
                bit = 0;
                byte++;
            }
        }
    }
}

union McTagU {
    unsigned w;
    struct {
        unsigned short c;
        unsigned char b;
        unsigned char a;
    } f;
};

extern "C" int fn_80391444();

/* near-miss 99.1%: same code; retail keeps the record pointer in r30 and the result in r29 (ours swapped), and adds
 * the row offset first in the shift loop. */
extern "C" int fn_80391B1C(McRec* r)
{
    int ret = -1;
    if (lbl_806243F8[0] != 0) {
        int idx = fn_80391444();
        if (idx < lbl_80624400[0] && idx >= 0) {
            if (r->m4 & 0x80)
                fn_80391A3C(r);
            int off = idx * 8;
            int i = lbl_80624404[0];
            if (i > idx) {
                McEntry* t = lbl_806243F8[0];
                do {
                    McEntry* e = (McEntry*)(i * 8 + (char*)t);
                    i--;
                    *e = e[-1];
                } while (i > idx);
            }
            McEntry* tab = lbl_806243F8[0];
            ret = lbl_806243FC[0];
            int n = lbl_80624404[0];
            tab[idx].m4 = r;
            tab[idx].m0 = ret;
            lbl_806243FC[0] = ret + 1;
            lbl_80624404[0] = n + 1;
        }
    }
    return ret;
}

extern "C" unsigned fn_80391C04(unsigned char a, unsigned char b, unsigned short c)
{
    McTagU t;
    t.f.b = b;
    t.f.c = c;
    t.f.a = a;
    return *(unsigned*)&t;
}

/* near-miss: lhzx operand order and the r0/r9 temps swapped (retail indexes (i*2, base+0x18)); 12 spellings tried. */
extern "C" unsigned short* fn_80391C20(McRec* r, int key)
{
    int i = 0;
    int n = r->m10;
    while (i < n) {
        unsigned short* e = (unsigned short*)((char*)r + r->m18[i] * 4);
        if (*e == key)
            return e;
        i++;
    }
    return 0;
}

extern "C" int fn_80391C68(McTag* k, McSlot** out)
{
    int r = 0;
    int i = 0;
    do {
        McRec* n = lbl_8069B7CC[i].m0;
        if (n != 0 && n->m9 == k->b && n->m8 == k->a) {
            r = 1;
            *out = &lbl_8069B7CC[i];
            break;
        }
        i++;
    } while (i <= 7);
    return r;
}

extern "C" unsigned short* fn_80391CCC(McTag* k)
{
    unsigned short* r = 0;
    McSlot* s;
    if (fn_80391C68(k, &s))
        r = fn_80391C20(s->m0, k->c);
    return r;
}

extern "C" int fn_80391D20(McTag* k, int* out)
{
    int r = 0;
    McSlot* s;
    if (fn_80391C68(k, &s)) {
        r = 1;
        *out = (int)s->m4;
    }
    return r;
}

extern "C" int fn_80391D70(McTag* k, int* out)
{
    int r = 0;
    McSlot* s;
    if (fn_80391C68(k, &s)) {
        r = 1;
        *out = s->m0->m9;
    }
    return r;
}

/* near-miss (98.7%): slot pointer in r10 and the halfword in r9, retail has r9 and r0; 11 spellings tried. */
extern "C" int fn_80391DC4(McTag* k, void** out)
{
    int r = 0;
    McSlot* s;
    if (fn_80391C68(k, &s)) {
        r = 1;
        McRec* n = s->m0;
        *out = (char*)n + (((n->m10 * 2 + 3) & ~3) + 0x18);
    }
    return r;
}

extern "C" void fn_80391E2C()
{
    for (int i = 0; i < 8; i++) {
        lbl_8069B7CC[i].m0 = 0;
        lbl_8069B7CC[i].m4 = 0;
    }
}

extern "C" unsigned short fn_80391E5C(McTag* k)
{
    unsigned short r = 0;
    McSlot* s;
    if (fn_80391C68(k, &s))
        r = s->m0->m14;
    return r;
}

struct McRaw {
    char pad0[0x44];
    short m44;
    char m46;
    unsigned char m47;
};

extern "C" void fn_80391EA4()
{
    int i;
    for (i = 0; i <= 7; i++) {
        lbl_8069B80C.cnt[i] = 0;
        lbl_8069B80C.pos[i] = -1;
    }
    for (i = 0; i <= 15; i++) {
        McRaw* p = (McRaw*)((char*)&lbl_8069B80C + i * 16);
        p->m46 = 0;
        p->m44 = 0;
        lbl_8069B80C.ch[i].m0 = 0;
        lbl_8069B80C.ch[i].m8 = 0;
        p->m47 = 0xFF;
        if (lbl_8069B80C.ch[i].mC != 0)
            fn_80392BC0(lbl_8069B80C.ch[i].mC);
        lbl_8069B80C.ch[i].mC = 0;
    }
    lbl_8069B9B8[0] = 0;
    lbl_8069B9BC[0] = 0;
}

struct McRecW {
    unsigned short m0;
    unsigned short m2;
    unsigned short m4;
};

extern "C" int fn_8039582C();
extern "C" void fn_803927E4(int i);

extern "C" int fn_80391F70(unsigned x, int y)
{
    int ret = -1;
    int skip = -1;
    int i = 0;
    do {
        if (lbl_8069B80C.ch[i].m6 == 0) {
            ret = i;
            goto done;
        }
        i++;
    } while (i <= 15);
    {
        unsigned now = fn_8039582C();
        i = 0;
        do {
            McRecW* r = (McRecW*)lbl_8069B80C.ch[i].m8;
            if (r->m2 != 0 && now - lbl_8069B80C.ch[i].m0 > r->m2 && skip != i) {
                fn_803927E4(i);
                ret = i;
                goto done;
            }
            i++;
        } while (i <= 15);
    }
    i = 0;
    do {
        McRecW* r = (McRecW*)lbl_8069B80C.ch[i].m8;
        int slot = lbl_8069B80C.ch[i].m7;
        if (r->m4 <= x && slot == y) {
            lbl_8069B80C.ch[i].m6 = 0;
            ret = i;
            lbl_8069B80C.cnt[slot] -= 1;
            goto done;
        }
        i++;
    } while (i <= 15);
done:
    return ret;
}

/* near-miss: retail forms lbl+0x20 first and indexes it; 3 spellings of the +8 index tried. */
extern "C" int fn_80392098(int i)
{
    return (unsigned)lbl_8069B80C.pos[i] <= 15;
}

struct McRecV {
    char pad0[4];
    unsigned short m4;
    char pad6[3];
    signed char m9;
    unsigned char mA;
};

extern int lbl_80624410[];
extern "C" int fn_80394FD4(int a, int b);
extern "C" int fn_8039582C();
extern "C" int fn_80391F70(unsigned x, int y);
extern "C" void fn_80392988(int slot);

inline unsigned char Lo8(int* p)
{
    return *((unsigned char*)p + 3);
}

extern "C" int fn_803920BC(int* arg0)
{
    int r = 0;
    int spC;
    McTag tag;
    int* pSp;
    if (lbl_80624410[0] == 0) {
        lbl_80624410[0] = 1;
        if (arg0 != 0) {
            *(int*)&tag = *arg0;
            McRecV* o = (McRecV*)fn_80391CCC(&tag);
            if (o != 0 && fn_80391D20(&tag, &spC) != 0) {
                int lim = o->m9;
                if (fn_80394FD4(100, -1) <= lim) {
                    int ch = fn_80391F70(o->m4, spC);
                    if (ch >= 0) {
                        int now = fn_8039582C();
                        if (now == lbl_8069B9B8[0])
                            lbl_8069B9BC[0] += 1;
                        else
                            lbl_8069B9BC[0] = 0;
                        McRaw* p = (McRaw*)((char*)&lbl_8069B80C + ch * 16);
                        lbl_8069B80C.ch[ch].m8 = (int)o;
                        p->m47 = Lo8(&spC);
                        p->m44 = lbl_8069B9BC[0];
                        lbl_8069B9B8[0] = now;
                        lbl_8069B80C.ch[ch].m0 = now;
                        if (lbl_8069B80C.ch[ch].mC != 0)
                            fn_80392BC0(lbl_8069B80C.ch[ch].mC);
                        lbl_8069B80C.ch[ch].mC = arg0;
                        lbl_8069B80C.cnt[spC] += 1;
                        p->m46 = 1;
                        lbl_8069B80C.pos[spC] = ch;
                        if (o->mA & 0x20)
                            fn_80392988(spC);
                        r = 1;
                    }
                }
            }
        }
    }
    lbl_80624410[0] = 0;
    return r;
}

extern "C" void fn_80392388(int* p)
{
    p[0] = 0;
    p[1] = 0;
}

struct McShortList {
    int m0;
    unsigned short* m4;
};

extern "C" int fn_80392398(int x, McShortList* s)
{
    int r = 0;
    for (int i = 0; i < s->m0; i++) {
        if (s->m4[i] == x) {
            r = 1;
            break;
        }
    }
    return r;
}

extern "C" void fn_80392708()
{
    int i;
    for (i = 0; i <= 15; i++) {
        int off = i * 16;
        McRaw* p = (McRaw*)((char*)&lbl_8069B80C + off);
        if (p->m46 != 0) {
            p->m46 = 0;
            if (lbl_8069B80C.ch[i].mC != 0) {
                fn_80392BC0(lbl_8069B80C.ch[i].mC);
                lbl_8069B80C.ch[i].mC = 0;
            }
            lbl_8069B80C.cnt[p->m47]--;
        }
    }
    for (i = 0; i <= 7; i++) {
        int v = lbl_8069B80C.cnt[i];
        lbl_8069B80C.pos[i] = -1;
        if (v != 0)
            lbl_8069B80C.cnt[i] = 0;
    }
    fn_80392BF4();
}

extern int lbl_806E2A50[];

extern "C" int fn_803927D0(int i) { return lbl_8069B80C.cnt[i]; }
