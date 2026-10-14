/* Copy hook stored at lbl_80626518. The retail default is memcpy (0x8040B190),
 * whose implementation uses (void*, const void*, size_t) and returns void*.
 * fn_803B5A18 installs the hook; packet-copy consumers use the same signature.
 */
#ifndef SND_COPY_CALLBACK_H
#define SND_COPY_CALLBACK_H

#include "libc/stddef.h"

typedef void* (*SndCopyCallback)(void* destination, const void* source, size_t count);
extern SndCopyCallback lbl_80626518;
extern "C" int fn_803B5A18(SndCopyCallback callback);

#endif
