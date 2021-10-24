#include<cstdio>
#define MAX 1000
int max(int a,int b)
{
    return a>b?a:b;
}
int n,s;
int a,b,t;
struct edge{
    int next,to;
    int w;
}e[MAX];
int head[MAX]={0},cnt=1;
void add(int u,int v,int w)
{
    e[cnt].next=head[u];
    e[cnt].to=v;
    e[cnt].w=w;
    head[u]=cnt++;
}
long long f[500010]={0},ans=0;
void dfs(int u,int fa)
{
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
        f[u]=max(f[u],f[v]+e[i].w);
    }
    for(int i=head[u];i;i=e[i].next)
        if(fa!=e[i].to)
            ans+=f[u]-f[e[i].to]-e[i].w;
}
int main()
{
	scanf("%d",&n);
	scanf("%d",&s); 
    for(int i=1;i<n;i++)
    {
    	scanf("%d%d%d",&a,&b,&t);
		add(a,b,t);
		add(b,a,t);
	}
    dfs(s,0);
    printf("%lld",ans);
    return 0;
}
