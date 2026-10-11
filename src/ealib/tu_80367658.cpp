/*
 * .text 0x80367658-0x803682A8 (TU start is a guess: the previous TU's end).
 * Static registration object; ctor 0x803DA440 stores {fn, a, b, c} and links the
 * node into a global list. The 0x60 + 0x2c pair at the end is the GCC
 * __static_initialization_and_destruction_0 / _GLOBAL_.I wrapper.
 * fn_80367F00 (the registered setup function) is left as original asm.
 */

struct Unk803DA440 {
    Unk803DA440(void (*fn)(), const void* a, const void* b, const void* c); /* 0x803DA440 */
    char pad[0x14];
};

extern const char lbl_80623080[];
extern const char lbl_806230A8[];
extern const char lbl_80603458[];

void fn_80367F00();

Unk803DA440 lbl_80693CD4(fn_80367F00, lbl_80623080, lbl_806230A8, lbl_80603458);
