#ifndef GAME_TU_8035B60C_H
#define GAME_TU_8035B60C_H

/*
 * Shared types for the game tail 0x8035B60C..0x803606B0 (range 29).
 *
 * Array elements with a virtual destructor. Retail's nested-member destructors
 * (0x8035BBEC, 0x8035BDF8, 0x8035D87C, 0x8035DA94, 0x8035DB68, ...) destroy
 * member arrays with g++ 2.95's open-coded loop: `if (start != 0) { end = start +
 * n*size; if (end != start) do { end -= size; (*end->vptr[1])(end, 0); } while
 * (start != end); }`. Each VElemN below is one element type, N being its size;
 * its vptr sits in the last word. The classes never define the destructor, so
 * no vtable is emitted; the owning class stores retail's vtable address by hand
 * (a `const void*` member) because retail's vtables are data objects (lbl_).
 * Evidence: the loop shapes (start/end/stride, `lwz vptr; lha delta; lwz pfn`).
 */
#define VELEM(name, n) struct name { char pad[(n) - 4]; virtual ~name(); }
VELEM(VElem14, 0x14);
VELEM(VElem18, 0x18);
VELEM(VElem1C, 0x1C);
VELEM(VElem2C, 0x2C);
VELEM(VElem34, 0x34);
VELEM(VElem40, 0x40);
#undef VELEM

#endif
