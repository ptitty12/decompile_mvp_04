/*
 * Translation unit at 0x800034A0 (original file name unknown; placeholder).
 * A real TU: it ends with its static-initializer wrapper (docs/UNITS.md
 * ctor anchors). 2 functions.
 *
 * .text 0x800034A0-0x800042B0, .rodata 0x805A301C-0x805A3400, .bss 0x80686860-0x806868FC.
 * Not split (declare extern if used): small-data (.sdata/.sbss) objects and
 * any second, non-contiguous range of a section.
 */

/* Thirteen unit direction vectors; shape matches tu_800057D8. Constant points are this unit retail values. */
struct Vec3 {
    float x, y, z;
};
extern "C" float fn_804028E4(float x);
extern const Vec3 lbl_806055AC;
const Vec3 lbl_805A3024[4] = { { 7.5f, 0.0f, 1072.5f }, { 1080.0f, 0.0f, 1080.0f }, { 1072.5f, 0.0f, 7.5f }, { 7.5f, 0.0f, 7.5f } };
const Vec3 lbl_805A3054 = { 513.3594970703125f, 0.0f, 513.3594970703125f };

inline Vec3 operator-(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline Vec3 operator/(const Vec3& a, float s)
{
    Vec3 r;
    float inv = 1.0f / s;
    r.x = a.x * inv;
    r.y = a.y * inv;
    r.z = a.z * inv;
    return r;
}

inline Vec3 Normalized(const Vec3& v)
{
    float len = fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
    if (len != 0.0f) {
        return v / len;
    }
    return lbl_806055AC;
}

Vec3 lbl_80686860 = Normalized(lbl_805A3054 - lbl_805A3024[3]);
Vec3 lbl_8068686C = Normalized(lbl_805A3024[3] - lbl_805A3054);
Vec3 lbl_80686878 = Normalized(lbl_805A3024[2] - lbl_805A3024[1]);
Vec3 lbl_80686884 = Normalized(lbl_805A3024[1] - lbl_805A3024[2]);
Vec3 lbl_80686890 = Normalized(lbl_805A3024[1] - lbl_805A3024[0]);
Vec3 lbl_8068689C = Normalized(lbl_805A3024[0] - lbl_805A3024[1]);
Vec3 lbl_806868A8 = Normalized(lbl_805A3024[2] - lbl_805A3024[3]);
Vec3 lbl_806868B4 = Normalized(lbl_805A3024[3] - lbl_805A3024[2]);
Vec3 lbl_806868C0 = Normalized(lbl_805A3024[3] - lbl_805A3024[1]);
Vec3 lbl_806868CC = Normalized(lbl_805A3024[0] - lbl_805A3024[3]);
Vec3 lbl_806868D8 = Normalized(lbl_805A3024[3] - lbl_805A3024[0]);
Vec3 lbl_806868E4 = Normalized(lbl_805A3024[2] - lbl_805A3024[0]);
Vec3 lbl_806868F0 = Normalized(lbl_805A3024[0] - lbl_805A3024[2]);
