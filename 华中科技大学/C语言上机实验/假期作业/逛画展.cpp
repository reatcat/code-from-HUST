#include<stdio.h>
int a[2001],num;
int b[1000000];
int main()
{
    int f=-1,e=0,n,m,t,i=0,ans1,ans2;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    scanf("%d",b+i);
    i=0;
    while(num!=m)
    {
        if(a[b[i]]==0)num++;
        a[b[i]]++;
        f++;
        i++;
    }
    while(a[b[e]]>1)
        a[b[e++]]--;
    ans1=e;ans2=f;
    while(i<n)
    {
        a[b[i]]++;
        f++;
        i++;
        while(a[b[e]]>1)
        a[b[e++]]--;
        if(ans2-ans1>f-e)
        {
            ans2=f;
            ans1=e;
        }
    }
    printf("%d %d",ans1+1,ans2+1);
}

