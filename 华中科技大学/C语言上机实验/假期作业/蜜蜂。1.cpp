#include<stdio.h>
int n,m,a[5001][5000];//���� 
int pd=0;//�ж���λ 
int main()
{
	a[0][1]=0;//���� 
	a[1][1]=1;
	a[2][1]=2;
	scanf("%d%d",&m,&n);
	int i,j;
	for(i=3;i<=n-m;i++)
	{
		for(j=1;j<5000;j++) 
		a[i][j]=a[i-1][j]+a[i-2][j];
		for(j=1;j<5000;j++)
		{
			while(a[i][j]>9)
			{
				a[i][j+1]++;//���λ�洢 
				a[i][j]-=10;
			}
		}
	}
	for(i=5000;i>1;i--)
	{
		if(!pd&&a[n-m][i]==0)
		continue;
		pd=1;
		printf("%d",a[n-m][i]);
	}
	printf("%d",a[n-m][1]);
	return 0;
}
