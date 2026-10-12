/*
 * Database overlay code, .database_codeoverlay 0x8054FA04-0x80554628 (code-only unit;
 * placeholder TU). Define every function DB_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */
#include "game/db_8054FA04.h"

extern float lbl_80622C24[][4];
extern float lbl_80622C74[];
extern float lbl_806EFA08;
extern float lbl_805FF458;
extern int lbl_80622C90;
extern int lbl_80622C94;

extern "C" float fn_8054FA04(int a, int b, int c, int d);
extern "C" float fn_80598348();
extern Unk8007A4DC_Screen* lbl_8061930C;
extern Unk80538DD8_G* lbl_80619948;
extern "C" int fn_800A2E90(Unk80538DD8_G* g);
extern "C" int fn_80077BC4(void* g, int a);
extern unsigned char lbl_8060252C[];
extern unsigned char lbl_80602530[];
extern unsigned char lbl_8060251C[];
extern float lbl_805FF41C;
extern float lbl_805FF420;
extern float lbl_805FF424;
extern char lbl_80622C18[];
extern int lbl_806015F4[][3];
extern "C" int fn_80552D98(int a);
struct Db80553358_S {
    char pad0[0x634];
    int m634;
};
extern "C" void fn_8057D20C(Db80553358_S* self, int a, int b, int c);
struct Db80553754_S {
    char pad0[0x10];
    int m10;
};
struct Db8055395C_S {
    char pad0[0x20];
    int m20;
};
struct Db80553E4C_S {
    int m0;
    int m4;
    int m8;
};
struct Db80553E54_S {
    int m0;
    int m4;
    char* m8;
};
extern "C" void fn_805553C0(Db80553754_S* self);
extern "C" void fn_80542274();
extern "C" void fn_805479F0(char* p);
extern "C" void fn_80547B38(char* p);
extern "C" void fn_80547C5C(char* p);
extern "C" void fn_80547D28(char* p);
extern "C" int fn_80553248(int i);

extern "C" DB_OVERLAY int fn_80550E68(int a)
{
    Unk8007B2B0_Screen* sc = (Unk8007B2B0_Screen*)lbl_8061930C;
    float f = ((Unk80537D24_Screen*)sc)->fn_8007BB28(5, a, fn_800A2E90(lbl_80619948));
    int i = 0;
    if (!(f >= lbl_80622C74[0])) {
        while (++i <= 6 && f < lbl_80622C74[i])
            ;
    }
    return i;
}

extern "C" DB_OVERLAY float fn_805518D4(int a)
{
    Unk8007A4DC_Screen* sc = lbl_8061930C;
    int s = lbl_8060252C[sc->fn_8007A6A0(0x34, a)];
    s += lbl_80602530[sc->fn_8007A6A0(0x35, a)];
    s += lbl_8060251C[sc->fn_8007A6A0(0x36, a)];
    return (float)s;
}

extern "C" DB_OVERLAY float fn_80551984(int a, int b)
{
    return lbl_80622C24[a][b];
}

extern "C" DB_OVERLAY void fn_805519A0(int a, int b, float f)
{
    lbl_80622C24[a][b] = f;
}

extern "C" DB_OVERLAY float fn_805519CC(int i)
{
    return lbl_80622C74[i];
}

extern "C" DB_OVERLAY void fn_805519E0(int i, float f)
{
    lbl_80622C74[i] = f;
}

extern "C" DB_OVERLAY void fn_80551A04(int a, Unk80070DDC_Stream* io)
{
    io->v08(a, lbl_80622C18, 4);
    io->v08(a, &lbl_806EFA08, 4);
}

extern "C" DB_OVERLAY void fn_80552054()
{
    lbl_806EFA08 = fn_80598348();
}

extern "C" DB_OVERLAY int fn_8055207C(float f)
{
    int r = 0;
    if (!(f <= lbl_805FF41C))
        r = 3;
    else if (!(f <= lbl_805FF420))
        r = 2;
    else if (!(f <= lbl_805FF424))
        r = 1;
    return r;
}

extern "C" DB_OVERLAY float fn_8055260C(int a, int b, int c, int d)
{
    return fn_8054FA04(a, b, c, d) * lbl_805FF458;
}

extern "C" DB_OVERLAY void fn_80552638(int a)
{
    lbl_80622C90 = a;
    lbl_80622C94 = 0;
}

extern "C" DB_OVERLAY int fn_80552650(int a)
{
    Unk8007B2B0_Screen* sc = (Unk8007B2B0_Screen*)lbl_8061930C;
    int n = fn_80077BC4(sc, a);
    int flag = 1;
    if (fn_800A2E90(lbl_80619948) == 0)
        flag = 0;
    if (n == 0)
        return 0;
    return (int)((Unk80537D24_Screen*)sc)->fn_8007BB28(2, n, flag);
}

extern "C" DB_OVERLAY int fn_80552CE8(float f)
{
    float t[10] = {0.94f, 0.89f, 0.84f, 0.79f, 0.74f, 0.69f, 0.64f, 0.59f, 0.54f, 0.49f};
    int i;
    for (i = 0; i < 10; i++) {
        if (f > t[i])
            return 10 - i;
    }
    return 0;
}

extern "C" DB_OVERLAY int fn_80553248(int i)
{
    return lbl_806015F4[i][1];
}

extern "C" DB_OVERLAY int fn_80553260(int a)
{
    return fn_80553248(fn_80552D98(a));
}

extern "C" DB_OVERLAY void fn_80553358(Db80553358_S* self, int a, int b)
{
    self->m634 = b;
    fn_8057D20C(self, a, b, 1);
}

extern "C" DB_OVERLAY void fn_80553754(Db80553754_S* self)
{
    self->m10 = 10;
}

extern "C" DB_OVERLAY void fn_8055395C(Db8055395C_S* self)
{
    self->m20 = 1;
}

extern "C" DB_OVERLAY int fn_80553E4C(Db80553E4C_S* self)
{
    return self->m8;
}

extern "C" DB_OVERLAY char* fn_80553E54(Db80553E54_S* self)
{
    return self->m8 + 0x32E0;
}

extern "C" DB_OVERLAY char* fn_80553E60(Db80553E54_S* self)
{
    return self->m8 + 0x3500;
}

extern "C" DB_OVERLAY void fn_80554228(Db80553754_S* self)
{
    fn_805553C0(self);
    fn_80542274();
    self->m10 = 3;
}

extern "C" DB_OVERLAY void fn_80554260(Db80553E54_S* self)
{
    fn_805479F0(self->m8);
}

extern "C" DB_OVERLAY void fn_80554284(Db80553E54_S* self)
{
    fn_80547B38(self->m8);
}

extern "C" DB_OVERLAY void fn_805542A8(Db80553E54_S* self)
{
    fn_80547C5C(self->m8);
}

extern "C" DB_OVERLAY void fn_805542CC(Db80553E54_S* self)
{
    fn_80547D28(self->m8);
}

extern "C" DB_OVERLAY void fn_8055440C()
{
}
