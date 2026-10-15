// The disc identity check on the server (deploy): an uploaded image is kept only
// if it is MVP Baseball 2005 for GameCube, USA (GV4E69), revision 0, by the
// SHA-1 of its main.dol, the same check the engine runs in the browser
// (engine/vfs: source.cpp for CISO, gcm.cpp for the disc header and the FST,
// dol.cpp for main.dol, disc_check.cpp for the identity; tools/recon/gcdisc.py
// is the same reader in Python).
//
// It reads through an asynchronous Reader, so it also runs on an upload that is
// still arriving: a read past what has arrived throws NotYet, and the check is
// tried again after the next chunk. An image that cannot be the game throws
// DiscRejected with the reason, as soon as the bytes that show it are there.
import { createHash } from 'node:crypto';

/** A whole GameCube disc (GCM): the largest ISO there is, and a CISO's smallest logical size. */
export const GAMECUBE_DISC_SIZE = 1_459_978_240;
const CISO_HEADER = 0x8000;
const DISC_MAGIC = 0xc2339f3d;  // at 0x1C
const BOOT_SIZE = 0x440;
const DOL_HEADER = 0x100;
const FST_MAX = 16 << 20;
const DOL_MAX = 32 << 20;
/**
 * Bytes a CISO may carry after its last stored block. Some tools append a short
 * footer (the owner's image has 576 bytes); anything longer is refused, so an
 * upload cannot carry another file behind the game.
 */
export const CISO_TRAILER_MAX = 64 * 1024;

export interface ExpectedDisc {
  gameId: string;
  revision: number;
  /** SHA-1 of main.dol, lowercase hex. */
  dolSha1: string;
}

/** The one disc the engine runs (engine/vfs/dol.h kRetailDolSha1, config/GV4E69/build.sha1). */
export const RETAIL_DISC: ExpectedDisc = {
  gameId: 'GV4E69',
  revision: 0,
  dolSha1: 'da6becdbea614d03c4b5eae9f8a0fb08e0a184dd',
};

/** Random access to an image file of `size` bytes. `read` returns exactly `length` bytes. */
export interface Reader {
  readonly size: number;
  read(offset: number, length: number): Promise<Buffer>;
}

/** The check needs bytes of an upload that have not arrived yet. */
export class NotYet extends Error {}
/** The image is not the expected disc (the message says why, without echoing its contents). */
export class DiscRejected extends Error {}

export interface DiscInfo {
  format: 'ciso' | 'iso';
  /** The file's size in bytes. */
  fileSize: number;
  gameId: string;
  revision: number;
  dolSha1: string;
  dolSize: number;
}

const be32 = (b: Buffer, at: number) => b.readUInt32BE(at);

/** Six printable characters of a game id, or its hex when it is not printable (never raw bytes in a message). */
function showId(b: Buffer): string {
  const s = b.toString('latin1');
  return /^[A-Za-z0-9]{6}$/.test(s) ? s : `0x${b.toString('hex')}`;
}

/** The logical disc behind a CISO container (block map in the 0x8000-byte header; unstored blocks read as zero). */
async function openCiso(file: Reader): Promise<Reader> {
  if (file.size < CISO_HEADER) throw new DiscRejected('CISO: file shorter than its header');
  const h = await file.read(0, CISO_HEADER);
  const bs = h.readUInt32LE(4);
  if (bs === 0 || (bs & (bs - 1)) !== 0) throw new DiscRejected('CISO: block size is not a power of two');
  const nblocks = CISO_HEADER - 8;
  const where = new Array<number>(nblocks).fill(-1);
  let next = CISO_HEADER;
  let lastUsed = 0;
  for (let i = 0; i < nblocks; ++i) {
    const m = h[8 + i]!;
    if (m > 1) throw new DiscRejected('CISO: bad block map entry');
    if (m === 1) {
      where[i] = next;
      next += bs;
      lastUsed = i + 1;
    }
  }
  if (next > file.size) throw new DiscRejected(`CISO: the stored blocks need ${next} bytes, the file has ${file.size}`);
  if (file.size - next > CISO_TRAILER_MAX)
    throw new DiscRejected(`CISO: ${file.size - next} bytes after the last stored block (at most ${CISO_TRAILER_MAX})`);
  // As engine/vfs/source.cpp: at least a whole disc and every stored block, within what the map addresses.
  const logical = Math.min(Math.max(lastUsed * bs, GAMECUBE_DISC_SIZE), nblocks * bs);
  return {
    size: logical,
    async read(offset, length) {
      if (offset < 0 || length < 0 || offset + length > logical) throw new DiscRejected('read outside the disc');
      const out = Buffer.alloc(length);
      let done = 0;
      while (done < length) {
        const off = offset + done;
        const blk = Math.floor(off / bs);
        const bo = off % bs;
        const take = Math.min(bs - bo, length - done);
        const at = where[blk]!;
        if (at >= 0) (await file.read(at + bo, take)).copy(out, done);
        done += take;
      }
      return out;
    },
  };
}

/** Size of main.dol from its header: the furthest section end (engine/vfs/dol.cpp size_from_header). */
function dolSize(h: Buffer): number {
  let end = DOL_HEADER;
  for (let i = 0; i < 18; ++i) {
    const off = be32(h, 4 * i);
    const size = be32(h, 0x90 + 4 * i);
    if (size) end = Math.max(end, off + size);
  }
  return end;
}

/** The DOL's sections must lie inside the file and not overlap once loaded (engine/vfs/dol.cpp Dol::parse). */
function checkDol(dol: Buffer): void {
  const loaded: [number, number][] = [];
  for (let i = 0; i < 18; ++i) {
    const off = be32(dol, 4 * i), addr = be32(dol, 0x48 + 4 * i), size = be32(dol, 0x90 + 4 * i);
    if (!size) continue;
    if (off < DOL_HEADER || off + size > dol.length) throw new DiscRejected(`DOL: section ${i} outside the file`);
    if (addr + size > 0x1_0000_0000) throw new DiscRejected('DOL: section address wraps');
    loaded.push([addr, size]);
  }
  loaded.sort((a, b) => a[0] - b[0]);
  for (let i = 1; i < loaded.length; ++i)
    if (loaded[i - 1]![0] + loaded[i - 1]![1] > loaded[i]![0]) throw new DiscRejected('DOL: sections overlap');
}

/** Walks the FST the way engine/vfs/gcm.cpp does: every name inside the string table, every file inside the disc. */
function checkFst(f: Buffer, discSize: number): void {
  const count = be32(f, 8);
  if (f[0] !== 1 || count === 0 || count * 12 > f.length) throw new DiscRejected('GCM: bad FST root');
  const strBase = count * 12;
  const stack: number[] = [count];
  for (let i = 1; i < count; ++i) {
    while (stack.length > 1 && i >= stack[stack.length - 1]!) stack.pop();
    const p = strBase + (be32(f, i * 12) & 0xffffff);
    if (p >= f.length || f.indexOf(0, p) < 0) throw new DiscRejected('GCM: FST name outside the string table');
    const type = f[i * 12]!;
    const a = be32(f, i * 12 + 4), b = be32(f, i * 12 + 8);
    if (type === 1) {
      if (b <= i || b > count) throw new DiscRejected('GCM: bad directory end index');
      stack.push(b);
    } else {
      if (type !== 0) throw new DiscRejected('GCM: bad FST entry type');
      if (a + b > discSize) throw new DiscRejected('GCM: a file lies outside the disc');
    }
  }
}

/**
 * Checks that `file` (a CISO or a plain GCM/ISO image) is the expected disc and
 * describes it. Throws DiscRejected with the reason, or NotYet when `file` is a
 * partial upload that does not hold the needed bytes yet.
 */
export async function identifyDisc(file: Reader, expect: ExpectedDisc): Promise<DiscInfo> {
  if (file.size < 4) throw new DiscRejected('the file is too small to be a disc image');
  const isCiso = (await file.read(0, 4)).toString('latin1') === 'CISO';
  if (!isCiso && file.size > GAMECUBE_DISC_SIZE)
    throw new DiscRejected(`the file is larger than a GameCube disc (${file.size} > ${GAMECUBE_DISC_SIZE} bytes)`);
  const disc = isCiso ? await openCiso(file) : file;
  if (disc.size < BOOT_SIZE) throw new DiscRejected('GCM: disc header read failed');
  const boot = await disc.read(0, BOOT_SIZE);
  if (be32(boot, 0x1c) !== DISC_MAGIC) throw new DiscRejected('GCM: bad disc magic at 0x1C');
  const gameId = showId(boot.subarray(0, 6));
  const revision = boot[7]!;
  if (gameId !== expect.gameId) throw new DiscRejected(`not ${expect.gameId}: game id ${gameId}`);
  if (revision !== expect.revision) throw new DiscRejected(`not revision ${expect.revision} (revision ${revision})`);

  const dolOff = be32(boot, 0x420), fstOff = be32(boot, 0x424), fstSize = be32(boot, 0x428);
  if (fstSize < 12 || fstSize > FST_MAX) throw new DiscRejected('GCM: bad FST size');
  if (fstOff + fstSize > disc.size) throw new DiscRejected('GCM: FST outside the disc');
  checkFst(await disc.read(fstOff, fstSize), disc.size);

  if (dolOff + DOL_HEADER > disc.size) throw new DiscRejected('DOL header outside the disc');
  const size = dolSize(await disc.read(dolOff, DOL_HEADER));
  if (size > DOL_MAX || dolOff + size > disc.size) throw new DiscRejected('DOL body outside the disc');
  const dol = await disc.read(dolOff, size);
  const sha = createHash('sha1').update(dol).digest('hex');
  if (sha !== expect.dolSha1) throw new DiscRejected(`main.dol SHA-1 ${sha} is not ${expect.gameId} rev ${expect.revision}`);
  checkDol(dol);
  return { format: isCiso ? 'ciso' : 'iso', fileSize: file.size, gameId, revision, dolSha1: sha, dolSize: size };
}
