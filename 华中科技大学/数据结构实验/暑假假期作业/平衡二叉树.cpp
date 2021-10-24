#include<bits/stdc++.h>
using namespace std; 
#define maxn 10000
int n,q[maxn],a[maxn],p[maxn],tot=0,c[maxn];
int hash(int x){
return lower_bound(q+1,q+1+tot,x)-q;//借用库函数 
}
int lowbit(int x){//表示最低位 
return x&-x;
}
void add(int x,int p)
{
	while(x<=tot)
	{
		c[x]+=p;
		x+=lowbit(x);
	}
}
int sum(int x)
{
	int res=0;
	while(x)
	{
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
int query(int x)
{
	int t=0;
	for(int i=19;i>=0;i--)
	{
		t+=1<<i;
		if(t>tot||c[t]>=x) t-=1<<i;
		else x-=c[t];
	}
	return q[t+1];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i],&a[i]);
		if(p[i]!=4) q[++tot]=a[i];
	}
	sort(q+1,q+1+tot);//输入完成的排序 
	tot=unique(q+1,q+1+tot)-(1+q);
	for(int i=1;i<=n;i++)
	{
		if(p[i]==1) add(hash(a[i]),1);//直接+1 
		if(p[i]==2) add(hash(a[i]),-1);
		if(p[i]==3) printf("%d\n",sum(hash(a[i])-1)+1);
		if(p[i]==4) printf("%d\n",query(a[i]));
		if(p[i]==5) printf("%d\n",query(sum(hash(a[i])-1)));
		if(p[i]==6) printf("%d\n",query(sum(hash(a[i]))+1));
	}
	return 0;
} 
