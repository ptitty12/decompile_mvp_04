#!/bin/sh
# Installs the MVP Baseball 2005 netplay deployment on a fresh Debian 12 or
# Ubuntu 24.04 VPS (E5). Run as root from the unpacked package directory:
#
#   ./deploy/install.sh mvp.example.com
#
# - DOMAIN must already resolve to this VPS (Caddy gets its certificate for it).
# - There is no site password to give the script (E5b): a fresh install starts
#   in setup mode with no password, and the owner creates it in the browser on
#   the first visit (https://DOMAIN/ goes to /setup). The password is stored
#   as a scrypt hash in /var/lib/mvp/state.json; nobody else ever handles it.
#   Setup stays open for 48 hours after the server first starts without a
#   password (setupHours in /etc/mvp/server.json), so make the first visit
#   right after installing. To reopen setup later: stop mvp-server, delete
#   /var/lib/mvp/state.json, start it (docs/engine/NETPLAY.md).
# - The disc image is not part of the package: copy it to /srv/mvp/disc/ and
#   set "disc" in /etc/mvp/server.json (the script does this when
#   /srv/mvp/disc/GV4E69.ciso or GV4E69.iso exists).
#
# Idempotent: running it again updates the engine and the server, keeps the
# password (the state file) and the TURN secret.
set -eu

DOMAIN=${1:?usage: install.sh DOMAIN}
NODE_VERSION=24.18.0
HERE=$(cd "$(dirname "$0")/.." && pwd)

if [ -n "${MVP_PASSWORD:-}" ]; then
  echo "install.sh: MVP_PASSWORD is no longer accepted here: the owner creates the site password in the browser on the first visit" >&2
  exit 1
fi
if [ "$(id -u)" -ne 0 ]; then echo "install.sh: run as root" >&2; exit 1; fi

echo "== packages (Caddy, coturn)"
apt-get update -q
DEBIAN_FRONTEND=noninteractive apt-get install -y -q caddy coturn curl xz-utils ca-certificates

echo "== Node.js $NODE_VERSION (official build, checksum verified)"
if [ "$(/usr/local/bin/node --version 2>/dev/null || true)" != "v$NODE_VERSION" ]; then
  ARCH=$(uname -m); case "$ARCH" in x86_64) ARCH=x64;; aarch64) ARCH=arm64;; esac
  TMP=$(mktemp -d)
  curl -fsSL -o "$TMP/node.tar.xz" "https://nodejs.org/dist/v$NODE_VERSION/node-v$NODE_VERSION-linux-$ARCH.tar.xz"
  curl -fsSL -o "$TMP/SHASUMS256.txt" "https://nodejs.org/dist/v$NODE_VERSION/SHASUMS256.txt"
  (cd "$TMP" && grep " node-v$NODE_VERSION-linux-$ARCH.tar.xz\$" SHASUMS256.txt | sed 's/node-v.*/node.tar.xz/' | sha256sum -c -)
  tar -xJf "$TMP/node.tar.xz" -C /usr/local --strip-components=1
  rm -rf "$TMP"
fi

echo "== user and directories"
id mvp >/dev/null 2>&1 || useradd --system --home /opt/mvp --shell /usr/sbin/nologin mvp
install -d -m 0755 /opt/mvp /srv/mvp /srv/mvp/disc
install -d -m 0750 -g mvp /etc/mvp

echo "== engine site and server"
rm -rf /opt/mvp/site.new /opt/mvp/server.new
cp -r "$HERE/site" /opt/mvp/site.new
cp -r "$HERE/server" /opt/mvp/server.new
rm -rf /opt/mvp/site /opt/mvp/server
mv /opt/mvp/site.new /opt/mvp/site
mv /opt/mvp/server.new /opt/mvp/server
chown -R root:root /opt/mvp/site /opt/mvp/server

echo "== secrets (the TURN secret; the site password is created in the browser, not here)"
[ -s /etc/mvp/turn-secret ] || head -c 32 /dev/urandom | base64 | tr -d '/+=' > /etc/mvp/turn-secret
chown root:mvp /etc/mvp/turn-secret
chmod 0640 /etc/mvp/turn-secret

echo "== configuration"
DISC=""
for f in /srv/mvp/disc/GV4E69.ciso /srv/mvp/disc/GV4E69.iso; do [ -f "$f" ] && DISC="$f" && break; done
[ -n "$DISC" ] && chown root:mvp "$DISC" && chmod 0640 "$DISC"
sed -e "s#mvp.example.com#$DOMAIN#g" -e "s#/srv/mvp/disc/GV4E69.ciso#$DISC#" "$HERE/deploy/server.json.example" > /etc/mvp/server.json
cp "$HERE/deploy/server.env.example" /etc/mvp/server.env
# An install made before first-run setup has its password in /etc/mvp/password: keep using it (it wins over
# the stored one) rather than silently opening setup on an already protected site.
if [ -s /etc/mvp/password ]; then
  chown root:mvp /etc/mvp/password
  chmod 0640 /etc/mvp/password
  printf 'MVP_PASSWORD_FILE=/etc/mvp/password\n' >> /etc/mvp/server.env
  echo "   keeping the existing /etc/mvp/password (set before first-run setup existed)"
fi
chown root:mvp /etc/mvp/server.json /etc/mvp/server.env
chmod 0640 /etc/mvp/server.json /etc/mvp/server.env
sed -e "s#<mvp.example.com>#$DOMAIN#g" "$HERE/deploy/Caddyfile.template" > /etc/caddy/Caddyfile
sed -e "s#<mvp.example.com>#$DOMAIN#g" \
    -e "s#<the long random secret, same as MVP_TURN_SECRET>#$(cat /etc/mvp/turn-secret)#" \
    "$HERE/deploy/turnserver.conf.template" > /etc/turnserver.conf
chmod 0640 /etc/turnserver.conf
chown root:turnserver /etc/turnserver.conf 2>/dev/null || true
[ -f /etc/default/coturn ] && sed -i 's/^#\?TURNSERVER_ENABLED=.*/TURNSERVER_ENABLED=1/' /etc/default/coturn

echo "== services"
sed -e "s#/usr/bin/node#/usr/local/bin/node#" "$HERE/deploy/mvp-server.service" > /etc/systemd/system/mvp-server.service
systemctl daemon-reload
systemctl enable --now coturn mvp-server caddy
systemctl restart coturn mvp-server caddy

echo "== firewall (ufw, when present)"
if command -v ufw >/dev/null 2>&1; then
  ufw allow 22/tcp; ufw allow 80/tcp; ufw allow 443/tcp
  ufw allow 3478/udp; ufw allow 3478/tcp; ufw allow 49160:49200/udp
fi

sleep 2
curl -fsS http://127.0.0.1:8080/healthz && echo " <- mvp-server"
echo "== done: https://$DOMAIN/"
# What the first visit will find: the setup form (200), a stored or configured password (404), or a closed window (403).
SETUP=$(curl -s -o /dev/null -w '%{http_code}' http://127.0.0.1:8080/setup || true)
case "$SETUP" in
  200) echo "   first visit: open https://$DOMAIN/ and create the site password (setup is open for 48 hours from the server's first start; do it now)." ;;
  404) echo "   a site password already exists (the stored one, or /etc/mvp/password); setup is closed." ;;
  403) echo "   the setup window has closed and no password exists: stop mvp-server, delete /var/lib/mvp/state.json, start it, then make the first visit." ;;
  *)   echo "   could not read the setup state (HTTP $SETUP): see: journalctl -u mvp-server" ;;
esac
