#include<stdio.h>
int n,m;
int find(int k,int *f)
{
    if(f[k]==k)return k;//一开始初始化 
    return f[k]=find(f[k],f);//实际上是找根 
}
int main()
{
	scanf("%d%d",&n,&m);
	int i;
//	int x[m+1];
//	int y[m+1];
//	int z[m+1];
	int f[n+1];
	int x,y,z;
	for(i=1;i<=n;i++)
        f[i]=i;//确定一个根节点，那么一开始是分开的 
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)//建树 
		f[find(y,f)]=find(z,f);//以后一个数为树的根 
		else  if(find(y,f)==find(z,f))//判断是否在 一颗树下 
                printf("Y\n");
            else
                printf("N\n");
	}
	
	return 0;
 } 
