#include "stdio.h"
#include "stdlib.h"
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
typedef struct{  //˳���˳��ṹ���Ķ���
	      ElemType * elem;
	      int length;
	      int listsize;
         }SqList;
status ClearList(SqList& L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
if(L.elem) 
{
	
	L.length=0;
	return OK;
}
else return -1;
    /********** End **********/
}
int main() {
	SqList L;
	int i,j;
	scanf("%d",&i);
	if (!i) { 
		L.elem=NULL;
		j=ClearList(L);
		if (j==INFEASIBLE) printf("INFEASIBLE");
    	else printf("���ܻ�Բ����ڵ����Ա����");
    }
	else {
		L.elem=(ElemType *) malloc(sizeof(ElemType));
        L.length = 1;
		j=ClearList(L);
		if (L.length) printf("δ��ȷ���");
		if (!L.elem)  printf("�����ͷ�Ԫ�ؿռ�");
		if (j==OK) printf("OK");
		free(L.elem);
    }
	return 1;
}
