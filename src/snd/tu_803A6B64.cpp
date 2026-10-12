/*
 * EA SND 9.02.04 / csis (cflags_snd: -O2 -G0 -fno-strength-reduce -fno-strict-aliasing
 * -ffast-math -mps-float, C++),
 * .text 0x803A6B64-0x803A6D80 (code-only unit, 3 functions; TU boundaries approximate, placeholder).
 * Every data object is extern by its lbl_ name.
 * Reference source: the port/mvp2005 branch (ported from mitsevox/mvp2005, CC0; see docs/DECISIONS.md).
 */
#include "snd/sndo.h"
#include "snd/cmn/sndcmn.h"
#undef override
#include "snd/extern/aemsdef.h"
#include "snd/cmn/saemsi.h"

typedef void* ModuleBankAllocFn(AemsDef::ModuleBank*, int, int);

extern "C" {

int fn_803A82A8(int* phandle, BANKVER5* pb);
int fn_803A8648(int bhandle);

/* near-miss: same instructions; pmb and rc swap r30/r31 (global-alloc priority of rc vs pmb). */
int fn_803A6B64(AemsDef::ModuleBank* pmb, char* streamfilename, int streamfileoffset, ModuleBankAllocFn* alloc)
{
    int sfxrc = 0;
    int midirc = 0;
    AemsDef::ModuleBank* pnew = pmb;
    int rc;
    if (sndaems.logaddmodulebank != NULL) {
        sndaems.logaddmodulebank();
    }
    pmb->modulebankhandle = SNDAEMSI_createmodulebankhandle();
    if (pmb->sfxbankoffset != 0) {
        sfxrc = fn_803A82A8(&pmb->sfxbhandle, reinterpret_cast<BANKVER5*>(reinterpret_cast<char*>(pmb) + pmb->sfxbankoffset));
        if (sfxrc < 0) {
            rc = sfxrc;
            goto fail;
        }
    }
    if (pmb->midibankoffset != 0) {
        midirc = fn_803A82A8(&pmb->midibhandle, reinterpret_cast<BANKVER5*>(reinterpret_cast<char*>(pmb) + pmb->midibankoffset));
        if (midirc < 0) {
            rc = midirc;
            goto fail;
        }
        rc = midirc;
    }
    {
        int basesize;
        int midisize;
        rc = pmb->residentsize;
        if (sfxrc == 7) {
            rc += SNDbankheadersize(pmb->sfxbhandle);
        } else {
            rc += pmb->sfxbanksizepadded;
        }
        if (midirc == 7) {
            midisize = SNDbankheadersize(pmb->midibhandle);
        } else {
            midisize = pmb->midibanksizepadded;
        }
        basesize = rc;
        rc = reinterpret_cast<int>(alloc(pmb, basesize + midisize, pmb->totalsize));
        if (rc == 0) {
            rc = -6;
            goto fail;
        }
        if (rc != reinterpret_cast<int>(pmb)) {
            pnew = reinterpret_cast<AemsDef::ModuleBank*>(rc);
            Snd::Util::MemCpy(pnew, pmb, pmb->residentsize);
            if (sfxrc != 0) {
                SNDbankheadercopy(reinterpret_cast<char*>(pnew) + pnew->residentsize, pnew->sfxbhandle);
            }
        }
        if (midirc > 0) {
            if (rc != reinterpret_cast<int>(pmb) || sfxrc == 7) {
                SNDbankheadercopy(reinterpret_cast<char*>(rc) + basesize, pnew->midibhandle);
            }
        }
        SNDAEMSI_resolvemodulebank(pnew, reinterpret_cast<AemsDef::FUNCFIXUPHEADER*>(reinterpret_cast<char*>(pmb) + pnew->funcfixupoffset), streamfilename, streamfileoffset);
        return pnew->modulebankhandle;
    }
fail:
    if (sfxrc > 0) {
        fn_803A8648(pmb->sfxbhandle);
    }
    if (midirc > 0) {
        fn_803A8648(pmb->midibhandle);
    }
    return rc;
}

void fn_803A6D1C(int a, int b)
{
    if (b != 0xFFFF) {
        return;
    }
    if (a == 0) {
        return;
    }
    sndaems.timerclient = CListDStack();
    sndaems.modulebank = CListDStack();
    sndaems.allocatedstreams = CListDStack();
    sndaems.freestreams = CListDStack();
}

void fn_803A6D54()
{
    fn_803A6D1C(1, 0xFFFF);
}

}
