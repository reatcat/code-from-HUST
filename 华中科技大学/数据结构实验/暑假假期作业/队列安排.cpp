#include<stdio.h>
#define max 10000
#define MAXSIZE 100
typedef struct{
	int data[MAXSIZE];
	int front;
	int rear; 
}Queue; //队列的定义 

void InitQueue(Queue *Q)
{
	Q->front=Q->rear=0;
}
void EnQueue(Queue *Q,int e)
{
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXSIZE;//此处的循环队列将rear指向后一个空的位置 
 }
void DeQueue(Queue *Q,int * e)
{
	*e = Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
 }
 //以下为补充的函数
int QueueEmpty(Queue *Q)
{
	if(Q->front==Q->rear) return 1;
	else return 0; 
 }
int QueueFull(Queue *Q)
{
	if((Q->rear+1)%MAXSIZE==Q->front) return 1;
	else return 0;
 } 
int a[max][4]={0};//其中的j表示存在及左右状态 
int main()
{
	int n;
	scanf("%d",&n);
	a[1][1]=1;//第一个同学 
	int temp=1;
	for(int i=2;i<=n;i++)
	{
		int k,p;
		scanf("%d%d",&k,&p);
		a[i][1]=i;//该同学是存在的 
		if(p==0){//左 
			a[a[k][3]][2]=i;//表示该k同学的左边是i 
			a[i][2]=k;
            a[i][3]=a[k][3]; 
			a[k][3]=i;
            if(k==temp)//是否要更换 
			temp=i;
		}
		else{//右 
			a[i][2]=a[k][2];
			a[a[k][2]][3]=i;
            a[k][2]=i;
			a[i][3]=k;
		}
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
    {
        int x; 
		scanf("%d",&x);
        if(a[x][1]!=0)//在队列中 
        {
            a[x][1]=0;
            a[a[x][3]][2]=a[x][2];
            a[a[x][2]][3]=a[x][3];
            n--;
            if(x==temp) 
			temp=a[x][3];
        }
    }
    int i=1,x=temp;
    while(i<=n)
    {
        printf("%d ",a[x][1]);
        x=a[x][2]; i++;
    }
	return 0;
 } 
