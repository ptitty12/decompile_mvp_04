# coturn for the MVP Baseball 2005 deployment (deploy/docker-compose.yml): the
# pinned upstream image (it runs as "nobody") plus an entrypoint that writes
# coturn's configuration from the environment and the shared TURN secret that
# mvp-server generated in the mvp-data volume. Nothing else is added.
FROM coturn/coturn:4.18.0@sha256:bbefd3e1fdfdc0d58770fe01b581fd8b00d9f3a5580d00acb77cf719a6bc78e3
COPY entrypoint.sh /usr/local/share/mvp/coturn-entrypoint.sh
ENTRYPOINT ["/bin/sh", "/usr/local/share/mvp/coturn-entrypoint.sh"]
CMD []
