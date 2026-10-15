// The disc image's manifest (P1): what a player's browser needs to download the
// server's image once, check it, and keep it in its own storage, so the game
// reads the disc locally instead of over the network.
//
//   pieces  the SHA-256 of each PIECE_BYTES piece of the image file, in order (the
//           last piece may be shorter)
//   hash    the image hash: SHA-256 over the pieces' digests (32 bytes each, in
//           order). It names the image: any change to any byte changes it.
//
// /config.json advertises the hash and the size, /api/disc/manifest lists the
// pieces (src/server.ts). The page checks the list against the hash, then every
// piece as it arrives, with the browser's own SHA-256 (engine/web/src/disc-store.ts).
//
// Hashing a 1.4 GB image takes a few seconds, so the result is kept next to an
// uploaded image (<image>.manifest.json, keyed by its size and modification time)
// and in memory; it is computed again only when the image changes.
import { createHash, randomBytes } from 'node:crypto';
import { createReadStream, promises as fsp } from 'node:fs';

/** Bytes per piece: 8 MiB (a 1.38 GB image has 165 pieces). */
export const PIECE_BYTES = 8 << 20;

export interface DiscManifest {
  size: number;
  pieceBytes: number;
  /** SHA-256 of each piece, lowercase hex. */
  pieces: string[];
  /** SHA-256 over the pieces' digests, lowercase hex. */
  hash: string;
}

/** The image hash of a list of piece digests (hex). */
export function imageHash(pieces: string[]): string {
  const h = createHash('sha256');
  for (const p of pieces) h.update(Buffer.from(p, 'hex'));
  return h.digest('hex');
}

/** Reads the file once and hashes its pieces. */
export async function hashImage(path: string, pieceBytes = PIECE_BYTES): Promise<DiscManifest> {
  const pieces: string[] = [];
  let piece = createHash('sha256'), inPiece = 0, size = 0;
  for await (const chunk of createReadStream(path, { highWaterMark: 4 << 20 }) as AsyncIterable<Buffer>) {
    let at = 0;
    while (at < chunk.length) {
      const take = Math.min(chunk.length - at, pieceBytes - inPiece);
      piece.update(chunk.subarray(at, at + take));
      at += take;
      inPiece += take;
      if (inPiece === pieceBytes) {
        pieces.push(piece.digest('hex'));
        piece = createHash('sha256');
        inPiece = 0;
      }
    }
    size += chunk.length;
  }
  if (inPiece > 0 || size === 0) pieces.push(piece.digest('hex'));
  return { size, pieceBytes, pieces, hash: imageHash(pieces) };
}

const HEX64 = /^[0-9a-f]{64}$/;

/** A stored manifest, if it is well formed and describes a file of `size` bytes modified at `mtimeMs`. */
function parseStored(text: string, size: number, mtimeMs: number): DiscManifest | null {
  try {
    const m = JSON.parse(text) as Partial<DiscManifest> & { mtimeMs?: number };
    if (m.size !== size || m.mtimeMs !== Math.floor(mtimeMs) || m.pieceBytes !== PIECE_BYTES || !Array.isArray(m.pieces)) return null;
    if (m.pieces.length !== Math.max(1, Math.ceil(size / PIECE_BYTES)) || !m.pieces.every((p) => typeof p === 'string' && HEX64.test(p))) return null;
    if (m.hash !== imageHash(m.pieces)) return null;
    return { size, pieceBytes: PIECE_BYTES, pieces: m.pieces, hash: m.hash };
  } catch {
    return null;
  }
}

/**
 * The manifests of the images the server serves, computed in the background:
 * `get` answers at once with the manifest, 'pending' while it is being computed,
 * or null when the file cannot be hashed.
 */
export class ManifestCache {
  private readonly entries = new Map<string, { key: string; state: DiscManifest | 'pending' | null }>();

  constructor(private readonly log: (message: string) => void = () => {}) {}

  /**
   * The manifest of `path` as it is now. `sidecar`: where to keep it between
   * restarts (next to an uploaded image); without one it lives in memory only.
   */
  async get(path: string, sidecar?: string): Promise<DiscManifest | 'pending' | null> {
    let st;
    try {
      st = await fsp.stat(path);
    } catch {
      return null;
    }
    const key = `${st.size}-${Math.floor(st.mtimeMs)}`;
    const e = this.entries.get(path);
    if (e && e.key === key) return e.state;
    const entry: { key: string; state: DiscManifest | 'pending' | null } = { key, state: 'pending' };
    this.entries.set(path, entry);
    if (sidecar) {
      const stored = parseStored(await fsp.readFile(sidecar, 'utf8').catch(() => ''), st.size, st.mtimeMs);
      if (stored) {
        entry.state = stored;
        return stored;
      }
    }
    const t0 = Date.now();
    this.log(`disc: hashing the image for players' downloads (${st.size} bytes)`);
    void hashImage(path).then(
      async (m) => {
        if (this.entries.get(path) !== entry) return;  // replaced meanwhile
        if (sidecar) {
          const tmp = `${sidecar}.${randomBytes(4).toString('hex')}.tmp`;
          try {
            await fsp.writeFile(tmp, JSON.stringify({ ...m, mtimeMs: Math.floor(st.mtimeMs) }), { mode: 0o600 });
            await fsp.rename(tmp, sidecar);
          } catch (err) {
            await fsp.rm(tmp, { force: true }).catch(() => {});
            this.log(`disc: the image hash could not be stored (${(err as Error).message}); it is computed again at the next start`);
          }
        }
        if (this.entries.get(path) !== entry) return;
        entry.state = m;
        this.log(`disc: image hash ${m.hash.slice(0, 16)}... (${m.pieces.length} pieces, ${Date.now() - t0} ms)`);
      },
      (err: Error) => {
        if (this.entries.get(path) !== entry) return;
        entry.state = null;
        this.log(`disc: the image could not be hashed (${err.message}); players read it from the server instead`);
      },
    );
    return 'pending';
  }

  /** Waits until the manifest of `path` is computed (tests, and warming up at start). */
  async ready(path: string, sidecar?: string): Promise<DiscManifest | null> {
    for (;;) {
      const m = await this.get(path, sidecar);
      if (m !== 'pending') return m;
      await new Promise((r) => setTimeout(r, 20));
    }
  }
}
