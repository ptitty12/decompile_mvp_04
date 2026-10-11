/*
 * Translation unit at 0x8000D650 (original file name unknown; placeholder).
 * A real TU: it ends with its static-initializer wrapper (docs/UNITS.md
 * ctor anchors). 7 functions.
 *
 * .text 0x8000D650-0x8000E618, .rodata 0x805A4014-0x805A430C, .data 0x806164B8-0x806164C0, .bss 0x80686B94-0x80686C30.
 * Not split (declare extern if used): small-data (.sdata/.sbss) objects and
 * any second, non-contiguous range of a section.
 *
 * What it holds: boot-time memory setup (fn_8000D650 registers the two
 * allocation callbacks below and prints the pool size), a controller check
 * that sets lbl_806164B8 (fn_8000D6D4), "ProDGRegisteredMEM_alloc" / "GC
 * malloc()" allocation wrappers, and the same 13 static unit vectors as
 * tu_8000E618.cpp (.bss 0x80686B94..0x80686C30).
 *
 * The .rodata range is not all reproduced: the strings (including the
 * string-literal order) and the Vec3 table are, up to 0x805A40D0. The
 * remaining 0x23C bytes (0x805A40D0-0x805A430C: "soa allocator NEW", geomlib
 * header paths, "PreMorph", ...) are unreferenced string literals that retail
 * pools after the table. They look like the strings of inline functions in
 * headers this TU includes (expanded, never emitted), so they are left out.
 *
 * Retail order in .text: the three small allocation functions follow the
 * static initializer (deferred, as inline functions are). fn_8000E56C and
 * fn_8000E59C are `static inline` here for that reason. fn_8000E5BC is called
 * from other units (libc), so it must be a global definition in .text; as a
 * plain function it is emitted where it is defined (first), not after the
 * static initializer, and as `inline` it would land in a .gnu.linkonce.t
 * section outside .text. Its string literal keeps retail's .rodata order.
 */
#include "game/tu_8000D650.h"
#include "game/tu_8000E618.h"

typedef Unk8000E618_Vec3 Vec3;

void* fn_803ED604(const char* name, int size, int flags);
void fn_803EDA0C();
void fn_8033E958(const char* fmt, ...);
void fn_803EDC74();
int fn_803EE3D4(int a);
int fn_80436404();
int fn_8043D6A8();
void fn_80436F58(int a);
int fn_80436EE8();
void fn_80439618(Unk8000D6D4_Pad* pad);
float fn_804028E4(float x); /* square root */
extern const Vec3 lbl_806055AC;
void fn_8000E624();

extern void* (*lbl_806EEB30)(int);
extern void (*lbl_806EEB34)();

int lbl_806164B8[2] = { 0, 0 };

static inline void* fn_8000E56C(int size)
{
    return fn_803ED604("ProDGRegisteredMEM_alloc allocation", size, 0x100);
}

static inline void fn_8000E59C()
{
    fn_803EDA0C();
}

void* fn_8000E5BC(int size)
{
    return fn_803ED604("GC malloc() allocation", size, 0x100);
}

void fn_8000D650()
{
    fn_8000E624();
    fn_8033E958("MEM_init\n");
    fn_803EDC74();
    lbl_806EEB30 = fn_8000E56C;
    lbl_806EEB34 = fn_8000E59C;
    int size = fn_803EE3D4(0);
    fn_8033E958("Memory initialized: Mempool is %d bytes (%dKb)", size, size / 1024);
}

void fn_8000D6D4()
{
    if (fn_80436404() >= 0) {
        if (fn_8043D6A8() != 1) {
            fn_80436F58(0);
        }
        int mode = fn_8043D6A8();
        if (mode == 1) {
            if (fn_80436EE8() != 0) {
                lbl_806164B8[0] = mode;
            } else {
                Unk8000D6D4_Pad pad[4];
                fn_80439618(pad);
                for (int i = 0; i < 4; i++) {
                    if (pad[i].mA == 0 && (pad[i].m0 & 0x200)) {
                        lbl_806164B8[0] = 1;
                    }
                }
            }
        }
    }
}

static inline Vec3 operator-(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

static inline Vec3 Normalize(const Vec3& v, float len)
{
    Vec3 r;
    float inv = 1.0f / len;
    r.x = v.x * inv;
    r.y = v.y * inv;
    r.z = v.z * inv;
    return r;
}

/* Unit vector along v; lbl_806055AC when v has zero length. */
static inline Vec3 NormalizeOrDefault(const Vec3& v)
{
    float len = fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
    if (len != 0.0f) {
        return Normalize(v, len);
    }
    return lbl_806055AC;
}

/* Four corner points and a centre point (consecutive Vec3s in .rodata at
 * 0x805A4094..0x805A40D0, the same table as in tu_8000E618.cpp). The 13
 * directions below are the normalised differences between them. Nothing
 * outside this unit reads those directions. */
static const Vec3 lbl_805A4094[4] = {
    { 7.5f, 0.0f, 1072.5f }, { 1080.0f, 0.0f, 1080.0f }, { 1072.5f, 0.0f, 7.5f }, { 7.5f, 0.0f, 7.5f }
};
static const Vec3 lbl_805A40C4 = { 513.3595f, 0.0f, 513.3595f };

Vec3 lbl_80686B94 = NormalizeOrDefault(lbl_805A40C4 - lbl_805A4094[3]);
Vec3 lbl_80686BA0 = NormalizeOrDefault(lbl_805A4094[3] - lbl_805A40C4);
Vec3 lbl_80686BAC = NormalizeOrDefault(lbl_805A4094[2] - lbl_805A4094[1]);
Vec3 lbl_80686BB8 = NormalizeOrDefault(lbl_805A4094[1] - lbl_805A4094[2]);
Vec3 lbl_80686BC4 = NormalizeOrDefault(lbl_805A4094[1] - lbl_805A4094[0]);
Vec3 lbl_80686BD0 = NormalizeOrDefault(lbl_805A4094[0] - lbl_805A4094[1]);
Vec3 lbl_80686BDC = NormalizeOrDefault(lbl_805A4094[2] - lbl_805A4094[3]);
Vec3 lbl_80686BE8 = NormalizeOrDefault(lbl_805A4094[3] - lbl_805A4094[2]);
Vec3 lbl_80686BF4 = NormalizeOrDefault(lbl_805A4094[3] - lbl_805A4094[1]);
Vec3 lbl_80686C00 = NormalizeOrDefault(lbl_805A4094[0] - lbl_805A4094[3]);
Vec3 lbl_80686C0C = NormalizeOrDefault(lbl_805A4094[3] - lbl_805A4094[0]);
Vec3 lbl_80686C18 = NormalizeOrDefault(lbl_805A4094[2] - lbl_805A4094[0]);
Vec3 lbl_80686C24 = NormalizeOrDefault(lbl_805A4094[0] - lbl_805A4094[2]);
