/*
 * Game code, .text 0x800A4668-0x800A8684 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */


extern "C" void fn_80553CA8(void* p);
extern "C" void fn_80400560(void* p, int n);
extern "C" char* fn_8040B61C(char* dst, const char* src);
extern const char* lbl_80619308;

struct Unk800A65F4 {
    char pad0[0x24];
    void* m24;
};

extern "C" void fn_800A65F4(Unk800A65F4* p) { fn_80553CA8(p->m24); }

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
