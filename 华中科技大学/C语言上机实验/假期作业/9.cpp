#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n][n];
	int i=0,j=n/2;
	int k=1;
	for(k=1;k<=n*n;k++)
	{
		a[i][j]=k;
		if(k%n==0)//当出现输入数的倍数的时候，退一行 
		{
			i++;
		if(i==n)//到最后一行的时候 
		
			i=0;
		}
		else {//未出现异常情况，下一个数存在于右斜上方 
			i--;
			j++;
		}
		if(i<0) //如果到了第一行，转向最后一行 
		i=n-1;
		if(j==n)//如果到了第一列，转向最后一列 
		j=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
 } 
