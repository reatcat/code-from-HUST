#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 20
#define LISTINCREMENT 10
typedef int ElemType;
typedef struct
   { ElemType *elem;
     int length;
     int listsize;
    } SqList;
int insert(SqList &L,ElemType x);
int main()
{
    SqList L;
    ElemType x;
    int i;
    L.elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    scanf("%d",&x);
    while (x)//如果不是0的话就加一 
    {
        L.elem[L.length++]=x;
        scanf("%d",&x);
    }
    scanf("%d",&x);//此时是要插入的元素 
    insert(L,x);
    for(i=0;i<L.length;i++)
        printf("%8d",L.elem[i]);
    if (L.length>L.listsize) printf("\n程序未处理溢出");

	return 0;
}
int insert(SqList &L,ElemType x)
{
/**********begin**********/
int i=0;
	if(L.length==0)
	{
		L.elem[L.length++]=x;
		L.listsize++;
	}
	else{
		for(i=0;x>L.elem[i];i++)
		;
		if(x<L.elem[i])
		{
			int j=0;
			for(j=0;j<L.length-i+1;j++)
			{
				L.elem[L.length-j]=L.elem[L.length-j-1];
			}
			L.length++,L.listsize++;
			L.elem[i]=x;
		}	
	if(i==L.length-1)
		L.elem[L.length++]=x;
		L.listsize++;
	}
	 return 0;

/**********end**********/
}


