/*
 * .text 0x8036A490-0x8036AEE4 (TU start is a guess: the previous TU's end).
 * Static registration object; ctor 0x803DA440 stores {fn, a, b, c} and links the
 * node into a global list. The 0x60 + 0x2c pair at the end is the GCC
 * __static_initialization_and_destruction_0 / _GLOBAL_.I wrapper.
 * fn_8036AB38 (the registered setup function) is left as original asm.
 */

struct Unk803DA440 {
    Unk803DA440(void (*fn)(), const void* a, const void* b, const void* c); /* 0x803DA440 */
    char pad[0x14];
};

extern const char lbl_80623398[];
extern const char lbl_806233B8[];
extern const char lbl_80603990[];

void fn_8036AB38();

Unk803DA440 lbl_80693D24(fn_8036AB38, lbl_80623398, lbl_806233B8, lbl_80603990);
