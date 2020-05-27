// solar panels max space 29x17 inch
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
//#include <Dns.h>

const char* ssid = "AS701.NET";
const char* password = "wow-wow-wubbzy";

// data is a struct for holding the imput JSON data
struct data {
  int red;
  int green;
  int blue;

};

#define redURL "http://llib.clickable.systems/r"
#define greenURL "http://llib.clickable.systems/g"
#define blueURL "http://llib.clickable.systems/b"

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

data getColors() {

  data colors;

  chkRed(&colors);
  chkGreen(&colors);
  chkBlue(&colors);

  

  return colors;
}

void chkRed(data* obj) {
  HTTPClient client;

  client.begin(redURL);

  int httpCode = client.GET();//Send the request
 
  String color = "N/A";

  

  color = client.getString();
 

  
  client.end();
  
  //Serial.println(color);

  obj->red = color.toInt();
}

void chkGreen(data* obj) {
  HTTPClient client;

  client.begin(greenURL);
  
  int httpCode = client.GET();//Send the request
 
  String color = "N/A";

  color = client.getString();
  
  client.end();

  obj->green = color.toInt();
}

void chkBlue(data* obj) {
  HTTPClient client;

  client.begin(blueURL);

  int httpCode = client.GET();//Send the request
 
  String color = "N/A";

  color = client.getString();
  
  client.end();

  obj->blue = color.toInt();
}

void loop() {
  data colors = getColors();
  Serial.println(colors.blue);
  delay(1000);
}