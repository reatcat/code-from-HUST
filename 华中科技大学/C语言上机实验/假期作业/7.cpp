#include<stdio.h>
int main()
{
	int x;
	long n;
	scanf("%d %d",&n,&x);
	int i,a,b,count;
	for(i=1;i<=n;i++)
	{
		a=i;
		while(a)
		{
			b=a%10;
			a=a/10;
			if(b==x)
			count++;
		}
	}
	printf("%d",count);
	return 0;
}

