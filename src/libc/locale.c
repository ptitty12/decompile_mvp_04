/* Imported from emoose/re4 @ feb6805b (src/game/locale.c). newlib 1.8.2 as built into SN ProDG's libc. */
/* newlib 1.8.2 libc/locale/locale.c (MB_CAPABLE); _setlocale_r/setlocale were dead-stripped, but in
 * MVP their static lc_ctype buffers and locale-name strings are still linked */
#include "newlib_stdio.h"

/* limits.h: ProDG chars are unsigned (-D__CHAR_UNSIGNED__) */
#ifdef __CHAR_UNSIGNED__
#define CHAR_MAX 255
#else
#define CHAR_MAX 127
#endif
#define LC_ALL 0
#define LC_CTYPE 2

struct lconv {
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
    char *int_curr_symbol;
    char *currency_symbol;
    char *mon_decimal_point;
    char *mon_thousands_sep;
    char *mon_grouping;
    char *positive_sign;
    char *negative_sign;
    char int_frac_digits;
    char frac_digits;
    char p_cs_precedes;
    char p_sep_by_space;
    char n_cs_precedes;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
};

extern int strcmp(const char *, const char *);
extern size_t strlen(const char *);

extern int __mb_cur_max;

extern struct lconv lbl_8060EEE4;

/* The fixed "C" numeric/monetary formatting table. */
struct lconv *_localeconv_r(struct _reent *data)
{
    return &lbl_8060EEE4;
}

struct lconv *localeconv(void)
{
    return _localeconv_r(_REENT);
}
