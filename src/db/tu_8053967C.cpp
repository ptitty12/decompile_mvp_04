/*
 * Database overlay code, .database_codeoverlay 0x8053967C-0x8053CC9C (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8053967C.h"

typedef Db8053967C_List L;
typedef Db8053967C_Rost R;
typedef Db8053967C_Idx X;
typedef Db8053967C_Obj58 O58;

extern "C" {

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

DB_OVERLAY unsigned char fn_8053B210(R* r, int id)
{
    unsigned char i = 0;
    for (; i < (unsigned char)r->m4; i++) {
        if (r->m0[i] == id)
            return i;
    }
    return 0xFF;
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

}
