/* SN ProDG libm (newlib 1.8.2 fdlibm): sinf(). Compiled as C++ through this wrapper, as in
 * emoose/re4 (src/lib/sf_sin.cpp): g++ drops folded static consts defined in an included file
 * and keeps tables in small data, which is what SN's libm has. */
/* Game code still refers to this function by its placeholder name; the rename to sinf waits for
 * a project-wide pass over those sources. */
#define sinf fn_8041171C
#include "fdlibm/sf_sin.c"
