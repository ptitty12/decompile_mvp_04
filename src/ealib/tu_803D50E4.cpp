/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803D50E4-0x803D7830 (code-only unit, 34 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

extern "C" {
unsigned strlen(const char* s);
int strncmp(const char* a, const char* b, unsigned n);
}

struct Mtx4 {
    float m[16];
};

/* Sequence of 16-byte records (name pointer at +0): begin at +0, count at +4. */
struct Unk803D50E4Rec {
    const char* m0;
    int m4;
    int m8;
    int mC;
};
struct Unk803D50E4Seq {
    Unk803D50E4Rec* m0;
    int m4;
};
struct Unk803D50E4It {
    Unk803D50E4Rec* p;
};

/* Scene-like object: child pointer array at +8 (count at +0x38), scale at +0x54, int table at +0x5C. */
struct Unk803D50E4Obj {
    int m0;
    int m4;
    void** m8;
    int mC;
    char pad10[0x38 - 0x10];
    int m38;
    int m3C;
    char pad40[0x54 - 0x40];
    float m54;
    int pad58;
    int* m5C;
};

/* Matrix-like object: 4x4 floats at +0 (identity by default), int words at +0x40..+0x50. */
struct Unk803D50E4Mat {
    float m[14];
    float m38;
    float m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
    int m50;
};

struct Unk803D50E4Rec6 {
    char pad0[6];
    unsigned short m6;
};

struct Unk803D50E4Dev {
    char padDC[0xDC];
    int mDC;
};

extern int lbl_806AA900[];
extern int lbl_806279B8;

extern "C" {
void fn_803DFA2C(Mtx4* dst, Mtx4* src);
void fn_803DFCB0(Mtx4* dst, float x, float y, float z, float w);
void fn_803E1C44(void* o, Mtx4* m);
void fn_803D74EC(Unk803D50E4Dev* d);
void fn_803D7830(void);
void fn_803D6528(void* out, Unk803D50E4Obj* self, int a);
void fn_803D675C(Unk803D50E4Obj* self, void* t, int b);
void fn_803D7414(int a, int b);
}

extern "C" void fn_803D50E4(Unk803D50E4Obj* self, int v)
{
    self->mC = v;
    *(short*)((char*)self + 0x10) = 0;
}

extern "C" int fn_803D50F4(int unused, float* out)
{
    int z = 0;
    *out = (float)z;
    return 1;
}

extern "C" void fn_803D5F6C(Unk803D50E4Obj* self, int v)
{
    self->m38 = v;
}

extern "C" void fn_803D5F74(Unk803D50E4Obj* self, int v)
{
    self->m3C = v;
}

extern "C" void fn_803D6098(Unk803D50E4Obj* self, Mtx4* src)
{
    Mtx4 m;
    int i = 0;
    fn_803DFA2C(&m, src);
    float s = self->m54;
    fn_803DFCB0(&m, s, s, s, 1.0f);
    for (; i < self->m38; i++) {
        void* o = self->m8[i];
        if (o)
            fn_803E1C44(o, &m);
    }
}

extern "C" int fn_803D6124(Unk803D50E4Obj* self)
{
    return self->mC;
}

extern "C" void fn_803D612C(Unk803D50E4Obj* self, int idx, int v)
{
    int arr = (int)self->m5C;
    if (arr == 0)
        return;
    *(int*)(arr + idx * 4) = v;
}

extern "C" Unk803D50E4Mat* fn_803D700C(Unk803D50E4Mat* self)
{
    self->m40 = 0;
    self->m44 = 0;
    self->m48 = 0;
    self->m4C = 0;
    self->m[0] = 1.0f;
    self->m[1] = 0.0f;
    self->m[2] = 0.0f;
    self->m50 = 0;
    self->m[3] = 0.0f;
    self->m[4] = 0.0f;
    self->m[5] = 1.0f;
    self->m[6] = 0.0f;
    self->m[7] = 0.0f;
    self->m[8] = 0.0f;
    self->m[9] = 0.0f;
    self->m[10] = 1.0f;
    self->m[11] = 0.0f;
    self->m[12] = 0.0f;
    self->m[13] = 0.0f;
    self->m38 = 0.0f;
    self->m3C = 1.0f;
    return self;
}

/* near-miss (2 instructions longer): the reverse search over the 16-byte records; retail keeps the
   record pointer one element ahead and rebuilds the end pointer on exit. */
extern "C" Unk803D50E4It fn_803D7378(Unk803D50E4Seq* s, const char* name)
{
    Unk803D50E4It it;
    Unk803D50E4Rec* p = s->m0 + s->m4;
    Unk803D50E4Rec* stop = s->m0 - 1;
    for (; p != stop; p--) {
        if (strncmp(name, p->m0, strlen(name)) == 0) {
            it.p = p + 1;
            return it;
        }
    }
    it.p = s->m0 + s->m4;
    return it;
}

extern "C" void fn_803D7414(int a, int b)
{
    if (b == 0xFFFF && a != 0) {
        lbl_806AA900[0] = 4;
        lbl_806AA900[1] = 4;
        lbl_806AA900[2] = 1;
    }
}

extern "C" void fn_803D744C(Unk803D50E4Dev* self)
{
    self->mDC = lbl_806279B8 - 5;
    fn_803D74EC(self);
}

extern "C" void fn_803D7480()
{
    fn_803D7830();
}

extern "C" void fn_803D74A0(Unk803D50E4Obj* self, int a, int b)
{
    char t[0x1C];
    fn_803D6528(t, self, a);
    fn_803D675C(self, t, b);
}

extern "C" void fn_803D76F4(Mtx4* dst, Mtx4* src)
{
    *dst = *src;
}

/* near-miss (4 instructions shorter): the forward search; retail recomputes the end pointer (count * 16 +
   begin) after every step and stores it in a stack slot (stw r0,8(r1)) that is never read, as if the end
   iterator were a struct temporary. Tried an inline struct-returning EndOf() in three loop shapes (plain
   register use, or an extra flag); none gives the stack store. */
extern "C" Unk803D50E4It fn_803D775C(Unk803D50E4Seq* s, const char* name)
{
    Unk803D50E4It it;
    it.p = s->m0;
    while (it.p != s->m0 + s->m4) {
        if (strncmp(name, it.p->m0, strlen(name)) == 0)
            break;
        it.p++;
    }
    return it;
}

extern "C" int fn_803D77EC(Unk803D50E4Rec6* e)
{
    if (e->m6 & 3)
        return 1;
    return 0;
}

extern "C" void fn_803D7804()
{
    fn_803D7414(1, 0xFFFF);
}

/*
 * Not attempted: the large functions fn_803D5130 (126), fn_803D5328 (219), fn_803D5694 (424), fn_803D5D34 (84),
 * fn_803D5E84 (58), fn_803D6144 (249), fn_803D6528 (141), fn_803D675C (84), fn_803D68AC (246), fn_803D6C84 (226),
 * fn_803D707C (93), fn_803D71F0 (98), fn_803D74EC (53), fn_803D7600 (61); fn_803D5F7C and fn_803D5FE8 convert
 * integer fields with an unused sixth parameter copy; fn_803D75C0 is a pointer/value pair copy loop.
 * The original code stays linked for these.
 */
