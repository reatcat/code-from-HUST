#include<stdio.h>
#define MAXSIZE 1000000
int n,k;
int a[MAXSIZE];
int q[MAXSIZE],front,rear,p[MAXSIZE];
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
 void funmax()
 {
 	front=1;
 	rear=0;
 	for(int i=1;i<=n;i++)
 	{
 		while(front<=rear&&q[rear]<=a[i])
 		rear--;//队列中有值且其中的队尾值比较大,此时必然不是最小的 
	q[++rear]=a[i];
	 p[rear]=i;
	 while(p[front]<=i-k)
	 front++;
	 if(i>=k)
	  printf("%d ",q[front]);
	  }
	  	printf("\n");
 }
 void funmin()
 {
 	front=1;
 	rear=0;
 	for(int i=1;i<=n;i++)
 	{
 		while(front<=rear&&q[rear]>=a[i])
 		rear--;//队列中有值且其中的队尾值比较大,此时必然不是最小的 
	q[++rear]=a[i];
	 p[rear]=i;
	 while(p[front]<=i-k)
	 front++;
	 if(i>=k)
	  printf("%d ",q[front]);
	  }
 	printf("\n");
 }
int main()
{
	
	scanf("%d %d",&n,&k); 
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
//	Queue Q,P;
//	InitQueue(&Q);
//	InitQueue(&P);
	funmin();
	funmax();
	return 0;
}
