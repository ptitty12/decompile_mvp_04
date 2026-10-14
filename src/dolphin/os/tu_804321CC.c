/*
 * Dolphin SDK OS (OSAlarm, OSAlloc, OSArena, OSAudioSystem, OSCache; MWCC GC/1.2.5n),
 * .text 0x804321CC-0x804330D0 (code-only unit, 33 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Not reproduced (original code, no C equivalent): fn_804328B4 (DecrementerExceptionHandler),
 * fn_80432F94 (DCEnable), fn_80432FA8 (DCInvalidateRange), fn_80432FD4 (DCFlushRange), DCStoreRange (DCStoreRange),
 * fn_80433034 (DCFlushRangeNoSync), DCStoreRangeNoSync (DCStoreRangeNoSync), ICInvalidateRange, fn_804330C0 (ICFlashInvalidate).
 */
#include <dolphin.h>
#include <dolphin/os.h>
#include <dolphin/hw_regs.h>
#include <dolphin/tail10.h>

/* ---- OSAlarm ---- */

typedef struct AlarmQueue {
    OSAlarm* head;
    OSAlarm* tail;
} AlarmQueue;

extern AlarmQueue lbl_806EF7D8;
extern OSResetFunctionInfo lbl_80635850;

void fn_804321CC(void);
void fn_80432224(OSAlarm* alarm);
void fn_80432234(OSAlarm* alarm, OSTime fire, OSAlarmHandler handler);
void fn_80432484(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler);
void fn_804324EC(OSAlarm* alarm, OSTime start, OSTime period, OSAlarmHandler handler);
void OSCancelAlarm(OSAlarm* alarm);
void fn_80432684(u8 exception, OSContext* context);
void fn_804328B4(u8 exception, OSContext* context);
BOOL fn_80432904(BOOL final);

static void SetTimer(OSAlarm* alarm)
{
    OSTime delta;

    delta = alarm->fire - __OSGetSystemTime();
    if (delta < 0) {
        fn_8041A5D4(0);
    } else if (delta < 0x80000000) {
        fn_8041A5D4((u32)delta);
    } else {
        fn_8041A5D4(0x7FFFFFFF);
    }
}

/* OSInitAlarm */
void fn_804321CC(void)
{
    if (fn_80432030(8) != (void*)fn_804328B4) {
        lbl_806EF7D8.head = lbl_806EF7D8.tail = NULL;
        fn_80432014(8, (void*)fn_804328B4);
        OSRegisterResetFunction(&lbl_80635850);
    }
}

/* OSCreateAlarm */
void fn_80432224(OSAlarm* alarm)
{
    alarm->handler = NULL;
    alarm->tag = 0;
}

/* InsertAlarm */
void fn_80432234(OSAlarm* alarm, OSTime fire, OSAlarmHandler handler)
{
    OSAlarm* next;
    OSAlarm* prev;

    if (0 < alarm->period) {
        OSTime time = __OSGetSystemTime();

        fire = alarm->start;
        if (alarm->start < time) {
            fire += alarm->period * ((time - alarm->start) / alarm->period + 1);
        }
    }

    alarm->handler = handler;
    alarm->fire = fire;

    for (next = lbl_806EF7D8.head; next; next = next->next) {
        if (next->fire <= fire) {
            continue;
        }
        alarm->prev = next->prev;
        next->prev = alarm;
        alarm->next = next;
        prev = alarm->prev;
        if (prev) {
            prev->next = alarm;
        } else {
            lbl_806EF7D8.head = alarm;
            SetTimer(alarm);
        }
        return;
    }
    alarm->next = NULL;
    prev = lbl_806EF7D8.tail;
    lbl_806EF7D8.tail = alarm;
    alarm->prev = prev;
    if (prev) {
        prev->next = alarm;
    } else {
        lbl_806EF7D8.head = lbl_806EF7D8.tail = alarm;
        SetTimer(alarm);
    }
}

/* OSSetAlarm */
void fn_80432484(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    alarm->period = 0;
    fn_80432234(alarm, __OSGetSystemTime() + tick, handler);
    OSRestoreInterrupts(enabled);
}

/* OSSetPeriodicAlarm */
void fn_804324EC(OSAlarm* alarm, OSTime start, OSTime period, OSAlarmHandler handler)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    alarm->period = period;
    alarm->start = fn_804386AC(start);
    fn_80432234(alarm, 0, handler);
    OSRestoreInterrupts(enabled);
}

/* OSCancelAlarm */
void OSCancelAlarm(OSAlarm* alarm)
{
    OSAlarm* next;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    if (alarm->handler == NULL) {
        OSRestoreInterrupts(enabled);
        return;
    }
    next = alarm->next;
    if (next == NULL) {
        lbl_806EF7D8.tail = alarm->prev;
    } else {
        next->prev = alarm->prev;
    }
    if (alarm->prev) {
        alarm->prev->next = next;
    } else {
        lbl_806EF7D8.head = next;
        if (next) {
            SetTimer(next);
        }
    }
    alarm->handler = NULL;
    OSRestoreInterrupts(enabled);
}

/* DecrementerExceptionCallback */
void fn_80432684(u8 exception, OSContext* context)
{
    OSAlarm* alarm;
    OSAlarm* next;
    OSAlarmHandler handler;
    OSTime time;
    OSContext exceptionContext;

    time = __OSGetSystemTime();
    alarm = lbl_806EF7D8.head;
    if (alarm == NULL) {
        fn_80433734(context);
    }

    if (time < alarm->fire) {
        SetTimer(alarm);
        fn_80433734(context);
    }

    next = alarm->next;
    lbl_806EF7D8.head = next;
    if (next == NULL) {
        lbl_806EF7D8.tail = NULL;
    } else {
        next->prev = NULL;
    }

    handler = alarm->handler;
    alarm->handler = NULL;
    if (0 < alarm->period) {
        fn_80432234(alarm, 0, handler);
    }

    if (lbl_806EF7D8.head) {
        SetTimer(lbl_806EF7D8.head);
    }

    fn_80437484();
    fn_80433814(&exceptionContext);
    fn_8043364C(&exceptionContext);
    handler(alarm, context);
    fn_80433814(&exceptionContext);
    fn_8043364C(context);
    fn_804374C4();
    fn_804379E0();
    fn_80433734(context);
}

/* OnReset (OSAlarm) */
/* matches only with -opt nopeephole (defined after the original-code DecrementerExceptionHandler) */
BOOL fn_80432904(BOOL final)
{
    OSAlarm* alarm;
    OSAlarm* next;

    if (final != FALSE) {
        alarm = lbl_806EF7D8.head;
        next = (alarm) ? alarm->next : NULL;

        while (alarm != 0) {
            if (fn_80425724(alarm) == FALSE) {
                OSCancelAlarm(alarm);
            }

            alarm = next;
            next = (alarm) ? alarm->next : NULL;
        }
    }

    return TRUE;
}

/* ---- OSAlloc ---- */

typedef struct Cell Cell;
struct Cell {
    Cell* prev;
    Cell* next;
    long size;
};

typedef struct HeapDesc {
    long size;
    Cell* free;
    Cell* allocated;
} HeapDesc;

extern volatile long lbl_806EF2C8;   /* __OSCurrHeap */
extern HeapDesc* lbl_806EF7E0;       /* HeapArray */
extern int lbl_806EF7E4;             /* NumHeaps */
extern void* lbl_806EF7E8;           /* ArenaStart */
extern void* lbl_806EF7EC;           /* ArenaEnd */

static Cell* DLExtract(Cell* list, Cell* cell)
{
    if (cell->next) {
        cell->next->prev = cell->prev;
    }
    if (cell->prev == NULL) {
        return cell->next;
    }
    cell->prev->next = cell->next;
    return list;
}

static Cell* DLAddFront(Cell* list, Cell* cell)
{
    cell->next = list;
    cell->prev = NULL;
    if (list) {
        list->prev = cell;
    }
    return cell;
}

Cell* fn_804329A4(Cell* list, Cell* cell);
void* fn_80432A50(long heap, u32 size);
void fn_80432B4C(long heap, void* ptr);
long fn_80432BC8(long heap);
void* OSInitAlloc(void* arenaStart, void* arenaEnd, int maxHeaps);
long fn_80432C48(void* start, void* end);

/* DLInsert */
Cell* fn_804329A4(Cell* list, Cell* cell)
{
    Cell* prev;
    Cell* next;

    for (next = list, prev = NULL; next; prev = next, next = next->next) {
        if (cell <= next) {
            break;
        }
    }

    cell->next = next;
    cell->prev = prev;
    if (next) {
        next->prev = cell;
        if ((char*)cell + cell->size == (char*)next) {
            cell->size += next->size;
            next = next->next;
            cell->next = next;
            if (next) {
                next->prev = cell;
            }
        }
    }
    if (prev) {
        prev->next = cell;
        if ((char*)prev + prev->size == (char*)cell) {
            prev->size += cell->size;
            prev->next = next;
            if (next) {
                next->prev = prev;
            }
        }
        return list;
    }
    return cell;
}

/* OSAllocFromHeap */
void* fn_80432A50(long heap, u32 size)
{
    HeapDesc* hd = &lbl_806EF7E0[heap];
    long sz = (long)(((size + 32) + 31) & ~31);
    Cell* cell;
    Cell* newCell;
    unsigned long leftover;

    for (cell = hd->free; cell != NULL; cell = cell->next) {
        if (sz <= cell->size) {
            break;
        }
    }
    if (cell == NULL) {
        return NULL;
    }

    leftover = cell->size - sz;
    if (leftover < 64) {
        hd->free = DLExtract(hd->free, cell);
    } else {
        cell->size = sz;
        newCell = (Cell*)((char*)cell + sz);
        newCell->size = leftover;
        newCell->prev = cell->prev;
        newCell->next = cell->next;
        if (newCell->next) {
            newCell->next->prev = newCell;
        }
        if (newCell->prev) {
            newCell->prev->next = newCell;
        } else {
            hd->free = newCell;
        }
    }

    hd->allocated = DLAddFront(hd->allocated, cell);
    return (char*)cell + 32;
}

/* OSFreeToHeap */
/* near-miss: same instructions, stack frame 32 bytes vs retail 24 */
void fn_80432B4C(long heap, void* ptr)
{
    Cell* cell = (Cell*)((char*)ptr - 32);
    HeapDesc* hd = &lbl_806EF7E0[heap];

    hd->allocated = DLExtract(hd->allocated, cell);
    hd->free = fn_804329A4(hd->free, cell);
}

/* OSSetCurrentHeap */
long fn_80432BC8(long heap)
{
    long prev = lbl_806EF2C8;
    lbl_806EF2C8 = heap;
    return prev;
}

/* OSInitAlloc */
/* near-miss 98.9%: arraySize hoisted before the loop and the last stores in retail order fix the structure; 5 slots differ only in the
 * volatile register numbers of the final base load (r5 here, r3 in retail) */
void* OSInitAlloc(void* arenaStart, void* arenaEnd, int maxHeaps)
{
    u32 arraySize;
    long i;
    HeapDesc* hd;

    arraySize = maxHeaps * sizeof(HeapDesc);
    lbl_806EF7E0 = (HeapDesc*)arenaStart;
    lbl_806EF7E4 = maxHeaps;
    for (i = 0; i < lbl_806EF7E4; i++) {
        hd = &lbl_806EF7E0[i];
        hd->size = -1;
        hd->free = hd->allocated = NULL;
    }
    arenaStart = (void*)((u32)lbl_806EF7E0 + arraySize);
    arenaStart = (void*)(((u32)arenaStart + 31) & ~31);
    lbl_806EF2C8 = -1;
    lbl_806EF7E8 = arenaStart;
    lbl_806EF7EC = (void*)((u32)arenaEnd & ~31);
    return arenaStart;
}

/* OSCreateHeap */
long fn_80432C48(void* start, void* end)
{
    long heap;
    HeapDesc* hd;
    Cell* cell;

    start = (void*)(((u32)start + 31) & ~31);
    end = (void*)((u32)end & ~31);

    for (heap = 0; heap < lbl_806EF7E4; heap++) {
        hd = &lbl_806EF7E0[heap];
        if (hd->size < 0) {
            hd->size = (char*)end - (char*)start;
            cell = (Cell*)start;
            cell->prev = NULL;
            cell->next = NULL;
            cell->size = hd->size;
            hd->free = cell;
            hd->allocated = NULL;
            return heap;
        }
    }
    return -1;
}

/* ---- OSAudioSystem: __OSInitAudioSystem ----
 * Emitted ahead of the OSArena block on purpose: in the original OSAudioSystem.c is its own file and calls
 * OSGetArenaHi (fn_80432CB4) out of line; defined after fn_80432CB4 here, the compiler expands that call inline.
 * Body: dolsdk2004 OSAudioSystem.c (adonis-singh/re4 src/lib/OSAudioSystem.c), instruction stream equal. */

extern u8 lbl_80635DE0[0x80];        /* DSPInitCode */

void fn_80432D00(void);
void fn_80432EBC(void);

/* __OSInitAudioSystem */
void fn_80432D00(void)
{
    u8 errFlag;
    u16 reg16;
    u32 start_tick;

    memcpy((void*)((u32)fn_80432CB4() - 0x80), (void*)0x81000000, 0x80);
    memcpy((void*)0x81000000, (void*)lbl_80635DE0, 0x80);
    fn_80432FD4((void*)0x81000000, 0x80);

    __DSPRegs[9] = 0x43;

    __DSPRegs[5] = 0x8AC;
    __DSPRegs[5] |= 1;

    while (__DSPRegs[5] & 1);
        __DSPRegs[0] = 0;

    while (((__DSPRegs[2] << 16) | __DSPRegs[3]) & 0x80000000);

    *(u32*)&__DSPRegs[16] = 0x1000000;
    *(u32*)&__DSPRegs[18] = 0;
    *(u32*)&__DSPRegs[20] = 0x20;

    reg16 = __DSPRegs[5];
    while (!(reg16 & 0x20))
        reg16 = __DSPRegs[5];

    __DSPRegs[5] = reg16;

    start_tick = fn_80438640();
    while ((s32)(fn_80438640() - start_tick) < 0x892);

    *(u32*)&__DSPRegs[16] = 0x1000000;
    *(u32*)&__DSPRegs[18] = 0;
    *(u32*)&__DSPRegs[20] = 0x20;

    reg16 = __DSPRegs[5];
    while (!(reg16 & 0x20)) {
        reg16 = __DSPRegs[5];
    }
    __DSPRegs[5] = reg16;

    __DSPRegs[5] &= ~0x800;
    while ((__DSPRegs[5]) & 0x400);

    __DSPRegs[5] &= ~4;
    errFlag = 0;

    reg16 = __DSPRegs[2];

    while (!(reg16 & 0x8000)) {
        reg16 = __DSPRegs[2];
    }

    if (((u32)((reg16 << 16) | __DSPRegs[3]) + 0x7FAC0000U) != 0x4348) {
    }

    reg16 != 0x81800;  /* no code; fixes the register allocation (as in the dolsdk2004 source) */
    __DSPRegs[5] |= 4;
    __DSPRegs[5] = 0x8AC;
    __DSPRegs[5] |= 1;
    while (__DSPRegs[5] & 1);

    memcpy((void*)0x81000000, (void*)((u32)fn_80432CB4() - 0x80), 0x80);
}

/* ---- OSArena ---- */

extern void* lbl_806EF7F0;           /* __OSArenaHi */
extern void* lbl_806EF2D0;           /* __OSArenaLo */

void* fn_80432CB4(void);
void* fn_80432CBC(void);
void fn_80432CC4(void* hi);
void fn_80432CCC(void* lo);
void* fn_80432CD4(u32 size, u32 align);

/* OSGetArenaHi */
void* fn_80432CB4(void)
{
    return lbl_806EF7F0;
}

/* OSGetArenaLo */
void* fn_80432CBC(void)
{
    return lbl_806EF2D0;
}

/* OSSetArenaHi */
void fn_80432CC4(void* hi)
{
    lbl_806EF7F0 = hi;
}

/* OSSetArenaLo */
void fn_80432CCC(void* lo)
{
    lbl_806EF2D0 = lo;
}

/* OSAllocFromArenaLo */
void* fn_80432CD4(u32 size, u32 align)
{
    void* ptr;
    u8* arenaLo;

    arenaLo = (u8*)lbl_806EF2D0;
    ptr = (void*)(((u32)arenaLo + align - 1) & ~(align - 1));
    arenaLo = (u8*)ptr + size;
    arenaLo = (u8*)(((u32)arenaLo + align - 1) & ~(align - 1));
    lbl_806EF2D0 = arenaLo;
    return ptr;
}

/* ---- OSAudioSystem: __OSStopAudioSystem ---- */

/* __OSStopAudioSystem */
void fn_80432EBC(void)
{
    u16 reg16;
    u32 start_tick;

    #define waitUntil(load, mask)  \
        reg16 = (load);            \
        while (reg16 & (mask)) {   \
            reg16 = (load);        \
        }

    __DSPRegs[5] = 0x804;
    reg16 = __DSPRegs[27];
    __DSPRegs[27] = reg16 & ~0x8000;
    waitUntil(__DSPRegs[5], 0x400);
    waitUntil(__DSPRegs[5], 0x200);
    __DSPRegs[5] = 0x8ac;
    __DSPRegs[0] = 0;

    while (((__DSPRegs[2] << 16) | __DSPRegs[3]) & 0x80000000);

    start_tick = fn_80438640();
    while ((s32)(fn_80438640() - start_tick) < 0x2c);

    reg16 = __DSPRegs[5];
    __DSPRegs[5] = reg16 | 1;
    waitUntil(__DSPRegs[5], 0x001);

    #undef waitUntil
}
