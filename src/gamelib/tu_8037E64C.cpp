/*
 * EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib), built with
 * the game flags (cflags_game: -Os -G0 -ffloat-store),
 * .text 0x8037E64C-0x80382BB8 (code-only unit, 47 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

struct Unk8037E64C {
    char pad0[4];
    int m4;
    char* m8;
};

struct Unk8037E6F4 {
    float m0;
    char m4;
    int m8;
};

struct Unk8037E714 {
    int m0;
    int m4;
    int m8;
};

struct Unk8037ECA4 {
    char pad0[0x2C];
    int m2C;
    int m30;
    int m34;
    char pad38[0x84 - 0x38];
    int m84;
};

struct Unk8037FCE4_Inner {
    char pad0[8];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7();
};

struct Unk8037FCE4 {
    char padC[0xC];
    Unk8037FCE4_Inner* mC;
};

struct U {
    char pad0[0x4000];
};

extern "C" {
void fn_80384A48(void* p);
void fn_803809BC(char* o, int a, char* slot, int b, int c, int d);
}

extern "C" int fn_8037E64C(Unk8037E64C* o, int key)
{
    for (int i = 0; i < o->m4; i++) {
        if (*(int*)(o->m8 + i * 16) == key)
            return i;
    }
    return -1;
}

extern "C" void fn_8037E6F4(Unk8037E6F4* o)
{
    o->m0 = 1.0f;
    o->m4 = 0;
    o->m8 = 0;
}

extern "C" void fn_8037E714(Unk8037E714* dst, const Unk8037E714* src)
{
    if (src != 0)
        *dst = *src;
}

extern "C" void fn_8037E738() {}

extern "C" void fn_8037E904(char* self)
{
    fn_8037E6F4((Unk8037E6F4*)(self + 4));
}

extern "C" void fn_8037ECA4(Unk8037ECA4* o, int v)
{
    o->m84 = v;
    if (v == 0) {
        o->m2C = v;
        o->m34 = v;
        o->m30 = v;
    }
}

extern "C" int fn_8037FCE4(Unk8037FCE4* o)
{
    return o->mC->v7();
}

extern "C" void fn_80380920(char* o)
{
    char* p = o + 0x10;
    for (int i = 3; i != 0; i--) {
        fn_8037ECA4((Unk8037ECA4*)p, 0);
        p += 0x88;
    }
}

/* near-miss: retail keeps the byte offset in r11 and forms o + 0x10 only when the slot is used (addi r9,r3,16; lwzx r10,r9,r11); 21 vs 22 insns */
extern "C" int fn_80380964(char* o)
{
    int r = 0;
    int off = (((signed char)o[0x861] + 2) % 3) * 0x88;
    if (*(int*)(o + off + 0x94) != 0) {
        char* b = o + 0x10;
        r = *(int*)(b + off);
    }
    return r;
}

extern "C" void fn_80380BB0(char* o, int a)
{
    fn_803809BC(o, a, o + 0x10 + (((signed char)o[0x861] + 1) % 3) * 0x88, *(int*)(o + 0x884), 0, 0);
}

extern "C" void fn_80382B94(U* self, void* p)
{
    fn_80384A48(p);
}
