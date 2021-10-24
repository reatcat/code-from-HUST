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
			else {//最后一个学生特殊化 
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
	struct information tell;//修改的学生信息 
			 scanf("%s",tell.num);
			 int xuan;
			 scanf("%d",&xuan);//修改的科目 
			 int gai;
			 scanf("%d",&gai);//最终分数 
			 p=head;
			 while(strcmp(p->num,tell.num)!=0)//字符串的比较 
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
				p->sum=p->yinyu+p->shuxue+p->wuli+p->cyuyan;
				p->average=p->sum*25;
				p->average+=0.5;
				p->average=(int )p->average;
				p->average/=100;
				p=p->next;
			}
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
	scanf("%d",&choice);//菜单选项 
	int n;
	struct information *head,*p; 
	head=(struct information*)malloc(sizeof(struct information));//动态存储
	head->next=NULL; 
	while(choice>0)//实现菜单选择功能 
	{   
		if(choice==1)//实现对于学生信息输入 
		{
		scanf("%d",&n);//输入学生人数 
		shuru(head,n);
		}
		else if(choice==2)//实现对于学生信息输出 
		{
		shuchu(head);
		}
		else if(choice==3)//实现成绩修改 
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
