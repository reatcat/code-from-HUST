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
 int main()
 {
 	Stack S;
 	int a,b;
	int end; 
 	char op;//利用op来表示输入的值 
 	int now=0;//对于输入的数据，进行一位读取，直到遇到. 
 	InitStack(&S);//先初始化栈
 	while((op=getchar())!='@'){
    if(op>='0'&&op<='9') now*=10,now+=op-'0';
    else if(op=='.'){
        Push(&S,now);
        now=0;
        }
          else if(op=='+'){//当出现‘+’时，将栈中的两位取出 
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
