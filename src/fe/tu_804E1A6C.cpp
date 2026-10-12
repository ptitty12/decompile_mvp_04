/*
 * Front-end overlay code, .frontend_codeoverlay 0x804E1A6C-0x804E5180 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#include "game/fe_804E02E0.h"

extern "C" FE_OVERLAY int fn_804E1B34(FeWf184* self)
{
    self->m184->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E1C38(FeWf184* self)
{
    self->m184->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2B68(FeW138* self)
{
    self->m138->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2BF8(FeW138* self)
{
    self->m138->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E2CE0(FeWf13C* self)
{
    self->m13C->v57();
    return 0;
}

extern "C" FE_OVERLAY int fn_804E2DC4(FeWf13C* self)
{
    self->m13C->v55();
    return 0;
}

extern "C" FE_OVERLAY void fn_804E3154(void* self, int a)
{
    fn_800ECAA4(self);
}

extern "C" FE_OVERLAY int fn_804E3C3C(FeWf13C* self)
{
    self->m13C->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3CC4(FeWf13C* self)
{
    self->m13C->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3D00(FeWf140b* self)
{
    self->m140->v40(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3D40(FeWf140* self)
{
    self->m140->v41();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3D7C(FeWf140b* self)
{
    self->m140->v38(1);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E3DBC(FeWf140* self)
{
    self->m140->v39();
    return 1;
}
