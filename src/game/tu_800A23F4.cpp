/*
 * Game code, .text 0x800A23F4-0x800A4668 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */


extern "C" void fn_80566674(void* p);
extern "C" void fn_80566520(void* p);
extern "C" void fn_80566570(void* p);
extern "C" void fn_80569128(void* p);
extern "C" void fn_8054C940(void* p);
extern "C" void fn_8054C94C(void* p);
extern "C" void fn_805701E4(void* p);

struct Unk800A2B10 {
    char pad0[0x74];
    int m74;
};

extern "C" void fn_800A2B10(Unk800A2B10* p) { p->m74 = 0; }

struct Unk800A2E6C {
    char pad0[0x48];
    void* m48;
};

extern "C" void fn_800A2E6C(Unk800A2E6C* p) { fn_80566674(p->m48); }

struct Unk800A2E90 {
    char pad0[0x48];
    void* m48;
};

extern "C" void fn_800A2E90(Unk800A2E90* p) { fn_80566520(p->m48); }

struct Unk800A2EB4 {
    char pad0[0x48];
    void* m48;
};

extern "C" void fn_800A2EB4(Unk800A2EB4* p) { fn_80566570(p->m48); }

struct Unk800A2ED8 {
    char pad0[0x48];
    void* m48;
};

extern "C" void fn_800A2ED8(Unk800A2ED8* p) { fn_80569128(p->m48); }

struct Unk800A2EFC {
    char pad0[0x24];
    void* m24;
};

extern "C" int fn_800A2EFC(Unk800A2EFC* p)
{
    if (p->m24)
        return 1;
    return 0;
}

struct Unk800A2F40_Q {
    char pad0[0x10];
    int m10;
};

struct Unk800A2F40 {
    char pad0[0x24];
    Unk800A2F40_Q* m24;
};

extern "C" int fn_800A2F40(Unk800A2F40* p)
{
    Unk800A2F40_Q* q = p->m24;
    if (!q)
        return 9;
    return q->m10;
}

struct Unk800A31D0 {
    char pad0[0x70];
    int m70;
    int m74;
};

extern "C" int fn_800A31D0(Unk800A31D0* p)
{
    return p->m74 == 0 && (unsigned)(p->m70 - 2) <= 2;
}

struct Unk800A31FC {
    char pad0[0x50];
    void* m50;
};

extern "C" void fn_800A31FC(Unk800A31FC* p) { fn_8054C940(p->m50); }

struct Unk800A3220 {
    char pad0[0x50];
    void* m50;
};

extern "C" void fn_800A3220(Unk800A3220* p) { fn_8054C94C(p->m50); }

struct Unk800A3244 {
    char padA4[0xA4];
    int mA4;
};

extern "C" int fn_800A3244(Unk800A3244* p) { return p->mA4; }

struct Unk800A324C_Q {
    char pad0[8];
    int m8;
    int mC;
    int m10;
};

struct Unk800A324C {
    char pad0[0x50];
    Unk800A324C_Q* m50;
};

extern "C" int fn_800A324C(Unk800A324C* p) { return p->m50->m8; }

extern "C" int fn_800A3258(Unk800A324C* p) { return p->m50->mC; }

extern "C" int fn_800A3264(Unk800A324C* p) { return p->m50->m10; }

struct Unk800A35A8 {
    char pad0[0x4C];
    void* m4C;
};

extern "C" void fn_800A35A8(Unk800A35A8* p) { fn_805701E4(p->m4C); }

extern "C" void fn_800A3DF4() {}
