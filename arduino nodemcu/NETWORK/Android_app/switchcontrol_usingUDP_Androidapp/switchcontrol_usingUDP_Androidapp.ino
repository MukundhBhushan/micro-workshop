
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "XXXXXXX";
const char* password = "XXXXXXX";
uint16_t port = 8888;
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];

WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  delay(10);

  // prepare GPIO2
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  IPAddress myIp = WiFi.localIP();
  Serial.println(myIp);

  // Start the UDP client
  udp.begin(port);
}

void loop() {
  int packetSize = udp.parsePacket();
  if(packetSize) {
      //change ID:1 for ID:2 ID:3 to mach your SWITCH NUMBER
      String note ="ID:1. ";
      note += "Received packet of size ";
      note += packetSize;
      note += "  From: ";
      Serial.print(note);
      IPAddress remote = udp.remoteIP();
      for (int i =0; i < 4; i++)
      {
        Serial.print(remote[i], DEC);
        if (i < 3)
        {
          Serial.print(".");
        }
      }
      note= "  Port:";
      note += udp.remotePort();
      // read the packet into packetBufffer
      udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
      note += "  Contents:";
      note += packetBuffer;
      Serial.println(note);
     }  
     //change packetBuffer[0]=='1' for packetBuffer[0]=='2'  to mach your SWITCH NUMBER
     if( packetBuffer[0]=='1' && packetBuffer[2]=='2' && packetBuffer[8]=='1')
        digitalWrite(5, HIGH);
     if( packetBuffer[0]=='1' && packetBuffer[2]=='2' && packetBuffer[8]=='0')
        digitalWrite(5, LOW);
      memset(packetBuffer, 0, UDP_TX_PACKET_MAX_SIZE);
}    
  

