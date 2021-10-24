
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct transcripts
{
    char ID[12];
    char name[10];
    int English;
    int Math;
    int Physics;
    int Cprogramming;
    double ave;
    int sum;
    struct transcripts *next;
};
int n, s = 0;
int k = 1, t;
int i, j;
char q[12];
struct transcripts *h = NULL, *tail, *a, *b, *c;
//��������

void create_list(int n)
{

    if (h == NULL)
    {
        h = tail = (struct transcripts *)malloc(sizeof(struct transcripts));
        scanf("%s", h->ID);
        scanf("%s", h->name);
        scanf("%d", &h->English);
        scanf("%d", &h->Math);
        scanf("%d", &h->Physics);
        scanf("%d", &h->Cprogramming);
        for (i = 1; i < n; i++)
        {
            tail->next = (struct transcripts *)malloc(sizeof(struct transcripts));
            tail = tail->next;
            scanf("%s", tail->ID);
            scanf("%s", tail->name);
            scanf("%d", &tail->English);
            scanf("%d", &tail->Math);
            scanf("%d", &tail->Physics);
            scanf("%d", &tail->Cprogramming);
        }
        tail->next = NULL;
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            tail->next = (struct transcripts *)malloc(sizeof(struct transcripts));
            tail = tail->next;
            scanf("%s", tail->ID);
            scanf("%s", tail->name);
            scanf("%d", &tail->English);
            scanf("%d", &tail->Math);
            scanf("%d", &tail->Physics);
            scanf("%d", &tail->Cprogramming);
        }
        tail->next = NULL;
    }
}
void display()
{
    a = h;
    for (i = 0; a != NULL; i++)
    {
        printf("%s ", a->ID);
        printf("%s ", a->name);
        printf("%d ", a->English);
        printf("%d ", a->Math);
        printf("%d ", a->Physics);
        printf("%d\n", a->Cprogramming);
        a = a->next;
    }
}

void modify()
{
 //   printf("����ѧ��ID\n");
    scanf("%s", q);
    a = h;
    for (i = 0; a != NULL; i++)
    {
        if (!strcmp(a->ID, q))
            break;
        a = a->next;
    }
//    printf("����1 �޸�Ӣ��ɼ�\n");
//    printf("����2 �޸ĸߵ���ѧ�ɼ�\n");
//    printf("����3 �޸���ͨ����ɼ�\n");
//    printf("����4 �޸�C���Գɼ�\n");
   scanf("%d", &t);
    switch (t)
    {
    case 1:
        scanf("%d", &a->English);
        break;
    case 2:
        scanf("%d", &a->Math);
        break;
    case 3:
        scanf("%d", &a->Physics);
        break;
    case 4:
        scanf("%d", &a->Cprogramming);
        break;
    default:
        break;
    }
};
void average(int n)
{

    a = h;
    for (i = 0; a != NULL; i++)
    {
        a->ave = (double)(a->English + a->Math + a->Physics + a->Cprogramming) / 4.0;
        printf("%s ", a->ID);
        printf("%s ", a->name);
        printf("%.2f\n", a->ave);
        a = a->next;
    }
}
void sum(int n)
{
    a = h;
    for (i = 0; a != NULL; i++)
    {
        a->sum = a->English + a->Math + a->Physics + a->Cprogramming;
        a->ave = (double)(a->English + a->Math + a->Physics + a->Cprogramming) / 4.0;
        printf("%s ", a->ID);
        printf("%s ", a->name);
        printf("%d ", a->sum);
        printf("%.2f\n", a->ave);
        a = a->next;
    }
}
void sort(int n)
{
    a = h;
    b = a->next; //����д��b=a+1

    for (i = 1; i <= n - 1; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            a->ave = (double)(a->English + a->Math + a->Physics + a->Cprogramming) / 4.0;
            b->ave = (double)(b->English + b->Math + b->Physics + b->Cprogramming) / 4.0; //�ڸú�������ǰ��a->ave��b->ave��û�б�����
            if (a->ave > b->ave)
            {
                free(c);
                c = (struct transcripts *)malloc(sizeof(struct transcripts)); //Ҫ��c���䶯̬�ռ�
                c = a;
                a = b;
                b = c;
                c->next = a->next;
                a->next = b->next;
                b->next = c->next;
                /*strcpy(c->ID, a->ID);
                strcpy(a->ID, b->ID);
                strcpy(b->ID, c->ID);
                strcpy(c->name, a->name);
                strcpy(a->name, b->name);
                strcpy(b->name, c->name);
                c->English = a->English;
                a->English = b->English;
                b->English = c->English;
                c->Math = a->Math;
                a->Math = b->Math;
                b->Math = c->Math;
                c->Physics = a->Physics;
                a->Physics = b->Physics;
                b->Physics = c->Physics;
                c->Cprogramming = a->Cprogramming;
                a->Cprogramming = b->Cprogramming;
                b->Cprogramming = c->Cprogramming;*/
            }
            a = a->next;
            b = b->next;
        }
        a = h;
        b = a->next;
    }
}
int main()
{
    while (k >= 1 && k <= 4)
    {

//        printf("�˵�\n");
//        printf("����1 ����ÿ��ѧ���ĸ�����Ϣ\n");
//        printf("����2 ���ÿ��ѧ���ĸ�����Ϣ\n");
//        printf("����3 �޸�ָ��ѧ����ָ������������\n");
//        printf("����4 ͳ��ÿ��ѧ����ƽ���ɼ��������ƽ���ɼ���������\n"); //�������������
//        printf("����5 �����λѧ����ѧ�š�������4�ſ��ܳɼ���ƽ���ɼ��������ƽ���ɼ���������\n");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
         //   printf("����ѧ������\n");
            scanf("%d", &n);
            s += n;
            create_list(n);
            sort(s);
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            average(s);
            break;
        case 5:
            sum(s);
            break;
        default:
            break;
        }
    }
    return 0;
}


