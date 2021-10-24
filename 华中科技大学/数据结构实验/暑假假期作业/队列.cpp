#include<stdio.h>
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
 int main()
 {
	Queue Q;
	int e;
	InitQueue(&Q);
	printf("请输入要入队的值：\n");
	scanf("%d",&e);	
	EnQueue(&Q,e);
	printf("入队成功\n");
	
	DeQueue(&Q,&e);
	 printf("目前队列中的队首元素为:%d",e);

	 
 }
