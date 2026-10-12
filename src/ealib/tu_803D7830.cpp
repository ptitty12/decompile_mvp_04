/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803D7830-0x803D7ED4 (code-only unit, 15 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

extern "C" {
void fn_80377408(void* p); /* __builtin_delete */
int strcmp(const char* a, const char* b);
}

struct Unk803D7830;
struct Unk803D7830Entry {
    short m0;
    short m2;
    int m4;
    int m8;
    int mC;
};
/* Source record (16 bytes): m0 value, m4 short, m6 flags (bits 0-1 tested by fn_803D77EC), mC value. */
struct Unk803D7830SrcEnt {
    int m0;
    short m4;
    short m6;
    int m8;
    int mC;
};
struct Unk803D7830Src {
    Unk803D7830SrcEnt* m0;
    int m4;
};

/* Table object: m0 source holder, m4/m8 scalars, m10 entry count, m14 entries (16 bytes each), m18 flag, m1C limit. */
struct Unk803D7830 {
    Unk803D7830Src* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    Unk803D7830Entry* m14;
    int m18;
    int m1C;
};

extern void* (*lbl_8062C668)(int size, const char* tag);
extern const char lbl_8060AE28[];
extern const char lbl_8060AE48[];
extern const char lbl_8060AE58[];
extern int lbl_806279B8;
extern int lbl_806272B0[];
extern int lbl_80627298;
extern void (*lbl_8062C66C)(void* p, int size);

extern "C" {
void fn_803D987C(Unk803D7830* self);
void fn_803D6C84(Unk803D7830Src* src, Unk803D7830* self, int a, int b);
void fn_803D7E78(Unk803D7830* p, Unk803D7830* v);
int* fn_803D7E3C(int* p);
int fn_803D77EC(Unk803D7830SrcEnt* e);
}

extern "C" void fn_803D7830(char* self)
{
    if ((unsigned)(lbl_806279B8 - *(int*)(self + 0xDC)) <= 1)
        fn_803D987C((Unk803D7830*)self);
}

/* near-miss (same length): retail loads src->m4 once for m10 and the allocation size, shares one zero register
   between the two zero stores, and keeps the loop end in a stack slot (stw r0,8(r1)) that is stored but
   never read. Tried an end-iterator struct with and without a dtor; the dtor form adds a cleanup flag. */
extern "C" int fn_803D7868(Unk803D7830* self, Unk803D7830Src* src, int extra)
{
    self->m4 = extra;
    self->m8 = 0;
    self->m0 = src;
    self->m10 = src->m4;
    self->m14 = (Unk803D7830Entry*)lbl_8062C668(src->m4 * 16, lbl_8060AE28);
    int i = 0;
    for (Unk803D7830SrcEnt* p = src->m0; p != src->m0 + src->m4; p++, i++) {
        int v = p->m0;
        short w = p->m4;
        int t = 0;
        if (fn_803D77EC(p))
            t = p->mC;
        self->m14[i].m0 = 0;
        self->m14[i].m2 = w;
        self->m14[i].mC = v;
        self->m14[i].m4 = 0;
        self->m14[i].m8 = t;
    }
    return 1;
}

extern "C" Unk803D7830* fn_803D7970(Unk803D7830* self)
{
    self->m1C = 10000;
    self->m0 = 0;
    self->m4 = 0;
    self->m8 = 0;
    self->mC = 0;
    self->m10 = 0;
    self->m14 = 0;
    self->m18 = 0;
    return self;
}

extern "C" void fn_803D79A0(Unk803D7830* self, int c)
{
    if (self->m14)
        lbl_8062C66C(self->m14, self->m10 * 16);
    self->m14 = 0;
    self->m10 = 0;
    if (c & 1)
        lbl_8062C66C(self, 0x20);
}

/* near-miss: retail tests each name with strcmp(..)==0 materialised as 0/1 (subfic/adde) and compared
   with 1, and the scan loop keeps the previous element offset in a register; tried inline bool/int
   helpers and local flags, none gives subfic/adde here. */
extern "C" void fn_803D7A1C(Unk803D7830* self, const char* name, int a, int b)
{
    if (strcmp(name, lbl_8060AE48) == 0)
        self->m8 = a;
    else if (strcmp(name, lbl_8060AE58) == 0)
        self->mC = a;
    else {
        int i = 0;
        int off = 0;
        for (; i < self->m10; i++, off += 16) {
            if (strcmp(name, *(const char**)((char*)self->m14 + off + 0xC)) == 0) {
                *(int*)((char*)self->m14 + off + 4) = a;
                *(short*)((char*)self->m14 + off) = b;
                break;
            }
        }
    }
}

inline void Clear(Unk803D7830* s)
{
    s->m18 = 0;
}

extern "C" int fn_803D7AFC(Unk803D7830* self, int a, int b)
{
    Clear(self);
    fn_803D6C84(self->m0, self, a, b);
    return 1;
}

extern "C" void fn_803D7CA4(int a, int b)
{
    if (b == 0xFFFF && a != 0) {
        lbl_806272B0[0] = 3;
        lbl_806272B0[1] = 3;
        lbl_806272B0[2] = 1;
    }
}

extern "C" Unk803D7830* fn_803D7CDC(Unk803D7830* self)
{
    fn_803D7E78(self, self);
    fn_803D7E3C(&self->m4);
    lbl_80627298 = (int)self;
    return self;
}

extern "C" int* fn_803D7E3C(int* p)
{
    p[2] = 0;
    p[3] = 0;
    return p;
}

extern "C" void fn_803D7E50(void* p, int c)
{
    if (c & 1)
        fn_80377408(p);
}

extern "C" void fn_803D7E78(Unk803D7830* p, Unk803D7830* v)
{
    p->m0 = (Unk803D7830Src*)v;
}

extern "C" void fn_803D7E80(void* p, int c)
{
    if (c & 1)
        fn_80377408(p);
}

extern "C" void fn_803D7EA8()
{
    fn_803D7CA4(1, 0xFFFF);
}

/*
 * Not attempted: fn_803D7B40 (89 instructions, 20 data references: teardown of the registered classes/lists);
 * fn_803D7D20 needs mtspr GQR2..GQR5 (instructions only inline assembly can emit); the original code stays linked.
 */
