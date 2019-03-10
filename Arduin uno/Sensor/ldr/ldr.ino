void setup() 
{
  Serial.begin(9600);
  pinMode(3,OUTPUT);
}
void loop() 
{int i=analogRead(A0);
 int j=map(i,0,1023,0,255);
 Serial.println(i);
 Serial.println(j);
 analogWrite(3,(255-j));
 delay(100);
}
