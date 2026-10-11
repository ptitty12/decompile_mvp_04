/*
 * EA library TU, .text 0x80372F60-0x80373AD8 (static-init anchored; issue #71).
 * Registers one static node (5 words, intrusive list, ctor 0x803DA440) whose
 * arguments are a creator function and three data tables.
 */

class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), void* a, void* b, void* c);
    int m[5];
};

extern "C" void fn_80373748(void);
extern char lbl_80623D78[];
extern char lbl_80623DA0[];
extern char lbl_80604D4C[];

Unk803DA440 lbl_80693E14(fn_80373748, lbl_80623D78, lbl_80623DA0, lbl_80604D4C);
