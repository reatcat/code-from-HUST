#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int m;
	scanf("%d",&m);
	int x[n+1]={0};//��ʾ���Ľ������ 
	int a,b;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		for(int i=a;i<=b;i++)//�ӵ�a��b�� 
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
