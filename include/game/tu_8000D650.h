/*
 * Types for game/tu_8000D650.cpp (reconstructed, placeholder names).
 * Nothing here comes from original headers.
 */
#ifndef GAME_TU_8000D650_H
#define GAME_TU_8000D650_H

/* One element of the 4-element, 12-byte-stride array that fn_80439618 fills;
 * fn_8000D6D4 reads the halfword at +0 (tests mask 0x200) and the byte at +0xA
 * (must be 0). The layout and the mask match a controller-state record
 * (buttons at +0, error code at +0xA), but nothing here proves the name, so it
 * stays a placeholder. Evidence: fn_8000D6D4 (0x8000D740 loop, stride 0xC). */
struct Unk8000D6D4_Pad {
    unsigned short m0;
    char pad2[8];
    unsigned char mA;
    char padB;
};

#endif
