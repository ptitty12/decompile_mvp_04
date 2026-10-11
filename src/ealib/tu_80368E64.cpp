/*
 * EA library TU, .text 0x80368E64-0x80369878 (TU start is a guess: the previous
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

struct Unk80368E64Param {
    void* m0;
    void* m4;
};

/*
 * Object built by fn_803E3C08 (x, -1). Offsets seen in fn_80369554 (stack
 * object, 0xC0 bytes) and fn_80368E64.
 */
struct Unk803E3C08 {
    Unk80368E64Param* m0;
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

struct Unk8062326C {
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

extern const char lbl_80623230[];
extern const char lbl_80623248[];
extern const char lbl_80603718[];

extern int lbl_80627290;
extern int lbl_8062325C;
extern char lbl_80623260[];
extern Unk8062326C lbl_8062326C;
extern int lbl_806232A0;
extern int lbl_806232B0;
extern int lbl_806EFA74;
extern int lbl_806EFA78;
extern void* lbl_806EFA80[2];
extern int lbl_806EFA88;
extern int lbl_806EFA8C;

extern "C" void fn_80368E64(Unk803E3C08* a, Unk8062326C* b);

extern "C" void fn_80369554(void* x)
{
    Unk803E3C08 a;
    a.m8 = &lbl_806EFA74;
    a.m24 = (unsigned char*)lbl_80623260;
    a.m18 = lbl_8062325C;
    a.m14 = &lbl_806EFA78;
    a.m10 = (int*)lbl_806EFA80;
    a.m1C = &lbl_806EFA88;
    a.m20 = &lbl_806EFA8C;
    fn_803E3C08(&a, x, -1);
    if (a.mB0) {
        GXColor c = { 0xff, 0xff, 0xff, 0xff };
        fn_8042DA74(4, c);
        fn_8042DB5C(4, c);
        fn_803DDE7C();
        fn_803DDBF0();
    }
    if (a.mB4 != 0 || a.m50[10] != lbl_8062326C.m34 || a.m50[14] != lbl_8062326C.m44) {
        a.mB8 = 0;
        fn_8042B460();
        lbl_806232A0 = a.m50[10];
        if (lbl_806232A0) {
            fn_8042AB48(9, 2);
        } else {
            fn_8042AB48(9, 3);
        }
        lbl_806232B0 = a.m50[14];
        if (lbl_806232B0) {
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
        lbl_8062326C.m0 = 2;
        lbl_8062326C.m8 = 0x1200;
        lbl_8062326C.m6C = 1;
        fn_803DB9C0(0x1200, -1);
        lbl_8062326C.m70 = 1;
    }
    fn_803DA468(9, lbl_806EFA80[0], 0xc);
    fn_803DA468(0xb, lbl_806EFA80[1], 4);
    fn_80368E64(&a, &lbl_8062326C);
    if (a.m4) {
        while (a.m4[0] == 2) {
            a.m0[a.m4[1]].m4 = (void*)((int)a.m0[a.m4[1]].m4 - *(int*)(a.m4 + 2) * lbl_80627290);
            a.m4 += 6;
        }
    }
}

Unk803DA440 lbl_80693CFC((void (*)())fn_80369554, lbl_80623230, lbl_80623248, lbl_80603718);
