#include <stdio.h>
#include <stdlib.h>
struct s_list{
    int data;
    struct s_list *next;
};
void create_list(struct s_list **headp,int *p);//利用二级指针修改指针的地址 
int main(void){
    struct s_list *head=NULL,*p;//head作为指针 
   int s[10],i=0;
   do
        scanf("%d",&s[i]);
    while (s[i++]);
    create_list(&head,s);//修改指针地址使得指针指向表头 
    p=head;
    while (p){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
    return 0;  
}
void create_list(struct s_list **headp,int *p)
{
 struct s_list *h=NULL,*f;
 while (*p)
    {
    f=(struct s_list *)malloc(sizeof(struct s_list));
    f->data=*p++;
    f->next=h;   //新结点的指针指向链表的第一个结点
    h=f;         //使新结点成为链表的第一个结点
        }
 *headp=h;
}

