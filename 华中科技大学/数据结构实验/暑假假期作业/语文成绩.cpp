#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int p;
	scanf("%d",&p);
	int x[n+1];
	for(int i=1;i<=n;i++)
	scanf("%d",&x[i]);
	int a,b,add;
//	for(int i=1;i<=p;i++)
//	{
//		
//		scanf("%d%d%d",&a,&b,&add);
//		for(int j=a;j<=b;j++)
//		{
//			x[j]+=add;
//		}
//	}
//	sort(x+1,x+n+1);
//	printf("%d",x[1]);
for(int i=n;i>1;i--)x[i]-=x[i-1];
	while(p--)
	{
		scanf("%d%d%d",&a,&b,&add);
		x[a]+=add;x[b+1]-=add;
	}
	int min=x[1];
	for(int i=2;i<=n;i++)
	{
		x[i]+=x[i-1];if(x[i]<min)min=x[i];
	}
	printf("%d",min);
	return 0;
 } 

