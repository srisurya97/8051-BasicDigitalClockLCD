#include<reg51.h>
#include"7seg.h"


//       0   1
//P0 g   0   0
//P1 f   1   0 
//P2 a   1   0
//P3 b   1   1
//P4 e   1   0
//P5 d   1   0
//P6 c   1   1
//P7 dot 0   0

//Numbers
//

int digitloop = 0;
int digitTime = 300;

void delay(int k)       
    {
    int i;
    for(i=0;i<k;i++)
    {
        TL1=0xFD;
         TH1=0x4B;
         TR1=1;
         while(TF1==0);
         TR1=0;
         TF1=0;
    }
}

void numberOne(void){
	digitloop = 0;
	while(digitloop <= digitTime){
		segb = 1;
		segb = 0;
		segc = 1;
		segc = 0;	
		digitloop++;
	}
}

void numberTwo(void){
	digitloop = 0;
	while(digitloop <= digitTime){
		sega = 1;
		sega = 0;
		segb = 1;
		segb = 0;	
		segg = 1;
		segg = 0;
		sege = 1;
		sege = 0;
		segd = 1;
		segd = 0;
		digitloop++;
	}
}

void numberThree(void){
	digitloop = 0;
	while(digitloop <= digitTime){
		sega = 1;
		sega = 0;
		segb = 1;
		segb = 0;	
		segg = 1;
		segg = 0;
		segc = 1;
		segc = 0;
		segd = 1;
		segd = 0;
		digitloop++;
	}
}

void numberFour(void){
	digitloop = 0;
	while(digitloop <= digitTime){
		segb = 1;
		segb = 0;	
		segg = 1;
		segg = 0;
		segc = 1;
		segc = 0;
		segf = 1;
		segf = 0;
		digitloop++;
	}
}

void numberFive(void){
	digitloop = 0;
	while(digitloop <= digitTime){
		sega = 1;
		sega = 0;	
		segg = 1;
		segg = 0;
		segc = 1;
		segc = 0;
		segf = 1;
		segf = 0;
		segd = 1;
		segd = 0;	
		digitloop++;
	}
}

void numberSix(void){
	digitloop = 0;
	while(digitloop <= digitTime){
		sega = 1;
		sega = 0;	
		segg = 1;
		segg = 0;
		segc = 1;
		segc = 0;
		segf = 1;
		segf = 0;
		segd = 1;
		segd = 0;
		sege = 1;
		sege = 0;	
		digitloop++;
	}
}

void numberSeven(void){
	digitloop = 0;
	while(digitloop <= digitTime){
		sega = 1;
		sega = 0;	
		segb = 1;
		segb = 0;
		segc = 1;
		segc = 0;
		digitloop++;
	}
}

void numberEight(void){
	digitloop = 0;
	while(digitloop <= digitTime){
		sega = 1;
		sega = 0;	
		segb = 1;
		segb = 0;
		segc = 1;
		segc = 0;
		segd = 1;
		segd = 0;	
		sege = 1;
		sege = 0;
		segf = 1;
		segf = 0;
		segg = 1;
		segg = 0;
		digitloop++;
	}
}

void numberNine(void){
	digitloop = 0;
	while(digitloop <= digitTime){
		sega = 1;
		sega = 0;	
		segb = 1;
		segb = 0;
		segc = 1;
		segc = 0;
		segd = 1;
		segd = 0;	
		segf = 1;
		segf = 0;
		segg = 1;
		segg = 0;
		digitloop++;
	}
}

void numberZero(void){
	digitloop = 0;
	while(digitloop <= digitTime){
		sega = 1;
		sega = 0;	
		segb = 1;
		segb = 0;
		segc = 1;
		segc = 0;
		segd = 1;
		segd = 0;	
		sege = 1;
		sege = 0;
		segf = 1;
		segf = 0;
		digitloop++;
	}
}

void SegmentsInit(void){
	//Segment Selection
	seg0 = 0;
	seg1 = 0;
	seg2 = 0;
	seg3 = 0;
	//LED selection
  segg = 0;
  segf = 0; 
  sega = 0;
  segb = 0;
  sege = 0;
  segd = 0;
  segc = 0;
  segdot = 0;
}

void showNumbers(int digit1, int digit2, int digit3, int digit4 ){
	
		seg0 = 1;
		switch (digit1){
			case 1:
				Number1;
				break;
			case 2:
				Number2;
				break;
			case 3:
				Number3;
				break;
			case 4:
				Number4;
				break;
			case 5:
				Number5;
				break;
			case 6:
				Number6;
				break;
			case 7:
				Number7;
				break;
			case 8:
				Number8;
				break;
			case 9:
				Number9;
				break;
			case 0:
				Number0;
				break;
		}
		seg0 = 0;
		seg1 = 1;
		switch (digit2){
			case 1:
				Number1;
				break;
			case 2:
				Number2;
				break;
			case 3:
				Number3;
				break;
			case 4:
				Number4;
				break;
			case 5:
				Number5;
				break;
			case 6:
				Number6;
				break;
			case 7:
				Number7;
				break;
			case 8:
				Number8;
				break;
			case 9:
				Number9;
				break;
			case 0:
				Number0;
				break;
		}
		seg1 = 0;
		seg2 = 1;
		switch (digit3){
			case 1:
				Number1;
				break;
			case 2:
				Number2;
				break;
			case 3:
				Number3;
				break;
			case 4:
				Number4;
				break;
			case 5:
				Number5;
				break;
			case 6:
				Number6;
				break;
			case 7:
				Number7;
				break;
			case 8:
				Number8;
				break;
			case 9:
				Number9;
				break;
			case 0:
				Number0;
				break;
		}
		seg2 = 0;
		seg3 = 1;
		switch (digit4){
			case 1:
				Number1;
				break;
			case 2:
				Number2;
				break;
			case 3:
				Number3;
				break;
			case 4:
				Number4;
				break;
			case 5:
				Number5;
				break;
			case 6:
				Number6;
				break;
			case 7:
				Number7;
				break;
			case 8:
				Number8;
				break;
			case 9:
				Number9;
				break;
			case 0:
				Number0;
				break;
		}
		seg3 = 0;
}


