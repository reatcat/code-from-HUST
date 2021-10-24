#include<stdio.h>
#define MAXSIZE 100
typedef struct {
	int front;//其中front为队列中的首元素 
	int rear;//rear为队列中最后一位元素的后一个空位 
	int data[MAXSIZE];
}Queue;
//以下为对于队列的初始操作
void InitQueue(Queue* Q)//初始化队列，此处将队列的头尾置为0 
{
	Q->front = Q->rear = 0;

}
void EnQueue(Queue* Q, int e)//元素入队列 
{
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
}
void DeQueue(Queue* Q, int& e)//元素出列 
{
	e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
}
//以下是附加的部分函数：
int QueueEmpty(Queue* Q)
{
	if (Q->front == Q->rear) return 1;
	else return 0;
}
int QueueFull(Queue* Q)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) return 1;
	else return 0;
}
int main()
{
	Queue Q;
	int e;
	char c;
	InitQueue(&Q);
	printf("请输入要入队的值：");
	while ((c = getchar()) != '\n') {
		scanf("%d", &e);
		EnQueue(&Q, e);
	}
	DeQueue(&Q, e);
	printf("现在的队首的值为：%d", e);
	return 0;
}