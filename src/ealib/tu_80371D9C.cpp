/*
 * EA library TU, .text 0x80371D9C-0x803728E8 (static-init anchored; issue #69).
 * Registers one static node (5 words, intrusive list, ctor 0x803DA440) whose
 * arguments are a creator function and three data tables.
 */

class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), void* a, void* b, void* c);
    int m[5];
};

extern "C" void fn_80372638(void);
extern char lbl_80623BE8[];
extern char lbl_80623C08[];
extern char lbl_80604A1C[];

Unk803DA440 lbl_80693DEC(fn_80372638, lbl_80623BE8, lbl_80623C08, lbl_80604A1C);
