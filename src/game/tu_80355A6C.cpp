/*
 * Game code, .text 0x80355A6C-0x803560F8 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

struct Unk803541D4_E {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    inline int EqLo(const Unk803541D4_E& o) const
    {
        int r = 0;
        if (m8 == o.m8)
            r = mC == o.mC;
        return r;
    }
    inline int Eq(const Unk803541D4_E& o) const
    {
        int lo = EqLo(o);
        int r = 0;
        if (o.m0 == m0 && lo)
            r = 1;
        return r;
    }
    inline int EqAll(const Unk803541D4_E& o) const
    {
        int r = 0;
        if (o.m1C == m1C && m20 == o.m20) {
            if (Eq(o))
                r = 1;
        }
        return r;
    }
};

struct Unk803541D4 {
    Unk803541D4_E* m0;
    unsigned m4;
    int m8;
    unsigned mC;
};

struct Unk80354940_V : Unk803541D4 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual int v19(int i);
};

extern "C" void fn_8040074C(void* p, unsigned n);

struct Unk80353E68 {
    int* m0;
    unsigned m4;
    int m8;
    unsigned mC;
    inline void Clear()
    {
        fn_8040074C(m0, m8 << 2);
        m4 = 0;
        mC = 0;
    }
    inline int Find(int v)
    {
        unsigned i;
        for (i = 0; i < m4; i++) {
            if (m0[i] == v)
                return i;
        }
        return -1;
    }
    inline void Add(int v)
    {
        if (m4 < m8) {
            m0[m4] = v;
            m4++;
        }
    }
};

struct Unk80354940 : Unk80354940_V {
    Unk80353E68 m14;
};

extern "C" int fn_80355AD0(Unk80354940* s)
{
    int n = 0;
    for (unsigned i = 0; i < s->m4;) {
        if (s->v19(i++) == 1)
            n++;
    }
    return n;
}

struct Unk8034468C {
    const void* m0;
    char pad4[0x9A - 4];
    unsigned char m9A;
    char pad9B[0xFE - 0x9B];
    unsigned char mFE;
};

struct Unk803442CC {
    const void* m0;
};

extern "C" Unk803442CC* fn_8035709C(Unk803442CC* self);

extern char lbl_8065D240[];

extern "C" Unk8034468C* fn_80355D08(Unk8034468C* self)
{
    fn_8035709C((Unk803442CC*)self);
    self->m0 = lbl_8065D240;
    return self;
}

extern char lbl_8065D1D0[];

extern "C" Unk8034468C* fn_80355D44(Unk8034468C* self)
{
    fn_8035709C((Unk803442CC*)self);
    self->m0 = lbl_8065D1D0;
    return self;
}

extern char lbl_8065D2B0[];

extern "C" Unk8034468C* fn_80355D80(Unk8034468C* self)
{
    fn_8035709C((Unk803442CC*)self);
    self->m0 = lbl_8065D2B0;
    return self;
}

extern char lbl_8065D278[];

extern "C" Unk8034468C* fn_80355E34(Unk8034468C* self)
{
    fn_8035709C((Unk803442CC*)self);
    self->m0 = lbl_8065D278;
    return self;
}

extern char lbl_8065D048[];

extern "C" Unk8034468C* fn_80355F60(Unk8034468C* self)
{
    fn_8035709C((Unk803442CC*)self);
    self->m0 = lbl_8065D048;
    return self;
}

extern char lbl_8065D010[];

extern "C" Unk8034468C* fn_80355F9C(Unk8034468C* self)
{
    fn_8035709C((Unk803442CC*)self);
    self->m0 = lbl_8065D010;
    return self;
}

struct DtorAt0 { const void* m; };

extern "C" void fn_8035686C(DtorAt0* self, int chrg);

extern "C" void fn_80355FD8(DtorAt0* s, int chrg)
{
    fn_8035686C(s, chrg);
}

extern "C" void fn_80355FF8(DtorAt0* s, int chrg)
{
    fn_8035686C(s, chrg);
}

extern "C" void fn_80356018(DtorAt0* s, int chrg)
{
    fn_8035686C(s, chrg);
}

extern "C" void fn_80356C04(DtorAt0* self, int chrg);

extern "C" void fn_80356038(DtorAt0* s, int chrg)
{
    fn_80356C04(s, chrg);
}

extern "C" void fn_80356058(DtorAt0* s, int chrg)
{
    fn_80356C04(s, chrg);
}

extern "C" void fn_80356078(DtorAt0* s, int chrg)
{
    fn_80356C04(s, chrg);
}

extern "C" void fn_80356098(DtorAt0* s, int chrg)
{
    fn_80356C04(s, chrg);
}

extern "C" void fn_803560B8(DtorAt0* s, int chrg)
{
    fn_80356C04(s, chrg);
}

extern "C" void fn_803560D8(DtorAt0* s, int chrg)
{
    fn_80356C04(s, chrg);
}
