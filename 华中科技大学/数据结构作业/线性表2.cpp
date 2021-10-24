#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef  struct  Dnode
    {
        ElemType     data;
        struct  Dnode *prior,*next;
    } *DuLinkList;

void  adjust(DuLinkList  L)
{
/**********Begin**********/
DuLinkList p,q,s,r;
 int i = 0;
   q = L;
   p = L;
   p = p -> next;
   r = p;
   while(p->next!=L){        
        s=p->next;
        i++;    
        if(i%2==0){  
            q->prior=p;
            p->next=q; 
            q=q->prior;
            p=s;           
            r->next=s;   
            s->prior=r;
            r=r->next;
        }
        else 
            p=p->next;
   }
   p->next=q;
   q->prior=p;

}

int main()
{
    DuLinkList L,p,tail;
    int n,i;
    L=tail=(DuLinkList)malloc(sizeof(struct Dnode));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        p=(DuLinkList)malloc(sizeof(struct Dnode));
        scanf("%d",&p->data);
        tail->next=p;
        p->prior=tail;
        tail=p;
    }
    L->prior=tail;
    tail->next=L;
    adjust(L);
    p=L->next;
    while(p!=L)
    {
        printf(" %d",p->data);
        p=p->next;
    }
}

