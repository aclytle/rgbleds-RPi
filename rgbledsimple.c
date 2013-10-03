#include <wiringPi.h>

main ()
{
	int pwm = 100;
	wiringPiSetup();
	pinMode (0, OUTPUT);
	pinMode (2, OUTPUT);
	pinMode (3, OUTPUT);
	digitalWrite(0, LOW);
	digitalWrite(2, LOW);
	digitalWrite(3, LOW);
	
	while (1)
	{
		digitalWrite(0, HIGH);
		delay(500);
		digitalWrite(2, HIGH);
		delay(500);
		digitalWrite(0, LOW);
		delay(500);
		digitalWrite(3, HIGH);
		delay(500);
		digitalWrite(2, LOW);
		delay(500);
		digitalWrite(0, HIGH);
		delay(500);
		digitalWrite(3, LOW);


	}
}

