/*
 * Front-end overlay code, .frontend_codeoverlay 0x804ABCBC-0x804AECD0 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/overlay.h"

struct UiObj;

extern "C" void fn_804AC114(UiObj* a);

extern "C" FE_OVERLAY void fn_804AC0AC(int a, UiObj* b)
{
    switch (a) {
    case 0:
        break;
    case 1:
        fn_804AC114(b);
        break;
    }
}

extern "C" void fn_804AC1C0(UiObj* a);

extern "C" FE_OVERLAY void fn_804AC0E0(int a, UiObj* b)
{
    switch (a) {
    case 0:
        break;
    case 1:
        fn_804AC1C0(b);
        break;
    }
}

struct Unk800C7B40_Data {
    int m0;
    int m4;
    int m8;
    char mC[16];
    int m1C;
    int m20;
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned b2 : 1;
    unsigned b3 : 1;
    unsigned b4 : 1;
    unsigned b5 : 1;
    unsigned b6 : 1;
    unsigned b7 : 1;
    unsigned b8 : 1;
    unsigned b9 : 1;
    unsigned b10 : 1;
    unsigned b11 : 1;
    unsigned b12 : 1;
    unsigned b13 : 1;
    unsigned b14 : 1;
    unsigned b15 : 1;
    short m26;
    short m28;
    short m2A;
    short m2C;
    short m2E;
    short m30;
    short m32;
    short m34;
    short m36;
    float m38;
};

struct Unk800C7B40_Widget : Unk800C7B40_Data {
    virtual ~Unk800C7B40_Widget();
    // BEGIN-SLOTS
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
    virtual void fn_vslot9(int a);
    virtual void fn_vslot10(int a);
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14(int a);
    virtual void fn_vslot15();
    virtual void fn_vslot16(int a);
    virtual void fn_vslot17();
    virtual void fn_vslot18(int a);
    virtual float fn_vslot19();
    virtual void fn_vslot20(float a);
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual Unk800C7B40_Widget* fn_vslot28(const char* name);
    virtual Unk800C7B40_Widget* fn_vslot29(const char* name);
    virtual Unk800C7B40_Widget* fn_vslot30(const char* name, int a);
    virtual int fn_vslot31();
    virtual Unk800C7B40_Widget* fn_vslot32(const char* name, int a);
    virtual Unk800C7B40_Widget* fn_vslot33(int a, int b);
    virtual const char* fn_vslot34();
    virtual void fn_vslot35();
    virtual void fn_vslot36();
    virtual void fn_vslot37(int a);
    virtual void fn_vslot38(int a);
    virtual void fn_vslot39();
    virtual void fn_vslot40(int a);
    virtual void fn_vslot41(int a);
    virtual void fn_vslot42();
    virtual void fn_vslot43(int a, int b, char* c, int d);
    virtual void fn_vslot44(int a, int b, char* c, int d);
    virtual void fn_vslot45();
    virtual void fn_vslot46();
    virtual void fn_vslot47(int a);
    virtual void fn_vslot48();
    virtual void fn_vslot49(int a);
    virtual void fn_vslot50();
    virtual void fn_vslot51();
    virtual void fn_vslot52();
    virtual void fn_vslot53();
    virtual void fn_vslot54();
    virtual void fn_vslot55();
    virtual void fn_vslot56();
    virtual void fn_vslot57();
    virtual int fn_vslot58();
    virtual int fn_vslot59();
    virtual int fn_vslot60();
    virtual int fn_vslot61();
    virtual void fn_vslot62();
    virtual void fn_vslot63();
    virtual void fn_vslot64();
    virtual void fn_vslot65();
    virtual void fn_vslot66();
    virtual void fn_vslot67(int a, int b);
    virtual void fn_vslot68(int a);
    virtual void fn_vslot69();
    virtual Unk800C7B40_Widget* fn_vslot70();
    virtual void fn_vslot71();
    virtual void fn_vslot72();
    virtual Unk800C7B40_Widget* fn_vslot73(int idx, int a);
    virtual void fn_vslot74();
    virtual void fn_vslot75();
    virtual void fn_vslot76();
    virtual void fn_vslot77();
    virtual void fn_vslot78();
    virtual void fn_vslot79(int a, int b);
    virtual void fn_vslot80(int a);
    virtual void fn_vslot81();
    virtual void fn_vslot82();
    virtual int fn_vslot83();
    virtual void fn_vslot84(int a, int b);
    virtual int fn_vslot85();
    virtual int fn_vslot86();
    virtual int fn_vslot87();
    virtual void fn_vslot88(int a);
    virtual void fn_vslot89(int a);
    virtual int fn_vslot90();
    virtual int fn_vslot91();
    virtual void fn_vslot92();
    virtual void fn_vslot93();
    virtual void fn_vslot94();
    virtual void fn_vslot95();
    virtual void fn_vslot96();
    virtual void fn_vslot97();
    virtual void fn_vslot98();
    virtual void fn_vslot99();
    virtual void fn_vslot100();
    virtual void fn_vslot101();
    virtual void fn_vslot102();
    virtual void fn_vslot103();
    virtual void fn_vslot104();
    virtual void fn_vslot105(int a);
    virtual void fn_vslot106();
    virtual void fn_vslot107();
    virtual void fn_vslot108();
    virtual void fn_vslot109();
    virtual void fn_vslot110();
    virtual void fn_vslot111();
    virtual void fn_vslot112();
    virtual void fn_vslot113();
    virtual void fn_vslot114();
    virtual void fn_vslot115();
    virtual void fn_vslot116();
    virtual void fn_vslot117();
    virtual void fn_vslot118();
    virtual void fn_vslot119();
    virtual void fn_vslot120();
    virtual void fn_vslot121();
    virtual void fn_vslot122();
    virtual void fn_vslot123();
    virtual void fn_vslot124();
    virtual void fn_vslot125();
    virtual void fn_vslot126();
    virtual void fn_vslot127();
    // END-SLOTS
    void SetVptr(const void* v) { *(const void**)((char*)this + 0x3C) = v; }
};

typedef Unk800C7B40_Widget FeW;

struct FeScrN : FeW {
    char pad40[0xF0];
    int m130;
    FeW* m134;
    FeW* m138;
    FeW* m13C;
    FeW* m140;
    FeW* m144;
    FeW* m148;
    FeW* m14C;
    FeW* m150;
    FeW* m154;
    FeW* m158;
    FeW* m15C;
    FeW* m160;
    FeW* m164;
    FeW* m168;
    FeW* m16C;
    FeW* m170;
    FeW* m174;
    FeW* m178;
    FeW* m17C;
    FeW* m180;
    FeW* m184;
    FeW* m188;
    FeW* m18C;
    FeW* m190;
};

extern "C" void fn_800ED254(void* x);

extern "C" void* fn_800C33D0();

extern "C" void fn_800C3BE0();

extern "C" FE_OVERLAY void fn_804AD830(FeScrN* x)
{
    fn_800ED254(x);
    fn_800C33D0();
    fn_800C3BE0();
}
