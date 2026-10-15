// Password hashing for the first-run setup (E5b): scrypt (RFC 7914) through
// Node's crypto.scrypt. The site password is never stored, only this record.
//
// Parameters (OWASP's first scrypt recommendation, 2024; docs/engine/NETPLAY.md):
//   N = 2^17 (CPU/memory cost), r = 8 (block size), p = 1 (parallelism):
//   about 128 MiB of memory and 0.2 s per hash on a current x86 core;
//   a random 32-byte salt per password; a 64-byte derived key.
// Each record carries its own parameters, so raising the cost later keeps old
// records verifiable. Records are validated when they are read (a state file
// edited into an absurd cost is refused rather than run).
import { randomBytes, scrypt, timingSafeEqual } from 'node:crypto';

export interface ScryptParams {
  N: number;
  r: number;
  p: number;
  keylen: number;
}

export const SCRYPT_PARAMS: ScryptParams = { N: 1 << 17, r: 8, p: 1, keylen: 64 };
export const SALT_BYTES = 32;

/** What the state file holds in place of the password. */
export interface StoredPassword extends ScryptParams {
  kdf: 'scrypt';
  /** base64 */
  salt: string;
  /** base64, `keylen` bytes */
  hash: string;
}

/** The shortest and longest new password, in characters (code points). */
export const MIN_PASSWORD_LENGTH = 12;
export const MAX_PASSWORD_LENGTH = 128;

/** NFKC, so the same password typed on another keyboard or device hashes the same. */
export function normalizePassword(password: string): string {
  return password.normalize('NFKC');
}

/** The password's length in characters (code points of the normalized form). */
export function passwordLength(password: string): number {
  return [...normalizePassword(password)].length;
}

function derive(password: string, salt: Buffer, prm: ScryptParams): Promise<Buffer> {
  return new Promise((resolve, reject) => {
    scrypt(
      Buffer.from(normalizePassword(password), 'utf8'),
      salt,
      prm.keylen,
      // scrypt needs 128 * r * (N + p + 2) bytes; Node's default limit (32 MiB) is below our N.
      { N: prm.N, r: prm.r, p: prm.p, maxmem: 128 * prm.r * (prm.N + prm.p + 2) + (1 << 20) },
      (err, key) => (err ? reject(err) : resolve(key)),
    );
  });
}

export async function hashPassword(password: string): Promise<StoredPassword> {
  const salt = randomBytes(SALT_BYTES);
  const key = await derive(password, salt, SCRYPT_PARAMS);
  return { kdf: 'scrypt', ...SCRYPT_PARAMS, salt: salt.toString('base64'), hash: key.toString('base64') };
}

/** Compares a candidate with a stored record in constant time. */
export async function verifyPassword(candidate: string, stored: StoredPassword): Promise<boolean> {
  const key = await derive(candidate, Buffer.from(stored.salt, 'base64'), stored);
  const want = Buffer.from(stored.hash, 'base64');
  return key.length === want.length && timingSafeEqual(key, want);
}

/** Checks a record read from the state file; throws a readable error when it is unusable. */
export function parseStoredPassword(x: unknown): StoredPassword {
  const bad = (why: string): never => {
    throw new Error(`stored password record is invalid (${why})`);
  };
  if (typeof x !== 'object' || x === null) return bad('not an object');
  const o = x as Record<string, unknown>;
  if (o.kdf !== 'scrypt') return bad('kdf is not scrypt');
  const int = (k: string, lo: number, hi: number): number => {
    const v = o[k];
    if (typeof v !== 'number' || !Number.isInteger(v) || v < lo || v > hi) return bad(`${k} out of range`);
    return v;
  };
  const N = int('N', 1 << 14, 1 << 20);
  const r = int('r', 1, 16);
  const p = int('p', 1, 4);
  const keylen = int('keylen', 32, 128);
  if ((N & (N - 1)) !== 0) bad('N is not a power of two');
  if (128 * N * r > 256 * 1024 * 1024) bad('memory cost above 256 MiB');
  const b64 = (k: string, min: number, max: number): string => {
    const v = o[k];
    if (typeof v !== 'string' || !/^[A-Za-z0-9+/]+={0,2}$/.test(v)) return bad(`${k} is not base64`);
    const n = Buffer.from(v, 'base64').length;
    if (n < min || n > max) return bad(`${k} has the wrong length`);
    return v;
  };
  const salt = b64('salt', 16, 64);
  const hash = b64('hash', keylen, keylen);
  return { kdf: 'scrypt', N, r, p, keylen, salt, hash };
}
