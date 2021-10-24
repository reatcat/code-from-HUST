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
 int main()
 {
 	Stack S;
 	int a,b;
	int end; 
 	char op;//����op����ʾ�����ֵ 
 	int now=0;//������������ݣ�����һλ��ȡ��ֱ������. 
 	InitStack(&S);//�ȳ�ʼ��ջ
 	while((op=getchar())!='@'){
    if(op>='0'&&op<='9') now*=10,now+=op-'0';
    else if(op=='.'){
        Push(&S,now);
        now=0;
        }
          else if(op=='+'){//�����֡�+��ʱ����ջ�е���λȡ�� 
          	Pop(&S,&b);
          	Pop(&S,&a);
          	Push(&S,a+b);
        }
        else if(op=='-'){
            Pop(&S,&b);
          	Pop(&S,&a);
          	Push(&S,a-b);
        }
        else if(op=='*'){
            Pop(&S,&b);
          	Pop(&S,&a);
          	Push(&S,a*b);
        }
        else if(op=='/'){
            Pop(&S,&b);
          	Pop(&S,&a);
          	Push(&S,a/b);
        }
}
Pop(&S,&end);
if(StackEmpty(&S))
printf("%d",end);

 	return 0;
 }
