// OpenBikeRadar V1 — placeholder
// Full firmware coming in Day 4 of build series

// Pins
#define RADAR_RX 16
#define RADAR_TX 17
#define BUZZER_PIN 25
#define OLED_SDA 21
#define OLED_SCL 22

void setup() {
  Serial.begin(115200);
  Serial2.begin(256000, SERIAL_8N1, RADAR_RX, RADAR_TX);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.println("OpenBikeRadar starting...");
}

void loop() {
  // Read from LD2410 via Serial2
  // Parse detection data
  // Classify risk level
  // Update display
  // Trigger alert if needed
}
