/*
 * .text 0x80368E64-0x80369878 (TU start is a guess: the previous TU's end).
 * Static registration object; ctor 0x803DA440 stores {fn, a, b, c} and links the
 * node into a global list. The 0x60 + 0x2c pair at the end is the GCC
 * __static_initialization_and_destruction_0 / _GLOBAL_.I wrapper.
 * fn_80369554 (the registered setup function) is left as original asm.
 */

struct Unk803DA440 {
    Unk803DA440(void (*fn)(), const void* a, const void* b, const void* c); /* 0x803DA440 */
    char pad[0x14];
};

extern const char lbl_80623230[];
extern const char lbl_80623248[];
extern const char lbl_80603718[];

void fn_80369554();

Unk803DA440 lbl_80693CFC(fn_80369554, lbl_80623230, lbl_80623248, lbl_80603718);
