/*
 * Translation unit at 0x803D7ED4 (EA library; original file name unknown).
 * Partial: only the small functions are written; the rest stays unmatched.
 * .text 0x803D7ED4-0x803D8234, .ctors 0x805A2CD0 (static init fn_803D8208).
 */

struct Unk803D7ED4Head {
    int a, b, c;
    Unk803D7ED4Head(int x, int y, int z) : a(x), b(y), c(z) {}
};

struct Unk803D7ED4Link {
    int mNext;
};
struct Unk803D7ED4Item {
    char pad0[0x8];
    Unk803D7ED4Link* m8;
};

class Unk803D7ED4Pool {
public:
    char pad0[0xC];
    Unk803D7ED4Item* mC;
    void fn_803D8080(Unk803D7ED4Item* item);
};

extern int lbl_8062729C;
extern int lbl_806272A0;
extern int lbl_806272A4;
extern int lbl_80627298;
extern int lbl_8062C668;
extern int lbl_8062C66C;

struct Unk803D7ED4Big : Unk803D7ED4Head {
    int pad;
    Unk803D7ED4Big(int x, int y, int z) : Unk803D7ED4Head(x, y, z) {}
};
Unk803D7ED4Big lbl_806AA910(3, 3, 1);

void Unk803D7ED4Pool::fn_803D8080(Unk803D7ED4Item* item)
{
    *(Unk803D7ED4Item**)item->m8 = mC;
    mC = item;
}

int fn_803D817C()
{
    return lbl_8062729C;
}

int fn_803D8188()
{
    return lbl_806272A0;
}

int fn_803D8194()
{
    return lbl_806272A4;
}

void fn_803D81A0(int unused, int v)
{
    lbl_8062729C = v;
    lbl_806272A4 = v;
}

void fn_803D81B4(int unused, int v)
{
    lbl_806272A0 = v;
    if (v == 0)
        lbl_806272A4 = lbl_8062729C;
    else
        lbl_806272A4 = v;
}

void fn_803D81E4(int v)
{
    lbl_8062C668 = v;
}

void fn_803D81F0(int v)
{
    lbl_8062C66C = v;
}

int fn_803D81FC()
{
    return lbl_80627298;
}
