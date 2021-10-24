#include <stdio.h>
#define MAXSIZE 100
#define MAX 10000 
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
 int main()
 {
 	Stack S;
 	int a,b;
	char c;
	InitStack(&S);
	scanf("%d",&a);//������ĵ�һ�����϶������� 
	a=a%MAX;
	Push(&S,a); 
	while(scanf("%c",&c))//ֱ�Ӷ�ȡ����˷��ż����ֵ���ʽ 
	{
		if(c=='\n') break;
		else scanf("%d",&b); 
		if(c=='*')//�ж����ȼ��������Ƚ���*�Ĳ�����+�Ĳ�������ͳһ���� 
		{
			Pop(&S,&a);
			a=a*b;
			a=a%MAX;
			Push(&S,a); 
		}
		else//��b����
			Push(&S,b);
	}
	int sum=0;
	while(StackEmpty(&S)!=1)
	{
		Pop(&S,&a);
		sum+=a;
		sum%=MAX;
	}
	printf("%d",sum);
 	return 0;
  } 
