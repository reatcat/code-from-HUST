#include<stdio.h>
#include<cmath>
int main()
{
	int n,m,x=0;
	scanf("%d%d",&n,&m);
	while(pow(x,m)<=n)
		x++;
	printf("%d",x-1);
	return 0;
} 

