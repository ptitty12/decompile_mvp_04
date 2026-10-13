#ifndef GAME_TU_80067A20_H
#define GAME_TU_80067A20_H

/*
 * 0x80067A20..0x8006902C: seventy 0x50-byte setters of one shape, then the
 * game TU's `_GLOBAL_.I` wrapper (0x80069000). Each setter clamps its int
 * argument to 0..0x7FFF in a stack slot and passes the slot's address as the
 * second argument of fn_803BA7C4 (first argument: one of the 8-byte .bss
 * objects lbl_806872EC..lbl_8068754C, which the static initializer fn_80065968
 * and fn_800418C4 also reference).
 *
 * Evidence for the prototype: fn_803BA7C4 takes the object in r3 and a
 * pointer to the new value in r4, brackets fn_803BA80C(obj, &value) with
 * fn_803B9DDC / fn_803B9E08 (a lock-style pair), and fn_803BA80C compares the
 * value against the word at *(obj->m0 + 4), stores it there if different and
 * then calls every entry of the list at *(obj->m0) (a notify list). So each
 * object is {pointer to a state block, one more word} and behaves like a
 * set-able observable int. No code calls the setters by name: they are only
 * referenced from a .rodata table of (function pointer, 1) pairs.
 */
struct Unk803BA7C4_Obj {
    void* m0;
    int m4;
};
/* C wrapper implemented in snd/tu_803B998C.cpp; local view of a GlobalVariableHandle. */
extern "C" int fn_803BA7C4(Unk803BA7C4_Obj* obj, int* value);

/* The game TU's __static_initialization_and_destruction_0(int initialize, int priority),
 * at 0x80065968 in tu_80064D48; its caller below passes (1, 0xFFFF). */
void fn_80065968(int initialize, int priority);

#endif
