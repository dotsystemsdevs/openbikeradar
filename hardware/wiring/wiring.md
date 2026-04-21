# Wiring — OpenBikeRadar V1

## LD2410 → ESP32

| LD2410 pin | ESP32 pin | Notes |
|------------|-----------|-------|
| VCC | 3.3V | DO NOT connect to 5V |
| GND | GND | |
| TX | GPIO16 (RX2) | Serial communication |
| RX | GPIO17 (TX2) | Serial communication |
| OT1 | GPIO4 | Optional: presence output |

## OLED (SSD1306) → ESP32

| OLED pin | ESP32 pin |
|----------|-----------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

## Buzzer → ESP32

| Buzzer pin | ESP32 pin |
|------------|-----------|
| + | GPIO25 |
| - | GND |

## Power (18650 + TP4056)

```
18650 battery
     ↓
  TP4056 (charge module)
     ↓
  On/off switch
     ↓
  ESP32 VIN (5V input)
```

The TP4056 outputs ~4.2V fully charged. ESP32 VIN accepts 4.75–12V — works fine.

## Breadboard layout (V1 prototype)

Keep sensor cable short — long cables on the serial lines can cause noise.
The LD2410 should point backward, tilted ~20–30° downward for best detection angle.
