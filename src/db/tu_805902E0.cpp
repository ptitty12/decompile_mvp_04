/*
 * Database overlay code, .database_codeoverlay 0x805902E0-0x8059377C (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

struct Unk8007FF8C_CI {
    char pad0[8];
    unsigned short* m8;
};

struct Unk8007FF8C_EI {
    char pad0[0x800];
    int m800;
};

struct Unk8007FF8C_Item {
    char pad0[0x18];
};

struct Unk8007FF8C_List {
    unsigned m0;
    Unk8007FF8C_Item m4[1];
};

struct Unk8007FF8C_Slot {
    char pad0[0x20];
};

struct Unk8007FF8C_G {
    char pad0[0xC];
    Unk8007FF8C_CI* mC;
    char pad10[0xC];
    Unk8007FF8C_EI* m1C;
    Unk8007FF8C_List* m20;
    Unk8007FF8C_Slot* m24;
    void* m28;
    char pad2C[0x1F0 - 0x2C];
    int m1F0;
};

typedef Unk8007FF8C_G G;

extern "C" void fn_80596E3C(void* p);

extern "C" DB_OVERLAY void fn_8059124C(G* self)
{
    fn_80596E3C(self->m28);
}

extern "C" void fn_80596FCC(void* p);

extern "C" DB_OVERLAY void fn_80591378(G* self)
{
    fn_80596FCC(self->m28);
}
