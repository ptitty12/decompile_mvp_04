/*
 * Game code, .text 0x800A23F4-0x800A4668 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */


extern int lbl_8061930C;
extern "C" void fn_80564EB0(void* a);
extern "C" int fn_80566520(void* a);
extern "C" void fn_80077CF8(int g);
extern "C" void fn_80077DAC(int g);
extern "C" int fn_8007B2B0(int g);
extern "C" void fn_8007B6B8(int g, int a, int b, int c);
extern "C" int fn_8007F9B4(int g);
extern "C" int fn_8007F9E8(int g);
extern "C" void fn_805909D4(int a);
extern "C" int fn_8007F7D0(int g, int a);
extern "C" int fn_8007B320(int g, int a, int b);
extern "C" void fn_80552054();
extern "C" void* fn_805535A4(void* mem);
extern "C" void fn_805536B4(void* p);
extern "C" int fn_8007FB6C(int g, int e);
extern "C" int fn_8007FBC0(int g, int a, int b);
extern "C" int fn_8007FBDC(int g, int a, int b);
extern "C" int fn_8007F9B4(int a);
extern "C" int fn_8008FCC8(int a);
extern "C" unsigned fn_8007C458(int g);
extern "C" int fn_8007C67C(int g, int a, int b);
extern "C" int fn_8007C4A4(int g, int a);
extern "C" int fn_8007C034(int g, int a, int b);
extern "C" void fn_80072C28(int g);
extern "C" int fn_80566674(void* p);
extern "C" int fn_80566520(void* p);
extern "C" int fn_80566570(void* p);
extern "C" int fn_80569128(void* p);
extern "C" void fn_8055395C(void* p);
extern "C" int fn_8054C940(void* p);
extern "C" int fn_8054C94C(void* p);
extern "C" int fn_8007F84C(int g);
extern "C" int fn_80083FC0(int e);
extern "C" int fn_800A588C(void* o, int v);
extern "C" int fn_8007B648(int g, int a, int b);
extern "C" int fn_8007B5D8(int g, int a, int b);
extern "C" int fn_800A55A4(void* p, int a, int b, int* c, int* d);
extern "C" int fn_805701E4(void* p);
extern "C" void fn_8006BE18(int a);
extern "C" void fn_80081D88(int a);
extern const float lbl_805B5DF0;
extern const float lbl_805B5DF4;
extern int lbl_8061994C;
extern float lbl_80619950;
extern const float lbl_805FF3E4;
extern "C" float fn_8055248C(int x);
extern "C" int fn_80566570(void* a);
extern "C" int fn_80566674(void* a);
extern "C" int fn_8007FB2C(int g, int a);
extern "C" int fn_8007FDA8(int g, int a, int b);

/* state object of the game flow (fields seen in the unit: +0x70..+0x98) */
struct Unk800A2688 {
    char pad0[0x70];
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
};

struct Unk800A2598_Sub {
    char pad0[0x1C];
    void* m1C;
};

extern "C" void fn_800A6618(Unk800A2688* p, int a);

extern "C" void fn_800A2598(Unk800A2688* p)
{
    Unk800A2598_Sub* sub = (Unk800A2598_Sub*)((char*)p + 0x2C);
    fn_800A6618(p, 0);
    fn_80564EB0(sub->m1C);
    if (fn_80566520(sub->m1C) == 0) {
        unsigned i = 0;
        int g = lbl_8061930C;
        fn_80077CF8(g);
        fn_80077DAC(g);
        unsigned n = fn_8007B2B0(g);
        if (i < n) {
            do {
                fn_8007B6B8(g, 0x12, i, 0);
                i++;
            } while (i < n);
        }
        int old = p->m84;
        p->m70 = 3;
        p->m84 = fn_8007F9B4(g);
        p->m88 = fn_8007F9E8(g);
        p->m98 = p->m84 - old;
        p->m8C = -1;
        p->m90 = -1;
        p->m94 = -1;
    }
    int t = p->m78;
    p->m7C = t;
    p->m78 = 0;
    p->m74 = 0;
}

extern "C" void fn_800A6618(Unk800A2688* p, int a);
extern "C" void fn_800A6484(Unk800A2688* p);

extern "C" void fn_800A2688(Unk800A2688* p)
{
    fn_805909D4(*(int*)(lbl_8061930C + 0x30));
    int t = fn_8007F7D0(lbl_8061930C, 0);
    fn_8007B320(lbl_8061930C, 0, t);
    fn_80552054();
    fn_800A6618(p, 1);
    p->m7C = p->m78;
    p->m78 = 2;
    p->m84 = fn_8007F9B4(lbl_8061930C) + 1;
    p->m88 = -1;
    p->m90 = -1;
    p->m94 = -1;
    p->m8C = -1;
    p->m98 = 0;
    fn_800A6484(p);
    p->m70 = 1;
}

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

struct Unk800A2910_R {
    char pad0[0x107F0];
    int m107F0;
    int m107F4;
    int m107F8;
};

struct Unk800A28C4_Obj {
    int m0;
    int m4;
    Unk800A2910_R* m8;
    ~Unk800A28C4_Obj();
};

struct Unk800A28C4 {
    char pad0[0x24];
    Unk800A28C4_Obj* m24;
};

extern "C" void fn_80553DA0(Unk800A28C4_Obj* o);

extern "C" void fn_800A28C4(Unk800A28C4* p)
{
    fn_80553DA0(p->m24);
    if (p->m24) {
        delete p->m24;
        p->m24 = 0;
    }
}

extern "C" void fn_800A2910(Unk800A28C4* p)
{
    if (p->m24->m8->m107F8 == 0)
        fn_800A28C4(p);
}

extern "C" void fn_800A2948(Unk800A2688* p)
{
    if (p->m74 != 2) {
        int old = p->m84;
        int g = lbl_8061930C;
        p->m84 = fn_8007F9B4(g);
        p->m88 = fn_8007F9E8(g);
        p->m98 = p->m84 - old;
        p->m8C = p->m84;
        p->m90 = -1;
        p->m94 = -1;
        p->m74 = 1;
    }
}

/* near-miss (10 of 73 slots): g and x take each other's callee-saved registers */

extern "C" void fn_800A29C4(Unk800A2688* p, int limit)
{
    if (p->m74 != 2) {
        int g = lbl_8061930C;
        p->m8C = fn_8007F9B4(g);
        int hiA = fn_8007F9E8(g);
        int hiB = fn_8007F9B4(g);
        volatile int sp8 = 0;
        int e = 0;
        do {
            int a = fn_8007FB6C(g, e);
            if (a != -1) {
                int x = fn_8007FBC0(g, a, sp8);
                int y = fn_8007FBDC(g, a, sp8);
                if (hiB <= x) {
                    hiB = x;
                    if (hiA < y)
                        hiA = y;
                }
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
        if (limit > hiB)
            limit = hiB + 1;
        if (p->m74 != 1 || (p->m90 != -1 && p->m90 < limit)) {
            p->m90 = limit;
            p->m94 = 0;
        }
        p->m74 = 1;
    }
}

extern "C" void fn_800A2AE8() { fn_8007F9B4(lbl_8061930C); }

struct Unk800A2B10 {
    char pad0[0x74];
    int m74;
};

extern "C" void fn_800A2B10(Unk800A2B10* p) { p->m74 = 0; }

extern "C" void fn_800A2DCC()
{
    int g = lbl_8061930C;
    unsigned i = fn_8008FCC8(0) == 1;
    while (i < fn_8007C458(g)) {
        if (fn_8007C67C(g, 0xE, i) == 0 && fn_8007C034(g, 0, fn_8007C4A4(g, i)) == 1)
            i--;
        i++;
    }
    fn_80072C28(g);
}

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

extern "C" int fn_800A2F58(Unk800A28C4* p)
{
    int ret = 0;
    if (p->m24) {
        Unk800A2910_R* r = p->m24->m8;
        int v = 0;
        if (r)
            v = r->m107F0 == 1;
        if (v)
            ret = 1;
    }
    return ret;
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

extern "C" int fn_800A3270(void* o, int* a, int* b)
{
    int g = lbl_8061930C;
    int i = 0;
    int n = fn_8007F84C(g);
    if (i < n) {
        do {
            int h = fn_8007F7D0(g, i);
            volatile int sp8 = 0;
            int e = 0;
            do {
                int v = fn_8007B320(g, fn_80083FC0(e), h);
                *a = v;
                int r = fn_800A588C(o, v);
                *b = r;
                if (r != 0)
                    return 0;
                int c = sp8;
                int t;
                if (c > 3)
                    t = c;
                else
                    t = c + 1;
                sp8 = t;
                e = t;
            } while (e <= 3);
            i++;
        } while (i < n);
    }
    return 1;
}

extern "C" int fn_800A3348(void* o, int* a, int* b)
{
    int g = lbl_8061930C;
    int i = 0;
    int n = fn_8007B2B0(g);
    if (i < n) {
        do {
            int cnt = 0;
            if (fn_8007B648(g, 0xE, i) != 0)
                cnt = 4;
            volatile int sp8;
            int t = 0;
            int e;
            while (sp8 = t, e = t, e < cnt) {
                int v = fn_8007B5D8(g, fn_80083FC0(e), i);
                *a = v;
                int r = fn_800A588C(o, v);
                *b = r;
                if (r != 0)
                    return 0;
                int c = sp8;
                if (c > 3)
                    t = c;
                else
                    t = c + 1;
            }
            i++;
        } while (i < n);
    }
    return 1;
}

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

struct Unk800A39C4 {
    char pad0[0x9C];
    int m9C;
    float mA0;
};

extern "C" float fn_800A39C4(Unk800A39C4* p, int x);

extern "C" float fn_800A3944(Unk800A39C4* p, int x, int kind)
{
    float r = lbl_805B5DF0;
    r = (fn_800A39C4(p, x) - lbl_805B5DF4) * 2.0f;
    if (lbl_8061994C != 0)
        r = lbl_80619950;
    if (kind == 1)
        r = -r;
    return r;
}

extern "C" float fn_800A39C4(Unk800A39C4* p, int x)
{
    if (p->m9C == 1)
        return p->mA0;
    float t = fn_8055248C(x);
    return t / lbl_805FF3E4;
}

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
    char pad0[0x48];
    void* m48;
    char pad4C[0x70 - 0x4C];
    int m70;
    char pad74[8];
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

struct Unk800A42EC_Sub {
    char pad0[0x1C];
    void* m1C;
};

extern "C" void fn_800A42EC(Unk800A3E6C* p)
{
    int v;
    Unk800A42EC_Sub* q = (Unk800A42EC_Sub*)((char*)p + 0x2C);
    if (fn_80566570(q->m1C) == 1)
        v = 3;
    else if (fn_80566520(q->m1C) == 1)
        v = 2;
    else if (fn_80566674(q->m1C) == 1)
        v = 4;
    else
        return;
    p->m70 = v;
}

/* near-miss: ok/v swap registers, one mr missing */

extern "C" int fn_800A449C()
{
    int g = lbl_8061930C;
    int ok = 1;
    volatile int sp8 = 0;
    int e = 0;
    do {
        int v = 0;
        if (fn_8007FB2C(g, e) == 0 || fn_8007FDA8(g, fn_8007FB2C(g, sp8) - 1, sp8) != 0)
            v = 1;
        int both = 0;
        if (ok && v)
            both = 1;
        int c = sp8;
        ok = both;
        int t;
        if (c > 3)
            t = c;
        else
            t = c + 1;
        sp8 = t;
        e = t;
    } while (e <= 3);
    return ok;
}
