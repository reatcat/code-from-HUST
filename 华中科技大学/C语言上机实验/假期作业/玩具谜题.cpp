#include<stdio.h>
int main()
{
    int n,m,a[100001],k=1,i,j,x,y;              
    char c[100001][11];//�ö�ά���飬�������ַ�����ͳ�� 
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    scanf("%d %s",&a[i],c[i]);// ��һ��ʼ���������г���λ 
    for(j=1;j<=m;j++)
    {
        scanf("%d %d",&x,&y);                 
        if(a[k]==0)     
        {
            if(x==0)
			k=k-y; 
            else 
			k=k+y;
        }
        else
        {
            if(x==0)
			k=k+y;
            else 
			k=k-y;
        }
        if(k>n)
		k-=n; 
        if(k<=0)
		k+=n;
    }
    printf("%s",c[k]);
    return 0;
} 
