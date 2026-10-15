// The VPS server (E5): one Node process behind a TLS reverse proxy.
//
//   GET  /login, POST /login, POST /logout   the password gate (src/auth.ts)
//   GET/POST /setup                          first-run password setup (src/setup.ts): open only
//                                            while the server has no password; 404 once it has one
//   GET  /healthz                            "ok" (no login; for monitoring)
//   GET  /config.json                        {"disc":"/api/disc/image"} or {}
//   GET/HEAD /api/disc/image                 the owner's disc image (src/files.ts)
//   GET  /api/rooms                          open rooms (src/lobby.ts)
//   WS   /ws                                 lobby and WebRTC signaling
//   GET  anything else                       the engine site (static files)
//
// Everything except /login and /healthz needs the session cookie: a page load
// without it is sent to the login form, anything else gets 401. While the
// server has no password (setup mode) every page load is sent to /setup instead.
import { createServer, type IncomingMessage, type Server, type ServerResponse } from 'node:http';
import type { AddressInfo } from 'node:net';
import { WebSocketServer } from 'ws';

import {
  COOKIE,
  LOGIN_CSS_HASH,
  LoginLimiter,
  Sessions,
  clearCookie,
  clientAddress,
  isNavigation,
  loginPage,
  parseCookies,
  safeNext,
  sessionCookie,
} from './auth.js';
import type { ServerConfig } from './config.js';
import { serveDisc, serveStatic } from './files.js';
import { Lobby } from './lobby.js';
import {
  CsrfTokens,
  HitLimiter,
  MESSAGE_CSP,
  PasswordGate,
  SETUP_COOKIE,
  SETUP_CSP,
  SETUP_LIMITS,
  checkNewPassword,
  clearSetupCookie,
  messagePage,
  setupCookie,
  setupPage,
  type PasswordMode,
} from './setup.js';
import { iceServers } from './turn.js';

/** Content-Security-Policy of the engine pages: same-origin only, plus compiling the translated game (wasm). */
export const SITE_CSP =
  "default-src 'self'; script-src 'self' 'wasm-unsafe-eval'; worker-src 'self'; connect-src 'self'; " +
  "img-src 'self' data: blob:; style-src 'self'; object-src 'none'; base-uri 'none'; form-action 'self'; frame-ancestors 'none'";

const COMMON_HEADERS: Record<string, string> = {
  'X-Content-Type-Options': 'nosniff',
  'Referrer-Policy': 'no-referrer',
  'X-Frame-Options': 'DENY',
  'Cross-Origin-Opener-Policy': 'same-origin',
};

export interface App {
  server: Server;
  lobby: Lobby;
  sessions: Sessions;
  url: string;
  /** Where the password comes from now: the environment, the state file, or none yet (setup open or closed). */
  passwordMode(): PasswordMode;
  close(): Promise<void>;
}

/** For tests: the clock (setup window, sessions) and where the log lines go. */
export interface StartOptions {
  now?: () => number;
  log?: (message: string) => void;
}

function readBody(req: IncomingMessage, limit: number): Promise<string | null> {
  return new Promise((resolve) => {
    let size = 0;
    const chunks: Buffer[] = [];
    req.on('data', (c: Buffer) => {
      size += c.length;
      if (size > limit) {
        resolve(null);
        req.destroy();
        return;
      }
      chunks.push(c);
    });
    req.on('end', () => resolve(Buffer.concat(chunks).toString('utf8')));
    req.on('error', () => resolve(null));
  });
}

/** The origin requests must come from: the configured public URL, else the request's own host. */
function originAllowed(req: IncomingMessage, cfg: ServerConfig): boolean {
  const origin = req.headers.origin;
  if (!origin) return false;
  if (cfg.publicUrl) return origin === new URL(cfg.publicUrl).origin;
  try {
    return new URL(origin).host === req.headers.host;
  } catch {
    return false;
  }
}

/** A form POST from our own page: Sec-Fetch-Site (when sent) says same-origin, Origin (when sent) is ours. */
function sameOriginPost(req: IncomingMessage, cfg: ServerConfig): boolean {
  const site = req.headers['sec-fetch-site'];
  if (site !== undefined && site !== 'same-origin') return false;
  return req.headers.origin === undefined || originAllowed(req, cfg);
}

export async function startServer(cfg: ServerConfig, opts: StartOptions = {}): Promise<App> {
  const now = opts.now ?? Date.now;
  const log = opts.log ?? ((m: string) => console.log(`mvp-server: ${m}`));
  const gate = new PasswordGate({
    envPassword: cfg.password,
    stateFile: cfg.stateFile,
    windowMs: cfg.setupHours * 3600_000,
    now,
    log,
  });
  const csrf = new CsrfTokens(now);
  const setupPerAddress = new HitLimiter(SETUP_LIMITS.requestsPerAddress, SETUP_LIMITS.windowMs, now);
  const setupPostsPerAddress = new HitLimiter(SETUP_LIMITS.submissionsPerAddress, SETUP_LIMITS.windowMs, now);
  const setupPostsGlobal = new HitLimiter(SETUP_LIMITS.submissionsGlobal, SETUP_LIMITS.windowMs, now);
  const sessions = new Sessions(cfg.sessionHours, now);
  const limiter = new LoginLimiter(cfg.loginAttempts);
  let baseUrl = cfg.publicUrl;
  const lobby = new Lobby({
    invite: (room) => `${baseUrl}/?room=${room}`,
    ice: () => iceServers(cfg, Date.now()),
    idleMinutes: cfg.roomIdleMinutes,
  });
  const wss = new WebSocketServer({ noServer: true, maxPayload: 64 * 1024 });

  const loggedIn = (req: IncomingMessage) => sessions.valid(parseCookies(req.headers.cookie).get(COOKIE));

  /** GET/POST /setup: the first-run password form (404 once a password exists; src/setup.ts). */
  const handleSetup = async (req: IncomingMessage, res: ServerResponse, method: string): Promise<void> => {
    const notFound = () => res.writeHead(404, { 'Content-Type': 'text/plain; charset=utf-8' }).end('not found');
    const mode = gate.mode;
    if (mode === 'env' || mode === 'stored') {
      notFound();
      return;
    }
    const html = (status: number, csp: string, body: string, extra: Record<string, string | string[]> = {}) =>
      res
        .writeHead(status, {
          'Content-Type': 'text/html; charset=utf-8',
          'Cache-Control': 'no-store',
          'Content-Security-Policy': csp,
          ...extra,
        })
        .end(body);
    const message = (status: number, title: string, text: string, extra: Record<string, string | string[]> = {}) =>
      html(status, MESSAGE_CSP, messagePage(title, text), extra);
    const closedPage = () => {
      gate.logClosed();
      message(403, 'Setup is closed', 'The setup window for this server has closed, so no password can be created. The server operator has to reopen setup.');
    };
    // The setup pages send a same-origin Referrer-Policy, so the browser's form POST carries our own Origin
    // (under the site-wide "no-referrer" it would say "null").
    res.setHeader('Referrer-Policy', 'same-origin');
    if (mode === 'closed') {
      closedPage();
      return;
    }
    if (method !== 'GET' && method !== 'HEAD' && method !== 'POST') {
      res.writeHead(405, { Allow: 'GET, HEAD, POST' }).end();
      return;
    }
    const addr = clientAddress(req, cfg.trustProxy);
    if (
      !setupPerAddress.allow(addr) ||
      (method === 'POST' && !(setupPostsPerAddress.allow(addr) && setupPostsGlobal.allow('*')))
    ) {
      message(429, 'Too many requests', 'Too many setup requests. Try again in 15 minutes.', { 'Retry-After': String(SETUP_LIMITS.windowMs / 1000) });
      return;
    }
    const cookieId = parseCookies(req.headers.cookie).get(SETUP_COOKIE);
    const id = CsrfTokens.validId(cookieId) ? cookieId : csrf.newId();
    const form = (status: number, error: string) =>
      html(status, SETUP_CSP, setupPage(csrf.issue(id), error), { 'Set-Cookie': setupCookie(id, cfg.secureCookies) });
    if (method !== 'POST') {
      form(200, '');
      return;
    }
    if (!sameOriginPost(req, cfg)) {
      message(403, 'Refused', 'This form must be sent from the setup page of this site.');
      return;
    }
    const body = await readBody(req, 8192);
    if (body === null) {
      message(413, 'Refused', 'The form was too large.');
      return;
    }
    const fields = new URLSearchParams(body);
    if (!csrf.verify(cookieId, fields.get('csrf'))) {
      form(403, 'The form had expired or did not come from this page. Fill it in again.');
      return;
    }
    const password = fields.get('password') ?? '';
    const problem = checkNewPassword(password, fields.get('confirm') ?? '');
    if (problem) {
      form(400, problem);
      return;
    }
    let result: Awaited<ReturnType<PasswordGate['claim']>>;
    try {
      result = await gate.claim(password);
    } catch (e) {
      log(`setup: could not store the password (${(e as Error).message}); setup stays open`);
      message(500, 'Could not save', 'The password could not be saved. See the server log.');
      return;
    }
    if (result === 'done') {
      notFound();
    } else if (result === 'closed') {
      closedPage();
    } else if (result === 'busy') {
      message(503, 'Busy', 'Another submission is being processed. Try again in a moment.', { 'Retry-After': '5' });
    } else {
      const token = sessions.create();
      res
        .writeHead(303, {
          Location: '/',
          'Set-Cookie': [sessionCookie(token, cfg.sessionHours, cfg.secureCookies), clearSetupCookie(cfg.secureCookies)],
          'Cache-Control': 'no-store',
        })
        .end();
    }
  };

  const handle = async (req: IncomingMessage, res: ServerResponse): Promise<void> => {
    for (const [k, v] of Object.entries(COMMON_HEADERS)) res.setHeader(k, v);
    let url: URL;
    try {
      url = new URL(req.url ?? '/', 'http://localhost');
      decodeURIComponent(url.pathname);
    } catch {
      res.writeHead(400).end();
      return;
    }
    const path = decodeURIComponent(url.pathname);
    const method = req.method ?? 'GET';

    if (path === '/healthz') {
      res.writeHead(200, { 'Content-Type': 'text/plain', 'Cache-Control': 'no-store' }).end('ok');
      return;
    }
    if (path === '/setup') {
      await handleSetup(req, res, method);
      return;
    }
    if (gate.needsSetup) {
      // Setup open or closed: there is no password to log in with, so nothing else is served.
      const closed = gate.mode === 'closed';
      if (closed) gate.logClosed();
      if (isNavigation(req)) {
        if (closed) {
          res
            .writeHead(503, { 'Content-Type': 'text/html; charset=utf-8', 'Cache-Control': 'no-store', 'Content-Security-Policy': MESSAGE_CSP })
            .end(messagePage('Not set up', 'This server has no password and its first-run setup window has closed. The server operator has to reopen setup.'));
        } else {
          res.writeHead(303, { Location: '/setup', 'Cache-Control': 'no-store' }).end();
        }
      } else {
        res
          .writeHead(503, { 'Content-Type': 'application/json', 'Cache-Control': 'no-store' })
          .end(closed ? '{"error":"server not set up"}' : '{"error":"setup required"}');
      }
      return;
    }
    if (path === '/login') {
      const loginCsp = `default-src 'none'; style-src ${LOGIN_CSS_HASH}; img-src data:; form-action 'self'; frame-ancestors 'none'; base-uri 'none'`;
      const page = (status: number, next: string, error: string) =>
        res
          .writeHead(status, { 'Content-Type': 'text/html; charset=utf-8', 'Cache-Control': 'no-store', 'Content-Security-Policy': loginCsp })
          .end(loginPage(next, error));
      if (method === 'GET') {
        page(200, safeNext(url.searchParams.get('next')), '');
        return;
      }
      if (method !== 'POST') {
        res.writeHead(405, { Allow: 'GET, POST' }).end();
        return;
      }
      const addr = clientAddress(req, cfg.trustProxy);
      if (limiter.blocked(addr)) {
        page(429, '/', 'Too many attempts. Try again in 15 minutes.');
        return;
      }
      const body = await readBody(req, 4096);
      const form = new URLSearchParams(body ?? '');
      const next = safeNext(form.get('next'));
      const ok = body === null ? false : await gate.verify(form.get('password') ?? '');
      if (ok === 'busy') {
        page(503, next, 'Busy. Try again in a moment.');
        return;
      }
      if (!ok) {
        limiter.fail(addr);
        page(401, next, 'Wrong password.');
        return;
      }
      limiter.succeed(addr);
      const token = sessions.create();
      res.writeHead(303, { Location: next, 'Set-Cookie': sessionCookie(token, cfg.sessionHours, cfg.secureCookies), 'Cache-Control': 'no-store' }).end();
      return;
    }
    if (path === '/logout') {
      if (method !== 'POST' || !originAllowed(req, cfg)) {
        res.writeHead(method === 'POST' ? 403 : 405).end();
        return;
      }
      sessions.remove(parseCookies(req.headers.cookie).get(COOKIE));
      res.writeHead(303, { Location: '/login', 'Set-Cookie': clearCookie(cfg.secureCookies) }).end();
      return;
    }

    // ---- everything below needs a session ----
    if (!loggedIn(req)) {
      if (isNavigation(req)) {
        const next = encodeURIComponent(url.pathname + url.search);
        res.writeHead(303, { Location: `/login?next=${next}`, 'Cache-Control': 'no-store' }).end();
      } else {
        res.writeHead(401, { 'Content-Type': 'application/json', 'Cache-Control': 'no-store' }).end('{"error":"login required"}');
      }
      return;
    }
    if (method !== 'GET' && method !== 'HEAD') {
      res.writeHead(405, { Allow: 'GET, HEAD' }).end();
      return;
    }
    if (path === '/config.json') {
      res
        .writeHead(200, { 'Content-Type': 'application/json', 'Cache-Control': 'private, no-store' })
        .end(cfg.disc ? JSON.stringify({ disc: '/api/disc/image' }) : '{}');
      return;
    }
    if (path === '/api/disc/image') {
      if (!cfg.disc) {
        res.writeHead(404, { 'Cache-Control': 'private, no-store' }).end();
        return;
      }
      await serveDisc(cfg.disc, req, res);
      return;
    }
    if (path === '/api/rooms') {
      res.writeHead(200, { 'Content-Type': 'application/json', 'Cache-Control': 'no-store' }).end(JSON.stringify({ rooms: lobby.list() }));
      return;
    }
    if (path.startsWith('/api/')) {
      res.writeHead(404, { 'Content-Type': 'application/json' }).end('{"error":"not found"}');
      return;
    }
    res.setHeader('Content-Security-Policy', SITE_CSP);
    await serveStatic(cfg.site, path, req, res);
  };

  const server = createServer((req, res) => {
    handle(req, res).catch(() => {
      if (!res.headersSent) res.writeHead(500).end();
      else res.destroy();
    });
  });

  server.on('upgrade', (req, socket, head) => {
    const path = (req.url ?? '').split('?')[0];
    if (path !== '/ws' || !loggedIn(req) || !originAllowed(req, cfg)) {
      socket.write('HTTP/1.1 401 Unauthorized\r\nConnection: close\r\nContent-Length: 0\r\n\r\n');
      socket.destroy();
      return;
    }
    wss.handleUpgrade(req, socket, head, (ws) => {
      const client = lobby.connect(ws);
      let alive = true;
      ws.on('pong', () => (alive = true));
      const ping = setInterval(() => {
        if (!alive) {
          ws.terminate();
          return;
        }
        alive = false;
        ws.ping();
      }, 30_000);
      ws.on('message', (data, isBinary) => {
        if (isBinary) return;
        lobby.handle(client, data.toString());
      });
      ws.on('close', () => {
        clearInterval(ping);
        lobby.leave(client);
      });
    });
  });

  await new Promise<void>((resolve) => server.listen(cfg.port, cfg.host, resolve));
  const addr = server.address() as AddressInfo;
  const local = `http://${addr.address.includes(':') ? `[${addr.address}]` : addr.address}:${addr.port}`;
  if (!baseUrl) baseUrl = local;
  return {
    server,
    lobby,
    sessions,
    url: local,
    passwordMode: () => gate.mode,
    close: () =>
      new Promise<void>((resolve) => {
        for (const ws of wss.clients) ws.terminate();
        wss.close();
        server.closeAllConnections();
        server.close(() => resolve());
      }),
  };
}
