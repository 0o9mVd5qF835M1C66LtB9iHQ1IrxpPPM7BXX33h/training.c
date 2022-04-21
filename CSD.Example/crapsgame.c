#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define  GAMEREPEATNUMBER 1000000000

int rollfunc()
{
	int roll1=rand()%6+1;
	int roll2=rand()%6+1;
	return roll1+roll2;
}

int game(void)
{
	int roll=rollfunc();
	switch(roll)
	{
		case 2:
		case 3:
		case 12: return 0;
		case 7:
		case11: return 1;
		default: return gamecontinue(roll);
	}
}

int gamecontinue(int roll)
{
	int newroll;
	while(1)
	{
		newroll=rollfunc();
		if(newroll==roll)
			return 1;
		if(newroll==7)
			return 0;
	}
}

int main(void)
{
	int wincounter=0;
	int k;
	srand(time(0));
	for(k=0;k<GAMEREPEATNUMBER;++k)
	{
		wincounter+=game();
		printf("win probability=%lf\n",(double)wincounter/GAMEREPEATNUMBER);
		getch();
		return 0;
	}
}
