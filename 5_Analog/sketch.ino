// Exercise 5 - Analog (Potentiometer + LED PWM)
// Based on course exercise "5 - Analog"

const int POT_PIN = A0;
const int LED_PIN = 9;   // PWM pin (~)

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int pot = analogRead(POT_PIN);          // 0..1023
  Serial.println(pot);

  // Exercise: LED ON above half, OFF below half
  if (pot > 512) {
    // ON
    // digitalWrite(LED_PIN, HIGH); // (not ideal on PWM pin, so use analogWrite)
    analogWrite(LED_PIN, 255);
  } else {
    analogWrite(LED_PIN, 0);
  }

  // Exercise: brightness controlled by potentiometer
  int brightness = map(pot, 0, 1023, 0, 255);
  analogWrite(LED_PIN, brightness);

  delay(50);
}
