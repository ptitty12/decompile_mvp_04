/*
 * Game code, .text 0x801287AC-0x8012C8CC (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8010E0F4.h"
#include "game/tu_8001B190.h"

typedef Unk800C7B40_Widget Wid;

/* Button widget as seen through fn_8012B960 (its id is at +0x138). */
struct Unk8012B960_Btn : Unk800C7B40_Widget {
    char pad40[0xF8];
    int m138;
};
/* Screen with two button widgets at +0x188 / +0x18C (fn_8012B960, fn_8012BBF4 ...). */
struct Unk8012B960_Scr : Unk800C7B40_Widget {
    char pad40[0x144];
    int m184;
    Unk8012B960_Btn* m188;
    Unk8012B960_Btn* m18C;
};
typedef Unk8012B960_Scr Scr;

extern const float lbl_805C068C;
extern const float lbl_805C0690;
extern const float lbl_805C0694;
extern const float lbl_805C06A0;
extern const int lbl_805C06A4[];
extern const char lbl_805C0424[];
extern const char lbl_805C0438[];
extern const char lbl_805C088C[];
extern const char lbl_805C0890[];

// PROTOS-BEGIN
extern "C" {
void fn_801287AC(int a, int b, int c);
int fn_801295DC(int a, int b, int c);
int fn_8012964C(int a, int c, float v);
int fn_801296DC(int a, int b, int c);
void fn_8012981C(int a, int b, int* out);
void fn_8012A490(int a, int b, int c);
Wid* fn_8012B960(Scr* self, int id, int* out);
int fn_8012BBF4(Scr* self, int id);
}
// PROTOS-END
extern "C" {
void fn_80128850(int a, int b, int c);
void fn_80128BD8(int a, int b, int c);
void fn_801292A4(int a, int b, int c);
void fn_8012A0E8(int a, int b, int c);
void fn_80129A44(int a, int b);
void fn_8012A554(int a, int b, int c);
void fn_8012A8D0(int a, int b, int c);
void fn_8012AB7C(int a, int b, int c);
void fn_8012AF28(int a, int b, int c);
void fn_8012B678(int a, int b, int c);
int fn_8007AB9C(int a, int b, int c);
int fn_8012E3F4(Scr* self);
Wid* fn_8012B960(Scr* self, int id, int* out);
int fn_8007AA84(int a, int b, int c, int d);
int fn_8007A6A0(int a, int b, int c);
}

extern "C" {

void fn_801287AC(int a, int b, int c)
{
    fn_80128850(a, b, c);
    fn_80128BD8(a, b, c);
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    if (lbl_8061A32C->mB8 == 0) {
        fn_801292A4(a, b, c);
        fn_8012A0E8(a, b, c);
        fn_80129A44(b, c);
    }
}

/* near-miss: retail tests b <= 0x3C with bgt-first layout (li r3,6 after the branch); GCC hoists the li here. */
int fn_801295DC(int a, int b, int c)
{
    int r = 0;
    if (b > 0x14) {
        if (b <= 0x28) {
            r = 3;
        } else if (b <= 0x3C) {
            r = 6;
        } else {
            r = 0xC;
            if (b <= 0x50)
                r = 9;
        }
    }
    if (a <= 0x16)
        return c + 0xF;
    if (a > 0x1D) {
        if (a <= 0x22)
            return r + 1;
        return r + 2;
    }
    return r;
}

/* near-miss: retail keeps the result in r3 with a shared epilogue (single exit); this form uses r11. */
int fn_8012964C(int a, int c, float v)
{
    int r = 0;
    if (!(v < lbl_805C068C)) {
        if (!(v >= lbl_805C0690)) {
            r = 3;
        } else {
            r = 9;
            if (!(v >= lbl_805C0694))
                r = 6;
        }
    }
    if (a <= 0x16)
        return c + 0xC;
    if (a > 0x1D) {
        if (a <= 0x22)
            return r + 1;
        return r + 2;
    }
    return r;
}

/* near-miss: retail splits the switch into nested compares on b (80 insns vs 69). */
int fn_801296DC(int a, int b, int c)
{
    switch (b) {
    case 0:
    case 1: {
        int t = fn_8007AA84(a, b, c, 0) + fn_8007AA84(a, b, c, 1);
        return t / 2;
    }
    case 2:
        return fn_8007A6A0(a, 0xD, c);
    case 3:
        return (int)((float)fn_8007A6A0(a, 0x10, c) * lbl_805C06A0);
    case 4:
        return (int)((float)fn_8007A6A0(a, 0xE, c) * lbl_805C06A0);
    }
    return 0;
}

/* near-miss: one instruction (lwzx operand order r30,r3 in retail). */
void fn_8012981C(int a, int b, int* out)
{
    for (int i = 0; i < 4; i++) {
        const int* t = lbl_805C06A4;
        out[i] = t[fn_8007AB9C(a, 6 + i * 5, b)];
    }
}

void fn_8012A490(int a, int b, int c)
{
    fn_8012A554(a, b, c);
    fn_8012A8D0(a, b, c);
    fn_8012AB7C(a, b, c);
    fn_8012AF28(a, b, c);
    if (lbl_8061A32C == 0)
        lbl_8061A32C = (UnkFEMgr*)fn_800B64BC(operator new(0xd8, 0));
    if (lbl_8061A32C->mB8 == 0) {
        fn_801292A4(a, b, c);
        fn_8012B678(a, b, c);
        fn_80129A44(b, c);
    }
}

/* near-miss: retail loads the vptr after selecting the name (14 slots differ). */
Wid* fn_8012B960(Scr* self, int id, int* out)
{
    const char* name;
    if (self->m188->m138 == id) {
        *out = 0;
        name = lbl_805C0424;
    } else if (self->m18C->m138 != id) {
        return 0;
    } else {
        *out = 1;
        name = lbl_805C0438;
    }
    return fn_800C8044(self->fn_vslot32(name, 1));
}

/* near-miss: retail loads the vptr inside each name arm (85 insns vs 84). */
int fn_8012BBF4(Scr* self, int id)
{
    int out;
    int c;
    if (self->m188 != 0 || self->m18C != 0)
        c = 1;
    else
        c = 0;
    if (c != 0) {
        Wid* w = fn_8012B960(self, id, &out);
        if (w != 0)
            fn_800C8034(w->fn_vslot32(lbl_805C088C, 1))->fn_vslot15(0);
        return 1;
    }
    if (fn_8012E3F4(self) != 0) {
        fn_800C8034(fn_800C8044(self->fn_vslot32(self->m184 == 0 ? lbl_805C0424 : lbl_805C0438, 1))->fn_vslot32(lbl_805C088C, 1))->fn_vslot15(0);
    }
    return 0;
}

}
