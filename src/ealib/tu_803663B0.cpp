/*
 * .text 0x803663B0-0x803666EC (TU boundaries unknown; the start is a guess at the
 * previous function's end, 0x803663B0 = fn_803663B0, the setup function).
 *
 * Static registration object: ctor fn_803DA440 stores {fn, a, b, c} into this
 * and links it to the head of a global list (lbl_806272AC).
 * Evidence: fn_803DA440 (0x28 bytes), the 0x60 + 0x2c pair after it is the
 * GCC __static_initialization_and_destruction_0 / _GLOBAL_.I wrapper.
 */

struct Unk803DA440 {
    Unk803DA440(void (*fn)(), const void* a, const void* b, const void* c); /* 0x803DA440 */
    char pad[0x14];
};

struct GXColor {
    unsigned char r, g, b, a;
};

struct Unk80373AD8Param {
    void* m0;
    void* m4;
};

/*
 * Object built by fn_803E3C08 (x, -1). Offsets seen in fn_80366D94 in tu_803666EC).
 */
struct Unk803E3C08 {
    Unk80373AD8Param* m0;
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

struct Unk80623E94 {
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
void fn_80365C10(Unk803E3C08* a, Unk80623E94* b);
void fn_8042DA74(int chan, GXColor c);
void fn_8042DB5C(int chan, GXColor c);
void fn_803DDE7C(void);
void fn_803DDBF0(void);
void fn_8042B460(void);
void fn_8042AB48(int attr, int type);
void fn_803DBF78(int a, int b, int c, int d, int e);
void fn_803DDB88(int a, int b, int c, int d, int e, int f);
void fn_803DDB5C(int n);
void fn_8042DC44(int n);
void fn_803DB9C0(int a, int b);
void fn_803DA468(int attr, void* base, int stride);
void fn_803E3C08(Unk803E3C08* self, void* x, int n);
}

extern int lbl_80627290;
extern int lbl_80622E7C;
extern char lbl_80622E80[];
extern int lbl_806EFA0C;
extern int lbl_806EFA10;
extern int lbl_806EFA14;
extern int lbl_806EFA18;
extern int lbl_806EFA1C;
extern Unk80623E94 lbl_80622E84;
extern int lbl_80622EB8;
extern int lbl_80622ED0;

extern "C" void fn_803663B0(void* x)
{
    Unk803E3C08 a;
    a.m8 = &lbl_806EFA0C;
    a.m24 = (unsigned char*)lbl_80622E80;
    a.m18 = lbl_80622E7C;
    a.m14 = &lbl_806EFA10;
    a.m10 = &lbl_806EFA14;
    a.m1C = &lbl_806EFA18;
    a.m20 = &lbl_806EFA1C;
    fn_803E3C08(&a, x, -1);
    if (a.mB0) {
        GXColor c = { 0xff, 0xff, 0xff, 0xff };
        fn_8042DA74(4, c);
        fn_8042DB5C(4, c);
        fn_803DDE7C();
        fn_803DDBF0();
    }
    if (a.mB4 != 0 || a.m50[10] != lbl_80622E84.m34 || a.m50[16] != lbl_80622E84.m4C) {
        a.mB8 = 0;
        fn_8042B460();
        lbl_80622EB8 = a.m50[10];
        if (lbl_80622EB8) {
            fn_8042AB48(9, 2);
        } else {
            fn_8042AB48(9, 3);
        }
        lbl_80622ED0 = a.m50[16];
        if (lbl_80622ED0) {
            fn_8042AB48(0xd, 2);
        } else {
            fn_8042AB48(0xd, 3);
        }
    }
    if (a.mB4) {
        fn_803DBF78(0, 9, 1, 3, 8);
        fn_803DBF78(0, 0xd, 1, 0, 7);
        fn_803DDB88(0, 1, 4, 0x3c, 0, 0x7d);
        fn_803DDB5C(1);
        fn_8042DC44(0);
        lbl_80622E84.m8 = 0x4200;
        lbl_80622E84.m0 = 2;
        lbl_80622E84.m6C = 1;
        fn_803DB9C0(0x4200, -1);
    }
    fn_803DA468(9, a.m0[2].m4, 6);
    fn_803DA468(0xd, a.m0[3].m4, 2);
    fn_80365C10(&a, &lbl_80622E84);
    if (a.m4) {
        while (a.m4[0] == 2) {
            a.m0[a.m4[1]].m4 = (void*)((int)a.m0[a.m4[1]].m4 - *(int*)(a.m4 + 2) * lbl_80627290);
            a.m4 += 6;
        }
    }
}

extern const char lbl_80622E38[]; /* .data 0x24 */
extern const char lbl_80622E5C[]; /* .data 0x20 */
extern const char lbl_80603030[]; /* .rodata 0x4C */

Unk803DA440 lbl_80693C98((void (*)())fn_803663B0, lbl_80622E38, lbl_80622E5C, lbl_80603030);
