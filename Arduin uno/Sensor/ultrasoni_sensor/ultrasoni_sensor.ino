
#define TRIGGER 12 // defining trigger pin
#define ECHO 11 // defining echo pin
int led=9;

void setup()
{
  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT); //initializing trigger as output
  pinMode(ECHO, INPUT); //initialing trigger as input
  pinMode(led,OUTPUT);
  }

void loop()
{
  float duration1, dist1;
  digitalWrite(TRIGGER, LOW); // make trigger low
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH); // make trigger high
  delayMicroseconds(10); //give 10 microsec delay
  digitalWrite(TRIGGER, LOW);
  duration1 = pulseIn(ECHO, HIGH);
  dist1 = (duration1 / 2000000) * 34000; // calibrate the distance using pulse
  Serial.print("distance: ");
  Serial.println(dist1); // Print the distance value
  delay(1000);
 int m=map(dist1,0,300,255,0);
  analogWrite(led,m);
  
}
