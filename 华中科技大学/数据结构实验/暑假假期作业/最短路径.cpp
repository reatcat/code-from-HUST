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
void floyd()//���÷��������㷨 
{
    for(int k=1;k<=n;k++)
    //��Ҫö�� 
	{
        for(int i=1;i<=n;i++)
		{
            if(i==k||a[i][k]==state)//������һ���㹻��������б�� 
            {
                continue;//�Լ����Լ� 
			}
			for(int j=1;j<=n;j++)
			{
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);//ȡ��С·�� 
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
        //��ֹ�����ر� 
    }
    floyd();
    a[s][s]=0;//�Լ����Լ� 
    for(int i=1;i<=n;i++)
    {
    	if(a[s][i]==state) 
  		printf("2147483647 "); 
		else	
        printf("%d ",a[s][i]);
    }
    return 0;
}
