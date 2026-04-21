# Parts list — OpenBikeRadar V1

Everything you need to build the first version. Total cost: **~400–600 SEK / 35–55 EUR**.

---

## The parts

| Part | How many | Approx cost | Why you need it |
|------|----------|-------------|-----------------|
| ESP32 DevKit (WROOM) | 2 | 80–120 SEK | The brain — runs your code. Buy 2 in case one breaks. |
| LD2410 mmWave radar sensor | 1 | 80–150 SEK | Detects objects behind you |
| OLED screen 0.96" I2C (SSD1306) | 1 | 50–80 SEK | Shows distance and status |
| Active buzzer | 1 | 10–20 SEK | Makes a sound when something is close |
| Breadboard | 1 | 30–50 SEK | Lets you connect things without soldering |
| Dupont cables (mixed pack) | 1 set | 30–50 SEK | The wires that connect everything |
| 18650 battery 3000mAh | 1 | 50–100 SEK | Powers the device (~15 hours) |
| TP4056 USB-C charge module | 1 | 20–40 SEK | Charges the battery safely |
| On/off switch | 1 | 10–20 SEK | So you can turn it off |
| USB cable (fits your ESP32) | 1 | 20–40 SEK | For uploading code |

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
- Electrokit, Kjell & Company, or Elfa (Swedish, fast shipping)

---

## What to check before buying

- **OLED:** Must say "I2C" — not SPI. Both look similar.
- **LD2410:** Some sellers ship different versions. Search specifically for "LD2410" (not LD2412 or similar).
- **Buzzer:** Must say "active buzzer" — passive buzzers need different code.
