/* Imported from emoose/re4 @ feb6805b (src/lib/Pad.c), based on doldecomp/dolsdk2004. Nintendo Dolphin SDK 2004 Patch 1, pad library; names are Nintendo's. */
/* The game code still calls this by its placeholder name; the placeholder keeps symbols.txt and the
 * callers consistent until a project-wide rename. */
#define PADRecalibrate fn_804393B4
#define PADControlMotor fn_80439918
#include <dolphin.h>
#include <dolphin/pad.h>
#include <dolphin/si.h>

#include "__si.h"
extern void fn_80433814(OSContext*);
extern void fn_8043364C(OSContext*);
extern OSTime fn_80438628(void);
extern void fn_80437080(s32, u16);
extern u32 lbl_806EF8A8;


#if DEBUG
const char* __PADVersion = "<< Dolphin SDK - PAD\tdebug build: Apr  5 2004 03:56:05 (0x2301) >>";
#else
const char* __PADVersion = "<< Dolphin SDK - PAD\trelease build: Apr  5 2004 04:14:49 (0x2301) >>";
#endif

#define PAD_ALL                                                                                                        \
    (                      \
        PAD_BUTTON_LEFT  | \
        PAD_BUTTON_RIGHT | \
        PAD_BUTTON_DOWN  | \
        PAD_BUTTON_UP    | \
        PAD_TRIGGER_Z    | \
        PAD_TRIGGER_R    | \
        PAD_TRIGGER_L    | \
        PAD_BUTTON_A     | \
        PAD_BUTTON_B     | \
        PAD_BUTTON_X     | \
        PAD_BUTTON_Y     | \
        PAD_BUTTON_MENU  | \
        0x2000           | \
        0x0080             \
    )

static s32 ResettingChan = 0x20;
static u32 XPatchBits = PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT;
static u32 AnalogMode = 0x300;
static u32 Spec = PAD_SPEC_5;

extern BOOL lbl_806EF870;
extern u32 lbl_806EF874;
extern u32 lbl_806EF878;
extern u32 lbl_806EF87C;
extern u32 lbl_806EF880;
extern u32 lbl_806EF884;
extern u32 lbl_806EF888;
extern u32 lbl_806EF88C;

static u32 Type[4];
static PADStatus Origin[4];

extern u32 lbl_806EF89C;

// prototypes
static void PADTypeAndStatusCallback(s32 chan, u32 type);
static u16 GetWirelessID(s32 chan);
static void SetWirelessID(s32 chan, u16 id);
static inline void DoReset();
static inline void PADEnable(s32 chan);
static void ProbeWireless(s32 chan);
static void PADProbeCallback(s32 chan, u32 error, OSContext *context);
static inline void PADDisable(s32 chan);
static void UpdateOrigin(s32 chan);
static void PADOriginCallback(s32 chan, u32 error, OSContext *context);
static void PADFixCallback(s32 unused, u32 error, struct OSContext *context);
static void PADResetCallback(s32 unused, u32 error, struct OSContext *context);
static void PADReceiveCheckCallback(s32 chan, u32 error);
static void SPEC0_MakeStatus(s32 chan, PADStatus *status, u32 data[2]);
static void SPEC1_MakeStatus(s32 chan, PADStatus *status, u32 data[2]);
static inline s8 ClampS8(s8 var, s8 org);
static inline u8 ClampU8(u8 var, u8 org);
static void SPEC2_MakeStatus(s32 chan, PADStatus *status, u32 data[2]);
static BOOL OnReset(BOOL f);
void __PADDisableXPatch(void);
BOOL __PADDisableRumble(BOOL disable);

typedef void (*SPECCallback)(s32, PADStatus*, u32*);
static SPECCallback MakeStatus = SPEC2_MakeStatus;

extern u32 lbl_806EF890;
static u32 CmdReadOrigin = 0x41000000;
static u32 CmdCalibrate = 0x42000000;
static u32 CmdProbeDevice[4];

static OSResetFunctionInfo ResetFunctionInfo = {
    OnReset,
    127,
    NULL,
    NULL,
};

static inline void PADEnable(s32 chan) {
    u32 cmd;
    u32 chanBit;
    u32 data[2];

    chanBit = PAD_CHAN0_BIT >> chan;
    lbl_806EF874 |= chanBit;
    SIGetResponse(chan, &data);
    cmd = (AnalogMode | 0x400000);
    SISetCommand(chan, cmd);
    SIEnablePolling(lbl_806EF874);
}

static inline void PADDisable(s32 chan) {
    BOOL enabled;
    u32 chanBit;

    enabled = OSDisableInterrupts();
    chanBit = PAD_CHAN0_BIT >> chan;
    SIDisablePolling(chanBit);
    lbl_806EF874 &= ~chanBit;
    lbl_806EF880 &= ~chanBit;
    lbl_806EF884 &= ~chanBit;
    lbl_806EF888 &= ~chanBit;
    lbl_806EF88C &= ~chanBit;
    fn_80437080(chan, 0);
    OSRestoreInterrupts(enabled);
}

static inline void DoReset() {
    u32 chanBit;

    ResettingChan = __cntlzw(lbl_806EF878);
    if (ResettingChan != 32) {
        ASSERTLINE(559, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);
        chanBit = (PAD_CHAN0_BIT >> ResettingChan);
        lbl_806EF878 &= ~chanBit;
        
        memset(&Origin[ResettingChan], 0, sizeof(PADStatus));
        SIGetTypeAsync(ResettingChan, PADTypeAndStatusCallback);
    }
}

static void UpdateOrigin(s32 chan) {
    PADStatus* origin;
    u32 chanBit = PAD_CHAN0_BIT >> chan;

    origin = &Origin[chan];
    switch (AnalogMode & 0x00000700u) {
    case 0x00000000u:
    case 0x00000500u:
    case 0x00000600u:
    case 0x00000700u:
        origin->triggerLeft &= ~15;
        origin->triggerRight &= ~15;
        origin->analogA &= ~15;
        origin->analogB &= ~15;
        break;
    case 0x00000100u:
        origin->substickX &= ~15;
        origin->substickY &= ~15;
        origin->analogA &= ~15;
        origin->analogB &= ~15;
        break;
    case 0x00000200u:
        origin->substickX &= ~15;
        origin->substickY &= ~15;
        origin->triggerLeft &= ~15;
        origin->triggerRight &= ~15;
        break;
    case 0x00000300u: break;
    case 0x00000400u: break;
    }

    origin->stickX -= 128;
    origin->stickY -= 128;
    origin->substickX -= 128;
    origin->substickY -= 128;

    if (XPatchBits & chanBit) {
        if (64 < origin->stickX && (SIGetType(chan) & 0xFFFF0000) == SI_GC_CONTROLLER) {
            origin->stickX = 0;
        }
    }
}

static void PADOriginCallback(s32 chan, u32 error, OSContext* context) {
    ASSERTLINE(641, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);
    ASSERTLINE(642, chan == ResettingChan);

    if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION)))
    {
        UpdateOrigin(ResettingChan);
        PADEnable(ResettingChan);
    }

    DoReset();
}

static void PADOriginUpdateCallback(s32 chan, u32 error, OSContext* context) {
    ASSERTLINE(671, 0 <= chan && chan < SI_MAX_CHAN);
    if (!(lbl_806EF874 & (PAD_CHAN0_BIT >> chan)))
        return;
    if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION)))
        UpdateOrigin(chan);
    if (error & SI_ERROR_NO_RESPONSE) {
        PADDisable(chan);
    }
}

static void PADProbeCallback(s32 chan, u32 error, OSContext* context) {
    u32 type;
    ASSERTLINE(710, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);
    ASSERTLINE(711, chan == ResettingChan);
    ASSERTLINE(713, (Type[chan] & SI_WIRELESS_CONT_MASK) == SI_WIRELESS_CONT && !(Type[chan] & SI_WIRELESS_LITE));
    
    if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION)))
    {
        PADEnable(ResettingChan);
        lbl_806EF880 |= PAD_CHAN0_BIT >> ResettingChan;
    }

    DoReset();
}

static void PADTypeAndStatusCallback(s32 chan, u32 type) {
    u32 chanBit;
    u32 recalibrate;
    BOOL rc = TRUE;
    u32 error;

    ASSERTLINE(746, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);
    ASSERTLINE(747, chan == ResettingChan);

    chanBit = PAD_CHAN0_BIT >> ResettingChan;
    error = type & 0xFF;
    ASSERTLINE(756, !(error & SI_ERROR_BUSY));

    recalibrate = lbl_806EF87C & chanBit;
    lbl_806EF87C &= ~chanBit;

    if (error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION))
    {
        DoReset();
        return;
    }

    type &= ~0xFF;
    Type[ResettingChan] = type;

    if ((type & SI_TYPE_MASK) != SI_TYPE_GC || !(type & SI_GC_STANDARD)) {
        DoReset();
        return;
    }

    if (Spec < PAD_SPEC_2) {
        PADEnable(ResettingChan);
        DoReset();
        return;
    }

    if (!(type & SI_GC_WIRELESS) || (type & SI_WIRELESS_IR)) {
        if (recalibrate) {
            rc = SITransfer(ResettingChan, &CmdCalibrate, 3, &Origin[ResettingChan], 10,
                            PADOriginCallback, 0);
        } else {
            rc = SITransfer(ResettingChan, &CmdReadOrigin, 1, &Origin[ResettingChan], 10,
                            PADOriginCallback, 0);
        }
    } else if ((type & SI_WIRELESS_FIX_ID) && (type & SI_WIRELESS_CONT_MASK) == SI_WIRELESS_CONT &&
               !(type & SI_WIRELESS_LITE))
    {
        if (type & SI_WIRELESS_RECEIVED) {
            rc = SITransfer(ResettingChan, &CmdReadOrigin, 1, &Origin[ResettingChan], 10,
                            PADOriginCallback, 0);
        } else {
            rc = SITransfer(ResettingChan, &CmdProbeDevice[ResettingChan], 3,
                            &Origin[ResettingChan], 8, PADProbeCallback, 0);
        }
    }

    if (!rc) {
        lbl_806EF888 |= chanBit;
        DoReset();
        return;
    }
}

static void PADReceiveCheckCallback(s32 chan, u32 type) {
    u32 error;
    u32 chanBit;

    chanBit = PAD_CHAN0_BIT >> chan;

    if (lbl_806EF874 & chanBit) {
        error = type & 0xFF;
        type &= ~0xFF;

        lbl_806EF880 &= ~chanBit;
        lbl_806EF884 &= ~chanBit;

        if (!(error &
            (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION)) &&
            (type & SI_GC_WIRELESS) && (type & SI_WIRELESS_FIX_ID) && (type & SI_WIRELESS_RECEIVED) &&
            !(type & SI_WIRELESS_IR) && (type & SI_WIRELESS_CONT_MASK) == SI_WIRELESS_CONT &&
            !(type & SI_WIRELESS_LITE))
        {
            SITransfer(chan, &CmdReadOrigin, 1, &Origin[chan], 10, PADOriginUpdateCallback, 0);
        } else {
            PADDisable(chan);
        }
    }
}

int PADReset(u32 mask) {
    BOOL enabled;
    u32 disableBits;

    ASSERTMSGLINE(0x381, !(mask & 0x0FFFFFFF), "PADReset(): invalid mask");

    enabled = OSDisableInterrupts();
    mask |= lbl_806EF888;
    lbl_806EF888 = 0;
    mask &= ~(lbl_806EF880 | lbl_806EF884);
    lbl_806EF878 |= mask;
    disableBits = lbl_806EF878 & lbl_806EF874;
    lbl_806EF874 &= ~mask;
    lbl_806EF88C &= ~mask;

    if (Spec == 4) {
        lbl_806EF87C |= mask;
    }

    SIDisablePolling(disableBits);

    if (ResettingChan == 0x20) {
        DoReset();
    }

    OSRestoreInterrupts(enabled);
    return 1;
}

BOOL PADRecalibrate(u32 mask) {
    BOOL enabled;
    u32 disableBits;

    ASSERTMSGLINE(939, !(mask & 0x0FFFFFFF), "PADReset(): invalid mask");
    enabled = OSDisableInterrupts();

    mask |= lbl_806EF888;
    lbl_806EF888 = 0;
    mask &= ~(lbl_806EF880 | lbl_806EF884);
    lbl_806EF878 |= mask;
    disableBits = lbl_806EF878 & lbl_806EF874;
    lbl_806EF874 &= ~mask;
    lbl_806EF88C &= ~mask;

    if (!(__gUnknown800030E3 & 0x40)) {
        lbl_806EF87C |= mask;
    }

    SIDisablePolling(disableBits);
    if (ResettingChan == 32)
        DoReset();

    OSRestoreInterrupts(enabled);
    return 1;
}

BOOL PADInit() {
    s32 chan;
    if (lbl_806EF870) {
        return 1;
    }
    
    OSRegisterVersion(__PADVersion);

    if (lbl_806EF89C)
        PADSetSpec(lbl_806EF89C);

    lbl_806EF870 = TRUE;

    if (lbl_806EF8A8 != 0) {
        OSTime time = fn_80438628();
        __OSWirelessPadFixMode
            = (u16)((((time)&0xffff) + ((time >> 16) & 0xffff) + ((time >> 32) & 0xffff) + ((time >> 48) & 0xffff))
                    & 0x3fffu);
    
        lbl_806EF87C = PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT;
    }

    for (chan = 0; chan < SI_MAX_CHAN; ++chan) {
        CmdProbeDevice[chan] = (0x4D << 24) | (chan << 22) | ((__OSWirelessPadFixMode & 0x3fffu) << 8);
    }

    SIRefreshSamplingRate();
    OSRegisterResetFunction(&ResetFunctionInfo);

    return PADReset(PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT);
}

u32 PADRead(PADStatus* status) {
    BOOL enabled;
    s32 chan;
    u32 data[2];
    u32 chanBit;
    u32 sr;
    int chanShift;
    u32 motor;

    enabled = OSDisableInterrupts();
    motor = 0;

    for (chan = 0; chan < 4; chan++, status++) {
        chanBit = PAD_CHAN0_BIT >> chan;
        chanShift = 8 * (SI_MAX_CHAN - 1 - chan);

        if (lbl_806EF888 & chanBit) {
            PADReset(0);
            status->err = PAD_ERR_NOT_READY;
            memset(status, 0, offsetof(PADStatus, err));
        } else if ((lbl_806EF878 & chanBit) || ResettingChan == chan) {
            status->err = PAD_ERR_NOT_READY;
            memset(status, 0, offsetof(PADStatus, err));
        } else if (!(lbl_806EF874 & chanBit)) {
            status->err = PAD_ERR_NO_CONTROLLER;
            memset(status, 0, offsetof(PADStatus, err));
        } else if (SIIsChanBusy(chan)) {
            status->err = PAD_ERR_TRANSFER;
            memset(status, 0, offsetof(PADStatus, err));
        } else {
            sr = SIGetStatus(chan);
            if (sr & SI_ERROR_NO_RESPONSE) {
                SIGetResponse(chan, data);

                if (lbl_806EF880 & chanBit) {
                    status->err = PAD_ERR_NONE;
                    memset(status, 0, offsetof(PADStatus, err));

                    if (!(lbl_806EF884 & chanBit)) {
                        lbl_806EF884 |= chanBit;
                        SIGetTypeAsync(chan, PADReceiveCheckCallback);
                    }
                } else {
                    PADDisable(chan);
                    status->err = PAD_ERR_NO_CONTROLLER;
                    memset(status, 0, offsetof(PADStatus, err));
                }
            } else {
                if (!(SIGetType(chan) & SI_GC_NOMOTOR)) {
                    motor |= chanBit;
                }
    
                if (!SIGetResponse(chan, &data)) {
                    status->err = PAD_ERR_TRANSFER;
                    memset(status, 0, offsetof(PADStatus, err));
                } else if (data[0] & 0x80000000) {
                    status->err = PAD_ERR_TRANSFER;
                    memset(status, 0, offsetof(PADStatus, err));
                } else {
                    MakeStatus(chan, status, data);
    
                    // Check and clear PAD_ORIGIN bit
                    if (status->button & 0x2000) {
                        status->err = PAD_ERR_TRANSFER;
                        memset(status, 0, offsetof(PADStatus, err));
        
                        // Get origin. It is okay if the following transfer fails
                        // since the PAD_ORIGIN bit remains until the read origin
                        // command complete.
                        SITransfer(chan, &CmdReadOrigin, 1, &Origin[chan], 10, PADOriginUpdateCallback, 0);
                    } else {
                        status->err = PAD_ERR_NONE;
        
                        // Clear PAD_INTERFERE bit
                        status->button &= ~0x0080;
                    }
                }
            }
        }
    }

    OSRestoreInterrupts(enabled);
    return motor;
}

typedef struct XY {
    u8 line;
    u8 count;
} XY;

#if DEBUG
void __PADTestSamplingRate(u32 tvmode) {
    __SITestSamplingRate(tvmode);
}
#endif

void PADControlMotor(s32 chan, u32 command) {
    BOOL enabled;
    u32 chanBit;

    ASSERTMSGLINE(1244, !(command & 0xFFFFFFFC), "PADControlMotor(): invalid command");

    enabled = OSDisableInterrupts();
    chanBit = PAD_CHAN0_BIT >> chan;
    if ((lbl_806EF874 & chanBit) && !(SIGetType(chan) & SI_GC_NOMOTOR)) {
        if (Spec < PAD_SPEC_2 && command == PAD_MOTOR_STOP_HARD)
            command = PAD_MOTOR_STOP;
        if (__gUnknown800030E3 & 0x20)
            command = PAD_MOTOR_STOP;
        SISetCommand(chan, (0x40 << 16) | AnalogMode | (command & (0x00000001 | 0x00000002)));
        SITransferCommands();
    }

    OSRestoreInterrupts(enabled);
}

void PADSetSpec(u32 spec) {
    ASSERTLINE(1282, !lbl_806EF870);
    lbl_806EF89C = 0;

    switch (spec) {
    case PAD_SPEC_0:
        MakeStatus = SPEC0_MakeStatus;
        break;
    case PAD_SPEC_1:
        MakeStatus = SPEC1_MakeStatus;
        break;
    case PAD_SPEC_2:
    case PAD_SPEC_3:
    case PAD_SPEC_4:
    case PAD_SPEC_5:
        MakeStatus = SPEC2_MakeStatus;
        break;
    }
    Spec = spec;
}

static void SPEC0_MakeStatus(s32 chan, PADStatus* status, u32 data[2]) {
    status->button = 0;
    status->button |= ((data[0] >> 16) & 0x0008) ? PAD_BUTTON_A : 0;
    status->button |= ((data[0] >> 16) & 0x0020) ? PAD_BUTTON_B : 0;
    status->button |= ((data[0] >> 16) & 0x0100) ? PAD_BUTTON_X : 0;
    status->button |= ((data[0] >> 16) & 0x0001) ? PAD_BUTTON_Y : 0;
    status->button |= ((data[0] >> 16) & 0x0010) ? PAD_BUTTON_START : 0;
    status->stickX = (s8)(data[1] >> 16);
    status->stickY = (s8)(data[1] >> 24);
    status->substickX = (s8)(data[1]);
    status->substickY = (s8)(data[1] >> 8);
    status->triggerLeft = (u8)(data[0] >> 8);
    status->triggerRight = (u8)data[0];
    status->analogA = 0;
    status->analogB = 0;
    if (170 <= status->triggerLeft)
        status->button |= PAD_TRIGGER_L;
    if (170 <= status->triggerRight)
        status->button |= PAD_TRIGGER_R;
    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;
}

static void SPEC1_MakeStatus(s32 chan, PADStatus* status, u32 data[2]) {
    status->button = 0;
    status->button |= ((data[0] >> 16) & 0x0080) ? PAD_BUTTON_A : 0;
    status->button |= ((data[0] >> 16) & 0x0100) ? PAD_BUTTON_B : 0;
    status->button |= ((data[0] >> 16) & 0x0020) ? PAD_BUTTON_X : 0;
    status->button |= ((data[0] >> 16) & 0x0010) ? PAD_BUTTON_Y : 0;
    status->button |= ((data[0] >> 16) & 0x0200) ? PAD_BUTTON_START : 0;

    status->stickX = (s8)(data[1] >> 16);
    status->stickY = (s8)(data[1] >> 24);
    status->substickX = (s8)(data[1]);
    status->substickY = (s8)(data[1] >> 8);

    status->triggerLeft = (u8)(data[0] >> 8);
    status->triggerRight = (u8)data[0];

    status->analogA = 0;
    status->analogB = 0;

    if (170 <= status->triggerLeft)
        status->button |= PAD_TRIGGER_L;
    if (170 <= status->triggerRight)
        status->button |= PAD_TRIGGER_R;

    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;
}

static inline s8 ClampS8(s8 var, s8 org) {
    if (0 < org) {
        s8 min = (s8)(-128 + org);
        if (var < min)
            var = min;
    } else if (org < 0) {
        s8 max = (s8)(127 + org);
        if (max < var)
            var = max;
    }
    return var -= org;
}

static inline u8 ClampU8(u8 var, u8 org) {
    if (var < org)
        var = org;
    return var -= org;
}

static void SPEC2_MakeStatus(s32 chan, PADStatus* status, u32 data[2]) {
    PADStatus* origin;

    status->button = (u16)((data[0] >> 16) & PAD_ALL);
    status->stickX = (s8)(data[0] >> 8);
    status->stickY = (s8)(data[0]);

    switch (AnalogMode & 0x00000700) {
    case 0x00000000:
    case 0x00000500:
    case 0x00000600:
    case 0x00000700:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = (u8)(((data[1] >> 12) & 0x0f) << 4);
        status->triggerRight = (u8)(((data[1] >> 8) & 0x0f) << 4);
        status->analogA = (u8)(((data[1] >> 4) & 0x0f) << 4);
        status->analogB = (u8)(((data[1] >> 0) & 0x0f) << 4);
        break;
    case 0x00000100:
        status->substickX = (s8)(((data[1] >> 28) & 0x0f) << 4);
        status->substickY = (s8)(((data[1] >> 24) & 0x0f) << 4);
        status->triggerLeft = (u8)(data[1] >> 16);
        status->triggerRight = (u8)(data[1] >> 8);
        status->analogA = (u8)(((data[1] >> 4) & 0x0f) << 4);
        status->analogB = (u8)(((data[1] >> 0) & 0x0f) << 4);
        break;
    case 0x00000200:
        status->substickX = (s8)(((data[1] >> 28) & 0x0f) << 4);
        status->substickY = (s8)(((data[1] >> 24) & 0x0f) << 4);
        status->triggerLeft = (u8)(((data[1] >> 20) & 0x0f) << 4);
        status->triggerRight = (u8)(((data[1] >> 16) & 0x0f) << 4);
        status->analogA = (u8)(data[1] >> 8);
        status->analogB = (u8)(data[1] >> 0);
        break;
    case 0x00000300:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = (u8)(data[1] >> 8);
        status->triggerRight = (u8)(data[1] >> 0);
        status->analogA = 0;
        status->analogB = 0;
        break;
    case 0x00000400:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = 0;
        status->triggerRight = 0;
        status->analogA = (u8)(data[1] >> 8);
        status->analogB = (u8)(data[1] >> 0);
        break;
    }

    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;

    if (((Type[chan] & (0xFFFF0000)) == SI_GC_CONTROLLER) && ((status->button & 0x80) ^ 0x80)) {
        lbl_806EF88C |= (PAD_CHAN0_BIT >> chan);
        status->stickX = 0;
        status->stickY = 0;
        status->substickX = 0;
        status->substickY = 0;
        return;
    } else {
        lbl_806EF88C &= ~(PAD_CHAN0_BIT >> chan);
    }

    origin = &Origin[chan];
    status->stickX = ClampS8(status->stickX, origin->stickX);
    status->stickY = ClampS8(status->stickY, origin->stickY);
    status->substickX = ClampS8(status->substickX, origin->substickX);
    status->substickY = ClampS8(status->substickY, origin->substickY);
    status->triggerLeft = ClampU8(status->triggerLeft, origin->triggerLeft);
    status->triggerRight = ClampU8(status->triggerRight, origin->triggerRight);
}

inline BOOL PADSync(void) {
    return lbl_806EF878 == 0 && (s32)ResettingChan == 32 && !SIBusy();
}

extern PADSamplingCallback lbl_806EF894;

static BOOL OnReset(BOOL final) {
    BOOL sync;
    extern BOOL lbl_806EF898;

    if (lbl_806EF894)
        PADSetSamplingCallback(NULL);

    if (!final) {
        sync = PADSync();
        if (!lbl_806EF898 && sync) {
            lbl_806EF898 = PADRecalibrate(PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT);
            return FALSE;
        }
        return sync;
    } else
        lbl_806EF898 = FALSE;

    return TRUE;
}

static void SamplingHandler(__OSInterrupt interrupt, OSContext* context) {
    OSContext exceptionContext;

    if (lbl_806EF894) {
        fn_80433814(&exceptionContext);
        fn_8043364C(&exceptionContext);
        lbl_806EF894();
        fn_80433814(&exceptionContext);
        fn_8043364C(context);
    }
}

PADSamplingCallback PADSetSamplingCallback(PADSamplingCallback callback) {
    PADSamplingCallback prev;

    prev = lbl_806EF894;
    lbl_806EF894 = callback;
    if (callback) {
        SIRegisterPollingHandler(SamplingHandler);
    } else {
        SIUnregisterPollingHandler(SamplingHandler);
    }

    return prev;
}

BOOL __PADDisableRecalibration(BOOL disable) {
    BOOL enabled;
    BOOL prev;

    enabled = OSDisableInterrupts();
    prev = (__gUnknown800030E3 & 0x40) ? TRUE : FALSE;
    __gUnknown800030E3 &= ~0x40;
    if (disable) {
        __gUnknown800030E3 |= 0x40;
    }

    OSRestoreInterrupts(enabled);
    return prev;
}

