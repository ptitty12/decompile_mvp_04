/*
 * .text 0x803663B0-0x803666EC (TU boundaries unknown; the start is a guess at the
 * previous function's end, 0x803663B0 = fn_803663B0, the setup function).
 *
 * Static registration object: ctor fn_803DA440 stores {fn, a, b, c} into this
 * and links it to the head of a global list (lbl_806272AC).
 * Evidence: fn_803DA440 (0x28 bytes), the 0x60 + 0x2c pair after it is the
 * GCC __static_initialization_and_destruction_0 / _GLOBAL_.I wrapper.
 */

struct Unk803DA440 {
    Unk803DA440(void (*fn)(), const void* a, const void* b, const void* c); /* 0x803DA440 */
    char pad[0x14];
};

extern const char lbl_80622E38[]; /* .data 0x24 */
extern const char lbl_80622E5C[]; /* .data 0x20 */
extern const char lbl_80603030[]; /* .rodata 0x4C */

void fn_803663B0();

Unk803DA440 lbl_80693C98(fn_803663B0, lbl_80622E38, lbl_80622E5C, lbl_80603030);
