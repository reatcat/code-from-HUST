#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include <conio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LEFT 4
#define RIGHT 6
#define max(a,b) ((a>b)?a:b)

//用于按层遍历中definition扩容 
#define INIT_DEF_SIZE 64
#define INCREMENT 16

//用于森林扩容
#define INIT_SIZE 100 

typedef int status;
typedef int KeyType; 
typedef struct {
    KeyType  key;
	char others[20];
} TElemType; //二叉树结点类型定义


typedef struct BiTNode{  //二叉链表结点的定义
	TElemType  data;
	struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

typedef struct {
    int pos;
    TElemType data;
} DEF;

typedef struct {   //二叉树的结点definition，包含pos以及pos对应的结点地址，仅用于按层遍历 
    int pos;
    BiTNode *node;
} def;

typedef struct { //森林中每棵树的定义 
	BiTree T;
	char name[30];
} Tree, *pTree;

typedef struct {  //森林定义(线性表结构存储) 
	pTree *tree;
	int length;
	int size;
} FOREST, *FST;
status InitBiTree(BiTree &T);
status CreateBiTree(BiTree &T,DEF definition[]);
status CreateBiTree(BiTree &T,TElemType definition[]);
/*根据先序遍历序列definition创建二叉树 T，definition中如有重复则返回ERROR，否则返回OK*/ 
int  BiTreeEmpty(BiTree T);//二叉树判空 
status ClearBiTree(BiTree &T); //将二叉树设置成空，并删除所有结点，释放结点空间
bool IsRepeat(TElemType definition[]);   //判断先序序列definition中是否有重复key值，用于创建树 
int BiTreeDepth(BiTree T);   //求二叉树T的深度
BiTNode* LocateNode(BiTree T,KeyType e); //查找结点
status Assign(BiTree &T,KeyType e,TElemType value); //实现结点赋值。
BiTNode* GetSibling(BiTree T,KeyType e); //实现获得兄弟结点
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c); //实现插入节点，在e的LR(左右)孩子处插入c
status ParentNode(BiTree T, KeyType e, BiTree &p); 
/*寻找key值为e元素的双亲结点，由参数p带出函数，返回OK表示删除结点为根节点，
返回LEFT表示e为p的左孩子，返回RIGHT表示e为p的右孩子，返回ERROR表示没有此结点*/ 
BiTNode* RightMostNode(BiTree T); //寻找 T 最右端结点，用于删除
status DeleteNode(BiTree &T,KeyType e); //删除结点。
status PreOrderTraverse(BiTree T,void (*visit)(BiTree)); //先序遍历二叉树T(递归)
status InOrderTraverse(BiTree T,void (*visit)(BiTree)); //先序遍历二叉树T(非递归)
status PostOrderTraverse(BiTree T,void (*visit)(BiTree)); //后序遍历二叉树T(递归)
def* CreateDef(BiTree T, int &length); //按照结点位置构造二叉树的definition 
void DefOrder(def *definition, int length); //按结点位置对definition排序
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree)); //按层遍历二叉树T
//status SaveBiTree(BiTree T,  FILE *fp);
status SaveBiTree(BiTree T,FILE *fp,int i);
status LoadBiTree(BiTree &T, char FileName[]); //读档 
status TreeLikeTraverse(BiTree T, void (*visit)(BiTree)); //树形遍历，输出树的图形表示 
void visit(BiTree T);
BiTree* gather_operate(FST& fst);
//森林操作 
status InitForest(FST& fst)
//初始化森林(以线性表形式定义) 
{
	if(fst != NULL) return INFEASIBLE;
	fst = (FST)malloc(sizeof(FOREST));
	fst->tree = (pTree*)malloc(INIT_SIZE * sizeof(pTree));
	fst->length = 0;
	fst->size = INIT_SIZE;
	return OK;
}

status AddBiTree(const FST fst, int i, char BiTreeName[])
//向森林中第i位种入名为BiTreeName的树 
{
	if(fst == NULL) return INFEASIBLE;
	
	if(i > fst->length + 1 || i < 1) return ERROR;
	
	if(fst->length >= fst->size) //扩容 
	{
		fst->size += INCREMENT;
		fst->tree = (pTree*)realloc(fst->tree, fst->size * sizeof(pTree));
	}
	
	for(int j = fst->length; j >= i; j--) //移位置 
	{
		fst->tree[j] = fst->tree[j - 1];
	}
	
	fst->tree[i - 1] = (pTree)malloc(sizeof(Tree));
	strcpy(fst->tree[i - 1]->name, BiTreeName); //树命名 && 树初始化 
	fst->tree[i - 1]->T = NULL;
	InitBiTree(fst->tree[i - 1]->T);
	fst->length++;
	return OK;
}

status RemoveBiTree(const FST fst, char BiTreeName[])
//砍去森林中名为BiTreeName的树 
{
	if(fst == NULL) return INFEASIBLE;
	for(int i = 0; i < fst->length; i++)
	{
		if(!strcmp(BiTreeName, fst->tree[i]->name))
		{
			ClearBiTree(fst->tree[i]->T);
			free(fst->tree[i]);
			
			for(int a = i + 1; a < fst->length; a++)
			fst->tree[a - 1] = fst->tree[a];
			
			fst->length--;
			return OK;
		}
	}
	return ERROR;
}

int LocateBiTree(const FST fst, char BiTreeName[])
//查找当前森林中名为BiTreeName的树 
{
	if(fst == NULL) return INFEASIBLE;
	for(int i = 0; i < fst->length; i++)
	{
		if(!strcmp(BiTreeName, fst->tree[i]->name)) return i + 1;
	}
	return ERROR;
}

status ForestTraverse(const FST fst)
//遍历森林 
{
	if(fst == NULL) return INFEASIBLE;
	if(fst->length == 0) return ERROR;
	int op = 1;
	status (*p)(BiTree, void (*)(BiTree)) = NULL;
	while(op)
	{
		printf("            遍历方式选择\n");
		printf("             1.前序遍历\n");
		printf("             2.中序遍历\n");
		printf("             3.后序遍历\n");
		printf("             4.按层遍历\n");
		printf("  请输入您所选择遍历方式的相应序号[1-4]:");
		scanf("%d", &op);
		switch(op)
		{
			case 1: p = PreOrderTraverse;   break;
			case 2: p = InOrderTraverse;    break;
			case 3: p = PostOrderTraverse;  break;
			case 4: p = LevelOrderTraverse; break;
			default: printf("输错\n"); 
			op = 6; _getch(); break;
		}
		if(op != 6) op = 0;
	}
	
	printf("当前树中数据如下所示：\n");
	for(int i = 0; i < fst->length; i++)
	{
		printf("第%d棵树：\n %s:\n", i + 1, fst->tree[i]->name);
		p(fst->tree[i]->T->lchild, visit);
		printf("\n\n");
	}
	return OK;
}

status ClearForest(const FST fst)
{
	if(fst == NULL) return INFEASIBLE;
	for(int i = 0; i < fst->length; i++)
	{
		ClearBiTree(fst->tree[i]->T);  //ClearBiTree函数：参数为T时为销毁，参数为T->lchild时清空 
		free(fst->tree[i]);
		fst->tree[i] = NULL;
	}
	fst->length = 0;
	return OK;
}

status DestroyForest(FST &fst)
{
	if(fst == NULL) return INFEASIBLE;
	ClearForest(fst);
	fst = NULL;
	return OK;
}

//森林操作 






//bool IsRepeat(TElemType definition[])
////判断先序序列definition中是否有重复key值，用于创建树
//{
//	int a = 0, b = 0;
//	for(int i = 0; (a = definition[i].key) != -1; i++)
//	{
//		for(int j = i + 1; (b = (definition[j].key)) != -1; j++)
//		{
//			if(a == b && a != 0)
//			{
//				return true;
//			}
//		}
//	}
//	return false;
//}

status InitBiTree(BiTree &T)
{
	if(T != NULL) return INFEASIBLE;
	T = (BiTree)malloc(sizeof(BiTNode));
	T->lchild = NULL;
	T->rchild = NULL;
	return OK;
}

status CreateBiTree(BiTree &T,DEF definition[])
{
    int i=0,j;
    static BiTNode *p[100];
    while (j=definition[i].pos)
    {
	 p[j]=(BiTNode *)malloc(sizeof(BiTNode));
       p[j]->data=definition[i].data;
       p[j]->lchild=NULL;
       p[j]->rchild=NULL;
       if (j!=1)
       		if (j%2)   p[j/2]->rchild=p[j];
       	   else      p[j/2]->lchild=p[j];
       i++;
    }
    T=p[1];
    return OK;
}
//
//status CreateBiTree(BiTree &T,TElemType definition[])
////根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
////如果有相同的关键字，返回ERROR。
//{
//    static int i = 0, flag = 0;//i为递归变量，遍历definition；flag控制IsRepeat函数只被调用一次；over处理二叉树结束标志-1 
//    if(flag == 0 && (flag = 1) && IsRepeat(definition)) //判断是否有重复，并由于IsRepeat只需运行一次，通过flag使其成为一次性。 
//    {
//    	return ERROR;
//	}
//	T = (BiTree)malloc(sizeof(BiTNode));    //先对当前结点分配空间
//	//printf("In CreateBiTree, definition[%d].key = %d\n", i, definition[i].key);
//    if(definition[i].key == 0)     //对于 0,null，直接回溯，将分配的空间free，T置NULL，definition后移 
//    {
//    	free(T);
//    	T = NULL;
//    	i++;
//    	if(definition[i].key == -1)
//    	{
//    		i = 0;   //函数结束，全局变量应恢复原状 
//    		flag = 0;
//		}
//    	return OK;
//	}
//	else               //数据进树 
//	{
//    	T->data.key = definition[i].key;
//    	strcpy(T->data.others,definition[i].others);
//	}
//    i++;           //definition后移 
//	CreateBiTree(T->lchild, definition);
//	CreateBiTree(T->rchild, definition);
//}


status ClearBiTree(BiTree &T)
//将二叉树设置成空，并删除所有结点，释放结点空间
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T == NULL)
    {
    	return OK;
	}
	ClearBiTree(T->lchild);
	ClearBiTree(T->rchild);
	if(T->lchild == NULL && T->rchild == NULL)
	{
		free(T);
		T = NULL;
		return OK;
	}
    /********** End **********/
}

int BiTreeDepth(BiTree T)
//求二叉树T的深度
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T == NULL)
    {
    	return 0;
	}
	int LeftLen = 1 + BiTreeDepth(T->lchild);
	int RightLen = 1 + BiTreeDepth(T->rchild);
	return max(LeftLen, RightLen);
}

BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
{
	static BiTNode *p = NULL;
	if(p != NULL && p->data.key != e) p = NULL;
	//在别处多次调用(非递归)时，防止上一次使用遗留下来的p未被置NULL而导致之后使用故障 

	if(p != NULL) return p;
	//p不为NULL时，表明已找到目标节点，直接回溯即可
		
	if(T == NULL) 	return p;
	//当前T为空时，直接回溯即可 
	
	if(e == T->data.key)//当找到目标节点，将目标节点地址传至p，返回即可 
	{
		p = T;
		return p;
	}
	LocateNode(T->lchild,e);
	LocateNode(T->rchild,e);
}

status Assign(BiTree &T,KeyType e,TElemType value)
//实现结点赋值。
{
    BiTNode *p = LocateNode(T, value.key);
	//p记录树中key值为value.key的结点地址用于保证赋值后的树中无key值重复项 
	BiTNode *q = LocateNode(T, e);
	//q记录结点编号为e的结点地址以查重以及赋值 
	if(!q || (p && q && p != q))  //所有错误状况 
	//q为空，代表树中无编号为e结点，不可赋值；p!=q且p,q均不为空，说明赋值后会有key值重复 
    {
    	return ERROR;
	}
	else
	{
		q->data.key = value.key;
		strcpy(q->data.others, value.others);
		return OK;
	}
    /********** End **********/
}
int  BiTreeEmpty(BiTree T)
{
	if(T->lchild==NULL&&T->rchild==NULL)
	return TRUE;
	else return ERROR;
}
BiTNode* GetSibling(BiTree T,KeyType e)
//实现获得兄弟结点
{
	BiTNode *rec = NULL;        //记录返回值
	if(T == NULL)           //当前树为空时，返回空值，表明找不到，直接回溯 
	{
		return NULL;
	}
	if(T->lchild != NULL && T->lchild->data.key == e) return T->rchild;     //当前结点左儿子为所找结点时，返回当前结点右儿子 
	else if(T->rchild != NULL && T->rchild->data.key == e) return T->lchild;//当前结点左儿子为所找结点时，返回当前结点右儿子
	else   //不满足以上两种，继续深入搜索 
	{
		if(rec = GetSibling(T->lchild, e)) return rec;     //如果左边找到了，返回其返回值 
		else if(rec = GetSibling(T->rchild, e)) return rec;//如果右边找到了，返回其返回值 
		else return NULL;     //都没有，返回NULL 
	}
}

status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//实现插入节点，在e的LR(左右)孩子处插入c 
{
	BiTNode *aim = LocateNode(T, e);   //查找e所在结点 
	BiTNode *repeat = LocateNode(T, c.key);  //判断即将插入的结点key值在原树中是否已存在 
	if(aim == NULL || repeat != NULL) return ERROR;  //当未找到 key=e 的结点或者将插入的结点key值在原树中已存在
	else
	{
		BiTNode *NewNode = (BiTNode*)malloc(sizeof(BiTNode));
		NewNode->data.key = c.key;
		strcpy(NewNode->data.others, c.others);   //新建结点，存储新结点值 
		if(LR == 0) //左插 
		{
			NewNode->rchild = aim->lchild;
			NewNode->lchild = NULL;
			aim->lchild = NewNode;
			return OK;
		}
		else if(LR == 1) //右插 
		{
			NewNode->rchild = aim->rchild;
			NewNode->lchild = NULL;
			aim->rchild = NewNode;
			return OK;
		}
		else if(LR == -1) //头插 
		{
			NewNode->rchild = T;
			NewNode->lchild = NULL;
			T = NewNode;
			return OK;
		}
		else return ERROR;
	}
}

status ParentNode(BiTree T, KeyType e, BiTree &p)
/*寻找key值为e元素的双亲结点，由参数p带出函数，返回OK表示删除结点为根节点，
返回LEFT表示e为p的左孩子，返回RIGHT表示e为p的右孩子，返回ERROR表示没有此结点*/ 
{
	status state = ERROR;
	if(T == NULL) return ERROR;
	if(T->data.key == e) {p = T; return OK;}
	else if(T->lchild && T->lchild->data.key == e) {p = T; return LEFT;}
	else if(T->rchild && T->rchild->data.key == e) {p = T; return RIGHT;}
	state = ParentNode(T->lchild, e, p);
	if(state) return state;
	return ParentNode(T->rchild, e, p);
}

BiTNode* RightMostNode(BiTree T)
//寻找 T 最右端结点 
{
	while(T->rchild != NULL) T = T->rchild;
	return T;
}

status DeleteNode(BiTree &T,KeyType e)
//删除结点。
{
	BiTNode *p = NULL, *del = NULL;
	status state = ParentNode(T, e, p);
	if(state == OK) //根节点为所要删除的结点
	{
		if(p->lchild == NULL)//根结点没有左孩子 
		{
			T = T->rchild;
			free(p);
			return OK;
		}
		else if(p->rchild == NULL)//根结点没有右孩子 
		{
			T = T->lchild;
			free(p);
			return OK;
		}
		else  //根结点度为二 
		{
			T = T->lchild;
			RightMostNode(T)->rchild = p->rchild;//根节点左孩子的最右置为根节点右孩子 
			free(p);
			return OK;
		}
	}
	else if(state == LEFT)            //待删除结点为p的左孩子时 
	{
		del = p->lchild;              //记录待删除结点 
		if(del->lchild != NULL)//如果要删除的结点有左孩子
		{
			RightMostNode(del->lchild)->rchild = del->rchild; //要删除的结点的右孩子移至要删除的结点的左孩子的最右结点的右子树处 
			p->lchild = del->lchild;
		}
		else p->lchild = del->rchild; 
		free(del);
		return OK;
	}
	else if(state == RIGHT)           //待删除结点为p的右孩子时
	{
		del = p->rchild;              //记录待删除结点 
		if(del->lchild != NULL)       //待删除结点有左孩子 
		{
			RightMostNode(del->lchild)->rchild = del->rchild;//要删除的结点的右孩子移至要删除的结点的左孩子的最右结点的右子树处
			p->rchild = del->lchild; 
		}
		else p->rchild = del->rchild;//待删除结点没有左孩子 
		free(del);
		return OK;
	}
	else return ERROR;      //未查找到待删除结点 
}

status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//先序遍历二叉树T(非递归)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T == NULL) {
    	printf("空"); 
    	return OK;
	}
    BiTree st[20],p;//用栈实现
    int top=0;//置空栈；
    if(T){
        st[top++]=T;
        while(top){
            p=st[--top];
            visit(p);
            if(p->rchild)
            st[top++]=p->rchild;
            if(p->lchild)
            st[top++]=p->lchild;
        }
    }
    return OK;
    /********** End **********/
}
status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//中序遍历二叉树T（递归实现）
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
if (T)
    {
        
        InOrderTraverse(T->lchild,visit);
        visit(T);
        InOrderTraverse(T->rchild,visit);
    return OK;
    }
else return OK;
    /********** End **********/
}
status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//后序遍历二叉树T
{
    if(T == NULL) return OK;
    PostOrderTraverse(T->lchild, visit);
	PostOrderTraverse(T->rchild, visit);
    visit(T);
	return OK;
}

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
static int l=0,r=1;
static BiTree trees[200];//建立数组来持续遍历
if(l||r!=1||trees)
{
	l=0;
	r=1;
	trees[200]=NULL;
}
trees[0]=T;//从根节点开始，不用考虑右子树
for(l=0;l<r;l++)
{
    visit(trees[l]);
    if(trees[l]->lchild)//所遍历的该层该节点有左子树，在下一层前面遍历
    {
        trees[r++]=trees[l]->lchild;
    }
    if(trees[l]->rchild)//有右子树
    {
        trees[r++]=trees[l]->rchild;
    }
}
return OK;
    /********** End **********/
}

status SaveBiTree(BiTree T,FILE *fp,int i) 
{//以满二叉树的形式进行存储
    if(T==NULL) return OK;
	fprintf(fp,"%d %d %s ",i,T->data.key,T->data.others);
    SaveBiTree(T->lchild,fp,i*2);
    SaveBiTree(T->rchild,fp,i*2+1);
	
}

status LoadBiTree(BiTree &T, char FileName[])
{
    FILE *fp = fopen(FileName, "r");
    if(fp == NULL) return ERROR;
    int i = 0;
    int number = 0;
    DEF definition[100];
    while(fscanf(fp,"%d",&definition[i].pos)!=EOF&&fscanf(fp,"%d",&definition[i].data.key)!=EOF&&fscanf(fp,"%s",&definition[i].data.others)!=EOF) 
	{
	i++;
	}
	
	CreateBiTree(T,definition);
	fclose(fp);
    return OK;
}
void visit(BiTree T)
{
    printf(" %d,%s",T->data.key,T->data.others);
}

BiTree* gather_operate(FST& fst)
//森林操作 
{
	int op = 1; int j = 0;
	char BiTreeName[30];
	while(op)
	{
		system("cls");	printf("\n\n");
		printf("             森林操作菜单\n");
		printf("--------------------------------------------\n");
		printf("    	 1. 初始化       6. 修改\n");
		printf("    	 2.  新增        7. 遍历\n");
		printf("    	 3.  删除        8. 销毁\n");
		printf("    	 4.  查找        0. 退出\n");
		printf("         5.  清空\n");
		printf("--------------------------------------------\n");
		printf("    请选择你的操作[0~6]:");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
				if(InitForest(fst) == INFEASIBLE) printf("当前森林已被初始化！\n");
				else printf("初始化成功！\n");
	   	 		printf("----任意键继续----\n");
		 		_getch();
				break;
			case 2:
		 		if(fst == NULL) printf("当前森林不存在，请先初始化！\n");
		 		else
		 		{
					char BiTreeName[30];
					int pos = 0;
		 			printf("请输入新增树的名称：\n");
		 			scanf("%s",BiTreeName);
		 			printf("请输入新树种在几号位？\n");
		 			scanf("%d", &pos);
	   	 			if(AddBiTree(fst, pos, BiTreeName) == ERROR) printf("种树位置不合法！第%d位之前仍有空位！\n");
	   	 			else printf("树\"%s\"成功种进森林了！\n", BiTreeName);
				}
	   	 		printf("----任意键继续----\n");
		 		_getch();
				break;
			case 3:
		 		if(fst == NULL) printf("当前森林不存在，请先初始化！\n");
		 		else if(fst->length == 0) printf("当前森林里没有树！\n");
		 		else
		 		{
					printf("请输入想砍掉的树的名称：\n");
	   				scanf("%s",BiTreeName);
	   				if(RemoveBiTree(fst, BiTreeName)) printf("树\"%s\"成功被砍没了！\n",BiTreeName);
		 			else printf("查无此树！\n");
				}
		 		printf("----任意键继续----\n");
		 		_getch();
		 		break;
		 	case 4:
		 		if(fst == NULL) printf("当前森林不存在，请先初始化！\n");
		 		else
		 		{
		 			printf("请输入所要查找的树的名称：\n");
	   		 		scanf("%s",BiTreeName);
	   	 			if(j = LocateBiTree(fst, BiTreeName)) printf("树%s位于森林中第%d位\n", BiTreeName, j);
		 			else printf("查无此树！\n");
				}
		 		printf("----任意键继续----\n");
		 		_getch();
		 		break;
		 	case 5:
//		 		if(ClearForest(fst) == INFEASIBLE) printf("当前森林不存在，请先初始化！\n");
//		 		else printf("清空成功！森林空了！\n");
				if(fst == NULL) printf("当前森林不存在，请先初始化！\n");
		 		else
		 		{
		 			printf("请输入所要清空的树的名称：\n");
	   		 		scanf("%s",BiTreeName);
	   	 			if(j = LocateBiTree(fst, BiTreeName))
	   	 			ClearBiTree(fst->tree[j-1]->T->lchild); 
	   	 			printf("清空成功\n"); 
				}
		 		printf("----任意键继续----\n");
		 		_getch();
		 		break;
		 	case 6:
			    if(fst == NULL)
				{
					printf("当前森林不存在，请先初始化！\n");
					printf("----任意键继续----\n");
		 			_getch();
		 			break;
				}
			    else
			    {
		 			printf("请输入所需更改的树的名称:\n");
		 			scanf("%s",BiTreeName);
		 			j = LocateBiTree(fst, BiTreeName);
		 			if(j == 0)
		 			{
		 				printf("查无此树！\n");
	   	 		 		printf("----任意键继续----\n");
		 				_getch();
		 				break;
					}
					else
					{
						int ord = 0;
						printf("是否要修改树的名字?(是.1 / 否.0)：");
						scanf("%d", &ord);
						if(ord)
						{
							printf("输入新名字：");
							scanf("%s", fst->tree[j - 1]->name);
							printf("修改成功！\n");
							printf("继续修改数据吗？(是.1 / 否.0):");
							scanf("%d", &ord);
							if(!ord) break;
						}
						return &(fst->tree[j - 1]->T);
					}
				}
		 	case 7:
	   	 		if((j = ForestTraverse(fst)) == 0) printf("当前森林一棵树也没有！\n");
	   	 		else if(j == INFEASIBLE) printf("当前森林不存在！\n");
				printf("----任意键继续----\n");
		 		_getch();
		 		break;
		 	case 8:
		 		if(DestroyForest(fst) == INFEASIBLE) printf("啧..你还是不记得初始化！\n");
		 		else printf("销毁成功！森林没了！\n");
		 		printf("----任意键继续----\n");
		 		_getch();
		 		break;
		 	case 0:
		 		break;
		 	default:
		 		printf("指令错误！\n");
	   	 		printf("----任意键继续----\n");
		 		_getch();
		 		break;
		}
	}
	return NULL;
}


int main(){
BiTree T = NULL; //树  
FST fst = NULL;  //森林 
int op = 1;    //操作指令 
int flag = 0;  //森林操作完成标志 
DEF definition[100]; //输入树中的数据载体 
int e = 0;   //键值载体 
BiTNode *node = NULL; //结点载体
BiTree *T_ope = NULL, temp = NULL;//森林操作树的载体 
TElemType value;    //结点数据载体 
int LR;   //插入节点：定左右 
while(op){
	system("cls");	printf("\n\n");
	printf("                         基于二叉链表的二叉树操作菜单\n");
	printf("-----------------------------------------------------------------------\n");
	printf("    	  1. 初始化树       8. 获得兄弟结点     15. 二叉树判空\n");
	printf("    	  2. 初始化输入     9. 插入节点         16. 存档\n");
	printf("    	  3. 摧毁树        10. 删除结点         17. 读档\n");
	printf("    	  4. 清空树        11. 前序遍历         18. 森林管理\n");
	printf("    	  5. 树的深度      12. 中序遍历          0. 退出/载入到森林\n");
	printf("    	  6. 结点查找      13. 后序遍历\n");
	printf("          7. 结点赋值      14. 按层遍历\n");
	printf("-----------------------------------------------------------------------\n");
	if(op)
	printf("    请选择你的操作[0~18]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
	   	 if(InitBiTree(T) == OK) printf("初始化成功！\n");
	   	 else printf("当前的树里已经有点东西了~\n");
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 2:
	   	 if(T == NULL) printf("请先初始化！\n");
	   	 else if(T->lchild != NULL) printf("当前的树非空\n");
	   	 else{
	   	 	int i=0;
	   	 		printf("输入数据：(格式：满二叉树中的位置序号+键值+数据)，位置序号为0时结束\n");
		 		do {
					scanf("%d%d%s",&definition[i].pos,&definition[i].data.key,definition[i].data.others);
		 		} while (definition[i++].pos);
		 		CreateBiTree(T->lchild,definition);
		 		printf("输入成功！\n");
			}
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 3:
	   	 if(T == NULL) printf("请先初始化！\n");
	   	 else{
	   	 	ClearBiTree(T);
		 	printf("销毁成功！\n");
		 }
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 4:
	   	 if(T == NULL) printf("请先初始化！\n");
	   	 else if(flag==0){
	   	 	ClearBiTree(T->lchild);
		 	printf("清空成功！\n");
		 }
		 else if(flag)
		 printf("在当前页面不支持树的删除功能，请在森林中完成\n"); 
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 5:
	   	 if(T == NULL) printf("树不存在\n");
	     else printf("当前树的深度为%d\n", BiTreeDepth(T->lchild));
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 6:
	   	 if(T == NULL) printf("请先初始化！\n");
	   	 else{
	   	 	printf("输入键值：");
	   	 	scanf("%d", &e);
	   	 	node = LocateNode(T->lchild, e);
	   	 	if(node == NULL) printf("当前树里面没有key值为%d的结点\n", e);
	   	 	else printf("当前结点键值为:%d, 数据为:%s\n", node->data.key, node->data.others);
			}
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 7:
	   	if(T == NULL) printf("当前树不存在！\n");
	   	else{
		    printf("输入所要修改的结点键值：");
	   	 	scanf("%d", &e);
	   	 	node = LocateNode(T->lchild, e);
	   	 	if(node == NULL) printf("当前树里面没有key值为%d的结点\n", e);
	   	 	else
	   	 	{
	   	 		printf("请输入输入更改后的结点键值：");
	   	 		scanf("%d", &value.key);
	   	 		printf("请输入更改后的数据：");
	   	 		scanf("%s", value.others);
	   	 		if(Assign(T->lchild, e, value) == ERROR)
					printf("更改键值出错！因为原树中已存在其他结点的键值为%d！\n", value.key);
	   	 		else printf("更改成功！\n");
			}
		   }
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 8:
	   	 if(T == NULL) printf("请先初始化！\n");
	   	 else
	   	 {
	   	 	printf("输入当前键值：");
	   	 	scanf("%d", &e);
	   	 	node = LocateNode(T->lchild, e);
	   	 	if(node == NULL) printf("当前树里面没有key值为%d的结点\n", e);
	   	 	else
	   	 	{
	   	 		node = GetSibling(T->lchild, e);
	   	 		if(node == NULL) printf("这个结点没有兄弟~\n");
	   	 		else printf("这个结点的兄弟结点的键值为：%d, 数据为：%s\n", node->data.key, node->data.others);
			}
		 }
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 9:
	   	 if(T == NULL) printf("请先初始化！\n"); 
	   	 else
	   	 {
	   	 	printf("输入相应添加孩子结点键值\n");
	   	 	scanf("%d", &e);
	   	 	node = LocateNode(T->lchild, e);
	   	 	if(node == NULL) printf("当前树里面没有key值为%d的结点\n", e);
	   	 	else{
	   	 		printf("想添个左孩子还是右孩子？(左孩子输0，右孩子输1，当祖先输-1)\n");
	   	 		scanf("%d", &LR);
	   	 		printf("输入新增结点键值：");
	   	 		scanf("%d", &value.key);
	   	 		printf("输入新增结点数据：");
	   	 		scanf("%s", value.others);
	   	 		if(InsertNode(T->lchild, e, LR, value) == ERROR) printf("新增键值出错！因为原树中已存在其他结点的键值为%d！\n", value.key);
	   	 		else printf("插入节点成功！\n");
			}
		 }
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 10:
	   	 if(T == NULL) printf("请先初始化！\n");
	   	 else{
	   	 	printf("输入待删除结点的键值：");
			scanf("%d", &e);
			if(DeleteNode(T, e) == ERROR) printf("当前树里面没有key值为%d的结点\n", e);
			else printf("删除成功！\n");
		 }
		 	printf("----任意键继续----\n");
		 	_getch();
		 	break;
	   case 11:
	   	 if(T == NULL) printf("先请先初始化！\n");
	   	 else
		 {
			printf("前序遍历当前树中结点信息如下：\n");
			PreOrderTraverse(T->lchild, visit);
			printf("\n");
		 }
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 12:
	   	 if(T == NULL) printf("请先初始化！\n");
	   	 else
		 {
			printf("中序遍历当前树中结点信息如下：\n");
			InOrderTraverse(T->lchild, visit);
			printf("\n");	
		 }
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 13:
	   	 if(T == NULL) printf("请先初始化！\n");
	   	 else
		 {
			printf("后序遍历当前树中结点信息如下：\n");
			PostOrderTraverse(T->lchild, visit);
			printf("\n");	
		 }
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 14:
	   	 if(T == NULL) printf("请先初始化！\n");
	   	 else
		 {
			printf("按层遍历当前树中结点信息如下：\n");
			LevelOrderTraverse(T->lchild, visit);
			printf("\n");
		 }
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	  case 15:
	   	 if(T == NULL) printf("树不存在\n");
	   	 else
	   	 {
	   	 	BiTreeEmpty(T);
	   	 	printf("清空成功"); 
	   	 	printf("\n");
		 }
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 16:
	   	 if(T == NULL) printf("您还未初始化！\n");
	   	 else{
		 	char SaveFile[40];
		 	printf("输入存档文件路径(输入0选择默认路径):\n");
		 	scanf("%s",SaveFile);
		 	if(!strcmp(SaveFile,"0")) strcpy(SaveFile, "D:\\数据结构实验\\文件.dat");
		 	FILE *fp = fopen(SaveFile, "w");
	   	 	SaveBiTree(T->lchild,fp,1);
	   	 	fclose(fp);
	   	 	printf("已将数据存入 %s\n",SaveFile);
			}
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 17:
	   	 if(T == NULL) printf("树不存在树不存在树不存在！\n");
		 else if(T->lchild != NULL) printf("当前这颗树非空！\n");
		 else
		 {
	   	 	char LoadFile[40];
	   	 	printf("输入读档文件路径(输入0选择默认路径):\n");
		 	scanf("%s",LoadFile);
		 	if(!strcmp(LoadFile,"0")) strcpy(LoadFile, "D:\\数据结构实验\\文件.dat");
	   	 	if(LoadBiTree(T->lchild, LoadFile) == ERROR) printf("存档文件%s无法打开！\n", LoadFile);
	   	 	else printf("数据已从 %s 中读出\n",LoadFile);
		 }
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	   case 18:
	   	 if(flag == 1)            //修改状态，不可再次选择线性表集合操作 
		{
			printf("当前有未结束的线性表修改，请先结束前一修改！\n"); 
		 	printf("----任意键继续----\n");
		 	_getch();
			break;
		}
	   	 T_ope = gather_operate(fst);//采用指向指针的指针，方便进行读取 
	   	 if(T_ope != NULL)//只要选择了集合操作中的修改，就将主界面线性表置换成集合中所选线性表 
	   	 {
	   	 	temp = T;             //temp暂存主界面线性表数据
	   	 	T = *T_ope;            //主界面后台线性表置换为集合内所选线性表
	   	 	flag = 1;             //系统状态置为集合操作态
		 }
		 break;
	   case 0:
         break; 
		 printf("----任意键继续----\n");
		 _getch();
		 break;
	}//end of switch
	if(flag && op == 0)     //flag判断当前是否在线性表集合操作中，此时退出返回主界面
	{
		T = temp;           //返还原始主界面线性表数据
		op = 1;             //保持不退出while
		flag = 0;           //状态置为初始界面
		printf("原主界面的树中数据已载入！\n");
		_getch();
	}
  }//end of while
printf("欢迎下次再使用本系统！\n");
printf("----任意键结束----\n");
_getch(); 
return 0;
}//end of main()

