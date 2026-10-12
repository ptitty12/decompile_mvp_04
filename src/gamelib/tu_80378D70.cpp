/*
 * EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib), built with
 * the game flags (cflags_game: -Os -G0 -ffloat-store),
 * .text 0x80378D70-0x8037B3AC (code-only unit, 41 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 *
 * String scanning helpers, then the animlib vector/quaternion math (Vec3,
 * Vec4/quaternion, plane) and the motion-request record accessors.
 */

struct Unk80379324_Vec3 {
    float x;
    float y;
    float z;
};

struct Unk80379324 {
    float x;
    float y;
    float z;
    float w;
    Unk80379324();
    Unk80379324(const Unk80379324& o);
    Unk80379324(float x, float y, float z, float w);
};

extern "C" {
void fn_80377488(void* p);
void fn_80377408(void* p);
float fn_80410CE8(float y, float x);
void fn_8037B310(int a, int b);
}

extern "C" int fn_80379134(const char* s, int ch)
{
    const char* p = s;
    int i = 0;
    while (*p != ch && *p != 0) {
        p++;
        i++;
    }
    return i;
}

extern "C" int fn_80379174(const char* s)
{
    const char* p = s;
    int c = *p;
    while ((unsigned)(c - 'A') <= 25 || (unsigned)(c - 'a') <= 25 || (unsigned)(c - '0') <= 9 || c == '_') {
        c = *++p;
    }
    return p - s;
}

Unk80379324::Unk80379324()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
}

Unk80379324::Unk80379324(const Unk80379324& o)
{
    *this = o;
}

/* fn_8037936C (0x28 bytes) is a second, identical Vec4 copy ctor of another class;
 * it stays unmatched here: other units reference its fn_ name, so a real ctor
 * (which the "mr r9,r3" copy needs) would have to rename it. */

Unk80379324::Unk80379324(float a, float b, float c, float d)
{
    x = a;
    y = b;
    z = c;
    w = d;
}

extern "C" float fn_80379AF4(const Unk80379324* a, const Unk80379324* b)
{
    float r = a->x * b->x + a->y * b->y + a->z * b->z - b->w;
    return r;
}

struct Unk8037B10C_Obj {
    char pad0[0x30];
    float m30;
    float m34;
    float m38;
};

extern "C" void fn_8037B10C(Unk8037B10C_Obj* m, const Unk80379324_Vec3* v)
{
    m->m30 = v->x;
    m->m34 = v->y;
    m->m38 = v->z;
}

extern "C" float fn_8037B1F0(const Unk80379324_Vec3* v)
{
    float r = -fn_80410CE8(v->z, v->x);
    return r;
}

extern "C" void fn_8037B224(void** p, int chrg)
{
    if (*p)
        fn_80377488(*p);
    if (chrg & 1)
        fn_80377408(p);
}

extern "C" void fn_8037B374() {}

extern "C" void fn_8037B378() {}

extern "C" void fn_8037B37C() {}

extern "C" void fn_8037B380()
{
    fn_8037B310(1, 0xFFFF);
}
