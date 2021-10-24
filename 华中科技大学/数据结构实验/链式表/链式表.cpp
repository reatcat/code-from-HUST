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
typedef int ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct LNode{  //单链表（链式结构）结点的定义
      ElemType data;
      struct LNode *next;
    }LNode,*LinkList;

typedef struct {  //线性表的管理表定义
	struct {
		char name[30];
		LinkList L;
	} elem[10];
	int length;
	int listsize;
}LISTS;
/*-------------线性表操作---------------*/
status InitList(LinkList &L);// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
status DestroyList(LinkList &L);// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
status ClearList(LinkList &L);// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
status ListEmpty(LinkList L);// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
status ListLength(LinkList L);// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
status GetElem(LinkList L,int i,ElemType &e);// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status LocateElem(LinkList L,ElemType e);// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
status PriorElem(LinkList L,ElemType e,ElemType &pre);// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status NextElem(LinkList L,ElemType e,ElemType &next);// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status ListInsert(LinkList &L,int i,ElemType e);// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status ListDelete(LinkList &L,int i,ElemType &e);// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status ListTraverse(LinkList L);// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
status SaveList(LinkList L,char FileName[]);// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
status LoadList(LinkList &L,char FileName[]);// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
/*-------------线性表操作---------------*/

/*-------------线性表集合操作---------------*/
status InitInput(LinkList &L);
status AddList(LISTS& Lists, char ListName[]);// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据由后台测试程序插入。
status RemoveList(LISTS& Lists, char ListName[]);// Lists中删除一个名称为ListName的线性表
status LocateList(LISTS Lists, char ListName[]);// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
status SaveEdit(LISTS& Lists, LinkList L, char ListName[]);//更新管理系统中的线性表
status EditList(LISTS Lists, LinkList& L, char ListName[]);
status ListGet(LISTS Ls,int i);//遍历指定线性表 
status TraverseLists(LISTS Lists);//遍历所有线性表 
/*-------------线性表集合操作---------------*/
int main(){  
int op=1; 
LinkList L;//链式线性表的定义L
L=NULL;
int e,i,j;
char filename[100];
char Listname[30]; 
LISTS Ls;
Ls.length=0,Ls.listsize=10;
while(op){
	system("cls");	printf("\n\n");
	printf("                        基于顺序存储的链式表操作菜单\n");
	printf("--------------------------------------------------------------------------\n");
	printf("    	  1. 初始化链表       7. 查找元素            13. 保存链表                   19. 将集合中的线性表载入\n");
	printf("    	  2. 摧毁链表         8. 查找前驱元素        14. 读取链表      	            20. 遍历集合中的线性表\n");
	printf("    	  3. 清空链表         9. 查找后继元素        15. 链表集合操作               21. 将线性表存储到集合中\n");
	printf("    	  4. 链表判空         10. 插入元素           16. 删除集合中的线性表         0. 退出\n");
	printf("    	  5. 链表表长         11. 删除元素           17. 定位集合中的线性表\n");
	printf("    	  6. 由位置求元素     12. 遍历链表           18. 遍历集合\n");
	printf("--------------------------------------------------------------------------\n");
	printf("    请选择你的操作[0~15]:");
	scanf("%d",&op);
    switch(op){
	case 1:
		if((j=InitList(L))==OK) printf("线性表创建成功！\n"); 
		else if(j==-1)printf("线性表已创建！\n");
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
		j=ClearList(L);
		if(j == INFEASIBLE) printf("当前线性表不存在！\n");
		else printf("清除成功！\n");   
		getchar();getchar();
		break;
	case 4:
		j=ListEmpty(L);
		if(j == INFEASIBLE) printf("当前线性表不存在！\n");
		else if(j) printf("当前线性表为空\n");
		else printf("当前线性表不为空\n");
		getchar();getchar();
		break;
	case 5:
		j=ListLength(L); 
		if(j == INFEASIBLE) printf("当前线性表不存在！\n");
		else printf("当前线性表长度为%d\n",j);
		getchar();getchar();
		break;
	case 6:
		printf("查找第几位元素？\n");
	   	scanf("%d",&i);
		j = GetElem(L,i,e);
		if(j == INFEASIBLE) printf("当前线性表不存在！\n");
		else if(j == ERROR) printf("查找位置不合法！\n");
		else printf("当前线性表中第%d个元素为%d\n", i, e);
		getchar();getchar();
		break;
	case 7:
		printf("请输入要查找的元素：\n");
		scanf("%d",&e);
		j=LocateElem(L,e);
		if(j==-1) printf("当前线性表不存在！\n");
		else if(j==0) printf("未找到该元素！\n");
		else printf("元素%d位于线性表中第%d个位置\n", e, j);    
	 	getchar();getchar();
		break;
	case 8:
		int cur,pre;
		printf("输入当前元素\n");
	   	scanf("%d", &cur);
		j=PriorElem(L,cur,pre);   
		if(j==-1) printf("当前线性表不存在！\n");
		else if(j==0) printf("该元素无前驱！\n");
		else printf("元素%d的前驱是%d\n",cur,pre);  
		getchar();getchar();
		break;
	case 9:
		int next;
		printf("输入当前元素\n");
	   	scanf("%d", &cur);
		j=NextElem(L,cur,next);   
		if(j==-1) printf("当前线性表不存在！\n");
		else if(j==0) printf("该元素无后继！\n");
		else printf("元素%d的后继是%d\n",cur,next);       
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
		 	ListTraverse(L);
		}
		getchar();getchar();
		break;
	case 11:
		printf("输入想删除的元素位置\n");
		scanf("%d", &i);
		j = ListDelete(L, i, e);
		if(j == ERROR) printf("删除位置非法！\n");
		else if(j == INFEASIBLE) printf("当前线性表不存在！\n");
		else
		{
			printf("%d已删除成功！\n",e);
		 	ListTraverse(L);
		}   
		getchar();getchar();
		break;
	case 12:
		if(ListTraverse(L)==-1) printf("当前线性表不存在！\n");
		getchar();getchar();
		break;
	case 13:
		printf("输入文件名:\n");
		scanf("%s",filename); 
		if((j=SaveList(L,filename))!=-1)printf("保存到文件成功\n");
		getchar();getchar();
		break;
	case 14:	
		printf("输入文件名:\n");
		scanf("%s",filename);
		if((j=LoadList(L,filename))!=-1)printf("从文件读取成功 \n");
		getchar();getchar();
	   	break;
	case 15:
		//新建管理系统中线性表
		printf("请输入新增线性表的名称:");
		scanf("%s", Listname);
		if (AddList(Ls, Listname) == ERROR) {
			int choice;
			printf("线性表名称已存在,是否继续?(1:是,0:否)\n");
			scanf("%d", &choice);
			if (choice) {
				RemoveList(Ls, Listname);
				AddList(Ls, Listname);
				printf("线性表\"%s\"存储成功！\n", Listname);
			}
		}
		else printf("线性表\"%s\"存储成功！\n", Listname);
		getchar(); getchar();
		break;
	case 16:
		//删除管理系统中线性表
		printf("请输入待删除线性表名称:");
		scanf("%s", Listname);
		if (RemoveList(Ls, Listname) == FALSE) printf("该线性表不存在\n");
		else printf("删除成功!\n");
		getchar(); getchar();
		break;
	case 17:
		//查询管理系统中线性表
		printf("请输入要定位的表名:\n");
		scanf("%s", Listname);
		if ((j = LocateList(Ls, Listname)) == 0) printf("该线性表不存在\n");
		else printf("该线性表的次序为%d\n", j);
		getchar(); getchar();
		break;
	case 18:
		if(TraverseLists(Ls)==-1)printf("线性表集合为空\n"); 
		getchar();getchar();
		break;
	case 19:
		//编辑管理系统中线性表
		printf("请输入待编辑线性表名称:");
		scanf("%s", Listname);
		EditList(Ls, L, Listname);
		getchar(); getchar();
		break;
	case 20:
	 	int i;
		printf("请输入想要遍历的线性表序号：");
		scanf("%d",&i);
		if(ListGet(Ls,i)==-1)printf("序号不正确\n");
	 	getchar();getchar();
	 	break;
	case 21:
		//更新管理系统线性表
		printf("请输入待更新的线性表名称:");
		scanf("%s", Listname);
		SaveEdit(Ls, L, Listname);
		getchar(); getchar();
		break;
	case 0:
    break;
	}//end of switch
  }//end of while
printf("欢迎下次再使用本系统！\n");
}//end of main()
status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L!=NULL)return INFEASIBLE;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    return OK;
    /********** End **********/
}
status InitInput(LinkList &L)
// 线性表不存在，返回INFEASIBLE；如果线性表为空表，输入数据；如果线性表不为空，返回ERROR 
{
	{
		ElemType temp = 0;
		printf("请输入一组数据(0结束):\n");
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
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE;
    LinkList q=L,p;
    while(p) //把链表中除头结点外的所有结点释放 
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
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
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
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE;
    if(L->next==NULL)return TRUE;
    else return FALSE;
    /********** End **********/
}
int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
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
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
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
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
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
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
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
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
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
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
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
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
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
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE; 
    printf("当前线性表中数据如下:\n");
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
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    if(L==NULL){printf("未初始化线性表\n");return INFEASIBLE;}
    FILE *fp;
    fp=fopen(FileName,"w");
    if(fp==NULL){
	printf("文件打开失败\n");
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
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    LinkList p;
    if(L!=NULL){printf("线性表已存在\n");return INFEASIBLE;}
    FILE *fp;
    L=(LinkList)malloc(sizeof(LNode));
    p=L;
    fp=fopen(FileName,"r");
    if(fp==NULL){printf("文件打开失败\n");return INFEASIBLE;}
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
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据由后台测试程序插入。
{
	int k = LocateList(Lists, ListName);
	if (k)
		return ERROR;//该名称已存在 
	strcpy(Lists.elem[Lists.length].name, ListName);
	Lists.elem[Lists.length].L = NULL;
	InitList(Lists.elem[Lists.length].L);
	InitInput(Lists.elem[Lists.length].L);
	Lists.length++;
	return OK;
}
status RemoveList(LISTS& Lists, char ListName[])
// Lists中删除一个名称为ListName的线性表
{
	int i;
	for (i = 0; i < Lists.length; i++) {
		if (!strcmp(Lists.elem[i].name, ListName))  break;
	}
	if (i == Lists.length) return FALSE;//未找到
	DestroyList(Lists.elem[i].L);
	for (; i < Lists.length - 1; i++) {//移动管理系统中的元素
		Lists.elem[i] = Lists.elem[i + 1];
	}
	Lists.length--;//管理系统中线性表个数减一
	return OK;
}
status LocateList(LISTS Lists, char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
	int i;
	for (i = 0; i < Lists.length; i++) {
		if (!strcmp(Lists.elem[i].name, ListName))  break;
	}
	if (i == Lists.length) return 0;//未找到
	return i + 1;//逻辑序号为下标+1
}
status SaveEdit(LISTS& Lists, LinkList L, char ListName[]) 
{
//更新管理系统中的线性表
	int k = LocateList(Lists, ListName);
	if (!k) {
		printf("未找到文件名为%s的线性表\n", ListName);
		return ERROR;
	}
	if(L==NULL){printf("当前线性表不存在\n");return ERROR;}

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
	printf("%s更新成功！", ListName);
	return OK;
}
status EditList(LISTS Lists, LinkList& L, char ListName[]) {
	//将管理表中名称为ListName的线性表加载到L
	if (!ListEmpty(L)) {//当前编辑区线性表非空
		int choice;
		printf("现在线性表非空,继续操作可能会丢失数据，是否继续？(1:是,0:否):\n");
		scanf("%d", &choice);
		if (!choice) return ERROR;
		else DestroyList(L);
	}
	int k = LocateList(Lists, ListName);
	if (!k) {
		printf("\n未找到文件名为%s的线性表\n", ListName);
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
	printf("\n现在可对%s进行编辑,记得使用保存编辑\n", ListName);
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
		printf("当前线性表集合中共包含以下%d个线性表：\n", Ls.length);
		for(int i=0;i<Ls.length;i++)
		{
			printf("%s\n",Ls.elem[i].name);
			ListTraverse(Ls.elem[i].L);
		}
	}
	return OK;
}

