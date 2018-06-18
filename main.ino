int pwmPin = 10;
int maxPWM = 255;

void fadeSequence (int count, int fadeDelay, int maxPWM)
{
  for (int x=1; x <= count; x++)
  {
    for (int i=0; i <= maxPWM; i++)
    {
      analogWrite(pwmPin, i);
      delay(fadeDelay);
    }

    for (int i=maxPWM; i >= 0; i--)
    {
      analogWrite(pwmPin, i);
      delay(fadeDelay);
    }
  }
}

void flashSequence(int count, int flashDelay, int maxPWM)
{
  for (int x=1; x <= count; x++)
  {
    analogWrite(pwmPin, maxPWM);
    delay(flashDelay);
    analogWrite(pwmPin, 0);
    delay(flashDelay); 
  }
}

void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pwmPin, OUTPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop()
{
  fadeSequence(10, 5, maxPWM);
  delay(500);
  flashSequence(10, 500, maxPWM); 
}
