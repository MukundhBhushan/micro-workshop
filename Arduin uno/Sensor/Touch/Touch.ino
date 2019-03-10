int TouchSensor = 7; //connected to Digital pin D1
int led = 8; // connected to Digital pin D4
void setup()
{
  Serial.begin(9600); // Communication speed
  pinMode(led, OUTPUT);
  pinMode(TouchSensor, INPUT);
}
void loop(){
  if(digitalRead(TouchSensor)==HIGH)       //Read Touch sensor signal
   { 
    digitalWrite(led, HIGH);   // if Touch sensor is HIGH, then turn on
    Serial.println("Led ON");
   }
  else
   {
    digitalWrite(led, LOW);    // if Touch sensor is LOW, then turn off the led
    Serial.println("Led OFF");
   }
  delay(500); // Slow down the output for easier reading
}


