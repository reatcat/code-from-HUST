#include<stdio.h>
typedef struct Queue{
    int data;
    struct Queue * next;
    int front,rear; 
}Queue;
//初始化队列

typedef struct QNode {
    int data;
    struct QNode *next;
} QNode;//链队结点 QNode类型定义

typedef struct Queue {
    QNode *front, *rear;
} Queue;//链队 Queue类型定义

void InitQueue(Queue * Q){
    Q=(Queue*)malloc(sizeof(Queue));
    Q->next=NULL;
}
//顶点元素v进队列
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
//队头元素出队列
void DeQueue(Queue *Q,int *u){
    (*u)=Q->next->data;
    Q->next=Q->next->next;
}
//判断队列是否为空
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
} QNode;//链队结点 QNode类型定义

typedef struct Queue {
    QNode *front, *rear;
} Queue;//链队 Queue类型定义


/*
 * 队列函数 1：status InitQueue(Queue &Q)
 * 参数类型：Queue &
 * 返回类型：status ( ERROR, OK )
 * 功能说明：初始化队列，即生成仅带表头结点的空队列 Q。初始化成功，返回 OK，否则返回 ERROR。
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
// * 队列函数 2：status PushQueue(Queue &Q, BiTree e)
// * 参数类型：Queue &, BiTree
// * 返回类型：status ( OK )
// * 功能说明：入队操作，将结点 e入队。入队成功，返回 OK。
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
// * 队列函数 3：status PopQueue(Queue &Q, BiTree &e)
// * 参数类型：Queue &, BiTree &
// * 返回类型：status ( ERROR, OK )
// * 功能说明：出队操作，将出队的元素保存在 e中。出队成功，返回 OK；若队列为空出队失败，返回 ERROR。
// */
//status PopQueue(Queue &Q, int &e)
//{
//    if (Q.front == Q.rear) return ERROR;
//    QNode *p = Q.front->next;
//    e = p->data;//e就是被删除的元素
//    Q.front->next = p->next;
//    if (Q.rear == p) Q.rear = Q.front;//若原队列只有一个结点，修改尾指针
//    free(p);
//    return OK;
//}
//
///*
// * 队列函数 4：status EmptyQueue(Queue Q)
// * 参数类型：Queue
// * 返回类型：bool ( true, false )
// * 功能说明：判断是否为空队列，队列为空返回 true，队列不为空返回 false。
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

