#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,sum=0,i=1;
    scanf("%d",&a);
    c=b=a;
    while(b/10!=0)
    {
    i++;
    b=b/10;
    }
    for(;c!=0;)
    {
        sum+=c%10;
        c=c/10;

    }
    printf("%d是%d位数,且各位数字之和为%d",a,i,sum);
    return 0;
}
