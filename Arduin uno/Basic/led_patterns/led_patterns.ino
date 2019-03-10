int ledPin[] = {4,5,6,7};

void setup()
{
  for (int i =0;i<4;i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() 
{
  byte nums[] = {0, 1,2, 3, 4, 5,6,7,8,9,10,11,12,13,14,15};
  for (byte i = 0; i<16;i++)
  {
    displayBinary(nums[i]);
    delay(1000);
  } 
}

void displayBinary(byte numToShow)
{
  for (int i =0;i<4;i++)
  {
    if (bitRead(numToShow, i)==1)
    {
      digitalWrite(ledPin[i], HIGH); 
    }
    else
    {
      digitalWrite(ledPin[i], LOW); 
    }
  }
}
