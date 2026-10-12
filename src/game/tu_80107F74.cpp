/*
 * Game code, .text 0x80107F74-0x8010A0A4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800F1AEC.h"

extern char lbl_80649DA0[];
extern char lbl_8065B888[];
struct UiEvtBase80108800 {
    int id;
    const void* vt;
    UiEvtBase80108800(int i)
    {
        vt = lbl_80649DA0;
        id = i;
    }
    ~UiEvtBase80108800() { vt = lbl_80649DA0; }
};
struct UiEvt80108800 : UiEvtBase80108800 {
    UiEvt80108800() : UiEvtBase80108800(0x9E) { vt = lbl_8065B888; }
    ~UiEvt80108800() { vt = lbl_80649DA0; }
};
inline UiMsg* UiMsgInit(UiMsg* m)
{
    fn_8035682C(m);
    return m;
}
struct UiV_134_140 : UiObj {
    char pad40[0x134 - 0x40];
    UiObj* m134;
    char pad138[0x140 - 0x138];
    int m140;
};
int fn_8010A6C0();


void fn_80107F74(UiArr158* self, int i, int a)
{
    fn_800C8034(self->m158[i])->v15(a);
}

void fn_80107FC8(UiV_158_15C* self, int a)
{
    self->m158->v8(a ^ 1);
    self->m15C->v8(a);
}

extern int lbl_8061A330;
void fn_80108034(UiV_134f_198i* self, float f)
{
    fn_800DC50C(self->m198, self->m134, f);
    lbl_8061A330 = 1;
}

extern char lbl_805BF838[];
extern char lbl_805BA060[];
void fn_80108070(UiV_14Ci_19Ci_1A8_1ACb* self, int a)
{
    self->m1AC->v8();
    ((UiObj*)self->v32((int)lbl_805BF838, 1))->v8(a ^ 1);
    self->m1A8->v8(a);
    if (a != 0) {
        fn_801A8198(self->m19C);
        fn_80107C94(self);
    }
    if (self->m14C != 0)
        ((UiObj*)self->v32((int)lbl_805BA060, 1))->v8(a);
}

extern char lbl_805BA240[];
void fn_8010817C(int a, UiObj* b)
{
    int one = 1;
    lbl_80620298 = one;
    if (a == one) {
        UiMsg m;
        UiMsg* p = &m;
        fn_8035682C(p);
        fn_8040B830(p->name, lbl_805BA240, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, b);
    }
}

extern char lbl_8064F0D0[];
UiScrRaw* fn_80108214(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8064F0D0;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

/* near-miss: same calls; retail interleaves the xor/subfic chain with the vcalls and keeps m134 in r29 (we reload it) */
extern char lbl_805BE370[];
extern char lbl_805BE4B0[];
void fn_80108268(UiV_134* self)
{
    fn_800ECF18(self);
    fn_802DC9C0();
    Ui8011AA24* g = fn_8011AA24(0);
    fn_801083AC(self);
    self->m134 = (UiObj*)fn_800C8060(self->v32((int)lbl_805BE370, 1));
    UiObj* o = self->m134;
    int t = g->m6F8->m14->m1CD0;
    int x = fn_801059E4() ^ (t == 0);
    int y = x == 0;
    o->v91(1, 0, y);
    self->m134->v91(0, 0, y ^ 1);
    fn_80118A70(fn_800C8044(self->v32((int)lbl_805BE4B0, 1)));
    fn_800C80C0(self, fn_800B555C()->m570);
}

void fn_8010838C(UiObj* self)
{
    fn_800ED254(self);
}

extern char lbl_805BA6D0[];
void fn_801083AC(UiV_138* self)
{
    UiObj* o = fn_800B7A94(UiGetMsgMgr(), lbl_805BA6D0);
    self->m138 = o;
    fn_80124FA8(o, self);
    fn_801251CC(self->m138, 1, 0x1A0B, 0);
    fn_80125490(self->m138, 1, 4, 0x38C8, 1);
    UiObj* l = self->m138;
    fn_800C80C0(l, fn_800B555C()->m570);
    fn_801251CC(self->m138, 0, 0x1A0D, 2);
}

int fn_8010846C(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v50();
    return 1;
}

int fn_801084C8(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v51();
    return 1;
}

int fn_80108524(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v52();
    return 1;
}

int fn_80108580(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v53();
    return 1;
}

int fn_801085DC(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v54();
    return 1;
}

int fn_80108638(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v55();
    return 1;
}

int fn_80108694(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v56();
    return 1;
}

int fn_801086F0(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v57();
    return 1;
}

int fn_8010874C(UiV_134i* self, int a, int b, int c)
{
    if (a == self->m134) {
        fn_80108958(self, c);
        return 1;
    }
    return 0;
}

void fn_8010878C(UiV_134* self, char* out)
{
    UiObj* o = self->m134->v70();
    fn_8040B830(out, o->v33(5, 1)->name, 16);
}

extern char lbl_805BE138[];
extern char lbl_805BADC8[];
extern char lbl_80649DA0[];
extern char lbl_8065B888[];
void fn_80108800(UiV_134* self, int a, int b)
{
    const char* s = 0;
    switch (a) {
    case 0:
        s = lbl_805BE138;
        break;
    case 1: {
        UiEvt80108800 e;
        s = lbl_805BADC8;
        fn_8037893C(fn_8011AA24(0)->m704, e.id, (UiEvtRaw*)&e, 0, 0);
        break;
    }
    case 2:
        if (fn_800B555C()->m570 == b) {
            fn_80108958(self, self->m134->v60());
            return;
        }
        break;
    }
    if (fn_800B555C()->m570 == b) {
        UiMsg m;
        UiMsg* p = UiMsgInit(&m);
        fn_8040B830(p->name, s, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
    }
}

void fn_80108958(UiObj* a, int b)
{
    switch (b) {
    case 1:
        break;
    case 2:
        fn_801089E4(a, 0);
        break;
    case 3:
        fn_801089E4(a, 1);
        break;
    }
    fn_800B7ADC(UiGetMsgMgr(), a);
}

void fn_801089E4(UiObj* self, int a)
{
    int v = fn_801059E4();
    if (a == 1)
        v = v == 0;
    Ui8011AA24* o = fn_8011AA24(0);
    o->m788 = v;
    fn_801A3704(o, 1);
}

extern char lbl_8064EE28[];
UiScrRaw* fn_80108A38(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8064EE28;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    return self;
}

void fn_80108DB0(int a, UiObj* obj)
{
    obj->v67(2, fn_800B555C()->m570);
}

void fn_80108E04(UiObj* self)
{
    fn_800ED254(self);
}

extern char lbl_805BA6D0[];
void fn_80108E24(UiV_138* self)
{
    UiObj* o = fn_800B7A94(UiGetMsgMgr(), lbl_805BA6D0);
    self->m138 = o;
    fn_80124FA8(o, self);
    fn_801251CC(self->m138, 1, 0x1A0B, 0);
    fn_80125490(self->m138, 1, 4, 0x38C8, 1);
    UiObj* l = self->m138;
    fn_800C80C0(l, fn_800B555C()->m570);
    fn_801251CC(self->m138, 0, 0x1A0D, 2);
}

int fn_80108EE4(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v50();
    return 1;
}

int fn_80108F40(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v51();
    return 1;
}

int fn_80108F9C(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v52();
    return 1;
}

int fn_80108FF8(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v53();
    return 1;
}

int fn_80109054(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v54();
    return 1;
}

int fn_801090B0(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v55();
    return 1;
}

int fn_8010910C(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v56();
    return 1;
}

int fn_80109168(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v57();
    return 1;
}

void fn_801091C4(UiV_134* self)
{
    Ui8011AA24* g = fn_8011AA24(0);
    int pid = fn_801059E4();
    UiObj* o = self->m134;
    int a = fn_8011BD94(g, pid);
    int b = fn_8011BE1C(g, pid);
    int c = fn_8011BF1C(g, pid);
    o->v91(0, 0, a);
    o->v91(1, 0, b);
    o->v91(2, 0, c);
}

int fn_801092A0(UiV_134i* self, int a, int b, int c)
{
    if (a == self->m134) {
        fn_801094AC(self, c);
        return 1;
    }
    return 0;
}

void fn_801092E0(UiV_134* self, char* out)
{
    UiObj* o = self->m134->v70();
    fn_8040B830(out, o->v33(5, 1)->name, 16);
}

extern char lbl_805BE138[];
extern char lbl_805BADC8[];
extern char lbl_80649DA0[];
extern char lbl_8065B888[];
void fn_80109354(UiV_134* self, int a, int b)
{
    const char* s = 0;
    switch (a) {
    case 0:
        s = lbl_805BE138;
        break;
    case 1: {
        UiEvt80108800 e;
        s = lbl_805BADC8;
        fn_8037893C(fn_8011AA24(0)->m704, e.id, (UiEvtRaw*)&e, 0, 0);
        break;
    }
    case 2:
        if (fn_800B555C()->m570 == b) {
            fn_801094AC(self, self->m134->v60());
            return;
        }
        break;
    }
    if (fn_800B555C()->m570 == b) {
        UiMsg m;
        UiMsg* p = UiMsgInit(&m);
        fn_8040B830(p->name, s, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
    }
}

void fn_801094AC(UiObj* a, int b)
{
    if (b <= 3) {
        if (b >= 0)
            fn_800B7ADC(UiGetMsgMgr(), a);
    }
}

extern char lbl_8064EB80[];
extern char lbl_805B6F58[];
UiScrRaw* fn_80109514(UiScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8064EB80;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = (int)lbl_805B6F58;
    return self;
}

extern char lbl_805BE370[];
extern char lbl_805BE4B0[];
void fn_8010957C(UiV_134i_140i* self)
{
    fn_800ECF18(self);
    fn_80109660(self);
    self->m134 = fn_800C8060(self->v32((int)lbl_805BE370, 1));
    fn_800C80C0(self, fn_800B555C()->m570);
    if (fn_800B555C()->m0 == 0x22) {
        fn_8010A3FC(self);
        self->m140 = 1;
    }
    fn_80109A98(self);
    fn_80118A70(fn_800C8044(self->v32((int)lbl_805BE4B0, 1)));
}

void fn_80109640(UiObj* self)
{
    fn_800ED254(self);
}

int fn_801097B8(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v50();
    return 1;
}

int fn_80109814(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v51();
    return 1;
}

int fn_80109870(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v52();
    return 1;
}

int fn_801098CC(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v53();
    return 1;
}

int fn_80109928(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v54();
    return 1;
}

int fn_80109984(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v55();
    return 1;
}

int fn_801099E0(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v56();
    return 1;
}

int fn_80109A3C(UiScr134* self, int a)
{
    if (fn_800B555C()->m570 == a)
        self->m134->v57();
    return 1;
}

void fn_80109A98(UiV_134* self)
{
    Ui8011AA24* g = fn_8011AA24(0);
    UiObj* o = self->m134;
    int pid = fn_801059E4();
    if (g->m710->m14 != 0 || (g->m6F8->m14->m1CD0 == 0) != pid || fn_8017C974(g->m700) == 0)
        ((UiObj*)fn_800C8060((int)o))->v91(0, 0, 0);
    int a = fn_8011BD3C(g, pid);
    int b = fn_8011BD0C(g, pid);
    int c = fn_8011BF1C(g, pid);
    o->v91(1, 0, a);
    o->v91(3, 0, b);
    o->v91(5, 0, c);
}

int fn_80109BDC(UiV_134i* self, int a, int b, int c)
{
    if (a == self->m134) {
        fn_80109E0C(self, c);
        return 1;
    }
    return 0;
}

void fn_80109C1C(UiV_134* self, char* out)
{
    UiObj* o = self->m134->v70();
    fn_8040B830(out, o->v33(5, 1)->name, 16);
}

void fn_80109C90(UiV_134_140* self, int a, int b)
{
    const char* s = 0;
    switch (a) {
    case 0:
        s = lbl_805BE138;
        break;
    case 1: {
        if (self->m140 != 0 && fn_8010A6C0() == 0) {
            fn_8010A3FC(self);
            return;
        }
        UiEvt80108800 e;
        s = lbl_805BADC8;
        fn_8037893C(fn_8011AA24(0)->m704, e.id, (UiEvtRaw*)&e, 0, 0);
        break;
    }
    case 2:
        if (fn_800B555C()->m570 == b) {
            fn_80109E0C(self, self->m134->v60());
            return;
        }
        break;
    }
    if (fn_800B555C()->m570 == b) {
        UiMsg m;
        UiMsg* p = UiMsgInit(&m);
        fn_8040B830(p->name, s, 15);
        p->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), p, self);
    }
}

extern char lbl_80649DA0[];
extern char lbl_8065B888[];
void fn_80109E0C(UiObj* a, int b)
{
    if (b == 0) {
        fn_8017D378(fn_8011AA24(0)->m700, 0);
        UiEvtRaw e;
        e.vt = lbl_80649DA0;
        e.id = 0x9E;
        e.vt = lbl_8065B888;
        fn_8037893C(fn_8011AA24(0)->m704, e.id, &e, 0, 0);
        e.vt = lbl_80649DA0;
    }
    fn_800B7ADC(UiGetMsgMgr(), a);
}

void fn_80109EC8(int unused, UiV_144s* self)
{
    fn_8010A0A4(self);
    UiMsg m;
    UiMsg* p = &m;
    fn_8035682C(p);
    fn_8040B830(p->name, self->m144, 15);
    p->name[15] = 0;
    fn_800B7B4C(UiGetMsgMgr(), p, self);
}

int fn_80109F50()
{
    return 0;
}

extern char lbl_805BA6D8[];
void fn_80109F58(Ui9F58* self, int a, int b)
{
    self->m144 = b;
    if (self->m13C != 0)
        fn_8010A0A4(self);
    self->m13C = (UiV_2F0i*)fn_800B7A94(UiGetMsgMgr(), lbl_805BA6D8);
    self->v16(0);
    self->m138->v16(0);
    fn_801321D4(self->m13C, self, fn_80109EC8, fn_80109F50, a, 1, -1, 1, fn_80090880(lbl_8061977C, 0x1FE1), 0, 0, 0, 0, 0);
    self->m13C->m2F0 = -0x63;
    fn_800C80C0(self->m13C, fn_800B555C()->m570);
    self->m13C->v86();
}
