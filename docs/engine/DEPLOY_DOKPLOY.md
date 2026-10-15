# Deploying with Dokploy

How to put the game site on your VPS using only Dokploy's web pages. You don't
need SSH and you don't type any commands. The repository and the Docker image
hold no game data. You upload your disc image through the site after it is
running, and it is kept in the app's private storage on your server.

Technical details for agents are in `deploy/docker-compose.yml`, `deploy/Dockerfile`
and `docs/engine/NETPLAY.md`.

## Before you start

- **A domain or subdomain**, for example `mvp.yourdomain.com`. In your DNS
  provider's web panel, give it an **A record** pointing to the VPS's public IP
  address. If you use Cloudflare, set that record to **DNS only** (grey cloud).
- **The VPS** needs at least 2 GB of memory and about 6 GB of free disk. The first
  deploy compiles the engine, which takes roughly 10 to 20 minutes on a small VPS.

## 1. Create the app

1. In Dokploy, open (or create) a project, then **Create Service → Compose**.
   Name it `mvp2005`, keep the type **Docker Compose**, and create it.
2. Open the **General** tab and choose the **Git** provider:
   - Repository URL: `https://github.com/ptitty12/mvp2005-decomp.git`
   - Branch: `main`
   - Compose Path: `./deploy/docker-compose.yml`

   Click **Save**.

## 2. Domain

Open the **Domains** tab and click **Add Domain**:

| Field | Value |
|---|---|
| Service Name | `mvp` |
| Host | your domain, for example `mvp.yourdomain.com` |
| Path | `/` |
| Container Port | `8080` |
| HTTPS | on |
| Certificate | Let's Encrypt |

Click **Create**. Only `mvp` gets a domain. The other service, `coturn`, uses its
own ports (section 4).

## 3. Settings (optional)

Open the **Environment** tab. Everything works with nothing set. Recommended:

```
TURN_EXTERNAL_IP=<your VPS's public IPv4 address>
```

Other settings, only if you need them:

| Setting | When |
|---|---|
| `TURN_HOST=<VPS IP address>` | Your domain goes through a proxy, such as Cloudflare's orange cloud. |
| `TURN_MODE=stun` or `off` | You want no relay (`stun`), or no STUN and no relay (`off`). The default is `relay`. |
| `SETUP_HOURS=<hours>` | How long the create-password page stays open after the first start. The default is 48. |
| `RESET_PASSWORD=<any new word>` | You forgot the password, or someone else created it. Set a word you haven't used before, then deploy. The password is removed once and the create-password page comes back. |

Click **Save**.

## 4. Firewall

If your VPS provider has a firewall in its web panel, allow these **inbound**
ports so online games can connect through the relay:

- UDP 3478
- TCP 3478
- UDP 49160-49200

Ports 80 and 443 are already open for Dokploy.

## 5. Deploy

On the **General** tab, click **Deploy**. Watch the **Deployments** tab: the first
deploy is done when the log ends without errors and both services (`mvp` and
`coturn`) are running. Later deploys, from the same button, are much faster.

## 6. Create the password (right away)

Open `https://<your domain>/` as soon as the deploy finishes. The first visit
shows **create the password**:

1. Type a password of at least 12 characters twice. A few unrelated words work well.
2. Click **Create the password**. You are now logged in.

If the first visit shows a **login** form instead, someone else created the
password first. Set `RESET_PASSWORD` (section 3), deploy again, and repeat this
step. Until a password exists, nothing else on the site works, and no disc can
be uploaded.

## 7. Upload the disc

1. On the game page, click **Server disc**, or open `https://<your domain>/disc`.
2. Click **Choose file** and pick
   `C:\Users\Patrick Taylor\decompile_mvp_04\orig\GV4E69\MVP Baseball 2005 (USA).ciso`.
3. Click **Upload** and keep the page open. The page shows the progress and the
   time left (about 1.4 GB).

   The server checks the file early and refuses anything that isn't MVP Baseball
   2005, GV4E69 revision 0.

   If the upload stops (lost connection, closed page), choose the same file and
   click **Upload** again. It continues where it stopped.
4. When it says **Done**, the server has the disc. Every player's page now loads it
   from the server, with no file picker.

## 8. Play with your brother

Send your brother the site address and, separately, the password. On the game
page, either of you can:

- press **Play** to play alone; or
- **create a game** and send the invite link. The other player opens the link
  and joins.

## Later

- **Update:** click **Deploy** again. It rebuilds from `main`. The password and
  the disc stay. Both players reload the page afterwards.
- **Online game doesn't connect:** check the firewall ports (section 4), set
  `TURN_EXTERNAL_IP`, and if the domain is proxied, set `TURN_HOST`. Then deploy
  again.
- **Removing everything:** deleting the app in Dokploy with its volumes also
  deletes the stored password and the uploaded disc.
