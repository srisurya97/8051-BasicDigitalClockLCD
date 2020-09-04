#ifndef __7SEG_H
#define __7SEG_H



#define Number1 numberOne()
#define Number2 numberTwo()
#define Number3 numberThree()
#define Number4 numberFour()
#define Number5 numberFive()
#define Number6 numberSix()
#define Number7 numberSeven()
#define Number8 numberEight()
#define Number9 numberNine()
#define Number0 numberZero()


sbit seg0 = P1^0;
sbit seg1 = P1^1;
sbit seg2 = P1^2;
sbit seg3 = P1^3;
 
sbit segg = P3^0;
sbit segf = P3^1; 
sbit sega = P3^2;
sbit segb = P3^3;
sbit sege = P3^4;
sbit segd = P3^5;
sbit segc = P3^6;
sbit segdot = P3^7;

void showNumbers(int, int, int, int);
void SegmentsInit(void);
void delay(int);
void numberOne(void);
void numberTwo(void);
void numberThree(void);
void numberFour(void);
void numberFive(void);
void numberSix(void);
void numberSeven(void);
void numberEight(void);
void numberNine(void);
void numberZero(void);

#endif