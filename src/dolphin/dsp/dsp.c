/* Imported from emoose/re4 @ feb6805b (src/lib/dsp.c), based on doldecomp/dolsdk2004. Nintendo Dolphin SDK 2004 Patch 1, dsp library; names are Nintendo's. */
#include <stddef.h>
#include <dolphin.h>
#include <dolphin/hw_regs.h>


#define __DSP_rude_task_pending lbl_806EF624
#define __DSP_rude_task lbl_806EF628
#define __DSP_tmp_task lbl_806EF62C
#define __DSP_last_task lbl_806EF630
#define __DSP_first_task lbl_806EF634
#define __DSP_curr_task lbl_806EF638
#define __DSP_init_flag lbl_806EF610
#define __DSPVersion lbl_806EF190
#include "__dsp.h"

#define BUILD_DATE "Apr  5 2004"
#if DEBUG
#define BUILD_TIME "03:56:49"
#else
#define BUILD_TIME "04:15:32"
#endif

struct DSPVersionStrings {
    char version[72];
    char format[32];
    char date[12];
    char time[9];
};
#ifdef DEBUG
struct DSPVersionStrings lbl_80633678 = {
    "<< Dolphin SDK - DSP\tdebug build: Apr  5 2004 03:56:49 (0x2301) >>",
    "DSPInit(): Build Date: %s %s\n",
    "Apr  5 2004",
    "03:56:49"
};
#else
struct DSPVersionStrings lbl_80633678 = {
    "<< Dolphin SDK - DSP\trelease build: Apr  5 2004 04:15:32 (0x2301) >>",
    "DSPInit(): Build Date: %s %s\n",
    "Apr  5 2004",
    "04:15:32"
};
#endif
const char* __DSPVersion = lbl_80633678.version;

extern DSPTaskInfo* __DSP_rude_task;
extern int __DSP_rude_task_pending;

extern BOOL __DSP_init_flag;


u32 DSPCheckMailToDSP(void) {
    return (__DSPRegs[0] & (1 << 15)) >> 15;
}

u32 DSPCheckMailFromDSP(void) {
    return (__DSPRegs[2] & (1 << 15)) >> 15;
}

u32 DSPReadMailFromDSP(void) {
    return (__DSPRegs[2] << 16) | __DSPRegs[3];
}

void DSPSendMailToDSP(u32 mail) {
    __DSPRegs[0] = mail >> 16;
    __DSPRegs[1] = mail & 0xFFFF;
}

static inline void __DSPAssertInt(void) {
    BOOL old;
    u16 tmp;

    old = OSDisableInterrupts();
    tmp = __DSPRegs[5];
    tmp = (tmp & ~0xA8) | 2;
    __DSPRegs[5] = tmp;
    OSRestoreInterrupts(old);
}

void DSPInit(void) {
    BOOL old;
    u16 tmp;

    __DSP_debug_printf(lbl_80633678.format, lbl_80633678.date, lbl_80633678.time);

    if (__DSP_init_flag == 1)
        return;

    OSRegisterVersion(__DSPVersion);

    old = OSDisableInterrupts();
    __OSSetInterruptHandler(7, __DSPHandler);
    __OSUnmaskInterrupts(OS_INTERRUPTMASK_DSP_DSP);

    tmp = __DSPRegs[5];
    tmp = (tmp & ~0xA8) | 0x800;
    __DSPRegs[5] = tmp;

    tmp = __DSPRegs[5];
    __DSPRegs[5] = tmp = tmp & ~0xAC;

    __DSP_first_task = __DSP_last_task = __DSP_curr_task = __DSP_tmp_task = NULL;
    __DSP_init_flag = 1;

    OSRestoreInterrupts(old);
}

BOOL DSPCheckInit(void) {
    return __DSP_init_flag;
}

DSPTaskInfo* DSPAddTask(DSPTaskInfo* task) {
    BOOL old;

    ASSERTMSGLINE(556, __DSP_init_flag == 1, "DSPAddTask(): DSP driver not initialized!\n");

    old = OSDisableInterrupts();

    __DSP_insert_task(task);
    task->state = 0;
    task->flags = 1;

    OSRestoreInterrupts(old);
    if (task == __DSP_first_task)
        __DSP_boot_task(task);
    return task;
}

DSPTaskInfo* DSPCancelTask(DSPTaskInfo* task) {
    BOOL old;

    ASSERTMSGLINE(592, __DSP_init_flag == 1, "DSPCancelTask(): DSP driver not initialized!\n");

    old = OSDisableInterrupts();

    task->flags |= 2;

    OSRestoreInterrupts(old);
    return task;
}

DSPTaskInfo* DSPAssertTask(DSPTaskInfo* task) {
    s32 old;

    ASSERTMSGLINE(623, __DSP_init_flag == 1, "DSPAssertTask(): DSP driver not initialized!\n");
    ASSERTMSGLINE(624, task->flags & 1, "DSPAssertTask(): Specified task not in active task list!\n");

    old = OSDisableInterrupts();

    if (__DSP_curr_task == task) {
        __DSP_rude_task = task;
        __DSP_rude_task_pending = 1;
        OSRestoreInterrupts(old);
        return task;
    }

    if (task->priority < __DSP_curr_task->priority) {
        __DSP_rude_task = task;
        __DSP_rude_task_pending = 1;
        if (__DSP_curr_task->state == 1) {
            __DSPAssertInt();
        }
        OSRestoreInterrupts(old);
        return task;
    }

    OSRestoreInterrupts(old);
    return NULL;
}

