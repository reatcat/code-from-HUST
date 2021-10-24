#include <stdio.h>
#define MAXSIZE 100
typedef struct{
	int data[MAXSIZE];
	int top; 
}Stack;
 
void InitStack(Stack *S)//��ʼ��ջ 
{
	S->top=-1;//�˴���ջ����Ϊ-1��top��ָ��ļ�Ϊջ����Ԫ�� 
}
void Push(Stack *S,int a)//��Ԫ����ջ
{
	
	S->top++;
	S->data[S->top]=a;
}
void Pop(Stack *S,int *e)//��Ԫ�س�ջ������ֵ��e 
{
	*e=S->data[S->top];
	S->top--;
}
//����Ϊ����ĺ���������ûʲô�ã� 
int StackEmpty(Stack *S)//�ж�ջ����ջ�� 
{
	if(S->top==-1) return 1;
	else return 0;
 } 
 int StackFull(Stack *S)
 {
 	if (S->top ==MAXSIZE-1) return 1;
 	else return 0;
 }
 int searchtop(Stack *S)//��ѯջ����Ԫ�� 
 {
 	return S->data[S->top];
  } 
 int main()
 {
 	Stack S;
 	int e;
 	InitStack(&S);//�ȳ�ʼ��ջ
	printf("������Ҫ��ջ��ֵ��"); 
 	scanf("%d",&e);
 	Push(&S,e);
 	int temp;
 	Pop(&S,&temp);
 	printf("���Գɹ���ջ����ֵΪ%d",temp);
 	return 0;
 }
