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

#endif
