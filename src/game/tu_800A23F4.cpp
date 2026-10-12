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
extern "C" int fn_800A4668(void* o);
extern "C" void fn_800A625C(void* o);
extern "C" void fn_800A6340(void* o);
extern "C" void fn_800A641C(void* o);
extern "C" int fn_80075948(int g, int a);
extern "C" void fn_80086EC0(int a, int b, int c);
extern "C" int fn_805701E4(void* p);
extern "C" void fn_8006BE18(int a);
extern "C" void fn_80081D88(void* a);
extern const float lbl_805B5DF0;
extern const float lbl_805B5DF4;
extern int lbl_8061994C;
extern float lbl_80619950;
extern const float lbl_805FF3E4;
extern "C" float fn_8055248C(int x);
extern "C" void fn_80353218(void* p);
extern "C" void fn_80072E90(int g, int a, int b, int c, int d, void* out);
extern "C" int fn_80566570(void* a);
extern "C" int fn_80566674(void* a);
extern "C" int fn_8007FB2C(int g, int a);
extern "C" int fn_8007FDA8(int g, int a, int b);
extern "C" int fn_80078A38(int g, int a);

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

struct FEO54 {
    int m0;
    int m4;
    const void* m8;
};
extern const char lbl_80649EC0[];
extern "C" void fn_8007B87C(int g, int a);
extern "C" int fn_8007B8C4(int g, int a, int b);
extern "C" int fn_8007B3E0(int g, int a, int b);
extern "C" void fn_8007B4A8(int g, int a, int b, int c);
extern "C" void fn_8056503C(int a);
extern "C" void fn_80590910(int a);
extern "C" int fn_8007B2FC(int g, int i);
extern "C" FEO54* fn_8054CBBC(FEO54* o, int a, int g);
extern "C" void fn_8054CBD8(FEO54* o, int a);

extern "C" void fn_800A23F4(Unk800A2688* p)
{
    int g = lbl_8061930C;
    fn_80077DAC(g);
    fn_8007B87C(g, fn_8007F7D0(g, 0));
    fn_8056503C(*(int*)((char*)p + 0x48));
    fn_80590910(*(int*)(g + 0x30));
    p->m70 = 4;
    p->m84 = fn_8007F9B4(g);
    int old = p->m78;
    p->m7C = old;
    p->m78 = 0;
    p->m74 = 2;
    p->m80 = 10;
    int e = fn_8007F7D0(g, 0);
    int n = fn_8007B2B0(g);
    int v = fn_8007B3E0(g, 0xF, e);
    if (v == v / 3 * 3) {
        fn_8007B4A8(g, 0x22, e, 0);
        for (int i = 0; i < n; i++) {
            if (fn_8007B648(g, 0xE, i) != 0) {
                int h = fn_8007B2FC(g, i);
                fn_8007B4A8(g, 0x10, h, fn_8007B8C4(g, 0x36, fn_8007B320(g, 0, h)));
            }
        }
    }
    FEO54 o;
    fn_8054CBBC(&o, fn_8007F7D0(lbl_8061930C, 0), lbl_8061930C);
    fn_8054CBD8(&o, 1);
    o.m8 = lbl_80649EC0;
}

extern "C" void fn_800A2598(Unk800A2688* p, int a)
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

extern "C" void fn_800A2688(Unk800A2688* p, int a)
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

extern "C" void fn_8040074C(void* p, int n);
extern const char lbl_8064B298[];
extern const char lbl_8064A550[];
extern const char lbl_8064A3B8[];
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

inline void FeArD2(FeAr* a)
{
    a->vp = lbl_8064A3B8;
    a->m4 = 0;
    a->mC = 0;
    a->m14 = 0;
}

inline void FeArDtor(FeAr* a)
{
    a->vp = lbl_8064A550;
}

extern "C" void fn_80538368(FeAr* a, int v);
extern "C" void fn_8055EBAC(int x, FeAr* a);
extern "C" int fn_8007B2FC(int g, int i);
struct Unk800A2EFC;
extern "C" int fn_800A2EFC(Unk800A2EFC* p);

extern "C" void fn_800A2738(Unk800A2EFC* self)
{
    FeAr a;
    int buf[0xCB2];
    FeArBase(&a, buf, 0xCB2);
    FeArMid(&a);
    FeArD2(&a);
    fn_80538368(&a, 0);
    int g = lbl_8061930C;
    int e = fn_8007F7D0(g, 0);
    int n = fn_8007B2B0(g);
    for (int i = 0; i < n; i++) {
        if (fn_8007B2FC(g, i) != e && fn_8007B648(g, 0xE, i) != 0) {
            fn_8055EBAC(fn_8007B5D8(g, 0, i), &a);
        }
    }
    fn_800A2EFC(self);
    FeArDtor(&a);
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

extern "C" int fn_800A2AE8(void* p) { return fn_8007F9B4(lbl_8061930C); }

struct Unk800A2B10 {
    char pad0[0x74];
    int m74;
};

extern "C" void fn_800A2B10(Unk800A2B10* p) { p->m74 = 0; }

struct Unk800A2B1C_Obj {
    int* m0;
    unsigned m4;
    char pad8[0x13D2C - 8];
    virtual ~Unk800A2B1C_Obj();
};
extern "C" char* fn_80546600(char* o);
extern "C" void fn_80547594(char* o, int a);
extern "C" void fn_80547610(char* o, int a, int b);
extern "C" int fn_8007A808(int g, int a, int b, int c);

extern "C" void fn_800A2B1C()
{
    int g = lbl_8061930C;
    unsigned i = 0;
    Unk800A2B1C_Obj* o = (Unk800A2B1C_Obj*)fn_80546600((char*)operator new(0x13D30, 0x100));
    fn_80547594((char*)o, 1);
    fn_80547610((char*)o, 1, 1);
    for (; i < o->m4; i++) {
        char* b = (char*)o->m0;
        int off = i * 4;
        fn_8007A808(g, 0xB, *(int*)(b + off), 0);
    }
    if (o) {
        delete o;
    }
}

extern "C" int fn_80085FB0();
extern "C" int fn_80085FB8(int j);
extern "C" unsigned fn_8007C3E8(int g);
extern "C" void fn_8007C644(int g, int a, int i, int k);
extern "C" int fn_8052DD18();
extern "C" int fn_8052DD20(int j);
extern "C" unsigned fn_8007C6B4(int g);
extern "C" void fn_8007C8A0(int g, int a, int i, int k);
extern "C" int fn_8053125C();
extern "C" int fn_80531264(int j);
extern "C" unsigned fn_8007C8D8(int g);
extern "C" void fn_8007CAC4(int g, int a, int i, int k);
extern "C" int fn_8053DDE8();
extern "C" int fn_8053DDF0(int j);
extern "C" unsigned fn_8007CAFC(int g);
extern "C" void fn_8007CCE8(int g, int a, int i, int k);
extern "C" int fn_80599A64();
extern "C" int fn_80599A6C(int j);
extern "C" unsigned fn_8007CD20(int g);
extern "C" void fn_8007CF0C(int g, int a, int i, int k);
extern "C" void fn_80072CE8(int g);

extern "C" void fn_800A2BE0()
{
    int g = lbl_8061930C;
    {
        int n = fn_80085FB0();
        for (unsigned i = 0; i < fn_8007C3E8(g); i++) {
            for (int j = 0; j < n; j++) {
                fn_8007C644(g, fn_80085FB8(j), i, 0x46);
            }
        }
    }
    {
        int n = fn_8052DD18();
        for (unsigned i = 0; i < fn_8007C6B4(g); i++) {
            for (int j = 0; j < n; j++) {
                fn_8007C8A0(g, fn_8052DD20(j), i, 0x46);
            }
        }
    }
    {
        int n = fn_8053125C();
        for (unsigned i = 0; i < fn_8007C8D8(g); i++) {
            for (int j = 0; j < n; j++) {
                fn_8007CAC4(g, fn_80531264(j), i, 0x46);
            }
        }
    }
    {
        int n = fn_8053DDE8();
        for (unsigned i = 0; i < fn_8007CAFC(g); i++) {
            for (int j = 0; j < n; j++) {
                fn_8007CCE8(g, fn_8053DDF0(j), i, 0x46);
            }
        }
    }
    {
        int n = fn_80599A64();
        for (unsigned i = 0; i < fn_8007CD20(g); i++) {
            for (int j = 0; j < n; j++) {
                fn_8007CF0C(g, fn_80599A6C(j), i, 0x46);
            }
        }
    }
    fn_80072CE8(g);
}

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

struct Unk800A3490_Pl {
    char pad0[0x198];
    int m198;
    char pad19C[0xFFC - 0x19C];
    int mFFC;
};

struct Unk800A3604_Q {
    char pad0[0x10];
    int m10;
    Unk800A3490_Pl* m14;
};

struct Unk806192E0 {
    int m0;
    Unk800A3604_Q* m4;
};

extern Unk806192E0* lbl_806192E0;

extern "C" void fn_800A3490(void* o)
{
    if (fn_800A4668(o)) {
        unsigned i = 0;
        fn_800A625C(o);
        fn_800A6340(o);
        fn_800A641C(o);
        int g = lbl_8061930C;
        Unk800A3604_Q* q = lbl_806192E0->m4;
        int a = q->m10;
        int c = q->m14->m198;
        int b = q->m14->mFFC;
        while (i < fn_8007F84C(g)) {
            int t = fn_8007F7D0(g, i);
            if (fn_80075948(g, c) == t)
                fn_80086EC0(a, 0, 0);
            else if (fn_80075948(g, b) == t)
                fn_80086EC0(a, 1, 0);
            i++;
        }
    }
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

extern "C" int fn_800A3BC0(Unk800A2EB4* p, int a, int b)
{
    if (fn_800A2EB4(p) == 1) {
        return 2;
    }
    int g = lbl_8061930C;
    float r = (float)a / (float)(unsigned)fn_8007FB2C(g, fn_80078A38(g, b));
    if (r <= 0.85f) {
        return r > 0.6f;
    }
    return 2;
}

struct Unk800A3C98 {
    char pad0[0x28];
    int m28;
};
extern int lbl_80619954;
extern int lbl_80619958;
extern "C" int fn_8007B8C4(int g, int a, int b);
extern "C" int fn_8056A5F4(int a, int k, int b, int c);
extern "C" int fn_8055B078(int a, int b, int c);
extern "C" int fn_8056B3CC(int a, int b);
extern "C" int fn_800D6FA0();
extern "C" int fn_800D7160(int a, int b, int c, int d, int e, int f, int g, void* h, int i);

extern "C" int fn_800A3C98(Unk800A3C98* p, int a, int b)
{
    if (lbl_80619954 == 0) {
        int g = lbl_8061930C;
        int k = fn_80078A38(g, b);
        if (k == 4) {
            return 10;
        }
        void* r22 = fn_800A3A10((Unk800A3AB0*)p, k);
        int r24 = 3;
        int h = fn_8056A5F4(p->m28, k, a, b);
        int t = fn_8055B078(*(int*)(g + 0x68), b, h);
        int same = fn_8007B8C4(g, 1, b) == fn_8007B8C4(g, 1, h);
        int c = fn_800A2EB4((Unk800A2EB4*)p);
        int d = fn_800A2E6C((Unk800A2E6C*)lbl_80619948);
        if (t != 0) {
            r24 = 0;
            if (same) {
                r24 = 2;
            }
        } else if (same) {
            r24 = 1;
        }
        int e = fn_8056B3CC(p->m28, b);
        return fn_800D7160(fn_800D6FA0(), a, k, c, d, b, e, r22, r24);
    }
    return lbl_80619958;
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

struct Unk800A42A4 {
    char pad0[0x6C];
    int m6C;
};

extern "C" void fn_800A3E6C(Unk800A3E6C* p);
extern "C" void fn_800A42A4(Unk800A42A4* p, int v);

/* Polymorphic 8-byte object built by fn_80353218 (stores m0 = 0 and the vptr
 * lbl_8064B718 at +4, g++ 2.95 layout). A class with virtuals lives in memory
 * (no ADDRESSOF pseudo), so retail recomputes `addi rX,r1,8` for each use. */
struct Unk80353218 {
    int m0;
    Unk80353218(); /* fn_80353218 */
    virtual void vf0();
};

extern "C" void fn_800A3DF8(Unk800A3E6C* o, int a, int b, int c, int d)
{
    Unk80353218 sp8;
    fn_80072E90(lbl_8061930C, a, b, c, d, &sp8);
    fn_800A42A4((Unk800A42A4*)o, c);
    fn_800A3E6C(o);
}

extern "C" void fn_800A42EC(Unk800A3E6C* p);

extern "C" void fn_800A3E6C(Unk800A3E6C* p)
{
    fn_800A42EC(p);
    p->m7C = 1;
    p->m84 = fn_8007F9B4(lbl_8061930C);
}

struct Unk800A4180 {
    char pad0[0x48];
    int m48;
    char pad4C[0x70 - 0x4C];
    int m70;
    int m74;
    int m78;
    char pad7C[4];
    int m80;
};
extern "C" int fn_805653B4(int a, void* b, void* c, void* d, void* e);
extern "C" int fn_80565BFC(int a);
extern "C" int fn_800A449C(void* p);

extern "C" void fn_800A4180(Unk800A4180* p)
{
    int k = p->m70;
    p->m74 = 0;
    p->m78 = 0;
    switch (k) {
    case 2: {
        void* a = fn_800A3AB0((Unk800A3AB0*)p);
        void* b = fn_800A3AF4((Unk800A3AB0*)p);
        void* c = fn_800A3B38((Unk800A3AB0*)p);
        void* d = fn_800A3B7C((Unk800A3AB0*)p);
        if (fn_805653B4(p->m48, a, b, c, d) == 1) {
            p->m74 = k;
            p->m80 = 8;
        }
        break;
    }
    case 3: {
        int r = fn_80565BFC(p->m48);
        if (r == 1) {
            if (fn_800A449C(p) == 1) {
                p->m74 = 2;
                p->m80 = 9;
            } else {
                fn_800A29C4((Unk800A2688*)p, fn_800A2AE8(p) + 0x16D);
                p->m74 = r;
            }
        }
        break;
    }
    case 4:
        if (fn_800A449C(p) == 1) {
            p->m74 = 2;
            p->m80 = 0xB;
        }
        break;
    }
}

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

struct Unk800A4360 {
    char pad0[0x24];
    void* m24;
    char pad28[0x6C - 0x28];
    int m6C;
    int m70;
    int m74;
    int m78;
    int m7C;
};
struct Unk800A4360_Sub {
    char pad0[0x1C];
    int m1C;
    char pad20[0x30 - 0x20];
    int m30;
};
extern "C" void fn_800A2330(void* p, int a);
extern "C" void fn_800A4CBC(void* p);
extern "C" void fn_8053FAD4(int a);
extern "C" void fn_8053FB70(int a);
extern "C" void fn_80553754(void* p);

extern "C" void fn_800A4360(Unk800A4360* p)
{
    if (fn_800A449C(p) == 0) {
        fn_800A4CBC(p);
        p->m78 = 3;
        return;
    }
    switch (p->m70) {
    case 1:
        p->m78 = 2;
        break;
    case 2:
        fn_800A2598((Unk800A2688*)p, p->m6C);
        break;
    case 3: {
        Unk800A4360_Sub* s = (Unk800A4360_Sub*)((char*)p + 0x2C);
        if (fn_80565BFC(s->m1C) == 1) {
            fn_800A2688((Unk800A2688*)p, p->m6C);
        } else {
            int t = s->m30;
            fn_8053FAD4(t);
            fn_8053FB70(t);
            fn_80564EB0((void*)s->m1C);
            int old = p->m78;
            p->m78 = 0;
            p->m7C = old;
            p->m74 = 0;
        }
        break;
    }
    case 4:
        if (p->m24 == 0) {
            p->m24 = fn_805535A4(operator new(0x33F4, 0x100));
        }
        fn_80553754(p->m24);
        p->m78 = 2;
        p->m70 = 5;
        break;
    case 5:
        fn_800A2330(p, p->m6C);
        break;
    }
}

/* near-miss: ok/v swap registers, one mr missing */

extern "C" int fn_800A449C(void* p)
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

extern "C" unsigned fn_8007FB40(int g, int a);
extern "C" int fn_8007FB98(int g, int a, int b, int c);
extern "C" int fn_80075808(int a);

extern "C" int fn_800A4558(void* self, int e)
{
    int g = lbl_8061930C;
    for (unsigned i = 0; i < fn_8007F84C(g); i++) {
        int t = fn_8007B320(g, fn_80083FC0(e), fn_8007F7D0(g, i));
        unsigned j = fn_8007FB40(g, e);
        if (j < fn_8007FB2C(g, e)) {
            int a = fn_8007FB98(g, j, 0, e);
            int b = fn_8007FB98(g, j, 1, e);
            if (a != b && (a == t || b == t || fn_80075808(a) == 1 || fn_80075808(b) == 1)) {
                return 1;
            }
        }
    }
    return 0;
}
