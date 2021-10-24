#include<stdio.h>
#define MAXSIZE 100
typedef struct {
	int front;//����frontΪ�����е���Ԫ�� 
	int rear;//rearΪ���������һλԪ�صĺ�һ����λ 
	int data[MAXSIZE];
}Queue;
//����Ϊ���ڶ��еĳ�ʼ����
void InitQueue(Queue* Q)//��ʼ�����У��˴������е�ͷβ��Ϊ0 
{
	Q->front = Q->rear = 0;

}
void EnQueue(Queue* Q, int e)//Ԫ������� 
{
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
}
void DeQueue(Queue* Q, int& e)//Ԫ�س��� 
{
	e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
}
//�����Ǹ��ӵĲ��ֺ�����
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
	printf("������Ҫ��ӵ�ֵ��");
	while ((c = getchar()) != '\n') {
		scanf("%d", &e);
		EnQueue(&Q, e);
	}
	DeQueue(&Q, e);
	printf("���ڵĶ��׵�ֵΪ��%d", e);
	return 0;
}