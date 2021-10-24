#include<stdio.h>

int main()
{
	int n,m;
	scanf("%d%d",&m,&n);
	int a[1001][1001];
	a[1][1]=1;
	a[1][2]=1;
	int i,j;
	for(i=1;i<=m;i++)
	for(j=3;j<=n;j++)
	a[i][j]=a[i][j-1]+a[i][j-2];
	printf("%d",a[m][n]);
//	int i,j;
//	for(i=3;i<=n-m;i++)
//	{
//		for(j=1;j<1000;j++) 
//		a[i][j]=a[i-1][j]+a[i-2][j];
//		for(j=1;j<1000;j++)
//		{
//			while(a[i][j]>9)
//			{
//				a[i][j+1]++;
//				a[i][j]-=10;
//			}
//		}
//	}
//	for(i=1000;i>1;i--)
//	{
//		if(!pd&&a[n-m][i]==0)
//		continue;
//		pd=1;
//		printf("%d",a[n-m][i]);
//	}
//	printf("%d",a[n-m][1]);
	return 0;
}

