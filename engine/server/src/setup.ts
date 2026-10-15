// First-run password setup (E5b). The agents never handle the site password,
// so a server started without one waits for the owner to choose it in the
// browser (docs/engine/NETPLAY.md, "First-run password setup").
//
// Where the password comes from, in order:
//   1. MVP_PASSWORD / MVP_PASSWORD_FILE (the environment; tests and CI): wins,
//      first-run setup is off and the state file is not touched ("env");
//   2. the scrypt record in the state file ("stored");
//   3. neither: "setup" mode for `setupHours` after the server first started
//      without a password (the window is kept in the state file, so restarts do
//      not extend it), then "closed" until an operator deletes the state file.
//
// Resetting without a shell (the Docker deployment): MVP_RESET_PASSWORD set to a
// value the server has not seen before removes the stored password at start and
// opens a fresh setup window, once; the state file keeps the value's SHA-256, so
// later restarts with the same value change nothing.
import { createHash, createHmac, randomBytes, timingSafeEqual } from 'node:crypto';

import { LOGIN_CSS, escapeHtml, passwordMatches } from './auth.js';
import {
  MAX_PASSWORD_LENGTH,
  MIN_PASSWORD_LENGTH,
  hashPassword,
  passwordLength,
  verifyPassword,
  type StoredPassword,
} from './password.js';
import { loadState, writeState, type StateFile } from './state.js';

export type PasswordMode = 'env' | 'stored' | 'setup' | 'closed';

// ---- limits ----

/** Setup endpoint limits, per sliding 15-minute window. A refused request is not counted. */
export const SETUP_LIMITS = {
  windowMs: 15 * 60_000,
  /** Every request to /setup (GET or POST) from one address. */
  requestsPerAddress: 30,
  /** Form submissions (POST) from one address. */
  submissionsPerAddress: 10,
  /** Form submissions from all addresses together (each valid one costs a scrypt run). */
  submissionsGlobal: 100,
};

/** At most `max` hits per key within `windowMs`. */
export class HitLimiter {
  private readonly hits = new Map<string, number[]>();
  constructor(
    private readonly max: number,
    private readonly windowMs: number,
    private readonly now: () => number = Date.now,
  ) {}

  /** Counts a hit; false (and no count) when the key has used its quota. */
  allow(key: string): boolean {
    const t = this.now();
    const cutoff = t - this.windowMs;
    if (this.hits.size > 4096) {
      for (const [k, list] of this.hits) if (!list.some((x) => x > cutoff)) this.hits.delete(k);
    }
    const list = (this.hits.get(key) ?? []).filter((x) => x > cutoff);
    if (list.length >= this.max) {
      this.hits.set(key, list);
      return false;
    }
    list.push(t);
    this.hits.set(key, list);
    return true;
  }
}

/** Runs scrypt jobs one at a time (each needs 128 MiB); a full queue is refused instead of piling up. */
export const BUSY = Symbol('busy');
export class KdfQueue {
  private running = 0;
  private readonly waiting: (() => void)[] = [];
  constructor(
    private readonly concurrency = 1,
    private readonly maxWaiting = 8,
  ) {}

  async run<T>(job: () => Promise<T>): Promise<T | typeof BUSY> {
    if (this.running >= this.concurrency) {
      if (this.waiting.length >= this.maxWaiting) return BUSY;
      await new Promise<void>((resolve) => this.waiting.push(resolve));  // the finishing job hands its slot over
    } else {
      this.running++;
    }
    try {
      return await job();
    } finally {
      const next = this.waiting.shift();
      if (next) next();
      else this.running--;
    }
  }
}

// ---- CSRF ----

export const SETUP_COOKIE = 'mvp_setup';
const SETUP_TOKEN_TTL_MS = 30 * 60_000;

/**
 * CSRF tokens for the setup form: bound to a random id kept in an HttpOnly
 * SameSite=Strict cookie, so a page on another site can neither read a token
 * nor make the owner's browser send one that matches. Stateless: the token is
 * `<expiry>.<HMAC-SHA256(per-process key, id.expiry)>`.
 */
export class CsrfTokens {
  private readonly key = randomBytes(32);
  constructor(private readonly now: () => number = Date.now) {}

  newId(): string {
    return randomBytes(24).toString('base64url');
  }
  static validId(id: string | undefined): id is string {
    return id !== undefined && /^[A-Za-z0-9_-]{32}$/.test(id);
  }
  issue(id: string): string {
    const exp = this.now() + SETUP_TOKEN_TTL_MS;
    return `${exp}.${this.mac(id, exp)}`;
  }
  verify(id: string | undefined, token: string | null): boolean {
    if (!CsrfTokens.validId(id) || !token) return false;
    const m = /^(\d{1,16})\.([A-Za-z0-9_-]{43})$/.exec(token);
    if (!m) return false;
    const exp = Number(m[1]);
    if (!(exp > this.now())) return false;
    const want = Buffer.from(this.mac(id, exp));
    const got = Buffer.from(m[2]!);
    return want.length === got.length && timingSafeEqual(want, got);
  }
  private mac(id: string, exp: number): string {
    return createHmac('sha256', this.key).update(`${id}.${exp}`).digest('base64url');
  }
}

export function setupCookie(id: string, secure: boolean): string {
  return `${SETUP_COOKIE}=${id}; Path=/setup; HttpOnly; SameSite=Strict; Max-Age=${SETUP_TOKEN_TTL_MS / 1000}${secure ? '; Secure' : ''}`;
}
export function clearSetupCookie(secure: boolean): string {
  return `${SETUP_COOKIE}=; Path=/setup; HttpOnly; SameSite=Strict; Max-Age=0${secure ? '; Secure' : ''}`;
}

// ---- the new password ----

/** The reason a new password is refused, or null when it is acceptable. Never repeats the password. */
export function checkNewPassword(password: string, confirm: string): string | null {
  if (password !== confirm) return 'The two passwords do not match.';
  const n = passwordLength(password);
  if (n < MIN_PASSWORD_LENGTH) return `The password is too short: ${n} characters, at least ${MIN_PASSWORD_LENGTH} are needed.`;
  if (n > MAX_PASSWORD_LENGTH) return `The password is too long: at most ${MAX_PASSWORD_LENGTH} characters.`;
  return null;
}

// ---- the gate ----

export interface GateOptions {
  /** MVP_PASSWORD(_FILE): the plaintext password from the environment, or ''. */
  envPassword: string;
  stateFile: string;
  /** How long setup stays open after the server first started without a password. */
  windowMs: number;
  /** MVP_RESET_PASSWORD: a value not seen before reopens setup once (see above); '' does nothing. */
  resetRequest?: string;
  now: () => number;
  log: (message: string) => void;
}

export type ClaimResult = 'ok' | 'closed' | 'done' | 'busy';

/** Where the password comes from, whether setup is open, and checking logins against it. */
export class PasswordGate {
  private stored: (StoredPassword & { setAt: number }) | null = null;
  private openedAt = 0;
  private claiming = false;
  private closedLogged = false;
  private resetToken: string | undefined;
  private readonly kdf = new KdfQueue();

  constructor(private readonly o: GateOptions) {
    if (o.envPassword) return;  // first-run setup is off and the state file is not touched
    let st = loadState(o.stateFile, o.now());
    if (o.resetRequest) {
      const token = createHash('sha256').update(o.resetRequest).digest('hex');
      if (token !== st.resetToken) {
        st = { version: 1, setupOpenedAt: o.now(), resetToken: token };
        writeState(o.stateFile, st);
        o.log('password: reset by a new MVP_RESET_PASSWORD value; the stored password is gone and setup is open again');
      }
    }
    this.resetToken = st.resetToken;
    this.openedAt = st.setupOpenedAt;
    this.stored = st.password ?? null;
    if (this.stored) {
      o.log(`password: stored hash from ${o.stateFile}; /setup is closed`);
    } else if (this.mode === 'setup') {
      o.log(
        `no password configured: SETUP MODE. Open the site in a browser to create the password; setup stays open until ` +
          `${new Date(this.windowEnd).toISOString()} (started ${new Date(this.openedAt).toISOString()})`,
      );
    } else {
      this.logClosed();
    }
  }

  get mode(): PasswordMode {
    if (this.o.envPassword) return 'env';
    if (this.stored) return 'stored';
    return this.o.now() < this.windowEnd ? 'setup' : 'closed';
  }
  /** Whether the site is waiting for a password (setup open or closed): nothing else is served. */
  get needsSetup(): boolean {
    const m = this.mode;
    return m === 'setup' || m === 'closed';
  }
  get windowEnd(): number {
    return this.openedAt + this.o.windowMs;
  }

  /** Logs, once, that the window has closed and the server needs an operator. */
  logClosed(): void {
    if (this.closedLogged) return;
    this.closedLogged = true;
    this.o.log(
      `setup window closed at ${new Date(this.windowEnd).toISOString()}: the server has no password and needs an operator. ` +
        `Stop the service, delete ${this.o.stateFile}, and start it again to reopen setup (docs/engine/NETPLAY.md)`,
    );
  }

  /** Checks a login. 'busy' when too many password checks are already queued. */
  async verify(candidate: string): Promise<boolean | 'busy'> {
    if (this.o.envPassword) return passwordMatches(candidate, this.o.envPassword);
    const stored = this.stored;
    if (!stored) return false;
    const r = await this.kdf.run(() => verifyPassword(candidate, stored));
    return r === BUSY ? 'busy' : r;
  }

  /**
   * Stores the owner's new password (already checked with checkNewPassword) and
   * leaves setup mode. 'closed': the window ended; 'done': a password exists;
   * 'busy': another submission is being processed. Throws when the state file
   * cannot be written (setup mode stays open then).
   */
  async claim(password: string): Promise<ClaimResult> {
    const before = this.mode;
    if (before === 'closed') return 'closed';
    if (before !== 'setup') return 'done';
    if (this.claiming) return 'busy';
    this.claiming = true;
    try {
      const rec = await this.kdf.run(() => hashPassword(password));
      if (rec === BUSY) return 'busy';
      // The hash took a moment: look again before writing.
      const after: PasswordMode = this.mode;
      if (after === 'closed') return 'closed';
      if (after !== 'setup') return 'done';
      const next: StateFile = { version: 1, setupOpenedAt: this.openedAt, password: { ...rec, setAt: this.o.now() } };
      if (this.resetToken) next.resetToken = this.resetToken;
      writeState(this.o.stateFile, next);
      this.stored = next.password!;
      this.o.log(`setup: the site password was created (scrypt N=${rec.N} r=${rec.r} p=${rec.p}); setup is closed for good`);
      return 'ok';
    } finally {
      this.claiming = false;
    }
  }
}

// ---- pages ----

const SETUP_EXTRA_CSS = `
.card,form{max-width:420px;box-sizing:border-box}.card{background:#1b222c;padding:24px 28px;border-radius:10px;display:grid;gap:12px}
p{margin:0}.note,small{color:#9aa7b8;font-size:14px}label{display:grid;gap:4px}meter{width:100%}input{min-width:0}`;
export const SETUP_CSS = LOGIN_CSS + SETUP_EXTRA_CSS;

// A rough guide only: length first, penalizing repeated characters. The server enforces the length alone.
export const SETUP_SCRIPT = `(function () {
  var pw = document.getElementById('pw'), pw2 = document.getElementById('pw2');
  var meter = document.getElementById('meter'), hint = document.getElementById('hint'), same = document.getElementById('same');
  function rate(v) {
    var n = Array.from(v).length;
    if (n === 0) return [0, 'Use at least 12 characters.'];
    if (n < 12) return [1, 'Too short: ' + n + ' of 12 characters.'];
    var distinct = new Set(Array.from(v.toLowerCase())).size;
    var kinds = /[a-z]/.test(v) + /[A-Z]/.test(v) + /[0-9]/.test(v) + /[^A-Za-z0-9]/.test(v);
    var eff = Math.min(n, distinct * 3) + (kinds >= 3 ? 4 : 0);
    if (eff < 14) return [1, 'Weak: too repetitive or predictable.'];
    if (eff < 18) return [2, 'Fair: longer is better.'];
    if (eff < 24) return [3, 'Good.'];
    return [4, 'Strong.'];
  }
  function update() {
    var r = rate(pw.value);
    meter.value = r[0];
    hint.textContent = r[1] + ' (a rough guide)';
    same.textContent = pw2.value === '' ? '' : (pw2.value === pw.value ? 'The passwords match.' : 'The passwords do not match yet.');
  }
  pw.addEventListener('input', update);
  pw2.addEventListener('input', update);
  update();
})();`;

const sha = (s: string) => `'sha256-${createHash('sha256').update(s).digest('base64')}'`;
/** CSP of the setup form: its one style and its one script by hash, nothing else. */
export const SETUP_CSP =
  `default-src 'none'; style-src ${sha(SETUP_CSS)}; script-src ${sha(SETUP_SCRIPT)}; img-src data:; ` +
  `form-action 'self'; frame-ancestors 'none'; base-uri 'none'`;
/** CSP of the plain message pages (no script). */
export const MESSAGE_CSP = `default-src 'none'; style-src ${sha(SETUP_CSS)}; img-src data:; frame-ancestors 'none'; base-uri 'none'`;

const HEAD = (title: string) => `<!doctype html><html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<meta name="robots" content="noindex"><title>${escapeHtml(title)}</title><link rel="icon" href="data:,"><style>${SETUP_CSS}</style></head><body>`;

export function setupPage(csrf: string, error: string): string {
  return `${HEAD('MVP Baseball 2005 - create the password')}
<form method="post" action="/setup"><h1>MVP Baseball 2005</h1>
<p class="note">First run: this server has no password yet. Choose the one password everybody types to get in.
At least ${MIN_PASSWORD_LENGTH} characters; a few unrelated words make a strong one that is easy to type.</p>
${error ? `<p class="err" role="alert">${escapeHtml(error)}</p>` : ''}
<label>Password <input id="pw" type="password" name="password" autocomplete="new-password" minlength="${MIN_PASSWORD_LENGTH}" maxlength="${MAX_PASSWORD_LENGTH}" autofocus required></label>
<label>Confirm password <input id="pw2" type="password" name="confirm" autocomplete="new-password" minlength="${MIN_PASSWORD_LENGTH}" maxlength="${MAX_PASSWORD_LENGTH}" required></label>
<meter id="meter" min="0" max="4" low="2" high="3" optimum="4" value="0"></meter>
<small id="hint" aria-live="polite">Use at least ${MIN_PASSWORD_LENGTH} characters.</small><small id="same" aria-live="polite"></small>
<input type="hidden" name="csrf" value="${escapeHtml(csrf)}">
<button type="submit">Create the password</button></form>
<script>${SETUP_SCRIPT}</script></body></html>`;
}

export function messagePage(title: string, text: string): string {
  return `${HEAD(`MVP Baseball 2005 - ${title}`)}
<div class="card"><h1>${escapeHtml(title)}</h1><p>${escapeHtml(text)}</p></div></body></html>`;
}
