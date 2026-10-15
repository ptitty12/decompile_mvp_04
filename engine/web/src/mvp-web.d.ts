// The engine module that Emscripten builds from wasm/mvp_web.cpp (mvp-web.js).
// Only what the Worker uses; pointers and sizes are numbers.

export interface MvpEngine {
  HEAPU8: Uint8Array;
  UTF8ToString(ptr: number, maxBytes?: number): string;
  specialHTMLTargets: Record<string, unknown>;
  _malloc(size: number): number;
  _free(ptr: number): void;

  _mvp_last_error(): number;
  _mvp_open_disc(size: number): number;
  _mvp_disc_info(): number;
  _mvp_translate(text: number, len: number): number;
  _mvp_translate_info(): number;
  _mvp_boot(script: number, len: number, stopFields: number, stopFrames: number): number;
  _mvp_gfx_init(selector: number, width: number, height: number): void;
  _mvp_canvas_resize(width: number, height: number): void;
  _mvp_run_fields(n: number): number;
  _mvp_present(): number;
  _mvp_set_pad(port: number, connected: number, buttons: number, sx: number, sy: number, cx: number, cy: number,
               tl: number, tr: number): void;
  _mvp_status(): number;
  _mvp_guest_line(): number;

  // E2c: the server's image, the module cache, audio.
  _mvp_open_disc_url(size: number, blockKib: number, maxBlocks: number, maxRun: number, ahead: number): number;
  _mvp_disc_trace_enable(): void;
  _mvp_disc_trace(): number;
  _mvp_disc_want(): number;
  _mvp_disc_want_first(): number;
  _mvp_disc_block(): number;
  _mvp_disc_insert(first: number, count: number, data: number, n: number, ok: number): void;
  _mvp_keep_module(keep: number): void;
  _mvp_module_blob(): number;
  _mvp_module_blob_ptr(): number;
  _mvp_module_bytes_ptr(): number;
  _mvp_module_bytes_len(): number;
  _mvp_module_release(): void;
  _mvp_translate_cached(blob: number, len: number): number;
  _mvp_audio_enable(on: number): void;
  _mvp_audio_take(): number;
  _mvp_audio_ptr(): number;
  _mvp_audio_rate(): number;

  // Netplay (E5, wasm/net_web.cpp).
  _mvp_net_begin(player: number, delay: number, hashEvery: number, build: number, buildLen: number, nonce: number): number;
  _mvp_net_recv(data: number, len: number): void;
  _mvp_net_pump(): number;
  _mvp_net_quit(): void;
  _mvp_net_status(): number;
  _mvp_net_windows(): number;
  _mvp_net_diagnostic(): number;

  // Set by the Worker before the calls that use them.
  mvpDisc?: File;
  mvpDiscUrl?: string;
  mvpOnGfx?: (ok: number, message: string) => void;
  mvpOnProgress?: (text: string, step: number, steps: number) => void;
  mvpNetSend?: (datagram: Uint8Array) => void;
}

export interface MvpEngineOptions {
  print?: (text: string) => void;
  printErr?: (text: string) => void;
}

export default function createMvpEngine(options?: MvpEngineOptions): Promise<MvpEngine>;
