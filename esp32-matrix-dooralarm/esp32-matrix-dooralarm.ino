#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <WiFiManager.h>
#include <HTTPClient.h>
#include <string>

const int reedSwitch = 5; //set reedswitch pin

#define room_id "roomid"
#define server_url "serverurl"
// If authentication is enabled
#define auth_secret "authsecret" 

HTTPClient http;

WiFiClientSecure client;

void setup() {

  Serial.begin (115200);  //open serial port 
  
WiFiManager wm;

 
pinMode (reedSwitch, INPUT_PULLUP); //set pinmode

 bool res;

res = wm.autoConnect("AutoConnectAP","password"); // password protected ap, you can replace the password and ssid
  http.setReuse(true);
	
  http.begin (server_url);
  http.addHeader ("Content-Type", "text/plain");
  http.addHeader ("Channel", room_id);
  http.addHeader ("Authorization", auth_secret);
  int httpResponseCode = http.POST ("Started up");
  if (httpResponseCode == 401) {
  Serial.print ("Invalid auth_secret");
  }
  http.end();

}

void loop() {  
  //sets the value of  the reedSwitch pin at the start as base, and  then checks if anything changed, then acts acordingly
  static int lastval = !digitalRead(reedSwitch);
  int val = digitalRead(reedSwitch);

  if (val != lastval)
  {
    if (val == LOW)
    {
      
      Serial.println ("door open");
      //send message via http to matrix-notifier
      http.begin (server_url);
      http.addHeader ("Content-Type", "text/plain");
      http.addHeader ("Channel", room_id);
      http.addHeader ("Authorization", auth_secret);
      int httpResponseCode = http.POST ("The door is open");
      if (httpResponseCode == 401) {
      Serial.print ("Invalid auth_secret");
      }
      http.end();

    }
    else
    {
      
      Serial.println ("door closed");
      //end message via http to matrix-notifier
      http.begin (server_url);
      http.addHeader ("Content-Type", "text/plain");
      http.addHeader ("Channel", room_id);
      http.addHeader ("Authorization", auth_secret);
      int httpResponseCode = http.POST ("The door is closed");
      if (httpResponseCode == 401) {
      Serial.print ("Invalid auth_secret");
      }
      http.end();
      
    }
    lastval = val;
  }
}
