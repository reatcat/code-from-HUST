#include <stdio.h>
int main()
{
    int n,c[100002],m,p,s,ss,i;
    long long sum=0;//��long long
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&c[i]);
    scanf("%d%d%d%d",&m,&p,&s,&ss);
    c[p]+=s;
    for(i=1;i<=n;i++)
        sum+=(long long)c[i]*(i-m);//��Ͳ�����
    sum=-sum;
    long long ans=sum/ss;//�������
    if(ans<0&&sum-(ans-1)*ss<=ans*ss-sum)//��������
        ans--;
    if(ans>0&&(ans+1)*ss-sum<sum-ans*ss)
        ans++;
    printf("%lld",ans+m);//���𰸼���m
    return 0;
}
