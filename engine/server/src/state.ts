// The server's state file (E5b): a small JSON file the server owns. It records
// when the server first started without a password (the start of the setup
// window) and, once the owner has chosen one, the password's scrypt record.
//
//   {
//     "version": 1,
//     "setupOpenedAt": 1760400000000,        // ms since the epoch
//     "password": {                          // absent until setup is done
//       "kdf": "scrypt", "N": 131072, "r": 8, "p": 1, "keylen": 64,
//       "salt": "<base64>", "hash": "<base64>", "setAt": 1760400123456
//     }
//   }
//
// Written atomically (a temporary file in the same directory, fsync, rename),
// created with mode 0600 and its directory with 0700 where the OS supports
// modes (on Windows the user profile's own ACLs apply). The password itself
// never reaches this file, only the salted hash.
import { randomBytes } from 'node:crypto';
import {
  chmodSync,
  closeSync,
  fsyncSync,
  mkdirSync,
  openSync,
  readFileSync,
  renameSync,
  unlinkSync,
  writeSync,
} from 'node:fs';
import { dirname } from 'node:path';

import { parseStoredPassword, type StoredPassword } from './password.js';

export interface StateFile {
  version: 1;
  /** When the server first started without a password (ms since the epoch). */
  setupOpenedAt: number;
  password?: StoredPassword & { setAt: number };
}

export class StateFileError extends Error {}

/** Reads the file; null when it does not exist. Throws StateFileError when it exists but is unusable. */
export function readState(path: string): StateFile | null {
  let text: string;
  try {
    text = readFileSync(path, 'utf8');
  } catch (e) {
    if ((e as NodeJS.ErrnoException).code === 'ENOENT') return null;
    throw new StateFileError(`cannot read the state file ${path}: ${(e as Error).message}`);
  }
  try {
    const o = JSON.parse(text) as Record<string, unknown>;
    if (typeof o !== 'object' || o === null || o.version !== 1) throw new Error('unknown version');
    if (typeof o.setupOpenedAt !== 'number' || !Number.isFinite(o.setupOpenedAt)) throw new Error('setupOpenedAt is not a time');
    const out: StateFile = { version: 1, setupOpenedAt: o.setupOpenedAt };
    if (o.password !== undefined) {
      const rec = o.password as Record<string, unknown>;
      if (typeof rec.setAt !== 'number' || !Number.isFinite(rec.setAt)) throw new Error('password.setAt is not a time');
      out.password = { ...parseStoredPassword(rec), setAt: rec.setAt };
    }
    return out;
  } catch (e) {
    // Never fall back to "no password" on a damaged file: that would reopen setup.
    throw new StateFileError(
      `the state file ${path} is unusable (${(e as Error).message}); fix it, or delete it and restart to reopen setup`,
    );
  }
}

/** Replaces the file atomically; creates its directory (0700) and the file (0600) when needed. */
export function writeState(path: string, state: StateFile): void {
  mkdirSync(dirname(path), { recursive: true, mode: 0o700 });
  const tmp = `${path}.${randomBytes(6).toString('hex')}.tmp`;
  const fd = openSync(tmp, 'wx', 0o600);
  try {
    try {
      writeSync(fd, `${JSON.stringify(state, null, 2)}\n`);
      fsyncSync(fd);
    } finally {
      closeSync(fd);
    }
    try {
      chmodSync(tmp, 0o600);
    } catch {
      // no modes on this OS or file system
    }
    renameSync(tmp, path);
  } catch (e) {
    try {
      unlinkSync(tmp);
    } catch {
      // already gone
    }
    throw e;
  }
  try {
    const dfd = openSync(dirname(path), 'r');  // make the rename durable (POSIX); Windows cannot open a directory
    try {
      fsyncSync(dfd);
    } finally {
      closeSync(dfd);
    }
  } catch {
    // not supported here
  }
}

/**
 * The state at server start. A missing file is created now: its `setupOpenedAt`
 * is the start of the setup window, and later restarts do not move it.
 */
export function loadState(path: string, now: number): StateFile {
  const st = readState(path);
  if (!st) {
    const fresh: StateFile = { version: 1, setupOpenedAt: now };
    writeState(path, fresh);
    return fresh;
  }
  if (!st.password && st.setupOpenedAt > now) {
    // The clock was set back since the window opened: restart the window now rather than let a future time extend it.
    st.setupOpenedAt = now;
    writeState(path, st);
  }
  return st;
}
