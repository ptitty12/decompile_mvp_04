// TURN credentials (E5) for coturn's "TURN REST API" mode (use-auth-secret):
// username = "<expiry unix seconds>:mvp", password = base64(HMAC-SHA1(secret,
// username)). coturn checks them with the same shared secret, so no account is
// ever stored, and leaked credentials stop working at the expiry.
import { createHmac } from 'node:crypto';

import type { ServerConfig } from './config.js';
import type { IceServer } from './lobby_protocol.js';

export function turnCredentials(secret: string, ttlSeconds: number, nowMs: number): { username: string; credential: string } {
  const username = `${Math.floor(nowMs / 1000) + ttlSeconds}:mvp`;
  const credential = createHmac('sha1', secret).update(username).digest('base64');
  return { username, credential };
}

/**
 * The ICE servers handed to a page: STUN, plus TURN with fresh credentials. "{host}" in a URL
 * becomes `host`, the page's host name (the Docker deployment runs coturn on the site's host).
 */
export function iceServers(cfg: Pick<ServerConfig, 'stun' | 'turn'>, nowMs: number, host = ''): IceServer[] {
  const fill = (urls: string[]) => urls.map((u) => u.replaceAll('{host}', host));
  const out: IceServer[] = [];
  if (cfg.stun.length) out.push({ urls: fill(cfg.stun) });
  if (cfg.turn) out.push({ urls: fill(cfg.turn.urls), ...turnCredentials(cfg.turn.secret, cfg.turn.ttlSeconds, nowMs) });
  return out;
}
