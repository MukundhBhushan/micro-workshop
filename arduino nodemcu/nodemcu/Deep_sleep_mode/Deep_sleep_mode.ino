//connect rst pin to D0
#include <ESP8266WiFi.h>
#define SLEEP_DELAY_IN_SECONDS  30
void setup()
{
  Serial.begin(9600);
  Serial.println("wake up");
  pinMode(5, OUTPUT);
}

void loop()
{
  digitalWrite(5, LOW);
  delay(2000);
  digitalWrite(5, HIGH);
  delay(2000);
  ESP.deepSleep(10000000, WAKE_RF_DEFAULT); // Sleep for 10 seconds

}
