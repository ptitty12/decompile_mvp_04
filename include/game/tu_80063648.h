#ifndef GAME_TU_80063648_H
#define GAME_TU_80063648_H

#include "game/tu_8005DF2C.h"
#include "game/tu_8005EDCC.h"
#include "game/tu_8005F4E4.h"
#include "game/tu_80060250.h"

/*
 * 0x80063648..0x80064D48: action handlers void f(A*, O*, Ctx*) (see
 * tu_80060F94.h), the candidate table helpers fn_800637F0 / fn_800638F0, and
 * the bank-name manager (fn_800642F0 and the loaders after it).
 */

/*
 * Bank-name manager. The string "Name manager loaded a total of %d banks
 * taking ..." (lbl_805AE330) is printed by fn_800644D4 after it has loaded
 * every list; the class name is otherwise unknown. Layout from the constructor
 * (fn_800642F0), the loaders (fn_80064594..fn_80064D48) and the destructor:
 *   m0/m4   count and int array (50 entries) of bank ids built by fn_80064594
 *   m8/mC, m10/m14, m18/m1C, m20/m24, m28/m2C   count and Rec array per list
 *   m38     loaded flag, m3C   running total of loaded sizes
 * The Rec arrays are allocated with new[] and constructed by the inline loop
 * (m0 = -1, m4 = m8 = 0).
 */
struct Unk800642F0_Rec {
    Unk800642F0_Rec()
    {
        m0 = -1;
        m4 = 0;
        m8 = 0;
    }
    int m0;
    int m4;
    int m8;
};

struct Unk800642F0_Str {
    char pad[16];
};

struct Unk800642F0 {
    Unk800642F0();
    ~Unk800642F0();
    int fn_800644CC();
    void fn_800644D4();
    void fn_80064594();
    int fn_8006473C(const char* name, int h, Unk800642F0_Rec* r);
    int fn_80064830(int a);
    void fn_80064858();
    void fn_800649C0();
    void fn_80064AB0();
    void fn_80064BFC();
    void fn_80064D48();
    void fn_80064F78();

    int m0;
    int* m4;
    int m8;
    Unk800642F0_Rec* mC;
    int m10;
    Unk800642F0_Rec* m14;
    int m18;
    Unk800642F0_Rec* m1C;
    int m20;
    Unk800642F0_Rec* m24;
    int m28;
    Unk800642F0_Rec* m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
};
#endif
