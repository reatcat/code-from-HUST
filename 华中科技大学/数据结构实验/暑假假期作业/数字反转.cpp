#include <stdio.h>
#define MAXSIZE 10000
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
 	Stack P;//����һ��ջ������С������� 
 	int e;
 	int num;
 	InitStack(&S);//�ȳ�ʼ��ջ
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
	 	while(searchtop(&S)==0)//��Ԫ��Ϊ0 
	 	Pop(&S,&e);
	 	while(!StackEmpty(&S))
	 	{
	 		Pop(&S,&e);
	 		printf("%d",e);
		 }	 
	 } 
	 else if(flag==1)//����С���� 
	 {
	 	while(searchtop(&S)==0)//��Ԫ��Ϊ0 
	 	Pop(&S,&e);
	 	while(!StackEmpty(&S))
	 	{
	 		Pop(&S,&e);
	 		printf("%d",e);
		 }
		 printf(".");
		 while(searchtop(&P)==0)//��Ԫ��Ϊ0 
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
	 	while(searchtop(&S)==0)//��Ԫ��Ϊ0 
	 	Pop(&S,&e);
	 	while(!StackEmpty(&S))
	 	{
	 		Pop(&S,&e);
	 		printf("%d",e);
		 }
		 printf("\\");
		 while(searchtop(&P)==0)//��Ԫ��Ϊ0 
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
	 	while(searchtop(&S)==0)//��Ԫ��Ϊ0 
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
