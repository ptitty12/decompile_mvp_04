/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803D8234-0x803D9C34 (code-only unit, 38 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

extern "C" {
void fn_80377408(void* p); /* __builtin_delete */
void GXInvalidateVtxCache(void);
void GXInvalidateTexAll(void);
void VISetPreRetraceCallback(int cb);
void fn_803DB4CC(void);
void fn_8043000C(int a);
void fn_8042C464(void);
void fn_80432FA8(void);
void fn_8042A8A0(int a);
void fn_8042A9A8(void);
void fn_8042A588(int a);
void fn_8042A614(void);
void fn_8042C020(void);
int fn_8042A890(void);
void fn_8042A4AC(int h, int* a, int* b);
int OSDisableInterrupts(void);
void OSRestoreInterrupts(int level);
}

struct lbl_Node;

/* Object at +8 of the owner: current node at +8, list head at +0xC. */
struct lbl_Impl {
    char pad0[0x8];
    lbl_Node* mCur;
    lbl_Node* mHead;
};

class lbl_Owner {
public:
    char pad0[0x8];
    lbl_Impl* m8;
    const void* mC;
    void fn_803DA098(lbl_Node* node);
};

union PPCWGPipe {
    unsigned char u8;
    unsigned short u16;
    unsigned int u32;
    float f32;
    double f64;
};
extern volatile PPCWGPipe GXWGFifo;

/* Render device object (size at least 0xF0): sub-objects at +0x10 and +0x38, owner at +0xEC. */
struct Unk803D8234Dev {
    int m0;
    int m4;
    int m8;
    const void* mC;
    char pad10[0x54 - 0x10];
    float m54;
    float m58;
    int m5C;
    char pad60[0xDC - 0x60];
    int mDC;
    char padE0[4];
    int mE4;
    int mE8;
    int mEC;
};

/* Ring-buffer record (12 bytes). */
struct Unk803D8234Rec {
    int m0;
    int m4;
    void (*m8)(int);
};

extern const void* lbl_80686770[];
extern int lbl_806272E8;
extern int lbl_80627A84;
extern int lbl_80627A80;
extern int lbl_806279B8;
extern int lbl_80627310[];
extern int lbl_8062731C;
extern int lbl_80627320;
extern int lbl_80627350;
extern volatile int lbl_80627348;
extern volatile int lbl_8062734C;
extern Unk803D8234Rec lbl_806273B4[];

extern "C" void fn_803D999C(void);

extern int lbl_80627380[];
extern int lbl_80627374[];
extern int lbl_80627324;
extern int lbl_806272D0;
extern int lbl_80627304;
extern short lbl_806272E0;
extern short lbl_806E9938[];
extern short lbl_806EB938[];
extern unsigned char lbl_806ED938[];
extern const void* lbl_80686740[];
extern const void* lbl_806867E8[];
extern const void* lbl_806867B8[];
extern const void* lbl_806867D0[];
extern const void* lbl_806867A0[];
extern int lbl_806272EC;
extern int lbl_8062C2B4;
extern int fn_803D81FC();
extern void fn_803D81A0(int unused, int v);

extern "C" {
void* fn_803D9BE0(struct Unk803D8234Light* sub, void* owner);
void fn_803DD73C(void* o, int c);
void* fn_803DD7C0(void* o);
void fn_803EDA0C(void* o);
void* fn_803D9A24(struct Unk803D8234Sub* sub, void* owner);
void fn_804310E0(int* a, int* b, int* c, int* d, int* e, int* f);
void fn_803D9664(void);
int fn_803D96FC(Unk803D8234Rec* a, Unk803D8234Rec* b);
void fn_803D9774(Unk803D8234Rec* r, int a, int b);
void fn_803D96CC(Unk803D8234Rec* r);
}

extern "C" void fn_803D9110(int a, int b)
{
    if (b == 0xFFFF && a != 0) {
        lbl_80627374[0] = 4;
        lbl_80627374[1] = 4;
        lbl_80627374[2] = 1;
        lbl_80627380[0] = 3;
        lbl_80627380[1] = 3;
        lbl_80627380[2] = 1;
    }
}

/* Light-like sub-object (vptr at +0x1C). */
struct Unk803D8234Light {
    int m0;
    float m4;
    float m8;
    int mC;
    int m10;
    int m14;
    void* m18;
    const void* m1C;
    void* m20;
    int m24;
};


struct Unk803D8234Sub {
    int m0;
    int m4;
    int m8;
    int mC;
    const void* m10;
    int m14;
    void* m18;
    float m1C;
    float m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    char pad40[0x80 - 0x40];
    int m80;
    int pad84;
    int m88;
    int m8C;
    int m90;
    int m94;
    float m98;
    int m9C;
    int mA0;
    int mA4;
    int mA8;
    int mAC;
    int mB0;
};


extern "C" Unk803D8234Dev* fn_803D9160(Unk803D8234Dev* self, int a, int b, int c)
{
    self->m0 = b;
    self->mC = lbl_80686770;
    self->m4 = a;
    self->m8 = c;
    return self;
}

extern "C" void fn_803D9180(lbl_Owner* self, int c)
{
    self->mC = lbl_80686770;
    while (self->m8->mHead != 0)
        self->fn_803DA098(self->m8->mHead);
    if (c & 1)
        fn_80377408(self);
}

extern "C" void* fn_803D91F8(Unk803D8234Dev* self, int owner)
{
    char* sub10 = (char*)self + 0x10;
    char* sub38 = (char*)self + 0x38;
    self->m8 = (int)sub38;
    self->m4 = 0;
    self->mC = lbl_80686740;
    self->m0 = (int)sub10;
    fn_803D9BE0((Unk803D8234Light*)sub10, self);
    fn_803D9A24((Unk803D8234Sub*)sub38, self);
    self->mEC = owner;
    return self;
}

extern "C" void fn_803D9268(Unk803D8234Sub* self)
{
    lbl_80627A80 = self->mA8;
    lbl_80627A84 = self->mAC;
    fn_803DB4CC();
    if (lbl_80627324) {
        int v = 0;
        if (self->mB0)
            v = 1;
        fn_8043000C(v);
    }
}

extern "C" void fn_803D92D4(Unk803D8234Dev* dev)
{
    Unk803D8234Sub* s = (Unk803D8234Sub*)((char*)dev + 0x38);
    lbl_806272D0 = lbl_806272D0 + 1;
    GXInvalidateVtxCache();
    GXInvalidateTexAll();
    fn_803D81A0(fn_803D81FC() + 4, (int)dev);
    lbl_80627A80 = s->mA8;
    lbl_80627A84 = s->mAC;
    fn_803DB4CC();
    if (lbl_80627324) {
        int v = 0;
        if (s->mB0)
            v = 1;
        fn_8043000C(v);
    }
    lbl_8062C2B4 = 0;
}

/* near-miss (same length): the register assignment matches retail (x in r30, idx = x & 0xFFF before the
   call), but the lhz loads and the three table stores come out in another order; 24 orderings of the three
   stores and of the sum operands were tried. */
extern "C" void fn_803D9454(int x)
{
    if (x == 0x8000) {
        lbl_80627304 = 0;
    } else {
        lbl_806272E0 = x;
        if ((x & 0xF000) == 0x4000) {
            int a;
            int b;
            int c;
            int d;
            int e;
            int f;
            int idx = x & 0xFFF;
            fn_804310E0(&a, &b, &c, &d, &e, &f);
            lbl_806E9938[idx] = (unsigned short)d + (unsigned short)b;
            lbl_806EB938[idx] = (unsigned short)c + (unsigned short)a;
            lbl_806ED938[idx] = 1;
            fn_803D9664();
        }
    }
}

extern "C" void fn_803D95C4()
{
    fn_803D96CC(&lbl_806273B4[lbl_8062734C]);
}

extern "C" void fn_803D95FC(int a, int b)
{
    fn_803D9774(&lbl_806273B4[lbl_80627348], a, b);
    lbl_80627348 = lbl_80627348 + 1;
    if (lbl_80627348 > 0x7F)
        lbl_80627348 = 0;
}

extern "C" void fn_803D9664()
{
    int n = lbl_8062734C + 1;
    if (n > 0x7F)
        n = 0;
    if (fn_803D96FC(&lbl_806273B4[lbl_8062734C], &lbl_806273B4[n]))
        lbl_8062734C = n;
}

extern "C" void fn_803D96CC(Unk803D8234Rec* r)
{
    r->m8(r->m4);
}

extern "C" int fn_803D96FC(Unk803D8234Rec* a, Unk803D8234Rec* b)
{
    if (a->m0 == 0)
        return 0;
    int v = b->m0;
    if (v != 0) {
        fn_8042A588(v);
        lbl_80627350 = 1;
    } else {
        fn_8042A614();
        lbl_80627350 = v;
    }
    a->m0 = 0;
    return 1;
}

extern "C" void fn_803D9774(Unk803D8234Rec* r, int a, int b)
{
    int x;
    int y;
    fn_8042C020();
    fn_8042A4AC(fn_8042A890(), &x, &y);
    while (r->m0 != 0)
        ;
    r->m4 = a;
    r->m8 = (void (*)(int))b;
    int ints = OSDisableInterrupts();
    r->m0 = y;
    if (lbl_80627350 == 0) {
        lbl_80627350 = 1;
        fn_8042A588(y);
    }
    OSRestoreInterrupts(ints);
}

extern "C" void fn_803D9804(Unk803D8234Dev* self, float a, float b)
{
    self->m54 = a;
    self->m58 = b;
}

extern "C" void fn_803D9810(Unk803D8234Dev* self, float* a, float* b)
{
    *a = self->m54;
    *b = self->m58;
}

extern "C" int fn_803D9824(Unk803D8234Dev* self)
{
    return self->m5C;
}

extern "C" void fn_803D982C(Unk803D8234Dev* self, int v)
{
    self->mDC = v;
    lbl_806272E8 = v;
}

extern "C" int fn_803D983C(Unk803D8234Dev* self, int v)
{
    self->mE4 = v;
    lbl_80627A84 = v;
    fn_803DB4CC();
    return 1;
}

extern "C" int fn_803D986C(Unk803D8234Dev* self, int* out)
{
    *out = self->mE4;
    return 1;
}

extern "C" void fn_803D987C()
{
    fn_8042C464();
    lbl_806279B8 += 5;
}

extern "C" int fn_803D98AC()
{
    return lbl_80627310[lbl_8062731C];
}

extern "C" void fn_803D98C8(int x)
{
    fn_80432FA8();
    if (lbl_80627320)
        fn_803D999C();
    lbl_80627320 = 1;
    fn_8042A8A0(x);
}

extern "C" void fn_803D9918(const double* p, unsigned n)
{
    while (n > 31) {
        double a = p[0];
        double b = p[1];
        double c = p[2];
        double d = p[3];
        GXWGFifo.f64 = a;
        GXWGFifo.f64 = b;
        GXWGFifo.f64 = c;
        GXWGFifo.f64 = d;
        p += 4;
        n -= 32;
    }
    while (n > 7) {
        double a = p[0];
        p++;
        n -= 8;
        GXWGFifo.f64 = a;
    }
    if (n != 0) {
        const unsigned char* q = (const unsigned char*)p;
        do {
            unsigned char c = *q;
            n--;
            q++;
            GXWGFifo.u8 = c;
        } while (n != 0);
    }
}

extern "C" void fn_803D999C()
{
    fn_8042A9A8();
    lbl_80627320 = 0;
}

extern "C" Unk803D8234Dev* fn_803D99C8(char* self, int a)
{
    *(const void**)(self + 0x10) = lbl_806867D0;
    *(int*)(self + 4) = a;
    *(int*)(self + 0) = 0;
    *(int*)(self + 8) = 0;
    *(int*)(self + 0xC) = 0;
    return (Unk803D8234Dev*)self;
}

extern "C" void fn_803D99F0(char* self, int c)
{
    *(const void**)(self + 0x10) = lbl_806867D0;
    if (c & 1)
        fn_80377408(self);
}

extern "C" void* fn_803D9A24(Unk803D8234Sub* self, void* owner)
{
    self->m0 = 0;
    self->m4 = (int)owner;
    self->m8 = 0;
    self->mC = 0;
    self->m10 = lbl_806867A0;
    self->m14 = 0;
    self->m18 = owner;
    self->m1C = 640.0f;
    self->m20 = 448.0f;
    self->m24 = 0x18;
    self->m28 = 0x18;
    self->m2C = -1;
    self->m30 = -1;
    self->m34 = -1;
    self->m38 = -1;
    self->m3C = 0;
    self->m80 = 0;
    self->m88 = 0;
    self->m8C = 0x40000;
    self->m90 = 0;
    self->m94 = 0;
    self->m98 = 0.0f;
    self->m9C = 0;
    self->mA0 = 1;
    self->mA4 = 1;
    self->mA8 = 0;
    self->mAC = 1;
    self->mB0 = 1;
    return self;
}

extern "C" void fn_803D9AD0(Unk803D8234Sub* self, int c)
{
    self->m10 = lbl_806867A0;
    if (lbl_806272EC) {
        lbl_806272EC = lbl_806272EC - 1;
        VISetPreRetraceCallback(0);
    }
    if (self->m94) {
        fn_803EDA0C(fn_803DD7C0((void*)self->m94));
        if (self->m94)
            fn_803DD73C((void*)self->m94, 3);
    }
    self->m10 = lbl_806867D0;
    if (c & 1)
        fn_80377408(self);
}

inline void LightInit(Unk803D8234Light* self, void* owner)
{
    self->m1C = lbl_806867E8;
    self->m0 = 0;
    self->m4 = 0.0f;
    self->m8 = 0.0f;
    self->mC = 0;
    self->m10 = 0;
    self->m14 = 1;
    self->m18 = owner;
}

extern "C" Unk803D8234Light* fn_803D9B6C(Unk803D8234Light* self, void* owner)
{
    self->m0 = 0;
    self->m1C = lbl_806867E8;
    self->m4 = 0.0f;
    self->m8 = 0.0f;
    self->mC = 0;
    self->m10 = 0;
    self->m14 = 1;
    self->m18 = owner;
    return self;
}

extern "C" void fn_803D9BAC(Unk803D8234Light* self, int c)
{
    self->m1C = lbl_806867E8;
    if (c & 1)
        fn_80377408(self);
}

extern "C" void* fn_803D9BE0(Unk803D8234Light* self, void* owner)
{
    LightInit(self, owner);
    self->m1C = lbl_806867B8;
    self->m20 = owner;
    self->m24 = 0;
    return self;
}

/*
 * Not attempted: fn_803D8234 (98 instructions), fn_803D83BC (161), fn_803D8640 (122), fn_803D8918 (510);
 * fn_803D8828 and fn_803D9378 read the time base (mftb); fn_803D9528 ends in a trap word after the
 * fatal-error call. The original code stays linked for these.
 * fn_803D9918 differs from retail only in the GXWGFifo reloc versus lis 0xcc01 (objdiff scores 100%).
 */
