// The VPS server (E5): one Node process behind a TLS reverse proxy.
//
//   GET  /login, POST /login, POST /logout   the password gate (src/auth.ts)
//   GET  /healthz                            "ok" (no login; for monitoring)
//   GET  /config.json                        {"disc":"/api/disc/image"} or {}
//   GET/HEAD /api/disc/image                 the owner's disc image (src/files.ts)
//   GET  /api/rooms                          open rooms (src/lobby.ts)
//   WS   /ws                                 lobby and WebRTC signaling
//   GET  anything else                       the engine site (static files)
//
// Everything except /login and /healthz needs the session cookie: a page load
// without it is sent to the login form, anything else gets 401.
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
  passwordMatches,
  safeNext,
  sessionCookie,
} from './auth.js';
import type { ServerConfig } from './config.js';
import { serveDisc, serveStatic } from './files.js';
import { Lobby } from './lobby.js';
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
  close(): Promise<void>;
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

export async function startServer(cfg: ServerConfig): Promise<App> {
  const sessions = new Sessions(cfg.sessionHours);
  const limiter = new LoginLimiter(cfg.loginAttempts);
  let baseUrl = cfg.publicUrl;
  const lobby = new Lobby({
    invite: (room) => `${baseUrl}/?room=${room}`,
    ice: () => iceServers(cfg, Date.now()),
    idleMinutes: cfg.roomIdleMinutes,
  });
  const wss = new WebSocketServer({ noServer: true, maxPayload: 64 * 1024 });

  const loggedIn = (req: IncomingMessage) => sessions.valid(parseCookies(req.headers.cookie).get(COOKIE));

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
    if (path === '/login') {
      const loginCsp = `default-src 'none'; style-src ${LOGIN_CSS_HASH}; form-action 'self'; frame-ancestors 'none'; base-uri 'none'`;
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
      if (body === null || !passwordMatches(form.get('password') ?? '', cfg.password)) {
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
    close: () =>
      new Promise<void>((resolve) => {
        for (const ws of wss.clients) ws.terminate();
        wss.close();
        server.closeAllConnections();
        server.close(() => resolve());
      }),
  };
}
