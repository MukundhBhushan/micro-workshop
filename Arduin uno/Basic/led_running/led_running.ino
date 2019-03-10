
int led[4]={ 4,5,6,7};

void setup()
{
  for(int i=0; i<4; i++)
  {
    pinMode(led[i], OUTPUT);
  }
}

void loop()
{
  for(int i =0; i<4;i++)
  {
    digitalWrite(led[i], HIGH);
    delay(200);
    digitalWrite(led[i], LOW);
   }

  
}

