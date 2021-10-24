#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node
   { ElemType data;
     struct node *next;
    } NODE,*LinkList;

void TriLinkList(LinkList  A,LinkList  B,LinkList  C)
{
/**********Begin**********/
LinkList p1,p2,p3;
LinkList p;
p1=A->next;
p2=B->next;
p3=C->next; 
p=A;
while(p1&&p2&&p3){
	if(p2->data<p3->data)
	p2=p2->next;
	else if(p2->data>p3->data)
	p3=p3->next;
	else
	{
		while(p1&&p1->data<p2->data)
		{
			p=p1;
			p1=p1->next;
		}
		while(p1&&p1->data==p2->data)
		{
			p->next=p1->next;
			free(p1);
			p1=p->next;
		}
		if(p1)
		{
			p2=p2->next;
			p3=p3->next;
		}
	}
}

 /**********End**********/
}
int main()
{
    LinkList L[3],p;
    ElemType x;
    int i;
    for(i=0;i<3;i++)
    {
    	L[i]=p=(NODE *)malloc(sizeof(NODE));
    	scanf("%d",&x);
    	while (x)
    	{
				p->next=(NODE *)malloc(sizeof(NODE));
				p=p->next;
				p->data=x;
				scanf("%d",&x);
    	}
      p->next=NULL;
    }
    TriLinkList(L[0],L[1],L[2]);
    for(p=L[0]->next;p;p=p->next)
        printf(" %d",p->data);
	return 0;
}

