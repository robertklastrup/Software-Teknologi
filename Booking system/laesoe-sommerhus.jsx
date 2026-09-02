import { useState, useEffect, useMemo } from 'react';
import {
  Calendar as CalendarIcon, Image as ImageIcon, Users, LogOut, Plus, X,
  ChevronLeft, ChevronRight, Home, Trash2, ArrowLeft, Check, Delete
} from 'lucide-react';

/* ---------------------------------------------------------
   Data helpers
--------------------------------------------------------- */

const FAMILY_KEY = 'laesoe-family-members';
const BOOKINGS_KEY = 'laesoe-bookings';
const PHOTOS_KEY = 'laesoe-photos';

async function loadData(key, fallback) {
  try {
    const res = await window.storage.get(key, true);
    return res ? JSON.parse(res.value) : fallback;
  } catch (e) {
    return fallback;
  }
}

async function saveData(key, value) {
  try {
    await window.storage.set(key, JSON.stringify(value), true);
    return true;
  } catch (e) {
    console.error('Kunne ikke gemme', key, e);
    return false;
  }
}

function uid() {
  return Date.now().toString(36) + Math.random().toString(36).slice(2, 7);
}

function getInitials(name) {
  return name.trim().split(/\s+/).map(p => p[0]).slice(0, 2).join('').toUpperCase();
}

function isoDate(d) {
  const off = d.getTimezoneOffset();
  const local = new Date(d.getTime() - off * 60000);
  return local.toISOString().slice(0, 10);
}

function fromIso(s) {
  const [y, m, d] = s.split('-').map(Number);
  return new Date(y, m - 1, d);
}

function addDays(date, n) {
  const d = new Date(date);
  d.setDate(d.getDate() + n);
  return d;
}

const MONTHS_DA = ['Januar', 'Februar', 'Marts', 'April', 'Maj', 'Juni', 'Juli', 'August', 'September', 'Oktober', 'November', 'December'];
const WEEKDAYS_DA = ['Man', 'Tir', 'Ons', 'Tor', 'Fre', 'Lør', 'Søn'];

const PLACEHOLDER_PHOTOS = [
  { id: 'p1', url: 'https://picsum.photos/seed/laesoe-hus/900/650', caption: 'Sommerhuset' },
  { id: 'p2', url: 'https://picsum.photos/seed/laesoe-klit/900/650', caption: 'Klitterne ved stranden' },
  { id: 'p3', url: 'https://picsum.photos/seed/laesoe-aften/900/650', caption: 'Aftenlys over Kattegat' },
  { id: 'p4', url: 'https://picsum.photos/seed/laesoe-terrasse/900/650', caption: 'Udsigten fra terrassen' },
];

/* ---------------------------------------------------------
   Small shared pieces
--------------------------------------------------------- */

function RoofDivider({ color = 'var(--tang)', opacity = 1 }) {
  let path = 'M0,10';
  for (let x = 0; x <= 400; x += 20) path += ` Q${x + 5},0 ${x + 10},10`;
  return (
    <svg viewBox="0 0 400 10" preserveAspectRatio="none" style={{ width: '100%', height: 10, display: 'block', opacity }}>
      <path d={path} fill="none" stroke={color} strokeWidth="2" strokeLinecap="round" />
    </svg>
  );
}

function Avatar({ name, size = 44 }) {
  return (
    <div style={{
      width: size, height: size, borderRadius: '50%',
      background: 'var(--sea)', color: '#fff',
      display: 'flex', alignItems: 'center', justifyContent: 'center',
      fontFamily: 'var(--font-display)', fontWeight: 600,
      fontSize: size * 0.4, flexShrink: 0,
    }}>
      {getInitials(name)}
    </div>
  );
}

function GlobalStyle() {
  return (
    <style>{`
      @import url('https://fonts.googleapis.com/css2?family=Fraunces:opsz,wght@9..144,400;9..144,500;9..144,600;9..144,700&family=Inter:wght@400;500;600;700&family=JetBrains+Mono:wght@400;500&display=swap');
      .laesoe-app * { box-sizing: border-box; }
      .laesoe-app {
        --sand: #F6F2E9;
        --sand-deep: #EAE1CC;
        --ink: #2C2A26;
        --ink-soft: #726C60;
        --sea: #4F7585;
        --sea-deep: #33525F;
        --tang: #A8794F;
        --marram: #74875F;
        --rust: #9B5B3C;
        --card: #FFFDF8;
        font-family: var(--font-body);
        color: var(--ink);
      }
      .laesoe-app { --font-display: 'Fraunces', serif; --font-body: 'Inter', sans-serif; --font-mono: 'JetBrains Mono', monospace; }
      .laesoe-btn {
        font-family: var(--font-body); font-weight: 600; border: none; cursor: pointer;
        transition: transform 0.12s ease, background 0.15s ease, opacity 0.15s ease;
      }
      .laesoe-btn:active { transform: scale(0.97); }
      .laesoe-btn:disabled { opacity: 0.45; cursor: not-allowed; }
      .laesoe-keypad-btn {
        font-family: var(--font-mono); font-size: 20px; font-weight: 500;
        width: 56px; height: 56px; border-radius: 50%; border: 1.5px solid var(--sand-deep);
        background: var(--card); color: var(--ink); cursor: pointer;
        transition: background 0.12s ease, transform 0.08s ease;
      }
      .laesoe-keypad-btn:hover { background: var(--sand-deep); }
      .laesoe-keypad-btn:active { transform: scale(0.92); }
      .laesoe-shake { animation: laesoe-shake 0.4s; }
      @keyframes laesoe-shake {
        10%, 90% { transform: translateX(-2px); }
        20%, 80% { transform: translateX(4px); }
        30%, 50%, 70% { transform: translateX(-8px); }
        40%, 60% { transform: translateX(8px); }
      }
      .laesoe-fade-in { animation: laesoe-fade-in 0.35s ease both; }
      @keyframes laesoe-fade-in { from { opacity: 0; transform: translateY(6px); } to { opacity: 1; transform: translateY(0); } }
      .laesoe-tab {
        font-family: var(--font-body); font-weight: 600; font-size: 14px;
        background: none; border: none; cursor: pointer; padding: 10px 4px;
        color: var(--ink-soft); border-bottom: 2px solid transparent;
        display: flex; align-items: center; gap: 6px;
      }
      .laesoe-tab.active { color: var(--sea-deep); border-bottom: 2px solid var(--sea); }
      .laesoe-day {
        aspect-ratio: 1; border-radius: 10px; border: none; cursor: pointer;
        font-family: var(--font-mono); font-size: 13px; position: relative;
        display: flex; flex-direction: column; align-items: center; justify-content: center; gap: 2px;
        background: var(--card); color: var(--ink); transition: background 0.15s ease;
      }
      .laesoe-day:hover:not(:disabled) { background: var(--sand-deep); }
      .laesoe-day:disabled { color: #C9C3B4; cursor: default; }
      .laesoe-day.booked { background: var(--sea); color: #fff; }
      .laesoe-day.selected { background: var(--tang); color: #fff; }
      .laesoe-day.today { box-shadow: inset 0 0 0 2px var(--marram); }
      .laesoe-input {
        font-family: var(--font-body); font-size: 15px; padding: 10px 12px;
        border-radius: 8px; border: 1.5px solid var(--sand-deep); background: var(--card); color: var(--ink);
        width: 100%; outline: none;
      }
      .laesoe-input:focus { border-color: var(--sea); }
      .laesoe-card { background: var(--card); border-radius: 14px; padding: 20px; box-shadow: 0 1px 3px rgba(44,42,38,0.08); }
      ::selection { background: var(--tang); color: #fff; }
    `}</style>
  );
}

/* ---------------------------------------------------------
   Setup screen — first run, add family members
--------------------------------------------------------- */

function SetupScreen({ familyMembers, onAdd, onDone }) {
  const [name, setName] = useState('');
  const [pin, setPin] = useState('');
  const [error, setError] = useState('');

  function submit(e) {
    e.preventDefault();
    if (!name.trim()) { setError('Skriv et navn.'); return; }
    if (!/^\d{4}$/.test(pin)) { setError('PIN-koden skal være præcis 4 tal.'); return; }
    if (familyMembers.some(m => m.name.toLowerCase() === name.trim().toLowerCase())) {
      setError('Det navn er allerede tilføjet.'); return;
    }
    onAdd({ name: name.trim(), pin });
    setName(''); setPin(''); setError('');
  }

  return (
    <div style={{ minHeight: '100vh', background: 'var(--sand)', display: 'flex', alignItems: 'center', justifyContent: 'center', padding: 24 }}>
      <div className="laesoe-fade-in" style={{ width: '100%', maxWidth: 420 }}>
        <div style={{ textAlign: 'center', marginBottom: 24 }}>
          <Home size={28} color="var(--sea-deep)" />
          <h1 style={{ fontFamily: 'var(--font-display)', fontSize: 28, margin: '8px 0 2px', fontWeight: 600 }}>Velkommen</h1>
          <p style={{ color: 'var(--ink-soft)', fontSize: 14, margin: 0 }}>Tilføj hvem der skal have adgang til sommerhuset på Læsø.</p>
        </div>
        <RoofDivider />
        <div className="laesoe-card" style={{ marginTop: 20 }}>
          {familyMembers.length > 0 && (
            <div style={{ display: 'flex', flexWrap: 'wrap', gap: 10, marginBottom: 18 }}>
              {familyMembers.map(m => (
                <div key={m.name} style={{ display: 'flex', alignItems: 'center', gap: 8, background: 'var(--sand)', borderRadius: 20, padding: '4px 12px 4px 4px' }}>
                  <Avatar name={m.name} size={28} />
                  <span style={{ fontSize: 14, fontWeight: 500 }}>{m.name}</span>
                </div>
              ))}
            </div>
          )}
          <form onSubmit={submit} style={{ display: 'flex', flexDirection: 'column', gap: 10 }}>
            <input className="laesoe-input" placeholder="Navn (fx Mor, Far...)" value={name} onChange={e => setName(e.target.value)} />
            <input className="laesoe-input" placeholder="Vælg en 4-cifret PIN-kode" value={pin} inputMode="numeric" maxLength={4}
              onChange={e => setPin(e.target.value.replace(/\D/g, '').slice(0, 4))} />
            {error && <div style={{ color: 'var(--rust)', fontSize: 13 }}>{error}</div>}
            <button type="submit" className="laesoe-btn" style={{ background: 'var(--sea)', color: '#fff', borderRadius: 8, padding: '10px 0', fontSize: 14, display: 'flex', alignItems: 'center', justifyContent: 'center', gap: 6 }}>
              <Plus size={16} /> Tilføj familiemedlem
            </button>
          </form>
        </div>
        {familyMembers.length > 0 && (
          <button className="laesoe-btn" onClick={onDone} style={{ width: '100%', marginTop: 14, background: 'var(--tang)', color: '#fff', borderRadius: 8, padding: '11px 0', fontSize: 14 }}>
            Gå til login →
          </button>
        )}
        <p style={{ textAlign: 'center', fontSize: 12, color: 'var(--ink-soft)', marginTop: 16 }}>
          Bemærk: dette er en simpel PIN-løsning til familiebrug — ikke en sikker login-løsning.
        </p>
      </div>
    </div>
  );
}

/* ---------------------------------------------------------
   Login screen
--------------------------------------------------------- */

function LoginScreen({ familyMembers, onLogin }) {
  const [selected, setSelected] = useState(null);
  const [pin, setPin] = useState('');
  const [error, setError] = useState(false);

  function pressDigit(d) {
    if (pin.length >= 4) return;
    const next = pin + d;
    setPin(next);
    if (next.length === 4) {
      const member = familyMembers.find(m => m.name === selected);
      if (member && member.pin === next) {
        onLogin(selected);
      } else {
        setError(true);
        setTimeout(() => { setPin(''); setError(false); }, 450);
      }
    }
  }

  return (
    <div style={{ minHeight: '100vh', background: 'var(--sand)', display: 'flex', alignItems: 'center', justifyContent: 'center', padding: 24, position: 'relative', overflow: 'hidden' }}>
      <svg style={{ position: 'absolute', bottom: 0, left: 0, width: '100%', opacity: 0.5 }} viewBox="0 0 400 60" preserveAspectRatio="none">
        <path d="M0,40 Q50,10 100,40 T200,40 T300,40 T400,40 V60 H0 Z" fill="var(--sand-deep)" />
      </svg>
      <div className="laesoe-fade-in" style={{ width: '100%', maxWidth: 380, position: 'relative' }}>
        <div style={{ textAlign: 'center', marginBottom: 20 }}>
          <Home size={28} color="var(--sea-deep)" />
          <h1 style={{ fontFamily: 'var(--font-display)', fontSize: 30, margin: '8px 0 0', fontWeight: 600 }}>Sommerhuset</h1>
          <p style={{ fontFamily: 'var(--font-display)', fontStyle: 'italic', color: 'var(--ink-soft)', margin: '2px 0 0', fontSize: 15 }}>på Læsø</p>
        </div>
        <RoofDivider />

        {!selected ? (
          <div className="laesoe-card" style={{ marginTop: 20 }}>
            <p style={{ fontSize: 13, color: 'var(--ink-soft)', marginTop: 0, marginBottom: 14 }}>Hvem er du?</p>
            <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fill, minmax(84px, 1fr))', gap: 14 }}>
              {familyMembers.map(m => (
                <button key={m.name} className="laesoe-btn" onClick={() => setSelected(m.name)}
                  style={{ background: 'none', display: 'flex', flexDirection: 'column', alignItems: 'center', gap: 6, padding: 6, borderRadius: 10 }}>
                  <Avatar name={m.name} size={52} />
                  <span style={{ fontSize: 13, fontWeight: 500 }}>{m.name}</span>
                </button>
              ))}
            </div>
          </div>
        ) : (
          <div className={`laesoe-card ${error ? 'laesoe-shake' : ''}`} style={{ marginTop: 20, textAlign: 'center' }}>
            <button className="laesoe-btn" onClick={() => { setSelected(null); setPin(''); }} style={{ background: 'none', color: 'var(--ink-soft)', display: 'flex', alignItems: 'center', gap: 4, fontSize: 13, marginBottom: 10 }}>
              <ArrowLeft size={14} /> Tilbage
            </button>
            <Avatar name={selected} size={48} />
            <p style={{ fontFamily: 'var(--font-display)', fontSize: 17, margin: '8px 0 14px' }}>Hej {selected}, indtast din PIN-kode</p>
            <div style={{ display: 'flex', justifyContent: 'center', gap: 12, marginBottom: 18 }}>
              {[0, 1, 2, 3].map(i => (
                <div key={i} style={{
                  width: 14, height: 14, borderRadius: '50%',
                  border: '1.5px solid var(--sea)',
                  background: i < pin.length ? (error ? 'var(--rust)' : 'var(--sea)') : 'transparent',
                }} />
              ))}
            </div>
            <div style={{ display: 'grid', gridTemplateColumns: 'repeat(3, 1fr)', gap: 10, justifyItems: 'center', maxWidth: 220, margin: '0 auto' }}>
              {[1, 2, 3, 4, 5, 6, 7, 8, 9].map(d => (
                <button key={d} className="laesoe-keypad-btn" onClick={() => pressDigit(String(d))}>{d}</button>
              ))}
              <div />
              <button className="laesoe-keypad-btn" onClick={() => pressDigit('0')}>0</button>
              <button className="laesoe-keypad-btn" onClick={() => setPin(pin.slice(0, -1))} style={{ display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
                <Delete size={18} />
              </button>
            </div>
            {error && <p style={{ color: 'var(--rust)', fontSize: 13, marginTop: 12 }}>Forkert PIN-kode, prøv igen.</p>}
          </div>
        )}
      </div>
    </div>
  );
}

/* ---------------------------------------------------------
   Calendar tab
--------------------------------------------------------- */

function CalendarTab({ bookings, currentUser, onAddBooking, onDeleteBooking }) {
  const today = new Date();
  const [cursor, setCursor] = useState({ year: today.getFullYear(), month: today.getMonth() });
  const [range, setRange] = useState({ start: null, end: null });
  const [note, setNote] = useState('');
  const [overlapWarning, setOverlapWarning] = useState(null);

  const grid = useMemo(() => {
    const first = new Date(cursor.year, cursor.month, 1);
    const startOffset = (first.getDay() + 6) % 7; // Monday = 0
    const gridStart = addDays(first, -startOffset);
    return Array.from({ length: 42 }, (_, i) => {
      const date = addDays(gridStart, i);
      return { date, inMonth: date.getMonth() === cursor.month };
    });
  }, [cursor]);

  function bookingFor(dateIso) {
    return bookings.find(b => dateIso >= b.start && dateIso <= b.end);
  }

  function isInSelection(dateIso) {
    if (!range.start) return false;
    const end = range.end || range.start;
    const [lo, hi] = dateIso < end ? [range.start, end] : [end, range.start];
    return dateIso >= (range.start < end ? range.start : end) && dateIso <= (range.start < end ? end : range.start);
  }

  function handleDayClick(date) {
    const dIso = isoDate(date);
    if (!range.start || (range.start && range.end)) {
      setRange({ start: dIso, end: null });
      setNote(''); setOverlapWarning(null);
    } else {
      const start = dIso < range.start ? dIso : range.start;
      const end = dIso < range.start ? range.start : dIso;
      setRange({ start, end });
    }
  }

  function confirmBooking() {
    if (!range.start || !range.end) return;
    const overlap = bookings.find(b => !(range.end < b.start || range.start > b.end));
    if (overlap && !overlapWarning) {
      setOverlapWarning(overlap);
      return;
    }
    onAddBooking({ id: uid(), name: currentUser, start: range.start, end: range.end, note: note.trim() });
    setRange({ start: null, end: null }); setNote(''); setOverlapWarning(null);
  }

  const upcoming = [...bookings]
    .filter(b => b.end >= isoDate(today))
    .sort((a, b) => a.start.localeCompare(b.start));

  const monthLabel = `${MONTHS_DA[cursor.month]} ${cursor.year}`;

  return (
    <div style={{ display: 'flex', flexDirection: 'column', gap: 24 }}>
      <div className="laesoe-card">
        <div style={{ display: 'flex', alignItems: 'center', justifyContent: 'space-between', marginBottom: 16 }}>
          <button className="laesoe-btn" style={{ background: 'none', padding: 6 }}
            onClick={() => setCursor(c => { const m = c.month - 1; return m < 0 ? { year: c.year - 1, month: 11 } : { year: c.year, month: m }; })}>
            <ChevronLeft size={18} />
          </button>
          <span style={{ fontFamily: 'var(--font-display)', fontSize: 18, fontWeight: 600 }}>{monthLabel}</span>
          <button className="laesoe-btn" style={{ background: 'none', padding: 6 }}
            onClick={() => setCursor(c => { const m = c.month + 1; return m > 11 ? { year: c.year + 1, month: 0 } : { year: c.year, month: m }; })}>
            <ChevronRight size={18} />
          </button>
        </div>
        <div style={{ display: 'grid', gridTemplateColumns: 'repeat(7, 1fr)', gap: 6, marginBottom: 6 }}>
          {WEEKDAYS_DA.map(w => (
            <div key={w} style={{ textAlign: 'center', fontSize: 11, color: 'var(--ink-soft)', fontWeight: 600 }}>{w}</div>
          ))}
        </div>
        <div style={{ display: 'grid', gridTemplateColumns: 'repeat(7, 1fr)', gap: 6 }}>
          {grid.map(({ date, inMonth }) => {
            const dIso = isoDate(date);
            const booking = bookingFor(dIso);
            const selected = isInSelection(dIso);
            const isToday = dIso === isoDate(today);
            const classes = ['laesoe-day'];
            if (booking && !selected) classes.push('booked');
            if (selected) classes.push('selected');
            if (isToday) classes.push('today');
            return (
              <button key={dIso} disabled={!inMonth} className={classes.join(' ')} onClick={() => handleDayClick(date)}
                title={booking ? `${booking.name}${booking.note ? ': ' + booking.note : ''}` : ''}>
                <span style={{ opacity: inMonth ? 1 : 0.3 }}>{date.getDate()}</span>
                {booking && <span style={{ fontSize: 9 }}>{getInitials(booking.name)}</span>}
              </button>
            );
          })}
        </div>
      </div>

      {range.start && (
        <div className="laesoe-card laesoe-fade-in">
          <p style={{ margin: '0 0 10px', fontSize: 14, fontWeight: 600 }}>
            {range.end ? `Book ${fromIso(range.start).toLocaleDateString('da-DK')} – ${fromIso(range.end).toLocaleDateString('da-DK')}` : `Startdato: ${fromIso(range.start).toLocaleDateString('da-DK')} — vælg slutdato`}
          </p>
          {range.end && (
            <>
              <textarea className="laesoe-input" placeholder="Note (valgfri)" rows={2} value={note} onChange={e => setNote(e.target.value)} style={{ marginBottom: 10, resize: 'vertical' }} />
              {overlapWarning && (
                <p style={{ color: 'var(--rust)', fontSize: 13, marginBottom: 10 }}>
                  Overlapper med {overlapWarning.name}s ophold. Klik "Book ophold" igen for at booke alligevel.
                </p>
              )}
              <div style={{ display: 'flex', gap: 10 }}>
                <button className="laesoe-btn" onClick={confirmBooking} style={{ background: 'var(--sea)', color: '#fff', borderRadius: 8, padding: '9px 16px', fontSize: 14 }}>
                  Book ophold
                </button>
                <button className="laesoe-btn" onClick={() => { setRange({ start: null, end: null }); setOverlapWarning(null); }} style={{ background: 'none', color: 'var(--ink-soft)', fontSize: 14 }}>
                  Annuller
                </button>
              </div>
            </>
          )}
        </div>
      )}

      <div>
        <h3 style={{ fontFamily: 'var(--font-display)', fontSize: 17, marginBottom: 10 }}>Kommende ophold</h3>
        {upcoming.length === 0 ? (
          <p style={{ color: 'var(--ink-soft)', fontSize: 14 }}>Ingen ophold booket endnu — vælg en dato i kalenderen for at booke det første.</p>
        ) : (
          <div style={{ display: 'flex', flexDirection: 'column', gap: 8 }}>
            {upcoming.map(b => (
              <div key={b.id} className="laesoe-card" style={{ padding: 14, display: 'flex', alignItems: 'center', gap: 12 }}>
                <Avatar name={b.name} size={36} />
                <div style={{ flex: 1 }}>
                  <div style={{ fontSize: 14, fontWeight: 600 }}>{b.name}</div>
                  <div style={{ fontSize: 13, color: 'var(--ink-soft)' }}>
                    {fromIso(b.start).toLocaleDateString('da-DK')} – {fromIso(b.end).toLocaleDateString('da-DK')}
                    {b.note && <> · {b.note}</>}
                  </div>
                </div>
                {b.name === currentUser && (
                  <button className="laesoe-btn" onClick={() => onDeleteBooking(b.id)} style={{ background: 'none', color: 'var(--ink-soft)', padding: 6 }}>
                    <Trash2 size={16} />
                  </button>
                )}
              </div>
            ))}
          </div>
        )}
      </div>
    </div>
  );
}

/* ---------------------------------------------------------
   Photos tab
--------------------------------------------------------- */

function PhotosTab({ photos, onAdd, onDelete }) {
  const [showForm, setShowForm] = useState(false);
  const [url, setUrl] = useState('');
  const [caption, setCaption] = useState('');

  function submit(e) {
    e.preventDefault();
    if (!url.trim()) return;
    onAdd({ id: uid(), url: url.trim(), caption: caption.trim() });
    setUrl(''); setCaption(''); setShowForm(false);
  }

  return (
    <div>
      <div style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'center', marginBottom: 16 }}>
        <h3 style={{ fontFamily: 'var(--font-display)', fontSize: 17, margin: 0 }}>Billeder</h3>
        <button className="laesoe-btn" onClick={() => setShowForm(s => !s)} style={{ background: 'var(--sea)', color: '#fff', borderRadius: 8, padding: '8px 14px', fontSize: 13, display: 'flex', alignItems: 'center', gap: 6 }}>
          <Plus size={15} /> Tilføj billede
        </button>
      </div>

      {showForm && (
        <form onSubmit={submit} className="laesoe-card laesoe-fade-in" style={{ marginBottom: 16, display: 'flex', flexDirection: 'column', gap: 10 }}>
          <input className="laesoe-input" placeholder="Billede-URL (fx et link fra din telefon/skyen)" value={url} onChange={e => setUrl(e.target.value)} />
          <input className="laesoe-input" placeholder="Billedtekst (valgfri)" value={caption} onChange={e => setCaption(e.target.value)} />
          <div style={{ display: 'flex', gap: 10 }}>
            <button type="submit" className="laesoe-btn" style={{ background: 'var(--sea)', color: '#fff', borderRadius: 8, padding: '9px 16px', fontSize: 14 }}>Gem</button>
            <button type="button" className="laesoe-btn" onClick={() => setShowForm(false)} style={{ background: 'none', color: 'var(--ink-soft)', fontSize: 14 }}>Annuller</button>
          </div>
        </form>
      )}

      <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fill, minmax(220px, 1fr))', gap: 16 }}>
        {photos.map(p => (
          <div key={p.id} className="laesoe-card" style={{ padding: 0, overflow: 'hidden' }}>
            <div style={{ position: 'relative' }}>
              <img src={p.url} alt={p.caption || 'Sommerhuset'} style={{ width: '100%', height: 160, objectFit: 'cover', display: 'block', filter: 'saturate(0.9) contrast(0.97)' }} />
              <button className="laesoe-btn" onClick={() => onDelete(p.id)}
                style={{ position: 'absolute', top: 8, right: 8, background: 'rgba(44,42,38,0.55)', color: '#fff', borderRadius: '50%', width: 28, height: 28, display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
                <X size={14} />
              </button>
            </div>
            {p.caption && <p style={{ margin: 0, padding: '10px 12px', fontSize: 13, color: 'var(--ink-soft)' }}>{p.caption}</p>}
          </div>
        ))}
      </div>
      <p style={{ fontSize: 12, color: 'var(--ink-soft)', marginTop: 16 }}>
        De første billeder er midlertidige eksempler. Tilføj jeres egne ved at indsætte et link til et billede (fx uploadet til Google Fotos eller iCloud og delt som link).
      </p>
    </div>
  );
}

/* ---------------------------------------------------------
   Family tab
--------------------------------------------------------- */

function FamilyTab({ familyMembers, currentUser, onAdd, onRemove }) {
  const [name, setName] = useState('');
  const [pin, setPin] = useState('');
  const [error, setError] = useState('');

  function submit(e) {
    e.preventDefault();
    if (!name.trim()) { setError('Skriv et navn.'); return; }
    if (!/^\d{4}$/.test(pin)) { setError('PIN-koden skal være præcis 4 tal.'); return; }
    if (familyMembers.some(m => m.name.toLowerCase() === name.trim().toLowerCase())) {
      setError('Det navn findes allerede.'); return;
    }
    onAdd({ name: name.trim(), pin });
    setName(''); setPin(''); setError('');
  }

  return (
    <div>
      <h3 style={{ fontFamily: 'var(--font-display)', fontSize: 17, marginBottom: 14 }}>Familie med adgang</h3>
      <div style={{ display: 'flex', flexDirection: 'column', gap: 8, marginBottom: 20 }}>
        {familyMembers.map(m => (
          <div key={m.name} className="laesoe-card" style={{ padding: 12, display: 'flex', alignItems: 'center', gap: 12 }}>
            <Avatar name={m.name} size={36} />
            <span style={{ flex: 1, fontSize: 14, fontWeight: 500 }}>{m.name}{m.name === currentUser && ' (dig)'}</span>
            {familyMembers.length > 1 && (
              <button className="laesoe-btn" onClick={() => onRemove(m.name)} style={{ background: 'none', color: 'var(--ink-soft)', padding: 6 }}>
                <Trash2 size={16} />
              </button>
            )}
          </div>
        ))}
      </div>
      <form onSubmit={submit} className="laesoe-card" style={{ display: 'flex', flexDirection: 'column', gap: 10, maxWidth: 340 }}>
        <p style={{ margin: 0, fontSize: 14, fontWeight: 600 }}>Tilføj familiemedlem</p>
        <input className="laesoe-input" placeholder="Navn" value={name} onChange={e => setName(e.target.value)} />
        <input className="laesoe-input" placeholder="4-cifret PIN-kode" value={pin} inputMode="numeric" maxLength={4}
          onChange={e => setPin(e.target.value.replace(/\D/g, '').slice(0, 4))} />
        {error && <div style={{ color: 'var(--rust)', fontSize: 13 }}>{error}</div>}
        <button type="submit" className="laesoe-btn" style={{ background: 'var(--sea)', color: '#fff', borderRadius: 8, padding: '9px 0', fontSize: 14 }}>
          Tilføj
        </button>
      </form>
    </div>
  );
}

/* ---------------------------------------------------------
   Main app shell (after login)
--------------------------------------------------------- */

function MainApp({ familyMembers, bookings, photos, currentUser, onLogout, mutators }) {
  const [tab, setTab] = useState('calendar');

  return (
    <div style={{ minHeight: '100vh', background: 'var(--sand)' }}>
      <div style={{ maxWidth: 780, margin: '0 auto', padding: '28px 20px 60px' }}>
        <div style={{ display: 'flex', alignItems: 'center', justifyContent: 'space-between', marginBottom: 8 }}>
          <div style={{ display: 'flex', alignItems: 'center', gap: 10 }}>
            <Home size={22} color="var(--sea-deep)" />
            <div>
              <h1 style={{ fontFamily: 'var(--font-display)', fontSize: 22, margin: 0, fontWeight: 600 }}>Sommerhuset på Læsø</h1>
            </div>
          </div>
          <div style={{ display: 'flex', alignItems: 'center', gap: 10 }}>
            <Avatar name={currentUser} size={32} />
            <button className="laesoe-btn" onClick={onLogout} style={{ background: 'none', color: 'var(--ink-soft)', padding: 6 }} title="Log ud">
              <LogOut size={18} />
            </button>
          </div>
        </div>
        <RoofDivider opacity={0.7} />

        <div style={{ display: 'flex', gap: 20, margin: '18px 0 22px', borderBottom: '1px solid var(--sand-deep)' }}>
          <button className={`laesoe-tab ${tab === 'calendar' ? 'active' : ''}`} onClick={() => setTab('calendar')}>
            <CalendarIcon size={15} /> Kalender
          </button>
          <button className={`laesoe-tab ${tab === 'photos' ? 'active' : ''}`} onClick={() => setTab('photos')}>
            <ImageIcon size={15} /> Billeder
          </button>
          <button className={`laesoe-tab ${tab === 'family' ? 'active' : ''}`} onClick={() => setTab('family')}>
            <Users size={15} /> Familie
          </button>
        </div>

        <div className="laesoe-fade-in" key={tab}>
          {tab === 'calendar' && (
            <CalendarTab bookings={bookings} currentUser={currentUser} onAddBooking={mutators.addBooking} onDeleteBooking={mutators.deleteBooking} />
          )}
          {tab === 'photos' && (
            <PhotosTab photos={photos} onAdd={mutators.addPhoto} onDelete={mutators.deletePhoto} />
          )}
          {tab === 'family' && (
            <FamilyTab familyMembers={familyMembers} currentUser={currentUser} onAdd={mutators.addMember} onRemove={mutators.removeMember} />
          )}
        </div>
      </div>
    </div>
  );
}

/* ---------------------------------------------------------
   Root
--------------------------------------------------------- */

export default function App() {
  const [loading, setLoading] = useState(true);
  const [familyMembers, setFamilyMembers] = useState([]);
  const [bookings, setBookings] = useState([]);
  const [photos, setPhotos] = useState([]);
  const [currentUser, setCurrentUser] = useState(null);

  useEffect(() => {
    (async () => {
      const [fm, bk, ph] = await Promise.all([
        loadData(FAMILY_KEY, []),
        loadData(BOOKINGS_KEY, []),
        loadData(PHOTOS_KEY, PLACEHOLDER_PHOTOS),
      ]);
      setFamilyMembers(fm);
      setBookings(bk);
      setPhotos(ph);
      setLoading(false);
    })();
  }, []);

  async function addMember(member) {
    const next = [...familyMembers, member];
    setFamilyMembers(next);
    await saveData(FAMILY_KEY, next);
  }
  async function removeMember(name) {
    const next = familyMembers.filter(m => m.name !== name);
    setFamilyMembers(next);
    await saveData(FAMILY_KEY, next);
    if (currentUser === name) setCurrentUser(null);
  }
  async function addBooking(booking) {
    const next = [...bookings, booking];
    setBookings(next);
    await saveData(BOOKINGS_KEY, next);
  }
  async function deleteBooking(id) {
    const next = bookings.filter(b => b.id !== id);
    setBookings(next);
    await saveData(BOOKINGS_KEY, next);
  }
  async function addPhoto(photo) {
    const next = [...photos, photo];
    setPhotos(next);
    await saveData(PHOTOS_KEY, next);
  }
  async function deletePhoto(id) {
    const next = photos.filter(p => p.id !== id);
    setPhotos(next);
    await saveData(PHOTOS_KEY, next);
  }

  if (loading) {
    return (
      <div className="laesoe-app" style={{ minHeight: '100vh', background: 'var(--sand)', display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
        <GlobalStyle />
        <p style={{ color: 'var(--ink-soft)', fontFamily: 'var(--font-body)' }}>Henter sommerhuset…</p>
      </div>
    );
  }

  return (
    <div className="laesoe-app">
      <GlobalStyle />
      {familyMembers.length === 0 ? (
        <SetupScreen familyMembers={familyMembers} onAdd={addMember} onDone={() => {}} />
      ) : !currentUser ? (
        <LoginScreen familyMembers={familyMembers} onLogin={setCurrentUser} />
      ) : (
        <MainApp
          familyMembers={familyMembers}
          bookings={bookings}
          photos={photos}
          currentUser={currentUser}
          onLogout={() => setCurrentUser(null)}
          mutators={{ addMember, removeMember, addBooking, deleteBooking, addPhoto, deletePhoto }}
        />
      )}
    </div>
  );
}
