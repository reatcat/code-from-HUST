#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct information{
	char num[15];//ѧ��ѧ�� 
	char name[10];//ѧ������ 
	int yinyu;//Ӣ��ɼ� 
	int shuxue;//��ѧ�ɼ� 
	int wuli;//����ɼ� 
	int cyuyan;//C���Գɼ� 
	float average;//ѧ��ƽ���� 
	int sum;//�ܷ� 
	struct information *next;//��̽ڵ� 
};

void paixu(struct information *head)//����ƽ�������� 
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
	printf("�����ΰ���ѧ�ţ�������Ӣ��ɼ�����ѧ�ɼ�������ɼ���C���Գɼ� ����%d��ѧ������Ϣ\n",n); 
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
//	paixu(head);
	struct information *p;
	p=head;
	printf("ѧ����Ϣ���£�\n");
	while(p->next!=NULL)
			{
				printf("ѧ��ѧ�ţ�");
				printf("%s \n",p->num);
				printf("ѧ��������");
				printf("%s \n",p->name);
				printf("ѧ���ĸ��Ƴɼ�");
				printf("%d %d %d %d\n",p->yinyu,p->shuxue,p->wuli,p->cyuyan);
				p=p->next; 
			}
}
void xiugai(struct information *head)
{
	struct information *p;
	struct information tell;//�޸ĵ�ѧ����Ϣ 
	printf("��������޸ĵ�ѧ��ѧ��"); 
			 scanf("%s",tell.num);
			 int xuan;
			 printf("��������޸ĵĿ�Ŀ�����տ�Ŀ��������Ϊ1 2 3 4��");
			 scanf("%d",&xuan);//�޸ĵĿ�Ŀ 
			 int gai;
			 printf("���������ճɼ�"); 
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
		printf("������ѧ����Ϣ���£�"); 
			while(p->next!=NULL)
			{
				p->sum=p->yinyu+p->shuxue+p->wuli+p->cyuyan;
				p->average=p->sum*25;
				p->average+=0.5;
				p->average=(int )p->average;
				p->average/=100;
				
				printf("ѧ��ѧ�ţ�"); 
				printf("%s ",p->num);
				printf("ѧ�������� ");
				printf("%s \n",p->name);
				printf("��ѧ����ƽ���֣�"); 
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
				printf("ѧ��ѧ�ţ�"); 
				printf("%s \n",p->num);
				printf("ѧ�������� ");
				printf("%s \n",p->name);
				printf("��ѧ�����ܷ���ƽ���֣�"); 
				printf("%d %.2f\n",p->sum,p->average);
				p=p->next;
			}
}

int main()
{
	int op=1;
	
	int n;
	struct information *head,*p; 
	head=(struct information*)malloc(sizeof(struct information));//��̬�洢
	head->next=NULL; 
	while(op){//����while����ѭ��ѡ���� 
	system("cls");	printf("\n\n");
	printf("                        ������ѧ����Ϣ����ϵͳ\n");
	printf("--------------------------------------------------------------------------\n");
	printf("    	  1. ����ѧ����Ϣ          6. ����ѧ����Ϣ\n");
	printf("    	  2. �������ѧ����Ϣ      7. ����ƽ�����������ѧ����Ϣ\n");
	printf("    	  3. ����ѧ���ɼ������޸�\n");
	printf("    	  4. ����ѧ����ƽ����\n");
	printf("    	  5. ����ѧ������ƽ��������\n");
	printf("    	  0. �˳�    \n");
	printf("--------------------------------------------------------------------------\n");
	if(op)
	printf("    ��ѡ����Ĳ���[0~5]:");
	scanf("%d",&op);//�˵�ѡ�� 
switch(op){
	   case 1:
	   	printf("������Ҫ��¼��ѧ������:"); 
		 scanf("%d",&n);//����ѧ������ 
		shuru(head,n);
//		paixu(head);
		printf("�ѳɹ���¼ѧ����Ϣ\n");
		printf("----���������----\n"); 
		 getchar();getchar();
		 break;
		 case 2:
		 	printf("���չ涨Ҫ�������ѧ����Ϣ���£�\n");
		  shuchu(head);
		  printf("----���������----\n"); 
		  getchar();getchar();
		 break;
		 case 3:
		 xiugai(head);
		 printf("�޸ĳɹ�\n");
		 printf("----���������----\n"); 
		 getchar();getchar();
		 break; 
		 case 4:
		 	jisuan(head);
		 	printf("----���������----\n"); 
		 	getchar();getchar();
		 break;
		 case 5:
		 	paixu(head);
		 	printf("����ɹ�"); 
		 	printf("----���������----\n"); 
		 		getchar();getchar();
		 break;
		 case 6:
		 	shuru(head,1);
		 	printf("----���������----\n"); 
		 	getchar();getchar();
		 break;
		 case 7:
		  shuchu2(head);
		  printf("----���������----\n"); 
		 	getchar();getchar();
		case 0:
         break;
	}//end of switch
  }//end of while
printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
return 0;
}//end of main()
