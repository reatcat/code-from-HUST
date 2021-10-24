#include<stdio.h>
long long c[21][21],flag[21][21];
int main()
{
    int n,m,i,j,a,b;
    c[0][0]=1;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    if(a>=2&&b>=1) flag[a-2][b-1]=1;//可以被马吃掉的 
    if(a>=2) flag[a-2][b+1]=1;
    if(a>=1&&b>=2) flag[a-1][b-2]=1;
    if(a>=1) flag[a-1][b+2]=1;
    if(b>=2) flag[a+1][b-2]=1;
    flag[a+1][b+2]=1;
    if(b>=1) flag[a+2][b-1]=1;
    flag[a+2][b+1]=1;
    flag[a][b]=1;
    for(i=1;i<=n;i++)
    {
        if(flag[i][0]==0) 
		c[i][0]=c[i-1][0];
        else 
		break;//flag为1则路线为0 
    }
    for(i=1;i<=m;i++)
    {
        if(flag[0][i]==0) 
		c[0][i]=c[0][i-1];
        else 
		break;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(flag[i][j]==1) 
			continue;
            c[i][j]=c[i-1][j]+c[i][j-1];//上面的点与左边的点之和 
        }
    }
    printf("%lld",c[n][m]);
    return 0;
}

