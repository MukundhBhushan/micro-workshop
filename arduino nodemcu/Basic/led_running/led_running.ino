
int led[4]={ 16,5,4,0};

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

