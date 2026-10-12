/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803DA188-0x803DA4EC (code-only unit, 6 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

extern "C" void GXSetArray(int attr, void* base_ptr, unsigned char stride);
extern "C" void fn_803DBF5C(unsigned int* a, unsigned int* b);

/* Per-attribute vertex array bases and strides, indexed by the GX attribute number. */
extern unsigned char* lbl_806279F0[];
extern unsigned char lbl_80627A58[];
class Unk803DA440;
extern Unk803DA440* lbl_806272AC;

/* Intrusive list node: creator and three tables, link at +0x10, list head lbl_806272AC. */
class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), void* a, void* b, void* c);
    void (*m0)();
    void* m4;
    void* m8;
    void* mC;
    Unk803DA440* m10;
};

#define BUMP(attr, n)                                                   \
    {                                                                   \
        unsigned char* p = lbl_806279F0[attr] + lbl_80627A58[attr] * n; \
        lbl_806279F0[attr] = p;                                         \
        GXSetArray(attr, p, lbl_80627A58[attr]);                        \
    }

extern "C" void fn_803DA188(int n)
{
    unsigned int flags;
    unsigned int flags2;
    fn_803DBF5C(&flags, &flags2);
    if (flags & 0x200)
        BUMP(9, n);
    if (flags & 0x400)
        BUMP(10, n);
    if (flags & 0x1000)
        BUMP(11, n);
    if (flags & 0x4000)
        BUMP(13, n);
    if (flags & 0x3FA000) {
        if (flags & 0x2000)
            BUMP(12, n);
        if (flags & 0x8000)
            BUMP(14, n);
        if (flags & 0x10000)
            BUMP(15, n);
        if (flags & 0x20000)
            BUMP(16, n);
        if (flags & 0x40000)
            BUMP(17, n);
        if (flags & 0x80000)
            BUMP(18, n);
        if (flags & 0x100000)
            BUMP(19, n);
        if (flags & 0x200000)
            BUMP(20, n);
    }
}

extern "C" void fn_803DA43C(int a, int b)
{
}

/* near-miss: same 10 instructions, but registers differ (ours: lbl address r9, this r11,
   loaded head r0; retail: this r9, loaded head r10, lbl address r11). Tried statement
   permutations (360), init list, local head pointer, int vs pointer field types. */
Unk803DA440::Unk803DA440(void (*fn)(), void* a, void* b, void* c)
{
    m0 = fn;
    m4 = a;
    m8 = b;
    mC = c;
    m10 = lbl_806272AC;
    lbl_806272AC = this;
}

extern "C" void fn_803DA468(int attr, unsigned char* base, unsigned char stride)
{
    GXSetArray(attr, base, stride);
    lbl_80627A58[attr] = stride;
    lbl_806279F0[attr] = base;
}

extern "C" int fn_803DA4B8()
{
    return 1;
}

extern "C" void fn_803DA4C0()
{
    fn_803DA43C(1, 0xFFFF);
}
