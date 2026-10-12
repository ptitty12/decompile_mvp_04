/* SN ProDG libm (newlib 1.8.2 fdlibm): __kernel_rem_pio2: the big-argument pi/2 reduction with the 2/pi table. Compiled as C++ through this wrapper, as in
 * emoose/re4 (src/lib/k_rem_pio2.cpp): g++ drops folded static consts defined in an included file
 * and keeps tables in small data, which is what SN's libm has. */
/* floor() is still called by its placeholder name (see s_floor.cpp). */
#define floor fn_80410634
#include "fdlibm/k_rem_pio2.c"
