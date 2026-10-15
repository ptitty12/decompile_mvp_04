// Tests for first-run password setup (E5b): setup mode, the form and its CSRF
// token, the window, the stored scrypt hash, the environment override and
// restarts. No game data; every state file lives in a temporary directory.
import assert from 'node:assert/strict';
import { existsSync, mkdirSync, mkdtempSync, readFileSync, readdirSync, rmSync, statSync, writeFileSync } from 'node:fs';
import { get as httpGet } from 'node:http';
import { tmpdir } from 'node:os';
import { join } from 'node:path';
import { after, before, describe, it } from 'node:test';
import WebSocket from 'ws';

import { defaults, loadConfig, type ServerConfig } from '../src/config.js';
import {
  SALT_BYTES,
  SCRYPT_PARAMS,
  hashPassword,
  normalizePassword,
  parseStoredPassword,
  passwordLength,
  verifyPassword,
} from '../src/password.js';
import { startServer, type App } from '../src/server.js';
import { BUSY, CsrfTokens, HitLimiter, KdfQueue, SETUP_LIMITS, checkNewPassword } from '../src/setup.js';
import { loadState, readState, writeState } from '../src/state.js';

const PASSWORD = 'violet-lantern-ripple-42';
const OTHER = 'copper-meadow-lighthouse-7';
const ENV_PASSWORD = 'from the environment';
const HOUR = 3600_000;

const dir = mkdtempSync(join(tmpdir(), 'mvp-setup-test-'));
const site = join(dir, 'site');
let counter = 0;
before(() => {
  mkdirSync(site, { recursive: true });
  writeFileSync(join(site, 'index.html'), '<!doctype html><title>engine</title>');
  writeFileSync(join(site, 'main.js'), 'console.log(1);');
});
after(() => rmSync(dir, { recursive: true, force: true }));

/** A fresh state file path (the file itself is created by the server). */
const newStateFile = () => join(dir, `state-${++counter}`, 'state.json');

function config(stateFile: string, over: Partial<ServerConfig> = {}): ServerConfig {
  return { ...defaults, site, password: '', port: 0, disc: '', stateFile, ...over };
}

class Clock {
  t = Date.now();
  readonly now = () => this.t;
}

interface Started {
  app: App;
  logs: string[];
}
const running: App[] = [];
async function start(stateFile: string, over: Partial<ServerConfig> = {}, clock?: Clock): Promise<Started> {
  const logs: string[] = [];
  const app = await startServer(config(stateFile, over), { now: clock?.now, log: (m) => logs.push(m) });
  running.push(app);
  return { app, logs };
}
async function stop(app: App): Promise<void> {
  running.splice(running.indexOf(app), 1);
  await app.close();
}
after(async () => {
  for (const app of running.splice(0)) await app.close();
});

function rawGet(url: string, headers: Record<string, string>): Promise<{ status: number; location?: string; body: string }> {
  return new Promise((resolve, reject) => {
    httpGet(url, { headers }, (res) => {
      let body = '';
      res.setEncoding('utf8');
      res.on('data', (c: string) => (body += c));
      res.on('end', () => resolve({ status: res.statusCode ?? 0, location: res.headers.location, body }));
    }).on('error', reject);
  });
}
const NAV = { Accept: 'text/html', 'Sec-Fetch-Mode': 'navigate' };

interface SetupForm {
  status: number;
  html: string;
  csrf: string;
  cookie: string;
  headers: Headers;
}
async function openSetup(app: App, cookie = ''): Promise<SetupForm> {
  const r = await fetch(`${app.url}/setup`, { headers: cookie ? { Cookie: cookie } : {}, redirect: 'manual' });
  const html = await r.text();
  return {
    status: r.status,
    html,
    csrf: /name="csrf" value="([^"]*)"/.exec(html)?.[1] ?? '',
    cookie: r.headers.getSetCookie().find((x) => x.startsWith('mvp_setup='))?.split(';')[0] ?? '',
    headers: r.headers,
  };
}
function submit(app: App, fields: Record<string, string>, cookie: string, headers: Record<string, string> = {}): Promise<Response> {
  return fetch(`${app.url}/setup`, {
    method: 'POST',
    headers: { Cookie: cookie, Origin: app.url, ...headers },
    body: new URLSearchParams(fields),
    redirect: 'manual',
  });
}
/** Opens the form and submits a password; returns the response and the form's cookie. */
async function setUp(app: App, password: string, confirm = password): Promise<{ r: Response; form: SetupForm }> {
  const form = await openSetup(app);
  assert.equal(form.status, 200);
  const r = await submit(app, { password, confirm, csrf: form.csrf }, form.cookie);
  return { r, form };
}
const sessionOf = (r: Response) => r.headers.getSetCookie().find((x) => x.startsWith('mvp_session='))?.split(';')[0] ?? '';
async function login(app: App, password: string): Promise<Response> {
  return fetch(`${app.url}/login`, { method: 'POST', body: new URLSearchParams({ password, next: '/' }), redirect: 'manual' });
}

describe('setup mode (no password configured)', () => {
  it('sends every page to /setup and answers API calls with 503', async () => {
    const { app, logs } = await start(newStateFile());
    assert.equal(app.passwordMode(), 'setup');
    for (const p of ['/', '/?room=abc', '/login', '/main.js', '/nothing', '/api/rooms']) {
      const r = await rawGet(`${app.url}${p}`, NAV);
      assert.equal(r.status, 303, p);
      assert.equal(r.location, '/setup', p);
    }
    const curl = await rawGet(`${app.url}/`, { Accept: 'text/html,application/xhtml+xml' });  // no Sec-Fetch-*
    assert.equal(curl.status, 303);
    for (const p of ['/config.json', '/api/disc/image', '/api/rooms', '/main.js']) {
      const r = await fetch(`${app.url}${p}`, { redirect: 'manual' });
      assert.equal(r.status, 503, p);
      assert.deepEqual(await r.json(), { error: 'setup required' });
    }
    const post = await fetch(`${app.url}/login`, { method: 'POST', body: new URLSearchParams({ password: PASSWORD }), redirect: 'manual' });
    assert.equal(post.status, 503);
    assert.equal(await (await fetch(`${app.url}/healthz`)).text(), 'ok');
    await assert.rejects(
      new Promise((resolve, reject) => {
        const ws = new WebSocket(app.url.replace('http:', 'ws:') + '/ws', { headers: { Origin: app.url } });
        ws.on('open', resolve);
        ws.on('error', reject);
        ws.on('unexpected-response', (_q, res) => reject(new Error(`HTTP ${res.statusCode}`)));
      }),
      /401/,
    );
    assert.ok(logs.some((l) => /SETUP MODE/.test(l)), logs.join('\n'));
    await stop(app);
  });

  it('shows the form: two password fields, minimum length 12, a CSRF token, a strict CSP', async () => {
    const { app } = await start(newStateFile());
    const form = await openSetup(app);
    assert.equal(form.status, 200);
    assert.match(form.html, /name="password"[^>]*minlength="12"/);
    assert.match(form.html, /name="confirm"[^>]*minlength="12"/);
    assert.match(form.html, /type="password"/);
    assert.match(form.html, /id="hint"/);  // the strength hint
    assert.match(form.csrf, /^\d+\.[A-Za-z0-9_-]{43}$/);
    assert.match(form.cookie, /^mvp_setup=[A-Za-z0-9_-]{32}$/);
    const setCookie = form.headers.getSetCookie().find((x) => x.startsWith('mvp_setup='))!;
    assert.match(setCookie, /HttpOnly/);
    assert.match(setCookie, /SameSite=Strict/);
    const csp = form.headers.get('content-security-policy') ?? '';
    assert.match(csp, /^default-src 'none'; style-src 'sha256-[^']+'; script-src 'sha256-[^']+'; img-src data:; form-action 'self'/);
    assert.doesNotMatch(csp, /unsafe-inline|unsafe-eval/);
    assert.equal(form.headers.get('cache-control'), 'no-store');
    assert.equal(form.headers.get('x-frame-options'), 'DENY');
    // No value attributes on the password fields: a password is never echoed.
    assert.doesNotMatch(form.html, /<input[^>]*type="password"[^>]*value=/);
    await stop(app);
  });

  it('refuses mismatched or too short passwords and forged forms, and stores nothing', async () => {
    const stateFile = newStateFile();
    const { app, logs } = await start(stateFile);
    const form = await openSetup(app);
    const good = { password: PASSWORD, confirm: PASSWORD, csrf: form.csrf };

    let r = await submit(app, { ...good, confirm: PASSWORD + 'x' }, form.cookie);
    assert.equal(r.status, 400);
    let html = await r.text();
    assert.match(html, /do not match/);
    assert.ok(!html.includes(PASSWORD), 'the password is never echoed');

    for (const short of ['', 'a', 'elevenchars', '12345678901']) {
      r = await submit(app, { ...good, password: short, confirm: short }, form.cookie);
      assert.equal(r.status, 400, short);
      html = await r.text();
      assert.match(html, /too short/);
    }
    // At most 128 characters.
    r = await submit(app, { ...good, password: 'a'.repeat(129), confirm: 'a'.repeat(129) }, form.cookie);
    assert.equal(r.status, 400);
    assert.match(await r.text(), /too long/);

    assert.equal(app.passwordMode(), 'setup');
    assert.equal(readState(stateFile)?.password, undefined);
    assert.ok(!logs.join('\n').includes(PASSWORD));
    await stop(app);
  });

  it('refuses a forged form: a missing, forged or foreign CSRF token, or a cross-site submission', async () => {
    const stateFile = newStateFile();
    const { app, logs } = await start(stateFile);
    const form = await openSetup(app);
    const good = { password: PASSWORD, confirm: PASSWORD, csrf: form.csrf };
    let r: Response;
    const other = await openSetup(app);
    const cases: [string, Record<string, string>, string, Record<string, string>][] = [
      ['no token', { password: PASSWORD, confirm: PASSWORD }, form.cookie, {}],
      ['forged token', { ...good, csrf: form.csrf.replace(/.$/, (c) => (c === 'A' ? 'B' : 'A')) }, form.cookie, {}],
      ['no cookie', good, '', {}],
      ['token of another cookie', { ...good, csrf: other.csrf }, form.cookie, {}],
    ];
    for (const [name, fields, cookie, headers] of cases) {
      r = await submit(app, fields, cookie, headers);
      assert.equal(r.status, 403, name);
      assert.ok(!(await r.text()).includes(PASSWORD), name);
    }
    r = await submit(app, good, form.cookie, { Origin: 'https://evil.example' });
    assert.equal(r.status, 403, 'foreign Origin');
    r = await submit(app, good, form.cookie, { 'Sec-Fetch-Site': 'cross-site' });
    assert.equal(r.status, 403, 'cross-site');
    r = await submit(app, good, form.cookie, { Origin: 'null' });
    assert.equal(r.status, 403, 'Origin: null');

    assert.equal(app.passwordMode(), 'setup');
    assert.equal(readState(stateFile)?.password, undefined);
    assert.equal((await rawGet(`${app.url}/`, NAV)).status, 303);
    assert.ok(!logs.join('\n').includes(PASSWORD));
    await stop(app);
  });

  it('refuses a token that has expired', async () => {
    const clock = new Clock();
    const { app } = await start(newStateFile(), {}, clock);
    const form = await openSetup(app);
    clock.t += 31 * 60_000;  // a token lives 30 minutes, the window 48 hours
    const r = await submit(app, { password: PASSWORD, confirm: PASSWORD, csrf: form.csrf }, form.cookie);
    assert.equal(r.status, 403);
    assert.equal(app.passwordMode(), 'setup');
    const again = await openSetup(app, form.cookie);  // a fresh form with the same cookie works
    assert.equal((await submit(app, { password: PASSWORD, confirm: PASSWORD, csrf: again.csrf }, form.cookie)).status, 303);
    await stop(app);
  });

  it('stores a salted scrypt hash, logs the owner in, and keeps the password out of the file and the log', async () => {
    const stateFile = newStateFile();
    const { app, logs } = await start(stateFile);
    const before = readFileSync(stateFile, 'utf8');
    assert.deepEqual(Object.keys(JSON.parse(before) as object).sort(), ['setupOpenedAt', 'version']);

    const { r } = await setUp(app, PASSWORD);
    assert.equal(r.status, 303);
    assert.equal(r.headers.get('location'), '/');
    const cookies = r.headers.getSetCookie();
    const session = cookies.find((x) => x.startsWith('mvp_session='))!;
    assert.match(session, /^mvp_session=[A-Za-z0-9_-]{43}; Path=\/; HttpOnly; SameSite=Lax; Max-Age=\d+$/);
    assert.ok(cookies.some((x) => /^mvp_setup=;.*Max-Age=0/.test(x)), 'the setup cookie is cleared');
    assert.equal(app.passwordMode(), 'stored');

    // Logged in right away.
    const home = await fetch(`${app.url}/`, { headers: { Cookie: sessionOf(r) } });
    assert.equal(home.status, 200);
    assert.equal(await home.text(), '<!doctype html><title>engine</title>');

    // The file: a scrypt record with the documented parameters, and no plaintext.
    const text = readFileSync(stateFile, 'utf8');
    assert.ok(!text.includes(PASSWORD));
    assert.ok(!text.includes(Buffer.from(PASSWORD).toString('base64')));
    const st = JSON.parse(text) as { version: number; setupOpenedAt: number; password: Record<string, unknown> };
    assert.equal(st.version, 1);
    assert.deepEqual(Object.keys(st.password).sort(), ['N', 'hash', 'kdf', 'keylen', 'p', 'r', 'salt', 'setAt']);
    assert.equal(st.password.kdf, 'scrypt');
    assert.deepEqual([st.password.N, st.password.r, st.password.p, st.password.keylen], [131072, 8, 1, 64]);
    assert.equal(Buffer.from(st.password.salt as string, 'base64').length, SALT_BYTES);
    assert.equal(Buffer.from(st.password.hash as string, 'base64').length, 64);
    assert.ok(await verifyPassword(PASSWORD, parseStoredPassword(st.password)));
    assert.ok(!(await verifyPassword(OTHER, parseStoredPassword(st.password))));
    if (process.platform !== 'win32') {
      assert.equal(statSync(stateFile).mode & 0o777, 0o600);
      assert.equal(statSync(join(stateFile, '..')).mode & 0o077, 0);
    }
    assert.deepEqual(
      readdirSync(join(stateFile, '..')),
      ['state.json'],
      'no temporary files are left behind',
    );

    assert.ok(logs.some((l) => /password was created/.test(l)));
    assert.ok(!logs.join('\n').includes(PASSWORD), 'the password is never logged');
    await stop(app);
  });

  it('answers 404 to every later setup, even with a valid form from before', async () => {
    const stateFile = newStateFile();
    const { app } = await start(stateFile);
    const stale = await openSetup(app);  // a second visitor holds a valid form while the owner finishes
    const { r } = await setUp(app, PASSWORD);
    assert.equal(r.status, 303);
    const session = sessionOf(r);

    for (const headers of [{}, { Cookie: session }]) {
      const get = await fetch(`${app.url}/setup`, { headers, redirect: 'manual' });
      assert.equal(get.status, 404);
      assert.doesNotMatch(await get.text(), /password/i);
      const head = await fetch(`${app.url}/setup`, { method: 'HEAD', headers, redirect: 'manual' });
      assert.equal(head.status, 404);
    }
    const second = await submit(app, { password: OTHER, confirm: OTHER, csrf: stale.csrf }, stale.cookie);
    assert.equal(second.status, 404);
    assert.equal(sessionOf(second), '');

    // The first password still works, the second never did.
    assert.equal((await login(app, PASSWORD)).status, 303);
    assert.equal((await login(app, OTHER)).status, 401);
    assert.ok(await verifyPassword(PASSWORD, readState(stateFile)!.password!));
    await stop(app);
  });

  it('lets exactly one of two simultaneous submissions win', async () => {
    const stateFile = newStateFile();
    const { app } = await start(stateFile);
    const [a, b] = [await openSetup(app), await openSetup(app)];
    const [ra, rb] = await Promise.all([
      submit(app, { password: PASSWORD, confirm: PASSWORD, csrf: a.csrf }, a.cookie),
      submit(app, { password: OTHER, confirm: OTHER, csrf: b.csrf }, b.cookie),
    ]);
    const statuses = [ra.status, rb.status].sort();
    assert.equal(statuses[0], 303, `statuses ${statuses}`);
    assert.ok(statuses[1] === 503 || statuses[1] === 404, `statuses ${statuses}`);
    const winner = ra.status === 303 ? PASSWORD : OTHER;
    const loser = winner === PASSWORD ? OTHER : PASSWORD;
    assert.equal((await login(app, winner)).status, 303);
    assert.equal((await login(app, loser)).status, 401);
    await stop(app);
  });

  it('keeps setup open and says so when the state file cannot be written', async () => {
    const stateFile = newStateFile();
    const { app, logs } = await start(stateFile);
    // Replace the file by a non-empty directory: the atomic rename cannot succeed.
    rmSync(stateFile);
    mkdirSync(join(stateFile, 'blocker'), { recursive: true });
    const { r } = await setUp(app, PASSWORD);
    assert.equal(r.status, 500);
    assert.equal(sessionOf(r), '');
    assert.equal(app.passwordMode(), 'setup');
    assert.ok(logs.some((l) => /could not store the password/.test(l)));
    assert.ok(!logs.join('\n').includes(PASSWORD));
    assert.deepEqual(readdirSync(join(stateFile, '..')), ['state.json'], 'no temporary file is left behind');
    await stop(app);
  });
});

describe('the setup window', () => {
  it('refuses setup after the window and logs that the server needs an operator', async () => {
    const clock = new Clock();
    const stateFile = newStateFile();
    const { app, logs } = await start(stateFile, { setupHours: 48 }, clock);
    const form = await openSetup(app);
    clock.t += 48 * HOUR - 1;  // the last millisecond: still open
    assert.equal((await openSetup(app)).status, 200);
    assert.equal(app.passwordMode(), 'setup');
    clock.t += 1;
    assert.equal(app.passwordMode(), 'closed');

    // The form fetched earlier no longer works.
    const late = await submit(app, { password: PASSWORD, confirm: PASSWORD, csrf: form.csrf }, form.cookie);
    assert.equal(late.status, 403);
    assert.match(await late.text(), /Setup is closed/);
    assert.equal((await openSetup(app)).status, 403);
    assert.equal(readState(stateFile)?.password, undefined);

    // Pages and API calls say the server is not set up (no redirect to a dead form).
    const page = await rawGet(`${app.url}/`, NAV);
    assert.equal(page.status, 503);
    assert.match(page.body, /Not set up/);
    const api = await fetch(`${app.url}/api/rooms`);
    assert.equal(api.status, 503);
    assert.deepEqual(await api.json(), { error: 'server not set up' });
    assert.equal(await (await fetch(`${app.url}/healthz`)).text(), 'ok');

    const needs = logs.filter((l) => /needs an operator/.test(l));
    assert.equal(needs.length, 1, 'logged once');
    assert.ok(needs[0]!.includes(stateFile));
    await stop(app);
  });

  it('closes while a submission is being hashed', async () => {
    const clock = new Clock();
    const stateFile = newStateFile();
    const { app } = await start(stateFile, { setupHours: 1 }, clock);
    const form = await openSetup(app);
    clock.t += HOUR - 1;
    const pending = submit(app, { password: PASSWORD, confirm: PASSWORD, csrf: form.csrf }, form.cookie);
    await new Promise((r) => setTimeout(r, 20));  // the scrypt run is under way
    clock.t += 2;
    assert.equal((await pending).status, 403);
    assert.equal(readState(stateFile)?.password, undefined);
    await stop(app);
  });

  it('is not extended by restarts', async () => {
    const clock = new Clock();
    const stateFile = newStateFile();
    const t0 = clock.t;
    let s = await start(stateFile, {}, clock);
    assert.equal(readState(stateFile)!.setupOpenedAt, t0);
    await stop(s.app);

    clock.t = t0 + 47 * HOUR;
    s = await start(stateFile, {}, clock);
    assert.equal(s.app.passwordMode(), 'setup');
    assert.equal(readState(stateFile)!.setupOpenedAt, t0, 'the window start stays');
    await stop(s.app);

    clock.t = t0 + 49 * HOUR;
    s = await start(stateFile, {}, clock);
    assert.equal(s.app.passwordMode(), 'closed');
    assert.ok(s.logs.some((l) => /needs an operator/.test(l)), 'logged at start');
    assert.equal((await openSetup(s.app)).status, 403);
    await stop(s.app);
  });

  it('reopens, with a fresh window, when an operator deletes the state file', async () => {
    const clock = new Clock();
    const stateFile = newStateFile();
    const t0 = clock.t;
    let s = await start(stateFile, {}, clock);
    await stop(s.app);
    clock.t = t0 + 60 * HOUR;
    s = await start(stateFile, {}, clock);
    assert.equal(s.app.passwordMode(), 'closed');
    await stop(s.app);

    rmSync(stateFile);
    s = await start(stateFile, {}, clock);
    assert.equal(s.app.passwordMode(), 'setup');
    assert.equal(readState(stateFile)!.setupOpenedAt, t0 + 60 * HOUR);
    const { r } = await setUp(s.app, PASSWORD);
    assert.equal(r.status, 303);
    await stop(s.app);
  });

  it('honours a configured window and a clock set back', async () => {
    const clock = new Clock();
    const stateFile = newStateFile();
    const t0 = clock.t;
    let s = await start(stateFile, { setupHours: 0.5 }, clock);
    clock.t = t0 + 29 * 60_000;
    assert.equal(s.app.passwordMode(), 'setup');
    clock.t = t0 + 31 * 60_000;
    assert.equal(s.app.passwordMode(), 'closed');
    await stop(s.app);

    // The file claims the window opened in the future (the clock was corrected): it restarts now.
    writeState(stateFile, { version: 1, setupOpenedAt: t0 + 1000 * HOUR });
    s = await start(stateFile, { setupHours: 48 }, clock);
    assert.equal(s.app.passwordMode(), 'setup');
    assert.equal(readState(stateFile)!.setupOpenedAt, clock.t);
    await stop(s.app);
  });
});

describe('stored password and restarts', () => {
  it('requires a login after a restart, and the stored password logs in', async () => {
    const stateFile = newStateFile();
    let s = await start(stateFile);
    const { r } = await setUp(s.app, PASSWORD);
    const oldSession = sessionOf(r);
    await stop(s.app);

    s = await start(stateFile);
    const app = s.app;
    assert.equal(app.passwordMode(), 'stored');
    assert.ok(s.logs.some((l) => /stored hash/.test(l)));
    const page = await rawGet(`${app.url}/`, NAV);
    assert.equal(page.status, 303);
    assert.equal(page.location, '/login?next=%2F');
    assert.equal((await fetch(`${app.url}/config.json`)).status, 401);
    assert.equal((await fetch(`${app.url}/config.json`, { headers: { Cookie: oldSession } })).status, 401, 'sessions do not survive a restart');
    assert.equal((await fetch(`${app.url}/setup`)).status, 404);
    assert.equal((await fetch(`${app.url}/login`)).status, 200);

    let bad = await login(app, OTHER);
    assert.equal(bad.status, 401);
    assert.equal(bad.headers.get('set-cookie'), null);
    assert.match(await bad.text(), /Wrong password/);
    bad = await login(app, PASSWORD.toUpperCase());
    assert.equal(bad.status, 401);
    const ok = await login(app, PASSWORD);
    assert.equal(ok.status, 303);
    assert.equal((await fetch(`${app.url}/config.json`, { headers: { Cookie: sessionOf(ok) } })).status, 200);
    await stop(app);
  });

  it('still limits failed logins per address', async () => {
    const stateFile = newStateFile();
    let s = await start(stateFile);
    await setUp(s.app, PASSWORD);
    await stop(s.app);
    s = await start(stateFile, { loginAttempts: 2 });
    for (let k = 0; k < 2; ++k) assert.equal((await login(s.app, OTHER)).status, 401);
    assert.equal((await login(s.app, PASSWORD)).status, 429);
    await stop(s.app);
  });

  it('refuses to start on a damaged state file instead of reopening setup', async () => {
    const stateFile = newStateFile();
    mkdirSync(join(stateFile, '..'), { recursive: true });
    const good = await hashPassword(PASSWORD);
    const bad: [string, string][] = [
      ['not json', 'not json'],
      ['wrong version', JSON.stringify({ version: 2, setupOpenedAt: 1 })],
      ['no time', JSON.stringify({ version: 1 })],
      ['cost too high', JSON.stringify({ version: 1, setupOpenedAt: 1, password: { ...good, N: 1 << 25, setAt: 1 } })],
      ['hash too short', JSON.stringify({ version: 1, setupOpenedAt: 1, password: { ...good, hash: 'AAAA', setAt: 1 } })],
      ['plaintext in place of a record', JSON.stringify({ version: 1, setupOpenedAt: 1, password: PASSWORD })],
    ];
    for (const [name, text] of bad) {
      writeFileSync(stateFile, text);
      await assert.rejects(start(stateFile), /unusable|invalid/, name);
      assert.equal(readFileSync(stateFile, 'utf8'), text, `${name}: left alone`);
    }
  });
});

describe('the environment password', () => {
  it('wins over a stored one, turns setup off, and leaves the state file alone', async () => {
    const stateFile = newStateFile();
    let s = await start(stateFile);
    await setUp(s.app, PASSWORD);
    await stop(s.app);
    const before = readFileSync(stateFile, 'utf8');

    s = await start(stateFile, { password: ENV_PASSWORD });
    const app = s.app;
    assert.equal(app.passwordMode(), 'env');
    assert.equal((await login(app, ENV_PASSWORD)).status, 303);
    assert.equal((await login(app, PASSWORD)).status, 401, 'the stored password is ignored');
    assert.equal((await fetch(`${app.url}/setup`)).status, 404);
    assert.equal(readFileSync(stateFile, 'utf8'), before);
    await stop(app);
  });

  it('needs no state file at all', async () => {
    const stateFile = newStateFile();
    const { app } = await start(stateFile, { password: ENV_PASSWORD });
    assert.equal(app.passwordMode(), 'env');
    assert.equal((await rawGet(`${app.url}/`, NAV)).location, '/login?next=%2F');
    assert.equal((await fetch(`${app.url}/setup`, { method: 'POST', body: 'x=1' })).status, 404);
    assert.ok(!existsSync(stateFile), 'not created');
    await stop(app);

    const bare = await startServer({ ...config(''), password: ENV_PASSWORD }, { log: () => undefined });
    assert.equal(bare.passwordMode(), 'env');
    await bare.close();
  });

  it('is resolved by loadConfig: environment first, the state file otherwise, an error for neither', () => {
    const state = join(dir, 'cfg-state.json');
    assert.throws(() => loadConfig({ MVP_SITE: site }), /MVP_STATE_FILE/);
    assert.throws(() => loadConfig({ MVP_SITE: site, MVP_PASSWORD: 'short' }), /at least 8/);
    const none = loadConfig({ MVP_SITE: site, MVP_STATE_FILE: state });
    assert.equal(none.password, '');
    assert.equal(none.stateFile, state);
    assert.equal(none.setupHours, 48);
    const both = loadConfig({ MVP_SITE: site, MVP_STATE_FILE: state, MVP_PASSWORD: ENV_PASSWORD, MVP_SETUP_HOURS: '12' });
    assert.equal(both.password, ENV_PASSWORD);
    assert.equal(both.setupHours, 12);
    const envOnly = loadConfig({ MVP_SITE: site, MVP_PASSWORD: ENV_PASSWORD });
    assert.equal(envOnly.stateFile, '');
    for (const bad of ['0', '-1', 'abc', '99999']) {
      assert.throws(() => loadConfig({ MVP_SITE: site, MVP_STATE_FILE: state, MVP_SETUP_HOURS: bad }), /MVP_SETUP_HOURS/, bad);
    }
    // The configuration file can carry the state file and the window.
    const file = join(dir, 'server.json');
    writeFileSync(file, JSON.stringify({ site, stateFile: state, setupHours: 6 }));
    const fromFile = loadConfig({ MVP_SERVER_CONFIG: file });
    assert.equal(fromFile.stateFile, state);
    assert.equal(fromFile.setupHours, 6);
    // An empty password file is an error, not "no password" (which would open setup).
    const empty = join(dir, 'empty-pw');
    writeFileSync(empty, '\n');
    assert.throws(() => loadConfig({ MVP_SITE: site, MVP_STATE_FILE: state, MVP_PASSWORD_FILE: empty }), /empty/);
  });
});

describe('setup limits', () => {
  it('limits requests per address', async () => {
    const { app } = await start(newStateFile());
    for (let k = 0; k < SETUP_LIMITS.requestsPerAddress; ++k) assert.equal((await openSetup(app)).status, 200, `request ${k}`);
    const r = await fetch(`${app.url}/setup`);
    assert.equal(r.status, 429);
    assert.equal(r.headers.get('retry-after'), '900');
    assert.equal(r.headers.get('set-cookie'), null);
    await stop(app);
  });

  it('limits submissions per address, and so slows guessing of the form', async () => {
    const { app } = await start(newStateFile());
    const form = await openSetup(app);
    for (let k = 0; k < SETUP_LIMITS.submissionsPerAddress; ++k) {
      const r = await submit(app, { password: 'x', confirm: 'y', csrf: form.csrf }, form.cookie);
      assert.equal(r.status, 400, `submission ${k}`);
      await r.arrayBuffer();
    }
    const blocked = await submit(app, { password: PASSWORD, confirm: PASSWORD, csrf: form.csrf }, form.cookie);
    assert.equal(blocked.status, 429);
    assert.equal(app.passwordMode(), 'setup');
    await stop(app);
  });

  it('counts the window per key and forgets old hits', () => {
    let now = 1_000_000;
    const lim = new HitLimiter(2, 1000, () => now);
    assert.ok(lim.allow('a'));
    assert.ok(lim.allow('a'));
    assert.ok(!lim.allow('a'));
    assert.ok(lim.allow('b'));
    now += 1001;
    assert.ok(lim.allow('a'));
    assert.ok(lim.allow('a'));
    assert.ok(!lim.allow('a'));
  });
});

describe('password hashing and tokens', () => {
  it('hashes with scrypt N=2^17 r=8 p=1, a fresh salt each time, and verifies in either direction', async () => {
    assert.deepEqual(SCRYPT_PARAMS, { N: 131072, r: 8, p: 1, keylen: 64 });
    const a = await hashPassword(PASSWORD);
    const b = await hashPassword(PASSWORD);
    assert.notEqual(a.salt, b.salt);
    assert.notEqual(a.hash, b.hash);
    assert.ok(await verifyPassword(PASSWORD, a));
    assert.ok(!(await verifyPassword(PASSWORD + ' ', a)));
    assert.ok(!(await verifyPassword(OTHER, b)));
    assert.deepEqual(parseStoredPassword(JSON.parse(JSON.stringify(a))), a);
  });

  it('normalizes (NFKC) and counts characters, not bytes', async () => {
    assert.equal(normalizePassword('ＡＢＣ'), 'ABC');  // full-width letters
    assert.equal(passwordLength('\u{1F600}'.repeat(12)), 12);  // 12 characters, 48 bytes
    const rec = await hashPassword('café crème brûlée');
    assert.ok(await verifyPassword('café crème brûlée', rec));  // composed vs decomposed
    assert.equal(checkNewPassword('\u{1F600}'.repeat(12), '\u{1F600}'.repeat(12)), null);
    assert.match(checkNewPassword('short', 'short') ?? '', /too short: 5 characters/);
    assert.match(checkNewPassword(PASSWORD, OTHER) ?? '', /do not match/);
  });

  it('runs one hash at a time and refuses a full queue', async () => {
    const q = new KdfQueue(1, 2);
    let active = 0;
    let peak = 0;
    const release: (() => void)[] = [];
    const job = () =>
      new Promise<number>((resolve) => {
        peak = Math.max(peak, ++active);
        release.push(() => {
          --active;
          resolve(1);
        });
      });
    const runs = [q.run(job), q.run(job), q.run(job), q.run(job)];  // one running, two waiting, the fourth refused
    assert.equal(await runs[3], BUSY);
    for (let k = 0; k < 3; ++k) {
      await new Promise((r) => setImmediate(r));
      release[k]!();
    }
    assert.deepEqual(await Promise.all(runs.slice(0, 3)), [1, 1, 1]);
    assert.equal(peak, 1);
    assert.equal(await q.run(async () => 5), 5);
  });

  it('binds CSRF tokens to the cookie id and expires them', () => {
    let now = 5_000_000;
    const t = new CsrfTokens(() => now);
    const id = t.newId();
    const token = t.issue(id);
    assert.ok(CsrfTokens.validId(id));
    assert.ok(t.verify(id, token));
    assert.ok(!t.verify(t.newId(), token));
    assert.ok(!t.verify(undefined, token));
    assert.ok(!t.verify(id, null));
    assert.ok(!t.verify(id, token + 'x'));
    assert.ok(!new CsrfTokens(() => now).verify(id, token), 'another process has another key');
    now += 30 * 60_000;
    assert.ok(!t.verify(id, token));
  });

  it('writes the state file atomically with owner-only modes', () => {
    const file = join(dir, 'unit', 'nested', 'state.json');
    const st = loadState(file, 1234);
    assert.deepEqual(st, { version: 1, setupOpenedAt: 1234 });
    assert.deepEqual(loadState(file, 9999), st);
    if (process.platform !== 'win32') assert.equal(statSync(file).mode & 0o777, 0o600);
    assert.equal(readState(join(dir, 'unit', 'missing.json')), null);
  });
});
