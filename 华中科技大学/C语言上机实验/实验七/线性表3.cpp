#include "stdio.h"
#include "stdlib.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct{  //顺序表（顺序结构）的定义
	      ElemType * elem;
	      int length;
	      int listsize;
         }SqList;
status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
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
    	else printf("可能会对不存在的线性表清空");
    }
	else {
		L.elem=(ElemType *) malloc(sizeof(ElemType));
        L.length = 1;
		j=ClearList(L);
		if (L.length) printf("未正确清空");
		if (!L.elem)  printf("错误释放元素空间");
		if (j==OK) printf("OK");
		free(L.elem);
    }
	return 1;
}
