// Exercise 9 - Communication basics (MQTT template)
// NOTE: Fill WiFi + broker settings to run on real hardware or supported simulator environment.

#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASS";

const char* mqttServer = "test.mosquitto.org";
const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

const char* topic = "centri/iot/hello";

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message received on ");
  Serial.print(topic);
  Serial.print(": ");

  for (unsigned int i = 0; i < length; i++) Serial.print((char)payload[i]);
  Serial.println();
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting MQTT...");
    if (client.connect("IsmailClient")) {
      Serial.println("OK");
      client.subscribe(topic);
    } else {
      Serial.println("failed, retrying...");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  reconnect();

  client.publish(topic, "Hello World!");
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();
}
