#ifndef GAME_DB_RECORD_8052DD58_H
#define GAME_DB_RECORD_8052DD58_H

/* Shared 0x18-byte database record; declarations retained from tu_8052A220.h.
 * The vptr is at +0x14. Only a stream pointer is needed for the serializer slot. */
struct Unk80070DDC_Stream;

struct Unk8052DD58_Bits {
    unsigned p : 2;
    unsigned a : 6;
    unsigned e : 6;
    unsigned f : 6;
    unsigned g : 6;
    unsigned h : 6;
};
struct Unk8052DD58_EntData {
    int m0;
    int m4;
    int m8;
    Unk8052DD58_Bits mC;
    unsigned short m10;
    unsigned short m12;
};
struct Unk8052DD58_Ent : Unk8052DD58_EntData {
    virtual void v08();
    virtual void v10(int a, Unk80070DDC_Stream* io);
};

#endif
