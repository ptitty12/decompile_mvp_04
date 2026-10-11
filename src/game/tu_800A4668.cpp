/*
 * Game code, .text 0x800A4668-0x800A8684 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */


extern int lbl_8061930C;
extern "C" unsigned fn_8007F198(int g, int team);
extern "C" int fn_8007F24C(int g, int team, int j);
extern "C" int fn_8007A6A0(int g, int a, int e);
extern "C" void fn_8056B8C0(int a, int b);
extern "C" int fn_8007F7D0(int g, int a);
extern "C" int fn_8007B320(int g, int a, int b);
extern "C" void fn_80551A80(int a, int b);
extern "C" int fn_80083FC0(int e);
extern "C" int fn_800A3C98(void* o, int a, int b);
extern "C" int fn_800768E0(int g, int a);
extern "C" int fn_80553CA8(void* p);
extern "C" int fn_80075948(int g, int a);
extern "C" int fn_8007B510(int g, int a, int b);
extern "C" void fn_8007B570(int g, int a, int b, int c);
extern "C" void fn_800A6D60(void* p);
extern "C" void fn_80400560(void* p, int n);
extern "C" char* fn_8040B61C(char* dst, const char* src);
extern const char* lbl_80619308;

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
    char pad18[0x88 - 0x18];
    int m88;
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

struct Unk800A59F0 {
    char pad0[0x28];
    int m28;
};

extern "C" void fn_800A59F0(Unk800A59F0* p) { fn_8056B8C0(p->m28, lbl_8061930C); }

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
