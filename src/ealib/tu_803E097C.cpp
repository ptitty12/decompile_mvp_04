/*
 * EA shared library code (ProDG, cflags_ealib: -O2 -G0),
 * .text 0x803E097C-0x803E0ACC (code-only unit, 4 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 */

struct Unk803E097C_Init {
    int a, b, c;
};

extern Unk803E097C_Init lbl_806AA984;

/* static initializer of lbl_806AA984 (a 3-int object built with (4, 4, 1)) */
extern "C" void fn_803E097C(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize) {
        lbl_806AA984.a = 4;
        lbl_806AA984.b = 4;
        lbl_806AA984.c = 1;
    }
}

struct Unk803E09B4_Sub10 {
    char pad0[0x2C];
};

struct Unk803E09B4_Sub3C {
    char pad0[0x38];
};

struct Unk803E09B4 {
    char pad0[0xC];
    const void* mC;
    Unk803E09B4_Sub10 m10;
    Unk803E09B4_Sub3C m3C;
    int m74;
};

extern const char lbl_80686800[];
extern void (*lbl_8062C66C)(void*, int);

extern "C" void* fn_803D9160(void* self, int a, void* b, void* c);
extern "C" void fn_803D9180(void* self, int chrg);
extern "C" void* fn_803E081C(void* sub, void* owner);
extern "C" void fn_803E0868(void* sub, int chrg);
extern "C" void* fn_803E08B8(void* sub, void* owner);
extern "C" void fn_803E0920(void* sub, int chrg);

extern "C" Unk803E09B4* fn_803E09B4(Unk803E09B4* self, int owner)
{
    fn_803D9160(self, 1, &self->m10, &self->m3C);
    self->mC = lbl_80686800;
    fn_803E081C(&self->m10, self);
    fn_803E08B8(&self->m3C, self);
    self->m74 = owner;
    return self;
}

extern "C" void fn_803E0A24(Unk803E09B4* self, int chrg)
{
    self->mC = lbl_80686800;
    fn_803E0920(&self->m3C, 2);
    fn_803E0868(&self->m10, 2);
    fn_803D9180(self, 0);
    if (chrg & 1)
        lbl_8062C66C(self, 0x78);
}

extern "C" void fn_803E0AA0()
{
    fn_803E097C(1, 0xFFFF);
}
