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

struct Db8053967C_LV {
    int* m0;
    unsigned m4;
    unsigned m8;
    int mC;
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual int s13(int key);
};
DB_OVERLAY void fn_80539DB4(L* self, int a)
{
    fn_80539C44(self, a);
    unsigned i = 0;
    int n = fn_8008FBE8(a);
    Unk8007B2B0_Screen* s = (Unk8007B2B0_Screen*)lbl_8061930C;
    unsigned cnt = s->fn_8007B2B0();
    for (; i < cnt; i++) {
        if (s->fn_8007B648(0xE, i) != 0) {
            for (int j = 0; j < n; j++) {
                int h = s->fn_8007B610(fn_8008FE14(fn_8008FC40(a, j)), i);
                if (h != 0) {
                    unsigned k = ((Db8053967C_LV*)self)->s13(h);
                    if (k != (unsigned)-1 && k < self->m4) {
                        for (; k < self->m4; k++)
                            self->m0[k] = self->m0[k + 1];
                        self->m4--;
                    }
                }
            }
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

extern "C" int fn_800787E8(void* g, int a, int b);
DB_OVERLAY void fn_8053A044(L* self, int a, int dir)
{
    int keys[0x1BE];
    unsigned n = self->m4;
    void* g = lbl_8061930C;
    unsigned i = 0;
    for (i = 0; i < n; i++) {
        int o = i * 4;
        keys[i] = fn_800787E8(g, a, *(int*)((char*)self->m0 + o));
    }
    int* kp = keys;
    unsigned i2 = 0;
    unsigned n3 = self->m4;
    for (; i2 < n3; i2++) {
        for (unsigned j = i2 + 1; j < n3; j++) {
            if ((dir == 1 && kp[i2] < kp[j]) || (dir == 0 && kp[i2] > kp[j])) {
                int x = kp[j];
                int y = kp[i2];
                kp[i2] = x;
                kp[j] = y;
                int oi = i2 * 4;
                int vi = *(int*)((char*)self->m0 + oi);
                int oj = j * 4;
                int vj = *(int*)((char*)self->m0 + oj);
                if (i2 >= self->m4)
                    self->m4 = i2 + 1;
                self->m0[i2] = vj;
                if (j >= self->m4)
                    self->m4 = j + 1;
                self->m0[j] = vi;
            }
        }
    }
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

DB_OVERLAY int fn_8053B064(R* r)
{
    int cnt = 0;
    int i = 0;
    unsigned j;
    int nb = fn_8053CA58((X*)r);
    unsigned char n = r->m4;
    int v68 = *(int*)((char*)r + 0x68);
    Unk8007A4DC_Screen* s = (Unk8007A4DC_Screen*)lbl_8061930C;
    if (n != 0) {
        do {
            int o = (unsigned char)i * 4;
            if (s->fn_8007A270(*(int*)((char*)r->m0 + o)) == 0)
                cnt++;
            i++;
        } while (i < n);
    }
    Db8053967C_Tab* tb = (Db8053967C_Tab*)r;
    for (j = 0; j <= 3; j++) {
        int flag = 0;
        if (j == 0 || j == 2)
            flag = 1;
        for (i = 0; i != 10; i++) {
            if (i == 0)
                continue;
            if (i == 9) {
                if (flag == 0)
                    continue;
            }
            if (tb->r[j].b[i] == 0xFF)
                return 4;
        }
    }
    if (cnt <= 8)
        return 3;
    if (nb <= 4)
        return 1;
    if (v68 <= 0)
        return 2;
    for (j = 0; j < 2; j++) {
        unsigned n2 = fn_8053BA1C(r, j);
        for (i = 0; (unsigned)i < n2; i++) {
            int off = i * 8 + j * 16;
            char* bs = (char*)r + 0x1B0;
            int id = *(int*)(bs + off);
            if (fn_8053BAD0(r, j, id, fn_800A2AE8(lbl_80619948)) <= 0)
                return 6;
        }
    }
    return 0;
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

struct Db8053967C_BL {
    char* m0;
    unsigned m4;
    unsigned m8;
    unsigned mC;
    int m10;
};
struct Db8053967C_RecB {
    int* m0;
    unsigned m4;
    unsigned m8;
    unsigned mC;
    int pad10;
    Db8053967C_BL bl[5];
    char pad78[0xF0 - 0x78];
    Db8053967C_Row r[4];
};
DB_OVERLAY void fn_8053B548(char* p, int v)
{
    Db8053967C_RecB* self = (Db8053967C_RecB*)p;
    for (unsigned i = 0; i < 4; i++) {
        for (int k = 0; k < 10; k++)
            self->r[i].b[k] = 0xFF;
        for (int k = 0; k < 9; k++)
            self->r[i].s[k] = 10;
    }
    Db8053967C_BL* q;
    for (unsigned k = 0; k < 5; k++) {
        q = &self->bl[0];
        if (k >= q->m4)
            q->m4 = k + 1;
        self->bl[0].m0[k] = -1;
    }
    q->mC = 0;
    Db8053967C_BL* p1 = &self->bl[1];
    Db8053967C_BL* p2 = &self->bl[2];
    Db8053967C_BL* p3 = &self->bl[3];
    Db8053967C_BL* p4 = &self->bl[4];
    fn_8040074C(self->bl[1].m0, p1->m8);
    p1->m4 = 0;
    p1->mC = 0;
    fn_8040074C(self->bl[2].m0, p2->m8);
    p2->m4 = 0;
    p2->mC = 0;
    fn_8040074C(self->bl[3].m0, p3->m8);
    p3->m4 = 0;
    p3->mC = 0;
    fn_8040074C(self->bl[4].m0, p4->m8);
    p4->m4 = 0;
    p4->mC = 0;
    fn_8040074C(self->m0, self->m8 * 4);
    self->m4 = 0;
    self->mC = 0;
    fn_8053B6A4((R*)self);
    if (v == 0)
        fn_8053BA94((R*)self);
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

struct Db8053967C_RecV {
    char pad0[0x1DC];
    virtual ~Db8053967C_RecV();
};
struct Db8053967C_Obj58D {
    char pad0[0x10];
    Db8053967C_RecV* m10;
    char pad14[0x40];
    const void* m54;
};
extern char lbl_80684660[];
DB_OVERLAY void fn_8053BDA8(Db8053967C_Obj58D* self, int chrg)
{
    self->m54 = lbl_80684660;
    if (self->m10) {
        delete[] self->m10;
        self->m10 = 0;
    }
    if (chrg & 1)
        delete self;
}

DB_OVERLAY void fn_8053BE58(O58* o)
{
    o->m4->m4 = 0;
    o->mC = 0;
    unsigned i = 0;
    for (; i < o->m8; i++)
        fn_8053B548(o->m10 + i * 0x1E0, 0);
}

struct Db8053967C_Ld {
    int m0;
    char pad4[0x50];
    virtual void s1();
    virtual void s2();
    virtual int s3();
};
extern "C" char* fn_802B9300(const char* path, int a, int b, unsigned* n);
extern "C" void fn_802B961C(char* buf, int b);
extern "C" int fn_80409DAC(const char* s);
extern "C" int fn_8053C550(const char* s);
extern "C" void fn_8053C6F4(R* r, int id, int kind, int v);
extern "C" int fn_805A1958(R* r, int a, int b, unsigned char c);
/* near-miss: 98.0%; the two int stores at 0xFC + n*4 + K: retail does slwi/addi then base+index (stwx), ours addi/slwi (same count) */
DB_OVERLAY void fn_8053BEC8(Db8053967C_Ld* self)
{
    if (self->s3() == self->m0)
        return;
    fn_8053BE58((O58*)self);
    unsigned len = 0;
    char* buf = fn_802B9300((char*)self + 0x14, 0x100, 4, &len);
    char* end = buf + len;
    char* p = buf;
    while (*p != ';')
        p++;
    int last = 0;
    R* cur = 0;
    while (p < end) {
        while (*p != ',')
            p++;
        while (*p != ' ')
            p++;
        p++;
        int team = ((int (*)(const char*, int))fn_8053A1B0)(p, 0);
        while (*p != ' ')
            p++;
        p++;
        int hash = ((int (*)(const char*, int))fn_8053A190)(p, 0);
        while (*p != ' ')
            p++;
        p++;
        int k0 = fn_8053C550(p);
        while (*p != ' ')
            p++;
        p++;
        int n0 = fn_80409DAC(p);
        while (*p != ' ')
            p++;
        p++;
        int k1 = fn_8053C550(p);
        while (*p != ' ')
            p++;
        p++;
        int n1 = fn_80409DAC(p);
        while (*p != ' ')
            p++;
        p++;
        int k2 = fn_8053C550(p);
        while (*p != ' ')
            p++;
        p++;
        int n2 = fn_80409DAC(p);
        while (*p != ' ')
            p++;
        p++;
        int k3 = fn_8053C550(p);
        while (*p != ' ')
            p++;
        p++;
        int n3 = fn_80409DAC(p);
        while (*p != ';')
            p++;
        if (team != last) {
            cur = (R*)fn_8053C40C((O58*)self, team);
            last = team;
        }
        if (cur->m4 < cur->m8) {
            cur->m0[cur->m4] = hash;
            cur->m4++;
        }
        if (k0 == 0 || (unsigned)(k0 - 10) <= 9) {
            fn_8053C6F4(cur, 0, k0, hash);
            if (k0 == 10) {
                if (hash != 0)
                    fn_805A1958(cur, 0, 0, fn_8053B6CC(cur, hash));
                else
                    fn_805A1958(cur, 0, 0, 0xFF);
                if (hash != 0)
                    fn_805A1958(cur, 1, 0, fn_8053B6CC(cur, hash));
                else
                    fn_805A1958(cur, 1, 0, 0xFF);
                if (hash != 0)
                    fn_805A1958(cur, 2, 0, fn_8053B6CC(cur, hash));
                else
                    fn_805A1958(cur, 2, 0, 0xFF);
                if (hash != 0)
                    fn_805A1958(cur, 3, 0, fn_8053B6CC(cur, hash));
                else
                    fn_805A1958(cur, 3, 0, 0xFF);
            }
            if (n1 >= 0) {
                int o1 = (n1 + 11) * 4;
                char* bs = (char*)cur + 0xFC;
                *(int*)(bs + o1) = 0;
            }
            if (n3 >= 0) {
                int o3 = (n3 + 35) * 4;
                char* bs = (char*)cur + 0xFC;
                *(int*)(bs + o3) = 0;
            }
        } else {
            fn_8053C6F4(cur, 0, k0, hash);
            fn_8053C6F4(cur, 1, k1, hash);
            fn_8053C6F4(cur, 2, k2, hash);
            fn_8053C6F4(cur, 3, k3, hash);
            if (n0 > 0)
                fn_8053AF9C((X*)cur, 0, n0 - 1, hash);
            if (n1 > 0)
                fn_8053AF9C((X*)cur, 1, n1 - 1, hash);
            if (n2 > 0)
                fn_8053AF9C((X*)cur, 2, n2 - 1, hash);
            if (n3 > 0)
                fn_8053AF9C((X*)cur, 3, n3 - 1, hash);
        }
        for (;;) {
            int c = *p;
            if (p >= end)
                goto done;
            if ((unsigned)(c - 0x30) <= 9)
                break;
            if (c == '-')
                break;
            p++;
        }
    }
done:
    self->m0 = self->s3();
    fn_802B961C(buf, 4);
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

DB_OVERLAY int fn_8053C550(const char* s)
{
    int r = 0x14;
    switch (s[0]) {
    case 0x41: break;
    case 'C':
        if (s[1] == 'F')
            r = 7;
        else if (s[1] == 'P')
            r = 0x13;
        else
            r = 1;
        break;
    case '1':
        r = 2;
        break;
    case '2':
        r = 3;
        break;
    case '3':
        r = 4;
        break;
    case 'R':
        if (s[1] == 'F')
            r = 8;
        else if (s[1] == 'P')
            r = 0x11;
        break;
    case 'L':
        if (s[1] == 'F')
            r = 6;
        else if (s[1] == 'R')
            r = 0x11;
        break;
    case 'S':
        if (s[1] == 'S') {
            r = 5;
        } else if (s[1] == 'P') {
            switch (s[2]) {
            case '1':
                r = 10;
                break;
            case '2':
                r = 11;
                break;
            case '3':
                r = 12;
                break;
            case '4':
                r = 13;
                break;
            case '5':
                r = 14;
                break;
            }
        } else if (s[1] == 'U') {
            r = 0x12;
        }
        break;
    case 'D':
        r = 9;
        break;
    case 'M':
        r = 0x10;
        break;
    }
    return r;
}

extern "C" int fn_805A1958(R* r, int a, int b, unsigned char c);
DB_OVERLAY void fn_8053C6F4(R* r, int id, int kind, int v)
{
    Db8053967C_RecB* rb = (Db8053967C_RecB*)r;
    switch (kind) {
    case 1:
        if (v != 0)
            fn_805A1958(r, id, 1, fn_8053B6CC(r, v));
        else
            fn_805A1958(r, id, 1, 0xFF);
        break;
    case 2:
        if (v != 0)
            fn_805A1958(r, id, 2, fn_8053B6CC(r, v));
        else
            fn_805A1958(r, id, 2, 0xFF);
        break;
    case 3:
        if (v != 0)
            fn_805A1958(r, id, 3, fn_8053B6CC(r, v));
        else
            fn_805A1958(r, id, 3, 0xFF);
        break;
    case 5:
        if (v != 0)
            fn_805A1958(r, id, 5, fn_8053B6CC(r, v));
        else
            fn_805A1958(r, id, 5, 0xFF);
        break;
    case 4:
        if (v != 0)
            fn_805A1958(r, id, 4, fn_8053B6CC(r, v));
        else
            fn_805A1958(r, id, 4, 0xFF);
        break;
    case 8:
        if (v != 0)
            fn_805A1958(r, id, 8, fn_8053B6CC(r, v));
        else
            fn_805A1958(r, id, 8, 0xFF);
        break;
    case 7:
        if (v != 0)
            fn_805A1958(r, id, 7, fn_8053B6CC(r, v));
        else
            fn_805A1958(r, id, 7, 0xFF);
        break;
    case 6:
        if (v != 0)
            fn_805A1958(r, id, 6, fn_8053B6CC(r, v));
        else
            fn_805A1958(r, id, 6, 0xFF);
        break;
    case 9:
        if (v != 0)
            fn_805A1958(r, id, 9, fn_8053B6CC(r, v));
        else
            fn_805A1958(r, id, 9, 0xFF);
        break;
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
        fn_8053CB94((X*)r, v, kind - 0xA);
        break;
    case 0x11: {
        unsigned char b = fn_8053B6CC(r, v);
        Db8053967C_BL* l = &rb->bl[1];
        if (l->m4 < l->m8) {
            l->m0[l->m4] = b;
            l->m4++;
        }
        break;
    }
    case 0x10: {
        unsigned char b = fn_8053B6CC(r, v);
        Db8053967C_BL* l = &rb->bl[2];
        if (l->m4 < l->m8) {
            l->m0[l->m4] = b;
            l->m4++;
        }
        break;
    }
    case 0x12: {
        unsigned char b = fn_8053B6CC(r, v);
        Db8053967C_BL* l = &rb->bl[3];
        if (l->m4 < l->m8) {
            l->m0[l->m4] = b;
            l->m4++;
        }
        break;
    }
    case 0x13: {
        unsigned char b = fn_8053B6CC(r, v);
        Db8053967C_BL* l = &rb->bl[4];
        if (l->m4 < l->m8) {
            l->m0[l->m4] = b;
            l->m4++;
        }
        break;
    }
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
