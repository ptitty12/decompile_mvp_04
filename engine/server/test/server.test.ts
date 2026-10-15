// Tests for the VPS server (E5): the password gate, the static site, the disc
// route, the lobby and signaling. No game data: the "disc" is random bytes in
// a temporary directory.
import assert from 'node:assert/strict';
import { createHmac, randomBytes } from 'node:crypto';
import { mkdtempSync, mkdirSync, rmSync, writeFileSync } from 'node:fs';
import { get as httpGet } from 'node:http';
import { tmpdir } from 'node:os';
import { join } from 'node:path';
import { after, before, describe, it } from 'node:test';
import WebSocket from 'ws';

import { LoginLimiter, Sessions, parseCookies, safeNext } from '../src/auth.js';
import { defaults, loadConfig, type ServerConfig } from '../src/config.js';
import { parseRange } from '../src/files.js';
import { parseClientMsg } from '../src/lobby.js';
import type { ServerMsg } from '../src/lobby_protocol.js';
import { SITE_CSP, startServer, type App } from '../src/server.js';
import { turnCredentials } from '../src/turn.js';

const PASSWORD = 'correct horse battery';
const dir = mkdtempSync(join(tmpdir(), 'mvp-server-test-'));
const site = join(dir, 'site');
const discPath = join(dir, 'disc.bin');
const disc = randomBytes(100_000);

before(() => {
  mkdirSync(join(site, 'sub'), { recursive: true });
  writeFileSync(join(site, 'index.html'), '<!doctype html><title>engine</title>');
  writeFileSync(join(site, 'main.js'), 'console.log(1);');
  writeFileSync(join(site, 'sub', 'a.txt'), 'hello');
  writeFileSync(join(site, 'secret.key'), 'not served: unknown type');
  writeFileSync(join(dir, 'outside.txt'), 'outside the site');
  writeFileSync(discPath, disc);
});
after(() => rmSync(dir, { recursive: true, force: true }));

function config(over: Partial<ServerConfig> = {}): ServerConfig {
  return { ...defaults, site, password: PASSWORD, port: 0, disc: discPath, ...over };
}

function rawGet(url: string, headers: Record<string, string>): Promise<{ status: number; location?: string }> {
  return new Promise((resolve, reject) => {
    httpGet(url, { headers }, (res) => {
      res.resume();
      resolve({ status: res.statusCode ?? 0, location: res.headers.location });
    }).on('error', reject);
  });
}

async function login(app: App): Promise<string> {
  const r = await fetch(`${app.url}/login`, {
    method: 'POST',
    headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
    body: new URLSearchParams({ password: PASSWORD, next: '/' }),
    redirect: 'manual',
  });
  assert.equal(r.status, 303);
  const cookie = r.headers.get('set-cookie') ?? '';
  return cookie.split(';')[0]!;
}

describe('password gate', () => {
  let app: App;
  before(async () => (app = await startServer(config())));
  after(() => app.close());

  it('sends page loads to the login form and API calls a 401', async () => {
    // A browser's page load says Sec-Fetch-Mode: navigate (Node's fetch always says cors,
    // so these go through node:http with exact headers).
    let raw = await rawGet(`${app.url}/?room=abc`, { Accept: 'text/html', 'Sec-Fetch-Mode': 'navigate' });
    assert.equal(raw.status, 303);
    assert.equal(raw.location, '/login?next=%2F%3Froom%3Dabc');
    raw = await rawGet(`${app.url}/main.js`, { 'Sec-Fetch-Mode': 'navigate' });
    assert.equal(raw.status, 303);
    raw = await rawGet(`${app.url}/`, { Accept: 'text/html,application/xhtml+xml' });  // curl-like, no Sec-Fetch-*
    assert.equal(raw.status, 303);
    raw = await rawGet(`${app.url}/config.json`, { Accept: '*/*', 'Sec-Fetch-Mode': 'cors' });
    assert.equal(raw.status, 401);
    let r: Response;
    for (const p of ['/config.json', '/api/disc/image', '/api/rooms', '/main.js', '/nothing']) {
      r = await fetch(`${app.url}${p}`, { redirect: 'manual' });
      assert.equal(r.status, 401, p);
      assert.deepEqual(await r.json(), { error: 'login required' });
    }
    r = await fetch(`${app.url}/api/disc/image`, { method: 'HEAD', redirect: 'manual' });
    assert.equal(r.status, 401);
  });

  it('shows the login form with a strict CSP', async () => {
    const r = await fetch(`${app.url}/login?next=/x`);
    assert.equal(r.status, 200);
    const html = await r.text();
    assert.match(html, /type="password"/);
    assert.match(html, /name="next" value="\/x"/);
    assert.match(r.headers.get('content-security-policy') ?? '', /default-src 'none'; style-src 'sha256-/);
    assert.equal(r.headers.get('x-frame-options'), 'DENY');
  });

  it('refuses a wrong password and accepts the right one with an HttpOnly cookie', async () => {
    let r = await fetch(`${app.url}/login`, {
      method: 'POST',
      body: new URLSearchParams({ password: 'nope', next: '/' }),
      redirect: 'manual',
    });
    assert.equal(r.status, 401);
    assert.equal(r.headers.get('set-cookie'), null);
    assert.match(await r.text(), /Wrong password/);
    r = await fetch(`${app.url}/login`, {
      method: 'POST',
      body: new URLSearchParams({ password: PASSWORD, next: '/?room=abcd' }),
      redirect: 'manual',
    });
    assert.equal(r.status, 303);
    assert.equal(r.headers.get('location'), '/?room=abcd');
    const sc = r.headers.get('set-cookie') ?? '';
    assert.match(sc, /^mvp_session=[A-Za-z0-9_-]{43}; Path=\/; HttpOnly; SameSite=Lax; Max-Age=\d+$/);
    const cookie = sc.split(';')[0]!;
    r = await fetch(`${app.url}/`, { headers: { Cookie: cookie } });
    assert.equal(r.status, 200);
    assert.equal(await r.text(), '<!doctype html><title>engine</title>');
    assert.equal(r.headers.get('content-security-policy'), SITE_CSP);
    assert.equal(r.headers.get('referrer-policy'), 'no-referrer');
  });

  it('never redirects outside the site after the login', async () => {
    for (const next of ['//evil.example', 'https://evil.example/', '/\\evil.example', 'relative']) {
      const r = await fetch(`${app.url}/login`, {
        method: 'POST',
        body: new URLSearchParams({ password: PASSWORD, next }),
        redirect: 'manual',
      });
      assert.equal(r.headers.get('location'), '/', next);
    }
    assert.equal(safeNext('/?room=x'), '/?room=x');
    assert.equal(safeNext('/a\r\nSet-Cookie: x'), '/');
  });

  it('logs out only from the site itself', async () => {
    const cookie = await login(app);
    let r = await fetch(`${app.url}/logout`, { method: 'POST', headers: { Cookie: cookie }, redirect: 'manual' });
    assert.equal(r.status, 403);  // no Origin
    r = await fetch(`${app.url}/logout`, {
      method: 'POST',
      headers: { Cookie: cookie, Origin: 'https://evil.example' },
      redirect: 'manual',
    });
    assert.equal(r.status, 403);
    r = await fetch(`${app.url}/logout`, { method: 'POST', headers: { Cookie: cookie, Origin: app.url }, redirect: 'manual' });
    assert.equal(r.status, 303);
    assert.match(r.headers.get('set-cookie') ?? '', /Max-Age=0/);
    r = await fetch(`${app.url}/config.json`, { headers: { Cookie: cookie } });
    assert.equal(r.status, 401);
  });

  it('answers /healthz without a login', async () => {
    const r = await fetch(`${app.url}/healthz`);
    assert.equal(await r.text(), 'ok');
  });
});

describe('login limits and sessions', () => {
  it('blocks an address after too many failures, even with the right password', async () => {
    const app = await startServer(config({ loginAttempts: 3 }));
    try {
      for (let k = 0; k < 3; ++k) {
        const r = await fetch(`${app.url}/login`, { method: 'POST', body: 'password=x', redirect: 'manual' });
        assert.equal(r.status, 401);
      }
      const r = await fetch(`${app.url}/login`, {
        method: 'POST',
        body: new URLSearchParams({ password: PASSWORD }),
        redirect: 'manual',
      });
      assert.equal(r.status, 429);
      assert.equal(r.headers.get('set-cookie'), null);
    } finally {
      await app.close();
    }
  });

  it('expires sessions and windows', () => {
    let now = 1_000_000;
    const s = new Sessions(1, () => now);
    const t = s.create();
    assert.ok(s.valid(t));
    assert.ok(!s.valid('other'));
    now += 3600_000;
    assert.ok(!s.valid(t));
    const l = new LoginLimiter(2, () => now);
    l.fail('a');
    l.fail('a');
    assert.ok(l.blocked('a'));
    assert.ok(!l.blocked('b'));
    now += 15 * 60_000 + 1;
    assert.ok(!l.blocked('a'));
    assert.deepEqual([...parseCookies('a=1; mvp_session=xyz; b=2').entries()], [['a', '1'], ['mvp_session', 'xyz'], ['b', '2']]);
  });

  it('reads secrets from the environment only, and refuses a short password', () => {
    assert.throws(() => loadConfig({ MVP_SITE: site }), /MVP_PASSWORD/);
    assert.throws(() => loadConfig({ MVP_SITE: site, MVP_PASSWORD: 'short' }), /at least 8/);
    const pw = join(dir, 'pw.txt');
    writeFileSync(pw, 'from a file 123\n');
    const c = loadConfig({ MVP_SITE: site, MVP_PASSWORD_FILE: pw, MVP_PORT: '9000', MVP_SECURE_COOKIES: '1' });
    assert.equal(c.password, 'from a file 123');
    assert.equal(c.port, 9000);
    assert.equal(c.secureCookies, true);
    assert.equal(c.turn, null);
  });
});

describe('static site', () => {
  let app: App;
  let cookie: string;
  before(async () => {
    app = await startServer(config());
    cookie = await login(app);
  });
  after(() => app.close());

  it('serves files inside the site only', async () => {
    const get = (p: string) => fetch(`${app.url}${p}`, { headers: { Cookie: cookie } });
    let r = await get('/sub/a.txt');
    assert.equal(r.status, 200);
    assert.equal(await r.text(), 'hello');
    assert.equal(r.headers.get('content-type'), 'text/plain; charset=utf-8');
    assert.equal(r.headers.get('cache-control'), 'private, no-cache');
    for (const p of ['/../outside.txt', '/%2e%2e/outside.txt', '/sub/../../outside.txt', '/secret.key', '/sub', '/missing.js']) {
      r = await get(p);
      assert.equal(r.status, 404, p);
    }
  });

  it('revalidates with an ETag', async () => {
    let r = await fetch(`${app.url}/main.js`, { headers: { Cookie: cookie } });
    const etag = r.headers.get('etag')!;
    assert.ok(etag);
    r = await fetch(`${app.url}/main.js`, { headers: { Cookie: cookie, 'If-None-Match': etag } });
    assert.equal(r.status, 304);
  });
});

describe('disc route', () => {
  it('advertises the disc in /config.json only when configured', async () => {
    for (const [d, body] of [[discPath, { disc: '/api/disc/image' }], ['', {}]] as const) {
      const app = await startServer(config({ disc: d }));
      try {
        const cookie = await login(app);
        const r = await fetch(`${app.url}/config.json`, { headers: { Cookie: cookie } });
        assert.equal(r.status, 200);
        assert.deepEqual(await r.json(), body);
        const img = await fetch(`${app.url}/api/disc/image`, { method: 'HEAD', headers: { Cookie: cookie } });
        assert.equal(img.status, d ? 200 : 404);
      } finally {
        await app.close();
      }
    }
  });

  it('serves HEAD, whole and ranged GETs, never cacheable', async () => {
    const app = await startServer(config());
    try {
      const cookie = await login(app);
      const req = (init: RequestInit & { headers?: Record<string, string> } = {}) =>
        fetch(`${app.url}/api/disc/image`, { ...init, headers: { Cookie: cookie, ...(init.headers ?? {}) } });
      let r = await req({ method: 'HEAD' });
      assert.equal(r.status, 200);
      assert.equal(r.headers.get('content-length'), String(disc.length));
      assert.equal(r.headers.get('accept-ranges'), 'bytes');
      assert.equal(r.headers.get('cache-control'), 'private, no-store');
      r = await req();
      assert.equal(r.status, 200);
      assert.ok(Buffer.from(await r.arrayBuffer()).equals(disc));
      const cases: [string, number, number][] = [
        ['bytes=10-19', 10, 19],
        ['bytes=99990-', 99990, 99999],
        ['bytes=-16', 99984, 99999],
        ['bytes=99000-200000', 99000, 99999],
        ['bytes=0-0', 0, 0],
      ];
      for (const [range, s, e] of cases) {
        r = await req({ headers: { Range: range } });
        assert.equal(r.status, 206, range);
        assert.equal(r.headers.get('content-range'), `bytes ${s}-${e}/${disc.length}`);
        assert.equal(r.headers.get('content-length'), String(e - s + 1));
        assert.equal(r.headers.get('cache-control'), 'private, no-store');
        assert.ok(Buffer.from(await r.arrayBuffer()).equals(disc.subarray(s, e + 1)), range);
      }
      for (const bad of ['bytes=100000-', 'bytes=5-3', 'bytes=0-1,5-6', 'items=0-1', 'bytes=-0']) {
        r = await req({ headers: { Range: bad } });
        assert.equal(r.status, 416, bad);
        assert.equal(r.headers.get('content-range'), `bytes */${disc.length}`);
        await r.arrayBuffer();
      }
    } finally {
      await app.close();
    }
  });

  it('parses ranges', () => {
    assert.equal(parseRange(undefined, 10), 'none');
    assert.deepEqual(parseRange('bytes=2-', 10), { start: 2, end: 9 });
    assert.deepEqual(parseRange('bytes=-3', 10), { start: 7, end: 9 });
    assert.deepEqual(parseRange('bytes=-30', 10), { start: 0, end: 9 });
    assert.equal(parseRange('bytes=10-', 10), 'bad');
    assert.equal(parseRange('bytes=-', 10), 'bad');
  });
});

// ---- lobby and signaling ----

class Peer {
  readonly msgs: ServerMsg[] = [];
  private waiters: (() => void)[] = [];
  constructor(readonly ws: WebSocket) {
    ws.on('message', (d) => {
      this.msgs.push(JSON.parse(d.toString()) as ServerMsg);
      for (const w of this.waiters.splice(0)) w();
    });
  }
  static open(url: string, headers: Record<string, string>): Promise<Peer> {
    return new Promise((resolve, reject) => {
      const ws = new WebSocket(url, { headers });
      const p = new Peer(ws);
      ws.on('open', () => resolve(p));
      ws.on('error', reject);
      ws.on('unexpected-response', (_req, res) => reject(new Error(`HTTP ${res.statusCode}`)));
    });
  }
  send(m: unknown): void {
    this.ws.send(typeof m === 'string' ? m : JSON.stringify(m));
  }
  async next<T extends ServerMsg['t']>(t: T): Promise<Extract<ServerMsg, { t: T }>> {
    for (;;) {
      const i = this.msgs.findIndex((m) => m.t === t);
      if (i >= 0) return this.msgs.splice(i, 1)[0] as Extract<ServerMsg, { t: T }>;
      await new Promise<void>((resolve, reject) => {
        const timer = setTimeout(() => reject(new Error(`timeout waiting for ${t}`)), 3000);
        this.waiters.push(() => {
          clearTimeout(timer);
          resolve();
        });
      });
    }
  }
}

describe('lobby and signaling', () => {
  let app: App;
  let cookie: string;
  const secret = 'turn-secret-for-tests';
  before(async () => {
    app = await startServer(
      config({
        stun: ['stun:turn.example.test:3478'],
        turn: { urls: ['turn:turn.example.test:3478?transport=udp'], secret, ttlSeconds: 3600 },
        publicUrl: '',
      }),
    );
    cookie = await login(app);
  });
  after(() => app.close());
  const wsUrl = () => app.url.replace('http:', 'ws:') + '/ws';
  const open = () => Peer.open(wsUrl(), { Cookie: cookie, Origin: app.url });

  it('refuses sockets without a session or from another origin', async () => {
    await assert.rejects(Peer.open(wsUrl(), { Origin: app.url }), /401/);
    await assert.rejects(Peer.open(wsUrl(), { Cookie: cookie, Origin: 'https://evil.example' }), /401/);
    await assert.rejects(Peer.open(wsUrl(), { Cookie: cookie }), /401/);
  });

  it('welcomes with STUN and time-limited TURN credentials', async () => {
    const p = await open();
    const w = await p.next('welcome');
    assert.equal(w.v, 1);
    assert.deepEqual(w.iceServers[0], { urls: ['stun:turn.example.test:3478'] });
    const turn = w.iceServers[1]!;
    assert.deepEqual(turn.urls, ['turn:turn.example.test:3478?transport=udp']);
    const [expiry, tag] = turn.username!.split(':');
    assert.equal(tag, 'mvp');
    const left = Number(expiry) - Date.now() / 1000;
    assert.ok(left > 3500 && left <= 3600, String(left));
    assert.equal(turn.credential, createHmac('sha1', secret).update(turn.username!).digest('base64'));
    p.ws.close();
  });

  it('creates a room, joins it, relays signals, and tells who left', async () => {
    const a = await open();
    const b = await open();
    const c = await open();
    a.send({ t: 'create', name: 'Patrick', delay: 4 });
    const ra = await a.next('room');
    assert.equal(ra.player, 1);
    assert.equal(ra.delay, 4);
    assert.equal(ra.peer, false);
    assert.match(ra.room, /^[a-z2-9]{12}$/);
    assert.equal(ra.invite, `${app.url}/?room=${ra.room}`);

    const r = await fetch(`${app.url}/api/rooms`, { headers: { Cookie: cookie } });
    const rooms = ((await r.json()) as { rooms: { room: string; name: string; players: number }[] }).rooms;
    assert.ok(rooms.some((x) => x.room === ra.room && x.name === 'Patrick' && x.players === 1));

    b.send({ t: 'join', room: ra.room });
    const rb = await b.next('room');
    assert.equal(rb.player, 2);
    assert.equal(rb.delay, 4);
    assert.equal(rb.peer, true);
    assert.deepEqual(await a.next('peer'), { t: 'peer', present: true });

    c.send({ t: 'join', room: ra.room });
    assert.equal((await c.next('error')).code, 'room-full');
    c.send({ t: 'join', room: 'nosuchroom' });
    assert.equal((await c.next('error')).code, 'no-room');

    const offer = { kind: 'offer', sdp: 'v=0\r\no=- 1 2 IN IP4 127.0.0.1\r\n' } as const;
    a.send({ t: 'signal', data: offer });
    assert.deepEqual((await b.next('signal')).data, offer);
    const cand = { kind: 'candidate', candidate: { candidate: 'candidate:1 1 udp 1 127.0.0.1 5000 typ host', sdpMid: '0', sdpMLineIndex: 0 } } as const;
    b.send({ t: 'signal', data: cand });
    assert.deepEqual((await a.next('signal')).data, cand);
    b.send({ t: 'signal', data: { kind: 'candidate', candidate: null } });
    assert.deepEqual((await a.next('signal')).data, { kind: 'candidate', candidate: null });
    c.send({ t: 'signal', data: offer });
    assert.equal((await c.next('error')).code, 'no-peer');

    b.ws.close();
    assert.deepEqual(await a.next('peer'), { t: 'peer', present: false });
    a.send({ t: 'list' });
    const list = await a.next('rooms');
    assert.ok(list.rooms.some((x) => x.room === ra.room && x.players === 1));
    a.ws.close();
    c.ws.close();
  });

  it('rejects malformed messages', async () => {
    const p = await open();
    for (const bad of ['not json', '{}', '{"t":"join","room":"../x"}', '{"t":"create","delay":99}',
                       '{"t":"signal","data":{"kind":"offer"}}', '{"t":"signal","data":{"kind":"candidate","candidate":{"candidate":5}}}']) {
      p.send(bad);
      assert.equal((await p.next('error')).code, 'bad-message', bad);
    }
    assert.equal(parseClientMsg('{"t":"signal","data":{"kind":"offer","sdp":"' + 'x'.repeat(40000) + '"}}'), null);
    p.ws.close();
  });
});

describe('TURN credentials', () => {
  it('match coturn REST API credentials', () => {
    const c = turnCredentials('s3cret', 600, 1_700_000_000_000);
    assert.equal(c.username, '1700000600:mvp');
    assert.equal(c.credential, createHmac('sha1', 's3cret').update('1700000600:mvp').digest('base64'));
  });
});
