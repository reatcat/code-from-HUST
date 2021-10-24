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

//���ڰ��������definition���� 
#define INIT_DEF_SIZE 64
#define INCREMENT 16

//����ɭ������
#define INIT_SIZE 100 

typedef int status;
typedef int KeyType; 
typedef struct {
    KeyType  key;
	char others[20];
} TElemType; //������������Ͷ���


typedef struct BiTNode{  //����������Ķ���
	TElemType  data;
	struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

typedef struct {
    int pos;
    TElemType data;
} DEF;

typedef struct {   //�������Ľ��definition������pos�Լ�pos��Ӧ�Ľ���ַ�������ڰ������ 
    int pos;
    BiTNode *node;
} def;

typedef struct { //ɭ����ÿ�����Ķ��� 
	BiTree T;
	char name[30];
} Tree, *pTree;

typedef struct {  //ɭ�ֶ���(���Ա�ṹ�洢) 
	pTree *tree;
	int length;
	int size;
} FOREST, *FST;
status InitBiTree(BiTree &T);
status CreateBiTree(BiTree &T,DEF definition[]);
status CreateBiTree(BiTree &T,TElemType definition[]);
/*���������������definition���������� T��definition�������ظ��򷵻�ERROR�����򷵻�OK*/ 
int  BiTreeEmpty(BiTree T);//�������п� 
status ClearBiTree(BiTree &T); //�����������óɿգ���ɾ�����н�㣬�ͷŽ��ռ�
bool IsRepeat(TElemType definition[]);   //�ж���������definition���Ƿ����ظ�keyֵ�����ڴ����� 
int BiTreeDepth(BiTree T);   //�������T�����
BiTNode* LocateNode(BiTree T,KeyType e); //���ҽ��
status Assign(BiTree &T,KeyType e,TElemType value); //ʵ�ֽ�㸳ֵ��
BiTNode* GetSibling(BiTree T,KeyType e); //ʵ�ֻ���ֵܽ��
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c); //ʵ�ֲ���ڵ㣬��e��LR(����)���Ӵ�����c
status ParentNode(BiTree T, KeyType e, BiTree &p); 
/*Ѱ��keyֵΪeԪ�ص�˫�׽�㣬�ɲ���p��������������OK��ʾɾ�����Ϊ���ڵ㣬
����LEFT��ʾeΪp�����ӣ�����RIGHT��ʾeΪp���Һ��ӣ�����ERROR��ʾû�д˽��*/ 
BiTNode* RightMostNode(BiTree T); //Ѱ�� T ���Ҷ˽�㣬����ɾ��
status DeleteNode(BiTree &T,KeyType e); //ɾ����㡣
status PreOrderTraverse(BiTree T,void (*visit)(BiTree)); //�������������T(�ݹ�)
status InOrderTraverse(BiTree T,void (*visit)(BiTree)); //�������������T(�ǵݹ�)
status PostOrderTraverse(BiTree T,void (*visit)(BiTree)); //�������������T(�ݹ�)
def* CreateDef(BiTree T, int &length); //���ս��λ�ù����������definition 
void DefOrder(def *definition, int length); //�����λ�ö�definition����
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree)); //�������������T
//status SaveBiTree(BiTree T,  FILE *fp);
status SaveBiTree(BiTree T,FILE *fp,int i);
status LoadBiTree(BiTree &T, char FileName[]); //���� 
status TreeLikeTraverse(BiTree T, void (*visit)(BiTree)); //���α������������ͼ�α�ʾ 
void visit(BiTree T);
BiTree* gather_operate(FST& fst);
//ɭ�ֲ��� 
status InitForest(FST& fst)
//��ʼ��ɭ��(�����Ա���ʽ����) 
{
	if(fst != NULL) return INFEASIBLE;
	fst = (FST)malloc(sizeof(FOREST));
	fst->tree = (pTree*)malloc(INIT_SIZE * sizeof(pTree));
	fst->length = 0;
	fst->size = INIT_SIZE;
	return OK;
}

status AddBiTree(const FST fst, int i, char BiTreeName[])
//��ɭ���е�iλ������ΪBiTreeName���� 
{
	if(fst == NULL) return INFEASIBLE;
	
	if(i > fst->length + 1 || i < 1) return ERROR;
	
	if(fst->length >= fst->size) //���� 
	{
		fst->size += INCREMENT;
		fst->tree = (pTree*)realloc(fst->tree, fst->size * sizeof(pTree));
	}
	
	for(int j = fst->length; j >= i; j--) //��λ�� 
	{
		fst->tree[j] = fst->tree[j - 1];
	}
	
	fst->tree[i - 1] = (pTree)malloc(sizeof(Tree));
	strcpy(fst->tree[i - 1]->name, BiTreeName); //������ && ����ʼ�� 
	fst->tree[i - 1]->T = NULL;
	InitBiTree(fst->tree[i - 1]->T);
	fst->length++;
	return OK;
}

status RemoveBiTree(const FST fst, char BiTreeName[])
//��ȥɭ������ΪBiTreeName���� 
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
//���ҵ�ǰɭ������ΪBiTreeName���� 
{
	if(fst == NULL) return INFEASIBLE;
	for(int i = 0; i < fst->length; i++)
	{
		if(!strcmp(BiTreeName, fst->tree[i]->name)) return i + 1;
	}
	return ERROR;
}

status ForestTraverse(const FST fst)
//����ɭ�� 
{
	if(fst == NULL) return INFEASIBLE;
	if(fst->length == 0) return ERROR;
	int op = 1;
	status (*p)(BiTree, void (*)(BiTree)) = NULL;
	while(op)
	{
		printf("            ������ʽѡ��\n");
		printf("             1.ǰ�����\n");
		printf("             2.�������\n");
		printf("             3.�������\n");
		printf("             4.�������\n");
		printf("  ����������ѡ�������ʽ����Ӧ���[1-4]:");
		scanf("%d", &op);
		switch(op)
		{
			case 1: p = PreOrderTraverse;   break;
			case 2: p = InOrderTraverse;    break;
			case 3: p = PostOrderTraverse;  break;
			case 4: p = LevelOrderTraverse; break;
			default: printf("���\n"); 
			op = 6; _getch(); break;
		}
		if(op != 6) op = 0;
	}
	
	printf("��ǰ��������������ʾ��\n");
	for(int i = 0; i < fst->length; i++)
	{
		printf("��%d������\n %s:\n", i + 1, fst->tree[i]->name);
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
		ClearBiTree(fst->tree[i]->T);  //ClearBiTree����������ΪTʱΪ���٣�����ΪT->lchildʱ��� 
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

//ɭ�ֲ��� 






//bool IsRepeat(TElemType definition[])
////�ж���������definition���Ƿ����ظ�keyֵ�����ڴ�����
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
////���ݴ���֦�Ķ������ȸ���������definition����һ�ö������������ڵ�ָ�븳ֵ��T������OK��
////�������ͬ�Ĺؼ��֣�����ERROR��
//{
//    static int i = 0, flag = 0;//iΪ�ݹ����������definition��flag����IsRepeat����ֻ������һ�Σ�over���������������־-1 
//    if(flag == 0 && (flag = 1) && IsRepeat(definition)) //�ж��Ƿ����ظ���������IsRepeatֻ������һ�Σ�ͨ��flagʹ���Ϊһ���ԡ� 
//    {
//    	return ERROR;
//	}
//	T = (BiTree)malloc(sizeof(BiTNode));    //�ȶԵ�ǰ������ռ�
//	//printf("In CreateBiTree, definition[%d].key = %d\n", i, definition[i].key);
//    if(definition[i].key == 0)     //���� 0,null��ֱ�ӻ��ݣ�������Ŀռ�free��T��NULL��definition���� 
//    {
//    	free(T);
//    	T = NULL;
//    	i++;
//    	if(definition[i].key == -1)
//    	{
//    		i = 0;   //����������ȫ�ֱ���Ӧ�ָ�ԭ״ 
//    		flag = 0;
//		}
//    	return OK;
//	}
//	else               //���ݽ��� 
//	{
//    	T->data.key = definition[i].key;
//    	strcpy(T->data.others,definition[i].others);
//	}
//    i++;           //definition���� 
//	CreateBiTree(T->lchild, definition);
//	CreateBiTree(T->rchild, definition);
//}


status ClearBiTree(BiTree &T)
//�����������óɿգ���ɾ�����н�㣬�ͷŽ��ռ�
{
    // �������ﲹ����룬��ɱ�������
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
//�������T�����
{
    // �������ﲹ����룬��ɱ�������
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
//���ҽ��
{
	static BiTNode *p = NULL;
	if(p != NULL && p->data.key != e) p = NULL;
	//�ڱ𴦶�ε���(�ǵݹ�)ʱ����ֹ��һ��ʹ������������pδ����NULL������֮��ʹ�ù��� 

	if(p != NULL) return p;
	//p��ΪNULLʱ���������ҵ�Ŀ��ڵ㣬ֱ�ӻ��ݼ���
		
	if(T == NULL) 	return p;
	//��ǰTΪ��ʱ��ֱ�ӻ��ݼ��� 
	
	if(e == T->data.key)//���ҵ�Ŀ��ڵ㣬��Ŀ��ڵ��ַ����p�����ؼ��� 
	{
		p = T;
		return p;
	}
	LocateNode(T->lchild,e);
	LocateNode(T->rchild,e);
}

status Assign(BiTree &T,KeyType e,TElemType value)
//ʵ�ֽ�㸳ֵ��
{
    BiTNode *p = LocateNode(T, value.key);
	//p��¼����keyֵΪvalue.key�Ľ���ַ���ڱ�֤��ֵ���������keyֵ�ظ��� 
	BiTNode *q = LocateNode(T, e);
	//q��¼�����Ϊe�Ľ���ַ�Բ����Լ���ֵ 
	if(!q || (p && q && p != q))  //���д���״�� 
	//qΪ�գ����������ޱ��Ϊe��㣬���ɸ�ֵ��p!=q��p,q����Ϊ�գ�˵����ֵ�����keyֵ�ظ� 
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
//ʵ�ֻ���ֵܽ��
{
	BiTNode *rec = NULL;        //��¼����ֵ
	if(T == NULL)           //��ǰ��Ϊ��ʱ�����ؿ�ֵ�������Ҳ�����ֱ�ӻ��� 
	{
		return NULL;
	}
	if(T->lchild != NULL && T->lchild->data.key == e) return T->rchild;     //��ǰ��������Ϊ���ҽ��ʱ�����ص�ǰ����Ҷ��� 
	else if(T->rchild != NULL && T->rchild->data.key == e) return T->lchild;//��ǰ��������Ϊ���ҽ��ʱ�����ص�ǰ����Ҷ���
	else   //�������������֣������������� 
	{
		if(rec = GetSibling(T->lchild, e)) return rec;     //�������ҵ��ˣ������䷵��ֵ 
		else if(rec = GetSibling(T->rchild, e)) return rec;//����ұ��ҵ��ˣ������䷵��ֵ 
		else return NULL;     //��û�У�����NULL 
	}
}

status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//ʵ�ֲ���ڵ㣬��e��LR(����)���Ӵ�����c 
{
	BiTNode *aim = LocateNode(T, e);   //����e���ڽ�� 
	BiTNode *repeat = LocateNode(T, c.key);  //�жϼ�������Ľ��keyֵ��ԭ�����Ƿ��Ѵ��� 
	if(aim == NULL || repeat != NULL) return ERROR;  //��δ�ҵ� key=e �Ľ����߽�����Ľ��keyֵ��ԭ�����Ѵ���
	else
	{
		BiTNode *NewNode = (BiTNode*)malloc(sizeof(BiTNode));
		NewNode->data.key = c.key;
		strcpy(NewNode->data.others, c.others);   //�½���㣬�洢�½��ֵ 
		if(LR == 0) //��� 
		{
			NewNode->rchild = aim->lchild;
			NewNode->lchild = NULL;
			aim->lchild = NewNode;
			return OK;
		}
		else if(LR == 1) //�Ҳ� 
		{
			NewNode->rchild = aim->rchild;
			NewNode->lchild = NULL;
			aim->rchild = NewNode;
			return OK;
		}
		else if(LR == -1) //ͷ�� 
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
/*Ѱ��keyֵΪeԪ�ص�˫�׽�㣬�ɲ���p��������������OK��ʾɾ�����Ϊ���ڵ㣬
����LEFT��ʾeΪp�����ӣ�����RIGHT��ʾeΪp���Һ��ӣ�����ERROR��ʾû�д˽��*/ 
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
//Ѱ�� T ���Ҷ˽�� 
{
	while(T->rchild != NULL) T = T->rchild;
	return T;
}

status DeleteNode(BiTree &T,KeyType e)
//ɾ����㡣
{
	BiTNode *p = NULL, *del = NULL;
	status state = ParentNode(T, e, p);
	if(state == OK) //���ڵ�Ϊ��Ҫɾ���Ľ��
	{
		if(p->lchild == NULL)//�����û������ 
		{
			T = T->rchild;
			free(p);
			return OK;
		}
		else if(p->rchild == NULL)//�����û���Һ��� 
		{
			T = T->lchild;
			free(p);
			return OK;
		}
		else  //������Ϊ�� 
		{
			T = T->lchild;
			RightMostNode(T)->rchild = p->rchild;//���ڵ����ӵ�������Ϊ���ڵ��Һ��� 
			free(p);
			return OK;
		}
	}
	else if(state == LEFT)            //��ɾ�����Ϊp������ʱ 
	{
		del = p->lchild;              //��¼��ɾ����� 
		if(del->lchild != NULL)//���Ҫɾ���Ľ��������
		{
			RightMostNode(del->lchild)->rchild = del->rchild; //Ҫɾ���Ľ����Һ�������Ҫɾ���Ľ������ӵ����ҽ����������� 
			p->lchild = del->lchild;
		}
		else p->lchild = del->rchild; 
		free(del);
		return OK;
	}
	else if(state == RIGHT)           //��ɾ�����Ϊp���Һ���ʱ
	{
		del = p->rchild;              //��¼��ɾ����� 
		if(del->lchild != NULL)       //��ɾ����������� 
		{
			RightMostNode(del->lchild)->rchild = del->rchild;//Ҫɾ���Ľ����Һ�������Ҫɾ���Ľ������ӵ����ҽ�����������
			p->rchild = del->lchild; 
		}
		else p->rchild = del->rchild;//��ɾ�����û������ 
		free(del);
		return OK;
	}
	else return ERROR;      //δ���ҵ���ɾ����� 
}

status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T(�ǵݹ�)
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(T == NULL) {
    	printf("��"); 
    	return OK;
	}
    BiTree st[20],p;//��ջʵ��
    int top=0;//�ÿ�ջ��
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
//�������������T���ݹ�ʵ�֣�
{
    // �������ﲹ����룬��ɱ�������
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
//�������������T
{
    if(T == NULL) return OK;
    PostOrderTraverse(T->lchild, visit);
	PostOrderTraverse(T->rchild, visit);
    visit(T);
	return OK;
}

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
static int l=0,r=1;
static BiTree trees[200];//������������������
if(l||r!=1||trees)
{
	l=0;
	r=1;
	trees[200]=NULL;
}
trees[0]=T;//�Ӹ��ڵ㿪ʼ�����ÿ���������
for(l=0;l<r;l++)
{
    visit(trees[l]);
    if(trees[l]->lchild)//�������ĸò�ýڵ���������������һ��ǰ�����
    {
        trees[r++]=trees[l]->lchild;
    }
    if(trees[l]->rchild)//��������
    {
        trees[r++]=trees[l]->rchild;
    }
}
return OK;
    /********** End **********/
}

status SaveBiTree(BiTree T,FILE *fp,int i) 
{//��������������ʽ���д洢
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
//ɭ�ֲ��� 
{
	int op = 1; int j = 0;
	char BiTreeName[30];
	while(op)
	{
		system("cls");	printf("\n\n");
		printf("             ɭ�ֲ����˵�\n");
		printf("--------------------------------------------\n");
		printf("    	 1. ��ʼ��       6. �޸�\n");
		printf("    	 2.  ����        7. ����\n");
		printf("    	 3.  ɾ��        8. ����\n");
		printf("    	 4.  ����        0. �˳�\n");
		printf("         5.  ���\n");
		printf("--------------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~6]:");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
				if(InitForest(fst) == INFEASIBLE) printf("��ǰɭ���ѱ���ʼ����\n");
				else printf("��ʼ���ɹ���\n");
	   	 		printf("----���������----\n");
		 		_getch();
				break;
			case 2:
		 		if(fst == NULL) printf("��ǰɭ�ֲ����ڣ����ȳ�ʼ����\n");
		 		else
		 		{
					char BiTreeName[30];
					int pos = 0;
		 			printf("�����������������ƣ�\n");
		 			scanf("%s",BiTreeName);
		 			printf("�������������ڼ���λ��\n");
		 			scanf("%d", &pos);
	   	 			if(AddBiTree(fst, pos, BiTreeName) == ERROR) printf("����λ�ò��Ϸ�����%dλ֮ǰ���п�λ��\n");
	   	 			else printf("��\"%s\"�ɹ��ֽ�ɭ���ˣ�\n", BiTreeName);
				}
	   	 		printf("----���������----\n");
		 		_getch();
				break;
			case 3:
		 		if(fst == NULL) printf("��ǰɭ�ֲ����ڣ����ȳ�ʼ����\n");
		 		else if(fst->length == 0) printf("��ǰɭ����û������\n");
		 		else
		 		{
					printf("�������뿳�����������ƣ�\n");
	   				scanf("%s",BiTreeName);
	   				if(RemoveBiTree(fst, BiTreeName)) printf("��\"%s\"�ɹ�����û�ˣ�\n",BiTreeName);
		 			else printf("���޴�����\n");
				}
		 		printf("----���������----\n");
		 		_getch();
		 		break;
		 	case 4:
		 		if(fst == NULL) printf("��ǰɭ�ֲ����ڣ����ȳ�ʼ����\n");
		 		else
		 		{
		 			printf("��������Ҫ���ҵ��������ƣ�\n");
	   		 		scanf("%s",BiTreeName);
	   	 			if(j = LocateBiTree(fst, BiTreeName)) printf("��%sλ��ɭ���е�%dλ\n", BiTreeName, j);
		 			else printf("���޴�����\n");
				}
		 		printf("----���������----\n");
		 		_getch();
		 		break;
		 	case 5:
//		 		if(ClearForest(fst) == INFEASIBLE) printf("��ǰɭ�ֲ����ڣ����ȳ�ʼ����\n");
//		 		else printf("��ճɹ���ɭ�ֿ��ˣ�\n");
				if(fst == NULL) printf("��ǰɭ�ֲ����ڣ����ȳ�ʼ����\n");
		 		else
		 		{
		 			printf("��������Ҫ��յ��������ƣ�\n");
	   		 		scanf("%s",BiTreeName);
	   	 			if(j = LocateBiTree(fst, BiTreeName))
	   	 			ClearBiTree(fst->tree[j-1]->T->lchild); 
	   	 			printf("��ճɹ�\n"); 
				}
		 		printf("----���������----\n");
		 		_getch();
		 		break;
		 	case 6:
			    if(fst == NULL)
				{
					printf("��ǰɭ�ֲ����ڣ����ȳ�ʼ����\n");
					printf("----���������----\n");
		 			_getch();
		 			break;
				}
			    else
			    {
		 			printf("������������ĵ���������:\n");
		 			scanf("%s",BiTreeName);
		 			j = LocateBiTree(fst, BiTreeName);
		 			if(j == 0)
		 			{
		 				printf("���޴�����\n");
	   	 		 		printf("----���������----\n");
		 				_getch();
		 				break;
					}
					else
					{
						int ord = 0;
						printf("�Ƿ�Ҫ�޸���������?(��.1 / ��.0)��");
						scanf("%d", &ord);
						if(ord)
						{
							printf("���������֣�");
							scanf("%s", fst->tree[j - 1]->name);
							printf("�޸ĳɹ���\n");
							printf("�����޸�������(��.1 / ��.0):");
							scanf("%d", &ord);
							if(!ord) break;
						}
						return &(fst->tree[j - 1]->T);
					}
				}
		 	case 7:
	   	 		if((j = ForestTraverse(fst)) == 0) printf("��ǰɭ��һ����Ҳû�У�\n");
	   	 		else if(j == INFEASIBLE) printf("��ǰɭ�ֲ����ڣ�\n");
				printf("----���������----\n");
		 		_getch();
		 		break;
		 	case 8:
		 		if(DestroyForest(fst) == INFEASIBLE) printf("��..�㻹�ǲ��ǵó�ʼ����\n");
		 		else printf("���ٳɹ���ɭ��û�ˣ�\n");
		 		printf("----���������----\n");
		 		_getch();
		 		break;
		 	case 0:
		 		break;
		 	default:
		 		printf("ָ�����\n");
	   	 		printf("----���������----\n");
		 		_getch();
		 		break;
		}
	}
	return NULL;
}


int main(){
BiTree T = NULL; //��  
FST fst = NULL;  //ɭ�� 
int op = 1;    //����ָ�� 
int flag = 0;  //ɭ�ֲ�����ɱ�־ 
DEF definition[100]; //�������е��������� 
int e = 0;   //��ֵ���� 
BiTNode *node = NULL; //�������
BiTree *T_ope = NULL, temp = NULL;//ɭ�ֲ����������� 
TElemType value;    //����������� 
int LR;   //����ڵ㣺������ 
while(op){
	system("cls");	printf("\n\n");
	printf("                         ���ڶ�������Ķ����������˵�\n");
	printf("-----------------------------------------------------------------------\n");
	printf("    	  1. ��ʼ����       8. ����ֵܽ��     15. �������п�\n");
	printf("    	  2. ��ʼ������     9. ����ڵ�         16. �浵\n");
	printf("    	  3. �ݻ���        10. ɾ�����         17. ����\n");
	printf("    	  4. �����        11. ǰ�����         18. ɭ�ֹ���\n");
	printf("    	  5. �������      12. �������          0. �˳�/���뵽ɭ��\n");
	printf("    	  6. ������      13. �������\n");
	printf("          7. ��㸳ֵ      14. �������\n");
	printf("-----------------------------------------------------------------------\n");
	if(op)
	printf("    ��ѡ����Ĳ���[0~18]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
	   	 if(InitBiTree(T) == OK) printf("��ʼ���ɹ���\n");
	   	 else printf("��ǰ�������Ѿ��е㶫����~\n");
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 2:
	   	 if(T == NULL) printf("���ȳ�ʼ����\n");
	   	 else if(T->lchild != NULL) printf("��ǰ�����ǿ�\n");
	   	 else{
	   	 	int i=0;
	   	 		printf("�������ݣ�(��ʽ�����������е�λ�����+��ֵ+����)��λ�����Ϊ0ʱ����\n");
		 		do {
					scanf("%d%d%s",&definition[i].pos,&definition[i].data.key,definition[i].data.others);
		 		} while (definition[i++].pos);
		 		CreateBiTree(T->lchild,definition);
		 		printf("����ɹ���\n");
			}
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 3:
	   	 if(T == NULL) printf("���ȳ�ʼ����\n");
	   	 else{
	   	 	ClearBiTree(T);
		 	printf("���ٳɹ���\n");
		 }
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 4:
	   	 if(T == NULL) printf("���ȳ�ʼ����\n");
	   	 else if(flag==0){
	   	 	ClearBiTree(T->lchild);
		 	printf("��ճɹ���\n");
		 }
		 else if(flag)
		 printf("�ڵ�ǰҳ�治֧������ɾ�����ܣ�����ɭ�������\n"); 
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 5:
	   	 if(T == NULL) printf("��������\n");
	     else printf("��ǰ�������Ϊ%d\n", BiTreeDepth(T->lchild));
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 6:
	   	 if(T == NULL) printf("���ȳ�ʼ����\n");
	   	 else{
	   	 	printf("�����ֵ��");
	   	 	scanf("%d", &e);
	   	 	node = LocateNode(T->lchild, e);
	   	 	if(node == NULL) printf("��ǰ������û��keyֵΪ%d�Ľ��\n", e);
	   	 	else printf("��ǰ����ֵΪ:%d, ����Ϊ:%s\n", node->data.key, node->data.others);
			}
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 7:
	   	if(T == NULL) printf("��ǰ�������ڣ�\n");
	   	else{
		    printf("������Ҫ�޸ĵĽ���ֵ��");
	   	 	scanf("%d", &e);
	   	 	node = LocateNode(T->lchild, e);
	   	 	if(node == NULL) printf("��ǰ������û��keyֵΪ%d�Ľ��\n", e);
	   	 	else
	   	 	{
	   	 		printf("������������ĺ�Ľ���ֵ��");
	   	 		scanf("%d", &value.key);
	   	 		printf("��������ĺ�����ݣ�");
	   	 		scanf("%s", value.others);
	   	 		if(Assign(T->lchild, e, value) == ERROR)
					printf("���ļ�ֵ������Ϊԭ�����Ѵ����������ļ�ֵΪ%d��\n", value.key);
	   	 		else printf("���ĳɹ���\n");
			}
		   }
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 8:
	   	 if(T == NULL) printf("���ȳ�ʼ����\n");
	   	 else
	   	 {
	   	 	printf("���뵱ǰ��ֵ��");
	   	 	scanf("%d", &e);
	   	 	node = LocateNode(T->lchild, e);
	   	 	if(node == NULL) printf("��ǰ������û��keyֵΪ%d�Ľ��\n", e);
	   	 	else
	   	 	{
	   	 		node = GetSibling(T->lchild, e);
	   	 		if(node == NULL) printf("������û���ֵ�~\n");
	   	 		else printf("��������ֵܽ��ļ�ֵΪ��%d, ����Ϊ��%s\n", node->data.key, node->data.others);
			}
		 }
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 9:
	   	 if(T == NULL) printf("���ȳ�ʼ����\n"); 
	   	 else
	   	 {
	   	 	printf("������Ӧ��Ӻ��ӽ���ֵ\n");
	   	 	scanf("%d", &e);
	   	 	node = LocateNode(T->lchild, e);
	   	 	if(node == NULL) printf("��ǰ������û��keyֵΪ%d�Ľ��\n", e);
	   	 	else{
	   	 		printf("��������ӻ����Һ��ӣ�(������0���Һ�����1����������-1)\n");
	   	 		scanf("%d", &LR);
	   	 		printf("������������ֵ��");
	   	 		scanf("%d", &value.key);
	   	 		printf("��������������ݣ�");
	   	 		scanf("%s", value.others);
	   	 		if(InsertNode(T->lchild, e, LR, value) == ERROR) printf("������ֵ������Ϊԭ�����Ѵ����������ļ�ֵΪ%d��\n", value.key);
	   	 		else printf("����ڵ�ɹ���\n");
			}
		 }
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 10:
	   	 if(T == NULL) printf("���ȳ�ʼ����\n");
	   	 else{
	   	 	printf("�����ɾ�����ļ�ֵ��");
			scanf("%d", &e);
			if(DeleteNode(T, e) == ERROR) printf("��ǰ������û��keyֵΪ%d�Ľ��\n", e);
			else printf("ɾ���ɹ���\n");
		 }
		 	printf("----���������----\n");
		 	_getch();
		 	break;
	   case 11:
	   	 if(T == NULL) printf("�����ȳ�ʼ����\n");
	   	 else
		 {
			printf("ǰ�������ǰ���н����Ϣ���£�\n");
			PreOrderTraverse(T->lchild, visit);
			printf("\n");
		 }
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 12:
	   	 if(T == NULL) printf("���ȳ�ʼ����\n");
	   	 else
		 {
			printf("���������ǰ���н����Ϣ���£�\n");
			InOrderTraverse(T->lchild, visit);
			printf("\n");	
		 }
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 13:
	   	 if(T == NULL) printf("���ȳ�ʼ����\n");
	   	 else
		 {
			printf("���������ǰ���н����Ϣ���£�\n");
			PostOrderTraverse(T->lchild, visit);
			printf("\n");	
		 }
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 14:
	   	 if(T == NULL) printf("���ȳ�ʼ����\n");
	   	 else
		 {
			printf("���������ǰ���н����Ϣ���£�\n");
			LevelOrderTraverse(T->lchild, visit);
			printf("\n");
		 }
		 printf("----���������----\n");
		 _getch();
		 break;
	  case 15:
	   	 if(T == NULL) printf("��������\n");
	   	 else
	   	 {
	   	 	BiTreeEmpty(T);
	   	 	printf("��ճɹ�"); 
	   	 	printf("\n");
		 }
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 16:
	   	 if(T == NULL) printf("����δ��ʼ����\n");
	   	 else{
		 	char SaveFile[40];
		 	printf("����浵�ļ�·��(����0ѡ��Ĭ��·��):\n");
		 	scanf("%s",SaveFile);
		 	if(!strcmp(SaveFile,"0")) strcpy(SaveFile, "D:\\���ݽṹʵ��\\�ļ�.dat");
		 	FILE *fp = fopen(SaveFile, "w");
	   	 	SaveBiTree(T->lchild,fp,1);
	   	 	fclose(fp);
	   	 	printf("�ѽ����ݴ��� %s\n",SaveFile);
			}
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 17:
	   	 if(T == NULL) printf("�����������������������ڣ�\n");
		 else if(T->lchild != NULL) printf("��ǰ������ǿգ�\n");
		 else
		 {
	   	 	char LoadFile[40];
	   	 	printf("��������ļ�·��(����0ѡ��Ĭ��·��):\n");
		 	scanf("%s",LoadFile);
		 	if(!strcmp(LoadFile,"0")) strcpy(LoadFile, "D:\\���ݽṹʵ��\\�ļ�.dat");
	   	 	if(LoadBiTree(T->lchild, LoadFile) == ERROR) printf("�浵�ļ�%s�޷��򿪣�\n", LoadFile);
	   	 	else printf("�����Ѵ� %s �ж���\n",LoadFile);
		 }
		 printf("----���������----\n");
		 _getch();
		 break;
	   case 18:
	   	 if(flag == 1)            //�޸�״̬�������ٴ�ѡ�����Ա��ϲ��� 
		{
			printf("��ǰ��δ���������Ա��޸ģ����Ƚ���ǰһ�޸ģ�\n"); 
		 	printf("----���������----\n");
		 	_getch();
			break;
		}
	   	 T_ope = gather_operate(fst);//����ָ��ָ���ָ�룬������ж�ȡ 
	   	 if(T_ope != NULL)//ֻҪѡ���˼��ϲ����е��޸ģ��ͽ����������Ա��û��ɼ�������ѡ���Ա� 
	   	 {
	   	 	temp = T;             //temp�ݴ����������Ա�����
	   	 	T = *T_ope;            //�������̨���Ա��û�Ϊ��������ѡ���Ա�
	   	 	flag = 1;             //ϵͳ״̬��Ϊ���ϲ���̬
		 }
		 break;
	   case 0:
         break; 
		 printf("----���������----\n");
		 _getch();
		 break;
	}//end of switch
	if(flag && op == 0)     //flag�жϵ�ǰ�Ƿ������Ա��ϲ����У���ʱ�˳�����������
	{
		T = temp;           //����ԭʼ���������Ա�����
		op = 1;             //���ֲ��˳�while
		flag = 0;           //״̬��Ϊ��ʼ����
		printf("ԭ��������������������룡\n");
		_getch();
	}
  }//end of while
printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
printf("----���������----\n");
_getch(); 
return 0;
}//end of main()

