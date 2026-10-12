/*
 * EA library TU, .text 0x80371D9C-0x803728E8 (static-init anchored; issue #69).
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

struct Unk80371D9CParam {
    void* m0;
    void* m4;
};

/*
 * Object built by fn_803E3C08 (x, -1). Offsets seen in fn_80372638 (stack
 * object, 0xC0 bytes) and fn_80371D9C.
 */
struct Unk803E3C08 {
    Unk80371D9CParam* m0;
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

struct Unk80623C2C {
    int m0;
    void* m4;
    int m8;
    int pad0C[10];
    int m34;
    int pad38[3];
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
void fn_803DDB5C(int n);
void fn_803DA468(int attr, void* base, int stride);
void fn_803E3C08(Unk803E3C08* self, void* x, int n);
void fn_80371D9C(Unk803E3C08* a, Unk80623C2C* b);
}

extern char lbl_80623BE8[];
extern char lbl_80623C08[];
extern char lbl_80604A1C[];

extern int lbl_80627290;
extern int lbl_80623C24;
extern char lbl_80623C28[];
extern Unk80623C2C lbl_80623C2C;
extern int lbl_80623C60;
extern int lbl_806EFB70;
extern int lbl_806EFB74;
extern int lbl_806EFB78;
extern int lbl_806EFB7C;
extern int lbl_806EFB80;

extern "C" void fn_80372638(void* x)
{
    Unk803E3C08 a;
    a.m8 = &lbl_806EFB70;
    a.m24 = (unsigned char*)lbl_80623C28;
    a.m18 = lbl_80623C24;
    a.m14 = &lbl_806EFB74;
    a.m10 = &lbl_806EFB78;
    a.m1C = &lbl_806EFB7C;
    a.m20 = &lbl_806EFB80;
    fn_803E3C08(&a, x, -1);
    if (a.mB0) {
        GXColor c = { 0xff, 0xff, 0xff, 0xff };
        fn_8042DA74(4, c);
        fn_8042DB5C(4, c);
        fn_803DDE7C();
        fn_803DDBF0();
    }
    if (a.mB4 != 0 || a.m50[10] != lbl_80623C2C.m34) {
        a.mB8 = 0;
        fn_8042B460();
        lbl_80623C60 = a.m50[10];
        if (lbl_80623C60) {
            fn_8042AB48(9, 2);
        } else {
            fn_8042AB48(9, 3);
        }
    }
    if (a.mB4) {
        fn_803DBF78(0, 9, 1, 4, 0);
        fn_803DDB5C(0);
        fn_8042DC44(0);
        lbl_80623C2C.m8 = 0x200;
        lbl_80623C2C.m0 = 1;
        lbl_80623C2C.m6C = 1;
        fn_803DB9C0(0x200, -1);
    }
    fn_803DA468(9, a.m0[3].m4, 0xc);
    fn_80371D9C(&a, &lbl_80623C2C);
    if (a.m4) {
        while (a.m4[0] == 2) {
            a.m0[a.m4[1]].m4 = (void*)((int)a.m0[a.m4[1]].m4 - *(int*)(a.m4 + 2) * lbl_80627290);
            a.m4 += 6;
        }
    }
}

Unk803DA440 lbl_80693DEC((void (*)())fn_80372638, lbl_80623BE8, lbl_80623C08, lbl_80604A1C);
