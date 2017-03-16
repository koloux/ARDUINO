const int led = 12;
const int button = 4;

void setup() 
{
	pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() 
{
  if (digitalRead(button) == HIGH)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}
