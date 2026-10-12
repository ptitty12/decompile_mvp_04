/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803AB310-0x803AC88C (code-only unit, 30 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include "snd/cmn/sndcmn.h"

extern int lbl_80625448;
extern "C" void fn_803A975C();
extern "C" void fn_803A979C();
extern "C" void fn_803B4160(int shandle, int cutoff);
extern "C" void fn_803B445C(int shandle, int cutoff);
extern "C" void fn_803B0F24(int voice);
extern "C" int fn_803B4CD4(int n);
extern "C" int fn_803FD944(int a, int b, int c);
extern "C" void fn_803AA810(int h, int a, void* b, int c, int d);
extern "C" unsigned int fn_803B53DC(int h);
extern "C" int fn_803FE914(int h);
extern "C" void fn_803FDD78(int h, int v);
extern "C" void fn_803AD258(int shandle, int v);

extern "C" Snd::SNDSTREAMREQUEST* fn_803AB310(int h)
{
    if (h < 0)
        return 0;
    SNDSTREAMCHANNEL* pssc = SNDSTRMI_getstreamptr((unsigned char)h);
    if (pssc == 0)
        return 0;
    Snd::SNDSTREAMREQUEST* r = (Snd::SNDSTREAMREQUEST*)pssc->allocatedrequests.phead;
    while (r != 0 && r->sndrequesthandle != h)
        r = (Snd::SNDSTREAMREQUEST*)r->node.pnext;
    return r;
}

extern "C" int fn_803AB388(int h, int v)
{
    SNDSTREAMCHANNEL* pssc = SNDSTRMI_getstreamptr(h);
    if (pssc == 0)
        return -8;
    pssc->po.highpasscutoff = v;
    fn_803B4160(pssc->shandle, v);
    return 0;
}

extern "C" int fn_803AB3D8(int h, int v)
{
    fn_803A975C();
    int ret = -8;
    Snd::SNDSTREAMREQUEST* r = fn_803AB310(h);
    if (r != 0) {
        ret = 0;
        r->holdtime = (short)v;
    }
    fn_803A979C();
    return ret;
}

extern "C" int fn_803AB430(int h, int v)
{
    SNDSTREAMCHANNEL* pssc = SNDSTRMI_getstreamptr(h);
    if (pssc == 0)
        return -8;
    pssc->po.lowpasscutoff = v;
    fn_803B445C(pssc->shandle, v);
    return 0;
}

extern "C" int fn_803AB480(int shandle)
{
    int setvoice;
    int voice = SNDVOICEI_get(shandle);
    if (voice >= 0) {
        setvoice = -1;
        while (iSNDpatchkey(voice, &setvoice))
            fn_803B0F24(setvoice);
    }
    return voice;
}

extern "C" int fn_803AB4E0(int maxrequests, int maxchunks)
{
    int n = lbl_80625448 * 4;
    n += 0x214;
    n += maxrequests * 0x28;
    return n + fn_803B4CD4(maxchunks);
}

extern "C" int fn_803AB528(int a, int b)
{
    int n = fn_803AB4E0(a, b);
    return n + fn_803FD944(a + 2, 1, 1);
}

extern "C" int fn_803AB56C(int h, int v)
{
    SNDSTREAMCHANNEL* pssc = SNDSTRMI_getstreamptr(h);
    if (pssc == 0)
        return -8;
    if (v > 0x4000)
        v = 0x4000;
    pssc->po.pitchmult = v;
    SNDpitchmult(pssc->shandle, v);
    return 0;
}

extern "C" void fn_803AB5C8(int a, int b, int c)
{
    fn_803AA810(a, b, 0, c, 2);
}

extern "C" int fn_803AB5F4(int h, int v)
{
    SNDSTREAMCHANNEL* pssc = SNDSTRMI_getstreamptr(h);
    if (pssc == 0)
        return -8;
    pssc->po.drylevel = v;
    SNDCTRL_drylevel(pssc->shandle, v);
    return 0;
}

extern "C" int fn_803AB858(int h, int v)
{
    SNDSTREAMCHANNEL* pssc = SNDSTRMI_getstreamptr(h);
    if (pssc == 0)
        return -8;
    fn_803FDD78(pssc->streamhandle, v);
    return 0;
}

extern "C" int fn_803AB8A4(int h, SNDSTREAMSTATUS* s)
{
    s->timebuffered = 0;
    s->currentrequest = 0;
    s->outstandingrequests = 0;
    SNDSTREAMCHANNEL* pssc = SNDSTRMI_getstreamptr(h);
    if (pssc == 0)
        return -8;
    int n = pssc->allocatedrequests.items;
    s->outstandingrequests = n;
    if (n != 0) {
        Snd::SNDSTREAMREQUEST* r = (Snd::SNDSTREAMREQUEST*)pssc->allocatedrequests.phead;
        s->currentrequest = r->sndrequesthandle;
        if (pssc->cursf.samplerate != 0) {
            s->timebuffered = fn_803B53DC(pssc->packetinstancehandle) * 1000 / pssc->cursf.samplerate;
            if (s->timebuffered == 0) {
                r = fn_803AB310(s->currentrequest);
                if (r->avgdatarate != 0) {
                    unsigned int t = fn_803FE914(pssc->streamhandle);
                    if (t > 0x3D0900)
                        t = 0x3D0900;
                    s->timebuffered = t * 1000 / r->avgdatarate;
                }
            }
        }
    }
    return 0;
}

extern "C" int fn_803AB984(int h, int v)
{
    if (v > 0x2000)
        v = 0x2000;
    else if (v < 0x800)
        v = 0x800;
    SNDSTREAMCHANNEL* pssc = SNDSTRMI_getstreamptr(h);
    if (pssc == 0)
        return -8;
    pssc->po.timemult = v;
    fn_803AD258(pssc->shandle, v);
    return 0;
}

extern "C" int fn_803ABEDC()
{
    return -5;
}

extern unsigned char lbl_8069C9E4[7];
extern int lbl_8062543C;
extern "C" int fn_803AC5CC();

extern "C" int fn_803AC11C()
{
    return lbl_8069C9E4[0] == 1;
}

extern "C" int fn_803AC134()
{
    fn_803AC5CC();
    lbl_8062543C = 0;
    return 0;
}
