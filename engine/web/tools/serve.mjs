// Local development server for the browser build (E2): serves the engine's
// static site directory, and nothing else, on localhost.
//
//   node engine/web/tools/serve.mjs [--root DIR] [--port N]
//
// DIR defaults to build/engine/emscripten/web/site (what the "emscripten"
// preset's mvp-web target assembles: the page, the shell, the engine module and
// symbols.txt). It holds no game data: the player's browser reads the disc
// image the player picks, and nothing is ever uploaded here. Only GET and HEAD,
// only files inside DIR, no directory listings. No COOP/COEP headers: the
// engine uses no SharedArrayBuffer. Prints "serving http://127.0.0.1:PORT/" once
// it listens (port 0 picks a free one).

import { createServer } from 'node:http';
import { createReadStream, statSync } from 'node:fs';
import { extname, join, normalize, resolve, sep } from 'node:path';
import { fileURLToPath } from 'node:url';

const here = fileURLToPath(new URL('.', import.meta.url));
const args = process.argv.slice(2);
const arg = (name, fallback) => {
  const i = args.indexOf(name);
  return i >= 0 && i + 1 < args.length ? args[i + 1] : fallback;
};
const root = resolve(arg('--root', join(here, '..', '..', '..', 'build', 'engine', 'emscripten', 'web', 'site')));
const port = Number(arg('--port', '8000'));

const types = {
  '.html': 'text/html; charset=utf-8',
  '.js': 'text/javascript; charset=utf-8',
  '.mjs': 'text/javascript; charset=utf-8',
  '.css': 'text/css; charset=utf-8',
  '.wasm': 'application/wasm',
  '.txt': 'text/plain; charset=utf-8',
  '.json': 'application/json',
  '.png': 'image/png',
  '.svg': 'image/svg+xml',
};

const server = createServer((req, res) => {
  if (req.method !== 'GET' && req.method !== 'HEAD') {
    res.writeHead(405, { Allow: 'GET, HEAD' }).end();
    return;
  }
  let path;
  try {
    path = decodeURIComponent(new URL(req.url ?? '/', 'http://localhost').pathname);
  } catch {
    res.writeHead(400).end();
    return;
  }
  if (path.endsWith('/')) path += 'index.html';
  const file = normalize(join(root, path));
  const type = types[extname(file).toLowerCase()];
  let st;
  try {
    st = file.startsWith(root + sep) && type ? statSync(file) : null;
  } catch {
    st = null;
  }
  if (!st || !st.isFile()) {
    res.writeHead(404, { 'Content-Type': 'text/plain' }).end('not found');
    return;
  }
  res.writeHead(200, {
    'Content-Type': type,
    'Content-Length': st.size,
    'Cache-Control': 'no-store',
    'X-Content-Type-Options': 'nosniff',
  });
  if (req.method === 'HEAD') res.end();
  else createReadStream(file).pipe(res);
});

server.listen(port, '127.0.0.1', () => {
  const { port: p } = server.address();
  console.log(`serving http://127.0.0.1:${p}/ from ${root}`);
});
