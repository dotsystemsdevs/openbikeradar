# OpenBikeRadar — Projektplan

## Vad vi bygger
En open source cykelradar-prototyp som kan:
- Känna att något finns bakom cykeln
- Uppskatta avstånd
- Avgöra om något närmar sig
- Visa status på liten skärm
- Ge varning med ljud/vibration

---

## Delar (köp detta)

| Del | Antal | Notering |
|-----|-------|----------|
| ESP32 DevKit (WROOM) | 2 st | Köp backup direkt |
| LD2410 radar/mmWave-sensor | 1 st | Kärnan i projektet |
| OLED 0.96" I2C (SSD1306) | 1 st | Display |
| Buzzer | 1 st | Enkelt alert V1 |
| Breadboard | 1 st | |
| Dupontkablar | 1 set | |
| 18650-batteri (3000mAh) | 1 st | ~15h drifttid |
| Laddmodul TP4056 (USB-C) | 1 st | |
| On/off-switch | 1 st | |
| USB-kabel till ESP32 | 1 st | |

**Budget: ~400–600 kr**

Strömförbrukning: LD2410 + ESP32 + OLED ≈ 150–200mA → 18650 (3000mAh) ger ~15 timmar.

---

## Systemarkitektur

```
[ LD2410 sensor ]
        ↓
      ESP32
    ↙       ↘
 OLED      Buzzer
```

---

## Bygge — fas 1 (proof of concept)

| Del | Vad |
|-----|-----|
| 1. Sensor-modul | Känner av objekt bakom |
| 2. Hjärna | ESP32 läser sensorn |
| 3. Display | Visar status och avstånd |
| 4. Alert | Buzzer med olika mönster |
| 5. Mjukvara | Detection + risk-logik + filtrering |
| 6. Test-rigg | Tillfällig montering |
| 7. Case V1 | Enkel 3D-printad kapsling |

## Bygge — fas 2 (riktig cykelversion)

| Del | Vad |
|-----|-----|
| 8. Cykelmontering | Fäste för sadelstolpe |
| 9. Strömförsörjning | Batteri + laddning |
| 10. Väderanpassning | Bättre kapsling |
| 11. Bättre UI | Tydligare visning |
| 12. Fälttest | Riktig test ute |

---

## 13-dagars serieupplägg

### DAG 1 — Problemet
**Bygger:** Ingenting hårdvara. Sätter projektet.
**Video:** Varför detta behövs, vad du ska bygga, varför inte bara köpa Garmin.
**Hook:** "Jag bygger min egen cykelradar."

---

### DAG 2 — Delarna + systemet
**Bygger:** Samla allt, rita blockskiss.
**Video:** Visa alla komponenter, förklara vad varje del gör, rita kopplingsschema på papper.
*(Dag 2 + 3 slagna ihop — sparar tid, samma naturliga flow)*

---

### DAG 3 — Första kopplingen
**Bygger:** Koppla sensor till ESP32.
**Video:** Timelapse av koppling, close-up på komponenter.
- VCC, GND, TX/RX
- Starta upp

---

### DAG 4 — Första data
**Bygger:** Första kodtest. Läs data i serial monitor.
**Video:** Skärminspelning, första gången siffror kommer in.
- Arduino IDE / PlatformIO
- ESP32-board vald
- Sensorvärden i terminalen

---

### DAG 5 — Förstå datan + filtrering
**Bygger:** Tolka sensorvärden. Bygg enkel filtrering.
**Video:** Gå fram/bak från sensorn, visa hur siffror ändras.

**Viktigt — lägg till detta här:**
- Ignorera detektioner kortare än 500ms
- Kräv 3 konsekutiva positiva läsningar innan trigger
- Definiera tröskelvärde för "verklig" detektion

*(Filtrering MÅSTE in tidigt — annars fastnar du i falska larm och tappar tempo)*

---

### DAG 6 — Första detection-logiken
**Bygger:** Enkel klassificering.
**Video:** "Nu försöker jag få den att fatta skillnad på inget och något."

```
Inget objekt
Objekt upptäckt
Objekt närmar sig
```

---

### DAG 7 — Risknivåer
**Bygger:** LOW / MED / HIGH.
**Video:** Förklara att rå data inte räcker — du måste skapa "meaning".

```
Långt bort = LOW
Närmare    = MED
Nära + snabbt = HIGH
```

---

### DAG 8 — Display
**Bygger:** Koppla OLED, visa status.
**Video:** Koppla skärmen, visa när text dyker upp.

```
CLEAR
OBJECT DETECTED
APPROACHING
```

---

### DAG 9 — Första fälttest (tidigt — viktigt)
**Bygger:** Ingen ny feature. Montera provisoriskt och testa utomhus.
**Video:** Verklig miljö, låt någon gå/cykla/bil passera bakom.

*(Fälttest MÅSTE komma här — inte dag 12. Du vill inte bygga på fel antaganden i 10 dagar.)*

---

### DAG 10 — Alert-system
**Bygger:** Buzzer med olika beteende för MED/HIGH.
**Video:** Demo av ljud, jämför olika varningsmönster.

---

### DAG 11 — Test-rigg
**Bygger:** Tillfällig montering. Allt sitter ihop som prototyp.
**Video:** "Den ser hemsk ut men den sitter ihop."

---

### DAG 12 — Case
**Bygger:** Enkel 3D-printad kapsling.
**Video:** CAD → print → montering.

**OBS:** Ha plan B om print tar tid — plastlådscase som ersätter printad version.

- Hål för skärm, kabel, sensor
- Passar sadelstolpe

---

### DAG 13 — V1 demo
**Bygger:** Sätter ihop allt.
**Video:** Fullständig demo av detect → distance → risk → alert. Before/after.

---

## Videomall (varje avsnitt)

1. Hook — vad händer idag
2. Problem — vad är svårt
3. Bygge — vad du gör
4. Resultat — vad funkade / inte funkade
5. Nästa steg

---

## Prioriteringsordning (bygg i denna ordning)

1. Sensor fungerar
2. ESP32 läser data
3. Du förstår datan + filtrering
4. Enkel logik
5. Display
6. Fälttest (tidigt)
7. Alert
8. Test-rigg
9. Case
10. Bättre version

---

## Positionering

**Du säger inte:** "Jag uppfann en radar"
**Du säger:** "Jag gjorde det byggbart"

Gap i marknaden: sensor-teknik finns, DIY-projekt finns, Garmin Varia finns — men en enkel open source version som vem som helst kan bygga saknas helt.
