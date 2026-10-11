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
    char pad40[0xF4];
    int m134;
    int m138;
    int m13C;
    char pad140[8];
    int m148;
    int m14C;
    char pad150[0x14];
    int m164;
    int m168;
    int m16C;
    int m170;
    char pad174[0x10];
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
extern const char lbl_805BC19C[];
extern const char lbl_805BC1A0[];

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
void fn_8012D0D0(Scr* self);
int fn_80126CF4(Scr* self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
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

void fn_8012981C(int a, int b, int* out)
{
    for (int i = 0; i < 4; i++) {
        const char* t = (const char*)lbl_805C06A4;
        int off = fn_8007AB9C(a, 6 + i * 5, b) * 4;
        out[i] = *(const int*)(t + off);
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

Wid* fn_8012B960(Scr* self, int id, int* out)
{
    if (self->m188->m138 == id) {
        *out = 0;
        return fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
    } else if (self->m18C->m138 == id) {
        *out = 1;
        return fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
    }
    return 0;
}

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
        Wid* w;
        if (self->m184 == 0)
            w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
        else
            w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
        fn_800C8034(w->fn_vslot32(lbl_805C088C, 1))->fn_vslot15(0);
    }
    return 0;
}

int fn_8012B9EC(Scr* self, int id)
{
    int out;
    int c;
    if (self->m188 != 0 || self->m18C != 0)
        c = 1;
    else
        c = 0;
    if (c != 0) {
        Wid* w = fn_8012B960(self, id, &out);
        if (w != 0) {
            fn_800C8034(w->fn_vslot32(lbl_805C088C, 1))->fn_vslot15(1);
            if (out == 0) {
                if (self->m164 != 0) {
                    int a = self->m188->fn_vslot95();
                    int b = self->m168;
                    fn_80126CF4(self, a, b, self->m134, self->m16C, self->m170, 0, self->m138, self->m13C, self->m148, self->m14C);
                    return 1;
                }
            } else if (self->m168 != 0) {
                int b = self->m18C->fn_vslot95();
                int a = self->m164;
                fn_80126CF4(self, a, b, self->m134, self->m16C, self->m170, 0, self->m138, self->m13C, self->m148, self->m14C);
                return 1;
            }
        }

    } else if (self->m138 != 0 && fn_8012E3F4(self) != 0) {
        Wid* w;
        if (self->m184 == 0)
            w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
        else
            w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
        fn_800C8034(w->fn_vslot32(lbl_805C088C, 1))->fn_vslot15(1);
    }
    return 0;
}

int fn_8012BD48(Scr* self, int id)
{
    int out;
    int c;
    if (self->m188 != 0 || self->m18C != 0)
        c = 1;
    else
        c = 0;
    if (c != 0) {
        Wid* w = fn_8012B960(self, id, &out);
        if (w != 0) {
            fn_800C8034(w->fn_vslot32(lbl_805C0890, 1))->fn_vslot15(1);
            if (out == 0) {
                if (self->m164 != 0) {
                    int a = self->m188->fn_vslot94();
                    int b = self->m168;
                    fn_80126CF4(self, a, b, self->m134, self->m16C, self->m170, 0, self->m138, self->m13C, self->m148, self->m14C);
                    return 1;
                }
            } else if (self->m168 != 0) {
                int b = self->m18C->fn_vslot94();
                int a = self->m164;
                fn_80126CF4(self, a, b, self->m134, self->m16C, self->m170, 0, self->m138, self->m13C, self->m148, self->m14C);
                return 1;
            }
        }

    } else if (self->m138 != 0 && fn_8012E3F4(self) != 0) {
        Wid* w;
        if (self->m184 == 0)
            w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
        else
            w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
        fn_800C8034(w->fn_vslot32(lbl_805C0890, 1))->fn_vslot15(1);
    }
    return 0;
}

int fn_8012BF50(Scr* self, int id)
{
    int out;
    int c;
    if (self->m188 != 0 || self->m18C != 0)
        c = 1;
    else
        c = 0;
    if (c != 0) {
        Wid* w = fn_8012B960(self, id, &out);
        if (w != 0) {
            fn_800C8034(w->fn_vslot32(lbl_805C0890, 1))->fn_vslot15(0);
            return 1;
        }
        return 0;
    }
    if (fn_8012E3F4(self) != 0) {
        Wid* w;
        if (self->m184 == 0)
            w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
        else
            w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
        fn_800C8034(w->fn_vslot32(lbl_805C0890, 1))->fn_vslot15(0);
    }
    return 0;
}

/* near-miss: same layout difference as fn_8012C2BC. */
int fn_8012C0A4(Scr* self, int id)
{
    int out;
    int c;
    if (self->b0) {
        if (self->m188 != 0 || self->m18C != 0)
            c = 1;
        else
            c = 0;
        if (c != 0) {
            Wid* w = fn_8012B960(self, id, &out);
            if (w != 0) {
                fn_800C805C(fn_800C8044(w->fn_vslot32(lbl_805BC1A0, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot38(1);
                fn_8012D0D0(self);
            }
            return 1;
        }
        if (fn_8012E3F4(self) != 0) {
            int k = self->fn_vslot85();
            Wid* w;
            if (k != 2) {
                if (k == 0) {
                    if (self->fn_vslot86() == 0)
                        return 0;
                    w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
                } else {
                    if (self->fn_vslot87() == 0)
                        return 0;
                    w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
                }
                fn_800C805C(fn_800C8044(w->fn_vslot32(lbl_805BC1A0, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot38(1);
            } else
                return 0;
        }
        return 1;
    }
    return 0;
}

/* near-miss: 1 extra insn; retail places the shared `li r3,0` block between the slot-87 test and the second name arm, and
 * does not merge the first chain with the shared one (GCC merges them when the early returns are hoisted). */
int fn_8012C2BC(Scr* self, int id)
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
            fn_800C805C(fn_800C8044(w->fn_vslot32(lbl_805BC1A0, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot39();
        return 1;
    }
    if (fn_8012E3F4(self) != 0) {
        int k = self->fn_vslot85();
        Wid* w;
        if (k != 2) {
            if (k == 0) {
                if (self->fn_vslot86() == 0)
                    return 0;
                w = fn_800C8044(self->fn_vslot32(lbl_805C0424, 1));
            } else {
                if (self->fn_vslot87() == 0)
                    return 0;
                w = fn_800C8044(self->fn_vslot32(lbl_805C0438, 1));
            }
            fn_800C805C(fn_800C8044(w->fn_vslot32(lbl_805BC1A0, 1))->fn_vslot32(lbl_805BC19C, 1))->fn_vslot39();
        } else
            return 0;
    }
    return 1;
}


}
