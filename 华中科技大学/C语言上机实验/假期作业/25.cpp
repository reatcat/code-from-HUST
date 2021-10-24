#include<stdio.h>
void dfs(int x, int y, char e[][101], int n, int m)
{
    e[x][y] = '.';
    int dx, dy;
    int i, j;
    for (i = -1; i <= 1; i++)
        for (j = -1; j <= 1; j++)
        {
            dx = x + i;
            dy = y + j;
            if (dx >= 0 && dx <= n  && dy >= 0 && dy <= m - 1 && e[dx][dy] == 'w')
                dfs(dx, dy, e, n, m);
        }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    char e[101][101];
    int i, j;
    int num = 0;
    getchar();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%c", &e[i][j]);
        getchar();
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (e[i][j] == 'w')
            {
                dfs(i, j, e, n, m);
                num++;
            }
    printf("%d", num);
    return 0;
}

