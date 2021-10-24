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
 int main()//�����ջ�Ĳ���û��̫���ϵ 
 {//��һ�ֽп������� 
 int n; 
 int f[10000];
 	scanf("%d", &n);
 	//������ΪxΪ���һ��������i����ʾ���ж��ٸ���������i��j����ͬ���� 
    f[0] = 1, f[1] = 1;//��Ϊ���һ����Ϊ1��ʱ����1�� 
    for(int i=2; i<=n; i++)              
        for(int j=0; j<i; j++) 
            f[i] += f[j] * f[i-j-1];     //���ƹ�ʽ 
    printf("%d", f[n]);
    return 0;
  } 
