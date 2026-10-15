// Roster packs (E6), the part shared by the page's panel (packs.ts), the engine
// Worker (worker.ts) and the unit tests: handing a pack set to the engine's pack
// code (wasm/packs_web.cpp, compiled into both mvp-web and the small mvp-packs
// module) and reading its report. The format is docs/MODDING.md; every check and
// hash is the engine's C++ (engine/mods), the same code the netplay handshake uses.

import type { PackInput, PackSetReport } from './protocol.js';

// The exports both modules have (wasm/packs_web.cpp).
export interface PacksModule {
  HEAPU8: Uint8Array;
  wasmMemory?: WebAssembly.Memory;  // the threaded engine (P2): a shared memory another thread may grow
  UTF8ToString(ptr: number, maxBytes?: number): string;
  _malloc(size: number): number;
  _free(ptr: number): void;
  _mvp_packs_reset(): void;
  _mvp_pack_begin(label: number, len: number, kind: number): void;
  _mvp_pack_file(path: number, len: number, data: number, n: number): void;
  _mvp_pack_end(): void;
  _mvp_packs_json(): number;
  _mvp_packs_mount(): number;
}

// The empty set's hash (MODDING.md §10): what a page without packs sends.
export const EMPTY_SET_HASH = 'f5e1298911db13adf522a1b34d4d4f9291b42fa7a77f63a5f6f07bc322dcc66e';

function withBytes<T>(M: PacksModule, bytes: Uint8Array, f: (ptr: number, len: number) => T): T {
  const ptr = M._malloc(Math.max(1, bytes.length));
  const mem = M.wasmMemory;
  (mem && M.HEAPU8.buffer !== mem.buffer ? new Uint8Array(mem.buffer) : M.HEAPU8).set(bytes, ptr);
  try {
    return f(ptr, bytes.length);
  } finally {
    M._free(ptr);
  }
}

/** Hands `packs` (in set order) to the module and returns its static report. */
export function feedPacks(M: PacksModule, packs: PackInput[]): PackSetReport {
  const enc = new TextEncoder();
  M._mvp_packs_reset();
  for (const p of packs) {
    withBytes(M, enc.encode(p.label), (ptr, n) => M._mvp_pack_begin(ptr, n, p.kind === 'zip' ? 1 : 0));
    for (const f of p.files) {
      withBytes(M, enc.encode(f.path), (pp, pn) =>
        withBytes(M, new Uint8Array(f.data), (dp, dn) => M._mvp_pack_file(pp, pn, dp, dn)));
    }
    M._mvp_pack_end();
  }
  return readReport(M);
}

export function readReport(M: PacksModule): PackSetReport {
  return JSON.parse(M.UTF8ToString(M._mvp_packs_json())) as PackSetReport;
}

/** A short text for an error line: the first errors, then how many more. */
export function summarize(r: PackSetReport, max = 3): string {
  const errors = r.issues.filter((i) => i.severity === 'error');
  const lines = errors.slice(0, max).map((i) => `${i.code} ${i.where}: ${i.message}`);
  if (r.fatal) lines.unshift(r.fatal);
  if (errors.length > max) lines.push(`and ${errors.length - max} more`);
  return lines.join('; ');
}

/** The files of a picked folder or zip, as the engine wants them. */
export async function readPick(files: ArrayLike<File>, kind: 'files' | 'zip'): Promise<PackInput[]> {
  const list = Array.from(files);
  if (kind === 'zip') {
    return Promise.all(list.map(async (f) => ({
      label: f.name, kind: 'zip' as const, files: [{ path: f.name, data: await f.arrayBuffer() }],
    })));
  }
  // A folder: webkitRelativePath is "<folder>/<path inside>"; the engine strips the folder.
  const label = (list[0]?.webkitRelativePath || list[0]?.name || 'pack').split('/')[0] ?? 'pack';
  const out: PackInput = { label, kind: 'files', files: [] };
  for (const f of list) out.files.push({ path: f.webkitRelativePath || f.name, data: await f.arrayBuffer() });
  return [out];
}
