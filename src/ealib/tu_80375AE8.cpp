/*
 * EA library TU, .text 0x80375AE8-0x80376598 (static-init anchored; issue #75).
 * Registers one static node (5 words, intrusive list, ctor 0x803DA440) whose
 * arguments are a creator function and three data tables.
 */

class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), void* a, void* b, void* c);
    int m[5];
};

extern "C" void fn_803761EC(void);
extern char lbl_80624088[];
extern char lbl_806240AC[];
extern char lbl_806052F4[];

Unk803DA440 lbl_80693E64(fn_803761EC, lbl_80624088, lbl_806240AC, lbl_806052F4);
