#include <cstdio>
#include <cstring> 
int B[20][600];//��ʾ״̬ 
char G[770][1540];//����
int L[20];
int m,n,x,y;
void Delete(int x,int y)//ɾ����x�е�y���ڵ�
{
	B[x][y]=0;//ɾ��
	if(x>=m)return;//�ݹ�
	Delete(x+1,y*2-1);//ɾ��������
	Delete(x+1,y*2);//ɾ��������
}
void Draw(int x,int y,int d,int k)
{
	if(B[d][k])G[x][y]='o';
	if(B[d+1][k*2-1])
	{
		int i,j;
		for(i=x+1,j=y-1;i-x<=L[d];i++,j--)
			G[i][j]='/';
		Draw(i,j,d+1,k*2-1);//�ݹ� 
	}
	if(B[d+1][k*2])
	{
		int i,j;
		for(i=x+1,j=y+1;i-x<=L[d];i++,j++)
			G[i][j]='\\';//��ʾ��ת�� 
		Draw(i,j,d+1,k*2);
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	memset(G,32,sizeof(G));
	for(int i=0;i<m;i++)
		for(int j=1;j<=1<<i;j++)
			B[i+1][j]=1;
	L[m-1]=1;
	for(int i=m-2;i>=0;i--)
	{
		L[i]=m-i-1;
		for(int j=m-1;j>i;j--)
			L[i]+=L[j];
	}
	while(n--)
	{
		scanf("%d%d",&x,&y);
				Delete(x,y);
	}
	Draw(1,L[0]+1,1,1);
	for(int i=1;i<=L[0]+1;i++)//���
	{
		for(int j=1;j<=2*L[0]+1;j++)
		printf("%c",G[i][j]);
		printf("\n");
	}
	return 0;
}
