#include<stdio.h>
int n, x, y;
void dfs(int t, int sx, int sy, int x, int y)
{//sx��sy��������������Ͻ�λ�ã�xy��ʾ��������λ�ã���ռ����λ�ã�
	if(t == 0) return;
	int t1 = (1 << t - 1);//С�����α߳�
	if(x < sx + t1 && y < sy + t1)//���Ͻ�
	{
		printf("%d %d %d\n", sx + t1, sy + t1, 1);
		dfs(t - 1, sx, sy, x, y), dfs(t - 1, sx, sy + t1, sx + t1 - 1, sy + t1);
		dfs(t - 1, sx + t1, sy, sx + t1, sy + t1 - 1), dfs(t - 1, sx + t1, sy + t1, sx + t1, sy + t1);
	}
	else if(x < sx + t1)//���Ͻ�
	{
		printf("%d %d %d\n", sx + t1, sy + t1 - 1, 2);
		dfs(t - 1, sx, sy, sx + t1 - 1, sy + t1 - 1), dfs(t - 1, sx, sy + t1, x, y);
		dfs(t - 1, sx + t1, sy, sx + t1, sy + t1 - 1), dfs(t - 1, sx + t1, sy + t1, sx + t1, sy + t1);
	}
	else if(y < sy + t1)//���½�
	{
		printf("%d %d %d\n", sx + t1 - 1, sy + t1, 3);
		dfs(t - 1, sx, sy, sx + t1 - 1, sy + t1 - 1), dfs(t - 1, sx, sy + t1, sx + t1 - 1, sy + t1);
		dfs(t - 1, sx + t1, sy, x, y), dfs(t - 1, sx + t1, sy + t1, sx + t1, sy + t1);
	}
	else//���½�
	{
		printf("%d %d %d\n", sx + t1 - 1, sy + t1 - 1, 4);
		dfs(t - 1, sx, sy, sx + t1 - 1, sy + t1 - 1), dfs(t - 1, sx, sy + t1, sx + t1 - 1, sy + t1);
		dfs(t - 1, sx + t1, sy, sx + t1, sy + t1 - 1), dfs(t - 1, sx + t1, sy + t1, x, y);
	}
}

int main()
{
	scanf("%d%d%d", &n, &x, &y);
	dfs(n, 1, 1, x, y);
	return 0;
}
