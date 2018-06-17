int pwmPin = 10;
int ambientLightPin = A7;
int maxPWM = 255;

void fadeFlash (int number_of_times, int fadeDelay, int maxPWM)
{
  for (int x=1; x <= number_of_times; x++)
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

void flash(int number_of_times, int flashDelay)
{
  for (int x=1; x <= number_of_times; x++)
  {
    analogWrite(pwmPin, ambientLightToPWM(ambientLightPin));
    delay(flashDelay);
    analogWrite(pwmPin, 0);
    delay(flashDelay); 
  }
}

int ambientLightToPWM(int ambientLightPin)
{
  int PWM = 1 + (analogRead(ambientLightPin) / (1024/255));
  Serial.println("Actual Light Level:" + String(PWM));

  if (PWM >= 255)
  {
    PWM = 255;
  }
  Serial.println("Adjusted Light Level:" + String(PWM));
  Serial.println();
  return PWM;
}

void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pwmPin, OUTPUT);
  pinMode(ambientLightPin, INPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop()
{
  // fadeFlash(10, 5, ambientLightToPWM(ambientLightPin));
  // delay(500);
  flash(10, 500); 
}
