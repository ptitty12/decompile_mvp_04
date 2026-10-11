/*
 * Game code, .text 0x8009FC5C-0x800A23F4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */


extern "C" char* fn_8040B61C(char* dst, const char* src);
extern const char* lbl_80619308;
extern "C" void fn_80553E4C(void* p);
extern "C" void fn_80553E54(void* p);
extern "C" void fn_80553E60(void* p);

extern "C" void fn_8009FE64(int a, int b, int c, char* out) { fn_8040B61C(out, lbl_80619308); }

extern "C" void fn_800A001C() {}

extern "C" int fn_800A07B4() { return 0; }

extern "C" int fn_800A07BC() { return 0; }

extern "C" void fn_800A0810(int a, int b, int c, char* out) { fn_8040B61C(out, lbl_80619308); }

extern "C" void fn_800A0954() {}

struct Unk800A1960_Q {
    char pad0[8];
    int m8;
};

struct Unk800A1960 {
    char pad0[0x24];
    Unk800A1960_Q* m24;
};

extern "C" int fn_800A1960(Unk800A1960* p)
{
    Unk800A1960_Q* q = p->m24;
    if (!q)
        return 0;
    return q->m8;
}

struct Unk800A1978 {
    char pad0[0x24];
    void* m24;
};

extern "C" void fn_800A1978(Unk800A1978* p) { fn_80553E4C(p->m24); }

struct Unk800A199C {
    char pad0[0x24];
    void* m24;
};

extern "C" void fn_800A199C(Unk800A199C* p) { fn_80553E54(p->m24); }

struct Unk800A19C0 {
    char pad0[0x24];
    void* m24;
};

extern "C" void fn_800A19C0(Unk800A19C0* p) { fn_80553E60(p->m24); }

struct Unk800A2328 {
    char pad0[0x6C];
    int m6C;
};

extern "C" void fn_800A2328(Unk800A2328* p, int v) { p->m6C = v; }
