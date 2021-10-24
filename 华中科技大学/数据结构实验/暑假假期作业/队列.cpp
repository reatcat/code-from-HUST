#include<stdio.h>
#define MAXSIZE 100
typedef struct{
	int data[MAXSIZE];
	int front;
	int rear; 
}Queue; //���еĶ��� 

void InitQueue(Queue *Q)
{
	Q->front=Q->rear=0;
}
void EnQueue(Queue *Q,int e)
{
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXSIZE;//�˴���ѭ�����н�rearָ���һ���յ�λ�� 
 }
void DeQueue(Queue *Q,int * e)
{
	*e = Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
 }
 //����Ϊ����ĺ���
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
	printf("������Ҫ��ӵ�ֵ��\n");
	scanf("%d",&e);	
	EnQueue(&Q,e);
	printf("��ӳɹ�\n");
	
	DeQueue(&Q,&e);
	 printf("Ŀǰ�����еĶ���Ԫ��Ϊ:%d",e);

	 
 }
