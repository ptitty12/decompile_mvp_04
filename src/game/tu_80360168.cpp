/*
 * Game code, .text 0x80360168-0x803606B0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8035B60C.h"
#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))
#define PUTI(o, v) (*(int*)((char*)self + (o)) = (v))
#define PUTB(o, v) (*(unsigned char*)((char*)self + (o)) = (v))
#define PUTF(o, v) (*(float*)((char*)self + (o)) = (v))
#define CPUT(o, v) (*(const void**)((char*)this + (o)) = (v))
#define CPUTI(o, v) (*(int*)((char*)this + (o)) = (v))
#define CPUTB(o, v) (*(unsigned char*)((char*)this + (o)) = (v))
#define CPUTF(o, v) (*(float*)((char*)this + (o)) = (v))
#define GETI(o) (*(int*)((char*)self + (o)))
struct U {
    char pad0[0x4000];
};
void fn_80377408(void* p);
extern char lbl_8064A550[];
extern char lbl_80655808[];
void fn_800EC1B8(void* p, int chrg);
void fn_8035686C(void* p, int chrg);
void fn_80360B60(void* p, int chrg);

void fn_80360168(U* self, int chrg)
{
    fn_80360B60(self, chrg);
}

void fn_80360188(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_803601A8(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_803601C8(U* self, int chrg)
{
    PUT(0x144, lbl_8064A550);
    fn_8035686C(self, chrg);
}

void fn_803601F8(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360218(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360238(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360258(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360278(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360298(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_803602B8(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_803602D8(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_803602F8(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360318(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360338(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360358(U* self, int chrg)
{
    PUT(0x198, lbl_8064A550);
    fn_8035686C(self, chrg);
}

void fn_80360388(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_803603A8(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_803603C8(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_803603E8(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360408(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360428(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360448(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360468(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360488(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_803604A8(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_803604C8(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_803604E8(U* self, int chrg)
{
    PUT(0xd88, lbl_8064A550);
    PUT(0x3c, lbl_80655808);
    fn_800EC1B8(self, chrg);
}

void fn_80360520(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360540(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360560(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360580(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_803605A0(U* self, int chrg)
{
    PUT(0x158, lbl_8064A550);
    fn_8035686C(self, chrg);
}

void fn_803605D0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_803605F0(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360610(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360630(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360650(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360670(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}

void fn_80360690(U* self, int chrg)
{
    fn_8035686C(self, chrg);
}
