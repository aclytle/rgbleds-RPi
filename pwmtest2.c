#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main ()
{
	int red = 0, green = 0, blue = 100;
	int greens = 0, reds = 20, blues = 40;
	int greenp = 50, redp = 100, bluep = 100;
	int resolution = 100;
	int counter = 0;
	srand(time(NULL));
	wiringPiSetup();
	pinMode (0, OUTPUT);
        pinMode (2, OUTPUT);
        pinMode (3, OUTPUT);
        //digitalWrite(0, LOW);
        //digitalWrite(2, LOW);
        //digitalWrite(3, LOW);
	softPwmCreate(0, green, resolution);
	softPwmCreate(2, blue, resolution);
	softPwmCreate(3, red, resolution);	
	// Program loop. This program runs forever.
	while (1) {
		
		delay(5);
		//printf("%d\n", counter % 100);
		greens = (int)(rand()*100) % 100;
		blues = (int)(rand()*100) % 100;
		reds = (int)(rand()*100) % 100;
 
		if(!(counter % greenp)){
			softPwmWrite(0, green += greens);
		}
		if(!(counter % redp)) {
			 softPwmWrite(3, red += reds);
		}
		if(!(counter % bluep)) {
			 softPwmWrite(2, blue += blues);
		}
		if(blue < 0 || blue > 100){
			 blues *= -1;
			 blue += blues;
		}
		if(green < 0 || green > 100){
			greens *= -1;
			green += greens;
		}		
		if(red < 0 || red > 100) {
			reds *= -1;
			red += greens;
		}
//		printf("%d\n", counter);	
		counter++;
	}



}
