/*
 * Kiwistrons
 * KiwisIoT - MQ-2 Gas Sensor
 * NodeMCU ESP8266
 */

#include <KiwisIoT.h>

const char* ssid  = "YOUR_WIFI_NAME";
const char* pass  = "YOUR_WIFI_PASSWORD";
const char* topic = "dash_1787738664437";

KiwisIoT kiwisiot(ssid, pass, topic);

#define GAS_PIN A0

void setup() {

  Serial.begin(9600);

  kiwisiot.begin();
}

void loop() {

  kiwisiot.run();

  // Read MQ-2 analog value
  int gasValue = analogRead(GAS_PIN);

  // Send gas value to Channel ID 1
  kiwisiot.send("1", gasValue);

  Serial.print("Gas Value = ");
  Serial.println(gasValue);

  delay(1000);
}