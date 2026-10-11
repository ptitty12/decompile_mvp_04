/*
 * Game code, .text 0x8019C1F8-0x8019F8C0 (code-only unit; original file and TU
 * boundaries unknown, placeholder). Every data object is extern by its lbl_ name.
 */
#include "game/tu_8019C1F8.h"
//@BODY
//@8019E3C0
Unk8019E3C0::Unk8019E3C0(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(12, owner)
{
}

//@8019E558
void Unk8019E3C0::v6()
{
}

//@8019E55C
Unk8019E55C::Unk8019E55C(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(13, owner)
{
}

//@8019E5B4
void Unk8019E55C::v4()
{
    fn_8017B0D8(m18->m700);
    if (m18->m6F4 == 6)
        fn_801594A8(m18->m710);
}

//@8019E6A0
void Unk8019E55C::v6()
{
}

//@8019E6A4
Unk8019E6A4::Unk8019E6A4(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(14, owner)
{
}

//@8019EB0C
void Unk8019E6A4::v6()
{
}

//@8019EB10
Unk8019EB10::Unk8019EB10(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(15, owner)
{
}

//@8019EB68
void Unk8019EB10::v4()
{
    int s = m18->m6F4;
    if (s == 6) {
        m1C = 0x3C;
        return;
    }
    if (s == 7) {
        m1C = 0x3C;
        return;
    }
    if (s == 9) {
        m1C = 0x3C;
        return;
    }
    m1C = fn_8040ABA0() % 20 + 0x91;
}

//@8019EF6C
void Unk8019EB10::v6()
{
}

//@8019EF70
Unk8019EF70::Unk8019EF70(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(16, owner)
{
}

//@8019EFC8
void Unk8019EF70::v4()
{
    if (m18->m6F4 != 7 && m18->m6F4 != 9) {
        Unk8019E3C0_Own* c = m18;
        void* old = c->m6CC;
        fn_801A505C(c);
        if (m18->m6CC == old)
            fn_801A505C(m18);
    }
    if (m18->m6F4 != 9)
        fn_8017BB60(m18->m700);
}

//@8019F0D0
void Unk8019EF70::v6()
{
    fn_8017BBF4(m18->m700);
}

//@8019F0F8
Unk8019F0F8::Unk8019F0F8(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(17, owner)
{
    m20 = 0;
    m1C = 0;
}

//@8019F23C
void Unk8019F0F8::v6()
{
}

//@8019F240
extern "C" void fn_8019F240(Unk8019E3C0_Own* m)
{
    char* list = (char*)m + 0x560;
    fn_8033E464(list, new (0) Unk8019E3C0(m));
    fn_8033E464(list, new (0) Unk8019E55C(m));
    fn_8033E464(list, new (0) Unk8019E6A4(m));
    fn_8033E464(list, new (0) Unk8019EB10(m));
    fn_8033E464(list, new (0) Unk8019EF70(m));
    fn_8033E464(list, new (0) Unk8019F0F8(m));
}

//@8019F414
Unk8019F414::Unk8019F414(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(0, owner)
{
}

//@8019F468
void Unk8019F414::v5()
{
    fn_8033E3FC(this, 1);
}

//@8019F48C
Unk8019F48C::Unk8019F48C(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(1, owner)
{
}

//@8019F5C4
void Unk8019F48C::v6()
{
    fn_8017AF30(m18->m700);
}

//@8019F5EC
Unk8019F5EC::Unk8019F5EC(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(10, owner)
{
}

//@8019F6DC
void Unk8019F5EC::v5()
{
    fn_8033E3FC(this, 2);
}

//@8019F700
void Unk8019F5EC::v6()
{
    fn_8017AF7C(m18->m700);
}

//@8019F728
Unk8019F728::Unk8019F728(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(2, owner)
{
}

//@8019F780
void Unk8019F728::v4()
{
    fn_80158CB8(m18->m710);
}

//@8019F7F4
void Unk8019F728::v6()
{
    fn_8017B0A4(m18->m700);
}

//@8019F81C
Unk8019F81C::Unk8019F81C(Unk8019E3C0_Own* owner)
    : Unk8019E3C0_Base(3, owner)
{
}

