#include <wiringPi.h>
#include <softPwm.h>

main ()
{
	int pwm = 1;
	int red = 20, green = 0, blue = 0;
	int counter = 0;
	wiringPiSetup();
	pinMode (0, OUTPUT);
        pinMode (2, OUTPUT);
        pinMode (3, OUTPUT);
        //digitalWrite(0, LOW);
        //digitalWrite(2, LOW);
        //digitalWrite(3, LOW);
	softPwmCreate(0, 50, 100);
	
	// Program loop. This program runs forever.
	while (1) {

		if (counter > 30000)
			counter = 0;

	//	if (counter % 4 == 0)
	//		red++;
		if (red > 0)
			digitalWrite(3, HIGH);
	//	else if(red >255)
	//		red = 0;
		if (green > 0)
        		digitalWrite(0, HIGH);
		if (blue > 0)
        		digitalWrite(2, HIGH);
		//PWM loop
		for (pwm = 1; pwm < 255; pwm++)
		{
			if (pwm == red)
				digitalWrite(3, LOW);
			if (pwm == green)
				digitalWrite(0, LOW);
			if (pwm == blue)
				digitalWrite(2, LOW);
		}	


	}



}
