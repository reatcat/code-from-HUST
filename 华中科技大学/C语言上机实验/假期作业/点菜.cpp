#include<stdio.h>
int n,m,a[101],b[101][10001]={0};//��ʾ����nʱ���õķ��� 
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
		  b[i][j]=b[i-1][j]+1;//��һ��ֻ��ǰ��Ʒ�� 
          if(j>a[i]) 
		  b[i][j]=b[i-1][j]+b[i-1][j-a[i]];//�๺��ǰƬ 
          if(j<a[i])
			b[i][j]=b[i-1][j];
      }
      printf("%d",b[n][m]);
	return 0;
 } 
