#include <cstdio>
#include <cstring> 
int B[20][600];//表示状态 
char G[770][1540];//画布
int L[20];
int m,n,x,y;
void Delete(int x,int y)//删除第x行第y个节点
{
	B[x][y]=0;//删除
	if(x>=m)return;//递归
	Delete(x+1,y*2-1);//删除左子树
	Delete(x+1,y*2);//删除右子树
}
void Draw(int x,int y,int d,int k)
{
	if(B[d][k])G[x][y]='o';
	if(B[d+1][k*2-1])
	{
		int i,j;
		for(i=x+1,j=y-1;i-x<=L[d];i++,j--)
			G[i][j]='/';
		Draw(i,j,d+1,k*2-1);//递归 
	}
	if(B[d+1][k*2])
	{
		int i,j;
		for(i=x+1,j=y+1;i-x<=L[d];i++,j++)
			G[i][j]='\\';//表示有转义 
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
	for(int i=1;i<=L[0]+1;i++)//输出
	{
		for(int j=1;j<=2*L[0]+1;j++)
		printf("%c",G[i][j]);
		printf("\n");
	}
	return 0;
}
