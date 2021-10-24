#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int max(int x,int y)
{
    int z;
    if(x>y)
        z=x;
    else
        z=y;
    return z;
}
int main()
{
    int n;
    long price[100],s[100],b,c,d;
    printf("请输入天数\n");
    scanf("%d",&n);
    int i=0;
    printf("请依次输入%d天的价格\n",n);
    for(i=0; i<n; i++)
        scanf("%d",&price[i]);

    int a=0;
    for(a=0; a<n-2; a++)
    {
        b=abs(price[a+1]-price[a]);
        c=abs(price[a+2]-price[a+1]);
        d=max(b,c);

    }
    printf("%d\n",b);
    return 0;
}
