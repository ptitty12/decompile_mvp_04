/*
 * Shared types of the EA video/stream buffer code (0x8038BC58-0x803912F8): reconstructed from the
 * offsets the functions use; names are placeholders.
 */
#ifndef EALIB_TU_8038BC58_H
#define EALIB_TU_8038BC58_H

struct VdFilter {
    char pad0[0x70];
    float m70;
    float m74;
    float m78;
    float m7C;
    float m80;
    float m84;
    float m88;
    float m8C;
    float m90;
};

struct VdCb {
    int m0;
    int m4;
    int m8;
    void (*mC)(VdCb*, int, int);
};

class VdA {
public:
    int m0;
    int m4;
    int m8;
    VdA();
};

class VdB {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    VdB();
    VdB(int a, int b, int c, int d);
};

class VdC {
public:
    void* (*m0)(const char*, int, int, int, int);
    void (*m4)(void*);
    int m8;
    VdC();
    virtual ~VdC() {}
};
extern VdC lbl_80699B94;

/* Interface owned by a VdCbObj at +0x14 (vtable slots read by fn_8038E8A4..fn_8038E9D8). */
struct VdObj5 {
    virtual ~VdObj5();
    virtual void v2(void*);
    virtual int v3(int);
    virtual int v4();
    virtual float v5();
    virtual int v6();
};

/* Callback holder, flat view: m0 state, m4 cookie, m8 callback, m14 owned VdObj5 (vptr at +0x18). */
struct VdCbObj {
    int m0;
    int m4;
    void (*m8)(VdCbObj*, int, int*);
    int mC;
    int m10;
    VdObj5* m14;
};

extern "C" void fn_8038E8EC(VdCbObj* s);
extern "C" int fn_8038EA64(VdCbObj* h, int a);
extern "C" int fn_8038E9D8(VdCbObj* s, int a);
extern "C" int fn_8038E944(VdCbObj* s);
extern "C" float fn_8038E98C(VdCbObj* s);

/* Same object with its VdB sub-object at +4 (fn_8038E7D8 ctor, fn_8038E84C dtor). */
class VdD {
public:
    int m0;
    VdB m4;
    VdObj5* m14;
    virtual ~VdD();
    VdD(const VdB* s);
    void operator delete(void* p) { lbl_80699B94.m4(p); }
};

extern "C" void fn_8038D110(char* o);

struct VdRes;

struct VdClock {
    unsigned long long m0;
    unsigned long long m8;
    unsigned m10;
};

/* 64-bit clock (fn_80438628 returns the current time): m0 last time, m8 accumulated, m10 rate (0x1000 = 1.0).
 * Stream state: m0 resource (VdRes), m60 clock. */
struct VdStream {
    VdRes* m0;
    char pad4[0x60 - 4];
    VdClock* m60;
};

typedef VdStream I;

extern "C" int fn_8038E694(VdRes* o, int a);
extern "C" unsigned long long fn_80438628();


struct VdRes {
    int m0;
    void* m4;
    int m8;
    int mC;
    int m10;
};

struct VdBufs {
    char pad0[0x600];
    void* m600;
    void* m604;
};

/* Stream object: m0 owner holder, vptr at +4 (base vtable lbl_80605EC8, derived lbl_80605E88). */
class VdBase {
public:
    VdCbObj* m0;
    virtual ~VdBase() {}
};

class VdMain : public VdBase {
public:
    VdBufs* m8;
    char padC[0x40 - 0xC];
    unsigned m40;
    unsigned m44;
    float m48;
    int m4C;
    char pad50[4];
    int m54;
    int m58;
    int m5C;
    VdClock* m60;
    char pad64[4];
    VdCbObj* m68;
    int m6C;
    char pad70[0x78 - 0x70];
    int m78;
    virtual ~VdMain();
    void operator delete(void* p) { lbl_80699B94.m4(p); }
};

struct VdTile {
    unsigned m0;
    unsigned m4;
    unsigned m8;
    unsigned mC;
    unsigned m10;
    unsigned m14;
    unsigned m18;
};

#endif /* EALIB_TU_8038BC58_H */
