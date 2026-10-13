/*
 * Front-end overlay code, .frontend_codeoverlay 0x804E750C-0x804EA2E4 (code-only unit;
 * placeholder TU). Define every function FE_OVERLAY (game/overlay.h); data extern by lbl_ name.
 */

#define FE_SCREEN_CF44_VOID

#define FE_SCREEN_D004_VOID

#include "game/fe_804E02E0.h"

/* Q16-DECL-BEGIN */
struct FeS7a : FeObj {
    char pad40[0x134 - 0x40];
    FeObj1* m134;
    int m138;
    FeObj* m13C;
    FeObjK* m140;
    FeObj1* m144;
    char pad148[0x14C - 0x148];
    FeObj* m14C;
    FeObj* m150;
    char pad154[0x164 - 0x154];
    FeObj* m164;
};
struct FeS7b : FeObj {
    char pad40[0x134 - 0x40];
    int m134;
    char pad138[0x150 - 0x138];
    FeObj* m150;
};
extern char lbl_805F4F84[];
extern char lbl_805FA7B4[];
extern "C" {
void fn_804E8B40(void);
void fn_8013D164(FeObj* w, int v);
void fn_804E8780(FeS7a* self);
int fn_804E8A30(FeS7b* self, unsigned short* s);
void fn_804E8CB4(FeS9* self);
void fn_800DFF5C(unsigned short* s);
int fn_80403060(const unsigned short* s);
int fn_804030C8(const unsigned short* a, const unsigned short* b);
}
unsigned fn_8007DBB0(Unk8007DB74_A* a);
#define FE_LO30(X) \
    X(1) X(2) X(3) X(4) X(5) X(6) X(7) X(8) X(9) X(10) X(11) X(12) X(13) X(14) X(15) X(16) X(17) \
    X(18) X(19) X(20) X(21) X(22) X(23) X(24) X(25) X(26) X(27) X(28) X(29) X(30)
class FeObjR31 : public UiBase {
public:
    FE_LO30(FE_V0) virtual const void* v31(); virtual FeObj* v32(const char* a, int b); FE_HI(FE_V0)
};
struct FeS7c : FeObj {
    char pad40[0x134 - 0x40];
    int m134;
    char pad138[0x13C - 0x138];
    FeObjR31* m13C;
};
struct FeS7d : FeObj {
    char pad40[0x134 - 0x40];
    int m134;
    char pad138[0x160 - 0x138];
    int m160;
    char pad164[0x168 - 0x164];
    int m168;
    int m16C;
};
extern "C" int sprintf(char* d, const char* fmt, ...);
void fn_800E2944(int a, int b);
#define FE_R33_42(X) X(33) X(34) X(35) X(36) X(37) X(38) X(39) X(40) X(41) X(42)
#define FE_R44_66(X) \
    X(44) X(45) X(46) X(47) X(48) X(49) X(50) X(51) X(52) X(53) X(54) X(55) X(56) X(57) X(58) X(59) X(60) \
    X(61) X(62) X(63) X(64) X(65) X(66)
#define FE_R68_127(X) \
    X(68) X(69) X(70) X(71) X(72) X(73) X(74) X(75) X(76) X(77) X(78) X(79) X(80) X(81) X(82) X(83) X(84) \
    X(85) X(86) X(87) X(88) X(89) X(90) X(91) X(92) X(93) X(94) X(95) X(96) X(97) X(98) X(99) X(100) \
    X(101) X(102) X(103) X(104) X(105) X(106) X(107) X(108) X(109) X(110) X(111) X(112) X(113) X(114) \
    X(115) X(116) X(117) X(118) X(119) X(120) X(121) X(122) X(123) X(124) X(125) X(126) X(127)
/* List widget whose v43 takes (row, col, text, flags) and v67 two ints. */
class FeObjL43 : public UiBase {
public:
    FE_LO(FE_V0) virtual FeObj* v32(const char* a, int b); FE_R33_42(FE_V0) virtual void v43(int a, int b, void* c, int d);
    FE_R44_66(FE_V0) virtual void v67(int a, int b); FE_R68_127(FE_V0)
};
struct FeS7e : FeObj {
    char pad40[0x134 - 0x40];
    FeObj1* m134;
    char pad138[0x140 - 0x138];
    FeObjL43* m140;
    FeObj1* m144;
};
struct FeSt8x {
    char pad0[0x610];
    int m610;
};
class FeSubI21 {
public:
    char pad0[0x24];
    virtual int s1(); virtual int s2(); virtual int s3(); virtual int s4(); virtual int s5(); virtual int s6(); virtual int s7();
    virtual int s8(); virtual int s9(); virtual int s10(); virtual int s11(); virtual int s12(); virtual int s13(); virtual int s14();
    virtual int s15(); virtual int s16(); virtual int s17(); virtual int s18(); virtual int s19(); virtual int s20(); virtual int s21();
};
struct FeS7f : FeObj {
    char pad40[0x134 - 0x40];
    int m134;
    char pad138[0x13C - 0x138];
    FeObjR31* m13C;
    char pad140[0x154 - 0x140];
    int m154;
    FeObj* m158;
    char pad15C[0x168 - 0x15C];
    int m168;
};
int fn_8007DB8C(Unk8007DB74_A* a, int b, int c);
extern "C" void fn_804E8E54(FeS7f* self, int a);
extern "C" void fn_804E9220(FeS7* self);
struct FeS7g : FeObj {
    char pad40[0x138 - 0x40];
    FeObjK* m138;
    FeObjR31* m13C;
    char pad140[0x14C - 0x140];
    FeObj* m14C;
    char pad150[0x160 - 0x150];
    int m160;
};
extern "C" void fn_8013D4CC(FeObj* w, void* cb1, void* cb2, const void* s, int a, int b, int c, int d);
class FeObjQ15 : public UiBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(int a); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(int a); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
    virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual FeObjQ15* v32(const char* a, int b); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(int a, int b); virtual void v68();
    virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73();
    virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78();
    virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88();
    virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93();
    virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98();
    virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102();
    virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106();
    virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110();
    virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114();
    virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118();
    virtual void v119(); virtual void v120(); virtual void v121(); virtual void v122();
    virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126();
    virtual void v127();
};
class FeSubQ15 {
public:
    char pad0[0x24];
    virtual int s1(); virtual int s2(); virtual int s3(); virtual int s4(); virtual int s5(); virtual int s6();
    virtual int s7(); virtual int s8(); virtual int s9(); virtual int s10(); virtual int s11(); virtual int s12();
    virtual int s13(); virtual int s14(); virtual int s15(); virtual int s16(); virtual int s17(); virtual int s18();
    virtual int s19(); virtual void s20(int a, int b);
};
struct FeS7z : FeObj {
    char pad40[0x134 - 0x40];
    FeObjQ15* m134;
    char pad138[0x13C - 0x138];
    FeObj* m13C;
};
extern const char lbl_805F7B50[];
extern const char lbl_805FA710[];
extern const char lbl_805F6548[];
extern const char lbl_805FA71C[];
extern const char lbl_805FA72C[];
class FeObjQ16 : public UiBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(int a);
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual void v29(int a); virtual void v30(); virtual void v31();
    virtual FeObjQ16* v32(const char* a, int b); virtual FeObjQ16* v33(int a, int b);
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(int a, int b);
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72();
    virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82();
    virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92();
    virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97();
    virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101();
    virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105();
    virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
    virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113();
    virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117();
    virtual void v118(); virtual void v119(); virtual void v120(); virtual void v121();
    virtual void v122(); virtual void v123(); virtual void v124(); virtual void v125();
    virtual void v126(); virtual void v127();
};
struct FeS7y : FeObj {
    char pad40[0x134 - 0x40];
    FeObjQ16* m134;
    char pad138[0x13C - 0x138];
    int m13C;
};
extern const char lbl_805F57D0[];
extern const char lbl_805FA7C4[];
extern "C" void fn_800DD204__FP3UiST0(FeObj* a, FeObj* b);
extern "C" void fn_804E9C88(FeS7y* self);
class FeObjQ17 : public UiBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(int a); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual FeObjQ17* v32(const char* a, int b);
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(int a, int b, const void* s, int c);
    virtual void v44(int a, int b, const char* s, int c); virtual void v45(); virtual void v46();
    virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56();
    virtual void v57(); virtual int v58(); virtual void v59(); virtual void v60(); virtual void v61();
    virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66();
    virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual FeObjQ17* v73(int a, int b); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(int a, int b);
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
    virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
    virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
    virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
    virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
    virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115();
    virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
    virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123();
    virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127();
};
int fn_80083F6C(int a);
int fn_80084114(int a);
int fn_800E190C(int a);
class FeObjQ23 : public UiBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual FeObjQ23* v33(int a, int b); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual FeObjQ23* v70(); virtual void v71(); virtual void v72(); virtual void v73();
    virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78();
    virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88();
    virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93();
    virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98();
    virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102();
    virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106();
    virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110();
    virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114();
    virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118();
    virtual void v119(); virtual void v120(); virtual void v121(); virtual void v122();
    virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126();
    virtual void v127();
};
struct FeBit31 {
    unsigned top : 1;
    unsigned rest : 31;
};
struct FeS7w : FeObj {
    char pad40[0x134 - 0x40];
    FeObjQ23* m134;
    int m138;
    char pad13C[0x144 - 0x13C];
    UiBase* m144;
};
struct FeStQ23 {
    char pad0[0x4C4];
    int m4C4;
    int m4C8;
    int m4CC;
    int m4D0;
    char pad4D4[0x614 - 0x4D4];
    int m614;
    int m618;
};
extern const char lbl_805FA738[];
extern const char lbl_805FA740[];
extern const char lbl_805FA620[];
extern const char lbl_805F5B44[];
extern const char lbl_805F4450[];
extern "C" FeObj* fn_800C8068(void* p);
class FeObjQ24 : public UiBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual FeObjQ24* v29(const char* a);
    virtual void v30(); virtual void v31(); virtual FeObjQ24* v32(const char* a, int b);
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52();
    virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57();
    virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62();
    virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72();
    virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82();
    virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92();
    virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97();
    virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101();
    virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105();
    virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
    virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113();
    virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117();
    virtual void v118(); virtual void v119(); virtual void v120(); virtual void v121();
    virtual void v122(); virtual void v123(); virtual void v124(); virtual void v125();
    virtual void v126(); virtual void v127();
};
class FeObjQ25 : public UiBase {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(int a);
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
    virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
    virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
    virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
    virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
    virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115();
    virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
    virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123();
    virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127();
};
class FeSubQ24 {
public:
    char pad0[8];
    unsigned a : 1;
    unsigned b : 1;
    unsigned c : 1;
    unsigned rest : 29;
    char padC[0x24 - 0xC];
    virtual int s1(); virtual int s2(); virtual int s3(); virtual int s4(); virtual int s5(); virtual int s6();
    virtual int s7(); virtual int s8(); virtual int s9(); virtual int s10(); virtual int s11(); virtual int s12();
    virtual int s13(); virtual int s14(); virtual int s15(); virtual int s16(); virtual int s17(); virtual int s18();
    virtual int s19(); virtual int s20(); virtual int s21(); virtual void s22(int a);
};
class FeSubQ26 {
public:
    char pad0[0x24];
    virtual int s1(); virtual int s2(); virtual int s3(); virtual int s4(); virtual int s5(); virtual int s6();
    virtual int s7(); virtual int s8(); virtual void s9(int a, int b);
};
struct FeS8a : FeObj {
    char pad40[0x134 - 0x40];
    int m134;
    FeObj* m138;
    FeObj* m13C;
    FeObj* m140;
    FeObj* m144;
    FeObj* m148;
    FeObj* m14C;
    FeObj* m150;
    int m154;
    FeObj* m158;
    FeObj* m15C;
};
struct FeStQ24 {
    char pad0[0x618];
    int m618;
};
extern const char lbl_805FA748[];
extern const char lbl_805FA754[];
extern const char lbl_805FA764[];
extern const char lbl_805FA770[];
extern const char lbl_805FA778[];
extern const char lbl_805FA780[];
extern const char lbl_805FA794[];
extern const char lbl_805FA7A4[];
extern const char lbl_805F7A0C[];
extern const char lbl_805F7B14[];
extern const char lbl_805F4F0C[];
extern "C" void fn_800DD204__FP3UiST0(FeObj* a, FeObj* b);
extern const char lbl_805F4EF4[];
/* Q16-DECL-END */

extern "C" FE_OVERLAY void fn_804E750C(FeS7z* self)
{
    fn_800ECF18(self);
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), lbl_805F4F84);
    fn_80124FA8(p, self);
    ((int (*)(FeObj*, int))fn_80125154)(p, 1);
    fn_801251CC(p, 0, 0x10, 0);
    int sel = lbl_8061930C->fn_8007DA28();
    fn_800E26B4(sel, (int)fn_800C8044(((FeObjQ15*)self)->v32(lbl_805F7B50, 1)));
    self->m134->v67(0, 0);
    self->m134->v14(1);
    if (sel != -1) {
        int w = lbl_8061930C->fn_8007D098(sel, 0);
        FeObj* a = fn_800C8044(((FeObjQ15*)self)->v32(lbl_805FA710, 1));
        self->m13C = fn_800C8054(((FeObjQ15*)a)->v32(lbl_805F6548, 1));
        ((FeSubQ15*)((char*)self->m13C + 0x98))->s20(w, 0);
        ((FeObjQ15*)((FeObjQ15*)self)->v32(lbl_805FA710, 1))->v8(1);
    } else {
        ((FeObjQ15*)((FeObjQ15*)self)->v32(lbl_805FA710, 1))->v8(0);
    }
    if (lbl_8061930C->fn_8007DA28() != -1 && lbl_8061930C->fn_8007DADC(sel) != 0) {
        ((FeObjQ15*)((FeObjQ15*)self)->v32(lbl_805FA71C, 1))->v8(1);
        ((FeObjQ15*)((FeObjQ15*)self)->v32(lbl_805FA72C, 1))->v8(1);
        return;
    }
    ((FeObjQ15*)((FeObjQ15*)self)->v32(lbl_805FA71C, 1))->v8(0);
    ((FeObjQ15*)((FeObjQ15*)self)->v32(lbl_805FA72C, 1))->v8(0);
}

extern "C" FE_OVERLAY void fn_804E7860(void* self, int a)
{
    fn_800ECAA4(self);
}

extern "C" FE_OVERLAY int fn_804E7880(FeS7* self)
{
    if (self->m140->m24 & 0x40000000) {
        int a = ((FeObjK*)self->m140)->v60();
        if (a == ((FeObjK*)self->m140)->v59() - 1)
            fn_804E7D44(self, 0);
        else
            fn_804E7D44(self, 1);
    } else
        ((FeObj2*)self)->v67(0, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7940(FeS7* self)
{
    if (self->m140->m24 & 0x40000000)
        self->m140->v50();
    else
        self->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E79A8(FeS7* self)
{
    if (self->m140->m24 & 0x40000000)
        self->m140->v51();
    else
        self->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7A10(FeS7* self)
{
    if (self->m140->m24 & 0x40000000)
        self->m140->v52();
    else
        self->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7A78(FeS7* self)
{
    if (self->m140->m24 & 0x40000000)
        self->m140->v53();
    else
        self->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7AE0(FeWf134* self)
{
    self->m134->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7B1C(FeWf134* self)
{
    self->m134->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7B58(FeWf134* self)
{
    self->m134->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7B94(FeWf134* self)
{
    self->m134->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E7BD0(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_804E7BD8(FeS7e* self)
{
    self->m144->v16(1);
    self->m144->v8(1);
    self->m134->v16(0);
    fn_8001BC4C()->fn_8001BDAC(0x9D);
    ((FeObj1*)fn_800B7A94(UiGetMsgMgr(), lbl_805F4F84))->v16(0);
    Unk8007B2B0_Screen* sc = lbl_8061930C;
    unsigned short tmp[12];
    for (unsigned i = 0; i < fn_8007DBB0((Unk8007DB74_A*)sc); i++) {
        sc->fn_8007CF44(i, (int)tmp, 0);
        self->m140->v43(i, 0, tmp, 5);
    }
    self->m140->v67(0, 0);
}

extern "C" FE_OVERLAY void fn_804E7D44(FeS7* s7, int a)
{
    FeS7a* self = (FeS7a*)s7;
    self->m144->v16(0);
    self->m144->v8(0);
    self->m134->v16(1);
    ((FeObj1*)fn_800B7A94(UiGetMsgMgr(), lbl_805F4F84))->v16(1);
    if (a != 0) {
        self->m138 = self->m140->v60();
        ((FeObj2*)self)->v67(0, 0);
    } else {
        fn_8001BC4C()->fn_8001BDAC(0x9D);
        self->m138 = -1;
    }
}

extern char lbl_8066BA30[];
/* near-miss: 99.8%; in the d == 0 branch retail stores m4CC (the zero in r31) last, ours hoists it first; all 24 store orders tried. The flag is a 1-bit field (srwi + separate cmpwi). */
extern "C" FE_OVERLAY void fn_804E7E80(FeS7w* self, int kind, int arg2)
{
    unsigned flag = ((FeBit31*)&self->m144->m24)->top;
    if (flag == 0) {
        switch (kind) {
        case 0: {
            char* p = (char*)fn_800C8068(self->m134->v70()->v33(14, 1)) + 0xC;
            if (fn_8040B574(lbl_805FA738, p) == 0 || fn_8040B574(lbl_805FA620, p) == 0) {
                if (fn_8007DBB0((Unk8007DB74_A*)lbl_8061930C) == 4 && self->m138 == -1) {
                    fn_804E7BD8((FeS7e*)self);
                    return;
                }
                int mm = self->m138;
                if (mm != -1)
                    fn_8007DB74((Unk8007DB74_A*)lbl_8061930C, mm);
            }
            if (fn_8040B574(lbl_805F5B44, p) != 0) {
                int c = fn_8040B574(lbl_805FA620, p);
                if (c == 0) {
                    FeStQ23* s = (FeStQ23*)((char*)fn_800B555C() + 8);
                    s->m614 = 1;
                    s->m618 = arg2;
                    FeStQ23* st = (FeStQ23*)((char*)fn_800B555C() + 8);
                    st->m4D0 = (int)fn_80090880(lbl_8061977C, 0x60D);
                    st->m4C4 = c;
                    st->m4CC = c;
                    st->m4C8 = 0x200000;
                } else {
                    int d = fn_8040B574(lbl_805FA740, p);
                    if (d == 0) {
                        FeStQ23* st = (FeStQ23*)((char*)fn_800B555C() + 8);
                        st->m4D0 = (int)fn_80090880(lbl_8061977C, 0x60D);
                        st->m4C4 = 2;
                        st->m4C8 = 0x200000;
                        st->m4CC = d;
                    }
                }
            }
            UiMsg m;
            UiMsg* mp = &m;
            fn_8035682C(mp);
            fn_8040B830(mp->name, p, 15);
            mp->name[15] = 0;
            fn_800B7B4C(UiGetMsgMgr(), mp, self);
            break;
        }
        case 1: {
            UiMsg m;
            UiMsg* mp = &m;
            fn_8035682C(mp);
            fn_8040B830(mp->name, lbl_805F4450, 15);
            mp->name[15] = flag;
            fn_800B7B4C(UiGetMsgMgr(), mp, self);
            break;
        }
        }
    }
}

extern "C" FE_OVERLAY FeScrRaw* fn_804E80FC(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066BA30;
    self->m130 = 0;
    self->m134 = -1;
    self->m138 = 0;
    self->m13C = 0;
    self->m140 = 0;
    self->m144 = 0;
    self->m148 = 0;
    self->m14C = 0;
    self->m150 = 0;
    self->m154 = 0;
    self->m164 = 0;
    self->m168 = 0;
    self->m160 = -1;
    self->m16C = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804E8180(FeS8a* self)
{
    int z = 0;
    int one = 1;
    fn_800ECE34(self);
    self->m138 = fn_800C8060(((FeObjQ24*)self)->v32(lbl_805F4EF4, 1));
    self->m140 = fn_800C805C(((FeObjQ24*)self->m138)->v29(lbl_805FA748));
    self->m144 = fn_800C805C(((FeObjQ24*)self->m138)->v29(lbl_805FA754));
    self->m148 = fn_800C8058(((FeObjQ24*)self->m144)->v32(lbl_805FA764, 1));
    self->m158 = fn_800C8058(((FeObjQ24*)self->m140)->v32(lbl_805FA770, 1));
    self->m15C = fn_800C8054(((FeObjQ24*)self->m140)->v32(lbl_805FA778, 1));
    FeSubQ24* s1 = (FeSubQ24*)((char*)self->m158 + 0xDC);
    s1->c = z;
    s1->s22(0);
    FeSubQ24* s2 = (FeSubQ24*)((char*)self->m15C + 0x98);
    s2->c = z;
    s2->s22(0);
    *(int*)((char*)self->m158 + 0xFC) = one;
    *(int*)((char*)self->m15C + 0xB8) = one;
    ((FeSubQ26*)((char*)self->m148 + 0xDC))->s9(0, 0);
    ((FeSubQ26*)((char*)self->m148 + 0xDC))->s9(1, 1);
    ((FeSubQ26*)((char*)self->m148 + 0xDC))->s9(2, 2);
    ((FeSubQ26*)((char*)self->m148 + 0xDC))->s9(3, 3);
    self->m14C = fn_800B7AB8(UiGetMsgMgr(), lbl_805F7B14);
    self->m150 = fn_800B7AB8(UiGetMsgMgr(), lbl_805F4F0C);
    self->m13C = fn_800C8048(((FeObjQ24*)self->m138)->v29(lbl_805FA780));
    FeObjQ25* a = (FeObjQ25*)fn_800C8040(((FeObjQ24*)self)->v29(lbl_805F7A0C));
    FeObj* t = fn_800C8038(((FeObjQ24*)self)->v29(lbl_805FA794));
    FeObjQ25* b = (FeObjQ25*)fn_800C8040(((FeObjQ24*)self)->v32(lbl_805FA7A4, 1));
    if (fn_800B555C()->m0 == 0x4D) {
        self->m154 = one;
        a->v29(0x40EC);
        self->m134 = ((FeStQ24*)fn_800B555C())->m618;
        b->v29(0x5D78);
    } else {
        a->v29(0x40E8);
        self->m134 = -1;
        b->v29(0x5D77);
    }
    fn_800DD204__FP3UiST0((FeObj*)a, t);
}

extern "C" FE_OVERLAY void fn_804E858C(FeS7a* self)
{
    fn_800ECF18(self);
    self->m164 = fn_800B7A94(UiGetMsgMgr(), lbl_805F4F84);
    fn_80124FA8(self->m164, self);
    fn_80125154(self->m164, 1);
    if (fn_800B555C()->m0 != 0x4D)
        fn_801251CC(self->m164, 0, 0x10, 0);
    fn_8013D164(self->m14C, 8);
    fn_804E8780(self);
}

extern "C" FE_OVERLAY void fn_804E8640(void)
{
}

extern "C" FE_OVERLAY void fn_804E8644(void* s)
{
    FeS7c* self = (FeS7c*)s;
    FeObj* a = fn_800C8044(self->v32("INFO", 1));
    FeObj* b = fn_800C8040(a->v32("NAME", 1));
    ((FeObj1*)b)->v28((int)self->m13C->v31());
    int k = 0;
    if (self->m134 != -1)
        k = lbl_8061930C->fn_8007D050(self->m134, 8);
    char buf[400];
    sprintf(buf, "%d", k);
    ((FeObjS*)fn_800C8040(a->v32("CREDITS", 1)))->v30(buf);
}

extern "C" FE_OVERLAY int fn_804E8A30(FeS7b* self, unsigned short* s)
{
    Unk8007B2B0_Screen* sc = lbl_8061930C;
    int cur = self->m134;
    unsigned short tmp[12];
    for (unsigned i = 0; i < fn_8007DBB0((Unk8007DB74_A*)lbl_8061930C); i++) {
        if ((int)i != cur) {
            sc->fn_8007CF44(i, (int)tmp, 0);
            if (fn_804030C8(tmp, s) == 0) {
                fn_80131F34(self->m150, self, (FeCb)fn_804E8B40, 0, 0x3FD7, 1, -1, 1, 0x26DE, 0, 0, 0, 0, 0);
                ((FeObj1*)self->m150)->v84(0);
                self->m150->v86();
                return 1;
            }
        }
    }
    return 0;
}

extern "C" FE_OVERLAY void fn_804E8B40(void)
{
}

extern "C" FE_OVERLAY void fn_804E8B44(unsigned short* name)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), lbl_805FA7B4);
    unsigned short buf[100];
    fn_80403144((char*)buf, (const char*)name);
    fn_800DFF5C(buf);
    ((FeObj1*)p)->v16(1);
    ((FeObj1*)p)->v8(1);
    if (fn_80403060(buf) > 0 && fn_804E8A30((FeS7b*)p, buf) == 0)
        ((void (*)(FeObj*, unsigned short*))fn_804E8CB4)(p, buf);
}

extern "C" FE_OVERLAY void fn_804E8C20(void)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), "USERPROFEDIT");
    ((FeObj1*)p)->v16(1);
    ((FeObj1*)p)->v8(1);
}

extern "C" FE_OVERLAY void fn_804E8CB4(FeS9* self)
{
    self->m13C->v28();
    fn_804E8644(self);
}

extern "C" FE_OVERLAY void fn_804E8D00(int a, FeObj* self)
{
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), lbl_805FA7B4);
    UiMsg m;
    UiMsg* mp = &m;
    fn_8035682C(mp);
    ((FeObj1*)p)->v16(1);
    ((FeObj1*)p)->v8(1);
    FeS7d* d = (FeS7d*)p;
    d->m16C = 0;
    if (a == 0)
        fn_800E2944(d->m134, d->m160);
    if (d->m168 != 0) {
        fn_8040B830(mp->name, "SAVE", 15);
        mp->name[15] = 0;
    } else {
        fn_8040B830(mp->name, "DONE", 15);
        mp->name[15] = 0;
    }
    ((FeObj1*)self)->v80(1);
    fn_800B7B4C(UiGetMsgMgr(), &m, self);
}

extern "C" FE_OVERLAY void fn_804E90A4(int kind)
{
    FeS7f* p = (FeS7f*)fn_800B7A94(UiGetMsgMgr(), lbl_805FA7B4);
    if (p->m154 == 1) {
        Unk8007B2B0_Screen* sc = lbl_8061930C;
        int idx = p->m134;
        sc->fn_8007D004(idx, 0, ((FeSubI21*)((char*)p->m158 + 0xDC))->s21());
        Unk8007B2B0_Screen* sc2 = lbl_8061930C;
        sc2->fn_8007CF90(p->m134, (int)p->m13C->v31());
    } else {
        Unk8007DB74_A* sc = (Unk8007DB74_A*)lbl_8061930C;
        int s = (int)p->m13C->v31();
        p->m134 = fn_8007DB8C(sc, s, ((FeSubI21*)((char*)p->m158 + 0xDC))->s21());
    }
    switch (kind) {
    case 0:
        p->m168 = 1;
        fn_804E9220((FeS7*)p);
        break;
    case 1:
        p->m168 = 0;
        break;
    }
    fn_804E8E54(p, 0);
}

extern "C" FE_OVERLAY void fn_804E9220(FeS7* self)
{
    fn_800E29CC((int)self->m134);
}

extern "C" FE_OVERLAY void fn_804E9244(FeS7* self, int a)
{
    fn_800ED310(self, a);
    if (a != 0)
        ((FeObj1*)self->m138)->v14(1);
    else
        ((FeObj1*)self->m138)->v14(0);
}

extern "C" FE_OVERLAY int fn_804E92C0(FeS11* self)
{
    self->m138->v50();
    int a = ((FeObjK*)self->m138)->v60() + 1;
    if (a == ((FeObjK*)self->m138)->v59() || ((FeObjK*)self->m138)->v60() == 0)
        fn_801251CC(self->m164, 0, 16, 0);
    else
        fn_80125084(self->m164, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E9394(FeW138* self)
{
    self->m138->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E93D0(FeS11* self)
{
    self->m138->v52();
    int a = ((FeObjK*)self->m138)->v60() + 1;
    if (a == ((FeObjK*)self->m138)->v59() || ((FeObjK*)self->m138)->v60() == 0)
        fn_801251CC(self->m164, 0, 16, 0);
    else
        fn_80125084(self->m164, 0);
    return 1;
}

extern "C" FE_OVERLAY int fn_804E94A4(FeW138* self)
{
    self->m138->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E94E0(FeWf138* self)
{
    self->m138->v56();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E951C(FeWf138* self)
{
    self->m138->v57();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E9558(FeWf138* self)
{
    self->m138->v54();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E9594(FeWf138* self)
{
    self->m138->v55();
    return 1;
}

extern "C" FE_OVERLAY int fn_804E95D0(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_804E95D8(FeS8* self, int a)
{
    if (a == self->m144) {
        fn_800D0074(&self->m158->mDC, ((FeSub*)&self->m148->mDC)->s11(), 0);
        fn_800D0074(&self->m15C->m98, ((FeSub*)&self->m148->mDC)->s11(), 0);
    }
}

extern "C" FE_OVERLAY void fn_804E967C(FeS7g* self, int kind, int x)
{
    switch (kind) {
    case 0:
        if (self->m138->v60() == 0) {
            ((FeObj1*)self)->v16(0);
            fn_8013D4CC(self->m14C, (void*)fn_804E8B44, (void*)fn_804E8C20, self->m13C->v31(), 8, 3, 1, 0);
        } else if (self->m138->v60() == 3) {
            self->m160 = x;
            if (fn_804E8A30((FeS7b*)self, (unsigned short*)self->m13C->v31()) == 0)
                fn_804E8E54((FeS7f*)self, 1);
        }
        break;
    case 1: {
        UiMsg m;
        UiMsg* mp = &m;
        fn_8035682C(mp);
        fn_8040B830(mp->name, "BACK", 15);
        mp->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), &m, self);
        break;
    }
    }
}

extern char lbl_8066B788[];
extern "C" FE_OVERLAY FeScrRaw* fn_804E9810(FeScrRaw* self, int a, int b, int c, int d, int e, int f, int g, int h)
{
    fn_800EC648(self, a, b, c, d, e, f, g, h);
    self->m3C = lbl_8066B788;
    self->m130 = 0;
    self->m134 = 0;
    self->m138 = 0;
    self->m13C = 0;
    return self;
}

extern "C" FE_OVERLAY void fn_804E9868(FeS7* self)
{
    fn_800ECE34(self);
    self->m134 = fn_800C8060(self->v32("PROFILES", 1));
    ((FeObj1*)self->m134)->v105(1);
    self->m138 = fn_800C8044(self->v32("INFO", 1));
    if (fn_800B555C()->m0 == 0x4D)
        self->m13C = 1;
    else if (fn_800B555C()->m4 & 0x200)
        self->m13C = 2;
}

extern "C" FE_OVERLAY void fn_804E9938(FeS7y* self)
{
    fn_800ECF18(self);
    FeObj* p = fn_800B7A94(UiGetMsgMgr(), lbl_805F4F84);
    fn_80124FA8(p, self);
    ((int (*)(FeObj*, int))fn_80125154)(p, 1);
    fn_801251CC(p, 0, 0x10, 0);
    int sel = lbl_8061930C->fn_8007DA28();
    fn_800E26B4(sel, (int)fn_800C8044(((FeObjQ16*)self)->v32(lbl_805F7B50, 1)));
    fn_804E9C88(self);
    if (sel == -1)
        self->m134->v67(0, 0);
    FeObjQ16* w = (FeObjQ16*)fn_800C8044(((FeObjQ16*)self)->v32(lbl_805F57D0, 1));
    FeObjQ16* a = (FeObjQ16*)fn_800C8040(w->v33(4, 1));
    FeObj* t = fn_800C8038(w->v33(2, 1));
    FeObjQ16* b = (FeObjQ16*)fn_800C8040(((FeObjQ16*)self)->v32(lbl_805FA7C4, 1));
    if (self->m13C == 0) {
        self->m134->v67(sel + 1, 0);
        a->v29(0x3FCC);
        b->v29(0x5D86);
    } else {
        if (sel != -1)
            self->m134->v67(sel, 0);
        if (self->m13C == 1) {
            a->v29(0x3FCF);
            b->v29(0x5D78);
        } else {
            a->v29(0x3FD1);
            b->v29(0x5D87);
        }
    }
    fn_800DD204__FP3UiST0((FeObj*)a, t);
    self->m134->v14(1);
}

extern "C" FE_OVERLAY int fn_804E9C20(FeS7* self)
{
    int r;
    if (self->m13C != 0)
        r = ((FeObjK*)self->m134)->v60();
    else
        r = ((FeObjK*)self->m134)->v60() - 1;
    return r;
}

extern "C" FE_OVERLAY void fn_804E9C88(FeS7y* self)
{
    char buf1[0x18];
    char buf2[0x10];
    int start = 0;
    int n = fn_8007DBB0((Unk8007DB74_A*)lbl_8061930C);
    Unk8007B2B0_Screen* g = lbl_8061930C;
    Unk80090880* tbl = lbl_8061977C;
    if (self->m13C == 0)
        n += 1;
    ((FeObjQ17*)self->m134)->v79(n, 0);
    ((FeObjQ17*)self->m134)->v3();
    if (self->m13C == 0) {
        ((FeObjQ17*)self->m134)->v43(0, 0, fn_80090880(tbl, 0x3FB5), 5);
        start = 1;
        int i = 1;
        while (i < ((FeObjQ17*)self->m134)->v58()) {
            ((FeObjQ17*)self->m134)->v43(0, i, fn_80090880(tbl, 0xBBC), 5);
            i++;
        }
    }
    int row = start;
    int idx = 0;
    if (row < n) {
        do {
            g->fn_8007CF44(idx, (int)buf1, 0);
            ((FeObjQ17*)self->m134)->v43(row, 0, buf1, 5);
            int v = g->fn_8007D098(idx, 0);
            ((FeObjQ17*)self->m134)->v43(row, 1, fn_80090880(tbl, fn_800E190C(v)), 5);
            int q = fn_80084114(g->fn_8007B8C4(0, v));
            ((FeObjQ17*)self->m134)->v43(row, 2, fn_80090880(tbl, fn_80083F6C(q)), 5);
            sprintf(buf2, "%d", g->fn_8007D050(idx, 8));
            ((FeObjQ17*)self->m134)->v44(row, 3, buf2, 5);
            if (g->fn_8007DADC(idx) != 0) {
                FeObjQ17* c = ((FeObjQ17*)self->m134)->v73(row, 0);
                ((FeObjQ17*)fn_800C8038(fn_800C8044(c)->v32(lbl_805FA72C, 1)))->v8(1);
            } else {
                FeObjQ17* c = ((FeObjQ17*)self->m134)->v73(row, 0);
                ((FeObjQ17*)fn_800C8038(fn_800C8044(c)->v32(lbl_805FA72C, 1)))->v8(0);
            }
            row++;
            idx++;
        } while (row < n);
    }
}

extern "C" FE_OVERLAY void fn_804EA038(FeS7* self, int a)
{
    if (a == (int)self->m134)
        fn_800E26B4(fn_804E9C20(self), (int)self->m138);
}

extern "C" FE_OVERLAY int fn_804EA078(FeScr_80447264* self)
{
    self->m134->v50();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA0B4(FeScr_80447264* self)
{
    self->m134->v51();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA0F0(FeScr_80447264* self)
{
    self->m134->v52();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA12C(FeScr_80447264* self)
{
    self->m134->v53();
    return 1;
}

extern "C" FE_OVERLAY int fn_804EA168(void)
{
    return 0;
}

extern "C" FE_OVERLAY void fn_804EA170(FeS7* self, int kind, int x)
{
    switch (kind) {
    case 0: {
        UiMsg m;
        UiMsg* mp = &m;
        fn_8035682C(mp);
        if (self->m13C == 1) {
            fn_8040B830(mp->name, "EDIT", 15);
            mp->name[15] = 0;
            FeSt8x* st = (FeSt8x*)((char*)fn_800B555C() + 8);
            st->m610 = fn_804E9C20(self);
        } else if (self->m13C == 2) {
            fn_8040B830(mp->name, "SAVE", 15);
            mp->name[15] = 0;
            fn_800E29CC(fn_804E9C20(self));
        } else {
            fn_8040B830(mp->name, "SETACTIVE", 15);
            mp->name[15] = 0;
            fn_800E2944(fn_804E9C20(self), x);
        }
        fn_800B7B4C(UiGetMsgMgr(), &m, self);
        break;
    }
    case 1: {
        UiMsg m;
        UiMsg* mp = &m;
        fn_8035682C(mp);
        fn_8040B830(mp->name, "BACK", 15);
        mp->name[15] = 0;
        fn_800B7B4C(UiGetMsgMgr(), &m, self);
        break;
    }
    }
}
