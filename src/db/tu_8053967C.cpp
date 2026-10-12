/*
 * Database overlay code, .database_codeoverlay 0x8053967C-0x8053CC9C (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8053967C.h"

typedef Db8053967C_List L;
typedef Db8053967C_Rost R;
typedef Db8053967C_Idx X;
typedef Db8053967C_Obj58 O58;

/* Q18 types */
struct Db8053967C_ElemVT {
    char pad0[0x10];
    short delta;
    short padA;
    void (*pfn)(void* self, int a, void* s);
};

struct Db8053967C_Row {
    unsigned char b[12];
    int s[9];
};
struct Db8053967C_Tab {
    int* m0;
    char pad4[0xEC];
    Db8053967C_Row r[1];
};

struct Unk8007DB74_A;
void fn_8007DEF8(Unk8007DB74_A* a, int id, int k, int m, int x);
void fn_8007F2EC(Unk8007F198_A* a, int id, int b);

int fn_800A2AE8(void* g);
/* end Q18 types */

extern "C" {
/* Q18 protos */
void fn_8053967C(L* self);
void fn_8053971C(L* self);
void fn_80539900(L* self, int a);
int fn_805399BC(int k);
int fn_80539A84(int k);
void fn_80539AE8(L* self, int a);
void fn_80539B84(L* self);
void fn_80539C44(L* self, int a);
void fn_80539EDC(L* self, int a);
void fn_80539FC0(L* self);
void fn_8053A190();
void fn_8053A1B0();
void fn_8053ACB8(X* x, int v);
void fn_8053AF9C(X* x, int a, int b, int c);
unsigned char fn_8053B210(R* r, int id);
void fn_8053B450(R* r, int id);
void fn_8053B6A4(R* r);
unsigned fn_8053B6CC(R* r, int id);
void fn_8053B720(R* self, int mode, Unk80084910_VObj* strm);
int fn_8053B824(R* r, int v);
void fn_8053B85C(R* r, int id);
int fn_8053B8C0(R* r);
int fn_8053B900(R* r, int id);
int fn_8053B934(R* r, int h, int id, int val);
void fn_8053B980(R* r, int h, int id);
int fn_8053BA1C(R* r, int h);
void fn_8053BA64(R* r, int h);
void fn_8053BA94(R* r);
int fn_8053BAD0(R* r, int h, int id, int now);
void fn_8053BE58(O58* o);
char* fn_8053C40C(O58* o, int id);
void fn_8053C4B0(O58* self, int mode, Unk80084910_VObj* strm);
int fn_8053CA58(X* x);
int fn_8053CA8C(X* x, int i);
unsigned char fn_8053CAD4(X* x, int i);
int fn_8053CAE0(X* x);
void fn_8053CB1C(X* x, int id);
void fn_8053CB94(X* x, int on, unsigned k);
void fn_8053CBF8(X* x);
void fn_8053CC1C(X* x);
/* end Q18 protos */

/* Q18 decls */
void fn_8053A1D0(R* r, int mode, Unk80084910_VObj* strm);
extern const char lbl_805FEC48[];
extern const char lbl_805FEC50[];
extern const char lbl_805FEC5C[];
extern const char lbl_805FEC64[];
void fn_8053B258(R* r, int id);
/* end Q18 decls */

DB_OVERLAY void fn_8053967C(L* self)
{
    fn_8040074C(self->m0, self->m8 * 4);
    self->m4 = 0;
    self->mC = 0;
    self->m14 = 0;
    unsigned i = 0;
    int off = 0;
    do {
        int h = fn_800736EC(lbl_80622AC4[i]);
        if (self->m4 < self->m8) {
            self->m0[self->m4] = h;
            self->m4++;
        }
        i++;
        off += 4;
    } while (i <= 29);
    self->m14 = 1;
}

DB_OVERLAY void fn_8053971C(L* self)
{
    fn_8040074C(self->m0, self->m8 * 4);
    Unk8007A4DC_Screen* s = (Unk8007A4DC_Screen*)lbl_8061930C;
    self->m4 = 0;
    self->mC = 0;
    self->m14 = 0;
    unsigned n = s->fn_8007B1EC();
    unsigned i;
    for (i = 1; i < n; i++) {
        if (s->fn_8007A8DC(0xB, i) == 0) {
            int v = s->fn_800728BC(i);
            if (self->m4 < self->m8) {
                self->m0[self->m4] = v;
                self->m4++;
            }
        }
    }
    Db8053E240_Tmp t;
    int buf[0x82];
    Db8053E240_Tmp* q = &t;
    q->C1(buf, 0x82);
    q->C2();
    q->C3(lbl_8064A2A8);
    fn_805371C4(q, 0x71FFFFFF);
    unsigned j;
    for (j = 0; j < q->m4; j++) {
        int id = t.At(j);
        fn_8007F2EC((Unk8007F198_A*)s, id, 0);
        int k = 0;
        do {
            int m = 0;
            do {
                int x = m;
                if (m == 0 && (k == 0 || k == 2))
                    x = 9;
                fn_8007DEF8((Unk8007DB74_A*)s, id, k, m, x);
                m++;
            } while (m <= 8);
            k++;
        } while (k <= 3);
    }
    t.vp = lbl_8064A550;
    self->m14 = 1;
}

DB_OVERLAY void fn_80539900(L* self, int a)
{
    fn_8040074C(self->m0, self->m8 * 4);
    Unk8007F198_A* scr = (Unk8007F198_A*)lbl_8061930C;
    self->m4 = 0;
    self->mC = 0;
    self->m14 = 0;
    unsigned i = 0;
    unsigned n = fn_8007F488(scr, a);
    for (; i < n; i++) {
        int v = fn_8007F4D0(scr, a, i);
        if (self->m4 < self->m8) {
            self->m0[self->m4] = v;
            self->m4++;
        }
    }
    self->m14 = 1;
}

DB_OVERLAY int fn_805399BC(int k)
{
    switch (k) {
    case 0:
        return 0x7;
    case 1:
        return 0x38;
    case 2:
        return 0x1C0;
    case 3:
        return 0x1E00;
    case 4:
        return 0x6000;
    case 5:
        return 0x18000;
    case 6:
        return 0x60000;
    case 7:
        return 0x180000;
    case 8:
        return 0x600000;
    case 9:
        return 0x1800000;
    }
    return 0x7;
}

DB_OVERLAY int fn_80539A84(int k)
{
    switch (k) {
    case 0:
        return 0x2000003F;
    case 1:
        return 0x20001FC0;
    case 2:
        return 0x2007E000;
    case 3:
        return 0x21F80000;
    }
    return 0x2000003F;
}

DB_OVERLAY void fn_80539AE8(L* self, int a)
{
    unsigned i = 0;
    int t = fn_80083FC0(a);
    for (; i < self->m4; i++) {
        int o = i * 4;
        int k = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_80075948(*(int*)((char*)self->m0 + o));
        int v = ((Unk8007B2B0_Screen*)lbl_8061930C)->fn_8007B320(t, k);
        if (i >= self->m4)
            self->m4 = i + 1;
        self->m0[i] = v;
    }
}

DB_OVERLAY void fn_80539B84(L* self)
{
    Unk8007A4DC_Screen* scr = (Unk8007A4DC_Screen*)lbl_8061930C;
    unsigned i = 0;
    for (; i < self->m4;) {
        int o = i * 4;
        if (scr->fn_8007A6A0(0x19, *(int*)((char*)self->m0 + o)) == 0) {
            if (i < self->m4) {
                for (unsigned j = i; j < self->m4; j++)
                    self->m0[j] = self->m0[j + 1];
                self->m4--;
            }
        } else {
            i++;
        }
    }
}

DB_OVERLAY void fn_80539C44(L* self, int a)
{
    fn_8040074C(self->m0, self->m8 * 4);
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    self->m4 = 0;
    self->mC = 0;
    self->m14 = 0;
    int p0 = 0;
    int p1 = 0;
    unsigned n = s->fn_8007BD94(a);
    unsigned h1 = fn_8007366C(lbl_805FEC48, lbl_805FEC50);
    unsigned h2 = fn_8007366C(lbl_805FEC5C, lbl_805FEC64);
    int idx = s->fn_8007DA28();
    if (idx != -1) {
        p0 = s->fn_8007D4AC(idx, 0) == 1;
        p1 = s->fn_8007D4AC(idx, 1) == 1;
    }
    unsigned i = fn_8008FCC8(a) == 1;
    for (; i < n; i++) {
        int v = s->fn_8007BE10(a, i);
        if (v == h1) {
            if (p0 != 1)
                continue;
        } else if (v == h2) {
            if (p1 != 1)
                continue;
        }
        if (self->m4 < self->m8) {
            self->m0[self->m4] = v;
            self->m4++;
        }
    }
    self->m14 = 1;
}

DB_OVERLAY void fn_80539EDC(L* self, int a)
{
    fn_8040074C(self->m0, self->m8 * 4);
    Unk8007B2B0_Screen* scr = (Unk8007B2B0_Screen*)lbl_8061930C;
    self->m4 = 0;
    self->mC = 0;
    self->m14 = 0;
    unsigned n = scr->fn_8007BD94(a);
    unsigned i = fn_8008FCC8(a) == 1;
    for (; i < n; i++) {
        int v = scr->fn_8007BE10(a, i);
        if (fn_800902B0(a, v) == 1) {
            if (self->m4 < self->m8) {
                self->m0[self->m4] = v;
                self->m4++;
            }
        }
    }
    self->m14 = 1;
}

DB_OVERLAY void fn_80539FC0(L* self)
{
    fn_8040074C(self->m0, self->m8 * 4);
    self->m4 = 0;
    self->mC = 0;
    self->m14 = 0;
    Unk8006A138_It<4> it(0);
    int e = 0;
    do {
        fn_80539C44(self, e);
        e = it.Next();
    } while (e <= 4);
    self->m14 = 1;
}

DB_OVERLAY void fn_8053A190()
{
    fn_803791BC();
}

DB_OVERLAY void fn_8053A1B0()
{
    fn_803791BC();
}

/* near-miss: retail loads the count word once and clrlwi's it at each compare; ours narrows to lbz */
DB_OVERLAY void fn_8053ACB8(X* x, int v)
{
    int i = 0;
    while (i < fn_8053CA58(x)) {
        if (fn_8053CA8C(x, i) == v) {
            x->m14.mC = i;
            return;
        }
        i++;
    }
}

/* near-miss: 99.9%; only the loop exit compare differs (retail cmpwi r11,10 / blt, ours folds it to cmpwi 9 / ble) */
DB_OVERLAY void fn_8053AF9C(X* x, int a, int b, int c)
{
    Db8053967C_Tab* tb = (Db8053967C_Tab*)x;
    Unk8006A138_It<9> it(0);
    int idx = 0;
    do {
        int v;
        if (idx == 0) {
            v = fn_8053CAE0(x);
        } else {
            unsigned char t = tb->r[a].b[idx];
            if (t != 0xFF) {
                int o = t * 4;
                v = *(int*)((char*)tb->m0 + o);
            } else {
                v = 0;
            }
        }
        if (c == v) {
            tb->r[a].s[b] = it.v;
            return;
        }
        idx = it.Next();
    } while (idx <= 9);
}

DB_OVERLAY unsigned char fn_8053B210(R* r, int id)
{
    unsigned char i = 0;
    for (; i < (unsigned char)r->m4; i++) {
        if (r->m0[i] == id)
            return i;
    }
    return 0xFF;
}

DB_OVERLAY void fn_8053B450(R* r, int id)
{
    unsigned i;
    for (i = 0; i < r->m4; i++) {
        int o = i * 4;
        if (*(int*)((char*)r->m0 + o) == id) {
            fn_8053B258(r, id);
            break;
        }
    }
    for (i = 0; i <= 1; i++) {
        unsigned j;
        for (j = 0; j <= 1; j++) {
            if (r->m1B0[i][j].id == id) {
                fn_8053B980(r, i, id);
                break;
            }
        }
    }
    for (i = 0; i <= 2; i++) {
        if (r->m1D0[i] == id) {
            fn_8053B85C(r, id);
            break;
        }
    }
}

DB_OVERLAY void fn_8053B6A4(R* r)
{
    fn_8040074C(r->m1D0, 0xC);
}

/* near-miss: lwzx base/index order (retail: base m0, index i*4) */
DB_OVERLAY unsigned fn_8053B6CC(R* r, int id)
{
    unsigned n = r->m4;
    unsigned i = 0;
    unsigned res = -1;
    for (; i < n; i++) {
        if (id == r->m0[i]) {
            res = i;
            break;
        }
    }
    return res;
}

DB_OVERLAY void fn_8053B720(R* self, int mode, Unk80084910_VObj* strm)
{
    Unk80084910_VT* vt = strm->m4;
    unsigned i = 0;
    char* p = (char*)self + 0x1D0;
    vt->pfn((char*)strm + vt->delta, mode, (char*)self + 0xF0, 0xC0);
    fn_8053A1D0(self, mode, strm);
    do {
        vt = strm->m4;
        i++;
        vt->pfn((char*)strm + vt->delta, mode, p, 4);
        p += 4;
    } while (i <= 2);
    i = 0;
    char* w = (char*)self + 0x1C0;
    char* q = (char*)self + 0x1B0;
    do {
        vt = strm->m4;
        i++;
        vt->pfn((char*)strm + vt->delta, mode, q, 8);
        q += 8;
        vt = strm->m4;
        vt->pfn((char*)strm + vt->delta, mode, w, 8);
        w += 8;
    } while (i <= 1);
}

DB_OVERLAY int fn_8053B824(R* r, int v)
{
    for (int i = 0; i < 3; i++) {
        if (r->m1D0[i] == 0) {
            r->m1D0[i] = v;
            return 1;
        }
    }
    return 0;
}

DB_OVERLAY void fn_8053B85C(R* r, int id)
{
    int found = 0;
    for (int i = 0; i < 3; i++) {
        if (r->m1D0[i] == id)
            found = 1;
        if (found) {
            if (i == 2)
                r->m1D0[i] = 0;
            else
                r->m1D0[i] = r->m1D0[i + 1];
        }
    }
}

/* near-miss: retail keeps &m1D0[0] in a register and walks three lockstep counters */
DB_OVERLAY int fn_8053B8C0(R* r)
{
    int n = 0;
    unsigned k = 0;
    if (r->m1D0[0] != 0) {
        do {
            k++;
            n++;
            if (k > 2)
                return n;
        } while (r->m1D0[k] != 0);
    }
    return n;
}

DB_OVERLAY int fn_8053B900(R* r, int id)
{
    for (int i = 0; i < 3; i++) {
        if (r->m1D0[i] == id)
            return 1;
    }
    return 0;
}

DB_OVERLAY int fn_8053B934(R* r, int h, int id, int val)
{
    for (unsigned k = 0; k < 2; k++) {
        if (r->m1B0[h][k].id == 0) {
            r->m1B0[h][k].id = id;
            r->m1B0[h][k].val = val;
            return 1;
        }
    }
    return 0;
}

/* near-miss: 4 slots longer in retail (the k == 1 arm keeps separate zero stores) */
DB_OVERLAY void fn_8053B980(R* r, int h, int id)
{
    int found = 0;
    for (unsigned k = 0; k < 2; k++) {
        if (r->m1B0[h][k].id == id)
            found = 1;
        if (found) {
            if (k == 1) {
                r->m1B0[h][1].id = 0;
                r->m1B0[h][1].val = 0;
            } else {
                r->m1B0[h][k] = r->m1B0[h][k + 1];
            }
        }
    }
}

DB_OVERLAY int fn_8053BA1C(R* r, int h)
{
    int n = 0;
    unsigned k = 0;
    if (r->m1B0[h][0].id != 0) {
        do {
            n++;
            k++;
            if (k > 1)
                return n;
        } while (r->m1B0[h][k].id != 0);
    }
    return n;
}

DB_OVERLAY void fn_8053BA64(R* r, int h)
{
    fn_8040074C(r->m1B0[h], 0x10);
}

DB_OVERLAY void fn_8053BA94(R* r)
{
    fn_8053BA64(r, 0);
    fn_8053BA64(r, 1);
}

/* near-miss: callee-saved assignment (retail keeps the found value in r29) */
DB_OVERLAY int fn_8053BAD0(R* r, int h, int id, int now)
{
    unsigned n = fn_8053BA1C(r, h);
    int t = 0;
    unsigned k = 0;
    for (; k < n; k++) {
        if (r->m1B0[h][k].id == id)
            t = r->m1B0[h][k].val;
    }
    if (t == 0)
        return 0;
    int lim = 0x3C;
    if (h == 0)
        lim = 0xF;
    int d = lim - (now - t);
    int res = 0;
    if (d > 0)
        res = d;
    return res;
}

DB_OVERLAY void fn_8053BE58(O58* o)
{
    o->m4->m4 = 0;
    o->mC = 0;
    unsigned i = 0;
    for (; i < o->m8; i++)
        fn_8053B548(o->m10 + i * 0x1E0, 0);
}

/* near-miss: retail hoists the sp8 load above the compare and lays out the found arm first */
DB_OVERLAY char* fn_8053C40C(O58* o, int id)
{
    int sp8 = -1;
    int spC = -1;
    char* r;
    if (fn_80377E90(o->m4, &sp8, &spC, id) == 1) {
        r = o->m10 + sp8 * 0x1E0;
    } else {
        int c = o->mC;
        fn_80377CD8(o->m4, c, c, id);
        int t = o->mC;
        o->mC = t + 1;
        r = o->m10 + t * 0x1E0;
    }
    return r;
}

DB_OVERLAY void fn_8053C4B0(O58* self, int mode, Unk80084910_VObj* strm)
{
    Unk80084910_VT* vt = strm->m4;
    unsigned i = 0;
    vt->pfn((char*)strm + vt->delta, mode, &self->mC, 4);
    if (i < self->m8) {
        int off = 0;
        do {
            char* rec = (char*)(off + (int)self->m10);
            i++;
            Db8053967C_ElemVT* ev = *(Db8053967C_ElemVT**)(rec + 0x1DC);
            off += 0x1E0;
            ev->pfn(rec + ev->delta, mode, strm);
        } while (i < self->m8);
    }
}

DB_OVERLAY int fn_8053CA58(X* x)
{
    int n = 0;
    for (int i = 0; i < 5; i++) {
        if (x->m14.m0[i] != 0xFF)
            n++;
    }
    return n;
}

DB_OVERLAY int fn_8053CA8C(X* x, int i)
{
    int idx = fn_8053CAD4(x, i);
    int r;
    if (idx != 0xFF) {
        int o = idx * 4;
        r = *(int*)((char*)x->m0 + o);
    } else {
        r = 0;
    }
    return r;
}

DB_OVERLAY unsigned char fn_8053CAD4(X* x, int i)
{
    return x->m14.m0[i];
}

DB_OVERLAY int fn_8053CAE0(X* x)
{
    Db8053967C_Bytes* p = &x->m14;
    unsigned cur = p->mC;
    if (p->m4 > cur) {
        unsigned char b = x->m14.m0[cur];
        if (b != 0xFF) {
            int o = b * 4;
            return *(int*)((char*)x->m0 + o);
        }
    }
    return 0;
}

DB_OVERLAY void fn_8053CB1C(X* x, int id)
{
    unsigned char v = fn_8053B6CC((R*)x, id);
    for (unsigned k = 0; k < 5; k++) {
        Db8053967C_Bytes* p = &x->m14;
        if (x->m14.m0[k] == 0xFF) {
            if (k >= p->m4)
                p->m4 = k + 1;
            x->m14.m0[k] = v;
            return;
        }
    }
}

DB_OVERLAY void fn_8053CB94(X* x, int on, unsigned k)
{
    unsigned char v;
    if (on != 0)
        v = fn_8053B6CC((R*)x, on);
    else
        v = 0xFF;
    Db8053967C_Bytes* p = &x->m14;
    if (k >= p->m4)
        p->m4 = k + 1;
    x->m14.m0[k] = v;
}

DB_OVERLAY void fn_8053CBF8(X* x)
{
    Db8053967C_Bytes* p = &x->m14;
    p->mC = (p->mC + 1) % p->m4;
}

DB_OVERLAY void fn_8053CC1C(X* x)
{
    x->m14.mC = 0;
}

static inline int IdxOf(Db8053967C_Bytes* p, int v)
{
    for (unsigned i = 0; i < p->m4; i++) {
        if (p->m0[i] == v)
            return i;
    }
    return -1;
}
DB_OVERLAY int fn_8053CC28(X* x, int id)
{
    unsigned char idx = fn_8053B210((R*)x, id);
    if (idx != 0xFF)
        return IdxOf(&x->m14, idx);
    return -1;
}

}
