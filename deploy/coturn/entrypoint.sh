#!/bin/sh
# coturn for the MVP Baseball 2005 deployment (deploy/docker-compose.yml).
#
# STUN tells each player's browser its public address, so the two browsers can
# connect directly; the TURN relay carries the game's few KB/s for players whose
# networks block that. Credentials are never stored: mvp-server hands each page
# time-limited ones derived from a shared secret (coturn's "TURN REST API" mode,
# use-auth-secret), and that secret is the file mvp-server generated on its
# first start in the mvp-data volume, mounted here read-only.
#
# Environment (all optional; deploy/docker-compose.yml passes them from Dokploy):
#   TURN_MODE         relay (STUN and TURN, the default), stun (STUN only), off (coturn idles)
#   TURN_EXTERNAL_IP  the server's public IPv4 address; detected when empty (DNS, the upstream image's tool)
set -eu

mode=${TURN_MODE:-relay}
secret_file=/mvp-data/turn/secret
conf=/tmp/turnserver.conf

case "$mode" in
  relay | stun) ;;
  off)
    echo "coturn: TURN_MODE=off: no STUN and no relay (players connect directly on one network only)"
    # Stay up doing nothing, so the restart policy does not start this container over and over.
    exec sleep infinity
    ;;
  *)
    echo "coturn: TURN_MODE must be relay, stun or off (it is '$mode')" >&2
    exit 1
    ;;
esac

ip=${TURN_EXTERNAL_IP:-}
if [ -z "$ip" ]; then
  ip=$(detect-external-ip 2>/dev/null || true)
  if [ -n "$ip" ]; then
    echo "coturn: detected public address $ip (set TURN_EXTERNAL_IP to choose it)"
  else
    echo "coturn: could not detect the public address; set TURN_EXTERNAL_IP to the server's public IPv4 address" >&2
  fi
fi
if [ -n "$ip" ] && ! printf '%s' "$ip" | grep -Eq '^[0-9a-fA-F.:]+$'; then
  echo "coturn: TURN_EXTERNAL_IP '$ip' is not an IP address" >&2
  exit 1
fi

umask 077
{
  echo "listening-port=3478"
  echo "realm=mvp"
  echo "fingerprint"
  echo "no-tls"
  echo "no-software-attribute"
  echo "no-rfc5780"
  echo "response-origin-only-with-rfc5780"
  echo "log-file=stdout"
  echo "simple-log"
  echo "pidfile=/tmp/turnserver.pid"
  [ -z "$ip" ] || echo "external-ip=$ip"
} > "$conf"

if [ "$mode" = stun ]; then
  echo "stun-only" >> "$conf"
  echo "coturn: STUN only (no relay)"
else
  # mvp-server creates the secret on its first start (compose starts coturn after mvp is healthy).
  waited=0
  while [ ! -s "$secret_file" ]; do
    if [ "$waited" -ge 120 ]; then
      echo "coturn: no TURN secret at $secret_file after 120 s (is the mvp service running with TURN_MODE=relay?)" >&2
      exit 1
    fi
    sleep 2
    waited=$((waited + 2))
  done
  secret=$(tr -d '\r\n' < "$secret_file")
  {
    echo "use-auth-secret"
    echo "static-auth-secret=$secret"
    # Relay ports (published on the host by deploy/docker-compose.yml): two players need a handful.
    echo "min-port=49160"
    echo "max-port=49200"
    echo "total-quota=32"
    echo "user-quota=8"
    echo "stale-nonce=600"
    # The game uses UDP relays only; no TCP relaying, no multicast.
    echo "no-tcp-relay"
    echo "no-multicast-peers"
    # Never relay into this server, its Docker networks or other private networks.
    for r in 0.0.0.0-0.255.255.255 10.0.0.0-10.255.255.255 100.64.0.0-100.127.255.255 127.0.0.0-127.255.255.255 \
             169.254.0.0-169.254.255.255 172.16.0.0-172.31.255.255 192.0.0.0-192.0.0.255 192.168.0.0-192.168.255.255 \
             198.18.0.0-198.19.255.255 ::1 fc00::-fdff:ffff:ffff:ffff:ffff:ffff:ffff:ffff \
             fe80::-febf:ffff:ffff:ffff:ffff:ffff:ffff:ffff; do
      echo "denied-peer-ip=$r"
    done
  } >> "$conf"
  echo "coturn: STUN and TURN relay (UDP 3478 and 49160-49200, TCP 3478)"
fi

exec turnserver -c "$conf"
