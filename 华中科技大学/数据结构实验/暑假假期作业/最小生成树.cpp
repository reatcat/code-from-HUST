#include<cstdio>
#define MAXSIZE 1000
int min(int a,int b)
{
	return (a>b)?b:a;
}
int state[MAXSIZE];//记录状态 
int dis[MAXSIZE];//用于记录距离树的距离最短路程
int MAX = 99999;//边界值
int tu[MAXSIZE][MAXSIZE];//用于记录所有边的关系
int main()
{
    int i,j,k;
    int n,m;
    int x,y,z;
    int min,minv;
    int sum=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    	if(i!=j)
    		tu[i][j]=MAX;
    	else
    		tu[i][j]=0;	
		}
	}
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d",&x,&y,&z);//xy中长为z的边 
        tu[x][y]=z;
        tu[y][x]=z;
    }
    //先从1开始 
    for (i = 1; i <= n; i++)
        dis[i] = tu[1][i];

    state[1]=1;//记录1已经被访问过了

    for (i = 1; i <= n-1; i++)
    {
        min = MAX;//一开始认为是无穷 
        for (j = 1; j <= n; j++)
        {
            if(state[j] ==0 && dis[j] < min)//没有访问过且最小 
            {
                min = dis[j];
                minv = j;
            }
        }

        //记录这个点已经被访问过了
        state[minv] = 1;
        sum += dis[minv];

        for (j = 1; j <= n; j++)
        {
            //如果这点没有被访问过，而且这个点到任意一点的距离比现在到树的距离近那么更新
            if(state[j] == 0 && tu[minv][j] < dis[j])
                dis[j] = tu[minv][j];
        }
    }
	if(sum<MAX)
    printf("%d",sum);
    else 
    printf("orz");
}
