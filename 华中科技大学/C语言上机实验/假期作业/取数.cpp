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
void dfs(int x, int y, int z)     //(x, y)��ʾ��ǰ�ѵ�������λ�ã�z��ʾ�ѵ���(x, y)ʱ����ȡ�õ�������
{
    if (x > n)         //����ʱ�����´�
    {
        ans=max(ans, z);
        return ;
    }
    int next_x = x, next_y = y + 1;   //��һ��������(next_x, next_y)
    if (next_y > m)           //�����һ��������
    {
        next_y = 1;           //����һ�еĵ�һ�м�����
        next_x = x + 1;
    }
    if (!u[x - 1][y - 1] && !u[x - 1][y] && !u[x - 1][y + 1] && !u[x][y - 1] && !u[x][y + 1] && !u[x + 1][y - 1] && !u[x + 1][y] && !u[x + 1][y + 1])
    {                        //�����Χ��8���㶼û��ѡ��Ļ�
        u[x][y] = 1; //��� 
        dfs(next_x, next_y, z + a[x][y]);  //��������һ����
        u[x][y] = 0;
    }
    dfs(next_x, next_y, z);   //�����Χ8�������ѱ�ѡ��ĵ�Ļ�������㲻��ѡ�񣬼�����һ����
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
