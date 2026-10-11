/*
 * Game code, .text 0x800A4668-0x800A8684 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */


extern int lbl_8061930C;
extern "C" void fn_8056B8C0(int a, int b);
extern "C" int fn_800768E0(int g, int a);
extern "C" int fn_80553CA8(void* p);
extern "C" int fn_80075948(int g, int a);
extern "C" int fn_8007B510(int g, int a, int b);
extern "C" void fn_8007B570(int g, int a, int b, int c);
extern "C" void fn_800A6D60(void* p);
extern "C" void fn_80400560(void* p, int n);
extern "C" char* fn_8040B61C(char* dst, const char* src);
extern const char* lbl_80619308;

struct Unk800A59F0 {
    char pad0[0x28];
    int m28;
};

extern "C" void fn_800A59F0(Unk800A59F0* p) { fn_8056B8C0(p->m28, lbl_8061930C); }

struct Unk800A641C_Pl {
    char pad0[0x198];
    int m198;
    char pad19C[0xD74 - 0x19C];
    int mD74;
    char padD78[0xE64 - 0xD78];
};

struct Unk800A641C_Q {
    char pad0[0x14];
    Unk800A641C_Pl* m14;
};

struct Unk806192E0 {
    int m0;
    Unk800A641C_Q* m4;
};

extern Unk806192E0* lbl_806192E0;

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
