#include<stdio.h>
int main()
{
    int a[500]={0};
    long long b[100];
    b[1]=2;
    int n,i,len=1;
    scanf("%d",&n);
    a[0]=2;
    n--;
    while(n--)
    {
        int x=0;
        for(i=0;i<len;i++)
        {
            a[i]=a[i]*2+x;
            if(i==0)
                a[i]+=2;
            x=a[i]/10;
            a[i]%=10;
        }
        a[len]+=x;
        if(a[len])
            len++;
    }
    for(i=len-1;i>=0;i--)
    printf("%d",a[i]);
    return 0;
}
