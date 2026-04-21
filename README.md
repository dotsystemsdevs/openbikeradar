# OpenBikeRadar

An open source bike radar you can build yourself — a DIY alternative to the Garmin Varia.

## What it does

- Detects objects behind your bike using mmWave radar
- Estimates distance
- Determines if something is approaching
- Displays status on a small screen
- Alerts you with sound or vibration

## Hardware

| Part | Notes |
|------|-------|
| ESP32 DevKit (WROOM) | Main microcontroller |
| LD2410 mmWave radar sensor | Core detection |
| OLED 0.96" I2C (SSD1306) | Display |
| Buzzer | Alert |
| 18650 battery + TP4056 charger | Power (~15h runtime) |

Total cost: ~400–600 SEK / ~35–55 EUR

## System architecture

```
[ LD2410 sensor ]
        ↓
      ESP32
    ↙       ↘
 OLED      Buzzer
```

## Repository structure

```
openbikeradar/
├── firmware/        # ESP32 code
│   └── src/
├── hardware/        # Wiring diagrams and BOM
│   └── wiring/
├── cad/             # 3D print files for enclosure
└── docs/            # Build guides and documentation
```

## Status

**V1 — In progress (proof of concept)**

- [ ] Sensor reading
- [ ] Detection logic
- [ ] Risk levels (LOW / MED / HIGH)
- [ ] Display output
- [ ] Alert system
- [ ] Field tested

## Build guide

See [docs/build-guide.md](docs/build-guide.md)

## License

MIT — build it, modify it, share it.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md)
