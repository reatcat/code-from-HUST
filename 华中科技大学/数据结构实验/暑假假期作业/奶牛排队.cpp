#include<bits/stdc++.h>//借用头文件 
using namespace std;
#define N 100000
int n,top1=0,top2=0,s1[N],s2[N],a[N];//运用单调栈 
unsigned long long  ans=0; //结果 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		while(top1!=0&&a[s1[top1]]>=a[i]) 
		top1--;
		while(top2!=0&&a[s2[top2]]<a[i]) 
		top2--;
		int k=upper_bound(s1+1,s1+1+top1,s2[top2])-s1;//STL
		if(k!=(top1+1)){if(ans<i-s1[k]+1)
		ans=i-s1[k]+1;}
		s1[++top1]=i;
		s2[++top2]=i;
	}
	printf("%lld",ans);
	return 0;
} 
