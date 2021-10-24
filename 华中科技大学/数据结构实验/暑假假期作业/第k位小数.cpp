#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;//调用sort（hase后排序比较）
#define MAX 100000
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	 }
	 sort(a+1,a+n+1);
	 int i;
	  for(i=1;i<=k&&i<=n;i++)
    {
        if(a[i]==a[i+1])
            k++;
    }
    if(i>n)
        printf("NO RESULT");
    else
        printf("%d",a[i-1]);
    return 0;
}
