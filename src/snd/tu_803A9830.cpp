/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803A9830-0x803AB278 (code-only unit, 26 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */

#include "snd/cmn/sndcmn.h"

extern unsigned short lbl_80625214[258];
extern float lbl_806095A0;
extern SNDSTREAMSTATE lbl_8069CADC;

extern "C" void* fn_803AB310();
extern "C" void fn_803B43FC(SNDLINKLIST* list, void* node);
extern "C" void fn_803B4344(SNDLINKLIST* list, void* node);
extern "C" void fn_803FE7E0(int handle, void* p);
extern "C" int fn_803AA95C(int h);
extern "C" void fn_803AA07C(SNDSTREAMCHANNEL* pssc, int* hdr);
extern "C" void fn_803A9E40(int h, int* hdr);
extern "C" int fn_803FE914(int handle);
extern "C" int fn_803FE954(int handle);
extern "C" void fn_803A975C();
extern "C" void fn_803A979C();
extern "C" int fn_803AA468();
extern "C" int fn_803AAA3C(int h);
extern "C" void fn_803AC7F0(void (*fn)());
extern "C" void fn_803AA2E8();
extern "C" void fn_803B54A8(int h);
extern "C" void fn_803B5408(int h);
extern "C" void fn_803FDC80(int h);
extern "C" void fn_803FE418(int h);
extern "C" void fn_803FE660(int h);
extern "C" void fn_803AA4B0(void* a, int b, void* c, void* d, int e, int f, int g);
extern void* lbl_8069CA44;
extern "C" void fn_803AA810(void* a, int b, void* c, void* d, int e);

int iSNDsin(int angle)
{
    int quad = (angle >> 8) & 3;
    int idx = angle & 0xFF;
    if (quad == 0)
        return lbl_80625214[idx];
    if (quad == 1)
        return lbl_80625214[256 - idx];
    if (quad == 2)
        return -lbl_80625214[idx];
    return -lbl_80625214[256 - idx];
}

extern "C" void fn_803A98B0(SNDSTREAMCHANNEL* pssc)
{
    int i;
    for (i = 0; i < 6; i++) {
        Snd::StreamSourceChannelState* s = &pssc->sourceChannelState[i];
        if (s->fader.incrementPerUpdate != lbl_806095A0)
            Snd::Util::RemoveVariableTimerClient(&s->fader.variableTimerClient);
    }
}

/* Average data rate of a sample format (bytes per second). */
/* near-miss: instruction set matches; callee-saved/scratch registers are permuted (retail: rep r0, chans r9, rate r3, mult r11); declaration-order permutations tried */
extern "C" int fn_803A9BEC(SNDSAMPLEFORMAT* ssf)
{
    int rep = ssf->samplerep;
    int chans = ssf->channels;
    int rate = ssf->samplerate * chans;
    int mult = 0;
    if (rep == 10)
        mult = 0x88;
    else if (rep == 4)
        mult = 0x33;
    else if (rep == 22)
        mult = 0x66;
    else if (rep == 7)
        mult = 0x200;
    else if (rep == 16 || rep == 23)
        return chans << 3;
    return (rate * mult) >> 8;
}

extern "C" int fn_803A9C64()
{
    int i;
    for (i = 0; i < sndgs.sso.set.maxstreams; i++)
        fn_803AA95C(i);
    return 0;
}

SNDSTREAMCHANNEL* SNDSTRMI_getstreamptr(int sndstreamhandle)
{
    if (sndstreamhandle >= sndgs.sso.set.maxstreams || sndstreamhandle < 0)
        return 0;
    return lbl_8069CADC.pssc[sndstreamhandle];
}

/* near-miss: one register differs: retail computes (unsigned char)h << 2 into r0, ours overwrites r3; unsigned char param, local index, mask forms tried */
extern "C" void fn_803A9CF4(int h)
{
    SNDSTREAMCHANNEL* pssc = lbl_8069CADC.pssc[(unsigned char)h];
    void* req = fn_803AB310();
    fn_803B43FC(&pssc->allocatedrequests, req);
    fn_803B4344(&pssc->freerequests, req);
    if (pssc->parsingrequest == req)
        pssc->parsingrequest = 0;
}

extern "C" void fn_803A9D5C(int* p)
{
    unsigned char* hdr = (unsigned char*)p[-1];
    fn_803FE7E0(lbl_8069CADC.pssc[hdr[3]]->streamhandle, hdr);
}

extern "C" void fn_803A9D98(int unused, unsigned int frames, SNDSTREAMCHANNEL* pssc)
{
    unsigned int leftover = 0;
    int iter = 0;
    for (;;) {
        iter++;
        Snd::SNDSTREAMREQUEST* r = (Snd::SNDSTREAMREQUEST*)pssc->allocatedrequests.phead;
        if (iter > 200) {
            fn_803A9CF4(r->sndrequesthandle);
            return;
        }
        if (frames > r->outstandingframes) {
            leftover = frames - r->outstandingframes;
            frames = frames - leftover;
        }
        r->currentframe += frames;
        r->outstandingframes -= frames;
        if (r->currentframe >= (unsigned int)r->totalframes)
            fn_803A9CF4(r->sndrequesthandle);
        if (leftover == 0)
            return;
        frames = leftover;
        leftover = 0;
    }
}

extern "C" int fn_803AA194(int h, int* hdr)
{
    SNDSTREAMCHANNEL* pssc = lbl_8069CADC.pssc[h];
    int tag = *hdr;
    if (tag == 0x5343446c) {
        fn_803AA07C(pssc, hdr);
    } else if (tag == 0x5343486c) {
        fn_803A9E40(h, hdr);
        return 0;
    } else {
        fn_803FE7E0(pssc->streamhandle, hdr);
    }
    return 1;
}

extern "C" int fn_803AA20C(SNDSTREAMCHANNEL* pssc)
{
    Snd::SNDSTREAMREQUEST* r = (Snd::SNDSTREAMREQUEST*)pssc->parsingrequest;
    if (r != 0 && r->avgdatarate != 0) {
        if (r->holdtime < 0) {
        yes:
            return 1;
        }
        if (r->holdtime != 0) {
            unsigned int t = fn_803FE914(pssc->streamhandle);
            if (t > 0x3D0900)
                t = 0x3D0900;
            if (t * 1000 / r->avgdatarate >= (unsigned int)r->holdtime || fn_803FE954(pssc->streamhandle) == 2) {
                r->holdtime = 0;
                return 0;
            }
            if (pssc->freerequests.items > 0)
                goto yes;
            int st = fn_803FE954(pssc->streamhandle);
            if (st != 0)
                goto yes;
            r->holdtime = st;
        }
    }
    return 0;
}

extern "C" int fn_803AA468()
{
    int n = 0;
    int i;
    for (i = 0; i < sndgs.sso.set.maxstreams; i++)
        if (lbl_8069CADC.pssc[i] != 0)
            n++;
    return n;
}

extern "C" void fn_803AA934(void* a, int b, void* c, void* d, int e)
{
    fn_803AA4B0(a, b, c, d, e, 0, 0);
}

extern "C" int fn_803AA95C(int h)
{
    fn_803A975C();
    SNDSTREAMCHANNEL* pssc = SNDSTRMI_getstreamptr(h);
    if (pssc == 0) {
        fn_803A979C();
        return -8;
    }
    fn_803AAA3C(h);
    fn_803A98B0(pssc);
    if (fn_803AA468() == 1) {
        fn_803AC7F0(fn_803AA2E8);
        lbl_8069CA44 = 0;
    }
    fn_803B54A8(pssc->packetinstancehandle);
    int sh = pssc->streamhandle;
    int tap = pssc->fromtap;
    lbl_8069CADC.pssc[h] = 0;
    fn_803A979C();
    if (tap == 0)
        fn_803FDC80(sh);
    return 0;
}

extern "C" void fn_803AAA18(void* a, int b, void* c, void* d)
{
    fn_803AA810(a, b, c, d, 0);
}
