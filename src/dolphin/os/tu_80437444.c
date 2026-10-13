/*
 * Dolphin SDK OS (OSThread, MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x80437444-0x80438778 (code-only unit; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * OSThread.c is done (fn_80437444..fn_8043857C). Not reproduced: fn_80438628/fn_80438640 (OSGetTime/OSGetTick,
 * mftb: original code) and fn_80438704/fn_80438724 (a walk over a zeroed 4-entry function table at lbl_80649298;
 * unoptimised code with branch-to-next chains, no source shape found). __OSGetSystemTime (0x80438648) and
 * __OSTimeToSystemTime (0x804386AC) are OSTime.c: they match only with -opt nopeephole (copies come out as mr
 * instead of addi), so they need their own unit with the nopeephole flags (owner/lead: split at 0x80438628).
 *
 * Statics: RunQueue/IdleThread/DefaultThread/IdleContext are real .bss statics here (the compiler addresses
 * them off one shared base, which an extern cannot reproduce); RunQueueBits/RunQueueHint/Reschedule are volatile.
 */
#include <dolphin.h>
#include <dolphin/os.h>
#include <dolphin/tail10.h>

extern volatile s32 lbl_806EF868;               /* Reschedule */
extern volatile u32 lbl_806EF860;               /* RunQueueBits */
extern volatile s32 lbl_806EF864;               /* RunQueueHint */
extern void (*lbl_806EF2F8)(OSThread* from, OSThread* to);   /* SwitchThreadCallback */
/* OSThread.c statics: one .bss block at lbl_806DF418 (the compiler addresses them off a shared base) */
static OSThreadQueue RunQueue[OS_PRIORITY_MAX + 1];
static OSThread IdleThread;
static OSThread DefaultThread;
static OSContext IdleContext;

extern OSContext* fn_804336A8(void);   /* OSGetCurrentContext */
extern u32 fn_804336B4(OSContext* context);   /* OSSaveContext */
extern void fn_80434F9C(void);         /* OSEnableInterrupts */
extern void fn_80433734(OSContext* context);  /* OSLoadContext */
extern void fn_80433838(OSContext* context, u32 pc, u32 newsp);   /* OSInitContext */
extern u32 fn_8043380C(void);          /* OSGetStackPointer */
extern void fn_80435EC4(OSThread* thread);    /* __OSUnlockAllMutex */
extern u32 lbl_806EF2D8;               /* __OSFpscrEnableBits */
extern void* lbl_806DF090[17];         /* __OSErrorTable */

#define AddTail(queue, thread, link)       \
    do {                                   \
        OSThread* prev;                    \
        prev = (queue)->tail;              \
        if (prev == NULL)                  \
            (queue)->head = (thread);      \
        else                               \
            prev->link.next = (thread);    \
        (thread)->link.prev = prev;        \
        (thread)->link.next = NULL;        \
        (queue)->tail = (thread);          \
    } while (0)

#define RemoveItem(queue, thread, link)    \
    do {                                   \
        OSThread *next, *prev;             \
        next = (thread)->link.next;        \
        prev = (thread)->link.prev;        \
        if (next == NULL)                  \
            (queue)->tail = prev;          \
        else                               \
            next->link.prev = prev;        \
        if (prev == NULL)                  \
            (queue)->head = next;          \
        else                               \
            prev->link.next = next;        \
    } while (0)

#define RemoveHead(queue, thread, link)        do {                                           OSThread* __next;                          (thread) = (queue)->head;                  __next = (thread)->link.next;              if (__next == NULL)                            (queue)->tail = NULL;                  else                                           __next->link.prev = NULL;              (queue)->head = __next;                } while (0)

#define AddPrio(queue, thread, link)                                \
    do {                                                            \
        OSThread *prev, *next;                                      \
        for (next = (queue)->head; next && next->priority <= (thread)->priority; next = next->link.next) \
            ;                                                       \
        if (next == NULL) {                                         \
            AddTail(queue, thread, link);                           \
        } else {                                                    \
            (thread)->link.next = next;                             \
            prev = next->link.prev;                                 \
            next->link.prev = (thread);                             \
            (thread)->link.prev = prev;                             \
            if (prev == NULL)                                       \
                (queue)->head = (thread);                           \
            else                                                    \
                prev->link.next = (thread);                         \
        }                                                           \
    } while (0)

#define SetRun(thread)                                                  \
    do {                                                                \
        (thread)->queue = &RunQueue[(thread)->priority];                \
        AddTail((thread)->queue, (thread), link);                       \
        lbl_806EF860 |= 1u << (OS_PRIORITY_MAX - (thread)->priority);   \
        lbl_806EF864 = TRUE;                                            \
    } while (0)

OSThread* fn_80437444(void);
BOOL fn_80437450(OSThread* thread);
s32 fn_80437484(void);
s32 fn_804374C4(void);
static void fn_80437504(OSThread* thread);
s32 fn_8043756C(OSThread* thread);
OSThread* fn_804375A8(OSThread* thread, OSPriority priority);
void fn_80437768(OSThread* thread, OSPriority priority);
OSThread* fn_804377B8(BOOL yield);
void fn_804379E0(void);
void fn_80437A10(void);
int fn_80437A4C(OSThread* thread, void* (*func)(void*), void* param, void* stack, u32 stackSize, OSPriority priority, u16 attr);
void fn_80437C34(void* val);
void fn_80437D18(OSThread* thread);
s32 fn_80437ED4(OSThread* thread);
s32 fn_8043815C(OSThread* thread);
void fn_804382CC(OSThreadQueue* queue);
void fn_804383B8(OSThreadQueue* queue);
int fn_804384BC(OSThread* thread, OSPriority priority);
void fn_8043857C(u8 val);

/* OSGetCurrentThread */
OSThread* fn_80437444(void)
{
    return *(OSThread**)0x800000E4;
}

/* OSIsThreadTerminated */
BOOL fn_80437450(OSThread* thread)
{
    return (thread->state == OS_THREAD_STATE_MORIBUND || thread->state == 0) ? TRUE : FALSE;
}

/* OSDisableScheduler */
s32 fn_80437484(void)
{
    BOOL enabled;
    s32 count;

    enabled = OSDisableInterrupts();
    count = lbl_806EF868++;
    OSRestoreInterrupts(enabled);
    return count;
}

/* OSEnableScheduler */
s32 fn_804374C4(void)
{
    BOOL enabled;
    s32 count;

    enabled = OSDisableInterrupts();
    count = lbl_806EF868--;
    OSRestoreInterrupts(enabled);
    return count;
}

/* UnsetRun */
static void fn_80437504(OSThread* thread)
{
    OSThreadQueue* queue;

    ASSERTMSGLINE(0, 0, "");
    queue = thread->queue;
    RemoveItem(queue, thread, link);
    if (queue->head == NULL) {
        lbl_806EF860 &= ~(1u << (OS_PRIORITY_MAX - thread->priority));
    }
    thread->queue = NULL;
}

/* __OSGetEffectivePriority */
s32 fn_8043756C(OSThread* thread)
{
    s32 priority = thread->base;
    OSMutex* mutex;

    for (mutex = thread->queueMutex.head; mutex; mutex = mutex->link.next) {
        OSThread* blocked = mutex->queue.head;

        if (blocked && blocked->priority < priority) {
            priority = blocked->priority;
        }
    }
    return priority;
}

/* SetEffectivePriority */
OSThread* fn_804375A8(OSThread* thread, OSPriority priority)
{
    switch (thread->state) {
    case OS_THREAD_STATE_READY:
        fn_80437504(thread);
        thread->priority = priority;
        SetRun(thread);
        break;
    case OS_THREAD_STATE_WAITING:
        RemoveItem(thread->queue, thread, link);
        thread->priority = priority;
        AddPrio(thread->queue, thread, link);
        if (thread->mutex) {
            return thread->mutex->thread;
        }
        break;
    case OS_THREAD_STATE_RUNNING:
        lbl_806EF864 = TRUE;
        thread->priority = priority;
        break;
    }
    return NULL;
}

/* UpdatePriority (always expanded in its callers) */
static void UpdatePriority(OSThread* thread)
{
    OSPriority priority;

    do {
        if (IsSuspended(thread->suspend)) {
            break;
        }
        priority = fn_8043756C(thread);
        if (thread->priority == priority) {
            break;
        }
        thread = fn_804375A8(thread, priority);
    } while (thread);
}

/* priority donation (PromoteThread) */
void fn_80437768(OSThread* thread, OSPriority priority)
{
    do {
        if (IsSuspended(thread->suspend)) {
            break;
        }
        if (thread->priority <= priority) {
            break;
        }
        thread = fn_804375A8(thread, priority);
    } while (thread);
}

/* SelectThread */
OSThread* fn_804377B8(BOOL yield)
{
    OSContext* currentContext;
    OSThread* currentThread;
    OSThread* nextThread;
    OSPriority priority;
    OSThreadQueue* queue;

    if (0 < lbl_806EF868) {
        return NULL;
    }
    currentContext = fn_804336A8();
    currentThread = fn_80437444();
    if (currentContext != &currentThread->context) {
        return NULL;
    }
    if (currentThread) {
        if (currentThread->state == OS_THREAD_STATE_RUNNING) {
            if (!yield) {
                priority = __cntlzw(lbl_806EF860);
                if (currentThread->priority <= priority) {
                    return NULL;
                }
            }
            currentThread->state = OS_THREAD_STATE_READY;
            SetRun(currentThread);
        }
        if (!(currentThread->context.state & OS_CONTEXT_STATE_EXC) && fn_804336B4(&currentThread->context)) {
            return NULL;
        }
    }
    if (lbl_806EF860 == 0) {
        lbl_806EF2F8(fn_80437444(), NULL);
        __OSCurrentThread = NULL;
        fn_8043364C(&IdleContext);
        do {
            fn_80434F9C();
            while (lbl_806EF860 == 0) {
            }
            OSDisableInterrupts();
        } while (lbl_806EF860 == 0);
        fn_80433814(&IdleContext);
    }
    lbl_806EF864 = FALSE;
    priority = __cntlzw(lbl_806EF860);
    queue = &RunQueue[priority];
    RemoveHead(queue, nextThread, link);
    if (queue->head == NULL) {
        lbl_806EF860 &= ~(1u << (OS_PRIORITY_MAX - priority));
    }
    nextThread->queue = NULL;
    nextThread->state = OS_THREAD_STATE_RUNNING;
    lbl_806EF2F8(fn_80437444(), nextThread);
    __OSCurrentThread = nextThread;
    fn_8043364C(&nextThread->context);
    fn_80433734(&nextThread->context);
    return nextThread;
}

/* __OSReschedule */
void fn_804379E0(void)
{
    if (lbl_806EF864) {
        fn_804377B8(FALSE);
    }
}

/* OSYieldThread */
void fn_80437A10(void)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    fn_804377B8(TRUE);
    OSRestoreInterrupts(enabled);
}

/* OSCreateThread */
int fn_80437A4C(OSThread* thread, void* (*func)(void*), void* param, void* stack, u32 stackSize, OSPriority priority, u16 attr)
{
    BOOL enabled;
    u32 sp;
    int i;

    if (priority < 0 || priority > OS_PRIORITY_MAX) {
        return FALSE;
    }
    thread->state = OS_THREAD_STATE_READY;
    thread->attr = (u16)(attr & OS_THREAD_ATTR_DETACH);
    thread->priority = thread->base = priority;
    thread->suspend = 1;
    thread->val = (void*)-1;
    thread->mutex = NULL;
    thread->queueJoin.head = thread->queueJoin.tail = NULL;
    thread->queueMutex.head = thread->queueMutex.tail = NULL;
    sp = (u32)stack & ~7;
    ((u32*)sp)[-2] = 0;
    ((u32*)sp)[-1] = 0;
    fn_80433838(&thread->context, (u32)func, sp - 8);
    thread->context.lr = (u32)fn_80437C34;
    thread->context.gpr[3] = (u32)param;
    thread->stackBase = (u8*)stack;
    thread->stackEnd = (u32*)((u32)stack - stackSize);
    *thread->stackEnd = OS_THREAD_STACK_MAGIC;
    thread->error = 0;
    thread->specific[0] = NULL;
    thread->specific[1] = NULL;
    enabled = OSDisableInterrupts();
    if (lbl_806DF090[16]) {
        thread->context.srr1 |= 0x900;
        thread->context.state |= OS_CONTEXT_STATE_FPSAVED;
        thread->context.fpscr = (lbl_806EF2D8 & 0xF8) | 4;
        for (i = 0; i < 32; i++) {
            u64 v = 0xFFFFFFFFFFFFFFFFull;
            *(u64*)&thread->context.fpr[i] = v;
            *(u64*)&thread->context.psf[i] = v;
        }
    }
    AddTail(&__OSActiveThreadQueue, thread, linkActive);
    OSRestoreInterrupts(enabled);
    return TRUE;
}

/* OSExitThread */
void fn_80437C34(void* val)
{
    BOOL enabled;
    OSThread* currentThread;

    enabled = OSDisableInterrupts();
    currentThread = fn_80437444();
    fn_80433814(&currentThread->context);
    if (currentThread->attr & OS_THREAD_ATTR_DETACH) {
        RemoveItem(&__OSActiveThreadQueue, currentThread, linkActive);
        currentThread->state = 0;
    } else {
        currentThread->state = OS_THREAD_STATE_MORIBUND;
        currentThread->val = val;
    }
    fn_80435EC4(currentThread);
    fn_804383B8(&currentThread->queueJoin);
    lbl_806EF864 = TRUE;
    fn_804379E0();
    OSRestoreInterrupts(enabled);
}

/* OSCancelThread */
void fn_80437D18(OSThread* thread)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    switch (thread->state) {
    case OS_THREAD_STATE_READY:
        if (!IsSuspended(thread->suspend)) {
            fn_80437504(thread);
        }
        break;
    case OS_THREAD_STATE_RUNNING:
        lbl_806EF864 = TRUE;
        break;
    case OS_THREAD_STATE_WAITING:
        RemoveItem(thread->queue, thread, link);
        thread->queue = NULL;
        if (!IsSuspended(thread->suspend) && thread->mutex) {
            UpdatePriority(thread->mutex->thread);
        }
        break;
    default:
        OSRestoreInterrupts(enabled);
        return;
    }
    fn_80433814(&thread->context);
    if (thread->attr & OS_THREAD_ATTR_DETACH) {
        RemoveItem(&__OSActiveThreadQueue, thread, linkActive);
        thread->state = 0;
    } else {
        thread->state = OS_THREAD_STATE_MORIBUND;
    }
    fn_80435EC4(thread);
    fn_804383B8(&thread->queueJoin);
    fn_804379E0();
    OSRestoreInterrupts(enabled);
}

/* OSResumeThread */
s32 fn_80437ED4(OSThread* thread)
{
    BOOL enabled;
    s32 suspendCount;

    enabled = OSDisableInterrupts();
    suspendCount = thread->suspend--;
    if (thread->suspend < 0) {
        thread->suspend = 0;
    } else if (thread->suspend == 0) {
        switch (thread->state) {
        case OS_THREAD_STATE_READY:
            thread->priority = fn_8043756C(thread);
            SetRun(thread);
            break;
        case OS_THREAD_STATE_WAITING:
            RemoveItem(thread->queue, thread, link);
            thread->priority = fn_8043756C(thread);
            AddPrio(thread->queue, thread, link);
            if (thread->mutex) {
                UpdatePriority(thread->mutex->thread);
            }
            break;
        }
        fn_804379E0();
    }
    OSRestoreInterrupts(enabled);
    return suspendCount;
}

/* OSSuspendThread */
s32 fn_8043815C(OSThread* thread)
{
    BOOL enabled;
    s32 suspendCount;

    enabled = OSDisableInterrupts();
    suspendCount = thread->suspend++;
    if (suspendCount == 0) {
        switch (thread->state) {
        case OS_THREAD_STATE_RUNNING:
            lbl_806EF864 = TRUE;
            thread->state = OS_THREAD_STATE_READY;
            break;
        case OS_THREAD_STATE_READY:
            fn_80437504(thread);
            break;
        case OS_THREAD_STATE_WAITING:
            RemoveItem(thread->queue, thread, link);
            thread->priority = 32;
            AddTail(thread->queue, thread, link);
            if (thread->mutex) {
                UpdatePriority(thread->mutex->thread);
            }
            break;
        }
        fn_804379E0();
    }
    OSRestoreInterrupts(enabled);
    return suspendCount;
}

/* OSSleepThread */
void fn_804382CC(OSThreadQueue* queue)
{
    BOOL enabled;
    OSThread* currentThread;

    enabled = OSDisableInterrupts();
    currentThread = fn_80437444();
    currentThread->state = OS_THREAD_STATE_WAITING;
    currentThread->queue = queue;
    AddPrio(queue, currentThread, link);
    lbl_806EF864 = TRUE;
    fn_804379E0();
    OSRestoreInterrupts(enabled);
}

/* OSWakeupThread */
void fn_804383B8(OSThreadQueue* queue)
{
    BOOL enabled;
    OSThread* thread;

    enabled = OSDisableInterrupts();
    while (queue->head) {
        RemoveHead(queue, thread, link);
        thread->state = OS_THREAD_STATE_READY;
        if (!IsSuspended(thread->suspend)) {
            SetRun(thread);
        }
    }
    fn_804379E0();
    OSRestoreInterrupts(enabled);
}

/* OSSetThreadPriority */
int fn_804384BC(OSThread* thread, OSPriority priority)
{
    BOOL enabled;

    if (priority < OS_PRIORITY_MIN || priority > OS_PRIORITY_MAX) {
        return FALSE;
    }
    enabled = OSDisableInterrupts();
    if (thread->base != priority) {
        thread->base = priority;
        UpdatePriority(thread);
        fn_804379E0();
    }
    OSRestoreInterrupts(enabled);
    return TRUE;
}

/* OSClearStack */
void fn_8043857C(u8 val)
{
    u32 sp;
    u32* p;
    u32 pattern;

    pattern = (val << 24) | (val << 16) | (val << 8) | val;
    sp = fn_8043380C();
    for (p = fn_80437444()->stackEnd + 1; p < (u32*)sp; p++) {
        *p = pattern;
    }
}

BOOL fn_80438724(void);

BOOL fn_80438704(void)
{
    return fn_80438724();
}
