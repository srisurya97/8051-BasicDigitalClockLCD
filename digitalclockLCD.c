#include<reg51.h>

sbit rs = P3^2;
sbit rw = P3^3;
sbit e = P3^4;
sbit set = P1^3;
sbit s = P1^4;


int hour=0, minute=0, hourtemp = 0, minutetemp = 0;

void delay(unsigned int);
void delay_1m();
void lcdinit();
void lcdsetup();
void lcddata(unsigned char);
void lcdcmd(char);
void string(char *);
int timesethour();
int timesetminute(int);
clock(int, int);

void main()
{
  set = 0;
  s = 0;	
  lcdinit();
	lcdsetup();
  string("Initializing...");
	delay(500);
	lcdcmd(0x01);
	delay(60);
	hour = timesethour();
	delay(200);
	minute = timesetminute(hour);
  clock(hour, minute);
	
}

void delay(unsigned int k)
{
unsigned int i,j;
	 for(i=0;i<k;i++)
	   for(j=0;j<130;j++);
}

void delay_m()
{
int count=0;
  while(count != 1200)	
	 {
		 TMOD = 0x01;
		 TH0 = 0X4B;
		 TL0 = 0XFD;
		 TR0 = 1;
		 while(TF0 == 0);
		 TF0 = 0;
		 TR0 = 0;
     count++;		 
	 } 
}


void lcdinit()
{
 e = 1;
 delay(50);
	
}

void lcdsetup()
{
	lcdcmd(0x38);
	delay(60);
	lcdcmd(0x0E);
	delay(60);
	lcdcmd(0x01);
	delay(60);
	lcdcmd(0x80);
	delay(60);
}

void lcdcmd(char cmd)
{
  P2 = cmd;
	rs=0;
  rw=0;
  e=1;
  delay(40);	
  e=0;
}	

void lcddata(unsigned char val)
{
  P2 = val;
	rs=1;
  rw=0;
  e=1;
  delay(20);	
  e=0;
}

void string(char *text)
{
//	while(*text)
//		lcddata(*text++);
int i=0;
while(text[i]!='\0')
{
lcddata(text[i]);
i++;	
}	
}

int timesethour()
{
  while(set != 1)
  {
    if(s == 1)
      {
		 	  if(hour < 12)
        hour = hour + 1;
        else hour = 1; 
		   }
		hourtemp = (hour/10)+48;
		lcddata(hourtemp);
		hourtemp = (hour%10)+48;
		lcddata(hourtemp);
		string(":");
    minutetemp = (minute/10)+48;
    lcddata(minutetemp);			
    minutetemp = (minute%10)+48;
    lcddata(minutetemp);			
    lcdcmd(0x80);
    delay(60); 			
  }
	
 	return hour;
}	

int timesetminute(int hour)
{ 
	
  while(set != 1)
  {
    if(s == 1)
     {
       if(minute < 60)
			 minute = minute + 1;
       else minute=0; 
		  }
		hourtemp = (hour/10)+48;
		lcddata(hourtemp);
		hourtemp = (hour%10)+48;
		lcddata(hourtemp);
		string(":");
    minutetemp = (minute/10)+48;
    lcddata(minutetemp);			
    minutetemp = (minute%10)+48;
    lcddata(minutetemp);			
    lcdcmd(0x80);
    delay(60); 			
  }
	
	return minute;
}

clock(int hour, int minute)
{
	while(1)
	{
     delay_m();
		 minute = minute + 1;
		    if(minute == 60)
          {
             hour = hour + 1;
             minute = 0;
				 	    if(hour > 12)
	   			 	     hour = 1;
            }
    hourtemp = (hour/10)+48;
		lcddata(hourtemp);
		hourtemp = (hour%10)+48;
		lcddata(hourtemp);
		string(":");
    minutetemp = (minute/10)+48;
    lcddata(minutetemp);			
    minutetemp = (minute%10)+48;
    lcddata(minutetemp);			
    lcdcmd(0x80);
    delay(60); 									
  }	 
	
}