/*
 * EA shared library code that uses small data (cflags_ealib_sda: -O2, default -G8):
 * VP6/MAD video codecs and SPCH, or RealCore,
 * .text 0x803A0310-0x803A4214 (code-only unit, 39 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */
#include "../../include/game/tu_803959E0.h"

extern "C" {

/* near-miss: same weights as fn_803A00DC; load and multiply scheduling differ (72 vs 62 insns). */
void fn_803A0310(const unsigned char* src, unsigned n, unsigned char* dst)
{
    unsigned i;
    n -= 3;
    for (i = 0; i < n; i += 3) {
        dst[0] = src[0];
        dst[1] = (src[0] * 0x66U + src[1] * 0x9AU + 0x80) >> 8;
        dst[2] = (src[1] * 0xCDU + src[2] * 0x33U + 0x80) >> 8;
        dst[4] = (src[2] * 0x9AU + src[3] * 0x66U + 0x80) >> 8;
        dst[3] = (src[1] * 0x33U + src[2] * 0xCDU + 0x80) >> 8;
        src += 3;
        dst += 5;
    }
    dst[0] = src[0];
    dst[1] = (src[0] * 0x66U + src[1] * 0x9AU + 0x80) >> 8;
    dst[2] = (src[1] * 0xCDU + src[2] * 0x33U + 0x80) >> 8;
    dst[3] = (src[1] * 0x33U + src[2] * 0xCDU + 0x80) >> 8;
    dst[4] = src[2];
}

/* near-miss: 4 slots, order of the first two loads and multiplies. */
void fn_803A0408(unsigned char* p, int s, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++) {
        unsigned p0 = p[0];
        unsigned p1 = p[s];
        p[s] = (p0 * 0x66U + p1 * 0x9AU + 0x80) >> 8;
        unsigned p2 = p[2 * s];
        p[2 * s] = (p1 * 0xCDU + p2 * 0x33U + 0x80) >> 8;
        p[3 * s] = (p1 * 0x33U + p2 * 0xCDU + 0x80) >> 8;
        unsigned p5 = p[5 * s];
        p[4 * s] = (p2 * 0x9AU + p5 * 0x66U + 0x80) >> 8;
        p++;
    }
}

void fn_803A04BC(unsigned char* p, int s, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++) {
        unsigned p0 = p[0];
        unsigned p1 = p[s];
        p[s] = (p0 * 0x66U + p1 * 0x9AU + 0x80) >> 8;
        unsigned p2 = p[2 * s];
        p[2 * s] = (p1 * 0xCDU + p2 * 0x33U + 0x80) >> 8;
        p[3 * s] = (p1 * 0x33U + p2 * 0xCDU + 0x80) >> 8;
        p[4 * s] = p2;
        p++;
    }
}

/* near-miss: 1 slot (add operand order) */
void fn_803A0554(const unsigned char* src, unsigned n, unsigned char* dst)
{
    unsigned i;
    n--;
    for (i = 0; i < n; i++) {
        unsigned a = src[0];
        src++;
        unsigned b = src[0];
        dst[0] = a;
        dst[1] = (b + a + 1) >> 1;
        dst += 2;
    }
    unsigned c = src[0];
    dst[0] = c;
    dst[1] = c;
}

void fn_803A05A0(unsigned char* p, int stride, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++) {
        p[stride] = (p[0] + p[2 * stride] + 1U) >> 1;
        p++;
    }
}

void fn_803A05DC(unsigned char* p, int stride, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++) {
        p[stride] = p[0];
        p++;
    }
}

}
