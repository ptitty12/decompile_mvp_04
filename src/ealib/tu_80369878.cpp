/*
 * .text 0x80369878-0x8036A490 (TU start is a guess: the previous TU's end).
 * Static registration object; ctor 0x803DA440 stores {fn, a, b, c} and links the
 * node into a global list. The 0x60 + 0x2c pair at the end is the GCC
 * __static_initialization_and_destruction_0 / _GLOBAL_.I wrapper.
 * fn_8036A16C (the registered setup function) is left as original asm.
 */

struct Unk803DA440 {
    Unk803DA440(void (*fn)(), const void* a, const void* b, const void* c); /* 0x803DA440 */
    char pad[0x14];
};

extern const char lbl_806232E0[];
extern const char lbl_806232FC[];
extern const char lbl_8060383C[];

void fn_8036A16C();

Unk803DA440 lbl_80693D10(fn_8036A16C, lbl_806232E0, lbl_806232FC, lbl_8060383C);
