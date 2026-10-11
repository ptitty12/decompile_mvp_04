/*
 * EA library TU, .text 0x803728E8-0x80372F60 (static-init anchored; issue #70).
 * Registers one static node (5 words, intrusive list, ctor 0x803DA440) whose
 * arguments are a creator function and three data tables.
 */

class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), void* a, void* b, void* c);
    int m[5];
};

extern "C" void fn_80372C30(void);
extern char lbl_80623CA0[];
extern char lbl_80623CCC[];
extern char lbl_80604BB8[];

Unk803DA440 lbl_80693E00(fn_80372C30, lbl_80623CA0, lbl_80623CCC, lbl_80604BB8);
