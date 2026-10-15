// The password gate (E5): one shared password (from the environment, or the hash
// chosen at first-run setup: src/setup.ts), a login form, and an HTTP-only
// session cookie. Sessions live in memory (a restart logs everyone out). Failed
// logins are limited per client address.
import { createHash, randomBytes, timingSafeEqual } from 'node:crypto';
import type { IncomingMessage } from 'node:http';

export const COOKIE = 'mvp_session';

export class Sessions {
  private readonly tokens = new Map<string, number>();  // token -> expiry (ms)
  constructor(private readonly hours: number, private readonly now: () => number = Date.now) {}

  create(): string {
    const token = randomBytes(32).toString('base64url');
    this.tokens.set(token, this.now() + this.hours * 3600_000);
    return token;
  }
  valid(token: string | undefined): boolean {
    if (!token) return false;
    const exp = this.tokens.get(token);
    if (exp === undefined) return false;
    if (exp <= this.now()) {
      this.tokens.delete(token);
      return false;
    }
    return true;
  }
  remove(token: string | undefined): void {
    if (token) this.tokens.delete(token);
  }
  get size(): number {
    return this.tokens.size;
  }
}

/** Compares a candidate password with the configured one in constant time. */
export function passwordMatches(candidate: string, password: string): boolean {
  const a = createHash('sha256').update(candidate, 'utf8').digest();
  const b = createHash('sha256').update(password, 'utf8').digest();
  return timingSafeEqual(a, b);
}

/** Failed logins per client address, in a sliding 15-minute window. */
export class LoginLimiter {
  private readonly failures = new Map<string, number[]>();
  constructor(private readonly max: number, private readonly now: () => number = Date.now) {}
  private recent(addr: string): number[] {
    const cutoff = this.now() - 15 * 60_000;
    const list = (this.failures.get(addr) ?? []).filter((t) => t > cutoff);
    if (list.length) this.failures.set(addr, list);
    else this.failures.delete(addr);
    return list;
  }
  blocked(addr: string): boolean {
    return this.recent(addr).length >= this.max;
  }
  fail(addr: string): void {
    const list = this.recent(addr);
    list.push(this.now());
    this.failures.set(addr, list);
  }
  succeed(addr: string): void {
    this.failures.delete(addr);
  }
}

export function parseCookies(header: string | undefined): Map<string, string> {
  const out = new Map<string, string>();
  for (const part of (header ?? '').split(';')) {
    const eq = part.indexOf('=');
    if (eq < 0) continue;
    const k = part.slice(0, eq).trim();
    if (k && !out.has(k)) out.set(k, part.slice(eq + 1).trim());
  }
  return out;
}

export function sessionCookie(token: string, hours: number, secure: boolean): string {
  return `${COOKIE}=${token}; Path=/; HttpOnly; SameSite=Lax; Max-Age=${Math.floor(hours * 3600)}${secure ? '; Secure' : ''}`;
}

export function clearCookie(secure: boolean): string {
  return `${COOKIE}=; Path=/; HttpOnly; SameSite=Lax; Max-Age=0${secure ? '; Secure' : ''}`;
}

/** The client address: the socket's, or the proxy's last X-Forwarded-For entry. */
export function clientAddress(req: IncomingMessage, trustProxy: boolean): string {
  if (trustProxy) {
    const xff = req.headers['x-forwarded-for'];
    const v = Array.isArray(xff) ? xff[xff.length - 1] : xff;
    if (v) {
      const parts = v.split(',').map((s) => s.trim()).filter(Boolean);
      if (parts.length) return parts[parts.length - 1]!;
    }
  }
  return req.socket.remoteAddress ?? '?';
}

/** A local path to return to after the login ("/?room=x"), or "/" for anything else. */
export function safeNext(next: string | null | undefined): string {
  if (!next || !next.startsWith('/') || next.startsWith('//') || next.startsWith('/\\')) return '/';
  if (/[\r\n]/.test(next)) return '/';
  return next;
}

/** Whether a request is a page load (gets the login form) rather than an API call (gets 401). */
export function isNavigation(req: IncomingMessage): boolean {
  const mode = req.headers['sec-fetch-mode'];
  if (mode) return mode === 'navigate';
  return req.method === 'GET' && (req.headers.accept ?? '').includes('text/html');
}

export const LOGIN_CSS = `body{font:16px system-ui,sans-serif;background:#10141a;color:#e8ecf1;display:grid;place-items:center;min-height:100vh;margin:0}
form{background:#1b222c;padding:24px 28px;border-radius:10px;display:grid;gap:12px;min-width:260px}
h1{font-size:18px;margin:0 0 4px}input,button{font:inherit;padding:8px 10px;border-radius:6px;border:1px solid #3a4553;background:#0f1319;color:inherit}
button{background:#2f6fde;border-color:#2f6fde;cursor:pointer}.err{color:#ff8a80;margin:0}`;
export const LOGIN_CSS_HASH = `'sha256-${createHash('sha256').update(LOGIN_CSS).digest('base64')}'`;

export function escapeHtml(s: string): string {
  return s.replace(/[&<>"']/g, (c) => `&#${c.charCodeAt(0)};`);
}

export function loginPage(next: string, error: string): string {
  return `<!doctype html><html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>MVP Baseball 2005</title><link rel="icon" href="data:,"><style>${LOGIN_CSS}</style></head><body>
<form method="post" action="/login"><h1>MVP Baseball 2005</h1>
${error ? `<p class="err">${escapeHtml(error)}</p>` : ''}
<label>Password <input type="password" name="password" autocomplete="current-password" autofocus required></label>
<input type="hidden" name="next" value="${escapeHtml(next)}">
<button type="submit">Enter</button></form></body></html>`;
}
