/*
 * EA gamelib (C:/mvp2004/libraries/gamelib: memory, datafile, animlib), built with
 * the game flags (cflags_game: -Os -G0 -ffloat-store),
 * .text 0x8038B938-0x8038BC58 (code-only unit, 38 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

#include "game/chooser.h"

struct DtorAt0 { const void* m; };

struct GlSub4 {
    int m0;
    int m4;
    int m8;
    int mC;
    inline int Used() const
    {
        int r = 0;
        if (mC != 0 || m4 != 0)
            r = 1;
        return r;
    }
};

struct GlNode {
    const void* m0;
    GlSub4 m4;
    char pad14[0x28c - 0x14];
    int m28C;
    int m290;
};

#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))

extern char lbl_806626C0[];
extern char lbl_80684D30[];
extern char lbl_80684D90[];
extern char lbl_80605A18[];
extern char lbl_80605A24[];
extern char lbl_80605A30[];
extern char lbl_80605A3C[];
extern char lbl_80605A48[];
extern char lbl_80605A50[];
extern int lbl_8069595C;
extern int lbl_80695960;
extern int lbl_80695964;
extern int lbl_80695968;
extern int lbl_80699B0C;
extern int lbl_80699B10;

extern "C" void fn_8037B424(void* p, int c);

extern "C" const char* fn_8038B998(DtorAt0*, int);
extern "C" const char* fn_8038BA64(DtorAt0*, int);
extern "C" const char* fn_8038BACC(DtorAt0*, int);
extern "C" const char* fn_8038BB44(DtorAt0*, int);
extern "C" const char* fn_8038BB7C(DtorAt0*, int);
extern "C" const char* fn_8038BBCC(DtorAt0*, int);

extern "C" void fn_8038B938(DtorAt0* s, int chrg)
{
    fn_8038B998(s, chrg);
}

extern "C" int fn_8038B958()
{
    return lbl_8069595C;
}

extern "C" int fn_8038B964(GlNode* self)
{
    return *(int*)((char*)self + 0x14);
}

extern "C" int fn_8038B96C(GlNode* self)
{
    return self->m4.Used();
}

extern "C" const char* fn_8038B998(DtorAt0*, int)
{
    return lbl_80605A18;
}

extern "C" void fn_8038B9A4(void* self, int c)
{
    PUT(0x0, lbl_80684D90);
    ((Unk80384F28*)((char*)self + 0x14))->Unk80384F28::~Unk80384F28();
    ((Unk80384F28*)((char*)self + 0x4))->Unk80384F28::~Unk80384F28();
    PUT(0x0, lbl_806626C0);
    fn_8037B424(self, c);
}

extern "C" void fn_8038BA0C(DtorAt0* s, int chrg)
{
    fn_8038BA64(s, chrg);
}

extern "C" int fn_8038BA2C()
{
    return lbl_80695960;
}

extern "C" int fn_8038BA38(GlNode* self)
{
    return self->m4.Used();
}

extern "C" const char* fn_8038BA64(DtorAt0*, int)
{
    return lbl_80605A24;
}

extern char lbl_80684D30[];

extern "C" void fn_8038BA70(DtorAt0* s, int chrg)
{
    s->m = lbl_80684D30;
    fn_8037B424(s, chrg);
}

extern "C" void fn_8038BAA0(DtorAt0* s, int chrg)
{
    fn_8038BACC(s, chrg);
}

extern "C" int fn_8038BAC0()
{
    return lbl_80695964;
}

extern "C" const char* fn_8038BACC(DtorAt0*, int)
{
    return lbl_80605A30;
}

extern "C" void fn_8038BAD8()
{
}

extern "C" void fn_8038BADC()
{
}

extern "C" int fn_8038BAE0(GlNode* self)
{
    return *(int*)((char*)self + 0x14);
}

extern "C" void fn_80383E74(void* self);

extern "C" int fn_8038BAE8(void* self)
{
    fn_80383E74(self);
    return *(int*)((char*)self + 0x18);
}

extern "C" void fn_8038BB18(DtorAt0* s, int chrg)
{
    fn_8038BB44(s, chrg);
}

extern "C" int fn_8038BB38()
{
    return lbl_80695968;
}

extern "C" const char* fn_8038BB44(DtorAt0*, int)
{
    return lbl_80605A3C;
}

extern "C" void fn_8038BB50(DtorAt0* s, int chrg)
{
    fn_8038BB7C(s, chrg);
}

extern "C" int fn_8038BB70()
{
    return lbl_80699B0C;
}

extern "C" const char* fn_8038BB7C(DtorAt0*, int)
{
    return lbl_80605A48;
}

extern "C" int fn_8038BB88()
{
    return 1;
}

extern "C" void fn_8038BB90()
{
}

extern "C" void fn_8038BB94()
{
}

extern "C" void fn_8038BB98(DtorAt0* s, int chrg)
{
    fn_8038BBCC(s, chrg);
}

extern "C" int fn_8038BBB8()
{
    return lbl_80699B10;
}

extern "C" int fn_8038BBC4(GlNode* self)
{
    return *(int*)((char*)self + 0x8);
}

extern "C" const char* fn_8038BBCC(DtorAt0*, int)
{
    return lbl_80605A50;
}

extern "C" int fn_8038BBD8(GlNode* self)
{
    return self->m28C;
}

extern "C" void fn_8038BBE0(GlNode* self, int v)
{
    self->m28C = v;
}

extern "C" int fn_8038BBE8(GlNode* self)
{
    return self->m290;
}

extern "C" void fn_8038BBF0(GlNode* self, int v)
{
    self->m290 = v;
}

extern "C" char* fn_8038BBF8(char* self)
{
    return self + 0x294;
}

extern "C" void fn_8038B630(int a, int b);

extern "C" void fn_8038BC00()
{
    fn_8038B630(1, 0xFFFF);
}

extern "C" void fn_8038BC2C()
{
    fn_8038B630(0, 0xFFFF);
}
