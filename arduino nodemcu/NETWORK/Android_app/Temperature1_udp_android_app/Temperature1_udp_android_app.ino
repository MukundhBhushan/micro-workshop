#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <DHT.h>

#define DHTPIN 5                            //Pin D1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);  

//change ssid and password with your credentials
const char* ssid = "Wifilink";
const char* password = "kmvgrp020";
uint16_t port = 8888;
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];


WiFiUDP udp;

void setup() {
    dht.begin();
  Serial.begin(115200);
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Start the UDP client and temperature driver
  udp.begin(port);
  Serial.println(WiFi.localIP());
}

void loop() {
  int packetSize = udp.parsePacket();
  if(packetSize) {
      udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
      Serial.println(packetBuffer);
     }
     //change packetBuffer[0]=='1' for packetBuffer[0]=='2' if you are refering to node 2
   if( packetBuffer[0]=='1' && packetBuffer[2]=='1' ){
    //change "1,1,0,0:" for "2,1,0,0:"  if you are refering to node 2.
      String message ="1,1,0,0:";
      char payload[5];
      float h = dht.readHumidity();                       // Reading humidity

     float t = dht.readTemperature();                    // Read temperature as Celsius

  if (isnan(h) || isnan(t))                           // Check if any reads failed and exit early (to try again).
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

       Serial.println("Temperature :");
       Serial.println(t);

       Serial.println("Humidity :");
       Serial.println(h);
      double T=double(t);
      delay(10);
      dtostrf(T,5,2,payload);
      //String Spayload = 
      message += String(payload);
      for(int i=0; i<4; i++){
      udp.beginPacket(udp.remoteIP(), 8888);
      udp.print(message);
      udp.endPacket();
      delay(70);}
      Serial.println(message);
      memset(packetBuffer, 0, UDP_TX_PACKET_MAX_SIZE);
    }     
}
