#ifndef EALIB_GX_FIFO_H
#define EALIB_GX_FIFO_H

/* GX FIFO is at 0xCC008000. The address is represented relative to the
 * 0xCC010000 base so PPC emits a signed -0x8000
 * displacement from lis 0xCC01, as in retail. Register must be complete. */
template<class Register> inline volatile Register* GXRegisterPageEnd() {
    return (volatile Register*)0xCC010000u;
}
#define EALIB_GX_FIFO(Register) \
    (GXRegisterPageEnd<Register>()[-0x8000 / (int)sizeof(Register)])

#endif
