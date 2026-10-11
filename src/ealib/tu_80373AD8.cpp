/*
 * EA library TU, .text 0x80373AD8-0x80374588 (static-init anchored; issue #72).
 * Registers one static node (5 words, intrusive list, ctor 0x803DA440) whose
 * arguments are a creator function and three data tables.
 */

class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), void* a, void* b, void* c);
    int m[5];
};

extern "C" void fn_803741DC(void);
extern char lbl_80623E48[];
extern char lbl_80623E6C[];
extern char lbl_80604EB0[];

Unk803DA440 lbl_80693E28(fn_803741DC, lbl_80623E48, lbl_80623E6C, lbl_80604EB0);
