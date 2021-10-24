#include<stdio.h>
int main()
{
	float a;
	scanf("%f",&a);
	a*=10;
	int c;
	c=(int )a;
	char b[4];
	int i=3;
	for(i=0;i<4;i++)
	{
		b[i]=c%10;
		c=c/10;
	}
	printf("%d.",b[0]);
	for(i=1;i<4;i++)
	{
		printf("%d",b[i]);
	}
	return 0;
 } 
