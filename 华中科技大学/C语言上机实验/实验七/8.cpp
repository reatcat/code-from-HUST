#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct information{
	char num[15];
	char name[10];
	int yinyu;
	int shuxue;
	int wuli;
	int cyuyan;
	float average;
	int sum;
	struct information *next;
};

void paixu(struct information **head)//���ý����ڵ�ķ�ʽ�������� 
{
	struct information *c,*b,*a,*t,*p,*q;
		p=*head;
			while(p->next!=NULL)//�������ѧ�����ܳɼ���ƽ���ɼ� 
			{
				p->sum=p->yinyu+p->shuxue+p->wuli+p->cyuyan;
				p->average=p->sum*25;
				p->average+=0.5;
				p->average=(int )p->average;
				p->average/=100;
				p=p->next;
			}
	int i=0;
	p=*head;
    while(p->next!=NULL)
    {
        p=p->next;i++;
    }
    struct information *d;
    d=(struct information*)malloc(sizeof(struct information));
    d->next=*head;//����һ��ͷ�ڵ� 
    
    for(int i1=0;i1<i-1;i1++)
    {
    	a=d;
    	p=d->next;
        for(int i2=0;i2<i-i1-1;i2++)
        {
        	q=p->next;
        	b=q->next;
            if(p->sum>q->sum)
            {
				q->next=p;
				p->next=b;
				c=p;
				p=q;
				q=c;
				a->next=p;
            }
            if(q->next==NULL)
            break;
            else
            {
            	a=a->next;
            	p=a->next;
			}
        }
    }
	*head=d->next;
}
void shuru(struct information *head,int n)
{
	int i;
	struct information *p;
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	for(i=0;i<n;i++)
		{
			if(i<n-1)
			{
			scanf("%s",(*p).num);
			scanf("%s",(*p).name);
			scanf("%d %d %d %d",&(*p).yinyu,&(*p).shuxue,&(*p).wuli,&(*p).cyuyan);
			p->next=(struct information*)malloc(sizeof(struct information));
			p=p->next;
			}
			else {//���һ��ѧ�����⻯ 
			scanf("%s",(*p).num);
			scanf("%s",(*p).name);
			scanf("%d %d %d %d",&(*p).yinyu,&(*p).shuxue,&(*p).wuli,&(*p).cyuyan);
			p->next=(struct information*)malloc(sizeof(struct information));
			p=p->next;
			p->next=NULL;
			}
				
		}
}
void shuchu(struct information *head)
{
	struct information *p;
	p=head;
	while(p->next!=NULL)
			{
				printf("%s ",p->num);
				printf("%s ",p->name);
				printf("%d %d %d %d\n",p->yinyu,p->shuxue,p->wuli,p->cyuyan);
				p=p->next; 
			}
}
void xiugai(struct information *head)
{
	struct information *p;
	struct information tell;//�޸ĵ�ѧ����Ϣ 
			 scanf("%s",tell.num);
			 int xuan;
			 scanf("%d",&xuan);//�޸ĵĿ�Ŀ 
			 int gai;
			 scanf("%d",&gai);//���շ��� 
			 p=head;
			 while(strcmp(p->num,tell.num)!=0)//�ַ����ıȽ� 
			 {
			 	p=p->next;
			 }
			 switch(xuan)
			 {
			 	case 1:p->yinyu=gai;break; 
			 	case 2:p->shuxue=gai;break;
			 	case 3:p->wuli=gai;break;
			 	case 4:p->cyuyan=gai;break;
			 }
}
void jisuan(struct information *head)
{
	struct information *p;
		p=head;
			while(p->next!=NULL)
			{
				p->sum=p->yinyu+p->shuxue+p->wuli+p->cyuyan;
				p->average=p->sum*25;
				p->average+=0.5;
				p->average=(int )p->average;
				p->average/=100;
				printf("%s ",p->num);
				printf("%s ",p->name);
				printf("%.2f\n",p->average);
				p=p->next;
			}
}
void shuchu2(struct information *head)
{
	struct information *p;
			p=head;
			while(p->next!=NULL)
			{
				printf("%s ",p->num);
				printf("%s ",p->name);
				printf("%d %.2f\n",p->sum,p->average);
				p=p->next;
			}
}

int main()
{
	int choice;
	scanf("%d",&choice);//�˵�ѡ�� 
	int n;
	struct information *head,*p; 
	head=(struct information*)malloc(sizeof(struct information));//��̬�洢
	head->next=NULL; 
	while(choice>0)//ʵ�ֲ˵�ѡ���� 
	{   
		if(choice==1)//ʵ�ֶ���ѧ����Ϣ���� 
		{
		scanf("%d",&n);//����ѧ������ 
		shuru(head,n);
		paixu(&head);
		}
		else if(choice==2)//ʵ�ֶ���ѧ����Ϣ��� 
	{
		shuchu(head);
		}
		else if(choice==3)//ʵ�ֳɼ��޸� 
		{
			xiugai(head);
		} 
		else if(choice==4)
		{
		    jisuan(head);
		}
		else if(choice==5)
		{
		shuchu2(head);
			break;
		}
		scanf("%d",&choice);
	}
	return 0;
}
