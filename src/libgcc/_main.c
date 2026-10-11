/*
 * libgcc2.c (L__main) from GCC 2.95.3, as built into SN ProDG's libgcc.
 * DO_GLOBAL_CTORS_BODY comes from gcc/gbl-ctors.h. SN's build has no
 * atexit(__do_global_dtors) call at the end of __do_global_ctors.
 *
 * `_ctors` is the start of .ctors (GCC's __CTOR_LIST__): 0xFFFFFFFF, then the
 * constructors, then 0. It is defined by config/GV4E69/ldscript.ld.
 */

typedef void (*func_ptr)(void);

extern func_ptr _ctors[];

void __do_global_ctors(void)
{
    unsigned long nptrs = (unsigned long)_ctors[0];
    unsigned i;

    if (nptrs == (unsigned long)-1)
        for (nptrs = 0; _ctors[nptrs + 1] != 0; nptrs++);
    for (i = nptrs; i >= 1; i--)
        _ctors[i]();
}

void __main(void)
{
    /* Support recursive calls to `main': run initializers just once. */
    static int initialized;

    if (!initialized) {
        initialized = 1;
        __do_global_ctors();
    }
}
