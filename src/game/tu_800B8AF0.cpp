/*
 * Game code, .text 0x800B8AF0-0x800BCD38 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800A8684.h"
#include "game/tu_8000E618.h"

Unk8000E618* fn_8000E65C();
int fn_80076270(int v);
struct FEMgrB8 {
    char pad0[0xB8];
    int mB8;
};
struct FE4G {
    char pad0[4];
    struct FE4Gb* m4;
};
struct FE4Gb {
    char pad0[0xC];
    struct FE24* mC;
    struct FE74* m10;
};
struct FE24 {
    char pad0[0x24];
    int m24;
};
struct FE74 {
    char pad0[0x74];
    int m74;
};
extern FEMgrB8* lbl_8061A32C;
extern FE4G* lbl_806192E0;
extern int lbl_8061B3B8;
extern int lbl_8061A58C;
extern int lbl_8061A590;
extern int lbl_8061A594;
extern int lbl_8061A598;
extern int lbl_8061A59C;
extern int lbl_8061A5A0;
extern const char lbl_805BA58C[];
extern const char lbl_805BA5A4[];
extern const char lbl_805BA5B4[];
extern const char lbl_805BA5CC[];
extern const char lbl_805BA5DC[];
extern const char lbl_805BA5F0[];
extern const char lbl_805BA60C[];

/* ---- generated externs ---- */

extern "C" {
void fn_800B8B3C(FEObj68* self, int k);
void fn_800B8DA0(FEObj68* self, const char* name);
void fn_800B8E7C(FEObj68* self, char* buf);
FEMgrB8* fn_800B64BC(FEMgrB8* p);
void fn_80377408(void* p);
void fn_80377488(void* p);
void* fn_803774A8(unsigned n, int heap);
void fn_8033E884(const char* s);
void fn_803FFA60(char* d, const char* s, int n);
const char* fn_802B9300(int v, int a, int b, int* outn);
void* fn_803FC480(int path);
int fn_80401904(void* f);
void fn_804017B0(void* f, void* buf);
int fn_803EE3D4(int a);
void* fn_800ED534(void* o, const char* name);
int fn_8040B574(const char* a, const char* b);
int fn_8011B5A4();
void* fn_80149F70(const char* s, int a);
void fn_8014A0EC(void* p);
int fn_803ED604(const char* fmt, int a, int b);
void fn_80378D40(const char* s, int c, unsigned* used);
}



/* ---- unit prototypes ---- */
extern "C" {
void fn_800B8AF0(FEObj68* self);
void fn_800B8B3C(FEObj68* self, int k);
void* fn_800B8CA4(FEObj68* self, const char* name);
void fn_800B8DA0(FEObj68* self, const char* name);
void fn_800B9FB8(void* self, const char** cur, int n);
}
/* ---- end prototypes ---- */

/* ---- functions ---- */

extern "C" void fn_800B8AF0(FEObj68* self)
{
    if (self->mC != 0) {
        fn_80377408((void*)self->mC);
        self->mC = 0;
    }
    fn_800B8B3C(self, self->m5C);
}

extern "C" void fn_800B8B3C(FEObj68* self, int k)
{
    int v;
    switch (k) {
    case 0:
        v = lbl_8061A58C;
        break;
    case 1:
        fn_8014A0EC(fn_80149F70(lbl_805BA58C, 0));
        v = lbl_8061A590;
        break;
    case 2:
        v = lbl_8061A590;
        break;
    case 3:
        switch (lbl_806192E0->m4->m10->m74) {
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
            v = lbl_8061A59C;
            break;
        default:
            if (fn_80076270(lbl_806192E0->m4->mC->m24)) {
                v = lbl_8061A598;
            } else {
                v = lbl_8061A594;
            }
            break;
        }
        break;
    case 6:
        v = lbl_8061A5A0;
        break;
    default:
        return;
    }
    int len = 0;
    const char* data = fn_802B9300(v, 0, 0xE, &len);
    int n = len;
    int h = fn_8000E65C()->fn_8000E6F0();
    self->mC = fn_803ED604(lbl_805BA5A4, n, h);
    fn_803FFA60((char*)self->mC, data, len);
    fn_80377408((void*)data);
    fn_8000E65C()->fn_8000E6F8();
}

extern "C" void* fn_800B8CA4(FEObj68* self, const char* name)
{
    self->m4 = fn_803EE3D4(self->m0);
    self->m58 = 0;
    self->m10 = (int)fn_800ED534(operator new(0x1D0, self->m0), name);
    if (fn_8040B574(name, lbl_805BA5B4) == 0) {
        int v = fn_8011B5A4();
        lbl_8061B3B8 = v;
        if (v) {
            fn_800B8DA0(self, lbl_805BA5CC);
        } else {
            fn_800B8DA0(self, lbl_805BA5DC);
        }
    }
    fn_800B8DA0(self, name);
    if (lbl_8061A32C == 0) {
        lbl_8061A32C = fn_800B64BC((FEMgrB8*)operator new(0xD8, 0));
    }
    if (lbl_8061A32C->mB8 != 0) {
        fn_800B8DA0(self, lbl_805BA5F0);
    }
    return (void*)self->m10;
}

extern "C" void fn_800B8DA0(FEObj68* self, const char* name)
{
    int off = 0;
    void* f = fn_803FC480(self->mC);
    if (self->m5C == 3) {
        off = self->m0;
    }
    int n = fn_80401904(f);
    char* buf = (char*)fn_803774A8(n + 0x400, off | 0x100);
    fn_804017B0(f, buf);
    char* src = buf;
    char* dst = buf;
    if (n > 0) {
        do {
            unsigned char c = *src;
            if (c == 0xD) {
                src++;
            } else {
                *dst = c;
                src++;
                dst++;
            }
        } while (src - buf < n);
    }
    *dst = 0;
    fn_800B8E7C(self, buf);
    fn_8033E884(lbl_805BA60C);
    if (buf) {
        fn_80377488(buf);
    }
}

extern "C" void fn_800B9FB8(void* self, const char** cur, int n)
{
    for (int i = 0; i < n; i++) {
        unsigned used = 0;
        fn_80378D40(*cur, 0x2C, &used);
        *cur += used + 1;
    }
}
