	#include "stdio.h"
	#include "stdlib.h"
	#include<string.h>
	#include "conio.h"
	#define TRUE 1
	#define FALSE 0
	#define OK 1
	#define ERROR 0
	#define INFEASIBLE -1
	#define OVERFLOW -2
	#define MAX_VERTEX_NUM 20
	typedef int status;
	typedef int KeyType; 
   typedef enum {DG,DN,UDG,UDN} GraphKind;
	typedef struct {
         KeyType  key;
         char others[20];
	} VertexType; //顶点类型定义


	typedef struct ArcNode {         //表结点类型定义
   		 int adjvex;              //顶点位置编号 
    	 struct ArcNode  *nextarc;	   //下一个表结点指针
	} ArcNode;
	typedef struct VNode{				//头结点及其数组类型定义
   		 VertexType data;       	//顶点信息
    	 ArcNode *firstarc;      	 //指向第一条弧
    	} VNode,AdjList[MAX_VERTEX_NUM];
	typedef  struct {  //邻接表的类型定义
        AdjList vertices;     	 //头结点数组
        int vexnum,arcnum;   	  //顶点数、弧数（度数） 
        GraphKind  kind;        //图的类型
       } ALGraph;
typedef struct {
    char name[30];//图的名字 
    ALGraph G;
}Graph, *G;
typedef struct {  //多图定义
    G *elem;
    int length;//多重图的长度 
    int size;//多重图的大小 
}ALGraphs;
int IsRepeat(ArcNode* arc, int num);//判断是否有重复的弧 
int IsRepeat(ALGraph G, KeyType key);// 判断是否有重复的键值 
 status CreateGraph(ALGraph &G);//新建一个图 
int LocateVex(ALGraph G, KeyType u);// 定位图中的键值 
status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2]);//按照一定的规则进行图的创建 
status DestroyGraph(ALGraph& G);//摧毁一个图 
status PutVex(ALGraph &G,KeyType u,VertexType value);//改变图中的键值 
int FirstAdjVex(ALGraph G,KeyType u);//定位对应键值的第一邻接点 
int NextAdjVex(ALGraph G,KeyType v,KeyType w);//定位对应键值的邻接点的下一邻接点 
status InsertVex(ALGraph &G,VertexType v);//插入顶点 
status DeleteVex(ALGraph &G,KeyType v);//删除节点 
status InsertArc(ALGraph &G,KeyType v,KeyType w);//插入弧 
status DeleteArc(ALGraph &G,KeyType v,KeyType w);//删除弧 
status DFSTraverse(ALGraph G, void (*visit)(VertexType));//广度遍历 
status DFS(ALGraph G,int i ,void (*visit)(VertexType));//广度遍历辅助函数 
status BFSTraverse(ALGraph &G,void (*visit)(VertexType));//深度遍历 
status visitNode(ALGraph G, ArcNode** Q, int& head, int& tail, int* rec, void (*visit)(VertexType));//深度遍历辅助函数 
void visit(VertexType v);//访问函数 
status SaveGraph(ALGraph G, char FileName[]);//保存图 
status LoadGraph(ALGraph &G, char FileName[]);//读取图 
//以下为多重图操作 
status InitALGraphs(ALGraphs& GS); //初始化多图(以顺序线性表形式定义)
status AddGraph(ALGraphs& GS, int i, char GraphName[]);//新增一个图 
status RemoveGraph(ALGraphs& GS, char GraphName[]);//移除一个图 
status ALGraphsTraverse(ALGraphs GS);//多重图的遍历 
status ClearALGraphs(ALGraphs& GS);//清空多重图中的内容 
status DestroyALGraphs(ALGraphs& GS);//摧毁多重图 
ALGraph* gather_operate(ALGraphs& GS);//多重图集合操作 
int main()
{
	ALGraph *G = (ALGraph*)malloc(sizeof(ALGraph));   //图  
	G->vexnum = 0;
	G->arcnum = 0;
	int op = 1;  //操作指令 
	int j = 0, k = 0;   //函数执行状态
	KeyType key = 0, key1 = 0; //键值载体
	VertexType value;
	ALGraphs GS;  //多图
	GS.elem = NULL;
	int flag = 0;  //多图操作完成标志 
	ALGraph* G_ope = NULL, *temp = NULL; //多图操作图的载体
	while (op) {
		system("cls");	printf("\n\n");
		printf("                         基于邻接表的图操作菜单\n");
		printf("-----------------------------------------------------------------------\n");
		printf("    	  1. 创建图           7.  插入顶点       13. 存档\n");
		printf("    	  2. 销毁图           8.  删除顶点       14. 读档\n");
		printf("    	  3. 查找顶点         9.  插入弧         15. 多图管理\n");
		printf("    	  4. 顶点赋值         10. 删除弧         0.  退出 \n");
		printf("    	  5. 获得第一邻接点   11. 深度优先遍历\n");
		printf("    	  6. 获得下一邻接点   12. 广度优先遍历\n");
		printf("-----------------------------------------------------------------------\n");
		if (op)
			printf("    请选择你的操作[0~17]:");
		scanf("%d", &op);
		switch(op) {
			case 1:
				if((j = CreateGraph(*G)) == OK) printf("创建成功！\n");
				else if(j == INFEASIBLE) printf("当前的图里已经有点东西了~\n");
				else if(j == ERROR) printf("输入数据有误，键值重复，创建失败！\n");
				printf("----任意键继续----\n");
				_getch();
				break;
			case 2:
				if (G->vexnum == 0) printf("空图\n");
				else
				{
					DestroyGraph(*G);
					printf("销毁成功！\n");
				}
				printf("----任意键继续----\n");
				_getch();
				break;
			case 3:
				if (G->vexnum == 0) printf("空图\n");
				else
				{
					printf("请输入\n");
					scanf("%d", &key);
					if((j = LocateVex(*G, key)) == -1) printf("没找到键值是%d的点\n", key);
					else printf("键值为%d的结点在这个图里是第%d个点, 其中的数据是：key=%d, others=%s\n", key, j + 1, G->vertices[j].data.key, G->vertices[j].data.others);
				}
				printf("----任意键继续----\n");
				_getch();
				break;
			case 4:
				if (G->vexnum == 0) printf("空图\n");
				else {
					printf("请输入要定位的键值：");
					scanf("%d", &key);
					if (LocateVex(*G, key) == -1)
					{
						printf("没有键值为%d的顶点\n", key);
						printf("----任意键继续----\n");
						_getch();
						break;
					}
					else
					{
						printf("请输入要更改的键值：");
						scanf("%d", &value.key);
						if (LocateVex(*G, value.key) != -1 && value.key != key)
						{
							printf("没有找到该键值的点\n");
							printf("----任意键继续----\n");
							_getch();
							break;
						}
						else {
							printf("请输入要更改的内容");
							scanf("%s", value.others);
						}
					}
					PutVex(*G, key, value);
					printf("更改成功！\n");
				}
				printf("----任意键继续----\n");
				_getch();
				break;
			case 5:
				if (G->vexnum == 0) printf("空图\n");
				else
				{
					printf("请输入要定位的键值:\n");
					scanf("%d", &key);
					if ((j = FirstAdjVex(*G, key)) == -1) printf("没有找到\n");
					else printf("键值为%d的点的第一邻接点是第%d号点, 其中的数据是：key=%d, others=%s\n", key, j + 1, G->vertices[j].data.key, G->vertices[j].data.others);
				}
				printf("----任意键继续----\n");
				_getch();
				break;
			case 6:
			if (G->vexnum == 0) printf("空图\n");
			else {
				printf("输入键值：");
				scanf("%d", &key);
				if ((j = LocateVex(*G, key)) != -1)
				{
					printf("请输入在它的邻接链表里找哪一个点的下一邻接点？键值：\n");
					scanf("%d", &key1);
					if (IsRepeat(G->vertices[j].firstarc, LocateVex(*G, key1)))
					{
						if ((j = NextAdjVex(*G, key, key1)) == -1) printf("无下一邻接点！\n");
						else printf("键值为%d的点相对于键值为%d的点的下一邻接点为第%d号点，其数据为：key=%d, others=%s\n", key, key1, j + 1, G->vertices[j].data.key, G->vertices[j].data.others);
					}
					else printf("键值为%d的点与键值为%d的点不邻接！\n",key, key1);
				}
				else
				{
					printf("该图中没有与之对应的点\n");
				}
			}
			printf("----任意键继续----\n");
			_getch();
			break;
		case 7:
			if (G->vexnum == MAX_VERTEX_NUM) printf("超过图的上线\n");
			else {
				printf("请输入新增顶点的键值：");
				scanf("%d", &value.key);
				if (IsRepeat(*G, value.key)) printf("重复的键值\n");
				else
				{
					printf("请输入新增顶点的数据：");
					scanf("%s", value.others);
					InsertVex(*G, value);
					printf("添加成功！\n");
				}
			}
			printf("----任意键继续----\n");
			_getch();
			break;
		case 8:
			if (G->vexnum == 0) printf("空图\n");
			else
			{
				printf("输入待删除顶点键值：");
				scanf("%d", &key);
				j = LocateVex(*G, key);
				if (j == -1) printf("当前图里面没有key值为%d的顶点\n", key);
				else
				{
					DeleteVex(*G, key);
					printf("删除成功！\n");
				}
			}
			printf("----任意键继续----\n");
			_getch();
			break;
		case 9:
			if (G->vexnum < 2) printf("不符合增减条件\n");
			else
			{
				printf("请输入增加弧顶点的键值：");
				scanf("%d%d", &key, &key1);
				j = InsertArc(*G, key, key1);
				if(j == INFEASIBLE) printf("这两点之间已经有弧了!\n");
				else if (j == ERROR)
				{
					if ((k = LocateVex(*G, key)) == -1)
					{
						if (LocateVex(*G, key1) == -1)
							printf("没有找到对应的点\n");
						else
							printf("键值为%d的点不在这个图里\n", key);
					}
					else if (k != -1) printf("键值为%d的点不在这个图里\n", key1);
				}
				else printf("添加成功！\n");
			}
			printf("----任意键继续----\n");
			_getch();
			break;
		case 10:
			if (G->vexnum < 2) printf("不满足增减条件\n");
			else
			{
				printf("请输入删减的的弧对应的两个顶点：");
				scanf("%d%d", &key, &key1);
				j = DeleteArc(*G, key, key1);
				if(j == INFEASIBLE) printf("这两个点不邻接！\n");
				else if (j == ERROR)
				{
					if ((k = LocateVex(*G, key)) == -1)
					{
						if (LocateVex(*G, key1) == -1)
							printf("没有找到对应的点\n");
						else
							printf("键值为%d的点不在这个图里\n", key);
					}
					else printf("键值为%d的点不在这个图里\n", key1);
				}
				else printf("删除成功！\n");
			}
			printf("----任意键继续----\n");
			_getch();
			break;
		case 11:
			if (G->vexnum == 0) printf("空图\n");
			else
			{
				printf("深度优先遍历时，当前图中所有点的信息如下：\n");
				DFSTraverse(*G, visit);
				printf("\n");
			}
			printf("----任意键继续----\n");
			_getch();
			break;
		case 12:
			if (G->vexnum == 0) printf("空图\n");
			else
			{
				printf("广度优先遍历时，当前图中所有点的信息如下：\n");
				BFSTraverse(*G, visit);
				printf("\n");
			}
			printf("----任意键继续----\n");
			_getch();
			break;
		case 13:
			if (G->vexnum == 0) printf("空图\n");
			else {
				char SaveFile[40];
				printf("输入存档文件路径(输入0选择默认路径):\n");
				scanf("%s", SaveFile);
				if (!strcmp(SaveFile, "0")) strcpy(SaveFile, "D:\\数据结构实验\\文件.dat");
				SaveGraph(*G, SaveFile);
				printf("已将数据存入 %s\n", SaveFile);
			}
			printf("----任意键继续----\n");
			_getch();
			break;
		case 14:
			if(G->vexnum != 0) printf("当前图中已有其它结点!\n");
			else
			{
				char LoadFile[40];
				printf("输入读档文件路径(输入0选择默认路径):\n");
				scanf("%s", LoadFile);
				if (!strcmp(LoadFile, "0")) strcpy(LoadFile, "D:\\数据结构实验\\文件.dat");
				if ((j = LoadGraph(*G, LoadFile)) == ERROR) printf("存档文件%s无法打开！\n", LoadFile);
				else if(j == INFEASIBLE) printf("存档文件中点的个数超出容量!读档失败!\n");
				else printf("数据已从 %s 中读出\n", LoadFile);
//				printf("当前图中有%d个点, %d条边\n", G->vexnum, G->arcnum);
			}
			printf("----任意键继续----\n");
			_getch();
			break;
		case 15:
			if (flag == 1)            //修改状态，不可再次选择线性表集合操作 
			{
				printf("当前有未结束的修改，请先结束前一修改！\n");
				printf("----任意键继续----\n");
				_getch();
				break;
			}
			G_ope = gather_operate(GS);
			if (G_ope != NULL)//只要选择了集合操作中的修改，就将主界面的图置换成集合中所选图 
			{
				temp = G;             //temp暂存主界面线性表数据
				G = G_ope;            //主界面后台线性表置换为集合内所选图
				flag = 1;             //系统状态置为集合操作态
			}
			break;
		case 0:
			break;
		}//end of switch
		if (flag && op == 0)     //flag判断当前是否在线性表集合操作中，此时退出返回主界面
		{
			G = temp;           //返还原始主界面线性表数据
			op = 1;             //保持不退出while
			flag = 0;           //状态置为初始界面
			printf("原主界面的图中数据已载入！\n");
			_getch();
		}
	}//end of while
	printf("欢迎下次再使用本系统！\n");
	printf("----任意键结束----\n");
	_getch();
	return 0;

 } 

int IsRepeat(ArcNode* arc, int num)
//在当前结点及其后续链表中是否存在num
{
	while (arc != NULL)
	{
		if (arc->adjvex == num)
			return 1;
		arc = arc->nextarc;
	}
	return 0;
}

int IsRepeat(ALGraph G, KeyType key)
//图G中查找键值与key相同的点
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (key == G.vertices[i].data.key)
			return 1;
	}
	return 0;
}

 status CreateGraph(ALGraph &G)
//输入创建图
{
	if (G.vexnum != 0) return INFEASIBLE;
	VertexType V[30];
	KeyType VR[100][2];
	int i = 0;
	G.arcnum = G.vexnum = 0;
	printf("按照\"键值 名称 键值 名称 ... -1 nil 连接键值 连接键值 ... -1 -1\"输入\n"); 
	do {
		scanf("%d%s", &V[i].key, V[i].others);
	} while (V[i++].key != -1);
	i = 0;
	do {
		scanf("%d%d", &VR[i][0], &VR[i][1]);
	} while (VR[i++][0] != -1);
	if (CreateCraph(G, V, VR) == ERROR) return ERROR;
	else return OK;
}

status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
int i=0;
	for(i=0;V[i].key!=-1;i++)//先判断其中的头节点数据的个数是否超 
	{
		if(i>=MAX_VERTEX_NUM)
		return ERROR; 
	 }
	 for(i=0;V[i].key!=-1;i++)//是否有键值重复 
	 {
	 	int j=0;
	 	for(j=i+1;V[j].key!=-1;j++)
	 	{
	 		if(V[i].key== V[j].key)
	 		return ERROR;
		 }
	  }
 i=0;
 if(V[i].key==-1)//是否从一开始就没有输入 
	 		return ERROR;
	  G.vexnum=0; 
	  for(i=0; V[i].key!=-1; i++) 
	  {
	  	G.vertices[i].data.key = V[i].key;
		strcpy(G.vertices[i].data.others, V[i].others);
		G.vertices[i].firstarc = NULL;
		G.vexnum++;
	   } 
	   	//指针域链接
	int count = 0;  //记录图的度degree，每链接一次count++，最终count为degree的两倍 
	G.arcnum = 0;//度数置为0 
	for ( i = 0; VR[i][0] != -1; i++)
	{
		int head = LocateVex(G, VR[i][0]); //定位到要插入的键值 
		int tail = LocateVex(G, VR[i][1]);//定位到要插入的键值 

		if (head == -1|| tail == -1)   //VR中包含V中不存在的点，错误
			return ERROR;
		if ( tail != head)
		{
			count++;
			ArcNode* in = (ArcNode*)malloc(sizeof(ArcNode));
			in->nextarc = G.vertices[head].firstarc;//利用首插法 
			G.vertices[head].firstarc = in;
			in->adjvex = tail;
		}

		if (tail != head)
		{
			count++;
			ArcNode* back = (ArcNode*)malloc(sizeof(ArcNode));
			back->nextarc = G.vertices[tail].firstarc;
			G.vertices[tail].firstarc = back;
			back->adjvex = head;
		}
	}
	
	G.arcnum = count / 2;
	return OK;

    /********** End **********/
}

status DestroyGraph(ALGraph& G)
/*销毁无向图G*/
{
	for (int i = 0; i < G.vexnum; i++)
	{
		//释放每个结点后的链表
		ArcNode* p = G.vertices[i].firstarc, * del = NULL;
		while (p != NULL)
		{
			del = p;
			p = p->nextarc;
			free(del);
			del = NULL;
		}
	}
	G.vexnum = 0;
	G.arcnum = 0;
	return OK;
}

int LocateVex(ALGraph G, KeyType u)
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data.key == u)
			return i;
	}
	return -1;
}
status PutVex(ALGraph &G,KeyType u,VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
int i,j;
i=LocateVex(G,u);
j=LocateVex(G,value.key);
if(j!=-1||i==-1)
return ERROR;
else  {
    G.vertices[i].data=value;
    return OK;
}

    /********** End **********/
}
int FirstAdjVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
int i;
i=LocateVex(G,u);
if(i==-1)
{
    return ERROR;
}
else
{
    return G.vertices[i].firstarc->adjvex;
}
    /********** End **********/
}
int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//根据u在图G中查找顶点，查找成功返回顶点v的邻接顶点相对于w的下一邻接顶点的位序，查找失败返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
int i;
i=LocateVex(G,v);
if(i==-1)
{
    return -1;
}
else
{
    ArcNode* p;
    p=G.vertices[i].firstarc ;
    while(p){
        int pos = p->adjvex;
		p = p->nextarc;
		if (G.vertices[pos].data.key == w)
			break;

    }
   if (p == NULL) return -1;  //没找到 w 或者 w没有下一个
	else return p->adjvex;


}
    /********** End **********/
}
status InsertVex(ALGraph &G,VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
int i;
i=LocateVex(G,v.key);
if(i!=-1)
{
    return ERROR;
}
else{
    if(G.vexnum == MAX_VERTEX_NUM )
    return ERROR;
    G.vertices[G.vexnum].data.key = v.key;
	strcpy(G.vertices[G.vexnum].data.others, v.others);
	G.vertices[G.vexnum].firstarc = NULL;
	G.vexnum++;
	return OK;

}
    /********** End **********/
}
status DeleteVex(ALGraph &G,KeyType v)
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
{
	int i;
	i=LocateVex(G,v);
    if(G.vexnum==1||i==-1)return ERROR;//若删除后为空图 或者没有找到该节点 
    for(int j=0;j<G.vexnum;j++)//将该顶点前的顶点中含有该顶点的弧空间释放 
            {
                ArcNode *p=G.vertices[j].firstarc,*q;
                if(!p)continue;
                if(p->adjvex==i) 
                {
				G.vertices[j].firstarc=p->nextarc;
				free(p);
				continue;
				}
                while(p->nextarc)
                {
                    if(p->nextarc->adjvex==i)
                    {
					q=p->nextarc;
					p->nextarc=q->nextarc;
					free(q);
					break;
					}
                    p=p->nextarc;
                }
            }
            ArcNode *p=G.vertices[i].firstarc,*q;
            while(p)//将该顶点上的弧空间释放 
            {
                q=p;
                p=p->nextarc;
                free(q);
                G.arcnum--;
            }
            G.vertices[i].firstarc=NULL;
            G.vexnum--;//无向图中顶点数-1 
            //无向图中弧数量减少sum 
            for(int j=i;j<G.vexnum;j++)//顶点移位 
            {
                G.vertices[j]=G.vertices[j+1];
            }
            for(int j=0;j<G.vexnum;j++)//调整弧的顶点位序 
            {
                p=G.vertices[j].firstarc;
                while(p)
                {
                    if(p->adjvex>i)
					p->adjvex--;
                    p=p->nextarc;
                }
            }
            return OK; 
    return ERROR;//未找到该顶点 
}
status InsertArc(ALGraph &G,KeyType v,KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //顶点数小于2的图直接
if (G.vexnum < 2) return ERROR;
int i,j;
i=LocateVex(G,v);
j=LocateVex(G,w);
if(i==-1||j==-1)//如果两个节点都没有，返回错误
return ERROR;
else//当节点都存在时
{
	ArcNode* p = G.vertices[i].firstarc;
	while (p != NULL)
	{
		if (p->adjvex == j)
			return INFEASIBLE;
		p = p->nextarc;
	}

	//v后加 w 
	ArcNode* newj = (ArcNode*)malloc(sizeof(ArcNode));
	newj->adjvex =j;
	newj->nextarc = G.vertices[i].firstarc;
	G.vertices[i].firstarc = newj;

	//w后加 v 
	ArcNode* newi = (ArcNode*)malloc(sizeof(ArcNode));
	newi->adjvex = i;
	newi->nextarc = G.vertices[j].firstarc;
	G.vertices[j].firstarc = newi;

	G.arcnum++;
	return OK;
}
}
status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR

{   // 请在这里补充代码，完成本关任务
    /********** Begin *********/
if (G.vexnum < 2) return ERROR;
int i,j;
i=LocateVex(G,v);
j=LocateVex(G,w);
if(i==-1||j==-1)//如果两个节点都没有，返回错误
return ERROR;
ArcNode* p = G.vertices[i].firstarc;
ArcNode* q = G.vertices[j].firstarc;
ArcNode* temp;
	int flag = 0;
	while (p != NULL)
	{
		if (p->adjvex == j)
			flag = 1;
		p = p->nextarc;
	}
	if (!flag) return ERROR;
    p = G.vertices[i].firstarc;
    if(p->adjvex==j) 
                {
				G.vertices[i].firstarc=p->nextarc;
				free(p);
				}
                while(p->nextarc)
                {
                    if(p->nextarc->adjvex==j)
                    {
					temp=p->nextarc;
					p->nextarc=temp->nextarc;
					free(temp);
					break;
					}
                    p=p->nextarc;
                }
	
    if(q->adjvex==i) 
                {
				G.vertices[j].firstarc=q->nextarc;
				free(q);
				}
                while(q->nextarc)
                {
                    if(q->nextarc->adjvex==i)
                    {
					temp=q->nextarc;
					q->nextarc=temp->nextarc;
					free(temp);
					break;
					}
                    q=q->nextarc;
                }
         G.arcnum--;       
	return OK;



    /********** End **********/
}
int state[20];//记录状态，确保只遍历一次
status DFS(ALGraph G,int i ,void (*visit)(VertexType))
{
	int j;
	//1.处理起始点 
	visit(G.vertices[i].data);//1.输出起始结点 
	state[i]=1;//2.将已访问的结点标志成1
	 //2.由起始点开始，对后续结点进行操作
	ArcNode* p=G.vertices[i].firstarc;
	while(p)
    {
        j=p->adjvex;//访问其邻接点
		if(state[j]==0)//当满足有边且未被访问过时，递归调用去查找该邻接点 
	{
		DFS(G,j,visit);
	}
	p=p->nextarc;
	}
	return OK;
}
void visit(VertexType v)
{
    printf(" %d %s",v.key,v.others);
}
status DFSTraverse(ALGraph G, void (*visit)(VertexType)){
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
int i=0;
for(i=0;i<G.vexnum;i++)
{
	state[i]=0;
}
for(i=0;i<G.vexnum;i++)
{
	if(!state[i])//当出现非联通分支的时候，重新遍历
	DFS(G,i,visit);
}
return OK;

}
status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

	ArcNode** Q = (ArcNode**)calloc(G.vexnum, sizeof(ArcNode*));
	int state[20]={0} ;
	int head = 0, tail = 0;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!state[i])
		{
			Q[tail++] = G.vertices[i].firstarc;
			visit(G.vertices[i].data);
			state[i] = 1;
	while (head != tail)
	{
		//访问当前结点并出队 
		ArcNode* p = Q[head++];
		if(p == NULL) return OK;
		if (!state[p->adjvex])
		{
			visit(G.vertices[p->adjvex].data);
			state[p->adjvex] = 1;
		}

		//进队 
		while (p != NULL)
		{
			if (!state[p->adjvex])
			{
				Q[tail++] = p;
			}
			p = p->nextarc;
		}
	}
		}
	}
	free(Q);
	return OK;


    /********** End **********/
}
status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
FILE* fp = fopen(FileName, "w+");
	for (int i = 0; i < G.vexnum; i++)
	{
		fprintf(fp, "%d %s", G.vertices[i].data.key, G.vertices[i].data.others);
		ArcNode* p = G.vertices[i].firstarc;
		while (p != NULL)
		{
			fprintf(fp, " %d", p->adjvex);
			p = p->nextarc;
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	return OK; 
    /********** End 1 **********/
}
status LoadGraph(ALGraph &G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
FILE* fp = fopen(FileName, "r");
	if(fp == NULL) return ERROR;
	int ch;
	G.vexnum = G.arcnum = 0;
	for (int i = 0; ch != EOF; i++)
	{
		//读取部分 
		fscanf(fp, "%d %s", &G.vertices[i].data.key, G.vertices[i].data.others);
		G.vexnum++;
		ch = fgetc(fp); 
		if (ch != '\n')
		{
			G.vertices[i].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
			ArcNode* p = G.vertices[i].firstarc;
			//读一个空格，读一个数据，读到换行直接退，此行的链表构建完成 
			while ((ch != '\n') && (ch != EOF) && fscanf(fp, "%d", &ch) != EOF)
			{
				p->adjvex = ch;
				ch = fgetc(fp);
				if (ch == '\n' || ch == EOF)
					p->nextarc = NULL;
				else
				{
					p->nextarc = (ArcNode*)malloc(sizeof(ArcNode));
					p = p->nextarc;
					p->nextarc = NULL; 
				}
				G.arcnum++;
			}
			p = NULL;
		}
		else G.vertices[i].firstarc = NULL;
	}
	--G.vexnum;
	G.arcnum /= 2;
	fclose(fp);
	return OK;
    /********** End 2 **********/
}
status InitALGraphs(ALGraphs& GS)
//初始化多图(以顺序线性表形式定义) 
{
	if (GS.elem != NULL) return INFEASIBLE;
	GS.elem = (G*)malloc(20*sizeof(Graph));
	GS.length = 0;
	GS.size = 20;
	return OK;
}
status AddGraph(ALGraphs& GS, int i, char GraphName[])
//第i位加入名为GraphName的图 
{
	if (GS.elem == NULL) return INFEASIBLE;

	if (i > GS.length + 1 || i < 1) return ERROR;
	
	for(int i = 0; i < GS.length; i++)
	{
		if(!strcmp(GraphName, GS.elem[i]->name))
		return ERROR;
	}
	
	//建立新图 
	G p = (Graph*)malloc(sizeof(Graph));
	int j = 0; int ord; 
	strcpy(p->name, GraphName); //图命名 && 图初始化 
	p->G.arcnum = p->G.vexnum = 0;
	printf("直接输入或者不输入(1/0)\n");
	scanf("\n%c", &ord);
	if(ord == 1)
	{
		j = CreateGraph(p->G);
		if(j == ERROR) printf("输入数据有误，部分顶点键值重复，新增失败！\n");
	}
	
	if (GS.length >= GS.size) //扩容 
	{
		GS.size += 10;
		GS.elem = (G*)realloc(GS.elem, GS.size * sizeof(G));
	}
	
	for (int j = GS.length; j >= i; j--) //移位置 
	{
		GS.elem[j] = GS.elem[j - 1];
	}

	GS.elem[i - 1] = p;
	GS.length++;
	return OK;
}

status RemoveGraph(ALGraphs& GS, char GraphName[])
//删去名为GraphName的图 
{
	if (GS.elem == NULL) return INFEASIBLE;
	for (int i = 0; i < GS.length; i++)
	{
		if (!strcmp(GraphName, GS.elem[i]->name))
		{
			DestroyGraph(GS.elem[i]->G);
			free(GS.elem[i]);
			for (int a = i + 1; a < GS.length; a++)
				GS.elem[a - 1] = GS.elem[a];

			GS.length--;
			return OK;
		}
	}
	return ERROR;
}

int LocateGraph(ALGraphs GS, char GraphName[])
//查找当前森林中名为GraphName的树 
{
	if (GS.elem == NULL) return INFEASIBLE;
	for (int i = 0; i < GS.length; i++)
	{
		if (!strcmp(GraphName, GS.elem[i]->name)) return i + 1;
	}
	return ERROR;
}

status ALGraphsTraverse(ALGraphs GS)
//遍历多图 
{
	if (GS.elem == NULL) return INFEASIBLE;
	if (GS.length == 0) return ERROR;
	int op = 0;
	if(op==0)
	{
		printf("请选择遍历方式：1.深度优先遍历 2.广度优先遍历\n");
		scanf("%d", &op);
	}
	if(op==1)
	{
		printf("当前集合中数据如下所示：\n");
	for (int i = 0; i < GS.length; i++)
	{
		printf("第%d个图：\n %s:\n", i + 1, GS.elem[i]->name);
		DFSTraverse(GS.elem[i]->G, visit);
		printf("\n\n");
	}
	}
	else{printf("当前集合中数据如下所示：\n");
	for (int i = 0; i < GS.length; i++)
	{
		printf("第%d个图：\n %s:\n", i + 1, GS.elem[i]->name);
		BFSTraverse(GS.elem[i]->G, visit);
		printf("\n\n");
	}
	}
	
	return OK;
}

status ClearALGraphs(ALGraphs& GS)
{
	if (GS.elem == NULL) return INFEASIBLE;
	for (int i = 0; i < GS.length; i++)
	{
		DestroyGraph(GS.elem[i]->G);
		free(GS.elem[i]);
		GS.elem[i] = NULL;
	}
	GS.length = 0;
	return OK;
}

status DestroyALGraphs(ALGraphs& GS)
{
	if (GS.elem == NULL) return INFEASIBLE;
	ClearALGraphs(GS);
	GS.size = 0;
	free(GS.elem);
	GS.elem = NULL;
	return OK;
}

ALGraph* gather_operate(ALGraphs& GS)
{
	int op = 1; int j = 0; int i = 0;
	char GraphName[30];
	while (op)
	{
		system("cls");	printf("\n\n");
		printf("              多图集合操作菜单\n");
		printf("--------------------------------------------\n");
		printf("    	 1. 初始化       5. 修改\n");
		printf("    	 2.  新增        6. 遍历\n");
		printf("    	 3.  删除        7. 清空集合\n");
		printf("    	 4.  查找        0. 退出\n");
		printf("--------------------------------------------\n");
		printf("    请选择你的操作[0~7]:");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			if (InitALGraphs(GS) == INFEASIBLE) printf("当前图集合已被初始化！\n");
			else printf("初始化成功！\n");
			printf("----任意键继续----\n");
			_getch();
			break;
		case 2:
			if (GS.elem == NULL)
			{
				printf("当前图集合不存在，请先初始化！\n");
				printf("----任意键继续----\n");
				_getch();
				break;
			}
			printf("请输入新增图的名称：\n");
			scanf("%s", GraphName);
			printf("新增到第几位?");
			scanf("%d", &i);
			if ((j = AddGraph(GS, i, GraphName)) == ERROR) printf("插入位置非法，添加失败！\n");
			else printf("图\"%s\"存储成功！\n", GraphName);
			printf("----任意键继续----\n");
			_getch();
			break;
		case 3:
			if (GS.elem == NULL)
			{
				printf("当前图集合不存在，请先初始化！\n");
				printf("----任意键继续----\n");
				_getch();
				break;
			}
			printf("请输入所要删除的图名称：\n");
			scanf("%s", GraphName);
			if (RemoveGraph(GS, GraphName) == OK)
			{
				printf("图\"%s\"删除成功！\n", GraphName);
			}
			else
			{
				printf("查无此图！\n");
			}
			printf("----任意键继续----\n");
			_getch();
			break;
		case 4:
			if (GS.elem == NULL)
			{
				printf("当前图集合不存在，请先初始化！\n");
				printf("----任意键继续----\n");
				_getch();
				break;
			}
			printf("请输入所要查找的图名称：\n");
			scanf("%s", &GraphName);
			if (j = LocateGraph(GS, GraphName))
			{
				printf("图\"%s\"位于集合中第%d位\n", GraphName, j);
			}
			else
			{
				printf("无图！\n");
			}
			printf("----任意键继续----\n");
			_getch();
			break;
		case 5:
			if (GS.elem == NULL)
			{
				printf("当前图集合不存在，请先初始化！\n");
				printf("----任意键继续----\n");
				_getch();
				break;
			}
			printf("请输入所需更改的图的名称:\n");
			scanf("%s", GraphName);
			j = LocateGraph(GS, GraphName);
			if (j == 0)
			{
				printf("查无此图！\n");
				printf("----任意键继续----\n");
				_getch();
				break;
			}
			else
			{
				return &(GS.elem[j - 1]->G);
			}
		case 6:
			if ((j = ALGraphsTraverse(GS)) == ERROR) printf("当前图集合为空！\n");
			else if (j == INFEASIBLE) printf("当前图集合不存在！\n");
			printf("----任意键继续----\n");
			_getch();
			break;
		case 7:
			if(ClearALGraphs(GS) == INFEASIBLE) printf("当前集合尚未被初始化!\n");
			else printf("清空成功!\n");
			printf("----任意键继续----\n");
			_getch();
			break;
		case 0:
			break;
		}
	}
	return NULL;
}
/*多图操作*/

