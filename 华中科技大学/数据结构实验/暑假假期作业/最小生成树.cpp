#include<cstdio>
#define MAXSIZE 1000
int min(int a,int b)
{
	return (a>b)?b:a;
}
int state[MAXSIZE];//��¼״̬ 
int dis[MAXSIZE];//���ڼ�¼�������ľ������·��
int MAX = 99999;//�߽�ֵ
int tu[MAXSIZE][MAXSIZE];//���ڼ�¼���бߵĹ�ϵ
int main()
{
    int i,j,k;
    int n,m;
    int x,y,z;
    int min,minv;
    int sum=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    	if(i!=j)
    		tu[i][j]=MAX;
    	else
    		tu[i][j]=0;	
		}
	}
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d",&x,&y,&z);//xy�г�Ϊz�ı� 
        tu[x][y]=z;
        tu[y][x]=z;
    }
    //�ȴ�1��ʼ 
    for (i = 1; i <= n; i++)
        dis[i] = tu[1][i];

    state[1]=1;//��¼1�Ѿ������ʹ���

    for (i = 1; i <= n-1; i++)
    {
        min = MAX;//һ��ʼ��Ϊ������ 
        for (j = 1; j <= n; j++)
        {
            if(state[j] ==0 && dis[j] < min)//û�з��ʹ�����С 
            {
                min = dis[j];
                minv = j;
            }
        }

        //��¼������Ѿ������ʹ���
        state[minv] = 1;
        sum += dis[minv];

        for (j = 1; j <= n; j++)
        {
            //������û�б����ʹ�����������㵽����һ��ľ�������ڵ����ľ������ô����
            if(state[j] == 0 && tu[minv][j] < dis[j])
                dis[j] = tu[minv][j];
        }
    }
	if(sum<MAX)
    printf("%d",sum);
    else 
    printf("orz");
}
