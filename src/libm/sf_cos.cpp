/* SN ProDG libm (newlib 1.8.2 fdlibm): cosf(). Compiled as C++ through this wrapper, as in
 * emoose/re4 (src/lib/sf_cos.cpp): g++ drops folded static consts defined in an included file
 * and keeps tables in small data, which is what SN's libm has. */
/* Game code still refers to this function by its placeholder name; the rename to cosf waits for
 * a project-wide pass over those sources. */
#define cosf fn_80411554
#include "fdlibm/sf_cos.c"
