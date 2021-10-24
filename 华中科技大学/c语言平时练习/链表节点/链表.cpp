#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct information {
	char num[15];
	char name[10];
	int yinyu;
	int shuxue;
	int wuli;
	int cyuyan;
	float average;
	int sum;
	struct information* next;
};

void paixu(struct information** head)//���ý����ڵ�ķ�ʽ�������� 
{
	struct information* p1, * p2, * prior1, * prior2, * t, * p;
	p = *head;
	while (p->next != NULL)//�������ѧ�����ܳɼ���ƽ���ɼ� 
	{
		p->sum = p->yinyu + p->shuxue + p->wuli + p->cyuyan;
		p->average = p->sum * 25;
		p->average += 0.5;
		p->average = (int)p->average;
		p->average /= 100;
		p = p->next;
	}
	p1 = *head;
	for (p2 = p1->next, prior2 = p1;p2 != NULL;prior2 = p2, p2 = p2->next)
	{
		if (p1->sum > p2->sum)
		{
			prior2->next = p1;t = p1->next;
			p1->next = p2->next;(*head) = p2;
			p2->next = t;p1 = p2;
		}
	}

	//			for(prior1=*head,p1=prior1->next;p1->next!=NULL;prior1=p1,p1=p1->next)
	//			{for(p2=p1->next,prior2=p1;p2!=NULL;prior2=p2,p2=p2->next)
	//			{
	//				if(p1->sum>p2->sum)
	//				{
	//					t=p2->next;prior1->next=p2;
	//					prior2->next=p1;p2->next=p1->next;
	//					p1->next=t;p1=p2;
	//				}
	//				}
	//			} 
	//				
}
void shuru(struct information* head, int n)
{
	int i;
	struct information* p;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	for (i = 0;i < n;i++)
	{
		if (i < n - 1)
		{
			scanf_s("%s", (*p).num);
			scanf_s("%s", (*p).name);
			scanf_s("%d %d %d %d", &(*p).yinyu, &(*p).shuxue, &(*p).wuli, &(*p).cyuyan);
			p->next = (struct information*)malloc(sizeof(struct information));
			p = p->next;
		}
		else {//���һ��ѧ�����⻯ 
			scanf_s("%s", (*p).num);
			scanf_s("%s", (*p).name);
			scanf_s("%d %d %d %d", &(*p).yinyu, &(*p).shuxue, &(*p).wuli, &(*p).cyuyan);
			p->next = (struct information*)malloc(sizeof(struct information));
			p = p->next;
			p->next = NULL;
		}

	}
}
void shuchu(struct information* head)
{
	struct information* p;
	p = head;
	while (p->next != NULL)
	{
		printf("%s ", p->num);
		printf("%s ", p->name);
		printf("%d %d %d %d\n", p->yinyu, p->shuxue, p->wuli, p->cyuyan);
		p = p->next;
	}
}
void xiugai(struct information* head)
{
	struct information* p;
	struct information tell;//�޸ĵ�ѧ����Ϣ 
	scanf_s("%s", tell.num);
	int xuan;
	scanf_s("%d", &xuan);//�޸ĵĿ�Ŀ 
	int gai;
	scanf_s("%d", &gai);//���շ��� 
	p = head;
	while (strcmp(p->num, tell.num) != 0)//�ַ����ıȽ� 
	{
		p = p->next;
	}
	switch (xuan)
	{
	case 1:p->yinyu = gai;break;
	case 2:p->shuxue = gai;break;
	case 3:p->wuli = gai;break;
	case 4:p->cyuyan = gai;break;
	}
}
void jisuan(struct information* head)
{
	struct information* p;
	p = head;
	while (p->next != NULL)
	{
		p->sum = p->yinyu + p->shuxue + p->wuli + p->cyuyan;
		p->average = p->sum * 25;
		p->average += 0.5;
		p->average = (int)p->average;
		p->average /= 100;
		printf("%s ", p->num);
		printf("%s ", p->name);
		printf("%.2f\n", p->average);
		p = p->next;
	}
}
void shuchu2(struct information* head)
{
	struct information* p;
	p = head;
	while (p->next != NULL)
	{
		printf("%s ", p->num);
		printf("%s ", p->name);
		printf("%d %.2f\n", p->sum, p->average);
		p = p->next;
	}
}

int main()
{
	int choice;
	scanf_s("%d", &choice);//�˵�ѡ�� 
	int n;
	struct information* head, * p;
	head = (struct information*)malloc(sizeof(struct information));//��̬�洢
	head->next = NULL;
	while (choice > 0)//ʵ�ֲ˵�ѡ���� 
	{
		if (choice == 1)//ʵ�ֶ���ѧ����Ϣ���� 
		{
			scanf_s("%d", &n);//����ѧ������ 
			shuru(head, n);
			paixu(&head);
		}
		else if (choice == 2)//ʵ�ֶ���ѧ����Ϣ��� 
		{
			shuchu(head);
		}
		else if (choice == 3)//ʵ�ֳɼ��޸� 
		{
			xiugai(head);
		}
		else if (choice == 4)
		{
			jisuan(head);
		}
		else if (choice == 5)
		{
			shuchu2(head);
			break;
		}
		scanf_s("%d", &choice);
	}
	return 0;
}