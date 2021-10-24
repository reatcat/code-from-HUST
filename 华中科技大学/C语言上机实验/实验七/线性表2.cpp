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
status DestroyList(SqList& L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(!(L.elem))
	return -1; 
    else{
    free(L.elem);//����˳���
L.elem=NULL;
L.length=0;
L.listsize=0;
return OK;	
	}
 
    /********** End **********/
}

status lex(FILE *fp,char word[])   //��������ĸ�ͱ�ʶ��
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
    if (!fp) {printf("�ļ���ʧ��"); return FALSE;}
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
        else printf("���ܶԲ����ڵ����Ա�������ٲ�����");
	}
else
     { 
        L.elem=(ElemType *) malloc(sizeof(ElemType)*10);
        L.length=0;
        L.listsize= 10;
       
        j=DestroyList(L);
        if (j==OK) 
            if (match("src/step02/stu.h","free")==FALSE || L.elem)
                printf("δ��ȷ�ͷ�����Ԫ�ؿռ�");
            else printf("OK");
        else printf("ERROR");
     }
return 1;
}

