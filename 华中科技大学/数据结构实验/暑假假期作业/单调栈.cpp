#include <stdio.h>
#define MAXSIZE 100
#define MAX 10000000
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
 	int n;
	scanf("%d",&n);
	int a[n+1];
	 int i;
	 int f[n];//存储答案 
	 int temp;
	 for(i=1;i<=n;i++)
	 {
	 	scanf("%d",&a[i]);
	  }
	  //利用桶排序的方法只需要看第一个比其大的值 
	  //对于栈中，只用保存数列的下标 ，每一次保存的是比该值更大的数的下标 
	  for(i=n;i>=1;i--)
	  {
	  	while(!(StackEmpty(&S))&&a[searchtop(&S)]<=a[i])// 当栈非空且 
		  Pop(&S,&temp);
	  	f[i]=StackEmpty(&S)?0:searchtop(&S);
//	  	Push(&S,a[i]);
	  	Push(&S,i);
	  }
	  for(int i=1;i<=n;i++) printf("%d ",f[i]);

 	return 0;
 }
