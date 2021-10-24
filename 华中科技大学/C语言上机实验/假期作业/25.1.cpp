#include <stdio.h>
char e[105][105];
int n, m, vis[105][105];
int dir[8][2] = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
void dfs(int x, int y)
{
    int i;
    int dx, dy;
    vis[x][y] = 1;
    for (i = 0; i <= 7; i++)
    {
        dx = x + dir[i][0];
        dy = y + dir[i][1];
        if (e[dx][dy] == 'W' && vis[dx][dy] == 0)//水坑判断 
            dfs(dx, dy);
    }
}
int main()
{
    int i, j, ans = 0;
    scanf("%d%d", &n, &m);
    getchar();
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            scanf("%c", &e[i][j]);//直接用行列 
        getchar();//存放换行 
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (e[i][j] == 'W' && vis[i][j] == 0)
                dfs(i, j), ans++;
    printf("%d", ans);
    return 0;
}
