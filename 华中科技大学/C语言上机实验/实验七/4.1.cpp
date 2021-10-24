#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct c_node
{
    char data;
    struct c_node *next;
} C_NODE;
void createLinkList(C_NODE **headp, char *s)
{
    C_NODE *h = NULL, *tail;
    int i;
    h = tail = (C_NODE *)malloc(sizeof(C_NODE));
    h->data = s[0];
    for (i = 1; s[i] != '\0'; i++)
    {
        tail->next = (C_NODE *)malloc(sizeof(C_NODE));
        tail = tail->next;
        tail->data = s[i];
    }
    tail->next = NULL;
    *headp = h;
}
C_NODE *reverse_(C_NODE *head)
{
    C_NODE *newHead = NULL;
    C_NODE *node;
    while (head != NULL)
    {//��֮ǰ��������ͷɾ
        node = head;
        head = head->next;
        //����������ͷ��
        node->next = newHead;
        newHead = node;
    }
    return newHead;
}
//void reverse(C_NODE *h)
//{
//    C_NODE *p, *q;
//    if (!h)
//        return;
//    p = h;
//    h = NULL;
//    while (p) //�����ײ巨˼��
//    {
//        q = p->next;
//        p->next = h;
//        h = p;
//        p = q;
//    }
//}
void judgePalindrome(C_NODE *head)
{
    int len = 0, i;
    C_NODE *p, *head1 = head, *head2, *a, *b;
    int flag = 1;
    for (p = head; p; p = p->next)
        len++;
    a = head1;
    for (i = 0; i < len / 2 - 1; i++)
        a = a->next;
    if (!(len % 2))
        b = a->next;
    else
        b = a->next->next;
    head2 = b;
    a->next = NULL;
    head2 = reverse_(head2);
    for (i = 0, a = head1, b = head2; i < len / 2; i++, a = a->next, b = b->next)
        if (a->data != b->data)
            flag = 0;
    if (flag)
        printf("true");
    else
        printf("false");
}
int main()
{
char s[1000],*pc=s;
int len=0;
C_NODE *head,*p;
scanf("%[^\n]",s);
createLinkList(&head,s);
for(p=head;p;p=p->next) len++;
if (len!=strlen(s)) { printf("�������Ȳ���ȷ");return 1;}
else for(p=head;p;p=p->next)
        if (p->data!=*pc++) { printf("�������д�����");return 1;}
judgePalindrome(head);
return 1;
}
