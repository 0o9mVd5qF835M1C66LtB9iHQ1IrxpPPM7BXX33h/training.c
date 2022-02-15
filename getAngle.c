#include <stdio.h>

double get_angle(int hour, int minute);
int main()
{
	int h,min;
	printf("saat ile dakika değerlerini giriniz:\n");
	scanf("%d%d",&h,&min);
	printf("angle=%lf\n",get_angle(h,min));
	getch();
}
double get_angle(int hour, int minute)
{
	int angleHour;
	int angleMinute;
	double angleResult;
	if(hour>12)
		hour=hour-12;
	if(hour==12)
		hour=0;
	if(minute>60)
		return 0;
	angleHour=hour*5*6;
	angleMinute=minute*6;
	if(angleHour>=angleMinute)
		angleResult=angleHour-angleMinute;
	if(angleHour<angleMinute)
		angleResult=angleMinute-angleHour;
	printf("%lf.Angle",angleResult);
	return angleResult;
}
