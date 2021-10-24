#include <stdio.h>
#define MAXSIZE 100
#define MAX 10000 
typedef struct{
	int data[MAXSIZE];
	int top; 
}Stack;
 
void InitStack(Stack *S)//初始化栈 
{
	S->top=-1;//此处将栈的置为-1，top所指向的即为栈顶的元素 
}
void Push(Stack *S,int a)//将元素入栈
{
	
	S->top++;
	S->data[S->top]=a;
}
void Pop(Stack *S,int *e)//将元素出栈，并赋值给e 
{
	*e=S->data[S->top];
	S->top--;
}
//以下为补充的函数（可能没什么用） 
int StackEmpty(Stack *S)//判断栈空与栈满 
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
	scanf("%d",&a);//所输入的第一个数肯定是数字 
	a=a%MAX;
	Push(&S,a); 
	while(scanf("%c",&c))//直接读取变成了符号加数字的形式 
	{
		if(c=='\n') break;
		else scanf("%d",&b); 
		if(c=='*')//判断优先级，可以先进行*的操作，+的操作后续统一进行 
		{
			Pop(&S,&a);
			a=a*b;
			a=a%MAX;
			Push(&S,a); 
		}
		else//将b存入
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
