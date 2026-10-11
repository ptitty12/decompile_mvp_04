/*
 * .text 0x803666EC-0x80367140 (TU start is a guess: the previous TU's end).
 * Static registration object; ctor 0x803DA440 stores {fn, a, b, c} and links the
 * node into a global list. The 0x60 + 0x2c pair at the end is the GCC
 * __static_initialization_and_destruction_0 / _GLOBAL_.I wrapper.
 * fn_80366D94 (the registered setup function) is left as original asm.
 */

struct Unk803DA440 {
    Unk803DA440(void (*fn)(), const void* a, const void* b, const void* c); /* 0x803DA440 */
    char pad[0x14];
};

extern const char lbl_80622EF8[];
extern const char lbl_80622F18[];
extern const char lbl_806030AC[];

void fn_80366D94();

Unk803DA440 lbl_80693CAC(fn_80366D94, lbl_80622EF8, lbl_80622F18, lbl_806030AC);
