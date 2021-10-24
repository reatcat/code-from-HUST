#include<stdio.h>
int n,a[5001][5000];//超长 
int pd=0;//判定高位 
int main()
{
	a[0][1]=0;//特例 
	a[1][1]=1;
	a[2][1]=2;
	scanf("%d",&n);
	int i,j;
	for(i=3;i<=n;i++)
	{
		for(j=1;j<5000;j++) //j代表位数 
		a[i][j]=a[i-1][j]+a[i-2][j];//fib 
		for(j=1;j<5000;j++)
		{
			while(a[i][j]>9)
			{
				a[i][j+1]++;//像高位存储 
				a[i][j]-=10;
			}
		}
	}
	for(i=5000;i>1;i--)//从最高位开始 
	{
		if(!pd&&a[n][i]==0)
		continue;
		pd=1;
		printf("%d",a[n][i]);
	}
	printf("%d",a[n][1]);
	return 0;
}
