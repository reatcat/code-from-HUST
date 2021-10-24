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
 int main()//该题和栈的操作没有太大关系 
 {//有一种叫卡特兰数 
 int n; 
 int f[10000];
 	scanf("%d", &n);
 	//可以认为x为最后一个，利用i来表示共有多少个数，利用i，j来共同控制 
    f[0] = 1, f[1] = 1;//认为最后一个数为1的时候有1种 
    for(int i=2; i<=n; i++)              
        for(int j=0; j<i; j++) 
            f[i] += f[j] * f[i-j-1];     //递推公式 
    printf("%d", f[n]);
    return 0;
  } 
