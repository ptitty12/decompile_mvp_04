/*
 * Game code, .text 0x80070DDC-0x80073914 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_80070DDC.h"

void* operator new(unsigned int size, int heap);
void fn_80377E90(Obj* list, int* a, int* b, int idx);
void fn_80377DBC(Obj* list, int* a, int* b, int idx);
char* fn_8040B61C(char* dst, const char* src);
Unk8052AE7C_Obj* fn_8052AE7C(void* p);
unsigned fn_80378568(const char* s, int n);
extern Unk8052AE7C_Obj* lbl_80619300;
extern int lbl_80619304;
extern char lbl_8064B548[];
extern Unk80070ED8_Obj* lbl_806192E0;
extern Unk80071FA0_Obj* lbl_8061930C;
Unk80070ED8_Mgr* fn_80070ED8(Unk80070ED8_Mgr* self);
Unk80071FA0_Obj* fn_80071FA0(void* p);
void fn_80071E2C(Unk80071604* self, int a, Unk80070DDC_Stream* io);
Unk8006902C_Ctx* fn_8006F594(void* p);
extern char lbl_80649EF0[];
void fn_80083DF4(Unk8007A4DC_Obj1E8* o);
void fn_80083E18(Unk8007A4DC_Obj1E8* o);
void fn_800956B8(Handle* h, int a, int b);
void fn_80090A90(Handle* h, int a, int b);
void fn_802B8EC4(void);
void fn_802B8F2C(void);
void fn_8059A580(void* p);
void fn_8052DE9C(void* p);
void fn_8009191C(Handle* h);
void fn_8009252C(Handle* h);
void fn_80092E50(Handle* h);
void fn_80093774(Handle* h);
void fn_80094098(Handle* h);
void fn_80091D88(Handle* a, Handle* b);
void fn_8009222C(Handle* a, Handle* b);
void fn_80092B50(Handle* a, Handle* b);
void fn_80093474(Handle* a, Handle* b);
void fn_80093D98(Handle* a, Handle* b);
void fn_800946BC(Handle* a, Handle* b);
void fn_800919A8(Handle* h);
void fn_800925B8(Handle* h);
void fn_80092EDC(Handle* h);
void fn_80093800(Handle* h);
void fn_80094124(Handle* h);
void fn_80091F40(Handle* h);
void fn_80092864(Handle* h);
void fn_80093188(Handle* h);
void fn_80093AAC(Handle* h);
void fn_800943D0(Handle* h);
void fn_8009010C(void);
void fn_80090164(void);
void fn_80091804(Handle* h);
void fn_80091BA4(Handle* a, Handle* b);
void fn_80091CB4(Handle* a, Handle* b);
void fn_80092414(Handle* h);
void fn_800926FC(Handle* a, Handle* b);
void fn_80092D38(Handle* h);
void fn_80093020(Handle* a, Handle* b);
void fn_8009365C(Handle* h);
void fn_80093944(Handle* a, Handle* b);
void fn_80093F80(Handle* h);
void fn_80094268(Handle* a, Handle* b);
void* fn_8040B320(void* p, int c, ...);
char* fn_8040B448(char* dst, const char* src);
extern const char lbl_805B3CDC[];
extern const char lbl_805B3CE0[];
struct Unk80072A84 {
    char pad0[0x1C];
    void* m1C;
    void* m20;
};

void fn_80070DDC(Unk80071604* self, int a, Unk80070DDC_Stream* io)
{
    fn_80071E2C(self, a, io);
    io->v08(a, self->m24, self->m1C * 0xC);
}

void fn_80070E38(void)
{
    if (!lbl_806192E0)
        lbl_806192E0 = (Unk80070ED8_Obj*)fn_80070ED8((Unk80070ED8_Mgr*)operator new(0x10, 0));
}

void fn_80070E80(void)
{
    if (lbl_806192E0) {
        delete lbl_806192E0;
        lbl_806192E0 = 0;
    }
}

/* near-miss: 1 slot (stwx operand order, r30/r28 swapped). */
Unk80070ED8_Mgr* fn_80070ED8(Unk80070ED8_Mgr* self)
{
    self->mC = lbl_80649EF0;
    self->m0 = fn_8006F594(operator new(0x604, 0));
    int i;
    for (i = 0; i < 2; i++) {
        Unk80069F0C** a = self->m4;
        Unk80069F0C* s = (Unk80069F0C*)operator new(0x5C, 0);
        a[i] = s->fn_80069F0C(self->m0);
    }
    self->m0->mC->m0 = self->m4[0];
    return self;
}

void fn_80070F64(Unk80070ED8_Mgr* self, int chrg)
{
    self->mC = lbl_80649EF0;
    int i;
    for (i = 0; i < 2; i++) {
        if (self->m4[i]) {
            delete (Unk80070F64_SessionV*)self->m4[i];
            self->m4[i] = 0;
        }
    }
    if (self->m0) {
        delete (Unk80070F64_CtxV*)self->m0;
        self->m0 = 0;
    }
    if (chrg & 1)
        delete self;
}

void fn_800715A8(Unk80071604* self, int a, Unk80070DDC_Stream* io)
{
    fn_80071E2C(self, a, io);
    io->v08(a, self->m24, 0xCB20);
}

Unk80071604* fn_80071604(Unk80071604* self, const char* name, Obj* type, unsigned count)
{
    self->m14 = 0;
    self->m18 = 0;
    self->m20 = lbl_8064B548;
    self->m10 = type;
    self->m1C = count;
    fn_8040B61C(self->m0, name);
    if (lbl_80619300 == 0)
        lbl_80619300 = fn_8052AE7C(operator new(0x18, 0));
    lbl_80619304++;
    return self;
}

void fn_80071688(Unk80071604* self, int chrg)
{
    self->m20 = lbl_8064B548;
    if (chrg & 1)
        delete self;
}

void fn_800716BC(W* w)
{
    unsigned i;
    for (i = 0; i < w->m1C; i++)
        w->v10(i);
}

int fn_80071718(W* w, int x)
{
    int b = -1;
    int a = -1;
    fn_80377E90(w->m10, &a, &b, x);
    int r = -1;
    if (b >= 0 && x != w->m14)
        r = b;
    return r;
}

/* near-miss: 12 slots; register allocation of the loop variables differs (retail:
 * this=r31, i=r30 copied from res=r28, off=r29, cnt=r27). */
int fn_80071784(W* w, int id)
{
    int res = 0;
    int off = 0;
    int a = -1;
    int cnt = w->m10->m4;
    int b = -1;
    int i;
    for (i = 0; i < cnt; i++, off += 12) {
        fn_80377DBC(w->m10, &a, &b, i);
        if (a == id) {
            res = *(int*)(w->m10->m0 + off);
            break;
        }
    }
    return res;
}

int fn_80071814(W* w, int id)
{
    int a = -1;
    int b = -1;
    fn_80377E90(w->m10, &a, &b, id);
    if (b < 0) {
        fn_80377E90(w->m10, &a, &b, w->m14);
        if (b < 0)
            b = 0;
    }
    return b;
}

void fn_80071E2C(Unk80071604* self, int a, Unk80070DDC_Stream* io)
{
    io->v08(a, &self->m14, 4);
    if (io->v10() == 0)
        self->m18 = ((W*)self)->v60();
}

unsigned fn_80071EB4(const char* s, int n)
{
    return fn_80378568(s, n);
}

unsigned fn_80071ED4(const char* s, int n)
{
    return fn_80378568(s, n);
}

void fn_80071EF4(void)
{
}

void fn_80071EF8(void)
{
}

void fn_80071EFC(void)
{
}

void fn_80071F00(void)
{
    if (!lbl_8061930C)
        lbl_8061930C = fn_80071FA0(operator new(0x210, 0));
}

void fn_80071F48(void)
{
    if (lbl_8061930C) {
        delete lbl_8061930C;
        lbl_8061930C = 0;
    }
}

void Unk8007A4DC_Screen::fn_8007285C()
{
    fn_80083DF4(m1E8);
    fn_80083E18(m1E8);
}

void Unk8007A4DC_Screen::fn_80072894(int a)
{
    fn_800956B8(&m17C, a, 1);
}

void Unk8007A4DC_Screen::fn_800728BC(int a)
{
    fn_800956B8(&m17C, a, 0);
}

void Unk8007A4DC_Screen::fn_800728E4(int a)
{
    fn_80090A90(&m1C0, a, 1);
}

void Unk8007B2B0_Screen::fn_8007290C(int a)
{
    fn_80090A90(&m4C, a, 0);
}

void Unk8007B2B0_Screen::fn_80072934(int a)
{
    fn_80090A90(&m4C, a, 1);
}

void fn_80072A84(Unk80072A84* o)
{
    fn_8059A580(o->m1C);
    fn_8052DE9C(o->m20);
}

void Unk8007B2B0_Screen::fn_80072B60()
{
    fn_80072BD0();
    fn_802B8EC4();
    fn_80072C28();
}

void Unk8007B2B0_Screen::fn_80072B98()
{
    fn_80072CE8();
    fn_802B8F2C();
    fn_80072D68();
}

void Unk8007B2B0_Screen::fn_80072BD0()
{
    fn_8009191C(&m6C);
    fn_8009252C(&mBC);
    fn_80092E50(&mEC);
    fn_80093774(&m11C);
    fn_80094098(&m14C);
    m1EC = 1;
}

void Unk8007B2B0_Screen::fn_80072C28()
{
    if (m1EC == 1) {
        Handle* h6c = &m6C;
        fn_8009010C();
        Handle* hbc = &mBC;
        fn_80091804(h6c);
        Handle* hec = &mEC;
        fn_80091BA4(h6c, &m8C);
        Handle* h11c = &m11C;
        fn_80091CB4(h6c, &mAC);
        Handle* h14c = &m14C;
        fn_80092414(hbc);
        fn_800926FC(hbc, &mDC);
        fn_80092D38(hec);
        fn_80093020(hec, &m10C);
        fn_8009365C(h11c);
        fn_80093944(h11c, &m13C);
        fn_80093F80(h14c);
        fn_80094268(h14c, &m16C);
        fn_80090164();
    }
}

void Unk8007B2B0_Screen::fn_80072CE8()
{
    if (m1EC == 1) {
        Handle* h = &m6C;
        fn_80091D88(&m8C, h);
        fn_8009222C(&mAC, h);
        fn_80092B50(&mDC, &mBC);
        fn_80093474(&m10C, &mEC);
        fn_80093D98(&m13C, &m11C);
        fn_800946BC(&m16C, &m14C);
    }
}

void Unk8007B2B0_Screen::fn_80072D68()
{
    m1EC = 0;
    fn_800919A8(&m6C);
    fn_800925B8(&mBC);
    fn_80092EDC(&mEC);
    fn_80093800(&m11C);
    fn_80094124(&m14C);
}

void Unk8007B2B0_Screen::fn_80072DC0()
{
    fn_80091F40(&mAC);
    fn_80092864(&mDC);
    fn_80093188(&m10C);
    fn_80093AAC(&m13C);
    fn_800943D0(&m16C);
}

int fn_80072E10(void* self, int a, int b, int c, int* out)
{
    if (a & b) {
        int v = 0;
        if (c != 0)
            v = (b & c) == 0;
        *out = v;
        return 1;
    }
    return 0;
}

void fn_80072E44(void* self, int a, Unk80070DDC_Stream* io)
{
    int magic = 0xBEEFF00D;
    io->v08(a, &magic, 4);
}

/* near-miss: 2 slots (li r5,127 / addi r3 order in the memset call setup). */
unsigned fn_8007366C(const char* a, const char* b)
{
    char buf[0x80];
    buf[0] = lbl_805B3CDC[0];
    fn_8040B320(buf + 1, 0, 0x7F);
    fn_8040B61C(buf, b);
    fn_8040B448(buf, lbl_805B3CE0);
    fn_8040B448(buf, a);
    return fn_80071EB4(buf, 0);
}

unsigned fn_800736EC(const char* s)
{
    return fn_80071ED4(s, 0);
}
