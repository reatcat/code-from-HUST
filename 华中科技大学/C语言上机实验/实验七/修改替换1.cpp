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
void create_list(struct s_list **headp,int *p){
    struct s_list *loc_head=NULL,*tail;
    if(p[0]==0)
	*headp=NULL;//直接将指针指向空 
    else {
        loc_head=(struct s_list *)malloc(sizeof(struct s_list));
        loc_head->data=*p++;
        tail=loc_head;
        while (*p)
        {
            tail->next=(struct s_list *)malloc(sizeof(struct s_list));
            tail=tail->next;
            tail->data=*p++;
        }
        tail->next=NULL;
        
    }
    *headp=loc_head;//修改指针的地址， 
}

