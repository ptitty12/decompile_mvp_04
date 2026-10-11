/*
 * Game code, .text 0x800B5C68-0x800B8AF0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_800A8684.h"

struct UnkAtA0 {
    char pad0[0xA0];
    void* mA0;
};
void fn_800B5D34(void* p);
void fn_800C68D0(void* p);
void fn_800C694C(void* p);
void fn_8031CECC();
void fn_8031D54C();
void fn_800736EC(const char* s);
extern const char lbl_805B9E14[];
extern const char lbl_805B9E68[];

/* ---- generated externs ---- */


/* ---- functions ---- */
extern "C" {

void fn_800B5C9C(void* p)
{
    fn_800B5D34(p);
}

void fn_800B5D0C()
{
    fn_800736EC(lbl_805B9E14);
}

void fn_800B5D34()
{
    fn_800736EC(lbl_805B9E68);
}

void fn_800B7614() {}

void fn_800B7A94(UnkAtA0* p)
{
    fn_800C68D0(p->mA0);
}

void fn_800B7AB8(UnkAtA0* p)
{
    fn_800C694C(p->mA0);
}

void fn_800B82AC()
{
    fn_8031CECC();
    fn_8031D54C();
}

}
