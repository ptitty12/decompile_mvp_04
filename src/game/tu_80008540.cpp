/*
 * Translation unit at 0x80008540 (original file name unknown; placeholder).
 * A real TU: it ends with its static-initializer wrapper (docs/UNITS.md
 * ctor anchors). 26 functions.
 *
 * .text 0x80008540-0x8000C2C4, .rodata 0x805A3A54-0x805A3B38, .data 0x80615848-0x80615850, .bss 0x80686A4C-0x80686AF8.
 * Not split (declare extern if used): small-data (.sdata/.sbss) objects and
 * any second, non-contiguous range of a section.
 *
 * Game controller ("gcpad") classes; layouts and evidence are in
 * include/game/tu_80008540.h.
 */
#include "game/tu_80008540.h"

extern "C" {
void SISetSamplingRate(int);                      /* called once before the pads are created */
void* fn_8040B320(void* dst, int val, unsigned int n);   /* memset */
void* fn_803FFC58(void* dst, int val, unsigned int n);   /* memset */
void fn_804393B4(unsigned int mask);
void fn_80439918(int chan, int cmd);   /* motor control */
}
extern char lbl_806E0210[0x30];             /* two 0x30-byte buffers (common symbols) */
extern char lbl_806E0240[0x30];

const char* lbl_80615848 = "gcpad";

/* Allocates the pad objects into arr and returns n. */
int fn_80008540(Unk800085B0** arr, int n)
{
    SISetSamplingRate(1);
    for (int i = 0; i < n; i++) {
        arr[i] = new (0) Unk800085B0(i);
    }
    return n;
}

void fn_800085AC()
{
}

static const int lbl_805A3B18[4] = { 0x80000000, 0x40000000, 0x20000000, 0x10000000 };
static const int lbl_805A3B28[4] = { 0, 1, 2, 3 };

/* near-miss: 14 insn slots differ (register numbers of the two lis/addi
 * pairs and the placement of the memset argument setup); about 850 statement
 * orders tried. */
Unk800085B0::Unk800085B0(int idx)
{
    m15DC = idx;
    m15E0 = 0;
    m15E4 = 0;
    m15E8 = -1;
    m15EC = 0.0f;
    m15F0 = -1;
    m15F4 = 0.0f;
    m15F8 = 0;
    m15FC = 0;
    fn_803FFC58(lbl_806E0210, 0, 0x30);
    fn_803FFC58(lbl_806E0240, 0, 0x30);
    fn_804393B4(lbl_805A3B18[m15DC]);
}

/* not attempted: fn_80008664 (0x1DE8 bytes, large frame). */
void Unk800085B0::vslot39()
{
}

/* not attempted: fn_8000A44C (0xA68 bytes): polls the PAD into *out, applies the
 * dead zone (lbl_80686AE8 / lbl_80686AEC) and calls fn_8000AEB4. */
void Unk800085B0::vslot42(Unk8000B258_State* out)
{
}

/* Motor/rumble update, called once per frame from vslot42. */
void Unk800085B0::fn_8000AEB4()
{
    if (m15F8 > 0)
        m15F8++;
    if (m1600 > 0)
        m1600--;
    if (m15E4) {
        if (m15E8 > 0) {
            m15E8--;
        } else if (m15E8 == 0) {
            m15E8 = -1;
            m15E0 = 1;
            m15EC = 0.0f;
        }
        if (m15F0 > 0) {
            m15F0--;
        } else if (m15F0 == 0) {
            m15F0 = -1;
            m15E0 = 1;
            m15F4 = 0.0f;
        }
    }
    if (vslot6()) {
        if ((m15F8 > 0x78 && m15FC) || (m15F8 > 0 && m15E8 <= 0 && m15F0 <= 0)) {
            m15F8 = 0;
            fn_80439918(lbl_805A3B28[m15DC], 0);
            m1600 = 5;
            m15FC = 0;
            m15E0 = 0;
        } else if (m15E0) {
            int a = (int)(m15EC * 65535.0f);
            int b = 0;
            if (!(m15F4 <= 0.0f))
                b = (int)(m15F4 * 8192.0f) + 0x3FDC;
            int c = a + b;
            int v;
            if (!(c > 0xFFFF)) {
                v = c;
                if (v < 0)
                    v = 0;
            } else {
                v = 0xFFFF;
            }
            if ((float)v == 0.0f)
                m15F8 = 0;
            else if (m15F8 > 0x78)
                v = 0;
            if (v == 0) {
                fn_80439918(lbl_805A3B28[m15DC], 0);
                m1600 = 5;
            } else if (m15FC == 0) {
                fn_80439918(lbl_805A3B28[m15DC], 1);
            }
            m15FC = v;
            m15E0 = 0;
        }
    } else {
        m15E0 = 0;
    }
}

/* near-miss: only the first two instructions differ (retail stores the float
 * argument to its stack slot before loading m15E4). */
void Unk800085B0::vslot22(int a, float f)
{
    if (m15E4) {
        if (!m15F8 && m1600 <= 0) {
            m15E8 = a;
            m15F8 = 1;
            m15E0 = 1;
            m15EC = f;
        }
        m1600 = 5;
    }
}

/* near-miss: same leading stfs/lwz order as vslot22, and the clamp is laid out
 * differently (retail shares one fmr between both clamps, 33 insns). */
void Unk800085B0::vslot23(int a, float f)
{
    if (m15E4) {
        if (!m15F8 && m1600 <= 0) {
            m15F0 = a;
            m15E0 = 1;
            m15F8 = 1;
            if (f > 1.0f)
                f = 1.0f;
            else if (!(f >= 0.0f))
                f = 0.0f;
            m15F4 = f;
        }
        m1600 = 5;
    }
}

void Unk800085B0::vslot24(int a)
{
    if (m15E4 != a) {
        m15E4 = a;
        m15EC = 0.0f;
        m15F4 = 0.0f;
        m15E0 = 1;
    }
}

Unk8000B258::Unk8000B258()
{
    fn_8040B320(&m1580, 0, sizeof(m1580));
}

int Unk8000B258::vslot41()
{
    return sizeof(Unk8000B258_State);
}

void Unk8000B258::vslot43(const Unk8000B258_State* s)
{
    m1580 = *s;
}

int Unk8000B258::vslot6()
{
    return m1580.m0;
}

int Unk8000B258::vslot7()
{
    return 0x15;
}

float Unk8000B258::vslot8(int i)
{
    return m1580.m4[i];
}

void Unk8000B258::vslot9(int i, float f)
{
    m1580.m4[i] = f;
}

int Unk8000B258::vslot25(int n)
{
    if (n <= 0)
        return n;
    if (n > 0x18)
        return n;
    return m0[n + 0xEC].m0;
}

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" float fn_804028E4(float);       /* sqrtf */
extern const Vec3 lbl_806055AC;            /* zero vector (shared .rodata) */

inline Vec3 operator-(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline Vec3 operator*(const Vec3& v, float s)
{
    Vec3 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}

inline float Recip(float x)
{
    return 1.0f / x;
}

inline Vec3 Normalized(const Vec3& v)
{
    float len = fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
    if (len != 0.0f)
        return v * Recip(len);
    return lbl_806055AC;
}

static const Vec3 lbl_805A3ADC[4] = {
    { 7.5f, 0.0f, 1072.5f },
    { 1080.0f, 0.0f, 1080.0f },
    { 1072.5f, 0.0f, 7.5f },
    { 7.5f, 0.0f, 7.5f },
};
static const Vec3 lbl_805A3B0C = { 513.3595f, 0.0f, 513.3595f };

Vec3 lbl_80686A4C = Normalized(lbl_805A3B0C - lbl_805A3ADC[3]);
Vec3 lbl_80686A58 = Normalized(lbl_805A3ADC[3] - lbl_805A3B0C);
Vec3 lbl_80686A64 = Normalized(lbl_805A3ADC[2] - lbl_805A3ADC[1]);
Vec3 lbl_80686A70 = Normalized(lbl_805A3ADC[1] - lbl_805A3ADC[2]);
Vec3 lbl_80686A7C = Normalized(lbl_805A3ADC[1] - lbl_805A3ADC[0]);
Vec3 lbl_80686A88 = Normalized(lbl_805A3ADC[0] - lbl_805A3ADC[1]);
Vec3 lbl_80686A94 = Normalized(lbl_805A3ADC[2] - lbl_805A3ADC[3]);
Vec3 lbl_80686AA0 = Normalized(lbl_805A3ADC[3] - lbl_805A3ADC[2]);
Vec3 lbl_80686AAC = Normalized(lbl_805A3ADC[3] - lbl_805A3ADC[1]);
Vec3 lbl_80686AB8 = Normalized(lbl_805A3ADC[0] - lbl_805A3ADC[3]);
Vec3 lbl_80686AC4 = Normalized(lbl_805A3ADC[3] - lbl_805A3ADC[0]);
Vec3 lbl_80686AD0 = Normalized(lbl_805A3ADC[2] - lbl_805A3ADC[0]);
Vec3 lbl_80686ADC = Normalized(lbl_805A3ADC[0] - lbl_805A3ADC[2]);

/* near-miss (fn_8000B384, static initializer): the 13 direction vectors differ
 * from retail only in two stack-slot choices per vector (the Recip() argument
 * and the scaled-vector argument swap slots). The four values below are
 * initialized in retail from one load of lbl_80686AE8 (computed before it is
 * updated); this declaration order reloads it instead. */
float lbl_80686AE8 = lbl_80686AE8 - 0.2f;
float lbl_80686AEC = 1.0f / (1.0f - lbl_80686AE8);
float lbl_80686AF0 = lbl_80686AE8 * lbl_80686AE8;
const char* lbl_80686AF4 = lbl_80615848;
