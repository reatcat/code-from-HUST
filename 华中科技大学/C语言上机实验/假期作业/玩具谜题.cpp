#include<stdio.h>
int main()
{
    int n,m,a[100001],k=1,i,j,x,y;              
    char c[100001][11];//用二维数组，以数字字符串来统计 
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    scanf("%d %s",&a[i],c[i]);// 给一开始的人数还有朝向定位 
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
