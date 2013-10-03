#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct color
{
	int red;
	int green;
	int blue;
};

int main ()
{
	int red = 0, green = 0, blue = 0;
	int resolution = 100;
	char buffer[12];
	char newbuf[12];
	char* bufEnd = newbuf;
	FILE * fileStream;
	struct color colorList[300];	
	int i=0;
	int rselect=0;

	fileStream = fopen("colors.txt", "r");
	while(!feof(fileStream)) {

		fgets(buffer, 8, fileStream);
		newbuf[0] = buffer[0];
		newbuf[1] = buffer[1];
		newbuf[2] = ' ';
		newbuf[3] = buffer[2];
		newbuf[4] = buffer[3];
		newbuf[5] = ' ';
		newbuf[6] = buffer[4];
		newbuf[7] = buffer[5];
		newbuf[8] = '\0';	
	
		colorList[i].red = strtol(newbuf, &bufEnd, 16);
		colorList[i].green = strtol(bufEnd, &bufEnd , 16);
		colorList[i].blue = strtol(bufEnd, &bufEnd, 16);
		i++;
	}
	
	//printf("%d %d %d\n", colorList[1].red, colorList[1].green, colorList[1].blue);
	
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
		
		delay(700);
		rselect = (rand()) % (i-1); 
		green = (int)(((double)(colorList[rselect].green)/255)*100);
		softPwmWrite(0, green);
		red = (int)(((double)(colorList[rselect].red)/255)*100);;
		softPwmWrite(3, red);
		blue = (int)(((double)(colorList[rselect].blue)/255)*100);;
		softPwmWrite(2, blue);
	}


return 0;
}

