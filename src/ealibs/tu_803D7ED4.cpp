/*
 * Translation unit at 0x803D7ED4 (EA library; original file name unknown).
 * Partial: only the small functions are written; the rest stays unmatched.
 * .text 0x803D7ED4-0x803D8234, .ctors 0x805A2CD0 (static init fn_803D8208).
 */

struct Unk803D7ED4Head {
    int a, b, c;
    Unk803D7ED4Head(int x, int y, int z) : a(x), b(y), c(z) {}
};

struct Unk803D7ED4Item;
struct Unk803D7ED4Link {
    Unk803D7ED4Item* mNext;
};
struct Unk803D7ED4Item {
    char pad0[0x4];
    int m4;
    Unk803D7ED4Link* m8;
};

class Unk803D7ED4Pool {
public:
    char pad0[0xC];
    Unk803D7ED4Item* mC;
    void fn_803D8080(Unk803D7ED4Item* item);
    void fn_803D8094(Unk803D7ED4Item* item);
    Unk803D7ED4Item* fn_803D7F0C();
    void fn_803D7FD0(Unk803D7ED4Item* item);
    Unk803D7ED4Item* fn_803D7F74();
    void fn_803D803C(Unk803D7ED4Item* item);
};
Unk803D7ED4Item* fn_803D91F8(void* mem, Unk803D7ED4Pool* owner);
Unk803D7ED4Item* fn_803E09B4(void* mem, Unk803D7ED4Pool* owner);

extern int lbl_8062729C;
extern int lbl_806272A0;
extern int lbl_806272A4;
extern int lbl_80627298;
extern void* (*lbl_8062C668)(int, int);
extern int lbl_8062C66C;

struct Unk803D7ED4Big : Unk803D7ED4Head {
    int pad;
    Unk803D7ED4Big(int x, int y, int z) : Unk803D7ED4Head(x, y, z) {}
};
Unk803D7ED4Big lbl_806AA910(3, 3, 1);

void Unk803D7ED4Pool::fn_803D8080(Unk803D7ED4Item* item)
{
    item->m8->mNext = mC;
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

void fn_803D81E4(void* (*v)(int, int))
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

Unk803D7ED4Item* Unk803D7ED4Pool::fn_803D7F74()
{
    Unk803D7ED4Item* item = fn_803E09B4(lbl_8062C668(0x78, 0), this);
    fn_803D8080(item);
    return item;
}

void Unk803D7ED4Pool::fn_803D803C(Unk803D7ED4Item* item)
{
    fn_803D8094(item);
    if (lbl_806272A0 == (int)item)
        lbl_806272A0 = 0;
}

Unk803D7ED4Item* Unk803D7ED4Pool::fn_803D7F0C()
{
    Unk803D7ED4Item* item = fn_803D91F8(lbl_8062C668(0xF0, 0), this);
    fn_803D8080(item);
    fn_803D81A0((int)this + 4, (int)item);
    return item;
}

void Unk803D7ED4Pool::fn_803D7FD0(Unk803D7ED4Item* item)
{
    fn_803D8094(item);
    if (lbl_8062729C == (int)item) {
        Unk803D7ED4Item* p = mC;
        while (p && p->m4 != 0)
            p = p->m8->mNext;
        lbl_8062729C = (int)p;
    }
}
