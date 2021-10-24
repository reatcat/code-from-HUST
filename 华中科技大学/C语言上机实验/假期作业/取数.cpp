#include<stdio.h> 
int T, n, m, a[2001][2001];
int ans;
int u[2001][2001];
int max(int a,int b)
{
	if(a>=b)
	return a;
	else 
	return b;
}
void dfs(int x, int y, int z)     //(x, y)表示当前搜到的坐标位置，z表示搜到了(x, y)时，所取得的最大分数
{
    if (x > n)         //搜完时，更新答案
    {
        ans=max(ans, z);
        return ;
    }
    int next_x = x, next_y = y + 1;   //下一步的坐标(next_x, next_y)
    if (next_y > m)           //如果这一行搜完了
    {
        next_y = 1;           //从下一行的第一列继续搜
        next_x = x + 1;
    }
    if (!u[x - 1][y - 1] && !u[x - 1][y] && !u[x - 1][y + 1] && !u[x][y - 1] && !u[x][y + 1] && !u[x + 1][y - 1] && !u[x + 1][y] && !u[x + 1][y + 1])
    {                        //如果周围的8个点都没有选择的话
        u[x][y] = 1; //标记 
        dfs(next_x, next_y, z + a[x][y]);  //继续搜下一个点
        u[x][y] = 0;
    }
    dfs(next_x, next_y, z);   //如果周围8个点有已被选择的点的话，这个点不能选择，继续下一个点
}

int main()
{
    scanf("%d",&T);
    int sth,i,j;
    for (sth=1;sth<=T;sth++)
    {
        ans = 0;
    scanf("%d%d",&n,&m);
        for (i=1; i<=n;i++)  
            for (j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
        dfs(1, 0, 0);              
        printf("%d\n",ans);
    }
    return 0;
}
