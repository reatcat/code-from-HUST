#include <bits/stdc++.h>//ΩË”√sort 
using namespace std;
#define MAXSIZE 1000000
int dl[MAXSIZE];
int state1[MAXSIZE],state2[MAXSIZE];
struct node{
	int x;
	int y;
}b[MAXSIZE];
int ver[MAXSIZE],nxt[MAXSIZE],head[MAXSIZE],tot,n,m,tail,had=1,sum=0;
void init(int a,int b) {
	ver[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
}
void dfs(int v)
{
	state1[v]=1;
	for(int i=head[v];i;i=nxt[i])
	if(!state1[ver[i]]) 
		{
			sum++;
			printf("%d",ver[i]);
			if(sum!=n)
			printf(" ",ver[i]);
			dfs(ver[i]);
		}
}
void bfs(int v)
{
	sum=0;
	dl[++tail]=1;
	state2[v]=1;
	printf("1 ");
	while(had<=tail)
	{
		if(sum==n)
		return;
		int x=dl[had];
		had++;
		for(int i=head[x];i;i=nxt[i])
		if(!state2[ver[i]])
		{
			state2[ver[i]]=1;
			dl[++tail]=ver[i];
			sum++;
			printf("%d",ver[i]);
			if(sum!=n)
			printf(" ");
		}
	}
}
int MAX(node a,node b)
{
	if(a.y>b.y||(a.y==b.y&&a.x>b.x))
	return 1;
	else return 0;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&b[i].x,&b[i].y);
	}
	sort(b+1,b+m+1,MAX);
	for(int i=1;i<=m;i++)
	init(b[i].x,b[i].y);
	printf("1 ");
	dfs(1);
	printf("\n");
	bfs(1);
}
