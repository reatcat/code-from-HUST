/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct LNode{  //��������ʽ�ṹ�����Ķ���
      ElemType data;
      struct LNode *next;
    }LNode,*LinkList;

typedef struct {  //���Ա�Ĺ������
	struct {
		char name[30];
		LinkList L;
	} elem[10];
	int length;
	int listsize;
}LISTS;
/*-------------���Ա����---------------*/
status InitList(LinkList &L);// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
status DestroyList(LinkList &L);// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
status ClearList(LinkList &L);// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
status ListEmpty(LinkList L);// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
status ListLength(LinkList L);// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
status GetElem(LinkList L,int i,ElemType &e);// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status LocateElem(LinkList L,ElemType e);// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
status PriorElem(LinkList L,ElemType e,ElemType &pre);// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status NextElem(LinkList L,ElemType e,ElemType &next);// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status ListInsert(LinkList &L,int i,ElemType e);// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status ListDelete(LinkList &L,int i,ElemType &e);// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status ListTraverse(LinkList L);// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
status SaveList(LinkList L,char FileName[]);// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
status LoadList(LinkList &L,char FileName[]);// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
/*-------------���Ա����---------------*/

/*-------------���Ա��ϲ���---------------*/
status InitInput(LinkList &L);
status AddList(LISTS& Lists, char ListName[]);// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ɺ�̨���Գ�����롣
status RemoveList(LISTS& Lists, char ListName[]);// Lists��ɾ��һ������ΪListName�����Ա�
status LocateList(LISTS Lists, char ListName[]);// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
status SaveEdit(LISTS& Lists, LinkList L, char ListName[]);//���¹���ϵͳ�е����Ա�
status EditList(LISTS Lists, LinkList& L, char ListName[]);
status ListGet(LISTS Ls,int i);//����ָ�����Ա� 
status TraverseLists(LISTS Lists);//�����������Ա� 
/*-------------���Ա��ϲ���---------------*/
int main(){  
int op=1; 
LinkList L;//��ʽ���Ա�Ķ���L
L=NULL;
int e,i,j;
char filename[100];
char Listname[30]; 
LISTS Ls;
Ls.length=0,Ls.listsize=10;
while(op){
	system("cls");	printf("\n\n");
	printf("                        ����˳��洢����ʽ������˵�\n");
	printf("--------------------------------------------------------------------------\n");
	printf("    	  1. ��ʼ������       7. ����Ԫ��            13. ��������                   19. �������е����Ա�����\n");
	printf("    	  2. �ݻ�����         8. ����ǰ��Ԫ��        14. ��ȡ����      	            20. ���������е����Ա�\n");
	printf("    	  3. �������         9. ���Һ��Ԫ��        15. �����ϲ���               21. �����Ա�洢��������\n");
	printf("    	  4. �����п�         10. ����Ԫ��           16. ɾ�������е����Ա�         0. �˳�\n");
	printf("    	  5. �����         11. ɾ��Ԫ��           17. ��λ�����е����Ա�\n");
	printf("    	  6. ��λ����Ԫ��     12. ��������           18. ��������\n");
	printf("--------------------------------------------------------------------------\n");
	printf("    ��ѡ����Ĳ���[0~15]:");
	scanf("%d",&op);
    switch(op){
	case 1:
		if((j=InitList(L))==OK) printf("���Ա����ɹ���\n"); 
		else if(j==-1)printf("���Ա��Ѵ�����\n");
		else printf("���Ա���ʧ�ܣ�\n");
		getchar();getchar();
		break;
	case 2:
		j = DestroyList(L);
		if(j == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
		else printf("���ٳɹ���\n");
		getchar();getchar();
		break;
	case 3:
		j=ClearList(L);
		if(j == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
		else printf("����ɹ���\n");   
		getchar();getchar();
		break;
	case 4:
		j=ListEmpty(L);
		if(j == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
		else if(j) printf("��ǰ���Ա�Ϊ��\n");
		else printf("��ǰ���Ա�Ϊ��\n");
		getchar();getchar();
		break;
	case 5:
		j=ListLength(L); 
		if(j == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
		else printf("��ǰ���Ա���Ϊ%d\n",j);
		getchar();getchar();
		break;
	case 6:
		printf("���ҵڼ�λԪ�أ�\n");
	   	scanf("%d",&i);
		j = GetElem(L,i,e);
		if(j == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
		else if(j == ERROR) printf("����λ�ò��Ϸ���\n");
		else printf("��ǰ���Ա��е�%d��Ԫ��Ϊ%d\n", i, e);
		getchar();getchar();
		break;
	case 7:
		printf("������Ҫ���ҵ�Ԫ�أ�\n");
		scanf("%d",&e);
		j=LocateElem(L,e);
		if(j==-1) printf("��ǰ���Ա����ڣ�\n");
		else if(j==0) printf("δ�ҵ���Ԫ�أ�\n");
		else printf("Ԫ��%dλ�����Ա��е�%d��λ��\n", e, j);    
	 	getchar();getchar();
		break;
	case 8:
		int cur,pre;
		printf("���뵱ǰԪ��\n");
	   	scanf("%d", &cur);
		j=PriorElem(L,cur,pre);   
		if(j==-1) printf("��ǰ���Ա����ڣ�\n");
		else if(j==0) printf("��Ԫ����ǰ����\n");
		else printf("Ԫ��%d��ǰ����%d\n",cur,pre);  
		getchar();getchar();
		break;
	case 9:
		int next;
		printf("���뵱ǰԪ��\n");
	   	scanf("%d", &cur);
		j=NextElem(L,cur,next);   
		if(j==-1) printf("��ǰ���Ա����ڣ�\n");
		else if(j==0) printf("��Ԫ���޺�̣�\n");
		else printf("Ԫ��%d�ĺ����%d\n",cur,next);       
		getchar();getchar();
		break;
	case 10:
		printf("�������Ԫ��\n");
	   	scanf("%d", &e);
	   	printf("�����ڼ���Ԫ��ǰ��\n");
		scanf("%d", &i);
		j = ListInsert(L, i, e);
		if(j == ERROR) printf("����λ�÷Ƿ���\n");
		else if(j == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
		else
		{
		 	printf("����ɹ���\n");
		 	ListTraverse(L);
		}
		getchar();getchar();
		break;
	case 11:
		printf("������ɾ����Ԫ��λ��\n");
		scanf("%d", &i);
		j = ListDelete(L, i, e);
		if(j == ERROR) printf("ɾ��λ�÷Ƿ���\n");
		else if(j == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
		else
		{
			printf("%d��ɾ���ɹ���\n",e);
		 	ListTraverse(L);
		}   
		getchar();getchar();
		break;
	case 12:
		if(ListTraverse(L)==-1) printf("��ǰ���Ա����ڣ�\n");
		getchar();getchar();
		break;
	case 13:
		printf("�����ļ���:\n");
		scanf("%s",filename); 
		if((j=SaveList(L,filename))!=-1)printf("���浽�ļ��ɹ�\n");
		getchar();getchar();
		break;
	case 14:	
		printf("�����ļ���:\n");
		scanf("%s",filename);
		if((j=LoadList(L,filename))!=-1)printf("���ļ���ȡ�ɹ� \n");
		getchar();getchar();
	   	break;
	case 15:
		//�½�����ϵͳ�����Ա�
		printf("�������������Ա������:");
		scanf("%s", Listname);
		if (AddList(Ls, Listname) == ERROR) {
			int choice;
			printf("���Ա������Ѵ���,�Ƿ����?(1:��,0:��)\n");
			scanf("%d", &choice);
			if (choice) {
				RemoveList(Ls, Listname);
				AddList(Ls, Listname);
				printf("���Ա�\"%s\"�洢�ɹ���\n", Listname);
			}
		}
		else printf("���Ա�\"%s\"�洢�ɹ���\n", Listname);
		getchar(); getchar();
		break;
	case 16:
		//ɾ������ϵͳ�����Ա�
		printf("�������ɾ�����Ա�����:");
		scanf("%s", Listname);
		if (RemoveList(Ls, Listname) == FALSE) printf("�����Ա�����\n");
		else printf("ɾ���ɹ�!\n");
		getchar(); getchar();
		break;
	case 17:
		//��ѯ����ϵͳ�����Ա�
		printf("������Ҫ��λ�ı���:\n");
		scanf("%s", Listname);
		if ((j = LocateList(Ls, Listname)) == 0) printf("�����Ա�����\n");
		else printf("�����Ա�Ĵ���Ϊ%d\n", j);
		getchar(); getchar();
		break;
	case 18:
		if(TraverseLists(Ls)==-1)printf("���Ա���Ϊ��\n"); 
		getchar();getchar();
		break;
	case 19:
		//�༭����ϵͳ�����Ա�
		printf("��������༭���Ա�����:");
		scanf("%s", Listname);
		EditList(Ls, L, Listname);
		getchar(); getchar();
		break;
	case 20:
	 	int i;
		printf("��������Ҫ���������Ա���ţ�");
		scanf("%d",&i);
		if(ListGet(Ls,i)==-1)printf("��Ų���ȷ\n");
	 	getchar();getchar();
	 	break;
	case 21:
		//���¹���ϵͳ���Ա�
		printf("����������µ����Ա�����:");
		scanf("%s", Listname);
		SaveEdit(Ls, L, Listname);
		getchar(); getchar();
		break;
	case 0:
    break;
	}//end of switch
  }//end of while
printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()
status InitList(LinkList &L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L!=NULL)return INFEASIBLE;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    return OK;
    /********** End **********/
}
status InitInput(LinkList &L)
// ���Ա����ڣ�����INFEASIBLE��������Ա�Ϊ�ձ��������ݣ�������Ա�Ϊ�գ�����ERROR 
{
	{
		ElemType temp = 0;
		printf("������һ������(0����):\n");
		scanf("%d",&temp);
		while(temp)
		{
			L->next = (LinkList)malloc(sizeof(LNode));
			L = L->next;
			L->data = temp;
			scanf("%d",&temp);
		}
		L->next = NULL;
	}
}


status DestroyList(LinkList &L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE;
    LinkList q=L,p;
    while(p) //�������г�ͷ���������н���ͷ� 
    { 
    p=q->next; 
    free(q); 
    q=p;
    } 
    L=NULL;
    return OK;
    /********** End **********/
}

status ClearList(LinkList &L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE;
    LinkList p=L->next,q;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;
    return OK;
    /********** End **********/
}
status ListEmpty(LinkList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE;
    if(L->next==NULL)return TRUE;
    else return FALSE;
    /********** End **********/
}
int ListLength(LinkList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE;
    int x=0;
    L=L->next;
    while(L)
    {
        x++;
        L=L->next;
    }
    return x;
    /********** End **********/
}
status GetElem(LinkList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE;
    if(i<1)return ERROR;
    while(i>0)
    {
        L=L->next;
        i--;
        if(L==NULL)return ERROR;
    }
    e=L->data;
    return OK;
    /********** End **********/
}
status LocateElem(LinkList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE;
    int i=0;
    while(L->next)
    {
        L=L->next;i++;
        if(L->data==e)return i;
    }
    return ERROR;
    /********** End **********/
}
status PriorElem(LinkList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE;
    L=L->next;
    if(L==NULL)return ERROR;
    LinkList p=L;
    L=L->next;
    while(L)
    {
        if(L->data==e){pre=p->data;return OK;}
        p=L;L=L->next;
    }
    return ERROR;
    /********** End **********/
}
status NextElem(LinkList L,ElemType e,ElemType &next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE;
    L=L->next;
    if(L==NULL)return ERROR;
    while(L->next)
    {
        if(L->data==e){next=L->next->data;return OK;}
        L=L->next;
    }
    return ERROR;
    /********** End **********/
}
status ListInsert(LinkList &L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE; 
    LinkList p=L;int j=1;
    while(p&&j<i){
	p=p->next;
	j++;
	}
    if(!p||j>i)return ERROR;
    LinkList s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
	s->next=p->next;
	p->next=s;
    return OK;
    /********** End **********/
}
status ListDelete(LinkList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE; 
    LinkList p=L;int j=1;
    while(p->next&&j<i){p=p->next;j++;}
    if(!p->next||j>i)return ERROR;
    LinkList q=p->next;p->next=q->next;
    e=q->data;
    free(q);
    return OK;
    /********** End **********/
}
status ListTraverse(LinkList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE; 
    printf("��ǰ���Ա�����������:\n");
	while(L->next)
    {
        L=L->next;
        printf("%d",L->data);if(L->next)printf(" ");
    }
    printf("\n");
    return OK;
    /********** End **********/
}
status SaveList(LinkList L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin 1 *********/
    if(L==NULL){printf("δ��ʼ�����Ա�\n");return INFEASIBLE;}
    FILE *fp;
    fp=fopen(FileName,"w");
    if(fp==NULL){
	printf("�ļ���ʧ��\n");
	return INFEASIBLE;}
    while(L->next)
    {
        L=L->next;
        fprintf(fp,"%d ",L->data);
    }
    fclose(fp);
    return OK;

    /********** End 1 **********/
}
status LoadList(LinkList &L,char FileName[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin 2 *********/
    LinkList p;
    if(L!=NULL){printf("���Ա��Ѵ���\n");return INFEASIBLE;}
    FILE *fp;
    L=(LinkList)malloc(sizeof(LNode));
    p=L;
    fp=fopen(FileName,"r");
    if(fp==NULL){printf("�ļ���ʧ��\n");return INFEASIBLE;}
    int e;
    while(fscanf(fp,"%d ",&e)!=EOF)
	{
    p->next=(LinkList)malloc(sizeof(LNode));
    p=p->next;
    p->data=e;
    }
    p->next=NULL;
    fclose(fp);
    return OK;
    /********** End 2 **********/
}
status AddList(LISTS& Lists, char ListName[])
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ɺ�̨���Գ�����롣
{
	int k = LocateList(Lists, ListName);
	if (k)
		return ERROR;//�������Ѵ��� 
	strcpy(Lists.elem[Lists.length].name, ListName);
	Lists.elem[Lists.length].L = NULL;
	InitList(Lists.elem[Lists.length].L);
	InitInput(Lists.elem[Lists.length].L);
	Lists.length++;
	return OK;
}
status RemoveList(LISTS& Lists, char ListName[])
// Lists��ɾ��һ������ΪListName�����Ա�
{
	int i;
	for (i = 0; i < Lists.length; i++) {
		if (!strcmp(Lists.elem[i].name, ListName))  break;
	}
	if (i == Lists.length) return FALSE;//δ�ҵ�
	DestroyList(Lists.elem[i].L);
	for (; i < Lists.length - 1; i++) {//�ƶ�����ϵͳ�е�Ԫ��
		Lists.elem[i] = Lists.elem[i + 1];
	}
	Lists.length--;//����ϵͳ�����Ա������һ
	return OK;
}
status LocateList(LISTS Lists, char ListName[])
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
{
	int i;
	for (i = 0; i < Lists.length; i++) {
		if (!strcmp(Lists.elem[i].name, ListName))  break;
	}
	if (i == Lists.length) return 0;//δ�ҵ�
	return i + 1;//�߼����Ϊ�±�+1
}
status SaveEdit(LISTS& Lists, LinkList L, char ListName[]) 
{
//���¹���ϵͳ�е����Ա�
	int k = LocateList(Lists, ListName);
	if (!k) {
		printf("δ�ҵ��ļ���Ϊ%s�����Ա�\n", ListName);
		return ERROR;
	}
	if(L==NULL){printf("��ǰ���Ա�����\n");return ERROR;}

	ClearList(Lists.elem[k - 1].L);
	LinkList temp, p, q;
	p = L->next;
	q = Lists.elem[k-1].L;
	while (p)
	{
		temp = (LinkList)malloc(sizeof(LNode));
		temp->data = p->data;
		q->next = temp;
		q = q->next;
		p = p->next;
	}
	q->next = NULL;
	printf("%s���³ɹ���", ListName);
	return OK;
}
status EditList(LISTS Lists, LinkList& L, char ListName[]) {
	//�������������ΪListName�����Ա���ص�L
	if (!ListEmpty(L)) {//��ǰ�༭�����Ա�ǿ�
		int choice;
		printf("�������Ա�ǿ�,�����������ܻᶪʧ���ݣ��Ƿ������(1:��,0:��):\n");
		scanf("%d", &choice);
		if (!choice) return ERROR;
		else DestroyList(L);
	}
	int k = LocateList(Lists, ListName);
	if (!k) {
		printf("\nδ�ҵ��ļ���Ϊ%s�����Ա�\n", ListName);
		return ERROR;
	}
//	InitList(L);
	LinkList q = L;
	LinkList p = Lists.elem[k - 1].L->next;
	LinkList temp;
	while (p)
	{
		temp = (LinkList)malloc(sizeof(LNode));
		temp->data = p->data;
		q->next = temp;
		q = q->next;
		p = p->next;
	}
	q->next = NULL;
	printf("\n���ڿɶ�%s���б༭,�ǵ�ʹ�ñ���༭\n", ListName);
	return OK;
}
status ListGet(LISTS Ls,int i)
{
	if(i>Ls.length||i<1)return -1;
	printf("%s\n",Ls.elem[i-1].name);
	ListTraverse(Ls.elem[i-1].L);
}
status TraverseLists(LISTS Ls)
{
	if(Ls.length==0)return -1;
	else
	{
		printf("��ǰ���Ա����й���������%d�����Ա�\n", Ls.length);
		for(int i=0;i<Ls.length;i++)
		{
			printf("%s\n",Ls.elem[i].name);
			ListTraverse(Ls.elem[i].L);
		}
	}
	return OK;
}

