// The lobby and signaling protocol, version 1 (E5): JSON messages over the
// WebSocket at /ws, between the page (engine/web) and the server. Types only, so
// the page can import them too (`import type`) without a runtime file. The
// server validates every message it receives (src/lobby.ts).
//
// The game itself never goes through the server: once the two pages have a
// WebRTC data channel, the engines talk directly (or through the TURN relay),
// with the netplay wire protocol of engine/net/protocol.h.

export type LobbyVersion = 1;

/** One ICE server for RTCPeerConnection (STUN, or TURN with time-limited credentials). */
export interface IceServer {
  urls: string[];
  username?: string;
  credential?: string;
}

/** What a page sends to its peer through the server (opaque to the server beyond its shape). */
export type SignalData =
  | { kind: 'offer' | 'answer'; sdp: string }
  | { kind: 'candidate'; candidate: { candidate: string; sdpMid?: string | null; sdpMLineIndex?: number | null } | null };

export interface RoomInfo {
  room: string;
  name: string;
  created: number;  // ms since the epoch
  players: number;  // 1 or 2
  delay: number;
}

// ---- page -> server ----
export type ClientMsg =
  | { t: 'create'; name?: string; delay?: number }  // a new room; the creator is player 1 (delay 0: Auto, Q5)
  | { t: 'join'; room: string }                     // join as player 2
  | { t: 'signal'; data: SignalData }               // relayed to the other player in the room
  | { t: 'leave' }
  | { t: 'list' };

// ---- server -> page ----
export type ServerMsg =
  | { t: 'welcome'; v: LobbyVersion; iceServers: IceServer[] }
  | { t: 'room'; room: string; player: 1 | 2; invite: string; delay: number; peer: boolean }
  | { t: 'peer'; present: boolean }  // the other player joined (true) or left (false)
  | { t: 'signal'; data: SignalData }
  | { t: 'rooms'; rooms: RoomInfo[] }
  | { t: 'error'; code: string; message: string };
