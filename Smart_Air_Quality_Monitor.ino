// Smart_Air_Quality_Monitor.ino (v2 excerpt)
void loop() {
  unsigned long currentMillis = millis();

  // Task 1: Non-blocking button debounce (50ms refractory filter)
  int reading = digitalRead(PIN_BUTTON_MUTE);
  if (reading != lastButtonReading) { lastDebounceTimestamp = currentMillis; }
  if ((currentMillis - lastDebounceTimestamp) > BUTTON_DEBOUNCE_DELAY_MS) {
    if (reading != stableButtonState) {
      stableButtonState = reading;
      if (stableButtonState == LOW) { alarmMuted = !alarmMuted; }
    }
  }
  lastButtonReading = reading;

  // Task 2: High-frequency gas sampling (10 Hz / 100ms)
  if (currentMillis - lastGasSampleTimestamp >= INTERVAL_GAS_SAMPLE_MS) {
    lastGasSampleTimestamp = currentMillis;
    sampleGasAndActuateAlarm();
  }

  // Task 3: Display dashboard refresh (2 Hz / 500ms)
  if (currentMillis - lastLcdRefreshTimestamp >= INTERVAL_LCD_REFRESH_MS) {
    lastLcdRefreshTimestamp = currentMillis;
    refreshLcdDashboard();
  }
}
