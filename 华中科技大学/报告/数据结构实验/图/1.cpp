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
	} VertexType; //�������Ͷ���


	typedef struct ArcNode {         //�������Ͷ���
   		 int adjvex;              //����λ�ñ�� 
    	 struct ArcNode  *nextarc;	   //��һ������ָ��
	} ArcNode;
	typedef struct VNode{				//ͷ��㼰���������Ͷ���
   		 VertexType data;       	//������Ϣ
    	 ArcNode *firstarc;      	 //ָ���һ����
    	} VNode,AdjList[MAX_VERTEX_NUM];
	typedef  struct {  //�ڽӱ�����Ͷ���
        AdjList vertices;     	 //ͷ�������
        int vexnum,arcnum;   	  //�������������������� 
        GraphKind  kind;        //ͼ������
       } ALGraph;
typedef struct {
    char name[30];//ͼ������ 
    ALGraph G;
}Graph, *G;
typedef struct {  //��ͼ����
    G *elem;
    int length;//����ͼ�ĳ��� 
    int size;//����ͼ�Ĵ�С 
}ALGraphs;
int IsRepeat(ArcNode* arc, int num);//�ж��Ƿ����ظ��Ļ� 
int IsRepeat(ALGraph G, KeyType key);// �ж��Ƿ����ظ��ļ�ֵ 
 status CreateGraph(ALGraph &G);//�½�һ��ͼ 
int LocateVex(ALGraph G, KeyType u);// ��λͼ�еļ�ֵ 
status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2]);//����һ���Ĺ������ͼ�Ĵ��� 
status DestroyGraph(ALGraph& G);//�ݻ�һ��ͼ 
status PutVex(ALGraph &G,KeyType u,VertexType value);//�ı�ͼ�еļ�ֵ 
int FirstAdjVex(ALGraph G,KeyType u);//��λ��Ӧ��ֵ�ĵ�һ�ڽӵ� 
int NextAdjVex(ALGraph G,KeyType v,KeyType w);//��λ��Ӧ��ֵ���ڽӵ����һ�ڽӵ� 
status InsertVex(ALGraph &G,VertexType v);//���붥�� 
status DeleteVex(ALGraph &G,KeyType v);//ɾ���ڵ� 
status InsertArc(ALGraph &G,KeyType v,KeyType w);//���뻡 
status DeleteArc(ALGraph &G,KeyType v,KeyType w);//ɾ���� 
status DFSTraverse(ALGraph G, void (*visit)(VertexType));//��ȱ��� 
status DFS(ALGraph G,int i ,void (*visit)(VertexType));//��ȱ����������� 
status BFSTraverse(ALGraph &G,void (*visit)(VertexType));//��ȱ��� 
status visitNode(ALGraph G, ArcNode** Q, int& head, int& tail, int* rec, void (*visit)(VertexType));//��ȱ����������� 
void visit(VertexType v);//���ʺ��� 
status SaveGraph(ALGraph G, char FileName[]);//����ͼ 
status LoadGraph(ALGraph &G, char FileName[]);//��ȡͼ 
//����Ϊ����ͼ���� 
status InitALGraphs(ALGraphs& GS); //��ʼ����ͼ(��˳�����Ա���ʽ����)
status AddGraph(ALGraphs& GS, int i, char GraphName[]);//����һ��ͼ 
status RemoveGraph(ALGraphs& GS, char GraphName[]);//�Ƴ�һ��ͼ 
status ALGraphsTraverse(ALGraphs GS);//����ͼ�ı��� 
status ClearALGraphs(ALGraphs& GS);//��ն���ͼ�е����� 
status DestroyALGraphs(ALGraphs& GS);//�ݻٶ���ͼ 
ALGraph* gather_operate(ALGraphs& GS);//����ͼ���ϲ��� 
int main()
{
	ALGraph *G = (ALGraph*)malloc(sizeof(ALGraph));   //ͼ  
	G->vexnum = 0;
	G->arcnum = 0;
	int op = 1;  //����ָ�� 
	int j = 0, k = 0;   //����ִ��״̬
	KeyType key = 0, key1 = 0; //��ֵ����
	VertexType value;
	ALGraphs GS;  //��ͼ
	GS.elem = NULL;
	int flag = 0;  //��ͼ������ɱ�־ 
	ALGraph* G_ope = NULL, *temp = NULL; //��ͼ����ͼ������
	while (op) {
		system("cls");	printf("\n\n");
		printf("                         �����ڽӱ��ͼ�����˵�\n");
		printf("-----------------------------------------------------------------------\n");
		printf("    	  1. ����ͼ           7.  ���붥��       13. �浵\n");
		printf("    	  2. ����ͼ           8.  ɾ������       14. ����\n");
		printf("    	  3. ���Ҷ���         9.  ���뻡         15. ��ͼ����\n");
		printf("    	  4. ���㸳ֵ         10. ɾ����         0.  �˳� \n");
		printf("    	  5. ��õ�һ�ڽӵ�   11. ������ȱ���\n");
		printf("    	  6. �����һ�ڽӵ�   12. ������ȱ���\n");
		printf("-----------------------------------------------------------------------\n");
		if (op)
			printf("    ��ѡ����Ĳ���[0~17]:");
		scanf("%d", &op);
		switch(op) {
			case 1:
				if((j = CreateGraph(*G)) == OK) printf("�����ɹ���\n");
				else if(j == INFEASIBLE) printf("��ǰ��ͼ���Ѿ��е㶫����~\n");
				else if(j == ERROR) printf("�����������󣬼�ֵ�ظ�������ʧ�ܣ�\n");
				printf("----���������----\n");
				_getch();
				break;
			case 2:
				if (G->vexnum == 0) printf("��ͼ\n");
				else
				{
					DestroyGraph(*G);
					printf("���ٳɹ���\n");
				}
				printf("----���������----\n");
				_getch();
				break;
			case 3:
				if (G->vexnum == 0) printf("��ͼ\n");
				else
				{
					printf("������\n");
					scanf("%d", &key);
					if((j = LocateVex(*G, key)) == -1) printf("û�ҵ���ֵ��%d�ĵ�\n", key);
					else printf("��ֵΪ%d�Ľ�������ͼ���ǵ�%d����, ���е������ǣ�key=%d, others=%s\n", key, j + 1, G->vertices[j].data.key, G->vertices[j].data.others);
				}
				printf("----���������----\n");
				_getch();
				break;
			case 4:
				if (G->vexnum == 0) printf("��ͼ\n");
				else {
					printf("������Ҫ��λ�ļ�ֵ��");
					scanf("%d", &key);
					if (LocateVex(*G, key) == -1)
					{
						printf("û�м�ֵΪ%d�Ķ���\n", key);
						printf("----���������----\n");
						_getch();
						break;
					}
					else
					{
						printf("������Ҫ���ĵļ�ֵ��");
						scanf("%d", &value.key);
						if (LocateVex(*G, value.key) != -1 && value.key != key)
						{
							printf("û���ҵ��ü�ֵ�ĵ�\n");
							printf("----���������----\n");
							_getch();
							break;
						}
						else {
							printf("������Ҫ���ĵ�����");
							scanf("%s", value.others);
						}
					}
					PutVex(*G, key, value);
					printf("���ĳɹ���\n");
				}
				printf("----���������----\n");
				_getch();
				break;
			case 5:
				if (G->vexnum == 0) printf("��ͼ\n");
				else
				{
					printf("������Ҫ��λ�ļ�ֵ:\n");
					scanf("%d", &key);
					if ((j = FirstAdjVex(*G, key)) == -1) printf("û���ҵ�\n");
					else printf("��ֵΪ%d�ĵ�ĵ�һ�ڽӵ��ǵ�%d�ŵ�, ���е������ǣ�key=%d, others=%s\n", key, j + 1, G->vertices[j].data.key, G->vertices[j].data.others);
				}
				printf("----���������----\n");
				_getch();
				break;
			case 6:
			if (G->vexnum == 0) printf("��ͼ\n");
			else {
				printf("�����ֵ��");
				scanf("%d", &key);
				if ((j = LocateVex(*G, key)) != -1)
				{
					printf("�������������ڽ�����������һ�������һ�ڽӵ㣿��ֵ��\n");
					scanf("%d", &key1);
					if (IsRepeat(G->vertices[j].firstarc, LocateVex(*G, key1)))
					{
						if ((j = NextAdjVex(*G, key, key1)) == -1) printf("����һ�ڽӵ㣡\n");
						else printf("��ֵΪ%d�ĵ�����ڼ�ֵΪ%d�ĵ����һ�ڽӵ�Ϊ��%d�ŵ㣬������Ϊ��key=%d, others=%s\n", key, key1, j + 1, G->vertices[j].data.key, G->vertices[j].data.others);
					}
					else printf("��ֵΪ%d�ĵ����ֵΪ%d�ĵ㲻�ڽӣ�\n",key, key1);
				}
				else
				{
					printf("��ͼ��û����֮��Ӧ�ĵ�\n");
				}
			}
			printf("----���������----\n");
			_getch();
			break;
		case 7:
			if (G->vexnum == MAX_VERTEX_NUM) printf("����ͼ������\n");
			else {
				printf("��������������ļ�ֵ��");
				scanf("%d", &value.key);
				if (IsRepeat(*G, value.key)) printf("�ظ��ļ�ֵ\n");
				else
				{
					printf("������������������ݣ�");
					scanf("%s", value.others);
					InsertVex(*G, value);
					printf("��ӳɹ���\n");
				}
			}
			printf("----���������----\n");
			_getch();
			break;
		case 8:
			if (G->vexnum == 0) printf("��ͼ\n");
			else
			{
				printf("�����ɾ�������ֵ��");
				scanf("%d", &key);
				j = LocateVex(*G, key);
				if (j == -1) printf("��ǰͼ����û��keyֵΪ%d�Ķ���\n", key);
				else
				{
					DeleteVex(*G, key);
					printf("ɾ���ɹ���\n");
				}
			}
			printf("----���������----\n");
			_getch();
			break;
		case 9:
			if (G->vexnum < 2) printf("��������������\n");
			else
			{
				printf("���������ӻ�����ļ�ֵ��");
				scanf("%d%d", &key, &key1);
				j = InsertArc(*G, key, key1);
				if(j == INFEASIBLE) printf("������֮���Ѿ��л���!\n");
				else if (j == ERROR)
				{
					if ((k = LocateVex(*G, key)) == -1)
					{
						if (LocateVex(*G, key1) == -1)
							printf("û���ҵ���Ӧ�ĵ�\n");
						else
							printf("��ֵΪ%d�ĵ㲻�����ͼ��\n", key);
					}
					else if (k != -1) printf("��ֵΪ%d�ĵ㲻�����ͼ��\n", key1);
				}
				else printf("��ӳɹ���\n");
			}
			printf("----���������----\n");
			_getch();
			break;
		case 10:
			if (G->vexnum < 2) printf("��������������\n");
			else
			{
				printf("������ɾ���ĵĻ���Ӧ���������㣺");
				scanf("%d%d", &key, &key1);
				j = DeleteArc(*G, key, key1);
				if(j == INFEASIBLE) printf("�������㲻�ڽӣ�\n");
				else if (j == ERROR)
				{
					if ((k = LocateVex(*G, key)) == -1)
					{
						if (LocateVex(*G, key1) == -1)
							printf("û���ҵ���Ӧ�ĵ�\n");
						else
							printf("��ֵΪ%d�ĵ㲻�����ͼ��\n", key);
					}
					else printf("��ֵΪ%d�ĵ㲻�����ͼ��\n", key1);
				}
				else printf("ɾ���ɹ���\n");
			}
			printf("----���������----\n");
			_getch();
			break;
		case 11:
			if (G->vexnum == 0) printf("��ͼ\n");
			else
			{
				printf("������ȱ���ʱ����ǰͼ�����е����Ϣ���£�\n");
				DFSTraverse(*G, visit);
				printf("\n");
			}
			printf("----���������----\n");
			_getch();
			break;
		case 12:
			if (G->vexnum == 0) printf("��ͼ\n");
			else
			{
				printf("������ȱ���ʱ����ǰͼ�����е����Ϣ���£�\n");
				BFSTraverse(*G, visit);
				printf("\n");
			}
			printf("----���������----\n");
			_getch();
			break;
		case 13:
			if (G->vexnum == 0) printf("��ͼ\n");
			else {
				char SaveFile[40];
				printf("����浵�ļ�·��(����0ѡ��Ĭ��·��):\n");
				scanf("%s", SaveFile);
				if (!strcmp(SaveFile, "0")) strcpy(SaveFile, "D:\\���ݽṹʵ��\\�ļ�.dat");
				SaveGraph(*G, SaveFile);
				printf("�ѽ����ݴ��� %s\n", SaveFile);
			}
			printf("----���������----\n");
			_getch();
			break;
		case 14:
			if(G->vexnum != 0) printf("��ǰͼ�������������!\n");
			else
			{
				char LoadFile[40];
				printf("��������ļ�·��(����0ѡ��Ĭ��·��):\n");
				scanf("%s", LoadFile);
				if (!strcmp(LoadFile, "0")) strcpy(LoadFile, "D:\\���ݽṹʵ��\\�ļ�.dat");
				if ((j = LoadGraph(*G, LoadFile)) == ERROR) printf("�浵�ļ�%s�޷��򿪣�\n", LoadFile);
				else if(j == INFEASIBLE) printf("�浵�ļ��е�ĸ�����������!����ʧ��!\n");
				else printf("�����Ѵ� %s �ж���\n", LoadFile);
//				printf("��ǰͼ����%d����, %d����\n", G->vexnum, G->arcnum);
			}
			printf("----���������----\n");
			_getch();
			break;
		case 15:
			if (flag == 1)            //�޸�״̬�������ٴ�ѡ�����Ա��ϲ��� 
			{
				printf("��ǰ��δ�������޸ģ����Ƚ���ǰһ�޸ģ�\n");
				printf("----���������----\n");
				_getch();
				break;
			}
			G_ope = gather_operate(GS);
			if (G_ope != NULL)//ֻҪѡ���˼��ϲ����е��޸ģ��ͽ��������ͼ�û��ɼ�������ѡͼ 
			{
				temp = G;             //temp�ݴ����������Ա�����
				G = G_ope;            //�������̨���Ա��û�Ϊ��������ѡͼ
				flag = 1;             //ϵͳ״̬��Ϊ���ϲ���̬
			}
			break;
		case 0:
			break;
		}//end of switch
		if (flag && op == 0)     //flag�жϵ�ǰ�Ƿ������Ա��ϲ����У���ʱ�˳�����������
		{
			G = temp;           //����ԭʼ���������Ա�����
			op = 1;             //���ֲ��˳�while
			flag = 0;           //״̬��Ϊ��ʼ����
			printf("ԭ�������ͼ�����������룡\n");
			_getch();
		}
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
	printf("----���������----\n");
	_getch();
	return 0;

 } 

int IsRepeat(ArcNode* arc, int num)
//�ڵ�ǰ��㼰������������Ƿ����num
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
//ͼG�в��Ҽ�ֵ��key��ͬ�ĵ�
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (key == G.vertices[i].data.key)
			return 1;
	}
	return 0;
}

 status CreateGraph(ALGraph &G)
//���봴��ͼ
{
	if (G.vexnum != 0) return INFEASIBLE;
	VertexType V[30];
	KeyType VR[100][2];
	int i = 0;
	G.arcnum = G.vexnum = 0;
	printf("����\"��ֵ ���� ��ֵ ���� ... -1 nil ���Ӽ�ֵ ���Ӽ�ֵ ... -1 -1\"����\n"); 
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
/*����V��VR����ͼT������OK�����V��VR����ȷ������ERROR
�������ͬ�Ĺؼ��֣�����ERROR����������ͨ������������������ʵ�ֱ�������*/
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
int i=0;
	for(i=0;V[i].key!=-1;i++)//���ж����е�ͷ�ڵ����ݵĸ����Ƿ� 
	{
		if(i>=MAX_VERTEX_NUM)
		return ERROR; 
	 }
	 for(i=0;V[i].key!=-1;i++)//�Ƿ��м�ֵ�ظ� 
	 {
	 	int j=0;
	 	for(j=i+1;V[j].key!=-1;j++)
	 	{
	 		if(V[i].key== V[j].key)
	 		return ERROR;
		 }
	  }
 i=0;
 if(V[i].key==-1)//�Ƿ��һ��ʼ��û������ 
	 		return ERROR;
	  G.vexnum=0; 
	  for(i=0; V[i].key!=-1; i++) 
	  {
	  	G.vertices[i].data.key = V[i].key;
		strcpy(G.vertices[i].data.others, V[i].others);
		G.vertices[i].firstarc = NULL;
		G.vexnum++;
	   } 
	   	//ָ��������
	int count = 0;  //��¼ͼ�Ķ�degree��ÿ����һ��count++������countΪdegree������ 
	G.arcnum = 0;//������Ϊ0 
	for ( i = 0; VR[i][0] != -1; i++)
	{
		int head = LocateVex(G, VR[i][0]); //��λ��Ҫ����ļ�ֵ 
		int tail = LocateVex(G, VR[i][1]);//��λ��Ҫ����ļ�ֵ 

		if (head == -1|| tail == -1)   //VR�а���V�в����ڵĵ㣬����
			return ERROR;
		if ( tail != head)
		{
			count++;
			ArcNode* in = (ArcNode*)malloc(sizeof(ArcNode));
			in->nextarc = G.vertices[head].firstarc;//�����ײ巨 
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
/*��������ͼG*/
{
	for (int i = 0; i < G.vexnum; i++)
	{
		//�ͷ�ÿ�����������
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
//����u��ͼG�в��Ҷ��㣬���ҳɹ�����λ�򣬷��򷵻�-1��
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data.key == u)
			return i;
	}
	return -1;
}
status PutVex(ALGraph &G,KeyType u,VertexType value)
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ö���ֵ�޸ĳ�value������OK��
//�������ʧ�ܻ�ؼ��ֲ�Ψһ������ERROR
{
    // �������ﲹ����룬��ɱ�������
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
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���u�ĵ�һ�ڽӶ���λ�򣬷��򷵻�-1��
{
    // �������ﲹ����룬��ɱ�������
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
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���v���ڽӶ��������w����һ�ڽӶ����λ�򣬲���ʧ�ܷ���-1��
{
    // �������ﲹ����룬��ɱ�������
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
   if (p == NULL) return -1;  //û�ҵ� w ���� wû����һ��
	else return p->adjvex;


}
    /********** End **********/
}
status InsertVex(ALGraph &G,VertexType v)
//��ͼG�в��붥��v���ɹ�����OK,���򷵻�ERROR
{
    // �������ﲹ����룬��ɱ�������
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
//��ͼG��ɾ���ؼ���v��Ӧ�Ķ����Լ���صĻ����ɹ�����OK,���򷵻�ERROR
{
	int i;
	i=LocateVex(G,v);
    if(G.vexnum==1||i==-1)return ERROR;//��ɾ����Ϊ��ͼ ����û���ҵ��ýڵ� 
    for(int j=0;j<G.vexnum;j++)//���ö���ǰ�Ķ����к��иö���Ļ��ռ��ͷ� 
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
            while(p)//���ö����ϵĻ��ռ��ͷ� 
            {
                q=p;
                p=p->nextarc;
                free(q);
                G.arcnum--;
            }
            G.vertices[i].firstarc=NULL;
            G.vexnum--;//����ͼ�ж�����-1 
            //����ͼ�л���������sum 
            for(int j=i;j<G.vexnum;j++)//������λ 
            {
                G.vertices[j]=G.vertices[j+1];
            }
            for(int j=0;j<G.vexnum;j++)//�������Ķ���λ�� 
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
    return ERROR;//δ�ҵ��ö��� 
}
status InsertArc(ALGraph &G,KeyType v,KeyType w)
//��ͼG�����ӻ�<v,w>���ɹ�����OK,���򷵻�ERROR
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    //������С��2��ͼֱ��
if (G.vexnum < 2) return ERROR;
int i,j;
i=LocateVex(G,v);
j=LocateVex(G,w);
if(i==-1||j==-1)//��������ڵ㶼û�У����ش���
return ERROR;
else//���ڵ㶼����ʱ
{
	ArcNode* p = G.vertices[i].firstarc;
	while (p != NULL)
	{
		if (p->adjvex == j)
			return INFEASIBLE;
		p = p->nextarc;
	}

	//v��� w 
	ArcNode* newj = (ArcNode*)malloc(sizeof(ArcNode));
	newj->adjvex =j;
	newj->nextarc = G.vertices[i].firstarc;
	G.vertices[i].firstarc = newj;

	//w��� v 
	ArcNode* newi = (ArcNode*)malloc(sizeof(ArcNode));
	newi->adjvex = i;
	newi->nextarc = G.vertices[j].firstarc;
	G.vertices[j].firstarc = newi;

	G.arcnum++;
	return OK;
}
}
status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//��ͼG��ɾ����<v,w>���ɹ�����OK,���򷵻�ERROR

{   // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
if (G.vexnum < 2) return ERROR;
int i,j;
i=LocateVex(G,v);
j=LocateVex(G,w);
if(i==-1||j==-1)//��������ڵ㶼û�У����ش���
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
int state[20];//��¼״̬��ȷ��ֻ����һ��
status DFS(ALGraph G,int i ,void (*visit)(VertexType))
{
	int j;
	//1.������ʼ�� 
	visit(G.vertices[i].data);//1.�����ʼ��� 
	state[i]=1;//2.���ѷ��ʵĽ���־��1
	 //2.����ʼ�㿪ʼ���Ժ��������в���
	ArcNode* p=G.vertices[i].firstarc;
	while(p)
    {
        j=p->adjvex;//�������ڽӵ�
		if(state[j]==0)//�������б���δ�����ʹ�ʱ���ݹ����ȥ���Ҹ��ڽӵ� 
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
//��ͼG������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
int i=0;
for(i=0;i<G.vexnum;i++)
{
	state[i]=0;
}
for(i=0;i<G.vexnum;i++)
{
	if(!state[i])//�����ַ���ͨ��֧��ʱ�����±���
	DFS(G,i,visit);
}
return OK;

}
status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//��ͼG���й�������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
{
    // �������ﲹ����룬��ɱ�������
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
		//���ʵ�ǰ��㲢���� 
		ArcNode* p = Q[head++];
		if(p == NULL) return OK;
		if (!state[p->adjvex])
		{
			visit(G.vertices[p->adjvex].data);
			state[p->adjvex] = 1;
		}

		//���� 
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
//��ͼ������д�뵽�ļ�FileName��
{
    // �������ﲹ����룬��ɱ�������
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
//�����ļ�FileName��ͼ���ݣ�����ͼ���ڽӱ�
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin 2 *********/
FILE* fp = fopen(FileName, "r");
	if(fp == NULL) return ERROR;
	int ch;
	G.vexnum = G.arcnum = 0;
	for (int i = 0; ch != EOF; i++)
	{
		//��ȡ���� 
		fscanf(fp, "%d %s", &G.vertices[i].data.key, G.vertices[i].data.others);
		G.vexnum++;
		ch = fgetc(fp); 
		if (ch != '\n')
		{
			G.vertices[i].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
			ArcNode* p = G.vertices[i].firstarc;
			//��һ���ո񣬶�һ�����ݣ���������ֱ���ˣ����е���������� 
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
//��ʼ����ͼ(��˳�����Ա���ʽ����) 
{
	if (GS.elem != NULL) return INFEASIBLE;
	GS.elem = (G*)malloc(20*sizeof(Graph));
	GS.length = 0;
	GS.size = 20;
	return OK;
}
status AddGraph(ALGraphs& GS, int i, char GraphName[])
//��iλ������ΪGraphName��ͼ 
{
	if (GS.elem == NULL) return INFEASIBLE;

	if (i > GS.length + 1 || i < 1) return ERROR;
	
	for(int i = 0; i < GS.length; i++)
	{
		if(!strcmp(GraphName, GS.elem[i]->name))
		return ERROR;
	}
	
	//������ͼ 
	G p = (Graph*)malloc(sizeof(Graph));
	int j = 0; int ord; 
	strcpy(p->name, GraphName); //ͼ���� && ͼ��ʼ�� 
	p->G.arcnum = p->G.vexnum = 0;
	printf("ֱ��������߲�����(1/0)\n");
	scanf("\n%c", &ord);
	if(ord == 1)
	{
		j = CreateGraph(p->G);
		if(j == ERROR) printf("�����������󣬲��ֶ����ֵ�ظ�������ʧ�ܣ�\n");
	}
	
	if (GS.length >= GS.size) //���� 
	{
		GS.size += 10;
		GS.elem = (G*)realloc(GS.elem, GS.size * sizeof(G));
	}
	
	for (int j = GS.length; j >= i; j--) //��λ�� 
	{
		GS.elem[j] = GS.elem[j - 1];
	}

	GS.elem[i - 1] = p;
	GS.length++;
	return OK;
}

status RemoveGraph(ALGraphs& GS, char GraphName[])
//ɾȥ��ΪGraphName��ͼ 
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
//���ҵ�ǰɭ������ΪGraphName���� 
{
	if (GS.elem == NULL) return INFEASIBLE;
	for (int i = 0; i < GS.length; i++)
	{
		if (!strcmp(GraphName, GS.elem[i]->name)) return i + 1;
	}
	return ERROR;
}

status ALGraphsTraverse(ALGraphs GS)
//������ͼ 
{
	if (GS.elem == NULL) return INFEASIBLE;
	if (GS.length == 0) return ERROR;
	int op = 0;
	if(op==0)
	{
		printf("��ѡ�������ʽ��1.������ȱ��� 2.������ȱ���\n");
		scanf("%d", &op);
	}
	if(op==1)
	{
		printf("��ǰ����������������ʾ��\n");
	for (int i = 0; i < GS.length; i++)
	{
		printf("��%d��ͼ��\n %s:\n", i + 1, GS.elem[i]->name);
		DFSTraverse(GS.elem[i]->G, visit);
		printf("\n\n");
	}
	}
	else{printf("��ǰ����������������ʾ��\n");
	for (int i = 0; i < GS.length; i++)
	{
		printf("��%d��ͼ��\n %s:\n", i + 1, GS.elem[i]->name);
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
		printf("              ��ͼ���ϲ����˵�\n");
		printf("--------------------------------------------\n");
		printf("    	 1. ��ʼ��       5. �޸�\n");
		printf("    	 2.  ����        6. ����\n");
		printf("    	 3.  ɾ��        7. ��ռ���\n");
		printf("    	 4.  ����        0. �˳�\n");
		printf("--------------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~7]:");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			if (InitALGraphs(GS) == INFEASIBLE) printf("��ǰͼ�����ѱ���ʼ����\n");
			else printf("��ʼ���ɹ���\n");
			printf("----���������----\n");
			_getch();
			break;
		case 2:
			if (GS.elem == NULL)
			{
				printf("��ǰͼ���ϲ����ڣ����ȳ�ʼ����\n");
				printf("----���������----\n");
				_getch();
				break;
			}
			printf("����������ͼ�����ƣ�\n");
			scanf("%s", GraphName);
			printf("�������ڼ�λ?");
			scanf("%d", &i);
			if ((j = AddGraph(GS, i, GraphName)) == ERROR) printf("����λ�÷Ƿ������ʧ�ܣ�\n");
			else printf("ͼ\"%s\"�洢�ɹ���\n", GraphName);
			printf("----���������----\n");
			_getch();
			break;
		case 3:
			if (GS.elem == NULL)
			{
				printf("��ǰͼ���ϲ����ڣ����ȳ�ʼ����\n");
				printf("----���������----\n");
				_getch();
				break;
			}
			printf("��������Ҫɾ����ͼ���ƣ�\n");
			scanf("%s", GraphName);
			if (RemoveGraph(GS, GraphName) == OK)
			{
				printf("ͼ\"%s\"ɾ���ɹ���\n", GraphName);
			}
			else
			{
				printf("���޴�ͼ��\n");
			}
			printf("----���������----\n");
			_getch();
			break;
		case 4:
			if (GS.elem == NULL)
			{
				printf("��ǰͼ���ϲ����ڣ����ȳ�ʼ����\n");
				printf("----���������----\n");
				_getch();
				break;
			}
			printf("��������Ҫ���ҵ�ͼ���ƣ�\n");
			scanf("%s", &GraphName);
			if (j = LocateGraph(GS, GraphName))
			{
				printf("ͼ\"%s\"λ�ڼ����е�%dλ\n", GraphName, j);
			}
			else
			{
				printf("��ͼ��\n");
			}
			printf("----���������----\n");
			_getch();
			break;
		case 5:
			if (GS.elem == NULL)
			{
				printf("��ǰͼ���ϲ����ڣ����ȳ�ʼ����\n");
				printf("----���������----\n");
				_getch();
				break;
			}
			printf("������������ĵ�ͼ������:\n");
			scanf("%s", GraphName);
			j = LocateGraph(GS, GraphName);
			if (j == 0)
			{
				printf("���޴�ͼ��\n");
				printf("----���������----\n");
				_getch();
				break;
			}
			else
			{
				return &(GS.elem[j - 1]->G);
			}
		case 6:
			if ((j = ALGraphsTraverse(GS)) == ERROR) printf("��ǰͼ����Ϊ�գ�\n");
			else if (j == INFEASIBLE) printf("��ǰͼ���ϲ����ڣ�\n");
			printf("----���������----\n");
			_getch();
			break;
		case 7:
			if(ClearALGraphs(GS) == INFEASIBLE) printf("��ǰ������δ����ʼ��!\n");
			else printf("��ճɹ�!\n");
			printf("----���������----\n");
			_getch();
			break;
		case 0:
			break;
		}
	}
	return NULL;
}
/*��ͼ����*/

