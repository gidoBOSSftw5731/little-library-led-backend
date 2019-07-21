#include <ESP8266WiFi.h>

const char* ssid = "AS701.NET";
const char* password = "wow-wow-wubbzy";

void setup() {
  WiFi.begin(ssid, password);
  Serial.begin(9600);
  while (WiFi.status() != WL_CONNECTED) {
  
    delay(1000);
    Serial.println("Connecting..");
  
  }
}

void loop() {
  Serial.println(WiFi.localIP());
}