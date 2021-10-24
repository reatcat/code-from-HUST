#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct st{
    char n[12];
    char name[10];
    int e;
    int m;
    int p;
    int c;
    int sum;
    struct st *next;
};//定义结构型
void sort(struct st *head)
{
    struct st *p=head,*q=head;int i=0;
    while(p)
    {
        p=p->next;i++;
    }
    p=head->next;
    for(int i1=0;i1<i-1;i1++)
    {
        int change=1;
        for(int i2=0;i2<i-i1-1;i2++)
        {
            if(q->sum>p->sum)
            {
                char s[20];strcpy(s,q->n);strcpy(q->n,p->n);strcpy(p->n,s);
                strcpy(s,q->name);strcpy(q->name,p->name);strcpy(p->name,s);
                int m=p->e;p->e=q->e;q->e=m;
                m=p->m;p->m=q->m;q->m=m;
                m=p->p;p->p=q->p;q->p=m;
                m=p->c;p->c=q->c;q->c=m;
                m=p->sum;p->sum=q->sum;q->sum=m;
                change=0;
            }
            q=p;p=p->next;
        }
        if(change==1)break;
        p=head->next;q=head;
    }
}
void in1(struct st**headp)
{
    int num;scanf("%d",&num);//输入要输入信息的个数
    struct st *head,*tail;//确定新建的头尾链表指针
    head=tail=(struct st*)malloc(sizeof(struct st));//为链表头指针分配动态空间
    scanf("%s %s %d %d %d %d",tail->n,tail->name,&tail->e,&tail->m,&tail->p,&tail->c);//输入每个学生的学号、姓名、英语、高等数学、普通物理、C语言程序设计4门课程的成绩
    head->sum=tail->e+tail->m+tail->p+tail->c;
    for(int i=2;i<=num;i++)
    {
        tail->next=(struct st*)malloc(sizeof(struct st));
        tail=tail->next;//指针指向新建链表
        scanf("%s %s %d %d %d %d",tail->n,tail->name,&tail->e,&tail->m,&tail->p,&tail->c); //输入每个学生的学号、姓名、英语、高等数学、普通物理、C语言程序设计4门课程的成绩
        tail->sum=tail->e+tail->m+tail->p+tail->c;
    }
    tail->next=NULL;
    if(*headp==NULL)*headp=head;//若此链表为空
    else
    {
        tail=*headp;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
       tail->next=head;
    }//若不为空，则把新建头指针的值赋给先前最后一个结构的next
}
void out(struct st *head)
{
    struct st *tail=head;
    
    while(tail)
    {
        printf("%s %s %d %d %d %d\n",tail->n,tail->name,tail->e,tail->m,tail->p,tail->c); 
        //输出每个学生的学号、姓名、英语、高等数学、普通物理、C语言程序设计4门课程的成绩
        tail=tail->next;
    }
}
void change(struct st *head)
{
    struct st *tail=head;
    char s[12];scanf("%s",s);//寻找要更改的对象
    while(tail&&strcmp(tail->n,s)) //寻找要更改的对象
    {
        tail=tail->next;//下一个结构
    }
    int m;scanf("%d",&m);
    if(m==1)scanf("%d",&tail->e);
    else if(m==2)scanf("%d",&tail->m);
    else if(m==3)scanf("%d",&tail->p);
    else if(m==4)scanf("%d",&tail->c);//做相应的更改
    tail->sum=tail->e+tail->m+tail->p+tail->c;
}
void aver(struct st *head)
{
    struct st *tail=head;
    while(tail)
    {
        printf("%s %s %.2f\n",tail->n,tail->name,(double)tail->sum/4);//输出每一个结果
        tail=tail->next; //寻找直到最后一个结构
    }
} 
void outm(struct st *head)
{
    struct st *tail=head;
    while(tail)
    {
        printf("%s %s %d %.2f\n",tail->n,tail->name,tail->e+tail->m+tail->p+tail->c,(double)tail->sum/4);//输出
        tail=tail->next;
    }
}
int main()
{
    int x;
    struct st *head=NULL;
    scanf("%d",&x);//输入选项
    while(x>=1&&x<=4)
    {
        switch(x)//根据不同选项做出选择
        {
            case 1:in1(&head);sort(head);break;
            case 2:out(head);break;
            case 3:change(head);sort(head);break;
            case 4:aver(head);break;
        }
        scanf("%d",&x);
    }
    if(x==5)outm(head);
}
