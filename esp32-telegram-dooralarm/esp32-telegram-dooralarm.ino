
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <WiFiManager.h>
#include <HTTPClient.h>


const int reedSwitch = 5; //set reedswitch pin

const char* room_id "room_id";
const char* server "http://127.0.0.1:5505";


WiFiClientSecure client;

void setup() {

  Serial.begin(115200);  //open serial port
  
WiFiManager wm;

 
pinMode(reedSwitch, INPUT_PULLUP); //set pinmode

 bool res;

res = wm.autoConnect("AutoConnectAP","password"); // password protected ap, you can replace the password and ssid
  //send startup message

}

void loop() {  //sets the value of  the reedSwitch pin at the start as base, and  then checks if anything changed, then acts acordingly
  static int lastval = !digitalRead(reedSwitch);
  int val = digitalRead(reedSwitch);

  if (val != lastval)
  {
    if (val == LOW)
    {
      
      Serial.println("door open");
      //send message via http

    }
    else
    {
      
      Serial.println("door closed");
      //send message via http
      
    }
    lastval = val;
  }
}
