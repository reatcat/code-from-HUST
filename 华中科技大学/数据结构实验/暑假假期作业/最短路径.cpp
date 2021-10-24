#include<stdio.h>
#include<string.h>
#include<math.h>
#define state 555556
//#define error 2147483647
#define maxn 555
int min(int a,int b)
{
	return (a>b)?b:a;
}
int a[maxn][maxn],n,m,s;
void floyd()//运用佛洛依德算法 
{
    for(int k=1;k<=n;k++)
    //需要枚举 
	{
        for(int i=1;i<=n;i++)
		{
            if(i==k||a[i][k]==state)//这里用一个足够大的数进行标记 
            {
                continue;//自己到自己 
			}
			for(int j=1;j<=n;j++)
			{
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);//取最小路径 
            }
        }
    }
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
		{
            a[i][j]=state;
        }
    }
    for(int i=1,u,v,w;i<=m;i++)
	{
        scanf("%d%d%d",&u,&v,&w);
        a[u][v]=min(a[u][v],w);
        //防止出现重边 
    }
    floyd();
    a[s][s]=0;//自己到自己 
    for(int i=1;i<=n;i++)
    {
    	if(a[s][i]==state) 
  		printf("2147483647 "); 
		else	
        printf("%d ",a[s][i]);
    }
    return 0;
}
