# Build Guide — OpenBikeRadar V1

## Before you start

Read the full BOM: [hardware/bom.md](../hardware/bom.md)
Check the wiring: [hardware/wiring/wiring.md](../hardware/wiring/wiring.md)

## Step 1 — Flash the ESP32

1. Install [Arduino IDE](https://www.arduino.cc/en/software) or PlatformIO
2. Add ESP32 board support
3. Connect ESP32 via USB
4. Upload the placeholder firmware from `firmware/src/main.ino`
5. Open Serial Monitor at 115200 baud — confirm it prints "OpenBikeRadar starting..."

**Do this before buying or connecting anything else.**

## Step 2 — Connect the LD2410 sensor

Follow [hardware/wiring/wiring.md](../hardware/wiring/wiring.md).

Power on. The LD2410 starts outputting data immediately on Serial2.

## Step 3 — Read and understand the data

Wave your hand in front of the sensor. You should see values change in Serial Monitor.

Key values from LD2410:
- Moving target distance (cm)
- Moving target signal strength
- Stationary target distance (cm)
- Stationary target signal strength

## Step 4 — Add filtering

Before building any logic, add basic filtering:
- Ignore detections shorter than 500ms
- Require 3 consecutive positive readings before triggering

This prevents false alarms from branches, walls, brief reflections.

## Step 5 — Build risk logic

```
distance > 300cm             → CLEAR
150cm < distance < 300cm     → LOW
80cm < distance < 150cm      → MED
distance < 80cm OR closing fast → HIGH
```

## Step 6 — Connect OLED

Follow wiring guide. Display should show current risk level.

## Step 7 — Connect buzzer

Different patterns for different risk levels:
- LOW: no sound
- MED: single short beep every 2s
- HIGH: rapid beeping

## Step 8 — Field test (do this early)

Mount everything temporarily with tape or cable ties.
Stand with the bike on a quiet road. Have someone walk/cycle/drive behind you.
Note what triggers false alarms and tune your thresholds.

## Step 9 — Build the enclosure

See CAD files in `cad/` — print the enclosure, mount sensor pointing backward at 20–30° tilt.

## Troubleshooting

**No data from sensor:** Check TX/RX are not swapped. LD2410 TX → ESP32 RX (GPIO16).

**False alarms:** Lower signal strength threshold, increase debounce time.

**OLED not working:** Confirm it's I2C (not SPI). Check SDA/SCL connections.
