/*
 * Translation unit at 0x800042B0 (original file name unknown; placeholder).
 * A real TU: it ends with its static-initializer wrapper (docs/UNITS.md
 * ctor anchors). 18 functions.
 *
 * .text 0x800042B0-0x800057D8, .rodata 0x805A3400-0x805A344C, .data 0x8060F128-0x8060F720, .bss 0x806868FC-0x806869B0.
 * Not split (declare extern if used): small-data (.sdata/.sbss) objects and
 * any second, non-contiguous range of a section.
 *
 * What it does (evidence, not names): fn_80004568 maps the drive status codes
 * 5, 4, 6, 0xB, -1 (the Dolphin SDK DVD_STATE_* values for cover open, no
 * disc, wrong disc, retry, fatal error) to rows 0..4 of the UTF-16 message
 * table below (the six texts are the disc-error messages); fn_800042B0
 * shows / hides the message screen, fn_8000446C is the loop that polls it.
 * The static initializer builds thirteen unit vectors between five points
 * (x, 0, z) inside a 1080-unit square (four near the corners, one at the
 * centre), five (month, day, 2005)-looking records and the hash of "test".
 */

#include "game/tu_800042B0.h"

struct Unk8061FEDC;
/* Object returned by fn_80020BCC for the hash lbl_806869AC. Only m4 is used here: fn_80004850
 * passes m4 * 19 / 20 - 1 (at least 0) to fn_8002114C when the screen opens, fn_800048D0
 * passes 100 when it closes (a 0..100 level being ducked and restored). */
struct Unk806869AC {
    int m0;
    int m4;
};
unsigned int fn_80378568(const char* token, int len);

/* Hash of a name; fn_80020BCC looks the object up by it. Built last by the static initializer. */
struct Unk806869AC_Id {
    unsigned int m0;
    Unk806869AC_Id(const char* s, int n)
    {
        m0 = fn_80378568(s, n);
    }
};
extern Unk806869AC_Id lbl_806869AC;

/* Disc-error messages (UTF-16, 124 units each, row index = fn_80004568 result): cover open,
 * no disc, wrong disc, read error, fatal error, and row 5 ("please wait", also the lbl_8060F600 object). */
unsigned short lbl_8060F128[6][124] = {
    {
        'T', 'h', 'e', ' ', 'D', 'i', 's', 'c', ' ', 'C',
        'o', 'v', 'e', 'r', ' ', 'i', 's', ' ', 'o', 'p',
        'e', 'n', '.', ' ', ' ', 'I', 'f', ' ', 'y', 'o',
        'u', '\n', 'w', 'a', 'n', 't', ' ', 't', 'o', ' ',
        'c', 'o', 'n', 't', 'i', 'n', 'u', 'e', ' ', 't',
        'h', 'e', ' ', 'g', 'a', 'm', 'e', ',', '\n', 'p',
        'l', 'e', 'a', 's', 'e', ' ', 'c', 'l', 'o', 's',
        'e', ' ', 't', 'h', 'e', ' ', 'D', 'i', 's', 'c',
        ' ', 'C', 'o', 'v', 'e', 'r', '.',
    },
    {
        'P', 'l', 'e', 'a', 's', 'e', ' ', 'i', 'n', 's',
        'e', 'r', 't', ' ', 't', 'h', 'e', '\n', 'M', 'V',
        'P', ' ', 'B', 'a', 's', 'e', 'b', 'a', 'l', 'l',
        0x2122, ' ', '2', '0', '0', '5', '\n', 'G', 'a', 'm',
        'e', ' ', 'D', 'i', 's', 'c', '.',
    },
    {
        'P', 'l', 'e', 'a', 's', 'e', ' ', 'i', 'n', 's',
        'e', 'r', 't', ' ', 't', 'h', 'e', '\n', 'M', 'V',
        'P', ' ', 'B', 'a', 's', 'e', 'b', 'a', 'l', 'l',
        0x2122, ' ', '2', '0', '0', '5', '\n', 'G', 'a', 'm',
        'e', ' ', 'D', 'i', 's', 'c', '.',
    },
    {
        'T', 'h', 'e', ' ', 'G', 'a', 'm', 'e', ' ', 'D',
        'i', 's', 'c', ' ', 'c', 'o', 'u', 'l', 'd', ' ',
        'n', 'o', 't', '\n', 'b', 'e', ' ', 'r', 'e', 'a',
        'd', '.', ' ', 'P', 'l', 'e', 'a', 's', 'e', ' ',
        'r', 'e', 'a', 'd', '\n', 't', 'h', 'e', ' ', 'N',
        'i', 'n', 't', 'e', 'n', 'd', 'o', ' ', 'G', 'a',
        'm', 'e', 'C', 'u', 'b', 'e', 0x2122, '\n', 'I', 'n',
        's', 't', 'r', 'u', 'c', 't', 'i', 'o', 'n', ' ',
        'B', 'o', 'o', 'k', 'l', 'e', 't', '\n', 'f', 'o',
        'r', ' ', 'm', 'o', 'r', 'e', ' ', 'i', 'n', 'f',
        'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', '.',
    },
    {
        'A', 'n', ' ', 'e', 'r', 'r', 'o', 'r', ' ', 'h',
        'a', 's', ' ', 'o', 'c', 'c', 'u', 'r', 'r', 'e',
        'd', '.', '\n', 'T', 'u', 'r', 'n', ' ', 't', 'h',
        'e', ' ', 'p', 'o', 'w', 'e', 'r', ' ', 'o', 'f',
        'f', ' ', 'a', 'n', 'd', ' ', 'r', 'e', 'f', 'e',
        'r', '\n', 't', 'o', ' ', 't', 'h', 'e', ' ', 'N',
        'i', 'n', 't', 'e', 'n', 'd', 'o', ' ', 'G', 'a',
        'm', 'e', 'C', 'u', 'b', 'e', 0x2122, '\n', 'I', 'n',
        's', 't', 'r', 'u', 'c', 't', 'i', 'o', 'n', ' ',
        'B', 'o', 'o', 'k', 'l', 'e', 't', ' ', 'f', 'o',
        'r', ' ', 'f', 'u', 'r', 't', 'h', 'e', 'r', '\n',
        'i', 'n', 's', 't', 'r', 'u', 'c', 't', 'i', 'o',
        'n', 's', '.',
    },
    {
        'P', 'l', 'e', 'a', 's', 'e', ' ', 'w', 'a', 'i',
        't', ' ', 'w', 'h', 'i', 'l', 'e', '\n', 'M', 'V',
        'P', ' ', 'B', 'a', 's', 'e', 'b', 'a', 'l', 'l',
        0x2122, ' ', '2', '0', '0', '5', ' ', 'l', 'o', 'a',
        'd', 's', '.',
    },
};

Unk8060F6F8* lbl_8060F6F8 = 0;
int lbl_8060F6FC = 0;
int lbl_8060F700 = 1;     /* not referenced in this unit */
int lbl_8060F704 = 0;
int lbl_8060F708 = 0;
int lbl_8060F70C[5] = { 0, 0, 0, 0, 0 };    /* not referenced in this unit */

extern Unk8061FEDC* lbl_8061FEDC;
extern int lbl_8061A330;
extern int lbl_80624260;

int fn_801747A0();
int fn_804367C8();
void fn_8042C1E8();
void fn_8042C464();
void fn_8043D3EC(int);
void fn_8043D250();
void fn_8043C580();
void fn_80436204(int, int, int);
void fn_80439918(int, int);
int fn_804250B0();
void fn_800B81BC(int);
void fn_800B8194();
int fn_803D9E3C();
void fn_803157B4(Unk8061FEDC*);
void fn_80315B34(Unk8061FEDC*, unsigned short*, int);
void fn_803158DC(Unk8061FEDC*);
void fn_80315AD8(Unk8061FEDC*);
Unk806869AC* fn_80020BCC(unsigned int id);
void fn_8002114C(Unk806869AC*, int);

int fn_800045CC(int a);
void fn_80004610();
void fn_80004658();
void fn_80004764();
void fn_800047A8(Unk8060F6F8* o);
void fn_800047D8(Unk8060F6F8* o, int a);
void fn_80004850();
void fn_800048D0();
int fn_80004568(int a);

int fn_800042B0(int a)
{
    lbl_8060F6FC = a;
    if (fn_800045CC(a)) {
        fn_800B81BC(1);
        if (lbl_8060F6F8 == 0) {
            fn_80004610();
        }
        fn_80004850();
        fn_800045CC(a);
        lbl_8060F6F8->m0 = 1;
        fn_800047D8(lbl_8060F6F8, a);
        return lbl_8060F6F8->m4;
    }
    if (lbl_8060F6F8 != 0 && lbl_8060F6F8->m0 != 0) {
        fn_80004764();
        fn_800047A8(lbl_8060F6F8);
        lbl_8060F6F8->m0 = 0;
        fn_800B81BC(0);
        fn_800B8194();
        lbl_8061A330 = 1;
        fn_800048D0();
        int s = lbl_8060F6F8->m4;
        if (lbl_8060F6F8) {
            fn_80004658();
        }
        return s;
    }
    int r;
    if (lbl_8060F6F8 == 0) r = 5;
    else r = lbl_8060F6F8->m4;
    return r;
}

void fn_800043AC()
{
    if (lbl_8060F704 != 0) {
        if (fn_801747A0() != 0) {
            fn_8042C1E8();
            fn_8042C464();
            fn_8043D3EC(1);
            fn_8043D250();
            fn_8043C580();
            switch (lbl_8060F704) {
            case 1:
                fn_80436204(0, 1, 0);
                break;
            case 2:
                fn_80436204(1, 1, 0);
                break;
            case 3:
                fn_80436204(1, 1, 1);
                break;
            default:
                fn_80436204(2, 1, 1);
                break;
            }
        }
    }
}

int fn_8000446C()
{
    int s = 5;
    int flag = 0;
    int t;
    do {
        fn_800043AC();
        if (fn_804367C8()) {
            lbl_8060F708 = 1;
        } else if (lbl_8060F708 != 0 && lbl_8060F704 == 0 && s != 4) {
            lbl_8060F704 = (s != 5) ? 2 : 1;
        }
        if (fn_801747A0() == 0) {
            break;
        }
        t = fn_804250B0();
        s = fn_800042B0(t);
        if (flag == 0 && s != 5) {
            fn_80439918(0, 0);
            flag = 1;
            fn_80439918(1, 0);
            fn_80439918(2, 0);
            fn_80439918(3, 0);
        }
    } while (s != 5 || t == -1);
    return 0;
}

int fn_80004568(int a)
{
    switch (a) {
    case 5:
        return 0;
    case 4:
        return 1;
    case 6:
        return 2;
    case 11:
        return 3;
    case -1:
        return 4;
    default:
        return 5;
    }
}

int fn_800045CC(int a)
{
    int r = fn_80004568(a);
    if (lbl_8060F6F8) {
        lbl_8060F6F8->m4 = r;
    }
    return r != 5;
}

void fn_80004610()
{
    if (lbl_8060F6F8) {
        fn_80004658();
    }
    lbl_8060F6F8 = new Unk8060F6F8;
}

void fn_80004658()
{
    fn_800047A8(lbl_8060F6F8);
    delete lbl_8060F6F8;
    lbl_8060F6F8 = 0;
}

Unk8060F6F8::Unk8060F6F8()
{
    mC = 0;
    lbl_8060F6FC = 0;
    m4 = 5;
    lbl_8060F704 = 0;
    m0 = 0;
}

Unk8060F6F8::~Unk8060F6F8()
{
    fn_80004830();
}

void fn_80004710(Unk8060F6F8* o)
{
    if (o->mC == 0 && fn_803D9E3C() == 0) {
        fn_803157B4(lbl_8061FEDC);
        o->mC = 1;
    }
}

void fn_80004764()
{
    fn_80315B34(lbl_8061FEDC, lbl_8060F128[5], 0);
    fn_803158DC(lbl_8061FEDC);
}

void fn_800047A8(Unk8060F6F8* o)
{
    o->mC = 0;
    fn_80315AD8(lbl_8061FEDC);
}

void fn_800047D8(Unk8060F6F8* o, int a)
{
    fn_80004710(o);
    fn_80315B34(lbl_8061FEDC, lbl_8060F128[fn_80004568(a)], 1);
}

void Unk8060F6F8::fn_80004830()
{
    lbl_8060F6F8->m4 = 5;
    lbl_8060F6FC = 0;
}

inline bool Unk80624260_Active()
{
    return lbl_80624260 != 0;
}

void fn_80004850()
{
    if (Unk80624260_Active()) {
        Unk806869AC* o = fn_80020BCC(lbl_806869AC.m0);
        if (o) {
            int n = o->m4 * 19 / 20 - 1;
            if (n < 0) {
                n = 0;
            }
            fn_8002114C(o, n);
        }
    }
}

void fn_800048D0()
{
    if (Unk80624260_Active()) {
        Unk806869AC* o = fn_80020BCC(lbl_806869AC.m0);
        if (o) {
            fn_8002114C(o, 100);
        }
    }
}

/* ---- static initializer: thirteen unit vectors, five dates, one hash ---- */

struct Vec3 {
    float x;
    float y;
    float z;
};

float fn_804028E4(float x);               /* square root */
extern const Vec3 lbl_806055AC;           /* shared 0xC-byte constant: the fallback for a zero-length vector */

inline Vec3 VSub(const Vec3& a, const Vec3& b)
{
    Vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline Vec3 VNormalize(const Vec3& v, float len)
{
    Vec3 r;
    float inv = 1.0f / len;
    r.x = v.x * inv;
    r.y = v.y * inv;
    r.z = v.z * inv;
    return r;
}

inline float LengthR(const Vec3& v)
{
    return fn_804028E4(v.x * v.x + v.y * v.y + v.z * v.z);
}

/* v is a const reference to the by-value copy retail makes of VSub's result: with a by-value
 * parameter here, the compiler folds &v into frame offsets and the registers differ. */
inline Vec3 VUnit(const Vec3& v)
{
    float len = LengthR(v);
    if (len != 0.0f) {
        return VNormalize(v, len);
    }
    return lbl_806055AC;
}

/* Four bytes: month-like value (3..11), day-like value (1..31), 2005. The parameter order
 * (day, month, year) is the one that reproduces retail's register allocation; the other
 * orders that do are (day, year, month) and (year, day, month). */
struct Unk80686998 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    Unk80686998(int day, int month, int year)
    {
        m0 = month;
        m1 = day;
        m2 = year;
    }
};

/* Corner points (retail .rodata 0x805A3410..0x805A343C) and the centre (0x805A3440). The centre is
 * a separate object: its address is not derived from the corners' (separate lis in retail). */
static const Vec3 lbl_805A3410[4] = {
    { 7.5f, 0.0f, 1072.5f },
    { 1080.0f, 0.0f, 1080.0f },
    { 1072.5f, 0.0f, 7.5f },
    { 7.5f, 0.0f, 7.5f },
};
static const Vec3 lbl_805A3440 = { 513.3595f, 0.0f, 513.3595f };

Vec3 lbl_806868FC = VUnit(VSub(lbl_805A3440, lbl_805A3410[3]));
Vec3 lbl_80686908 = VUnit(VSub(lbl_805A3410[3], lbl_805A3440));
Vec3 lbl_80686914 = VUnit(VSub(lbl_805A3410[2], lbl_805A3410[1]));
Vec3 lbl_80686920 = VUnit(VSub(lbl_805A3410[1], lbl_805A3410[2]));
Vec3 lbl_8068692C = VUnit(VSub(lbl_805A3410[1], lbl_805A3410[0]));
Vec3 lbl_80686938 = VUnit(VSub(lbl_805A3410[0], lbl_805A3410[1]));
Vec3 lbl_80686944 = VUnit(VSub(lbl_805A3410[2], lbl_805A3410[3]));
Vec3 lbl_80686950 = VUnit(VSub(lbl_805A3410[3], lbl_805A3410[2]));
Vec3 lbl_8068695C = VUnit(VSub(lbl_805A3410[3], lbl_805A3410[1]));
Vec3 lbl_80686968 = VUnit(VSub(lbl_805A3410[0], lbl_805A3410[3]));
Vec3 lbl_80686974 = VUnit(VSub(lbl_805A3410[3], lbl_805A3410[0]));
Vec3 lbl_80686980 = VUnit(VSub(lbl_805A3410[2], lbl_805A3410[0]));
Vec3 lbl_8068698C = VUnit(VSub(lbl_805A3410[0], lbl_805A3410[2]));

Unk80686998 lbl_80686998(1, 3, 2005);
Unk80686998 lbl_8068699C(29, 3, 2005);
Unk80686998 lbl_806869A0(15, 5, 2005);
Unk80686998 lbl_806869A4(31, 7, 2005);
Unk80686998 lbl_806869A8(1, 11, 2005);
Unk806869AC_Id lbl_806869AC("test", 0);
