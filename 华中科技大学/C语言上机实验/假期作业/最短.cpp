#include<cstdio>
#include<algorithm>
#include<climits>
#define MAX 2147483647
#define maxn 50001
struct edge
{
    int to,next=0,w;
}edge[maxn];
int head[maxn];
int dis[maxn],n,m,s,t;    //edge´æ±ß £¬dis´æ¾àÀë£¬visÅĞ¶Ï±éÀúÌõ¼ş£»                         
void dj(int k)
{
    int  vis[maxn]={0};
    for(int i=1;i<=n;i++)
    {    
        int mi=MAX,t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j] && dis[j]<mi) 
            {
                mi=dis[j];
                t=j;            
            } 
        }    
        if(t==-1 || mi==MAX)   
        break;
        vis[t]=1;                   
        for(int j=head[t];j;j=edge[j].next)   
        {
            if(!vis[edge[j].to] && dis[edge[j].to]>(edge[j].w+dis[t]))
            dis[edge[j].to]=edge[j].w+dis[t];
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++)
    dis[i]=MAX;                                 
    dis[s]=0;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z); 
        edge[i].to=y;
        edge[i].w=z;
        edge[i].next=head[x];
        head[x]=i; 
    }    
    dj(n);                                   
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]);
    
    return 0;
}
