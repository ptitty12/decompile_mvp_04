/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803D9C34-0x803D9FE8 (code-only unit, 23 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

extern "C" void fn_80377408(void* p); /* __builtin_delete */
extern "C" void fn_803D9110(int a, int b);
extern "C" void fn_803E1A38(void* p);
extern "C" void fn_8042C4E4();
extern "C" {
void GXSetTexCopySrc(unsigned short left, unsigned short top, unsigned short wd, unsigned short ht);
void GXSetTexCopyDst(unsigned short wd, unsigned short ht, int fmt, unsigned char mipmap);
void GXSetCopyFilter(unsigned char aa, const unsigned char* sample_pattern, unsigned char vf, const unsigned char* vfilter);
void GXCopyTex(void* dest, unsigned char clear);
}

/* Texture-like object: m4 is the pixel-data holder. */
struct Unk803D9ECCTex {
    char pad0[0xC];
    unsigned int mC;
    int m10;
};
struct Unk803D9ECCHolder {
    char pad0[4];
    Unk803D9ECCTex* m4;
};
extern "C" Unk803D9ECCTex* fn_803DD7C0(Unk803D9ECCHolder* h);

/* Render-mode-like record at m20->m4C: aa flag at +0x19, sample pattern at +0x1A, vertical filter at +0x32. */
struct Unk803D9ECCMode {
    char pad0[0x19];
    unsigned char m19;
    unsigned char m1A[0x18];
    unsigned char m32[7];
};
struct Unk803D9ECCDev {
    char pad0[0x4C];
    Unk803D9ECCMode* m4C;
    char pad50[0xB8 - 0x50];
    int mB8;
    char padBC[0xC4 - 0xBC];
    int mC4;
};
struct Unk803D9E00 {
    char pad0[0x20];
    Unk803D9ECCDev* m20;
};

struct lbl_Node;
class lbl_Owner {
public:
    char pad0[0x8];
    void* m8;
    lbl_Node* fn_803DA148();
};

/* Light-like parameter object: vptr at +0x1C, setters call fn_803D9D48 to refresh the owner's node. */
struct Unk803D9C34 {
    int m0;
    float m4;
    float m8;
    int mC;
    int m10;
    int m14;
    lbl_Owner* m18;
    const void* m1C;
};

extern "C" void fn_803D9D48(Unk803D9C34* self);

struct Unk803D9C34Rec {
    int m10;
};

extern const void* lbl_806867E8[];
extern float lbl_8062732C;
extern int lbl_80627330;
extern int lbl_80627334;
extern int lbl_80627340;
extern int lbl_80627344;
extern int lbl_806272F8;
extern short lbl_806272FC;
extern int lbl_8062730C;
extern unsigned char lbl_80627308;
extern int lbl_80627300;

extern "C" void fn_803D9C34(Unk803D9C34* self, int c)
{
    self->m1C = lbl_806867E8;
    if (c & 1)
        fn_80377408(self);
}

extern "C" void fn_803D9C68(Unk803D9C34* self, int v)
{
    self->m0 = v;
    fn_803D9D48(self);
}

extern "C" void fn_803D9C8C(Unk803D9C34* self, int v)
{
    self->mC = v;
    fn_803D9D48(self);
}

extern "C" void fn_803D9CB0(Unk803D9C34* self, float v)
{
    self->m4 = v;
    fn_803D9D48(self);
}

extern "C" void fn_803D9CD4(Unk803D9C34* self, float v)
{
    self->m8 = v;
    fn_803D9D48(self);
}

extern "C" void fn_803D9CF8(Unk803D9C34* self, Unk803D9C34Rec* v)
{
    self->m10 = v->m10;
    fn_803D9D48(self);
}

extern "C" void fn_803D9D24(Unk803D9C34* self, int v)
{
    self->m14 = v;
    fn_803D9D48(self);
}

extern "C" void fn_803D9D48(Unk803D9C34* self)
{
    lbl_Node* n = self->m18->fn_803DA148();
    if (n)
        fn_803E1A38((char*)n + 0xC);
}

extern "C" int fn_803D9D7C(float* out)
{
    *out = lbl_8062732C;
    return 1;
}

extern "C" int fn_803D9D90(int* out)
{
    *out = lbl_80627330;
    return 1;
}

extern "C" int fn_803D9DA4(int* out)
{
    *out = lbl_80627334;
    return 1;
}

extern "C" int fn_803D9DB8(int* out)
{
    *out = lbl_80627340;
    return 1;
}

extern "C" void fn_803D9DCC(int* out)
{
    *out = lbl_80627344;
}

extern "C" void fn_803D9DDC(int unused, int a, short b)
{
    lbl_806272F8 = a;
    lbl_806272FC = b;
}

extern "C" void fn_803D9DF0()
{
}

extern "C" int fn_803D9DF4()
{
    return lbl_8062730C;
}

extern "C" void fn_803D9E00(Unk803D9E00* self, int* a, int* b)
{
    *a = self->m20->mB8;
    *b = (int)self->m20->m4C;
}

extern "C" void fn_803D9E1C(int x)
{
    unsigned char* q = &lbl_80627308;
    if (x)
        *q = 1;
    else
        *q = 0;
}

extern "C" int fn_803D9E3C()
{
    return lbl_80627308 == 1;
}

extern "C" void fn_803D9E54(Unk803D9E00* self, int v)
{
    if (lbl_80627300 == 0)
        self->m20->mC4 = v;
}

extern "C" void fn_803D9E70(int unused, int l, int t, int w, int h, int dw, int dh, int fmt, unsigned char mip)
{
    GXSetTexCopySrc(l, t, w, h);
    GXSetTexCopyDst(dw, dh, fmt, mip);
}

extern "C" void fn_803D9ECC(Unk803D9E00* self, Unk803D9ECCHolder* holder, int clear, int flag, int filt)
{
    Unk803D9ECCMode* m = self->m20->m4C;
    if (filt) {
        unsigned char vf[7] = { 9, 9, 9, 10, 9, 9, 9 };
        GXSetCopyFilter(m->m19, m->m1A, 1, vf);
    } else {
        GXSetCopyFilter(m->m19, m->m1A, 0, m->m32);
    }
    Unk803D9ECCTex* t = fn_803DD7C0(holder);
    void* dest;
    if (t->mC & 0x10000000)
        dest = (char*)t + t->m10;
    else
        dest = (char*)t + 0x10;
    GXCopyTex(dest, clear);
    GXSetCopyFilter(m->m19, m->m1A, 1, m->m32);
    if (flag)
        fn_8042C4E4();
}

extern "C" void fn_803D9FBC()
{
    fn_803D9110(1, 0xFFFF);
}
