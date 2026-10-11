/*
 * Types shared by game/tu_80331C60.cpp .. game/tu_8033FAFC.cpp (reconstructed,
 * placeholder names; nothing here comes from original headers).
 *
 * This region is the debug-menu system. A menu object holds a pointer array of
 * items at +0 (cursor at +0x174, count at +0x178), a vptr at +0x2DC (vtable
 * lbl_80666A18 for the base menu, one per derived menu). Items are 0x64/0x68
 * byte objects with a vptr at +8 (base vtable lbl_80666EC0). Evidence: the
 * menu ctors (fn_80331DB8, fn_80332978, ...), fn_80330ACC (append item) and
 * fn_8033FDC8 (item[cursor] virtual calls through slots 3 and 2).
 * Classes are written as extern "C" functions taking the object explicitly.
 */
#ifndef GAME_TU_80331C60_H
#define GAME_TU_80331C60_H

void* operator new(unsigned int size, int heap);
extern "C" void fn_80377408(void* p); /* __builtin_delete */

/* Menu item base: vptr at +8, slots called by the menu (slot N at vtable +8N). */
class MItem {
public:
    char pad0[0x8];
    virtual ~MItem();
    virtual int s2();
    virtual int s3();
    virtual int s4();
};

/* Menu base: item pointers at +0, cursor +0x174, count +0x178, vptr +0x2DC. */
struct Menu {
    MItem* items[93];
    int m174;
    int m178;
    char pad17C[0x80];
    int m1FC;
    int m200;
    int m204;
    int m208;
    float m20C;
    char pad210[0xC8];
    int m2D8;
    const void* m2DC;
};

/* A menu with embedded items starting at +0x2E0 (each 0x64 bytes or more). */
struct MenuD : Menu {
    const void* m2E0;
    int m2E4;
    const void* m2E8;
};

/* Menu helpers and item constructors (all in not-yet-matched units). Evidence:
 * fn_80330ACC appends to items[] and bumps m178; fn_8032E7C0 / fn_8032EB84 /
 * fn_8032FA3C initialise the item at r3 (vptr +8) and return it. */
extern "C" {
void fn_80330ACC(Menu* m, MItem* it);
void fn_80330870(Menu* m, int c);

void fn_80330778(Menu* m, int c);
void fn_8032F574(MItem* it, int idx);
MItem* fn_8032FA3C(void* mem, const char* name, const void* a, const void* b, const void* c, int d, int e);
MItem* fn_8032E7C0(void* mem, const char* name, float* val, float* ref, float a, float b, float c);
MItem* fn_8032EB84(void* mem, const char* name, int* val, int a, int b, int c, int d);
}

/* Game manager chain used by the debug menus (lbl_8061B8C0 -> +8 -> +0x6F8 -> +0x10/+0x14). */
struct UnkC128 { char pad0[0xC]; int mC; char pad10[4]; int m14[22]; int m6C; int m70; char pad74[0xB4]; int m128; };
struct UnkB14 { char pad0[0x114]; int m114; char pad118[0xE60]; int mF78; };
struct UnkB6F8 { char pad0[0x10]; UnkC128* m10; UnkB14* m14; };
struct Unk3B4 { char pad0[0x1C]; int m1C; };
struct Unk404 { char pad0[4]; float m4; float m8; };
struct Unk8017DD64_T { char pad0[0x3B0]; void* m3B0; Unk3B4* m3B4; char pad3B8[0x4C]; Unk404* m404; };
struct UnkObj65C { char pad0[0x60]; float m60; float m64; float m68; };
struct UnkMgr8 { char pad0[0x4C]; unsigned int m4C; char pad50[0x65C - 0x50]; UnkObj65C* m65C[13]; char pad690[0x68]; UnkB6F8* m6F8; char pad6FC[4]; Unk8017DD64_T* m700; char pad704[0xC]; void* m710; char pad714[0x24]; void* m738; };
struct UnkGm { char pad0[0x8]; UnkMgr8* m8; UnkMgr8* mC; char pad10[0x14]; int m24; };
/* result of fn_801A4CE8(mgr, 1): option record with fields at +0xC, +0x10, +0xA0 */
struct UnkOpt { char pad0[0xC]; int mC; int m10; char pad14[0x8C]; int mA0; };


/* Value item: a pointer to the live value at +0x48, or the value stored in the item at +0x4C. */
struct MIV { char pad0[0x48]; int* m48; int m4C; };
inline int GetV(MIV* i)
{
    if (i->m48)
        return *i->m48;
    return i->m4C;
}
inline int GetV2(MIV* i)
{
    if (!i->m48)
        return i->m4C;
    return *i->m48;
}
inline float GetVF2(MIV* i)
{
    if (!i->m48)
        return *(float*)&i->m4C;
    return *(float*)i->m48;
}
inline void SetVF(MIV* i, float v)
{
    if (!i->m48)
        *(float*)&i->m4C = v;
    else
        *(float*)i->m48 = v;
}
inline void SetV(MIV* i, int v)
{
    if (i->m48)
        *i->m48 = v;
    else
        i->m4C = v;
}
/* embedded item vptr resets in the dtors */
inline void SetVp(void* p, int off, const void* v) { *(const void**)((char*)p + off) = v; }
inline MIV* IAt(Menu* p, int off) { return (MIV*)((char*)p + off); }


extern UnkGm* lbl_8061B8C0;

/* Button item (0x4C bytes): +0/+4 floats, vptr at +8, +0xC flag, callback at +0x48. Evidence: the
 * inline base-item ctor in fn_80332978 stores m0, m4, vptr and mC, then fn_8032D868 sets the
 * name and fn_8033FBD8 the callback. */
struct ItemB { float m0; float m4; const void* m8; int mC; char pad10[0x38]; void* m48; };

extern "C" void fn_803E4A50(void* p);
/* Base-menu constructor body, as inlined into the derived menu constructors
 * (fn_8033648C, fn_80334BC0, ...): the vptr is set to the base vtable before the
 * +0x210 member is constructed, then to the derived one. */
extern const char lbl_80666A18[];
inline void MenuInit(Menu* p, int a)
{
    p->m174 = 0;
    p->m178 = 0;
    p->m1FC = 0;
    p->m200 = a;
    p->m2DC = lbl_80666A18;
    fn_803E4A50((char*)p + 0x210);
    p->m2D8 = 0;
}


#endif
