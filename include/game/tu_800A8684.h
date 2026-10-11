/*
 * Types shared by game/tu_800A8684.cpp .. game/tu_800B5C68.cpp (reconstructed,
 * placeholder names; nothing here comes from original headers).
 *
 * The functions are the methods of the front-end "action"/"condition" classes
 * (SetGameMode, ChangeMovie, ActionList, ... named by their attribute strings)
 * and the FE state objects. Their vtables live in .data, so the methods are
 * written as extern "C" functions that take the object explicitly; only the
 * virtual slots the code calls through are declared.
 */
#ifndef GAME_TU_800A8684_H
#define GAME_TU_800A8684_H

void* operator new(unsigned int size, int heap);
extern int lbl_806EF9B4;

extern "C" {
void fn_80400560(void* p, int n);
char* fn_8040B61C(char* dst, const char* src);          /* behaves like strcpy */
int fn_8040B6A0(const char* s);                          /* behaves like strlen */
int fn_8040B574(const char* a, const char* b);           /* behaves like strcmp */
/* Token reader: copies the next delimited token of s (length len) into out
 * (capacity size) and stores the number of characters consumed in *used. */
void fn_80378B68(const char* s, unsigned len, char* out, int size, int delim, int flag, unsigned* used);
}

/* Front-end action/condition object. Only the slots the code calls are
 * given (vslot3 = "is valid", vslot6 = parse one token). The derived structs
 * below add the value fields the individual classes use at +4. */
class UnkFEVirt {
public:
    virtual void fn_vslot1();
    virtual void fn_vslot2();
    virtual int fn_vslot3();
    virtual void fn_vslot4();
    virtual void fn_vslot5();
    virtual int fn_vslot6(char** s, int n);
};
struct UnkFEObj : UnkFEVirt {   /* int value (+4), two more ints */
    int m4;
    int m8;
    int mC;
};
struct UnkFEByte : UnkFEVirt {  /* flag byte (+4) */
    unsigned char m4;
};
struct UnkFEStr : UnkFEVirt {   /* string (+4) */
    char m4[0x40];
};

/* Object returned by fn_800B555C (front-end state): +0 and +4 written by the
 * flag actions (fn_800A94B4, fn_800A9328), +8 address passed to fn_800C1D6C
 * (fn_800A89DC), +0x608 compared by fn_800A9B0C / fn_800A9C90. */
struct Unk800B555C {
    int m0;
    int m4;
    int m8[0x180];
    int m608;
};
extern "C" Unk800B555C* fn_800B555C();

#endif
