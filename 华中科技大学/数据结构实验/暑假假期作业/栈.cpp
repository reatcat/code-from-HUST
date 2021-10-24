#include <stdio.h>
#define MAXSIZE 100
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
 int searchtop(Stack *S)//查询栈顶的元素 
 {
 	return S->data[S->top];
  } 
 int main()
 {
 	Stack S;
 	int e;
 	InitStack(&S);//先初始化栈
	printf("请输入要入栈的值："); 
 	scanf("%d",&e);
 	Push(&S,e);
 	int temp;
 	Pop(&S,&temp);
 	printf("测试成功，栈顶的值为%d",temp);
 	return 0;
 }
