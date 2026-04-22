# Parts list — OpenBikeRadar V1

Everything you need to build the first version. Total cost: **~35–55 EUR**.

---

## The parts

| Part | How many | Approx cost | Why you need it |
|------|----------|-------------|-----------------|
| ESP32 DevKit (WROOM) | 2 | €7–11 | The brain — runs your code. Buy 2 in case one breaks. |
| LD2410 mmWave radar sensor | 1 | €7–14 | Detects objects behind you |
| OLED screen 0.96" I2C (SSD1306) | 1 | €5–7 | Shows distance and status |
| Active buzzer | 1 | €1–2 | Makes a sound when something is close |
| Breadboard | 1 | €3–5 | Lets you connect things without soldering |
| Dupont cables (mixed pack) | 1 set | €3–5 | The wires that connect everything |
| 18650 battery 3000mAh | 1 | €5–9 | Powers the device (~15 hours) |
| TP4056 USB-C charge module | 1 | €2–4 | Charges the battery safely |
| On/off switch | 1 | €1–2 | So you can turn it off |
| USB cable (fits your ESP32) | 1 | €2–4 | For uploading code |

---

## How long does the battery last?

The whole device uses about 150–200mA of power when running.
A 3000mAh battery lasts around **15 hours** at that usage.

---

## What to buy first

Don't buy everything at once. Start with:

1. **ESP32** — get this working first before buying anything else
2. **LD2410** — the most important component
3. **Breadboard + cables** — needed for any testing

Add the rest once you know the core works.

---

## Where to buy

Search for these by name on:
- AliExpress (cheapest, ships in 2–4 weeks)
- Amazon (faster, slightly more expensive)
- Local electronics stores (faster shipping, slightly more expensive)

---

## What to check before buying

- **OLED:** Must say "I2C" — not SPI. Both look similar.
- **LD2410:** Some sellers ship different versions. Search specifically for "LD2410" (not LD2412 or similar).
- **Buzzer:** Must say "active buzzer" — passive buzzers need different code.
