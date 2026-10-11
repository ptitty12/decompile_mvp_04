/*
 * EA library TU, .text 0x80374588-0x80375038 (static-init anchored; issue #73).
 * Registers one static node (5 words, intrusive list, ctor 0x803DA440) whose
 * arguments are a creator function and three data tables.
 */

class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), void* a, void* b, void* c);
    int m[5];
};

extern "C" void fn_80374C8C(void);
extern char lbl_80623F08[];
extern char lbl_80623F2C[];
extern char lbl_80605028[];

Unk803DA440 lbl_80693E3C(fn_80374C8C, lbl_80623F08, lbl_80623F2C, lbl_80605028);
