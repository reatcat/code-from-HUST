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
		if(k%n==0)//�������������ı�����ʱ����һ�� 
		{
			i++;
		if(i==n)//�����һ�е�ʱ�� 
		
			i=0;
		}
		else {//δ�����쳣�������һ������������б�Ϸ� 
			i--;
			j++;
		}
		if(i<0) //������˵�һ�У�ת�����һ�� 
		i=n-1;
		if(j==n)//������˵�һ�У�ת�����һ�� 
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
