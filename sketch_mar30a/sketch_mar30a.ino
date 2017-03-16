#include <stdlib.h>

const int green = 8;
const int blue = 10;
const int yellow = 12;
int n = 3;

void liteUp(const int led)
{
	digitalWrite(led, LOW);
	delay(500);
	digitalWrite(led, HIGH);
	delay(500);
}

int *memoryGenerator(int lvl)
{
	int rand;
	int i;
	int *mem; 

	mem = (int *)malloc(sizeof(int) * lvl);
	i = 0;
	while (i < lvl)
	{
		rand = random(3);
		if (rand == 0)
		{
			mem[i] = green;
		}
		else if (rand == 1)
		{
			mem[i] = blue;
		}
		else
		{
			mem[i] = yellow;
		}
		i++;
	}
	return (mem);	
}

int	buttonTest(int *mem, int memory)
{
	
	if (digitalRead(memory))	
	{
		digitalWrite(memory);
		delay(500);
		return (1);
	}
	return (-1);	
}

void setup()
{
	pinMode(green, OUTPUT);
	digitalWrite(green, HIGH);
	pinMode(blue, OUTPUT);
	digitalWrite(blue, HIGH);
	pinMode(yellow, OUTPUT);
	digitalWrite(yellow, HIGH);
	randomSeed(analogRead(0));

	pinMode(1, INPUT);
	pinMode(2, INPUT);
	pinmode(3, INPUT);
}

void loop()
{
	int *mem;
	int i;

	mem = memoryGenerator(n);
	i = 0;
	while (i < n)
	{
		liteUp(mem[i]);
		i++;
	}
	while (i)
	{
		if (buttonTest(mem, i))
		i--;
	}
	free(mem);
	delay(2000);
	n++;
}
