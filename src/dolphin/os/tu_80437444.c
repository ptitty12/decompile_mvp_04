/*
 * Dolphin SDK OS (OSThread, MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x80437444-0x80438778 (code-only unit; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Only the first small functions are done; the rest of OSThread.c and OSTime.c were not attempted.
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
