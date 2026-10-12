/*
 * Database overlay code, .database_codeoverlay 0x80584CBC-0x805881E4 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_80584CBC.h"

typedef Unk8007A4DC_Screen SA;
typedef Unk8007B2B0_Screen SB;
extern const Db80586420_Tri lbl_806005E8;
extern const char lbl_805FEFF0[];
extern const char lbl_805FDB38[];
extern Unk8007A4DC_Screen* lbl_8061930C;

extern "C" DB_OVERLAY int fn_80586420(int a, int b, void* rec)
{
    Db80586420_Tri t = { -1, -1, -1 };
    Db80586420_Ent e(rec);
    int c = e.mC.e != 0;
    if (c) {
        Db80586420_Tri tb[2] = { { 0x1D5F, 0x1D6E, 0x1E41 }, { 0x1D5F, 0x1D85, 0x1E42 } };
        t = tb[((unsigned short*)rec)[8] & 1];
    } else {
        t.a = 0x1D5F;
        t.b = 0x1D6F;
        t.c = 0x1E43;
    }
    return fn_80582DF4(a, b, t);
}

/* near-miss (2 slots): retail sets r6, r4 and then r3 (mr) for the fn_800DE538 call; here r3 comes before r4. */
extern "C" DB_OVERLAY void fn_80586560(void* self, void* rec, unsigned short* dst)
{
    fn_8058233C(self);
    if (fn_800B5758(fn_800B555C())) {
        Db80586420_Ent e(rec);
        Db80586420_Ent* pe = &e;
        if (pe->m8 != 0) {
            unsigned short b[0x80];
            char n[0x80];
            Unk80090880* tb = lbl_8061977C;
            fn_800DE538((int)n, 0, pe->m8, 1);
            fn_80403DE4(b, ((DbLook)fn_80090880)(tb, 0x5C65), n, dst);
            fn_80403144(dst, b);
        }
    }
}

extern "C" DB_OVERLAY void fn_80586618(unsigned short* dst, int* p)
{
    unsigned short fmt[8];
    fn_804031BC(fmt, lbl_805FEFF0);
    fn_80403DE4(dst, fmt, *p);
}

extern "C" DB_OVERLAY void fn_80586668(unsigned short* dst, float* p)
{
    char buf[8];
    char* b = buf;
    fn_80119FF0(b, *p);
    fn_80402EF8(dst, b);
}

extern "C" DB_OVERLAY void fn_805866AC(unsigned short* dst, int* p)
{
    char a[100];
    char b[100];
    unsigned short wa[100];
    unsigned short wb[100];
    ((SA*)lbl_8061930C)->fn_8007A700(0, *p, a);
    ((SA*)lbl_8061930C)->fn_8007A700(1, *p, b);
    fn_804031BC(wa, a);
    fn_804031BC(wb, b);
    fn_8040321C(dst, DBTXT(0x1DB0), wa, wb);
}

extern "C" DB_OVERLAY void fn_8058674C(unsigned short* dst, int* p)
{
    char a[100];
    char b[100];
    unsigned short wa[100];
    unsigned short wb[100];
    ((SA*)lbl_8061930C)->fn_8007A700(0, *p, a);
    ((SA*)lbl_8061930C)->fn_8007A700(1, *p, b);
    a[1] = 0x2E;
    a[2] = 0x20;
    a[3] = 0;
    fn_804031BC(wa, a);
    fn_804031BC(wb, b);
    fn_8040321C(dst, DBTXT(0x1DB0), wa, wb);
}

extern "C" DB_OVERLAY void fn_80586804(unsigned short* dst, int* p)
{
    char buf[100];
    if (*p != 0) {
        ((SB*)lbl_8061930C)->fn_8007B924(3, *p, buf);
        fn_804031BC(dst, buf);
    } else {
        fn_804031BC(dst, lbl_805FDB38);
    }
}

extern "C" DB_OVERLAY void fn_8058686C(unsigned short* dst, int* p)
{
    char buf[100];
    ((SB*)lbl_8061930C)->fn_8007BC64(3, *p, buf);
    fn_804031BC(dst, buf);
}

extern "C" DB_OVERLAY void fn_805868B8(unsigned short* dst, int* p)
{
    char buf[100];
    if (*p != 0) {
        ((SB*)lbl_8061930C)->fn_8007B924(1, *p, buf);
        fn_804031BC(dst, buf);
    } else {
        fn_804031BC(dst, lbl_805FDB38);
    }
}

extern "C" DB_OVERLAY void fn_80586920(unsigned short* dst, int* p)
{
    char buf[100];
    ((SB*)lbl_8061930C)->fn_8007BC64(1, *p, buf);
    fn_804031BC(dst, buf);
}

extern "C" DB_OVERLAY void fn_8058696C(unsigned short* dst, int* p)
{
    char buf[100];
    int k = ((SB*)lbl_8061930C)->fn_80075948(*p);
    int j = ((SB*)lbl_8061930C)->fn_8007B320(0, k);
    ((SB*)lbl_8061930C)->fn_8007B924(1, j, buf);
    fn_804031BC(dst, buf);
}

extern "C" DB_OVERLAY void fn_805869D4(unsigned short* dst, unsigned* p)
{
    int t[9] = { 0xE74, 0xE75, 0xE76, 0xE77, 0xE78, 0xE79, 0xE7A, 0xE7B, 0xE7C };
    if (*p <= 8)
        fn_80403144(dst, DBTXT(t[*p]));
}

extern "C" DB_OVERLAY void fn_80586A94(unsigned short* dst, unsigned* p)
{
    int t[4] = { 0x1DB1, 0x1DB2, 0x1DB3, 0x1DB4 };
    if (*p <= 3)
        fn_80403144(dst, DBTXT(t[*p]));
}

extern "C" DB_OVERLAY void fn_80586B14(unsigned short* dst, unsigned i)
{
    int t[4] = { 0x3FB7, 0x3FB8, 0x3FB9, 0x5975 };
    if (i <= 3)
        fn_80403144(dst, DBTXT(t[i]));
}

extern "C" DB_OVERLAY void fn_80586B90(unsigned short* dst, int* p)
{
    fn_80586B14(dst, *p);
}

extern "C" DB_OVERLAY void fn_80586BB4(unsigned short* dst, int* p)
{
    fn_80586B14(dst, ((SB*)lbl_8061930C)->fn_80078A38(*p));
}

extern "C" DB_OVERLAY void fn_80586BF8(unsigned short* dst, unsigned* p)
{
    int t[4] = { 0x1DB8, 0x1DB6, 0x1DB7, 0x1DB5 };
    if (*p <= 3)
        fn_80403144(dst, DBTXT(t[*p]));
}

extern "C" DB_OVERLAY void fn_80586C78(unsigned short* dst, int* p)
{
    int id = 0;
    switch (*p) {
    case 0:
        id = 0x1DCD;
        break;
    case 1:
        id = 0x1DCF;
        break;
    case 2:
        id = 0x1DD0;
        break;
    case 3:
        id = 0x1DD1;
        break;
    case 4:
        id = 0x1DD2;
        break;
    case 5:
        id = 0x1DD3;
        break;
    case 6:
        id = 0x1DD5;
        break;
    case 7:
        id = 0x1DD6;
        break;
    case 8:
        id = 0x1DD7;
        break;
    }
    if (id != 0)
        fn_80403144(dst, DBTXT(id));
}

extern "C" DB_OVERLAY void fn_80586D68(unsigned short* dst, int* p)
{
    int id = 0;
    switch (*p) {
    case 0:
        id = 0x1DDA;
        break;
    case 1:
        id = 0x1DDA;
        break;
    case 2:
        id = 0x1DDB;
        break;
    case 3:
        id = 0x1DDA;
        break;
    case 4:
        id = 0x1DDA;
        break;
    case 5:
        id = 0x1DDA;
        break;
    case 6:
        id = 0x1DDC;
        break;
    case 7:
        id = 0x1DDB;
        break;
    case 8:
        id = 0x1DDC;
        break;
    }
    if (id != 0)
        fn_80403144(dst, DBTXT(id));
}

extern "C" DB_OVERLAY void fn_80586E28(unsigned short* dst, unsigned* p)
{
    int t[4] = { 0x1DBC, 0x1DBA, 0x1DBB, 0x1DB9 };
    if (*p <= 3)
        fn_80403144(dst, DBTXT(t[*p]));
}

extern "C" DB_OVERLAY void fn_80586EA8(unsigned short* dst, int* p)
{
    int t[2] = { 0x1DC0, 0x1DC1 };
    fn_80403144(dst, DBTXT(t[*p & 1]));
}

extern "C" DB_OVERLAY void fn_80586F10(unsigned short* dst, unsigned* p)
{
    int t[3] = { 0x1DBD, 0x1DBE, 0x1DBF };
    fn_80403144(dst, DBTXT(t[*p % 3]));
}

extern "C" DB_OVERLAY void fn_80586F9C(unsigned short* dst, int* p)
{
    if (*p <= 0x31)
        fn_80403144(dst, DBTXT(fn_800E6058(*p)));
}

extern "C" DB_OVERLAY void fn_80586FF8(unsigned short* dst, unsigned* p)
{
    int t[8] = { 0x1DC2, 0x1DC3, 0x1DC4, 0x1DC5, 0x1DC6, 0x1DC7, 0x1DC8, 0x1DC9 };
    if (*p <= 7)
        fn_80403144(dst, DBTXT(t[*p]));
}

extern "C" DB_OVERLAY void fn_805870B0(unsigned short* dst, unsigned* p)
{
    int t[3] = { 0x1DDD, 0x1DDE, 0x1DDF };
    if (*p <= 2)
        fn_80403144(dst, DBTXT(t[*p]));
}

extern "C" DB_OVERLAY void fn_80587128(unsigned short* dst, unsigned* p)
{
    int t[12] = { 0x1DE6, 0x1DE7, 0x1DE8, 0x1DE3, 0x1DE4, 0x1DE5, 0x1DE9, 0x1DEA, 0x1DEB, 0x1DEC, 0x1DED, 0x1DEE };
    if (*p <= 11)
        fn_80403144(dst, DBTXT(t[*p]));
}

extern "C" DB_OVERLAY void fn_805871D0(unsigned short* dst, unsigned* p)
{
    int t[3] = { 0x1DE0, 0x1DE1, 0x1DE2 };
    if (*p <= 2)
        fn_80403144(dst, DBTXT(t[*p]));
}

extern "C" DB_OVERLAY void fn_80587248(unsigned short* dst, int* p)
{
    float f = *p * 0.001f;
    char buf[8];
    char* b = buf;
    fn_80119FF0(b, f);
    fn_80402EF8(dst, b);
}

extern "C" DB_OVERLAY void fn_805872C4(unsigned short* dst, int* p)
{
    float f = *p * 0.001f;
    char buf[8];
    char* b = buf;
    fn_80119F48(b, f);
    fn_80402EF8(dst, b);
}

extern "C" DB_OVERLAY void fn_80587340(unsigned short* dst, int* p)
{
    float f = *p * 0.1f;
    char buf[8];
    char* b = buf;
    fn_804089B4(b, "%.1f", f);
    fn_80402EF8(dst, b);
}

extern "C" DB_OVERLAY void fn_805873C8(unsigned short* dst, int* p)
{
    float f = *p * 0.1f;
    char buf[8];
    char* b = buf;
    fn_804089B4(b, "%.1f", f);
    fn_80402EF8(dst, b);
}

extern "C" DB_OVERLAY void fn_80587450(unsigned short* dst, int* p)
{
    char a[100];
    char b[100];
    unsigned short wa[100];
    unsigned short wb[100];
    int k = ((SB*)lbl_8061930C)->fn_80075948(*p);
    int t = ((SB*)lbl_8061930C)->fn_8007B380(4, k);
    ((SB*)lbl_8061930C)->fn_8007C5DC(0, t, a);
    ((SB*)lbl_8061930C)->fn_8007C5DC(1, t, b);
    fn_804031BC(wa, a);
    fn_804031BC(wb, b);
    fn_8040321C(dst, DBTXT(0x1DB0), wa, wb);
}

extern "C" DB_OVERLAY int fn_80587728(int* p)
{
    if (((SA*)lbl_8061930C)->fn_8007A1D8(*p))
        return *p;
    return 0;
}

extern const char lbl_80683000[];

extern "C" DB_OVERLAY Db805822D0_Base* fn_80587770(Db805822D0_Base* self)
{
    fn_805822D0(self);
    self->m4 = lbl_80683000;
    return self;
}

extern "C" DB_OVERLAY int fn_805880EC(int a, int b, void* rec)
{
    Db80586420_Tri t = { -1, -1, -1 };
    Db80586420_Ent e(rec);
    int x = 0;
    int lo = 0, hi = 3;
    int k = e.mC.e;
    if (k != 0) {
        if (k >= lo && k <= hi)
            x = 0x1D5F;
    } else {
        x = 0x1D1A;
    }
    int ee = e.mC.e;
    int ff = e.mC.f;
    if (ee < ff) {
        t.a = x;
        t.b = 0x1D62;
        t.c = 0x1E18;
    } else {
        t.a = x;
        t.b = 0x1D61;
        t.c = 0x1E17;
    }
    return fn_80582DF4(a, b, t);
}
