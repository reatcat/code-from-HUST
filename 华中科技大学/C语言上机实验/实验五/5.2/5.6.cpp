#include<stdio.h>
int main()
{
	int n,m;
	int i,j,l;
	scanf("%d%d",&n,&m);
	int a[100][100] = {0};
	int temp[100][100]={0};  
	for( i=0;i<n;i++)
		for( j=0;j<m;j++)
			scanf("%d",&a[i][j]);//���� 
	// ���������ظ����μ����ϵ����� 
	for( i=0;i<n;i++)//����ÿ�ж��� 
	{
		int p=1;//��Ϊ��ǳ��ֵ� 
		int k = a[i][0];//���ڵ�i+1�ж��� 
		for( j=1;j<m;j++)//�ӵڶ��п�ʼ�Ƚ� 
		{
			if(a[i][j] == k)
			{
				p++;//p����ظ��ĸ��� 
			}
			else if(p >= 3)//�����ֲ�ͬ�������������ȥ���� ����ʼѭ�� 
			{
				int q = j;//����ռ�ñ���е��ַ� 
				for( l=0;l<p;l++)
				{
					temp[i][q-1] =1;//���¶���һ�����飬������ֽ������ �����ң������������ı��Ϊ1 
					q--;
				}
				k = a[i][j];//���¿�ʼ�ȶԼ��� 
				p = 1;
			}
			else//�����˲�ͬ�������Ҳ�������ȥ���������¿�ʼ�ȶ� 
			{
				k = a[i][j];
				p = 1;
			}
			if(j == m-1 && p>=3)//�������������ж����ж� 
			{
				int q = j;
				for( l=0;l<p;l++)
				{
					temp[i][q] = 1;
					q--;
				}
			}
		}
	}

	for( j=0;j<m;j++)
	{
		int p=1;
		int k = a[0][j];
		for( i=1;i<n;i++)
		{
			if(a[i][j] == k)
			{
				p++;
			}
			else if(p >= 3)
			{
				int q = i;
				for( l=0;l<p;l++)
				{
					temp[q-1][j] = 1;
					q--;
				}
				k = a[i][j];
				p = 1;
			}
			else
			{
				k =a[i][j];
				p = 1;
			}
			if(i == n-1 && p>=3)
			{
				int q = i;
				for( l=0;l<p;l++)
				{
					temp[q][j] = 1;
					q--;
				}
			}
		}
	}

	
	for( i=0;i<n;i++)
	{
		for( j=0;j<m;j++)
		{
			if(temp[i][j]==1)
			a[i][j]=0;
			if(j<m-1)
			printf("%d ",a[i][j]);
			else
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
