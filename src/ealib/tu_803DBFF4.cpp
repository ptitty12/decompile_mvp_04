/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803DBFF4-0x803DDCD4 (code-only unit, 30 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

extern "C" {
void fn_80377408(void* p); /* __builtin_delete */
void GXInitTexObjWrapMode(void* obj, int s, int t);
void GXInitTlutObj(void* tlut, void* lut, int fmt, int n_entries);
void GXLoadTlut(void* tlut, int name);
void GXInitTexObjTlut(void* obj, int tlut_name);
void GXLoadTexObj(void* obj, int id);
void GXSetNumTexGens(unsigned char n);
void GXSetTexCoordGen2(int dst, int type, int src, int mtx, unsigned char normalize, int postmtx);
}

/* Image info record: kind byte at +0 (0x31..0x33), width at +4, height at +6, flags at +0xC, data offset at +0x10. */
struct Unk803DBFF4Info {
    unsigned char m0;
    char pad1[3];
    short m4;
    short m6;
    int m8;
    unsigned int mC;
    int m10;
};

/* Texture state (the part at +4 of the wrapper). Offsets seen in fn_803DD838..fn_803DDC40. */
struct Unk803DBFF4Tex {
    Unk803DBFF4Info* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    float m14;
    int m18;
    int m1C;
    char m20[0x20];
    char m40[0xC];
    unsigned char m4C;
    int m50;
};

/* Wrapper object (size 0x58): state at +4, wrap modes mirrored at +0x1C/+0x20, GXTexObj at +0x24. */
struct Unk803DBFF4Obj {
    int m0;
    Unk803DBFF4Info* m4;
    int m8;
    int mC;
    int m10;
    int m14;
    float m18;
    int m1C;
    int m20;
    char m24[0x30];
    int m54;
};

/* Texture-coordinate generator tables (8 entries each). */
struct Unk803DBFF4Tc {
    int a[8];
    int b[8];
    int c[8];
    unsigned char d[8];
    int e[8];
};

extern Unk803DBFF4Tc lbl_8062BB70;
extern int lbl_8062BBF8[];
extern int lbl_80627B00;
extern void (*lbl_8062C66C)(void* p, int size);
extern float lbl_8060C6D8;

extern "C" {
Unk803DBFF4Tex* fn_803DDC40(Unk803DBFF4Tex* t);
void fn_803DDC80(void* p, int c);
void fn_803DD8E0(Unk803DBFF4Tex* self, int a, int b);
int fn_803DD068(Unk803DBFF4Tex* t, Unk803DBFF4Info* info);
void fn_803DD2A0(Unk803DBFF4Tex* t);
void fn_803DD73C(Unk803DBFF4Obj* o, int c);
Unk803DBFF4Info* fn_803EBF90(Unk803DBFF4Info* i);
int fn_803DDAC0(Unk803DBFF4Tex* t, Unk803DBFF4Info* info);
}

inline void TcReset()
{
    for (int i = 0; i < 8; i++) {
        lbl_8062BB70.a[i] = 1;
        lbl_8062BB70.b[i] = i + 4;
        lbl_8062BB70.c[i] = 0x3C;
        lbl_8062BB70.d[i] = 0;
        lbl_8062BB70.e[i] = 0x7D;
    }
}

extern "C" void fn_803DD4E4(int a, int b)
{
    if (b == 0xFFFF && a != 0) {
        TcReset();
        lbl_8062BBF8[0] = 4;
        lbl_8062BBF8[1] = 4;
        lbl_8062BBF8[2] = 1;
    }
}

extern "C" void fn_803DD568(Unk803DBFF4Obj* arr, int n)
{
    for (int i = 0; i < n; i++)
        fn_803DD73C((Unk803DBFF4Obj*)((char*)arr + i * 0x60), 2);
    lbl_8062C66C(arr, n * 0x60);
}

extern "C" void fn_803DD5D0(Unk803DBFF4Obj* o)
{
    fn_803DD73C(o, 2);
}

extern "C" Unk803DBFF4Obj* fn_803DD5F4(Unk803DBFF4Obj* self)
{
    fn_803DDC40((Unk803DBFF4Tex*)((char*)self + 4));
    return self;
}

/* near-miss (3 slots): retail stores m20 and m1C before `mr r4,r30`; ours leaves the second store after it.
   Tried store order, chained assignment, an inline setter, a local for the inner pointer. */
extern "C" Unk803DBFF4Obj* fn_803DD628(Unk803DBFF4Obj* self, Unk803DBFF4Info* info)
{
    fn_803DDC40((Unk803DBFF4Tex*)((char*)self + 4));
    int v;
    if ((info->m4 & (info->m4 - 1)) != 0 || (info->m6 & (info->m6 - 1)) != 0)
        v = 0;
    else
        v = 1;
    self->m1C = v;
    self->m20 = v;
    fn_803DD068((Unk803DBFF4Tex*)((char*)self + 4), info);
    return self;
}

extern "C" Unk803DBFF4Obj* fn_803DD6A0(Unk803DBFF4Obj* self, Unk803DBFF4Obj* other)
{
    Unk803DBFF4Tex* dst = (Unk803DBFF4Tex*)((char*)self + 4);
    fn_803DDC40(dst);
    *dst = *(Unk803DBFF4Tex*)((char*)other + 4);
    return self;
}

extern "C" void fn_803DD73C(Unk803DBFF4Obj* self, int c)
{
    fn_803DDC80((Unk803DBFF4Tex*)((char*)self + 4), 2);
    if (c & 1)
        lbl_8062C66C(self, 0x58);
}

extern "C" void fn_803DD794(Unk803DBFF4Obj* self)
{
    fn_803DD8E0((Unk803DBFF4Tex*)((char*)self + 4), 0, 0);
}

extern "C" Unk803DBFF4Info* fn_803DD7C0(Unk803DBFF4Obj* self)
{
    return self->m4;
}

extern "C" int fn_803DD7C8(Unk803DBFF4Obj* self, int v)
{
    Unk803DBFF4Info* t = self->m4;
    if ((t->m4 & (t->m4 - 1)) != 0 || (t->m6 & (t->m6 - 1)) != 0) {
        if (v != 0)
            v = 0;
    }
    self->m20 = v;
    self->m1C = v;
    GXInitTexObjWrapMode(self->m24, v, v);
    return 1;
}

extern "C" void fn_803DD838(Unk803DBFF4Tex* self, int v)
{
    Unk803DBFF4Info* t = self->m0;
    if ((t->m4 & (t->m4 - 1)) != 0 && v != 0)
        v = 0;
    self->m18 = v;
    GXInitTexObjWrapMode(self->m20, v, self->m1C);
}

extern "C" void fn_803DD88C(Unk803DBFF4Tex* self, int v)
{
    Unk803DBFF4Info* t = self->m0;
    if ((t->m6 & (t->m6 - 1)) != 0 && v != 0)
        v = 0;
    self->m1C = v;
    GXInitTexObjWrapMode(self->m20, self->m18, v);
}

extern "C" void fn_803DD8E0(Unk803DBFF4Tex* self, int a, int b)
{
    fn_803DD2A0(self);
    if (self->m50 != 0) {
        GXLoadTlut(self->m40, b);
        GXInitTexObjTlut(self->m20, b);
    }
    GXLoadTexObj(self->m20, a);
    Unk803DBFF4Info* i = fn_803EBF90((Unk803DBFF4Info*)self->m0);
    if (i != 0 && i->m0 == 0x33) {
        char* data;
        if (i->mC & 0x10000000)
            data = (char*)i + i->m10;
        else
            data = (char*)i + 0x10;
        int n = (unsigned short)i->m4;
        char tlut[0xC];
        b++;
        GXInitTlutObj(tlut, (void*)(((int)data + (n << 1) + 0x1F) & ~0x1F), 0, n);
        GXLoadTlut(tlut, b);
        GXInitTexObjTlut(self->m20, b);
        GXLoadTexObj(self->m20, a + 1);
    }
}

extern "C" void fn_803DD9CC(Unk803DBFF4Tex* self, unsigned char v)
{
    self->m4C = v;
}

extern "C" int fn_803DD9D4(Unk803DBFF4Obj* self, int v)
{
    if (v != -1 && self->m54 == 0) {
        self->m10 = v;
        return 1;
    }
    return 0;
}

extern "C" int fn_803DD9FC(Unk803DBFF4Obj* self, float f)
{
    int ok = 1;
    if (f > 3.99f) {
        f = 3.99f;
        ok = 0;
    } else if (f < -4.0f) {
        f = -4.0f;
        ok = 0;
    }
    self->m18 = f;
    return ok;
}

extern "C" int fn_803DDA34(Unk803DBFF4Obj* self, int v)
{
    if (self->m54 != 0 && v == 2) {
        self->m14 = 1;
        return 0;
    }
    self->m14 = v;
    return 1;
}

extern "C" void fn_803DDA68(Unk803DBFF4Obj* self, Unk803DBFF4Info* info)
{
    fn_803DDAC0((Unk803DBFF4Tex*)((char*)self + 4), info);
}

extern "C" int fn_803DDA8C(Unk803DBFF4Obj* self, Unk803DBFF4Info* info)
{
    int ok = fn_803DD068((Unk803DBFF4Tex*)((char*)self + 4), info);
    int t = 0;
    if (ok)
        t = 1;
    return t;
}

/* near-miss (one slot longer): retail's switch tree on the kind byte is rooted at 0x31 with a degenerate
   right chain (cmpwi 0x31; cmplwi 0x31; ble; cmpwi 0x32; cmpwi 0x33); ours balances around 0x32. Tried
   int/unsigned index locals, case order, an `int fmt = 0` form without default. */
extern "C" int fn_803DDAC0(Unk803DBFF4Tex* self, Unk803DBFF4Info* info)
{
    if (self->m50 != 0 && info != 0) {
        int fmt;
        switch (info->m0) {
        case 0x31:
            fmt = 1;
            break;
        case 0x32:
            fmt = 2;
            break;
        case 0x33:
            fmt = 0;
            break;
        default:
            fmt = 0;
        }
        void* data;
        if (info->mC & 0x10000000)
            data = (char*)info + info->m10;
        else
            data = (char*)info + 0x10;
        GXInitTlutObj(self->m40, data, fmt, (unsigned short)info->m4);
        return 1;
    }
    return 0;
}

extern "C" void fn_803DDB5C(int n)
{
    lbl_80627B00 = n;
    GXSetNumTexGens(n);
}

extern "C" void fn_803DDB88(int idx, int a, int b, int c, unsigned char d, int e)
{
    lbl_8062BB70.a[idx] = a;
    lbl_8062BB70.b[idx] = b;
    lbl_8062BB70.c[idx] = c;
    lbl_8062BB70.d[idx] = d;
    lbl_8062BB70.e[idx] = e;
    GXSetTexCoordGen2(idx, lbl_8062BB70.a[idx], lbl_8062BB70.b[idx], lbl_8062BB70.c[idx], lbl_8062BB70.d[idx], e);
}

extern "C" void fn_803DDBF0()
{
    TcReset();
}

extern "C" Unk803DBFF4Tex* fn_803DDC40(Unk803DBFF4Tex* t)
{
    t->m0 = 0;
    t->m4 = 0;
    t->mC = 2;
    t->m10 = 2;
    t->m14 = 0.0f;
    t->m18 = 1;
    t->m4C = 0;
    t->m1C = 1;
    t->m50 = 0;
    return t;
}

extern "C" void fn_803DDC80(void* p, int c)
{
    if (c & 1)
        fn_80377408(p);
}

extern "C" void fn_803DDCA8()
{
    fn_803DD4E4(1, 0xFFFF);
}

/*
 * Not attempted: fn_803DBFF4 (912 instructions), fn_803DCE34 (141, string-keyed lookup with sprintf),
 * fn_803DD068 (142), fn_803DD2A0 (145). The original code stays linked.
 */
