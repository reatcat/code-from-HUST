#include<stdio.h>
#define inf 2147483647
#define maxn 10005
#define maxm 500005
#define MAXSIZE 100
typedef struct{
	int data[MAXSIZE];
	int front;
	int rear; 
}Queue; //队列的定义 

void InitQueue(Queue *Q)
{
	Q->front=Q->rear=0;
}
void EnQueue(Queue *Q,int e)
{
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXSIZE;//此处的循环队列将rear指向后一个空的位置 
 }
void DeQueue(Queue *Q,int * e)
{
	*e = Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
 }
 //以下为补充的函数
int QueueEmpty(Queue *Q)
{
	if(Q->front==Q->rear) return 1;
	else return 0; 
 }
int QueueFull(Queue *Q)
{
	if((Q->rear+1)%MAXSIZE==Q->front) return 1;
	else return 0;
 } 
int n,m,s,num_edge=0;
int dis[maxn],vis[maxn],head[maxm];
struct Edge
{
  int next,to,dis;
}edge[maxm];
void addedge(int from,int to,int dis) 
{ 
  edge[++num_edge].next=head[from]; 
  edge[num_edge].to=to;
  edge[num_edge].dis=dis; 
  head[from]=num_edge; 
}
void spfa()
{
  Queue Q;
  for(int i=1; i<=n; i++) 
  {
    dis[i]=inf;
    vis[i]=0;
  }
  InitQueue(&Q);
  EnQueue(&Q,s); dis[s]=0; vis[s]=1; //第一个顶点入队，进行标记
  while(!QueueEmpty(&Q))
  {
    int u;
    DeQueue(&Q,&u);
    vis[u]=0; //出队标记
    for(int i=head[u]; i; i=edge[i].next)
    {
      int v=edge[i].to; 
      if(dis[v]>dis[u]+edge[i].dis) //如果有最短路就更改
      {
        dis[v]=dis[u]+edge[i].dis;
        if(vis[v]==0) //未入队则入队
        {
          vis[v]=1; //标记入队
          EnQueue(&Q,v);
        }
      }
    }
  }
}
int main()
{
  scanf("%d%d%d",&n,&m,&s);
  for(int i=1; i<=m; i++)
  {
    int f,g,w;
    scanf("%d%d%d",&f,&g,&w);
    addedge(f,g,w); //建图，有向图连一次边就可以了
  }
  spfa(); 
  for(int i=1; i<=n; i++)
    if(s==i) printf("0 ");
      else printf("%d ",dis[i]);
  return 0;
} 
