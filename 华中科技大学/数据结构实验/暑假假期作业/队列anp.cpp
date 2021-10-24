#include <cstdio>
#include <queue>
using namespace std;
#define max 10000
#define maxsize 1000000
#define MAXSIZE 100
//typedef struct{
//	int data[MAXSIZE];
//	int front;
//	int rear; 
//}Queue; //队列的定义 
//
//void InitQueue(Queue *Q)
//{
//	Q->front=Q->rear=0;
//}
//void EnQueue(Queue *Q,int e)
//{
//	Q->data[Q->rear]=e;
//	Q->rear=(Q->rear+1)%MAXSIZE;//此处的循环队列将rear指向后一个空的位置 
// }
//void DeQueue(Queue *Q,int * e)
//{
//	*e = Q->data[Q->front];
//	Q->front=(Q->front+1)%MAXSIZE;
// }
// //以下为补充的函数
//int QueueEmpty(Queue *Q)
//{
//	if(Q->front==Q->rear) return 1;
//	else return 0; 
// }
//int QueueFull(Queue *Q)
//{
//	if((Q->rear+1)%MAXSIZE==Q->front) return 1;
//	else return 0;
// } 
int n;
queue<int> Q;
queue<int> q[max];
char ch[30];
int team[maxsize];
int x;
int f;
int ans=1;
int main(){
	while(scanf("%d",&n)){
		if(n == 0)
			break;
		printf("Scenario #%d\n",ans);
		ans++;
		int num;
		for(int i = 0;i < n;++ i){
			scanf("%d",&num);
			for(int j = 0;j < num;++ j){
				scanf("%d",&x);
				team[x] = i;
			}
		}
		while(scanf("%s",ch)){
			if(ch[0] == 'S')
				break;
			if(ch[0] == 'E'){
				scanf("%d",&x);
				if(q[team[x]].empty()){
					Q.push(x);
					q[team[x]].push(x);
				}
				else{
					q[team[x]].push(x);
				}
			}
			if(ch[0] == 'D'){
				printf("%d\n",q[team[Q.front()]].front());
				q[team[Q.front()]].pop();
				if(q[team[Q.front()]].empty())
					Q.pop();
			}
		}
	}
	
	return 0;
}
