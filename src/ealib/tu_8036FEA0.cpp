/*
 * EA library TU, .text 0x8036FEA0-0x803708F4 (static-init anchored; see issue #66).
 * Registers one static node (5 words, intrusive list, ctor 0x803DA440) whose
 * arguments are a creator function and three data tables.
 */

class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), void* a, void* b, void* c);
    int m[5];
};

extern "C" void fn_80370548(void);
extern char lbl_806239C0[];
extern char lbl_806239E0[];
extern char lbl_80604634[];

Unk803DA440 lbl_80693DB0(fn_80370548, lbl_806239C0, lbl_806239E0, lbl_80604634);
