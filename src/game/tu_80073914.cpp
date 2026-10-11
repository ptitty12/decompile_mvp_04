/*
 * Game code, .text 0x80073914-0x80077238 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8007A4DC.h"

/* View of a widget whose slot 0x38 returns a float (fn_800745C4). */
struct Unk800745C4_WBase {
    char pad0[0x20];
};
struct Unk800745C4_W : Unk800745C4_WBase {
    virtual int v08();
    virtual int v10(int i);
    virtual int v18(int a);
    virtual int v20();
    virtual int v28(int a, int b);
    virtual int v30(int a, int b, char* c);
    virtual float v38(int a, int b);
};
extern const float lbl_805B3D0C;
extern const char* lbl_80622810;
extern const char* lbl_80622814;
extern const int lbl_805B6428[];
extern const int lbl_805B64A8[];
extern const int lbl_805B6698[];
extern const int lbl_805B6888[];
extern const int lbl_805B6968[];
extern const int lbl_805B6A48[];
extern const int lbl_805B6B28[];
extern const char lbl_805B3F4C[];
extern const char lbl_805B3F58[];
unsigned fn_800736EC(const char* s);
unsigned fn_8007366C(const char* a, const char* b);
int fn_80075868(int id);
int fn_80076058(int a, int b);
int fn_80329FA0(int* out, int c, ...);
int fn_804089B4(char* buf, const char* fmt, ...);
void fn_80075A44(Unk8007B2B0_Screen* s, int a, int i);
int fn_80075808(int id);
int fn_80075D48(int i);
int fn_80075D64(int i);
int fn_80075CC0(int y);
int fn_80075D80(int a);
int fn_800761D8(int x);
int fn_80075DCC(int i);
int fn_80075EF4(int x);
int fn_80075F08(int x);
int fn_800909A4(Handle* h, int a, Obj* o);
void fn_80090A24(Handle* h, int r);
extern const char* lbl_80622818;
extern const char* lbl_8062281C;
extern const char* lbl_80622820;
extern const char* lbl_80622824;

struct Unk80075CF0_Date {
    unsigned short m0;
    unsigned short m2;
};

int Unk8007A4DC_Screen::fn_80073914(int a, int b, int i)
{
    int r;
    if (i > 1)
        r = fn_80073710(a, fn_80072894(b), i);
    else
        r = m190[i].m0->v28(a, b);
    return r;
}

void Unk8007A4DC_Screen::fn_80073994(int a, int b, int i, int c)
{
    if (i <= 1)
        m190[i].m0->v40(a, b, c);
}

void Unk8007A4DC_Screen::fn_800743A0(int a, int b, int i, int j, int c)
{
    if (j <= 1 && i <= 1) {
        W* w = m190[i].m4[j];
        w->v40(a, fn_80071814(w, b), c);
    }
}

void Unk8007A4DC_Screen::fn_80074500(int a, int b, int i, int j, int c)
{
    if (j <= 1 && i <= 1)
        m190[i].m4[j]->v40(a, b, c);
}

int Unk8007A4DC_Screen::fn_8007455C(int a, int b, int i)
{
    W* w = m1A8[i];
    return w->v28(a, fn_80071814(w, b));
}

float Unk8007A4DC_Screen::fn_800745C4(int a, int b, int i)
{
    if (i <= 4) {
        W* w = m1A8[i];
        return ((Unk800745C4_W*)w)->v38(a, fn_80071814(w, b));
    }
    return lbl_805B3D0C;
}

void Unk8007A4DC_Screen::fn_80074640(int a, int b, int i, int c)
{
    if (i <= 4) {
        W* w = m1A8[i];
        w->v40(a, fn_80071814(w, b), c);
    }
}

int Unk8007A4DC_Screen::fn_800746B8(int a, int b, int i)
{
    int r;
    if (i > 4)
        r = 0;
    else
        r = m1A8[i]->v28(a, b);
    return r;
}

void Unk8007A4DC_Screen::fn_80074708(int a, int b, int i, int c)
{
    if (i <= 4)
        m1A8[i]->v40(a, b, c);
}

void Unk8007A4DC_Screen::fn_80074F50(int a, int b, int i, int c)
{
    if (i <= 1) {
        W* w = m1CC[i].m0;
        w->v40(a, fn_80071814(w, b), c);
    }
}

int Unk8007A4DC_Screen::fn_80074FC8(int a, int b, int i)
{
    int r;
    if (i > 1)
        r = fn_80074754(a, fn_800728E4(b), i);
    else
        r = m1CC[i].m0->v28(a, b);
    return r;
}

void Unk8007A4DC_Screen::fn_80075048(int a, int b, int i, int c)
{
    if (i <= 1)
        m1CC[i].m0->v40(a, b, c);
}

void Unk8007A4DC_Screen::fn_800755FC(int a, int b, int i, int j, int c)
{
    if (i <= 1 && j <= 1) {
        W* w = m1CC[i].m4[j];
        w->v40(a, fn_80071814(w, b), c);
    }
}

void Unk8007A4DC_Screen::fn_8007575C(int a, int b, int i, int j, int c)
{
    if (j <= 1 && i <= 1)
        m1CC[i].m4[j]->v40(a, b, c);
}

int Unk8007B2B0_Screen::fn_800757B8()
{
    int r = fn_80075948();
    if (r != 0 && fn_8007B3E0(0xE, r) != 0)
        return 1;
    return 0;
}

int fn_80075808(int id)
{
    int a = fn_800736EC(lbl_80622810);
    int b = fn_800736EC(lbl_80622814);
    int r = 0;
    if (id == a || id == b)
        r = 1;
    return r;
}

int fn_80075868(int id)
{
    int a = fn_800736EC(lbl_80622818);
    int b = fn_800736EC(lbl_8062281C);
    int c = fn_800736EC(lbl_80622820);
    int d = fn_800736EC(lbl_80622824);
    int r = 0;
    if (id == a || id == b || id == c || id == d)
        r = 1;
    return r;
}

int fn_800758F8(int id)
{
    int r = 0;
    if (fn_80075808(id) || fn_80075868(id))
        r = 1;
    return r;
}

void fn_800759F8(Unk8007B2B0_Screen* s, int a)
{
    int i = 0;
    do {
        fn_80075A44(s, a, i++);
    } while (i <= 0x3E);
}

int Unk8007B2B0_Screen::fn_80075C64(int id)
{
    int i;
    for (i = 0; i <= 3; i++) {
        if (fn_8007DA34(i) == id)
            return i;
    }
    return 5;
}

int fn_80075CC0(int y)
{
    unsigned short idx = (y - 2005) % 32;
    return lbl_805B6428[idx];
}

int fn_80075CF0(int a, int x)
{
    int v = fn_80075D80(a);
    Unk80075CF0_Date d;
    fn_80329FA0((int*)&d, x);
    return v == fn_80075CC0(d.m2);
}

int fn_80075D48(int i)
{
    return lbl_805B64A8[i] >= 0;
}

int fn_80075D64(int i)
{
    return lbl_805B6698[i] >= 0;
}

int fn_80075D80(int i)
{
    int r = 0;
    if (fn_80075D48(i) == 1)
        r = lbl_805B64A8[i];
    return r;
}

int fn_80075DCC(int i)
{
    int r;
    if (fn_80075D64(i) == 0)
        r = 0;
    else
        r = lbl_805B6698[i];
    return r;
}

int fn_80075E18(int i, int kind)
{
    int v = -1;
    switch (kind) {
    case 0:
        v = lbl_805B6888[i];
        break;
    case 1:
        v = lbl_805B6968[i];
        break;
    case 2:
        v = lbl_805B6A48[i];
        break;
    }
    return v >= 0;
}

int fn_80075E7C(int x)
{
    int i;
    for (i = 0; i <= 0x37; i++) {
        int j;
        for (j = 0; j <= 2; j++) {
            if (fn_80076058(i, j) == x)
                return i;
        }
    }
    if ((unsigned)(x - 0x25) <= 1)
        return 0x34;
    return 0;
}

int fn_80075EF4(int x)
{
    return (unsigned)(x - 0x1E) <= 0xF;
}

int fn_80075F08(int x)
{
    return (unsigned)(x - 0x2E) <= 8;
}

int fn_80075F1C(int id, int a, int b)
{
    int i;
    int j;
    for (i = 0; i <= 0x7B; i++) {
        if (fn_80075D48(i)) {
            int v;
            v = fn_80075D80(i);
            for (j = 0; j <= 2; j++) {
                if (fn_80075E18(v, j) && fn_80076058(v, j) == id)
                    return i;
            }
        }
    }
    for (i = 0; i <= 0x7B; i++) {
        if (fn_80075D64(i)) {
            int v;
            v = fn_80075DCC(i);
            for (j = 0; j <= 2; j++) {
                if (fn_80075E18(v, j) && fn_80076058(v, j) == id)
                    return i;
            }
        }
    }
    if (a != 0 && fn_800761D8(id) != 0)
        return 0;
    if (b != 0 && id > 0x4D && id <= 0x53)
        return 0x29;
    return 0;
}

/* near-miss: 6 slots; retail loads the last table entry into r0 and copies it to r3 (mr r3,r0). */
int fn_80076058(int i, int kind)
{
    int v = -1;
    switch (kind) {
    case 0:
        v = lbl_805B6888[i];
        break;
    case 1:
        v = lbl_805B6968[i];
        break;
    case 2:
        v = lbl_805B6A48[i];
        break;
    }
    int t;
    int u;
    if (v >= 0 || ((t = lbl_805B6968[i]) == -1 && (t = lbl_805B6A48[i]) == -1 && (u = lbl_805B6888[i], t = u, u == -1)))
        return v;
    return t;
}

int fn_80076104(int id, int a, int b)
{
    int i;
    for (i = 0; i <= 0x7B; i++) {
        if (fn_80075D48(i) && fn_80075D80(i) == id)
            return i;
    }
    for (i = 0; i <= 0x7B; i++) {
        if (fn_80075D64(i) && fn_80075DCC(i) == id)
            return i;
    }
    if (a != 0 && fn_80075EF4(id) != 0)
        return 0;
    if (b != 0 && fn_80075F08(id) != 0)
        return 0x29;
    return 0;
}

int fn_800761D8(int x)
{
    int r = 0;
    switch (x) {
    case 6:
    case 10:
    case 12:
    case 23:
    case 27:
    case 29:
    case 39:
    case 65:
    case 69:
    case 71:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 86:
        r = 1;
    }
    return r;
}

int fn_80076270(int x)
{
    int r = 0;
    switch (x) {
    case 6:
    case 10:
    case 12:
    case 23:
    case 27:
    case 29:
    case 39:
    case 76:
        r = 1;
    }
    return r;
}

int Unk8007A4DC_Screen::fn_800764F4(const char* a, const char* b, int c)
{
    Handle* h = &m17C;
    int r = fn_800909A4(h, fn_8007366C(a, b), 0);
    fn_80090A24(h, r);
    if (c == 0 || c == 10)
        fn_80090A24(&m1C0, r);
    fn_8007A808(0xB, r, 0);
    return r;
}

int fn_80076584(int a, int b)
{
    int r = b == 0;
    if (b == 2 && a == 1)
        r = 1;
    return r;
}

unsigned fn_800765A8(int x)
{
    char a[0x40];
    char b[0x40];
    int s = x << 2;
    fn_804089B4(a, lbl_805B3F4C, x, s);
    fn_804089B4(b, lbl_805B3F58, x, s);
    return fn_8007366C(a, b);
}

int Unk8007A4DC_Screen::fn_8007661C(int b)
{
    return fn_8007A6A0(5, b);
}

int fn_80076644(int a, int b, int c)
{
    if (a <= 9) {
        int t = lbl_805B6B28[a];
        int r = 0;
        if (((t >> b) & 1) || ((t >> c) & 1))
            r = 1;
        return r;
    }
    return 0;
}

int fn_8007668C(int a, int b)
{
    if (a <= 9)
        return (lbl_805B6B28[a] >> b) & 1;
    return 0;
}
