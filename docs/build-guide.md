# Build Guide — OpenBikeRadar V1

You don't need experience with electronics to follow this. Each step is self-contained — just do one at a time.

---

## What you need before starting

- All the parts from [hardware/bom.md](../hardware/bom.md)
- A computer (Windows, Mac, or Linux)
- A USB cable that fits your ESP32
- About 30 minutes per step

---

## Step 1 — Set up your computer

You need a free program to write code to the ESP32.

1. Download [Arduino IDE](https://www.arduino.cc/en/software) — it's free
2. Open it
3. Go to **File → Preferences**
4. In the "Additional boards manager URLs" field, paste this:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
5. Go to **Tools → Board → Boards Manager**
6. Search for "esp32" and install it

That's it — your computer can now talk to the ESP32.

---

## Step 2 — Flash the ESP32

"Flashing" just means sending code to the ESP32.

1. Connect the ESP32 to your computer with a USB cable
2. Open Arduino IDE
3. Go to **Tools → Board** and select "ESP32 Dev Module"
4. Go to **Tools → Port** and select the port that appeared when you plugged in the ESP32
   - On Windows it looks like: `COM3` or `COM4`
   - On Mac it looks like: `/dev/cu.usbserial-...`
5. Open the file `firmware/src/main.ino`
6. Click the Upload button (→ arrow)
7. Open **Tools → Serial Monitor**, set baud rate to `115200`
8. You should see: `OpenBikeRadar starting...`

If you see that message — the ESP32 works. Good.

---

## Step 3 — Connect the radar sensor

The LD2410 is the radar sensor. It sends data to the ESP32 over a connection called "serial" — basically the sensor talks and the ESP32 listens.

**How to connect** (use the wiring diagram: [hardware/wiring/wiring.md](../hardware/wiring/wiring.md)):

| LD2410 pin | Where it goes on ESP32 |
|------------|------------------------|
| VCC | 3.3V pin |
| GND | GND pin |
| TX | GPIO16 |
| RX | GPIO17 |

**Important:** Use the 3.3V pin, not 5V. The sensor will break if you use 5V.

Power on. Wave your hand in front of the sensor. You should see numbers change in the Serial Monitor.

---

## Step 4 — Read the data

The sensor sends numbers. Here's what they mean:

- **Moving target distance** — how far away a moving thing is (in cm)
- **Signal strength** — how confident the sensor is (higher = more confident)
- **Stationary target** — something that isn't moving

At this point just watch the numbers and get a feel for them. Walk toward the sensor, walk away. See what changes.

---

## Step 5 — Add filtering (important — don't skip)

The sensor picks up a lot of noise — reflections off walls, wind, random interference. Without filtering, it will give false alarms constantly.

Add these two rules in your code:

1. **Ignore short detections** — only count something if it's detected for at least 500ms in a row
2. **Require consistency** — only trigger if you get 3 positive readings in a row

This alone removes most false alarms.

---

## Step 6 — Build the detection logic

Now you turn raw numbers into something meaningful:

```
No object detected     → CLEAR
Object detected        → OBJECT DETECTED
Object getting closer  → APPROACHING
```

How do you know if something is "getting closer"? Compare the distance now to the distance a moment ago. If it's smaller — it's approaching.

---

## Step 7 — Add risk levels

Instead of just "detected" or "not detected", we use three levels:

| Level | When | What it means |
|-------|------|--------------|
| LOW | Object far away, not moving fast | Keep an eye on it |
| MED | Object getting closer | Pay attention |
| HIGH | Object close and fast | Move over |

You set the distance thresholds based on your field testing — everyone's situation is different.

---

## Step 8 — Connect the screen

The OLED screen shows you the current status.

Wiring:

| OLED pin | ESP32 pin |
|----------|-----------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

Install the library: In Arduino IDE, go to **Tools → Manage Libraries**, search for "SSD1306" by Adafruit, install it.

The screen should now show: `CLEAR`, `OBJECT DETECTED`, or `APPROACHING`.

---

## Step 9 — Test outside (do this early)

Before adding more features, test what you have in the real world.

Mount everything temporarily with tape or cable ties. Stand with the bike on a quiet street. Have someone walk or cycle behind you from about 50 meters away.

Write down:
- At what distance does it detect them?
- Does it give false alarms?
- How does it handle a car passing vs a cyclist?

Use what you learn to adjust your thresholds from Step 7.

---

## Step 10 — Connect the buzzer

The buzzer makes a sound so you don't have to stare at the screen.

| Buzzer pin | ESP32 pin |
|------------|-----------|
| + | GPIO25 |
| - | GND |

Different patterns for different risk levels:
- LOW → no sound
- MED → one short beep every 2 seconds
- HIGH → rapid beeping

---

## Step 11 — Build the case

See the CAD files in [cad/](../cad/) for a 3D-printable enclosure.

**If you don't have a 3D printer:** Use a small plastic project box from a hardware store. Cut holes for the screen, sensor, and charging cable with a hobby knife. It works just as well for testing.

Mount the sensor pointing backward at a slight downward angle (about 20–30 degrees).

---

## Troubleshooting

**No data from sensor**
Check that TX and RX are not swapped. The sensor's TX goes to the ESP32's RX (GPIO16), and vice versa.

**Constant false alarms**
Lower the signal strength threshold in your code, or increase the debounce time beyond 500ms.

**Screen not working**
Confirm it's an I2C screen (not SPI — they look similar). Check SDA is on GPIO21 and SCL is on GPIO22.

**Upload fails**
Hold the BOOT button on the ESP32 while clicking Upload, then release it once the upload starts.
