/*
 * Game code, .text 0x8010A0A4-0x8010E0F4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"
struct Ui10A3FC : UiObj {
    char pad40[0x134 - 0x40];
    UiObj* m134;
};
void fn_80109F58(Ui9F58* self, int a, int b);
extern char lbl_805BF8B0[];
extern char lbl_805BF8BC[];

inline int UiIntAt(char* b, int i)
{
    int o = i * 4;
    return *(int*)(b + o);
}

struct Ui10D618 : UiObj {
    char pad40[0x13C - 0x40];
    UiObj* m13C;
    int m140;
    char pad144[0x148 - 0x144];
    UiObj* m148;
    UiObj* m14C;
    char pad150[0x168 - 0x150];
    int m168;
    int a16C[25];
    int a1D0[1];
};

extern "C" void* fn_800C8058(int);
void fn_800ECE34(UiObj* self);
extern char lbl_805BE234[];
struct Ui10C51C : UiObj {
    char pad40[0x140 - 0x40];
    int m140;
    int m144;
    UiObj* m148;
    UiObj* m14C;
    int m150;
    char pad154[0x168 - 0x154];
    int m168;
};
void fn_8010A808(Ui10C51C* self);
void fn_8010B6B8(Ui10C51C* self);
void fn_8010BF88(Ui10C51C* self);
int fn_800E6058(int a);
int fn_8008CFD8(char* p, int a, int b);
void fn_8040321C(short* a, int b, short* buf, int c);

extern char lbl_80649DA0[];
extern char lbl_8065B990[];
extern char lbl_8065B9A8[];
struct UiEvtBase10A150 {
    int id;
    const void* vt;
    UiEvtBase10A150(int i)
    {
        vt = lbl_80649DA0;
        id = i;
    }
    ~UiEvtBase10A150() { vt = lbl_80649DA0; }
};
struct UiEvt10A284 : UiEvtBase10A150 {
    int m8;
    UiEvt10A284(int i, int v) : UiEvtBase10A150(i)
    {
        m8 = v;
        vt = lbl_8065B9A8;
    }
    ~UiEvt10A284() { vt = lbl_80649DA0; }
};
struct UiEvt10A150 : UiEvtBase10A150 {
    int m8;
    UiEvt10A150(int i, int v) : UiEvtBase10A150(i)
    {
        m8 = v;
        vt = lbl_8065B990;
    }
    ~UiEvt10A150() { vt = lbl_80649DA0; }
};
void fn_800DE440(short* buf, int a, int b);
int fn_800968C0(char* e, int a, int b);
int fn_80097148(char* e, int a);
int fn_80097210(char* e, int a);
int fn_801A4A94(Ui8011AA24* g, int a);
void fn_804031F8(short* a, int b, short* buf);
struct Ui10C7F0 : UiObj {
    char pad40[0x140 - 0x40];
    int m140;
    char pad144[0x150 - 0x144];
    int m150;
};
void fn_8010F494(void* a, int b);
void fn_8010F2CC(void* a);
int fn_8010D1C8();
void fn_8010D1D0();
extern char lbl_805BA6D8[];
struct Ui10D0C0 : UiObj {
    char pad40[0x134 - 0x40];
    Ui2F0Obj* m134;
    char pad138[0x144 - 0x138];
    int m144;
    char pad148[0x15C - 0x148];
    int m15C;
};
struct Ui10AF80 {
    char pad0[0x44C];
    Ui8011AA24* m44C;
    char pad450[0x704 - 0x450];
    int m704;
    int m708;
};
struct Unk800DB840_Slot;
int fn_800DBAE0(Unk800DB840_Slot* o, int a, int idx, int b);

void fn_8010A0A4(UiV_138_13C* self)
{
    self->m13C->v16(0);
    self->m13C->v8(0);
    self->m13C = 0;
    self->v16(1);
    self->m138->v16(1);
}

void fn_8010A150(short* a, int flag)
{
    int p;
    if (flag != 0)
        p = fn_800B555C()->m574;
    else
        p = fn_800B555C()->m578;
    char* e = (char*)fn_8011AA24(0)->m6F8->m14 + p * 0xE64;
    int t;
    for (int i = 0; i <= 9; i++) {
        t = fn_80097210(e, i);
        if (fn_80097148(e, fn_800968C0(e, t, 1)) == 3) {
            UiEvt10A150 ev(0x7A, fn_801A4A94(fn_8011AA24(0), t));
            fn_8037893C(fn_8011AA24(0)->m704, ev.id, (UiEvtRaw*)&ev, 0, 0);
            break;
        }
    }
    short buf[100];
    fn_800DE440(buf, t, 0);
    fn_804031F8(a, fn_80090880(lbl_8061977C, 0x414A), buf);
}

/* near-miss: 2 words swapped (retail: mr r4,r28 / li r5,0 / mr r3,r27 before the fn_800DE440 call; ours sets r3 before r5) */
void fn_8010A284(short* a, int flag)
{
    int p;
    if (flag != 0)
        p = fn_800B555C()->m574;
    else
        p = fn_800B555C()->m578;
    char* e = (char*)fn_8011AA24(0)->m6F8->m14 + p * 0xE64;
    int t;
    for (int i = 0; i <= 9; i++) {
        t = fn_80097210(e, i);
        if (fn_80097148(e, fn_800968C0(e, t, 1)) == 1) {
            UiEvt10A284 ev(0x78, fn_801A4A94(fn_8011AA24(0), t));
            fn_8037893C(fn_8011AA24(0)->m704, ev.id, (UiEvtRaw*)&ev, 0, 0);
            break;
        }
    }
    short buf[100];
    fn_800DE440(buf, t, 0);
    int k = fn_800968C0(e, t, 1);
    int q = fn_8008CFD8(e + 0xC9C, 0x1E, k);
    int s = fn_80090880(lbl_8061977C, 0x396D);
    fn_8040321C(a, s, buf, fn_80090880(lbl_8061977C, fn_800E6058(q)));
}

void fn_8010A3FC(Ui10A3FC* self)
{
    Ui8011AA24* g = fn_8011AA24(0);
    int p = fn_800B555C()->m578;
    int v = UiIntAt((char*)lbl_806192E0->m4->m10 + 0x6C, p);
    fn_800B555C()->m570 = v;
    fn_800C80C0(self, v);
    int r = fn_8017E030(g->m700, p, 0);
    UiObj* o = self->m134;
    short buf[500];
    switch (r) {
    case 0:
        break;
    case 1:
        o->v91(1, 0, 1);
        o->v67(1, 0);
        fn_80109F58((Ui9F58*)self, fn_80090880(lbl_8061977C, 0x37A1), (int)lbl_805BF8B0);
        break;
    case 3:
        o->v91(3, 0, 1);
        o->v67(3, 0);
        buf[0] = 0;
        fn_8010A284(buf, 0);
        fn_80109F58((Ui9F58*)self, (int)buf, (int)lbl_805BF8BC);
        break;
    case 2:
        o->v91(1, 0, 1);
        o->v67(1, 0);
        buf[0] = 0;
        fn_8010A284(buf, 0);
        fn_80109F58((Ui9F58*)self, (int)buf, (int)lbl_805BF8B0);
        break;
    case 4:
        o->v91(1, 0, 1);
        o->v67(1, 0);
        buf[0] = 0;
        fn_8010A150(buf, 0);
        fn_80109F58((Ui9F58*)self, (int)buf, (int)lbl_805BF8B0);
        break;
    case 5:
        o->v91(3, 0, 1);
        o->v67(3, 0);
        buf[0] = 0;
        fn_8010A150(buf, 0);
        fn_80109F58((Ui9F58*)self, (int)buf, (int)lbl_805BF8BC);
        break;
    }
}

int fn_8010A6C0()
{
    Ui700* o = fn_8011AA24(0)->m700;
    return fn_8017E030(o, fn_801059E4(), 0) == 0;
}

extern char lbl_8064F378[];
UiScrA70C* fn_8010A70C(UiScrA70C* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8064F378;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 1;
    self->m154 = 1;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m234 = 1;
    fn_803FFC58(self->m238, 0, 12);
    return self;
}

int fn_8010A7A0(int a)
{
    switch (a) {
    case 0:
        return fn_80090880(lbl_8061977C, 0x2B34);
    case 2:
        return fn_80090880(lbl_8061977C, 0x2B35);
    case 1:
    default:
        return fn_80090880(lbl_8061977C, 0x2B33);
    }
}

void fn_8010AE78(int unused, UiObj* list, int a, int b)
{
    short buf[100];
    buf[0] = 0;
    fn_800DE274(buf, b, 1);
    list->v43(a, 1, (int)buf, 5);
}

extern char lbl_805BC1A8[];
void fn_8010AEE4(int unused, UiObj* list, int a, int b)
{
    char buf[100] = "";
    fn_804089B4(buf, lbl_805BC1A8, fn_8011B6F8(1, b));
    list->v44(a, 2, (int)buf, 5);
}

void fn_8010AF80(int unused, UiObj* list, int a, Ui10AF80* ctx)
{
    char buf[100] = "";
    Unk800DB840_Slot* t = 0;
    if (ctx) {
        if (ctx->m44C) {
            if (ctx->m44C->m6F8)
                t = (Unk800DB840_Slot*)ctx->m44C->m6F8->m14;
        }
    }
    int v;
    if (t)
        v = fn_800DBAE0(t, 0xD, ctx->m708, ctx->m704);
    else
        v = fn_8025416C((char*)ctx + 0x588, 0xD);
    fn_804089B4(buf, lbl_805BC1A8, v);
    list->v44(a, 3, (int)buf, 5);
}

void fn_8010B060(int unused, UiObj* list, int a, char* ctx)
{
    int t = fn_8025416C(ctx + 0x588, 5);
    list->v44(a, 0, fn_800E5F38(t), 5);
}

/* near-miss: right length; the id selection chain is laid out differently (retail loads each id into r4 and branches to the shared call setup) */
void fn_8010B0CC(int unused, UiObj* list, int a, Ui8010B1E0* ctx)
{
    int idx = ctx->m708;
    int pid = ctx->m704;
    char* e = (char*)fn_8011AA24(0)->m6F8->m14 + idx * 0xE64;
    int id = fn_80097318(e, pid) != 0 ? 0xE80
             : fn_80097380(e, pid) != 0 ? 0xE83
             : fn_800973E8(e, pid) != 0 ? 0xE84
             : fn_80097450(e, pid) != 0 ? 0xE85
             : fn_800974B8(e, pid) != 0 ? 0xE7F
                                        : 0xBBC;
    list->v43(a, 0, fn_80090880(lbl_8061977C, id), 5);
}

void fn_8010B1E0(int unused, UiObj* list, int a, Ui8010B1E0* ctx, int b)
{
    int r = fn_80097288(b, ctx->m704);
    list->v44(a, 0, fn_800E5E4C(r), 5);
}

void fn_8010B24C(int unused, UiObj* list, int a, char* ctx)
{
    int t = fn_8025416C(ctx + 0x588, 9);
    list->v43(a, 2, fn_8010A7A0(t), 5);
}

void fn_8010B2B8(int unused, UiObj* list, int a, char* ctx)
{
    int t = fn_8025416C(ctx + 0x588, 8);
    list->v43(a, 2, fn_8010A7A0(t), 5);
}

void fn_8010B324(int unused, UiObj* list, int a, int b)
{
    char buf[100] = "";
    float f = fn_8011B81C(2, b, 2);
    fn_80119F48(buf, f);
    list->v44(a, 3, (int)buf, 5);
}

void fn_8010B3BC(int unused, UiObj* list, int a, int b)
{
    char buf[100] = "";
    float f = fn_8011B954(1, b);
    fn_80119FF0(buf, f);
    list->v44(a, 3, (int)buf, 5);
}

extern char lbl_805B6F58[];
void fn_8010B450(int unused, UiObj* list, int a, int b)
{
    list->v44(a, 0, (int)lbl_805B6F58, 5);
    list->v43(a, 1, fn_80090880(lbl_8061977C, b), 5);
    list->v44(a, 2, (int)lbl_805B6F58, 5);
    list->v44(a, 3, (int)lbl_805B6F58, 5);
}

extern char lbl_805B6F58[];
void fn_8010B53C(int unused, UiObj* list, int a, int b, int n)
{
    for (int j = 0; j < n; j++) {
        for (int i = a; i < b; i++)
            list->v44(i, j, (int)lbl_805B6F58, 5);
    }
    for (int i = a; i < b; i++)
        fn_8010B658(unused, list, i);
}

void fn_8010B5F8(int unused, UiObj* list, int a)
{
    for (int i = 0; i <= 4; i++)
        list->v91(a, i, 1);
}

void fn_8010B658(int unused, UiObj* list, int a)
{
    for (int i = 0; i <= 4; i++)
        list->v91(a, i, 0);
}

extern char lbl_80649DA0[];
extern char lbl_8065B888[];
int fn_8010C738(UiObj* a, int b)
{
    if (fn_800B555C()->m570 == b) {
        fn_800B7ADC(UiGetMsgMgr(), a);
        UiEvtRaw e;
        e.vt = lbl_80649DA0;
        e.id = 0x9E;
        e.vt = lbl_8065B888;
        fn_8037893C(fn_8011AA24(0)->m704, e.id, &e, 0, 0);
        e.vt = lbl_80649DA0;
    }
    return 1;
}

int fn_8010C7F0(Ui10C7F0* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        switch (self->m140) {
        case 0:
            fn_800B7ADC(UiGetMsgMgr(), self);
            return 1;
        case 1:
            if (self->m150 != 0) {
                fn_800B7ADC(UiGetMsgMgr(), self);
                return 1;
            }
            fn_8010F494(self, 0xA0);
            fn_8010F2CC(self);
            break;
        case 2:
            fn_8010F494(self, 0xA0);
            fn_8010F2CC(self);
            break;
        }
    }
    fn_8010D33C(self, 0);
    return 1;
}

void fn_8010D0C0(Ui10D0C0* self)
{
    self->m134 = (Ui2F0Obj*)fn_800B7A94(UiGetMsgMgr(), lbl_805BA6D8);
    int v = 0x3919;
    if (self->m144 == 2) {
        v = 0x391C;
        if (self->m15C == 0)
            v = 0x391D;
    }
    fn_80131F34(self->m134, self, (void (*)(int, UiObj*))fn_8010D1D0, fn_8010D1C8, v, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
    self->m134->m2F0 = -0x63;
    fn_800C80C0(self->m134, fn_800B555C()->m570);
    self->m134->v86();
}

int fn_8010D1C8()
{
    return 0;
}

void fn_8010D1D0()
{
}

void fn_8010D1D4(UiV_13C* self)
{
    fn_801268C4(self->m13C, fn_8011AA24(0)->m6F8, 5, 0, 5, 0, 1, 1, fn_8010D258, 0, 1, 0, 1, 0, 0);
    fn_8010D258();
}

extern char lbl_805BACD0[];
void fn_8010D258()
{
    UiV_140i_148_14C* o = fn_800B7AB8(UiGetMsgMgr(), lbl_805BACD0);
    o->v16(1);
    if (o->m140 == 0 || o->m140 == 2)
        o->m148->v14(1);
    else if (o->m140 == 1)
        o->m14C->v14(1);
    fn_8010D33C(o, 0);
}

int fn_8010D618(Ui10D618* self, int a)
{
    if (fn_800B555C()->m570 == a) {
        int flag = 0;
        int i;
        Ui6F8* p = fn_8011AA24(0)->m6F8;
        switch (self->m140) {
        case 0:
        case 2:
            i = self->m148->v60();
            if (self->a16C[i] != 0) {
                fn_801268C4(self->m13C, p, self->m168, self->a16C[i], 5, 0, 1, 1, fn_8010D258, 0, 1, 0, 1, 0, 0);
                flag = 1;
                self->m14C->v14(0);
                self->m148->v14(1);
                self->m13C->v84(0, 0);
            }
            break;
        case 1:
            i = self->m14C->v60();
            if (self->a1D0[i] != 0) {
                fn_801268C4(self->m13C, p, 5, 0, self->m168, self->a1D0[i], 1, 1, fn_8010D258, 0, 1, 0, 1, 0, 0);
                flag = 1;
                self->m148->v14(0);
                self->m14C->v14(1);
                self->m13C->v84(1, 0);
            }
            break;
        }
        if (flag != 0) {
            fn_8010F494(self, 0x9D);
            fn_8010D33C(self, 1);
        } else {
            self->m13C->v84(2, 0);
        }
        self->v16(1);
    }
    return 1;
}

void fn_8010D8B4(void* self, char* out)
{
    *out = 0;
}

void fn_8010DC14(UiV_148i_14Ci_158i_15Ci_160i_164i* self)
{
    self->m148 = 0;
    self->m14C = 0;
    self->m158 = 0;
    self->m15C = 0;
    self->m160 = 0;
    self->m164 = 0;
    fn_800ED254(self);
    fn_800C33D0();
    fn_800C3BE0();
}

void fn_8010DC5C(UiV_140i_148_14C* self, int a)
{
    fn_800ED310(self, a);
    if (a != 0) {
        switch (self->m140) {
        case 0:
        case 2:
            self->m148->v14(1);
            break;
        case 1:
            self->m14C->v14(1);
            break;
        }
    } else {
        self->m148->v14(0);
        self->m14C->v14(0);
    }
}
