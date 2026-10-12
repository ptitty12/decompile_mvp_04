/*
 * Dolphin SDK VM (MWCC GC/2.0: LR saved after the stack update),
 * .text 0x8043D960-0x8043E344 (code-only unit, 21 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 *
 * Virtual memory over ARAM: lbl_806EF94C is the page table (one word per 4 KB virtual page, top bit
 * "page is in ARAM", low 31 bits the ARAM address), lbl_806EF948 the table of resident main memory frames
 * (virtual page address per frame). The format string passed to sprintf in fn_8043E198 says
 * "Virtual address (%x) has not been allocated. Call VMAlloc ..." (strings: lbl_80649228),
 * so fn_8043E038 is VMAlloc. Names stay fn_ until symbols.txt is updated.
 */
#include <dolphin.h>
#include <dolphin/os.h>
#include <dolphin/tail10.h>
#include <stdio.h>

extern u32 lbl_806EF348;   /* ARAM base (second VMInit argument) */
extern s32 lbl_806EF350;   /* round-robin sweep started flag */
extern s32 lbl_806EF354;   /* replacement policy: 0 = scan, 1 = random, else = FIFO */
extern u32 lbl_806EF920;   /* main memory size reserved for frames */
extern u32 lbl_806EF924;   /* main memory frame area */
extern u32 lbl_806EF928;   /* ARAM size */
extern u32 lbl_806EF92C;   /* number of frames */
extern void (*lbl_806EF930)(u32, u32, u32, u32, u32);   /* page-fault statistics callback */
extern s32 lbl_806EF934;   /* initialized flag */
extern u32 lbl_806EF940;   /* current replacement frame */
extern u32* lbl_806EF948;  /* frame table */
extern u32* lbl_806EF94C;  /* page table */
extern u32 lbl_806EF950;   /* ARAM bytes handed out */
extern u32 lbl_806EF954;   /* ARAM allocation cursor */

extern u64 fn_80406CC0(u64 a, u64 b);   /* __div2u */
extern u32 fn_80415880(void);
extern void fn_804158BC(u32 type, void* mram, u32 aram, u32 len);
extern void fn_80415AF0(void);
extern u16 fn_80415B10(void);
extern OSTime fn_80438628(void);
extern u32 fn_80438640(void);
extern void fn_8043F058(void (*handler)(u32));
extern void fn_8043F124(u32 page, u32 frameAddr, u32 frame);
extern void fn_8043F1B8(u32 page, u32 frame);
extern int fn_8043F244(void);
extern int fn_8043F26C(u32 page);
extern int fn_8043F294(u32 page);
extern void fn_8043F2BC(u32 page, int v);
extern u32 fn_8043F35C(void);
extern u32 fn_8043F388(u32 frame);
extern int fn_8043F3A8(u32 frame);
extern void fn_8043F728(void (*cb)(u32));

void fn_8043D960(u32 memSize, u32 aramBase, u32 aramSize);
void fn_8043D9FC(void (*cb)(u32, u32, u32, u32, u32));
u32 fn_8043DA04(void);
u32 fn_8043DA0C(void);
u32 fn_8043DA14(void);
void fn_8043DA1C(void);
void fn_8043DA4C(u32 addr);
void fn_8043DC48(u32 page);
void fn_8043DCFC(void);
u32 fn_8043DD24(void);
u32 fn_8043DD68(void);
u32 fn_8043DF38(void);
u32 fn_8043DFCC(void);
int fn_8043E038(u32 vaddr, u32 size);
u32 fn_8043E138(u32 page);
int fn_8043E178(u32 page);
void fn_8043E198(u32 page);
void fn_8043E1D0(u32 page);
int fn_8043E1E8(u32 page);
void fn_8043E1FC(void);
void fn_8043E2A4(void);

#define TICKS_TO_US(t) fn_80406CC0((u64)(t) * 8, (u64)(OS_TIMER_CLOCK / 125000))

/* VMInit */
void fn_8043D960(u32 memSize, u32 aramBase, u32 aramSize)
{
    BOOL enabled;

    if (lbl_806EF934 == 0) {
        enabled = OSDisableInterrupts();
        lbl_806EF934 = 1;
        lbl_806EF348 = aramBase;
        lbl_806EF928 = aramSize;
        lbl_806EF920 = memSize;
        lbl_806EF92C = memSize >> 12;
        fn_8043F058(fn_8043DA4C);
        fn_8043E1FC();
        fn_8043E2A4();
        fn_8043DA1C();
        OSRestoreInterrupts(enabled);
    }
}

void fn_8043D9FC(void (*cb)(u32, u32, u32, u32, u32))
{
    lbl_806EF930 = cb;
}

u32 fn_8043DA04(void)
{
    return lbl_806EF92C;
}

u32 fn_8043DA0C(void)
{
    return lbl_806EF928;
}

u32 fn_8043DA14(void)
{
    return lbl_806EF348;
}

void fn_8043DA1C(void)
{
    lbl_806EF924 = (u32)fn_80432CBC();
    fn_80432CCC((void*)(lbl_806EF924 + lbl_806EF920));
}

/* page-fault handler */
void fn_8043DA4C(u32 addr)
{
    u32 start;
    u32 frameAddr;
    int wrote;
    u32 frame;
    u32 page;
    int inter;
    BOOL enabled;
    u32 old;

    start = TICKS_TO_US(fn_80438628());
    page = addr & 0xFFFFF000;
    wrote = 0;
    frame = fn_8043DD24();
    frameAddr = lbl_806EF924 + (frame << 12);
    old = fn_8043F388(frame);
    enabled = OSDisableInterrupts();
    while (fn_80415880() != 0) {
    }
    inter = fn_80415B10();
    if (old != 0) {
        if (fn_8043F294(old) != 0) {
            fn_8043E1D0(old);
            wrote = 1;
            fn_80432FD4((void*)frameAddr, 0x1000);
            fn_804158BC(0, (void*)frameAddr, fn_8043E138(old), 0x1000);
            while (fn_80415880() != 0) {
            }
        }
        fn_8043F1B8(old, frame);
    }
    if (fn_8043E1E8(page) != 0) {
        fn_804158BC(1, (void*)frameAddr, fn_8043E138(page), 0x1000);
        while (fn_80415880() != 0) {
        }
        fn_80432FA8((void*)frameAddr, 0x1000);
        ICInvalidateRange((void*)frameAddr, 0x1000);
    } else if (fn_8043E178(page) == 0) {
        fn_8043E198(page);
    }
    if (inter == 0) {
        fn_80415AF0();
    }
    fn_8043F124(page, frameAddr, frame);
    OSRestoreInterrupts(enabled);
    if (lbl_806EF930 != NULL) {
        lbl_806EF930(addr, frameAddr, frame, (u32)TICKS_TO_US(fn_80438628()) - start, wrote);
    }
}

void fn_8043DC48(u32 page)
{
    u32 frameAddr;
    int inter;
    BOOL enabled;

    frameAddr = fn_8043F35C();
    enabled = OSDisableInterrupts();
    while (fn_80415880() != 0) {
    }
    inter = fn_80415B10();
    fn_80432FD4((void*)frameAddr, 0x1000);
    fn_804158BC(0, (void*)frameAddr, fn_8043E138(page), 0x1000);
    while (fn_80415880() != 0) {
    }
    if (inter == 0) {
        fn_80415AF0();
    }
    OSRestoreInterrupts(enabled);
    fn_8043E1D0(page);
}

void fn_8043DCFC(void)
{
    fn_8043F728(fn_8043DC48);
}

/* pick a victim frame */
u32 fn_8043DD24(void)
{
    if (lbl_806EF354 == 0) {
        return fn_8043DD68();
    }
    if (lbl_806EF354 == 1) {
        return fn_8043DF38();
    }
    return fn_8043DFCC();
}

u32 fn_8043E138(u32 page)
{
    u32 aram = lbl_806EF94C[(page >> 12) & 0x1FFF] & 0x7FFFFFFF;

    if (aram != 0) {
        return aram;
    }
    fn_8043E198(page);
    return 0;
}

int fn_8043E178(u32 page)
{
    return (lbl_806EF94C[(page >> 12) & 0x1FFF] & 0x7FFFFFFF) != 0;
}

void fn_8043E198(u32 page)
{
    char buf[1024];

    sprintf(buf, "Virtual address (%x) has not been allocated. Call VMAlloc on virtual address ranges before using them.", page);
    fn_8041A5E4();
}

void fn_8043E1D0(u32 page)
{
    lbl_806EF94C[(page >> 12) & 0x1FFF] |= 0x80000000;
}

int fn_8043E1E8(u32 page)
{
    return lbl_806EF94C[(page >> 12) & 0x1FFF] >> 31;
}

void fn_8043E1FC(void)
{
    u32 i;

    lbl_806EF94C = (u32*)fn_80432CBC();
    fn_80432CCC((void*)((u32)lbl_806EF94C + 0x8000));
    for (i = 0; i < 0x8000; i += 4) {
        *(u32*)((char*)lbl_806EF94C + i) = 0;
    }
}

void fn_8043E2A4(void)
{
    u32 i;

    lbl_806EF948 = (u32*)fn_80432CBC();
    fn_80432CCC((void*)((u32)lbl_806EF948 + 0x4000));
    for (i = 0; i < 0x4000; i += 4) {
        *(u32*)((char*)lbl_806EF948 + i) = 0;
    }
}
