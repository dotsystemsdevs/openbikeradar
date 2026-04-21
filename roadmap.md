# Roadmap — OpenBikeRadar

## Var vi är nu

**Fas:** Pre-build. Repo satt upp. Plan klar. Inga delar köpta ännu.

---

## Status

### Fas 0 — Setup
- [x] Projektplan klar
- [x] Repo satt upp
- [x] Kopplingsschema klart (på papper)
- [ ] Delar beställda
- [ ] Delar mottagna

### Fas 1 — Proof of concept
- [ ] ESP32 flashad och testad
- [ ] LD2410 kopplad till ESP32
- [ ] Sensordata i serial monitor
- [ ] Filtrering implementerad (debounce 500ms, 3 konsekutiva träffar)
- [ ] Detection-logik (inget / objekt / närmar sig)
- [ ] Risknivåer (LOW / MED / HIGH)
- [ ] OLED kopplad och visar status
- [ ] Buzzer kopplad med olika mönster
- [ ] Första fälttest utomhus

### Fas 2 — Cykelversion
- [ ] 3D-printad kapsling V1
- [ ] Batteri + laddning inkopplat
- [ ] Monterat på sadelstolpe
- [ ] Fälttest på riktigt
- [ ] Firmware städad och kommenterad
- [ ] Build guide komplett

### Fas 3 — Open source release
- [ ] GitHub repo publikt
- [ ] README med bilder
- [ ] Video-serie klar
- [ ] Första issue/PR från någon annan

---

## Nuvarande blockers

- Ingenting klart förrän delar är beställda.

## Nästa konkreta steg

1. Beställ ESP32 + LD2410 + OLED + buzzer
2. När de kommer: flash ESP32, bekräfta att den svarar
3. Koppla sensor, öppna serial monitor, se att data kommer in
