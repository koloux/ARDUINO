const int l1 = 2;
const int l2 = 3;
const int l3 = 4;
const int l4 = 5;
const int l5 = 6;
const int l6 = 7;
boolean l_state = 0;
unsigned long prev = 0;

void setup() 
{
	pinMode(l1, OUTPUT);
	pinMode(l2, OUTPUT);
	pinMode(l3, OUTPUT);
	pinMode(l4, OUTPUT); 
	pinMode(l5, OUTPUT);
	pinMode(l6, OUTPUT);
	l_state = 0;

	digitalWrite(l1, LOW);
	digitalWrite(l2, HIGH);
	digitalWrite(l3, HIGH);
	digitalWrite(l4, HIGH);
	digitalWrite(l5, HIGH);
	digitalWrite(l6, LOW);
}

void loop()
{
	digitalWrite(l1, LOW);
	digitalWrite(l6, LOW);
	delay(2500);
	digitalWrite(l6, HIGH);
	for (int i = 0; i < 5; i++)
	{
		digitalWrite(l5, l_state);
		l_state = !l_state;
		delay(500);
	}
	l_state = 0;
	digitalWrite(l5, HIGH);
	digitalWrite(l1, HIGH);
	digitalWrite(l4, LOW);
	digitalWrite(l3, LOW);
	delay(2500);
	digitalWrite(l3, HIGH);
	for (int i = 0; i < 5; i++)
	{
		digitalWrite(l2, l_state);
		l_state = !l_state;
		delay(500);
	}
	l_state = 0;
	digitalWrite(l2, HIGH);
	digitalWrite(l4, HIGH);
}
