/* newlib 1.8.2 libc/stdlib/atexit.c, as built into SN ProDG's libc (MVP links it, re4 does not; written
 * here in the form of the other newlib units). */
#include "newlib_stdio.h"

/* Retail calls the C++ GC allocation wrapper in game/tu_8000D650.cpp. */
extern void *fn_8000E5BC(int);

/* Registers fn to run at exit: 32 per block, the first block inside the reent, more from the GC allocation wrapper. */
extern "C" int atexit(void (*fn)(void))
{
    register struct _atexit *p;

    if ((p = _REENT->_atexit) == NULL)
        _REENT->_atexit = p = &_REENT->_atexit0;
    if (p->_ind >= _ATEXIT_SIZE) {
        if ((p = (struct _atexit *)fn_8000E5BC(sizeof *p)) == NULL)
            return -1;
        p->_ind = 0;
        p->_next = _REENT->_atexit;
        _REENT->_atexit = p;
    }
    p->_fns[p->_ind++] = fn;
    return 0;
}
