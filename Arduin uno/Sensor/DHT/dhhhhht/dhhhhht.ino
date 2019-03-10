#include <DHT.h>

#define DHTPIN 3                            //Pin D1
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);
  dht.begin();
  pinMode(13,OUTPUT);
}

void loop()
{
  Serial.println("Collecting temperature data.");
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
  delay(1000); 
  if(h>80)
  {
  digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
}



