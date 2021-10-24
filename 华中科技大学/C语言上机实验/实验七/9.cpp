#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct number{
	int x;
	struct number *next;
};
void push(struct number **head,int n)//创建链表作为栈,将数字压入栈中
{
	struct number *h,*tail;
	h=tail=(struct number *)malloc(sizeof(struct number));
	if(*head==NULL)
	{
		h=NULL;
		tail->x=n;
		tail->next=h;
		h=tail;
		*head=h;
	}
	else
	{
		h=*head;
		tail->x=n;
		tail->next=h;
		h=tail;
		*head=h;
	}
}
int pop(struct number **head,char c)
{
	int m,n,t;
	struct number *p=*head,*q;
	m=p->x,n=p->next->x;
	if(c=='+') t=n+m;
	else if(c=='-') t=n-m;
	else if(c=='*') t=n*m;
	else if(c=='/') t=n/m;
	q=p->next;
	*head=q->next;
	free(p),free(q);
	return t;
}
void display(struct number *head)
{
	struct number *p;
	p=head; 
	printf("%d",p->x);
}
int main()
{
	struct number *head=NULL;
	char c,c1;
	int n,t;
	while((c=getchar())!='\n'&&c!=EOF)
	{
		if(c==' ')continue;
		if(isdigit(c)||c=='-')
		{
			if(c=='-')
			{
			c1=getchar();
			ungetc(c1,stdin);
			if(!isdigit(c1))
			{
				t=pop(&head,c);
				push(&head,t);
				break;
			}
			}
			ungetc(c,stdin);
			scanf("%d",&n);
			push(&head,n);
			continue;
		}
		else if(c=='+'||c=='-'||c=='*'||c=='/')
		{
			t=pop(&head,c);
			push(&head,t);
		}
	}
	display(head);
	return 0;
}
