/*
 * EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib), built with
 * the game flags (cflags_game: -Os -G0 -ffloat-store),
 * .text 0x8037C764-0x8037E64C (code-only unit, 45 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

struct VDel {
    char pad0[0xC];
    virtual ~VDel();
};

struct Unk8037CC30 {
    char pad0[4];
    VDel* m4;
    VDel* m8;
    VDel* mC;
};

extern int lbl_80624290;
extern int lbl_80624294;

extern "C" {
void fn_803FEDB8(void* p, int v);
void fn_8037CA4C(void* self, const char* name, void* field, int id);
void fn_8037CBB4(void* self, void* field, int id);
}

struct Unk8037D0E8 {
    char pad0[4];
    void* m4;
    void* m8;
    const void* mC;
};
struct Unk8037D0E8_P {
    void* m0;
};
extern const char lbl_80605830[];
extern const char lbl_806849B8[];
extern int lbl_80624288;
extern const char lbl_80685080[];

extern "C" {
void* fn_803779B8(void* mem, int cap, int heap, int flag, const char* path, int line);
void* fn_803774A8(unsigned size, int heap);
void fn_8037B8B4(int x);
void fn_80377408(void* p);
void fn_80377488(void* p);
int fn_8037C5D8(int x);
int fn_80377E90(void* arr, int* o1, int* o2, int key);
void fn_8037D768(void* self);
void fn_803DED40(void* a, int b, int c);
}
unsigned fn_80378568(const char* s, int n);
void* operator new(unsigned int size, int heap);

struct Unk8037C884 {
    char pad0[0x18];
    void* m18;
};

extern "C" void fn_8037C8F4(Unk8037C884* o)
{
    if (o->m18 != 0)
        fn_803FEDB8(o->m18, 100);
}

extern "C" void fn_8037C9F4(Unk8037CC30* o, const char* name)
{
    fn_8037CA4C(o, name, &o->m8, lbl_80624290);
}

extern "C" void fn_8037CA20(Unk8037CC30* o, const char* name)
{
    fn_8037CA4C(o, name, &o->mC, lbl_80624294);
}

extern "C" void fn_8037CC30(Unk8037CC30* o)
{
    if (o->m4 != 0) {
        delete o->m4;
        o->m4 = 0;
    }
}

extern "C" void fn_8037CC88(Unk8037CC30* o)
{
    if (o->m8 != 0)
        delete o->m8;
    o->m8 = 0;
}

extern "C" void fn_8037CCE0(Unk8037CC30* o)
{
    if (o->mC != 0)
        delete o->mC;
    o->mC = 0;
}

extern "C" void fn_8037CD38(Unk8037CC30* o)
{
    if (o->mC != 0)
        delete o->mC;
    int id = lbl_80624294;
    o->mC = 0;
    fn_8037CBB4(o, &o->mC, id);
}

extern "C" void fn_8037CDA4(Unk8037CC30* x)
{
    fn_8037CC30(x);
    fn_8037CC88(x);
    fn_8037CCE0(x);
}

extern "C" void fn_8037D0E8(Unk8037D0E8_P* out, int count)
{
    void* mem = operator new(0x18, 0);
    out->m0 = fn_803779B8(mem, count, 0, 0, lbl_80605830, 0x60);
}

extern "C" Unk8037D0E8* fn_8037D140(Unk8037D0E8* o, int a, int count)
{
    o->mC = lbl_806849B8;
    fn_8037D0E8((Unk8037D0E8_P*)o, a);
    o->m4 = fn_803774A8(count * 0x38, 0);
    o->m8 = fn_803774A8(count << 2, 0);
    return o;
}

struct DtorAt0 { const void* m; };

extern "C" void fn_8037BF88(DtorAt0* s, int chrg);

extern "C" void fn_8037D290(DtorAt0* s, int chrg)
{
    fn_8037BF88(s, chrg);
}

extern "C" int fn_8037D680(Unk8037D0E8_P* o, int x, int y)
{
    int sp8;
    int spC;
    if ((unsigned)fn_8037C5D8(x) <= 0xa4) {
        if (fn_80377E90(o->m0, &sp8, &spC, y))
            return sp8;
    }
    return 0;
}

extern "C" int fn_8037D6E4(Unk8037D0E8_P* o, const char* name, int y)
{
    return fn_8037D680(o, fn_80378568(name, 0), y);
}

struct Unk80361034_Pad18 {
    char pad[0x18];
};

struct Unk80361034_OwnV : Unk80361034_Pad18 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct Unk80361034_Own : Unk80361034_OwnV {
    char pad1C[0x74 - 0x1C];
    int m74;
    char pad78[0x80 - 0x78];
    int m80;
};

struct Unk80361034 {
    Unk80361034_Own* m0;
    const void* m4;
};

extern "C" int fn_80378024(Unk80361034_Own* o);

extern "C" void fn_8037D72C(Unk80361034* s)
{
    fn_80378024(s->m0);
}

extern "C" void fn_8037D750() {}

extern "C" void fn_8037D754() {}

extern "C" void fn_8037D758() {}

extern "C" void fn_8037D75C() {}

extern "C" int fn_8037D760()
{
    return 0;
}

extern "C" void fn_8037E050(int x)
{
    lbl_80624288 = x;
    fn_8037B8B4(x);
}

struct KnotBuf { const void* m0; void* m4; int m8; };

extern "C" void fn_80356798(void* p);

extern const char lbl_80685080[];

extern "C" KnotBuf* fn_8037E078(KnotBuf* p)
{
    fn_80356798(p);
    p->m4 = 0;
    p->m0 = lbl_80685080;
    p->m8 = 0;
    return p;
}

extern "C" void fn_8037E0C0(KnotBuf* p, int chrg)
{
    p->m0 = lbl_80685080;
    if (p->m8)
        fn_80377488((void*)p->m8);
    if (chrg & 1)
        fn_80377408(p);
}
