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
#define FAIL -3//Ԥ���峣��

typedef int status;//����״̬�����־
typedef int ElemType; //����Ԫ�����Ͷ���

#define LIST_INIT_SIZE 100//���Ա�洢�ṹ����������
#define LISTINCREMENT  10//���Ա�ķ�������
typedef struct{  //˳���˳��ṹ���Ķ���
	ElemType * elem;//��������Ԫ��
	int length;//��
	int listsize;//�洢����
}SqList;

typedef struct{  //���Ա�Ĺ������
     struct { char name[30];
     		  SqList L;
      } elem[10];
      int length;
      int listsize;
 }LISTS;

status InitList(SqList& L);    //���Ա��ʼ��
status InitInput(SqList &L);   //���Ա���������
status DestroyList(SqList& L); //�������Ա�
status ClearList(SqList&L);    //������Ա�
status ListEmpty(SqList L);    //���Ա��п� return status
int ListLength(SqList L);      //��� return int
status GetElem(SqList L,int i,ElemType& e);             //��ȡָ��λ�� i ��Ԫ�� e
status LocateElem(SqList L,ElemType e);                 //��Ԫ������e ����Ԫ��λ��return status
status PriorElem(SqList L,ElemType cur,ElemType &pre_e);//�ɵ�ǰԪ������cur ��ȡ��ǰ��Ԫ��pre_e
status NextElem(SqList L,ElemType cur,ElemType &next_e);//�ɵ�ǰԪ������cur ��ȡ����Ԫ��next_e
status ListInsert(SqList&L,int i,ElemType e);           //�����Ա�ָ��λ�� i ǰ����Ԫ��e
status ListDelete(SqList&L,int i,ElemType& e);          //ɾ��λ�� i ��Ԫ�ش��� e ��
status ListTrabverse(SqList L);                 //������ǰ���Ա�
status SaveList(SqList L,char FileName[]);      //��ǰ���Ա�浵
status LoadList(SqList &L,char FileName[]);     //��ǰ���Ա����
status InitLists(LISTS &Lists);                 //���Ա��ϳ�ʼ��
status AddList(LISTS &Lists, char ListName[]);  //�򼯺��������Ϊ ListsName �����Ա�
status RemoveList(LISTS &Lists,char ListName[]);//ɾ����������Ϊ  ListsName �����Ա�
int LocateList(LISTS Lists,char ListName[]);    //�ڵ�ǰ�����в�����Ϊ ListsName �����Ա�
status ListsTraverse(LISTS Lists);              //������ǰ����
status SaveLists(LISTS Lists, char *FileName); //���Ա��ϴ浵
status LoadLists(LISTS &Lists, char *FileName); //���Ա��϶���  �������⣩
status ChangeList(SqList &L);                   //�޸ļ�����ָ�����Ա�
status EditList(LISTS Lists,SqList &L);
status SaveEdit(LISTS& Lists, SqList L) ;
 char* SaveFile = "D:\\���ݽṹʵ��\\�ļ�.dat";
 char* LoadFile = "D:\\���ݽṹʵ��\\�ļ�.dat";
 char* SaveFile1 = "D:\\���ݽṹʵ��\\�ļ�.dat";
 char* LoadFile1 = "D:\\���ݽṹʵ��\\�ļ�.dat";

/*--------------------------------------------*/
int main(){
SqList L;  
int op=1; int flag = 0;
int j;
L.elem = NULL;
LISTS Lists;
Lists.elem[0].L.elem = NULL;
SqList temp ;
SqList *L_ope;
temp.elem = NULL;

while(op){
	system("cls");	printf("\n\n");
	printf("                        ����˳��洢�����Ա�����˵�\n");
	printf("--------------------------------------------------------------------------\n");
	printf("    	  1. ��ʼ�����Ա�       7. ����Ԫ��            13. �������Ա�         19. �������е����Ա�����\n");
	printf("    	  2. �ݻ����Ա�         8. ����ǰ��Ԫ��        14. ��ȡ���Ա�         20. ɾ�����������Ա�\n");
	printf("    	  3. ������Ա�         9. ���Һ��Ԫ��        15. ��ʼ�����Ա���   21. �����Ա�洢��������\n");
	printf("    	  4. ���Ա��п�         10. ����Ԫ��           16. ���������е����Ա� 0. �˳�\n");
	printf("    	  5. ���Ա��         11. ɾ��Ԫ��           17. ���Ҽ����е����Ա�\n");
	printf("    	  6. ��λ����Ԫ��       12. �������Ա�         18. �������Ա���\n");
	printf("--------------------------------------------------------------------------\n");
	if(op)
	printf("    ��ѡ����Ĳ���[0~21]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
		 if(InitList(L)==OK)
		 {
		 	printf("���Ա����ɹ���\n");
		 }
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
		 j = ClearList(L);
		 if(j == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
		 else printf("��ճɹ���\n");
		 getchar();getchar();
		 break;
	   case 4:
		 j = ListEmpty(L);
		 if(j == INFEASIBLE) printf("��ǰ���Ա�����\n");
		 else if(j) printf("��ǰ���Ա�Ϊ��\n");
		 else printf("��ǰ���Ա�Ϊ��\n");
		 getchar();getchar();
		 break;
	   case 5:j = ListLength(L);
		 if(j == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
		 else printf("��ǰ���Ա���Ϊ%d\n",j);
		 getchar();getchar();
		 break;
	   case 6:
	   	if(L.elem==NULL)
		{
		   	printf("��ǰ���Ա����ڣ�\n");
		 	getchar();getchar();
		 	break;
		}
	   	 int i, e;
	   	 printf("���ҵڼ�λԪ�أ�\n");
	   	 scanf("%d",&i);
		 j = GetElem(L, i, e);
		 if(j == ERROR) printf("����λ�ò��Ϸ���\n");
		 else printf("��ǰ���Ա��е�%d��Ԫ��Ϊ%d\n", i, e);
		 getchar();getchar();
		 break;
	   case 7:
		 printf("����������ҵ�Ԫ������\n");
		 scanf("%d", &e);
		 j = LocateElem(L, e);
		 if(j == ERROR) printf("���в�����Ԫ�� %d\n",e);
		 else if(j == INFEASIBLE) printf("��ǰ���Ա�Ϊ�����ڣ�\n");
		 else printf("Ԫ��%dλ�����Ա��е�%d��λ��\n", e, j);
		 getchar();getchar();
		 break;
	   case 8:
	   	 int prior;
	   	 printf("���뵱ǰԪ��\n");
	   	 scanf("%d", &e);
	   	 j = PriorElem(L, e, prior);
	   	 if(j == ERROR) printf("��Ԫ����ǰ����\n");
	   	 else if(j == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
	   	 else printf("��ǰԪ��ǰ��Ϊ%d\n", prior);
		 getchar();getchar();
		 break;
	   case 9:
	   	 int next;
	   	 printf("���뵱ǰԪ��\n");
	   	 scanf("%d", &e);
	   	 j = NextElem(L, e, next);
	   	 if(j == ERROR) printf("��Ԫ���޺�̣�\n");
	   	 else if(j == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
	   	 else printf("��ǰԪ�غ��Ϊ%d\n", next);
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
		 	if(!ListTrabverse(L))
			printf("��ǰ���Ա����ڣ�\n");
		 }
		 getchar();getchar();
		 break;
	   case 11:
	   	 printf("ɾ���ڼ���Ԫ�أ�\n");
	   	 scanf("%d",&i);
	   	 j = ListDelete(L, i, e);
		 if(j == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
		 else if(j == ERROR) printf("ɾ��λ�÷Ƿ���\n");
		 else
		 {
		 	printf("ɾ���ɹ���\n");
		 	if(!ListTrabverse(L))
			printf("��ǰ���Ա����ڣ�\n");
		 }
		 getchar();getchar();
		 break;
	   case 12:
		 if(ListTrabverse(L) == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
		 getchar();getchar();
		 break;
	   case 13:
	   	if(SaveList(L, SaveFile) == INFEASIBLE) printf("��ǰ���Ա����ڣ�\n");
	   	else printf("�ѽ����ݴ��� %s\n",SaveFile);
		 getchar();getchar();
		 break;
	   case 14:
	   	 if((j = LoadList(L, LoadFile)) == ERROR) printf("��ǰ���Ա����������ݣ�\n");
	   	 else if(j == OK) printf("�����Ѵ� %s �ж���\n",LoadFile);
	   	 else if(j == INFEASIBLE) printf("��ǰ���Ա����ڣ����ȳ�ʼ����\n");
	   	 else if(j == FAIL) printf("�浵�ļ�����ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
	   case 15:
				if(InitLists(Lists) == INFEASIBLE) printf("��ǰ���Ա����ѱ���ʼ����\n");
				else printf("��ʼ���ɹ���\n");
		 		getchar();getchar();
				break;
	   case 16:
		 		if(Lists.elem[0].L.elem == NULL)
		 		{
		 			printf("��ǰ���Ա��ϲ����ڣ����ȳ�ʼ����\n");
		 			getchar();getchar();
		 			break;
				}
				char ListName[30];
		 		printf("�������������Ա�����ƣ�\n");
		 		scanf("%s",ListName);
	   	 		if(AddList(Lists, ListName) == OVERFLOW) printf("���Ա������������ʧ�ܣ�\n");
	   	 		else printf("���Ա�\"%s\"�洢�ɹ���\n", ListName);
		 		getchar();getchar();
				break;
	   case 20:
		 		if(Lists.elem[0].L.elem == NULL)
		 		{
		 			printf("��ǰ���Ա��ϲ����ڣ����ȳ�ʼ����\n");
		 			getchar();getchar();
		 			break;
				}
				printf("��������Ҫɾ�������Ա����ƣ�\n");
	   			scanf("%s",&ListName);
	   			if(RemoveList(Lists, ListName))
	   	 		{
	   		 		printf("���Ա�%sɾ���ɹ���\n",ListName);
		 		}
		 		else
		 		{
		 	 		printf("���޴˱�\n");
		 		}
		 		getchar();getchar();
		 		break;
	   case 17:
		 		if(Lists.elem[0].L.elem == NULL)
		 		{
		 			printf("��ǰ���Ա��ϲ����ڣ����ȳ�ʼ����\n");
		 			getchar();getchar();
		 			break;
				}
		 		printf("������Ҫ��λ�ı���:\n");
		 		scanf("%s",ListName);
		 		j = LocateList(Lists, ListName);
		 		if(j == 0)
		 		{
		 			printf("���޴˱�\n");
		 			getchar();getchar();
		 			break;
				}
				else
				{
					ListTrabverse(Lists.elem[j - 1].L);
				}
				getchar();getchar();
				break;
		case 18:
	   	 		if((j = ListsTraverse(Lists)) == 0) printf("��ǰ���Ա���Ϊ�գ�\n");
	   	 		else if(j == INFEASIBLE) printf("��ǰ���Ա��ϲ����ڣ�\n");
		 		getchar();getchar();
		 		break;
		case 19:
		 		if(Lists.elem[0].L.elem == NULL)
		 		{
		 			printf("��ǰ���Ա��ϲ����ڣ����ȳ�ʼ����\n");
		 			getchar();getchar();
		 			break;
				}
		 		EditList(Lists,L);
		 		getchar();getchar();
		 		break;
		 		case 21:
		 		if(Lists.elem[0].L.elem == NULL)
		 		{
		 			printf("��ǰ���Ա��ϲ����ڣ����ȳ�ʼ����\n");
		 			getchar();getchar();
		 			break;
				}
		 		SaveEdit(Lists,L);
		 		getchar();getchar();
		 		break;
	   case 0:
         break;
	}//end of switch
  }//end of while
printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
return 0;
}//end of main()
status SaveEdit(LISTS& Lists, SqList L) 
{
//���¹���ϵͳ�е����Ա�
	char ListName[30];
	printf("��������������Ա�����");
	scanf("%s",ListName); 
	int k=LocateList(Lists,ListName);
	if(!k)
	{
		printf("δ�ҵ������Ա�");
		return ERROR; 
	}
	if(L.elem==NULL){printf("��ǰ���Ա�����\n");return ERROR;}
	Lists.elem[k - 1].L=L;
	printf("%s���³ɹ���", ListName);
	return OK;
}
status EditList(LISTS Lists,SqList &L)
{
	char ListName[30];
	printf("��������������Ա�����");
	scanf("%s",ListName); 
	int k=LocateList(Lists,ListName);
	if(!k)
	{
		printf("δ�ҵ������Ա�");
		return ERROR; 
	}
	InitList(L);
	L=(Lists.elem[k-1].L);
	printf("���Ա�����ɹ�"); 
	return OK;
}
status InitList(SqList& L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    if(!L.elem)
    {
    	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
		L.length = 0;
		L.listsize = LIST_INIT_SIZE;
		return OK;
	}
	else
	{
		return INFEASIBLE;
	}
}

status InitInput(SqList &L)
{
	int ord, temp;
	printf("�������ݰ�1������0\n");
	scanf("%d",&ord);
	if(ord == 0)
	{
		return 0;
	}
	else
	{
		printf("������һ�����ݣ�0Ϊ������־\n");
		scanf("%d",&temp);
		while(temp != 0)
		{
			if(L.length > L.listsize)
			{
				L.elem = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
				L.listsize += LISTINCREMENT;
			}
			ListInsert(L, L.length + 1, temp);
			scanf("%d",&temp);
		}
		printf("����ɹ���\n");
		return OK;
	}
}

status DestroyList(SqList& L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
	if(!L.elem)
	{
		return INFEASIBLE;
	}
	else
	{
		free(L.elem);
        L.length = 0;
        L.listsize = 0;
        L.elem = NULL;
		return OK;
	}
}

status ClearList(SqList& L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
	if(!L.elem)
	{
		return INFEASIBLE;
	}
	else
	{
		free(L.elem);
		L.length = 0;
		L.listsize = LIST_INIT_SIZE;
		L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
		return OK;
	}
}

status ListEmpty(SqList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
	if(!L.elem)
	{
		return INFEASIBLE;
	}
	else
	{
		if(L.length == 0)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
}

int ListLength(SqList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
	if(!L.elem)
	{
		return INFEASIBLE;
	}
	else
	{
		return L.length;
	}
}

status GetElem(SqList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	if(!L.elem)
	{
		return INFEASIBLE;
	}
	else
	{
		if(i > L.length || i < 1)
		{
			return ERROR;
		}
		else
		{
			e = L.elem[i - 1];
			return OK;
		}
	}
}

status LocateElem(SqList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų�����OK�����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{
	if(!L.elem)
	{
		return INFEASIBLE;
	}
	else
	{
		for(int i = 0; i < L.length; i++)
		{
			if(L.elem[i] == e)
			{
				return i + 1;
			}
		}
		return ERROR;
	}
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	if(!L.elem)
	{
		return INFEASIBLE;
	}
	else
	{
		for(int i = 0; i < L.length; i++)
		{
			if(L.elem[i] == e)
			{
				if(i)
				{
					pre = L.elem[i - 1];
					return OK;
				}
				else
				{
					return ERROR;
				}
			}
		}
		return ERROR;
	}
}

status NextElem(SqList L,ElemType e,ElemType &next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	if(!L.elem)
	{
		return INFEASIBLE;
	}
	else
	{
		for(int i = 0; i < L.length; i++)
		{
			if(L.elem[i] == e)
			{
				if(i == L.length - 1)
				{
					return ERROR;
				}
				else
				{
					next = L.elem[i + 1];
                    return OK;
				}
			}
		}
		return ERROR;
	}
}

status ListInsert(SqList &L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	if(!L.elem)
	{
		return INFEASIBLE;
	}
	else
	{
		if(i > L.length + 1 || i < 1)
		{
			return ERROR;
		}
		else
		{
			if(L.listsize < L.length + 1)
			{
				L.elem = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
				if(L.elem)
				{
					L.listsize += LISTINCREMENT;
				}
				else
				{
					return OVERFLOW;
				}

			}
			for(int j = L.length; j >= i; j--)
			{
				L.elem[j] = L.elem[j - 1];
			}
			L.elem[i - 1] = e;
			L.length++;
			return OK;
		}
	}
}

status ListDelete(SqList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	if(!L.elem)
	{
		return INFEASIBLE;
	}
	else
	{
		if(i < 1 || i > L.length)
		{
			return ERROR;
		}
		else
		{
            e = L.elem[i - 1];
			for(int j = i; j < L.length; j++)
			{
				L.elem[j - 1] = L.elem[j];
			}
			L.length--;
			return OK;
		}
	}
}

status ListTrabverse(SqList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
	if(!L.elem)
	{
		return INFEASIBLE;
	}
	else
	{
		printf("��ǰ���Ա�����������:\n");
		for(int i = 0; i < L.length; i++)
		{
			printf("%d",L.elem[i]);
			if(i != L.length - 1)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
		return OK;
	}
}

status SaveList(SqList L,char filename[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
	FILE  *fp;
	if(L.elem==NULL)
	{
		printf("δ��ʼ�����Ա�\n");
		return -1;
	}
	if ((fp=fopen(filename,"wb"))==NULL)
	{
		printf("File open error\n ");
		return -1;
	}
	fwrite(L.elem,sizeof(ElemType),L.length,fp);
	//������1����д�룬������������ṹ����ͨ�������������������Ԫ��
	//��д�뵽�ļ��С�Ҳ������д�������д��ȫ��Ԫ�أ���������������
	fclose(fp);
	return OK;
}
status LoadList(SqList &L,char filename[])
// ������Ա�LΪ�ǿգ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
	FILE  *fp;
	if(L.elem==NULL)
	{
		InitList(L);
	}
	if(L.length)
	{
		printf("���Ա�Ϊ�գ�\n");
		return -1;
	}
	if ((fp=fopen(filename,"rb"))==NULL)
	{
		printf("File open error\n ");
	 	return -1;
	}
	while(fread(&L.elem[L.length],sizeof(ElemType),1,fp))
	L.length++;
	//������ļ��������ȡ����Ԫ�ػָ�˳������ڲ�ͬ������ṹ����ͨ����//ȡ������Ԫ�ػָ��ڴ��е�����ṹ��
	fclose(fp);
	return OK;
}
status InitLists(LISTS &Lists)
//���Ա��ϳ�ʼ��
{
	if(Lists.elem[0].L.elem != NULL)
	{
		return INFEASIBLE;
	}
	else
	{
		Lists.length = 0;
		Lists.listsize = 10;
		InitList(Lists.elem[0].L);
		return OK;
	}
}

status AddList(LISTS &Lists, char ListName[])
// ��Lists������һ������ΪListName�Ŀ����Ա���������Ա�����
{
	if(Lists.length == Lists.listsize) //��������ж�
	{
		return OVERFLOW;
	}
	Lists.elem[Lists.length].L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	Lists.elem[Lists.length].L.length = 0;
	Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;
	strcpy(Lists.elem[Lists.length].name ,ListName);
	InitInput(Lists.elem[Lists.length].L);
	Lists.length++;
	return OK;
}

status RemoveList(LISTS &Lists,char ListName[])
// Lists��ɾ��һ������ΪListName�����Ա�
{
    for(int i = 0; i < Lists.length; i++)
	{
		if(!strcmp(ListName,Lists.elem[i].name))
		{
			for(; i < Lists.length - 1; i++)
			{
				Lists.elem[i] = Lists.elem[i + 1];
			}
			Lists.length--;
			return OK;
		}
	}
	return 0;
}

int LocateList(LISTS Lists,char ListName[])
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
{
	for(int i = 0; i < Lists.length; i++)
	{
		if(!strcmp(ListName, Lists.elem[i].name))
		{
			return i + 1;
		}
	}
	return 0;
}

status ListsTraverse(LISTS Lists)
//�������Ա��ϣ��������Ϊ�շ���0�����򽫼��������Ա��ȫ�����������������OK
{

	if(Lists.elem[0].L.elem == NULL)
	{
		return INFEASIBLE;
	}
	if(Lists.length == 0)
	{
		return 0;
	}
	printf("��ǰ���Ա����й���������%d�����Ա�\n", Lists.length);
	for(int i = 0; i < Lists.length; i++)
	{
		printf("%s\n",Lists.elem[i].name);
		if(Lists.elem[i].L.length == 0)
		{
			printf("��\n");
		}
		for(int j = 0; j < Lists.elem[i].L.length; j++)
		{
			printf("%d",Lists.elem[i].L.elem[j]);
			if(j != Lists.elem[i].L.length - 1)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
	}
	return OK;
}

status SaveLists(LISTS Lists, char *FileName)
//�����������ݴ����ļ� FileName �У������Ա���Ϊ�ջ򲻴���ʱ������INFEASIBLE,���򷵻�OK
{
	if(Lists.elem == NULL || Lists.length == 0)
	{
		return INFEASIBLE;
	}
	FILE *fp = fopen(FileName,"w+");
	char ch = '\0';
	for(int i = 0; i < Lists.length; i++)
	{
		fprintf(fp, "%s", Lists.elem[i].name);
		fprintf(fp,"%c",'\n');
		for(int j = 0; j < Lists.elem[i].L.length; j++)
		{
			fprintf(fp, "%d", Lists.elem[i].L.elem[j]);
			if(j == Lists.elem[i].L.length - 1)
			{
				fprintf(fp, "%c", '\n');
			}
			else
			{
				fprintf(fp, "%c", ' ');
			}
		}
	}
	fclose(fp);
	return OK;
}
