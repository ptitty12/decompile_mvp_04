/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80039B04-0x8003AEE4 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80039B04.h"

struct Unk8004072C_Obj {
    char pad0[0x5F8];
    int m5F8;
};

struct Unk80306AC0_Obj {
    char pad0[0x734];
    int m734;
};

struct Unk805B17A0 {
    int m0;
    int m4;
    int m8;
    int mC[3];
};
extern Unk805B17A0 lbl_805B17A0[];
extern Unk80306AC0_Obj* lbl_80616EF0[2];
extern int lbl_80616EE0;
extern int lbl_80616EE4;
extern int lbl_80616EE8;
extern int lbl_80616EEC;
extern int lbl_80616EF8;
extern int lbl_80616EFC;
extern int lbl_80616F00;
extern int lbl_80616F04;
extern int lbl_80616F10;
extern int lbl_80616F14;
extern Unk80616F18_Entry lbl_80616F18[];
extern float lbl_805A747C;
extern float lbl_805A7480;
extern float lbl_805A7484;
extern float lbl_805A74A4;
extern float lbl_805A74A8;
extern float lbl_805A74AC;
extern float lbl_805A74B0;
extern float lbl_805A75B8;
extern const char lbl_805A74B4[];
extern const char lbl_805A74C0[];
extern const char lbl_805A74D0[];
extern const char lbl_805A74D8[];
extern const char lbl_805A74E8[];
extern const char lbl_805A74F8[];
extern const char lbl_805A750C[];
extern const char lbl_805A7518[];
extern const char lbl_805A7528[];
extern const char lbl_805A7530[];
extern const char lbl_805A753C[];
extern const char lbl_805A754C[];
extern const char lbl_805A7554[];
extern const char lbl_805A7560[];
extern const char lbl_805A7570[];
extern const char lbl_805A7580[];
extern const char lbl_805A7588[];
extern const char lbl_805A7594[];
extern const char lbl_805A75A8[];

void fn_80306AC0(int a, int b);
void fn_80039790(float f);
Unk80039B04_Mgr* fn_80038EB4();
int fn_8040ABA0();
void* fn_8004072C();
int fn_800412AC(void* o, int a, int b, int c, int d, int e);
void fn_8004181C(void* o, int a, int b, int c, int d, int e, int f);
void fn_80040DCC(void* o, int a, int b);
Unk800475EC_Obj* fn_800475EC();
int fn_8003E844(Unk8003A5DC* self);
void fn_8003D394(Unk8003A5DC* self);
void fn_8003D554(Unk8003A5DC* self);
void fn_8003D648(Unk8003A5DC* self);
void fn_8003D8DC(Unk8003A5DC* self);
void fn_8003D944(Unk8003A5DC* self, int a, int b, int c, int d);
void fn_8003B56C(Unk8003A5DC* self);
void fn_8003B618(Unk8003A5DC* self);
void fn_8003B674(Unk8003A5DC* self);
extern int lbl_806EF9B4;
void fn_8001B2A4();
void fn_8001B8F8(int a);
void fn_8037B7E4(Unk8037B3E8* self, int a);

void fn_80039B94(int a, int b);
void fn_80039C20(Unk80039B04_Mgr* self);
int fn_80039C9C(int a);

void fn_80039B04(int a, int b)
{
    int v = lbl_805B17A0[a].m8;
    if (v != 0) {
        if (v == 2 && a != 6 && b == 2)
            v = 3;
        if (fn_80039C9C(v) != 0)
            fn_80039B94(v, lbl_805B17A0[a].mC[b]);
    }
}

void fn_80039B94(int a, int b)
{
    int i;
    for (i = 0; i <= lbl_80616F04; i++) {
        Unk80306AC0_Obj* o = lbl_80616EF0[i];
        if (o)
            fn_80306AC0(o->m734, a);
    }
    lbl_80616EEC = a;
    lbl_80616EF8 = b * 60;
}

void fn_80039C20(Unk80039B04_Mgr* self)
{
    int i;
    for (i = 0; i <= lbl_80616F04; i++)
        fn_80306AC0(lbl_80616EF0[i]->m734, 0);
    lbl_80616EEC = 0;
    lbl_80616EF8 = 0;
}

int fn_80039C9C(int a)
{
    int r = 0;
    switch (a) {
    case 3:
        if (lbl_80616EEC == 3 || lbl_80616EEC == 0 || lbl_80616EEC == 2 || lbl_80616EEC == 1)
            r = 1;
        break;
    case 2:
        if (lbl_80616EEC == 2 || lbl_80616EEC == 0 || lbl_80616EEC == 1)
            r = 1;
        break;
    case 1:
        if ((unsigned)lbl_80616EEC <= 1)
            r = 1;
        break;
    case 0:
        break;
    }
    return r;
}

Unk80034E14* fn_80039D28(Unk80039B04_Mgr* self, int i)
{
    return self->m52CC[i];
}

int fn_80039D38(Unk80039B04_Mgr* self, unsigned int i)
{
    int ok = 1;
    if (i > 7) {
        ok = 0;
    } else if (self->m52CC[i] == 0) {
        switch ((int)i) {
        case 3:
        case 6:
            self->m52CC[i] = new (0) Unk80034E14;
            if (self->m52CC[i] == 0)
                ok = 0;
            break;
        case 4:
            break;
        case 0:
            break;
        }
    }
    return ok;
}

void fn_80039DBC(Unk80039B04_Mgr* self, int i)
{
    if (self->m52CC[i]) {
        self->fn_800396D0(1);
        delete self->m52CC[i];
        self->m52CC[i] = 0;
    }
}

void fn_80039E2C(Unk80039B04_Mgr* self, int a)
{
    if (self->m52EC == -1) {
        self->m52EC = fn_800412AC(fn_8004072C(), 0x3f, a, 0, 0, 0);
        fn_80039B94(1, 0x1499700);
    }
}

void fn_80039E94(Unk80039B04_Mgr* self)
{
    if (self->m52EC > -1) {
        fn_8004181C(fn_8004072C(), 0x3f, self->m52EC, 0, 0, 0, 0);
        fn_80039C20(self);
    }
    self->m52EC = -1;
}

void fn_80039EF8(Unk80039B04_Mgr* self)
{
    self->m52F0 = 1;
}

void fn_80039F04(Unk80039B04_Mgr* self)
{
    self->m52F0 = 0;
    lbl_80616EFC = 0;
    lbl_80616F00 = 0xb;
}

void fn_80039F24(Unk80039B04_Mgr* self)
{
    switch (lbl_80616F00) {
    case 5:
    case 6:
    case 7:
        switch (lbl_80616EFC) {
        case 0:
            fn_80039790(lbl_805A747C);
            break;
        case 1:
            fn_80039790(lbl_805A7480);
            break;
        case 2:
            fn_80039790(lbl_805A7484);
            break;
        }
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 9:
        self->m52F0 = 0;
        break;
    }
}

int fn_80039FD4(Unk80039B04_Mgr* self, Unk80306AC0_Obj* o)
{
    int i;
    int r = -1;
    for (i = 0; i < 2; i++) {
        if (lbl_80616EF0[i] == 0) {
            lbl_80616EF0[i] = o;
            r = i;
            if (lbl_80616F04 < r)
                lbl_80616F04 = r;
            break;
        }
    }
    return r;
}

void fn_8003A058(Unk80039B04_Mgr* self, int i)
{
    if (lbl_80616EF0[i] != 0) {
        int j;
        lbl_80616EF0[i] = 0;
        for (j = 0; j < 2; j++) {
            if (lbl_80616EF0[j] != 0)
                lbl_80616F04 = j;
        }
    }
}

void fn_8003A0B0(Unk80039B04_Mgr* self, int a)
{
    if (lbl_80616F10 == 1 && ((Unk8004072C_Obj*)fn_8004072C())->m5F8 != a) {
        if (self->m52B8 >= 0) {
            fn_80038EB4()->fn_800396D0(1);
        }
        fn_80040DCC(fn_8004072C(), 0xd, a);
        fn_80038EB4()->fn_800395B0(self->m52FC);
    }
}

void fn_8003A130(Unk80039B04_Mgr* self)
{
    if (lbl_80616F10 == 1) {
        if (lbl_80616EE0 != 0) {
            fn_80038EB4()->fn_800395B0(self->m52FC);
        } else {
            fn_80038EB4()->fn_800396D0(0);
        }
    }
}

int fn_8003A194(Unk80039B04_Mgr* self, int a, int b, float f)
{
    int found = 0;
    int result = 0;
    unsigned char pct = 0;
    int i;
    for (i = 0; i < 0x68; i++) {
        if (a == self->m4EB0[i].m0 && b >= self->m4EB0[i].m2 && b <= self->m4EB0[i].m1 && !(f < (float)self->m4EB0[i].m4) && !(f > (float)self->m4EB0[i].m3)) {
            found = 1;
            pct = self->m4EB0[i].m5;
            break;
        }
    }
    if (found == 1 && (self->m52F8 == 0 || lbl_80616EE8 == 0 || fn_8040ABA0() % 100 <= pct))
        result = 1;
    return result;
}

int fn_8003A2D8(Unk80039B04_Mgr* self, int a)
{
    int result = 0;
    if (self->m52F8 == 0 || lbl_80616EE8 == 0 || fn_8040ABA0() % 100 <= a)
        result = 1;
    return result;
}

int fn_8003A354(Unk80039B04_Mgr* self, int a, int b, float f)
{
    int found = 0;
    int result = 0;
    unsigned char pct = 0;
    int i;
    for (i = 0; i < 10; i++) {
        if (a == self->m5120[i].m0 && b >= self->m5120[i].m2 && b <= self->m5120[i].m1 && !(f < (float)self->m5120[i].m4) && !(f > (float)self->m5120[i].m3)) {
            found = 1;
            pct = self->m5120[i].m5;
            break;
        }
    }
    if (found == 1 && (self->m52F8 == 0 || lbl_80616EE8 == 0 || fn_8040ABA0() % 100 <= pct))
        result = 1;
    return result;
}

int fn_8003A498(Unk80039B04_Mgr* self, int a, int b, float f)
{
    int found = 0;
    int result = 0;
    unsigned char pct = 0;
    int i;
    for (i = 0; i < 0x32; i++) {
        if (a == self->m515C[i].m0 && b >= self->m515C[i].m2 && b <= self->m515C[i].m1 && !(f < (float)self->m515C[i].m4) && !(f > (float)self->m515C[i].m3)) {
            found = 1;
            pct = self->m515C[i].m5;
            break;
        }
    }
    if (found == 1 && (self->m52F4 == 0 || lbl_80616EE4 == 0 || fn_8040ABA0() % 100 <= pct))
        result = 1;
    return result;
}

/* near-miss: 141/142 slots; retail stores m24 first in the 20-valued group
 * (before m28), here it lands after m138. Permuting the group (1680 orders)
 * and member-initializer forms did not fix it. */
Unk8003A5DC::Unk8003A5DC() : Unk8037B3E8(0xAB6EE03F)
{
    int i;
    mC = 10;
    m10 = 4;
    m14 = m8 = m4 = lbl_805A74A4;
    m28 = 30;
    m2C = lbl_805A74A8;
    m118 = lbl_805A74AC;
    m138 = 1;
    m18 = 20;
    m1C = 20;
    m20 = 20;
    m24 = 20;
    mD0 = 0;
    mFC = 0;
    m100 = 0;
    m104 = 0;
    m108 = 0;
    m10C = 0;
    m110 = 0;
    m114 = 0;
    m11C = 0;
    m120 = 0;
    m124 = 0;
    m128 = 0;
    m12C = 0;
    m130 = 0;
    m134 = 0;
    m13C = 0;
    m140 = 0;
    m190 = -1;
    m17C = lbl_805A74B0;
    m144 = 0;
    m148 = 0;
    m14C = 0;
    m150 = 0;
    m154 = 0;
    m158 = 0;
    m15C = 0;
    m160 = 0;
    m164 = 0;
    m168 = 0;
    m16C = 0;
    m170 = 0;
    m174 = 0;
    m178 = -1;
    m180 = -1;
    m184 = -1;
    m188 = 0;
    m18C = 0;
    m194 = 0;
    m198 = 0;
    m19C = 0;
    m1A0 = 0;
    m1A4 = 0;
    m1A8 = 0;
    m1AC = 0;
    m1B0 = 0;
    m1B4 = 0;
    for (i = 0; i < 10; i++) {
        m30[i].m0 = -1;
        m30[i].m4 = 1;
        m30[i].m8 = 0;
        m30[i].mC = 0;
    }
    fn_8003B56C(this);
    fn_8003B674(this);
    fn_8003B618(this);
    fn_8003AEC0();
    for (i = 0; i < 10; i++)
        mD4[i] = (unsigned int)fn_8040ABA0() % 49152 + 0x2000;
    for (i = 0; i < 5; i++) {
        m1CC[i] = 0;
        m1B8[i] = 0;
    }
}

void Unk8003A5DC::fn_vslot2()
{
    ::fn_8037B7E4(this, lbl_80616F14);  /* global: chooser.h declares a member of the same name */
    fn_8037B7E8(lbl_805A74B4);
    fn_8037B494(lbl_805A74C0, &mC, lbl_805A74D0, 0);
    fn_8037B50C(lbl_805A74D8, &m4, lbl_805A74E8, 0);
    fn_8037B50C(lbl_805A74F8, &m8, lbl_805A74E8, 0);
    fn_8037B830(lbl_805A74B4);
    fn_8037B7E8(lbl_805A750C);
    fn_8037B494(lbl_805A7518, &m10, lbl_805A7528, 0);
    fn_8037B50C(lbl_805A7530, &m14, lbl_805A74E8, 0);
    fn_8037B494(lbl_805A753C, &m18, lbl_805A754C, 0);
    fn_8037B494(lbl_805A7554, &m1C, lbl_805A754C, 0);
    fn_8037B494(lbl_805A7560, &m20, lbl_805A754C, 0);
    fn_8037B494(lbl_805A7570, &m24, lbl_805A754C, 0);
    fn_8037B830(lbl_805A750C);
    fn_8037B7E8(lbl_805A7580);
    fn_8037B494(lbl_805A7588, &m28, lbl_805A754C, 0);
    fn_8037B50C(lbl_805A7594, &m2C, lbl_805A75A8, 0);
    fn_8037B830(lbl_805A7580);
}

Unk8003A5DC::~Unk8003A5DC()
{
}

void fn_8003AA14(Unk8003A5DC* self)
{
    fn_8037C7FC()->fn_8037CE98(0xAB6EE03F, (int)self, 0);
}

Unk8037B3E8* Unk8003A5DC::fn_vslot5()
{
    return new (lbl_806EF9B4) Unk8003A5DC;
}

void Unk8003A5DC::fn_vslot8()
{
}

void Unk8003A5DC::fn_vslot11()
{
    if (m110 == 1) {
        Unk800475EC_Obj* o = fn_800475EC();
        int c = 0;
        if (o->mF4 == 1)
            c = o->mC00 >= 0;
        if (c == 1 && fn_8003E844(this) == 1) {
            int i;
            mFC = mFC - 1;
            m100 = m100 - 1;
            m104 = m104 - 1;
            m108 = m108 - 1;
            if (mD0 != 0) {
                for (i = 0; i <= 9; i++) {
                    if (m30[i].mC != 0) {
                        m30[i].mC = m30[i].mC - 1;
                        if (m30[i].mC == 0) {
                            int j;
                            for (j = 0; j <= 0x19; j++) {
                                if (lbl_80616F18[j].m0 == m30[i].m0) {
                                    (this->*lbl_80616F18[j].m4)(i);
                                    break;
                                }
                            }
                            mD0 = mD0 - 1;
                        }
                    }
                }
            }
            if (mFC <= 0) {
                fn_8003D394(this);
                fn_8003B56C(this);
            }
            if (m100 <= 0) {
                fn_8003D554(this);
                fn_8003B56C(this);
            }
            if (m104 <= 0) {
                fn_8003D648(this);
                fn_8003B674(this);
            }
            if (m108 <= 0) {
                int r = fn_8040ABA0();
                r %= 100;
                if ((m124 == 3 || m124 == 0x1d) && r <= 0x27)
                    fn_8001B8F8(m124);
                else if (r <= 0x31)
                    fn_8001B2A4();
                else
                    fn_8003D8DC(this);
                fn_8003B618(this);
            }
        }
    }
}

void Unk8003A5DC::fn_vslot12()
{
    int i;
    mD0 = 0;
    m114 = 0;
    m130 = 0;
    m134 = 0;
    m13C = 0;
    m140 = 0;
    m144 = 0;
    m160 = 0;
    m164 = 0;
    m168 = 0;
    m19C = 0;
    m154 = 0;
    m148 = 0;
    m158 = 0;
    m14C = 0;
    m15C = 0;
    m150 = 0;
    m1A8 = 0;
    m1AC = 0;
    m170 = 0;
    m1B0 = 0;
    m1B4 = 0;
    m118 = lbl_805A75B8;
    m138 = 1;
    fn_8003B56C(this);
    fn_8003B674(this);
    fn_8003B618(this);
    fn_8003AEC0();
    for (i = 0; i < 10; i++) {
        m30[i].m0 = -1;
        m30[i].m4 = 1;
        m30[i].m8 = 0;
        m30[i].mC = 0;
    }
}

void Unk8003A5DC::fn_8003ADD4()
{
    void** p;
    m154 = m148;
    m158 = m14C;
    p = m10C->m65C;
    m15C = m150;
    m1A8 = m1AC;
    m148 = (p[10] == 0) ? 0 : 1;
    m14C = (p[11] == 0) ? 0 : 1;
    m150 = (p[12] == 0) ? 0 : 1;
    m1AC = 0;
    m168 = 0;
    m1B4 = 0;
    m1A4 = 0;
    m1B0 = 0;
    fn_8003AEC0();
    fn_8003D944(this, 3, (unsigned int)fn_8040ABA0() % 60, m138, m130);
}

void Unk8003A5DC::fn_8003AEC0()
{
    int i;
    for (i = 0; i < 7; i++)
        m1E0[i] = 0;
}
