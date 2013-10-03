#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main ()
{
	int red = 0, green = 0, blue = 100;
	int greens = 0, reds = 20, blues = 40;
	int greenp = 50, redp = 50, bluep = 50;
	int resolution = 100;
	int counter = 0;
	srand(time(NULL));
	wiringPiSetup();
	pinMode (0, OUTPUT);
        pinMode (2, OUTPUT);
        pinMode (3, OUTPUT);
	softPwmCreate(0, green, resolution);
	softPwmCreate(2, blue, resolution);
	softPwmCreate(3, red, resolution);	
	// Program loop. This program runs forever.
	while (1) {
		
		delay(5);
 
		if(!(counter % greenp)){
			green = (rand()) % 100;
			softPwmWrite(0, green);
		}
		if(!(counter % redp)) {
			red = (rand()) % 100;
			softPwmWrite(3, red);
		}
		if(!(counter % bluep)) {
			blue = (rand()) % 100;
			softPwmWrite(2, blue);
		}
		counter++;
	}



}
