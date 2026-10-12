#ifndef GAME_TU_800BCD38_DECLS_H
#define GAME_TU_800BCD38_DECLS_H

/*
 * Declarations used by game/tu_800BCD38..tu_800D1758 whose type or return type differs from
 * the ones other units declare for the same symbol (e.g. game/tu_800B5C68.cpp has its own
 * FEMgr / FEColor / void-returning versions). They live here instead of tu_800BCD38.h so a
 * unit that includes tu_800BCD38.h for its types is not forced to use these. Return types
 * matter for codegen (sched2 order), so the range's units keep their own.
 */
#include "game/tu_800BCD38.h"

extern "C" {
char* fn_8040B830(char* dst, const char* src, unsigned n); /* behaves like strncpy */
Unk800D244C_Vec4 fn_8014DBA0(int r, int g, int b, int a);
void fn_804031BC(char* dst, const char* src);
int fn_804089B4(char* dst, const char* fmt, ...);
Unk800B64BC_Mgr* fn_800B64BC(Unk800B64BC_Mgr* m);
}
extern void* lbl_8061977C;
extern Unk800B64BC_Mgr* lbl_8061A32C;

#endif
