/*
 * Game code, .text 0x803401A8-0x803414A4 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
extern char lbl_806661D8[];
extern char lbl_80665E78[];
extern char lbl_80665EC8[];
extern char lbl_80666138[];
extern char lbl_80665F58[];
void fn_80328374(void* p, int chrg);
void fn_80332614(void* p, int chrg);
void fn_80332428(void* p, int chrg);
extern char lbl_80665FA8[];
extern char lbl_806660E8[];
extern char lbl_80666188[];
extern char lbl_80666888[];
extern char lbl_806667E8[];
extern char lbl_80666778[];
extern char lbl_80666EC0[];
extern char lbl_80666728[];
extern char lbl_806662C8[];
extern char lbl_80666548[];
extern char lbl_80666368[];
extern char lbl_80666318[];
void fn_80377408(void* p);
void fn_80330778(void* p, int chrg);
void fn_80330870(void* p, int chrg);
void fn_80330BC8(void* p, int chrg);

#define PUT(o, v) (*(const void**)((char*)self + (o)) = (v))

struct Unk803401A8 {
    char pad0[0x300];
};

void fn_803401A8(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_80666888);
    fn_80330778(self, chrg);
}

void fn_803408C4(Unk803401A8* self, int chrg)
{
    PUT(0, lbl_806667E8);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_803408F8(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_80666778);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_80340930(Unk803401A8* self, int chrg)
{
    fn_80330BC8(self, chrg);
}

void fn_80340950(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_80666728);
    PUT(0x588, lbl_80666EC0);
    PUT(0x534, lbl_80666EC0);
    PUT(0x4E0, lbl_80666EC0);
    PUT(0x48C, lbl_80666EC0);
    PUT(0x438, lbl_80666EC0);
    PUT(0x3E4, lbl_80666EC0);
    PUT(0x390, lbl_80666EC0);
    PUT(0x33C, lbl_80666EC0);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_803409AC(Unk803401A8* self, int chrg)
{
    fn_80330BC8(self, chrg);
}

extern char lbl_806666D8[];
extern char lbl_80666928[];

void fn_803409CC(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_806666D8);
    PUT(0x1610, lbl_80666EC0);
    PUT(0x15C4, lbl_80666EC0);
    char* s0 = (char*)self + 0xEF4;
    PUT(0x1570, lbl_80666EC0);
    *(const void**)(s0 + 0x2DC) = lbl_80666928;
    PUT(0x1508, lbl_80666EC0);
    PUT(0x14A0, lbl_80666EC0);
    PUT(0x1438, lbl_80666EC0);
    PUT(0x13D0, lbl_80666EC0);
    PUT(0x1368, lbl_80666EC0);
    PUT(0x1300, lbl_80666EC0);
    PUT(0x1298, lbl_80666EC0);
    PUT(0x1230, lbl_80666EC0);
    PUT(0x11DC, lbl_80666EC0);
    fn_80330870(s0, 2);
    char* s1 = (char*)self + 0xB74;
    PUT(0xEB0, lbl_80666EC0);
    *(const void**)(s1 + 0x2DC) = lbl_80666778;
    PUT(0xE5C, lbl_80666EC0);
    fn_80330870(s1, 2);
    PUT(0xB30, lbl_80666EC0);
    char* s2 = (char*)self + 0x32C;
    PUT(0xACC, lbl_80666EC0);
    PUT(0xA78, lbl_80666EC0);
    PUT(0xA14, lbl_80666EC0);
    PUT(0x9C0, lbl_80666EC0);
    PUT(0x95C, lbl_80666EC0);
    PUT(0x908, lbl_80666EC0);
    *(const void**)(s2 + 0x2DC) = lbl_80666728;
    PUT(0x8B4, lbl_80666EC0);
    PUT(0x860, lbl_80666EC0);
    PUT(0x80C, lbl_80666EC0);
    PUT(0x7B8, lbl_80666EC0);
    PUT(0x764, lbl_80666EC0);
    PUT(0x710, lbl_80666EC0);
    PUT(0x6BC, lbl_80666EC0);
    PUT(0x668, lbl_80666EC0);
    PUT(0x614, lbl_80666EC0);
    fn_80330870(s2, 2);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_80340AE4(Unk803401A8* self, int chrg)
{
    PUT(8, lbl_80666EC0);
    if (chrg & 1)
        fn_80377408(self);
}

void fn_80340B18(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_80666548);
    PUT(0x390, lbl_80666EC0);
    PUT(0x33C, lbl_80666EC0);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_80340B5C(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_80666368);
    PUT(0x3B0, lbl_80666EC0);
    PUT(0x34C, lbl_80666EC0);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_80340BA0(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_80666318);
    PUT(0x3B0, lbl_80666EC0);
    PUT(0x34C, lbl_80666EC0);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_80340BE4(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_806662C8);
    fn_80330778(self, chrg);
}

struct Item64 {
    char pad0[0x64];
};
extern char lbl_80666E70[];
struct Lbl48 {
    float m0;
    float m4;
    const void* m8;
    int mC;
    char pad10[0x48 - 0x10];
};
extern const float lbl_805F3288;
extern float lbl_805F328C;
extern float lbl_805F3290;
extern char lbl_805EC2E0[];
extern char lbl_805EC2FC[], lbl_805EC308[], lbl_805EC310[], lbl_805EC318[], lbl_805EC324[], lbl_805EC32C[], lbl_805EC334[], lbl_805EC340[], lbl_805EC350[], lbl_805EC35C[], lbl_805EC36C[], lbl_805EC378[], lbl_805EC388[], lbl_805EC394[], lbl_805EC39C[];
extern float lbl_80620578, lbl_8062057C, lbl_80620580, lbl_80620584, lbl_80620588, lbl_8062058C, lbl_80620590, lbl_80620594, lbl_80620598, lbl_8062059C, lbl_806205A0, lbl_806205A4, lbl_806205A8, lbl_806205AC, lbl_806205B0;
void* operator new(unsigned int size, int heap);
extern "C" void fn_8032D868(void*, const char*);
extern "C" void fn_80330ACC(void*, void*);
extern "C" void* fn_8032E894(void* mem, const char* name, float* p, float a, float b, float c, float d);
extern "C" void fn_80340C14(void* menu)
{
    Lbl48* l = new (0) Lbl48;
    l->m8 = lbl_80666E70;
    l->mC = 0;
    l->m0 = lbl_805F3288;
    l->m4 = lbl_805F3288;
    fn_8032D868(l, lbl_805EC2E0);
    fn_80330ACC(menu, l);
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC2FC, &lbl_80620578, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC308, &lbl_8062057C, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC310, &lbl_80620580, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC318, &lbl_80620584, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC324, &lbl_80620588, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC32C, &lbl_8062058C, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC334, &lbl_80620590, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC340, &lbl_80620594, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC350, &lbl_80620598, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC35C, &lbl_8062059C, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC36C, &lbl_806205A0, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC378, &lbl_806205A4, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC388, &lbl_806205A8, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC394, &lbl_806205AC, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
    fn_80330ACC(menu, fn_8032E894(new (0) Item64, lbl_805EC39C, &lbl_806205B0, lbl_805F328C, lbl_805F3290, lbl_805F3288, lbl_805F328C));
}

void fn_8034101C() {}
void fn_80341020() {}

void fn_80341024(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_806661D8);
    fn_80332614((char*)self + 0x83C, 2);
    PUT(0x7F8, lbl_80666EC0);
    fn_80332428((char*)self + 0x32C, 2);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_80341090(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_80666188);
    PUT(0x478, lbl_80666EC0);
    PUT(0x414, lbl_80666EC0);
    PUT(0x3B0, lbl_80666EC0);
    PUT(0x34C, lbl_80666EC0);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

extern char lbl_806661D8[];
extern char lbl_80665E78[];
extern char lbl_80665EC8[];
void fn_80328374(void* p, int chrg);
void fn_80332614(void* p, int chrg);
void fn_80332428(void* p, int chrg);

void fn_803410DC(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_80666138);
    PUT(0xA50, lbl_80666EC0);
    char* s0 = (char*)self + 0x520;
    PUT(0x9FC, lbl_80666EC0);
    *(const void**)(s0 + 0x2DC) = lbl_80666188;
    PUT(0x998, lbl_80666EC0);
    PUT(0x934, lbl_80666EC0);
    PUT(0x8D0, lbl_80666EC0);
    PUT(0x86C, lbl_80666EC0);
    PUT(0x808, lbl_80666EC0);
    fn_80330870(s0, 2);
    PUT(0x4DC, lbl_80666EC0);
    PUT(0x488, lbl_80666EC0);
    PUT(0x428, lbl_80666EC0);
    PUT(0x3D4, lbl_80666EC0);
    PUT(0x388, lbl_80666EC0);
    PUT(0x33C, lbl_80666EC0);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_80341178(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_806660E8);
    PUT(0x9A4, lbl_80666EC0);
    PUT(0x940, lbl_80666EC0);
    PUT(0x8DC, lbl_80666EC0);
    PUT(0x888, lbl_80666EC0);
    PUT(0x834, lbl_80666EC0);
    PUT(0x7E0, lbl_80666EC0);
    PUT(0x78C, lbl_80666EC0);
    PUT(0x738, lbl_80666EC0);
    PUT(0x6E4, lbl_80666EC0);
    PUT(0x690, lbl_80666EC0);
    PUT(0x63C, lbl_80666EC0);
    PUT(0x5E8, lbl_80666EC0);
    PUT(0x594, lbl_80666EC0);
    PUT(0x540, lbl_80666EC0);
    PUT(0x4EC, lbl_80666EC0);
    PUT(0x498, lbl_80666EC0);
    PUT(0x444, lbl_80666EC0);
    PUT(0x3F0, lbl_80666EC0);
    PUT(0x39C, lbl_80666EC0);
    PUT(0x33C, lbl_80666EC0);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_80341204(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_80665FA8);
    PUT(0x378, lbl_80666EC0);
    PUT(0x330, lbl_80666EC0);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_80341248(Unk803401A8* self, int chrg)
{
    PUT(0x2DC, lbl_80665F58);
    PUT(0xD0C, lbl_80666EC0);
    PUT(0xCA4, lbl_80666EC0);
    char* s0 = (char*)self + 0x8E4;
    *(const void**)(s0 + 0x2DC) = lbl_80665FA8;
    PUT(0xC5C, lbl_80666EC0);
    PUT(0xC14, lbl_80666EC0);
    PUT(0xBCC, lbl_80666EC0);
    fn_80330870(s0, 2);
    PUT(0x8A0, lbl_80666EC0);
    PUT(0x858, lbl_80666EC0);
    PUT(0x7F0, lbl_80666EC0);
    PUT(0x78C, lbl_80666EC0);
    PUT(0x72C, lbl_80666EC0);
    PUT(0x6D8, lbl_80666EC0);
    PUT(0x684, lbl_80666EC0);
    PUT(0x630, lbl_80666EC0);
    PUT(0x5DC, lbl_80666EC0);
    PUT(0x588, lbl_80666EC0);
    PUT(0x534, lbl_80666EC0);
    PUT(0x4E0, lbl_80666EC0);
    PUT(0x48C, lbl_80666EC0);
    PUT(0x438, lbl_80666EC0);
    PUT(0x3E4, lbl_80666EC0);
    PUT(0x390, lbl_80666EC0);
    PUT(0x33C, lbl_80666EC0);
    PUT(0x2E8, lbl_80666EC0);
    fn_80330870(self, chrg);
}

void fn_80341308(Unk803401A8* self, int chrg)
{
    PUT(0x300, lbl_80665E78);
    PUT(0x18, lbl_80665EC8);
    fn_80330870((char*)self + 0x24, 0);
    fn_80328374(self, chrg);
}

struct Unk803401A8_VT {
    char pad0[0x2DC];
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(int a);
};
struct Unk803413B0 {
    char pad0[0x24];
    Unk803401A8_VT m24;
};

extern Unk803401A8_VT* lbl_80620410;
extern int lbl_80620414;
extern int lbl_806204E4;
int fn_803308E4();
void fn_8033EA44(int a, int b);

void fn_80341364()
{
    if (lbl_80620414 != 0)
        lbl_80620410->s4();
}

void fn_803413B0(Unk803413B0* self)
{
    if (lbl_806204E4 == 1)
        ((Unk803401A8_VT*)((char*)self + 0x24))->s5(fn_803308E4());
}

void fn_80341410()
{
    lbl_80620410->s1();
}

void fn_8034144C()
{
    fn_8033EA44(1, 0xFFFF);
}

void fn_80341478()
{
    fn_8033EA44(0, 0xFFFF);
}
