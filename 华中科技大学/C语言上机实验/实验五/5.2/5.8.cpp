#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int m=n*n;
	int i=0;
	int a[100][100];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		a[i][j]=j+1;
	}
	return 0;
}
