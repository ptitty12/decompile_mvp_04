/*
 * EA library TU, .text 0x80375038-0x80375AE8 (static-init anchored; issue #74).
 * Registers one static node (5 words, intrusive list, ctor 0x803DA440) whose
 * arguments are a creator function and three data tables.
 */

class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), void* a, void* b, void* c);
    int m[5];
};

extern "C" void fn_8037573C(void);
extern char lbl_80623FC8[];
extern char lbl_80623FEC[];
extern char lbl_80605190[];

Unk803DA440 lbl_80693E50(fn_8037573C, lbl_80623FC8, lbl_80623FEC, lbl_80605190);
