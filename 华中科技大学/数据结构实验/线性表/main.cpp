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
#define FAIL -3//预定义常量

typedef int status;//函数状态结果标志
typedef int ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100//线性表存储结构的最大分配量
#define LISTINCREMENT  10//线性表的分配增量
typedef struct{  //顺序表（顺序结构）的定义
	ElemType * elem;//抽象数据元素
	int length;//表长
	int listsize;//存储容量
}SqList;

typedef struct{  //线性表的管理表定义
     struct { char name[30];
     		  SqList L;
      } elem[10];
      int length;
      int listsize;
 }LISTS;

status InitList(SqList& L);    //线性表初始化
status InitInput(SqList &L);   //线性表输入数据
status DestroyList(SqList& L); //销毁线性表
status ClearList(SqList&L);    //清空线性表
status ListEmpty(SqList L);    //线性表判空 return status
int ListLength(SqList L);      //求表长 return int
status GetElem(SqList L,int i,ElemType& e);             //获取指定位置 i 处元素 e
status LocateElem(SqList L,ElemType e);                 //由元素内容e 查找元素位置return status
status PriorElem(SqList L,ElemType cur,ElemType &pre_e);//由当前元素内容cur 获取其前驱元素pre_e
status NextElem(SqList L,ElemType cur,ElemType &next_e);//由当前元素内容cur 获取其后继元素next_e
status ListInsert(SqList&L,int i,ElemType e);           //向线性表指定位置 i 前插入元素e
status ListDelete(SqList&L,int i,ElemType& e);          //删除位置 i 处元素存入 e 中
status ListTrabverse(SqList L);                 //遍历当前线性表
status SaveList(SqList L,char FileName[]);      //当前线性表存档
status LoadList(SqList &L,char FileName[]);     //当前线性表读档
status InitLists(LISTS &Lists);                 //线性表集合初始化
status AddList(LISTS &Lists, char ListName[]);  //向集合中添加名为 ListsName 的线性表
status RemoveList(LISTS &Lists,char ListName[]);//删除集合中名为  ListsName 的线性表
int LocateList(LISTS Lists,char ListName[]);    //在当前集合中查找名为 ListsName 的线性表
status ListsTraverse(LISTS Lists);              //遍历当前集合
status SaveLists(LISTS Lists, char *FileName); //线性表集合存档
status LoadLists(LISTS &Lists, char *FileName); //线性表集合读档  （有问题）
status ChangeList(SqList &L);                   //修改集合中指定线性表
status EditList(LISTS Lists,SqList &L);
status SaveEdit(LISTS& Lists, SqList L) ;
 char* SaveFile = "D:\\数据结构实验\\文件.dat";
 char* LoadFile = "D:\\数据结构实验\\文件.dat";
 char* SaveFile1 = "D:\\数据结构实验\\文件.dat";
 char* LoadFile1 = "D:\\数据结构实验\\文件.dat";

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
	printf("                        基于顺序存储的线性表操作菜单\n");
	printf("--------------------------------------------------------------------------\n");
	printf("    	  1. 初始化线性表       7. 查找元素            13. 保存线性表         19. 将集合中的线性表载入\n");
	printf("    	  2. 摧毁线性表         8. 查找前驱元素        14. 读取线性表         20. 删除集合中线性表\n");
	printf("    	  3. 清空线性表         9. 查找后继元素        15. 初始化线性表集合   21. 将线性表存储到集合中\n");
	printf("    	  4. 线性表判空         10. 插入元素           16. 新增集合中的线性表 0. 退出\n");
	printf("    	  5. 线性表表长         11. 删除元素           17. 查找集合中的线性表\n");
	printf("    	  6. 由位置求元素       12. 遍历线性表         18. 遍历线性表集合\n");
	printf("--------------------------------------------------------------------------\n");
	if(op)
	printf("    请选择你的操作[0~21]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
		 if(InitList(L)==OK)
		 {
		 	printf("线性表创建成功！\n");
		 }
		 else printf("线性表创建失败！\n");
		 getchar();getchar();
		 break;
	   case 2:
		 j = DestroyList(L);
		 if(j == INFEASIBLE) printf("当前线性表不存在！\n");
		 else printf("销毁成功！\n");
		 getchar();getchar();
		 break;
	   case 3:
		 j = ClearList(L);
		 if(j == INFEASIBLE) printf("当前线性表不存在！\n");
		 else printf("清空成功！\n");
		 getchar();getchar();
		 break;
	   case 4:
		 j = ListEmpty(L);
		 if(j == INFEASIBLE) printf("当前线性表不存在\n");
		 else if(j) printf("当前线性表为空\n");
		 else printf("当前线性表不为空\n");
		 getchar();getchar();
		 break;
	   case 5:j = ListLength(L);
		 if(j == INFEASIBLE) printf("当前线性表不存在！\n");
		 else printf("当前线性表长度为%d\n",j);
		 getchar();getchar();
		 break;
	   case 6:
	   	if(L.elem==NULL)
		{
		   	printf("当前线性表不存在！\n");
		 	getchar();getchar();
		 	break;
		}
	   	 int i, e;
	   	 printf("查找第几位元素？\n");
	   	 scanf("%d",&i);
		 j = GetElem(L, i, e);
		 if(j == ERROR) printf("查找位置不合法！\n");
		 else printf("当前线性表中第%d个元素为%d\n", i, e);
		 getchar();getchar();
		 break;
	   case 7:
		 printf("输入所需查找的元素内容\n");
		 scanf("%d", &e);
		 j = LocateElem(L, e);
		 if(j == ERROR) printf("表中不存在元素 %d\n",e);
		 else if(j == INFEASIBLE) printf("当前线性表为不存在！\n");
		 else printf("元素%d位于线性表中第%d个位置\n", e, j);
		 getchar();getchar();
		 break;
	   case 8:
	   	 int prior;
	   	 printf("输入当前元素\n");
	   	 scanf("%d", &e);
	   	 j = PriorElem(L, e, prior);
	   	 if(j == ERROR) printf("此元素无前驱！\n");
	   	 else if(j == INFEASIBLE) printf("当前线性表不存在！\n");
	   	 else printf("当前元素前驱为%d\n", prior);
		 getchar();getchar();
		 break;
	   case 9:
	   	 int next;
	   	 printf("输入当前元素\n");
	   	 scanf("%d", &e);
	   	 j = NextElem(L, e, next);
	   	 if(j == ERROR) printf("此元素无后继！\n");
	   	 else if(j == INFEASIBLE) printf("当前线性表不存在！\n");
	   	 else printf("当前元素后继为%d\n", next);
		 getchar();getchar();
		 break;
	   case 10:
	   	 printf("输入加入元素\n");
	   	 scanf("%d", &e);
	   	 printf("想插入第几个元素前？\n");
		 scanf("%d", &i);
		 j = ListInsert(L, i, e);
		 if(j == ERROR) printf("插入位置非法！\n");
		 else if(j == INFEASIBLE) printf("当前线性表不存在！\n");
		 else
		 {
		 	printf("插入成功！\n");
		 	if(!ListTrabverse(L))
			printf("当前线性表不存在！\n");
		 }
		 getchar();getchar();
		 break;
	   case 11:
	   	 printf("删除第几个元素？\n");
	   	 scanf("%d",&i);
	   	 j = ListDelete(L, i, e);
		 if(j == INFEASIBLE) printf("当前线性表不存在！\n");
		 else if(j == ERROR) printf("删除位置非法！\n");
		 else
		 {
		 	printf("删除成功！\n");
		 	if(!ListTrabverse(L))
			printf("当前线性表不存在！\n");
		 }
		 getchar();getchar();
		 break;
	   case 12:
		 if(ListTrabverse(L) == INFEASIBLE) printf("当前线性表不存在！\n");
		 getchar();getchar();
		 break;
	   case 13:
	   	if(SaveList(L, SaveFile) == INFEASIBLE) printf("当前线性表不存在！\n");
	   	else printf("已将数据存入 %s\n",SaveFile);
		 getchar();getchar();
		 break;
	   case 14:
	   	 if((j = LoadList(L, LoadFile)) == ERROR) printf("当前线性表中已有数据！\n");
	   	 else if(j == OK) printf("数据已从 %s 中读出\n",LoadFile);
	   	 else if(j == INFEASIBLE) printf("当前线性表不存在！请先初始化！\n");
	   	 else if(j == FAIL) printf("存档文件建立失败！\n");
		 getchar();getchar();
		 break;
	   case 15:
				if(InitLists(Lists) == INFEASIBLE) printf("当前线性表集合已被初始化！\n");
				else printf("初始化成功！\n");
		 		getchar();getchar();
				break;
	   case 16:
		 		if(Lists.elem[0].L.elem == NULL)
		 		{
		 			printf("当前线性表集合不存在，请先初始化！\n");
		 			getchar();getchar();
		 			break;
				}
				char ListName[30];
		 		printf("请输入新增线性表的名称：\n");
		 		scanf("%s",ListName);
	   	 		if(AddList(Lists, ListName) == OVERFLOW) printf("线性表集合已满，添加失败！\n");
	   	 		else printf("线性表\"%s\"存储成功！\n", ListName);
		 		getchar();getchar();
				break;
	   case 20:
		 		if(Lists.elem[0].L.elem == NULL)
		 		{
		 			printf("当前线性表集合不存在，请先初始化！\n");
		 			getchar();getchar();
		 			break;
				}
				printf("请输入所要删除的线性表名称：\n");
	   			scanf("%s",&ListName);
	   			if(RemoveList(Lists, ListName))
	   	 		{
	   		 		printf("线性表%s删除成功！\n",ListName);
		 		}
		 		else
		 		{
		 	 		printf("查无此表！\n");
		 		}
		 		getchar();getchar();
		 		break;
	   case 17:
		 		if(Lists.elem[0].L.elem == NULL)
		 		{
		 			printf("当前线性表集合不存在，请先初始化！\n");
		 			getchar();getchar();
		 			break;
				}
		 		printf("请输入要定位的表名:\n");
		 		scanf("%s",ListName);
		 		j = LocateList(Lists, ListName);
		 		if(j == 0)
		 		{
		 			printf("查无此表！\n");
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
	   	 		if((j = ListsTraverse(Lists)) == 0) printf("当前线性表集合为空！\n");
	   	 		else if(j == INFEASIBLE) printf("当前线性表集合不存在！\n");
		 		getchar();getchar();
		 		break;
		case 19:
		 		if(Lists.elem[0].L.elem == NULL)
		 		{
		 			printf("当前线性表集合不存在，请先初始化！\n");
		 			getchar();getchar();
		 			break;
				}
		 		EditList(Lists,L);
		 		getchar();getchar();
		 		break;
		 		case 21:
		 		if(Lists.elem[0].L.elem == NULL)
		 		{
		 			printf("当前线性表集合不存在，请先初始化！\n");
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
printf("欢迎下次再使用本系统！\n");
return 0;
}//end of main()
status SaveEdit(LISTS& Lists, SqList L) 
{
//更新管理系统中的线性表
	char ListName[30];
	printf("请输入载入的线性表名称");
	scanf("%s",ListName); 
	int k=LocateList(Lists,ListName);
	if(!k)
	{
		printf("未找到该线性表");
		return ERROR; 
	}
	if(L.elem==NULL){printf("当前线性表不存在\n");return ERROR;}
	Lists.elem[k - 1].L=L;
	printf("%s更新成功！", ListName);
	return OK;
}
status EditList(LISTS Lists,SqList &L)
{
	char ListName[30];
	printf("请输入载入的线性表名称");
	scanf("%s",ListName); 
	int k=LocateList(Lists,ListName);
	if(!k)
	{
		printf("未找到该线性表");
		return ERROR; 
	}
	InitList(L);
	L=(Lists.elem[k-1].L);
	printf("线性表载入成功"); 
	return OK;
}
status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
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
	printf("输入数据按1，否则按0\n");
	scanf("%d",&ord);
	if(ord == 0)
	{
		return 0;
	}
	else
	{
		printf("请输入一组数据，0为结束标志\n");
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
		printf("输入成功！\n");
		return OK;
	}
}

status DestroyList(SqList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
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
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
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
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
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
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回OK；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
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
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
	if(!L.elem)
	{
		return INFEASIBLE;
	}
	else
	{
		printf("当前线性表中数据如下:\n");
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
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
	FILE  *fp;
	if(L.elem==NULL)
	{
		printf("未初始化线性表！\n");
		return -1;
	}
	if ((fp=fopen(filename,"wb"))==NULL)
	{
		printf("File open error\n ");
		return -1;
	}
	fwrite(L.elem,sizeof(ElemType),L.length,fp);
	//这里是1次性写入，对于其它物理结构，可通过遍历，逐个访问数据元素
	//并写入到文件中。也可以先写入表长，再写入全部元素，这样读入会更方便
	fclose(fp);
	return OK;
}
status LoadList(SqList &L,char filename[])
// 如果线性表L为非空，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
	FILE  *fp;
	if(L.elem==NULL)
	{
		InitList(L);
	}
	if(L.length)
	{
		printf("线性表不为空！\n");
		return -1;
	}
	if ((fp=fopen(filename,"rb"))==NULL)
	{
		printf("File open error\n ");
	 	return -1;
	}
	while(fread(&L.elem[L.length],sizeof(ElemType),1,fp))
	L.length++;
	//这里从文件中逐个读取数据元素恢复顺序表，对于不同的物理结构，可通过读//取的数据元素恢复内存中的物理结构。
	fclose(fp);
	return OK;
}
status InitLists(LISTS &Lists)
//线性表集合初始化
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
// 在Lists中增加一个名称为ListName的空线性表后输入线性表数据
{
	if(Lists.length == Lists.listsize) //集合溢出判断
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
// Lists中删除一个名称为ListName的线性表
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
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
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
//遍历线性表集合，如果集合为空返回0，否则将集合中线性表的全部数据输出，并返回OK
{

	if(Lists.elem[0].L.elem == NULL)
	{
		return INFEASIBLE;
	}
	if(Lists.length == 0)
	{
		return 0;
	}
	printf("当前线性表集合中共包含以下%d个线性表：\n", Lists.length);
	for(int i = 0; i < Lists.length; i++)
	{
		printf("%s\n",Lists.elem[i].name);
		if(Lists.elem[i].L.length == 0)
		{
			printf("空\n");
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
//将集合中数据存入文件 FileName 中，若线性表集合为空或不存在时，返回INFEASIBLE,否则返回OK
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
