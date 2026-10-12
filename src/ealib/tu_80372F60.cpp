/*
 * EA library TU, .text 0x80372F60-0x80373AD8 (static-init anchored).
 * Registers one static node (5 words, intrusive list, ctor 0x803DA440) whose
 * arguments are a creator function and three data tables.
 */

class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), void* a, void* b, void* c);
    int m[5];
};

struct GXColor {
    unsigned char r, g, b, a;
};

struct Unk80372F60Param {
    void* m0;
    void* m4;
};

/*
 * Object built by fn_803E3C08 (x, -1). Offsets seen in fn_80373748 (stack
 * object, 0xC0 bytes) and fn_80372F60.
 */
struct Unk803E3C08 {
    Unk80372F60Param* m0;
    unsigned char* m4;
    int* m8;
    int pad0C;
    int* m10;
    int* m14;
    int m18;
    int* m1C;
    int* m20;
    unsigned char* m24;
    void* m28;
    int m2C;
    int m30[8];
    int m50[24];
    int mB0;
    int mB4;
    int mB8;
    int mBC;
};

struct UnkCfg {
    int m0;
    void* m4;
    int m8;
    int pad0C[10];
    int m34;
    int m38;
    int pad3C[2];
    int m44;
    int pad48;
    int m4C;
    int pad50[7];
    int m6C;
    int m70;
};

extern "C" {
void fn_8042DC44(int n);
void fn_803DB9C0(int a, int b);
void fn_803DDBF0(void);
void fn_803DDE7C(void);
void fn_8042DA74(int chan, GXColor c);
void fn_8042DB5C(int chan, GXColor c);
void fn_8042B460(void);
void fn_8042AB48(int attr, int type);
void fn_803DBF78(int a, int b, int c, int d, int e);
void fn_803DDB88(int a, int b, int c, int d, int e, int f);
void fn_803DDB5C(int n);
void fn_803DA468(int attr, void* base, int stride);
void fn_803E3C08(Unk803E3C08* self, void* x, int n);
void fn_80372F60(Unk803E3C08* a, UnkCfg* b);
}

extern char lbl_80623D78[];
extern char lbl_80623DA0[];
extern char lbl_80604D4C[];

extern int lbl_80627290;
extern UnkCfg lbl_80623DD4;
extern int lbl_80623E08;
extern int lbl_80623E0C;
extern int lbl_80623E18;
extern int lbl_80623DC4;
extern char lbl_80623DC8[];
extern int lbl_806EFB98;
extern int lbl_806EFB9C;
extern int lbl_806EFBA0;
extern int lbl_806EFBA4;
extern int lbl_806EFBA8;

extern "C" void fn_80373748(void* x)
{
    Unk803E3C08 a;
    a.m8 = &lbl_806EFB9C;
    a.m24 = (unsigned char*)lbl_80623DC8;
    a.m18 = lbl_80623DC4;
    a.m14 = &lbl_806EFBA0;
    a.m10 = &lbl_806EFB98;
    a.m1C = &lbl_806EFBA4;
    a.m20 = &lbl_806EFBA8;
    fn_803E3C08(&a, x, -1);
    if (a.mB0) {
        GXColor c = { 0xff, 0xff, 0xff, 0xff };
        fn_8042DA74(4, c);
        fn_8042DB5C(4, c);
        fn_803DDE7C();
        fn_803DDBF0();
    }
    if (a.mB4 != 0 || a.m50[10] != lbl_80623DD4.m34 || a.m50[11] != lbl_80623DD4.m38 || a.m50[14] != lbl_80623DD4.m44) {
        a.mB8 = 0;
        fn_8042B460();
        lbl_80623E08 = a.m50[10];
        if (lbl_80623E08) {
            fn_8042AB48(9, 2);
        } else {
            fn_8042AB48(9, 3);
        }
        lbl_80623E0C = a.m50[11];
        if (lbl_80623E0C) {
            fn_8042AB48(0xa, 2);
        } else {
            fn_8042AB48(0xa, 3);
        }
        lbl_80623E18 = a.m50[14];
        if (lbl_80623E18) {
            fn_8042AB48(0xb, 2);
        } else {
            fn_8042AB48(0xb, 3);
        }
    }
    if (a.mB4) {
        fn_803DBF78(0, 9, 1, 4, 0);
        fn_803DBF78(0, 0xa, 0, 3, 0xe);
        fn_803DBF78(0, 0xb, 1, 5, 0);
        fn_803DDB5C(0);
        fn_8042DC44(1);
        lbl_80623DD4.m0 = 3;
        lbl_80623DD4.m8 = 0x1600;
        lbl_80623DD4.m6C = 1;
        fn_803DB9C0(0x1600, -1);
        lbl_80623DD4.m70 = 1;
    }
    fn_803DA468(9, a.m0[3].m4, 0xc);
    fn_803DA468(0xa, a.m0[4].m4, 6);
    fn_803DA468(0xb, a.m0[5].m4, 4);
    fn_80372F60(&a, &lbl_80623DD4);
    if (a.m4) {
        while (a.m4[0] == 2) {
            a.m0[a.m4[1]].m4 = (void*)((int)a.m0[a.m4[1]].m4 - *(int*)(a.m4 + 2) * lbl_80627290);
            a.m4 += 6;
        }
    }
}

Unk803DA440 lbl_80693E14((void (*)())fn_80373748, lbl_80623D78, lbl_80623DA0, lbl_80604D4C);
