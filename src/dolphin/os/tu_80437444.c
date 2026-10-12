/*
 * Dolphin SDK OS (OSThread, MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x80437444-0x80438778 (code-only unit; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Only the first small functions are done; the rest of OSThread.c and OSTime.c were not attempted.
 */
#include <dolphin.h>
#include <dolphin/os.h>
#include <dolphin/tail10.h>

extern s32 lbl_806EF868;               /* Reschedule */
extern u32 lbl_806EF860;               /* RunQueueBits */

OSThread* fn_80437444(void);
BOOL fn_80437450(OSThread* thread);
s32 fn_80437484(void);
s32 fn_804374C4(void);
void fn_80437504(OSThread* thread);
s32 fn_8043756C(OSThread* thread);

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
void fn_80437504(OSThread* thread)
{
    OSThreadQueue* queue;
    OSThread* next;
    OSThread* prev;

    queue = thread->queue;
    next = thread->link.next;
    prev = thread->link.prev;
    if (next == NULL) {
        queue->tail = prev;
    } else {
        next->link.prev = prev;
    }
    if (prev == NULL) {
        queue->head = next;
    } else {
        prev->link.next = next;
    }
    if (queue->head == NULL) {
        lbl_806EF860 &= ~(1u << (31 - thread->priority));
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
