/*
 * Dolphin SDK (MWCC GC/1.2.5n, cflags_dolphin_sdk),
 * .text 0x80417314-0x80417798 (code-only unit, 6 functions; original file name from the reference split).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 * Written from the public SDK arq.c (doldecomp/dolsdk2004 layout); the SDK names are in the comments, the
 * symbols stay fn_<addr> (symbols.txt has no real names for this range). The static __ARQPopTaskQueueHi is
 * inlined everywhere, so it has no symbol.
 */
#include <dolphin.h>
#include <dolphin/ar.h>
#include <dolphin/os.h>

extern const char* lbl_806EF158;     /* __ARQVersion */
extern ARQRequest* lbl_806EF4F8;     /* __ARQRequestQueueHi */
extern ARQRequest* lbl_806EF4FC;     /* __ARQRequestTailHi */
extern ARQRequest* lbl_806EF500;     /* __ARQRequestQueueLo */
extern ARQRequest* lbl_806EF504;     /* __ARQRequestTailLo */
extern ARQRequest* lbl_806EF508;     /* temporary queue head used while removing a request */
extern ARQRequest* lbl_806EF50C;     /* temporary queue tail */
extern ARQRequest* lbl_806EF510;     /* __ARQRequestPendingHi */
extern ARQRequest* lbl_806EF514;     /* __ARQRequestPendingLo */
extern ARQCallback lbl_806EF518;     /* __ARQCallbackHi */
extern ARQCallback lbl_806EF51C;     /* __ARQCallbackLo */
extern u32 lbl_806EF520;             /* __ARQChunkSize */
extern volatile BOOL lbl_806EF524;   /* __ARQ_init_flag */

typedef void (*ARCallback)(void);

void fn_804158BC(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length); /* ARStartDMA */
ARCallback fn_8041583C(ARCallback callback);                             /* ARRegisterDMACallback */

static void fn_80417314(void);
void fn_80417414(u32 unused);
static void fn_80417418(void);
void fn_804174E4(void);
void fn_80417554(ARQRequest* request, u32 owner, u32 type, u32 priority, u32 source, u32 dest, u32 length,
                 ARQCallback callback);
void fn_804176B0(ARQRequest* request);

/* __ARQPopTaskQueueHi */
static void __ARQPopTaskQueueHi(void)
{
    if (lbl_806EF4F8) {
        if (lbl_806EF4F8->type == ARQ_TYPE_MRAM_TO_ARAM) {
            fn_804158BC(lbl_806EF4F8->type, lbl_806EF4F8->source, lbl_806EF4F8->dest, lbl_806EF4F8->length);
        } else {
            fn_804158BC(lbl_806EF4F8->type, lbl_806EF4F8->dest, lbl_806EF4F8->source, lbl_806EF4F8->length);
        }
        lbl_806EF518 = lbl_806EF4F8->callback;
        lbl_806EF510 = lbl_806EF4F8;
        lbl_806EF4F8 = (ARQRequest*)lbl_806EF4F8->next;
    }
}

/* __ARQServiceQueueLo */
static void fn_80417314(void)
{
    if (!lbl_806EF514 && lbl_806EF500) {
        lbl_806EF514 = lbl_806EF500;
        lbl_806EF500 = (ARQRequest*)lbl_806EF500->next;
    }
    if (lbl_806EF514) {
        if (lbl_806EF514->length <= lbl_806EF520) {
            if (lbl_806EF514->type == ARQ_TYPE_MRAM_TO_ARAM) {
                fn_804158BC(lbl_806EF514->type, lbl_806EF514->source, lbl_806EF514->dest, lbl_806EF514->length);
            } else {
                fn_804158BC(lbl_806EF514->type, lbl_806EF514->dest, lbl_806EF514->source, lbl_806EF514->length);
            }
            lbl_806EF51C = lbl_806EF514->callback;
        } else {
            if (lbl_806EF514->type == ARQ_TYPE_MRAM_TO_ARAM) {
                fn_804158BC(lbl_806EF514->type, lbl_806EF514->source, lbl_806EF514->dest, lbl_806EF520);
            } else {
                fn_804158BC(lbl_806EF514->type, lbl_806EF514->dest, lbl_806EF514->source, lbl_806EF520);
            }
        }
        lbl_806EF514->length -= lbl_806EF520;
        lbl_806EF514->source += lbl_806EF520;
        lbl_806EF514->dest += lbl_806EF520;
    }
}

/* __ARQCallbackHack */
void fn_80417414(u32 unused)
{
}

/* __ARQInterruptServiceRoutine */
static void fn_80417418(void)
{
    if (lbl_806EF518) {
        lbl_806EF518((u32)lbl_806EF510);
        lbl_806EF510 = NULL;
        lbl_806EF518 = NULL;
    } else if (lbl_806EF51C) {
        lbl_806EF51C((u32)lbl_806EF514);
        lbl_806EF514 = NULL;
        lbl_806EF51C = NULL;
    }
    __ARQPopTaskQueueHi();
    if (!lbl_806EF510) {
        fn_80417314();
    }
}

/* ARQInit */
void fn_804174E4(void)
{
    if (lbl_806EF524 == TRUE) {
        return;
    }
    OSRegisterVersion(lbl_806EF158);
    lbl_806EF500 = NULL;
    lbl_806EF4F8 = NULL;
    lbl_806EF520 = 0x1000;
    fn_8041583C(fn_80417418);
    lbl_806EF510 = NULL;
    lbl_806EF514 = NULL;
    lbl_806EF518 = NULL;
    lbl_806EF51C = NULL;
    lbl_806EF524 = TRUE;
}

/* ARQPostRequest */
void fn_80417554(ARQRequest* request, u32 owner, u32 type, u32 priority, u32 source, u32 dest, u32 length,
                 ARQCallback callback)
{
    BOOL level;

    request->next = NULL;
    request->owner = owner;
    request->type = type;
    request->source = source;
    request->dest = dest;
    request->length = length;
    if (callback) {
        request->callback = callback;
    } else {
        request->callback = fn_80417414;
    }
    level = OSDisableInterrupts();
    switch (priority) {
    case ARQ_PRIORITY_LOW:
        if (lbl_806EF500) {
            lbl_806EF504->next = request;
        } else {
            lbl_806EF500 = request;
        }
        lbl_806EF504 = request;
        break;
    case ARQ_PRIORITY_HIGH:
        if (lbl_806EF4F8) {
            lbl_806EF4FC->next = request;
        } else {
            lbl_806EF4F8 = request;
        }
        lbl_806EF4FC = request;
        break;
    }
    if (!lbl_806EF510 && !lbl_806EF514) {
        __ARQPopTaskQueueHi();
        if (!lbl_806EF510) {
            fn_80417314();
        }
    }
    OSRestoreInterrupts(level);
}

/* ARQRemoveRequest */
void fn_804176B0(ARQRequest* request)
{
    BOOL level;
    ARQRequest* req;

    level = OSDisableInterrupts();
    lbl_806EF508 = NULL;
    lbl_806EF50C = NULL;
    for (req = lbl_806EF4F8; req; req = (ARQRequest*)req->next) {
        if (req != request) {
            if (!lbl_806EF508) {
                lbl_806EF508 = req;
                lbl_806EF50C = req;
            } else {
                lbl_806EF50C->next = req;
                lbl_806EF50C = req;
            }
        }
    }
    lbl_806EF4F8 = lbl_806EF508;
    lbl_806EF4FC = lbl_806EF50C;
    lbl_806EF508 = NULL;
    lbl_806EF50C = NULL;
    for (req = lbl_806EF500; req; req = (ARQRequest*)req->next) {
        if (req != request) {
            if (!lbl_806EF508) {
                lbl_806EF508 = req;
                lbl_806EF50C = req;
            } else {
                lbl_806EF50C->next = req;
                lbl_806EF50C = req;
            }
        }
    }
    lbl_806EF500 = lbl_806EF508;
    lbl_806EF504 = lbl_806EF50C;
    OSRestoreInterrupts(level);
}
