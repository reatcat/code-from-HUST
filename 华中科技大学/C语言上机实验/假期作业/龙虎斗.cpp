#include <stdio.h>
int main()
{
    int n,c[100002],m,p,s,ss,i;
    long long sum=0;//开long long
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&c[i]);
    scanf("%d%d%d%d",&m,&p,&s,&ss);
    c[p]+=s;
    for(i=1;i<=n;i++)
        sum+=(long long)c[i]*(i-m);//求和并作差
    sum=-sum;
    long long ans=sum/ss;//求初步答案
    if(ans<0&&sum-(ans-1)*ss<=ans*ss-sum)//分类讨论
        ans--;
    if(ans>0&&(ans+1)*ss-sum<sum-ans*ss)
        ans++;
    printf("%lld",ans+m);//最后答案加上m
    return 0;
}
