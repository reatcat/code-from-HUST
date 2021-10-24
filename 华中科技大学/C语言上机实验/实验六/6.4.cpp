#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n][m];
	int b[m][n];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int *p=&a[0][0];
	int *q=&b[0][0];
	
		for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		*(q+i*n+j)=*(p+j*m+m-1-i);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
