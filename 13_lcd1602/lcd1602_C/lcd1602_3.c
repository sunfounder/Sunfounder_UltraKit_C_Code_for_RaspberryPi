#include <stdio.h>
#include <stdlib.h>

#include <wiringPi.h>
#include <lcd.h>

const unsigned char Buf[] = "---SUNFOUNDER---";

int main(void)
{
	int fd;
	int i;
	
	if(wiringPiSetup() == -1){
		exit(1);
	}
	
	fd = lcdInit(2, 16, 8,  11,10 , 0,1,2,3,4,5,6,7); //see /usr/local/include/lcd.h
	if (fd == -1){
		printf("lcdInit 1 failed\n") ;
		return 1;
	}
	sleep(1);

	lcdClear(fd);
	lcdPosition(fd, 0, 0); 
	lcdPuts(fd, "  Raspberry Pi!");

	lcdPosition(fd, 0, 1); 
	lcdPuts(fd, Buf);

	/*sleep(1);
	lcdClear(fd);
	
	while(1){
		for(i=0;i<sizeof(Buf)-1;i++){
			lcdPosition(fd, i, 1);
			lcdPutchar(fd, *(Buf+i));
			delay(200);
		}
		//lcdPosition(fd, 0, 1); 
		lcdClear(fd);
		sleep(1);
	}
*/
	return 0;
}
