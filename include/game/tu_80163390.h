/*
 * Types for tu_80163390.cpp (script event handlers). Reconstructed: each handler
 * receives a record of its event type, so the layouts below differ per handler
 * (m8/mC are an int in one and a pointer in another).
 */
#ifndef GAME_TU_80163390_H
#define GAME_TU_80163390_H

#include "game/tu_8015AA94.h"

/* Object whose animation id is at +0x458 (read through event records). */
struct Unk80165578_Obj {
    char pad0[0x458];
    int m458;
};

struct Unk80165328_Evt {          /* fn_80165328 */
    char pad0[0x10];
    float m10;
};

struct Unk801654F0_Evt {          /* fn_801654F0, fn_80165738 */
    char pad0[8];
    int m8;
};

struct Unk80165578_Evt {          /* fn_80165578 */
    char pad0[8];
    int m8;
    int mC;
};

struct Unk80165790_Evt {          /* fn_80165790 */
    char pad0[8];
    Unk80165578_Obj* m8;
    int mC;
};

struct Unk801657EC_Evt {          /* fn_801657EC */
    char pad0[8];
    int m8;
};

struct Unk80165834_Evt {          /* fn_80165834, fn_80165908 */
    char pad0[8];
    int m8;
    Unk80165578_Obj* mC;
    char pad10[8];
    float m18;
};

struct Unk80165884_Evt {          /* fn_80165884 */
    char pad0[8];
    int m8;
    char padC[4];
    int m10;
};

struct Unk80165AF4_Evt {          /* fn_80165AF4 */
    char pad0[8];
    Unk80165578_Obj* m8;
    int mC;
};

struct Unk80165B68_Evt {          /* fn_80165B68 */
    char pad0[8];
    Unk80165578_Obj* m8;
    char padC[0x18 - 0xC];
    int m18;
    int m1C;
};

struct Unk80165BE0_Evt {          /* fn_80165BE0 */
    char pad0[8];
    int m8;
    int mC;
    char pad10[4];
    unsigned char m14;
    char pad15[3];
    int m18;
    float m1C;
};

#endif
