#include <stdio.h>
#define MAXSIZE 10000
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
 	Stack P;//用另一个栈来保存小数等情况 
 	int e;
 	int num;
 	InitStack(&S);//先初始化栈
 	InitStack(&P); 
 	char c;
 	int flag=0;
	while((c=getchar())!=EOF)
	{
		if(c=='.')
		{
			flag=1;
			while((c=getchar())!=EOF){
			num=c-'0';
			Push(&P,num);	
			}
			break;
		}
		else if(c=='/')
		{
			flag=2;
			while((c=getchar())!=EOF){
			num=c-'0';
			Push(&P,num);	
			}
			break;
		}
		else if(c=='%')
		{
			flag=3;
		}
		else {
			num=c-'0';
			Push(&S,num);
		}
	 }
	 if(flag==0){
	 	while(searchtop(&S)==0)//首元素为0 
	 	Pop(&S,&e);
	 	while(!StackEmpty(&S))
	 	{
	 		Pop(&S,&e);
	 		printf("%d",e);
		 }	 
	 } 
	 else if(flag==1)//出现小数点 
	 {
	 	while(searchtop(&S)==0)//首元素为0 
	 	Pop(&S,&e);
	 	while(!StackEmpty(&S))
	 	{
	 		Pop(&S,&e);
	 		printf("%d",e);
		 }
		 printf(".");
		 while(searchtop(&P)==0)//首元素为0 
	 	Pop(&P,&e);
	 	while(!StackEmpty(&P))
	 	{
	 		Pop(&P,&e);
	 		if(StackEmpty(&P)&&e==0)
	 		break;
	 		printf("%d",e);
		 } 
	 }
	 else if(flag==2)
	 {
	 	while(searchtop(&S)==0)//首元素为0 
	 	Pop(&S,&e);
	 	while(!StackEmpty(&S))
	 	{
	 		Pop(&S,&e);
	 		printf("%d",e);
		 }
		 printf("\\");
		 while(searchtop(&P)==0)//首元素为0 
	 	Pop(&P,&e);
	 	while(!StackEmpty(&P))
	 	{
	 		Pop(&P,&e);
	 		if(StackEmpty(&P)&&e==0)
	 		break;
	 		printf("%d",e);
		 } 
	 }
	 else if(flag==3)
	 {
	 	while(searchtop(&S)==0)//首元素为0 
	 	Pop(&S,&e);
	 	while(!StackEmpty(&S))
	 	{
	 		Pop(&S,&e);
	 		printf("%d",e);
		 }
		 printf("%%");
	 }
 	return 0;
 }
