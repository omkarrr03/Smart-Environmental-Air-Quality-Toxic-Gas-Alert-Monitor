// Smart_Air_Quality_Monitor.ino (v1 excerpt)
void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  Wire.begin();
  lcd.init();
  dht.begin();
}

void loop() {
  int rawADC = analogRead(A0);
  float ppm = (rawADC * 5.0 / 1023.0) * 200.0;
  if (digitalRead(2) == LOW) { alarmMuted = !alarmMuted; }
  if (ppm > 500 && !alarmMuted) { digitalWrite(8, HIGH); }
  else { digitalWrite(8, LOW); }
  delay(2000); // Blocking delay halts execution
}
