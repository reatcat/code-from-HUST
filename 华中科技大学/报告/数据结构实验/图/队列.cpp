#include<stdio.h>
typedef struct Queue{
    int data;
    struct Queue * next;
    int front,rear; 
}Queue;
//��ʼ������

typedef struct QNode {
    int data;
    struct QNode *next;
} QNode;//���ӽ�� QNode���Ͷ���

typedef struct Queue {
    QNode *front, *rear;
} Queue;//���� Queue���Ͷ���

void InitQueue(Queue * Q){
    Q=(Queue*)malloc(sizeof(Queue));
    Q->next=NULL;
}
//����Ԫ��v������
void EnQueue(Queue *Q,int v){
    Queue * element=(Queue*)malloc(sizeof(Queue));
    element->data=v;
    element->next = NULL;
    Queue * temp=Q;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=element;
}
//��ͷԪ�س�����
void DeQueue(Queue *Q,int *u){
    (*u)=Q->next->data;
    Q->next=Q->next->next;
}
//�ж϶����Ƿ�Ϊ��
int QueueEmpty(Queue *Q){
    if (Q->next==NULL)
    return 1;
    return 0;
}
#define INIT_QUEUE_SIZE 20
#define QUEUE_INCREMENT 10

typedef struct QNode {
    int data;
    struct QNode *next;
} QNode;//���ӽ�� QNode���Ͷ���

typedef struct Queue {
    QNode *front, *rear;
} Queue;//���� Queue���Ͷ���


/*
 * ���к��� 1��status InitQueue(Queue &Q)
 * �������ͣ�Queue &
 * �������ͣ�status ( ERROR, OK )
 * ����˵������ʼ�����У������ɽ�����ͷ���Ŀն��� Q����ʼ���ɹ������� OK�����򷵻� ERROR��
 */
//status InitQueue(Queue &Q)
//{
//    QNode *p = (QNode *) malloc(sizeof(QNode));
//    if (!p) return ERROR;
//    p->next = NULL;
//    Q.front = Q.rear = p;
//    Q.front->next = NULL;
//    return OK;
//}
//
///*
// * ���к��� 2��status PushQueue(Queue &Q, BiTree e)
// * �������ͣ�Queue &, BiTree
// * �������ͣ�status ( OK )
// * ����˵������Ӳ���������� e��ӡ���ӳɹ������� OK��
// */
//status PushQueue(Queue &Q, int e)
//{
//    QNode *NewNode = (QNode *) malloc(sizeof(QNode));
//    NewNode->data = e, NewNode->next = NULL;
//    Q.rear->next = NewNode;
//    Q.rear = NewNode;
//    return OK;
//}
//
///*
// * ���к��� 3��status PopQueue(Queue &Q, BiTree &e)
// * �������ͣ�Queue &, BiTree &
// * �������ͣ�status ( ERROR, OK )
// * ����˵�������Ӳ����������ӵ�Ԫ�ر����� e�С����ӳɹ������� OK��������Ϊ�ճ���ʧ�ܣ����� ERROR��
// */
//status PopQueue(Queue &Q, int &e)
//{
//    if (Q.front == Q.rear) return ERROR;
//    QNode *p = Q.front->next;
//    e = p->data;//e���Ǳ�ɾ����Ԫ��
//    Q.front->next = p->next;
//    if (Q.rear == p) Q.rear = Q.front;//��ԭ����ֻ��һ����㣬�޸�βָ��
//    free(p);
//    return OK;
//}
//
///*
// * ���к��� 4��status EmptyQueue(Queue Q)
// * �������ͣ�Queue
// * �������ͣ�bool ( true, false )
// * ����˵�����ж��Ƿ�Ϊ�ն��У�����Ϊ�շ��� true�����в�Ϊ�շ��� false��
// */
//bool EmptyQueue(Queue Q)
//{
//    if (Q.front == Q.rear) return true;
//    return false;
//}
status BFSNewVersion(ALGraph G, void (*visit)(VertexType))
{
    for (int v = 0; v < G.vexnum; v++) visited[v] = false;
    Queue Q;
    InitQueue(Q);
    for (int v = 0; v < G.vexnum; v++)
    {
        if (!visited[v])
        {
            visit(G.vertices[v].data), visited[v] = true;
            PushQueue(Q, v);
            while (!EmptyQueue(Q))
            {
                int u;
                PopQueue(Q, u);
                for (int w = FirstAdjVex(G, G.vertices[u].data.key); w >= 0; \
                w = NextAdjVex(G, G.vertices[u].data.key, G.vertices[w].data.key))
                {
                    if (!visited[w])
                    {
                        visit(G.vertices[w].data), visited[w] = true;
                        PushQueue(Q, w);
                    }
                }
            }//end of while loop
        }//end of if
    }//end of for loop
    return OK;
}

