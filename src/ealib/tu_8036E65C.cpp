/*
 * .text 0x8036E65C-0x8036F44C (TU start is a guess: the previous TU's end).
 * Static registration object; ctor 0x803DA440 stores {fn, a, b, c} and links the
 * node into a global list. The 0x60 + 0x2c pair at the end is the GCC
 * __static_initialization_and_destruction_0 / _GLOBAL_.I wrapper.
 * fn_8036F010 (the registered setup function) is left as original asm.
 */

struct Unk803DA440 {
    Unk803DA440(void (*fn)(), const void* a, const void* b, const void* c); /* 0x803DA440 */
    char pad[0x14];
};

extern const char lbl_80623800[];
extern const char lbl_80623840[];
extern const char lbl_80604398[];

void fn_8036F010();

Unk803DA440 lbl_80693D88(fn_8036F010, lbl_80623800, lbl_80623840, lbl_80604398);
