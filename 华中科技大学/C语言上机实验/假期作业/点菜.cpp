#include<stdio.h>
int n,m,a[101],b[101][10001]={0};//表示购买到n时所用的方案 
int main()
{
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
      for(j=1;j<=m;++j)
      {
          if(j==a[i])
		  b[i][j]=b[i-1][j]+1;//多一个只买当前菜品的 
          if(j>a[i]) 
		  b[i][j]=b[i-1][j]+b[i-1][j-a[i]];//多购买前片 
          if(j<a[i])
			b[i][j]=b[i-1][j];
      }
      printf("%d",b[n][m]);
	return 0;
 } 
