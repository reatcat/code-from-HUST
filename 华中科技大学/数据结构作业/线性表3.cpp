#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 5000
#define LISTINCREMENT 10
typedef int ElemType;
typedef struct
   { ElemType *elem;
     int length;
     int listsize;
    } SqList;
void  TriSqList(SqList  &A,SqList  B,SqList  C)
{
/**********Begin**********/
    int i=0,j=0,k=0,temp;
    for(i=0;i<A.length;i++)
    {
        for(;B.elem[j]<A.elem[i];j++)
            ;
        if(B.elem[j]>A.elem[i])
            continue;
        for(;C.elem[k]<A.elem[i];k++)
            ;
        if(C.elem[k]>A.elem[i])
            continue; 
        for(temp=i;t<A.length-1;temp++)
            A.elem[temp]=A.elem[temp+1];
        A.length--;
        i--;
    }
 /**********End**********/
}
int main()
{
    SqList L[3];
    ElemType x;
    int i;
    for(i=0;i<3;i++)
    {
    	L[i].elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    	L[i].length=0;
    	L[i].listsize=LIST_INIT_SIZE;
    	scanf("%d",&x);
    	while (x)
    	{
        	L[i].elem[L[i].length++]=x;
        	scanf("%d",&x);
    	}
    }
    TriSqList(L[0],L[1],L[2]);
    for(i=0;i<L[0].length;i++)
        printf(" %d",L[0].elem[i]);
	return 0;
}


