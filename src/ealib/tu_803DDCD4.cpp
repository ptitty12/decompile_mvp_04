/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803DDCD4-0x803DE414 (code-only unit, 15 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 *
 * TEV stage cache: 16 records of 0x64 bytes at lbl_8062BC30, a dirty flag at lbl_8062BC24 and the
 * stage count at lbl_8062BC20. fn_803DDCD4 flushes the dirty cache to the GX TEV state.
 */

extern "C" {
void GXSetNumTevStages(unsigned char n);
void GXSetTevOrder(int stage, int coord, int map, int color);
void GXSetTevAlphaIn(int stage, int a, int b, int c, int d);
void GXSetTevAlphaOp(int stage, int op, int bias, int scale, int clamp, int out_reg);
void GXSetTevColorIn(int stage, int a, int b, int c, int d);
void GXSetTevColorOp(int stage, int op, int bias, int scale, int clamp, int out_reg);
void GXSetTevKColorSel(int stage, int sel);
void GXSetTevKAlphaSel(int stage, int sel);
void GXSetTevSwapMode(int stage, int ras_sel, int tex_sel);
void GXSetTevSwapModeTable(int table, int red, int green, int blue, int alpha);
}

/* Evidence: field offsets and default values from the reset loop fn_803DE0F0 and the ctor fn_803DE1BC. */
struct Unk803DDCD4Stage {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    unsigned char m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    unsigned char m40;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
    int m5C;
    int m60;
};

inline void StageInit(Unk803DDCD4Stage* s)
{
    s->m0 = 7;
    s->m4 = 4;
    s->m8 = 5;
    s->mC = 7;
    s->m10 = 15;
    s->m14 = 8;
    s->m18 = 10;
    s->m1C = 15;
    s->m20 = 0;
    s->m24 = 0;
    s->m28 = 0;
    s->m2C = 1;
    s->m30 = 0;
    s->m34 = 0;
    s->m38 = 0;
    s->m3C = 0;
    s->m40 = 1;
    s->m44 = 0;
    s->m48 = 0;
    s->m4C = 0;
    s->m50 = 4;
    s->m54 = 12;
    s->m58 = 0;
    s->m5C = 0;
    s->m60 = 0;
}

extern unsigned char lbl_8062BC20;
extern int lbl_8062BC24;
extern int lbl_8062BC28;
extern int lbl_8062BC2C;
extern Unk803DDCD4Stage lbl_8062BC30[];

inline void SetAlphaIn(Unk803DDCD4Stage* s, int a, int b, int c, int d)
{
    s->m0 = a;
    s->m4 = b;
    s->m8 = c;
    s->mC = d;
    lbl_8062BC24 = 1;
}

inline void SetColorIn(Unk803DDCD4Stage* s, int a, int b, int c, int d)
{
    s->m10 = a;
    s->m14 = b;
    s->m18 = c;
    s->m1C = d;
    lbl_8062BC24 = 1;
}

inline void SetOrder(Unk803DDCD4Stage* s, int a, int b)
{
    s->m48 = a;
    s->m4C = b;
    lbl_8062BC24 = 1;
}

inline void SetOrderN(Unk803DDCD4Stage* s, int a, int b)
{
    s->m48 = a;
    s->m4C = b;
}

extern "C" void fn_803DDCD4()
{
    if (lbl_8062BC24 != 0) {
        int n = lbl_8062BC20;
        lbl_8062BC24 = 0;
        GXSetNumTevStages(n);
        for (int i = 0; i < n; i++) {
            Unk803DDCD4Stage* s = &lbl_8062BC30[i];
            int cscale = s->m3C;
            int ascale = s->m28;
            if (i == n - 1) {
                if (lbl_8062BC28 != 0) {
                    if (cscale == 0)
                        cscale = 1;
                    else if (cscale == 1)
                        cscale = 2;
                    else if (cscale == 3)
                        cscale = 0;
                }
                if (lbl_8062BC2C != 0) {
                    if (s->m28 == 0)
                        ascale = 1;
                    else if (s->m28 == 1)
                        ascale = 2;
                    else if (s->m28 == 3)
                        ascale = 0;
                }
            }
            GXSetTevOrder(i, s->m4C, s->m48 & 0x7FFFFFFF, s->m50);
            GXSetTevAlphaIn(i, s->m0, s->m4, s->m8, s->mC);
            GXSetTevAlphaOp(i, s->m20, s->m24, ascale, s->m2C, s->m30);
            GXSetTevColorIn(i, s->m10, s->m14, s->m18, s->m1C);
            GXSetTevColorOp(i, s->m34, s->m38, cscale, s->m40, s->m44);
            GXSetTevKColorSel(i, s->m54);
            GXSetTevKAlphaSel(i, s->m58);
            GXSetTevSwapMode(i, s->m5C, s->m60);
        }
    }
}

inline void SetCount(unsigned char n)
{
    lbl_8062BC20 = n;
    lbl_8062BC24 = 1;
}

extern "C" void fn_803DDE7C()
{
    Unk803DDCD4Stage def;
    StageInit(&def);
    lbl_8062BC30[0] = def;
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapModeTable(0, 0, 1, 2, 3);
    GXSetTevSwapModeTable(1, 0, 0, 0, 3);
    GXSetTevSwapModeTable(2, 1, 1, 1, 3);
    GXSetTevSwapModeTable(3, 2, 2, 2, 3);
    for (int i = 1; i < 16; i++) {
        lbl_8062BC30[i] = def;
        lbl_8062BC24 = 1;
        SetOrderN(&lbl_8062BC30[i], i, i);
        SetColorIn(&lbl_8062BC30[i], 15, 15, 15, 12);
        SetAlphaIn(&lbl_8062BC30[i], 7, 7, 7, 6);
        GXSetTevSwapMode(i, 0, 0);
    }
    SetCount(1);
}

extern "C" void fn_803DE0F0(int a, int b)
{
    if (b == 0xFFFF && a != 0) {
        for (int i = 0; i < 16; i++)
            StageInit(&lbl_8062BC30[i]);
    }
}

extern "C" Unk803DDCD4Stage* fn_803DE1BC(Unk803DDCD4Stage* s)
{
    StageInit(s);
    return s;
}

extern "C" void fn_803DE25C(Unk803DDCD4Stage* s, int a, int b, int c, int d)
{
    SetAlphaIn(s, a, b, c, d);
}

extern "C" void fn_803DE27C(Unk803DDCD4Stage* s, int a, int b, int c, int d)
{
    SetColorIn(s, a, b, c, d);
}

extern "C" void fn_803DE29C(Unk803DDCD4Stage* s, int a, int b, int c, unsigned char d, int e)
{
    s->m34 = a;
    s->m38 = b;
    s->m3C = c;
    s->m40 = d;
    s->m44 = e;
    lbl_8062BC24 = 1;
}

extern "C" void fn_803DE2C0(Unk803DDCD4Stage* s, int v)
{
    s->m54 = v;
    lbl_8062BC24 = 1;
}

extern "C" void fn_803DE2D4(Unk803DDCD4Stage* s, int v)
{
    s->m58 = v;
    lbl_8062BC24 = 1;
}

extern "C" void fn_803DE2E8(Unk803DDCD4Stage* s, int a, int b)
{
    SetOrder(s, a, b);
}

extern "C" void fn_803DE300(Unk803DDCD4Stage* src, int idx)
{
    Unk803DDCD4Stage* dst = &lbl_8062BC30[idx];
    if (dst == src)
        return;
    *dst = *src;
    lbl_8062BC24 = 1;
}

extern "C" void fn_803DE374(int a, int b)
{
    if (lbl_8062BC28 != a || lbl_8062BC2C != b)
        lbl_8062BC24 = 1;
    lbl_8062BC28 = a;
    lbl_8062BC2C = b;
}

extern "C" void fn_803DE3B4(int* a, int* b)
{
    *a = lbl_8062BC28;
    *b = lbl_8062BC2C;
}

extern "C" void fn_803DE3D0(unsigned char n)
{
    SetCount(n);
}

extern "C" void fn_803DE3E8()
{
    fn_803DE0F0(1, 0xFFFF);
}
