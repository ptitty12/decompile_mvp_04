// The lobby and WebRTC signaling (E5): rooms of two players, invite links, and a
// relay for the offer, answer and ICE candidates between the two pages of a
// room. Protocol: src/lobby_protocol.d.ts. Everything is in memory.
import { randomBytes } from 'node:crypto';
import type { WebSocket } from 'ws';

import type { ClientMsg, IceServer, RoomInfo, ServerMsg, SignalData } from './lobby_protocol.js';

const ROOM_ALPHABET = 'abcdefghjkmnpqrstuvwxyz23456789';  // no look-alikes
const MAX_SDP = 32 * 1024;
const MAX_CANDIDATE = 2048;
const MAX_NAME = 40;
const MAX_ROOMS = 64;

export function newRoomId(): string {
  const bytes = randomBytes(12);
  let s = '';
  for (const b of bytes) s += ROOM_ALPHABET[b % ROOM_ALPHABET.length];
  return s;
}

/** Parses and checks a client message; null when it is not a valid ClientMsg. */
export function parseClientMsg(text: string): ClientMsg | null {
  let m: unknown;
  try {
    m = JSON.parse(text);
  } catch {
    return null;
  }
  if (typeof m !== 'object' || m === null) return null;
  const o = m as Record<string, unknown>;
  switch (o.t) {
    case 'create': {
      if (o.name !== undefined && (typeof o.name !== 'string' || o.name.length > MAX_NAME)) return null;
      if (o.delay !== undefined && (!Number.isInteger(o.delay) || (o.delay as number) < 0 || (o.delay as number) > 10)) return null;
      return { t: 'create', name: o.name as string | undefined, delay: o.delay as number | undefined };
    }
    case 'join':
      return typeof o.room === 'string' && /^[a-z0-9]{4,32}$/.test(o.room) ? { t: 'join', room: o.room } : null;
    case 'signal': {
      const d = parseSignal(o.data);
      return d ? { t: 'signal', data: d } : null;
    }
    case 'leave':
      return { t: 'leave' };
    case 'list':
      return { t: 'list' };
    default:
      return null;
  }
}

function parseSignal(v: unknown): SignalData | null {
  if (typeof v !== 'object' || v === null) return null;
  const o = v as Record<string, unknown>;
  if (o.kind === 'offer' || o.kind === 'answer') {
    return typeof o.sdp === 'string' && o.sdp.length <= MAX_SDP ? { kind: o.kind, sdp: o.sdp } : null;
  }
  if (o.kind === 'candidate') {
    if (o.candidate === null) return { kind: 'candidate', candidate: null };
    if (typeof o.candidate !== 'object') return null;
    const c = o.candidate as Record<string, unknown>;
    if (typeof c.candidate !== 'string' || c.candidate.length > MAX_CANDIDATE) return null;
    if (c.sdpMid !== undefined && c.sdpMid !== null && (typeof c.sdpMid !== 'string' || c.sdpMid.length > 64)) return null;
    if (c.sdpMLineIndex !== undefined && c.sdpMLineIndex !== null && !Number.isInteger(c.sdpMLineIndex)) return null;
    return {
      kind: 'candidate',
      candidate: {
        candidate: c.candidate,
        sdpMid: (c.sdpMid as string | null | undefined) ?? null,
        sdpMLineIndex: (c.sdpMLineIndex as number | null | undefined) ?? null,
      },
    };
  }
  return null;
}

interface Room {
  id: string;
  name: string;
  created: number;
  delay: number;
  players: [Client | null, Client | null];
  idleSince: number;  // when it last became empty
}

export interface Client {
  ws: WebSocket;
  room: Room | null;
  player: 1 | 2 | 0;
}

export interface LobbyOptions {
  invite: (room: string) => string;  // the invite link of a room
  ice: () => IceServer[];
  idleMinutes: number;
  now?: () => number;
}

export class Lobby {
  private readonly rooms = new Map<string, Room>();
  private readonly now: () => number;
  constructor(private readonly opt: LobbyOptions) {
    this.now = opt.now ?? Date.now;
  }

  private send(c: Client, m: ServerMsg): void {
    if (c.ws.readyState === c.ws.OPEN) c.ws.send(JSON.stringify(m));
  }
  private error(c: Client, code: string, message: string): void {
    this.send(c, { t: 'error', code, message });
  }
  private other(c: Client): Client | null {
    if (!c.room || !c.player) return null;
    return c.room.players[c.player === 1 ? 1 : 0];
  }

  /** A new connection: gets the ICE servers. */
  connect(ws: WebSocket): Client {
    const c: Client = { ws, room: null, player: 0 };
    this.send(c, { t: 'welcome', v: 1, iceServers: this.opt.ice() });
    return c;
  }

  list(): RoomInfo[] {
    this.sweep();
    const out: RoomInfo[] = [];
    for (const r of this.rooms.values())
      out.push({ room: r.id, name: r.name, created: r.created, players: r.players.filter(Boolean).length, delay: r.delay });
    return out.sort((a, b) => b.created - a.created);
  }

  /** Removes rooms that have been empty for too long. */
  sweep(): void {
    const cutoff = this.now() - this.opt.idleMinutes * 60_000;
    for (const [id, r] of this.rooms)
      if (!r.players[0] && !r.players[1] && r.idleSince <= cutoff) this.rooms.delete(id);
  }

  handle(c: Client, text: string): void {
    const m = parseClientMsg(text);
    if (!m) {
      this.error(c, 'bad-message', 'unknown or malformed message');
      return;
    }
    switch (m.t) {
      case 'create': {
        this.leave(c);
        this.sweep();
        if (this.rooms.size >= MAX_ROOMS) {
          this.error(c, 'full', 'too many rooms');
          return;
        }
        const id = newRoomId();
        const room: Room = {
          id,
          name: (m.name ?? '').trim() || 'Game',
          created: this.now(),
          delay: m.delay ?? 3,
          players: [c, null],
          idleSince: 0,
        };
        this.rooms.set(id, room);
        c.room = room;
        c.player = 1;
        this.send(c, { t: 'room', room: id, player: 1, invite: this.opt.invite(id), delay: room.delay, peer: false });
        return;
      }
      case 'join': {
        const room = this.rooms.get(m.room);
        if (!room) {
          this.error(c, 'no-room', 'this game does not exist (any more)');
          return;
        }
        if (c.room === room) return;
        if (room.players[0] && room.players[1]) {
          this.error(c, 'room-full', 'this game already has two players');
          return;
        }
        const slot: 0 | 1 = room.players[0] ? 1 : 0;
        this.leave(c);
        room.players[slot] = c;
        c.room = room;
        c.player = slot === 0 ? 1 : 2;
        const other = this.other(c);
        this.send(c, { t: 'room', room: room.id, player: c.player, invite: this.opt.invite(room.id), delay: room.delay, peer: !!other });
        if (other) this.send(other, { t: 'peer', present: true });
        return;
      }
      case 'signal': {
        const other = this.other(c);
        if (!other) {
          this.error(c, 'no-peer', 'nobody to signal');
          return;
        }
        this.send(other, { t: 'signal', data: m.data });
        return;
      }
      case 'leave':
        this.leave(c);
        return;
      case 'list':
        this.send(c, { t: 'rooms', rooms: this.list() });
        return;
    }
  }

  /** The client leaves its room (also on disconnect); the other player is told. */
  leave(c: Client): void {
    const room = c.room;
    if (!room || !c.player) return;
    const other = this.other(c);
    room.players[c.player - 1] = null;
    c.room = null;
    c.player = 0;
    if (other) this.send(other, { t: 'peer', present: false });
    if (!room.players[0] && !room.players[1]) room.idleSince = this.now();
  }
}
