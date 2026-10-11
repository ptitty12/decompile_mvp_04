/*
 * Part of the game TU 0x8000F598-0x8006902C (2,110 functions; it ends with
 * the static-initializer wrapper at 0x80069000, so it is one large, likely
 * unity-built TU). Original file boundary unknown; placeholder.
 *
 * .text 0x80030778-0x800320B8 only: every data object is extern by its lbl_ name.
 */
#include "game/tu_80030778.h"

extern "C" void fn_80030778(void* self, int* p, int max)
{
    int t = *p + 1;
    *p = t;
    if (t >= max)
        *p = max;
}

extern "C" void fn_80030794(void* self, int* p)
{
    int t = *p - 1;
    *p = t;
    if (t <= 0)
        *p = 0;
}

extern "C" void fn_800307B4(Unk8002D15C* self)
{
    if (self->mFC != 0 && self->m5A8 == 2 && self->m7E0 == 0) {
        Unk8002D15C_Owner* o = self->m80;
        int n = 0;
        if (!(o->m6CC->m3F4 <= 1.0f)) {
            Unk8014E09C_It it;
            fn_8014E09C(&it, o, 7);
            while (it.m8 != 10) {
                if (fn_801DC964(o->m700->m3B8, it.m8))
                    n++;
                fn_8014E108(&it);
            }
            if (n > 1) {
                fn_8003EF1C(self->m6C8);
                self->m7E0 = 1;
            }
        }
    }
}

Unk80030884::Unk80030884()
{
    m34 = 0;
    m30 = lbl_80616B64;
    for (int i = 0; i < 3; i++) {
        m0[i].m0 = 0;
        m0[i].m4 = 0;
        m0[i].m8 = -1;
        m0[i].mC = 0;
    }
}

Unk80030884::~Unk80030884()
{
}

extern "C" void fn_800308FC()
{
    lbl_80616B68 = new (0) Unk80030884;
}

extern "C" Unk80030884* fn_80030938()
{
    return lbl_80616B68;
}

extern "C" void fn_80030944()
{
}

extern "C" void fn_80030948(Unk80030884* self)
{
    for (int i = 0; i <= 2; i++)
        fn_80030C90(self, i);
    if (lbl_80616B68) {
        delete lbl_80616B68;
        lbl_80616B68 = 0;
    }
}

extern "C" void fn_80030C90(Unk80030884* self, int idx)
{
    int removed = 0;
    int j = 0;
    int shared = 0;
    if (self->m34 == 1 && idx >= 0 && idx <= self->m30 && self->m0[idx].m0 != 0) {
        int type = self->m0[idx].m4->m6F4;
        switch (type) {
        case 0:
            self->m0[idx].mC->v8(self->m0[idx].m8);
            delete self->m0[idx].mC;
            self->m0[idx].mC = 0;
            self->m0[idx].m0 = 0;
            removed = 1;
            self->m0[idx].m4 = 0;
            self->m0[idx].m8 = -1;
            break;
        case 2:
        case 3:
        case 4:
        case 6:
        case 7:
        case 8:
            for (j = 0; j <= self->m30; j++) {
                if (self->m0[j].m0 != 0 && self->m0[j].m4->m6F4 == type && j != idx) {
                    shared = 1;
                    break;
                }
            }
            self->m0[idx].mC->v8(self->m0[idx].m8);
            if (shared == 0)
                delete self->m0[idx].mC;
            self->m0[idx].mC = 0;
            self->m0[idx].m0 = 0;
            removed = 1;
            self->m0[idx].m4 = 0;
            self->m0[idx].m8 = -1;
            break;
        }
        if (removed == 1) {
            for (j = 0; j < 3; j++) {
                if (self->m0[j].m0 != 0)
                    self->m30 = j;
            }
        }
    }
}

extern "C" void fn_80030EA4(Unk80030884* self, int idx)
{
    if (self->m34 == 1 && idx >= 0 && idx <= self->m30 && self->m0[idx].m0 != 0)
        self->m0[idx].mC->v2(self->m0[idx].m8);
}

extern "C" void fn_80030F18(Unk80030884* self, int idx, float f)
{
    if (self->m34 == 1 && idx >= 0 && idx <= self->m30 && self->m0[idx].m0 != 0)
        self->m0[idx].mC->v3(self->m0[idx].m8, f);
}

extern "C" void fn_80030F94(Unk80030884* self, int idx)
{
    if (self->m34 == 1 && idx >= 0 && idx <= self->m30 && self->m0[idx].m0 != 0)
        self->m0[idx].mC->v6();
}

extern "C" void fn_80031000(Unk80030884* self)
{
    if (self->m34 == 1) {
        for (int i = 0; i <= self->m30; i++) {
            if (self->m0[i].m0 != 0)
                self->m0[i].mC->v5();
        }
    }
}

extern "C" void fn_80031088(Unk80030884* self)
{
    if (self->m34 == 1) {
        for (int i = 0; i <= self->m30; i++) {
            if (self->m0[i].m0 != 0)
                self->m0[i].mC->v9();
        }
    }
}

extern "C" int fn_80031110(Unk800311D0* self, int a, int b)
{
    switch (self->m78) {
    case 2:
        return b;
    case 3:
        return lbl_805B1A0C[b];
    case 4:
    case 6:
    case 7:
    case 8: {
        Unk8002D15C_Sub6F8* s = self->m80[a]->m6F8;
        int v = s->m14->m1CD0;
        int x = s->m10->m6C[0];
        int y = s->m10->m6C[1];
        int flag = 0;
        if (v != 0)
            flag = 1;
        if (x == -1 && y != -1) {
            if (flag == 1)
                return b;
            return lbl_805B1A0C[b];
        }
        if (flag == 0)
            return b;
        return lbl_805B1A0C[b];
    }
    }
    return b;
}

extern "C" Unk800311D0* fn_800311D0(Unk800311D0* self)
{
    fn_80021A60(self);
    self->vptr = lbl_806498E0;
    self->m128 = 0;
    self->m12C = 0;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    for (int i = 0; i < 3; i++) {
        self->mBC[i] = 0;
        self->mC8[i] = 0;
        self->mD4[i] = 0;
        self->mE0[i] = 0;
        self->m11C[i] = 0;
        self->m110[i] = -1;
        self->mEC[i] = 0;
        self->mF8[i] = 0;
        self->m104[i] = 0;
    }
    int r = fn_8001CC40(fn_8001C394(), 2);
    if (r == 1)
        self->m128 = r;
    return self;
}

extern "C" void fn_800312A8(Unk800311D0* self, int chrg)
{
    self->vptr = lbl_806498E0;
    fn_8005B58C(fn_8005ACE4(), 0);
    fn_800396D0(fn_80038EB4(), 1);
    for (int i = 0; i < 3; i++) {
        if (self->m80[i] != 0)
            self->m80[i] = 0;
    }
    fn_80021BB4(self, chrg);
}

extern "C" int fn_80031330(Unk800311D0* self, Unk8002D15C_Owner* o)
{
    int idx = -1;
    for (int i = 0; i <= 2; i++) {
        if (self->m80[i] == 0) {
            idx = i;
            self->m80[i] = o;
            self->m110[i] = fn_80039FD4(fn_80038EB4(), (int)o);
            if (self->m7C < idx)
                self->m7C = idx;
            break;
        }
    }
    return idx;
}

extern "C" void fn_800313C0(Unk800311D0* self, int i)
{
    if (self->m80[i] != 0) {
        fn_8003A058(fn_80038EB4(), self->m110[i]);
        self->m80[i] = 0;
        for (int j = 0; j < 3; j++) {
            if (self->m80[j] != 0)
                self->m7C = j;
        }
    }
}

extern "C" void fn_80031440(Unk800311D0* self, int a)
{
    if (self->m138 == 0)
        fn_800233B4(self, 0x1B, 0x1E, a);
}

extern "C" void fn_80031478(Unk800311D0* self)
{
    if (self->m138 == 0) {
        fn_8005C250(fn_8005BA9C(), 2);
        float f = 0.45f;
        Unk8002D15C_Owner* o = self->m80[0];
        if (o != 0)
            f = fn_8017FA08((int)o->m700 + 0x24);
        fn_8003968C(fn_80038EB4(), 2);
        fn_80039854(fn_80038EB4(), 0, f);
        fn_80039790(fn_80038EB4(), f);
        fn_800398E4(fn_80038EB4(), 0.0f);
        fn_800395B0(fn_80038EB4(), 2);
        fn_80039790(fn_80038EB4(), f);
        self->m138 = 1;
        fn_8005AF00(fn_8005ACE4(), 0);
        self->m13C = 1;
    }
}

extern "C" int fn_80031548(Unk800311D0* self)
{
    int n = 0;
    for (int i = 0; i < 3; i++) {
        if (self->m80[i] != 0)
            n++;
    }
    return n;
}

extern "C" void fn_80031A20(Unk800311D0* self, int i, Unk8002D15C_Msg* msg)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(msg, 0x3A);
    self->m104[i] = m->m14;
    int t = self->mF8[i] + 1;
    self->mF8[i] = t;
    if (t > 4)
        self->mF8[i] = 4;
    if (self->m104[i] == 1)
        fn_80021E30(self, self->m80[i], 0x5A);
}

extern "C" void fn_80031AAC(Unk800311D0* self, int i, Unk8002F894_Ev* ev)
{
    int t = ev->m4;
    Unk8002D15C_Player* p = ev->m8;
    if ((unsigned int)t <= 1 || t == 3 || t == 6 || t == 4 || t == 5 || t == 9) {
        Unk8002F894_Obj o;
        o.Base(0x3B);
        o.Derived();
        int x;
        if (t == 0)
            x = 0xA;
        else if (t == 1)
            x = 0xB;
        else if (t == 4)
            x = 3;
        else if (t == 5)
            x = 4;
        else if (t == 6)
            x = 1;
        else if (t == 9)
            x = 6;
        else
            x = 0xD;
        o.Set(x, p);
        fn_8037893C((char*)p->m44C + 0x704, o.m0, &o, 0, 0);
        fn_803444D0(&o, 2);
    }
}

extern "C" void fn_80031F80(Unk800311D0* self, int i, Unk8002D15C_Msg* msg)
{
    Unk8002D15C_Msg* m = Unk8002D15C_AsMsg(msg, 0x58);
    Unk8002D15C_Player* p = (Unk8002D15C_Player*)m->mC;
    int r = p->m460;
    if (m->m20 == 1) {
        Unk8002D15C_Cc* c = self->m80[i]->m6CC;
        float d = c->m3F4 - 0.016666668f;
        float len;
        Unk8002D15C_Vec3 v = fn_80196E3C(c->m448, d);
        len = fn_804028E4(v.m0 * v.m0 + v.m4 * v.m4 + v.m8 * v.m8) * 0.05681818f;
        int n = (int)(float)fn_80410634(len) + 0xC;
        fn_80021EB4(self, self->m80[i], r, 2, n);
    }
    if (p != 0 && r == 1 && self->mE0[i] == 1)
        fn_80039A3C(fn_80031110(self, i, 3), 2, 0);
}

extern "C" void fn_800320B4()
{
}
