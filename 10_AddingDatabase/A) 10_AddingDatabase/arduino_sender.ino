// Exercise 10 - Arduino sender (simulate sensor values over Serial)
// In real setup, you might send via MQTT; for proof-of-concept we send via Serial.

const int SENSOR_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int v = analogRead(SENSOR_PIN);
  Serial.println(v);   // one value per line
  delay(1000);
}
