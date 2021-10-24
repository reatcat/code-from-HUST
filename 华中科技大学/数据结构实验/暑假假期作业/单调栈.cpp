#include <stdio.h>
#define MAXSIZE 100
#define MAX 10000000
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
 	int n;
	scanf("%d",&n);
	int a[n+1];
	 int i;
	 int f[n];//�洢�� 
	 int temp;
	 for(i=1;i<=n;i++)
	 {
	 	scanf("%d",&a[i]);
	  }
	  //����Ͱ����ķ���ֻ��Ҫ����һ��������ֵ 
	  //����ջ�У�ֻ�ñ������е��±� ��ÿһ�α�����Ǳȸ�ֵ����������±� 
	  for(i=n;i>=1;i--)
	  {
	  	while(!(StackEmpty(&S))&&a[searchtop(&S)]<=a[i])// ��ջ�ǿ��� 
		  Pop(&S,&temp);
	  	f[i]=StackEmpty(&S)?0:searchtop(&S);
//	  	Push(&S,a[i]);
	  	Push(&S,i);
	  }
	  for(int i=1;i<=n;i++) printf("%d ",f[i]);

 	return 0;
 }
