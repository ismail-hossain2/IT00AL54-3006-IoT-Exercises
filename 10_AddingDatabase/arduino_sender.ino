// Exercise 10 - Adding Database
// Arduino sender: sends sensor value every 1 second via Serial

const int SENSOR_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);  // 0–1023
  Serial.println(sensorValue);               // send value to computer
  delay(1000);
}
