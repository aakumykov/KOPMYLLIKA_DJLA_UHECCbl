#define BUZZER_PIN 3

void playAllowSound() {
  playSound(1200, 100);
}

void playDenySound() {
  playSound(600, 200);
}

void playSound(unsigned int freq, unsigned long diration) {
  tone(BUZZER_PIN, freq);
  delay(diration);
  noTone(BUZZER_PIN);
}