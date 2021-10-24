#include<stdio.h>
#include<string.h>
int pd[10000][200],a[10000][200];
int main()
{
	int n,m,x,i,j,ans=0,l=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		l=0;
		for(j=0;j<m;j++)
		{
			scanf("%d%d",&pd[i][j],&a[i][j]);
			if(pd[i][j]==1) l++;
		}
		pd[i][m]=l;
	}
	scanf("%d",&x);
	i=1;
	while(i<=n)
	{
	    ans+=a[i][x];
		ans%=20123;
	    int k=0;
		for(j=x;;j++)
		{
			if(j==m) j=0;
			if(pd[i][j]==1) k++;
			if(k==(a[i][x]-1)%pd[i][m]+1) 
			break;
		}
	    x=j;
		i++;
	}
	printf("%d",ans);
	return 0;
}
