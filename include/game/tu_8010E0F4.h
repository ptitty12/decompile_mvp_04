/*
 * Types shared by game/tu_8010E0F4.cpp .. game/tu_801287AC.cpp (0x8010E0F4..0x8012C8CC;
 * reconstructed, placeholder names; nothing here comes from original headers).
 *
 * The code is the methods of front-end "screen" classes derived from the widget base
 * (base ctor fn_800EC648, vptr at +0x3C). Their vtables live in .data, so the methods are
 * written as extern "C" functions taking the object explicitly; the vptr of a derived
 * object is written through SetVptr(). fn_vslotN = vtable slot N (virtual N is at +8N);
 * signatures are filled in only where a call site proves them.
 */
#ifndef GAME_TU_8010E0F4_H
#define GAME_TU_8010E0F4_H

void* operator new(unsigned int size, int heap);
extern int lbl_806EF9B4;

/* Data part of the widget base (size 0x3C; the vptr follows at +0x3C).
 * +0x24 is a word of flag bits (b0 = MSB) whose low half overlaps m26. */
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

// GEN-CLASSES-BEGIN
struct Unk800C7B40_Widget;
struct UnkLabel;
struct UnkSubData {
    char pad0[0x24];
};
/* Virtual part of the widget base; data that follows the vptr (+0x40 on) belongs to the
 * derived classes. Slots 2..127; unproven signatures are left as `void f()`. */
struct Unk800C7B40_Widget : Unk800C7B40_Data {
    virtual ~Unk800C7B40_Widget();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
    virtual void fn_vslot9(int a);
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14(int a);
    virtual void fn_vslot15();
    virtual void fn_vslot16(int a);
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual void fn_vslot28();
    virtual Unk800C7B40_Widget* fn_vslot29(const char* name);
    virtual Unk800C7B40_Widget* fn_vslot30(const char* name, int a);
    virtual void fn_vslot31();
    virtual Unk800C7B40_Widget* fn_vslot32(const char* name, int a);
    virtual Unk800C7B40_Widget* fn_vslot33(int a, int b);
    virtual void fn_vslot34();
    virtual void fn_vslot35();
    virtual void fn_vslot36();
    virtual void fn_vslot37();
    virtual void fn_vslot38(int a);
    virtual void fn_vslot39();
    virtual void fn_vslot40(int a);
    virtual void fn_vslot41();
    virtual void fn_vslot42(int a);
    virtual void fn_vslot43();
    virtual void fn_vslot44(int a);
    virtual void fn_vslot45();
    virtual void fn_vslot46();
    virtual void fn_vslot47();
    virtual void fn_vslot48();
    virtual void fn_vslot49();
    virtual void fn_vslot50();
    virtual void fn_vslot51();
    virtual void fn_vslot52();
    virtual void fn_vslot53();
    virtual void fn_vslot54();
    virtual void fn_vslot55();
    virtual void fn_vslot56();
    virtual void fn_vslot57();
    virtual void fn_vslot58();
    virtual void fn_vslot59();
    virtual int fn_vslot60();
    virtual void fn_vslot61();
    virtual void fn_vslot62();
    virtual void fn_vslot63();
    virtual void fn_vslot64();
    virtual void fn_vslot65();
    virtual void fn_vslot66();
    virtual void fn_vslot67(int a);
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
    virtual void fn_vslot79();
    virtual void fn_vslot80(int a);
    virtual void fn_vslot81();
    virtual void fn_vslot82();
    virtual void fn_vslot83();
    virtual void fn_vslot84(int a);
    virtual void fn_vslot85();
    virtual void fn_vslot86();
    virtual void fn_vslot87();
    virtual int fn_vslot88();
    virtual void fn_vslot89();
    virtual void fn_vslot90();
    virtual void fn_vslot91();
    virtual void fn_vslot92();
    virtual int fn_vslot93(int a, int b);
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
    virtual void fn_vslot105();
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
    void SetVptr(const void* v) { *(const void**)((char*)this + 0x3C) = v; }
};

/* Text-label widget (same data part and vptr offset as the base, own slot table): slot 30
 * sets the text (fn_8011A0A4 passes a char buffer). */
struct UnkLabel : Unk800C7B40_Data {
    virtual ~UnkLabel();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8();
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17(int a);
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual void fn_vslot28(const void* v);
    virtual void fn_vslot29(const char* s);
    virtual void fn_vslot30(const char* s);
    virtual int fn_vslot31();
    virtual void fn_vslot32();
    virtual void fn_vslot33();
    virtual void fn_vslot34();
    virtual void fn_vslot35();
    virtual void fn_vslot36();
    virtual void fn_vslot37();
    virtual void fn_vslot38();
    virtual void fn_vslot39();
    virtual void fn_vslot40();
    virtual void fn_vslot41();
    virtual void fn_vslot42();
    virtual void fn_vslot43();
    virtual void fn_vslot44();
    virtual void fn_vslot45();
    virtual void fn_vslot46();
    virtual void fn_vslot47();
    virtual void fn_vslot48();
    virtual void fn_vslot49();
    virtual void fn_vslot50();
    virtual void fn_vslot51();
    virtual void fn_vslot52();
    virtual void fn_vslot53();
    virtual void fn_vslot54();
    virtual void fn_vslot55();
    virtual void fn_vslot56();
    virtual void fn_vslot57();
    virtual void fn_vslot58();
    virtual void fn_vslot59();
    virtual void fn_vslot60();
    virtual void fn_vslot61();
    virtual void fn_vslot62();
    virtual void fn_vslot63();
    virtual void fn_vslot64();
    virtual void fn_vslot65();
    virtual void fn_vslot66();
    virtual void fn_vslot67();
    virtual void fn_vslot68();
    virtual void fn_vslot69();
    virtual void fn_vslot70();
    virtual void fn_vslot71();
    virtual void fn_vslot72();
    virtual void fn_vslot73();
    virtual void fn_vslot74();
    virtual void fn_vslot75();
    virtual void fn_vslot76();
    virtual void fn_vslot77();
    virtual void fn_vslot78();
    virtual void fn_vslot79();
    virtual void fn_vslot80();
    virtual void fn_vslot81();
    virtual void fn_vslot82();
    virtual void fn_vslot83();
    virtual void fn_vslot84();
    virtual void fn_vslot85();
    virtual void fn_vslot86();
    virtual void fn_vslot87();
    virtual void fn_vslot88();
    virtual void fn_vslot89();
    virtual void fn_vslot90();
    virtual void fn_vslot91();
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
    virtual void fn_vslot105();
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
    void SetVptr(const void* v) { *(const void**)((char*)this + 0x3C) = v; }
};

/* Member object of a widget (e.g. at +0x98 / +0xDC) with its own vptr at +0x24; reached through a pointer, so its
 * calls dispatch through the vtable. Slot 5 gets a value, 6/8 set one, 20 sets a pair. */
struct UnkSub : UnkSubData {
    virtual ~UnkSub();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual int fn_vslot5();
    virtual void fn_vslot6(int a);
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
    virtual void fn_vslot9();
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14();
    virtual void fn_vslot15();
    virtual void fn_vslot16();
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20(int a, int b);
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual void fn_vslot28();
    virtual void fn_vslot29();
    virtual void fn_vslot30();
    virtual void fn_vslot31();
    virtual void fn_vslot32();
    virtual void fn_vslot33();
    virtual void fn_vslot34();
    virtual void fn_vslot35();
    virtual void fn_vslot36();
    virtual void fn_vslot37();
    virtual void fn_vslot38();
    virtual void fn_vslot39();
    virtual void fn_vslot40();
    virtual void fn_vslot41();
    virtual void fn_vslot42();
    virtual void fn_vslot43();
    virtual void fn_vslot44();
    virtual void fn_vslot45();
    virtual void fn_vslot46();
    virtual void fn_vslot47();
    virtual void fn_vslot48();
    virtual void fn_vslot49();
    virtual void fn_vslot50();
    virtual void fn_vslot51();
    virtual void fn_vslot52();
    virtual void fn_vslot53();
    virtual void fn_vslot54();
    virtual void fn_vslot55();
    virtual void fn_vslot56();
    virtual void fn_vslot57();
    virtual void fn_vslot58();
    virtual void fn_vslot59();
    virtual void fn_vslot60();
    virtual void fn_vslot61();
    virtual void fn_vslot62();
    virtual void fn_vslot63();
    virtual void fn_vslot64();
    virtual void fn_vslot65();
    virtual void fn_vslot66();
    virtual void fn_vslot67();
    virtual void fn_vslot68();
    virtual void fn_vslot69();
    virtual void fn_vslot70();
    virtual void fn_vslot71();
    virtual void fn_vslot72();
    virtual void fn_vslot73();
    virtual void fn_vslot74();
    virtual void fn_vslot75();
    virtual void fn_vslot76();
    virtual void fn_vslot77();
    virtual void fn_vslot78();
    virtual void fn_vslot79();
    virtual void fn_vslot80();
    virtual void fn_vslot81();
    virtual void fn_vslot82();
    virtual void fn_vslot83();
    virtual void fn_vslot84();
    virtual void fn_vslot85();
    virtual void fn_vslot86();
    virtual void fn_vslot87();
    virtual void fn_vslot88();
    virtual void fn_vslot89();
    virtual void fn_vslot90();
    virtual void fn_vslot91();
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
    virtual void fn_vslot105();
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
};

/* The widget base seen by callers that pass two arguments to slot 84 (same vtable layout as Unk800C7B40_Widget;
 * the one-argument callers see slot 84 through Unk800C7B40_Widget). */
struct UnkWidgetB : Unk800C7B40_Data {
    virtual ~UnkWidgetB();
    virtual void fn_vslot2();
    virtual void fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual void fn_vslot6();
    virtual void fn_vslot7();
    virtual void fn_vslot8(int a);
    virtual void fn_vslot9(int a);
    virtual void fn_vslot10();
    virtual void fn_vslot11();
    virtual void fn_vslot12();
    virtual void fn_vslot13();
    virtual void fn_vslot14(int a);
    virtual void fn_vslot15();
    virtual void fn_vslot16(int a);
    virtual void fn_vslot17();
    virtual void fn_vslot18();
    virtual void fn_vslot19();
    virtual void fn_vslot20();
    virtual void fn_vslot21();
    virtual void fn_vslot22();
    virtual void fn_vslot23();
    virtual void fn_vslot24();
    virtual void fn_vslot25();
    virtual void fn_vslot26();
    virtual void fn_vslot27();
    virtual void fn_vslot28();
    virtual Unk800C7B40_Widget* fn_vslot29(const char* name);
    virtual Unk800C7B40_Widget* fn_vslot30(const char* name, int a);
    virtual void fn_vslot31();
    virtual Unk800C7B40_Widget* fn_vslot32(const char* name, int a);
    virtual Unk800C7B40_Widget* fn_vslot33(int a, int b);
    virtual void fn_vslot34();
    virtual void fn_vslot35();
    virtual void fn_vslot36();
    virtual void fn_vslot37();
    virtual void fn_vslot38(int a);
    virtual void fn_vslot39();
    virtual void fn_vslot40(int a);
    virtual void fn_vslot41();
    virtual void fn_vslot42(int a);
    virtual void fn_vslot43();
    virtual void fn_vslot44(int a);
    virtual void fn_vslot45();
    virtual void fn_vslot46();
    virtual void fn_vslot47();
    virtual void fn_vslot48();
    virtual void fn_vslot49();
    virtual void fn_vslot50();
    virtual void fn_vslot51();
    virtual void fn_vslot52();
    virtual void fn_vslot53();
    virtual void fn_vslot54();
    virtual void fn_vslot55();
    virtual void fn_vslot56();
    virtual void fn_vslot57();
    virtual void fn_vslot58();
    virtual void fn_vslot59();
    virtual int fn_vslot60();
    virtual void fn_vslot61();
    virtual void fn_vslot62();
    virtual void fn_vslot63();
    virtual void fn_vslot64();
    virtual void fn_vslot65();
    virtual void fn_vslot66();
    virtual void fn_vslot67(int a);
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
    virtual void fn_vslot79();
    virtual void fn_vslot80(int a);
    virtual void fn_vslot81();
    virtual void fn_vslot82();
    virtual void fn_vslot83();
    virtual void fn_vslot84(int a, int b);
    virtual void fn_vslot85();
    virtual void fn_vslot86();
    virtual void fn_vslot87();
    virtual int fn_vslot88();
    virtual void fn_vslot89();
    virtual void fn_vslot90();
    virtual void fn_vslot91();
    virtual void fn_vslot92();
    virtual int fn_vslot93(int a, int b);
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
    virtual void fn_vslot105();
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
    void SetVptr(const void* v) { *(const void**)((char*)this + 0x3C) = v; }
};
// GEN-CLASSES-END

/* Front-end screen (TITLESLIDE-derived, vtable lbl_806508D0, ctor fn_8010FBB0). Fields are the
 * offsets seen in this unit; m148/m14C are two widgets chosen by the mode word at m140. */
struct Unk8010E0F4_Scr : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    int m134;
    int m138;
    Unk800C7B40_Widget* m13C;
    int m140;
    int m144;
    Unk800C7B40_Widget* m148;
    Unk800C7B40_Widget* m14C;
    Unk800C7B40_Widget* m150;
    Unk800C7B40_Widget* m154;
    int m158;
    int m15C;
    int m160;
    int m164;
    int m168;
    int m16C[25];
    int m1D0[25];
    int m234;
    Unk800C7B40_Widget* m238;
    Unk800C7B40_Widget* m23C;
    Unk800C7B40_Widget* m240;
};

/* Second front-end screen (TITLESLIDE-derived, vtable lbl_80650628, ctor fn_80114A20 in
 * tu_8011243C.cpp): the same code as screen A at shifted offsets (A 0x134->0x184,
 * 0x150->0x198, 0x154->0x19C, 0x168->0x1B8, 0x16C->0x1BC), found by aligning the disassembly of
 * the cloned functions. Evidence for the rest: ctor fn_80114A20 stores m130, m17C (a second
 * vptr), m1A0..m1BC and calls fn_80134E38 on the member at +0x134. */
struct Unk80114A20_Scr : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    char m134[0x48];
    const void* m17C;
    int m180;
    int m184;
    int m188;
    int m18C;
    int m190;
    int m194;
    Unk800C7B40_Widget* m198;
    Unk800C7B40_Widget* m19C;
    int m1A0;
    int m1A4;
    int m1A8;
    int m1AC;
    int m1B0;
    int m1B4;
    int m1B8;
    int m1BC[25];
};

/* Small front-end screens (ctors fn_80117D20 / fn_80117FDC): widget base, value at +0x130, and
 * for the first one a second word at +0x134. */
struct Unk80117D20_Scr : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    int m134;
};

/* DIFFICULTY screen (vtable lbl_8064FE18, ctor fn_80120450 in tu_8011C5E8.cpp); methods in tu_8012068C.cpp.
 * m134/m138/m13C are looked up by name in fn_8012068C (group, SG1 label, TL1 label). */
struct Unk80120450_Diff : Unk800C7B40_Widget {
    char pad40[0xF0];
    int m130;
    Unk800C7B40_Widget* m134;
    Unk800C7B40_Widget* m138;
    Unk800C7B40_Widget* m13C;
};

/* Container widget: first child at +0x40, siblings chained through Data::m8 (fn_80117EA0 walks them). */
struct UnkGroupW : Unk800C7B40_Widget {
    Unk800C7B40_Widget* m40;
};

/* 0xC8-byte text argument block filled by fn_800DE274 / fn_80403DE4 and handed to UnkLabel slot 28. */
struct UnkTextArg {
    char b[0xC8];
};

/* Front-end state object returned by fn_800B555C; +0x570 is compared against ids. */
struct UnkFESub {
    char pad0[0x4C4];
    int m4C4;
    int m4C8;
    int m4CC;
    int m4D0;
    int m4D4;
    int m4D8;
    int m4DC;
};
struct UnkFEState {
    char pad0[8];
    UnkFESub m8;
    char pad4E8[0x88];
    int m570;
    char pad574[0x94];
    int m608;
};
extern "C" UnkFEState* fn_800B555C();

/* Identity casts between widget types (each returns its argument). */
extern "C" {
Unk800C7B40_Widget* fn_800C8034(Unk800C7B40_Widget* p);
Unk800C7B40_Widget* fn_800C8038(Unk800C7B40_Widget* p);
UnkLabel* fn_800C8040(Unk800C7B40_Widget* p);
Unk800C7B40_Widget* fn_800C8044(Unk800C7B40_Widget* p);
UnkLabel* fn_800C8048(Unk800C7B40_Widget* p);
Unk800C7B40_Widget* fn_800C8054(Unk800C7B40_Widget* p);
Unk800C7B40_Widget* fn_800C8058(Unk800C7B40_Widget* p);
Unk800C7B40_Widget* fn_800C805C(Unk800C7B40_Widget* p);
Unk800C7B40_Widget* fn_800C8060(Unk800C7B40_Widget* p);
}

/* Front-end manager singleton (0xD8 bytes, created on demand at lbl_8061A32C by
 * fn_800B64BC(new(0) 0xD8)); fn_800B7B4C(mgr, name, obj) / fn_800B7AB8(mgr, name) look
 * screens and widgets up by their 16-byte name. */
struct UnkFEMgr {
    char pad0[0xB8];
    int mB8;
    char padBC[0x1C];
};
extern UnkFEMgr* lbl_8061A32C;
extern "C" {
void* fn_800B64BC(void* p);
void fn_800B7B4C(UnkFEMgr* m, const void* name, void* obj);
Unk800C7B40_Widget* fn_800B7AB8(UnkFEMgr* m, const char* name);
void fn_8035682C(void* name);
void fn_8040B830(void* dst, const char* src, int n);
}

/* Game-state object returned by fn_8011AA24(i) (i = 0..2, table at lbl_8061B8C0+8; 0 otherwise).
 * Evidence: fn_801142C4, fn_8010EAF4, fn_8010F9CC read +0x6F8 (->+0x10/+0x14/+0x124), +0x700, +0x704, +0x708. */
struct UnkGameP10 {
    char pad0[0x14];
    int m14;
    int m18;
    char pad1C[0x50];
    int m6C;
    int m70;
    int m74;
    char pad78[0xAC];
    int m124;
};
/* One 0xE64-byte per-team record of the array at +0x14 (+0x198 is a value used for display). */
struct UnkPlayerRec {
    char pad0[0x198];
    int m198;
    char pad19C[0x3E4 - 0x19C];
    unsigned char m3E4;
    char pad3E5[3];
    int m3E8[1];
    char pad3EC[0xE64 - 0x3EC];
};
struct UnkTeamArr {
    UnkPlayerRec rec[2];
    char pad1CC8[8];
    int m1CD0;
};
struct UnkGameP6F8 {
    char pad0[0x10];
    UnkGameP10* m10;
    UnkTeamArr* m14;
};
struct UnkGameP700 {
    char pad0[0x3C4];
    int m3C4;
    int m3C8;
    int m3CC;
};
struct UnkGame {
    char pad0[0x65C];
    int m65C;
    char pad660[0x98];
    UnkGameP6F8* m6F8;
    char pad6FC[4];
    UnkGameP700* m700;
    int m704;
    int m708;
    char pad70C[0x7C];
    int m788;
};
/* lbl_8061B8C0 -> object whose +8 is an array of the three game-state objects (+0x24 a flag). */
struct UnkGameTbl {
    int m0;
    int m4;
    UnkGame* m8[3];
    char pad14[0x10];
    int m24;
};
extern UnkGameTbl* lbl_8061B8C0;
extern "C" {
UnkGame* fn_8011AA24(int i);
void* fn_801A4CE8(UnkGame* g, int a);
void fn_802D61AC(void* p, int a, int b);
}

/* lbl_806192E0 -> +4 -> +0xC -> +0x600 (a state flag written by the popup callbacks). */
struct UnkMgrB {
    char pad0[0x600];
    int m600;
};
struct UnkMgrC {
    char pad0[0x74];
    int m74;
    char pad78[0xA8];
    int m120;
};
struct UnkMgrA {
    char pad0[0xC];
    UnkMgrB* mC;
    UnkMgrC* m10;
};
struct UnkMgr {
    char pad0[4];
    UnkMgrA* m4;
};
extern UnkMgr* lbl_806192E0;

#endif
