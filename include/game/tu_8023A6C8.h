#ifndef GAME_TU_8023A6C8_H
#define GAME_TU_8023A6C8_H

#include "game/tu_802362A8.h"

/*
 * Rating-table classes at 0x8023BD44-0x8023D9C4 (placeholders named by first function).
 *
 * Unk8023BE30: base with an int at +0 and a vptr at +4 (ctor 0x8023BE30 stores
 * m0 = 0 and the vtable 0x80661458). The families fn_8023BE4C/BEEC/BF8C and
 * fn_8023C1E8/C254/C2C0 call virtual slots at vtable offsets 8, 0x10, 0x18, 0x20,
 * 0x28, 0x30 (lha delta / lwz pfn pairs), so the class declares v08..v30 in that order.
 * Three derived classes: 0x8023C388 (vptr 0x80661418, two 0x3C-byte Entry rows at
 * +8 and +0x44), 0x8023C4C4 (vptr 0x806613D8) and 0x8023C744 (vptr 0x80661398,
 * 15 ints at +0x10 cleared by fn_8023C4A8).
 */
class Unk8023BE30 {
public:
    int m0;
    Unk8023BE30();
    virtual int v08();
    virtual int v10(int a, int b, int c);
    virtual int v18(int a, int b, int c);
    virtual int v20(int a, int b, int c);
    virtual int v28(int a, int b, int c);
    virtual int v30();
    int fn_8023BD88(int k);
    int fn_8023BDF0(int k);
    int fn_8023BE08(int k);
    int fn_8023BE4C(int a, int b);
    int fn_8023BEEC(int a, int b);
    int fn_8023BF8C(int a, int b);
    int fn_8023C02C(int a, int b, int c);
    int fn_8023C084(int a, int b, int c);
    int fn_8023C0DC(int a, int b, int c);
    void fn_8023C1E8(int a, int* p, int c, int d);
    void fn_8023C254(int a, int* p, int c, int d);
    void fn_8023C2C0(int a, int* p, int c, int d);
    int fn_8023C1D8();
    void fn_8023C1E0(int v);
};

struct Unk8023C32C_Row {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    void fn_8023C32C();
};

int fn_8023C134(int k);
int fn_8023C18C(int v);
void fn_8023C4A8(int* p);

class Unk8023C388 : public Unk8023BE30 {
public:
    virtual int v30();
    Unk8023C388();
    Unk8023C32C_Row m8;
    Unk8023C32C_Row m44;
};

class Unk8023C4C4 : public Unk8023BE30 {
public:
    virtual int v30();
    Unk8023C4C4();
    int m8;
    int mC;
    int fn_8023C3E0(int a, int b);
    int fn_8023C414(int a, int unused, int c);
    void fn_8023C490(int a, int b, int d);
};

class Unk8023C744 : public Unk8023BE30 {
public:
    virtual int v30();
    Unk8023C744();
    int m8;
    int mC;
    int m10[15];
    void fn_8023C794();
    int fn_8023C730();
    int fn_8023C6C4(int i);
    void fn_8023C6F8(int i, int v);
    int fn_8023C620(int i, int d);
    int fn_8023C7B8(int i, int d);
};

#endif
