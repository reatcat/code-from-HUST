#include<stdio.h>
int main()
{
	double y;
	int x;
	scanf("%lf",&y);
	x=y*10000; 
	x/=10000;
	if(x>=5)
		y+=0.0005;
	printf("%.3lf",y);
	return 0;
 } 
