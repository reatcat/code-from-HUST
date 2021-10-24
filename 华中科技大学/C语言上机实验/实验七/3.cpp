#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct information{
	char num[15];//学生学号 
	char name[10];//学生姓名 
	int yinyu;//英语成绩 
	int shuxue;//数学成绩 
	int wuli;//物理成绩 
	int cyuyan;//C语言成绩 
	float average;//学生平均分 
	int sum;//总分 
	struct information *next;//后继节点 
};

void paixu(struct information *head)//利用平均分排序 
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
	struct information *q=head;
	int i=0;
	p=head;
    while(p->next!=NULL)
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
                char s[20];strcpy(s,q->num);strcpy(q->num,p->num);strcpy(p->num,s);
                strcpy(s,q->name);strcpy(q->name,p->name);strcpy(p->name,s);
                int m=p->yinyu;p->yinyu=q->yinyu;q->yinyu=m;
                m=p->shuxue;p->shuxue=q->shuxue;q->shuxue=m;
                m=p->wuli;p->wuli=q->wuli;q->wuli=m;
                m=p->cyuyan;p->cyuyan=q->cyuyan;q->cyuyan=m;
                m=p->sum;p->sum=q->sum;q->sum=m;
                change=0;
            }
            q=p;p=p->next;
        }
        if(change==1)break;
        p=head->next;q=head;
    }
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
	printf("请依次按照学号，姓名，英语成绩，数学成绩，物理成绩，C语言成绩 输入%d个学生的信息\n",n); 
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
//	paixu(head);
	struct information *p;
	p=head;
	printf("学生信息如下：\n");
	while(p->next!=NULL)
			{
				printf("学生学号：");
				printf("%s \n",p->num);
				printf("学生姓名：");
				printf("%s \n",p->name);
				printf("学生的各科成绩");
				printf("%d %d %d %d\n",p->yinyu,p->shuxue,p->wuli,p->cyuyan);
				p=p->next; 
			}
}
void xiugai(struct information *head)
{
	struct information *p;
	struct information tell;//修改的学生信息 
	printf("请输入待修改的学生学号"); 
			 scanf("%s",tell.num);
			 int xuan;
			 printf("请输入待修改的科目（按照科目排序依次为1 2 3 4）");
			 scanf("%d",&xuan);//修改的科目 
			 int gai;
			 printf("请输入最终成绩"); 
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
		printf("计算后的学生信息如下："); 
			while(p->next!=NULL)
			{
				p->sum=p->yinyu+p->shuxue+p->wuli+p->cyuyan;
				p->average=p->sum*25;
				p->average+=0.5;
				p->average=(int )p->average;
				p->average/=100;
				
				printf("学生学号："); 
				printf("%s ",p->num);
				printf("学生姓名： ");
				printf("%s \n",p->name);
				printf("该学生的平均分："); 
				printf("%.2f\n",p->average);
				p=p->next;
			}
}
void shuchu2(struct information *head)
{
	struct information *p;
//	paixu(head);
			p=head;
			while(p->next!=NULL)
			{
				printf("学生学号："); 
				printf("%s \n",p->num);
				printf("学生姓名： ");
				printf("%s \n",p->name);
				printf("该学生的总分与平均分："); 
				printf("%d %.2f\n",p->sum,p->average);
				p=p->next;
			}
}

int main()
{
	int op=1;
	
	int n;
	struct information *head,*p; 
	head=(struct information*)malloc(sizeof(struct information));//动态存储
	head->next=NULL; 
	while(op){//利用while进行循环选择功能 
	system("cls");	printf("\n\n");
	printf("                        基础的学生信息管理系统\n");
	printf("--------------------------------------------------------------------------\n");
	printf("    	  1. 输入学生信息          6. 新增学生信息\n");
	printf("    	  2. 依次输出学生信息      7. 按照平均分依次输出学生信息\n");
	printf("    	  3. 对于学生成绩进行修改\n");
	printf("    	  4. 计算学生的平均分\n");
	printf("    	  5. 对于学生按照平均分排序\n");
	printf("    	  0. 退出    \n");
	printf("--------------------------------------------------------------------------\n");
	if(op)
	printf("    请选择你的操作[0~5]:");
	scanf("%d",&op);//菜单选项 
switch(op){
	   case 1:
	   	printf("请输入要记录的学生人数:"); 
		 scanf("%d",&n);//输入学生人数 
		shuru(head,n);
//		paixu(head);
		printf("已成功记录学生信息\n");
		printf("----任意键继续----\n"); 
		 getchar();getchar();
		 break;
		 case 2:
		 	printf("按照规定要求输出的学生信息如下：\n");
		  shuchu(head);
		  printf("----任意键继续----\n"); 
		  getchar();getchar();
		 break;
		 case 3:
		 xiugai(head);
		 printf("修改成功\n");
		 printf("----任意键继续----\n"); 
		 getchar();getchar();
		 break; 
		 case 4:
		 	jisuan(head);
		 	printf("----任意键继续----\n"); 
		 	getchar();getchar();
		 break;
		 case 5:
		 	paixu(head);
		 	printf("排序成功"); 
		 	printf("----任意键继续----\n"); 
		 		getchar();getchar();
		 break;
		 case 6:
		 	shuru(head,1);
		 	printf("----任意键继续----\n"); 
		 	getchar();getchar();
		 break;
		 case 7:
		  shuchu2(head);
		  printf("----任意键继续----\n"); 
		 	getchar();getchar();
		case 0:
         break;
	}//end of switch
  }//end of while
printf("欢迎下次再使用本系统！\n");
return 0;
}//end of main()
