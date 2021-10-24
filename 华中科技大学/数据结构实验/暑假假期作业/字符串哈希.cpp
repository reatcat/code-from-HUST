#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;//调用sort（hase后排序比较） 
#define MAX 100000
#define mod 10000079//查的质数
#define jinzhi 15168418
typedef unsigned long long ull;
ull hash(char s[])
{
	int len=strlen(s);
	ull res=0;
	for(int i=0;i<len;i++)
	{
		res=(res*jinzhi+(ull)s[i])%mod;
	}
	return res;
}
int main()
{
	int n;
	scanf("%d",&n);
	char s[MAX];
	ull a[MAX];
	int ans=1;
//	char a[n+1][MAX];
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%s",a[i]);
//	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		a[i]=hash(s);
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
        if (a[i]!=a[i-1])
            ans++;
    printf("%d\n",ans);
	return 0;
 } 
