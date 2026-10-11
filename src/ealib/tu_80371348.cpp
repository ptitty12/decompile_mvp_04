/*
 * EA library TU, .text 0x80371348-0x80371D9C (static-init anchored; issue #68).
 * Registers one static node (5 words, intrusive list, ctor 0x803DA440) whose
 * arguments are a creator function and three data tables.
 */

class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), void* a, void* b, void* c);
    int m[5];
};

extern "C" void fn_803719F0(void);
extern char lbl_80623B30[];
extern char lbl_80623B50[];
extern char lbl_806048E4[];

Unk803DA440 lbl_80693DD8(fn_803719F0, lbl_80623B30, lbl_80623B50, lbl_806048E4);
