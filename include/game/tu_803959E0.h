/*
 * Shared types of the VP6 video codec units (ealib/tu_803959E0..tu_803A0310).
 * Offsets were read from the original code: the decoder context allocated by
 * fn_80395C68 (0x4954 bytes) and the buffer pointers freed by fn_80395A94.
 */
#ifndef TU_803959E0_H
#define TU_803959E0_H

struct Vp6AllocArgs {
    int m0, m4, m8;
    Vp6AllocArgs() : m0(0), m4(0), m8(0) {}
};

/* Allocator object at lbl_806EE9C0; slot 1 allocates, slot 2 frees. */
struct Vp6Allocator {
    virtual void* Alloc(int size, const Vp6AllocArgs& args);
    virtual void Free(void* p, int flags);
};

void* fn_8000E5BC(int size); /* C++ symbol fn_8000E5BC__Fi */
extern "C" {
void fn_8040ABC4(void* p);
void* memset(void* p, int c, unsigned n);
void* memcpy(void* d, const void* s, unsigned n);
int rand(void);
}

#endif
