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

struct Unk8037B16C_Mat {
    float m0, m4, m8, mC;
    float m10, m14, m18, m1C;
    float m20, m24, m28;
};

extern "C" float fn_8041171C(float x);
extern "C" float fn_80411554(float x);

extern "C" int printf(const char* fmt, ...);
extern "C" int strncmp(const char* a, const char* b, unsigned n);
extern const char lbl_80605648[];

struct Unk80379478_Mtx {
    float m[16];
};

extern "C" void fn_803E01F4(Unk80379478_Mtx* out, float x, float y, float z, float w, float tx, float ty, float tz);
extern "C" void fn_803DED40(Unk80379478_Mtx* m, void* in, void* out);

extern "C" void* memcpy(void* dst, const void* src, unsigned n);

extern const char lbl_806848F8[];

/* Intrusive singly linked list node: m8 = next, vptr at +0xC (virtual dtor in slot 1). */
struct Unk8037B270_NodeData {
    int m0;
    int m4;
    struct Unk8037B270_Node* m8;
};

struct Unk8037B270_Node : Unk8037B270_NodeData {
    virtual ~Unk8037B270_Node();
};

/* List owner: m0 = owned buffer, m4 = list head, vptr at +0xC. */
struct Unk8037B270 {
    void* m0;
    Unk8037B270_Node* m4;
    int m8;
    const void* mC;
};

struct Unk803793D4_Vec4 {
    float x, y, z, w;
};

inline void* operator new(unsigned int, void* p) { return p; }

extern Unk803793D4_Vec4 lbl_8069428C;
extern Unk80379324 lbl_8069429C;
extern Unk80379324 lbl_806055E8;
extern Unk80379324_Vec3 lbl_806055AC;
extern "C" Unk803793D4_Vec4 fn_803793D4(float w, const Unk80379324_Vec3* v);

extern "C" void fn_80378FB0(const char** pp, unsigned len, int ch)
{
    unsigned i = 0;
    int found = 0;
    if (i < len) {
        const char* s = *pp;
        while (s[i] != ch) {
            i++;
            if (i >= len)
                goto done;
        }
        found = 1;
    }
done:
    if (found)
        *pp = *pp + i;
}

extern "C" void fn_80379004(const char** pp, unsigned len, const char* needle, int n)
{
    int found = 0;
    int i;
    for (i = 0; !found; i++) {
        if (i + n >= len)
            break;
        if (strncmp(*pp + i, needle, n) == 0) {
            found = 1;
            break;
        }
    }
    if (found)
        *pp += i + n;
}

/* near-miss (98.8%): same instructions; retail keeps the source index in r8 and the destination index in r11, ours swaps them (8 slots). */
extern "C" int fn_80379094(char* buf, unsigned len, unsigned start)
{
    unsigned n = start;
    unsigned i = start;
    while (i < len && (unsigned char)(buf[i] - 0x21) > 0x5D) {
        i++;
        n++;
    }
    if ((int)n == 0)
        return 0;
    int d = 0;
    unsigned s = n;
    if (s < len) {
        char c = buf[s];
        buf[0] = buf[s];
        if (c != 0) {
            do {
                s++;
                d++;
                if (s >= len)
                    break;
                c = buf[s];
                buf[d] = buf[s];
            } while (c != 0);
        }
    }
    buf[d] = 0;
    return n;
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

extern "C" void fn_803792AC(unsigned char** pp, unsigned* len)
{
    unsigned char* p = *pp;
    int n = 0;
    unsigned char* start = p;
    if (*p != 0xD) {
        unsigned l = *len;
        if (p < start + l) {
        loop:
            unsigned char c = p[1];
            p += 1;
            n += 1;
            if (c != 0xD) {
                if (p < start + l)
                    goto loop;
            }
        }
    }
    p++;
    *pp = p;
    if (*len >= (unsigned)(n + 1)) {
        *len -= 1;
        *len -= n;
    } else
        *len = 0;
}

extern "C" Unk803793D4_Vec4 fn_803793D4(float w, const Unk80379324_Vec3* v)
{
    Unk803793D4_Vec4 u;
    Unk803793D4_Vec4 t = { 0.0f, 0.0f, 0.0f, 0.0f };
    t.x = v->x;
    t.y = v->y;
    t.z = v->z;
    t.w = w;
    u = t;
    return u;
}

extern "C" void fn_80379478(const Unk80379324* q, void* out)
{
    Unk80379478_Mtx t;
    fn_803E01F4(&t, q->x, q->y, q->z, q->w, 0.0f, 0.0f, 0.0f);
    fn_803DED40(&t, out, out);
}

extern "C" int fn_803794DC(int n)
{
    if (n > 1)
        return n * fn_803794DC(n - 1);
    printf(lbl_80605648);
    return 1;
}

extern "C" float fn_80379AF4(const Unk80379324* a, const Unk80379324* b)
{
    float r = a->x * b->x + a->y * b->y + a->z * b->z - b->w;
    return r;
}

extern "C" float fn_8037AA84(const Unk80379324* q)
{
    float ww = q->w * q->w;
    float xx = q->x * q->x;
    float yy = q->y * q->y;
    float zz = q->z * q->z;
    float r = fn_80410CE8(xx + yy - zz - ww, (q->y * q->z + q->x * q->w) + (q->y * q->z + q->x * q->w));
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

extern "C" Unk80379324_Vec3 fn_8037B128(const Unk8037B10C_Obj* m)
{
    Unk80379324_Vec3 v;
    v.x = m->m30;
    v.y = m->m34;
    v.z = m->m38;
    return v;
}

extern "C" void fn_8037B16C(Unk8037B16C_Mat* m, float a)
{
    float s = fn_8041171C(a);
    float c = fn_80411554(a);
    m->m0 = c;
    m->m4 = 0.0f;
    m->m8 = -s;
    m->m10 = 0.0f;
    m->m14 = 1.0f;
    m->m18 = 0.0f;
    m->m20 = s;
    m->m24 = 0.0f;
    m->m28 = c;
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

extern "C" void fn_8037B270(Unk8037B270* self, int chrg)
{
    self->mC = lbl_806848F8;
    if (self->m0 != 0)
        delete[] (char*)self->m0;
    if (self->m4 != 0) {
        Unk8037B270_Node* n = self->m4;
        for (;;) {
            self->m4 = n->m8;
            delete n;
            n = self->m4;
            if (n == 0)
                break;
        }
    }
    if (chrg & 1)
        delete self;
}

/* near-miss (99.2%): static-init body of two globals; same instructions, but retail forms the address of the first global (the return slot of fn_803793D4) after the address of the Vec3 argument, ours before it (two addi swapped). */
extern "C" void fn_8037B310(int a, int b)
{
    if (b == 0xFFFF && a != 0) {
        new (&lbl_8069428C) Unk803793D4_Vec4(fn_803793D4(1.0f, &lbl_806055AC));
        new (&lbl_8069429C) Unk80379324(lbl_806055E8);
    }
}

extern "C" void fn_8037B374() {}

extern "C" void fn_8037B378() {}

extern "C" void fn_8037B37C() {}

extern "C" void fn_8037B380()
{
    fn_8037B310(1, 0xFFFF);
}
