#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "AS701.NET";
const char* password = "wow-wow-wubbzy";

HTTPClient http;

void setup() {
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  while (WiFi.status() != WL_CONNECTED) {
  
    delay(1000);
    Serial.println("Connecting..");
  
  }
}

void loop() {
  Serial.println(WiFi.localIP());

  http.begin("http://restoncoffeemachine.appspot.com/");
  http.addHeader("Content-Type", "application/octet-stream");
  
  int httpCode = http.POST("Message from ESP8266");
  String payload = http.getString();

  Serial.println(payload);


  http.end();
}