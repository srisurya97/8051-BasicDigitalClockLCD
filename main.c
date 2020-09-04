#include<reg51.h>
#include"7seg.h"

//       0   1  2
//P0 g   0   0  1
//P1 f   1   0  0
//P2 a   1   0  1
//P3 b   1   1  1
//P4 e   1   0  1  
//P5 d   1   0  1
//P6 c   1   1  0
//P7 dot 0   0  0

//char digit[10]={0x7E, 0x48, 0x3D};

int count = 0;
int minute = 0;
int hour = 0;

void timer0_ISR(void) interrupt 1
{
	count++;
}

void CounterTimer(){
	TMOD = 0x01;
	TL0 = 0x00;
	TH0 = 0x00;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}


void main()
{
	CounterTimer();
	SegmentsInit();	
	
	while(1){
			if(count >= 915){ 
				count = 0;
				minute++;
				if(minute >= 60){
					minute = 0;
					hour++;
				}
			}
			showNumbers(hour/10,hour%10,minute/10,minute%10);
	}
}
