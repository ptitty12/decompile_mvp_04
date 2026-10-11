/*
 * Translation unit at 0x8000E618 (original file name unknown; placeholder).
 * A real TU: it ends with its static-initializer wrapper (docs/UNITS.md
 * ctor anchors). 8 functions.
 *
 * .text 0x8000E618-0x8000F598, .rodata 0x805A430C-0x805A4984, .data 0x806164C0-0x806164E8, .bss 0x80686C30-0x80686CCC.
 * Not split (declare extern if used): small-data (.sdata/.sbss) objects and
 * any second, non-contiguous range of a section.
 *
 * What it holds: a 4-byte singleton (EA core-library heap handle, created on
 * first use: fn_8000E65C), the allocation-statistics callback it registers
 * (fn_8000E718), and 13 static unit vectors (.bss 0x80686C30..0x80686CCC,
 * built by fn_8000E788 = __static_initialization_and_destruction_0) that nothing
 * outside this unit reads.
 *
 * The .rodata range above is only partly reproduced: the string "virtual
 * memory", 0.0f, 1.0f, the four corner points and the centre point (up to
 * 0x805A4360) are. The remaining 0x624 bytes (0x805A4360-0x805A4984: "soa
 * allocator NEW", geomlib header paths, event class names such as
 * "cSwingContactPhase", ...) are unreferenced string literals that retail
 * pools after the table; tu_8000D650.cpp has a 0x23C-byte prefix of the same
 * pool. They look like the strings of inline functions in headers this TU
 * includes (expanded, never emitted), so they are left out here.
 */
#include "game/tu_8000E618.h"

typedef Unk8000E618_Vec3 Vec3;

/* EA core-library memory manager entry points (fn_8043D960 and fn_8043D9FC
 * set up the virtual-memory pool and a callback; fn_803ED720 creates a heap). */
void fn_8043D960(int a, int b, int c);
void fn_8043D9FC(void (*cb)(int, int, int, int));
void fn_8043E038(int a, int b);
int fn_803ED9D4();
void fn_803ED720(int h, const char* name, int a, int b, int c, int d, int e, int f, int g, int h2);
void fn_8043DCFC();
void* operator new(unsigned int, int);

float fn_804028E4(float x); /* square root */
extern const Vec3 lbl_806055AC;
extern int lbl_8061E9F4;

Unk8000E618* lbl_806164C0 = 0;
int lbl_806164C4 = 0;
int lbl_806164C8 = 0;
int lbl_806164CC = 0;
int lbl_806164D0 = 0;
int lbl_806164D4 = 0;
Unk8000E618_Stats lbl_806164D8 = { 0, 0, 0.1f, 0 };

Unk8000E618::Unk8000E618()
{
    m0 = 0;
}

void fn_8000E718(int a, int b, int c, int size);

void fn_8000E624()
{
    fn_8043D960(0x100000, 0x800000, 0x800000);
    fn_8043D9FC(fn_8000E718);
}

Unk8000E618* fn_8000E65C()
{
    if (lbl_806164C0 == 0) {
        lbl_806164C0 = new (0) Unk8000E618;
        fn_8043E038(0x7e000000, 0x800000);
        lbl_806164C0->m0 = fn_803ED9D4();
        fn_803ED720(lbl_806164C0->m0, "virtual memory", 0x7e000000, 0x800000, 0x20, 0x20, 0, 0, 0, 1);
    }
    return lbl_806164C0;
}

int Unk8000E618::fn_8000E6F0()
{
    return m0;
}

void Unk8000E618::fn_8000E6F8()
{
    fn_8043DCFC();
}

void fn_8000E718(int a, int b, int c, int size)
{
    lbl_806164C4 += size;
    lbl_806164C8 += 1;
    int cur = lbl_8061E9F4;
    if (cur > lbl_806164CC) {
        int d = lbl_806164C8 - lbl_806164D8.m0;
        lbl_806164D0 = d;
        if (d > 10) {
            lbl_806164D4++;
        }
        lbl_806164D8.m0 = lbl_806164C8;
        lbl_806164CC = cur;
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
 * 0x805A4324..0x805A4360). The 13 directions below are the normalised
 * differences between them. Nothing outside this unit reads those directions. */
static const Vec3 lbl_805A4324[4] = {
    { 7.5f, 0.0f, 1072.5f }, { 1080.0f, 0.0f, 1080.0f }, { 1072.5f, 0.0f, 7.5f }, { 7.5f, 0.0f, 7.5f }
};
static const Vec3 lbl_805A4354 = { 513.3595f, 0.0f, 513.3595f };

Vec3 lbl_80686C30 = NormalizeOrDefault(lbl_805A4354 - lbl_805A4324[3]);
Vec3 lbl_80686C3C = NormalizeOrDefault(lbl_805A4324[3] - lbl_805A4354);
Vec3 lbl_80686C48 = NormalizeOrDefault(lbl_805A4324[2] - lbl_805A4324[1]);
Vec3 lbl_80686C54 = NormalizeOrDefault(lbl_805A4324[1] - lbl_805A4324[2]);
Vec3 lbl_80686C60 = NormalizeOrDefault(lbl_805A4324[1] - lbl_805A4324[0]);
Vec3 lbl_80686C6C = NormalizeOrDefault(lbl_805A4324[0] - lbl_805A4324[1]);
Vec3 lbl_80686C78 = NormalizeOrDefault(lbl_805A4324[2] - lbl_805A4324[3]);
Vec3 lbl_80686C84 = NormalizeOrDefault(lbl_805A4324[3] - lbl_805A4324[2]);
Vec3 lbl_80686C90 = NormalizeOrDefault(lbl_805A4324[3] - lbl_805A4324[1]);
Vec3 lbl_80686C9C = NormalizeOrDefault(lbl_805A4324[0] - lbl_805A4324[3]);
Vec3 lbl_80686CA8 = NormalizeOrDefault(lbl_805A4324[3] - lbl_805A4324[0]);
Vec3 lbl_80686CB4 = NormalizeOrDefault(lbl_805A4324[2] - lbl_805A4324[0]);
Vec3 lbl_80686CC0 = NormalizeOrDefault(lbl_805A4324[0] - lbl_805A4324[2]);
