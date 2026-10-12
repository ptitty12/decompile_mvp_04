/*
 * Game code, .text 0x800A4668-0x800A8684 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */


extern "C" int fn_800A2AE8();
extern "C" int fn_80329FA0(void* out, ...);
extern int lbl_8061930C;
extern "C" unsigned fn_8007F198(int g, int team);
extern "C" int fn_8007F24C(int g, int team, int j);
extern "C" int fn_8007A6A0(int g, int a, int e);
extern "C" void fn_8056B8C0(int a, int b);
extern const float lbl_805B5E5C;
extern const float lbl_805B5E68;
extern const float lbl_805B5E6C;
extern int lbl_8061995C;
extern float lbl_80619960;
extern "C" int fn_8007E0E4(int g, int a, int team);
extern "C" int fn_8007DF5C(int g, int a, int team, int i);
extern "C" int fn_8007A270(int g, int e);
extern "C" int fn_8007E1F8(int g, int a);
extern const float lbl_805B5E70;
extern "C" int fn_80078A38(int g, int a);
extern "C" float fn_800A5A1C(void* o, int x);
extern "C" int fn_8007F7D0(int g, int a);
extern "C" int fn_8007B320(int g, int a, int b);
extern "C" void fn_80551A80(int a, int b);
extern "C" int fn_80083FC0(int e);
extern "C" int fn_800A3C98(void* o, int a, int b);
extern "C" int fn_800A2EB4(void* p);
extern "C" int fn_805683AC(int a, int b, int c);
extern "C" int fn_80568464(int a, int b, int c, int d);
extern "C" int fn_800768E0(int g, int a);
extern "C" int fn_80553CA8(void* p);
extern "C" int fn_80075948(int g, int a);
extern "C" int fn_8007B510(int g, int a, int b);
extern "C" void fn_8007B570(int g, int a, int b, int c);
extern "C" void fn_800A6D60(void* p);
extern "C" void fn_80403144(void* dst, const void* src);
extern "C" int fn_800A71F8(int a);
extern "C" void fn_80400560(void* p, int n);
extern "C" char* fn_8040B61C(char* dst, const char* src);
extern const char* lbl_80619308;

extern "C" int fn_800A4EA4()
{
    unsigned char b;
    fn_80329FA0(&b, fn_800A2AE8());
    return b > 7;
}

struct Unk800A641C_Pl {
    char pad0[0x198];
    int m198;
    char pad19C[0xD74 - 0x19C];
    int mD74;
    char padD78[0xE64 - 0xD78];
};

struct Unk800A6114_C {
    char pad0[0x14];
    int m14;
    float m18;
    char pad1C[0x84 - 0x1C];
    int m84;
    int m88;
    char pad8C[4];
    float m90;
    float m94;
    float m98;
    float m9C;
};

struct Unk800A641C_Q {
    char pad0[0xC];
    Unk800A6114_C* mC;
    char pad10[4];
    Unk800A641C_Pl* m14;
};

struct Unk806192E0 {
    int m0;
    Unk800A641C_Q* m4;
};

extern Unk806192E0* lbl_806192E0;

struct Unk800A4EE4_E {
    char pad0[0x1C];
    int m1C;
    char pad20[0x1EC - 0x20];
    int m1EC;
};

struct Unk800A4EE4 {
    char pad0[0x6C];
    int m6C;
};

extern "C" Unk800A4EE4_E* fn_8007FE04(int g);

extern "C" void fn_800A4EE4(Unk800A4EE4* p)
{
    Unk800A4EE4_E* e = fn_8007FE04(lbl_8061930C);
    switch (p->m6C) {
    case 0:
    case 1:
        e->m1C = 9;
        break;
    case 2:
        e->m1C = 9;
        e->m1EC = 0;
        break;
    }
}

struct Unk800A4F54_Rec {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};
struct Unk800A4F54 {
    char pad0[0x28 + 0x2C];
    char pad54[0x70 - 0x54];
    int m70;
    int m74;
    int m78;
    int m7C;
    int m80;
    int m84;
    int m88;
    int m8C;
    int m90;
    int m94;
    int m98;
    int m9C;
    float mA0;
    int mA4;
    char padA8[0xDC - 0xA8];
    int mDC;
    int mE0;
    int mE4;
    char padE8[4];
    Unk800A4F54_Rec mEC;
};
extern "C" int fn_8007290C(int g, int a);
extern "C" void fn_80086278(int a, void* b);
extern "C" void fn_8006A004(Unk800A641C_Q* q);
extern "C" float fn_80574750(int a, int b);
extern "C" float fn_80574798(int a, int b);
extern "C" float fn_805747E4(int a, int b);
extern "C" float fn_80574830(int a, int b);
extern "C" int fn_800A2AE8(void* p);
inline void FEPut90(Unk800A6114_C* c, float v) { c->m90 = v; }

inline void FEPut94(Unk800A6114_C* c, float v) { c->m94 = v; }

inline void FEPut98(Unk800A6114_C* c, float v) { c->m98 = v; }

inline void FEPut9C(Unk800A6114_C* c, float v) { c->m9C = v; }

inline void FEPutQ90(Unk800A641C_Q* q, float v) { FEPut90(q->mC, v); }

inline void FEPutQ94(Unk800A641C_Q* q, float v) { FEPut94(q->mC, v); }

inline void FEPutQ98(Unk800A641C_Q* q, float v) { FEPut98(q->mC, v); }

inline void FEPutQ9C(Unk800A641C_Q* q, float v) { FEPut9C(q->mC, v); }

inline void FERecInit(Unk800A4F54_Rec* r)
{
    r->m8 = 4;
    r->m4 = -1;
    r->mC = -1;
    r->m10 = -1;
    r->m14 = 0;
    r->m18 = 0;
}

extern "C" void fn_800A4F54(Unk800A4F54* p)
{
    char* sub = (char*)p + 0x2C;
    int g = lbl_8061930C;
    int h = fn_8007290C(g, 0);
    Unk800A641C_Q* q = lbl_806192E0->m4;
    int own = *(int*)((char*)q + 0x10);
    fn_80086278(own, fn_8007FE04(lbl_8061930C));
    fn_8006A004(q);
    float a = fn_80574750(*(int*)(sub + 0x28), h);
    float b = fn_80574798(*(int*)(sub + 0x28), h);
    float c = fn_805747E4(*(int*)(sub + 0x28), h);
    float d = fn_80574830(*(int*)(sub + 0x28), h);
    FEPutQ90(q, a);
    FEPutQ94(q, b);
    FEPutQ98(q, c);
    FEPutQ9C(q, d);
    p->m70 = 0;
    p->m74 = 0;
    p->m78 = 0;
    p->m7C = 0;
    p->m80 = 0;
    p->m84 = ((int (*)(void*))fn_800A2AE8)(p);
    p->mA0 = 0.0f;
    p->mEC.m0 = -1;
    p->m88 = -1;
    p->m98 = 0;
    p->m8C = -1;
    p->m90 = -1;
    p->m94 = -1;
    p->m9C = 0;
    p->mA4 = 0;
    p->mDC = 0;
    p->mE0 = 0;
    p->mE4 = 0;
    FERecInit(&p->mEC);
}

extern "C" void fn_800A50F0(void* self, int (*arr)[2])
{
    int g = lbl_8061930C;
    Unk800A641C_Q* q = lbl_806192E0->m4;
    volatile int sp8 = 0;
    int e1 = 0;
    do {
        unsigned j = 0;
        Unk800A641C_Pl* pl = q->m14 + e1;
        int team = pl->m198;
        unsigned n = fn_8007F198(g, team);
        if (j < n) {
            do {
                int e = fn_8007F24C(g, team, (unsigned char)j);
                int a = fn_8007A6A0(g, 0x1E, e);
                int b = fn_8007A6A0(g, 0x1F, e);
                if (a != 0 && b > 0)
                    arr[j][sp8] = 1;
                else
                    arr[j][sp8] = 0;
                j++;
            } while (j < n);
        }
        int c = sp8;
        int t;
        if (c > 1)
            t = c;
        else
            t = c + 1;
        sp8 = t;
        e1 = t;
    } while (e1 <= 1);
}

extern "C" int fn_8007F3A0(int g);
extern "C" void fn_80078AE0(int g, int a, int* b, int* c, int* d, int* e);
extern "C" int fn_8007FDF8(int g);
extern "C" float fn_80079EFC(int g, int a);

/* near-miss (99.5%): lim and idx take r30/r29 swapped */
extern "C" int fn_800A588C(void* self, int idx)
{
    int g = lbl_8061930C;
    int r = fn_8007F3A0(g);
    if (r != 0) {
        return r;
    }
    int h = fn_80075948(g, idx);
    if (h != 0) {
        int k = fn_80078A38(g, idx);
        int lim = 0;
        switch (k) {
        case 0:
            lim = 0x19;
            break;
        case 1:
            lim = 0x14;
            break;
        case 2:
            lim = 0x14;
            break;
        case 3:
            lim = 0x14;
            break;
        }
        if ((int)fn_8007F198(g, idx) < lim) {
            return 5;
        }
    }
    int a;
    int b;
    int c;
    int d;
    fn_80078AE0(g, idx, &a, &b, &c, &d);
    if (d <= 9) {
        return 3;
    }
    if (fn_8007FDF8(g) == 0xC || fn_8007FDF8(g) == 0xD) {
        int one = *(int*)((char*)fn_8007FE04(g) + 0x1E0) == 1;
        if (h != 0 && one) {
            float s = fn_80079EFC(g, h);
            if (s < 0.0f) {
                return 7;
            }
        }
    }
    return 0;
}

struct Unk800A59F0 {
    char pad0[0x28];
    int m28;
};

extern "C" void fn_800A59F0(Unk800A59F0* p) { fn_8056B8C0(p->m28, lbl_8061930C); }

/* near-miss (39 of 102 slots): float temporaries/store order around the fmadds tail */

extern "C" float fn_800A5A1C(void* o, int arg)
{
    if (lbl_8061995C == 0) {
        int i = 0;
        int g = lbl_8061930C;
        int team = *(int*)((char*)lbl_806192E0->m4->m14 + 0xFC8);
        float spC = lbl_805B5E5C;
        float sp8 = lbl_805B5E5C;
        int n = fn_8007E0E4(g, arg, team);
        if (i < n) {
            do {
                int e = fn_8007DF5C(g, arg, team, i);
                if (fn_8007A270(g, e) == 0) {
                    sp8 = sp8 + (float)fn_8007A6A0(g, 0x16, e) + lbl_805B5E68;
                    spC = spC + lbl_805B5E68;
                }
                i++;
            } while (i < n);
        }
        int e2 = fn_8007E1F8(g, arg);
        sp8 = ((float)fn_8007A6A0(g, 0x16, e2) + lbl_805B5E68) * spC + sp8;
        spC = spC + spC;
        return sp8 / (spC * lbl_805B5E6C);
    }
    return lbl_80619960;
}

inline void SetM18(Unk800A6114_C* c, float v) { c->m18 = v; }

extern "C" void fn_800A5BB8(void* o)
{
    Unk800A641C_Q* q = lbl_806192E0->m4;
    if (fn_80078A38(lbl_8061930C, q->m14->m198) == 0) {
        float r = fn_800A5A1C(o, *(int*)((char*)q->m14 + 0xFFC));
        SetM18(q->mC, r);
    } else {
        float r = lbl_805B5E70;
        SetM18(q->mC, r);
    }
}

extern "C" void fn_800A5C54(Unk800A4EE4* p)
{
    if (p->m6C == 1) {
        int g = lbl_8061930C;
        Unk800A641C_Q* q = lbl_806192E0->m4;
        int r = fn_8007B320(g, 0, fn_8007F7D0(g, 0));
        if (r == q->m14->m198)
            fn_80551A80(r, 1);
    }
}

extern "C" int fn_8006A1B4(Unk800A641C_Q* q);

extern "C" void fn_800A6114(void* o)
{
    int g = lbl_8061930C;
    Unk800A641C_Q* q = lbl_806192E0->m4;
    int found = 2;
    int h = fn_8007F7D0(g, 0);
    volatile int sp8;
    volatile int spC = 0;
    int t2;
    do {
        sp8 = 0;
        int e = 0;
        do {
            int v = fn_8007B320(g, fn_80083FC0(e), h);
            int sc = spC;
            Unk800A641C_Pl* pl = q->m14 + sc;
            if (pl->m198 == v) {
                found = sc;
                break;
            }
            int c = sp8;
            int t;
            if (c > 3)
                t = c;
            else
                t = c + 1;
            sp8 = t;
            e = t;
        } while (e <= 3);
        int c2 = spC;
        if (c2 > 1)
            t2 = c2;
        else
            t2 = c2 + 1;
        spC = t2;
    } while (t2 <= 1 && found == 2);
    if (fn_8006A1B4(q) == 1)
        q->mC->m14 = 0xB;
    else if (found == 2)
        q->mC->m14 = 0;
    else {
        Unk800A641C_Pl* pf = q->m14 + found;
        q->mC->m14 = fn_800A3C98(o, q->mC->m88, pf->m198);
    }
}

/* near-miss: register allocation (o/a/b/q take different callee-saved registers) */
struct Unk800A625C_Sub {
    char pad0[0x1C];
    int m1C;
};

extern "C" void fn_800A625C(char* o)
{
    int a = 1;
    int b = 1;
    Unk800A641C_Q* q = lbl_806192E0->m4;
    if (fn_800A2EB4(o) == 1) {
        Unk800A6114_C* c = q->mC;
        Unk800A625C_Sub* s = (Unk800A625C_Sub*)(o + 0x2C);
        a = c->m88;
        b = c->m84;
        int t27 = fn_805683AC(s->m1C, a, b);
        int t26 = fn_80568464(s->m1C, a, 1, b);
        int t3 = fn_80568464(s->m1C, a, 0, b);
        int hi = 3;
        int lo = 2;
        if (t27 != 0) {
            hi = 5;
            lo = 4;
        }
        b = lo;
        if (t26 != 0)
            b = hi;
        a = lo;
        if (t3 != 0)
            a = hi;
    }
    *(int*)((char*)q->m14 + 0xD70) = a;
    *(int*)((char*)q->m14 + 0x1BD4) = b;
}

extern "C" int fn_8007FB40(int g, int a);
extern "C" unsigned fn_8007FB2C(int g, int a);
extern "C" int fn_8007FB98(int g, int a, int b, int c);
extern "C" int fn_8007B8C4(int g, int a, int b);
extern "C" int fn_8056A2F8(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
struct Unk800A6340 {
    char pad0[0x28];
    int m28;
};

extern "C" void fn_800A6340(Unk800A6340* o)
{
    int g = lbl_8061930C;
    Unk800A641C_Q* q = lbl_806192E0->m4;
    int h = q->mC->m84;
    int pl = q->m14->m198;
    int r = fn_8056A2F8(o->m28, fn_8007FB40(g, h) + 1, 0, 1, h, pl, 0, 0, 0, 0x1A);
    if (r != -1 && (unsigned)r < fn_8007FB2C(g, h)) {
        *(int*)((char*)q->m14 + 0x1D50) = fn_8007B8C4(g, 2, fn_8007FB98(g, r, 1, h));
    }
}

extern "C" void fn_800A641C()
{
    int g = lbl_8061930C;
    Unk800A641C_Q* q = lbl_806192E0->m4;
    Unk800A641C_Pl* z = q->m14;
    int a = z->m198;
    Unk800A641C_Pl* p1 = z + 1;
    p1->mD74 = fn_800768E0(g, z[1].m198);
    Unk800A641C_Pl* z0 = q->m14;
    z0->mD74 = fn_800768E0(g, a);
}

extern "C" void fn_8040074C(void* p, int n);
extern const char lbl_8064B298[];
extern const char lbl_8064A550[];
extern const char lbl_8064A2A8[];
struct FeAr {
    int* m0;
    int m4;
    int m8;
    int mC;
    const void* vp;
    int m14;
};

inline void FeArBase(FeAr* a, int* buf, int cap)
{
    a->vp = lbl_8064B298;
    a->m0 = buf;
    a->m8 = cap;
    fn_8040074C(a->m0, cap * 4);
}

inline void FeArMid(FeAr* a)
{
    a->m4 = 0;
    a->mC = 0;
    a->vp = lbl_8064A550;
    fn_8040074C(a->m0, a->m8 * 4);
}

inline void FeArD3(FeAr* a)
{
    a->vp = lbl_8064A2A8;
    a->m4 = 0;
    a->mC = 0;
    a->m14 = 0;
}

inline void FeArDtor(FeAr* a)
{
    a->vp = lbl_8064A550;
}

extern "C" void fn_805371C4(FeAr* a, int mask);
extern "C" int fn_8007B3E0(int g, int a, int b);
extern "C" void fn_8007B4A8(int g, int a, int b, int c);

inline unsigned FeArCount(FeAr* a)
{
    return a->m4;
}

inline int FeArGet(FeAr* a, int i)
{
    char* b = (char*)a->m0;
    int off = i * 4;
    return *(int*)(b + off);
}

extern "C" void fn_800A6484()
{
    int g = lbl_8061930C;
    FeAr a;
    int buf[0x82];
    FeArBase(&a, buf, 0x82);
    FeArMid(&a);
    FeArD3(&a);
    fn_805371C4(&a, 0x7000003F);
    for (unsigned i = 0; i < FeArCount(&a); i++) {
        int h = fn_80075948(g, FeArGet(&a, i));
        fn_8007B4A8(g, 0x16, h, fn_8007B3E0(g, 0x17, h));
        fn_8007B4A8(g, 0x17, h, fn_8007B3E0(g, 0x18, h));
        fn_8007B4A8(g, 0x18, h, fn_8007B3E0(g, 0x19, h));
        fn_8007B4A8(g, 0x19, h, 0);
    }
    FeArDtor(&a);
}

struct Unk800A65F4 {
    char pad0[0x24];
    void* m24;
};

extern "C" int fn_800A65F4(Unk800A65F4* p) { return fn_80553CA8(p->m24); }

extern "C" void fn_800A6CD0(void* self, int g, int x, int y)
{
    int t = fn_80075948(g, y);
    fn_8007B570(g, x, t, fn_8007B510(g, x, t) + 1);
}

extern "C" void* fn_800A6D30(void* p)
{
    fn_800A6D60(p);
    return p;
}

extern "C" int fn_800A71F8(int a)
{
    int r = -1;
    switch (a) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 1;
        break;
    case 2:
        r = 2;
        break;
    case 3:
        r = 3;
        break;
    }
    return r;
}

struct Unk800A724C_Stream {
    int m0;
    virtual void v1(int a, void* p, int n);
};

extern "C" void fn_800A724C(char* o, int a, Unk800A724C_Stream* s)
{
    s->v1(a, o, 0xF0);
    s->v1(a, o + 0xF0, 0x438);
    s->v1(a, o + 0x528, 0xC);
}

/* near-miss (7 of 43 slots): address-arithmetic operand order in the index expressions */

extern "C" void fn_800A7404(char* o, int i, int kind, int j, void* out, int* res)
{
    int k = fn_800A71F8(kind);
    char* base = o + 0x528;
    if (j < (signed char)base[k + i * 4]) {
        *res = *(int*)(o + (j * 4 + k * 0x14 + i * 0x50));
        fn_80403144(out, o + (i * 0x168 + 0xF0) + k * 0x5A + j * 0x12);
    } else {
        *res = -1;
    }
}

struct Unk800A74B0 {
    char pad0[0x534];
    int m534;
    int m538[5];
};

extern "C" int fn_800A74B0(Unk800A74B0* p, int i) { return p->m538[i]; }

extern "C" int fn_800A74C0(Unk800A74B0* p) { return p->m534; }

extern "C" void fn_800A74C8(Unk800A74B0* p, int v)
{
    if (v == -1) {
        p->m534 = v;
        return;
    }
    if (v > p->m534)
        p->m534 = v;
}

extern "C" void fn_800A74EC(Unk800A74B0* p)
{
    for (int i = 0; i < 5; i++)
        p->m538[i] = 0;
    p->m534 = -1;
}

extern "C" void fn_800A840C(void* p) { fn_80400560(p, 40); }

extern "C" void fn_800A8430(void* p) { fn_80400560(p, 40); }

extern "C" void fn_800A8454(void* p) { fn_80400560(p, 40); }

extern "C" void fn_800A8478(void* p) { fn_80400560(p, 40); }

extern "C" void fn_800A849C(void* p) { fn_80400560(p, 40); }

extern "C" void fn_800A84C0(void* p) { fn_80400560(p, 40); }

extern "C" void fn_800A84E4(void* p) { fn_80400560(p, 40); }

extern "C" void fn_800A8508(int a, int b, int c, char* out) { fn_8040B61C(out, lbl_80619308); }

extern "C" void fn_800A8534() {}

extern "C" void fn_800A8538(void* p) { fn_80400560(p, 40); }

extern "C" void fn_800A855C(int a, int b, int c, char* out) { fn_8040B61C(out, lbl_80619308); }

extern "C" void fn_800A8588() {}

extern "C" void fn_800A858C(void* p) { fn_80400560(p, 40); }

extern "C" void fn_800A85B0(int a, int b, int c, char* out) { fn_8040B61C(out, lbl_80619308); }

extern "C" void fn_800A85DC() {}

extern "C" void fn_800A85E0(void* p) { fn_80400560(p, 40); }

extern "C" void fn_800A8604(int a, int b, int c, char* out) { fn_8040B61C(out, lbl_80619308); }

extern "C" void fn_800A8630() {}

extern "C" void fn_800A8634(void* p) { fn_80400560(p, 40); }

extern "C" void fn_800A8658(int a, int b, int c, char* out) { fn_8040B61C(out, lbl_80619308); }
