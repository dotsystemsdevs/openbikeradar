# OpenBikeRadar

<img src="assets/logo.png" width="200" />

An open source bike radar you can build yourself — a DIY alternative to the Garmin Varia.

No advanced electronics experience needed. If you can follow a wiring diagram and copy-paste code, you can build this.

---

## What it does

- Detects vehicles or objects behind your bike using a small radar sensor
- Shows you how far away they are
- Warns you if something is getting closer
- Displays status on a tiny screen
- Beeps or vibrates when something is too close

## What it costs

Around **35–55 EUR** in parts. Compare that to ~180 EUR for a Garmin Varia.

---

## Parts you need

You don't need to understand all of these yet — just order them and we'll explain each one as we use it.

| Part | What it does |
|------|-------------|
| ESP32 (the brain) | A small computer that runs your code |
| LD2410 radar sensor | Detects movement behind you |
| OLED screen (0.96") | Shows distance and status |
| Buzzer | Makes a sound when something is close |
| 18650 battery + charger | Powers the whole thing for ~15 hours |
| Breadboard + cables | Connects everything together for testing |

Full list with quantities: [hardware/bom.md](hardware/bom.md)

---

## How it works (simple version)

```
Radar sensor → sees something behind you
      ↓
   ESP32 → figures out how close it is
      ↓
  Screen → shows you the distance
  Buzzer → beeps if it's too close
```

---

## How to build it

Follow the step-by-step guide: [docs/build-guide.md](docs/build-guide.md)

You don't need to read everything at once — just start at Step 1.

---

## Project status

**V1 — In progress**

- [ ] Sensor reading works
- [ ] Detection logic done
- [ ] Risk levels (LOW / MED / HIGH)
- [ ] Screen showing status
- [ ] Alert system working
- [ ] Tested on a real bike

---

## Why open source?

The Garmin Varia does basically the same thing and costs ~2000 SEK. It's also a closed system — you can't modify it, fix it, or understand how it works.

This project is fully open. Build it, change it, improve it.

---

## License

MIT — do whatever you want with it.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md)
