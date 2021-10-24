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
			scanf("%d",&a[i][j]);//输入 
	// 计算横向的重复三次及以上的数字 
	for( i=0;i<n;i++)//对于每行而言 
	{
		int p=1;//作为标记出现的 
		int k = a[i][0];//对于第i+1行而言 
		for( j=1;j<m;j++)//从第二列开始比较 
		{
			if(a[i][j] == k)
			{
				p++;//p标记重复的个数 
			}
			else if(p >= 3)//当出现不同的数如果满足消去条件 ，开始循环 
			{
				int q = j;//不能占用标记列的字符 
				for( l=0;l<p;l++)
				{
					temp[i][q-1] =1;//重新定义一个数组，避免出现交叉情况 ，并且，将满足条件的标记为1 
					q--;
				}
				k = a[i][j];//重新开始比对计数 
				p = 1;
			}
			else//出现了不同的数，且不满足消去条件，重新开始比对 
			{
				k = a[i][j];
				p = 1;
			}
			if(j == m-1 && p>=3)//对于最后的数进行额外判断 
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
