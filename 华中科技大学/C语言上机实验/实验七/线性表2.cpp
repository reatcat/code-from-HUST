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
status DestroyList(SqList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!(L.elem))
	return -1; 
    else{
    free(L.elem);//销毁顺序表
L.elem=NULL;
L.length=0;
L.listsize=0;
return OK;	
	}
 
    /********** End **********/
}

status lex(FILE *fp,char word[])   //仅查找字母型标识符
{
    char c,c1,i;
    while ((c=fgetc(fp))!=EOF && !feof(fp))
    {
        if (isspace(c)) continue;
        if (c=='/')
        {
            c==fgetc(fp);
            if (c==EOF) return ERROR;
            if (c=='/')
            {
                while ((c=fgetc(fp))!='\n') 
                       if (c==EOF) return ERROR;
                continue;
            }
            if (c=='*')
            {
                c=fgetc(fp);
                if (c==EOF) return ERROR;
                do
                {
                    c1=c;
                    c=fgetc(fp);
                    if (c==EOF) return ERROR;
                 } while (c1!='*' || c!='/');
                continue;
            }
        }
        if (!isalpha(c)) continue;
        i=0;
        do {
            	word[i++]=c;
            } while (isalpha(c=fgetc(fp)));
        if (isspace(c)|| !(c>='0' && c<='9') || c==EOF)
        {
            word[i]='\0';
            return OK;
        }
    }
    return ERROR;
}
status match(char fileName[],char keyword[])
{
    FILE *fp;
    char word[50];
    fp=fopen(fileName,"r");
    if (!fp) {printf("文件打开失败"); return FALSE;}
    while (lex(fp,word)==OK){
        if (strcmp(keyword,word))
             continue;
        fclose(fp);
        return TRUE;
    }
    fclose(fp);
    return FALSE;
}

int main()
{
SqList L;
int f,i,j,e;
scanf("%d",&f);
if (f==0)
	{
	    L.elem=NULL;
        j=DestroyList(L);
        if (j==INFEASIBLE) printf("INFEASIBLE");
        else printf("不能对不存在的线性表进行销毁操作！");
	}
else
     { 
        L.elem=(ElemType *) malloc(sizeof(ElemType)*10);
        L.length=0;
        L.listsize= 10;
       
        j=DestroyList(L);
        if (j==OK) 
            if (match("src/step02/stu.h","free")==FALSE || L.elem)
                printf("未正确释放数据元素空间");
            else printf("OK");
        else printf("ERROR");
     }
return 1;
}

