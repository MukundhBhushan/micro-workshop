#include <ESP8266WiFi.h>
void setup() {
  WiFi.mode(WIFI_AP); //switching to AP mode
  WiFi.softAP("ESP8266-12"); //initializing the AP with ssid and password. This will create a WPA2-PSK secured AP
  WiFi.begin();
}

void loop() {

}
