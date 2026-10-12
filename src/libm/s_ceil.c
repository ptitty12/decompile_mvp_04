/* SN ProDG libm (newlib 1.8.2 fdlibm): ceil() (double). Compiled as C, as SN built its libm: a C
 * build keeps the file's unreferenced static consts in .sdata2, and MVP's .sdata2 has them in
 * link order (the re4 units' .cpp wrappers drop them; docs/sdk.md). re4 has no s_ceil. */
/* Game code still refers to this function by its placeholder name; the rename to ceil waits for
 * a project-wide pass over those sources. */
#define ceil fn_804103C0
#include "fdlibm/s_ceil.c"
