#ifndef GAME_TU_80035DF0_H
#define GAME_TU_80035DF0_H

/*
 * Types for src/game/tu_80035DF0.cpp (reconstructed). The unit holds a small
 * comma-separated text parser (per-field helpers over a cursor + remaining
 * length pair) that reads rows of a play-call table (strings like "yes",
 * "earlyclose", "homebiglead" are looked up in tables of string pointers),
 * plus a few more handle helpers of the Unk80034E14 family.
 */
#include "game/tu_80034BBC.h"

struct Unk80034E14 : public Unk80034D00 {
    int mC;
    int m10;
};

extern const char* lbl_80616C0C;
extern const char* lbl_80616C10;
extern const char* lbl_80616C14[];
extern const char* lbl_80616C24[];
extern const char* lbl_80616C2C[];
extern const char* lbl_80616C38[];
extern const char* lbl_80616C60[];
extern const char* lbl_80616C6C[];
extern const char* lbl_80616C80[];
extern const char* lbl_80616C94[];
extern const char* lbl_80616CA0[];
extern const char* lbl_80616CD0[];
extern const char* lbl_80616CE4[];
extern const char* lbl_80616CF0[];
extern const char* lbl_80616CFC[];
extern const char* lbl_80616E24[];
extern const char* lbl_80616E38[];
extern char lbl_80649A78[];

extern "C" {
void fn_80035E38(Unk80034E14* self);
void fn_80035D94(Unk80034E14* self);
void fn_80378D70(const char* src, unsigned int len, char* dst, int cap, int delim, unsigned int* outn);
void fn_80379094(char* s, unsigned int n, int a);
int fn_80409DAC(const char* s);
char* fn_8040B948(const char* hay, const char* needle);
void fn_80329AEC(const char** pp, const char** out, unsigned int* pn, int delim);
void fn_80329C4C(const char** pp, unsigned int* pn, int* out, int lo, int hi, int delim);
void fn_800370B8(char* buf, unsigned char* out, const char* text, int lo3, int hi3, int lo5, int hi5);
void fn_80329D1C(const char** pp, unsigned int* pn, int* out, int lo, int hi, int delim);
const char* fn_802B9300(const char* s, int a, int b, unsigned int* outn);
void fn_802B961C(const char* p, int a);
void fn_803792AC(const char** pp, unsigned int* pn);
void fn_8003613C(char* buf, const char** pp, unsigned int* pn);
int fn_800361D8(char* buf, const char** pp, unsigned int* pn, int* out, int lo, int hi, int delim);
int fn_8003633C(char* buf, const char** pp, unsigned int* pn);
int fn_800363AC(char* buf, const char** pp, unsigned int* pn);
int fn_80036538(char* buf);
int fn_80036A28(void* x, const char** pp, unsigned int* pn, int delim);
int fn_80036AB4(void* x, const char** pp, unsigned int* pn, int delim);
int fn_80036B40(void* x, const char** pp, unsigned int* pn, int delim);
int fn_8003641C(char* buf, unsigned char* out, const char** pp, unsigned int* pn);
int fn_800365A4(char* buf, int* out, const char** pp, unsigned int* pn);
int fn_80036628(char* buf, int* out, const char** pp, unsigned int* pn);
}

#endif /* GAME_TU_80035DF0_H */
