#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#define error 2147483647
typedef struct 
{
    int c;
    int v;
    int next;
}edge[10000];
int head[20000];
int num=0;
void store(int a,int b,int c)
{
    num++;
    edge[num].c=b;
    edge[num].v=c;
    edge[num].next=head[a];
    head[a]=num;
}
int main()
{
    int visit[20000]={0};//���״̬ 
    long long dis[20000];//����
    int n,m,s;
    int a,b,c;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n;i++)dis[i]=error;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        store(a,b,c);
    }
    int curr=s;
    dis[s]=0;
    long long minn;
    while(!visit[curr])//����������ͼ
    {
        visit[curr]=true;//����Ϊ�����
        for(int i=head[curr];i!=0;i=edge[i].nexty)//��ʽǰ�����ѱ�
        {
            if(!visit[edge[i].z]&&dis[edge[i].z]>dis[curr]+edge[i].val)
            dis[edge[i].z]=dis[curr]+edge[i].val;//���²���
        }
        minn=error;
        for(int i=1;i<=n;i++)
        {
            if(!visit[i]&&minn>dis[i])//ȡ�µ���Сֵ
            {
                minn=dis[i];
                curr=i;
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%lld ",dis[i]);
    return 0;
}
