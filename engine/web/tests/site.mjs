// Where the compiled shell lives for the unit tests (node --test): the site
// directory the build assembles (MVP_WEB_SITE, else the emscripten preset's).
import { join, resolve } from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';

const here = fileURLToPath(new URL('.', import.meta.url));
const site = process.env.MVP_WEB_SITE ??
  resolve(here, '..', '..', '..', 'build', 'engine', 'emscripten', 'web', 'site');

export async function load(name) {
  return import(pathToFileURL(join(site, name)).href);
}
