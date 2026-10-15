// Server configuration (E5). Non-secret settings come from a JSON file
// (MVP_SERVER_CONFIG) and environment variables; secrets come only from the
// environment (or files named by it), never from the repository:
//
//   MVP_PASSWORD / MVP_PASSWORD_FILE        the site password (required)
//   MVP_TURN_SECRET / MVP_TURN_SECRET_FILE  coturn's static-auth-secret (optional)
//
// docs/engine/NETPLAY.md ("Deploying on a VPS") has a complete example.
import { readFileSync } from 'node:fs';
import { resolve } from 'node:path';

export interface TurnConfig {
  /** turn:/turns: URLs of the relay, e.g. "turn:turn.example.com:3478?transport=udp". */
  urls: string[];
  /** coturn's static-auth-secret (use-auth-secret): credentials are derived per session. */
  secret: string;
  /** Lifetime of the derived credentials. */
  ttlSeconds: number;
}

export interface ServerConfig {
  host: string;
  port: number;
  /** The built engine site (build/engine/emscripten/web/site). */
  site: string;
  /** The owner's disc image (ISO or CISO), served only behind the login; empty: none. */
  disc: string;
  password: string;
  /** Set the cookie's Secure flag (true behind TLS). */
  secureCookies: boolean;
  /** Take the client address from the last X-Forwarded-For entry (behind a reverse proxy). */
  trustProxy: boolean;
  /** "https://mvp.example.com": invite links and the allowed Origin. Empty: the request's Host. */
  publicUrl: string;
  sessionHours: number;
  stun: string[];
  turn: TurnConfig | null;
  /** Rooms without players are removed after this long. */
  roomIdleMinutes: number;
  /** Failed logins allowed per client address per 15 minutes. */
  loginAttempts: number;
}

export const defaults: Omit<ServerConfig, 'password' | 'site'> = {
  host: '127.0.0.1',
  port: 8080,
  disc: '',
  secureCookies: false,
  trustProxy: false,
  publicUrl: '',
  sessionHours: 24 * 30,
  stun: [],
  turn: null,
  roomIdleMinutes: 30,
  loginAttempts: 10,
};

function secret(env: NodeJS.ProcessEnv, name: string): string {
  const direct = env[name];
  if (direct) return direct;
  const file = env[`${name}_FILE`];
  if (file) return readFileSync(file, 'utf8').trim();
  return '';
}

/** Reads the configuration; throws with a readable message when it is unusable. */
export function loadConfig(env: NodeJS.ProcessEnv = process.env): ServerConfig {
  let file: Record<string, unknown> = {};
  if (env.MVP_SERVER_CONFIG) file = JSON.parse(readFileSync(env.MVP_SERVER_CONFIG, 'utf8')) as Record<string, unknown>;
  const pick = <T>(key: string, envName: string, parse: (s: string) => T, fallback: T): T => {
    if (env[envName] !== undefined && env[envName] !== '') return parse(env[envName]!);
    if (file[key] !== undefined) return file[key] as T;
    return fallback;
  };
  const bool = (s: string) => s === '1' || s === 'true';
  const password = secret(env, 'MVP_PASSWORD');
  if (password.length < 8) throw new Error('MVP_PASSWORD (or MVP_PASSWORD_FILE) must be set, at least 8 characters');
  const site = pick('site', 'MVP_SITE', String, '');
  if (!site) throw new Error('the site directory is not configured (MVP_SITE or "site")');
  const turnFile = file.turn as Partial<TurnConfig> | undefined;
  const turnSecret = secret(env, 'MVP_TURN_SECRET');
  const turn: TurnConfig | null = turnFile?.urls?.length && turnSecret
    ? { urls: turnFile.urls, secret: turnSecret, ttlSeconds: turnFile.ttlSeconds ?? 86400 }
    : null;
  return {
    host: pick('host', 'MVP_HOST', String, defaults.host),
    port: pick('port', 'MVP_PORT', Number, defaults.port),
    site: resolve(site),
    disc: pick('disc', 'MVP_DISC_IMAGE', String, defaults.disc),
    password,
    secureCookies: pick('secureCookies', 'MVP_SECURE_COOKIES', bool, defaults.secureCookies),
    trustProxy: pick('trustProxy', 'MVP_TRUST_PROXY', bool, defaults.trustProxy),
    publicUrl: pick('publicUrl', 'MVP_PUBLIC_URL', String, defaults.publicUrl),
    sessionHours: pick('sessionHours', 'MVP_SESSION_HOURS', Number, defaults.sessionHours),
    stun: (file.stun as string[] | undefined) ?? defaults.stun,
    turn,
    roomIdleMinutes: pick('roomIdleMinutes', 'MVP_ROOM_IDLE_MINUTES', Number, defaults.roomIdleMinutes),
    loginAttempts: pick('loginAttempts', 'MVP_LOGIN_ATTEMPTS', Number, defaults.loginAttempts),
  };
}
