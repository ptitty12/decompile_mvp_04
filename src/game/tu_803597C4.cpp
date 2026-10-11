/*
 * Game code, .text 0x803597C4-0x8035A2D0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_80355A6C.h"

/* TODO fn_803597C4 */

/* TODO fn_803598A0 */

/* TODO fn_80359910 */

/* TODO fn_80359948 */

/* TODO fn_80359964 */

/* TODO fn_80359974 */

/* TODO fn_8035998C */

/* TODO fn_803599A8 */

void fn_803599C0(void* self, int c)
{
    PUT(0x0, lbl_8065EB00);
    if (c & 1)
        fn_80377408(self);
}

void fn_803599F4() {}

/* TODO fn_803599F8 */

/* TODO fn_80359A40 */

void fn_80359A64(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

void fn_80359A98(void* self, int c)
{
    PUT(0x4, lbl_80649DA0);
    if (c & 1)
        fn_80377408(self);
}

/* TODO fn_80359ACC */

/* TODO fn_80359AF8 */

/* TODO fn_80359B04 */

/* TODO fn_80359B3C */

void fn_80359B48(void* self, int c)
{
    PUT(0x0, lbl_8065EC68);
    fn_8037B424(self, c);
}

extern "C" void fn_80359B78(void* self, int c)
{
    PUT(0x0, lbl_80649C48);
    if (c & 1)
        fn_80377408(self);
}

/* TODO fn_80359BAC */

/* TODO fn_80359C08 */

/* TODO fn_80359C58 */

/* TODO fn_80359CF8 */

/* TODO fn_80359D78 */

/* TODO fn_80359D8C */

/* TODO fn_80359DE8 */

/* TODO fn_80359E0C */

/* TODO fn_80359E30 */

/* TODO fn_80359E94 */

/* TODO fn_80359F30 */

/* TODO fn_80359FB0 */

/* TODO fn_8035A00C */

void fn_8035A020(void* p, int v) { F(int, p, 0xc) = v; }

/* TODO fn_8035A028 */

/* TODO fn_8035A09C */

/* TODO fn_8035A0E0 */

/* TODO fn_8035A104 */

void* fn_8035A134(void* self)
{
    PUT(0, lbl_8065EF20);
    return self;
}

void* fn_8035A148(void* self)
{
    PUT(0, lbl_8065EEE8);
    return self;
}

Unk803442CC* fn_8035A15C(Unk803442CC* self)
{
    fn_803445A8(self);
    PUT(0, lbl_8065EEB0);
    return self;
}

/* TODO fn_8035A198 */

int fn_8035A1F4() { return 0; }

int fn_8035A1FC() { return 0; }

int fn_8035A204() { return 0; }

int fn_8035A20C() { return 0; }

/* TODO fn_8035A214 */

/* TODO fn_8035A28C */

int fn_8035A2B0() { return 0; }

int fn_8035A2B8() { return 0; }

int fn_8035A2C0(void* p) { return F(int, p, 0x8); }

int fn_8035A2C8(void* p) { return F(int, p, 0x330); }
