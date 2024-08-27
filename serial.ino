void setupSerial() {
  Serial.begin(9600); while(!Serial);
  Serial.println("=== KOPMYLLIKA_DJLA_UHECCbl, setup() ===");
}