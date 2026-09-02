# Desk Pulse

Live dashboard: **https://claude.ai/code/artifact/5d21a0b1-b62f-46da-8162-1906ae00fe4c**

## To pin it to your Windows taskbar

The live data (inbox, calendar, jobs, Drive) only works when this page runs on
claude.ai's own domain — that's where `window.claude` (the connector bridge)
gets injected. Opening `desk-pulse.html` directly from this folder in a
browser will NOT show live data; it's here so you can read/edit the code.

To get an installed, taskbar-pinnable app with live data:

1. Open the live link above in **Microsoft Edge** (or Chrome).
2. Click the **install icon** in the address bar (or menu → *Apps* → *Install
   this site as an app*).
3. Once installed, right-click its icon in the Start menu or open taskbar
   window → **Pin to taskbar**.

That installed app always loads the current published version of the page —
so when Claude updates the artifact (from edits made here or requested in
chat), the pinned app picks it up automatically on next launch. No
reinstalling needed.

## To keep coding on it here

`desk-pulse.html` is a single self-contained file — all CSS/JS/icons/manifest
inlined, no build step, no dependencies. Edit it directly.

When you (or Claude) want a code change to show up in the live pinned app,
the file needs to be **republished** to the artifact URL above — editing the
local copy alone doesn't push anything automatically. Two ways to do that:

- Tell Claude what you changed (or paste the diff) and ask it to republish.
- If you're comfortable with it, ask Claude to pull this file back in and
  republish it as-is after your edits.

### Layout of the file

- `<style>` block: design tokens (`:root` custom properties) + component CSS.
- `<script>` block, bottom-up:
  - `wireInbox` / `wireCalendar` / `wireJobs` / `wireDrive` — one function per
    card, each calls `mcp.watchTool(...)` to keep live data flowing.
  - `wireCalendar` is the more involved one: it first calls
    `list_calendars` to find any calendar you've subscribed to by URL (like
    the mitstudie.au.dk feed, which shows up as `*@import.calendar.google.com`)
    and merges its events in alongside your primary calendar.
  - `boot()` at the bottom wires everything up once `window.claude.use('mcp')`
    resolves.

### Connectors this page uses

- Gmail — `search_threads` (inbox card + LinkedIn job-alert card)
- Google Calendar — `list_events`, `list_calendars`
- Google Drive — `list_recent_files`

If you add a call to a new tool, the Artifact's `capabilities.mcp.servers`
manifest needs that tool name added too, or the call gets rejected with
`not_in_manifest` — that's set when Claude republishes, not in this file.
