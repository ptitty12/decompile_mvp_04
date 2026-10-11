/*
 * EA library TU, .text 0x80376598-0x80377048 (static-init anchored; issue #76).
 * Registers one static node (5 words, intrusive list, ctor 0x803DA440) whose
 * arguments are a creator function and three data tables.
 */

class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), void* a, void* b, void* c);
    int m[5];
};

extern "C" void fn_80376C9C(void);
extern char lbl_80624148[];
extern char lbl_8062416C[];
extern char lbl_80605460[];

Unk803DA440 lbl_80693E78(fn_80376C9C, lbl_80624148, lbl_8062416C, lbl_80605460);
