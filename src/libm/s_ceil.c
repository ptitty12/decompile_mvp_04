/* SN ProDG newlib/fdlibm s_ceil: the writable huge object and zero literal
 * occupy the retail small-data block. Keep the reference compiled as C. */
/* Game code still refers to this function by its placeholder name; the rename to ceil waits for
 * a project-wide pass over those sources. */
#define ceil fn_804103C0
#include "fdlibm/s_ceil.c"
