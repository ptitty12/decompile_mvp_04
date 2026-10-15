// The server image's one-time download into the browser (src/disc-store.ts,
// P1), the parts that run without a browser: the offer in /config.json, the
// manifest check against the advertised image hash, the pieces' ranges and the
// progress text. The Worker that writes OPFS is checked in Chrome
// (tools/browser_check.mjs --real-server).
import assert from 'node:assert/strict';
import { createHash, randomBytes } from 'node:crypto';
import { test } from 'node:test';
import { load } from './site.mjs';

const { checkManifest, pieceRange, progressText, sha256Hex } = await load('disc-store.js');
const { findServerDisc } = await load('disc.js');

const BASE = 'https://mvp.example.test/';
const sha = (b) => createHash('sha256').update(b).digest('hex');
const json = (v) => new Response(JSON.stringify(v), { status: 200, headers: { 'Content-Type': 'application/json' } });
const cfg = (v) => async (url) => (url === `${BASE}config.json` ? json(v) : new Response('', { status: 404 }));

// A manifest as the server builds it (engine/server/src/disc_hash.ts).
function manifestOf(bytes, pieceBytes) {
  const pieces = [];
  for (let at = 0; at < bytes.length; at += pieceBytes) pieces.push(sha(bytes.subarray(at, at + pieceBytes)));
  const hash = sha(Buffer.concat(pieces.map((p) => Buffer.from(p, 'hex'))));
  return { size: bytes.length, pieceBytes, pieces, hash };
}

test('config.json offers the image for download: hash, size and a same-origin manifest', async () => {
  const hash = 'ab'.repeat(32);
  const r = await findServerDisc(BASE, cfg({ disc: '/api/disc/image?v=1', discHash: hash, discSize: 1379959360,
                                             discManifest: '/api/disc/manifest?v=1', discPage: '/disc' }));
  assert.equal(r.kind, 'url');
  assert.deepEqual(r.offer, { url: `${BASE}api/disc/image?v=1`, manifest: `${BASE}api/disc/manifest?v=1`, hash, size: 1379959360 });
  assert.equal(r.discPage, `${BASE}disc`);
  // Anything malformed: no offer (the page reads the image over the network, as before).
  for (const bad of [{ discHash: 'xyz' }, { discSize: -1 }, { discManifest: 'https://elsewhere.test/m' }, { discSize: '5' }]) {
    const b = await findServerDisc(BASE, cfg({ disc: '/api/disc/image', discHash: hash, discSize: 10, discManifest: '/m', ...bad }));
    assert.equal(b.kind, 'url');
    assert.equal(b.offer, undefined, JSON.stringify(bad));
  }
  const prep = await findServerDisc(BASE, cfg({ disc: '/api/disc/image', discPreparing: true }));
  assert.equal(prep.preparing, true);
});

test('a deployment without a disc names its operator page; no picker there', async () => {
  const r = await findServerDisc(BASE, cfg({ discPage: '/disc' }));
  assert.equal(r.kind, 'none');
  assert.equal(r.discPage, `${BASE}disc`);
  assert.equal(r.deployment, true);
  const foreign = await findServerDisc(BASE, cfg({ discPage: 'https://elsewhere.test/disc' }));
  assert.equal(foreign.discPage, undefined);
  const local = await findServerDisc(BASE, async () => new Response('', { status: 404 }));
  assert.equal(local.kind, 'none');
  assert.equal(local.discPage, undefined);
});

test('the manifest must cover the advertised size and hash to the advertised image hash', async () => {
  const bytes = randomBytes(300_000);
  const m = manifestOf(bytes, 65536);
  assert.equal(m.pieces.length, 5);
  assert.deepEqual(await checkManifest(m, m.hash, bytes.length), m);
  assert.match(await checkManifest(m, 'cd'.repeat(32), bytes.length), /do not match the image hash/);
  assert.match(await checkManifest(m, m.hash, bytes.length + 1), /advertised/);
  assert.match(await checkManifest({ ...m, pieces: m.pieces.slice(1) }, m.hash, bytes.length), /cover/);
  const swapped = { ...m, pieces: [m.pieces[1], m.pieces[0], ...m.pieces.slice(2)] };
  assert.match(await checkManifest(swapped, m.hash, bytes.length), /image hash/);
  assert.match(await checkManifest({ ...m, pieces: m.pieces.map((p) => p.toUpperCase()) }, m.hash, bytes.length), /bad piece/);
  assert.match(await checkManifest({ ...m, pieceBytes: 1000 }, m.hash, bytes.length), /piece size/);
  assert.match(await checkManifest(null, m.hash, bytes.length), /advertised/);
});

test('pieces, their hashes and the progress text', async () => {
  const m = { size: 300_000, pieceBytes: 65536, pieces: [], hash: '' };
  assert.deepEqual(pieceRange(m, 0), { start: 0, end: 65536 });
  assert.deepEqual(pieceRange(m, 4), { start: 262144, end: 300_000 });
  const b = new Uint8Array([1, 2, 3]);
  assert.equal(await sha256Hex(b), sha(b));
  assert.equal(progressText(470 * 1048576, 1316 * 1048576, 0), '470 of 1,316 MB');
  assert.equal(progressText(470 * 1048576, 1316 * 1048576, 11.8 * 1048576), '470 of 1,316 MB, 11.8 MB/s, about 72 s left');
  assert.equal(progressText(0, 1316 * 1048576, 5 * 1048576), '0 of 1,316 MB, 5.0 MB/s, about 4 min left');
});
