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
};//����ṹ��
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
    int num;scanf("%d",&num);//����Ҫ������Ϣ�ĸ���
    struct st *head,*tail;//ȷ���½���ͷβ����ָ��
    head=tail=(struct st*)malloc(sizeof(struct st));//Ϊ����ͷָ����䶯̬�ռ�
    scanf("%s %s %d %d %d %d",tail->n,tail->name,&tail->e,&tail->m,&tail->p,&tail->c);//����ÿ��ѧ����ѧ�š�������Ӣ��ߵ���ѧ����ͨ����C���Գ������4�ſγ̵ĳɼ�
    head->sum=tail->e+tail->m+tail->p+tail->c;
    for(int i=2;i<=num;i++)
    {
        tail->next=(struct st*)malloc(sizeof(struct st));
        tail=tail->next;//ָ��ָ���½�����
        scanf("%s %s %d %d %d %d",tail->n,tail->name,&tail->e,&tail->m,&tail->p,&tail->c); //����ÿ��ѧ����ѧ�š�������Ӣ��ߵ���ѧ����ͨ����C���Գ������4�ſγ̵ĳɼ�
        tail->sum=tail->e+tail->m+tail->p+tail->c;
    }
    tail->next=NULL;
    if(*headp==NULL)*headp=head;//��������Ϊ��
    else
    {
        tail=*headp;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
       tail->next=head;
    }//����Ϊ�գ�����½�ͷָ���ֵ������ǰ���һ���ṹ��next
}
void out(struct st *head)
{
    struct st *tail=head;
    
    while(tail)
    {
        printf("%s %s %d %d %d %d\n",tail->n,tail->name,tail->e,tail->m,tail->p,tail->c); 
        //���ÿ��ѧ����ѧ�š�������Ӣ��ߵ���ѧ����ͨ����C���Գ������4�ſγ̵ĳɼ�
        tail=tail->next;
    }
}
void change(struct st *head)
{
    struct st *tail=head;
    char s[12];scanf("%s",s);//Ѱ��Ҫ���ĵĶ���
    while(tail&&strcmp(tail->n,s)) //Ѱ��Ҫ���ĵĶ���
    {
        tail=tail->next;//��һ���ṹ
    }
    int m;scanf("%d",&m);
    if(m==1)scanf("%d",&tail->e);
    else if(m==2)scanf("%d",&tail->m);
    else if(m==3)scanf("%d",&tail->p);
    else if(m==4)scanf("%d",&tail->c);//����Ӧ�ĸ���
    tail->sum=tail->e+tail->m+tail->p+tail->c;
}
void aver(struct st *head)
{
    struct st *tail=head;
    while(tail)
    {
        printf("%s %s %.2f\n",tail->n,tail->name,(double)tail->sum/4);//���ÿһ�����
        tail=tail->next; //Ѱ��ֱ�����һ���ṹ
    }
} 
void outm(struct st *head)
{
    struct st *tail=head;
    while(tail)
    {
        printf("%s %s %d %.2f\n",tail->n,tail->name,tail->e+tail->m+tail->p+tail->c,(double)tail->sum/4);//���
        tail=tail->next;
    }
}
int main()
{
    int x;
    struct st *head=NULL;
    scanf("%d",&x);//����ѡ��
    while(x>=1&&x<=4)
    {
        switch(x)//���ݲ�ͬѡ������ѡ��
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
