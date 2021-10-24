#include<stdio.h>
int head[100000],cnt;
long long ans[1000000];
int state[1000000];
int m,n,s;
struct edge
{
	int to;
	int next;
	int wei;
}edge[1000000];
void store(int x,int y,int z)
{
	edge[++cnt].to=y;
	edge[cnt].wei=z;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n;i++)
	{
		ans[i]=2147483647;
	}
	ans[s]=0;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		store(a,b,c);
	}
	int pos=s;
	while(state[pos]==0)
	{
		long long minn=2147483647;
		state[pos]=1;
		for(int i=head[pos];i!=0;i=edge[i].next)
		{
			if(!state[edge[i].to]&&ans[edge[i].to]>ans[pos]+edge[i].wei)
			{
				ans[edge[i].to]=ans[pos]+edge[i].wei;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(ans[i]<minn&&state[i]==0)
			{
				minn=ans[i];
				pos=i;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
}
