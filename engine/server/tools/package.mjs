// Assembles the ready-to-deploy package (E5):
//
//   node engine/server/tools/package.mjs [--site DIR] [--out DIR]
//
// build/engine/deploy/mvp-netplay/ (and mvp-netplay.tar.gz next to it):
//   site/      the built engine (build/engine/emscripten/web/site): no game data
//   server/    dist/src (compiled), package.json, package-lock.json and the one
//              runtime dependency (node_modules/ws, MIT, with its license)
//   deploy/    install.sh and the templates (Caddy, coturn, systemd, config)
//   MANIFEST.txt  every file with its SHA-256
// Needs `npm ci && npm run build` in engine/server and the mvp-web target built.
// The disc image is never part of the package.
import { createHash } from 'node:crypto';
import { cpSync, existsSync, mkdirSync, readdirSync, readFileSync, rmSync, statSync, writeFileSync } from 'node:fs';
import { spawnSync } from 'node:child_process';
import { join, relative, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';

const here = fileURLToPath(new URL('.', import.meta.url));
const serverDir = resolve(here, '..');
const repo = resolve(serverDir, '..', '..');
const argv = process.argv.slice(2);
const opt = (name, fallback) => {
  const i = argv.indexOf(name);
  return i >= 0 && i + 1 < argv.length ? argv[i + 1] : fallback;
};
const site = resolve(opt('--site', join(repo, 'build', 'engine', 'emscripten', 'web', 'site')));
const outRoot = resolve(opt('--out', join(repo, 'build', 'engine', 'deploy')));
const pkg = join(outRoot, 'mvp-netplay');

for (const need of [join(site, 'index.html'), join(site, 'mvp-web.wasm'), join(serverDir, 'dist', 'src', 'main.js'),
                    join(serverDir, 'node_modules', 'ws', 'package.json')]) {
  if (!existsSync(need)) {
    console.error(`package: missing ${need} (build mvp-web; npm ci && npm run build in engine/server)`);
    process.exit(2);
  }
}
// Nothing game-derived may be in the site: only the engine's own file types.
const allowed = /\.(html|css|js|wasm|txt|json|svg|png|ico)$/i;
const walk = (dir) => readdirSync(dir).flatMap((n) => {
  const p = join(dir, n);
  return statSync(p).isDirectory() ? walk(p) : [p];
});
for (const f of walk(site)) {
  if (!allowed.test(f)) {
    console.error(`package: unexpected file in the site: ${f}`);
    process.exit(2);
  }
}

rmSync(pkg, { recursive: true, force: true });
mkdirSync(pkg, { recursive: true });
cpSync(site, join(pkg, 'site'), { recursive: true });
mkdirSync(join(pkg, 'server', 'dist'), { recursive: true });
cpSync(join(serverDir, 'dist', 'src'), join(pkg, 'server', 'dist', 'src'), { recursive: true });
for (const f of ['package.json', 'package-lock.json']) cpSync(join(serverDir, f), join(pkg, 'server', f));
cpSync(join(serverDir, 'node_modules', 'ws'), join(pkg, 'server', 'node_modules', 'ws'), { recursive: true });
cpSync(join(serverDir, 'deploy'), join(pkg, 'deploy'), { recursive: true });

const files = walk(pkg).sort();
const manifest = files.map((f) => `${createHash('sha256').update(readFileSync(f)).digest('hex')}  ${relative(pkg, f).replaceAll('\\', '/')}`);
writeFileSync(join(pkg, 'MANIFEST.txt'), manifest.join('\n') + '\n');
const tar = spawnSync('tar', ['-czf', 'mvp-netplay.tar.gz', 'mvp-netplay'], { cwd: outRoot, stdio: 'inherit' });
const tgz = join(outRoot, 'mvp-netplay.tar.gz');
console.log(`package: ${pkg} (${files.length} files)`);
if (tar.status === 0 && existsSync(tgz))
  console.log(`package: ${tgz} (${statSync(tgz).size} bytes, sha256 ${createHash('sha256').update(readFileSync(tgz)).digest('hex')})`);
