#ifndef GAME_TU_80061C6C_H
#define GAME_TU_80061C6C_H

#include "game/tu_8005DF2C.h"
#include "game/tu_8005EDCC.h"
#include "game/tu_8005F4E4.h"
#include "game/tu_80060250.h"

/*
 * 0x80061C6C..0x80063648: action handlers void f(A*, O*, Ctx*) (see
 * tu_80060F94.h). Most of them call a run of one-argument Ctx getters
 * (fn_8001D218, fn_8001D42C, fn_8001EDE4, ...) and pass the results, in
 * argument order, to a consumer; the arguments are evaluated left to right.
 */


#endif
