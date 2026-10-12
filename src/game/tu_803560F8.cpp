/*
 * Game code, .text 0x803560F8-0x8035688C (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */

#include "game/tu_80355A6C.h"

void fn_803560F8(void* self, int c)
{
    PUT(0x100, lbl_8065A2B0);
    PUT(0x3c, lbl_8065A0A8);
    fn_80356CA0(self, c);
}

void fn_80356130(void* a, int b) { fn_800B62FC(a, b); }

void fn_80356150(void* a, int b) { fn_800B62FC(a, b); }

void fn_80356170(void* a, int b) { fn_800B62FC(a, b); }

void fn_80356190(void* a, int b) { fn_800B62FC(a, b); }

void fn_803561B0(void* a, int b) { fn_800D0E24(a, b); }

void fn_803561D0(void* a, int b) { fn_800D0E24(a, b); }

void fn_803561F0(void* self, int c)
{
    PUT(0xbc, lbl_80657308);
    PUT(0x3c, lbl_806573C8);
    fn_80356F30(self, c);
}

void fn_80356228(char* self, int c)
{
    fn_800D0D64(self + 0x60, 2);
    fn_800D0D64(self + 0x4c, 2);
    fn_80356838(self, c);
}

void fn_80356278(void* self, int c)
{
    PUT(0x3c, lbl_8065CCE8);
    if (c & 1)
        fn_80377408(self);
}

void fn_803562AC(void* a, int b) { fn_8035686C(a, b); }

void fn_803562CC(void* a, int b) { fn_8035686C(a, b); }

void fn_803562EC(void* a, int b) { fn_8035686C(a, b); }

void fn_8035630C(void* a, int b) { fn_8035686C(a, b); }

void fn_8035632C(void* a, int b) { fn_8035686C(a, b); }

void fn_8035634C(void* a, int b) { fn_8035686C(a, b); }

void fn_8035636C(void* a, int b) { fn_8035686C(a, b); }

void fn_8035638C(void* a, int b) { fn_8035686C(a, b); }

void fn_803563AC(void* a, int b) { fn_8035686C(a, b); }

void fn_803563CC(void* a, int b) { fn_8035686C(a, b); }

void fn_803563EC(void* a, int b) { fn_8035686C(a, b); }

void fn_8035640C(void* a, int b) { fn_8035686C(a, b); }

void fn_8035642C(void* a, int b) { fn_8035686C(a, b); }

void fn_8035644C(void* a, int b) { fn_8035686C(a, b); }

void fn_8035646C(void* self, int c)
{
    PUT(0x3c, lbl_80651628);
    fn_8035686C(self, c);
}

void fn_8035649C(void* a, int b) { fn_8035686C(a, b); }

void fn_803564BC(void* a, int b) { fn_8035686C(a, b); }

void fn_803564DC(void* a, int b) { fn_8035686C(a, b); }

void fn_803564FC(void* a, int b) { fn_8035686C(a, b); }

void fn_8035651C(char* self, int c)
{
    PUT(0x17c, lbl_80650610);
    PUT(0x3c, lbl_80650628);
    fn_80134EC8(self + 0x134, 0);
    fn_8035686C(self, c);
}

void fn_80356578(void* a, int b) { fn_8035686C(a, b); }

void fn_80356598(void* a, int b) { fn_8035686C(a, b); }

void fn_803565B8(void* a, int b) { fn_8035686C(a, b); }

void fn_803565D8(void* a, int b) { fn_8035686C(a, b); }

void fn_803565F8(void* a, int b) { fn_8035686C(a, b); }

void fn_80356618(void* a, int b) { fn_8035686C(a, b); }

void fn_80356638(void* a, int b) { fn_8035686C(a, b); }

void fn_80356658(void* a, int b) { fn_8035686C(a, b); }

void fn_80356678(void* a, int b) { fn_8035686C(a, b); }

void fn_80356698(void* a, int b) { fn_8035686C(a, b); }

void fn_803566B8(void* a, int b) { fn_8035686C(a, b); }

void fn_803566D8(void* a, int b) { fn_8035686C(a, b); }

void fn_803566F8(void* a, int b) { fn_80356F9C(a, b); }

void fn_80356718(void* a, int b) { fn_8035686C(a, b); }

void fn_80356738(void* a, int b) { fn_8035686C(a, b); }

void fn_80356758(void* a, int b) { fn_8035686C(a, b); }

void fn_80356778(void* a, int b) { fn_8035686C(a, b); }

extern "C" void* fn_80356798(void* self)
{
    PUT(0, lbl_8065D430);
    return self;
}

Unk803567AC::Unk803567AC()
{
    m0 = 0;
    m4 = lbl_8065D410;
}

void fn_803567C8(void* self, int c)
{
    PUT(0x3c, lbl_8065CCE8);
    if (c & 1)
        fn_80377408(self);
}

void* fn_803567FC(char* self, const char* s)
{
    fn_8040B61C(self, s);
    return self;
}

extern "C" void fn_8035682C(char* p) { *p = 0; }

extern "C" void fn_80356838(void* self, int c)
{
    PUT(0x3c, lbl_8065CCE8);
    if (c & 1)
        fn_80377408(self);
}

extern "C" void fn_8035686C(void* a, int b) { fn_800EC704(a, b); }
