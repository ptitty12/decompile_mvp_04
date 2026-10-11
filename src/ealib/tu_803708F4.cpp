/*
 * EA library TU, .text 0x803708F4-0x80371348 (static-init anchored; issue #67).
 * Registers one static node (5 words, intrusive list, ctor 0x803DA440) whose
 * arguments are a creator function and three data tables.
 */

class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), void* a, void* b, void* c);
    int m[5];
};

extern "C" void fn_80370F9C(void);
extern char lbl_80623A78[];
extern char lbl_80623A98[];
extern char lbl_80604788[];

Unk803DA440 lbl_80693DC4(fn_80370F9C, lbl_80623A78, lbl_80623A98, lbl_80604788);
