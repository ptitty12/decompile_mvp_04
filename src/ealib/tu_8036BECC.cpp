/*
 * EA library TU, .text 0x8036BECC-0x8036CC08 (static-init anchored).
 * Registers one static node (5 words, intrusive list, ctor 0x803DA440) whose
 * arguments are a creator function and three data tables.
 */

class Unk803DA440 {
public:
    Unk803DA440(void (*fn)(), const void* a, const void* b, const void* c);
    int m[5];
};

struct GXColor {
    unsigned char r, g, b, a;
};

struct Unk8036BECCParam {
    void* m0;
    void* m4;
};

/*
 * Object built by fn_803E3C08 (x, -1). Offsets seen in fn_8036C7F0 (stack
 * object, 0xC0 bytes) and fn_8036BECC.
 */
struct Unk803E3C08 {
    Unk8036BECCParam* m0;
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
void fn_8036BECC(Unk803E3C08* a, UnkCfg* b);
}

extern const char lbl_80623528[];
extern const char lbl_80623558[];
extern const char lbl_80603D44[];

extern int lbl_80627290;
extern UnkCfg lbl_8062358C;
extern int lbl_806235C0;
extern int lbl_806235C4;
extern int lbl_806235D0;
extern int lbl_806235D8;
extern int lbl_80623584;
extern char lbl_80623588[];
extern int lbl_806EFACC;
extern int lbl_806EFAD0;
extern int lbl_806EFAD4;
extern int lbl_806EFAD8;
extern int lbl_806EFADC;

extern "C" void fn_8036C7F0(void* x)
{
    Unk803E3C08 a;
    a.m8 = &lbl_806EFACC;
    a.m24 = (unsigned char*)lbl_80623588;
    a.m18 = lbl_80623584;
    a.m14 = &lbl_806EFAD0;
    a.m10 = &lbl_806EFAD4;
    a.m1C = &lbl_806EFAD8;
    a.m20 = &lbl_806EFADC;
    fn_803E3C08(&a, x, -1);
    if (a.mB0) {
        GXColor c = { 0xff, 0xff, 0xff, 0xff };
        fn_8042DA74(4, c);
        fn_8042DB5C(4, c);
        fn_803DDE7C();
        fn_803DDBF0();
    }
    if (a.mB4 != 0 || a.m50[10] != lbl_8062358C.m34 || a.m50[11] != lbl_8062358C.m38 || a.m50[16] != lbl_8062358C.m4C || a.m50[14] != lbl_8062358C.m44) {
        a.mB8 = 0;
        fn_8042B460();
        lbl_806235C0 = a.m50[10];
        if (lbl_806235C0) {
            fn_8042AB48(9, 2);
        } else {
            fn_8042AB48(9, 3);
        }
        lbl_806235C4 = a.m50[11];
        if (lbl_806235C4) {
            fn_8042AB48(0xa, 2);
        } else {
            fn_8042AB48(0xa, 3);
        }
        lbl_806235D8 = a.m50[16];
        if (lbl_806235D8) {
            fn_8042AB48(0xd, 2);
        } else {
            fn_8042AB48(0xd, 3);
        }
        lbl_806235D0 = a.m50[14];
        if (lbl_806235D0) {
            fn_8042AB48(0xb, 2);
        } else {
            fn_8042AB48(0xb, 3);
        }
    }
    if (a.mB4) {
        fn_803DBF78(0, 9, 1, 4, 0);
        fn_803DBF78(0, 0xa, 0, 3, 0xe);
        fn_803DBF78(0, 0xd, 1, 4, 0);
        fn_803DDB88(0, 1, 4, 0x3c, 0, 0x7d);
        fn_803DBF78(0, 0xb, 1, 5, 0);
        fn_803DDB5C(1);
        fn_8042DC44(1);
        lbl_8062358C.m0 = 4;
        lbl_8062358C.m8 = 0x5600;
        lbl_8062358C.m6C = 1;
        fn_803DB9C0(0x5600, -1);
        lbl_8062358C.m70 = 1;
    }
    fn_803DA468(9, a.m0[2].m4, 0xc);
    fn_803DA468(0xa, a.m0[3].m4, 6);
    fn_803DA468(0xd, a.m0[4].m4, 8);
    fn_803DA468(0xb, a.m0[5].m4, 4);
    fn_8036BECC(&a, &lbl_8062358C);
    if (a.m4) {
        while (a.m4[0] == 2) {
            a.m0[a.m4[1]].m4 = (void*)((int)a.m0[a.m4[1]].m4 - *(int*)(a.m4 + 2) * lbl_80627290);
            a.m4 += 6;
        }
    }
}

Unk803DA440 lbl_80693D4C((void (*)())fn_8036C7F0, lbl_80623528, lbl_80623558, lbl_80603D44);
