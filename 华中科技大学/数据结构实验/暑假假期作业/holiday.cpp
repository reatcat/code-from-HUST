#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int m;
	scanf("%d",&m);
	int x[n+1]={0};//表示花的浇灌情况 
	int a,b;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		for(int i=a;i<=b;i++)//从第a到b天 
		{
			x[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(x[i]!=1){
			printf("%d %d",i,x[i]);
			return 0;
		} 
	}
	printf("OK"); 
	return 0;
 } 
