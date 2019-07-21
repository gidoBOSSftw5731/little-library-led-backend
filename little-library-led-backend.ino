#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "AS701.NET";
const char* password = "wow-wow-wubbzy";

HTTPClient client;

// data is a struct for holding the imput JSON data
struct data {
  char* red;
  char* green;
  char* blue;

};

#define server "http://pastebin.com/raw/5Qg6AzhP"

const unsigned long HTTP_TIMEOUT = 10000;  // max respone time from server
const size_t MAX_CONTENT_SIZE = 512;       // max size of the HTTP response



void setup() {
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  while (WiFi.status() != WL_CONNECTED) {
  
    delay(1000);
    Serial.println("Connecting..");
  
  }
}

void loop() {
   if(connect(server)) {
    if(sendRequest(server)) {
      data data;
      readResponseContent(&data);
      printData(&data);
      
    }
  }


  client.end();

}

void printData(const struct data* data) {
  Serial.print("red: ");
  Serial.println(data->red);
  Serial.print("green: ");
  Serial.println(data->green);
  Serial.print("blue: ");
  Serial.println(data->blue);
}

void readResponseContent(struct data* input) {

    DynamicJsonDocument root(JSON_OBJECT_SIZE(3));
    deserializeJson(root, input);
    //JsonObject& root = buf.parseObject(data);

    strcpy(input->red, root["red"]);
    strcpy(input->green, root["green"]);
    strcpy(input->blue, root["blue"]);

} 


bool sendRequest(const char* host) {
  Serial.print("GET ");
  Serial.println(host);
  /*
  client.print("GET ");
  client.print(resource);
  client.println(" HTTP/1.1");
  client.print("Host: ");
  client.println(host);
  client.println("Connection: close");
  client.println();*/

  return true;
}

bool connect(const char* hostName) {
  Serial.print("Connect to ");
  Serial.println(hostName);

  bool ok = client.begin(hostName);

  Serial.println(ok ? "Connected" : "Connection Failed!");
  return ok;
}