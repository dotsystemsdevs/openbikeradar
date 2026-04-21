# Bill of Materials — OpenBikeRadar V1

| Part | Qty | Approx cost (SEK) | Notes |
|------|-----|-------------------|-------|
| ESP32 DevKit WROOM | 2 | 80–120 | Buy 2, use 1 as backup |
| LD2410 mmWave radar sensor | 1 | 80–150 | Core component |
| OLED 0.96" I2C SSD1306 | 1 | 50–80 | |
| Buzzer (active) | 1 | 10–20 | |
| Breadboard | 1 | 30–50 | For prototyping |
| Dupont cables (M-M, M-F, F-F) | 1 set | 30–50 | |
| 18650 battery 3000mAh | 1 | 50–100 | ~15h runtime |
| TP4056 USB-C charge module | 1 | 20–40 | |
| On/off switch | 1 | 10–20 | |
| USB-C cable | 1 | 20–40 | For flashing ESP32 |

**Total: ~380–670 SEK**

## Power budget

| Component | Current draw |
|-----------|-------------|
| ESP32 (active) | ~80–100mA |
| LD2410 | ~50–70mA |
| OLED | ~20–30mA |
| **Total** | **~150–200mA** |

18650 at 3000mAh → ~15 hours runtime at full load.

## Notes

- Buy the ESP32 before anything else — flash it and confirm it works
- LD2410 is the most critical part — verify your supplier ships the real chip
- The OLED must be I2C (not SPI) for the standard wiring to work
