/* Imported from emoose/re4 @ feb6805b (src/game/printf.c). newlib 1.8.2 as built into SN ProDG's libc. */
/* newlib 1.8.2 libc/stdio/printf.c (_printf_r was dead-stripped) */
#include "newlib_stdio.h"

/* Reentrant printf: formats into the reent's stdout. */


/* printf onto stdout. */
int printf(const char *fmt, ...)
{
    int ret;
    va_list ap;

    va_start(ap, fmt);
    _stdout_r(_REENT)->_data = _REENT;
    ret = vfprintf(_stdout_r(_REENT), fmt, ap);
    va_end(ap);
    return ret;
}
