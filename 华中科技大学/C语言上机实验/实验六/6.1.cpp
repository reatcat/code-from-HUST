#include<stdio.h>
int main()
{
	long n,k;
	scanf("%d",&n);
	char *p=(char*)&n;
	char high,low;
    p=p+3;
	for(k=0;k<4;k++)
	{
		 low=(*p)&0x0f;
		high=(*p>>4)&0x0f;
       
		p--;
		printf("%x %x ",high,low);
	}
	return 0;
 } 
