// The "Server disc" page (deploy): GET /disc, behind the login. The owner picks
// the disc image on their computer and the page uploads it to the server in
// chunks (src/disc_store.ts), resuming where it stopped after a dropped
// connection or a reload (choose the same file again). The server keeps the
// image only if it is GV4E69 revision 0; afterwards /config.json names it and
// every player's browser downloads it once and keeps it (P1: engine/web/src/disc-store.ts).
//
// The page is self-contained: its one style and one script are pinned by hash
// in its Content-Security-Policy. Requests carry the page's CSRF token in the
// X-MVP-CSRF header (bound to the session cookie: src/server.ts).
import { createHash } from 'node:crypto';

import { escapeHtml } from './auth.js';

export const DISC_PAGE_CSS = `:root{color-scheme:dark}
body{font:16px/1.5 system-ui,sans-serif;background:#10141a;color:#e8ecf1;margin:0;padding:16px}
main{max-width:640px;margin:24px auto;display:grid;gap:16px}
.card{background:#1b222c;padding:20px 24px;border-radius:10px;display:grid;gap:10px}
h1{font-size:20px;margin:0}h2{font-size:16px;margin:0}p{margin:0}
.note,small{color:#9aa7b8;font-size:14px}.err{color:#ff8a80}.ok{color:#8fd694}
input,button{font:inherit;padding:8px 10px;border-radius:6px;border:1px solid #3a4553;background:#0f1319;color:inherit;max-width:100%}
button{background:#2f6fde;border-color:#2f6fde;cursor:pointer}button.plain{background:#0f1319;border-color:#3a4553}
button:disabled{opacity:.5;cursor:default}progress{width:100%;height:10px}a{color:#9cc0ff}
.row{display:flex;flex-wrap:wrap;gap:8px;align-items:center}code{word-break:break-all}`;

export const DISC_PAGE_SCRIPT = `(function () {
  'use strict';
  var token = document.querySelector('meta[name="mvp-csrf"]').getAttribute('content');
  function $(id) { return document.getElementById(id); }
  var fileEl = $('file'), startBtn = $('start'), cancelBtn = $('cancel'), bar = $('bar');
  var current = $('current'), pending = $('pending'), msg = $('msg'), progressText = $('progress');
  var status = null, uploading = false, stopRequested = false;
  var MB = 1048576;

  function mb(n) { return (n / MB).toFixed(n < 100 * MB ? 1 : 0) + ' MB'; }
  function say(text, kind) { msg.textContent = text; msg.className = kind || 'note'; }
  function sleep(ms) { return new Promise(function (r) { setTimeout(r, ms); }); }
  function fingerprint(f) { return [f.name, f.size, f.lastModified].join('|'); }

  async function api(method, url, body, type) {
    var headers = { 'X-MVP-CSRF': token };
    if (type) headers['Content-Type'] = type;
    var r = await fetch(url, { method: method, headers: headers, body: body, credentials: 'same-origin', cache: 'no-store' });
    var j = {};
    try { j = await r.json(); } catch (e) { j = {}; }
    j.httpStatus = r.status;
    return j;
  }

  function show() {
    var d = status && status.disc;
    if (d) {
      current.className = 'ok';
      current.textContent = 'The server has the disc: MVP Baseball 2005 (' + d.gameId + ', revision ' + d.revision + '), ' +
        d.format.toUpperCase() + ', ' + mb(d.size) + ', uploaded ' + new Date(d.uploadedAt).toLocaleString() +
        '. Players\\' browsers download it from here once and keep it.';
    } else {
      current.className = 'note';
      current.textContent = 'The server has no disc yet. Until you upload one, the game page tells players that the disc is missing.';
    }
    var u = status && status.upload;
    pending.hidden = !u || uploading;
    if (u) pending.textContent = 'An upload of "' + u.name + '" stopped at ' + mb(u.received) + ' of ' + mb(u.size) +
      '. Choose the same file and press Upload to continue where it stopped.';
  }

  async function refresh() {
    var j = await api('GET', '/api/disc');
    if (j.httpStatus === 401) { say('Your login has expired. Reload the page and log in again.', 'err'); return; }
    if (j.httpStatus !== 200) { say('The server answered HTTP ' + j.httpStatus + '.', 'err'); return; }
    status = j;
    show();
  }

  async function upload(file) {
    var limits = status.limits, u = status.upload;
    if (file.size > limits.maxBytes) throw new Error('This file is larger than a disc image can be.');
    if (!u || u.fingerprint !== fingerprint(file) || u.size !== file.size) {
      var c = await api('POST', '/api/disc/uploads', JSON.stringify({ size: file.size, name: file.name, fingerprint: fingerprint(file) }), 'application/json');
      if (c.httpStatus !== 201) throw new Error(c.error || ('The server answered HTTP ' + c.httpStatus + '.'));
      u = c.upload;
    }
    var offset = u.received, chunk = Math.min(8 * MB, limits.chunkBytes), failures = 0;
    var t0 = performance.now(), sent0 = offset;
    while (offset < file.size) {
      if (stopRequested) return false;
      var end = Math.min(file.size, offset + chunk), t = performance.now(), r;
      try {
        r = await api('PUT', '/api/disc/uploads/' + u.id + '?offset=' + offset, file.slice(offset, end), 'application/octet-stream');
      } catch (e) {
        r = { httpStatus: 0 };
      }
      if (r.httpStatus === 200) {
        offset = r.received;
        failures = 0;
        var took = (performance.now() - t) / 1000;
        if (took > 20 && chunk > MB) chunk = Math.max(MB, chunk / 2);  // a slow line: smaller chunks
        var rate = (offset - sent0) / Math.max(0.001, (performance.now() - t0) / 1000);
        bar.value = offset / file.size;
        progressText.textContent = mb(offset) + ' of ' + mb(file.size) + ' (' + (rate / MB).toFixed(1) + ' MB/s, about ' +
          Math.ceil((file.size - offset) / Math.max(1, rate) / 60) + ' min left)' +
          (r.identity === 'ok' ? '. Checked: this is MVP Baseball 2005, GV4E69 revision 0.' : '.');
        continue;
      }
      if (r.httpStatus === 409 && typeof r.received === 'number') { offset = r.received; await sleep(500); continue; }
      if (r.httpStatus === 401) throw new Error('Your login has expired. Log in again in another tab, then choose the same file to continue.');
      if (r.httpStatus === 404 || r.httpStatus === 413 || r.httpStatus === 422) throw new Error(r.error || ('HTTP ' + r.httpStatus));
      if (++failures > 10) throw new Error('The connection keeps failing. Choose the same file again later to continue where it stopped.');
      progressText.textContent = 'The connection failed; trying again (' + failures + ' of 10)...';
      await sleep(Math.min(30000, 1000 * Math.pow(2, failures)));
    }
    progressText.textContent = 'Checking the complete image on the server...';
    var f = await api('POST', '/api/disc/uploads/' + u.id + '/finish');
    if (f.httpStatus !== 200) throw new Error(f.error || ('The server answered HTTP ' + f.httpStatus + '.'));
    status = f;
    return true;
  }

  fileEl.addEventListener('change', function () {
    startBtn.disabled = !fileEl.files || !fileEl.files.length;
    say('');
  });
  startBtn.addEventListener('click', async function () {
    var file = fileEl.files && fileEl.files[0];
    if (!file || uploading) return;
    uploading = true; stopRequested = false;
    startBtn.disabled = true; fileEl.disabled = true; cancelBtn.hidden = false; cancelBtn.disabled = false;
    bar.hidden = false; bar.value = 0;
    say('Uploading. Keep this page open; you can keep playing in another tab.');
    show();
    try {
      await refresh();
      if (await upload(file)) {
        bar.value = 1;
        progressText.textContent = '';
        say('Done. The server keeps the disc; players\\' browsers download it from here once and keep it.', 'ok');
      } else {
        await refresh();
        var u = status && status.upload;
        if (u) await api('DELETE', '/api/disc/uploads/' + u.id);
        progressText.textContent = '';
        bar.hidden = true;
        say('Upload cancelled; the server deleted the part it had received.');
      }
    } catch (e) {
      say(e.message, 'err');
    }
    uploading = false;
    startBtn.disabled = !fileEl.files || !fileEl.files.length; fileEl.disabled = false; cancelBtn.hidden = true;
    await refresh().catch(function () {});
  });
  cancelBtn.addEventListener('click', function () {
    stopRequested = true;
    cancelBtn.disabled = true;
    say('Stopping after the current chunk...');
  });
  window.addEventListener('beforeunload', function (e) { if (uploading) e.preventDefault(); });
  refresh().catch(function (e) { say(String(e), 'err'); });
})();`;

const sha = (s: string) => `'sha256-${createHash('sha256').update(s).digest('base64')}'`;
/** CSP of the Server disc page: its one style and one script by hash; requests to this site only. */
export const DISC_PAGE_CSP =
  `default-src 'none'; style-src ${sha(DISC_PAGE_CSS)}; script-src ${sha(DISC_PAGE_SCRIPT)}; connect-src 'self'; ` +
  `img-src data:; form-action 'none'; frame-ancestors 'none'; base-uri 'none'`;

export function discPage(csrf: string): string {
  return `<!doctype html><html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<meta name="robots" content="noindex"><meta name="mvp-csrf" content="${escapeHtml(csrf)}">
<title>Server disc - MVP Baseball 2005</title><link rel="icon" href="data:,"><style>${DISC_PAGE_CSS}</style></head><body><main>
<div class="card"><h1>Server disc</h1><p id="current" class="note">Asking the server...</p></div>
<div class="card"><h2>Upload the disc image</h2>
<p class="note">Your own copy of MVP Baseball 2005 for GameCube, USA (GV4E69), as an ISO or CISO file (about 1.4 GB).
The server checks that it is that game, revision 0, and keeps nothing else. The current disc is replaced only once the
new one is complete and checked. If the upload stops, choose the same file again: it continues where it stopped.</p>
<p id="pending" class="note" hidden></p>
<div class="row"><input id="file" type="file" accept=".iso,.ciso,.gcm"><button id="start" type="button" disabled>Upload</button>
<button id="cancel" class="plain" type="button" hidden>Cancel</button></div>
<progress id="bar" max="1" value="0" hidden></progress><small id="progress" aria-live="polite"></small>
<p id="msg" class="note" role="status"></p></div>
<p><a href="/">Back to the game</a></p>
</main><script>${DISC_PAGE_SCRIPT}</script></body></html>`;
}
