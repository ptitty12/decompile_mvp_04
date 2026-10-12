/*
 * Database overlay code, .database_codeoverlay 0x8055A3B0-0x8055F730 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8054FA04.h"
#include "game/clampiter.h"
extern "C" void* memset(void* p, int c, unsigned n);
extern int lbl_80622D64[];

struct Db8055A880_Rec {
    int m0;
    float m4;
};

extern "C" int fn_8040ABA0();

struct Db8055AD70_S {
    unsigned char rec[0x7C][5];
    int keys[0x7C];
    int m45c;
};
extern "C" void fn_8055A8D0(Db8055AD70_S* self);
extern char lbl_8064A2A8[];

extern "C" void* bsearch(const void* key, const void* base, unsigned n, unsigned sz,
                             int (*cmp)(Db8055A880_Rec*, Db8055A880_Rec*));
extern "C" void fn_8040A208(void* base, unsigned n, unsigned sz, int (*cmp)(Db8055A880_Rec*, Db8055A880_Rec*));
extern "C" int fn_80539A84(int k);
extern "C" void fn_805371C4(Unk805352B0_List* self, unsigned f);

struct Db8055B000_Row {
    int m0;
    int v[3];
};
struct Db8055B000_T {
    Db8055B000_Row rows[0x7C];
    const void* vp;
};
extern char lbl_80682CB0[];
extern const char* lbl_80619D34[];
extern int lbl_8060260C[][3];

struct Db8055B048_Tbl {
    int m0;
};

struct Db8055B850_S {
    unsigned m0;
    unsigned m4;
    char pad8[0x1B8];
    int m1C0[0xCB2];
    float m3488[0xCB2];
    float m6750[22][14];
    float m6C20[22][14];
    Unk805352B0_List* m70F0;
    Unk8007A4DC_Screen* m70F4;
    void* m70F8;
    int m70FC;
    int m7100;
    int m7104;
};
int fn_8007FBC0(Unk8007F198_C* s, int a, int b);
extern "C" void fn_8055B6AC(Db8055B850_S* self);

extern char lbl_8064A3B8[];
struct Db8055B0D8_Big {
    int* m0;
    unsigned m4;
    unsigned m8;
    int mC;
    const void* vp;
    int m14;
    int buf[0xCB2];
    Db8055B0D8_Big()
    {
        vp = lbl_8064B298;
        m0 = buf;
        m8 = 0xCB2;
        fn_8040074C(m0, m8 << 2);
        m4 = 0;
        mC = 0;
        vp = lbl_8064A550;
        fn_8040074C(m0, m8 << 2);
        vp = lbl_8064A3B8;
        m4 = 0;
        mC = 0;
        m14 = 0;
    }
};

struct Db8055B1F4_L {
    char pad0[0x10];
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
    virtual void s13();
    virtual void s14();
    virtual ~Db8055B1F4_L();
};
struct Db8055B1F4_S {
    char pad0[0x70F8];
    Db8055B1F4_L* m70F8;
};

extern float lbl_805FF714;
extern float lbl_805FF718;
extern "C" float fn_8007824C(int a, int b);

extern "C" void fn_80077D88__18Unk8007A4DC_Screen(Unk8007A4DC_Screen* s, int id);
extern "C" int fn_8055BB14(Db8055B850_S* self, int k, int flag, int u);

struct Unk8007DB74_A;
int fn_8007DE50(Unk8007DB74_A* g, int a, int b, int c);
extern Unk8007A4DC_Screen* lbl_8061930C;
struct Db8055BD7C_W {
    int w[4];
};
extern Db8055BD7C_W lbl_805FF738;

struct Db8055D4B4_L {
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
    virtual int v13(int a);
    void RemoveAt(unsigned i)
    {
        if (i < m4) {
            unsigned j;
            for (j = i; j < m4; j++)
                m0[j] = m0[j + 1];
            m4--;
        }
    }
};

extern "C" void fn_8055EBAC(void* x, Unk805352B0_List* l);
extern "C" void fn_80538368(Unk805352B0_List* self, Unk805352B0_List* excl);
/* forward declarations (definitions are in address order) */
extern "C" int fn_8055A73C(int a, int b, int c);
extern "C" int fn_8055A880(Db8055A880_Rec* a, Db8055A880_Rec* b);
extern "C" int fn_8055A890(Db8055A880_Rec* a, Db8055A880_Rec* b);
extern "C" int fn_8055A8B0(Db8055A880_Rec* a, Db8055A880_Rec* b);
extern "C" void fn_8055AC44(Db8055AD70_S* self, int a);
extern "C" int fn_8055AD70(Db8055AD70_S* self, int key);
extern "C" int fn_8055ADD4(Db8055AD70_S* self, int key);
extern "C" int fn_8055AE1C(Db8055AD70_S* self, int key);
extern "C" int fn_8055AE68(Db8055AD70_S* self, int key);
extern "C" int fn_8055AEB4(Db8055AD70_S* self, int key);
extern "C" int fn_8055AF00(Db8055AD70_S* self, int key);
extern "C" Db8055B000_T* fn_8055AF4C(Db8055B000_T* self);
extern "C" int fn_8055B000(Db8055B000_T* t, int key, unsigned col);
extern "C" int fn_8055B048(Db8055B048_Tbl* t, int a, int b);
extern "C" int fn_8055B078(Db8055B000_T* t, int key, int val);
extern "C" Db8055B850_S* fn_8055B0D8(Db8055B850_S* self, Unk805352B0_List* l, Unk8007A4DC_Screen* sc);
extern "C" void fn_8055B1F4(Db8055B1F4_S* self, int chrg);
extern "C" void fn_8055B850(Db8055B850_S* self);
extern "C" void fn_8055B998(Db8055B850_S* self, Unk805352B0_List* list, int flag);
extern "C" int fn_8055BD7C(int a);
extern "C" int fn_8055BE60(Unk8007A4DC_Screen* sc, Unk805352B0_List* l);
extern "C" void fn_8055C444(Unk8007A4DC_Screen* sc, int id, int unused, int c, float* out);
extern "C" int fn_8055CC28(int a);
extern "C" int fn_8055CC38(int a);
extern "C" int fn_8055CC68(int a);
extern "C" int fn_8055CCA0(int a);
extern "C" int fn_8055CCB0(int a, int b);
extern "C" void fn_8055D2E8(Unk8007A4DC_Screen* sc, Unk805352B0_List* l);
extern "C" void fn_8055D4B4(Db8055D4B4_L* self);
extern "C" void fn_8055EAFC(void* x);

extern "C" DB_OVERLAY int fn_8055A73C(int a, int b, int c)
{
    int r = 0;
    if (c > 0x46) {
        float d = 30.0f;
        float t = (float)c - 70.0f;
        float x = t * (1.0f / 30.0f);
        float y = x * 5.0f;
        if ((int)y > 0)
            r = fn_8040ABA0() % (int)y;
    }
    int rr = r + 10;
    int v = a + ((int)((float)b * 0.15f) + rr);
    int res;
    if (v <= b) {
        res = v;
        if (res < 0)
            res = 0;
    } else
        res = b;
    return res;
}

extern "C" DB_OVERLAY int fn_8055A880(Db8055A880_Rec* a, Db8055A880_Rec* b)
{
    return a->m0 - b->m0;
}

extern "C" DB_OVERLAY int fn_8055A890(Db8055A880_Rec* a, Db8055A880_Rec* b)
{
    if (b->m4 < a->m4)
        return -1;
    return b->m4 > a->m4;
}

extern "C" DB_OVERLAY int fn_8055A8B0(Db8055A880_Rec* a, Db8055A880_Rec* b)
{
    if (b->m4 > a->m4)
        return -1;
    return b->m4 < a->m4;
}

/* near-miss: loop body (retail reloads the list fields m4/m0 every iteration, ours hoists them) and r29 reuse of flags as the count */
extern "C" DB_OVERLAY void fn_8055AC44(Db8055AD70_S* self, int a)
{
    Unk80535650_Tmp t;
    int buf[0x82];
    Unk80535650_Tmp* q = &t;
    unsigned f = fn_80539A84(a) | 0x70000000;
    q->C1(buf, 0x82);
    q->C2();
    q->C3(lbl_8064A2A8);
    fn_805371C4((Unk805352B0_List*)q, f);
    int n = q->m4;
    q->mC = 0;
    for (int i = 0; i < n; i++) {
        self->keys[i] = q->m0[q->mC];
        q->mC = (q->mC + 1) % q->m4;
    }
    self->m45c = n;
    fn_8040A208(self->keys, n, 4, (int (*)(Db8055A880_Rec*, Db8055A880_Rec*))fn_8055A880);
    fn_8055A8D0(self);
    t.vp = lbl_8064A550;
}

extern "C" DB_OVERLAY int fn_8055AD70(Db8055AD70_S* self, int key)
{
    void* p = bsearch(&key, self->keys, self->m45c, 4, (int (*)(Db8055A880_Rec*, Db8055A880_Rec*))fn_8055A880);
    if (p == 0)
        return -1;
    return ((unsigned)p - (unsigned)self->keys) >> 2;
}

extern "C" DB_OVERLAY int fn_8055ADD4(Db8055AD70_S* self, int key)
{
    int i = fn_8055AD70(self, key);
    if (i == -1)
        return 0;
    return self->rec[i][0];
}

extern "C" DB_OVERLAY int fn_8055AE1C(Db8055AD70_S* self, int key)
{
    int i = fn_8055AD70(self, key);
    if (i == -1)
        return 0;
    return self->rec[i][1];
}

extern "C" DB_OVERLAY int fn_8055AE68(Db8055AD70_S* self, int key)
{
    int i = fn_8055AD70(self, key);
    if (i == -1)
        return 0;
    return self->rec[i][2];
}

extern "C" DB_OVERLAY int fn_8055AEB4(Db8055AD70_S* self, int key)
{
    int i = fn_8055AD70(self, key);
    if (i == -1)
        return 0;
    return self->rec[i][3];
}

extern "C" DB_OVERLAY int fn_8055AF00(Db8055AD70_S* self, int key)
{
    int i = fn_8055AD70(self, key);
    if (i == -1)
        return 0;
    return self->rec[i][4];
}

extern "C" DB_OVERLAY Db8055B000_T* fn_8055AF4C(Db8055B000_T* self)
{
    self->vp = lbl_80682CB0;
    for (int i = 0; i < 0x7C; i++) {
        self->rows[i].m0 = fn_800736EC(lbl_80619D34[i]);
        for (int j = 0; j < 3; j++)
            self->rows[i].v[j] = fn_800736EC(lbl_80619D34[lbl_8060260C[i][j]]);
    }
    return self;
}

extern "C" DB_OVERLAY int fn_8055B000(Db8055B000_T* t, int key, unsigned col)
{
    if (col <= 2) {
        for (int i = 0; i < 0x7C; i++) {
            if (t->rows[i].m0 == key)
                return t->rows[i].v[col];
        }
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8055B048(Db8055B048_Tbl* t, int a, int b)
{
    if ((unsigned)b <= 2 && a <= 0x7B) {
        char* base = (char*)t + 4;
        int o = b * 4 + a * 16;
        return *(int*)(base + o);
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8055B078(Db8055B000_T* t, int key, int val)
{
    for (int i = 0; i < 0x7C; i++) {
        if (t->rows[i].m0 == key) {
            for (int j = 0; j < 3; j++) {
                if (t->rows[i].v[j] == val)
                    return 1;
            }
            break;
        }
    }
    return 0;
}

extern "C" DB_OVERLAY Db8055B850_S* fn_8055B0D8(Db8055B850_S* self, Unk805352B0_List* l, Unk8007A4DC_Screen* sc)
{
    self->m0 = 0;
    self->m4 = 0;
    self->m70F8 = 0;
    self->m70FC = 0;
    self->m7100 = 0;
    self->m7104 = 0;
    self->m70F0 = l;
    self->m70F4 = sc;
    self->m0 = sc->fn_8007B1EC();
    self->m4 = fn_8007FBC0((Unk8007F198_C*)self->m70F4, 0, 0);
    fn_8055B6AC(self);
    fn_8055B850(self);
    fn_8040074C(self->m1C0, 0x32C8);
    if (self->m70F8 == 0)
        self->m70F8 = new (0x100) Db8055B0D8_Big;
    fn_80538368((Unk805352B0_List*)self->m70F8, 0);
    return self;
}

extern "C" DB_OVERLAY void fn_8055B1F4(Db8055B1F4_S* self, int chrg)
{
    if (self->m70F8) {
        delete self->m70F8;
        self->m70F8 = 0;
    }
    if (chrg & 1)
        fn_80377408(self);
}

extern "C" DB_OVERLAY void fn_8055B850(Db8055B850_S* self)
{
    unsigned i;
    for (i = 0; i <= 21; i++) {
        int j;
        for (j = 0; j < 14; j++) {
            self->m6750[i][j] = lbl_805FF714;
            self->m6C20[i][j] = lbl_805FF718;
        }
    }
    for (i = 1; i < self->m0; i++) {
        int t = self->m70F4->fn_8007A8DC(1, i);
        unsigned yr = (self->m4 - t) / 365 - 24;
        self->m3488[i] = fn_8007824C(self->m70F4->fn_800728BC(i), 0);
        if (yr <= 21) {
            int c = self->m70F4->fn_8007A8DC(5, i);
            if (!(self->m3488[i] >= self->m6C20[yr][c]))
                self->m6C20[yr][c] = self->m3488[i];
            if (!(self->m3488[i] <= self->m6750[yr][c]))
                self->m6750[yr][c] = self->m3488[i];
        }
    }
}

extern "C" DB_OVERLAY void fn_8055B998(Db8055B850_S* self, Unk805352B0_List* list, int flag)
{
    unsigned i;
    for (i = 0; i < list->m4; i++) {
        int id = list->At(i);
        int k = self->m70F4->fn_8007A11C(id);
        int x = self->m70F4->fn_8007A8DC(0xB, k);
        if (self->m1C0[k] == 0 && x == 0) {
            int c5 = self->m70F4->fn_8007A8DC(5, k);
            int t = 0;
            if (c5 == 0 || c5 == 10)
                t = 1;
            int lim = 0x3D;
            int u = 0;
            if (t != 0)
                u = self->m70FC >= lim;
            if (fn_8055BB14(self, k, flag, u) != 0) {
                self->m70F0->Push(id);
                self->m1C0[k] = 1;
                if (t != 0)
                    self->m70FC++;
                else
                    self->m7104++;
                fn_80077D88__18Unk8007A4DC_Screen(self->m70F4, id);
                self->m7100 = self->m70FC + self->m7104;
            }
        }
    }
}

extern "C" DB_OVERLAY int fn_8055BD7C(int a)
{
    Db8055BD7C_W w = lbl_805FF738;
    int i = 0;
    do {
        Unk8006A138_It<9> it(0);
        int k = 0;
        do {
            if (fn_8007DE50((Unk8007DB74_A*)lbl_8061930C, a, w.w[i], k) == 0xFF) {
                if (it.v != 9 || w.w[i] == 2 || w.w[i] == 0)
                    return 0;
            }
            k = it.Next();
        } while (k <= 9);
        i++;
    } while (i <= 3);
    return 1;
}

extern "C" DB_OVERLAY int fn_8055BE60(Unk8007A4DC_Screen* sc, Unk805352B0_List* l)
{
    int i = 0;
    int n = l->m4;
    for (; i < n; i++) {
        int id = l->At(i);
        int a = sc->fn_8007A6A0(5, id);
        int b = sc->fn_8007A6A0(0x1E, id);
        int f = 1;
        if (b == 0)
            f = 0;
        if (a == 10 && f == 0)
            return i;
    }
    i = 0;
    for (; i < n; i++) {
        int id = l->At(i);
        int a = sc->fn_8007A6A0(5, id);
        int b = sc->fn_8007A6A0(0x1E, id);
        int f = 1;
        if (b == 0)
            f = 0;
        if (a == 0 && f == 0)
            return i;
    }
    return -1;
}

extern "C" DB_OVERLAY void fn_8055C444(Unk8007A4DC_Screen* sc, int id, int unused, int c, float* out)
{
    out[0] = sc->fn_8007A48C(1, id, 1) * 2.0f + sc->fn_8007A48C(1, id, 0);
    out[1] = sc->fn_8007A48C(0, id, 1) * 2.0f + sc->fn_8007A48C(0, id, 0);
    out[2] = sc->fn_8007A3FC(0xD, id);
    *(int*)&out[3] = c;
}

extern "C" DB_OVERLAY int fn_8055CC28(int a)
{
    return a == 1;
}

extern "C" DB_OVERLAY int fn_8055CC38(int a)
{
    switch (a) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 12:
    case 13:
        return 1;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8055CC68(int a)
{
    switch (a) {
    case 6:
    case 7:
    case 8:
    case 11:
    case 13:
        return 1;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_8055CCA0(int a)
{
    return a == 10;
}

extern "C" DB_OVERLAY int fn_8055CCB0(int a, int b)
{
    int r;
    switch (b) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        return a == b;
    case 11:
        r = 0;
        if (a == 11 || a == 6 || a == 7 || a == 8)
            r = 1;
        return r;
    case 12:
        r = 0;
        if (a == 12 || a == 2 || a == 3 || a == 4 || a == 5)
            r = 1;
        return r;
    case 13: {
        int t = 0;
        if (fn_8055CCB0(a, 12) != 0 || fn_8055CCB0(a, 11) != 0)
            t = 1;
        return t;
    }
    }
    return 0;
}

extern "C" DB_OVERLAY void fn_8055D2E8(Unk8007A4DC_Screen* sc, Unk805352B0_List* l)
{
    unsigned i = 0;
    unsigned n = l->m4;
    for (; i < n; i++)
        sc->fn_8007A808(0x19, l->At(i), 0);
}

extern "C" DB_OVERLAY int fn_8055D350(Unk8007A4DC_Screen* sc, Unk805352B0_List* l, int n, int* out)
{
    int cnt[14];
    int c;
    out[8] = n;
    out[2] = n;
    out[3] = n;
    out[4] = n;
    out[5] = n;
    out[6] = n;
    out[7] = n;
    out[1] = n * 2;
    out[0] = n * 10;
    memset(cnt, 0, 0x38);
    int t = l->m4;
    if (t > 0) {
        c = t;
        int o = 0;
        do {
            int id = *(int*)((char*)l->m0 + o);
            int flag = sc->fn_8007A6A0(0x1E, id) != 0;
            if (id != 0 && flag == 0)
                cnt[sc->fn_8007A6A0(5, id)]++;
            o += 4;
        } while (--c != 0);
    }
    int sum = 0;
    c = 0;
    for (; c < 9; c++) {
        out[c] = out[c] - cnt[lbl_80622D64[c]];
        if (c == 0)
            out[0] = out[0] - cnt[10];
        if (!(out[c] > 0))
            out[c] = 0;
        sum += out[c];
    }
    return sum;
}

extern "C" DB_OVERLAY void fn_8055D4B4(Db8055D4B4_L* self)
{
    int i;
    while ((i = self->v13(0)) != -1)
        self->RemoveAt(i);
}

extern "C" DB_OVERLAY void fn_8055EAFC(void* x)
{
    Unk80535650_Tmp t;
    int buf[0xCB2];
    Unk80535650_Tmp* q = &t;
    q->C1(buf, 0xCB2);
    q->C2();
    q->C3(lbl_8064A3B8);
    fn_80538368((Unk805352B0_List*)q, 0);
    fn_8055EBAC(x, (Unk805352B0_List*)q);
    q->D();
}
