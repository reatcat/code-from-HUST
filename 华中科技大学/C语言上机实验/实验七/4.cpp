typedef struct c_node
{
    char data;
    struct c_node *next;
} C_NODE;
void createLinkList(C_NODE **headp, char *s)
{
    C_NODE *h=NULL, *tail;
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
C_NODE *reverse_(C_NODE *head)//����������з�ת 
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
void judgePalindrome(C_NODE *head)
{
    int len = 0, i;
    C_NODE *p, *head1 = head, *head2, *a, *b;
    int flag = 1;
    for (p = head; p; p = p->next)//�жϳ�����ĳ��� 
        len++;
    a = head1;
    for (i = 0; i < len / 2 - 1; i++)//ȡһ������� 
        a = a->next;
    if (!(len % 2))
        b = a->next;
    else
        b = a->next->next;
    head2 = b;
    a->next = NULL;
    head2 = reverse_(head2);//��תһ������ 
    for (i = 0, a = head1, b = head2; i < len / 2; i++, a = a->next, b = b->next)
        if (a->data != b->data)
            flag = 0;
    if (flag)
        printf("true");
    else
        printf("false");
}

