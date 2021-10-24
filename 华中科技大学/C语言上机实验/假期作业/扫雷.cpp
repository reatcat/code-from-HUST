#include<stdio.h> 
int a[1000][1000]={0};
int main()
{
    int n,m;
    char t;
    scanf("%d %d\n",&n,&m);
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++) 
        {
            scanf("%c",&t);
            if(t=='*') a[i][j]=1;//如果是地雷就将这个点设为一 
        }
        getchar();
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i][j]) 
			printf("*"); 
            else
            {
                printf("%d",a[i+1][j+1]+a[i+1][j-1]+a[i+1][j]+a[i][j+1]+a[i][j-1]+a[i-1][j+1]+a[i-1][j]+a[i-1][j-1]);
                
            }
        }
        printf("\n");
    }
    return 0;
}
