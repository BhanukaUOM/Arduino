#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

//name and password of wifi neteork
const char* ssid = "asd";
const char* password = "123456789";
    
void setup(){
  Serial.begin(115200);
  delay(10);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }
  Serial.println("Connected to ");
  Serial.println(ssid);
  Serial.println("Hello, Internet");
  delay(1000);
  Serial.println("IP Address");
  Serial.println(WiFi.localIP());
}

void loop(){
}
