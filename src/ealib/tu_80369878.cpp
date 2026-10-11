/*
 * EA library TU, .text 0x80369878-0x8036A490 (TU start is a guess: the previous
 * TU's end).
 * Static registration object; ctor 0x803DA440 stores {fn, a, b, c} and links the
 * node into a global list. The 0x60 + 0x2c pair at the end is the GCC
 * __static_initialization_and_destruction_0 / _GLOBAL_.I wrapper.
 *
 * GXWGFifo (0xCC008000) is an extern symbol: retail has lis 0xcc01 /
 * -0x8000(rX) for it, which gcc 2.95 only produces for a symbol reference (a
 * literal address gives lis/ori and different loop hoisting).
 */

struct Unk803DA440 {
    Unk803DA440(void (*fn)(), const void* a, const void* b, const void* c); /* 0x803DA440 */
    char pad[0x14];
};

union PPCWGPipe {
    unsigned char u8;
    unsigned short u16;
    unsigned int u32;
    float f32;
};
extern volatile PPCWGPipe GXWGFifo;

struct GXColor {
    unsigned char r, g, b, a;
};

struct Unk80369878Param {
    void* m0;
    void* m4;
};

/*
 * Object built by fn_803E3C08 (x, -1). Offsets seen in fn_8036A16C (stack
 * object, 0xC0 bytes) and fn_80369878.
 */
struct Unk803E3C08 {
    Unk80369878Param* m0;
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

struct Unk80623320 {
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
void fn_803EA338(void* a, void* b, void* c, void* d);
void fn_8042DC80(int a, int b, int c, int d, int e, int f, int g);
void fn_8042DC44(int n);
void fn_803DD794(void* tex);
void fn_803DB5A0(void* state);
void fn_803DB9C0(int a, int b);
void fn_803DDCD4(void);
void fn_80430124(void* list, int nbytes);
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
}

extern const char lbl_806232E0[];
extern const char lbl_806232FC[];
extern const char lbl_8060383C[];

extern int lbl_80627290;
extern int lbl_80623314;
extern char lbl_80623318[];
extern Unk80623320 lbl_80623320;
extern int lbl_80623354;
extern int lbl_80623364;
extern int lbl_806EFA90;
extern int lbl_806EFA94;
extern int lbl_806EFA98;
extern int lbl_806EFA9C;
extern int lbl_806EFAA0;

extern "C" void fn_80369878(Unk803E3C08* a, Unk80623320* b);

extern "C" void fn_8036A16C(void* x)
{
    Unk803E3C08 a;
    a.m8 = &lbl_806EFA94;
    a.m24 = (unsigned char*)lbl_80623318;
    a.m18 = lbl_80623314;
    a.m14 = &lbl_806EFA98;
    a.m10 = &lbl_806EFA9C;
    a.m1C = &lbl_806EFAA0;
    a.m20 = &lbl_806EFA90;
    fn_803E3C08(&a, x, -1);
    if (a.mB0) {
        GXColor c = { 0xff, 0xff, 0xff, 0xff };
        fn_8042DA74(4, c);
        fn_8042DB5C(4, c);
        fn_803DDE7C();
        fn_803DDBF0();
    }
    if (a.mB4 != 0 || a.m50[10] != lbl_80623320.m34 || a.m50[14] != lbl_80623320.m44) {
        a.mB8 = 0;
        fn_8042B460();
        lbl_80623354 = a.m50[10];
        if (lbl_80623354) {
            fn_8042AB48(9, 2);
        } else {
            fn_8042AB48(9, 3);
        }
        lbl_80623364 = a.m50[14];
        if (lbl_80623364) {
            fn_8042AB48(0xb, 2);
        } else {
            fn_8042AB48(0xb, 3);
        }
    }
    if (a.mB4) {
        fn_803DBF78(0, 9, 1, 4, 0);
        fn_803DBF78(0, 0xb, 1, 5, 0);
        fn_803DDB5C(0);
        fn_8042DC44(1);
        lbl_80623320.m0 = 2;
        lbl_80623320.m8 = 0x1200;
        lbl_80623320.m6C = 1;
        fn_803DB9C0(0x1200, -1);
        lbl_80623320.m70 = 1;
    }
    fn_803DA468(9, a.m0[3].m4, 0xc);
    fn_803DA468(0xb, (void*)lbl_806EFA90, 4);
    fn_80369878(&a, &lbl_80623320);
    if (a.m4) {
        while (a.m4[0] == 2) {
            a.m0[a.m4[1]].m4 = (void*)((int)a.m0[a.m4[1]].m4 - *(int*)(a.m4 + 2) * lbl_80627290);
            a.m4 += 6;
        }
    }
}

Unk803DA440 lbl_80693D10((void (*)())fn_8036A16C, lbl_806232E0, lbl_806232FC, lbl_8060383C);
