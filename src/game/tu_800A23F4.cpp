/*
 * Game code, .text 0x800A23F4-0x800A4668 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */


extern "C" void* fn_805535A4(void* mem);
extern "C" void fn_805536B4(void* p);
extern int lbl_8061930C;
extern "C" int fn_8007F9B4(int a);
extern "C" int fn_80566674(void* p);
extern "C" int fn_80566520(void* p);
extern "C" int fn_80566570(void* p);
extern "C" int fn_80569128(void* p);
extern "C" void fn_8055395C(void* p);
extern "C" int fn_8054C940(void* p);
extern "C" int fn_8054C94C(void* p);
extern "C" int fn_800A55A4(void* p, int a, int b, int* c, int* d);
extern "C" int fn_805701E4(void* p);
extern "C" void fn_8006BE18(int a);
extern "C" void fn_80081D88(int a);

void* operator new(unsigned int size, int heap); /* 0x80377428 */

struct Unk800A286C {
    char pad0[0x24];
    void* m24;
    char pad28[0xC0];
    int mE8;
};

extern "C" void fn_800A286C(Unk800A286C* p)
{
    if (p->m24 == 0)
        p->m24 = fn_805535A4(operator new(0x33F4, 0x100));
    fn_805536B4(p->m24);
    p->mE8 = 0;
}

extern "C" void fn_800A2AE8() { fn_8007F9B4(lbl_8061930C); }

struct Unk800A2B10 {
    char pad0[0x74];
    int m74;
};

extern "C" void fn_800A2B10(Unk800A2B10* p) { p->m74 = 0; }

struct Unk800A2E6C {
    char pad0[0x48];
    void* m48;
};

extern "C" int fn_800A2E6C(Unk800A2E6C* p) { return fn_80566674(p->m48); }

struct Unk800A2E90 {
    char pad0[0x48];
    void* m48;
};

extern "C" int fn_800A2E90(Unk800A2E90* p) { return fn_80566520(p->m48); }

struct Unk800A2EB4 {
    char pad0[0x48];
    void* m48;
};

extern "C" int fn_800A2EB4(Unk800A2EB4* p) { return fn_80566570(p->m48); }

struct Unk800A2ED8 {
    char pad0[0x48];
    void* m48;
};

extern "C" int fn_800A2ED8(Unk800A2ED8* p) { return fn_80569128(p->m48); }

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

struct Unk800A2F14 {
    char pad0[0x24];
    void* m24;
};

extern "C" void fn_800A2F14(Unk800A2F14* p)
{
    if (p->m24)
        fn_8055395C(p->m24);
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

extern "C" int fn_800A31FC(Unk800A31FC* p) { return fn_8054C940(p->m50); }

struct Unk800A3220 {
    char pad0[0x50];
    void* m50;
};

extern "C" int fn_800A3220(Unk800A3220* p) { return fn_8054C94C(p->m50); }

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

extern "C" int fn_800A3430(Unk800A2EFC* p)
{
    int spC, sp8;
    sp8 = 0;
    spC = 0;
    if (fn_800A55A4(p, 1, 1, &sp8, &spC)) {
        fn_800A2EFC(p);
        return 1;
    }
    return 0;
}

struct Unk800A3578_Q {
    char pad0[0x10];
    int m10;
};

struct Unk800A3578 {
    char pad0[0x4C];
    Unk800A3578_Q* m4C;
};

extern "C" void fn_80570170(Unk800A3578_Q* q);

extern "C" void fn_800A3578(Unk800A3578* p)
{
    if (p->m4C->m10 == 1)
        fn_80570170(p->m4C);
}

struct Unk800A35A8 {
    char pad0[0x4C];
    void* m4C;
};

extern "C" int fn_800A35A8(Unk800A35A8* p) { return fn_805701E4(p->m4C); }

struct Unk800A35CC_Q {
    char pad0[8];
    int m8;
};

struct Unk800A35CC {
    char pad0[0x4C];
    Unk800A35CC_Q* m4C;
};

extern "C" void fn_805702CC(Unk800A35CC_Q* q);

extern "C" void fn_800A35CC(Unk800A35CC* p)
{
    Unk800A35CC_Q* q = p->m4C;
    fn_805702CC(q);
    fn_8006BE18(q->m8);
}

struct Unk800A3604_Q {
    char pad0[0x14];
    int m14;
};

struct Unk806192E0 {
    int m0;
    Unk800A3604_Q* m4;
};

extern Unk806192E0* lbl_806192E0;

extern "C" Unk800A3604_Q* fn_800A3604()
{
    Unk800A3604_Q* q = lbl_806192E0->m4;
    fn_80081D88(q->m14);
    return q;
}

struct Unk800A3640 {
    char pad0[0x4C];
    int m4C;
};

extern "C" void fn_805700C0(int a, Unk800A3604_Q* b);

extern "C" void fn_800A3640(Unk800A3640* p) { fn_805700C0(p->m4C, lbl_806192E0->m4); }

extern "C" void fn_800767DC(int a, Unk800A3604_Q* b);

extern "C" void fn_800A3910() { fn_800767DC(lbl_8061930C, lbl_806192E0->m4); }

struct Unk800A3AB0_Q {
    char padDBC[0xDBC];
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Unk800A3AB0 {
    char pad0[0x2C];
    Unk800A3AB0_Q* m2C;
    Unk800A3AB0_Q* m30;
    Unk800A3AB0_Q* m34;
    Unk800A3AB0_Q* m38;
};

extern "C" Unk800A3AB0_Q* fn_800A3AB0(Unk800A3AB0* p);
extern "C" Unk800A3AB0_Q* fn_800A3AF4(Unk800A3AB0* p);
extern "C" Unk800A3AB0_Q* fn_800A3B38(Unk800A3AB0* p);
extern "C" Unk800A3AB0_Q* fn_800A3B7C(Unk800A3AB0* p);
extern Unk800A2EB4* lbl_80619948;

extern "C" Unk800A3AB0_Q* fn_800A3A10(Unk800A3AB0* p, int k)
{
    Unk800A3AB0_Q* r = 0;
    if (fn_800A2EB4(lbl_80619948) == 0) {
        switch (k) {
        case 0:
            r = fn_800A3AB0(p);
            break;
        case 1:
            r = fn_800A3AF4(p);
            break;
        case 2:
            r = fn_800A3B38(p);
            break;
        case 3:
            r = fn_800A3B7C(p);
            break;
        default:
            r = fn_800A3AB0(p);
            break;
        }
    }
    return r;
}

extern "C" Unk800A3AB0_Q* fn_800A3AB0(Unk800A3AB0* p)
{
    Unk800A3AB0_Q* q = p->m2C;
    q->v3();
    return q;
}

extern "C" Unk800A3AB0_Q* fn_800A3AF4(Unk800A3AB0* p)
{
    Unk800A3AB0_Q* q = p->m30;
    q->v3();
    return q;
}

extern "C" Unk800A3AB0_Q* fn_800A3B38(Unk800A3AB0* p)
{
    Unk800A3AB0_Q* q = p->m34;
    q->v3();
    return q;
}

extern "C" Unk800A3AB0_Q* fn_800A3B7C(Unk800A3AB0* p)
{
    Unk800A3AB0_Q* q = p->m38;
    q->v3();
    return q;
}

extern "C" void fn_800A3DF4() {}

struct Unk800A3E6C {
    char pad0[0x7C];
    int m7C;
    char pad80[4];
    int m84;
};

extern "C" void fn_800A42EC(Unk800A3E6C* p);

extern "C" void fn_800A3E6C(Unk800A3E6C* p)
{
    fn_800A42EC(p);
    p->m7C = 1;
    p->m84 = fn_8007F9B4(lbl_8061930C);
}

struct Unk800A42A4 {
    char pad0[0x6C];
    int m6C;
};

extern "C" void fn_800A42A4(Unk800A42A4* p, int v)
{
    switch (v) {
    case 0x1101311:
        p->m6C = 0;
        return;
    case 0x2131311:
        p->m6C = 1;
        return;
    default:
        p->m6C = 3;
        return;
    }
}
